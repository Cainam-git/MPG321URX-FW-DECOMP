# leon2m FUN_a0132dd8 0xa0132dd8-0xa0132e1c (68 bytes)
a0132dd8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0132ddc:  9a 10 20 00  clr  %o5
a0132de0:  82 10 20 00  clr  %g1
a0132de4:  83 3a 00 01  sra  %o0, %g1, %g1
a0132de8:  80 a0 60 01  cmp  %g1, 1
a0132dec:  02 80 00 08  be  0xa0132e0c
a0132df0:  82 0a 60 01  and  %o1, 1, %g1
a0132df4:  9a 03 60 01  inc  %o5
a0132df8:  82 0b 60 ff  and  %o5, 0xff, %g1
a0132dfc:  80 a0 60 07  cmp  %g1, 7
a0132e00:  08 bf ff fa  bleu  0xa0132de8
a0132e04:  83 3a 00 01  sra  %o0, %g1, %g1
a0132e08:  82 0a 60 01  and  %o1, 1, %g1
a0132e0c:  93 28 60 04  sll  %g1, 4, %o1
a0132e10:  90 12 40 0d  or  %o1, %o5, %o0
a0132e14:  81 c3 e0 08  retl
a0132e18:  90 0a 20 ff  and  %o0, 0xff, %o0
