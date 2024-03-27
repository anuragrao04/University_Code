.data

source:
	.asciiz "Anurag Rao\0"

destination:
	.asciiz "aaaaaaaaaa\0"

newline:
	.asciiz "\n"

	.text
	ldr r0, =source
	ldr r1, =destination

	; r0 -> address of the source string
	; r1 -> address of the destination string
	; r2 -> character to be copied

loop:
	ldrb r2, [r0], #1
	cmp  r2, #0; if r2 == 0, then end of string
	beq  end
	strb r2, [r1], #1
	b    loop

end:
	ldr r0, =source
	swi 0x02
	;   printing the source string because it's fun to print strings in assembly
	ldr r0, =newline
	swi 0x02
	ldr r0, =destination
	swi 0x02; printing the destination string
	swi 0x11; bye bye
