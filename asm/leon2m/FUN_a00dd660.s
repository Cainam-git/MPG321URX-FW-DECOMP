# leon2m FUN_a00dd660 0xa00dd660-0xa00dd6b0 (80 bytes)
a00dd660:  9d e3 bf 98  save  %sp, -104, %sp
a00dd664:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a00dd668:  c2 03 60 68  ld  [ %o5 + 0x68 ], %g1	! 0xa8025c68
a00dd66c:  80 a0 60 00  cmp  %g1, 0
a00dd670:  02 80 00 0e  be  0xa00dd6a8
a00dd674:  a0 10 20 00  clr  %l0
a00dd678:  a2 13 60 68  or  %o5, 0x68, %l1
a00dd67c:  9a 10 20 00  clr  %o5
a00dd680:  25 00 06 63  sethi  %hi(0x198c00), %l2
a00dd684:  d2 04 40 0d  ld  [ %l1 + %o5 ], %o1
a00dd688:  40 00 06 ba  call  0xa00df170
a00dd68c:  90 14 a0 58  or  %l2, 0x58, %o0
a00dd690:  a0 04 20 01  inc  %l0
a00dd694:  9b 2c 20 02  sll  %l0, 2, %o5
a00dd698:  d0 04 40 0d  ld  [ %l1 + %o5 ], %o0
a00dd69c:  80 a2 20 00  cmp  %o0, 0
a00dd6a0:  32 bf ff fa  bne,a   0xa00dd688
a00dd6a4:  d2 04 40 0d  ld  [ %l1 + %o5 ], %o1
a00dd6a8:  81 c7 e0 08  ret
a00dd6ac:  81 e8 00 00  restore
