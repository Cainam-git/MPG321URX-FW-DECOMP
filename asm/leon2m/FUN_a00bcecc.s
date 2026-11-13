# leon2m FUN_a00bcecc 0xa00bcecc-0xa00bd070 (420 bytes)
a00bcecc:  9d e3 bf 98  save  %sp, -104, %sp
a00bced0:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00bced4:  c2 08 60 34  ldub  [ %g1 + 0x34 ], %g1	! 0xa802d434
a00bced8:  80 a0 60 00  cmp  %g1, 0
a00bcedc:  02 80 00 0f  be  0xa00bcf18
a00bcee0:  9a 10 20 00  clr  %o5
a00bcee4:  80 a0 60 01  cmp  %g1, 1
a00bcee8:  02 80 00 58  be  0xa00bd048
a00bceec:  80 a0 60 02  cmp  %g1, 2
a00bcef0:  02 80 00 5a  be  0xa00bd058
a00bcef4:  80 a0 60 04  cmp  %g1, 4
a00bcef8:  02 80 00 56  be  0xa00bd050
a00bcefc:  80 a0 60 03  cmp  %g1, 3
a00bcf00:  02 80 00 58  be  0xa00bd060
a00bcf04:  80 a0 60 05  cmp  %g1, 5
a00bcf08:  02 80 00 58  be  0xa00bd068
a00bcf0c:  80 a0 60 06  cmp  %g1, 6
a00bcf10:  22 80 00 02  be,a   0xa00bcf18
a00bcf14:  9a 10 20 08  mov  8, %o5
a00bcf18:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bcf1c:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00bcf20:  94 10 20 30  mov  0x30, %o2
a00bcf24:  9a 03 60 30  add  %o5, 0x30, %o5
a00bcf28:  d4 2c 20 08  stb  %o2, [ %l0 + 8 ]
a00bcf2c:  da 2c 20 09  stb  %o5, [ %l0 + 9 ]
a00bcf30:  d4 2c 20 07  stb  %o2, [ %l0 + 7 ]
a00bcf34:  92 10 20 00  clr  %o1
a00bcf38:  40 02 5d c1  call  0xa015463c
a00bcf3c:  90 10 20 22  mov  0x22, %o0
a00bcf40:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bcf44:  90 10 20 62  mov  0x62, %o0
a00bcf48:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bcf4c:  92 10 20 02  mov  2, %o1
a00bcf50:  40 02 5d bb  call  0xa015463c
a00bcf54:  90 10 20 22  mov  0x22, %o0
a00bcf58:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bcf5c:  92 10 20 03  mov  3, %o1
a00bcf60:  40 02 5d b7  call  0xa015463c
a00bcf64:  90 10 20 22  mov  0x22, %o0
a00bcf68:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bcf6c:  92 10 20 04  mov  4, %o1
a00bcf70:  40 02 5d b3  call  0xa015463c
a00bcf74:  90 10 20 22  mov  0x22, %o0
a00bcf78:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bcf7c:  92 10 20 05  mov  5, %o1
a00bcf80:  40 02 5d af  call  0xa015463c
a00bcf84:  90 10 20 22  mov  0x22, %o0
a00bcf88:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bcf8c:  92 10 20 06  mov  6, %o1
a00bcf90:  40 02 5d ab  call  0xa015463c
a00bcf94:  90 10 20 22  mov  0x22, %o0
a00bcf98:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bcf9c:  92 10 20 0d  mov  0xd, %o1
a00bcfa0:  d2 2c 20 0a  stb  %o1, [ %l0 + 0xa ]
a00bcfa4:  80 a6 20 02  cmp  %i0, 2
a00bcfa8:  02 80 00 10  be  0xa00bcfe8
a00bcfac:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bcfb0:  80 a6 20 03  cmp  %i0, 3
a00bcfb4:  02 80 00 19  be  0xa00bd018
a00bcfb8:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00bcfbc:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00bcfc0:  9a 14 20 d0  or  %l0, 0xd0, %o5
a00bcfc4:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]
a00bcfc8:  c0 2c 20 d0  clrb  [ %l0 + 0xd0 ]
a00bcfcc:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bcfd0:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bcfd4:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bcfd8:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bcfdc:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bcfe0:  40 02 2e 02  call  0xa01487e8
a00bcfe4:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bcfe8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bcfec:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00bcff0:  9a 13 20 40  or  %o4, 0x40, %o5
a00bcff4:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]
a00bcff8:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bcffc:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bd000:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bd004:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bd008:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bd00c:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bd010:  40 02 2d f6  call  0xa01487e8
a00bd014:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd018:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00bd01c:  33 2a 00 ac  sethi  %hi(0xa802b000), %i1
a00bd020:  c0 2e 60 98  clrb  [ %i1 + 0x98 ]	! 0xa802b098
a00bd024:  9a 13 e0 98  or  %o7, 0x98, %o5
a00bd028:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]
a00bd02c:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bd030:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bd034:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bd038:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bd03c:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bd040:  40 02 2d ea  call  0xa01487e8
a00bd044:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd048:  10 bf ff b4  b  0xa00bcf18
a00bd04c:  9a 10 20 01  mov  1, %o5
a00bd050:  10 bf ff b2  b  0xa00bcf18
a00bd054:  9a 10 20 03  mov  3, %o5
a00bd058:  10 bf ff b0  b  0xa00bcf18
a00bd05c:  9a 10 20 02  mov  2, %o5
a00bd060:  10 bf ff ae  b  0xa00bcf18
a00bd064:  9a 10 20 05  mov  5, %o5
a00bd068:  10 bf ff ac  b  0xa00bcf18
a00bd06c:  9a 10 20 07  mov  7, %o5
