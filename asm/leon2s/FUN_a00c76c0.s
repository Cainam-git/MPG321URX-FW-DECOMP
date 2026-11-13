# leon2s FUN_a00c76c0 0xa00c76c0-0xa00c7770 (176 bytes)
a00c76c0:  9d e3 bf 98  save  %sp, -104, %sp
a00c76c4:  82 10 00 19  mov  %i1, %g1
a00c76c8:  bb 28 60 10  sll  %g1, 0x10, %i5
a00c76cc:  83 28 60 10  sll  %g1, 0x10, %g1
a00c76d0:  93 30 60 10  srl  %g1, 0x10, %o1
a00c76d4:  9e 0e 20 ff  and  %i0, 0xff, %o7
a00c76d8:  03 27 c7 07  sethi  %hi(0x9f1c1c00), %g1
a00c76dc:  9a 10 00 1a  mov  %i2, %o5
a00c76e0:  95 37 60 10  srl  %i5, 0x10, %o2
a00c76e4:  96 0e e0 ff  and  %i3, 0xff, %o3
a00c76e8:  31 27 c7 07  sethi  %hi(0x9f1c1c00), %i0
a00c76ec:  33 27 c7 07  sethi  %hi(0x9f1c1c00), %i1
a00c76f0:  98 10 62 c8  or  %g1, 0x2c8, %o4
a00c76f4:  a1 2b e0 02  sll  %o7, 2, %l0
a00c76f8:  b0 16 23 48  or  %i0, 0x348, %i0
a00c76fc:  b2 16 62 f0  or  %i1, 0x2f0, %i1
a00c7700:  b4 10 00 0f  mov  %o7, %i2
a00c7704:  b6 10 00 0a  mov  %o2, %i3
a00c7708:  ba 10 00 0b  mov  %o3, %i5
a00c770c:  80 a3 e0 02  cmp  %o7, 2
a00c7710:  b8 0b 60 ff  and  %o5, 0xff, %i4
a00c7714:  08 80 00 04  bleu  0xa00c7724
a00c7718:  90 10 00 0c  mov  %o4, %o0
a00c771c:  40 3a ee 4a  call  0xa0f83044
a00c7720:  81 e8 00 00  restore
a00c7724:  c2 03 00 10  ld  [ %o4 + %l0 ], %g1
a00c7728:  82 00 40 0a  add  %g1, %o2, %g1
a00c772c:  83 28 60 02  sll  %g1, 2, %g1
a00c7730:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00c7734:  82 10 40 1d  or  %g1, %i5, %g1
a00c7738:  c2 00 40 00  ld  [ %g1 ], %g1
a00c773c:  80 a2 e0 01  cmp  %o3, 1
a00c7740:  02 80 00 03  be  0xa00c774c
a00c7744:  b8 10 40 0d  or  %g1, %o5, %i4
a00c7748:  b8 28 40 0d  andn  %g1, %o5, %i4
a00c774c:  c2 02 00 10  ld  [ %o0 + %l0 ], %g1
a00c7750:  82 00 40 09  add  %g1, %o1, %g1
a00c7754:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00c7758:  83 28 60 02  sll  %g1, 2, %g1
a00c775c:  82 10 40 1d  or  %g1, %i5, %g1
a00c7760:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00c7764:  fa 20 40 00  st  %i5, [ %g1 ]
a00c7768:  81 c7 e0 08  ret
a00c776c:  81 e8 00 00  restore
