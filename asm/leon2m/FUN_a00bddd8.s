# leon2m FUN_a00bddd8 0xa00bddd8-0xa00bde20 (72 bytes)
a00bddd8:  9d e3 bf 98  save  %sp, -104, %sp
a00bdddc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bdde0:  d0 0a a2 db  ldub  [ %o2 + 0x2db ], %o0	! 0xa802d2db
a00bdde4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bdde8:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bddec:  98 02 20 30  add  %o0, 0x30, %o4
a00bddf0:  82 10 20 30  mov  0x30, %g1
a00bddf4:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bddf8:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bddfc:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bde00:  7f ff f3 8f  call  0xa00bac3c
a00bde04:  90 10 20 3d  mov  0x3d, %o0
a00bde08:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bde0c:  7f ff f2 d1  call  0xa00ba950
a00bde10:  90 10 00 18  mov  %i0, %o0
a00bde14:  7f ff f3 74  call  0xa00babe4
a00bde18:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bde1c:  01 00 00 00  nop
