# leon2m FUN_a012bb94 0xa012bb94-0xa012bc00 (108 bytes)
a012bb94:  9d e3 bf 88  save  %sp, -120, %sp
a012bb98:  82 0e 20 ff  and  %i0, 0xff, %g1
a012bb9c:  9f 28 60 03  sll  %g1, 3, %o7
a012bba0:  9a 03 c0 01  add  %o7, %g1, %o5
a012bba4:  19 2a 00 b6  sethi  %hi(0xa802d800), %o4
a012bba8:  91 2b 60 02  sll  %o5, 2, %o0
a012bbac:  92 13 20 dc  or  %o4, 0xdc, %o1
a012bbb0:  96 02 00 09  add  %o0, %o1, %o3
a012bbb4:  d4 12 e0 1c  lduh  [ %o3 + 0x1c ], %o2
a012bbb8:  98 10 20 00  clr  %o4
a012bbbc:  9a 10 20 00  clr  %o5
a012bbc0:  b2 16 40 0a  or  %i1, %o2, %i1
a012bbc4:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a012bbc8:  f2 32 e0 1c  sth  %i1, [ %o3 + 0x1c ]
a012bbcc:  83 36 60 08  srl  %i1, 8, %g1
a012bbd0:  f0 2f bf e8  stb  %i0, [ %fp + -24 ]
a012bbd4:  c2 2f bf ea  stb  %g1, [ %fp + -22 ]
a012bbd8:  c0 27 bf f0  clr  [ %fp + -16 ]
a012bbdc:  f2 2f bf e9  stb  %i1, [ %fp + -23 ]
a012bbe0:  90 10 20 56  mov  0x56, %o0
a012bbe4:  92 10 20 0c  mov  0xc, %o1
a012bbe8:  94 07 bf e8  add  %fp, -24, %o2
a012bbec:  40 00 2d 3c  call  0xa01370dc
a012bbf0:  96 10 20 00  clr  %o3
a012bbf4:  01 00 00 00  nop
a012bbf8:  81 c7 e0 08  ret
a012bbfc:  81 e8 00 00  restore
