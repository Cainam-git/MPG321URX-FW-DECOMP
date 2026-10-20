# leon2m FUN_a00dd250 0xa00dd250-0xa00dd3d4 (388 bytes)
a00dd250:  9d e3 bf 88  save  %sp, -120, %sp
a00dd254:  80 a6 20 00  cmp  %i0, 0
a00dd258:  02 80 00 5d  be  0xa00dd3cc
a00dd25c:  80 a6 60 00  cmp  %i1, 0
a00dd260:  02 80 00 50  be  0xa00dd3a0
a00dd264:  ac 0e 3f fc  and  %i0, -4, %l6
a00dd268:  83 2e 60 02  sll  %i1, 2, %g1
a00dd26c:  b2 00 40 16  add  %g1, %l6, %i1
a00dd270:  9a 06 60 0f  add  %i1, 0xf, %o5
a00dd274:  2f 00 03 fb  sethi  %hi(0xfec00), %l7
a00dd278:  ba 0b 7f f0  and  %o5, -16, %i5
a00dd27c:  90 15 e3 90  or  %l7, 0x390, %o0
a00dd280:  40 00 07 30  call  0xa00def40
a00dd284:  b0 0e 3f f0  and  %i0, -16, %i0
a00dd288:  80 a6 00 1d  cmp  %i0, %i5
a00dd28c:  1a 80 00 42  bcc  0xa00dd394
a00dd290:  aa 10 00 18  mov  %i0, %l5
a00dd294:  37 00 06 62  sethi  %hi(0x198800), %i3
a00dd298:  b8 07 bf f8  add  %fp, -8, %i4
a00dd29c:  35 00 06 62  sethi  %hi(0x198800), %i2
a00dd2a0:  40 00 07 57  call  0xa00deffc
a00dd2a4:  90 10 00 15  mov  %l5, %o0
a00dd2a8:  40 00 07 26  call  0xa00def40
a00dd2ac:  90 16 e3 60  or  %i3, 0x360, %o0
a00dd2b0:  a4 07 3f f0  add  %i4, -16, %l2
a00dd2b4:  a8 10 20 03  mov  3, %l4
a00dd2b8:  80 a6 00 16  cmp  %i0, %l6
a00dd2bc:  92 40 20 00  addx  %g0, 0, %o1
a00dd2c0:  80 a6 00 19  cmp  %i0, %i1
a00dd2c4:  90 60 3f ff  subx  %g0, -1, %o0
a00dd2c8:  80 92 40 08  orcc  %o1, %o0, %g0
a00dd2cc:  12 80 00 3b  bne  0xa00dd3b8
a00dd2d0:  15 00 06 62  sethi  %hi(0x198800), %o2
a00dd2d4:  e2 06 00 00  ld  [ %i0 ], %l1
a00dd2d8:  e2 24 80 00  st  %l1, [ %l2 ]
a00dd2dc:  a0 10 20 00  clr  %l0
a00dd2e0:  27 00 06 62  sethi  %hi(0x198800), %l3
a00dd2e4:  99 2c 20 03  sll  %l0, 3, %o4
a00dd2e8:  97 34 40 0c  srl  %l1, %o4, %o3
a00dd2ec:  40 00 07 82  call  0xa00df0f4
a00dd2f0:  90 0a e0 ff  and  %o3, 0xff, %o0
a00dd2f4:  40 00 07 13  call  0xa00def40
a00dd2f8:  90 14 e3 b0  or  %l3, 0x3b0, %o0
a00dd2fc:  a0 04 20 01  inc  %l0
a00dd300:  80 a4 20 03  cmp  %l0, 3
a00dd304:  04 bf ff f9  ble  0xa00dd2e8
a00dd308:  99 2c 20 03  sll  %l0, 3, %o4
a00dd30c:  b0 06 20 04  add  %i0, 4, %i0
a00dd310:  a8 85 3f ff  addcc  %l4, -1, %l4
a00dd314:  1c bf ff e9  bpos  0xa00dd2b8
a00dd318:  a4 04 a0 04  add  %l2, 4, %l2
a00dd31c:  40 00 07 09  call  0xa00def40
a00dd320:  90 16 a3 68  or  %i2, 0x368, %o0
a00dd324:  a6 10 20 00  clr  %l3
a00dd328:  29 00 06 62  sethi  %hi(0x198800), %l4
a00dd32c:  a4 07 3f f0  add  %i4, -16, %l2
a00dd330:  e2 04 80 00  ld  [ %l2 ], %l1
a00dd334:  a0 10 20 00  clr  %l0
a00dd338:  93 2c 20 03  sll  %l0, 3, %o1
a00dd33c:  91 34 40 09  srl  %l1, %o1, %o0
a00dd340:  82 02 3f e0  add  %o0, -32, %g1
a00dd344:  9b 2a 20 18  sll  %o0, 0x18, %o5
a00dd348:  9e 08 60 ff  and  %g1, 0xff, %o7
a00dd34c:  80 a3 e0 5e  cmp  %o7, 0x5e
a00dd350:  18 80 00 16  bgu  0xa00dd3a8
a00dd354:  91 3b 60 18  sra  %o5, 0x18, %o0
a00dd358:  40 00 06 e6  call  0xa00deef0
a00dd35c:  a0 04 20 01  inc  %l0
a00dd360:  80 a4 20 03  cmp  %l0, 3
a00dd364:  04 bf ff f6  ble  0xa00dd33c
a00dd368:  93 2c 20 03  sll  %l0, 3, %o1
a00dd36c:  a6 04 e0 01  inc  %l3
a00dd370:  80 a4 e0 03  cmp  %l3, 3
a00dd374:  04 bf ff ef  ble  0xa00dd330
a00dd378:  a4 04 a0 04  add  %l2, 4, %l2
a00dd37c:  40 00 06 f1  call  0xa00def40
a00dd380:  90 15 e3 90  or  %l7, 0x390, %o0
a00dd384:  aa 05 60 10  add  %l5, 0x10, %l5
a00dd388:  80 a5 40 1d  cmp  %l5, %i5
a00dd38c:  0a bf ff c5  bcs  0xa00dd2a0
a00dd390:  01 00 00 00  nop
a00dd394:  40 00 06 eb  call  0xa00def40
a00dd398:  90 15 e3 90  or  %l7, 0x390, %o0
a00dd39c:  30 80 00 0c  b,a   0xa00dd3cc
a00dd3a0:  10 bf ff b2  b  0xa00dd268
a00dd3a4:  b2 10 20 20  mov  0x20, %i1
a00dd3a8:  40 00 06 e6  call  0xa00def40
a00dd3ac:  90 15 23 80  or  %l4, 0x380, %o0
a00dd3b0:  10 bf ff ec  b  0xa00dd360
a00dd3b4:  a0 04 20 01  inc  %l0
a00dd3b8:  c0 24 80 00  clr  [ %l2 ]
a00dd3bc:  40 00 06 e1  call  0xa00def40
a00dd3c0:  90 12 a3 70  or  %o2, 0x370, %o0
a00dd3c4:  10 bf ff d3  b  0xa00dd310
a00dd3c8:  b0 06 20 04  add  %i0, 4, %i0
a00dd3cc:  81 c7 e0 08  ret
a00dd3d0:  81 e8 00 00  restore
