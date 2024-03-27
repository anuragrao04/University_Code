	; .data

	; a:
	; .word 10, 20, 30, 40, 50, 60, 70, 80, 90, 100

	; sum:
	; .word 0

	; .text
	; ldr r1, =a
	; ldr r2, =sum
	; mov r4, #0
	; mov r5, #0

	; loop:
	; ldr r3, [r1]
	; add r4, r4, r3
	; add r1, r1, #8
	; add r5, r5, #1
	; cmp r5, #10
	; bne loop

	; str r5, [r2]
	; ldr r0, =sum
	; ldr r0, [r0]
	; bl  printf
	; b   exit
