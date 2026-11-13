# leon2m FUN_a00f67d0 0xa00f67d0-0xa00f6834 (100 bytes)
a00f67d0:  03 33 c0 3b  sethi  %hi(0xcf00ec00), %g1
a00f67d4:  80 a2 20 00  cmp  %o0, 0
a00f67d8:  02 80 00 12  be  0xa00f6820
a00f67dc:  9a 10 60 80  or  %g1, 0x80, %o5
a00f67e0:  03 33 c0 3b  sethi  %hi(0xcf00ec00), %g1
a00f67e4:  80 a2 20 01  cmp  %o0, 1
a00f67e8:  02 80 00 0a  be  0xa00f6810
a00f67ec:  9a 10 60 80  or  %g1, 0x80, %o5
a00f67f0:  03 33 c0 3b  sethi  %hi(0xcf00ec00), %g1
a00f67f4:  80 a2 20 02  cmp  %o0, 2
a00f67f8:  02 80 00 0a  be  0xa00f6820
a00f67fc:  9a 10 60 a8  or  %g1, 0xa8, %o5
a00f6800:  03 33 c0 3b  sethi  %hi(0xcf00ec00), %g1
a00f6804:  80 a2 20 03  cmp  %o0, 3
a00f6808:  12 80 00 09  bne  0xa00f682c
a00f680c:  9a 10 60 a8  or  %g1, 0xa8, %o5
a00f6810:  d0 03 40 00  ld  [ %o5 ], %o0
a00f6814:  82 0a 20 fd  and  %o0, 0xfd, %g1
a00f6818:  c2 23 40 00  st  %g1, [ %o5 ]
a00f681c:  30 80 00 04  b,a   0xa00f682c
a00f6820:  d0 03 40 00  ld  [ %o5 ], %o0
a00f6824:  10 bf ff fd  b  0xa00f6818
a00f6828:  82 0a 20 fe  and  %o0, 0xfe, %g1
a00f682c:  81 c3 e0 08  retl
a00f6830:  01 00 00 00  nop
