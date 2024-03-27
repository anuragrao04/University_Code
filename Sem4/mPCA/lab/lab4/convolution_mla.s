.data

a:
	.word 1, 1, 1, 1

b:
	.word 2, 2, 2, 2

size:
	.word 4

result:
	.word 0

	.text
	ldr r0, =a
	ldr r1, =b
	ldr r2, =size
	ldr r2, [r2]
	mov r3, #0

	; r0 -> Array A
	; r1 -> Array B
	; r2 -> Size
	; r3 -> accumulator
	; r4, r5 -> temporary registers

loop:
	ldr r4, [r0], #4
	ldr r5, [r1], #4
	mla r3, r4, r5, r3
	sub r2, r2, #1
	cmp r2, #0
	bgt loop

	ldr r0, =result
	str r3, [r0]; store in result
	swi 0x11; bye bye
