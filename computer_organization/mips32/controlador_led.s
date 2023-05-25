# Supóngase un procesador basado en MIPS para controlar una tira de 20 luces
# LED. Las luces están mapeadas en memoria a partir de la dirección 0xFFFF1000.
# Cada luz LED ocupa un byte.
# Si escribimos en la posición de memoria correspondiente:
#	Un 0 -> el LED se apaga.
#	Un 1 -> el LED se enciende con luz blanca.
#	Un 2 -> el LED se enciende con luz roja.
# Disponemos de un pequeño teclado numérico:
#	Puerto de estado 0xFFFF9990 (bit de estado 10)
#	Puerto de datos 0xFFFF9994

# a) Hacer una subrutina llamada "Escribirleds" que escriba el número que le
# llega como parámetro en el registro $a1 en la tira de 20 luces LED.

	escribirleds:
		li	$s0, 0xFFFF1000
		li	$s1, 20

		escribir:
			beq	$s1, $zero, retorno
			sb	$a1, 0($s0)
			addi	$s0, $s0, 1
			addi	$s1, $s1, -1
			j 	escribir

		salir:
			jr	$ra



# b) Hacer un programa MIPS para que atienda al teclado por consulta de estado
# y si se ha pulsado la tecla 0, apague todos los LED, si se ha pulsado la tecla
# 1 los encienda todos con luz blanca, y si se ha pulsado un 2 los encienda todos
# con luz roja.
# Con cualquier otra tecla no haga nada. El programa no acabará nunca.

		.text
		.globl	main
	main:
		li	$t0, 0xFFFF9990			# $t0 - Puerto de estado del teclado
		
		estado:
			lw	$t1, 0($t0)		# cargar puerto de estado del teclado
			andi	$t1, 0x400		# aislar bit 10
			beq	$t1, $zero, estado	# repetimos comprobación, no hay dato para leer

		# Se ha introducido un dato
		lw	$t1, 4($t0)			# cargamos contenido del puerto de datos
		sub	$t1, $t1, 0x30			# el valor es ASCII (0 = 0x30), por lo que restamos 0x30
		slti	$t2, $t1, 3			# comprobamos si es < 3
		beq	$t2, $zero, estado		# si es > 3, repetimos
		bgez	$t1, llamada			# y si es < 3, y >= 0, saltamos a llamada

		llamada:
			add	$a1, $zero, $t1		# guardamos el valor introducido en $a1
			jal	escribirleds		# y llamamos a la subrutina

		j 	estado				# repetimos
