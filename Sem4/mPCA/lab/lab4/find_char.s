.data
search_string: .asciiz "Please give me a good grade"
search_char: .asciiz "z"

	.text
	mov  r0, #0
	ldr  r1, =search_string
	ldr  r2, =search_char
	ldrb r2, [r2]
	;    r0 -> number of occurances
	;    r1 -> pointer to search string
	;    r2 -> character to search for
	;    r3 -> character to compare (temporary)

loop:
	ldrb  r3, [r1], #1
	cmp   r3, #0
	beq   end
	cmp   r3, r2
	addeq r0, r0, #1
	b     loop

end:
	swi 0x11
