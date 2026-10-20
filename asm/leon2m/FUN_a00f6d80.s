# leon2m FUN_a00f6d80 0xa00f6d80-0xa00f6dd8 (88 bytes)
a00f6d80:  9d e3 bf 98  save  %sp, -104, %sp
a00f6d84:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f6d88:  d8 00 63 b8  ld  [ %g1 + 0x3b8 ], %o4	! 0xa802b7b8
a00f6d8c:  90 10 20 00  clr  %o0
a00f6d90:  80 8e 20 80  btst  0x80, %i0
a00f6d94:  12 80 00 0d  bne  0xa00f6dc8
a00f6d98:  82 16 3f 80  or  %i0, -128, %g1
a00f6d9c:  92 08 60 ff  and  %g1, 0xff, %o1
a00f6da0:  80 a3 20 00  cmp  %o4, 0
a00f6da4:  12 80 00 06  bne  0xa00f6dbc
a00f6da8:  9a 10 00 09  mov  %o1, %o5
a00f6dac:  13 33 c0 3b  sethi  %hi(0xcf00ec00), %o1
a00f6db0:  90 12 63 04  or  %o1, 0x304, %o0	! 0xcf00ef04
a00f6db4:  da 22 00 00  st  %o5, [ %o0 ]
a00f6db8:  30 80 00 06  b,a   0xa00f6dd0
a00f6dbc:  9f c3 00 00  call  %o4
a00f6dc0:  01 00 00 00  nop
a00f6dc4:  30 80 00 03  b,a   0xa00f6dd0
a00f6dc8:  10 bf ff f5  b  0xa00f6d9c
a00f6dcc:  82 0e 20 7f  and  %i0, 0x7f, %g1
a00f6dd0:  81 c7 e0 08  ret
a00f6dd4:  81 e8 00 00  restore
