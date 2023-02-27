# Hacer un programa en ensamblador MIPS que sume los números 200h y 300h que están
# almacenados en memoria en las variables NUM1 y NUM2. El resultado debe guardarlo en
# memoria en la variable resultado.

#segmento de datos
.data
	NUM1: .word 0x200
	NUM2: .word 0x300
	resultado: .word 0

#segmento de texto
.text
.globl main

main:
	la $t0,NUM1	# guarda en $t0 la dirección de memoria de NUM1
	lw $t1,0($t0)	# guarda en $t1 la palabra almacenada en la dirección $t0
	lw $t2,4($t0)	# guarda en $t2 la palabra almacenada en la dirección $t0+4
		# bytes

	add $t2,$t1,$t2	# suma $t1 y $t2, y guarda el resultado en $t3
	sw $t2,8($t0)	# guarda en $t0+8 bytes, la palabra almacenada en $t3

fin:
	addi $v0,$0,10	#llamada al sistema para salir del programa
	syscall