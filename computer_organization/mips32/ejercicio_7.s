# En memoria tenemos definidas tres variables tipo word con valor inicial 5555, 0x15b3 y 0
# respectivamente. Hacer un programa en ensamblador MIPS para que, si el contenido de
# las dos primeras variables es el mismo, ponga un 5 en la tercera variable, y en caso
# contrario ponga un 1.

#segmento de datos
.data
	num1: .word 5555
	num2: .word 0x15b3
	num3: .word 0


#segmento de texto
.text
.globl main

main:
	la $t0,num1	# cargamos la dirección de memoria de num1 en $t0
	lw $t0,0($t0)	# cargamos la palabra almacenada en $t0 en $t0
	la $t1,num2	# cargamos la dirección de memoria de num2 en $t1
	lw $t1,0($t1)	# cargamos la palabra almacenada en $t1 en $t1
	la $t2,num3	# cargamos la dirección de memoria de num3 en $t2


	beq $t1,$t0,igual	# si $t0 y $t1 son iguales, saltar a "igual"
	addi $t3,$0,1	# guardar un 1 en $t3
	sw $t3,0($t2)	# guardar el valor de $t3 en la dirección cargada en $t2
	j fin	# saltar a fin

	igual:
		addi $t3,$0,5  	# guardar 5 en $t3 (solo si num1 y
			# num2 son iguales)
		sw $t3, 0($t2)	# guardar el valor de $t3 en la dirección
			# cargada en $t2
fin:
	addi $v0,$0,10	#llamada al sistema para salir del programa
	syscall