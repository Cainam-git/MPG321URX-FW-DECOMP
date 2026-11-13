# leon2m FUN_a00935e8 0xa00935e8-0xa0093694 (172 bytes)
a00935e8:  9d e3 bf 98  save  %sp, -104, %sp
a00935ec:  31 2a 00 97  sethi  %hi(0xa8025c00), %i0
a00935f0:  e2 0e 20 56  ldub  [ %i0 + 0x56 ], %l1	! 0xa8025c56
a00935f4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00935f8:  a0 14 22 90  or  %l0, 0x290, %l0	! 0xa802d290
a00935fc:  9a 0c 60 01  and  %l1, 1, %o5
a0093600:  d8 04 20 a8  ld  [ %l0 + 0xa8 ], %o4
a0093604:  1f 00 00 04  sethi  %hi(0x1000), %o7
a0093608:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009360c:  94 2b 00 0f  andn  %o4, %o7, %o2
a0093610:  97 2b 60 0c  sll  %o5, 0xc, %o3
a0093614:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a0093618:  82 12 80 0b  or  %o2, %o3, %g1
a009361c:  92 02 3f ad  add  %o0, -83, %o1
a0093620:  c2 24 20 a8  st  %g1, [ %l0 + 0xa8 ]
a0093624:  40 00 57 66  call  0xa00a93bc
a0093628:  90 0a 60 ff  and  %o1, 0xff, %o0
a009362c:  f2 04 20 a8  ld  [ %l0 + 0xa8 ], %i1
a0093630:  b1 36 60 0c  srl  %i1, 0xc, %i0
a0093634:  9e 0e 20 01  and  %i0, 1, %o7
a0093638:  90 03 e0 01  add  %o7, 1, %o0
a009363c:  40 00 58 05  call  0xa00a9650
a0093640:  92 10 20 00  clr  %o1
a0093644:  da 04 20 a8  ld  [ %l0 + 0xa8 ], %o5
a0093648:  99 33 60 0c  srl  %o5, 0xc, %o4
a009364c:  96 0b 20 01  and  %o4, 1, %o3
a0093650:  92 02 e0 01  add  %o3, 1, %o1
a0093654:  90 10 20 01  mov  1, %o0
a0093658:  40 00 52 b9  call  0xa00a813c
a009365c:  94 10 20 00  clr  %o2
a0093660:  d4 04 20 a8  ld  [ %l0 + 0xa8 ], %o2
a0093664:  91 32 a0 0c  srl  %o2, 0xc, %o0
a0093668:  92 0a 20 01  and  %o0, 1, %o1
a009366c:  92 02 60 01  inc  %o1
a0093670:  90 10 20 01  mov  1, %o0
a0093674:  40 00 52 b2  call  0xa00a813c
a0093678:  94 10 20 01  mov  1, %o2
a009367c:  82 10 20 11  mov  0x11, %g1
a0093680:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a0093684:  b0 10 20 03  mov  3, %i0
a0093688:  40 00 56 61  call  0xa00a900c
a009368c:  93 e8 20 01  restore  %g0, 1, %o1
a0093690:  01 00 00 00  nop
