# leon2s FUN_a00a0478 0xa00a0478-0xa00a0514 (156 bytes)
a00a0478:  9d e3 bf 98  save  %sp, -104, %sp
a00a047c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a0480:  7f ff ff d2  call  0xa00a03c8
a00a0484:  90 10 00 18  mov  %i0, %o0
a00a0488:  17 2a 01 f6  sethi  %hi(0xa807d800), %o3
a00a048c:  9a 12 e3 00  or  %o3, 0x300, %o5	! 0xa807db00
a00a0490:  82 5e 20 34  smul  %i0, 0x34, %g1
a00a0494:  80 8a 20 ff  btst  0xff, %o0
a00a0498:  82 00 40 0d  add  %g1, %o5, %g1
a00a049c:  92 10 20 00  clr  %o1
a00a04a0:  94 10 20 05  mov  5, %o2
a00a04a4:  90 10 00 19  mov  %i1, %o0
a00a04a8:  02 80 00 0c  be  0xa00a04d8
a00a04ac:  98 10 20 10  mov  0x10, %o4
a00a04b0:  da 00 60 2c  ld  [ %g1 + 0x2c ], %o5
a00a04b4:  c2 03 60 08  ld  [ %o5 + 8 ], %g1
a00a04b8:  83 30 60 10  srl  %g1, 0x10, %g1
a00a04bc:  80 88 60 f0  btst  0xf0, %g1
a00a04c0:  02 80 00 0a  be  0xa00a04e8
a00a04c4:  82 5e 20 34  smul  %i0, 0x34, %g1
a00a04c8:  c2 03 60 08  ld  [ %o5 + 8 ], %g1
a00a04cc:  83 30 60 14  srl  %g1, 0x14, %g1
a00a04d0:  10 80 00 05  b  0xa00a04e4
a00a04d4:  98 08 60 0f  and  %g1, 0xf, %o4
a00a04d8:  40 00 44 35  call  0xa00b15ac
a00a04dc:  b0 10 20 01  mov  1, %i0
a00a04e0:  30 80 00 0b  b,a   0xa00a050c
a00a04e4:  82 5e 20 34  smul  %i0, 0x34, %g1
a00a04e8:  9a 12 e3 00  or  %o3, 0x300, %o5
a00a04ec:  d8 2e 40 00  stb  %o4, [ %i1 ]
a00a04f0:  82 00 40 0d  add  %g1, %o5, %g1
a00a04f4:  c2 00 60 2c  ld  [ %g1 + 0x2c ], %g1
a00a04f8:  c2 00 60 08  ld  [ %g1 + 8 ], %g1
a00a04fc:  83 30 60 1b  srl  %g1, 0x1b, %g1
a00a0500:  82 08 60 01  and  %g1, 1, %g1
a00a0504:  c2 2e 60 01  stb  %g1, [ %i1 + 1 ]
a00a0508:  b0 10 20 00  clr  %i0
a00a050c:  81 c7 e0 08  ret
a00a0510:  81 e8 00 00  restore
