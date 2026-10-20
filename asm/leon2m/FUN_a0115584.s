# leon2m FUN_a0115584 0xa0115584-0xa0115644 (192 bytes)
a0115584:  9d e3 bf 90  save  %sp, -112, %sp
a0115588:  90 10 20 04  mov  4, %o0
a011558c:  c0 27 bf f0  clr  [ %fp + -16 ]
a0115590:  c0 37 bf f4  clrh  [ %fp + -12 ]
a0115594:  92 10 20 06  mov  6, %o1
a0115598:  40 00 1e 3a  call  0xa011ce80
a011559c:  94 07 bf f0  add  %fp, -16, %o2
a01155a0:  d0 0f bf f0  ldub  [ %fp + -16 ], %o0
a01155a4:  82 0a 20 e0  and  %o0, 0xe0, %g1
a01155a8:  80 a0 60 a0  cmp  %g1, 0xa0
a01155ac:  02 80 00 11  be  0xa01155f0
a01155b0:  90 10 20 00  clr  %o0
a01155b4:  90 10 20 01  mov  1, %o0
a01155b8:  80 a6 20 00  cmp  %i0, 0
a01155bc:  02 80 00 06  be  0xa01155d4
a01155c0:  82 10 20 03  mov  3, %g1
a01155c4:  94 1e 20 01  xor  %i0, 1, %o2
a01155c8:  80 a0 00 0a  cmp  %g0, %o2
a01155cc:  92 40 20 00  addx  %g0, 0, %o1
a01155d0:  82 02 60 04  add  %o1, 4, %g1
a01155d4:  80 8a 20 ff  btst  0xff, %o0
a01155d8:  12 80 00 19  bne  0xa011563c
a01155dc:  b0 10 3f ff  mov  -1, %i0
a01155e0:  98 08 60 ff  and  %g1, 0xff, %o4
a01155e4:  96 07 80 0c  add  %fp, %o4, %o3
a01155e8:  10 80 00 15  b  0xa011563c
a01155ec:  f0 0a ff f0  ldub  [ %o3 + -16 ], %i0
a01155f0:  d4 0f bf f1  ldub  [ %fp + -15 ], %o2
a01155f4:  80 a2 a0 00  cmp  %o2, 0
a01155f8:  96 10 20 00  clr  %o3
a01155fc:  02 80 00 0b  be  0xa0115628
a0115600:  98 10 20 00  clr  %o4
a0115604:  82 10 20 00  clr  %g1
a0115608:  92 07 bf f8  add  %fp, -8, %o1
a011560c:  9e 02 40 01  add  %o1, %g1, %o7
a0115610:  98 03 20 01  inc  %o4
a0115614:  da 0b ff fa  ldub  [ %o7 + -6 ], %o5
a0115618:  82 0b 20 ff  and  %o4, 0xff, %g1
a011561c:  80 a0 40 0a  cmp  %g1, %o2
a0115620:  0a bf ff fb  bcs  0xa011560c
a0115624:  96 1a c0 0d  xor  %o3, %o5, %o3
a0115628:  80 8a e0 ff  btst  0xff, %o3
a011562c:  02 bf ff e4  be  0xa01155bc
a0115630:  80 a6 20 00  cmp  %i0, 0
a0115634:  10 bf ff e2  b  0xa01155bc
a0115638:  90 10 20 01  mov  1, %o0
a011563c:  81 c7 e0 08  ret
a0115640:  81 e8 00 00  restore
