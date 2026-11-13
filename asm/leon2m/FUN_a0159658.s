# leon2m FUN_a0159658 0xa0159658-0xa01596b8 (96 bytes)
a0159658:  9d e3 be c8  save  %sp, -312, %sp
a015965c:  82 10 22 08  mov  0x208, %g1
a0159660:  92 07 bf 28  add  %fp, -216, %o1
a0159664:  c2 37 bf 34  sth  %g1, [ %fp + -204 ]
a0159668:  f2 27 bf 38  st  %i1, [ %fp + -200 ]
a015966c:  90 10 00 18  mov  %i0, %o0
a0159670:  80 a6 a0 00  cmp  %i2, 0
a0159674:  94 10 00 1b  mov  %i3, %o2
a0159678:  96 10 00 1c  mov  %i4, %o3
a015967c:  f2 27 bf 28  st  %i1, [ %fp + -216 ]
a0159680:  12 80 00 03  bne  0xa015968c
a0159684:  9a 06 bf ff  add  %i2, -1, %o5
a0159688:  9a 10 20 00  clr  %o5
a015968c:  82 10 3f ff  mov  -1, %g1
a0159690:  da 27 bf 3c  st  %o5, [ %fp + -196 ]
a0159694:  c2 37 bf 36  sth  %g1, [ %fp + -202 ]
a0159698:  7f ff f8 f2  call  0xa0157a60
a015969c:  da 27 bf 30  st  %o5, [ %fp + -208 ]
a01596a0:  80 a6 a0 00  cmp  %i2, 0
a01596a4:  02 80 00 03  be  0xa01596b0
a01596a8:  c2 07 bf 28  ld  [ %fp + -216 ], %g1
a01596ac:  c0 28 40 00  clrb  [ %g1 ]
a01596b0:  81 c7 e0 08  ret
a01596b4:  91 e8 00 08  restore  %g0, %o0, %o0
