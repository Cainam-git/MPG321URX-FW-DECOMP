# leon2s FUN_a0086bd8 0xa0086bd8-0xa0086c48 (112 bytes)
a0086bd8:  03 33 c0 62  sethi  %hi(0xcf018800), %g1
a0086bdc:  82 10 61 e0  or  %g1, 0x1e0, %g1	! 0xcf0189e0
a0086be0:  c2 00 40 00  ld  [ %g1 ], %g1
a0086be4:  1b 33 c0 4c  sethi  %hi(0xcf013000), %o5
a0086be8:  80 88 60 01  btst  1, %g1
a0086bec:  12 80 00 04  bne  0xa0086bfc
a0086bf0:  90 10 20 04  mov  4, %o0
a0086bf4:  10 80 00 13  b  0xa0086c40
a0086bf8:  90 10 20 00  clr  %o0
a0086bfc:  c2 03 40 00  ld  [ %o5 ], %g1
a0086c00:  80 88 60 80  btst  0x80, %g1
a0086c04:  02 80 00 04  be  0xa0086c14
a0086c08:  01 00 00 00  nop
a0086c0c:  10 80 00 0d  b  0xa0086c40
a0086c10:  90 10 20 01  mov  1, %o0	! 0x1
a0086c14:  c2 03 40 00  ld  [ %o5 ], %g1
a0086c18:  80 88 60 02  btst  2, %g1
a0086c1c:  02 80 00 04  be  0xa0086c2c
a0086c20:  01 00 00 00  nop
a0086c24:  10 80 00 07  b  0xa0086c40
a0086c28:  90 10 20 02  mov  2, %o0	! 0x2
a0086c2c:  c2 03 40 00  ld  [ %o5 ], %g1
a0086c30:  80 88 60 10  btst  0x10, %g1
a0086c34:  02 80 00 03  be  0xa0086c40
a0086c38:  01 00 00 00  nop
a0086c3c:  90 10 20 03  mov  3, %o0	! 0x3
a0086c40:  81 c3 e0 08  retl
a0086c44:  90 0a 20 07  and  %o0, 7, %o0
