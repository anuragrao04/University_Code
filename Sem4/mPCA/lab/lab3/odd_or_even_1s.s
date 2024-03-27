.data

num:
	.word 0xFFFFFFFE; this should have odd parity

oddpari:
	.asciiz "Odd Parity"

evenpari:
	.asciiz "Even Parity"
	.text
	;       r0 -> holds the number
	;       r1 -> size of the number, statically, 32 bits
	;       this is for the loop to count 1s
	;       r2 -> 1 if odd parity, 0 if even parity
	;       r3 -> temporary
	ldr     r0, =num
	ldr     r0, [r0]
	mov     r1, #32
	mov     r2, #0

loop:
	and   r3, r0, #0b1
	cmp   r3, #1
	eoreq r2, r2, #0b1
	mov   r0, r0, lsr #1
	sub   r1, r1, #1
	cmp   r1, #0
	bgt   loop

	cmp r2, #0
	beq evenparibranch
	bne oddparibranch

evenparibranch:
	ldr r0, =evenpari
	swi 0x02
	swi 0x11

oddparibranch:
	ldr r0, =oddpari
	swi 0x02
	swi 0x11
