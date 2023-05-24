# El ayuntamiento dispone de un sistema controlador de semáforos implementado
# en arquitectura MIPS, y nos contrata para instalarlo en un cruce entre una
# avenida y una calle.

# Disponemos de un chip temporizador conectado a la interrupción 2 del
# procesador, capaz de regular hasta 4 intervalos alternativamente. El chip
# se programa mediante el registro de control mapeado en la dirección
# 0xFFFF0200 con formato
#   Registro de control del temporizador:
#	|31|...|24|23|...|16|15|...|08|07|...|00|
#	| Interv1 | Interv2 | Interv3 | Interv4 |
#		-Intervalos en segundos (máx. 255 segundos)
#		-Asignar intervalo = 0 para desactivarlo.

# ¿Cuál sería el valor del registro de control, expresado en hexadecimal, para
# programar:
#	-01:55m - Avenida abierta al tráfico.
#	-00:05m - Tiempo para que los peatones terminen de cruzar la calle.
#	-00:45m - Calle abierta al tráfico.
#	-00:15m - Tiempo para que los peatones terminen de cruzar la avenida.

#		0111 0011 0000 0101 0010 1101 0000 1111
#		0x73052D0F



# El sistema dispone de un registro de control de las luces mapeado en la
# dirección 0xFFFF0300 con el siguiente formato:
#	|15|14|13|12|11|10|09|08|07|06|05|04|03|02|01|00|
#	|   coche   |   peatón  |   coche   |   peatón  |
#	|X |R |A |V |B |R |P |V |X |R |A |V |B |R |P |V |
#	|         AVENIDA       |	   CALLE        |
#	-X: no conectado
#	-B: botón de peatones
#	-P: luz parpadeante
#	-R/V/A: rojo/verde/amarillo
#	Modo: 1 - encendido/pulsado, 0 - apagado

# Definir el valor del registro de control para programar los comportamientos
# anteriores.
#	-Avenida abierta al tráfico: 0001 0100 0100 0001 (0x1441)
#	-Tiempo para terminar de cruzar la calle: 0010 0100 0100 0010 (0x2442)
#	-Calle abierta al tráfico: 0100 0001 0001 0100 (0x4114)
#	-Tiempo para terminar de cruzar la avenida: 0100 0010 0010 0100 (0x4224)



# Realizar un programa principal que:
#	1) Defina un dato state que represente el estado del semáforo, y que
#		variará entre 0, 1, 2 y 3.
#	2) Defina cuatro datos asociados a la configuración del semáforo para
#		cada posible estado.
#	3) Configure y active el temporizador con la información del primer
#		apartado.
#	4) Mediante consulta de estado, detecte la pulsación de un botón y salte
# 		a una hipotética subrutina buttons.
#	5) Realice el paso anterior indefinidamente.

		.data
state:		.word 0
state0:		.word 0x1441
state1:		.word 0x2442
state2:		.word 0x4114
state3:		.word 0x4224

		.text
		.globl main
main:
		# Configurar y activar temporizador
		li	$t0, 0x73052D0F			# configuración de tiempo
		li	$t1, 0xFFFF0200			# puerto de control del temporizador
		sw	$t0, 0($t1)			# guardar configuración

		li	$t0, 0xFFFF0300			# registro de control de luces

consulta:
		lw	$t1, 0($t0)			# cargamos puerto de control
		andi	$t1, $t1, 0x0808		# aislamos bits de botones
		beq	$t1, $zero, consulta		# repetimos si no se ha pulsado botón

		jal	buttons				# saltamos a buttons si se ha pulsado
		j 	consulta

fin:
		li	$v0, 10
		syscall



# Realizar una RSI que:
#	1) Se ejecute cada vez que se dispare el temporizador.
#	2) Avance cíclicamente el estado del semáforo.
#	3) Actualice las diferentes luces, a partir de la tabla definida para
#		los estados.

		.text 0x80000080
		# Comprobar si es interrupción externa
		mfc0	$k0, $13
		andi	$k1, $k0, 0x3C
		bne	$k1, $zero, salir

		# Comprobar IP2
		andi	$k1, $k0, 0x400
		beq	$k1, $zero, salir
		
		la	$k0, state0			# cargamos dirección de primer estado
		lw	$k1, -4($k0)			# cargamos número de estado
		addi	$k1, $k1, 1			#
		andi	$k1, $k1, 0x3			# pasamos al siguiente estado
		sw	$k1, -4($k0)			# y lo guardamos


		sll	$k1, $k1, 2			# multiplicamos por 4 (bytes)
		add	$k0, $k0, $k1			# posicionamos en la dirección del estado actual
		lw	$k0, 0($k0)			# cargamos el estado actual
		li	$k1, 0xFFFF0300			#
		sw	$k0, 0($k1)			# y lo guardamos en el puerto de control de luces

salir:
		mfc0	$k0, $14
		addi	$k0, $k0, 4
		rfe
		jr	$k0
