#segmento de datos
.data
	tabla: .word 0, 7, 3, 4, -1, 5, 1
	elementos: .word 7
	resultado: .word 0

#segmento de texto
.text
.globl main

main:
	la $a0, tabla			# $a0 almacena la primera direccion de tabla
	la $a1, elementos
	lw $a1, 0($a1)			# $a1 almacena la cantidad de elementos a sumar
	addi $a2, $a2, 3		# $a2 almacena el numero con el que comparar si es mayor
	jal sumar_elementos

	la $t0, resultado
	sw $v0, 0($t0)			# guardamos el resultado de la suma en resultado

	add $a0, $0, $v0		# guardamos el resultado de la suma en $a0
	addi $v0, $0, 1			#
	syscall					# y llamamos al sistema para mostrar el resultado

fin:
	addi $v0,$0,10			#llamada al sistema para salir del programa
	syscall


sumar_elementos:
	add $v0, $0, $0

	bucle:
		beq $a1, $0, retorno	# si no quedan mas elementos a comprobar, salta a retorno
		lw $t0, 0($a0)			# $t0 almacena el numero actual a comparar
		addi $a0, $a0, 4		# cambiamos $a0 para que apunte a la siguiente direccion de memoria
		addi $a1, $a1, -1		# y decrementamos el numero de elementos a comprobar en 1

		slt $t1, $a2, $t0		# $t1 almacena 1 si $a2 < $t0, o 0 en caso contrario
		beq $t1, $0, bucle		# salta a bucle si $t1 = 0 (en la comparacion anterior, el elemento leido ha
								# resultado ser menor que el elemento que se indica a la funcion: $a2)

		add $v0, $v0, $t0		# suma el n�mero actual al resultado
		j bucle					# y vuelve a bucle

	retorno:
		jr $ra