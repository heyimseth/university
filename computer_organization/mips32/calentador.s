# Tenemos que calentar una habitación. Para ello disponemos de:
#	-Sensor de temperatura 1:
#		Puerto de estado: 0xFFFF7000, bit de estado 17
#		Puerto de datos: 0xFFFF7004
#	-Sensor de temperatura 2:
#		Puerto de estado: 0xFFFF7008, bit de estado 15
#		Puerto de control: 0xFFFF700C
#	-Generador de calor:
#		Puerto de control: 0xFFFF7500
#		Encendido poniendo el bit 5 a 1 (dejando el resto igual)
#		Se apaga solo transcurrido un cierto tiempo.

# Tenemos un procesador basado en MIPS para controlar el sistema anterior.
# Realizar un programa principal que atienda a los dos sensores de temperatura
# por consulta de estado. Tiene que leer la temperatura del sensor 1 y del
# sensor 2, y si alguna de ellas es menor que 15 grados, activar el generador
# de calor y llamar a la rutina retardo25 que tarda 25 minutos en ejecutarse
# (para dar tiempo a que suba la temperatura). El programa estará constantemente
# atendiendo a los sensores de temperatura. Deberá empezar siempre preguntando
# por el sensor 1.

	.text
	.globl main
main:
	li	$t0, 0xFFFF7000			# dirección base de los sensores
	li	$t1, 0xFFFF7500			# dirección del calentador

sensor1:
	# comprobar estado de sensor1
	lw	$t2, 0($t0)
	srl	$t2, $t2, 2
	andi	$t2, $t2, 0x8000
	bne	$t2, $zero, leer_temp1		# si el bit de estado es 1, leemos temperatura

sensor2:
	# comprobar estado de sensor2
	lw	$t2, 8($t0)
	andi	$t2, $t2, 0x8000
	bne $t2, $zero, leer_temp2		# si el bit de estado es 1, leemos temperatura

	j 	sensor1

leer_temp1:
	lw	$t2, 4($t0)
	slti	$t2, $t2, 15
	bne	$t2, $zero, calentador		# si temperatura < 15, iniciamos calentador
	j 	sensor2				# si no, volvemos a sensor2

leer_temp2:
	lw	$t2, 12($t0)
	slti	$t2, $t2, 15
	bne	$t2, $zero, calentador		# si temperatura < 15, iniciamos calentador
	j 	sensor1				# si no, volvemos a sensor1

calentador:
	# alguna de las temperaturas era menor que 15, se inicia el calentador
	lw	$t2, 0($t1)
	ori	$t2, $t2, 0x20
	sw	$t2, 0($t1)
	jal	retardo25

	j	sensor1
