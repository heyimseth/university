# Una sauna se controla mediante un computador basado en MIPS. Un sensor mide
# la humedad relativa del aire (entre 0% y 100%) y un humidificador añade
# humedad a la sauna.

# Para el sensor de humedad, la dirección del puerto de estado es 0xFFFF0030 y
# la dirección del puerto de datos es 0xFFFF0034. Para poder leer un valor de
# humedad válido se deberá comprobar que el bit 6 del registro de estado esté
# puesto a 1. Este bit se reseteará automáticamente cuando se produzca la
# lectura del puerto de datos del sensor de humedad.

# Realizar una subrutina que se llame Get_Hum, que lea un valor de humedad y
# lo guarde en la posición de memoria indicada por el registro a0. Esta
# subrutina sólo podrá modificar los registros temporales del procesador MIPS.

Get_Hum:
	li	$s0, 0xFFFF0030

	bucle_estado:
		lw 	$s1, 0($s0)			# cargamos puerto de estado
		andi	$s1, $s1, 0x40			# aislamos bit 6
		beq	$s1, $zero, bucle_estado	# si es 0 no hay dato, repetimos

	lb 	$a0, 4($s0)				# cargamos el dato en a0
	jr	$ra					# retornamos



# Realizar una subrutina que se llame Humidif, que active el humidificador de
# la sauna. La dirección del puerto de estado/control del humidificador es
# 0xFFFF0050. Para activar el humidificador se deben poner los bits 0 y 1 del
# puerto de estado/control a 1. Esta subrutina no podrá modificar ningún
# registro del procesador MIPS.

Humidif:
	# Guardar valores de registros
	addi 	$sp, $sp, -8
	sb	$t0, 0($sp)
	sb	$t1, 4($sp)
	
	# Activar humidificador
	li	$t0, 0xFFFF0050				# puerto del humidificador
	lb	$t1, 0($t0)				# valor del puerto
	ori	$t1, $t1, 0x3				# cambiamos los bits 0 y 1
	sb	$t1, 0($t0)				# iniciamos humidificador

	# Restaurar valores de registros
	lb	$t0, 0($sp)
	lb	$t1, 4($sp)
	addi	$sp, $sp, 8

	jr	$ra



# Realizar un programa principal que:
#	1) Reserve espacio para 40000 valores de humedad relativa.
#	2) Llame a la subrutina Get_Hum para leer y guardar la humedad relativa.
#	3) Llame a la subrutina Humidif si la humedad relativa es inferior al 30%.
#	4) Cuando se hayan guardado 40000 valores de humedad relativa acabará el
#		programa.

		.data
valores:	.space 40000

		.text
		.globl main
main:
		li	$t0, 40000
		la	$a0, valores

bucle_humedad:
		beq	$t0, $zero, fin			# si no quedan valores, salimos
		jal 	Get_Hum				# obtener humedad
		addi	$a0, $a0, 1
		addi	$t0, $t0, -1

		lb	$t1, -1($a0)			# cargamos el valor leído
		slti	$t2, $t1, 30			# comprobamos si es menor que 30...
		beq	$t2, $zero, bucle_humedad	# ...si no lo es, repetimos

		# ...y si lo es
		jal 	Humidif				# iniciamos humidificador

		j 	bucle_humedad

fin:
		li	$v0, 10
		syscall
