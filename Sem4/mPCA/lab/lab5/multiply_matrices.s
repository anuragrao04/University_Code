.data

matrix1:
	.word 1, 2, 3, 4, 5, 6, 7, 8, 9

matrix2:
	.word 1, 2, 3, 4, 5, 6, 7, 8, 9

matrix_result:
	.word 0, 0, 0, 0, 0, 0, 0, 0, 0

	.text
	ldr r0, =matrix1
	ldr r1, =matrix2
	ldr r2, =matrix_result
	mov r3, #0
	mov r4, #0
	mov r5, #0

	; r0 -> matrix1
	; r1 -> matrix2
	; r2 -> matrix_result
	; r3 -> i
	; r4 -> j
	; r5 -> k
	; r6, r7 -> temporary registers

	; the C code we'll be replicating is:
	; for(int i = 0; i < 3; i++){
	; for(int j = 0; j < 3; j++){
	; for(int k = 0; k < 3; k++){
	; result[i][j] += matrix1[i][k] * matrix2[k][j]
	; }
	; }
	; }

	mov r3, #0

loop_i:
	cmp r3, #3
	bge end

	mov r4, #0

loop_j:
	cmp r4, #3
	bge loop_i

	mov r5, #0

loop_k:
	cmp r5, #3
	bge loop_j
	mul r6, r3, r4
	mov r6, r6, lsl #2
	add r2, r2, r6; r2 now holds result[i][j]

	mul r6, r3, r5
	mov r6, r6, lsl #2
	add r0, r0, r6; r0 now holds matrix1[i][k]

	mul r6, r5, r4
	mov r6, r6, lsl #2
	add r1, r1, r6; r1 now holds matrix2[k][j]

	ldr r7, [r2]; r7 now holds value at result[i][j]
	ldr r0, [r0]; r0 now holds value at matrix1[i][k]
	ldr r1, [r1]; r1 now holds value at matrix2[k][j]
	mla r7, r0, r1, r7; r7 now holds result[i][j] += matrix1[i][k] * matrix2[k][j]
	str r7, [r2]; store r7 back into result[i][j]

	;   reset registers
	ldr r0, =matrix1
	ldr r1, =matrix2
	ldr r2, =matrix_result

	b loop_k

end:
	swi 0x11
