# Una central nuclear tiene una malla de 256x64 sensores inalámbricos monitorizando
# la temperatura de la cubierta que rodea al reactor. Los sensores se gestionan con
# un controlador global que, cuando detecta un cambio de temperatura, provoca una
# interrupción de nivel 3 y deja la información en el registro
#   Registro de estado de la WSN: 0xFFFF1000
#	|31   ...   24|23   ...   16|15   ...   08|07   ...   00|
#	|   00000000  | temperatura | coordenadaY | coordenadaX |
#			rango:0-255º  rango:0-63º   rango:0-255º

# Implementar una RSI que recoja el dato del sensor y lo coloque en la posición de
# memoria correspondientes en la tabla direccionada por WSN.
# Ayuda: memoria(x,y) = wsn + 256*y + x

		.data
wsn:		.space	16384

		.text 	0x80000080
		# PUSH
		addi	$sp, $sp, -4
		sw	$t0, 0($sp)

		# Comprobar si ha sido interrupción externa
		mfc0 	$k0, $13
		andi	$k1, $k0, 0x3C
		bne	$k1, $zero, salir

		# Comprobar si ha sido IP3
		andi	$k1, $k0, 0x800
		beq	$k1, $zero, salir

		li	$k0, 0xFFFF1000
		lw	$k0, 0($k0)			# $k0 contiene el registro de estado
		andi	$t0, $k0, 0xFFFF		# $t0 contiene coordenada Y*256 + X
		la	$k1, wsn			# $k1 contiene dirección de wsn
		add	$t0, $t0, $k1			# $t0 contiene wsn + 256*Y + X

		sra	$k0, $k0, 16
		sb	$k0, 0($t0)			# guardamos temperatura leída en $t0
		
salir:
		# POP
		lw	$t0, 0($sp)
		addi	$sp, $sp, 4
		
		mfc0	$k0, $14
		addi	$k0, $k0, 4
		rfe
		jr	$k0
