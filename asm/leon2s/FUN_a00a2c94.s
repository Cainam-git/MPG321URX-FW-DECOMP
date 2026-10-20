# leon2s FUN_a00a2c94 0xa00a2c94-0xa00a2cf4 (96 bytes)
a00a2c94:  9d e3 bf 98  save  %sp, -104, %sp
a00a2c98:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a2c9c:  82 0e 20 ff  and  %i0, 0xff, %g1
a00a2ca0:  90 10 20 00  clr  %o0
a00a2ca4:  80 a6 60 01  cmp  %i1, 1
a00a2ca8:  12 80 00 08  bne  0xa00a2cc8
a00a2cac:  9a 58 60 34  smul  %g1, 0x34, %o5
a00a2cb0:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a2cb4:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00a2cb8:  d2 00 40 0d  ld  [ %g1 + %o5 ], %o1
a00a2cbc:  40 00 11 bc  call  0xa00a73ac
a00a2cc0:  92 02 60 08  add  %o1, 8, %o1
a00a2cc4:  30 80 00 0a  b,a   0xa00a2cec
a00a2cc8:  b0 58 60 34  smul  %g1, 0x34, %i0
a00a2ccc:  80 a6 60 00  cmp  %i1, 0
a00a2cd0:  12 80 00 07  bne  0xa00a2cec
a00a2cd4:  90 10 20 00  clr  %o0
a00a2cd8:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a2cdc:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00a2ce0:  d2 00 40 18  ld  [ %g1 + %i0 ], %o1
a00a2ce4:  40 00 11 bc  call  0xa00a73d4
a00a2ce8:  92 02 60 08  add  %o1, 8, %o1
a00a2cec:  81 c7 e0 08  ret
a00a2cf0:  91 e8 20 00  restore  %g0, 0, %o0
