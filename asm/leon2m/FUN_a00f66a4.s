# leon2m FUN_a00f66a4 0xa00f66a4-0xa00f67d0 (300 bytes)
a00f66a4:  80 8a 20 01  btst  1, %o0
a00f66a8:  02 80 00 08  be  0xa00f66c8
a00f66ac:  80 8a 20 02  btst  2, %o0
a00f66b0:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f66b4:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xcf00ef00
a00f66b8:  d8 03 40 00  ld  [ %o5 ], %o4
a00f66bc:  82 0b 3f bf  and  %o4, -65, %g1
a00f66c0:  c2 23 40 00  st  %g1, [ %o5 ]
a00f66c4:  80 8a 20 02  btst  2, %o0
a00f66c8:  02 80 00 08  be  0xa00f66e8
a00f66cc:  80 8a 20 04  btst  4, %o0
a00f66d0:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f66d4:  98 13 63 00  or  %o5, 0x300, %o4	! 0xcf00ef00
a00f66d8:  c2 03 00 00  ld  [ %o4 ], %g1
a00f66dc:  82 08 7f df  and  %g1, -33, %g1
a00f66e0:  c2 23 00 00  st  %g1, [ %o4 ]
a00f66e4:  80 8a 20 04  btst  4, %o0
a00f66e8:  02 80 00 08  be  0xa00f6708
a00f66ec:  80 8a 20 08  btst  8, %o0
a00f66f0:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f66f4:  98 13 63 00  or  %o5, 0x300, %o4	! 0xcf00ef00
a00f66f8:  c2 03 00 00  ld  [ %o4 ], %g1
a00f66fc:  82 08 7f ef  and  %g1, -17, %g1
a00f6700:  c2 23 00 00  st  %g1, [ %o4 ]
a00f6704:  80 8a 20 08  btst  8, %o0
a00f6708:  02 80 00 08  be  0xa00f6728
a00f670c:  80 8a 20 10  btst  0x10, %o0
a00f6710:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f6714:  98 13 63 00  or  %o5, 0x300, %o4	! 0xcf00ef00
a00f6718:  c2 03 00 00  ld  [ %o4 ], %g1
a00f671c:  82 08 7f f7  and  %g1, -9, %g1
a00f6720:  c2 23 00 00  st  %g1, [ %o4 ]
a00f6724:  80 8a 20 10  btst  0x10, %o0
a00f6728:  02 80 00 08  be  0xa00f6748
a00f672c:  80 8a 20 20  btst  0x20, %o0
a00f6730:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f6734:  98 13 63 00  or  %o5, 0x300, %o4	! 0xcf00ef00
a00f6738:  c2 03 00 00  ld  [ %o4 ], %g1
a00f673c:  82 08 7f fb  and  %g1, -5, %g1
a00f6740:  c2 23 00 00  st  %g1, [ %o4 ]
a00f6744:  80 8a 20 20  btst  0x20, %o0
a00f6748:  02 80 00 08  be  0xa00f6768
a00f674c:  80 8a 20 40  btst  0x40, %o0
a00f6750:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f6754:  98 13 63 30  or  %o5, 0x330, %o4	! 0xcf00ef30
a00f6758:  c2 03 00 00  ld  [ %o4 ], %g1
a00f675c:  82 08 7f 7f  and  %g1, -129, %g1
a00f6760:  c2 23 00 00  st  %g1, [ %o4 ]
a00f6764:  80 8a 20 40  btst  0x40, %o0
a00f6768:  02 80 00 08  be  0xa00f6788
a00f676c:  80 8a 20 80  btst  0x80, %o0
a00f6770:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f6774:  98 13 63 30  or  %o5, 0x330, %o4	! 0xcf00ef30
a00f6778:  c2 03 00 00  ld  [ %o4 ], %g1
a00f677c:  82 08 7f bf  and  %g1, -65, %g1
a00f6780:  c2 23 00 00  st  %g1, [ %o4 ]
a00f6784:  80 8a 20 80  btst  0x80, %o0
a00f6788:  02 80 00 08  be  0xa00f67a8
a00f678c:  03 33 c0 3b  sethi  %hi(0xcf00ec00), %g1
a00f6790:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f6794:  90 13 63 30  or  %o5, 0x330, %o0	! 0xcf00ef30
a00f6798:  c2 02 00 00  ld  [ %o0 ], %g1
a00f679c:  98 08 7f ef  and  %g1, -17, %o4
a00f67a0:  d8 22 00 00  st  %o4, [ %o0 ]
a00f67a4:  03 33 c0 3b  sethi  %hi(0xcf00ec00), %g1
a00f67a8:  98 10 63 30  or  %g1, 0x330, %o4	! 0xcf00ef30
a00f67ac:  d0 03 00 00  ld  [ %o4 ], %o0
a00f67b0:  80 8a 20 e0  btst  0xe0, %o0
a00f67b4:  12 80 00 05  bne  0xa00f67c8
a00f67b8:  01 00 00 00  nop
a00f67bc:  d0 03 00 00  ld  [ %o4 ], %o0
a00f67c0:  9a 0a 3f fe  and  %o0, -2, %o5
a00f67c4:  da 23 00 00  st  %o5, [ %o4 ]
a00f67c8:  81 c3 e0 08  retl
a00f67cc:  01 00 00 00  nop
