# Hacer un programa en ensamblador MIPS que sume los números 200h y 300h dados como valores
# inmediatos. El resultado debe guardarlo en memoria en la variable resultado.

# segmento de datos
.data
	resultado: .word 0

# segmento de texto
.text
.globl main

main:
	addi $t0,$0,0x200	# sumar 0x200 a $0 y guardar el resultado en $t0
	addi $t0,$t0,0x300	# sumar 0x300 a $t0 y guardar el resultado en $t0

	la $t1,resultado	# guarda en $t1 la dirección de memoria de resultado
	sw $t0,0($t1)	# guarda en la dirección de memoria almacenada en $t1 la
		# palabra almacenada en $t0
fin:
	addi $v0,$0,10	# llamada al sistema para salir del programa
	syscall