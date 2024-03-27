.text
mov r0, #10; number to find factorial of
mov r1, #1; accumulator

loop:
	mul r1, r0, r1; r1 = r0 * r1
	sub r0, r0, #1; r0 = r0 - 1
	cmp r0, #1; compare r0 to 1
	bne loop; if r0 != 0, branch to loop

	swi 0x11; exit
	.end
