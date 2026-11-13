# leon2s FUN_a00638a0 0xa00638a0-0xa00638cc (44 bytes)
a00638a0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00638a4:  c2 08 62 39  ldub  [ %g1 + 0x239 ], %g1	! 0xa8078a39
a00638a8:  80 a0 60 03  cmp  %g1, 3
a00638ac:  12 80 00 05  bne  0xa00638c0
a00638b0:  01 00 00 00  nop
a00638b4:  82 13 c0 00  mov  %o7, %g1
a00638b8:  7f ff ff 95  call  0xa006370c
a00638bc:  9e 10 40 00  mov  %g1, %o7
a00638c0:  01 00 00 00  nop
a00638c4:  81 c3 e0 08  retl
a00638c8:  01 00 00 00  nop
