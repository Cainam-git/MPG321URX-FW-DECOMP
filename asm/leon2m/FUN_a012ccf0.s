# leon2m FUN_a012ccf0 0xa012ccf0-0xa012cd68 (120 bytes)
a012ccf0:  9d e3 bf 98  save  %sp, -104, %sp
a012ccf4:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a012ccf8:  9e 10 61 a0  or  %g1, 0x1a0, %o7	! 0xa802e1a0
a012ccfc:  b2 10 20 00  clr  %i1
a012cd00:  b4 10 20 00  clr  %i2
a012cd04:  b6 10 20 00  clr  %i3
a012cd08:  82 06 c0 0f  add  %i3, %o7, %g1
a012cd0c:  b8 06 c0 18  add  %i3, %i0, %i4
a012cd10:  b4 06 a0 01  inc  %i2
a012cd14:  fa 08 60 22  ldub  [ %g1 + 0x22 ], %i5
a012cd18:  b6 0e a0 ff  and  %i2, 0xff, %i3
a012cd1c:  80 a6 e0 09  cmp  %i3, 9
a012cd20:  08 bf ff fa  bleu  0xa012cd08
a012cd24:  fa 2f 20 08  stb  %i5, [ %i4 + 8 ]
a012cd28:  ba 10 20 00  clr  %i5
a012cd2c:  82 10 20 00  clr  %g1
a012cd30:  f4 08 40 18  ldub  [ %g1 + %i0 ], %i2
a012cd34:  ba 07 60 01  inc  %i5
a012cd38:  b8 06 40 1a  add  %i1, %i2, %i4
a012cd3c:  82 0f 60 ff  and  %i5, 0xff, %g1
a012cd40:  80 a0 60 7e  cmp  %g1, 0x7e
a012cd44:  08 bf ff fb  bleu  0xa012cd30
a012cd48:  b2 10 00 1c  mov  %i4, %i1
a012cd4c:  80 8f 20 ff  btst  0xff, %i4
a012cd50:  02 80 00 03  be  0xa012cd5c
a012cd54:  82 10 20 00  clr  %g1
a012cd58:  82 20 00 1c  neg  %i4, %g1
a012cd5c:  c2 2e 20 7f  stb  %g1, [ %i0 + 0x7f ]
a012cd60:  81 c7 e0 08  ret
a012cd64:  81 e8 00 00  restore
