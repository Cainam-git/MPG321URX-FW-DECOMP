# leon2s FUN_a0098b60 0xa0098b60-0xa0098bb0 (80 bytes)
a0098b60:  90 0a 20 ff  and  %o0, 0xff, %o0
a0098b64:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a0098b68:  9a 02 00 08  add  %o0, %o0, %o5
a0098b6c:  82 10 60 54  or  %g1, 0x54, %g1
a0098b70:  19 2a 01 e2  sethi  %hi(0xa8078800), %o4
a0098b74:  80 a2 20 00  cmp  %o0, 0
a0098b78:  12 80 00 06  bne  0xa0098b90
a0098b7c:  c0 30 40 0d  clrh  [ %g1 + %o5 ]
a0098b80:  c2 0b 20 d2  ldub  [ %o4 + 0xd2 ], %g1
a0098b84:  82 10 60 04  or  %g1, 4, %g1
a0098b88:  10 80 00 08  b  0xa0098ba8
a0098b8c:  c2 2b 20 d2  stb  %g1, [ %o4 + 0xd2 ]
a0098b90:  80 a2 20 01  cmp  %o0, 1
a0098b94:  12 80 00 05  bne  0xa0098ba8
a0098b98:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0098b9c:  c2 0b 60 d2  ldub  [ %o5 + 0xd2 ], %g1	! 0xa80788d2
a0098ba0:  82 10 60 08  or  %g1, 8, %g1
a0098ba4:  c2 2b 60 d2  stb  %g1, [ %o5 + 0xd2 ]
a0098ba8:  81 c3 e0 08  retl
a0098bac:  01 00 00 00  nop
