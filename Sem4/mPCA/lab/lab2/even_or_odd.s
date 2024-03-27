.data

num:
	.word 1, 2, 3, 4, 5, 6

odd:
	.word 0, 0, 0, 0, 0, 0

even:
	.word 0, 0, 0, 0, 0, 0

	.text
	;   r0 -> A
	;   r1 -> odd
	;   r2 -> even
	;   r3 -> size of A = 6
	ldr r0, =num
	ldr r1, =odd
	ldr r2, =even
	mov r3, #6

loop:
	;    r4 -> temporary register
	;    r5 -> stores result of AND operation
	ldr  r4, [r0], #4
	and  r5, r4, #1
	cmp  r5, #0
	bleq even_num
	blne odd_num
	sub  r3, r3, #1
	cmp  r3, #0
	bgt  loop

	swi 0x11

even_num:
	str r4, [r2], #4
	mov pc, lr; go back

odd_num:
	str r4, [r1], #4
	mov pc, lr; go back
