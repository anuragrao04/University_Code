.text
mov r0, #255; number to count digits in
mov r1, #0; accumulator
mov r2, r0
mov r3, #0

loop:
	bl  div
	add r1, r1, r2
	cmp r3, #0
	beq end
	mov r2, r3
	mov r3, #0
	b   loop

div:
	; r2 -> divident
	; 10 -> divisor
	; r3 -> quotient
	; initialise r3 to 0 before calling this function

	;     if the divident is less than the divisor, quotient = 0 and divident is the remainder
	cmp   r2, #10
	movlt pc, lr
	;     since r3 is already 0 (quotient), we can directly return here

	sub r2, r2, #10
	add r3, r3, #1
	cmp r2, #10
	bge div

	mov pc, lr
	;   after this function:
	;   r2 -> remainder
	;   r3 -> quotient

end:
	swi 0x11
