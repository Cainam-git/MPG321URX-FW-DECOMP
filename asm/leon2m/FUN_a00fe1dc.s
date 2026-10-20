# leon2m FUN_a00fe1dc 0xa00fe1dc-0xa00fe3ec (528 bytes)
a00fe1dc:  9d e3 bf 98  save  %sp, -104, %sp
a00fe1e0:  13 00 06 69  sethi  %hi(0x19a400), %o1
a00fe1e4:  90 12 60 d8  or  %o1, 0xd8, %o0	! 0x19a4d8
a00fe1e8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00fe1ec:  7f ff 83 e1  call  0xa00df170
a00fe1f0:  92 10 00 18  mov  %i0, %o1
a00fe1f4:  40 00 7b 65  call  0xa011cf88
a00fe1f8:  01 00 00 00  nop
a00fe1fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00fe200:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00fe204:  80 a2 20 81  cmp  %o0, 0x81
a00fe208:  18 80 00 04  bgu  0xa00fe218
a00fe20c:  82 10 62 e0  or  %g1, 0x2e0, %g1
a00fe210:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00fe214:  82 12 a2 d4  or  %o2, 0x2d4, %g1	! 0xcf0116d4
a00fe218:  da 00 40 00  ld  [ %g1 ], %o5
a00fe21c:  9a 0b 7f d7  and  %o5, -41, %o5
a00fe220:  80 a6 20 02  cmp  %i0, 2
a00fe224:  02 80 00 3c  be  0xa00fe314
a00fe228:  a0 10 00 0d  mov  %o5, %l0
a00fe22c:  80 a6 20 02  cmp  %i0, 2
a00fe230:  04 80 00 1a  ble  0xa00fe298
a00fe234:  80 a6 20 01  cmp  %i0, 1
a00fe238:  80 a6 20 03  cmp  %i0, 3
a00fe23c:  02 80 00 54  be  0xa00fe38c
a00fe240:  13 33 c0 f2  sethi  %hi(0xcf03c800), %o1
a00fe244:  40 00 7b 51  call  0xa011cf88
a00fe248:  01 00 00 00  nop
a00fe24c:  96 0a 20 ff  and  %o0, 0xff, %o3
a00fe250:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00fe254:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00fe258:  80 a2 e0 81  cmp  %o3, 0x81
a00fe25c:  18 80 00 0d  bgu  0xa00fe290
a00fe260:  82 12 62 e0  or  %o1, 0x2e0, %g1
a00fe264:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00fe268:  de 00 62 a4  ld  [ %g1 + 0x2a4 ], %o7	! 0xa802d6a4
a00fe26c:  d4 03 c0 00  ld  [ %o7 ], %o2
a00fe270:  1b 00 1c 00  sethi  %hi(0x700000), %o5
a00fe274:  98 0a 80 0d  and  %o2, %o5, %o4
a00fe278:  31 00 04 00  sethi  %hi(0x100000), %i0
a00fe27c:  80 a3 00 18  cmp  %o4, %i0
a00fe280:  02 80 00 59  be  0xa00fe3e4
a00fe284:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00fe288:  21 33 c0 45  sethi  %hi(0xcf011400), %l0
a00fe28c:  82 14 22 d4  or  %l0, 0x2d4, %g1	! 0xcf0116d4
a00fe290:  da 20 40 00  st  %o5, [ %g1 ]
a00fe294:  30 80 00 54  b,a   0xa00fe3e4
a00fe298:  12 bf ff eb  bne  0xa00fe244
a00fe29c:  1f 33 c0 f2  sethi  %hi(0xcf03c800), %o7
a00fe2a0:  19 00 00 3f  sethi  %hi(0xfc00), %o4
a00fe2a4:  a0 10 00 0d  mov  %o5, %l0
a00fe2a8:  96 13 e0 40  or  %o7, 0x40, %o3
a00fe2ac:  92 13 23 ff  or  %o4, 0x3ff, %o1
a00fe2b0:  94 10 3f ff  mov  -1, %o2
a00fe2b4:  90 10 20 01  mov  1, %o0
a00fe2b8:  82 02 bf ff  add  %o2, -1, %g1
a00fe2bc:  95 28 60 10  sll  %g1, 0x10, %o2
a00fe2c0:  9b 32 a0 10  srl  %o2, 0x10, %o5
a00fe2c4:  f0 02 c0 00  ld  [ %o3 ], %i0
a00fe2c8:  80 a6 20 02  cmp  %i0, 2
a00fe2cc:  02 80 00 03  be  0xa00fe2d8
a00fe2d0:  94 10 00 01  mov  %g1, %o2
a00fe2d4:  d0 22 c0 00  st  %o0, [ %o3 ]
a00fe2d8:  d8 02 c0 00  ld  [ %o3 ], %o4
a00fe2dc:  80 a3 20 01  cmp  %o4, 1
a00fe2e0:  02 80 00 04  be  0xa00fe2f0
a00fe2e4:  80 a3 40 09  cmp  %o5, %o1
a00fe2e8:  32 bf ff f5  bne,a   0xa00fe2bc
a00fe2ec:  82 02 bf ff  add  %o2, -1, %g1
a00fe2f0:  9a 10 20 01  mov  1, %o5
a00fe2f4:  da 22 c0 00  st  %o5, [ %o3 ]
a00fe2f8:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00fe2fc:  9a 12 62 00  or  %o1, 0x200, %o5	! 0xcf011600
a00fe300:  d0 03 40 00  ld  [ %o5 ], %o0
a00fe304:  82 0a 3f 7f  and  %o0, -129, %g1
a00fe308:  c2 23 40 00  st  %g1, [ %o5 ]
a00fe30c:  c0 22 c0 00  clr  [ %o3 ]
a00fe310:  30 bf ff cd  b,a   0xa00fe244
a00fe314:  31 33 c0 f2  sethi  %hi(0xcf03c800), %i0
a00fe318:  1f 00 00 3f  sethi  %hi(0xfc00), %o7
a00fe31c:  a0 13 60 08  or  %o5, 8, %l0
a00fe320:  96 16 20 40  or  %i0, 0x40, %o3
a00fe324:  92 13 e3 ff  or  %o7, 0x3ff, %o1
a00fe328:  94 10 3f ff  mov  -1, %o2
a00fe32c:  90 10 20 01  mov  1, %o0
a00fe330:  82 02 bf ff  add  %o2, -1, %g1
a00fe334:  95 28 60 10  sll  %g1, 0x10, %o2
a00fe338:  9b 32 a0 10  srl  %o2, 0x10, %o5
a00fe33c:  d8 02 c0 00  ld  [ %o3 ], %o4
a00fe340:  80 a3 20 02  cmp  %o4, 2
a00fe344:  02 80 00 03  be  0xa00fe350
a00fe348:  94 10 00 01  mov  %g1, %o2
a00fe34c:  d0 22 c0 00  st  %o0, [ %o3 ]
a00fe350:  de 02 c0 00  ld  [ %o3 ], %o7
a00fe354:  80 a3 e0 01  cmp  %o7, 1
a00fe358:  02 80 00 04  be  0xa00fe368
a00fe35c:  80 a3 40 09  cmp  %o5, %o1
a00fe360:  32 bf ff f5  bne,a   0xa00fe334
a00fe364:  82 02 bf ff  add  %o2, -1, %g1
a00fe368:  90 10 20 01  mov  1, %o0
a00fe36c:  1f 33 c0 45  sethi  %hi(0xcf011400), %o7
a00fe370:  d0 22 c0 00  st  %o0, [ %o3 ]
a00fe374:  9a 13 e2 00  or  %o7, 0x200, %o5
a00fe378:  d4 03 40 00  ld  [ %o5 ], %o2
a00fe37c:  82 12 a0 80  or  %o2, 0x80, %g1
a00fe380:  c2 23 40 00  st  %g1, [ %o5 ]
a00fe384:  c0 22 c0 00  clr  [ %o3 ]
a00fe388:  30 bf ff af  b,a   0xa00fe244
a00fe38c:  11 00 00 3f  sethi  %hi(0xfc00), %o0
a00fe390:  96 12 60 40  or  %o1, 0x40, %o3
a00fe394:  92 12 23 ff  or  %o0, 0x3ff, %o1
a00fe398:  a0 13 60 20  or  %o5, 0x20, %l0
a00fe39c:  94 10 3f ff  mov  -1, %o2
a00fe3a0:  90 10 20 01  mov  1, %o0
a00fe3a4:  98 02 bf ff  add  %o2, -1, %o4
a00fe3a8:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00fe3ac:  f0 02 c0 00  ld  [ %o3 ], %i0
a00fe3b0:  9b 33 60 10  srl  %o5, 0x10, %o5
a00fe3b4:  80 a6 20 02  cmp  %i0, 2
a00fe3b8:  02 80 00 03  be  0xa00fe3c4
a00fe3bc:  94 10 00 0c  mov  %o4, %o2
a00fe3c0:  d0 22 c0 00  st  %o0, [ %o3 ]
a00fe3c4:  c2 02 c0 00  ld  [ %o3 ], %g1
a00fe3c8:  80 a0 60 01  cmp  %g1, 1
a00fe3cc:  02 bf ff e7  be  0xa00fe368
a00fe3d0:  80 a3 40 09  cmp  %o5, %o1
a00fe3d4:  12 bf ff f5  bne  0xa00fe3a8
a00fe3d8:  98 02 bf ff  add  %o2, -1, %o4
a00fe3dc:  10 bf ff e4  b  0xa00fe36c
a00fe3e0:  90 10 20 01  mov  1, %o0
a00fe3e4:  81 c7 e0 08  ret
a00fe3e8:  81 e8 00 00  restore
