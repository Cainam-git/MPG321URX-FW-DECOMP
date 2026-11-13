# leon2m FUN_a00ec340 0xa00ec340-0xa00ec6b8 (888 bytes)
a00ec340:  9d e3 bf 98  save  %sp, -104, %sp
a00ec344:  94 06 80 1b  add  %i2, %i3, %o2
a00ec348:  92 02 bf ff  add  %o2, -1, %o1
a00ec34c:  91 32 60 01  srl  %o1, 1, %o0
a00ec350:  81 80 00 00  mov  %g0, %y
a00ec354:  01 00 00 00  nop
a00ec358:  01 00 00 00  nop
a00ec35c:  01 00 00 00  nop
a00ec360:  b4 72 00 1c  udiv  %o0, %i4, %i2
a00ec364:  b8 5e 80 1c  smul  %i2, %i4, %i4
a00ec368:  b6 22 00 1c  sub  %o0, %i4, %i3
a00ec36c:  83 36 e0 03  srl  %i3, 3, %g1
a00ec370:  a2 08 60 1f  and  %g1, 0x1f, %l1
a00ec374:  80 a6 7f ff  cmp  %i1, -1
a00ec378:  02 80 00 a1  be  0xa00ec5fc
a00ec37c:  b8 0e e0 07  and  %i3, 7, %i4
a00ec380:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00ec384:  a1 2e 60 02  sll  %i1, 2, %l0
a00ec388:  96 13 21 08  or  %o4, 0x108, %o3
a00ec38c:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ec390:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00ec394:  9a 13 e1 18  or  %o7, 0x118, %o5
a00ec398:  d4 02 c0 10  ld  [ %o3 + %l0 ], %o2
a00ec39c:  b6 12 20 f8  or  %o0, 0xf8, %i3
a00ec3a0:  d2 03 40 10  ld  [ %o5 + %l0 ], %o1
a00ec3a4:  d6 06 c0 10  ld  [ %i3 + %l0 ], %o3
a00ec3a8:  7f ff d0 eb  call  0xa00e0754
a00ec3ac:  90 10 00 18  mov  %i0, %o0
a00ec3b0:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00ec3b4:  98 13 60 c8  or  %o5, 0xc8, %o4	! 0xa80268c8
a00ec3b8:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ec3bc:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ec3c0:  b6 02 00 1a  add  %o0, %i2, %i3
a00ec3c4:  82 12 60 e8  or  %o1, 0xe8, %g1
a00ec3c8:  9e 12 a0 d8  or  %o2, 0xd8, %o7
a00ec3cc:  d6 03 00 10  ld  [ %o4 + %l0 ], %o3
a00ec3d0:  d2 00 40 10  ld  [ %g1 + %l0 ], %o1
a00ec3d4:  d4 03 c0 10  ld  [ %o7 + %l0 ], %o2
a00ec3d8:  90 10 00 18  mov  %i0, %o0
a00ec3dc:  7f ff d0 e6  call  0xa00e0774
a00ec3e0:  98 10 00 1b  mov  %i3, %o4
a00ec3e4:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ec3e8:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00ec3ec:  90 12 e0 98  or  %o3, 0x98, %o0
a00ec3f0:  98 13 60 a8  or  %o5, 0xa8, %o4
a00ec3f4:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00ec3f8:  d6 02 00 10  ld  [ %o0 + %l0 ], %o3
a00ec3fc:  9e 10 60 b8  or  %g1, 0xb8, %o7
a00ec400:  d4 03 00 10  ld  [ %o4 + %l0 ], %o2
a00ec404:  d2 03 c0 10  ld  [ %o7 + %l0 ], %o1
a00ec408:  98 06 ff fc  add  %i3, -4, %o4
a00ec40c:  90 10 00 18  mov  %i0, %o0
a00ec410:  7f ff d0 d9  call  0xa00e0774
a00ec414:  01 00 00 00  nop
a00ec418:  80 a6 a0 08  cmp  %i2, 8
a00ec41c:  04 80 00 44  ble  0xa00ec52c
a00ec420:  80 a6 7f ff  cmp  %i1, -1
a00ec424:  02 80 00 9b  be  0xa00ec690
a00ec428:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00ec42c:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ec430:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ec434:  b7 2e 60 02  sll  %i1, 2, %i3
a00ec438:  98 12 e1 28  or  %o3, 0x128, %o4
a00ec43c:  90 12 61 48  or  %o1, 0x148, %o0
a00ec440:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ec444:  d6 03 00 1b  ld  [ %o4 + %i3 ], %o3
a00ec448:  d2 02 00 1b  ld  [ %o0 + %i3 ], %o1
a00ec44c:  82 12 a1 38  or  %o2, 0x138, %g1
a00ec450:  d4 00 40 1b  ld  [ %g1 + %i3 ], %o2
a00ec454:  90 10 00 18  mov  %i0, %o0
a00ec458:  7f ff d0 c7  call  0xa00e0774
a00ec45c:  98 10 20 03  mov  3, %o4
a00ec460:  80 a6 7f ff  cmp  %i1, -1
a00ec464:  22 80 00 45  be,a   0xa00ec578
a00ec468:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00ec46c:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00ec470:  a1 2e 60 02  sll  %i1, 2, %l0
a00ec474:  90 13 23 98  or  %o4, 0x398, %o0
a00ec478:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ec47c:  37 2a 00 99  sethi  %hi(0xa8026400), %i3
a00ec480:  82 12 a3 88  or  %o2, 0x388, %g1
a00ec484:  d2 02 00 10  ld  [ %o0 + %l0 ], %o1
a00ec488:  b4 16 e3 78  or  %i3, 0x378, %i2
a00ec48c:  d4 00 40 10  ld  [ %g1 + %l0 ], %o2
a00ec490:  d6 06 80 10  ld  [ %i2 + %l0 ], %o3
a00ec494:  98 10 00 11  mov  %l1, %o4
a00ec498:  7f ff d0 b7  call  0xa00e0774
a00ec49c:  90 10 00 18  mov  %i0, %o0
a00ec4a0:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ec4a4:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00ec4a8:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00ec4ac:  98 12 e3 28  or  %o3, 0x328, %o4
a00ec4b0:  9a 13 e3 38  or  %o7, 0x338, %o5
a00ec4b4:  d6 03 00 10  ld  [ %o4 + %l0 ], %o3
a00ec4b8:  b2 12 63 48  or  %o1, 0x348, %i1
a00ec4bc:  d4 03 40 10  ld  [ %o5 + %l0 ], %o2
a00ec4c0:  d2 06 40 10  ld  [ %i1 + %l0 ], %o1
a00ec4c4:  98 10 00 11  mov  %l1, %o4
a00ec4c8:  7f ff d0 ab  call  0xa00e0774
a00ec4cc:  90 10 00 18  mov  %i0, %o0
a00ec4d0:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00ec4d4:  94 12 23 68  or  %o0, 0x368, %o2	! 0xa8026768
a00ec4d8:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ec4dc:  35 2a 00 ad  sethi  %hi(0xa802b400), %i2
a00ec4e0:  d2 02 80 10  ld  [ %o2 + %l0 ], %o1
a00ec4e4:  b6 10 63 58  or  %g1, 0x358, %i3
a00ec4e8:  b2 16 a2 e8  or  %i2, 0x2e8, %i1
a00ec4ec:  d6 06 40 10  ld  [ %i1 + %l0 ], %o3
a00ec4f0:  d4 06 c0 10  ld  [ %i3 + %l0 ], %o2
a00ec4f4:  98 10 00 1c  mov  %i4, %o4
a00ec4f8:  7f ff d0 9f  call  0xa00e0774
a00ec4fc:  90 10 00 18  mov  %i0, %o0
a00ec500:  1f 2a 00 ad  sethi  %hi(0xa802b400), %o7
a00ec504:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ec508:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00ec50c:  9a 13 e2 d8  or  %o7, 0x2d8, %o5
a00ec510:  98 12 e3 18  or  %o3, 0x318, %o4
a00ec514:  92 14 63 08  or  %l1, 0x308, %o1
a00ec518:  f6 03 40 10  ld  [ %o5 + %l0 ], %i3
a00ec51c:  f2 03 00 10  ld  [ %o4 + %l0 ], %i1
a00ec520:  f4 02 40 10  ld  [ %o1 + %l0 ], %i2
a00ec524:  7f ff d0 94  call  0xa00e0774
a00ec528:  81 e8 00 00  restore
a00ec52c:  22 80 00 4f  be,a   0xa00ec668
a00ec530:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00ec534:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ec538:  b5 2e 60 02  sll  %i1, 2, %i2
a00ec53c:  90 12 61 28  or  %o1, 0x128, %o0
a00ec540:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ec544:  37 2a 00 9a  sethi  %hi(0xa8026800), %i3
a00ec548:  82 12 a1 48  or  %o2, 0x148, %g1
a00ec54c:  d6 02 00 1a  ld  [ %o0 + %i2 ], %o3
a00ec550:  a0 16 e1 38  or  %i3, 0x138, %l0
a00ec554:  d2 00 40 1a  ld  [ %g1 + %i2 ], %o1
a00ec558:  d4 04 00 1a  ld  [ %l0 + %i2 ], %o2
a00ec55c:  90 10 00 18  mov  %i0, %o0
a00ec560:  7f ff d0 85  call  0xa00e0774
a00ec564:  98 10 20 00  clr  %o4
a00ec568:  80 a6 7f ff  cmp  %i1, -1
a00ec56c:  32 bf ff c1  bne,a   0xa00ec470
a00ec570:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00ec574:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00ec578:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ec57c:  92 12 23 98  or  %o0, 0x398, %o1
a00ec580:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ec584:  96 10 63 78  or  %g1, 0x378, %o3
a00ec588:  98 10 00 11  mov  %l1, %o4
a00ec58c:  94 12 a3 88  or  %o2, 0x388, %o2
a00ec590:  7f ff d0 79  call  0xa00e0774
a00ec594:  90 10 00 18  mov  %i0, %o0
a00ec598:  37 2a 00 99  sethi  %hi(0xa8026400), %i3
a00ec59c:  35 2a 00 99  sethi  %hi(0xa8026400), %i2
a00ec5a0:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00ec5a4:  92 16 e3 48  or  %i3, 0x348, %o1
a00ec5a8:  96 16 a3 28  or  %i2, 0x328, %o3
a00ec5ac:  98 10 00 11  mov  %l1, %o4
a00ec5b0:  90 10 00 18  mov  %i0, %o0
a00ec5b4:  7f ff d0 70  call  0xa00e0774
a00ec5b8:  94 14 23 38  or  %l0, 0x338, %o2
a00ec5bc:  33 2a 00 99  sethi  %hi(0xa8026400), %i1
a00ec5c0:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00ec5c4:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00ec5c8:  92 16 63 68  or  %i1, 0x368, %o1
a00ec5cc:  96 13 62 e8  or  %o5, 0x2e8, %o3
a00ec5d0:  98 10 00 1c  mov  %i4, %o4
a00ec5d4:  94 13 e3 58  or  %o7, 0x358, %o2
a00ec5d8:  7f ff d0 67  call  0xa00e0774
a00ec5dc:  90 10 00 18  mov  %i0, %o0
a00ec5e0:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ec5e4:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00ec5e8:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00ec5ec:  b2 12 e3 18  or  %o3, 0x318, %i1
a00ec5f0:  b4 13 23 08  or  %o4, 0x308, %i2
a00ec5f4:  7f ff d0 60  call  0xa00e0774
a00ec5f8:  97 ec 62 d8  restore  %l1, 0x2d8, %o3
a00ec5fc:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00ec600:  96 12 20 f8  or  %o0, 0xf8, %o3	! 0xa80268f8
a00ec604:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ec608:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ec60c:  92 12 61 18  or  %o1, 0x118, %o1
a00ec610:  94 12 a1 08  or  %o2, 0x108, %o2
a00ec614:  7f ff d0 50  call  0xa00e0754
a00ec618:  90 10 00 18  mov  %i0, %o0
a00ec61c:  a0 02 00 1a  add  %o0, %i2, %l0
a00ec620:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00ec624:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ec628:  37 2a 00 9a  sethi  %hi(0xa8026800), %i3
a00ec62c:  92 10 60 e8  or  %g1, 0xe8, %o1
a00ec630:  94 16 e0 d8  or  %i3, 0xd8, %o2
a00ec634:  96 13 e0 c8  or  %o7, 0xc8, %o3
a00ec638:  90 10 00 18  mov  %i0, %o0
a00ec63c:  7f ff d0 4e  call  0xa00e0774
a00ec640:  98 10 00 10  mov  %l0, %o4
a00ec644:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00ec648:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00ec64c:  94 13 20 a8  or  %o4, 0xa8, %o2
a00ec650:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ec654:  90 10 00 18  mov  %i0, %o0
a00ec658:  92 13 60 b8  or  %o5, 0xb8, %o1
a00ec65c:  96 12 e0 98  or  %o3, 0x98, %o3
a00ec660:  10 bf ff 6c  b  0xa00ec410
a00ec664:  98 04 3f fc  add  %l0, -4, %o4
a00ec668:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ec66c:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00ec670:  92 16 61 48  or  %i1, 0x148, %o1
a00ec674:  94 13 e1 38  or  %o7, 0x138, %o2
a00ec678:  96 13 61 28  or  %o5, 0x128, %o3
a00ec67c:  90 10 00 18  mov  %i0, %o0
a00ec680:  7f ff d0 3d  call  0xa00e0774
a00ec684:  98 10 20 00  clr  %o4
a00ec688:  10 bf ff bc  b  0xa00ec578
a00ec68c:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00ec690:  35 2a 00 9a  sethi  %hi(0xa8026800), %i2
a00ec694:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00ec698:  92 14 21 48  or  %l0, 0x148, %o1
a00ec69c:  94 16 a1 38  or  %i2, 0x138, %o2
a00ec6a0:  96 16 61 28  or  %i1, 0x128, %o3
a00ec6a4:  90 10 00 18  mov  %i0, %o0
a00ec6a8:  7f ff d0 33  call  0xa00e0774
a00ec6ac:  98 10 20 03  mov  3, %o4
a00ec6b0:  10 bf ff b2  b  0xa00ec578
a00ec6b4:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
