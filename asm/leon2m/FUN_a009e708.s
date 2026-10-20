# leon2m FUN_a009e708 0xa009e708-0xa009e780 (120 bytes)
a009e708:  9d e3 bf 98  save  %sp, -104, %sp
a009e70c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009e710:  b4 14 22 90  or  %l0, 0x290, %i2	! 0xa802d290
a009e714:  40 00 2b 2a  call  0xa00a93bc
a009e718:  d0 0e a1 e1  ldub  [ %i2 + 0x1e1 ], %o0
a009e71c:  c2 0e a1 e1  ldub  [ %i2 + 0x1e1 ], %g1
a009e720:  80 a0 60 00  cmp  %g1, 0
a009e724:  02 80 00 14  be  0xa009e774
a009e728:  9a 00 7f ff  add  %g1, -1, %o5
a009e72c:  da 2e a1 e1  stb  %o5, [ %i2 + 0x1e1 ]
a009e730:  a0 14 22 90  or  %l0, 0x290, %l0
a009e734:  92 10 20 01  mov  1, %o1
a009e738:  40 00 2b c6  call  0xa00a9650
a009e73c:  d0 0c 21 e1  ldub  [ %l0 + 0x1e1 ], %o0
a009e740:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a009e744:  c2 0a 60 55  ldub  [ %o1 + 0x55 ], %g1	! 0xa8025c55
a009e748:  da 0c 21 e1  ldub  [ %l0 + 0x1e1 ], %o5
a009e74c:  b2 10 00 01  mov  %g1, %i1
a009e750:  b0 10 20 01  mov  1, %i0
a009e754:  80 a3 40 01  cmp  %o5, %g1
a009e758:  02 80 00 05  be  0xa009e76c
a009e75c:  b4 10 20 00  clr  %i2
a009e760:  b2 10 00 01  mov  %g1, %i1
a009e764:  b0 10 20 01  mov  1, %i0
a009e768:  b4 10 20 01  mov  1, %i2
a009e76c:  40 00 26 74  call  0xa00a813c
a009e770:  81 e8 00 00  restore
a009e774:  90 10 20 01  mov  1, %o0
a009e778:  10 bf ff ee  b  0xa009e730
a009e77c:  d0 2e a1 e1  stb  %o0, [ %i2 + 0x1e1 ]
