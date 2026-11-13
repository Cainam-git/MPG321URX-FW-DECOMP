# leon2m FUN_a00be624 0xa00be624-0xa00be66c (72 bytes)
a00be624:  9d e3 bf 98  save  %sp, -104, %sp
a00be628:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00be62c:  d0 0a a0 78  ldub  [ %o2 + 0x78 ], %o0	! 0xa802d478
a00be630:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be634:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be638:  98 02 20 30  add  %o0, 0x30, %o4
a00be63c:  82 10 20 30  mov  0x30, %g1
a00be640:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00be644:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00be648:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00be64c:  7f ff f1 7c  call  0xa00bac3c
a00be650:  90 10 20 7c  mov  0x7c, %o0
a00be654:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be658:  7f ff f0 be  call  0xa00ba950
a00be65c:  90 10 00 18  mov  %i0, %o0
a00be660:  7f ff f1 61  call  0xa00babe4
a00be664:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be668:  01 00 00 00  nop
