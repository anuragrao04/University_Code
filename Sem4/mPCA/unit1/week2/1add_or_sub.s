.text
mov   r0, #2
mov   r1, #2
cmp   r0, r1; add if equal, sub if not equal
addeq r2, r0, r1
subne r2, r0, r1
swi   0x11
.end
