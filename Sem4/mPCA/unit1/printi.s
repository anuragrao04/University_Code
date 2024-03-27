ldr r0, =A
swi 0x02
swi 0x11

.data

A:
	.ASCIZ "Hello World"
