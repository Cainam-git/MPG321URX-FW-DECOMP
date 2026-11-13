# leon2s FUN_a00a4610 0xa00a4610-0xa00a4658 (72 bytes)
a00a4610:  17 2a 01 e4  sethi  %hi(0xa8079000), %o3
a00a4614:  98 12 e2 18  or  %o3, 0x218, %o4	! 0xa8079218
a00a4618:  80 a2 20 00  cmp  %o0, 0
a00a461c:  12 80 00 0c  bne  0xa00a464c
a00a4620:  90 10 00 0c  mov  %o4, %o0
a00a4624:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a4628:  da 00 62 14  ld  [ %g1 + 0x214 ], %o5	! 0xa8079214
a00a462c:  03 28 02 91  sethi  %hi(0xa00a4400), %g1
a00a4630:  82 10 62 58  or  %g1, 0x258, %g1	! 0xa00a4658
a00a4634:  c0 22 e2 18  clr  [ %o3 + 0x218 ]
a00a4638:  c2 23 20 08  st  %g1, [ %o4 + 8 ]
a00a463c:  da 23 20 04  st  %o5, [ %o4 + 4 ]
a00a4640:  82 13 c0 00  mov  %o7, %g1
a00a4644:  40 00 36 a6  call  0xa00b20dc
a00a4648:  9e 10 40 00  mov  %g1, %o7
a00a464c:  01 00 00 00  nop
a00a4650:  81 c3 e0 08  retl
a00a4654:  01 00 00 00  nop
