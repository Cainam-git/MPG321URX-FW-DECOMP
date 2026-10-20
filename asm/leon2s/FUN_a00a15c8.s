# leon2s FUN_a00a15c8 0xa00a15c8-0xa00a1638 (112 bytes)
a00a15c8:  9d e3 bf 98  save  %sp, -104, %sp
a00a15cc:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a15d0:  a4 10 63 00  or  %g1, 0x300, %l2	! 0xa807db00
a00a15d4:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a15d8:  c2 08 63 68  ldub  [ %g1 + 0x368 ], %g1	! 0xa807db68
a00a15dc:  a2 10 00 18  mov  %i0, %l1
a00a15e0:  a0 5e 20 34  smul  %i0, 0x34, %l0
a00a15e4:  90 10 20 08  mov  8, %o0
a00a15e8:  80 a0 60 00  cmp  %g1, 0
a00a15ec:  02 80 00 11  be  0xa00a1630
a00a15f0:  b0 10 20 01  mov  1, %i0
a00a15f4:  d2 04 80 10  ld  [ %l2 + %l0 ], %o1
a00a15f8:  40 00 17 6d  call  0xa00a73ac
a00a15fc:  92 02 60 04  add  %o1, 4, %o1
a00a1600:  40 00 40 03  call  0xa00b160c
a00a1604:  90 10 20 01  mov  1, %o0
a00a1608:  d2 04 80 10  ld  [ %l2 + %l0 ], %o1
a00a160c:  92 02 60 04  add  %o1, 4, %o1
a00a1610:  40 00 17 71  call  0xa00a73d4
a00a1614:  90 10 20 08  mov  8, %o0
a00a1618:  90 0c 60 ff  and  %l1, 0xff, %o0
a00a161c:  7f ff d3 34  call  0xa00962ec
a00a1620:  92 10 20 01  mov  1, %o1
a00a1624:  7f ff eb 3b  call  0xa009c310
a00a1628:  90 10 20 15  mov  0x15, %o0
a00a162c:  b0 10 20 00  clr  %i0
a00a1630:  81 c7 e0 08  ret
a00a1634:  81 e8 00 00  restore
