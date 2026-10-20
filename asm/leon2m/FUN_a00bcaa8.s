# leon2m FUN_a00bcaa8 0xa00bcaa8-0xa00bcaf0 (72 bytes)
a00bcaa8:  9d e3 bf 98  save  %sp, -104, %sp
a00bcaac:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bcab0:  d0 0a a3 d0  ldub  [ %o2 + 0x3d0 ], %o0	! 0xa802d3d0
a00bcab4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bcab8:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bcabc:  98 02 20 30  add  %o0, 0x30, %o4
a00bcac0:  82 10 20 30  mov  0x30, %g1
a00bcac4:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bcac8:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bcacc:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bcad0:  7f ff f8 5b  call  0xa00bac3c
a00bcad4:  90 10 20 14  mov  0x14, %o0
a00bcad8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bcadc:  7f ff f7 9d  call  0xa00ba950
a00bcae0:  90 10 00 18  mov  %i0, %o0
a00bcae4:  7f ff f8 40  call  0xa00babe4
a00bcae8:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bcaec:  01 00 00 00  nop
