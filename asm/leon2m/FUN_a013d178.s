# leon2m FUN_a013d178 0xa013d178-0xa013d198 (32 bytes)
a013d178:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a013d17c:  da 08 61 a7  ldub  [ %g1 + 0x1a7 ], %o5	! 0xa802e1a7
a013d180:  80 a3 60 04  cmp  %o5, 4
a013d184:  08 80 00 03  bleu  0xa013d190
a013d188:  90 10 20 00  clr  %o0
a013d18c:  90 10 20 01  mov  1, %o0
a013d190:  81 c3 e0 08  retl
a013d194:  01 00 00 00  nop
