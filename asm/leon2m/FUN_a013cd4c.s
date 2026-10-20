# leon2m FUN_a013cd4c 0xa013cd4c-0xa013cda8 (92 bytes)
a013cd4c:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a013cd50:  90 0a 20 ff  and  %o0, 0xff, %o0
a013cd54:  94 10 63 30  or  %g1, 0x330, %o2
a013cd58:  96 10 20 00  clr  %o3
a013cd5c:  98 10 20 00  clr  %o4
a013cd60:  9b 2b 20 04  sll  %o4, 4, %o5
a013cd64:  82 23 40 0c  sub  %o5, %o4, %g1
a013cd68:  83 28 60 03  sll  %g1, 3, %g1
a013cd6c:  d8 02 80 01  ld  [ %o2 + %g1 ], %o4
a013cd70:  9b 33 20 0c  srl  %o4, 0xc, %o5
a013cd74:  96 02 e0 01  inc  %o3
a013cd78:  9a 0b 60 0f  and  %o5, 0xf, %o5
a013cd7c:  80 a2 00 0d  cmp  %o0, %o5
a013cd80:  02 80 00 07  be  0xa013cd9c
a013cd84:  98 0a e0 ff  and  %o3, 0xff, %o4
a013cd88:  80 a3 20 03  cmp  %o4, 3
a013cd8c:  08 bf ff f6  bleu  0xa013cd64
a013cd90:  9b 2b 20 04  sll  %o4, 4, %o5
a013cd94:  10 80 00 03  b  0xa013cda0
a013cd98:  90 10 20 00  clr  %o0
a013cd9c:  90 00 40 0a  add  %g1, %o2, %o0
a013cda0:  81 c3 e0 08  retl
a013cda4:  01 00 00 00  nop
