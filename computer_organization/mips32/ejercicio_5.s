# Hacer un programa en ensamblador MIPS que:
#	·Defina en memoria una variable llamda num1 con el valor inicial 0x1234567F
#	·Defina en memoria una variable llamada num2 con el valor inicial 0xFFFFFFFF
#	·Ponga a cero los bits 2 y 3 del contenido de la variable num1 sin modificar los bits restantes.
#	·Ponga a cero los bits 3, 7 y 31 del contenido de la variable num2, sin modificar los bits restantes.

#segmento de datos
.data
	num1: .word 0x1234567F
	num2: .word 0xFFFFFFFF


#segmento de texto
.text
.globl main

main:
	# apartado 3)
	la $t0,num1		# guardamos la dirección de num1 en $t0
	lw $t1,0($t0)		# guardamos en $t1 la palabra almacenada en $t0
	andi $t1,$t1,0xFFF3		# and entre $t1 y 0xFFF3, y lo guarda en $t1
	sw $t1,0($t0)		# almacenar la palabra $t1 en la dirección $t0

	# apartado 4)
	la $t0,num2		# guardamos la dirección de num2 en $t0
	lw $t1,0($t0)		# guardamos en $t1 la palabra almacenada en $t0
	li $t2,0x7FFFFF77		# guardamos en $t2 la palabra 0x7FFFFF77
	and $t1,$t1,$t2		# guardar en $t1 el resultado de un AND entre $t1 y $t2
	sw $t0,0($t1)

fin:
	addi $v0,$0,10	#llamada al sistema para salir del programa
	syscall