#segmento de datos
.data
	tabla: .word 0, 7, 3, 4, -1, 5, 1
	resultado: .word 0

#segmento de texto
.text
.globl main

main:
	addi $t0, $0, 7		# $t0 almacena la cantidad de elementos restantes a comprobar
	la $t1, tabla		# $t1 almacena la direccion de tabla
	
	add $t5, $0, $0
	
bucle:
	beq $t0, $0, fin	# si ya no quedan mas elementos a comprobar, salta a fin
	lw $t3, 0($t1)		# guarda en $t3 el siguiente valor de tabla
	addi $t1, $t1, 4	# pasa a la direccion siguiente de tabla
	addi $t0, $t0, -1	# decrementa el numero de elementos a sumar
	slti $t4, $t3, 4	# guarda en $t4 un 1 si el valor en $t3 es menor que 4
	
	beq $t4, $0, suma	# si $t3 es 0, salta a suma para sumar el elemento
	j bucle

suma:
	add $t5, $t5, $t3	# suma el valor en $t3 a $t5 (resultado)
	j bucle


fin:
	la $t2, resultado	# $t2 almacena la direccion de resultado
	sw $t5, 0($t2)		# almacena el resultado de la suma en la direccion de resultado
	addi $v0,$0,10		# llamada al sistema para salir del programa
	syscall