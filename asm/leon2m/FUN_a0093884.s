# leon2m FUN_a0093884 0xa0093884-0xa0093910 (140 bytes)
a0093884:  9d e3 bf 98  save  %sp, -104, %sp
a0093888:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a009388c:  de 02 a3 ec  ld  [ %o2 + 0x3ec ], %o7	! 0xa802afec
a0093890:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a0093894:  92 03 ff a8  add  %o7, -88, %o1
a0093898:  96 10 20 c5  mov  0xc5, %o3
a009389c:  a0 16 22 90  or  %i0, 0x290, %l0
a00938a0:  d6 22 a3 ec  st  %o3, [ %o2 + 0x3ec ]
a00938a4:  d2 2c 21 a3  stb  %o1, [ %l0 + 0x1a3 ]
a00938a8:  40 00 8a 7a  call  0xa00b6290
a00938ac:  90 10 20 01  mov  1, %o0
a00938b0:  90 10 20 00  clr  %o0
a00938b4:  40 00 8b 18  call  0xa00b6514
a00938b8:  92 10 20 01  mov  1, %o1
a00938bc:  d0 0c 21 a3  ldub  [ %l0 + 0x1a3 ], %o0
a00938c0:  82 02 00 10  add  %o0, %l0, %g1
a00938c4:  da 08 61 9c  ldub  [ %g1 + 0x19c ], %o5
a00938c8:  d8 08 61 98  ldub  [ %g1 + 0x198 ], %o4
a00938cc:  da 2c 20 8d  stb  %o5, [ %l0 + 0x8d ]
a00938d0:  d8 2c 20 8c  stb  %o4, [ %l0 + 0x8c ]
a00938d4:  90 10 20 02  mov  2, %o0
a00938d8:  40 00 56 e4  call  0xa00a9468
a00938dc:  92 10 20 01  mov  1, %o1
a00938e0:  90 10 20 00  clr  %o0
a00938e4:  40 00 56 e1  call  0xa00a9468
a00938e8:  92 10 20 00  clr  %o1
a00938ec:  90 10 20 01  mov  1, %o0
a00938f0:  40 00 56 de  call  0xa00a9468
a00938f4:  92 10 20 03  mov  3, %o1
a00938f8:  40 00 7e d5  call  0xa00b344c
a00938fc:  90 10 20 00  clr  %o0
a0093900:  b0 10 20 03  mov  3, %i0
a0093904:  40 00 7e f4  call  0xa00b34d4
a0093908:  93 e8 20 05  restore  %g0, 5, %o1
a009390c:  01 00 00 00  nop
