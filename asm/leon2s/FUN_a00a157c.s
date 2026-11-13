# leon2s FUN_a00a157c 0xa00a157c-0xa00a15c8 (76 bytes)
a00a157c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a1580:  82 10 63 e0  or  %g1, 0x3e0, %g1	! 0xa807d7e0
a00a1584:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a1588:  9a 00 61 14  add  %g1, 0x114, %o5
a00a158c:  92 5a 21 90  smul  %o0, 0x190, %o1
a00a1590:  82 02 40 01  add  %o1, %g1, %g1
a00a1594:  92 02 40 0d  add  %o1, %o5, %o1
a00a1598:  9a 10 20 01  mov  1, %o5
a00a159c:  d8 08 61 59  ldub  [ %g1 + 0x159 ], %o4
a00a15a0:  da 28 61 58  stb  %o5, [ %g1 + 0x158 ]
a00a15a4:  80 a3 20 00  cmp  %o4, 0
a00a15a8:  12 80 00 05  bne  0xa00a15bc
a00a15ac:  da 28 61 57  stb  %o5, [ %g1 + 0x157 ]
a00a15b0:  82 13 c0 00  mov  %o7, %g1
a00a15b4:  7f ff fa 47  call  0xa009fed0
a00a15b8:  9e 10 40 00  mov  %g1, %o7
a00a15bc:  01 00 00 00  nop
a00a15c0:  81 c3 e0 08  retl
a00a15c4:  01 00 00 00  nop
