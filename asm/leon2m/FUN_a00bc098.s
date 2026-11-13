# leon2m FUN_a00bc098 0xa00bc098-0xa00bc214 (380 bytes)
a00bc098:  9d e3 bf 98  save  %sp, -104, %sp
a00bc09c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bc0a0:  d4 0b 62 d9  ldub  [ %o5 + 0x2d9 ], %o2	! 0xa802d2d9
a00bc0a4:  11 14 7a e1  sethi  %hi(0x51eb8400), %o0
a00bc0a8:  b2 0a a0 ff  and  %o2, 0xff, %i1
a00bc0ac:  82 12 21 1f  or  %o0, 0x11f, %g1
a00bc0b0:  80 56 40 01  umul  %i1, %g1, %g0
a00bc0b4:  97 40 00 00  rd  %y, %o3
a00bc0b8:  b3 32 e0 05  srl  %o3, 5, %i1
a00bc0bc:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00bc0c0:  a0 5e a0 64  smul  %i2, 0x64, %l0
a00bc0c4:  b4 22 80 10  sub  %o2, %l0, %i2
a00bc0c8:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a00bc0cc:  92 0e a0 ff  and  %i2, 0xff, %o1
a00bc0d0:  9e 13 20 cd  or  %o4, 0xcd, %o7
a00bc0d4:  80 52 40 0f  umul  %o1, %o7, %g0
a00bc0d8:  9b 40 00 00  rd  %y, %o5
a00bc0dc:  9f 33 60 03  srl  %o5, 3, %o7
a00bc0e0:  90 0b e0 ff  and  %o7, 0xff, %o0
a00bc0e4:  83 2a 20 02  sll  %o0, 2, %g1
a00bc0e8:  a0 00 40 08  add  %g1, %o0, %l0
a00bc0ec:  98 04 00 10  add  %l0, %l0, %o4
a00bc0f0:  92 26 80 0c  sub  %i2, %o4, %o1
a00bc0f4:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bc0f8:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00bc0fc:  9a 03 e0 30  add  %o7, 0x30, %o5
a00bc100:  94 02 60 30  add  %o1, 0x30, %o2
a00bc104:  96 06 60 30  add  %i1, 0x30, %o3
a00bc108:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a00bc10c:  d6 2c 20 07  stb  %o3, [ %l0 + 7 ]
a00bc110:  d4 2c 20 09  stb  %o2, [ %l0 + 9 ]
a00bc114:  92 10 20 00  clr  %o1
a00bc118:  40 02 61 49  call  0xa015463c
a00bc11c:  90 10 20 05  mov  5, %o0
a00bc120:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bc124:  90 10 20 62  mov  0x62, %o0
a00bc128:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bc12c:  92 10 20 02  mov  2, %o1
a00bc130:  40 02 61 43  call  0xa015463c
a00bc134:  90 10 20 05  mov  5, %o0
a00bc138:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bc13c:  92 10 20 03  mov  3, %o1
a00bc140:  40 02 61 3f  call  0xa015463c
a00bc144:  90 10 20 05  mov  5, %o0
a00bc148:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bc14c:  92 10 20 04  mov  4, %o1
a00bc150:  40 02 61 3b  call  0xa015463c
a00bc154:  90 10 20 05  mov  5, %o0
a00bc158:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bc15c:  92 10 20 05  mov  5, %o1
a00bc160:  40 02 61 37  call  0xa015463c
a00bc164:  90 10 20 05  mov  5, %o0
a00bc168:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bc16c:  92 10 20 06  mov  6, %o1
a00bc170:  40 02 61 33  call  0xa015463c
a00bc174:  90 10 20 05  mov  5, %o0
a00bc178:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bc17c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bc180:  82 10 20 0d  mov  0xd, %g1
a00bc184:  9a 13 20 40  or  %o4, 0x40, %o5
a00bc188:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00bc18c:  80 a6 20 02  cmp  %i0, 2
a00bc190:  02 80 00 12  be  0xa00bc1d8
a00bc194:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bc198:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bc19c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bc1a0:  96 12 a0 98  or  %o2, 0x98, %o3
a00bc1a4:  80 a6 20 03  cmp  %i0, 3
a00bc1a8:  02 80 00 10  be  0xa00bc1e8
a00bc1ac:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bc1b0:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00bc1b4:  c0 2a a0 9c  clrb  [ %o2 + 0x9c ]	! 0xa802b09c
a00bc1b8:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bc1bc:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bc1c0:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bc1c4:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bc1c8:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bc1cc:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bc1d0:  40 02 31 86  call  0xa01487e8
a00bc1d4:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bc1d8:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00bc1dc:  c0 2a 60 9a  clrb  [ %o1 + 0x9a ]	! 0xa802b09a
a00bc1e0:  10 bf ff f7  b  0xa00bc1bc
a00bc1e4:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bc1e8:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bc1ec:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]	! 0xa802b098
a00bc1f0:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bc1f4:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bc1f8:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bc1fc:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bc200:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bc204:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bc208:  40 02 31 78  call  0xa01487e8
a00bc20c:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bc210:  01 00 00 00  nop
