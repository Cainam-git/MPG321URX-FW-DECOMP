# leon2s FUN_a00638f8 0xa00638f8-0xa0063924 (44 bytes)
a00638f8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00638fc:  c2 08 62 39  ldub  [ %g1 + 0x239 ], %g1	! 0xa8078a39
a0063900:  80 a0 60 01  cmp  %g1, 1
a0063904:  12 80 00 05  bne  0xa0063918
a0063908:  01 00 00 00  nop
a006390c:  82 13 c0 00  mov  %o7, %g1
a0063910:  7f ff ff 7f  call  0xa006370c
a0063914:  9e 10 40 00  mov  %g1, %o7
a0063918:  01 00 00 00  nop
a006391c:  81 c3 e0 08  retl
a0063920:  01 00 00 00  nop
