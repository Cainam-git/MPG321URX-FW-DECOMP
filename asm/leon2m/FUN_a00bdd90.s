# leon2m FUN_a00bdd90 0xa00bdd90-0xa00bddd8 (72 bytes)
a00bdd90:  9d e3 bf 98  save  %sp, -104, %sp
a00bdd94:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bdd98:  d0 0a a2 da  ldub  [ %o2 + 0x2da ], %o0	! 0xa802d2da
a00bdd9c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bdda0:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bdda4:  98 02 20 30  add  %o0, 0x30, %o4
a00bdda8:  82 10 20 30  mov  0x30, %g1
a00bddac:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bddb0:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bddb4:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bddb8:  7f ff f3 a1  call  0xa00bac3c
a00bddbc:  90 10 20 3c  mov  0x3c, %o0
a00bddc0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bddc4:  7f ff f2 e3  call  0xa00ba950
a00bddc8:  90 10 00 18  mov  %i0, %o0
a00bddcc:  7f ff f3 86  call  0xa00babe4
a00bddd0:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bddd4:  01 00 00 00  nop
