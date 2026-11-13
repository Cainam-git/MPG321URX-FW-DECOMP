# leon2m FUN_a015b300 0xa015b300-0xa015b468 (360 bytes)
a015b300:  9d e3 bf 98  save  %sp, -104, %sp
a015b304:  80 a6 20 00  cmp  %i0, 0
a015b308:  02 80 00 48  be  0xa015b428
a015b30c:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a015b310:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015b314:  80 88 62 00  btst  0x200, %g1
a015b318:  02 80 00 3e  be  0xa015b410
a015b31c:  01 00 00 00  nop
a015b320:  03 2a 00 aa  sethi  %hi(0xa802a800), %g1
a015b324:  d0 00 62 18  ld  [ %g1 + 0x218 ], %o0	! 0xa802aa18
a015b328:  80 a2 20 00  cmp  %o0, 0
a015b32c:  32 80 00 26  bne,a   0xa015b3c4
a015b330:  c2 02 20 38  ld  [ %o0 + 0x38 ], %g1
a015b334:  da 16 20 0c  lduh  [ %i0 + 0xc ], %o5
a015b338:  83 2b 60 10  sll  %o5, 0x10, %g1
a015b33c:  91 38 60 10  sra  %g1, 0x10, %o0
a015b340:  80 8a 20 08  btst  8, %o0
a015b344:  22 80 00 2c  be,a   0xa015b3f4
a015b348:  83 30 60 10  srl  %g1, 0x10, %g1
a015b34c:  e0 06 20 10  ld  [ %i0 + 0x10 ], %l0
a015b350:  80 a4 20 00  cmp  %l0, 0
a015b354:  02 80 00 27  be  0xa015b3f0
a015b358:  80 8a 20 03  btst  3, %o0
a015b35c:  c2 06 00 00  ld  [ %i0 ], %g1
a015b360:  b2 20 40 10  sub  %g1, %l0, %i1
a015b364:  e0 26 00 00  st  %l0, [ %i0 ]
a015b368:  02 80 00 2e  be  0xa015b420
a015b36c:  82 10 20 00  clr  %g1
a015b370:  80 a6 60 00  cmp  %i1, 0
a015b374:  04 80 00 0f  ble  0xa015b3b0
a015b378:  c2 26 20 08  st  %g1, [ %i0 + 8 ]
a015b37c:  92 10 00 10  mov  %l0, %o1
a015b380:  94 10 00 19  mov  %i1, %o2
a015b384:  c2 06 20 24  ld  [ %i0 + 0x24 ], %g1
a015b388:  9f c0 40 00  call  %g1
a015b38c:  d0 06 20 1c  ld  [ %i0 + 0x1c ], %o0
a015b390:  b2 26 40 08  sub  %i1, %o0, %i1
a015b394:  80 a2 20 00  cmp  %o0, 0
a015b398:  04 80 00 28  ble  0xa015b438
a015b39c:  a0 04 00 08  add  %l0, %o0, %l0
a015b3a0:  80 a6 60 00  cmp  %i1, 0
a015b3a4:  14 bf ff f7  bg  0xa015b380
a015b3a8:  92 10 00 10  mov  %l0, %o1
a015b3ac:  da 16 20 0c  lduh  [ %i0 + 0xc ], %o5
a015b3b0:  80 8b 62 00  btst  0x200, %o5
a015b3b4:  02 80 00 13  be  0xa015b400
a015b3b8:  01 00 00 00  nop
a015b3bc:  10 80 00 29  b  0xa015b460
a015b3c0:  b0 10 20 00  clr  %i0	! 0x0
a015b3c4:  80 a0 60 00  cmp  %g1, 0
a015b3c8:  32 bf ff dc  bne,a   0xa015b338
a015b3cc:  da 16 20 0c  lduh  [ %i0 + 0xc ], %o5
a015b3d0:  40 00 00 62  call  0xa015b558
a015b3d4:  01 00 00 00  nop
a015b3d8:  da 16 20 0c  lduh  [ %i0 + 0xc ], %o5
a015b3dc:  83 2b 60 10  sll  %o5, 0x10, %g1
a015b3e0:  91 38 60 10  sra  %g1, 0x10, %o0
a015b3e4:  80 8a 20 08  btst  8, %o0
a015b3e8:  32 bf ff da  bne,a   0xa015b350
a015b3ec:  e0 06 20 10  ld  [ %i0 + 0x10 ], %l0
a015b3f0:  83 30 60 10  srl  %g1, 0x10, %g1
a015b3f4:  80 88 62 00  btst  0x200, %g1
a015b3f8:  32 80 00 1a  bne,a   0xa015b460
a015b3fc:  b0 10 20 00  clr  %i0
a015b400:  40 00 0d 9a  call  0xa015ea68
a015b404:  90 06 20 58  add  %i0, 0x58, %o0
a015b408:  10 80 00 16  b  0xa015b460
a015b40c:  b0 10 20 00  clr  %i0
a015b410:  40 00 0d 7e  call  0xa015ea08
a015b414:  90 06 20 58  add  %i0, 0x58, %o0
a015b418:  10 bf ff c3  b  0xa015b324
a015b41c:  03 2a 00 aa  sethi  %hi(0xa802a800), %g1
a015b420:  10 bf ff d4  b  0xa015b370
a015b424:  c2 06 20 14  ld  [ %i0 + 0x14 ], %g1
a015b428:  33 00 03 ec  sethi  %hi(0xfb000), %i1
a015b42c:  f0 00 63 d8  ld  [ %g1 + 0x3d8 ], %i0
a015b430:  40 00 02 d3  call  0xa015bf7c
a015b434:  93 ee 63 00  restore  %i1, 0x300, %o1
a015b438:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015b43c:  82 10 60 40  or  %g1, 0x40, %g1
a015b440:  80 88 62 00  btst  0x200, %g1
a015b444:  02 80 00 04  be  0xa015b454
a015b448:  c2 36 20 0c  sth  %g1, [ %i0 + 0xc ]
a015b44c:  10 80 00 05  b  0xa015b460
a015b450:  b0 10 3f ff  mov  -1, %i0
a015b454:  40 00 0d 85  call  0xa015ea68
a015b458:  90 06 20 58  add  %i0, 0x58, %o0
a015b45c:  b0 10 3f ff  mov  -1, %i0
a015b460:  81 c7 e0 08  ret
a015b464:  81 e8 00 00  restore
