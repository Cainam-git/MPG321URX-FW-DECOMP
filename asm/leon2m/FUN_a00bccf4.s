# leon2m FUN_a00bccf4 0xa00bccf4-0xa00bcd54 (96 bytes)
a00bccf4:  9d e3 bf 98  save  %sp, -104, %sp
a00bccf8:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00bccfc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bcd00:  f2 08 63 fd  ldub  [ %g1 + 0x3fd ], %i1
a00bcd04:  9a 12 a2 90  or  %o2, 0x290, %o5
a00bcd08:  9e 06 40 0d  add  %i1, %o5, %o7
a00bcd0c:  d0 0b e1 9b  ldub  [ %o7 + 0x19b ], %o0
a00bcd10:  d2 0b e1 97  ldub  [ %o7 + 0x197 ], %o1
a00bcd14:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bcd18:  9a 13 20 78  or  %o4, 0x78, %o5	! 0xa802d078
a00bcd1c:  96 02 20 30  add  %o0, 0x30, %o3
a00bcd20:  94 02 60 30  add  %o1, 0x30, %o2
a00bcd24:  82 10 20 30  mov  0x30, %g1
a00bcd28:  d6 2b 60 09  stb  %o3, [ %o5 + 9 ]
a00bcd2c:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bcd30:  d4 2b 60 08  stb  %o2, [ %o5 + 8 ]
a00bcd34:  7f ff f7 c2  call  0xa00bac3c
a00bcd38:  90 10 20 1c  mov  0x1c, %o0
a00bcd3c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bcd40:  7f ff f7 04  call  0xa00ba950
a00bcd44:  90 10 00 18  mov  %i0, %o0
a00bcd48:  7f ff f7 a7  call  0xa00babe4
a00bcd4c:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bcd50:  01 00 00 00  nop
