# leon2m FUN_a01483b8 0xa01483b8-0xa01483f4 (60 bytes)
a01483b8:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a01483bc:  94 10 63 78  or  %g1, 0x378, %o2	! 0xa802e378
a01483c0:  82 10 20 00  clr  %g1
a01483c4:  96 00 60 01  add  %g1, 1, %o3
a01483c8:  83 28 60 10  sll  %g1, 0x10, %g1
a01483cc:  83 30 60 10  srl  %g1, 0x10, %g1
a01483d0:  d8 08 40 0a  ldub  [ %g1 + %o2 ], %o4
a01483d4:  9b 2a e0 10  sll  %o3, 0x10, %o5
a01483d8:  9b 33 60 10  srl  %o5, 0x10, %o5
a01483dc:  d8 2a 00 01  stb  %o4, [ %o0 + %g1 ]
a01483e0:  80 a3 60 57  cmp  %o5, 0x57
a01483e4:  08 bf ff f8  bleu  0xa01483c4
a01483e8:  82 10 00 0b  mov  %o3, %g1
a01483ec:  81 c3 e0 08  retl
a01483f0:  01 00 00 00  nop
