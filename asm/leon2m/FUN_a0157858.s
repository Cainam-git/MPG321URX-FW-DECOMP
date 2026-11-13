# leon2m FUN_a0157858 0xa0157858-0xa01578bc (100 bytes)
a0157858:  80 8a 20 03  btst  3, %o0
a015785c:  12 80 00 12  bne  0xa01578a4
a0157860:  94 10 00 08  mov  %o0, %o2
a0157864:  03 3f bf bf  sethi  %hi(0xfefefc00), %g1
a0157868:  da 02 00 00  ld  [ %o0 ], %o5
a015786c:  96 10 62 ff  or  %g1, 0x2ff, %o3
a0157870:  82 03 40 0b  add  %o5, %o3, %g1
a0157874:  19 20 20 20  sethi  %hi(0x80808000), %o4
a0157878:  9a 28 40 0d  andn  %g1, %o5, %o5
a015787c:  98 13 20 80  or  %o4, 0x80, %o4
a0157880:  80 8b 40 0c  btst  %o5, %o4
a0157884:  32 80 00 09  bne,a   0xa01578a8
a0157888:  c2 4a 00 00  ldsb  [ %o0 ], %g1
a015788c:  90 02 20 04  add  %o0, 4, %o0
a0157890:  c2 02 00 00  ld  [ %o0 ], %g1
a0157894:  9a 00 40 0b  add  %g1, %o3, %o5
a0157898:  82 2b 40 01  andn  %o5, %g1, %g1
a015789c:  10 bf ff fa  b  0xa0157884
a01578a0:  80 88 40 0c  btst  %g1, %o4
a01578a4:  c2 4a 00 00  ldsb  [ %o0 ], %g1
a01578a8:  80 a0 60 00  cmp  %g1, 0
a01578ac:  32 bf ff fe  bne,a   0xa01578a4
a01578b0:  90 02 20 01  inc  %o0
a01578b4:  81 c3 e0 08  retl
a01578b8:  90 22 00 0a  sub  %o0, %o2, %o0
