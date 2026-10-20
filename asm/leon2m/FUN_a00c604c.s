# leon2m FUN_a00c604c 0xa00c604c-0xa00c6228 (476 bytes)
a00c604c:  9d e3 bf 98  save  %sp, -104, %sp
a00c6050:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c6054:  80 a4 20 02  cmp  %l0, 2
a00c6058:  02 80 00 52  be  0xa00c61a0
a00c605c:  80 a4 20 03  cmp  %l0, 3
a00c6060:  02 80 00 53  be  0xa00c61ac
a00c6064:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c6068:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c606c:  94 08 60 ff  and  %g1, 0xff, %o2
a00c6070:  98 02 bf d0  add  %o2, -48, %o4
a00c6074:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c6078:  80 a3 60 05  cmp  %o5, 5
a00c607c:  18 80 00 69  bgu  0xa00c6220
a00c6080:  b0 10 20 ff  mov  0xff, %i0
a00c6084:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c6088:  40 00 39 be  call  0xa00d4780
a00c608c:  d8 2a e2 9f  stb  %o4, [ %o3 + 0x29f ]	! 0xa802d29f
a00c6090:  7f ff ca 0f  call  0xa00b88cc
a00c6094:  01 00 00 00  nop
a00c6098:  80 a4 20 02  cmp  %l0, 2
a00c609c:  02 80 00 24  be  0xa00c612c
a00c60a0:  80 a4 20 03  cmp  %l0, 3
a00c60a4:  02 80 00 45  be  0xa00c61b8
a00c60a8:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c60ac:  94 13 60 78  or  %o5, 0x78, %o2	! 0xa802d078
a00c60b0:  90 10 20 30  mov  0x30, %o0
a00c60b4:  96 10 20 35  mov  0x35, %o3
a00c60b8:  98 10 20 36  mov  0x36, %o4
a00c60bc:  92 10 20 2b  mov  0x2b, %o1
a00c60c0:  82 10 20 0d  mov  0xd, %g1
a00c60c4:  d6 2b 60 78  stb  %o3, [ %o5 + 0x78 ]
a00c60c8:  d8 2a a0 01  stb  %o4, [ %o2 + 1 ]
a00c60cc:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00c60d0:  d2 2a a0 04  stb  %o1, [ %o2 + 4 ]
a00c60d4:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00c60d8:  80 a4 20 02  cmp  %l0, 2
a00c60dc:  02 80 00 21  be  0xa00c6160
a00c60e0:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00c60e4:  80 a4 20 03  cmp  %l0, 3
a00c60e8:  02 80 00 41  be  0xa00c61ec
a00c60ec:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c60f0:  92 13 20 d0  or  %o4, 0xd0, %o1	! 0xa802d0d0
a00c60f4:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00c60f8:  c0 2b 60 9c  clrb  [ %o5 + 0x9c ]	! 0xa802b09c
a00c60fc:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00c6100:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00c6104:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00c6108:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00c610c:  80 a4 20 02  cmp  %l0, 2
a00c6110:  02 80 00 1d  be  0xa00c6184
a00c6114:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00c6118:  80 a4 20 03  cmp  %l0, 3
a00c611c:  12 80 00 1d  bne  0xa00c6190
a00c6120:  90 10 00 10  mov  %l0, %o0
a00c6124:  10 80 00 3c  b  0xa00c6214
a00c6128:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c612c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c6130:  98 12 21 28  or  %o0, 0x128, %o4	! 0xa802d128
a00c6134:  9e 10 20 30  mov  0x30, %o7
a00c6138:  92 10 20 35  mov  0x35, %o1
a00c613c:  82 10 20 0d  mov  0xd, %g1
a00c6140:  b0 10 20 36  mov  0x36, %i0
a00c6144:  a0 10 20 2b  mov  0x2b, %l0
a00c6148:  d2 2a 21 28  stb  %o1, [ %o0 + 0x128 ]
a00c614c:  c2 2b 20 05  stb  %g1, [ %o4 + 5 ]
a00c6150:  f0 2b 20 01  stb  %i0, [ %o4 + 1 ]
a00c6154:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a00c6158:  e0 2b 20 04  stb  %l0, [ %o4 + 4 ]
a00c615c:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a00c6160:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c6164:  94 13 e0 40  or  %o7, 0x40, %o2	! 0xa802d040
a00c6168:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00c616c:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00c6170:  c0 2b e0 40  clrb  [ %o7 + 0x40 ]
a00c6174:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c6178:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c617c:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c6180:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c6184:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c6188:  94 12 e1 28  or  %o3, 0x128, %o2	! 0xa802d128
a00c618c:  90 10 20 02  mov  2, %o0
a00c6190:  40 02 09 96  call  0xa01487e8
a00c6194:  92 10 20 06  mov  6, %o1
a00c6198:  10 80 00 22  b  0xa00c6220
a00c619c:  b0 10 20 00  clr  %i0
a00c61a0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c61a4:  10 bf ff b2  b  0xa00c606c
a00c61a8:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c61ac:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c61b0:  10 bf ff af  b  0xa00c606c
a00c61b4:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c61b8:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c61bc:  98 14 21 08  or  %l0, 0x108, %o4	! 0xa802d108
a00c61c0:  94 10 20 30  mov  0x30, %o2
a00c61c4:  b0 10 20 35  mov  0x35, %i0
a00c61c8:  9e 10 20 0d  mov  0xd, %o7
a00c61cc:  96 10 20 36  mov  0x36, %o3
a00c61d0:  9a 10 20 2b  mov  0x2b, %o5
a00c61d4:  f0 2c 21 08  stb  %i0, [ %l0 + 0x108 ]
a00c61d8:  de 2b 20 05  stb  %o7, [ %o4 + 5 ]
a00c61dc:  d6 2b 20 01  stb  %o3, [ %o4 + 1 ]
a00c61e0:  d4 2b 20 03  stb  %o2, [ %o4 + 3 ]
a00c61e4:  da 2b 20 04  stb  %o5, [ %o4 + 4 ]
a00c61e8:  d4 2b 20 02  stb  %o2, [ %o4 + 2 ]
a00c61ec:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c61f0:  b0 12 20 98  or  %o0, 0x98, %i0	! 0xa802d098
a00c61f4:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c61f8:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c61fc:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00c6200:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00c6204:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00c6208:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00c620c:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00c6210:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c6214:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c6218:  10 bf ff de  b  0xa00c6190
a00c621c:  90 10 20 03  mov  3, %o0
a00c6220:  81 c7 e0 08  ret
a00c6224:  81 e8 00 00  restore
