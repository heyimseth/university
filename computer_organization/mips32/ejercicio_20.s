# Hacer un programa en ensamblador MIPS que testee continuamente el contenido
# de la dirección de memoria 0xffff0000, y cuando en este posición se encuentre
# un número distinto de 9, debe llenar una tabla de datos (tamaño byte) definida
# en memoria de tamaño 20 bytes con los valores 0xa y 0xb alternativamente.

#segmento de datos
.data
	tabla: .space 20


#segmento de texto
.text
.globl main

main:
	li		$t0, 0xffff0000			# cargamos la dirección de memoria en $t0
	addi	$t1, $0, 9				# $t1 = $0 + 9

	bucle:
		lw		$t2, 0($t0)			# obtenemos la palabra almacenada
		beq		$t1, $t2, fin
			
		addi	$t3, $0, 20			# $t3 = $0 + 20
		la		$t4, tabla			# guardamos la dirección de tabla en $t4
		addi	$t5, $0, 10			# $t5 = $0 + 10
		addi	$t6, $0, 11			# $t6 = $0 + 11		
		
		rellenar:
			beq		$t3, $0, continuar
			sw		$t5, 0($t4)				# guardamos 0xa en tabla
			addi	$t3, $t3, -4			# $t3 = $t3 - 4
			addi	$t4, $t4, 4				# $t4 = $t4 + 4
			
			beq		$t3, $0, continuar
			sw		$t6, 0($t4)				# guardamos 0xb en tabla
			addi	$t3, $t3, -4			# $t3 = $t3 - 4
			addi	$t4, $t4, 4				# $t4 = $t4 + 4
			beq		$t3, $0, continuar
			j rellenar


	continuar:
			sw		$t1, 0($t0)			# guardamos 9 en $t0 (para no ser infinito)
			j		bucle				# jump to bucle

fin:
	addi $v0,$0,10	# llamada al sistema para salir del programa
	syscall