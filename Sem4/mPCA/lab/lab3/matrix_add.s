	; we'll make a 3x3 matrix
	.data

a:
	.word 1, 2, 3, 4, 5, 6, 7, 8, 9

b:
	.word 9, 8, 7, 6, 5, 4, 3, 2, 1

result:
	.word 0, 0, 0, 0, 0, 0, 0, 0, 0

dimension:
	.word 9

	.text
	ldr r0, =a
	ldr r1, =b
	ldr r2, =result
	ldr r3, =dimension
	ldr r3, [r3]

	; r0 -> first matrix
	; r1 -> second matrix
	; r2 -> result matrix
	; r3 -> counter
	; r4, r5, r6 -> temp

loop:
	ldr r4, [r0], #4
	ldr r5, [r1], #4
	add r6, r4, r5
	str r6, [r2], #4
	sub r3, r3, #1
	cmp r3, #0
	bgt loop

	swi 0x11
