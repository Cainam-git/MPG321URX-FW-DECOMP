# leon2m FUN_a00c1608 0xa00c1608-0xa00c165c (84 bytes)
a00c1608:  9d e3 bf 98  save  %sp, -104, %sp
a00c160c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c1610:  7f ff e6 0a  call  0xa00bae38
a00c1614:  90 10 00 18  mov  %i0, %o0
a00c1618:  82 0a 20 ff  and  %o0, 0xff, %g1
a00c161c:  80 a0 60 0b  cmp  %g1, 0xb
a00c1620:  18 80 00 0d  bgu  0xa00c1654
a00c1624:  82 10 20 ff  mov  0xff, %g1
a00c1628:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00c162c:  7f ff dc a8  call  0xa00b88cc
a00c1630:  d0 2a 60 1d  stb  %o0, [ %o1 + 0x1d ]	! 0xa802d41d
a00c1634:  7f ff e5 0e  call  0xa00baa6c
a00c1638:  90 10 00 18  mov  %i0, %o0
a00c163c:  7f ff e4 c5  call  0xa00ba950
a00c1640:  90 10 00 18  mov  %i0, %o0
a00c1644:  90 10 00 18  mov  %i0, %o0
a00c1648:  7f ff e5 4e  call  0xa00bab80
a00c164c:  92 10 20 06  mov  6, %o1
a00c1650:  82 10 20 00  clr  %g1
a00c1654:  81 c7 e0 08  ret
a00c1658:  91 e8 00 01  restore  %g0, %g1, %o0
