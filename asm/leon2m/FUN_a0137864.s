# leon2m FUN_a0137864 0xa0137864-0xa01378f0 (140 bytes)
a0137864:  9d e3 bf 90  save  %sp, -112, %sp
a0137868:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013786c:  80 a6 20 01  cmp  %i0, 1
a0137870:  02 80 00 0b  be  0xa013789c
a0137874:  c0 27 bf f0  clr  [ %fp + -16 ]
a0137878:  80 a6 20 01  cmp  %i0, 1
a013787c:  04 80 00 0e  ble  0xa01378b4
a0137880:  80 a6 20 02  cmp  %i0, 2
a0137884:  02 80 00 09  be  0xa01378a8
a0137888:  80 a6 20 03  cmp  %i0, 3
a013788c:  32 80 00 11  bne,a   0xa01378d0
a0137890:  f2 2f bf f1  stb  %i1, [ %fp + -15 ]
a0137894:  10 80 00 0d  b  0xa01378c8
a0137898:  82 10 20 05  mov  5, %g1
a013789c:  82 10 20 03  mov  3, %g1
a01378a0:  10 80 00 0b  b  0xa01378cc
a01378a4:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a01378a8:  82 10 20 04  mov  4, %g1
a01378ac:  10 80 00 08  b  0xa01378cc
a01378b0:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a01378b4:  80 a6 20 00  cmp  %i0, 0
a01378b8:  02 bf ff fa  be  0xa01378a0
a01378bc:  82 10 20 02  mov  2, %g1
a01378c0:  10 80 00 04  b  0xa01378d0
a01378c4:  f2 2f bf f1  stb  %i1, [ %fp + -15 ]
a01378c8:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a01378cc:  f2 2f bf f1  stb  %i1, [ %fp + -15 ]
a01378d0:  90 10 20 02  mov  2, %o0
a01378d4:  92 10 20 02  mov  2, %o1
a01378d8:  94 07 bf f0  add  %fp, -16, %o2
a01378dc:  7f ff fe 00  call  0xa01370dc
a01378e0:  96 10 20 00  clr  %o3
a01378e4:  01 00 00 00  nop
a01378e8:  81 c7 e0 08  ret
a01378ec:  81 e8 00 00  restore
