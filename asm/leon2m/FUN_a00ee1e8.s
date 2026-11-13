# leon2m FUN_a00ee1e8 0xa00ee1e8-0xa00ee964 (524 bytes)
a00ee1e8:  9d e3 bf 78  save  %sp, -136, %sp
a00ee1ec:  90 10 20 0c  mov  0xc, %o0
a00ee1f0:  92 10 00 18  mov  %i0, %o1
a00ee1f4:  94 10 00 1b  mov  %i3, %o2
a00ee1f8:  f6 27 a0 50  st  %i3, [ %fp + 0x50 ]
a00ee1fc:  7f ff c7 6e  call  0xa00dffb4
a00ee200:  e0 07 a0 5c  ld  [ %fp + 0x5c ], %l0
a00ee204:  90 10 00 18  mov  %i0, %o0
a00ee208:  f2 27 a0 48  st  %i1, [ %fp + 0x48 ]
a00ee20c:  92 10 00 19  mov  %i1, %o1
a00ee210:  f4 27 a0 4c  st  %i2, [ %fp + 0x4c ]
a00ee214:  7f ff c6 8f  call  0xa00dfc50
a00ee218:  94 10 00 1a  mov  %i2, %o2
a00ee21c:  c2 07 a0 50  ld  [ %fp + 0x50 ], %g1
a00ee220:  f8 27 a0 54  st  %i4, [ %fp + 0x54 ]
a00ee224:  80 a0 7f ff  cmp  %g1, -1
a00ee228:  02 80 01 66  be  0xa00ee7c0
a00ee22c:  fa 27 a0 58  st  %i5, [ %fp + 0x58 ]
a00ee230:  d6 07 a0 50  ld  [ %fp + 0x50 ], %o3
a00ee234:  27 2a 00 98  sethi  %hi(0xa8026000), %l3
a00ee238:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00ee23c:  9b 2a e0 02  sll  %o3, 2, %o5
a00ee240:  90 14 e2 f8  or  %l3, 0x2f8, %o0
a00ee244:  92 14 62 38  or  %l1, 0x238, %o1
a00ee248:  25 2a 00 98  sethi  %hi(0xa8026000), %l2
a00ee24c:  98 14 a3 08  or  %l2, 0x308, %o4	! 0xa8026308
a00ee250:  d6 02 40 0d  ld  [ %o1 + %o5 ], %o3
a00ee254:  d4 02 00 0d  ld  [ %o0 + %o5 ], %o2
a00ee258:  d2 03 00 0d  ld  [ %o4 + %o5 ], %o1
a00ee25c:  90 10 00 18  mov  %i0, %o0
a00ee260:  7f ff c9 3d  call  0xa00e0754
a00ee264:  33 14 7a e1  sethi  %hi(0x51eb8400), %i1
a00ee268:  f6 07 a0 60  ld  [ %fp + 0x60 ], %i3
a00ee26c:  b4 5a 00 1b  smul  %o0, %i3, %i2
a00ee270:  ab 2e a0 03  sll  %i2, 3, %l5
a00ee274:  ae 16 61 1f  or  %i1, 0x11f, %l7
a00ee278:  80 5d 40 17  smul  %l5, %l7, %g0
a00ee27c:  ad 40 00 00  rd  %y, %l6
a00ee280:  9f 3d a0 05  sra  %l6, 5, %o7
a00ee284:  a9 3d 60 1f  sra  %l5, 0x1f, %l4
a00ee288:  94 23 c0 14  sub  %o7, %l4, %o2
a00ee28c:  d4 27 bf ec  st  %o2, [ %fp + -20 ]
a00ee290:  80 a4 25 35  cmp  %l0, 0x535
a00ee294:  04 80 00 05  ble  0xa00ee2a8
a00ee298:  96 10 20 00  clr  %o3
a00ee29c:  80 a4 27 4a  cmp  %l0, 0x74a
a00ee2a0:  14 80 01 36  bg  0xa00ee778
a00ee2a4:  96 10 20 01  mov  1, %o3
a00ee2a8:  b8 10 00 0b  mov  %o3, %i4
a00ee2ac:  e0 07 a0 50  ld  [ %fp + 0x50 ], %l0
a00ee2b0:  92 14 a3 08  or  %l2, 0x308, %o1
a00ee2b4:  94 14 e2 f8  or  %l3, 0x2f8, %o2
a00ee2b8:  80 a4 3f ff  cmp  %l0, -1
a00ee2bc:  02 80 00 0a  be  0xa00ee2e4
a00ee2c0:  96 14 62 38  or  %l1, 0x238, %o3
a00ee2c4:  82 14 a3 08  or  %l2, 0x308, %g1
a00ee2c8:  ba 14 e2 f8  or  %l3, 0x2f8, %i5
a00ee2cc:  da 07 a0 50  ld  [ %fp + 0x50 ], %o5
a00ee2d0:  a5 2b 60 02  sll  %o5, 2, %l2
a00ee2d4:  a6 14 62 38  or  %l1, 0x238, %l3
a00ee2d8:  d6 04 c0 12  ld  [ %l3 + %l2 ], %o3
a00ee2dc:  d2 00 40 12  ld  [ %g1 + %l2 ], %o1
a00ee2e0:  d4 07 40 12  ld  [ %i5 + %l2 ], %o2
a00ee2e4:  7f ff c9 1c  call  0xa00e0754
a00ee2e8:  90 10 00 18  mov  %i0, %o0
a00ee2ec:  b6 10 00 08  mov  %o0, %i3
a00ee2f0:  90 10 00 18  mov  %i0, %o0
a00ee2f4:  7f ff c7 fe  call  0xa00e02ec
a00ee2f8:  92 10 22 8e  mov  0x28e, %o1
a00ee2fc:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00ee300:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00ee304:  9a 12 21 98  or  %o0, 0x198, %o5	! 0xa8026998
a00ee308:  10 80 00 06  b  0xa00ee320
a00ee30c:  98 10 20 00  clr  %o4
a00ee310:  98 03 20 01  inc  %o4
a00ee314:  80 a3 20 49  cmp  %o4, 0x49
a00ee318:  14 80 01 32  bg  0xa00ee7e0
a00ee31c:  01 00 00 00  nop
a00ee320:  d2 0b 40 00  ldub  [ %o5 ], %o1
a00ee324:  80 a2 40 10  cmp  %o1, %l0
a00ee328:  12 bf ff fa  bne  0xa00ee310
a00ee32c:  9a 03 60 03  add  %o5, 3, %o5
a00ee330:  80 a3 20 00  cmp  %o4, 0
a00ee334:  06 80 01 32  bl  0xa00ee7fc
a00ee338:  d4 07 a0 58  ld  [ %fp + 0x58 ], %o2
a00ee33c:  ea 07 a0 54  ld  [ %fp + 0x54 ], %l5
a00ee340:  d4 23 a0 64  st  %o2, [ %sp + 0x64 ]
a00ee344:  b4 07 bf f0  add  %fp, -16, %i2
a00ee348:  a2 10 00 0c  mov  %o4, %l1
a00ee34c:  d4 07 a0 4c  ld  [ %fp + 0x4c ], %o2
a00ee350:  96 10 00 1c  mov  %i4, %o3
a00ee354:  f6 23 a0 5c  st  %i3, [ %sp + 0x5c ]
a00ee358:  ea 23 a0 60  st  %l5, [ %sp + 0x60 ]
a00ee35c:  f4 23 a0 40  st  %i2, [ %sp + 0x40 ]
a00ee360:  90 10 00 18  mov  %i0, %o0
a00ee364:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a00ee368:  da 07 a0 50  ld  [ %fp + 0x50 ], %o5
a00ee36c:  7f ff fe 41  call  0xa00edc70
a00ee370:  01 00 00 00  nop
a00ee374:  00 00 00 08  unimp  0x8
a00ee378:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a00ee37c:  96 38 00 0a  xnor  %g0, %o2, %o3
a00ee380:  80 a0 00 0b  cmp  %g0, %o3
a00ee384:  d6 07 bf f0  ld  [ %fp + -16 ], %o3
a00ee388:  98 60 3f ff  subx  %g0, -1, %o4
a00ee38c:  a8 38 00 0b  xnor  %g0, %o3, %l4
a00ee390:  80 a0 00 14  cmp  %g0, %l4
a00ee394:  9e 60 3f ff  subx  %g0, -1, %o7
a00ee398:  80 8b 00 0f  btst  %o4, %o7
a00ee39c:  a0 10 00 11  mov  %l1, %l0
a00ee3a0:  12 80 01 69  bne  0xa00ee944
a00ee3a4:  a8 10 20 04  mov  4, %l4
a00ee3a8:  ba 10 00 0a  mov  %o2, %i5
a00ee3ac:  ae 10 00 0b  mov  %o3, %l7
a00ee3b0:  ac 10 00 0a  mov  %o2, %l6
a00ee3b4:  aa 10 00 0b  mov  %o3, %l5
a00ee3b8:  b2 10 20 00  clr  %i1
a00ee3bc:  80 a6 60 00  cmp  %i1, 0
a00ee3c0:  34 80 00 02  bg,a   0xa00ee3c8
a00ee3c4:  a8 10 20 01  mov  1, %l4
a00ee3c8:  a6 10 20 00  clr  %l3
a00ee3cc:  10 80 00 0c  b  0xa00ee3fc
a00ee3d0:  a4 10 20 00  clr  %l2
a00ee3d4:  80 a4 e0 00  cmp  %l3, 0
a00ee3d8:  02 80 00 36  be  0xa00ee4b0
a00ee3dc:  d8 07 a0 54  ld  [ %fp + 0x54 ], %o4
a00ee3e0:  80 a0 00 12  cmp  %g0, %l2
a00ee3e4:  9a 60 3f ff  subx  %g0, -1, %o5
a00ee3e8:  80 a0 00 13  cmp  %g0, %l3
a00ee3ec:  82 60 3f ff  subx  %g0, -1, %g1
a00ee3f0:  80 93 40 01  orcc  %o5, %g1, %g0
a00ee3f4:  22 80 00 5c  be,a   0xa00ee564
a00ee3f8:  b2 06 60 01  inc  %i1
a00ee3fc:  80 a4 a0 00  cmp  %l2, 0
a00ee400:  12 bf ff f6  bne  0xa00ee3d8
a00ee404:  80 a4 e0 00  cmp  %l3, 0
a00ee408:  da 07 a0 54  ld  [ %fp + 0x54 ], %o5
a00ee40c:  da 23 a0 60  st  %o5, [ %sp + 0x60 ]
a00ee410:  c2 07 a0 58  ld  [ %fp + 0x58 ], %g1
a00ee414:  a0 04 00 14  add  %l0, %l4, %l0
a00ee418:  98 10 00 10  mov  %l0, %o4
a00ee41c:  da 07 a0 50  ld  [ %fp + 0x50 ], %o5
a00ee420:  f6 23 a0 5c  st  %i3, [ %sp + 0x5c ]
a00ee424:  c2 23 a0 64  st  %g1, [ %sp + 0x64 ]
a00ee428:  f4 23 a0 40  st  %i2, [ %sp + 0x40 ]
a00ee42c:  90 10 00 18  mov  %i0, %o0
a00ee430:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a00ee434:  d4 07 a0 4c  ld  [ %fp + 0x4c ], %o2
a00ee438:  96 10 00 1c  mov  %i4, %o3
a00ee43c:  7f ff fe 0d  call  0xa00edc70
a00ee440:  01 00 00 00  nop
a00ee444:  00 00 00 08  unimp  0x8
a00ee448:  da 07 bf f4  ld  [ %fp + -12 ], %o5
a00ee44c:  80 a3 7f ff  cmp  %o5, -1
a00ee450:  02 80 00 d9  be  0xa00ee7b4
a00ee454:  d8 07 bf f0  ld  [ %fp + -16 ], %o4
a00ee458:  80 a5 80 0d  cmp  %l6, %o5
a00ee45c:  04 80 00 03  ble  0xa00ee468
a00ee460:  96 10 00 16  mov  %l6, %o3
a00ee464:  96 10 00 0d  mov  %o5, %o3
a00ee468:  80 a5 40 0c  cmp  %l5, %o4
a00ee46c:  16 80 00 03  bge  0xa00ee478
a00ee470:  82 10 00 15  mov  %l5, %g1
a00ee474:  82 10 00 0c  mov  %o4, %g1
a00ee478:  92 22 c0 01  sub  %o3, %g1, %o1
a00ee47c:  d0 07 bf ec  ld  [ %fp + -20 ], %o0
a00ee480:  80 a2 40 08  cmp  %o1, %o0
a00ee484:  26 80 00 cd  bl,a   0xa00ee7b8
a00ee488:  a0 24 00 14  sub  %l0, %l4, %l0
a00ee48c:  ba 10 00 0d  mov  %o5, %i5
a00ee490:  80 a4 20 49  cmp  %l0, 0x49
a00ee494:  04 bf ff d0  ble  0xa00ee3d4
a00ee498:  ae 10 00 0c  mov  %o4, %l7
a00ee49c:  a4 10 20 01  mov  1, %l2
a00ee4a0:  80 a4 e0 00  cmp  %l3, 0
a00ee4a4:  12 bf ff d0  bne  0xa00ee3e4
a00ee4a8:  80 a0 00 12  cmp  %g0, %l2
a00ee4ac:  d8 07 a0 54  ld  [ %fp + 0x54 ], %o4
a00ee4b0:  d8 23 a0 60  st  %o4, [ %sp + 0x60 ]
a00ee4b4:  de 07 a0 58  ld  [ %fp + 0x58 ], %o7
a00ee4b8:  a2 24 40 14  sub  %l1, %l4, %l1
a00ee4bc:  98 10 00 11  mov  %l1, %o4
a00ee4c0:  da 07 a0 50  ld  [ %fp + 0x50 ], %o5
a00ee4c4:  f6 23 a0 5c  st  %i3, [ %sp + 0x5c ]
a00ee4c8:  de 23 a0 64  st  %o7, [ %sp + 0x64 ]
a00ee4cc:  f4 23 a0 40  st  %i2, [ %sp + 0x40 ]
a00ee4d0:  90 10 00 18  mov  %i0, %o0
a00ee4d4:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a00ee4d8:  d4 07 a0 4c  ld  [ %fp + 0x4c ], %o2
a00ee4dc:  96 10 00 1c  mov  %i4, %o3
a00ee4e0:  7f ff fd e4  call  0xa00edc70
a00ee4e4:  01 00 00 00  nop
a00ee4e8:  00 00 00 08  unimp  0x8
a00ee4ec:  da 07 bf f4  ld  [ %fp + -12 ], %o5
a00ee4f0:  80 a3 7f ff  cmp  %o5, -1
a00ee4f4:  02 80 00 ad  be  0xa00ee7a8
a00ee4f8:  d8 07 bf f0  ld  [ %fp + -16 ], %o4
a00ee4fc:  80 a3 40 1d  cmp  %o5, %i5
a00ee500:  04 80 00 03  ble  0xa00ee50c
a00ee504:  96 10 00 0d  mov  %o5, %o3
a00ee508:  96 10 00 1d  mov  %i5, %o3
a00ee50c:  80 a3 00 17  cmp  %o4, %l7
a00ee510:  16 80 00 03  bge  0xa00ee51c
a00ee514:  82 10 00 0c  mov  %o4, %g1
a00ee518:  82 10 00 17  mov  %l7, %g1
a00ee51c:  94 22 c0 01  sub  %o3, %g1, %o2
a00ee520:  d6 07 bf ec  ld  [ %fp + -20 ], %o3
a00ee524:  80 a2 80 0b  cmp  %o2, %o3
a00ee528:  26 80 00 a1  bl,a   0xa00ee7ac
a00ee52c:  a2 04 40 14  add  %l1, %l4, %l1
a00ee530:  ac 10 00 0d  mov  %o5, %l6
a00ee534:  80 a4 60 00  cmp  %l1, 0
a00ee538:  14 bf ff aa  bg  0xa00ee3e0
a00ee53c:  aa 10 00 0c  mov  %o4, %l5
a00ee540:  a6 10 20 01  mov  1, %l3
a00ee544:  80 a0 00 12  cmp  %g0, %l2
a00ee548:  9a 60 3f ff  subx  %g0, -1, %o5
a00ee54c:  80 a0 00 13  cmp  %g0, %l3
a00ee550:  82 60 3f ff  subx  %g0, -1, %g1
a00ee554:  80 93 40 01  orcc  %o5, %g1, %g0
a00ee558:  12 bf ff aa  bne  0xa00ee400
a00ee55c:  80 a4 a0 00  cmp  %l2, 0
a00ee560:  b2 06 60 01  inc  %i1
a00ee564:  80 a6 60 01  cmp  %i1, 1
a00ee568:  04 bf ff 96  ble  0xa00ee3c0
a00ee56c:  80 a6 60 00  cmp  %i1, 0
a00ee570:  35 2a 00 9a  sethi  %hi(0xa8026800), %i2
a00ee574:  9a 16 a1 8c  or  %i2, 0x18c, %o5	! 0xa802698c
a00ee578:  99 2e 20 02  sll  %i0, 2, %o4
a00ee57c:  f2 03 40 0c  ld  [ %o5 + %o4 ], %i1
a00ee580:  80 a6 40 10  cmp  %i1, %l0
a00ee584:  38 80 00 02  bgu,a   0xa00ee58c
a00ee588:  e0 23 40 0c  st  %l0, [ %o5 + %o4 ]
a00ee58c:  25 2a 00 ad  sethi  %hi(0xa802b400), %l2
a00ee590:  82 14 a3 30  or  %l2, 0x330, %g1	! 0xa802b730
a00ee594:  e0 00 40 0c  ld  [ %g1 + %o4 ], %l0
a00ee598:  80 a4 00 11  cmp  %l0, %l1
a00ee59c:  2a 80 00 02  bcs,a   0xa00ee5a4
a00ee5a0:  e2 20 40 0c  st  %l1, [ %g1 + %o4 ]
a00ee5a4:  80 a5 40 17  cmp  %l5, %l7
a00ee5a8:  16 80 00 03  bge  0xa00ee5b4
a00ee5ac:  9a 10 00 15  mov  %l5, %o5
a00ee5b0:  9a 10 00 17  mov  %l7, %o5
a00ee5b4:  80 a5 80 1d  cmp  %l6, %i5
a00ee5b8:  04 80 00 03  ble  0xa00ee5c4
a00ee5bc:  82 10 00 16  mov  %l6, %g1
a00ee5c0:  82 10 00 1d  mov  %i5, %g1
a00ee5c4:  ae 03 40 01  add  %o5, %g1, %l7
a00ee5c8:  ec 07 a0 50  ld  [ %fp + 0x50 ], %l6
a00ee5cc:  80 a5 bf ff  cmp  %l6, -1
a00ee5d0:  02 80 00 8d  be  0xa00ee804
a00ee5d4:  ab 3d e0 01  sra  %l7, 1, %l5
a00ee5d8:  2f 2a 00 9a  sethi  %hi(0xa8026800), %l7
a00ee5dc:  da 07 a0 50  ld  [ %fp + 0x50 ], %o5
a00ee5e0:  a8 15 e0 f8  or  %l7, 0xf8, %l4
a00ee5e4:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00ee5e8:  2d 2a 00 9a  sethi  %hi(0xa8026800), %l6
a00ee5ec:  af 2b 60 02  sll  %o5, 2, %l7
a00ee5f0:  a4 13 21 08  or  %o4, 0x108, %l2
a00ee5f4:  a2 15 a1 18  or  %l6, 0x118, %l1
a00ee5f8:  d2 04 40 17  ld  [ %l1 + %l7 ], %o1
a00ee5fc:  d4 04 80 17  ld  [ %l2 + %l7 ], %o2
a00ee600:  d6 05 00 17  ld  [ %l4 + %l7 ], %o3
a00ee604:  7f ff c8 54  call  0xa00e0754
a00ee608:  90 10 00 18  mov  %i0, %o0
a00ee60c:  81 80 00 00  mov  %g0, %y
a00ee610:  01 00 00 00  nop
a00ee614:  01 00 00 00  nop
a00ee618:  01 00 00 00  nop
a00ee61c:  ac 75 40 1b  udiv  %l5, %i3, %l6
a00ee620:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ee624:  98 02 00 16  add  %o0, %l6, %o4
a00ee628:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ee62c:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ee630:  90 13 e0 c8  or  %o7, 0xc8, %o0
a00ee634:  82 12 e0 d8  or  %o3, 0xd8, %g1
a00ee638:  94 12 60 e8  or  %o1, 0xe8, %o2
a00ee63c:  d2 02 80 17  ld  [ %o2 + %l7 ], %o1
a00ee640:  d6 02 00 17  ld  [ %o0 + %l7 ], %o3
a00ee644:  d4 00 40 17  ld  [ %g1 + %l7 ], %o2
a00ee648:  7f ff c8 4b  call  0xa00e0774
a00ee64c:  90 10 00 18  mov  %i0, %o0
a00ee650:  d2 04 40 17  ld  [ %l1 + %l7 ], %o1
a00ee654:  d4 04 80 17  ld  [ %l2 + %l7 ], %o2
a00ee658:  d6 05 00 17  ld  [ %l4 + %l7 ], %o3
a00ee65c:  7f ff c8 3e  call  0xa00e0754
a00ee660:  90 10 00 18  mov  %i0, %o0
a00ee664:  a0 05 bf fc  add  %l6, -4, %l0
a00ee668:  35 2a 00 9a  sethi  %hi(0xa8026800), %i2
a00ee66c:  39 2a 00 9a  sethi  %hi(0xa8026800), %i4
a00ee670:  3b 2a 00 9a  sethi  %hi(0xa8026800), %i5
a00ee674:  98 02 00 10  add  %o0, %l0, %o4
a00ee678:  b2 16 a0 b8  or  %i2, 0xb8, %i1
a00ee67c:  a6 17 20 a8  or  %i4, 0xa8, %l3
a00ee680:  a4 17 60 98  or  %i5, 0x98, %l2
a00ee684:  d2 06 40 17  ld  [ %i1 + %l7 ], %o1
a00ee688:  d4 04 c0 17  ld  [ %l3 + %l7 ], %o2
a00ee68c:  d6 04 80 17  ld  [ %l2 + %l7 ], %o3
a00ee690:  7f ff c8 39  call  0xa00e0774
a00ee694:  90 10 00 18  mov  %i0, %o0
a00ee698:  a2 5d 80 1b  smul  %l6, %i3, %l1
a00ee69c:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ee6a0:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ee6a4:  ac 25 40 11  sub  %l5, %l1, %l6
a00ee6a8:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00ee6ac:  96 12 a3 88  or  %o2, 0x388, %o3
a00ee6b0:  9a 13 23 98  or  %o4, 0x398, %o5
a00ee6b4:  a8 10 63 78  or  %g1, 0x378, %l4
a00ee6b8:  d4 02 c0 17  ld  [ %o3 + %l7 ], %o2
a00ee6bc:  a5 35 a0 03  srl  %l6, 3, %l2
a00ee6c0:  d2 03 40 17  ld  [ %o5 + %l7 ], %o1
a00ee6c4:  d6 05 00 17  ld  [ %l4 + %l7 ], %o3
a00ee6c8:  90 10 00 18  mov  %i0, %o0
a00ee6cc:  7f ff c8 2a  call  0xa00e0774
a00ee6d0:  98 10 00 12  mov  %l2, %o4
a00ee6d4:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00ee6d8:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00ee6dc:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00ee6e0:  9e 15 63 58  or  %l5, 0x358, %o7
a00ee6e4:  b6 12 63 68  or  %o1, 0x368, %i3
a00ee6e8:  a0 12 22 e8  or  %o0, 0x2e8, %l0
a00ee6ec:  d2 06 c0 17  ld  [ %i3 + %l7 ], %o1
a00ee6f0:  d4 03 c0 17  ld  [ %o7 + %l7 ], %o2
a00ee6f4:  90 10 00 18  mov  %i0, %o0
a00ee6f8:  d6 04 00 17  ld  [ %l0 + %l7 ], %o3
a00ee6fc:  7f ff c8 1e  call  0xa00e0774
a00ee700:  98 0d a0 07  and  %l6, 7, %o4
a00ee704:  3b 2a 00 99  sethi  %hi(0xa8026400), %i5
a00ee708:  98 17 63 38  or  %i5, 0x338, %o4	! 0xa8026738
a00ee70c:  35 2a 00 99  sethi  %hi(0xa8026400), %i2
a00ee710:  39 2a 00 99  sethi  %hi(0xa8026400), %i4
a00ee714:  d4 03 00 17  ld  [ %o4 + %l7 ], %o2
a00ee718:  b2 16 a3 28  or  %i2, 0x328, %i1
a00ee71c:  a6 17 23 48  or  %i4, 0x348, %l3
a00ee720:  90 10 00 18  mov  %i0, %o0
a00ee724:  d6 06 40 17  ld  [ %i1 + %l7 ], %o3
a00ee728:  d2 04 c0 17  ld  [ %l3 + %l7 ], %o1
a00ee72c:  7f ff c8 12  call  0xa00e0774
a00ee730:  98 10 00 12  mov  %l2, %o4
a00ee734:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00ee738:  da 07 a0 50  ld  [ %fp + 0x50 ], %o5
a00ee73c:  ab 2b 60 02  sll  %o5, 2, %l5
a00ee740:  94 12 e2 d8  or  %o3, 0x2d8, %o2
a00ee744:  90 10 00 18  mov  %i0, %o0
a00ee748:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ee74c:  37 2a 00 99  sethi  %hi(0xa8026400), %i3
a00ee750:  d6 02 80 15  ld  [ %o2 + %l5 ], %o3
a00ee754:  a8 10 63 18  or  %g1, 0x318, %l4
a00ee758:  b0 16 e3 08  or  %i3, 0x308, %i0
a00ee75c:  98 10 00 16  mov  %l6, %o4
a00ee760:  d2 05 00 15  ld  [ %l4 + %l5 ], %o1
a00ee764:  d4 06 00 15  ld  [ %i0 + %l5 ], %o2
a00ee768:  7f ff c8 03  call  0xa00e0774
a00ee76c:  98 0b 20 07  and  %o4, 7, %o4
a00ee770:  10 80 00 7b  b  0xa00ee95c
a00ee774:  b0 10 20 00  clr  %i0
a00ee778:  80 a4 29 60  cmp  %l0, 0x960
a00ee77c:  04 bf fe cb  ble  0xa00ee2a8
a00ee780:  96 10 20 02  mov  2, %o3
a00ee784:  80 a4 2a 6b  cmp  %l0, 0xa6b
a00ee788:  04 bf fe c8  ble  0xa00ee2a8
a00ee78c:  96 10 20 03  mov  3, %o3
a00ee790:  7f ff c4 1f  call  0xa00df80c
a00ee794:  23 00 06 67  sethi  %hi(0x199c00), %l1
a00ee798:  7f ff c9 0a  call  0xa00e0bc0
a00ee79c:  01 00 00 00  nop
a00ee7a0:  10 80 00 15  b  0xa00ee7f4
a00ee7a4:  90 14 62 f0  or  %l1, 0x2f0, %o0
a00ee7a8:  a2 04 40 14  add  %l1, %l4, %l1
a00ee7ac:  10 bf ff 66  b  0xa00ee544
a00ee7b0:  a6 10 20 01  mov  1, %l3
a00ee7b4:  a0 24 00 14  sub  %l0, %l4, %l0
a00ee7b8:  10 bf ff 3a  b  0xa00ee4a0
a00ee7bc:  a4 10 20 01  mov  1, %l2
a00ee7c0:  25 2a 00 98  sethi  %hi(0xa8026000), %l2
a00ee7c4:  27 2a 00 98  sethi  %hi(0xa8026000), %l3
a00ee7c8:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00ee7cc:  90 10 00 18  mov  %i0, %o0
a00ee7d0:  92 14 a3 08  or  %l2, 0x308, %o1
a00ee7d4:  94 14 e2 f8  or  %l3, 0x2f8, %o2
a00ee7d8:  10 bf fe a2  b  0xa00ee260
a00ee7dc:  96 14 62 38  or  %l1, 0x238, %o3
a00ee7e0:  7f ff c4 0b  call  0xa00df80c
a00ee7e4:  31 00 06 67  sethi  %hi(0x199c00), %i0
a00ee7e8:  7f ff c8 f6  call  0xa00e0bc0
a00ee7ec:  01 00 00 00  nop
a00ee7f0:  90 16 23 28  or  %i0, 0x328, %o0
a00ee7f4:  7f ff c2 5f  call  0xa00df170
a00ee7f8:  92 10 00 10  mov  %l0, %o1
a00ee7fc:  10 80 00 58  b  0xa00ee95c
a00ee800:  b0 10 3f ff  mov  -1, %i0
a00ee804:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00ee808:  35 2a 00 9a  sethi  %hi(0xa8026800), %i2
a00ee80c:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00ee810:  92 14 21 18  or  %l0, 0x118, %o1
a00ee814:  94 16 a1 08  or  %i2, 0x108, %o2
a00ee818:  96 16 60 f8  or  %i1, 0xf8, %o3
a00ee81c:  7f ff c7 ce  call  0xa00e0754
a00ee820:  90 10 00 18  mov  %i0, %o0
a00ee824:  81 80 00 00  mov  %g0, %y
a00ee828:  01 00 00 00  nop
a00ee82c:  01 00 00 00  nop
a00ee830:  01 00 00 00  nop
a00ee834:  a8 75 40 1b  udiv  %l5, %i3, %l4
a00ee838:  98 02 00 14  add  %o0, %l4, %o4
a00ee83c:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00ee840:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ee844:  96 12 20 c8  or  %o0, 0xc8, %o3
a00ee848:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ee84c:  94 13 e0 d8  or  %o7, 0xd8, %o2
a00ee850:  92 12 60 e8  or  %o1, 0xe8, %o1
a00ee854:  7f ff c7 c8  call  0xa00e0774
a00ee858:  90 10 00 18  mov  %i0, %o0
a00ee85c:  92 14 21 18  or  %l0, 0x118, %o1
a00ee860:  94 16 a1 08  or  %i2, 0x108, %o2
a00ee864:  96 16 60 f8  or  %i1, 0xf8, %o3
a00ee868:  7f ff c7 bb  call  0xa00e0754
a00ee86c:  90 10 00 18  mov  %i0, %o0
a00ee870:  b8 05 3f fc  add  %l4, -4, %i4
a00ee874:  98 02 00 1c  add  %o0, %i4, %o4
a00ee878:  27 2a 00 9a  sethi  %hi(0xa8026800), %l3
a00ee87c:  3b 2a 00 9a  sethi  %hi(0xa8026800), %i5
a00ee880:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00ee884:  92 14 e0 b8  or  %l3, 0xb8, %o1
a00ee888:  94 17 60 a8  or  %i5, 0xa8, %o2
a00ee88c:  96 14 60 98  or  %l1, 0x98, %o3
a00ee890:  90 10 00 18  mov  %i0, %o0
a00ee894:  7f ff c7 b8  call  0xa00e0774
a00ee898:  ae 5d 00 1b  smul  %l4, %i3, %l7
a00ee89c:  b4 25 40 17  sub  %l5, %l7, %i2
a00ee8a0:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00ee8a4:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00ee8a8:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00ee8ac:  92 15 a3 98  or  %l6, 0x398, %o1
a00ee8b0:  94 14 a3 88  or  %l2, 0x388, %o2
a00ee8b4:  96 14 23 78  or  %l0, 0x378, %o3
a00ee8b8:  99 36 a0 03  srl  %i2, 3, %o4
a00ee8bc:  7f ff c7 ae  call  0xa00e0774
a00ee8c0:  90 10 00 18  mov  %i0, %o0
a00ee8c4:  b2 5d 00 1b  smul  %l4, %i3, %i1
a00ee8c8:  82 25 40 19  sub  %l5, %i1, %g1
a00ee8cc:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00ee8d0:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ee8d4:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00ee8d8:  92 13 63 68  or  %o5, 0x368, %o1
a00ee8dc:  98 08 60 07  and  %g1, 7, %o4
a00ee8e0:  94 12 a3 58  or  %o2, 0x358, %o2
a00ee8e4:  96 12 e2 e8  or  %o3, 0x2e8, %o3
a00ee8e8:  7f ff c7 a3  call  0xa00e0774
a00ee8ec:  90 10 00 18  mov  %i0, %o0
a00ee8f0:  98 5d 00 1b  smul  %l4, %i3, %o4
a00ee8f4:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00ee8f8:  96 12 23 28  or  %o0, 0x328, %o3	! 0xa8026728
a00ee8fc:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00ee900:  b8 25 40 0c  sub  %l5, %o4, %i4
a00ee904:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00ee908:  92 12 63 48  or  %o1, 0x348, %o1	! 0xa8026748
a00ee90c:  94 13 e3 38  or  %o7, 0x338, %o2
a00ee910:  99 37 20 03  srl  %i4, 3, %o4
a00ee914:  90 10 00 18  mov  %i0, %o0
a00ee918:  7f ff c7 97  call  0xa00e0774
a00ee91c:  a6 5d 00 1b  smul  %l4, %i3, %l3
a00ee920:  3b 2a 00 99  sethi  %hi(0xa8026400), %i5
a00ee924:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00ee928:  37 2a 00 ad  sethi  %hi(0xa802b400), %i3
a00ee92c:  98 25 40 13  sub  %l5, %l3, %o4
a00ee930:  90 10 00 18  mov  %i0, %o0
a00ee934:  92 17 63 18  or  %i5, 0x318, %o1
a00ee938:  94 14 63 08  or  %l1, 0x308, %o2
a00ee93c:  10 bf ff 8b  b  0xa00ee768
a00ee940:  96 16 e2 d8  or  %i3, 0x2d8, %o3
a00ee944:  7f ff c3 b2  call  0xa00df80c
a00ee948:  39 00 06 67  sethi  %hi(0x199c00), %i4
a00ee94c:  7f ff c8 9d  call  0xa00e0bc0
a00ee950:  b0 10 3f ff  mov  -1, %i0
a00ee954:  7f ff c2 07  call  0xa00df170
a00ee958:  90 17 21 50  or  %i4, 0x150, %o0
a00ee95c:  81 c7 e0 08  ret
a00ee960:  81 e8 00 00  restore
