.data

arr:
	.word 1, -2, -3, 4, -5, 6

highest:
	.word 0

	.text
	;   r0 -> arr
	;   r1 -> highest number
	;   r2 -> size of Arr = 6
	;   r3 -> will keep track of current maximum
	ldr r0, =arr
	ldr r1, =highest
	mov r2, #6
	ldr r3, [r0]; initialise to the first element of the array

loop:
	ldr   r4, [r0], #4
	cmp   r4, r3
	movgt r3, r4; if r4 is greater, mov it to r3
	sub   r2, r2, #1
	cmp   r2, #0
	bgt   loop

	str r3, [r1]; store in address r1

	swi 0x11
