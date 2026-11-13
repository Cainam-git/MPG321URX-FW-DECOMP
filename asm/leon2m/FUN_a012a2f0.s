# leon2m FUN_a012a2f0 0xa012a2f0-0xa012a700 (1040 bytes)
a012a2f0:  9d e3 bf 50  save  %sp, -176, %sp
a012a2f4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012a2f8:  80 a6 20 00  cmp  %i0, 0
a012a2fc:  02 80 00 12  be  0xa012a344
a012a300:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a012a304:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a012a308:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a012a30c:  92 10 62 3a  or  %g1, 0x23a, %o1
a012a310:  94 13 62 1a  or  %o5, 0x21a, %o2
a012a314:  96 10 20 00  clr  %o3
a012a318:  98 10 20 00  clr  %o4
a012a31c:  90 03 00 0c  add  %o4, %o4, %o0
a012a320:  a1 2b 20 06  sll  %o4, 6, %l0
a012a324:  96 02 e0 01  inc  %o3
a012a328:  9e 04 20 40  add  %l0, 0x40, %o7
a012a32c:  98 0a e0 ff  and  %o3, 0xff, %o4
a012a330:  de 32 80 08  sth  %o7, [ %o2 + %o0 ]
a012a334:  80 a3 20 0f  cmp  %o4, 0xf
a012a338:  08 bf ff f9  bleu  0xa012a31c
a012a33c:  de 32 40 08  sth  %o7, [ %o1 + %o0 ]
a012a340:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a012a344:  d2 14 22 12  lduh  [ %l0 + 0x212 ], %o1	! 0xa802ca12
a012a348:  80 a2 60 00  cmp  %o1, 0
a012a34c:  12 80 00 12  bne  0xa012a394
a012a350:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a012a354:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a012a358:  82 12 a2 e0  or  %o2, 0x2e0, %g1	! 0xa802cae0
a012a35c:  c0 34 22 12  clrh  [ %l0 + 0x212 ]
a012a360:  96 10 20 00  clr  %o3
a012a364:  9a 10 20 00  clr  %o5
a012a368:  92 10 20 3a  mov  0x3a, %o1
a012a36c:  94 10 20 00  clr  %o2
a012a370:  d2 28 40 0d  stb  %o1, [ %g1 + %o5 ]
a012a374:  96 02 e0 01  inc  %o3
a012a378:  98 02 a0 3a  add  %o2, 0x3a, %o4
a012a37c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a012a380:  80 a3 60 0f  cmp  %o5, 0xf
a012a384:  08 bf ff fb  bleu  0xa012a370
a012a388:  94 10 00 0c  mov  %o4, %o2
a012a38c:  d8 34 22 12  sth  %o4, [ %l0 + 0x212 ]
a012a390:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a012a394:  d6 04 62 0c  ld  [ %l1 + 0x20c ], %o3	! 0xa802ca0c
a012a398:  80 a2 e0 00  cmp  %o3, 0
a012a39c:  02 80 00 2d  be  0xa012a450
a012a3a0:  82 10 20 00  clr  %g1
a012a3a4:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a012a3a8:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a012a3ac:  9e 14 a2 9c  or  %l2, 0x29c, %o7
a012a3b0:  90 13 22 5c  or  %o4, 0x25c, %o0
a012a3b4:  92 10 20 00  clr  %o1
a012a3b8:  96 10 20 00  clr  %o3
a012a3bc:  94 10 20 00  clr  %o2
a012a3c0:  9a 10 20 00  clr  %o5
a012a3c4:  a5 2b 60 02  sll  %o5, 2, %l2
a012a3c8:  d8 02 00 12  ld  [ %o0 + %l2 ], %o4
a012a3cc:  c2 03 c0 12  ld  [ %o7 + %l2 ], %g1
a012a3d0:  a6 20 40 0c  sub  %g1, %o4, %l3
a012a3d4:  9b 3c e0 1f  sra  %l3, 0x1f, %o5
a012a3d8:  a4 1b 40 13  xor  %o5, %l3, %l2
a012a3dc:  98 24 80 0d  sub  %l2, %o5, %o4
a012a3e0:  83 2b 20 10  sll  %o4, 0x10, %g1
a012a3e4:  9a 02 e0 01  add  %o3, 1, %o5
a012a3e8:  a7 30 60 10  srl  %g1, 0x10, %l3
a012a3ec:  80 a4 e0 40  cmp  %l3, 0x40
a012a3f0:  08 80 00 08  bleu  0xa012a410
a012a3f4:  96 0a e0 80  and  %o3, 0x80, %o3
a012a3f8:  a6 0b 60 ff  and  %o5, 0xff, %l3
a012a3fc:  96 10 00 0d  mov  %o5, %o3
a012a400:  80 a4 e0 01  cmp  %l3, 1
a012a404:  08 80 00 03  bleu  0xa012a410
a012a408:  92 02 60 01  inc  %o1
a012a40c:  96 13 7f 80  or  %o5, -128, %o3
a012a410:  94 02 a0 01  inc  %o2
a012a414:  9a 0a a0 ff  and  %o2, 0xff, %o5
a012a418:  80 a3 60 0f  cmp  %o5, 0xf
a012a41c:  08 bf ff eb  bleu  0xa012a3c8
a012a420:  a5 2b 60 02  sll  %o5, 2, %l2
a012a424:  98 0a 60 ff  and  %o1, 0xff, %o4
a012a428:  80 a3 20 03  cmp  %o4, 3
a012a42c:  93 2a e0 18  sll  %o3, 0x18, %o1
a012a430:  91 32 60 1f  srl  %o1, 0x1f, %o0
a012a434:  9e 60 20 00  subx  %g0, 0, %o7
a012a438:  80 8b c0 08  btst  %o7, %o0
a012a43c:  12 80 00 05  bne  0xa012a450
a012a440:  82 10 20 00  clr  %g1
a012a444:  80 a3 20 00  cmp  %o4, 0
a012a448:  02 80 00 a7  be  0xa012a6e4
a012a44c:  82 10 20 01  mov  1, %g1
a012a450:  80 a0 60 00  cmp  %g1, 0
a012a454:  02 80 00 4d  be  0xa012a588
a012a458:  82 10 20 00  clr  %g1
a012a45c:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a012a460:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a012a464:  92 12 a2 9c  or  %o2, 0x29c, %o1
a012a468:  94 12 e2 5c  or  %o3, 0x25c, %o2
a012a46c:  96 10 20 00  clr  %o3
a012a470:  98 10 20 00  clr  %o4
a012a474:  9b 2b 20 02  sll  %o4, 2, %o5
a012a478:  96 02 e0 01  inc  %o3
a012a47c:  c2 02 80 0d  ld  [ %o2 + %o5 ], %g1
a012a480:  98 0a e0 ff  and  %o3, 0xff, %o4
a012a484:  80 a3 20 0f  cmp  %o4, 0xf
a012a488:  08 bf ff fb  bleu  0xa012a474
a012a48c:  c2 22 40 0d  st  %g1, [ %o1 + %o5 ]
a012a490:  d0 14 22 12  lduh  [ %l0 + 0x212 ], %o0
a012a494:  9e 10 24 00  mov  0x400, %o7
a012a498:  a0 23 c0 08  sub  %o7, %o0, %l0
a012a49c:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a012a4a0:  27 2a 00 b2  sethi  %hi(0xa802c800), %l3
a012a4a4:  90 14 a2 1a  or  %l2, 0x21a, %o0
a012a4a8:  a4 14 e2 5c  or  %l3, 0x25c, %l2
a012a4ac:  de 04 62 0c  ld  [ %l1 + 0x20c ], %o7
a012a4b0:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a012a4b4:  a2 13 22 e0  or  %o4, 0x2e0, %l1	! 0xa802cae0
a012a4b8:  a6 10 20 00  clr  %l3
a012a4bc:  92 10 20 00  clr  %o1
a012a4c0:  96 10 20 00  clr  %o3
a012a4c4:  83 2a e0 02  sll  %o3, 2, %g1
a012a4c8:  d8 04 80 01  ld  [ %l2 + %g1 ], %o4
a012a4cc:  9b 2b 20 02  sll  %o4, 2, %o5
a012a4d0:  94 03 40 0c  add  %o5, %o4, %o2
a012a4d4:  82 02 80 0a  add  %o2, %o2, %g1
a012a4d8:  81 80 00 00  mov  %g0, %y
a012a4dc:  01 00 00 00  nop
a012a4e0:  01 00 00 00  nop
a012a4e4:  01 00 00 00  nop
a012a4e8:  9a 70 40 0f  udiv  %g1, %o7, %o5
a012a4ec:  94 5c 00 0c  smul  %l0, %o4, %o2
a012a4f0:  80 a3 60 07  cmp  %o5, 7
a012a4f4:  81 80 00 00  mov  %g0, %y
a012a4f8:  01 00 00 00  nop
a012a4fc:  01 00 00 00  nop
a012a500:  01 00 00 00  nop
a012a504:  98 72 80 0f  udiv  %o2, %o7, %o4
a012a508:  9a 02 c0 0b  add  %o3, %o3, %o5
a012a50c:  92 02 60 01  inc  %o1
a012a510:  18 80 00 77  bgu  0xa012a6ec
a012a514:  94 03 40 08  add  %o5, %o0, %o2
a012a518:  c2 0c 40 0b  ldub  [ %l1 + %o3 ], %g1
a012a51c:  98 03 00 01  add  %o4, %g1, %o4
a012a520:  80 a2 e0 00  cmp  %o3, 0
a012a524:  96 0a 60 ff  and  %o1, 0xff, %o3
a012a528:  02 80 00 05  be  0xa012a53c
a012a52c:  d8 32 00 0d  sth  %o4, [ %o0 + %o5 ]
a012a530:  c2 12 bf fe  lduh  [ %o2 + -2 ], %g1
a012a534:  94 03 00 01  add  %o4, %g1, %o2
a012a538:  d4 32 00 0d  sth  %o2, [ %o0 + %o5 ]
a012a53c:  80 a2 e0 0f  cmp  %o3, 0xf
a012a540:  08 bf ff e2  bleu  0xa012a4c8
a012a544:  83 2a e0 02  sll  %o3, 2, %g1
a012a548:  80 8c e0 ff  btst  0xff, %l3
a012a54c:  02 80 00 0f  be  0xa012a588
a012a550:  82 10 20 01  mov  1, %g1
a012a554:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a012a558:  94 14 62 1a  or  %l1, 0x21a, %o2	! 0xa802ca1a
a012a55c:  96 10 20 00  clr  %o3
a012a560:  98 10 20 00  clr  %o4
a012a564:  a7 2b 20 06  sll  %o4, 6, %l3
a012a568:  a0 03 00 0c  add  %o4, %o4, %l0
a012a56c:  96 02 e0 01  inc  %o3
a012a570:  92 04 e0 40  add  %l3, 0x40, %o1
a012a574:  98 0a e0 ff  and  %o3, 0xff, %o4
a012a578:  80 a3 20 0f  cmp  %o4, 0xf
a012a57c:  08 bf ff fa  bleu  0xa012a564
a012a580:  d2 32 80 10  sth  %o1, [ %o2 + %l0 ]
a012a584:  82 10 20 01  mov  1, %g1
a012a588:  80 a0 60 00  cmp  %g1, 0
a012a58c:  12 80 00 09  bne  0xa012a5b0
a012a590:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a012a594:  80 a6 20 00  cmp  %i0, 0
a012a598:  32 80 00 07  bne,a   0xa012a5b4
a012a59c:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a012a5a0:  f0 0c 22 10  ldub  [ %l0 + 0x210 ], %i0
a012a5a4:  80 a6 20 00  cmp  %i0, 0
a012a5a8:  02 80 00 54  be  0xa012a6f8
a012a5ac:  01 00 00 00  nop
a012a5b0:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a012a5b4:  d6 04 a2 08  ld  [ %l2 + 0x208 ], %o3	! 0xa802ca08
a012a5b8:  80 a2 e0 00  cmp  %o3, 0
a012a5bc:  12 80 00 31  bne  0xa012a680
a012a5c0:  b0 10 20 00  clr  %i0
a012a5c4:  11 2a 00 b2  sethi  %hi(0xa802c800), %o0
a012a5c8:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a012a5cc:  9a 12 22 1a  or  %o0, 0x21a, %o5
a012a5d0:  9e 13 22 3a  or  %o4, 0x23a, %o7
a012a5d4:  90 10 20 00  clr  %o0
a012a5d8:  82 10 20 00  clr  %g1
a012a5dc:  98 00 40 01  add  %g1, %g1, %o4
a012a5e0:  c2 13 40 0c  lduh  [ %o5 + %o4 ], %g1
a012a5e4:  d6 13 c0 0c  lduh  [ %o7 + %o4 ], %o3
a012a5e8:  80 a2 c0 01  cmp  %o3, %g1
a012a5ec:  08 80 00 35  bleu  0xa012a6c0
a012a5f0:  94 10 00 01  mov  %g1, %o2
a012a5f4:  82 22 c0 01  sub  %o3, %g1, %g1
a012a5f8:  80 a0 60 04  cmp  %g1, 4
a012a5fc:  24 80 00 04  ble,a   0xa012a60c
a012a600:  d4 33 c0 0c  sth  %o2, [ %o7 + %o4 ]
a012a604:  82 02 ff fc  add  %o3, -4, %g1
a012a608:  c2 33 c0 0c  sth  %g1, [ %o7 + %o4 ]
a012a60c:  b0 10 20 01  mov  1, %i0
a012a610:  90 02 20 01  inc  %o0
a012a614:  82 0a 20 ff  and  %o0, 0xff, %g1
a012a618:  80 a0 60 0f  cmp  %g1, 0xf
a012a61c:  08 bf ff f1  bleu  0xa012a5e0
a012a620:  98 00 40 01  add  %g1, %g1, %o4
a012a624:  f0 2c 22 10  stb  %i0, [ %l0 + 0x210 ]
a012a628:  92 10 20 10  mov  0x10, %o1
a012a62c:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a012a630:  d2 2f bf b0  stb  %o1, [ %fp + -80 ]
a012a634:  92 12 a2 3a  or  %o2, 0x23a, %o1
a012a638:  c0 37 bf b2  clrh  [ %fp + -78 ]
a012a63c:  96 10 20 01  mov  1, %o3
a012a640:  9a 10 20 01  mov  1, %o5
a012a644:  94 07 bf f8  add  %fp, -8, %o2
a012a648:  90 03 40 0d  add  %o5, %o5, %o0
a012a64c:  98 02 00 09  add  %o0, %o1, %o4
a012a650:  96 02 e0 01  inc  %o3
a012a654:  e4 13 3f fe  lduh  [ %o4 + -2 ], %l2
a012a658:  b0 02 00 0a  add  %o0, %o2, %i0
a012a65c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a012a660:  80 a3 60 0f  cmp  %o5, 0xf
a012a664:  08 bf ff f9  bleu  0xa012a648
a012a668:  e4 36 3f ba  sth  %l2, [ %i0 + -70 ]
a012a66c:  96 10 24 00  mov  0x400, %o3
a012a670:  d6 37 bf d2  sth  %o3, [ %fp + -46 ]
a012a674:  7f ff 33 70  call  0xa00f7434
a012a678:  90 07 bf b0  add  %fp, -80, %o0
a012a67c:  30 80 00 1f  b,a   0xa012a6f8
a012a680:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a012a684:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a012a688:  c0 2c 22 10  clrb  [ %l0 + 0x210 ]
a012a68c:  92 13 62 3a  or  %o5, 0x23a, %o1
a012a690:  94 13 e2 1a  or  %o7, 0x21a, %o2
a012a694:  96 10 20 00  clr  %o3
a012a698:  98 10 20 00  clr  %o4
a012a69c:  a0 03 00 0c  add  %o4, %o4, %l0
a012a6a0:  96 02 e0 01  inc  %o3
a012a6a4:  e6 12 80 10  lduh  [ %o2 + %l0 ], %l3
a012a6a8:  98 0a e0 ff  and  %o3, 0xff, %o4
a012a6ac:  80 a3 20 0f  cmp  %o4, 0xf
a012a6b0:  08 bf ff fb  bleu  0xa012a69c
a012a6b4:  e6 32 40 10  sth  %l3, [ %o1 + %l0 ]
a012a6b8:  10 bf ff dd  b  0xa012a62c
a012a6bc:  92 10 20 10  mov  0x10, %o1
a012a6c0:  3a bf ff d5  bcc,a   0xa012a614
a012a6c4:  90 02 20 01  inc  %o0
a012a6c8:  a2 20 40 0b  sub  %g1, %o3, %l1
a012a6cc:  80 a4 60 04  cmp  %l1, 4
a012a6d0:  24 bf ff cf  ble,a   0xa012a60c
a012a6d4:  d4 33 c0 0c  sth  %o2, [ %o7 + %o4 ]
a012a6d8:  82 02 e0 04  add  %o3, 4, %g1
a012a6dc:  10 bf ff cc  b  0xa012a60c
a012a6e0:  c2 33 c0 0c  sth  %g1, [ %o7 + %o4 ]
a012a6e4:  10 bf ff 5b  b  0xa012a450
a012a6e8:  82 10 20 00  clr  %g1
a012a6ec:  d8 32 00 0d  sth  %o4, [ %o0 + %o5 ]
a012a6f0:  10 bf ff 96  b  0xa012a548
a012a6f4:  a6 10 20 01  mov  1, %l3
a012a6f8:  81 c7 e0 08  ret
a012a6fc:  81 e8 00 00  restore
