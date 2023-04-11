# Modificar una cadena sustituyendo todos aquellos caracteres coincidentes con uno dado por
# un "*". La rutina encargada de ello devolverá la cantidad de caracteres modificados.
    	 .data
cadena:   	.asciiz  "abcabbaa"

	.text
	.globl main
main:	
	addi $a0, $0,0x60		# código ASCII de "a"
	la $a1, cadena		# $a1 contiene la dirección de la cadena
	addi $a2, $0,8		# $a2 contiene el tamaño de la cadena
	jal cambiacaracter
	
	# mostrar por pantalla la cantidad de caracteres sustituidos
	add $a0, $v1, $0
	addi $v0, $0, 1
	syscall

	# mostrar por pantalla la nueva cadena (cadena modificada)
	add $a0, $a1, $0
	addi $v0, $0, 4
	syscall

fin:
	addi $v0, $0, 10
	syscall


# Rutina para sustituir los caracteres de una cadena dada que coincidan con otro caracter dado.
# También se devuelve la cantidad de caracteres modificados.
# Parámetros:
#	$a1: dirección de la cadena
#	$a2: tamaño de la cadena
# Retorno:
#	$v1: cantidad de caracteres modificados
cambiacaracter:
	add $t0, $0, $a1			# $t0: copia de la dirección de la cadena, para modificarla
	add $v1, $0, $0			# $v1: cantidad de caracteres modificados
	addi $t7, $0, 0x2A			# $t7: código ASCII para "*"

	bucle_cad:
		beq $a2, $0, salir
		lb $t1, 0($t0)		# $t1: carácter actual de la cadena
		bne $t1, $a0, incremento
		sb $t7, 0($t0)
		addi $v1, $v1, 1

	incremento:
		addi $t0, $t0, 1
		addi $a2, $a2, -1
		j bucle_cad

	salir:
		jr $ra