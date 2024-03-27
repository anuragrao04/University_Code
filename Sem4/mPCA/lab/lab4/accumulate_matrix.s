.data

matrix:
	.word 10, 20, 30, 40, 50, 60, 70, 80, 90

size:
	.word 9

result:
	.word 0

	.text
	ldr r0, =matrix
	ldr r1, =size
	ldr r1, [r1]; counter
	mov r5, #0

loop:
	;   r0 -> matrix
	;   r1 -> counter
	;   r2 -> number being read
	;   r5 -> accumulator
	ldr r2, [r0], #4
	add r5, r5, r2
	sub r1, r1, #1
	cmp r1, #0
	bgt loop

	;   once loop is done, we'll store r5 in result
	ldr r0, =result; we are reusing r0 which held the array before
	str r5, [r0]
	swi 0x11; bye bye
