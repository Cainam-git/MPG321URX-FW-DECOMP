# leon2m FUN_a00ef1b0 0xa00ef1b0-0xa00f0380 (4560 bytes)
a00ef1b0:  9d e3 bf 50  save  %sp, -176, %sp
a00ef1b4:  15 00 06 68  sethi  %hi(0x19a000), %o2
a00ef1b8:  92 12 a0 04  or  %o2, 4, %o1	! 0x19a004
a00ef1bc:  94 10 20 44  mov  0x44, %o2
a00ef1c0:  40 01 35 d4  call  0xa013c910
a00ef1c4:  90 07 bf b0  add  %fp, -80, %o0
a00ef1c8:  2d 2a 00 9a  sethi  %hi(0xa8026800), %l6
a00ef1cc:  92 10 20 55  mov  0x55, %o1
a00ef1d0:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef1d4:  40 00 0c 31  call  0xa00f2298
a00ef1d8:  94 10 20 00  clr  %o2
a00ef1dc:  67 fe 77 f1  call  0x4008d1a0
a00ef1e0:  90 10 20 32  mov  0x32, %o0
a00ef1e4:  d2 0d a2 79  ldub  [ %l6 + 0x279 ], %o1
a00ef1e8:  90 02 7f fa  add  %o1, -6, %o0
a00ef1ec:  82 0a 20 ff  and  %o0, 0xff, %g1
a00ef1f0:  80 a0 60 01  cmp  %g1, 1
a00ef1f4:  08 80 00 03  bleu  0xa00ef200
a00ef1f8:  b6 10 20 02  mov  2, %i3
a00ef1fc:  b6 10 20 08  mov  8, %i3
a00ef200:  3b 2a 00 9a  sethi  %hi(0xa8026800), %i5
a00ef204:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4	! 0xa8026a78
a00ef208:  80 a3 20 08  cmp  %o4, 8
a00ef20c:  02 80 02 d4  be  0xa00efd5c
a00ef210:  80 a3 20 03  cmp  %o4, 3
a00ef214:  08 80 00 e7  bleu  0xa00ef5b0
a00ef218:  03 00 06 67  sethi  %hi(0x199c00), %g1
a00ef21c:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef220:  92 10 20 88  mov  0x88, %o1
a00ef224:  94 10 20 20  mov  0x20, %o2
a00ef228:  40 00 0c 41  call  0xa00f232c
a00ef22c:  96 10 20 00  clr  %o3
a00ef230:  80 8e 60 ff  btst  0xff, %i1
a00ef234:  02 80 00 ef  be  0xa00ef5f0
a00ef238:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00ef23c:  d0 16 80 00  lduh  [ %i2 ], %o0
a00ef240:  80 8a 20 07  btst  7, %o0
a00ef244:  02 80 00 06  be  0xa00ef25c
a00ef248:  af 2a 20 10  sll  %o0, 0x10, %l7
a00ef24c:  97 35 e0 13  srl  %l7, 0x13, %o3
a00ef250:  95 2a e0 03  sll  %o3, 3, %o2
a00ef254:  92 02 a0 08  add  %o2, 8, %o1
a00ef258:  af 2a 60 10  sll  %o1, 0x10, %l7
a00ef25c:  d2 16 a0 02  lduh  [ %i2 + 2 ], %o1
a00ef260:  b9 2a 60 10  sll  %o1, 0x10, %i4
a00ef264:  e0 16 a0 0e  lduh  [ %i2 + 0xe ], %l0
a00ef268:  e2 16 a0 06  lduh  [ %i2 + 6 ], %l1
a00ef26c:  e4 16 a0 0a  lduh  [ %i2 + 0xa ], %l2
a00ef270:  e6 16 a0 0c  lduh  [ %i2 + 0xc ], %l3
a00ef274:  e8 16 a0 04  lduh  [ %i2 + 4 ], %l4
a00ef278:  ea 16 a0 08  lduh  [ %i2 + 8 ], %l5
a00ef27c:  d0 0e 62 79  ldub  [ %i1 + 0x279 ], %o0
a00ef280:  95 37 20 10  srl  %i4, 0x10, %o2
a00ef284:  40 00 0c 81  call  0xa00f2488
a00ef288:  92 10 20 5b  mov  0x5b, %o1
a00ef28c:  91 2c 20 10  sll  %l0, 0x10, %o0
a00ef290:  b5 32 20 10  srl  %o0, 0x10, %i2
a00ef294:  94 10 00 1a  mov  %i2, %o2
a00ef298:  d0 0e 62 79  ldub  [ %i1 + 0x279 ], %o0
a00ef29c:  40 00 0c 7b  call  0xa00f2488
a00ef2a0:  92 10 20 64  mov  0x64, %o1
a00ef2a4:  94 10 00 1a  mov  %i2, %o2
a00ef2a8:  d0 0e 62 79  ldub  [ %i1 + 0x279 ], %o0
a00ef2ac:  40 00 0c 77  call  0xa00f2488
a00ef2b0:  92 10 20 71  mov  0x71, %o1
a00ef2b4:  83 2c a0 10  sll  %l2, 0x10, %g1
a00ef2b8:  95 30 60 10  srl  %g1, 0x10, %o2
a00ef2bc:  d0 0e 62 79  ldub  [ %i1 + 0x279 ], %o0
a00ef2c0:  40 00 0c 72  call  0xa00f2488
a00ef2c4:  92 10 20 be  mov  0xbe, %o1
a00ef2c8:  99 2c 60 10  sll  %l1, 0x10, %o4
a00ef2cc:  a5 33 20 10  srl  %o4, 0x10, %l2
a00ef2d0:  d0 0e 62 79  ldub  [ %i1 + 0x279 ], %o0
a00ef2d4:  94 10 00 12  mov  %l2, %o2
a00ef2d8:  40 00 0c 6c  call  0xa00f2488
a00ef2dc:  92 10 20 62  mov  0x62, %o1
a00ef2e0:  94 10 00 12  mov  %l2, %o2
a00ef2e4:  d0 0e 62 79  ldub  [ %i1 + 0x279 ], %o0
a00ef2e8:  40 00 0c 68  call  0xa00f2488
a00ef2ec:  92 10 20 6f  mov  0x6f, %o1
a00ef2f0:  a3 2c e0 10  sll  %l3, 0x10, %l1
a00ef2f4:  95 35 e0 10  srl  %l7, 0x10, %o2
a00ef2f8:  d0 0e 62 79  ldub  [ %i1 + 0x279 ], %o0
a00ef2fc:  40 00 0c 63  call  0xa00f2488
a00ef300:  92 10 20 5e  mov  0x5e, %o1
a00ef304:  a1 34 60 10  srl  %l1, 0x10, %l0
a00ef308:  d0 0e 62 79  ldub  [ %i1 + 0x279 ], %o0
a00ef30c:  94 10 00 10  mov  %l0, %o2
a00ef310:  40 00 0c 5e  call  0xa00f2488
a00ef314:  92 10 20 68  mov  0x68, %o1
a00ef318:  94 10 00 10  mov  %l0, %o2
a00ef31c:  d0 0e 62 79  ldub  [ %i1 + 0x279 ], %o0
a00ef320:  40 00 0c 5a  call  0xa00f2488
a00ef324:  92 10 20 75  mov  0x75, %o1
a00ef328:  9b 2d 60 10  sll  %l5, 0x10, %o5
a00ef32c:  95 33 60 10  srl  %o5, 0x10, %o2
a00ef330:  d0 0e 62 79  ldub  [ %i1 + 0x279 ], %o0
a00ef334:  40 00 0c 55  call  0xa00f2488
a00ef338:  92 10 20 a0  mov  0xa0, %o1
a00ef33c:  9f 2d 20 10  sll  %l4, 0x10, %o7
a00ef340:  b5 33 e0 10  srl  %o7, 0x10, %i2
a00ef344:  d0 0e 62 79  ldub  [ %i1 + 0x279 ], %o0
a00ef348:  94 10 00 1a  mov  %i2, %o2
a00ef34c:  40 00 0c 4f  call  0xa00f2488
a00ef350:  92 10 20 66  mov  0x66, %o1
a00ef354:  d0 0e 62 79  ldub  [ %i1 + 0x279 ], %o0
a00ef358:  94 10 00 1a  mov  %i2, %o2
a00ef35c:  40 00 0c 4b  call  0xa00f2488
a00ef360:  92 10 20 73  mov  0x73, %o1
a00ef364:  a7 3d e0 10  sra  %l7, 0x10, %l3
a00ef368:  40 01 9a 36  call  0xa0155c40
a00ef36c:  90 10 00 13  mov  %l3, %o0
a00ef370:  80 a4 e0 00  cmp  %l3, 0
a00ef374:  06 80 01 11  bl  0xa00ef7b8
a00ef378:  a2 10 00 08  mov  %o0, %l1
a00ef37c:  a5 37 20 10  srl  %i4, 0x10, %l2
a00ef380:  40 01 9a 30  call  0xa0155c40
a00ef384:  90 10 00 12  mov  %l2, %o0
a00ef388:  92 10 00 08  mov  %o0, %o1
a00ef38c:  40 01 99 29  call  0xa0155830
a00ef390:  90 10 00 11  mov  %l1, %o0
a00ef394:  a6 10 00 08  mov  %o0, %l3
a00ef398:  40 00 c5 e8  call  0xa0120b38
a00ef39c:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef3a0:  91 2a 20 10  sll  %o0, 0x10, %o0
a00ef3a4:  40 01 9a 27  call  0xa0155c40
a00ef3a8:  91 32 20 10  srl  %o0, 0x10, %o0
a00ef3ac:  92 10 00 08  mov  %o0, %o1
a00ef3b0:  40 01 99 20  call  0xa0155830
a00ef3b4:  90 10 00 13  mov  %l3, %o0
a00ef3b8:  03 00 06 61  sethi  %hi(0x198400), %g1
a00ef3bc:  40 01 99 97  call  0xa0155a18
a00ef3c0:  d2 00 63 60  ld  [ %g1 + 0x360 ], %o1	! 0x198760
a00ef3c4:  40 01 97 7e  call  0xa01551bc
a00ef3c8:  a3 35 e0 10  srl  %l7, 0x10, %l1
a00ef3cc:  a6 10 00 08  mov  %o0, %l3
a00ef3d0:  d0 0f 62 78  ldub  [ %i5 + 0x278 ], %o0
a00ef3d4:  40 00 4c c5  call  0xa01026e8
a00ef3d8:  92 10 00 13  mov  %l3, %o1
a00ef3dc:  96 10 20 01  mov  1, %o3
a00ef3e0:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef3e4:  92 10 20 61  mov  0x61, %o1
a00ef3e8:  40 00 0b d1  call  0xa00f232c
a00ef3ec:  94 10 20 03  mov  3, %o2
a00ef3f0:  94 10 20 41  mov  0x41, %o2
a00ef3f4:  92 10 20 50  mov  0x50, %o1
a00ef3f8:  40 00 0b a8  call  0xa00f2298
a00ef3fc:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef400:  40 00 5d c2  call  0xa0106b08
a00ef404:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef408:  67 fe 77 66  call  0x4008d1a0
a00ef40c:  90 10 20 32  mov  0x32, %o0
a00ef410:  92 10 20 7c  mov  0x7c, %o1
a00ef414:  40 00 0b 90  call  0xa00f2254
a00ef418:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef41c:  98 0a 20 ff  and  %o0, 0xff, %o4
a00ef420:  a9 33 20 04  srl  %o4, 4, %l4
a00ef424:  92 10 20 78  mov  0x78, %o1
a00ef428:  40 00 0b 8b  call  0xa00f2254
a00ef42c:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef430:  9a 0a 20 7f  and  %o0, 0x7f, %o5
a00ef434:  a1 2b 60 08  sll  %o5, 8, %l0
a00ef438:  92 10 20 77  mov  0x77, %o1
a00ef43c:  40 00 0b 86  call  0xa00f2254
a00ef440:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef444:  96 0a 20 ff  and  %o0, 0xff, %o3
a00ef448:  b4 14 00 0b  or  %l0, %o3, %i2
a00ef44c:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef450:  92 10 20 50  mov  0x50, %o1
a00ef454:  40 00 0b 91  call  0xa00f2298
a00ef458:  94 10 20 01  mov  1, %o2
a00ef45c:  94 05 20 01  add  %l4, 1, %o2
a00ef460:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef464:  40 00 0b 8d  call  0xa00f2298
a00ef468:  92 10 20 51  mov  0x51, %o1
a00ef46c:  94 0e a0 ff  and  %i2, 0xff, %o2
a00ef470:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef474:  40 00 0b 89  call  0xa00f2298
a00ef478:  92 10 20 52  mov  0x52, %o1
a00ef47c:  b3 2e a0 10  sll  %i2, 0x10, %i1
a00ef480:  95 36 60 18  srl  %i1, 0x18, %o2
a00ef484:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef488:  40 00 0b 84  call  0xa00f2298
a00ef48c:  92 10 20 53  mov  0x53, %o1
a00ef490:  94 10 20 06  mov  6, %o2
a00ef494:  96 10 20 01  mov  1, %o3
a00ef498:  92 10 20 88  mov  0x88, %o1
a00ef49c:  40 00 0b a4  call  0xa00f232c
a00ef4a0:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef4a4:  9e 5c 40 12  smul  %l1, %l2, %o7
a00ef4a8:  a8 0e e0 ff  and  %i3, 0xff, %l4
a00ef4ac:  81 80 00 00  mov  %g0, %y
a00ef4b0:  01 00 00 00  nop
a00ef4b4:  01 00 00 00  nop
a00ef4b8:  01 00 00 00  nop
a00ef4bc:  a2 73 c0 14  udiv  %o7, %l4, %l1
a00ef4c0:  40 00 c5 9e  call  0xa0120b38
a00ef4c4:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef4c8:  93 2a 20 10  sll  %o0, 0x10, %o1
a00ef4cc:  93 32 60 10  srl  %o1, 0x10, %o1
a00ef4d0:  40 00 c9 bf  call  0xa0121bcc
a00ef4d4:  90 10 20 02  mov  2, %o0
a00ef4d8:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef4dc:  40 00 0d 3e  call  0xa00f29d4
a00ef4e0:  92 10 20 89  mov  0x89, %o1
a00ef4e4:  37 00 0e 00  sethi  %hi(0x380000), %i3
a00ef4e8:  80 a4 40 1b  cmp  %l1, %i3
a00ef4ec:  08 80 00 0c  bleu  0xa00ef51c
a00ef4f0:  a0 10 00 08  mov  %o0, %l0
a00ef4f4:  a4 24 40 08  sub  %l1, %o0, %l2
a00ef4f8:  9f 3c a0 1f  sra  %l2, 0x1f, %o7
a00ef4fc:  92 1b c0 12  xor  %o7, %l2, %o1
a00ef500:  b6 22 40 0f  sub  %o1, %o7, %i3
a00ef504:  15 00 08 00  sethi  %hi(0x200000), %o2
a00ef508:  80 a6 c0 0a  cmp  %i3, %o2
a00ef50c:  04 80 00 05  ble  0xa00ef520
a00ef510:  80 a4 e0 00  cmp  %l3, 0
a00ef514:  33 00 10 00  sethi  %hi(0x400000), %i1
a00ef518:  a0 02 00 19  add  %o0, %i1, %l0
a00ef51c:  80 a4 e0 00  cmp  %l3, 0
a00ef520:  06 80 02 31  bl  0xa00efde4
a00ef524:  b5 34 e0 01  srl  %l3, 1, %i2
a00ef528:  40 01 99 c6  call  0xa0155c40
a00ef52c:  90 10 00 13  mov  %l3, %o0
a00ef530:  80 a4 60 00  cmp  %l1, 0
a00ef534:  06 80 02 24  bl  0xa00efdc4
a00ef538:  a4 10 00 08  mov  %o0, %l2
a00ef53c:  40 01 99 c1  call  0xa0155c40
a00ef540:  90 10 00 11  mov  %l1, %o0
a00ef544:  80 a4 20 00  cmp  %l0, 0
a00ef548:  06 80 02 17  bl  0xa00efda4
a00ef54c:  a2 10 00 08  mov  %o0, %l1
a00ef550:  40 01 99 bc  call  0xa0155c40
a00ef554:  90 10 00 10  mov  %l0, %o0
a00ef558:  92 10 00 08  mov  %o0, %o1
a00ef55c:  40 01 99 2f  call  0xa0155a18
a00ef560:  90 10 00 11  mov  %l1, %o0
a00ef564:  92 10 00 08  mov  %o0, %o1
a00ef568:  40 01 98 b2  call  0xa0155830
a00ef56c:  90 10 00 12  mov  %l2, %o0
a00ef570:  40 01 97 13  call  0xa01551bc
a00ef574:  01 00 00 00  nop
a00ef578:  a2 10 00 08  mov  %o0, %l1
a00ef57c:  d0 0f 62 78  ldub  [ %i5 + 0x278 ], %o0
a00ef580:  40 00 4c 5a  call  0xa01026e8
a00ef584:  92 10 00 11  mov  %l1, %o1
a00ef588:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef58c:  92 10 20 88  mov  0x88, %o1
a00ef590:  94 10 20 06  mov  6, %o2
a00ef594:  40 00 0b 66  call  0xa00f232c
a00ef598:  96 10 20 00  clr  %o3
a00ef59c:  80 8e 20 ff  btst  0xff, %i0
a00ef5a0:  02 80 03 76  be  0xa00f0378
a00ef5a4:  27 00 06 68  sethi  %hi(0x19a000), %l3
a00ef5a8:  10 80 00 89  b  0xa00ef7cc
a00ef5ac:  90 14 e0 48  or  %l3, 0x48, %o0	! 0x19a048
a00ef5b0:  ae 03 00 0c  add  %o4, %o4, %l7
a00ef5b4:  b8 10 63 fc  or  %g1, 0x3fc, %i4
a00ef5b8:  ea 17 00 17  lduh  [ %i4 + %l7 ], %l5
a00ef5bc:  a7 2d 60 02  sll  %l5, 2, %l3
a00ef5c0:  29 33 c0 00  sethi  %hi(0xcf000000), %l4
a00ef5c4:  98 10 20 16  mov  0x16, %o4
a00ef5c8:  a4 14 c0 14  or  %l3, %l4, %l2
a00ef5cc:  d8 24 80 00  st  %o4, [ %l2 ]
a00ef5d0:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef5d4:  92 10 20 88  mov  0x88, %o1
a00ef5d8:  94 10 20 20  mov  0x20, %o2
a00ef5dc:  40 00 0b 54  call  0xa00f232c
a00ef5e0:  96 10 20 00  clr  %o3
a00ef5e4:  80 8e 60 ff  btst  0xff, %i1
a00ef5e8:  12 bf ff 15  bne  0xa00ef23c
a00ef5ec:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00ef5f0:  27 2a 00 ad  sethi  %hi(0xa802b400), %l3
a00ef5f4:  f2 14 e3 4e  lduh  [ %l3 + 0x34e ], %i1	! 0xa802b74e
a00ef5f8:  a7 2e 60 10  sll  %i1, 0x10, %l3
a00ef5fc:  b3 34 e0 10  srl  %l3, 0x10, %i1
a00ef600:  ee 16 80 00  lduh  [ %i2 ], %l7
a00ef604:  94 5d c0 19  smul  %l7, %i1, %o2
a00ef608:  d2 16 a0 0c  lduh  [ %i2 + 0xc ], %o1
a00ef60c:  97 3a a0 1f  sra  %o2, 0x1f, %o3
a00ef610:  81 82 e0 00  mov  %o3, %y
a00ef614:  01 00 00 00  nop
a00ef618:  01 00 00 00  nop
a00ef61c:  01 00 00 00  nop
a00ef620:  94 7a 80 09  sdiv  %o2, %o1, %o2
a00ef624:  21 2a 00 ad  sethi  %hi(0xa802b400), %l0
a00ef628:  91 2a a0 10  sll  %o2, 0x10, %o0
a00ef62c:  e4 14 23 4c  lduh  [ %l0 + 0x34c ], %l2
a00ef630:  83 32 20 10  srl  %o0, 0x10, %g1
a00ef634:  23 15 55 55  sethi  %hi(0x55555400), %l1
a00ef638:  aa 20 40 19  sub  %g1, %i1, %l5
a00ef63c:  a1 2c a0 10  sll  %l2, 0x10, %l0
a00ef640:  98 14 61 56  or  %l1, 0x156, %o4
a00ef644:  80 5d 40 0c  smul  %l5, %o4, %g0
a00ef648:  9b 40 00 00  rd  %y, %o5
a00ef64c:  a9 3d 60 1f  sra  %l5, 0x1f, %l4
a00ef650:  97 34 20 10  srl  %l0, 0x10, %o3
a00ef654:  de 16 a0 02  lduh  [ %i2 + 2 ], %o7
a00ef658:  82 23 40 14  sub  %o5, %l4, %g1
a00ef65c:  ae 5b c0 0b  smul  %o7, %o3, %l7
a00ef660:  f8 16 a0 0e  lduh  [ %i2 + 0xe ], %i4
a00ef664:  97 3d e0 1f  sra  %l7, 0x1f, %o3
a00ef668:  81 82 e0 00  mov  %o3, %y
a00ef66c:  01 00 00 00  nop
a00ef670:  01 00 00 00  nop
a00ef674:  01 00 00 00  nop
a00ef678:  98 7d c0 1c  sdiv  %l7, %i4, %o4
a00ef67c:  80 a6 6a 00  cmp  %i1, 0xa00
a00ef680:  a4 10 00 01  mov  %g1, %l2
a00ef684:  08 80 00 07  bleu  0xa00ef6a0
a00ef688:  aa 10 00 01  mov  %g1, %l5
a00ef68c:  b9 28 60 10  sll  %g1, 0x10, %i4
a00ef690:  b5 37 20 10  srl  %i4, 0x10, %i2
a00ef694:  80 a6 a0 1d  cmp  %i2, 0x1d
a00ef698:  28 80 00 02  bleu,a   0xa00ef6a0
a00ef69c:  a4 10 20 1e  mov  0x1e, %l2
a00ef6a0:  af 2a a0 10  sll  %o2, 0x10, %l7
a00ef6a4:  b3 34 e0 10  srl  %l3, 0x10, %i1
a00ef6a8:  95 2c a0 10  sll  %l2, 0x10, %o2
a00ef6ac:  b5 35 e0 10  srl  %l7, 0x10, %i2
a00ef6b0:  a5 32 a0 10  srl  %o2, 0x10, %l2
a00ef6b4:  90 26 80 19  sub  %i2, %i1, %o0
a00ef6b8:  82 22 00 12  sub  %o0, %l2, %g1
a00ef6bc:  b9 2b 20 10  sll  %o4, 0x10, %i4
a00ef6c0:  a3 38 60 01  sra  %g1, 1, %l1
a00ef6c4:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef6c8:  92 10 20 5b  mov  0x5b, %o1
a00ef6cc:  40 00 0b 6f  call  0xa00f2488
a00ef6d0:  95 37 20 10  srl  %i4, 0x10, %o2
a00ef6d4:  a1 34 20 10  srl  %l0, 0x10, %l0
a00ef6d8:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef6dc:  92 10 20 64  mov  0x64, %o1
a00ef6e0:  40 00 0b 6a  call  0xa00f2488
a00ef6e4:  94 10 00 10  mov  %l0, %o2
a00ef6e8:  94 10 00 10  mov  %l0, %o2
a00ef6ec:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef6f0:  40 00 0b 66  call  0xa00f2488
a00ef6f4:  92 10 20 71  mov  0x71, %o1
a00ef6f8:  99 2d 60 10  sll  %l5, 0x10, %o4
a00ef6fc:  95 33 20 10  srl  %o4, 0x10, %o2
a00ef700:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef704:  40 00 0b 61  call  0xa00f2488
a00ef708:  92 10 20 be  mov  0xbe, %o1
a00ef70c:  9a 05 40 15  add  %l5, %l5, %o5
a00ef710:  97 2b 60 10  sll  %o5, 0x10, %o3
a00ef714:  ab 32 e0 10  srl  %o3, 0x10, %l5
a00ef718:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef71c:  92 10 20 62  mov  0x62, %o1
a00ef720:  40 00 0b 5a  call  0xa00f2488
a00ef724:  94 10 00 15  mov  %l5, %o2
a00ef728:  94 10 00 15  mov  %l5, %o2
a00ef72c:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef730:  40 00 0b 56  call  0xa00f2488
a00ef734:  92 10 20 6f  mov  0x6f, %o1
a00ef738:  94 10 00 1a  mov  %i2, %o2
a00ef73c:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef740:  40 00 0b 52  call  0xa00f2488
a00ef744:  92 10 20 5e  mov  0x5e, %o1
a00ef748:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef74c:  92 10 20 68  mov  0x68, %o1
a00ef750:  40 00 0b 4e  call  0xa00f2488
a00ef754:  94 10 00 19  mov  %i1, %o2
a00ef758:  94 10 00 19  mov  %i1, %o2
a00ef75c:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef760:  40 00 0b 4a  call  0xa00f2488
a00ef764:  92 10 20 75  mov  0x75, %o1
a00ef768:  94 10 00 12  mov  %l2, %o2
a00ef76c:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef770:  40 00 0b 46  call  0xa00f2488
a00ef774:  92 10 20 a0  mov  0xa0, %o1
a00ef778:  9f 2c 60 10  sll  %l1, 0x10, %o7
a00ef77c:  a9 33 e0 10  srl  %o7, 0x10, %l4
a00ef780:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef784:  92 10 20 66  mov  0x66, %o1
a00ef788:  40 00 0b 40  call  0xa00f2488
a00ef78c:  94 10 00 14  mov  %l4, %o2
a00ef790:  94 10 00 14  mov  %l4, %o2
a00ef794:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00ef798:  40 00 0b 3c  call  0xa00f2488
a00ef79c:  92 10 20 73  mov  0x73, %o1
a00ef7a0:  a7 3d e0 10  sra  %l7, 0x10, %l3
a00ef7a4:  40 01 99 27  call  0xa0155c40
a00ef7a8:  90 10 00 13  mov  %l3, %o0
a00ef7ac:  80 a4 e0 00  cmp  %l3, 0
a00ef7b0:  16 bf fe f3  bge  0xa00ef37c
a00ef7b4:  a2 10 00 08  mov  %o0, %l1
a00ef7b8:  29 00 06 68  sethi  %hi(0x19a000), %l4
a00ef7bc:  40 01 97 f4  call  0xa015578c
a00ef7c0:  d2 05 22 d0  ld  [ %l4 + 0x2d0 ], %o1	! 0x19a2d0
a00ef7c4:  10 bf fe ee  b  0xa00ef37c
a00ef7c8:  a2 10 00 08  mov  %o0, %l1
a00ef7cc:  92 10 00 11  mov  %l1, %o1
a00ef7d0:  7f ff be 68  call  0xa00df170
a00ef7d4:  21 07 27 0d  sethi  %hi(0x1c9c3400), %l0
a00ef7d8:  b0 14 23 ff  or  %l0, 0x3ff, %i0	! 0x1c9c37ff
a00ef7dc:  80 a4 40 18  cmp  %l1, %i0
a00ef7e0:  18 80 01 88  bgu  0xa00efe00
a00ef7e4:  15 0e 4e 1b  sethi  %hi(0x39386c00), %o2
a00ef7e8:  80 a4 60 00  cmp  %l1, 0
a00ef7ec:  06 80 02 3f  bl  0xa00f00e8
a00ef7f0:  9e 0c 60 01  and  %l1, 1, %o7
a00ef7f4:  40 01 99 13  call  0xa0155c40
a00ef7f8:  90 10 00 11  mov  %l1, %o0
a00ef7fc:  17 13 79 38  sethi  %hi(0x4de4e000), %o3
a00ef800:  92 10 00 08  mov  %o0, %o1
a00ef804:  40 01 98 85  call  0xa0155a18
a00ef808:  90 12 e1 c0  or  %o3, 0x1c0, %o0
a00ef80c:  40 01 99 61  call  0xa0155d90
a00ef810:  b2 10 00 08  mov  %o0, %i1
a00ef814:  98 10 00 09  mov  %o1, %o4
a00ef818:  96 10 00 08  mov  %o0, %o3
a00ef81c:  2b 00 06 68  sethi  %hi(0x19a000), %l5
a00ef820:  94 10 00 11  mov  %l1, %o2
a00ef824:  13 07 27 0e  sethi  %hi(0x1c9c3800), %o1
a00ef828:  7f ff be 52  call  0xa00df170
a00ef82c:  90 15 60 60  or  %l5, 0x60, %o0
a00ef830:  35 00 06 68  sethi  %hi(0x19a000), %i2
a00ef834:  d2 06 a2 d4  ld  [ %i2 + 0x2d4 ], %o1	! 0x19a2d4
a00ef838:  40 01 97 fe  call  0xa0155830
a00ef83c:  90 10 00 19  mov  %i1, %o0
a00ef840:  40 01 96 5f  call  0xa01551bc
a00ef844:  23 00 06 68  sethi  %hi(0x19a000), %l1
a00ef848:  a0 10 00 08  mov  %o0, %l0
a00ef84c:  90 14 60 88  or  %l1, 0x88, %o0
a00ef850:  7f ff be 48  call  0xa00df170
a00ef854:  92 10 00 10  mov  %l0, %o1
a00ef858:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00ef85c:  80 a3 20 08  cmp  %o4, 8
a00ef860:  02 80 01 6e  be  0xa00efe18
a00ef864:  80 a3 20 03  cmp  %o4, 3
a00ef868:  18 80 00 10  bgu  0xa00ef8a8
a00ef86c:  80 a3 20 08  cmp  %o4, 8
a00ef870:  27 00 06 67  sethi  %hi(0x199c00), %l3
a00ef874:  b0 03 00 0c  add  %o4, %o4, %i0
a00ef878:  82 14 e3 fc  or  %l3, 0x3fc, %g1
a00ef87c:  da 10 40 18  lduh  [ %g1 + %i0 ], %o5
a00ef880:  96 03 60 07  add  %o5, 7, %o3
a00ef884:  b5 2a e0 02  sll  %o3, 2, %i2
a00ef888:  2b 33 c0 00  sethi  %hi(0xcf000000), %l5
a00ef88c:  94 16 80 15  or  %i2, %l5, %o2
a00ef890:  f2 02 80 00  ld  [ %o2 ], %i1
a00ef894:  a2 16 7f 80  or  %i1, -128, %l1
a00ef898:  92 0c 60 ff  and  %l1, 0xff, %o1
a00ef89c:  d2 22 80 00  st  %o1, [ %o2 ]
a00ef8a0:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00ef8a4:  80 a3 20 08  cmp  %o4, 8
a00ef8a8:  02 80 01 f7  be  0xa00f0084
a00ef8ac:  80 a3 20 03  cmp  %o4, 3
a00ef8b0:  38 80 00 0d  bgu,a   0xa00ef8e4
a00ef8b4:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00ef8b8:  27 00 06 67  sethi  %hi(0x199c00), %l3
a00ef8bc:  b0 03 00 0c  add  %o4, %o4, %i0
a00ef8c0:  82 14 e3 fc  or  %l3, 0x3fc, %g1
a00ef8c4:  da 10 40 18  lduh  [ %g1 + %i0 ], %o5
a00ef8c8:  aa 03 60 04  add  %o5, 4, %l5
a00ef8cc:  93 2d 60 02  sll  %l5, 2, %o1
a00ef8d0:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a00ef8d4:  94 12 40 1a  or  %o1, %i2, %o2
a00ef8d8:  98 0c 20 ff  and  %l0, 0xff, %o4
a00ef8dc:  d8 22 80 00  st  %o4, [ %o2 ]
a00ef8e0:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00ef8e4:  80 a3 20 08  cmp  %o4, 8
a00ef8e8:  02 80 01 d4  be  0xa00f0038
a00ef8ec:  97 34 20 08  srl  %l0, 8, %o3
a00ef8f0:  80 a3 20 03  cmp  %o4, 3
a00ef8f4:  38 80 00 0d  bgu,a   0xa00ef928
a00ef8f8:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00ef8fc:  03 00 06 67  sethi  %hi(0x199c00), %g1
a00ef900:  9a 03 00 0c  add  %o4, %o4, %o5
a00ef904:  b0 10 63 fc  or  %g1, 0x3fc, %i0
a00ef908:  ea 16 00 0d  lduh  [ %i0 + %o5 ], %l5
a00ef90c:  b4 05 60 05  add  %l5, 5, %i2
a00ef910:  99 2e a0 02  sll  %i2, 2, %o4
a00ef914:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a00ef918:  b2 13 00 09  or  %o4, %o1, %i1
a00ef91c:  94 0a e0 ff  and  %o3, 0xff, %o2
a00ef920:  d4 26 40 00  st  %o2, [ %i1 ]
a00ef924:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00ef928:  80 a3 20 08  cmp  %o4, 8
a00ef92c:  02 80 01 b0  be  0xa00effec
a00ef930:  97 34 20 10  srl  %l0, 0x10, %o3
a00ef934:  80 a3 20 03  cmp  %o4, 3
a00ef938:  38 80 00 0d  bgu,a   0xa00ef96c
a00ef93c:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00ef940:  03 00 06 67  sethi  %hi(0x199c00), %g1
a00ef944:  9a 03 00 0c  add  %o4, %o4, %o5
a00ef948:  b0 10 63 fc  or  %g1, 0x3fc, %i0
a00ef94c:  ea 16 00 0d  lduh  [ %i0 + %o5 ], %l5
a00ef950:  b4 05 60 06  add  %l5, 6, %i2
a00ef954:  99 2e a0 02  sll  %i2, 2, %o4
a00ef958:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a00ef95c:  b2 13 00 09  or  %o4, %o1, %i1
a00ef960:  94 0a e0 ff  and  %o3, 0xff, %o2
a00ef964:  d4 26 40 00  st  %o2, [ %i1 ]
a00ef968:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00ef96c:  80 a3 20 08  cmp  %o4, 8
a00ef970:  02 80 01 8c  be  0xa00effa0
a00ef974:  97 34 20 18  srl  %l0, 0x18, %o3
a00ef978:  80 a3 20 03  cmp  %o4, 3
a00ef97c:  38 80 00 0d  bgu,a   0xa00ef9b0
a00ef980:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00ef984:  31 00 06 67  sethi  %hi(0x199c00), %i0
a00ef988:  aa 03 00 0c  add  %o4, %o4, %l5
a00ef98c:  9a 16 23 fc  or  %i0, 0x3fc, %o5
a00ef990:  f4 13 40 15  lduh  [ %o5 + %l5 ], %i2
a00ef994:  92 06 a0 07  add  %i2, 7, %o1
a00ef998:  95 2a 60 02  sll  %o1, 2, %o2
a00ef99c:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a00ef9a0:  a2 12 80 0c  or  %o2, %o4, %l1
a00ef9a4:  b2 0a e0 ff  and  %o3, 0xff, %i1
a00ef9a8:  f2 24 40 00  st  %i1, [ %l1 ]
a00ef9ac:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00ef9b0:  80 a3 20 08  cmp  %o4, 8
a00ef9b4:  02 80 01 67  be  0xa00eff50
a00ef9b8:  80 a3 20 03  cmp  %o4, 3
a00ef9bc:  18 80 00 0e  bgu  0xa00ef9f4
a00ef9c0:  a7 37 20 10  srl  %i4, 0x10, %l3
a00ef9c4:  17 00 06 67  sethi  %hi(0x199c00), %o3
a00ef9c8:  9a 03 00 0c  add  %o4, %o4, %o5
a00ef9cc:  b0 12 e3 fc  or  %o3, 0x3fc, %i0
a00ef9d0:  ea 16 00 0d  lduh  [ %i0 + %o5 ], %l5
a00ef9d4:  b4 05 60 07  add  %l5, 7, %i2
a00ef9d8:  93 2e a0 02  sll  %i2, 2, %o1
a00ef9dc:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a00ef9e0:  a2 12 40 0c  or  %o1, %o4, %l1
a00ef9e4:  d4 04 40 00  ld  [ %l1 ], %o2
a00ef9e8:  b2 0a a0 7f  and  %o2, 0x7f, %i1
a00ef9ec:  f2 24 40 00  st  %i1, [ %l1 ]
a00ef9f0:  a7 37 20 10  srl  %i4, 0x10, %l3
a00ef9f4:  83 35 e0 10  srl  %l7, 0x10, %g1
a00ef9f8:  a0 58 40 13  smul  %g1, %l3, %l0
a00ef9fc:  81 80 00 00  mov  %g0, %y
a00efa00:  01 00 00 00  nop
a00efa04:  01 00 00 00  nop
a00efa08:  01 00 00 00  nop
a00efa0c:  b8 74 00 14  udiv  %l0, %l4, %i4
a00efa10:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efa14:  80 a3 20 08  cmp  %o4, 8
a00efa18:  02 80 01 3b  be  0xa00eff04
a00efa1c:  94 07 3f ff  add  %i4, -1, %o2
a00efa20:  80 a3 20 03  cmp  %o4, 3
a00efa24:  18 80 00 0e  bgu  0xa00efa5c
a00efa28:  80 a3 20 08  cmp  %o4, 8
a00efa2c:  03 00 06 67  sethi  %hi(0x199c00), %g1
a00efa30:  b8 03 00 0c  add  %o4, %o4, %i4
a00efa34:  a0 10 63 fc  or  %g1, 0x3fc, %l0
a00efa38:  f0 14 00 1c  lduh  [ %l0 + %i4 ], %i0
a00efa3c:  9a 06 20 01  add  %i0, 1, %o5
a00efa40:  99 2b 60 02  sll  %o5, 2, %o4
a00efa44:  2b 33 c0 00  sethi  %hi(0xcf000000), %l5
a00efa48:  90 13 00 15  or  %o4, %l5, %o0
a00efa4c:  92 0a a0 ff  and  %o2, 0xff, %o1
a00efa50:  d2 22 00 00  st  %o1, [ %o0 ]
a00efa54:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efa58:  80 a3 20 08  cmp  %o4, 8
a00efa5c:  02 80 01 17  be  0xa00efeb8
a00efa60:  97 32 a0 08  srl  %o2, 8, %o3
a00efa64:  80 a3 20 03  cmp  %o4, 3
a00efa68:  38 80 00 0d  bgu,a   0xa00efa9c
a00efa6c:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efa70:  39 00 06 67  sethi  %hi(0x199c00), %i4
a00efa74:  9a 03 00 0c  add  %o4, %o4, %o5
a00efa78:  b0 17 23 fc  or  %i4, 0x3fc, %i0
a00efa7c:  ea 16 00 0d  lduh  [ %i0 + %o5 ], %l5
a00efa80:  98 05 60 02  add  %l5, 2, %o4
a00efa84:  91 2b 20 02  sll  %o4, 2, %o0
a00efa88:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a00efa8c:  b2 12 00 09  or  %o0, %o1, %i1
a00efa90:  b4 0a e0 ff  and  %o3, 0xff, %i2
a00efa94:  f4 26 40 00  st  %i2, [ %i1 ]
a00efa98:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efa9c:  80 a3 20 08  cmp  %o4, 8
a00efaa0:  02 80 00 f3  be  0xa00efe6c
a00efaa4:  97 32 a0 10  srl  %o2, 0x10, %o3
a00efaa8:  80 a3 20 03  cmp  %o4, 3
a00efaac:  38 80 00 0d  bgu,a   0xa00efae0
a00efab0:  96 10 20 00  clr  %o3
a00efab4:  31 00 06 67  sethi  %hi(0x199c00), %i0
a00efab8:  98 03 00 0c  add  %o4, %o4, %o4
a00efabc:  9a 16 23 fc  or  %i0, 0x3fc, %o5
a00efac0:  ea 13 40 0c  lduh  [ %o5 + %o4 ], %l5
a00efac4:  92 05 60 03  add  %l5, 3, %o1
a00efac8:  b5 2a 60 02  sll  %o1, 2, %i2
a00efacc:  11 33 c0 00  sethi  %hi(0xcf000000), %o0
a00efad0:  a2 16 80 08  or  %i2, %o0, %l1
a00efad4:  b2 0a e0 ff  and  %o3, 0xff, %i1
a00efad8:  f2 24 40 00  st  %i1, [ %l1 ]
a00efadc:  96 10 20 00  clr  %o3
a00efae0:  82 10 20 00  clr  %g1
a00efae4:  98 07 bf f8  add  %fp, -8, %o4
a00efae8:  83 28 60 02  sll  %g1, 2, %g1
a00efaec:  a0 00 40 0c  add  %g1, %o4, %l0
a00efaf0:  f8 04 3f b8  ld  [ %l0 + -72 ], %i4
a00efaf4:  80 a7 00 0a  cmp  %i4, %o2
a00efaf8:  38 80 00 08  bgu,a   0xa00efb18
a00efafc:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efb00:  96 02 e0 01  inc  %o3
a00efb04:  82 0a e0 ff  and  %o3, 0xff, %g1
a00efb08:  80 a0 60 10  cmp  %g1, 0x10
a00efb0c:  28 bf ff f8  bleu,a   0xa00efaec
a00efb10:  83 28 60 02  sll  %g1, 2, %g1
a00efb14:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efb18:  80 a3 20 08  cmp  %o4, 8
a00efb1c:  02 80 01 b7  be  0xa00f01f8
a00efb20:  96 02 e0 0a  add  %o3, 0xa, %o3
a00efb24:  80 a3 20 03  cmp  %o4, 3
a00efb28:  38 80 00 0c  bgu,a   0xa00efb58
a00efb2c:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efb30:  31 00 06 67  sethi  %hi(0x199c00), %i0
a00efb34:  aa 03 00 0c  add  %o4, %o4, %l5
a00efb38:  9a 16 23 fc  or  %i0, 0x3fc, %o5
a00efb3c:  d2 13 40 15  lduh  [ %o5 + %l5 ], %o1
a00efb40:  b5 2a 60 02  sll  %o1, 2, %i2
a00efb44:  11 33 c0 00  sethi  %hi(0xcf000000), %o0
a00efb48:  a2 16 80 08  or  %i2, %o0, %l1
a00efb4c:  b2 0a e0 ff  and  %o3, 0xff, %i1
a00efb50:  f2 24 40 00  st  %i1, [ %l1 ]
a00efb54:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efb58:  80 a3 20 08  cmp  %o4, 8
a00efb5c:  02 80 01 94  be  0xa00f01ac
a00efb60:  80 a3 20 03  cmp  %o4, 3
a00efb64:  38 80 00 0d  bgu,a   0xa00efb98
a00efb68:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efb6c:  13 00 06 67  sethi  %hi(0x199c00), %o1
a00efb70:  b4 03 00 0c  add  %o4, %o4, %i2
a00efb74:  90 12 63 fc  or  %o1, 0x3fc, %o0
a00efb78:  f2 12 00 1a  lduh  [ %o0 + %i2 ], %i1
a00efb7c:  a2 06 60 10  add  %i1, 0x10, %l1
a00efb80:  9f 2c 60 02  sll  %l1, 2, %o7
a00efb84:  25 33 c0 00  sethi  %hi(0xcf000000), %l2
a00efb88:  94 13 c0 12  or  %o7, %l2, %o2
a00efb8c:  98 10 20 98  mov  0x98, %o4
a00efb90:  d8 22 80 00  st  %o4, [ %o2 ]
a00efb94:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efb98:  80 a3 20 08  cmp  %o4, 8
a00efb9c:  02 80 01 e4  be  0xa00f032c
a00efba0:  80 a3 20 03  cmp  %o4, 3
a00efba4:  18 80 00 0d  bgu  0xa00efbd8
a00efba8:  80 a5 20 08  cmp  %l4, 8
a00efbac:  33 00 06 67  sethi  %hi(0x199c00), %i1
a00efbb0:  a4 03 00 0c  add  %o4, %o4, %l2
a00efbb4:  a2 16 63 fc  or  %i1, 0x3fc, %l1
a00efbb8:  de 14 40 12  lduh  [ %l1 + %l2 ], %o7
a00efbbc:  98 03 e0 0f  add  %o7, 0xf, %o4
a00efbc0:  b7 2b 20 02  sll  %o4, 2, %i3
a00efbc4:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00efbc8:  96 16 c0 0a  or  %i3, %o2, %o3
a00efbcc:  a6 10 20 08  mov  8, %l3
a00efbd0:  e6 22 c0 00  st  %l3, [ %o3 ]
a00efbd4:  80 a5 20 08  cmp  %l4, 8
a00efbd8:  02 80 00 03  be  0xa00efbe4
a00efbdc:  95 35 e0 15  srl  %l7, 0x15, %o2
a00efbe0:  95 35 e0 12  srl  %l7, 0x12, %o2
a00efbe4:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efbe8:  80 a3 20 08  cmp  %o4, 8
a00efbec:  02 80 01 bd  be  0xa00f02e0
a00efbf0:  80 a3 20 03  cmp  %o4, 3
a00efbf4:  18 80 00 0e  bgu  0xa00efc2c
a00efbf8:  96 0a af 00  and  %o2, 0xf00, %o3
a00efbfc:  25 00 06 67  sethi  %hi(0x199c00), %l2
a00efc00:  b6 03 00 0c  add  %o4, %o4, %i3
a00efc04:  9e 14 a3 fc  or  %l2, 0x3fc, %o7
a00efc08:  e6 13 c0 1b  lduh  [ %o7 + %i3 ], %l3
a00efc0c:  82 04 e0 0e  add  %l3, 0xe, %g1
a00efc10:  b9 28 60 02  sll  %g1, 2, %i4
a00efc14:  21 33 c0 00  sethi  %hi(0xcf000000), %l0
a00efc18:  90 17 00 10  or  %i4, %l0, %o0
a00efc1c:  92 0a a0 ff  and  %o2, 0xff, %o1
a00efc20:  d2 22 00 00  st  %o1, [ %o0 ]
a00efc24:  96 0a af 00  and  %o2, 0xf00, %o3
a00efc28:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efc2c:  80 a3 20 08  cmp  %o4, 8
a00efc30:  02 80 01 97  be  0xa00f028c
a00efc34:  95 32 e0 04  srl  %o3, 4, %o2
a00efc38:  80 a3 20 03  cmp  %o4, 3
a00efc3c:  38 80 00 0f  bgu,a   0xa00efc78
a00efc40:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efc44:  17 00 06 67  sethi  %hi(0x199c00), %o3
a00efc48:  9e 03 00 0c  add  %o4, %o4, %o7
a00efc4c:  a4 12 e3 fc  or  %o3, 0x3fc, %l2
a00efc50:  f6 14 80 0f  lduh  [ %l2 + %o7 ], %i3
a00efc54:  a6 06 e0 0f  add  %i3, 0xf, %l3
a00efc58:  a1 2c e0 02  sll  %l3, 2, %l0
a00efc5c:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00efc60:  90 14 00 01  or  %l0, %g1, %o0
a00efc64:  f8 02 00 00  ld  [ %o0 ], %i4
a00efc68:  92 17 00 0a  or  %i4, %o2, %o1
a00efc6c:  94 0a 60 ff  and  %o1, 0xff, %o2
a00efc70:  d4 22 00 00  st  %o2, [ %o0 ]
a00efc74:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efc78:  80 a3 20 08  cmp  %o4, 8
a00efc7c:  02 80 01 71  be  0xa00f0240
a00efc80:  80 a3 20 03  cmp  %o4, 3
a00efc84:  38 80 00 0d  bgu,a   0xa00efcb8
a00efc88:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efc8c:  03 00 06 67  sethi  %hi(0x199c00), %g1
a00efc90:  b8 03 00 0c  add  %o4, %o4, %i4
a00efc94:  a0 10 63 fc  or  %g1, 0x3fc, %l0
a00efc98:  d2 14 00 1c  lduh  [ %l0 + %i4 ], %o1
a00efc9c:  94 02 60 11  add  %o1, 0x11, %o2
a00efca0:  9b 2a a0 02  sll  %o2, 2, %o5
a00efca4:  11 33 c0 00  sethi  %hi(0xcf000000), %o0
a00efca8:  aa 13 40 08  or  %o5, %o0, %l5
a00efcac:  b0 10 20 06  mov  6, %i0
a00efcb0:  f0 25 40 00  st  %i0, [ %l5 ]
a00efcb4:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efcb8:  80 a3 20 08  cmp  %o4, 8
a00efcbc:  02 80 01 27  be  0xa00f0158
a00efcc0:  80 a3 20 03  cmp  %o4, 3
a00efcc4:  38 80 00 0f  bgu,a   0xa00efd00
a00efcc8:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efccc:  03 00 06 67  sethi  %hi(0x199c00), %g1
a00efcd0:  b8 03 00 0c  add  %o4, %o4, %i4
a00efcd4:  a0 10 63 fc  or  %g1, 0x3fc, %l0
a00efcd8:  d2 14 00 1c  lduh  [ %l0 + %i4 ], %o1
a00efcdc:  94 02 60 16  add  %o1, 0x16, %o2
a00efce0:  9b 2a a0 02  sll  %o2, 2, %o5
a00efce4:  11 33 c0 00  sethi  %hi(0xcf000000), %o0
a00efce8:  96 13 40 08  or  %o5, %o0, %o3
a00efcec:  f0 02 c0 00  ld  [ %o3 ], %i0
a00efcf0:  aa 16 20 0c  or  %i0, 0xc, %l5
a00efcf4:  b4 0d 60 ff  and  %l5, 0xff, %i2
a00efcf8:  f4 22 c0 00  st  %i2, [ %o3 ]
a00efcfc:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efd00:  80 a3 20 08  cmp  %o4, 8
a00efd04:  02 80 01 01  be  0xa00f0108
a00efd08:  80 a3 20 03  cmp  %o4, 3
a00efd0c:  18 80 00 0e  bgu  0xa00efd44
a00efd10:  39 2a 00 ad  sethi  %hi(0xa802b400), %i4
a00efd14:  13 00 06 67  sethi  %hi(0x199c00), %o1
a00efd18:  90 03 00 0c  add  %o4, %o4, %o0
a00efd1c:  94 12 63 fc  or  %o1, 0x3fc, %o2
a00efd20:  da 12 80 08  lduh  [ %o2 + %o0 ], %o5
a00efd24:  ab 2b 60 02  sll  %o5, 2, %l5
a00efd28:  31 33 c0 00  sethi  %hi(0xcf000000), %i0
a00efd2c:  ae 15 40 18  or  %l5, %i0, %l7
a00efd30:  f4 05 c0 00  ld  [ %l7 ], %i2
a00efd34:  96 16 a0 20  or  %i2, 0x20, %o3
a00efd38:  a8 0a e0 ff  and  %o3, 0xff, %l4
a00efd3c:  e8 25 c0 00  st  %l4, [ %l7 ]
a00efd40:  39 2a 00 ad  sethi  %hi(0xa802b400), %i4
a00efd44:  c0 2f 23 47  clrb  [ %i4 + 0x347 ]	! 0xa802b747
a00efd48:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00efd4c:  92 10 20 8e  mov  0x8e, %o1
a00efd50:  40 00 09 52  call  0xa00f2298
a00efd54:  94 10 20 03  mov  3, %o2
a00efd58:  30 80 01 88  b,a   0xa00f0378
a00efd5c:  17 00 06 67  sethi  %hi(0x199c00), %o3
a00efd60:  92 12 e3 fc  or  %o3, 0x3fc, %o1	! 0x199ffc
a00efd64:  98 10 20 00  clr  %o4
a00efd68:  9a 10 20 00  clr  %o5
a00efd6c:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00efd70:  96 10 20 16  mov  0x16, %o3
a00efd74:  a2 03 40 0d  add  %o5, %o5, %l1
a00efd78:  e0 12 40 11  lduh  [ %o1 + %l1 ], %l0
a00efd7c:  9b 2c 20 02  sll  %l0, 2, %o5
a00efd80:  9e 13 40 0a  or  %o5, %o2, %o7
a00efd84:  98 03 20 01  inc  %o4
a00efd88:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00efd8c:  d6 23 c0 00  st  %o3, [ %o7 ]
a00efd90:  80 a3 60 03  cmp  %o5, 3
a00efd94:  08 bf ff f9  bleu  0xa00efd78
a00efd98:  a2 03 40 0d  add  %o5, %o5, %l1
a00efd9c:  10 bf fd 21  b  0xa00ef220
a00efda0:  d0 0d a2 79  ldub  [ %l6 + 0x279 ], %o0
a00efda4:  99 34 20 01  srl  %l0, 1, %o4
a00efda8:  82 0c 20 01  and  %l0, 1, %g1
a00efdac:  40 01 97 a5  call  0xa0155c40
a00efdb0:  90 10 40 0c  or  %g1, %o4, %o0
a00efdb4:  40 01 96 76  call  0xa015578c
a00efdb8:  92 10 00 08  mov  %o0, %o1
a00efdbc:  10 bf fd e8  b  0xa00ef55c
a00efdc0:  92 10 00 08  mov  %o0, %o1
a00efdc4:  97 34 60 01  srl  %l1, 1, %o3
a00efdc8:  9a 0c 60 01  and  %l1, 1, %o5
a00efdcc:  40 01 97 9d  call  0xa0155c40
a00efdd0:  90 13 40 0b  or  %o5, %o3, %o0
a00efdd4:  40 01 96 6e  call  0xa015578c
a00efdd8:  92 10 00 08  mov  %o0, %o1
a00efddc:  10 bf fd db  b  0xa00ef548
a00efde0:  80 a4 20 00  cmp  %l0, 0
a00efde4:  aa 0c e0 01  and  %l3, 1, %l5
a00efde8:  40 01 97 96  call  0xa0155c40
a00efdec:  90 15 40 1a  or  %l5, %i2, %o0
a00efdf0:  40 01 96 67  call  0xa015578c
a00efdf4:  92 10 00 08  mov  %o0, %o1
a00efdf8:  10 bf fd cf  b  0xa00ef534
a00efdfc:  80 a4 60 00  cmp  %l1, 0
a00efe00:  90 12 a3 ff  or  %o2, 0x3ff, %o0
a00efe04:  80 a4 40 08  cmp  %l1, %o0
a00efe08:  18 80 00 b2  bgu  0xa00f00d0
a00efe0c:  13 1c 9c 37  sethi  %hi(0x7270dc00), %o1
a00efe10:  10 bf fe 76  b  0xa00ef7e8
a00efe14:  a3 34 60 01  srl  %l1, 1, %l1
a00efe18:  1b 00 06 67  sethi  %hi(0x199c00), %o5
a00efe1c:  92 13 63 fc  or  %o5, 0x3fc, %o1	! 0x199ffc
a00efe20:  96 10 20 00  clr  %o3
a00efe24:  98 10 20 00  clr  %o4
a00efe28:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00efe2c:  a4 03 00 0c  add  %o4, %o4, %l2
a00efe30:  de 12 40 12  lduh  [ %o1 + %l2 ], %o7
a00efe34:  b6 03 e0 07  add  %o7, 7, %i3
a00efe38:  91 2e e0 02  sll  %i3, 2, %o0
a00efe3c:  b0 12 00 0a  or  %o0, %o2, %i0
a00efe40:  e6 06 00 00  ld  [ %i0 ], %l3
a00efe44:  98 14 ff 80  or  %l3, -128, %o4
a00efe48:  82 0b 20 ff  and  %o4, 0xff, %g1
a00efe4c:  96 02 e0 01  inc  %o3
a00efe50:  98 0a e0 ff  and  %o3, 0xff, %o4
a00efe54:  c2 26 00 00  st  %g1, [ %i0 ]
a00efe58:  80 a3 20 03  cmp  %o4, 3
a00efe5c:  08 bf ff f5  bleu  0xa00efe30
a00efe60:  a4 03 00 0c  add  %o4, %o4, %l2
a00efe64:  10 bf fe 90  b  0xa00ef8a4
a00efe68:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00efe6c:  98 0a e0 ff  and  %o3, 0xff, %o4
a00efe70:  21 00 06 67  sethi  %hi(0x199c00), %l0
a00efe74:  90 14 23 fc  or  %l0, 0x3fc, %o0	! 0x199ffc
a00efe78:  96 10 20 00  clr  %o3
a00efe7c:  9a 10 20 00  clr  %o5
a00efe80:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a00efe84:  a4 03 40 0d  add  %o5, %o5, %l2
a00efe88:  de 12 00 12  lduh  [ %o0 + %l2 ], %o7
a00efe8c:  b6 03 e0 03  add  %o7, 3, %i3
a00efe90:  a7 2e e0 02  sll  %i3, 2, %l3
a00efe94:  96 02 e0 01  inc  %o3
a00efe98:  82 14 c0 09  or  %l3, %o1, %g1
a00efe9c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00efea0:  d8 20 40 00  st  %o4, [ %g1 ]
a00efea4:  80 a3 60 03  cmp  %o5, 3
a00efea8:  08 bf ff f8  bleu  0xa00efe88
a00efeac:  a4 03 40 0d  add  %o5, %o5, %l2
a00efeb0:  10 bf ff 0c  b  0xa00efae0
a00efeb4:  96 10 20 00  clr  %o3
a00efeb8:  98 0a e0 ff  and  %o3, 0xff, %o4
a00efebc:  17 00 06 67  sethi  %hi(0x199c00), %o3
a00efec0:  90 12 e3 fc  or  %o3, 0x3fc, %o0	! 0x199ffc
a00efec4:  96 10 20 00  clr  %o3
a00efec8:  9a 10 20 00  clr  %o5
a00efecc:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a00efed0:  a2 03 40 0d  add  %o5, %o5, %l1
a00efed4:  e4 12 00 11  lduh  [ %o0 + %l1 ], %l2
a00efed8:  9e 04 a0 02  add  %l2, 2, %o7
a00efedc:  b7 2b e0 02  sll  %o7, 2, %i3
a00efee0:  96 02 e0 01  inc  %o3
a00efee4:  a6 16 c0 09  or  %i3, %o1, %l3
a00efee8:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00efeec:  d8 24 c0 00  st  %o4, [ %l3 ]
a00efef0:  80 a3 60 03  cmp  %o5, 3
a00efef4:  08 bf ff f8  bleu  0xa00efed4
a00efef8:  a2 03 40 0d  add  %o5, %o5, %l1
a00efefc:  10 bf fe e8  b  0xa00efa9c
a00eff00:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00eff04:  37 00 06 67  sethi  %hi(0x199c00), %i3
a00eff08:  98 0a a0 ff  and  %o2, 0xff, %o4
a00eff0c:  90 16 e3 fc  or  %i3, 0x3fc, %o0
a00eff10:  96 10 20 00  clr  %o3
a00eff14:  9a 10 20 00  clr  %o5
a00eff18:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a00eff1c:  b4 03 40 0d  add  %o5, %o5, %i2
a00eff20:  f2 12 00 1a  lduh  [ %o0 + %i2 ], %i1
a00eff24:  a2 06 60 01  add  %i1, 1, %l1
a00eff28:  a5 2c 60 02  sll  %l1, 2, %l2
a00eff2c:  96 02 e0 01  inc  %o3
a00eff30:  9e 14 80 09  or  %l2, %o1, %o7
a00eff34:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00eff38:  d8 23 c0 00  st  %o4, [ %o7 ]
a00eff3c:  80 a3 60 03  cmp  %o5, 3
a00eff40:  08 bf ff f8  bleu  0xa00eff20
a00eff44:  b4 03 40 0d  add  %o5, %o5, %i2
a00eff48:  10 bf fe c4  b  0xa00efa58
a00eff4c:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00eff50:  17 00 06 67  sethi  %hi(0x199c00), %o3
a00eff54:  92 12 e3 fc  or  %o3, 0x3fc, %o1	! 0x199ffc
a00eff58:  96 10 20 00  clr  %o3
a00eff5c:  98 10 20 00  clr  %o4
a00eff60:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00eff64:  a4 03 00 0c  add  %o4, %o4, %l2
a00eff68:  de 12 40 12  lduh  [ %o1 + %l2 ], %o7
a00eff6c:  b6 03 e0 07  add  %o7, 7, %i3
a00eff70:  91 2e e0 02  sll  %i3, 2, %o0
a00eff74:  a0 12 00 0a  or  %o0, %o2, %l0
a00eff78:  e6 04 00 00  ld  [ %l0 ], %l3
a00eff7c:  96 02 e0 01  inc  %o3
a00eff80:  82 0c e0 7f  and  %l3, 0x7f, %g1
a00eff84:  98 0a e0 ff  and  %o3, 0xff, %o4
a00eff88:  c2 24 00 00  st  %g1, [ %l0 ]
a00eff8c:  80 a3 20 03  cmp  %o4, 3
a00eff90:  08 bf ff f6  bleu  0xa00eff68
a00eff94:  a4 03 00 0c  add  %o4, %o4, %l2
a00eff98:  10 bf fe 97  b  0xa00ef9f4
a00eff9c:  a7 37 20 10  srl  %i4, 0x10, %l3
a00effa0:  98 0a e0 ff  and  %o3, 0xff, %o4
a00effa4:  21 00 06 67  sethi  %hi(0x199c00), %l0
a00effa8:  92 14 23 fc  or  %l0, 0x3fc, %o1	! 0x199ffc
a00effac:  96 10 20 00  clr  %o3
a00effb0:  9a 10 20 00  clr  %o5
a00effb4:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00effb8:  a4 03 40 0d  add  %o5, %o5, %l2
a00effbc:  de 12 40 12  lduh  [ %o1 + %l2 ], %o7
a00effc0:  b6 03 e0 07  add  %o7, 7, %i3
a00effc4:  91 2e e0 02  sll  %i3, 2, %o0
a00effc8:  96 02 e0 01  inc  %o3
a00effcc:  a6 12 00 0a  or  %o0, %o2, %l3
a00effd0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00effd4:  d8 24 c0 00  st  %o4, [ %l3 ]
a00effd8:  80 a3 60 03  cmp  %o5, 3
a00effdc:  08 bf ff f8  bleu  0xa00effbc
a00effe0:  a4 03 40 0d  add  %o5, %o5, %l2
a00effe4:  10 bf fe 73  b  0xa00ef9b0
a00effe8:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00effec:  98 0a e0 ff  and  %o3, 0xff, %o4
a00efff0:  27 00 06 67  sethi  %hi(0x199c00), %l3
a00efff4:  92 14 e3 fc  or  %l3, 0x3fc, %o1	! 0x199ffc
a00efff8:  96 10 20 00  clr  %o3
a00efffc:  9a 10 20 00  clr  %o5
a00f0000:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00f0004:  a2 03 40 0d  add  %o5, %o5, %l1
a00f0008:  e4 12 40 11  lduh  [ %o1 + %l1 ], %l2
a00f000c:  9e 04 a0 06  add  %l2, 6, %o7
a00f0010:  b7 2b e0 02  sll  %o7, 2, %i3
a00f0014:  96 02 e0 01  inc  %o3
a00f0018:  90 16 c0 0a  or  %i3, %o2, %o0
a00f001c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00f0020:  d8 22 00 00  st  %o4, [ %o0 ]
a00f0024:  80 a3 60 03  cmp  %o5, 3
a00f0028:  08 bf ff f8  bleu  0xa00f0008
a00f002c:  a2 03 40 0d  add  %o5, %o5, %l1
a00f0030:  10 bf fe 4f  b  0xa00ef96c
a00f0034:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00f0038:  98 0a e0 ff  and  %o3, 0xff, %o4
a00f003c:  17 00 06 67  sethi  %hi(0x199c00), %o3
a00f0040:  92 12 e3 fc  or  %o3, 0x3fc, %o1	! 0x199ffc
a00f0044:  96 10 20 00  clr  %o3
a00f0048:  9a 10 20 00  clr  %o5
a00f004c:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00f0050:  a2 03 40 0d  add  %o5, %o5, %l1
a00f0054:  e4 12 40 11  lduh  [ %o1 + %l1 ], %l2
a00f0058:  9e 04 a0 05  add  %l2, 5, %o7
a00f005c:  b7 2b e0 02  sll  %o7, 2, %i3
a00f0060:  96 02 e0 01  inc  %o3
a00f0064:  90 16 c0 0a  or  %i3, %o2, %o0
a00f0068:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00f006c:  d8 22 00 00  st  %o4, [ %o0 ]
a00f0070:  80 a3 60 03  cmp  %o5, 3
a00f0074:  08 bf ff f8  bleu  0xa00f0054
a00f0078:  a2 03 40 0d  add  %o5, %o5, %l1
a00f007c:  10 bf fe 2b  b  0xa00ef928
a00f0080:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00f0084:  11 00 06 67  sethi  %hi(0x199c00), %o0
a00f0088:  98 0c 20 ff  and  %l0, 0xff, %o4
a00f008c:  92 12 23 fc  or  %o0, 0x3fc, %o1
a00f0090:  96 10 20 00  clr  %o3
a00f0094:  9a 10 20 00  clr  %o5
a00f0098:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00f009c:  b2 03 40 0d  add  %o5, %o5, %i1
a00f00a0:  e2 12 40 19  lduh  [ %o1 + %i1 ], %l1
a00f00a4:  a4 04 60 04  add  %l1, 4, %l2
a00f00a8:  9f 2c a0 02  sll  %l2, 2, %o7
a00f00ac:  96 02 e0 01  inc  %o3
a00f00b0:  b6 13 c0 0a  or  %o7, %o2, %i3
a00f00b4:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00f00b8:  d8 26 c0 00  st  %o4, [ %i3 ]
a00f00bc:  80 a3 60 03  cmp  %o5, 3
a00f00c0:  08 bf ff f8  bleu  0xa00f00a0
a00f00c4:  b2 03 40 0d  add  %o5, %o5, %i1
a00f00c8:  10 bf fe 07  b  0xa00ef8e4
a00f00cc:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00f00d0:  b6 12 63 ff  or  %o1, 0x3ff, %i3
a00f00d4:  80 a4 40 1b  cmp  %l1, %i3
a00f00d8:  38 bf fd c4  bgu,a   0xa00ef7e8
a00f00dc:  a3 34 60 03  srl  %l1, 3, %l1
a00f00e0:  10 bf fd c2  b  0xa00ef7e8
a00f00e4:  a3 34 60 02  srl  %l1, 2, %l1
a00f00e8:  a5 34 60 01  srl  %l1, 1, %l2
a00f00ec:  90 13 c0 12  or  %o7, %l2, %o0
a00f00f0:  40 01 96 d4  call  0xa0155c40
a00f00f4:  01 00 00 00  nop
a00f00f8:  40 01 95 a5  call  0xa015578c
a00f00fc:  92 10 00 08  mov  %o0, %o1
a00f0100:  10 bf fd c0  b  0xa00ef800
a00f0104:  17 13 79 38  sethi  %hi(0x4de4e000), %o3
a00f0108:  3b 00 06 67  sethi  %hi(0x199c00), %i5
a00f010c:  92 17 63 fc  or  %i5, 0x3fc, %o1	! 0x199ffc
a00f0110:  96 10 20 00  clr  %o3
a00f0114:  98 10 20 00  clr  %o4
a00f0118:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00f011c:  b2 03 00 0c  add  %o4, %o4, %i1
a00f0120:  e2 12 40 19  lduh  [ %o1 + %i1 ], %l1
a00f0124:  99 2c 60 02  sll  %l1, 2, %o4
a00f0128:  a6 13 00 0a  or  %o4, %o2, %l3
a00f012c:  e4 04 c0 00  ld  [ %l3 ], %l2
a00f0130:  9e 14 a0 20  or  %l2, 0x20, %o7
a00f0134:  96 02 e0 01  inc  %o3
a00f0138:  b6 0b e0 ff  and  %o7, 0xff, %i3
a00f013c:  98 0a e0 ff  and  %o3, 0xff, %o4
a00f0140:  f6 24 c0 00  st  %i3, [ %l3 ]
a00f0144:  80 a3 20 03  cmp  %o4, 3
a00f0148:  28 bf ff f6  bleu,a   0xa00f0120
a00f014c:  b2 03 00 0c  add  %o4, %o4, %i1
a00f0150:  10 bf fe fd  b  0xa00efd44
a00f0154:  39 2a 00 ad  sethi  %hi(0xa802b400), %i4
a00f0158:  27 00 06 67  sethi  %hi(0x199c00), %l3
a00f015c:  92 14 e3 fc  or  %l3, 0x3fc, %o1	! 0x199ffc
a00f0160:  96 10 20 00  clr  %o3
a00f0164:  98 10 20 00  clr  %o4
a00f0168:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00f016c:  a8 03 00 0c  add  %o4, %o4, %l4
a00f0170:  ee 12 40 14  lduh  [ %o1 + %l4 ], %l7
a00f0174:  b2 05 e0 16  add  %l7, 0x16, %i1
a00f0178:  a3 2e 60 02  sll  %i1, 2, %l1
a00f017c:  b6 14 40 0a  or  %l1, %o2, %i3
a00f0180:  d8 06 c0 00  ld  [ %i3 ], %o4
a00f0184:  a4 13 20 0c  or  %o4, 0xc, %l2
a00f0188:  96 02 e0 01  inc  %o3
a00f018c:  9e 0c a0 ff  and  %l2, 0xff, %o7
a00f0190:  98 0a e0 ff  and  %o3, 0xff, %o4
a00f0194:  de 26 c0 00  st  %o7, [ %i3 ]
a00f0198:  80 a3 20 03  cmp  %o4, 3
a00f019c:  28 bf ff f5  bleu,a   0xa00f0170
a00f01a0:  a8 03 00 0c  add  %o4, %o4, %l4
a00f01a4:  10 bf fe d7  b  0xa00efd00
a00f01a8:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00f01ac:  17 00 06 67  sethi  %hi(0x199c00), %o3
a00f01b0:  92 12 e3 fc  or  %o3, 0x3fc, %o1	! 0x199ffc
a00f01b4:  98 10 20 00  clr  %o4
a00f01b8:  9a 10 20 00  clr  %o5
a00f01bc:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00f01c0:  96 10 20 98  mov  0x98, %o3
a00f01c4:  b6 03 40 0d  add  %o5, %o5, %i3
a00f01c8:  e6 12 40 1b  lduh  [ %o1 + %i3 ], %l3
a00f01cc:  82 04 e0 10  add  %l3, 0x10, %g1
a00f01d0:  a1 28 60 02  sll  %g1, 2, %l0
a00f01d4:  98 03 20 01  inc  %o4
a00f01d8:  b8 14 00 0a  or  %l0, %o2, %i4
a00f01dc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f01e0:  d6 27 00 00  st  %o3, [ %i4 ]
a00f01e4:  80 a3 60 03  cmp  %o5, 3
a00f01e8:  08 bf ff f8  bleu  0xa00f01c8
a00f01ec:  b6 03 40 0d  add  %o5, %o5, %i3
a00f01f0:  10 bf fe 6a  b  0xa00efb98
a00f01f4:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00f01f8:  15 00 06 67  sethi  %hi(0x199c00), %o2
a00f01fc:  98 0a e0 ff  and  %o3, 0xff, %o4
a00f0200:  92 12 a3 fc  or  %o2, 0x3fc, %o1
a00f0204:  96 10 20 00  clr  %o3
a00f0208:  9a 10 20 00  clr  %o5
a00f020c:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00f0210:  a4 03 40 0d  add  %o5, %o5, %l2
a00f0214:  de 12 40 12  lduh  [ %o1 + %l2 ], %o7
a00f0218:  b7 2b e0 02  sll  %o7, 2, %i3
a00f021c:  96 02 e0 01  inc  %o3
a00f0220:  a6 16 c0 0a  or  %i3, %o2, %l3
a00f0224:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00f0228:  d8 24 c0 00  st  %o4, [ %l3 ]
a00f022c:  80 a3 60 03  cmp  %o5, 3
a00f0230:  08 bf ff f9  bleu  0xa00f0214
a00f0234:  a4 03 40 0d  add  %o5, %o5, %l2
a00f0238:  10 bf fe 48  b  0xa00efb58
a00f023c:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00f0240:  19 00 06 67  sethi  %hi(0x199c00), %o4
a00f0244:  92 13 23 fc  or  %o4, 0x3fc, %o1	! 0x199ffc
a00f0248:  98 10 20 00  clr  %o4
a00f024c:  9a 10 20 00  clr  %o5
a00f0250:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00f0254:  96 10 20 06  mov  6, %o3
a00f0258:  b4 03 40 0d  add  %o5, %o5, %i2
a00f025c:  e8 12 40 1a  lduh  [ %o1 + %i2 ], %l4
a00f0260:  ae 05 20 11  add  %l4, 0x11, %l7
a00f0264:  b3 2d e0 02  sll  %l7, 2, %i1
a00f0268:  98 03 20 01  inc  %o4
a00f026c:  a2 16 40 0a  or  %i1, %o2, %l1
a00f0270:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f0274:  d6 24 40 00  st  %o3, [ %l1 ]
a00f0278:  80 a3 60 03  cmp  %o5, 3
a00f027c:  08 bf ff f8  bleu  0xa00f025c
a00f0280:  b4 03 40 0d  add  %o5, %o5, %i2
a00f0284:  10 bf fe 8d  b  0xa00efcb8
a00f0288:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00f028c:  19 00 06 67  sethi  %hi(0x199c00), %o4
a00f0290:  90 13 23 fc  or  %o4, 0x3fc, %o0	! 0x199ffc
a00f0294:  96 10 20 00  clr  %o3
a00f0298:  98 10 20 00  clr  %o4
a00f029c:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a00f02a0:  9a 03 00 0c  add  %o4, %o4, %o5
a00f02a4:  f0 12 00 0d  lduh  [ %o0 + %o5 ], %i0
a00f02a8:  aa 06 20 0f  add  %i0, 0xf, %l5
a00f02ac:  b5 2d 60 02  sll  %l5, 2, %i2
a00f02b0:  a2 16 80 09  or  %i2, %o1, %l1
a00f02b4:  e8 04 40 00  ld  [ %l1 ], %l4
a00f02b8:  ae 15 00 0a  or  %l4, %o2, %l7
a00f02bc:  96 02 e0 01  inc  %o3
a00f02c0:  b2 0d e0 ff  and  %l7, 0xff, %i1
a00f02c4:  98 0a e0 ff  and  %o3, 0xff, %o4
a00f02c8:  f2 24 40 00  st  %i1, [ %l1 ]
a00f02cc:  80 a3 20 03  cmp  %o4, 3
a00f02d0:  08 bf ff f5  bleu  0xa00f02a4
a00f02d4:  9a 03 00 0c  add  %o4, %o4, %o5
a00f02d8:  10 bf fe 68  b  0xa00efc78
a00f02dc:  d8 0f 62 78  ldub  [ %i5 + 0x278 ], %o4
a00f02e0:  2f 00 06 67  sethi  %hi(0x199c00), %l7
a00f02e4:  98 0a a0 ff  and  %o2, 0xff, %o4
a00f02e8:  90 15 e3 fc  or  %l7, 0x3fc, %o0
a00f02ec:  96 10 20 00  clr  %o3
a00f02f0:  9a 10 20 00  clr  %o5
a00f02f4:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a00f02f8:  9a 03 40 0d  add  %o5, %o5, %o5
a00f02fc:  f0 12 00 0d  lduh  [ %o0 + %o5 ], %i0
a00f0300:  aa 06 20 0e  add  %i0, 0xe, %l5
a00f0304:  b5 2d 60 02  sll  %l5, 2, %i2
a00f0308:  96 02 e0 01  inc  %o3
a00f030c:  a8 16 80 09  or  %i2, %o1, %l4
a00f0310:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00f0314:  d8 25 00 00  st  %o4, [ %l4 ]
a00f0318:  80 a3 60 03  cmp  %o5, 3
a00f031c:  28 bf ff f8  bleu,a   0xa00f02fc
a00f0320:  9a 03 40 0d  add  %o5, %o5, %o5
a00f0324:  10 bf fe 41  b  0xa00efc28
a00f0328:  96 0a af 00  and  %o2, 0xf00, %o3
a00f032c:  2b 00 06 67  sethi  %hi(0x199c00), %l5
a00f0330:  92 15 63 fc  or  %l5, 0x3fc, %o1	! 0x199ffc
a00f0334:  98 10 20 00  clr  %o4
a00f0338:  9a 10 20 00  clr  %o5
a00f033c:  94 10 20 08  mov  8, %o2
a00f0340:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00f0344:  82 03 40 0d  add  %o5, %o5, %g1
a00f0348:  e0 12 40 01  lduh  [ %o1 + %g1 ], %l0
a00f034c:  b8 04 20 0f  add  %l0, 0xf, %i4
a00f0350:  9b 2f 20 02  sll  %i4, 2, %o5
a00f0354:  b0 13 40 0b  or  %o5, %o3, %i0
a00f0358:  98 03 20 01  inc  %o4
a00f035c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f0360:  d4 26 00 00  st  %o2, [ %i0 ]
a00f0364:  80 a3 60 03  cmp  %o5, 3
a00f0368:  28 bf ff f8  bleu,a   0xa00f0348
a00f036c:  82 03 40 0d  add  %o5, %o5, %g1
a00f0370:  10 bf fe 1a  b  0xa00efbd8
a00f0374:  80 a5 20 08  cmp  %l4, 8
a00f0378:  81 c7 e0 08  ret
a00f037c:  81 e8 00 00  restore
