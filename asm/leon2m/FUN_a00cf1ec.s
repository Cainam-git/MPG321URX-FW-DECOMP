# leon2m FUN_a00cf1ec 0xa00cf1ec-0xa00cf23c (80 bytes)
a00cf1ec:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a00cf1f0:  94 0a 20 ff  and  %o0, 0xff, %o2
a00cf1f4:  92 10 60 58  or  %g1, 0x58, %o1
a00cf1f8:  96 10 20 00  clr  %o3
a00cf1fc:  98 10 20 00  clr  %o4
a00cf200:  91 2b 20 02  sll  %o4, 2, %o0
a00cf204:  9a 02 00 09  add  %o0, %o1, %o5
a00cf208:  96 02 e0 01  inc  %o3
a00cf20c:  c2 0b 60 01  ldub  [ %o5 + 1 ], %g1
a00cf210:  80 a0 40 0a  cmp  %g1, %o2
a00cf214:  02 80 00 07  be  0xa00cf230
a00cf218:  98 0a e0 ff  and  %o3, 0xff, %o4
a00cf21c:  80 a3 20 02  cmp  %o4, 2
a00cf220:  28 bf ff f9  bleu,a   0xa00cf204
a00cf224:  91 2b 20 02  sll  %o4, 2, %o0
a00cf228:  10 80 00 03  b  0xa00cf234
a00cf22c:  90 10 20 00  clr  %o0
a00cf230:  d0 0a 40 08  ldub  [ %o1 + %o0 ], %o0
a00cf234:  81 c3 e0 08  retl
a00cf238:  01 00 00 00  nop
