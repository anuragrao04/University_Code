.data

A:
	.word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

size:
	.word 10

result:
	.word 0

	.text
	ldr r0, =A
	ldr r1, =size
	ldr r1, [r1]; counter
	mov r5, #0

loop:
	;   r0 -> array
	;   r1 -> counter
	;   r2 -> word being read
	;   r5 -> accumulator
	ldr r2, [r0], #8
	add r5, r5, r2
	sub r1, r1, #2
	cmp r1, #0
	bgt loop

	;   once loop is done, we'll store r5 in result
	ldr r0, =result; we are reusing r0 which held the array before
	str r5, [r0]
	swi 0x11; bye bye
