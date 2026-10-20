# leon2m FUN_a01595f4 0xa01595f4-0xa0159658 (100 bytes)
a01595f4:  9d e3 be c8  save  %sp, -312, %sp
a01595f8:  03 2a 00 aa  sethi  %hi(0xa802a800), %g1
a01595fc:  d0 00 62 18  ld  [ %g1 + 0x218 ], %o0	! 0xa802aa18
a0159600:  82 10 22 08  mov  0x208, %g1
a0159604:  92 07 bf 28  add  %fp, -216, %o1
a0159608:  c2 37 bf 34  sth  %g1, [ %fp + -204 ]
a015960c:  f0 27 bf 38  st  %i0, [ %fp + -200 ]
a0159610:  80 a6 60 00  cmp  %i1, 0
a0159614:  94 10 00 1a  mov  %i2, %o2
a0159618:  96 10 00 1b  mov  %i3, %o3
a015961c:  f0 27 bf 28  st  %i0, [ %fp + -216 ]
a0159620:  12 80 00 03  bne  0xa015962c
a0159624:  9a 06 7f ff  add  %i1, -1, %o5
a0159628:  9a 10 20 00  clr  %o5
a015962c:  82 10 3f ff  mov  -1, %g1
a0159630:  da 27 bf 3c  st  %o5, [ %fp + -196 ]
a0159634:  c2 37 bf 36  sth  %g1, [ %fp + -202 ]
a0159638:  7f ff f9 0a  call  0xa0157a60
a015963c:  da 27 bf 30  st  %o5, [ %fp + -208 ]
a0159640:  80 a6 60 00  cmp  %i1, 0
a0159644:  02 80 00 03  be  0xa0159650
a0159648:  c2 07 bf 28  ld  [ %fp + -216 ], %g1
a015964c:  c0 28 40 00  clrb  [ %g1 ]
a0159650:  81 c7 e0 08  ret
a0159654:  91 e8 00 08  restore  %g0, %o0, %o0
