# leon2m FUN_a00bef90 0xa00bef90-0xa00bf110 (384 bytes)
a00bef90:  9d e3 bf 98  save  %sp, -104, %sp
a00bef94:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bef98:  40 02 15 99  call  0xa01445fc
a00bef9c:  d0 0b 62 ae  ldub  [ %o5 + 0x2ae ], %o0	! 0xa802d2ae
a00befa0:  13 14 7a e1  sethi  %hi(0x51eb8400), %o1
a00befa4:  b2 0a 20 ff  and  %o0, 0xff, %i1
a00befa8:  82 12 61 1f  or  %o1, 0x11f, %g1
a00befac:  80 56 40 01  umul  %i1, %g1, %g0
a00befb0:  97 40 00 00  rd  %y, %o3
a00befb4:  b3 32 e0 05  srl  %o3, 5, %i1
a00befb8:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00befbc:  a0 5e a0 64  smul  %i2, 0x64, %l0
a00befc0:  b4 22 00 10  sub  %o0, %l0, %i2
a00befc4:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a00befc8:  94 0e a0 ff  and  %i2, 0xff, %o2
a00befcc:  9e 13 20 cd  or  %o4, 0xcd, %o7
a00befd0:  80 52 80 0f  umul  %o2, %o7, %g0
a00befd4:  9b 40 00 00  rd  %y, %o5
a00befd8:  9f 33 60 03  srl  %o5, 3, %o7
a00befdc:  92 0b e0 ff  and  %o7, 0xff, %o1
a00befe0:  83 2a 60 02  sll  %o1, 2, %g1
a00befe4:  a0 00 40 09  add  %g1, %o1, %l0
a00befe8:  98 04 00 10  add  %l0, %l0, %o4
a00befec:  94 26 80 0c  sub  %i2, %o4, %o2
a00beff0:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00beff4:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00beff8:  92 02 a0 30  add  %o2, 0x30, %o1
a00beffc:  9a 03 e0 30  add  %o7, 0x30, %o5
a00bf000:  96 06 60 30  add  %i1, 0x30, %o3
a00bf004:  d2 2c 20 09  stb  %o1, [ %l0 + 9 ]
a00bf008:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a00bf00c:  d6 2c 20 07  stb  %o3, [ %l0 + 7 ]
a00bf010:  92 10 20 00  clr  %o1
a00bf014:  40 02 55 8a  call  0xa015463c
a00bf018:  90 10 20 12  mov  0x12, %o0
a00bf01c:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bf020:  90 10 20 62  mov  0x62, %o0
a00bf024:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bf028:  92 10 20 02  mov  2, %o1
a00bf02c:  40 02 55 84  call  0xa015463c
a00bf030:  90 10 20 12  mov  0x12, %o0
a00bf034:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bf038:  92 10 20 03  mov  3, %o1
a00bf03c:  40 02 55 80  call  0xa015463c
a00bf040:  90 10 20 12  mov  0x12, %o0
a00bf044:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bf048:  92 10 20 04  mov  4, %o1
a00bf04c:  40 02 55 7c  call  0xa015463c
a00bf050:  90 10 20 12  mov  0x12, %o0
a00bf054:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bf058:  92 10 20 05  mov  5, %o1
a00bf05c:  40 02 55 78  call  0xa015463c
a00bf060:  90 10 20 12  mov  0x12, %o0
a00bf064:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bf068:  92 10 20 06  mov  6, %o1
a00bf06c:  40 02 55 74  call  0xa015463c
a00bf070:  90 10 20 12  mov  0x12, %o0
a00bf074:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bf078:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bf07c:  82 10 20 0d  mov  0xd, %g1
a00bf080:  9a 13 20 40  or  %o4, 0x40, %o5
a00bf084:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00bf088:  80 a6 20 02  cmp  %i0, 2
a00bf08c:  02 80 00 12  be  0xa00bf0d4
a00bf090:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bf094:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bf098:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bf09c:  96 12 a0 98  or  %o2, 0x98, %o3
a00bf0a0:  80 a6 20 03  cmp  %i0, 3
a00bf0a4:  02 80 00 10  be  0xa00bf0e4
a00bf0a8:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bf0ac:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00bf0b0:  c0 2a a0 9c  clrb  [ %o2 + 0x9c ]	! 0xa802b09c
a00bf0b4:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bf0b8:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bf0bc:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bf0c0:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bf0c4:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bf0c8:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bf0cc:  40 02 25 c7  call  0xa01487e8
a00bf0d0:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bf0d4:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00bf0d8:  c0 2a 20 9a  clrb  [ %o0 + 0x9a ]	! 0xa802b09a
a00bf0dc:  10 bf ff f7  b  0xa00bf0b8
a00bf0e0:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bf0e4:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bf0e8:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]	! 0xa802b098
a00bf0ec:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bf0f0:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bf0f4:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bf0f8:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bf0fc:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bf100:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bf104:  40 02 25 b9  call  0xa01487e8
a00bf108:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bf10c:  01 00 00 00  nop
