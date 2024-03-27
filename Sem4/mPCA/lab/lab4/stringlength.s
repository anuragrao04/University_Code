.data

str:
	.asciiz "Anurag Rao\0"

result:
	.word 0
	.text
	ldr   r0, =str
	mov   r1, #0

	; r0 -> address of the string
	; r1 -> counter
	; r2 -> character being read

loop:
	ldrb r2, [r0], #1
	cmp  r2, #0; if r2 == 0, then end of string
	beq  end
	add  r1, r1, #1
	b    loop

end:
	ldr r0, =str
	swi 0x02; just to show that we can print strings :)
	ldr r0, =result
	str r1, [r0]; store in result
	swi 0x11; bye bye
