.data

dimension:
	.word 3

result:
	.word 0, 0, 0, 0, 0, 0, 0, 0, 0

	.text
	ldr r0, =dimension
	ldr r0, [r0]
	ldr r1, =result
	mov r2, #1; column
	mov r3, #1; row
	mov r4, #1; the number we'd be storing on the diagonal positions
	mov r5, #0; the number we'd be storing on the off-diagonal positions

loop:
	cmp   r2, r3
	streq r4, [r1], #4
	strne r5, [r1], #4
	add   r2, r2, #1
	cmp   r2, r0
	bgt   next_row
	b     loop

next_row:
	mov r2, #1
	add r3, r3, #1
	cmp r3, r0
	bgt end
	b   loop

end:
	swi 0x11
