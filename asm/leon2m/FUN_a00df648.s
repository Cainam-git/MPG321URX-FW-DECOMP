# leon2m FUN_a00df648 0xa00df648-0xa00df698 (80 bytes)
a00df648:  1b 2a aa aa  sethi  %hi(0xaaaaa800), %o5
a00df64c:  82 13 62 ab  or  %o5, 0x2ab, %g1	! 0xaaaaaaab
a00df650:  99 2a 60 11  sll  %o1, 0x11, %o4
a00df654:  80 53 00 01  umul  %o4, %g1, %g0
a00df658:  93 40 00 00  rd  %y, %o1
a00df65c:  97 32 60 03  srl  %o1, 3, %o3
a00df660:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00df664:  91 2a 20 02  sll  %o0, 2, %o0
a00df668:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00df66c:  83 32 60 0b  srl  %o1, 0xb, %g1
a00df670:  da 22 00 0b  st  %o5, [ %o0 + %o3 ]
a00df674:  98 08 60 ff  and  %g1, 0xff, %o4
a00df678:  82 12 e0 04  or  %o3, 4, %g1
a00df67c:  9b 32 60 13  srl  %o1, 0x13, %o5
a00df680:  d8 22 00 01  st  %o4, [ %o0 + %g1 ]
a00df684:  96 12 e0 08  or  %o3, 8, %o3
a00df688:  92 0b 60 ff  and  %o5, 0xff, %o1
a00df68c:  d2 22 00 0b  st  %o1, [ %o0 + %o3 ]
a00df690:  81 c3 e0 08  retl
a00df694:  01 00 00 00  nop
