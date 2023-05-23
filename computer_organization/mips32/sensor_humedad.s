# Realizar un programa en ensamblador para el procesador MIPS que lea un sensor de
# humedad por consulta de estado y en el caso de que la humedad leída sea menor del
# 20% se active un dispositivo de regadío durante 30 minutos.

# El sensor de humedad tiene asociado su puerto de estado a la dirección 0xFFFF6000
# y su puerto de datos a la dirección 0xFFFF6004. El bit 18 del puerto de estado del
# sensor de humedad se pondrá a 1 para indicar que tiene un dato de humedad preparado
# y retornará a cero automáticamente cuando haya sido leído.

# Para activar el dispositivo de regadío se deberá poner a 1 el bit 24 del puerto
# 0xFFFF7000, dejando sin alterar los demás bits del puerto. Para apagarlo, dicho bit
# se deberá poner a 0.

# Para implementar el retardo se usará la subrutina delay_30, que produce un retardo
# de 30 minutos.

	.text
	.globl main

main:
	li	$t0, 0xFFFF6000
	li	$t1, 0xFFFF7000
	li	$t2, 0x1000000
	li	$t3, 0xFEFFFFFF

bucle:
	lw	$t4, 0($t0)
	srl	$t4, $t4, 3
	andi	$t4, $t4, 0x8000
	beq	$t4, $zero, bucle		# si no hay dato de humedad, repetir

	# y si hay dato...
	lw	$t4, 4($t0)			# leerlo
	slti	$t4, $t4, 20			#
	beq	$t4, $zero, bucle		# si es mayor que 20, repetir

	# y si es menor que 20...
	lw	$t4, 0($t1)			# cargar puerto regador
	or	$t4, $t4, $t2			# cambiar bit 24
	sw	$t4, 0($t1)			# guardar para iniciar el regador
	
	# esperar 30 minutos
	jal	delay_30

	# desactivar regador
	and	$t4, $t4, $t3
	sw	$t4, 0($t1)

	j bucle



# Suponer que, en el ejercicio anterior, cuando la humedad baja del 20% se activa la
# interrupción IP5. Realizar una subrutina de tratamiento de la interrupción que:
#	1) Inicialmente salve y finalmente recupere los registros que modifica.
#	2) Determine si el sensor de humedad fue el causante de la interrupción.
#	3) Encienda el dispositivo en caso afirmativo.
#	4) Regrese al programa reactivando las interrupciones.

	.text 0x80000080
	addi	$sp, $sp, -4
	sw	$ra, 0($sp)

	# Comprobar si ha sido interrupción externa
	mfc0	$k0, $13
	andi	$k1, $k0, 0x3F
	bne	$k1, $zero, salir

	# Comprobar si ha sido IP5
	andi	$k1, $k0, 0x2000
	beq	$k1, $zero, salir

	# ...interrupción de IP5
	li	$k0, 0xFFFF7000
	lw	$k1, 0($k0)			# cargar puerto del regador
	li	$k0, 0x1000000
	or	$k1, $k1, $k0			# cambiar bit 24
	li	$k0, 0xFFFF7000
	sw	$k1, 0($k0)			# iniciar regador

	# esperar 30 minutos
	jal delay_30

	# desactivar regador
	li	$k0, 0xFEFFFFFF
	and	$k1, $k1, $k0
	li	$k0, 0xFFFF7000
	sw	$k1, 0($k0)

salir:
	# recuperar estado previo de los registros y salir
	lw 	$ra, 0($sp)
	addi 	$sp, $sp, 4

	mfc0	$k0, $14
	addi	$k0, $k0, 4
	rfe
	jr	$k0
