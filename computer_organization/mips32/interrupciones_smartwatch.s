# Ejercicio 2: Programar la subrutina beats con las siguientes funcionalidades:
#	1. Inicia una lectura del pulso cardíaco.
#	2. Consulta el estado del pulsómetro hasta que la lectura se complete.
#	3. Actualiza las pulsaciones por minuto mostradas por pantalla.

beats:
	li $t0, 0xFFFF0400						# $t0: registro de estado del chip del reloj. (4-acelerómetro, 8-control)
	ori $t1, $zero, 0x8000					#
	sw $t1, 8($t0)							# inicia la lectura de pulsaciones
	
	bucle_pulsaciones:
		lw $t1, 8($t0)
		andi $t2, $t1, 0x4000				# aislar el bit de medición completada
		beq $t2, $zero, bucle_pulsaciones
	
	andi $a0, $t1, 0xFF						# guardar los bits que indican el pulso cardíaco en $v0
	addi $v0, $zero, 42						#
	syscall									# mostrar las pulsaciones por minuto

	jr $ra




# Ejercicio 3: Programar la subrutina display con las siguientes funcionalidades:
#	1. Consulta el chip de reloj y actualiza la fecha/hora mostrada por pantalla.
#	2. Si la hora es 00:00:00 se reinicia el contador de pasos diarios.
#	3. Actualiza la cantidad de pasos diarios mostrados por pantalla.
#	4. La subrutina no modifica el estado del procesador (lo que permitirá invocarla desde una RSI).

display:
	# guardar registros que se van a modificar
	addi $sp, $sp, -8
	sw $a0, 0($sp)
	sw $v0, 4($sp)

	li $k0, 0xFFFF0400						# $k0: registro de estado del chip del reloj. (4-acelerómetro, 8-control)
	lw $a0, 0($k0)
	addi $v0, $zero, 40						#
	syscall									# mostrar por pantalla la fecha y hora

	bne $a0, $zero, mostrar_pasos
	sw $zero, 4($k0)						# poner los pasos a 0

	mostrar_pasos:
		lw $a0, 4($k0)
		addi $v0, $zero, 41					#
		syscall								# mostrar por pantalla la cantidad de pasos


	# recuperar el valor previo en los registros modificados
	lw $a0, 0($sp)
	lw $v0, 4($sp)
	addi $sp, $sp, 8

	jr $ra



# Ejercicio 4: Programar una RSI que:
#	1. Detecte la interrupción del reloj (que se produce cada minuto).
#	2. Invoque la rutina display.

RSI:
	.text 0x80000080
	# PUSH
	addi $sp, $sp, -4
	sw $ra, 0($sp)

	# Consulta código
	mfc0 $k0, $13
	sra $k0, $k0, 2
	andi $k1, $k0, 0xF
	bne $k1, $zero, exit

	# Comprueba si ha sido interrupción 4 (registro de estado)
	andi $k1, $k0, 0x1000
	beq $k1, $zero, exit
	jal display

	# POP
	lw $ra, 0($sp)
	addi $sp, $sp, 4

	exit:
		mfc0 $k0, $14
		addi $k0, $k0, 4
		rfe
		jr $k0