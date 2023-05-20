# Un cuadricóptero incorpora un sistema de navegación basado en arquitectura MIPS. Un dispositivo periférico LiDAR
# proporciona al drone información sobre los obstáculos a su alrededor mediante un haz láser radial. El periférico
# está asociado al nivel de interrupción 5 y dispone de dos registros mapeados a partir de la dirección 0xFFFF0100.

# Ejercicio 3 - Completa el programa principal para
#	1) Definir la etiqueta data: con espacio para albergar toda la información proporcionada por el LiDAR.
#	2) Activar el dispositivo, configurando un flujo de datos de una vuelta/segundo con una resolución de 1º
#	3) Desenmascarar la interrupción correspondiente (sin alterar el resto)


		.data
rotors:	.word 0,0,0,0
data:		.space 1440


		.text
		.globl main
main:
		li $t0, 0xFFFF0100				# $t0 contiene la dirección del registro de control


		# Activar dispositivo
		lw $t1, 0($t0)					# $t1 contiene el registro de control
		li $t2, 0x10040168
		or $t1, $t1, $t2
		sw $t1, 0($t0)					# guardamos la modificación del registro de control


		# Desenmascarar interrupción
		mfc0 $t2, $12
		ori $t2, $t2, 0x2000				# desenmascarar IM4
		mtc0 $t2, $12

		jal navigation					# Salta a la rutina que gestiona la navegación

		li $v0, 10
		syscall						# Fin de programa



# Ejercicio 4 - Implementar la RSI que
#	1) Inicialmente salve y finalmente recupere los registros que modifica.
#	2) Determine si el dispositivo LiDAR fue el causante de la interrupción.
#	3) Salte a la subrutina de gestión "LiDAR" (en caso afirmativo).
#	4) Retorne reactivando las interrupciones.


		.text 0x80000080
		# PUSH
		addi $sp, $sp, -4
		sw $ra, 0($sp)

		# Consultar código de excepción 
		mfc0 $k0, $13
		sra $k1, $k0, 2
		andi $k1, $k1, 0xF
		bne $k1, $zero, exit

		# Comprobar si ha sido el dispositivo LiDAR
		andi $k1, $k0, 0x2000
		beq $k1, $zero, exit
		jal lidar

	exit:
		# POP
		lw $ra, 0($sp)
		addi $sp, $sp, 4

		mfc0 $k0, $14
		addi $k0, $k0, 4
		rfe
		jr $k0



# Ejercicio 5 - Implementar la subrutina "LiDAR" que
#	1) Inicialmente salve y finalmente recupere los registros que modifica
#	2) Vuelque el dato proporcionado por el LiDAR al lugar correcto
#	3) Detenga los motores si la distancia detectada es menor de 1 metro (poner cero en 4 direcciones)
	

	lidar:
		# PUSH
		addi $sp, $sp, -4
		sw $t0, 0($sp)

		# Guardar dato
		li $t0, 0xFFFF0100
		lw $t0, 4($t0)					# $t0 contiene el dato leído
		andi $k1, $t0, 0xFFFF 				# aislar distancia en $k1
		sra $k0, $t0, 16				#
		andi $k0, $k0, 0x3FFF				# aislar ángulo en $k0
		
		la $t0, data
		add $t0, $t0, $k0				#
		sw $t0, 0($k1)					# guardamos en la dirección de data+ángulo
		
		# Comprobar distancia
		li $k0, 0x3E8					# 1 m = 1000 mm
		slt $t0, $k1, $k0				# comprobamos si la distancia leída ($k1) es menor que 1m ($k0)
		beq $t0, $zero, salir_lidar
		
		# Si la distancia era menor de 1 m, detener motores
		la $t0, rotors
		sw $zero, 0($t0)
		sw $zero, 4($t0)
		sw $zero, 8($t0)
		sw $zero, 12($t0)

	salir_lidar:
		# POP
		lw $t0, 0($sp)
		addi $sp, $sp, 4

		jr $ra
