# leon2m FUN_a010f65c 0xa010f65c-0xa010f724 (200 bytes)
a010f65c:  90 0a 20 ff  and  %o0, 0xff, %o0
a010f660:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010f664:  80 a2 20 01  cmp  %o0, 1
a010f668:  02 80 00 29  be  0xa010f70c
a010f66c:  96 10 63 04  or  %g1, 0x304, %o3
a010f670:  d2 12 e0 0e  lduh  [ %o3 + 0xe ], %o1
a010f674:  98 02 7f ff  add  %o1, -1, %o4
a010f678:  d4 0a e0 24  ldub  [ %o3 + 0x24 ], %o2
a010f67c:  c2 12 e0 0c  lduh  [ %o3 + 0xc ], %g1
a010f680:  92 5b 00 01  smul  %o4, %g1, %o1
a010f684:  9b 32 a0 03  srl  %o2, 3, %o5
a010f688:  98 5a 40 0d  smul  %o1, %o5, %o4
a010f68c:  95 3b 20 1f  sra  %o4, 0x1f, %o2
a010f690:  83 32 a0 1b  srl  %o2, 0x1b, %g1
a010f694:  d2 0a e0 3e  ldub  [ %o3 + 0x3e ], %o1
a010f698:  94 03 00 01  add  %o4, %g1, %o2
a010f69c:  80 a2 20 00  cmp  %o0, 0
a010f6a0:  9a 12 60 02  or  %o1, 2, %o5
a010f6a4:  99 3a a0 05  sra  %o2, 5, %o4
a010f6a8:  11 20 00 00  sethi  %hi(0x80000000), %o0
a010f6ac:  92 13 00 08  or  %o4, %o0, %o1
a010f6b0:  da 2a e0 3e  stb  %o5, [ %o3 + 0x3e ]
a010f6b4:  12 80 00 0c  bne  0xa010f6e4
a010f6b8:  94 10 00 09  mov  %o1, %o2
a010f6bc:  c2 02 e0 04  ld  [ %o3 + 4 ], %g1
a010f6c0:  19 34 00 c8  sethi  %hi(0xd0032000), %o4
a010f6c4:  9a 00 40 09  add  %g1, %o1, %o5
a010f6c8:  94 13 22 80  or  %o4, 0x280, %o2
a010f6cc:  da 22 80 00  st  %o5, [ %o2 ]
a010f6d0:  d0 02 e0 08  ld  [ %o3 + 8 ], %o0
a010f6d4:  17 34 00 e8  sethi  %hi(0xd003a000), %o3
a010f6d8:  98 02 00 09  add  %o0, %o1, %o4
a010f6dc:  10 80 00 0f  b  0xa010f718
a010f6e0:  82 12 e2 80  or  %o3, 0x280, %g1
a010f6e4:  d2 02 e0 04  ld  [ %o3 + 4 ], %o1
a010f6e8:  03 34 00 c8  sethi  %hi(0xd0032000), %g1
a010f6ec:  98 10 62 84  or  %g1, 0x284, %o4	! 0xd0032284
a010f6f0:  9a 02 40 0a  add  %o1, %o2, %o5
a010f6f4:  da 23 00 00  st  %o5, [ %o4 ]
a010f6f8:  d0 02 e0 08  ld  [ %o3 + 8 ], %o0
a010f6fc:  13 34 00 e8  sethi  %hi(0xd003a000), %o1
a010f700:  98 02 00 0a  add  %o0, %o2, %o4
a010f704:  10 80 00 05  b  0xa010f718
a010f708:  82 12 62 84  or  %o1, 0x284, %g1
a010f70c:  13 2a 00 b6  sethi  %hi(0xa802d800), %o1
a010f710:  10 bf ff d8  b  0xa010f670
a010f714:  96 12 60 04  or  %o1, 4, %o3	! 0xa802d804
a010f718:  d8 20 40 00  st  %o4, [ %g1 ]
a010f71c:  81 c3 e0 08  retl
a010f720:  01 00 00 00  nop
