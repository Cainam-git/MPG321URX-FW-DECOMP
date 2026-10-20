# leon2s FUN_a00a146c 0xa00a146c-0xa00a14c4 (88 bytes)
a00a146c:  9d e3 bf 98  save  %sp, -104, %sp
a00a1470:  90 0e 20 ff  and  %i0, 0xff, %o0
a00a1474:  13 2a 01 f5  sethi  %hi(0xa807d400), %o1
a00a1478:  92 12 63 e0  or  %o1, 0x3e0, %o1	! 0xa807d7e0
a00a147c:  98 5a 21 90  smul  %o0, 0x190, %o4
a00a1480:  82 03 00 09  add  %o4, %o1, %g1
a00a1484:  9a 10 20 01  mov  1, %o5
a00a1488:  d6 08 60 e8  ldub  [ %g1 + 0xe8 ], %o3
a00a148c:  92 02 60 bc  add  %o1, 0xbc, %o1
a00a1490:  b0 10 00 08  mov  %o0, %i0
a00a1494:  b2 10 20 12  mov  0x12, %i1
a00a1498:  b4 10 20 00  clr  %i2
a00a149c:  da 28 60 e7  stb  %o5, [ %g1 + 0xe7 ]
a00a14a0:  80 a2 e0 00  cmp  %o3, 0
a00a14a4:  92 03 00 09  add  %o4, %o1, %o1
a00a14a8:  12 80 00 04  bne  0xa00a14b8
a00a14ac:  da 28 60 e6  stb  %o5, [ %g1 + 0xe6 ]
a00a14b0:  7f ff f9 90  call  0xa009faf0
a00a14b4:  01 00 00 00  nop
a00a14b8:  7f ff fd b8  call  0xa00a0b98
a00a14bc:  81 e8 00 00  restore
a00a14c0:  01 00 00 00  nop
