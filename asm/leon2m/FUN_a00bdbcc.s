# leon2m FUN_a00bdbcc 0xa00bdbcc-0xa00bdc14 (72 bytes)
a00bdbcc:  9d e3 bf 98  save  %sp, -104, %sp
a00bdbd0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bdbd4:  d0 0a a2 af  ldub  [ %o2 + 0x2af ], %o0	! 0xa802d2af
a00bdbd8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bdbdc:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bdbe0:  98 02 20 30  add  %o0, 0x30, %o4
a00bdbe4:  82 10 20 30  mov  0x30, %g1
a00bdbe8:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bdbec:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bdbf0:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bdbf4:  7f ff f4 12  call  0xa00bac3c
a00bdbf8:  90 10 20 33  mov  0x33, %o0
a00bdbfc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bdc00:  7f ff f3 54  call  0xa00ba950
a00bdc04:  90 10 00 18  mov  %i0, %o0
a00bdc08:  7f ff f3 f7  call  0xa00babe4
a00bdc0c:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bdc10:  01 00 00 00  nop
