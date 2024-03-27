.data

a:
	.word 5, 10, 15, 40, 45, 69, 90, 8, 9, 10

key:
	.word 100

size:
	.word 10

found_text:
	.asciiz "Found!"

not_found_text:
	.asciiz "Not Found :("

	.text
	;   r0 -> array
	;   r1 -> key
	;   r2 -> flag, if found -> 1, else -> 0
	;   r3 -> size
	;   r4 -> temp
	ldr r0, =a
	ldr r1, =key
	ldr r1, [r1]
	ldr r3, =size
	ldr r3, [r3]

loop:
	ldr r4, [r0], #4
	cmp r4, r1
	beq found
	sub r3, r3, #1
	cmp r3, #0
	bgt loop

	;   if control reaches this point, it means the loop ran without breaking out
	ldr r0, =not_found_text
	swi 0x02
	mov r2, #0; not found :(
	swi 0x11

found:
	mov r2, #1; found! :)
	ldr r0, =found_text
	swi 0x02
	swi 0x11

	.end
