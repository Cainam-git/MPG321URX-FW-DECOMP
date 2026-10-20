# leon2s FUN_a00a2a80 0xa00a2a80-0xa00a2b08 (136 bytes)
a00a2a80:  9d e3 bf 98  save  %sp, -104, %sp
a00a2a84:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a2a88:  b6 10 63 00  or  %g1, 0x300, %i3	! 0xa807db00
a00a2a8c:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00a2a90:  9e 10 63 00  or  %g1, 0x300, %o7	! 0xff00
a00a2a94:  03 3f ff c0  sethi  %hi(0xffff0000), %g1
a00a2a98:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a2a9c:  b2 10 60 ff  or  %g1, 0xff, %i1
a00a2aa0:  b8 10 20 00  clr  %i4
a00a2aa4:  35 00 00 04  sethi  %hi(0x1000), %i2
a00a2aa8:  82 0f 20 ff  and  %i4, 0xff, %g1
a00a2aac:  80 a6 20 01  cmp  %i0, 1
a00a2ab0:  12 80 00 06  bne  0xa00a2ac8
a00a2ab4:  82 58 60 34  smul  %g1, 0x34, %g1
a00a2ab8:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a00a2abc:  c2 07 60 04  ld  [ %i5 + 4 ], %g1
a00a2ac0:  10 80 00 0a  b  0xa00a2ae8
a00a2ac4:  82 10 40 0f  or  %g1, %o7, %g1
a00a2ac8:  82 0f 20 ff  and  %i4, 0xff, %g1
a00a2acc:  80 a6 20 00  cmp  %i0, 0
a00a2ad0:  12 80 00 07  bne  0xa00a2aec
a00a2ad4:  82 58 60 34  smul  %g1, 0x34, %g1
a00a2ad8:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a00a2adc:  c2 07 60 04  ld  [ %i5 + 4 ], %g1
a00a2ae0:  82 08 40 19  and  %g1, %i1, %g1
a00a2ae4:  82 10 40 1a  or  %g1, %i2, %g1
a00a2ae8:  c2 27 60 04  st  %g1, [ %i5 + 4 ]
a00a2aec:  b8 07 20 01  inc  %i4
a00a2af0:  82 0f 20 ff  and  %i4, 0xff, %g1
a00a2af4:  80 a0 60 01  cmp  %g1, 1
a00a2af8:  08 bf ff ee  bleu  0xa00a2ab0
a00a2afc:  80 a6 20 01  cmp  %i0, 1
a00a2b00:  81 c7 e0 08  ret
a00a2b04:  91 e8 20 00  restore  %g0, 0, %o0
