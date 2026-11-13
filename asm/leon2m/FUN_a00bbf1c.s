# leon2m FUN_a00bbf1c 0xa00bbf1c-0xa00bc098 (380 bytes)
a00bbf1c:  9d e3 bf 98  save  %sp, -104, %sp
a00bbf20:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bbf24:  d4 0b 62 9a  ldub  [ %o5 + 0x29a ], %o2	! 0xa802d29a
a00bbf28:  11 14 7a e1  sethi  %hi(0x51eb8400), %o0
a00bbf2c:  b2 0a a0 ff  and  %o2, 0xff, %i1
a00bbf30:  82 12 21 1f  or  %o0, 0x11f, %g1
a00bbf34:  80 56 40 01  umul  %i1, %g1, %g0
a00bbf38:  97 40 00 00  rd  %y, %o3
a00bbf3c:  b3 32 e0 05  srl  %o3, 5, %i1
a00bbf40:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00bbf44:  a0 5e a0 64  smul  %i2, 0x64, %l0
a00bbf48:  b4 22 80 10  sub  %o2, %l0, %i2
a00bbf4c:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a00bbf50:  92 0e a0 ff  and  %i2, 0xff, %o1
a00bbf54:  9e 13 20 cd  or  %o4, 0xcd, %o7
a00bbf58:  80 52 40 0f  umul  %o1, %o7, %g0
a00bbf5c:  9b 40 00 00  rd  %y, %o5
a00bbf60:  9f 33 60 03  srl  %o5, 3, %o7
a00bbf64:  90 0b e0 ff  and  %o7, 0xff, %o0
a00bbf68:  83 2a 20 02  sll  %o0, 2, %g1
a00bbf6c:  a0 00 40 08  add  %g1, %o0, %l0
a00bbf70:  98 04 00 10  add  %l0, %l0, %o4
a00bbf74:  92 26 80 0c  sub  %i2, %o4, %o1
a00bbf78:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bbf7c:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00bbf80:  9a 03 e0 30  add  %o7, 0x30, %o5
a00bbf84:  94 02 60 30  add  %o1, 0x30, %o2
a00bbf88:  96 06 60 30  add  %i1, 0x30, %o3
a00bbf8c:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a00bbf90:  d6 2c 20 07  stb  %o3, [ %l0 + 7 ]
a00bbf94:  d4 2c 20 09  stb  %o2, [ %l0 + 9 ]
a00bbf98:  92 10 20 00  clr  %o1
a00bbf9c:  40 02 61 a8  call  0xa015463c
a00bbfa0:  90 10 20 04  mov  4, %o0
a00bbfa4:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bbfa8:  90 10 20 62  mov  0x62, %o0
a00bbfac:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bbfb0:  92 10 20 02  mov  2, %o1
a00bbfb4:  40 02 61 a2  call  0xa015463c
a00bbfb8:  90 10 20 04  mov  4, %o0
a00bbfbc:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bbfc0:  92 10 20 03  mov  3, %o1
a00bbfc4:  40 02 61 9e  call  0xa015463c
a00bbfc8:  90 10 20 04  mov  4, %o0
a00bbfcc:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bbfd0:  92 10 20 04  mov  4, %o1
a00bbfd4:  40 02 61 9a  call  0xa015463c
a00bbfd8:  90 10 20 04  mov  4, %o0
a00bbfdc:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bbfe0:  92 10 20 05  mov  5, %o1
a00bbfe4:  40 02 61 96  call  0xa015463c
a00bbfe8:  90 10 20 04  mov  4, %o0
a00bbfec:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bbff0:  92 10 20 06  mov  6, %o1
a00bbff4:  40 02 61 92  call  0xa015463c
a00bbff8:  90 10 20 04  mov  4, %o0
a00bbffc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bc000:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bc004:  82 10 20 0d  mov  0xd, %g1
a00bc008:  9a 13 20 40  or  %o4, 0x40, %o5
a00bc00c:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00bc010:  80 a6 20 02  cmp  %i0, 2
a00bc014:  02 80 00 12  be  0xa00bc05c
a00bc018:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bc01c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bc020:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bc024:  96 12 a0 98  or  %o2, 0x98, %o3
a00bc028:  80 a6 20 03  cmp  %i0, 3
a00bc02c:  02 80 00 10  be  0xa00bc06c
a00bc030:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bc034:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00bc038:  c0 2a a0 9c  clrb  [ %o2 + 0x9c ]	! 0xa802b09c
a00bc03c:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bc040:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bc044:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bc048:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bc04c:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bc050:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bc054:  40 02 31 e5  call  0xa01487e8
a00bc058:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bc05c:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00bc060:  c0 2a 60 9a  clrb  [ %o1 + 0x9a ]	! 0xa802b09a
a00bc064:  10 bf ff f7  b  0xa00bc040
a00bc068:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bc06c:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bc070:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]	! 0xa802b098
a00bc074:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bc078:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bc07c:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bc080:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bc084:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bc088:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bc08c:  40 02 31 d7  call  0xa01487e8
a00bc090:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bc094:  01 00 00 00  nop
