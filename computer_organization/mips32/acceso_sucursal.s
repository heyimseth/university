# Una sucursal bancaria utiliza un control de acceso basado en arquitectura MIPS.
# El sistema tiene conectado un dispositivo que detecta cuándo se abre la puerta
# de la oficina. Este consta de un registro de control mapeado en la dirección
# 0xFFFF0300, y solicita una interrupción de nivel 2 cada vez que detecta la
# apertura.

#	Registro de control
#	|15|14|13|12|11|10|09|08|07|06|05|04|03|02|01|00|
#	|   mode    |   sensibilidad  |  pdo. muestreo  |
#	-mode: 0: off, 1: on, 2: demo, 3-15: -
#	-sensibilidad: aumentar la tolerancia a vibraciones de la puerta
#	-periodo de muestreo: en segundos. Puede aumentar la vida útil de las baterías,
#		en caso de que el dispositivo las use.

# Además, el sistema accede a un reloj que proporciona fecha y hora por medio de
# un registro (siempre disponible) mapeado en la dirección 0xFFFF0304.
#	Registro de estado del reloj
#	|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|15|14|13|12|11|10|09|08|07|06|05|04|03|02|01|00|
#	|          mes          |          dia          |         hora          |         minuto	|

# Asumiendo que el sistema se configura según el programa:
		.data
num_ev:		.word 0				# Número de eventos en la base de datos
events:		.space 65536			# Base de datos de eventos (fecha/hora)

		.text
		.globl main
main:
		li	$a0, 0xFFFF0300		# Dirección del registro del sensor de la puerta
		lw	$t0, 0($a0)		# Leo registro
		andi	$t0, $t0, 0x0FFF	# Activo la puerta:
		ori	$t0, $t0, 0x1000	#	Mode = 1
		sw	$t0, 0($a0)		# Escribo registro

		mfc0	$t0, $12		# Leo registro de estado CP0
		ori	$t0, $t0, 0x0400	# Pongo a 1 el bit IM2
		mtc0	$t0, $12		# Escribo registro de estado CP0

		jal 	VIGILANCIA		# Salto a la rutina que gestiona la vigilancia de la sucursal

		li $v0, 10
		syscall

# implementar la RSI que:
#	1) Inicialmente salve y finalmente recupere los registros que modifica.
#	2) Determine si el dispositivo detector de la puerta fue el causante de la interrupción.
#	3) En caso afirmativo, añada la fecha/hora de la apertura de la puerta a la información
#		existente en la base de datos (actualizando los punteros correspondientes).
#	4) Retorne reactivando las interrupciones.

		.text	0x80000080
		# Determinar si ha sido interrupción externa
		mfc0	$k0, $13
		andi	$k1, $k0, 0x3C
		bne	$k1, $zero, salir

		# Determinar si ha sido el detector de la puerta
		andi	$k1, $k0, 0x0400
		beq	$k1, $zero, salir

		# ...ha sido el detector de la puerta
		la	$k0, num_ev		#
		lw	$k1, 0($k0)		# cargamos el número de eventos actual
		addi	$k1, $k1, 1		# sumamos un evento
		sw	$k1, 0($k0)		# y guardamos

		addi	$k1, $k1, -1
		sll	$k1, $k1, 2		# multiplicamos por 4 el índice
		la	$k0, events		# cargamos la dirección de la base de datos
		add	$k0, $k0, $k1		# cambiamos la dirección a dirección_inicial + eventos*4
		li	$k1, 0xFFFF0304		#
		lw	$k1, 0($k1)		# cargamos la fecha y hora
		sw	$k1, 0($k0)		# y la guardamos en la base de datos
		

	salir:
		mfc0	$k0, $14
		addi	$k0, $k0, 4
		rfe
		jr	$k0



# Implementar la subrutina "DOOR" que cuenta la cantidad de accesos que detecta el sensor de la puerta
# en un periodo de tiempo dado como argumento.
		# $a0: inicio del periodo de tiempo
		# $a1: fin del periodo de tiempo
		# $v0: cantidad de accesos detectados
# No modifica ningún registro (excepto $v0)

	DOOR:
		# guardamos registros que se van a modificar
		addi	$sp, $sp, -16
		sw	$t0, 0($sp)
		sw	$t1, 4($sp)
		sw	$t2, 8($sp)
		sw	$t3, 12($sp)

		la 	$t0, events			# $t0 guarda la dirección de la base de datos de eventos
		lw	$t1, -4($t0)			# $t1 guarda el número de eventos por procesar
		addi	$v0, $zero, $zero		# inicializamos cantidad de accesos detectados

	bucle_lectura:
		beq	$t1, $zero, retornar		# si no quedan eventos, volvemos
		lw	$t2, 0($t0)			# $t2 contiene el evento actual
		addi	$t0, $t0, 4
		addi	$t1, $t1, -1

		slt	$t3, $a0, $t2			# comprobamos si es mayor que el inicio del periodo
		beq	$t3, $zero, bucle_lectura	# si es menor, siguiente iteración

		# y si no...
		slt	$t3, $t2, $a1			# comprobamos si es menor que fin del periodo
		beq	$t3, $zero, bucle_lectura	# si es mayor que fin, siguiente iteración

		# y si no, se encuentra en el rango...
		addi	$v0, $v0, 1			# incrementamos los accesos

		j 	bucle_lectura			# repetimos

	retornar:
		# recuperamos el valor de los registros modificados
		lw	$t0, 0($sp)
		lw	$t1, 4($sp)
		lw	$t2, 8($sp)
		lw	$t3, 12($sp)
		addi	$sp, $sp, 16

		jr $ra
