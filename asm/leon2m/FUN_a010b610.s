# leon2m FUN_a010b610 0xa010b610-0xa010b6e4 (212 bytes)
a010b610:  9d e3 bf 98  save  %sp, -104, %sp
a010b614:  40 00 46 5d  call  0xa011cf88
a010b618:  01 00 00 00  nop
a010b61c:  1b 33 c0 2e  sethi  %hi(0xcf00b800), %o5
a010b620:  82 0a 20 ff  and  %o0, 0xff, %g1
a010b624:  13 34 00 c0  sethi  %hi(0xd0030000), %o1
a010b628:  a0 12 60 f0  or  %o1, 0xf0, %l0	! 0xd00300f0
a010b62c:  98 13 60 44  or  %o5, 0x44, %o4
a010b630:  96 13 60 70  or  %o5, 0x70, %o3
a010b634:  80 a0 60 81  cmp  %g1, 0x81
a010b638:  08 80 00 08  bleu  0xa010b658
a010b63c:  90 10 20 01  mov  1, %o0
a010b640:  c2 03 00 00  ld  [ %o4 ], %g1
a010b644:  9e 10 60 40  or  %g1, 0x40, %o7
a010b648:  de 23 00 00  st  %o7, [ %o4 ]
a010b64c:  d8 02 c0 00  ld  [ %o3 ], %o4
a010b650:  94 13 20 80  or  %o4, 0x80, %o2
a010b654:  d4 22 c0 00  st  %o2, [ %o3 ]
a010b658:  da 04 00 00  ld  [ %l0 ], %o5
a010b65c:  13 01 00 00  sethi  %hi(0x4000000), %o1
a010b660:  96 2b 40 09  andn  %o5, %o1, %o3
a010b664:  d6 24 00 00  st  %o3, [ %l0 ]
a010b668:  67 fe 06 ce  call  0x4008d1a0
a010b66c:  01 00 00 00  nop
a010b670:  d0 04 00 00  ld  [ %l0 ], %o0
a010b674:  03 01 00 00  sethi  %hi(0x4000000), %g1
a010b678:  9e 12 00 01  or  %o0, %g1, %o7
a010b67c:  de 24 00 00  st  %o7, [ %l0 ]
a010b680:  d8 04 00 00  ld  [ %l0 ], %o4
a010b684:  94 13 20 10  or  %o4, 0x10, %o2
a010b688:  d4 24 00 00  st  %o2, [ %l0 ]
a010b68c:  67 fe 06 c5  call  0x4008d1a0
a010b690:  90 10 20 02  mov  2, %o0
a010b694:  d2 04 00 00  ld  [ %l0 ], %o1
a010b698:  96 0a 7f ef  and  %o1, -17, %o3
a010b69c:  d6 24 00 00  st  %o3, [ %l0 ]
a010b6a0:  da 04 00 00  ld  [ %l0 ], %o5
a010b6a4:  90 13 64 00  or  %o5, 0x400, %o0
a010b6a8:  d0 24 00 00  st  %o0, [ %l0 ]
a010b6ac:  c2 04 00 00  ld  [ %l0 ], %g1
a010b6b0:  17 00 00 10  sethi  %hi(0x4000), %o3
a010b6b4:  9e 10 40 0b  or  %g1, %o3, %o7
a010b6b8:  19 34 00 e0  sethi  %hi(0xd0038000), %o4
a010b6bc:  de 24 00 00  st  %o7, [ %l0 ]
a010b6c0:  90 13 20 f0  or  %o4, 0xf0, %o0
a010b6c4:  d4 02 00 00  ld  [ %o0 ], %o2
a010b6c8:  92 12 a4 00  or  %o2, 0x400, %o1
a010b6cc:  d2 22 00 00  st  %o1, [ %o0 ]
a010b6d0:  da 02 00 00  ld  [ %o0 ], %o5
a010b6d4:  a0 13 40 0b  or  %o5, %o3, %l0
a010b6d8:  e0 22 00 00  st  %l0, [ %o0 ]
a010b6dc:  81 c7 e0 08  ret
a010b6e0:  81 e8 00 00  restore
