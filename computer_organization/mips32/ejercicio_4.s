# El registro $s0 almacena el valor 0x0001FF0F, el registro $s1 el valor 0x000F0020 y el registro $s2 el valor
# 0x20.
#	a) Si ejecutamos la instrucción and $t0,$s0,$s1, ¿qué valor dejará en $t0?
#		0000 0000 0000 0001 1111 1111 0000 1111 ($s0)
#		0000 0000 0000 1111 0000 0000 0010 0000 ($s1)
#	                      $t0   ->	0000 0000 0000 0001 0000 0000 0000 0000 (0x0001 0000)
#	b) Si ejecutamos la instrucción or $t1,$s0,$s1, ¿qué valor dejará en $t1?
#		0000 0000 0000 0001 1111 1111 0000 1111 ($s0)
#		0000 0000 0000 1111 0000 0000 0010 0000 ($s1)
#	                      $t1   ->	0000 0000 0000 1111 1111 1111 0010 1111 (0x000F FF2F)
#	c) Si ejecutamos la instrucción ori $t2,$s0,0x0F50, ¿qué valor dejará en $t2?
#		0000 0000 0000 0001 1111 1111 0000 1111 ($s0)
#		0000 0000 0000 0000 0000 1111 0101 0000 (0x0F50)
#	                      $t2   ->	0000 0000 0000 0001 1111 1111 0101 1111 (0x0001 FF5F)
#	d) Si ejecutamos la instrucción sll $t4,$s2,2, ¿qué valor dejará en $t4?
#		0000 0000 0000 0000 0000 0000 0010 0000 ($s2)
#		0000 0000 0000 0000 0000 0000 1000 0000 (desp 2) (0x0000080)
#	e) Si ejecutamos la instrucción sra $t5,$s2,3, ¿qué valor dejará en $t4?
#		0000 0000 0000 0000 0000 0000 0010 0000 ($s2)
#		0000 0000 0000 0000 0000 0000 0000 0100 (desp 3 der) (0x0000004)
# Hacer un programa en ensamblador MIPS para poder probar lo anterior.

#segmento de datos
.data


#segmento de texto
.text
.globl main

main:
	# guardar valores en los registros
	addi $s0,$0,0x0001FF0F	# guardar 0x0001FF0F en $s0
	addi $s1,$0,0x000F0020	# guardar 0x000F0020 en $s1
	addi $s2,$0,0x20		# guardar 0x20 en $s2

	# apartado a) AND
	and $t0,$s0,$s1		# guardar en $t0 el resultado de $s0 AND $s1

	# apartado b) OR
	or $t1,$s0,$s1		# guardar en $t1 el resultado de $s0 OR $s1

	# apartado c) ORI
	ori $t2,$s0,0x0F50		# guardar en $t2 el resultado de $s0 ORI 0x0F50

	# apartado d) SLL
	sll $t4,$s2,2		# desplazar 2 posiciones a la izquierda el valor de
			# $s2 y almacenarlo en $t4

	# apartado e) SRA
	sra $t5,$s2,3		# desplazar 3 posiciones a la derecha el valor de
			# $s2 y almacenarlo en $t5


fin:
	addi $v0,$0,10	#llamada al sistema para salir del programa
	syscall