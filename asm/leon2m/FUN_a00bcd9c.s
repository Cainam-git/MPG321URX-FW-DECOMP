# leon2m FUN_a00bcd9c 0xa00bcd9c-0xa00bcde4 (72 bytes)
a00bcd9c:  9d e3 bf 98  save  %sp, -104, %sp
a00bcda0:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00bcda4:  d0 0a a0 20  ldub  [ %o2 + 0x20 ], %o0	! 0xa802d420
a00bcda8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bcdac:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bcdb0:  98 02 20 30  add  %o0, 0x30, %o4
a00bcdb4:  82 10 20 30  mov  0x30, %g1
a00bcdb8:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bcdbc:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bcdc0:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bcdc4:  7f ff f7 9e  call  0xa00bac3c
a00bcdc8:  90 10 20 1e  mov  0x1e, %o0
a00bcdcc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bcdd0:  7f ff f6 e0  call  0xa00ba950
a00bcdd4:  90 10 00 18  mov  %i0, %o0
a00bcdd8:  7f ff f7 83  call  0xa00babe4
a00bcddc:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bcde0:  01 00 00 00  nop
