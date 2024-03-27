	; converting (54) base 16 to ascii
	; we convert to ascii by making an OR with 0x30

	.data

A:
	.word 0, 0

	.text
	ldr   r0, =A; this will be our answer pointer
	mov   r1, #0x54; input
	and   r2, r1, #0xF0; MSB bit
	mov   r2, r2, lsr #4
	orr   r2, r2, #0x30; to get ascii
	stmia r0, {r2}
	add   r0, r0, #4

	and   r2, r1, #0x0F; MSB bit
	orr   r2, r2, #0x30; to get ascii
	stmia r0, {r2}
	swi   0x11
