#segmento de datos
.data
	vector1: .word 0x19283, 12, 4, 0x1392, 0x19823410, 0, 26, 0x923
	vector2: .word 0, 0x82731, 6, 3, 0x989872, 0x7263512, 0x18274638, 3
	num_ele: .word 8

#segmento de texto
.text
.globl main

main:
	la $t0, vector1	# cargamos en $t0 la dirección de memoria de vector1
	la $t1, vector2	# cargamos en $t1 la dirección de memoria de vector2
	lw $t2, 32($t1)	# cargamos en $t2 el dato almacenado en num_ele

bucle:
	beq $t2, $0, fin	# si $t2 es igual a 0, salimos del bucle
	lw $t3, 0($t0)	# cargamos en $t3 el dato almacenado en $t0
	lw $t4, 0($t1)	# cargamos en $t4 el dato almacenado en $t0
	sw $t3, 0($t1)	# guardamos en $t1 el valor almacenado en $t3
	sw $t4, 0($t0)	# guardamos en $t0 el valor almacenado en $t4
	
	addi $t0, $t0, 4	# incrementamos la dirección almacenada en $t0 en 4
	addi $t1, $t1, 4	# incrementamos la dirección almacenada en $t1 en 4

	addi $t2, $t2, -1	# restamos 1 a $t2
	j bucle


fin:
	addi $v0,$0,10	#llamada al sistema para salir del programa
	syscall