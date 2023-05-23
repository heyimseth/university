# Una cinta transportadora incorpora un sistema basado en MIPS.
# Tiene un motor y un sensor óptico controlados a través de este
# registro mapeado en la dirección 0xFFFF6000.

#	|15|14|13|12|11|10|09|08|07|06|05|04|03|02|01|00|
#	|volt |  | vel |  |  M  |  |    luz    |     |O |

#	-volt: configuración eléctrica.
#		00 - 120V 50Hz
#		01 - 120V 60Hz
#		10 - 230V 50Hz
#		11 - 230V 60Hz
#	-vel: configuración de velocidad de la cinta.
#		00 - 5  cm/s
#		01 - 10 cm/s
#		10 - 15 cm/s
#		11 - 20 cm/s
#	-M: modo de funcionamiento de la cinta.
#		00 - detenida
#		01 - avance
#		10 - retroceso
#		11 - bloqueada
#	-luz: [0-15]*10 lúmenes de intensidad del diodo LED.
#	-O: estado del sensor.
#		0 - objeto no detectado.
#		1 - objeto detectado.

# Implementar un programa principal que:
#	a) Configure el motor para funcionar a 230V 50Hz, una velocidad
#	de 20 cm/s y modo detenido.
#	b) Configure el sensor a 60 lúmenes.
#	c) Todo el tiempo, la cinta avanza si el sensor no detecta un
#	obstáculo.

	.text
	.globl 	main
main:
	li 	$t0, 0xFFFF6000
	li 	$t1, 0x9830

bucle:
	sw 	$t1, 0($t0)			# configurar dispositivo
	lw 	$t1, 0($t0)			#
	andi 	$t1, $t1, 0xFCFF		# próximo estado: bloqueado
	andi 	$t2, $t1, 0x1			# comprobar si hay objeto
	bne 	$t2, $zero, bucle		# si hay objeto, repetimos y bloquea
	ori 	$t1, $t1, 0x0100		# y si no hay, próximo estado: avance
	j 	bucle

fin:
	addi 	$v0, $zero, 10
	syscall



# Observamos que la implementación anterior consume demasiado tiempo de procesador
# y decidimos utilizar la interrupción IP7, que se activa cuando cambia el estado
# del LED. Implementar el comportamiento del ejercicio anterior dentro de la RSI.

	.text 	0x80000080
	# Comprobar si es interrupción externa
	mfc0 	$k0, $13
	srl 	$k1, $k0, 2
	andi 	$k1, $k1, 0xF
	bne 	$k1, $zero, salir

	# Comprobar si es IP7
	andi	$k1, $k0, 0x8000
	beq	$k1, $zero, salir		# si no es IP7, salimos

	# ...y si es IP7
	andi 	$k0, $k0, 0xFCFF		# próximo estado: bloqueado
	andi 	$k1, $k0, 0x1			# comprobamos si hay objeto
	bne	$k1, $zero, guardar		# si hay objeto, guardamos bloqueado
	ori	$k0, $k0, 0x100			# y si no hay, próximo estado: avance

guardar:
	li	$k1, 0xFFFF6000			#
	sw	$k0, 0($k1)			# guarda estado

salir:
	mfc0	$k0, $14
	addi 	$k0, $k0, 4
	rfe
	jr $k0
