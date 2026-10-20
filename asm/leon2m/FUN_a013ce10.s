# leon2m FUN_a013ce10 0xa013ce10-0xa013ce6c (92 bytes)
a013ce10:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a013ce14:  90 0a 20 ff  and  %o0, 0xff, %o0
a013ce18:  94 10 63 30  or  %g1, 0x330, %o2
a013ce1c:  96 10 20 00  clr  %o3
a013ce20:  98 10 20 00  clr  %o4
a013ce24:  9b 2b 20 04  sll  %o4, 4, %o5
a013ce28:  82 23 40 0c  sub  %o5, %o4, %g1
a013ce2c:  83 28 60 03  sll  %g1, 3, %g1
a013ce30:  d8 02 80 01  ld  [ %o2 + %g1 ], %o4
a013ce34:  9b 33 20 01  srl  %o4, 1, %o5
a013ce38:  96 02 e0 01  inc  %o3
a013ce3c:  9a 0b 60 07  and  %o5, 7, %o5
a013ce40:  80 a2 00 0d  cmp  %o0, %o5
a013ce44:  02 80 00 07  be  0xa013ce60
a013ce48:  98 0a e0 ff  and  %o3, 0xff, %o4
a013ce4c:  80 a3 20 03  cmp  %o4, 3
a013ce50:  08 bf ff f6  bleu  0xa013ce28
a013ce54:  9b 2b 20 04  sll  %o4, 4, %o5
a013ce58:  10 80 00 03  b  0xa013ce64
a013ce5c:  90 10 20 00  clr  %o0
a013ce60:  90 00 40 0a  add  %g1, %o2, %o0
a013ce64:  81 c3 e0 08  retl
a013ce68:  01 00 00 00  nop
