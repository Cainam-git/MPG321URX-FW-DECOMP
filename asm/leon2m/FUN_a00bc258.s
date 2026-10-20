# leon2m FUN_a00bc258 0xa00bc258-0xa00bc3b0 (344 bytes)
a00bc258:  9d e3 bf 98  save  %sp, -104, %sp
a00bc25c:  92 10 20 00  clr  %o1
a00bc260:  40 02 60 f7  call  0xa015463c
a00bc264:  90 10 20 4b  mov  0x4b, %o0
a00bc268:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bc26c:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00bc270:  92 10 20 62  mov  0x62, %o1
a00bc274:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bc278:  d2 2c 20 01  stb  %o1, [ %l0 + 1 ]
a00bc27c:  92 10 20 02  mov  2, %o1
a00bc280:  40 02 60 ef  call  0xa015463c
a00bc284:  90 10 20 4b  mov  0x4b, %o0
a00bc288:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bc28c:  92 10 20 03  mov  3, %o1
a00bc290:  40 02 60 eb  call  0xa015463c
a00bc294:  90 10 20 4b  mov  0x4b, %o0
a00bc298:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bc29c:  92 10 20 04  mov  4, %o1
a00bc2a0:  40 02 60 e7  call  0xa015463c
a00bc2a4:  90 10 20 4b  mov  0x4b, %o0
a00bc2a8:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bc2ac:  92 10 20 05  mov  5, %o1
a00bc2b0:  40 02 60 e3  call  0xa015463c
a00bc2b4:  90 10 20 4b  mov  0x4b, %o0
a00bc2b8:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bc2bc:  90 10 20 4b  mov  0x4b, %o0
a00bc2c0:  40 02 60 df  call  0xa015463c
a00bc2c4:  92 10 20 06  mov  6, %o1
a00bc2c8:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bc2cc:  90 10 20 12  mov  0x12, %o0
a00bc2d0:  03 00 06 60  sethi  %hi(0x198000), %g1
a00bc2d4:  d0 2c 20 07  stb  %o0, [ %l0 + 7 ]
a00bc2d8:  94 10 62 80  or  %g1, 0x280, %o2
a00bc2dc:  96 10 20 00  clr  %o3
a00bc2e0:  98 10 20 00  clr  %o4
a00bc2e4:  da 0a 80 0c  ldub  [ %o2 + %o4 ], %o5
a00bc2e8:  9e 03 00 10  add  %o4, %l0, %o7
a00bc2ec:  96 02 e0 01  inc  %o3
a00bc2f0:  98 0a e0 ff  and  %o3, 0xff, %o4
a00bc2f4:  80 a3 20 12  cmp  %o4, 0x12
a00bc2f8:  0a bf ff fb  bcs  0xa00bc2e4
a00bc2fc:  da 2b e0 08  stb  %o5, [ %o7 + 8 ]
a00bc300:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bc304:  94 10 20 0d  mov  0xd, %o2
a00bc308:  80 a6 20 02  cmp  %i0, 2
a00bc30c:  02 80 00 10  be  0xa00bc34c
a00bc310:  d4 2c 20 24  stb  %o2, [ %l0 + 0x24 ]
a00bc314:  80 a6 20 03  cmp  %i0, 3
a00bc318:  02 80 00 19  be  0xa00bc37c
a00bc31c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00bc320:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00bc324:  9a 12 20 d0  or  %o0, 0xd0, %o5
a00bc328:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]
a00bc32c:  c0 2a 20 d0  clrb  [ %o0 + 0xd0 ]
a00bc330:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bc334:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bc338:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bc33c:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bc340:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bc344:  40 02 31 29  call  0xa01487e8
a00bc348:  93 e8 20 25  restore  %g0, 0x25, %o1
a00bc34c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bc350:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00bc354:  9a 13 20 40  or  %o4, 0x40, %o5
a00bc358:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]
a00bc35c:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bc360:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bc364:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bc368:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bc36c:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bc370:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bc374:  40 02 31 1d  call  0xa01487e8
a00bc378:  93 e8 20 25  restore  %g0, 0x25, %o1
a00bc37c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00bc380:  33 2a 00 ac  sethi  %hi(0xa802b000), %i1
a00bc384:  c0 2e 60 98  clrb  [ %i1 + 0x98 ]	! 0xa802b098
a00bc388:  9a 14 20 98  or  %l0, 0x98, %o5
a00bc38c:  c0 2c 20 98  clrb  [ %l0 + 0x98 ]
a00bc390:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bc394:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bc398:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bc39c:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bc3a0:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bc3a4:  40 02 31 11  call  0xa01487e8
a00bc3a8:  93 e8 20 25  restore  %g0, 0x25, %o1
a00bc3ac:  01 00 00 00  nop
