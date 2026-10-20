# leon2m FUN_a0098794 0xa0098794-0xa0098850 (188 bytes)
a0098794:  9d e3 bf 98  save  %sp, -104, %sp
a0098798:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a009879c:  a2 14 62 90  or  %l1, 0x290, %l1	! 0xa802d290
a00987a0:  d4 0c 61 a3  ldub  [ %l1 + 0x1a3 ], %o2
a00987a4:  b2 02 80 11  add  %o2, %l1, %i1
a00987a8:  d6 0e 61 8a  ldub  [ %i1 + 0x18a ], %o3
a00987ac:  21 09 24 92  sethi  %hi(0x24924800), %l0
a00987b0:  b2 14 21 25  or  %l0, 0x125, %i1	! 0x24924925
a00987b4:  80 52 c0 19  umul  %o3, %i1, %g0
a00987b8:  83 40 00 00  rd  %y, %g1
a00987bc:  a4 22 c0 01  sub  %o3, %g1, %l2
a00987c0:  9b 34 a0 01  srl  %l2, 1, %o5
a00987c4:  90 00 40 0d  add  %g1, %o5, %o0
a00987c8:  b1 32 20 02  srl  %o0, 2, %i0
a00987cc:  9f 2e 20 03  sll  %i0, 3, %o7
a00987d0:  98 23 c0 18  sub  %o7, %i0, %o4
a00987d4:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a00987d8:  a4 22 c0 0c  sub  %o3, %o4, %l2
a00987dc:  d6 2a a0 56  stb  %o3, [ %o2 + 0x56 ]
a00987e0:  92 0c a0 ff  and  %l2, 0xff, %o1
a00987e4:  94 10 20 00  clr  %o2
a00987e8:  40 00 3e 55  call  0xa00a813c
a00987ec:  90 10 20 01  mov  1, %o0
a00987f0:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a00987f4:  c2 04 a3 ec  ld  [ %l2 + 0x3ec ], %g1	! 0xa802afec
a00987f8:  90 00 7f da  add  %g1, -38, %o0
a00987fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0098800:  40 00 42 03  call  0xa00a900c
a0098804:  92 10 20 02  mov  2, %o1
a0098808:  da 0c 61 a3  ldub  [ %l1 + 0x1a3 ], %o5
a009880c:  b0 03 40 11  add  %o5, %l1, %i0
a0098810:  d0 0e 21 8a  ldub  [ %i0 + 0x18a ], %o0
a0098814:  80 52 00 19  umul  %o0, %i1, %g0
a0098818:  97 40 00 00  rd  %y, %o3
a009881c:  9e 22 00 0b  sub  %o0, %o3, %o7
a0098820:  99 33 e0 01  srl  %o7, 1, %o4
a0098824:  94 02 c0 0c  add  %o3, %o4, %o2
a0098828:  a1 32 a0 02  srl  %o2, 2, %l0
a009882c:  93 2c 20 03  sll  %l0, 3, %o1
a0098830:  82 22 40 10  sub  %o1, %l0, %g1
a0098834:  b0 22 00 01  sub  %o0, %g1, %i0
a0098838:  9a 02 20 86  add  %o0, 0x86, %o5
a009883c:  da 24 a3 ec  st  %o5, [ %l2 + 0x3ec ]
a0098840:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0098844:  40 00 43 83  call  0xa00a9650
a0098848:  93 e8 20 01  restore  %g0, 1, %o1
a009884c:  01 00 00 00  nop
