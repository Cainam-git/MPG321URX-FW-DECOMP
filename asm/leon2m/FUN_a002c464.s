# leon2m FUN_a002c464 0xa002c464-0xa002c4a8 (68 bytes)
a002c464:  83 2a 20 10  sll  %o0, 0x10, %g1
a002c468:  91 30 60 10  srl  %g1, 0x10, %o0
a002c46c:  92 0a 60 ff  and  %o1, 0xff, %o1
a002c470:  82 02 00 09  add  %o0, %o1, %g1
a002c474:  91 28 60 02  sll  %g1, 2, %o0
a002c478:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a002c47c:  90 12 00 09  or  %o0, %o1, %o0
a002c480:  c2 02 00 00  ld  [ %o0 ], %g1
a002c484:  92 0a e0 ff  and  %o3, 0xff, %o1
a002c488:  96 28 40 09  andn  %g1, %o1, %o3
a002c48c:  94 0a a0 ff  and  %o2, 0xff, %o2
a002c490:  92 12 c0 0a  or  %o3, %o2, %o1
a002c494:  83 2a 60 10  sll  %o1, 0x10, %g1
a002c498:  97 30 60 10  srl  %g1, 0x10, %o3
a002c49c:  d6 22 00 00  st  %o3, [ %o0 ]
a002c4a0:  81 c3 e0 08  retl
a002c4a4:  01 00 00 00  nop
