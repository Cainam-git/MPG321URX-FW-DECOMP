# leon2m FUN_a0155d90 0xa0155d90-0xa0155de0 (80 bytes)
a0155d90:  9d e3 bf 80  save  %sp, -128, %sp
a0155d94:  f0 27 bf e4  st  %i0, [ %fp + -28 ]
a0155d98:  90 07 bf e4  add  %fp, -28, %o0
a0155d9c:  40 00 04 66  call  0xa0156f34
a0155da0:  92 07 bf e8  add  %fp, -24, %o1
a0155da4:  d0 07 bf f4  ld  [ %fp + -12 ], %o0
a0155da8:  92 10 00 08  mov  %o0, %o1
a0155dac:  90 10 20 00  clr  %o0
a0155db0:  9b 32 60 02  srl  %o1, 2, %o5
a0155db4:  83 2a 20 1e  sll  %o0, 0x1e, %g1
a0155db8:  90 13 40 01  or  %o5, %g1, %o0
a0155dbc:  93 2a 60 1e  sll  %o1, 0x1e, %o1
a0155dc0:  96 10 00 08  mov  %o0, %o3
a0155dc4:  98 10 00 09  mov  %o1, %o4
a0155dc8:  d0 1f bf e8  ldd  [ %fp + -24 ], %o0
a0155dcc:  40 00 03 05  call  0xa01569e0
a0155dd0:  d4 07 bf f0  ld  [ %fp + -16 ], %o2
a0155dd4:  b0 10 00 08  mov  %o0, %i0
a0155dd8:  81 c7 e0 08  ret
a0155ddc:  93 e8 00 09  restore  %g0, %o1, %o1
