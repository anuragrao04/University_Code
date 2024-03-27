.data

string:
	.asciiz "ungabunga"

size:
	.word 9
	new_line: .asciiz "\n"

	.text
	ldr r0, =string
	ldr r1, =size
	ldr r1, [r1]
	sub r1, r1, #1

	; r0 -> string pointer
	; r1 -> size of string
	; r2 -> first character
	; r3 -> last character
	; r4 -> new line character

	swi 0x02; print the string before swapping
	ldr r0, =new_line; new line for pretty pretty
	swi 0x02; print the new line
	ldr r0, =string; load back the string pointer

	ldrb r2, [r0]; load first char
	add  r0, r0, r1; go to the last character
	ldrb r3, [r0]; load the last character
	strb r2, [r0]; store the first character in the last character
	sub  r0, r0, r1; go to the first character
	strb r3, [r0]; store the last character in the first character

	swi 0x02; print the string after swapping
	swi 0x11; exit
