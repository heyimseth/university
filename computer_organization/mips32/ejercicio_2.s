# Hacer un programa en ensamblador MIPS que sume los números 1024 y 30000h. El resultado debe
# guardarlo en memoria en la variable resultado.

#segmento de datos
.data
	resultado: .word 0

#segmento de texto
.text
.globl main

main:
	li $t0,0x30000	# almacena 0x30000 en $t0
	addi $t0,$t0,1024	# almacena en $t0 el resultado de sumar $t0 y 1024
	
	la $t1,resultado	# almacena en $t1 la dirección de memoria de resultado
	sw $t0,0($t1)	# almacena en la dirección $t1 la palabra guardada en $t0

fin:
	addi $v0,$0,10	#llamada al sistema para salir del programa
	syscall