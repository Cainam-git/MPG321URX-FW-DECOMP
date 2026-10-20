# leon2m FUN_a00dc2dc 0xa00dc2dc-0xa00dc3dc (256 bytes)
a00dc2dc:  9d e3 bf 88  save  %sp, -120, %sp
a00dc2e0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00dc2e4:  a2 10 62 90  or  %g1, 0x290, %l1	! 0xa802d290
a00dc2e8:  11 00 06 61  sethi  %hi(0x198400), %o0
a00dc2ec:  da 0c 61 e2  ldub  [ %l1 + 0x1e2 ], %o5
a00dc2f0:  d8 0c 61 e6  ldub  [ %l1 + 0x1e6 ], %o4
a00dc2f4:  92 12 21 24  or  %o0, 0x124, %o1
a00dc2f8:  de 0c 61 e3  ldub  [ %l1 + 0x1e3 ], %o7
a00dc2fc:  d6 0c 61 e7  ldub  [ %l1 + 0x1e7 ], %o3
a00dc300:  da 2f bf f0  stb  %o5, [ %fp + -16 ]
a00dc304:  d8 2f bf e8  stb  %o4, [ %fp + -24 ]
a00dc308:  94 10 21 fc  mov  0x1fc, %o2
a00dc30c:  e0 0c 60 1e  ldub  [ %l1 + 0x1e ], %l0
a00dc310:  de 2f bf f1  stb  %o7, [ %fp + -15 ]
a00dc314:  d6 2f bf e9  stb  %o3, [ %fp + -23 ]
a00dc318:  40 01 81 7e  call  0xa013c910
a00dc31c:  90 10 00 11  mov  %l1, %o0
a00dc320:  d8 0c 60 12  ldub  [ %l1 + 0x12 ], %o4
a00dc324:  d4 0f bf f0  ldub  [ %fp + -16 ], %o2
a00dc328:  d2 0f bf f1  ldub  [ %fp + -15 ], %o1
a00dc32c:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00dc330:  da 0f bf e9  ldub  [ %fp + -23 ], %o5
a00dc334:  90 10 20 00  clr  %o0
a00dc338:  e0 2c 60 1e  stb  %l0, [ %l1 + 0x1e ]
a00dc33c:  d4 2c 61 e2  stb  %o2, [ %l1 + 0x1e2 ]
a00dc340:  d2 2c 61 e3  stb  %o1, [ %l1 + 0x1e3 ]
a00dc344:  c2 2c 61 e6  stb  %g1, [ %l1 + 0x1e6 ]
a00dc348:  80 a3 20 64  cmp  %o4, 0x64
a00dc34c:  08 80 00 03  bleu  0xa00dc358
a00dc350:  da 2c 61 e7  stb  %o5, [ %l1 + 0x1e7 ]
a00dc354:  98 10 20 64  mov  0x64, %o4
a00dc358:  92 0b 20 ff  and  %o4, 0xff, %o1
a00dc35c:  40 01 b7 70  call  0xa014a11c
a00dc360:  d8 2c 60 12  stb  %o4, [ %l1 + 0x12 ]
a00dc364:  c2 0c 60 13  ldub  [ %l1 + 0x13 ], %g1
a00dc368:  80 a0 60 64  cmp  %g1, 0x64
a00dc36c:  08 80 00 03  bleu  0xa00dc378
a00dc370:  90 10 20 01  mov  1, %o0
a00dc374:  82 10 20 64  mov  0x64, %g1
a00dc378:  92 08 60 ff  and  %g1, 0xff, %o1
a00dc37c:  40 01 b7 68  call  0xa014a11c
a00dc380:  c2 2c 60 13  stb  %g1, [ %l1 + 0x13 ]
a00dc384:  c2 0c 60 14  ldub  [ %l1 + 0x14 ], %g1
a00dc388:  80 a0 60 64  cmp  %g1, 0x64
a00dc38c:  08 80 00 03  bleu  0xa00dc398
a00dc390:  90 10 20 02  mov  2, %o0
a00dc394:  82 10 20 64  mov  0x64, %g1
a00dc398:  92 08 60 ff  and  %g1, 0xff, %o1
a00dc39c:  40 01 b7 60  call  0xa014a11c
a00dc3a0:  c2 2c 60 14  stb  %g1, [ %l1 + 0x14 ]
a00dc3a4:  7f ff f4 56  call  0xa00d94fc
a00dc3a8:  01 00 00 00  nop
a00dc3ac:  d2 04 60 a8  ld  [ %l1 + 0xa8 ], %o1
a00dc3b0:  80 8a 68 00  btst  0x800, %o1
a00dc3b4:  12 80 00 05  bne  0xa00dc3c8
a00dc3b8:  01 00 00 00  nop
a00dc3bc:  7f ff fe 4d  call  0xa00dbcf0
a00dc3c0:  01 00 00 00  nop
a00dc3c4:  30 80 00 03  b,a   0xa00dc3d0
a00dc3c8:  7f ff fc dc  call  0xa00db738
a00dc3cc:  01 00 00 00  nop
a00dc3d0:  01 00 00 00  nop
a00dc3d4:  81 c7 e0 08  ret
a00dc3d8:  81 e8 00 00  restore
