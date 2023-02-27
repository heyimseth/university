# Hacer un programa en ensamblador MIPS que:
#	·Defina en memoria una variable llamada num1 con el valor inicial 0xF2345670 y una variable
#	 num2 con valor inicial 0.
#	·Lea el contenido de la variable num1, ponga a uno los bits 0 y 1, y ponga a cero los bits 30 y 31
#	 (sin modificar los bits restantes) y el resultado lo ponga en num2.

#segmento de datos
.data
	num1: .word 0xF2345670
	num2: .word 0


#segmento de texto
.text
.globl main

main:
	la $t0,num1	# cargar la direccion de memoria de num1
	lw $t1,0($t0)	# cargar en $t1 el valor almacenado en num1
	li $t2,0x3FFFFFFF	# cargar en $t2 el numero utilizado para modificar los bits 30 y 31

	ori $t1,$t1,0x3	# poner a uno los bits 0 y 1
	and $t1,$t1,$t2	# poner a 0 los bits 30 y 31
	
	la $t2,num2	# cargar la dirección de memoria de num2
	sw $t1,0($t2)	# guardar el resultado almacenado en $t1 en la dirección de num2


fin:
	addi $v0,$0,10	#llamada al sistema para salir del programa
	syscall