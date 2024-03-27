.data

num:
	.word 1, -2, -3, 0, -5, 0

pos:
	.word 0, 0, 0, 0, 0, 0

neg:
	.word 0, 0, 0, 0, 0, 0

zero:
	.word 0, 0, 0, 0, 0, 0

	.text
	;   r0 -> A
	;   r1 -> pos
	;   r2 -> neg
	;   r5 -> zero array
	;   r3 -> size of Arr = 6
	ldr r0, =num
	ldr r1, =pos
	ldr r2, =neg
	ldr r5, =zero
	mov r3, #6

loop:
	;    r4 -> temporary register
	ldr  r4, [r0], #4
	cmp  r4, #0
	blgt pos_num
	bllt neg_num
	bleq zero_num
	sub  r3, r3, #1
	cmp  r3, #0
	bgt  loop

	swi 0x11

pos_num:
	str r4, [r1], #4
	mov pc, lr; go back

neg_num:
	str r4, [r2], #4
	mov pc, lr; go back

zero_num:
	str r4, [r5], #4
	mov pc, lr; go back
