.text
mov  r0, #8; number to test
ands r1, r0, #1; test if odd
beq  even; if even, branch to even
b    odd; if odd, branch to odd

even:
	mov r2, #0; set r1 to 0
	b   end; branch to end

odd:
	mov r2, #1; set r1 to 1
	b   end; branch to end

end:
	swi 0x11; exit program
	.end
