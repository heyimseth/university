# Supóngase una entrada a un edificio que disponga de un sensor de luminosidad
# y de 8 dispositivos LED. Estos dispositivos se controlan mediante un computador
# basado en MIPS. El sensor de luminosidad está asociado al nivel de petición de
# interrupción IP7, de tal forma que cuando se detecte un nivel de luminosidad
# por debajo de 20, se activará la interrupción asociada al nivel IP7. Suponer
# que tenemos el control del encendido y apagado de los 8 dispositivos LED
# asociado al puerto de control 0xFFFF0000. Para activar los dispositivos LED se
# deberá poner a 1 los bits 0-7 de dicho puerto y para desactivarlos se deberá
# poner a 0 dichos bits.

# a) Realiza un programa que desactive los 8 dispositivos LED y desenmascare la
# interrupción del nivel IP7 dejando las demás como estaban.

		.text
		.globl 	main
	main:
		# Desactivar dispositivos
		li	$t0, 0xFFFF0000
		li	$t1, 0xFFFFFF00
		sw	$t1, 0($t0)

		# Desenmascarar interrupción
		mfc0	$t0, $12
		ori	$t0, $t0, 0x8000
		mtc0	$t0, $12



# b) Realizar una subrutina de tratamiento a la interrupción que:
#	1) Inicialmente salve y finalmente recupere los registros que modifica.
#	2) Determine si el sensor de luminosidad fue el causante de la interrupción.
#	3) Active los 8 dispositivos LED en caso afirmativo.
#	4) Regrese al programa reactivando las interrupciones.

		.text	0x80000080

		# Comprobar si ha sido interrupción externa
		mfc0	$k0, $13
		andi	$k1, $k0, 0x3C
		bne	$k1, $zero, salir

		# Comprobar si ha sido IP7
		andi	$k1, $k0, 0x8000
		beq	$k1, $zero, salir

		# Tratamiento de IP7
		li	$k0, 0xFFFF0000
		li	$k1, 0xFFFFFFFF
		sw	$k1, 0($k0)

	salir:
		mfc0	$k0, $14
		addi	$k0, $k0, 4
		rfe
		jr	$k0



# c) Se modifica el ejercicio anterior para atender al sensor de luminosidad por
# consulta de estado. El puerto de estado del sensor de luminosidad es 0xFFFF0500 y
# el puerto de datos es 0xFFFF0504, de forma que si el bit 6 del puerto de estado
# está a 1, se podrá leer el valor de luminosidad. Realizar una subrutina que active
# los dispositivos LED en el caso que el nivel de luminosidad esté por debajo de 20.

	lumin:
		li	$t0, 0xFFFF0500			# $t0 - Puerto de estado

		consulta:
			lw	$t1, 0($t0)		# $t1 - contenido puerto de estado
			andi	$t1, $t1, 0x40		# aislar bit de estado
			beq	$t1, $zero, consulta	# repetimos si no hay dato

		# Leer valor de luminosidad
		lw	$t1, 4($t0)
		slti	$t2, $t1, 20			#
		beq	$t2, $zero, fin			# si es mayor que 20, repetimos

		# Y si es menor que 20, activamos dispositivos
		li	$t1, 0xFFFF0000
		li	$t2, 0xFF
		sw	$t2, 0($t1)

	fin:
		jr	$ra
