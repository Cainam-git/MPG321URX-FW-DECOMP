# leon2m FUN_a0137644 0xa0137644-0xa01376ec (168 bytes)
a0137644:  9d e3 bf 78  save  %sp, -136, %sp
a0137648:  98 10 20 00  clr  %o4
a013764c:  9a 10 20 00  clr  %o5
a0137650:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a0137654:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a0137658:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a013765c:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0137660:  a0 10 20 64  mov  0x64, %l0
a0137664:  a4 10 20 00  clr  %l2
a0137668:  80 8e 20 ff  btst  0xff, %i0
a013766c:  12 80 00 12  bne  0xa01376b4
a0137670:  a2 07 bf d8  add  %fp, -40, %l1
a0137674:  90 10 20 01  mov  1, %o0
a0137678:  92 10 20 80  mov  0x80, %o1
a013767c:  94 10 00 11  mov  %l1, %o2
a0137680:  67 fd 53 94  call  0x4008c4d0
a0137684:  96 10 20 01  mov  1, %o3
a0137688:  c2 07 bf d8  ld  [ %fp + -40 ], %g1
a013768c:  80 a0 60 00  cmp  %g1, 0
a0137690:  12 bf ff fa  bne  0xa0137678
a0137694:  90 10 20 01  mov  1, %o0
a0137698:  10 80 00 12  b  0xa01376e0
a013769c:  a4 10 20 01  mov  1, %l2
a01376a0:  67 fd 56 c0  call  0x4008d1a0
a01376a4:  01 00 00 00  nop
a01376a8:  80 8c 20 ff  btst  0xff, %l0
a01376ac:  02 80 00 0e  be  0xa01376e4
a01376b0:  b0 0c a0 01  and  %l2, 1, %i0
a01376b4:  90 10 20 01  mov  1, %o0
a01376b8:  92 10 20 80  mov  0x80, %o1
a01376bc:  94 10 00 11  mov  %l1, %o2
a01376c0:  67 fd 53 84  call  0x4008c4d0
a01376c4:  96 10 20 01  mov  1, %o3
a01376c8:  d2 07 bf d8  ld  [ %fp + -40 ], %o1
a01376cc:  90 10 20 01  mov  1, %o0
a01376d0:  80 a2 60 00  cmp  %o1, 0
a01376d4:  12 bf ff f3  bne  0xa01376a0
a01376d8:  a0 04 3f ff  add  %l0, -1, %l0
a01376dc:  a4 10 20 01  mov  1, %l2
a01376e0:  b0 0c a0 01  and  %l2, 1, %i0
a01376e4:  81 c7 e0 08  ret
a01376e8:  81 e8 00 00  restore
