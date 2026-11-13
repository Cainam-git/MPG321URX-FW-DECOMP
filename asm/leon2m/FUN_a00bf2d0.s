# leon2m FUN_a00bf2d0 0xa00bf2d0-0xa00bf3f8 (296 bytes)
a00bf2d0:  9d e3 bf 98  save  %sp, -104, %sp
a00bf2d4:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00bf2d8:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bf2dc:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00bf2e0:  d4 0a e2 a8  ldub  [ %o3 + 0x2a8 ], %o2
a00bf2e4:  92 10 20 30  mov  0x30, %o1
a00bf2e8:  9a 02 a0 30  add  %o2, 0x30, %o5
a00bf2ec:  d2 2c 20 08  stb  %o1, [ %l0 + 8 ]
a00bf2f0:  d2 2c 20 07  stb  %o1, [ %l0 + 7 ]
a00bf2f4:  da 2c 20 09  stb  %o5, [ %l0 + 9 ]
a00bf2f8:  92 10 20 00  clr  %o1
a00bf2fc:  40 02 54 d0  call  0xa015463c
a00bf300:  90 10 20 0c  mov  0xc, %o0
a00bf304:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bf308:  90 10 20 62  mov  0x62, %o0
a00bf30c:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bf310:  92 10 20 02  mov  2, %o1
a00bf314:  40 02 54 ca  call  0xa015463c
a00bf318:  90 10 20 0c  mov  0xc, %o0
a00bf31c:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bf320:  92 10 20 03  mov  3, %o1
a00bf324:  40 02 54 c6  call  0xa015463c
a00bf328:  90 10 20 0c  mov  0xc, %o0
a00bf32c:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bf330:  92 10 20 04  mov  4, %o1
a00bf334:  40 02 54 c2  call  0xa015463c
a00bf338:  90 10 20 0c  mov  0xc, %o0
a00bf33c:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bf340:  92 10 20 05  mov  5, %o1
a00bf344:  40 02 54 be  call  0xa015463c
a00bf348:  90 10 20 0c  mov  0xc, %o0
a00bf34c:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bf350:  92 10 20 06  mov  6, %o1
a00bf354:  40 02 54 ba  call  0xa015463c
a00bf358:  90 10 20 0c  mov  0xc, %o0
a00bf35c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bf360:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bf364:  82 10 20 0d  mov  0xd, %g1
a00bf368:  9a 13 20 40  or  %o4, 0x40, %o5
a00bf36c:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00bf370:  80 a6 20 02  cmp  %i0, 2
a00bf374:  02 80 00 12  be  0xa00bf3bc
a00bf378:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bf37c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bf380:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bf384:  96 12 a0 98  or  %o2, 0x98, %o3
a00bf388:  80 a6 20 03  cmp  %i0, 3
a00bf38c:  02 80 00 10  be  0xa00bf3cc
a00bf390:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bf394:  33 2a 00 ac  sethi  %hi(0xa802b000), %i1
a00bf398:  c0 2e 60 9c  clrb  [ %i1 + 0x9c ]	! 0xa802b09c
a00bf39c:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bf3a0:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bf3a4:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bf3a8:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bf3ac:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bf3b0:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bf3b4:  40 02 25 0d  call  0xa01487e8
a00bf3b8:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bf3bc:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bf3c0:  c0 2b e0 9a  clrb  [ %o7 + 0x9a ]	! 0xa802b09a
a00bf3c4:  10 bf ff f7  b  0xa00bf3a0
a00bf3c8:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bf3cc:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00bf3d0:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]	! 0xa802b098
a00bf3d4:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bf3d8:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bf3dc:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bf3e0:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bf3e4:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bf3e8:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bf3ec:  40 02 24 ff  call  0xa01487e8
a00bf3f0:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bf3f4:  01 00 00 00  nop
