.data

A:
	.word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

size:
	.word 10

	.text
	ldr r0, =A
	ldr r1, =size
	ldr r1, [r1]
	mov r2, #1
	mov r3, #2
	mov r4, #0
	str r2, [r0], #4
	str r3, [r0], #4

loop:
	;       r2, r3 -> previous 2 numbers
	;       r4 -> current number to store
	;       r0 -> array pointer
	;       r1 -> counter
	add     r4, r2, r3
	;update r2 and r3
	mov     r2, r3
	mov     r3, r4
	str     r4, [r0], #4
	sub     r1, r1, #1
	cmp     r1, #0
	bgt     loop

	swi 0x11
