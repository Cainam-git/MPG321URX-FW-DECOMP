# leon2m FUN_a00f16d8 0xa00f16d8-0xa00f176c (148 bytes)
a00f16d8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f16dc:  80 a2 20 02  cmp  %o0, 2
a00f16e0:  02 80 00 0e  be  0xa00f1718
a00f16e4:  99 2a 60 10  sll  %o1, 0x10, %o4
a00f16e8:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00f16ec:  96 02 00 08  add  %o0, %o0, %o3
a00f16f0:  92 10 62 7a  or  %g1, 0x27a, %o1
a00f16f4:  da 12 40 0b  lduh  [ %o1 + %o3 ], %o5
a00f16f8:  91 33 20 10  srl  %o4, 0x10, %o0
a00f16fc:  82 03 40 08  add  %o5, %o0, %g1
a00f1700:  93 28 60 02  sll  %g1, 2, %o1
a00f1704:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00f1708:  90 12 40 0b  or  %o1, %o3, %o0
a00f170c:  98 0a a0 ff  and  %o2, 0xff, %o4
a00f1710:  d8 22 00 00  st  %o4, [ %o0 ]
a00f1714:  30 80 00 14  b,a   0xa00f1764
a00f1718:  9b 2a 60 10  sll  %o1, 0x10, %o5
a00f171c:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00f1720:  93 33 60 10  srl  %o5, 0x10, %o1
a00f1724:  94 0a a0 ff  and  %o2, 0xff, %o2
a00f1728:  90 10 62 7a  or  %g1, 0x27a, %o0
a00f172c:  96 10 20 00  clr  %o3
a00f1730:  9a 10 20 00  clr  %o5
a00f1734:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a00f1738:  9a 03 40 0d  add  %o5, %o5, %o5
a00f173c:  c2 12 00 0d  lduh  [ %o0 + %o5 ], %g1
a00f1740:  82 00 40 09  add  %g1, %o1, %g1
a00f1744:  9b 28 60 02  sll  %g1, 2, %o5
a00f1748:  82 13 40 0c  or  %o5, %o4, %g1
a00f174c:  96 02 e0 01  inc  %o3
a00f1750:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00f1754:  d4 20 40 00  st  %o2, [ %g1 ]
a00f1758:  80 a3 60 01  cmp  %o5, 1
a00f175c:  08 bf ff f8  bleu  0xa00f173c
a00f1760:  9a 03 40 0d  add  %o5, %o5, %o5
a00f1764:  81 c3 e0 08  retl
a00f1768:  01 00 00 00  nop
