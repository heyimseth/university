# Escribe una funcion que lea una cadena de caracteres introducidos desde el teclado,
# los escriba en memoria a partir de la posicion indicada en el registro $a0, y
# finalmente devuelva en el registro $v0 el numero de caracteres leidos. La cadena
# termina cuando se pulsa la tecla ESC (codigo 0x3B).
#
# Escribe una funcion que muestre por pantalla los datos que hay a partir de la
# direccion de memoria indicada en el registro $a0, teniendo en cuenta que la longitud
# de la cadena a mostrar esta en el registro $a1.
#
# Escribe un programa que llame a las dos funciones anteriores.

	.data
cadena:	.space 50


	.text
	.globl main
main:
	la $a0, cadena
	jal leer_cadena					# llamamos a funcion de leer cadena

	la $a0, cadena
	add $a1, $v0, $0
	jal mostrar_cadena				# llamamos a funcion de mostrar cadena

fin:
	addi $v0, $0, 10
	syscall


leer_cadena:
	add $v0, $0, $0					# $v0 contiene la cantidad de caracteres leidos
	li $t0, 0xffff0000				# $t0 contiene la direccion base de los puertos de E/S 
	addi $t1, $0, 0x3B				# $t1 contiene el caracter de salida

	buclelectura:
		lw $t2, 0($t0)				# leemos puerto de estado del teclado
		andi $t2, $t2, 1			# aislamos el bit de estado del teclado
		beq $t2, $0, buclelectura	# preguntamos si esta activo

		lb $t3, 4($t0)				# recogemos el caracter del teclado
		beq $t3, $t1, rtnlectura	# si el caracter es el de salida, salimos de la funcion
		
		sb $t3, 0($a0)				# guardamos el caracter leido
		addi $a0, $a0, 1			# pasamos al siguiente byte de la direccion
		addi $v0, $v0, 1			# incrementamos la cantidad de caracteres leidos

		j buclelectura

	rtnlectura:
		sb $0, 0($a0)				# guardamos byte nulo al final de la cadena
		jr $ra


mostrar_cadena:
	li $t0, 0xffff0000				# $t0 contiene la direccion base de los puertos de E/S

	bucleescritura:
		lw $t3, 8($t0)				# leemos puerto de estado del monitor
		andi $t3, $t3, 1			# aislamos el bit de estado del monitor
		beq $t3, $0, bucleescritura	# preguntamos si esta activo

		beq $a1, $0, rtnescritura

		lb $t1, 0($a0)
		sb $t1, 12($t0)				# mostrar el caracter por pantalla

		addi $a1, $a1, -1			# reducimos la cantidad de caracteres a mostrar
		addi $a0, $a0, 1			# pasamos al siguiente caracter

		j bucleescritura

	rtnescritura:
		jr $ra