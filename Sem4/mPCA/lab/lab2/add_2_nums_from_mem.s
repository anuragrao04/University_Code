.data

a:
	.word 20, 49

res:
	.word 0

	.text
	ldr r0, =a; sources
	ldr r1, =res; result
	ldr r2, [r0]; first operand
	add r0, r0, #4; increment to get the next operand pointer
	ldr r3, [r0]; second operand
	add r4, r3, r2; result in r4
	str r4, [r1]; store in location pointed by r1
	swi 0x11;; end off
	.end
