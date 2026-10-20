# leon2m FUN_a009e5ac 0xa009e5ac-0xa009e624 (120 bytes)
a009e5ac:  9d e3 bf 98  save  %sp, -104, %sp
a009e5b0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009e5b4:  b4 14 22 90  or  %l0, 0x290, %i2	! 0xa802d290
a009e5b8:  40 00 2b 81  call  0xa00a93bc
a009e5bc:  d0 0e a1 e0  ldub  [ %i2 + 0x1e0 ], %o0
a009e5c0:  c2 0e a1 e0  ldub  [ %i2 + 0x1e0 ], %g1
a009e5c4:  80 a0 60 00  cmp  %g1, 0
a009e5c8:  02 80 00 14  be  0xa009e618
a009e5cc:  9a 00 7f ff  add  %g1, -1, %o5
a009e5d0:  da 2e a1 e0  stb  %o5, [ %i2 + 0x1e0 ]
a009e5d4:  a0 14 22 90  or  %l0, 0x290, %l0
a009e5d8:  92 10 20 01  mov  1, %o1
a009e5dc:  40 00 2c 1d  call  0xa00a9650
a009e5e0:  d0 0c 21 e0  ldub  [ %l0 + 0x1e0 ], %o0
a009e5e4:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a009e5e8:  c2 0a 60 55  ldub  [ %o1 + 0x55 ], %g1	! 0xa8025c55
a009e5ec:  da 0c 21 e0  ldub  [ %l0 + 0x1e0 ], %o5
a009e5f0:  b2 10 00 01  mov  %g1, %i1
a009e5f4:  b0 10 20 01  mov  1, %i0
a009e5f8:  80 a3 40 01  cmp  %o5, %g1
a009e5fc:  02 80 00 05  be  0xa009e610
a009e600:  b4 10 20 00  clr  %i2
a009e604:  b2 10 00 01  mov  %g1, %i1
a009e608:  b0 10 20 01  mov  1, %i0
a009e60c:  b4 10 20 01  mov  1, %i2
a009e610:  40 00 26 cb  call  0xa00a813c
a009e614:  81 e8 00 00  restore
a009e618:  90 10 20 01  mov  1, %o0
a009e61c:  10 bf ff ee  b  0xa009e5d4
a009e620:  d0 2e a1 e0  stb  %o0, [ %i2 + 0x1e0 ]
