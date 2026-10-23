# leon2s FUN_a00d3f30 0xa00d3f30-0xa00d3f54 (36 bytes)
a00d3f30:  80 8a 20 ff  btst  0xff, %o0
a00d3f34:  02 80 00 05  be  0xa00d3f48
a00d3f38:  1b 2a 01 e3  sethi  %hi(0xa8078c00), %o5
a00d3f3c:  82 10 20 01  mov  1, %g1
a00d3f40:  10 80 00 03  b  0xa00d3f4c
a00d3f44:  c2 2b 60 31  stb  %g1, [ %o5 + 0x31 ]
a00d3f48:  c0 2b 60 31  clrb  [ %o5 + 0x31 ]
a00d3f4c:  81 c3 e0 08  retl
a00d3f50:  01 00 00 00  nop
