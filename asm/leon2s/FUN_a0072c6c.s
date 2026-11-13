# leon2s FUN_a0072c6c 0xa0072c6c-0xa0072cb8 (76 bytes)
a0072c6c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0072c70:  9a 10 60 e8  or  %g1, 0xe8, %o5	! 0xa80788e8
a0072c74:  d8 0b 60 81  ldub  [ %o5 + 0x81 ], %o4
a0072c78:  c2 0b 60 80  ldub  [ %o5 + 0x80 ], %g1
a0072c7c:  96 10 00 08  mov  %o0, %o3
a0072c80:  80 a0 40 0c  cmp  %g1, %o4
a0072c84:  02 80 00 0b  be  0xa0072cb0
a0072c88:  90 10 20 00  clr  %o0
a0072c8c:  c2 0b 40 0c  ldub  [ %o5 + %o4 ], %g1
a0072c90:  c2 2a c0 00  stb  %g1, [ %o3 ]
a0072c94:  c2 0b 60 81  ldub  [ %o5 + 0x81 ], %g1
a0072c98:  82 00 60 01  inc  %g1
a0072c9c:  80 88 60 80  btst  0x80, %g1
a0072ca0:  02 80 00 03  be  0xa0072cac
a0072ca4:  c2 2b 60 81  stb  %g1, [ %o5 + 0x81 ]
a0072ca8:  c0 2b 60 81  clrb  [ %o5 + 0x81 ]
a0072cac:  90 10 20 01  mov  1, %o0
a0072cb0:  81 c3 e0 08  retl
a0072cb4:  01 00 00 00  nop
