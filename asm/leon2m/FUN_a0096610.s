# leon2m FUN_a0096610 0xa0096610-0xa009665c (76 bytes)
a0096610:  9d e3 bf 98  save  %sp, -104, %sp
a0096614:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a0096618:  82 13 e2 90  or  %o7, 0x290, %g1	! 0xa802d290
a009661c:  d4 08 60 12  ldub  [ %g1 + 0x12 ], %o2
a0096620:  d2 08 60 13  ldub  [ %g1 + 0x13 ], %o1
a0096624:  d0 08 60 14  ldub  [ %g1 + 0x14 ], %o0
a0096628:  96 10 20 ca  mov  0xca, %o3
a009662c:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0096630:  98 10 20 03  mov  3, %o4
a0096634:  d0 28 60 8e  stb  %o0, [ %g1 + 0x8e ]
a0096638:  d6 23 63 ec  st  %o3, [ %o5 + 0x3ec ]
a009663c:  d8 28 60 11  stb  %o4, [ %g1 + 0x11 ]
a0096640:  d4 28 60 8c  stb  %o2, [ %g1 + 0x8c ]
a0096644:  40 00 83 8c  call  0xa00b7474
a0096648:  d2 28 60 8d  stb  %o1, [ %g1 + 0x8d ]
a009664c:  b0 10 20 00  clr  %i0
a0096650:  40 00 4c 00  call  0xa00a9650
a0096654:  93 e8 20 01  restore  %g0, 1, %o1
a0096658:  01 00 00 00  nop
