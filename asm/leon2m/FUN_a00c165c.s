# leon2m FUN_a00c165c 0xa00c165c-0xa00c16b0 (84 bytes)
a00c165c:  9d e3 bf 98  save  %sp, -104, %sp
a00c1660:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c1664:  7f ff e5 f5  call  0xa00bae38
a00c1668:  90 10 00 18  mov  %i0, %o0
a00c166c:  82 0a 20 ff  and  %o0, 0xff, %g1
a00c1670:  80 a0 60 0b  cmp  %g1, 0xb
a00c1674:  18 80 00 0d  bgu  0xa00c16a8
a00c1678:  82 10 20 ff  mov  0xff, %g1
a00c167c:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00c1680:  7f ff dc 93  call  0xa00b88cc
a00c1684:  d0 2a 60 1c  stb  %o0, [ %o1 + 0x1c ]	! 0xa802d41c
a00c1688:  7f ff e4 f9  call  0xa00baa6c
a00c168c:  90 10 00 18  mov  %i0, %o0
a00c1690:  7f ff e4 b0  call  0xa00ba950
a00c1694:  90 10 00 18  mov  %i0, %o0
a00c1698:  90 10 00 18  mov  %i0, %o0
a00c169c:  7f ff e5 39  call  0xa00bab80
a00c16a0:  92 10 20 06  mov  6, %o1
a00c16a4:  82 10 20 00  clr  %g1
a00c16a8:  81 c7 e0 08  ret
a00c16ac:  91 e8 00 01  restore  %g0, %g1, %o0
