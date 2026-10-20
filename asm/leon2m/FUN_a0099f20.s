# leon2m FUN_a0099f20 0xa0099f20-0xa009a018 (248 bytes)
a0099f20:  9d e3 bf 98  save  %sp, -104, %sp
a0099f24:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0099f28:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a0099f2c:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1
a0099f30:  80 a0 60 bb  cmp  %g1, 0xbb
a0099f34:  02 80 00 07  be  0xa0099f50
a0099f38:  98 14 a2 90  or  %l2, 0x290, %o4
a0099f3c:  80 a0 60 bc  cmp  %g1, 0xbc
a0099f40:  12 80 00 0d  bne  0xa0099f74
a0099f44:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0099f48:  10 80 00 07  b  0xa0099f64
a0099f4c:  d4 03 21 dc  ld  [ %o4 + 0x1dc ], %o2
a0099f50:  da 03 21 dc  ld  [ %o4 + 0x1dc ], %o5
a0099f54:  11 00 00 20  sethi  %hi(0x8000), %o0
a0099f58:  82 2b 40 08  andn  %o5, %o0, %g1
a0099f5c:  10 80 00 05  b  0xa0099f70
a0099f60:  c2 23 21 dc  st  %g1, [ %o4 + 0x1dc ]
a0099f64:  17 00 00 20  sethi  %hi(0x8000), %o3
a0099f68:  92 12 80 0b  or  %o2, %o3, %o1
a0099f6c:  d2 23 21 dc  st  %o1, [ %o4 + 0x1dc ]
a0099f70:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0099f74:  de 0c 20 56  ldub  [ %l0 + 0x56 ], %o7	! 0xa8025c56
a0099f78:  96 03 e0 45  add  %o7, 0x45, %o3
a0099f7c:  40 00 3d 10  call  0xa00a93bc
a0099f80:  90 0a e0 ff  and  %o3, 0xff, %o0
a0099f84:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a0099f88:  94 10 20 00  clr  %o2
a0099f8c:  40 00 38 6c  call  0xa00a813c
a0099f90:  90 10 20 01  mov  1, %o0
a0099f94:  a0 14 a2 90  or  %l2, 0x290, %l0
a0099f98:  d4 04 21 dc  ld  [ %l0 + 0x1dc ], %o2
a0099f9c:  92 10 20 37  mov  0x37, %o1
a0099fa0:  99 32 a0 0f  srl  %o2, 0xf, %o4
a0099fa4:  d2 24 63 ec  st  %o1, [ %l1 + 0x3ec ]
a0099fa8:  90 0b 20 01  and  %o4, 1, %o0
a0099fac:  40 00 3d a9  call  0xa00a9650
a0099fb0:  92 10 20 00  clr  %o1
a0099fb4:  da 04 21 dc  ld  [ %l0 + 0x1dc ], %o5
a0099fb8:  91 33 60 0f  srl  %o5, 0xf, %o0
a0099fbc:  92 0a 20 01  and  %o0, 1, %o1
a0099fc0:  94 10 20 01  mov  1, %o2
a0099fc4:  40 00 38 5e  call  0xa00a813c
a0099fc8:  90 10 20 01  mov  1, %o0
a0099fcc:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1
a0099fd0:  a4 00 7f cc  add  %g1, -52, %l2
a0099fd4:  90 0c a0 ff  and  %l2, 0xff, %o0
a0099fd8:  40 00 3c 0d  call  0xa00a900c
a0099fdc:  92 10 20 01  mov  1, %o1
a0099fe0:  90 10 20 01  mov  1, %o0
a0099fe4:  40 00 3d 21  call  0xa00a9468
a0099fe8:  92 10 20 02  mov  2, %o1
a0099fec:  90 10 20 00  clr  %o0
a0099ff0:  40 00 65 39  call  0xa00b34d4
a0099ff4:  92 10 20 01  mov  1, %o1
a0099ff8:  40 01 02 ca  call  0xa00dab20
a0099ffc:  01 00 00 00  nop
a009a000:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a009a004:  e2 0b e0 8e  ldub  [ %o7 + 0x8e ], %l1	! 0xa802b08e
a009a008:  a0 14 60 02  or  %l1, 2, %l0
a009a00c:  e0 2b e0 8e  stb  %l0, [ %o7 + 0x8e ]
a009a010:  81 c7 e0 08  ret
a009a014:  81 e8 00 00  restore
