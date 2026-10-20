# leon2m FUN_a00f6898 0xa00f6898-0xa00f6940 (168 bytes)
a00f6898:  03 33 c0 3b  sethi  %hi(0xcf00ec00), %g1
a00f689c:  98 10 60 80  or  %g1, 0x80, %o4	! 0xcf00ec80
a00f68a0:  80 a2 20 01  cmp  %o0, 1
a00f68a4:  02 80 00 1f  be  0xa00f6920
a00f68a8:  96 10 62 40  or  %g1, 0x240, %o3
a00f68ac:  80 a2 20 01  cmp  %o0, 1
a00f68b0:  3a 80 00 0b  bcc,a   0xa00f68dc
a00f68b4:  98 10 60 a8  or  %g1, 0xa8, %o4
a00f68b8:  d0 03 00 00  ld  [ %o4 ], %o0
a00f68bc:  82 12 20 01  or  %o0, 1, %g1
a00f68c0:  da 02 c0 00  ld  [ %o3 ], %o5
a00f68c4:  82 08 60 ff  and  %g1, 0xff, %g1
a00f68c8:  9a 13 60 03  or  %o5, 3, %o5
a00f68cc:  c2 23 00 00  st  %g1, [ %o4 ]
a00f68d0:  98 0b 60 ff  and  %o5, 0xff, %o4
a00f68d4:  d8 22 c0 00  st  %o4, [ %o3 ]
a00f68d8:  30 80 00 18  b,a   0xa00f6938
a00f68dc:  80 a2 20 02  cmp  %o0, 2
a00f68e0:  02 bf ff f6  be  0xa00f68b8
a00f68e4:  96 10 62 68  or  %g1, 0x268, %o3
a00f68e8:  80 a2 20 03  cmp  %o0, 3
a00f68ec:  12 80 00 13  bne  0xa00f6938
a00f68f0:  19 33 c0 3b  sethi  %hi(0xcf00ec00), %o4
a00f68f4:  96 13 20 a8  or  %o4, 0xa8, %o3	! 0xcf00eca8
a00f68f8:  da 02 c0 00  ld  [ %o3 ], %o5
a00f68fc:  90 13 22 68  or  %o4, 0x268, %o0
a00f6900:  82 13 60 02  or  %o5, 2, %g1
a00f6904:  da 02 00 00  ld  [ %o0 ], %o5
a00f6908:  82 08 60 ff  and  %g1, 0xff, %g1
a00f690c:  c2 22 c0 00  st  %g1, [ %o3 ]
a00f6910:  9a 13 60 0c  or  %o5, 0xc, %o5
a00f6914:  96 0b 60 ff  and  %o5, 0xff, %o3
a00f6918:  d6 22 00 00  st  %o3, [ %o0 ]
a00f691c:  30 80 00 07  b,a   0xa00f6938
a00f6920:  d0 03 00 00  ld  [ %o4 ], %o0
a00f6924:  82 12 20 02  or  %o0, 2, %g1
a00f6928:  da 02 c0 00  ld  [ %o3 ], %o5
a00f692c:  82 08 60 ff  and  %g1, 0xff, %g1
a00f6930:  10 bf ff e7  b  0xa00f68cc
a00f6934:  9a 13 60 0c  or  %o5, 0xc, %o5
a00f6938:  81 c3 e0 08  retl
a00f693c:  01 00 00 00  nop
