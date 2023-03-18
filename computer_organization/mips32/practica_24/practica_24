#segmento de datos
.data
	a: .word 0x50, 0x60, 0x70, 0, 0, 0, 0, 0x090
	b: .word 1, 3, 5, 7, 9, 11, 13, 15
	c: .word 2, 4, 6, 8, 0x10, 0x12, 0x14, 0x16
	v1: .space 32
	v2: .space 32
	sumando: .word 0


#segmento de texto
.text
.globl main

main:
	# preparación de parámetros para primera llamada
	la $a0, a	# $a0 apuntará a las direcciones de a
	la $a1, b	# $a1 apuntará a las direcciones de b
	addi $a2, $0, 8	# $a2 contendrá el número de elementos a sumar
	la $a3, v1	# $a3 apuntará a las direcciones de v1 (resultado)
	add $v1, $0, $0	# $v1 contendrá el valor de retorno
	
	jal suma_vector	# salta a suma_vector
	add $a0, $0, $v1	# guarda en $a0 el valor devuelto por suma_vector
	la $t0, sumando	# guarda en $t0 la dirección de sumando
	sw $a0, 0($t0)	# guarda en la dirección de memoria de sumando el valor devuelto por suma_vector
	addi $v0, $0, 1	# mostrar por pantalla el valor de sumando
	syscall

	# preparación de parámetros para segunda llamada
	la $a0, b	# $a0 apuntará a las direcciones de a
	la $a1, c	# $a1 apuntará a las direcciones de b
	addi $a2, $0, 3	# $a2 contendrá el número de elementos a sumar
	la $a3, v2	# $a3 apuntará a las direcciones de v1 (resultado)
	add $v1, $0, $0	# $v1 contendrá el valor de retorno
	
	jal suma_vector	# salta a suma_vector
	add $a0, $0, $v1	# guarda en $a0 el valor de sumando
	la $t0, sumando	# guarda en $t0 la dirección de sumando
	sw $a0, 0($t0)	# guarda en la dirección de memoria de sumando el valor devuelto por suma_vector
	addi $v0, $0, 1	# mostrar por pantalla el valor de sumando
	syscall


fin:
	addi $v0,$0,10	# llamada al sistema para salir del programa
	syscall


suma_vector:
	bucle:
		beq $a2, $0, fin_bucle	# saltará a fin_bucle cuando ya no queden elementos a sumar
		lw $t0, 0($a0)		# cargar en $t0 el valor de la posición actual del vector a
		lw $t1, 0($a1)		# cargar en $t1 el valor de la posición actual del vector b
		add $t2, $t0, $t1		# guarda en $t2 la suma de los elementos guardados en $t0 y $t1
		sw $t2, 0($a3)		# guarda en la posición actual de $a3 el valor de la suma
		add $v1, $v1, $t2		# sumar a sumando el resultado de la suma actual

		# incrementamos las direcciones de memoria a la siguiente posición
		addi $a0, $a0, 4
		addi $a1, $a1, 4
		addi $a3, $a3, 4

		# decrementamos la cantidad de elementos a sumar
		addi $a2, $a2, -1
		
		j bucle		# repite el bucle
	fin_bucle:
		jr $ra