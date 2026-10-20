# leon2m FUN_a0129810 0xa0129810-0xa01298d8 (200 bytes)
a0129810:  9d e3 bf 40  save  %sp, -192, %sp
a0129814:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a0129818:  b2 10 60 92  or  %g1, 0x92, %i1	! 0xa802d892
a012981c:  7f ff 7d 8e  call  0xa0108e54
a0129820:  e0 0e 60 01  ldub  [ %i1 + 1 ], %l0
a0129824:  9e 0a 20 ff  and  %o0, 0xff, %o7
a0129828:  80 a3 e0 01  cmp  %o7, 1
a012982c:  12 80 00 28  bne  0xa01298cc
a0129830:  b0 10 20 00  clr  %i0
a0129834:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0129838:  d8 02 23 d0  ld  [ %o0 + 0x3d0 ], %o4	! 0xa802e3d0
a012983c:  1b 01 00 00  sethi  %hi(0x4000000), %o5
a0129840:  80 8b 00 0d  btst  %o4, %o5
a0129844:  32 80 00 23  bne,a   0xa01298d0
a0129848:  b0 0e 20 01  and  %i0, 1, %i0
a012984c:  13 00 06 60  sethi  %hi(0x198000), %o1
a0129850:  9a 12 63 80  or  %o1, 0x380, %o5	! 0x198380
a0129854:  82 03 60 58  add  %o5, 0x58, %g1
a0129858:  90 07 bf a0  add  %fp, -96, %o0
a012985c:  80 a4 20 00  cmp  %l0, 0
a0129860:  12 80 00 1b  bne  0xa01298cc
a0129864:  92 10 20 01  mov  1, %o1
a0129868:  d4 18 60 50  ldd  [ %g1 + 0x50 ], %o2
a012986c:  d4 3f bf f0  std  %o2, [ %fp + -16 ]
a0129870:  d4 1b 60 58  ldd  [ %o5 + 0x58 ], %o2
a0129874:  d8 18 60 40  ldd  [ %g1 + 0x40 ], %o4
a0129878:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a012987c:  d8 18 60 48  ldd  [ %g1 + 0x48 ], %o4
a0129880:  d4 3f bf a0  std  %o2, [ %fp + -96 ]
a0129884:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0129888:  de 2e 60 01  stb  %o7, [ %i1 + 1 ]
a012988c:  d4 18 60 08  ldd  [ %g1 + 8 ], %o2
a0129890:  e0 18 60 10  ldd  [ %g1 + 0x10 ], %l0
a0129894:  e4 18 60 18  ldd  [ %g1 + 0x18 ], %l2
a0129898:  e8 18 60 20  ldd  [ %g1 + 0x20 ], %l4
a012989c:  ec 18 60 28  ldd  [ %g1 + 0x28 ], %l6
a01298a0:  f8 18 60 30  ldd  [ %g1 + 0x30 ], %i4
a01298a4:  f4 18 60 38  ldd  [ %g1 + 0x38 ], %i2
a01298a8:  d4 3f bf a8  std  %o2, [ %fp + -88 ]
a01298ac:  e0 3f bf b0  std  %l0, [ %fp + -80 ]
a01298b0:  e4 3f bf b8  std  %l2, [ %fp + -72 ]
a01298b4:  e8 3f bf c0  std  %l4, [ %fp + -64 ]
a01298b8:  ec 3f bf c8  std  %l6, [ %fp + -56 ]
a01298bc:  f8 3f bf d0  std  %i4, [ %fp + -48 ]
a01298c0:  40 00 7a cd  call  0xa01483f4
a01298c4:  f4 3f bf d8  std  %i2, [ %fp + -40 ]
a01298c8:  b0 10 20 01  mov  1, %i0
a01298cc:  b0 0e 20 01  and  %i0, 1, %i0
a01298d0:  81 c7 e0 08  ret
a01298d4:  81 e8 00 00  restore
