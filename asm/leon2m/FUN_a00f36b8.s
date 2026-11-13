# leon2m FUN_a00f36b8 0xa00f36b8-0xa00f37d0 (280 bytes)
a00f36b8:  9d e3 bf 98  save  %sp, -104, %sp
a00f36bc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f36c0:  92 10 20 12  mov  0x12, %o1
a00f36c4:  7f ff fa cb  call  0xa00f21f0
a00f36c8:  90 10 00 18  mov  %i0, %o0
a00f36cc:  15 3f ff f8  sethi  %hi(0xffffe000), %o2
a00f36d0:  92 2a 00 0a  andn  %o0, %o2, %o1
a00f36d4:  91 2a 60 10  sll  %o1, 0x10, %o0
a00f36d8:  a2 10 00 09  mov  %o1, %l1
a00f36dc:  40 01 89 59  call  0xa0155c40
a00f36e0:  91 32 20 10  srl  %o0, 0x10, %o0
a00f36e4:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f36e8:  a0 10 00 08  mov  %o0, %l0
a00f36ec:  40 01 89 23  call  0xa0155b78
a00f36f0:  d2 00 63 2c  ld  [ %g1 + 0x32c ], %o1
a00f36f4:  80 a2 20 00  cmp  %o0, 0
a00f36f8:  04 80 00 28  ble  0xa00f3798
a00f36fc:  9a 10 20 0a  mov  0xa, %o5
a00f3700:  19 33 c0 4a  sethi  %hi(0xcf012800), %o4
a00f3704:  94 13 20 44  or  %o4, 0x44, %o2	! 0xcf012844
a00f3708:  da 22 80 00  st  %o5, [ %o2 ]
a00f370c:  97 2c 60 10  sll  %l1, 0x10, %o3
a00f3710:  95 32 e0 10  srl  %o3, 0x10, %o2
a00f3714:  11 3f ff f8  sethi  %hi(0xffffe000), %o0
a00f3718:  92 3a 00 0a  xnor  %o0, %o2, %o1
a00f371c:  03 33 c0 4a  sethi  %hi(0xcf012800), %g1
a00f3720:  9a 10 60 04  or  %g1, 4, %o5	! 0xcf012804
a00f3724:  80 a0 00 09  cmp  %g0, %o1
a00f3728:  e2 03 40 00  ld  [ %o5 ], %l1
a00f372c:  9e 60 3f ff  subx  %g0, -1, %o7
a00f3730:  80 a0 00 0a  cmp  %g0, %o2
a00f3734:  a0 0c 7f df  and  %l1, -33, %l0
a00f3738:  98 60 3f ff  subx  %g0, -1, %o4
a00f373c:  e0 23 40 00  st  %l0, [ %o5 ]
a00f3740:  80 93 c0 0c  orcc  %o7, %o4, %g0
a00f3744:  12 80 00 03  bne  0xa00f3750
a00f3748:  9a 10 3f ff  mov  -1, %o5
a00f374c:  9b 2a a0 0d  sll  %o2, 0xd, %o5
a00f3750:  a3 2e 60 10  sll  %i1, 0x10, %l1
a00f3754:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f3758:  b3 34 60 10  srl  %l1, 0x10, %i1
a00f375c:  21 33 c0 4a  sethi  %hi(0xcf012800), %l0
a00f3760:  da 20 63 94  st  %o5, [ %g1 + 0x394 ]
a00f3764:  90 14 20 20  or  %l0, 0x20, %o0
a00f3768:  7f ff fe 49  call  0xa00f308c
a00f376c:  92 10 00 19  mov  %i1, %o1
a00f3770:  1f 2a 00 ad  sethi  %hi(0xa802b400), %o7
a00f3774:  da 0b e3 70  ldub  [ %o7 + 0x370 ], %o5	! 0xa802b770
a00f3778:  80 a3 60 00  cmp  %o5, 0
a00f377c:  02 80 00 12  be  0xa00f37c4
a00f3780:  9a 13 e3 70  or  %o7, 0x370, %o5
a00f3784:  da 03 60 04  ld  [ %o5 + 4 ], %o5
a00f3788:  80 a3 60 00  cmp  %o5, 0
a00f378c:  02 80 00 0e  be  0xa00f37c4
a00f3790:  90 10 00 18  mov  %i0, %o0
a00f3794:  30 80 00 0a  b,a   0xa00f37bc
a00f3798:  17 00 06 68  sethi  %hi(0x19a000), %o3
a00f379c:  90 10 00 10  mov  %l0, %o0
a00f37a0:  40 01 88 f6  call  0xa0155b78
a00f37a4:  d2 02 e3 30  ld  [ %o3 + 0x330 ], %o1
a00f37a8:  80 a2 20 00  cmp  %o0, 0
a00f37ac:  14 bf ff d5  bg  0xa00f3700
a00f37b0:  9a 10 20 0b  mov  0xb, %o5
a00f37b4:  10 bf ff d3  b  0xa00f3700
a00f37b8:  9a 10 20 0c  mov  0xc, %o5
a00f37bc:  9f c3 40 00  call  %o5
a00f37c0:  92 10 00 19  mov  %i1, %o1
a00f37c4:  01 00 00 00  nop
a00f37c8:  81 c7 e0 08  ret
a00f37cc:  81 e8 00 00  restore
