.data

a:
	.word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

size:
	.word 10

key:
	.word 4

found_text:
	.asciiz "Found"

not_found_text:
	.asciiz "Not Found"

	.text
	ldr r0, =a
	ldr r1, =size
	ldr r1, [r1]
	ldr r4, =key
	ldr r4, [r4]
	mov r2, #0
	mov r6, r0

	; r0 -> array
	; r1 -> size of the array/upper bound for binary search
	; r2 -> lower bound for binary search
	; r3 -> middle index
	; r4 -> key
	; r5 -> middle element
	; r6 -> temporary to traverse the array

loop:
	add r3, r1, r2
	mov r3, r3, lsr #1
	;   r3 = (r1 + r2) / 2
	add r6, r0, r3, lsl #2
	;   r6 = r0 + r3 * 4
	ldr r5, [r6]
	cmp r5, r4
	beq found
	bgt greater
	blt lesser

found:
	ldr r0, =found_text
	swi 0x02
	b   end

not_found:
	ldr r0, =not_found_text
	swi 0x02

end:
	swi 0x11

lesser:
	add r3, r3, #1
	mov r2, r3
	cmp r2, r1
	bge not_found
	b   loop

greater:
	sub r3, r3, #1
	mov r1, r5
	cmp r2, r1
	bge not_found
	b   loop
