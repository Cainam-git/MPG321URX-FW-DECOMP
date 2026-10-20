# leon2m FUN_a00e05d8 0xa00e05d8-0xa00e0740 (360 bytes)
a00e05d8:  9d e3 bf 88  save  %sp, -120, %sp
a00e05dc:  83 36 60 08  srl  %i1, 8, %g1
a00e05e0:  a0 08 60 0f  and  %g1, 0xf, %l0
a00e05e4:  80 a6 20 02  cmp  %i0, 2
a00e05e8:  14 80 00 43  bg  0xa00e06f4
a00e05ec:  a2 0e 60 ff  and  %i1, 0xff, %l1
a00e05f0:  2b 2a 00 97  sethi  %hi(0xa8025c00), %l5
a00e05f4:  92 15 61 10  or  %l5, 0x110, %o1	! 0xa8025d10
a00e05f8:  d8 0a 40 18  ldub  [ %o1 + %i0 ], %o4
a00e05fc:  94 0b 20 ff  and  %o4, 0xff, %o2
a00e0600:  11 33 c0 8a  sethi  %hi(0xcf022800), %o0
a00e0604:  1f 33 c0 8b  sethi  %hi(0xcf022c00), %o7
a00e0608:  25 33 c0 8c  sethi  %hi(0xcf023000), %l2
a00e060c:  a7 2e 20 02  sll  %i0, 2, %l3
a00e0610:  a8 07 bf f8  add  %fp, -8, %l4
a00e0614:  d0 27 bf e8  st  %o0, [ %fp + -24 ]
a00e0618:  de 27 bf ec  st  %o7, [ %fp + -20 ]
a00e061c:  e4 27 bf f0  st  %l2, [ %fp + -16 ]
a00e0620:  9a 04 c0 14  add  %l3, %l4, %o5
a00e0624:  80 a2 80 10  cmp  %o2, %l0
a00e0628:  d6 03 7f f0  ld  [ %o5 + -16 ], %o3
a00e062c:  02 80 00 05  be  0xa00e0640
a00e0630:  95 2c 60 02  sll  %l1, 2, %o2
a00e0634:  e0 22 e3 f8  st  %l0, [ %o3 + 0x3f8 ]
a00e0638:  e0 2a 40 18  stb  %l0, [ %o1 + %i0 ]
a00e063c:  98 10 00 10  mov  %l0, %o4
a00e0640:  9a 0e c0 1a  and  %i3, %i2, %o5
a00e0644:  c2 02 c0 0a  ld  [ %o3 + %o2 ], %g1
a00e0648:  b6 28 40 1a  andn  %g1, %i2, %i3
a00e064c:  9a 16 c0 0d  or  %i3, %o5, %o5
a00e0650:  b6 10 00 08  mov  %o0, %i3
a00e0654:  80 a4 60 fe  cmp  %l1, 0xfe
a00e0658:  02 80 00 31  be  0xa00e071c
a00e065c:  90 10 00 12  mov  %l2, %o0
a00e0660:  b4 0b 20 ff  and  %o4, 0xff, %i2
a00e0664:  80 a6 80 10  cmp  %i2, %l0
a00e0668:  02 80 00 04  be  0xa00e0678
a00e066c:  01 00 00 00  nop
a00e0670:  e0 22 e3 f8  st  %l0, [ %o3 + 0x3f8 ]
a00e0674:  e0 2a 40 18  stb  %l0, [ %o1 + %i0 ]
a00e0678:  da 22 c0 0a  st  %o5, [ %o3 + %o2 ]
a00e067c:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00e0680:  d2 02 e1 50  ld  [ %o3 + 0x150 ], %o1	! 0xa802b550
a00e0684:  80 a2 60 00  cmp  %o1, 0
a00e0688:  22 80 00 18  be,a   0xa00e06e8
a00e068c:  d0 27 bf f0  st  %o0, [ %fp + -16 ]
a00e0690:  92 15 61 10  or  %l5, 0x110, %o1
a00e0694:  15 33 c0 8a  sethi  %hi(0xcf022800), %o2
a00e0698:  11 33 c0 8b  sethi  %hi(0xcf022c00), %o0
a00e069c:  2b 33 c0 8c  sethi  %hi(0xcf023000), %l5
a00e06a0:  9e 04 c0 14  add  %l3, %l4, %o7
a00e06a4:  d4 27 bf e8  st  %o2, [ %fp + -24 ]
a00e06a8:  d0 27 bf ec  st  %o0, [ %fp + -20 ]
a00e06ac:  ea 27 bf f0  st  %l5, [ %fp + -16 ]
a00e06b0:  d8 0a 40 18  ldub  [ %o1 + %i0 ], %o4
a00e06b4:  80 a3 00 10  cmp  %o4, %l0
a00e06b8:  83 2c 60 02  sll  %l1, 2, %g1
a00e06bc:  02 80 00 04  be  0xa00e06cc
a00e06c0:  da 03 ff f0  ld  [ %o7 + -16 ], %o5
a00e06c4:  e0 23 63 f8  st  %l0, [ %o5 + 0x3f8 ]
a00e06c8:  e0 2a 40 18  stb  %l0, [ %o1 + %i0 ]
a00e06cc:  21 00 06 65  sethi  %hi(0x199400), %l0
a00e06d0:  d6 03 40 01  ld  [ %o5 + %g1 ], %o3
a00e06d4:  90 14 20 98  or  %l0, 0x98, %o0
a00e06d8:  92 10 00 18  mov  %i0, %o1
a00e06dc:  7f ff fa a5  call  0xa00df170
a00e06e0:  94 10 00 19  mov  %i1, %o2
a00e06e4:  30 80 00 15  b,a   0xa00e0738
a00e06e8:  de 27 bf ec  st  %o7, [ %fp + -20 ]
a00e06ec:  10 80 00 13  b  0xa00e0738
a00e06f0:  f6 27 bf e8  st  %i3, [ %fp + -24 ]
a00e06f4:  7f ff fc 46  call  0xa00df80c
a00e06f8:  2b 2a 00 97  sethi  %hi(0xa8025c00), %l5
a00e06fc:  40 00 01 37  call  0xa00e0bd8
a00e0700:  01 00 00 00  nop
a00e0704:  11 00 06 65  sethi  %hi(0x199400), %o0
a00e0708:  92 10 00 18  mov  %i0, %o1
a00e070c:  7f ff fa 99  call  0xa00df170
a00e0710:  90 12 20 c0  or  %o0, 0xc0, %o0
a00e0714:  10 bf ff b9  b  0xa00e05f8
a00e0718:  92 15 61 10  or  %l5, 0x110, %o1
a00e071c:  a4 0b 20 ff  and  %o4, 0xff, %l2
a00e0720:  80 a4 80 0d  cmp  %l2, %o5
a00e0724:  22 bf ff d7  be,a   0xa00e0680
a00e0728:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00e072c:  da 22 e3 f8  st  %o5, [ %o3 + 0x3f8 ]	! 0xa802b7f8
a00e0730:  10 bf ff d3  b  0xa00e067c
a00e0734:  da 2a 40 18  stb  %o5, [ %o1 + %i0 ]
a00e0738:  81 c7 e0 08  ret
a00e073c:  81 e8 00 00  restore
