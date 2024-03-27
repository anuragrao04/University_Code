.data

arr:
	.word 3, 2, 1, 0, 4, 6, 5, 8, 7, 9

arr_size:
	.word 10

	.text
	ldr r0, =arr
	ldr r1, =arr_size
	ldr r1, [r1]; array size

	; r3, r4, r5 -> temporary
	; r1 -> outer loop counter
	; r2 -> inner loop counter

outer_loop:
	sub r1, r1, #1
	mov r2, r1

inner_loop:
	ldr r3, [r0]
	add r0, r0, #4
	ldr r4, [r0]
	cmp r3, r4

	;     swapping process
	strgt r3, [r0]
	subgt r0, r0, #4
	strgt r4, [r0]
	addgt r0, r0, #4

	sub r2, r2, #1
	cmp r2, #0
	bgt inner_loop

	cmp   r1, #0
	ldrne r0, =arr; restore array pointer
	bgt   outer_loop

	swi 0x11
