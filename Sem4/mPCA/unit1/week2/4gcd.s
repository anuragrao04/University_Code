	.text
	mov r0, #24
	mov r1, #24
	;   the two numbers we need to find gcd of

	; logic:
	; compare both the numbers
	; subtract the smaller number from the larger number
	; repeat until both the numbers are equal
	; the number that is left is the gcd

loop:
	cmp   r0, r1
	subgt r0, r0, r1; if r0 > r1, r0 = r0 - r1
	sublt r1, r1, r0; if r0 < r1, r1 = r1 - r0
	bne   loop; if r0 != r1, loop

	mov r3, r1; result
	swi 0x11; exit
	.end
