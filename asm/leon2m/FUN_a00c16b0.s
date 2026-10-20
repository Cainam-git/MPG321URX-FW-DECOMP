# leon2m FUN_a00c16b0 0xa00c16b0-0xa00c1704 (84 bytes)
a00c16b0:  9d e3 bf 98  save  %sp, -104, %sp
a00c16b4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c16b8:  7f ff e5 e0  call  0xa00bae38
a00c16bc:  90 10 00 18  mov  %i0, %o0
a00c16c0:  82 0a 20 ff  and  %o0, 0xff, %g1
a00c16c4:  80 a0 60 0b  cmp  %g1, 0xb
a00c16c8:  18 80 00 0d  bgu  0xa00c16fc
a00c16cc:  82 10 20 ff  mov  0xff, %g1
a00c16d0:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00c16d4:  7f ff dc 7e  call  0xa00b88cc
a00c16d8:  d0 2a 60 1b  stb  %o0, [ %o1 + 0x1b ]	! 0xa802d41b
a00c16dc:  7f ff e4 e4  call  0xa00baa6c
a00c16e0:  90 10 00 18  mov  %i0, %o0
a00c16e4:  7f ff e4 9b  call  0xa00ba950
a00c16e8:  90 10 00 18  mov  %i0, %o0
a00c16ec:  90 10 00 18  mov  %i0, %o0
a00c16f0:  7f ff e5 24  call  0xa00bab80
a00c16f4:  92 10 20 06  mov  6, %o1
a00c16f8:  82 10 20 00  clr  %g1
a00c16fc:  81 c7 e0 08  ret
a00c1700:  91 e8 00 01  restore  %g0, %g1, %o0
