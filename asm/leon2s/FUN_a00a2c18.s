# leon2s FUN_a00a2c18 0xa00a2c18-0xa00a2c94 (124 bytes)
a00a2c18:  9d e3 bf 98  save  %sp, -104, %sp
a00a2c1c:  a0 10 20 00  clr  %l0
a00a2c20:  82 0c 20 ff  and  %l0, 0xff, %g1
a00a2c24:  98 0e 20 ff  and  %i0, 0xff, %o4
a00a2c28:  9a 58 60 34  smul  %g1, 0x34, %o5
a00a2c2c:  80 a3 20 01  cmp  %o4, 1
a00a2c30:  12 80 00 09  bne  0xa00a2c54
a00a2c34:  90 10 20 00  clr  %o0
a00a2c38:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a2c3c:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00a2c40:  d2 00 40 0d  ld  [ %g1 + %o5 ], %o1
a00a2c44:  40 00 11 da  call  0xa00a73ac
a00a2c48:  92 02 60 08  add  %o1, 8, %o1
a00a2c4c:  10 80 00 0c  b  0xa00a2c7c
a00a2c50:  a0 04 20 01  inc  %l0
a00a2c54:  82 0c 20 ff  and  %l0, 0xff, %g1
a00a2c58:  80 a3 20 00  cmp  %o4, 0
a00a2c5c:  12 80 00 07  bne  0xa00a2c78
a00a2c60:  9a 58 60 34  smul  %g1, 0x34, %o5
a00a2c64:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a2c68:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00a2c6c:  d2 00 40 0d  ld  [ %g1 + %o5 ], %o1
a00a2c70:  40 00 11 d9  call  0xa00a73d4
a00a2c74:  92 02 60 08  add  %o1, 8, %o1
a00a2c78:  a0 04 20 01  inc  %l0
a00a2c7c:  82 0c 20 ff  and  %l0, 0xff, %g1
a00a2c80:  80 a0 60 01  cmp  %g1, 1
a00a2c84:  08 bf ff e9  bleu  0xa00a2c28
a00a2c88:  98 0e 20 ff  and  %i0, 0xff, %o4
a00a2c8c:  81 c7 e0 08  ret
a00a2c90:  91 e8 20 00  restore  %g0, 0, %o0
