# leon2m FUN_a012cf1c 0xa012cf1c-0xa012cf64 (72 bytes)
a012cf1c:  03 00 06 94  sethi  %hi(0x1a5000), %g1
a012cf20:  94 10 61 98  or  %g1, 0x198, %o2	! 0x1a5198
a012cf24:  90 0a 20 ff  and  %o0, 0xff, %o0
a012cf28:  96 10 20 00  clr  %o3
a012cf2c:  98 10 20 00  clr  %o4
a012cf30:  83 2b 20 02  sll  %o4, 2, %g1
a012cf34:  da 12 80 01  lduh  [ %o2 + %g1 ], %o5
a012cf38:  80 a2 00 0d  cmp  %o0, %o5
a012cf3c:  02 80 00 06  be  0xa012cf54
a012cf40:  96 02 e0 01  inc  %o3
a012cf44:  98 0a e0 ff  and  %o3, 0xff, %o4
a012cf48:  80 a3 20 0a  cmp  %o4, 0xa
a012cf4c:  08 bf ff fa  bleu  0xa012cf34
a012cf50:  83 2b 20 02  sll  %o4, 2, %g1
a012cf54:  91 2b 20 02  sll  %o4, 2, %o0
a012cf58:  96 02 00 0a  add  %o0, %o2, %o3
a012cf5c:  81 c3 e0 08  retl
a012cf60:  d0 12 e0 02  lduh  [ %o3 + 2 ], %o0
