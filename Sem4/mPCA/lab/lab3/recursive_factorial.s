.text
mov r0, #5; number to find factorial of
mov r1, #1; accumulator
cmp r0, #0
beq end
b   factorial; factorial function

factorial:
	mul r1, r0, r1
	sub r0, r0, #1
	cmp r0, #0
	bne factorial

end:
	swi 0x11
