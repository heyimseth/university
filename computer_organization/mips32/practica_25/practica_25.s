#segmento de datos
	.data
cadenao:	.asciiz  "123 n f" #acaba la cadena con caracter nulo
cadenad:	.space 10
eliminados:	.word 0
string:	.asciiz "la cantidad de espacios eliminados es"

# segmento de texto
	.text
	.globl main
main:	
	la $a0,cadenao			# $a0 contiene la direccion de memoria de cadenao
	la $a1,cadenad			# $a1 contiene la direccion de memoria de cadenad
	jal eliminar_espacios 	# Llamada a la funcion		

	la $t0, eliminados		
	sw $v0,0($t0)			# escribo en memoria resultado

	la $a0, string
	li $v0, 4
	syscall   				# llamada al sistema para imprimir "la cantidad de espacios eliminados es"
	
	la $t0,eliminados
	lw $a0,0($t0)
	addi $v0, $0, 1			# llamada al sistema para imprimir eliminados 
	syscall	

	addi $v0, $0, 10		# llamada al sistema para salir del programa
	syscall	


#===============rutina eliminar_espacios
eliminar_espacios:
	addi $t2, $0, 0x20			# $t2 es el caracter espacio a comparar
	add $t4, $0, $0				# $t4 es el contador de espacios
	addi $sp, $sp, -4
	sw $ra, 0($sp)				# guarda el $ra en la pila
	addi $sp, $sp, -4
	sw $a1, 0($sp)

	bucle:
		lb $t3, 0($a0)			# $t3 almacena el caracter actual
		beq $t3, $t2, espacio	# salta a incremento si el caracter es un espacio
		sb $t3, 0($a1)			# guarda $t3 en la direccion de $a1

	incremento:
		addi $a0, $a0, 1		# incrementa en un byte la direccion de $a0
		beq $t3, $0, salir		# si el caracter en $t3 es el nulo, va a salir
		j bucle
	
	espacio:
		addi $t4, $t4, 1		# incrementa el contador de espacios
		addi $a1, $a1, 1		# incrementa en un byte la direccion de $a1
		j incremento
		

	salir:
		la $t5, eliminados		
		sw $t4, 0($t5)			# guarda el contador en eliminados

		jal imprimircadena		

		lw $ra, 0($sp)
		jr $ra


#======== subrutina que imprime la cadena cuya direccion esta en la cima de la pila
imprimircadena:
	lw $a0,0($sp)   			# desapilo en $a0
	addi $sp,$sp,4
	addi $v0, $0, 4				# llamada al sistema para imprimir cadena destino 
	syscall	
	jr $ra						# retorno al programa llamante
