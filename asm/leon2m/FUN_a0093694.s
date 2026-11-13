# leon2m FUN_a0093694 0xa0093694-0xa00936fc (104 bytes)
a0093694:  9d e3 bf 98  save  %sp, -104, %sp
a0093698:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a009369c:  a0 16 62 90  or  %i1, 0x290, %l0	! 0xa802d290
a00936a0:  de 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o7
a00936a4:  98 03 e0 01  add  %o7, 1, %o4
a00936a8:  92 0b 20 ff  and  %o4, 0xff, %o1
a00936ac:  90 10 20 01  mov  1, %o0
a00936b0:  40 00 52 a3  call  0xa00a813c
a00936b4:  94 10 20 00  clr  %o2
a00936b8:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00936bc:  d6 04 63 ec  ld  [ %l1 + 0x3ec ], %o3	! 0xa802afec
a00936c0:  92 02 ff f2  add  %o3, -14, %o1
a00936c4:  90 0a 60 ff  and  %o1, 0xff, %o0
a00936c8:  da 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o5
a00936cc:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a00936d0:  da 2a a0 56  stb  %o5, [ %o2 + 0x56 ]	! 0xa8025c56
a00936d4:  40 00 56 4e  call  0xa00a900c
a00936d8:  92 10 20 02  mov  2, %o1
a00936dc:  d0 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o0
a00936e0:  b0 02 20 01  add  %o0, 1, %i0
a00936e4:  82 02 20 57  add  %o0, 0x57, %g1
a00936e8:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a00936ec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00936f0:  40 00 57 d8  call  0xa00a9650
a00936f4:  93 e8 20 01  restore  %g0, 1, %o1
a00936f8:  01 00 00 00  nop
