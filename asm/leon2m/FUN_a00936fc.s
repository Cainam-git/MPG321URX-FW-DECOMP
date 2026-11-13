# leon2m FUN_a00936fc 0xa00936fc-0xa0093754 (88 bytes)
a00936fc:  9d e3 bf 98  save  %sp, -104, %sp
a0093700:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0093704:  d4 04 63 ec  ld  [ %l1 + 0x3ec ], %o2	! 0xa802afec
a0093708:  92 02 bf aa  add  %o2, -86, %o1
a009370c:  40 00 57 2c  call  0xa00a93bc
a0093710:  90 0a 60 ff  and  %o1, 0xff, %o0
a0093714:  40 00 7e 57  call  0xa00b3070
a0093718:  b2 10 20 01  mov  1, %i1
a009371c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0093720:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a0093724:  d8 0c 21 3f  ldub  [ %l0 + 0x13f ], %o4
a0093728:  82 03 20 e2  add  %o4, 0xe2, %g1
a009372c:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a0093730:  90 10 00 0c  mov  %o4, %o0
a0093734:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a0093738:  d8 2b 60 55  stb  %o4, [ %o5 + 0x55 ]
a009373c:  40 00 57 c5  call  0xa00a9650
a0093740:  92 10 20 00  clr  %o1
a0093744:  f0 0c 21 3f  ldub  [ %l0 + 0x13f ], %i0
a0093748:  40 00 57 c2  call  0xa00a9650
a009374c:  81 e8 00 00  restore
a0093750:  01 00 00 00  nop
