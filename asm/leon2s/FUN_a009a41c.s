# leon2s FUN_a009a41c 0xa009a41c-0xa009a580 (356 bytes)
a009a41c:  9d e3 bf 98  save  %sp, -104, %sp
a009a420:  15 00 00 07  sethi  %hi(0x1c00), %o2
a009a424:  94 12 a3 0c  or  %o2, 0x30c, %o2	! 0x1f0c
a009a428:  90 10 20 14  mov  0x14, %o0
a009a42c:  40 00 34 0f  call  0xa00a7468
a009a430:  92 10 20 00  clr  %o1
a009a434:  80 a2 20 00  cmp  %o0, 0
a009a438:  12 80 00 4b  bne  0xa009a564
a009a43c:  31 2a 01 e4  sethi  %hi(0xa8079000), %i0
a009a440:  a0 10 20 00  clr  %l0
a009a444:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009a448:  b0 0c 20 ff  and  %l0, 0xff, %i0
a009a44c:  82 10 61 10  or  %g1, 0x110, %g1
a009a450:  c2 08 40 18  ldub  [ %g1 + %i0 ], %g1
a009a454:  80 a0 60 00  cmp  %g1, 0
a009a458:  22 80 00 3e  be,a   0xa009a550
a009a45c:  a0 04 20 01  inc  %l0
a009a460:  7f ff ef 62  call  0xa00961e8
a009a464:  90 10 00 18  mov  %i0, %o0
a009a468:  90 0a 20 ff  and  %o0, 0xff, %o0
a009a46c:  82 02 00 08  add  %o0, %o0, %g1
a009a470:  82 00 40 08  add  %g1, %o0, %g1
a009a474:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a009a478:  83 28 60 03  sll  %g1, 3, %g1
a009a47c:  9a 13 60 64  or  %o5, 0x64, %o5
a009a480:  82 00 40 0d  add  %g1, %o5, %g1
a009a484:  c2 08 60 06  ldub  [ %g1 + 6 ], %g1
a009a488:  80 a0 60 00  cmp  %g1, 0
a009a48c:  12 80 00 08  bne  0xa009a4ac
a009a490:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009a494:  98 10 62 48  or  %g1, 0x248, %o4	! 0xa807d648
a009a498:  9b 2e 20 02  sll  %i0, 2, %o5
a009a49c:  c2 03 00 0d  ld  [ %o4 + %o5 ], %g1
a009a4a0:  80 a0 60 01  cmp  %g1, 1
a009a4a4:  32 80 00 02  bne,a   0xa009a4ac
a009a4a8:  c0 23 00 0d  clr  [ %o4 + %o5 ]
a009a4ac:  7f ff cc d5  call  0xa008d800
a009a4b0:  01 00 00 00  nop
a009a4b4:  90 0a 20 ff  and  %o0, 0xff, %o0
a009a4b8:  80 a2 20 82  cmp  %o0, 0x82
a009a4bc:  18 80 00 17  bgu  0xa009a518
a009a4c0:  90 0c 20 ff  and  %l0, 0xff, %o0
a009a4c4:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009a4c8:  94 10 60 d0  or  %g1, 0xd0, %o2	! 0xa80790d0
a009a4cc:  c2 0a 80 18  ldub  [ %o2 + %i0 ], %g1
a009a4d0:  80 a0 60 01  cmp  %g1, 1
a009a4d4:  12 80 00 12  bne  0xa009a51c
a009a4d8:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009a4dc:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009a4e0:  82 10 62 80  or  %g1, 0x280, %g1	! 0xa807d680
a009a4e4:  98 5e 20 b0  smul  %i0, 0xb0, %o4
a009a4e8:  98 03 00 01  add  %o4, %g1, %o4
a009a4ec:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009a4f0:  82 10 62 48  or  %g1, 0x248, %g1	! 0xa807d648
a009a4f4:  97 2e 20 02  sll  %i0, 2, %o3
a009a4f8:  9a 10 20 03  mov  3, %o5
a009a4fc:  da 20 40 0b  st  %o5, [ %g1 + %o3 ]
a009a500:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009a504:  82 10 60 d8  or  %g1, 0xd8, %g1	! 0xa80790d8
a009a508:  c0 2a 80 18  clrb  [ %o2 + %i0 ]
a009a50c:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a009a510:  c0 2b 20 02  clrb  [ %o4 + 2 ]
a009a514:  90 0c 20 ff  and  %l0, 0xff, %o0
a009a518:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009a51c:  9b 2a 20 02  sll  %o0, 2, %o5
a009a520:  82 10 62 48  or  %g1, 0x248, %g1
a009a524:  da 00 40 0d  ld  [ %g1 + %o5 ], %o5
a009a528:  03 28 02 d0  sethi  %hi(0xa00b4000), %g1
a009a52c:  9b 2b 60 02  sll  %o5, 2, %o5
a009a530:  82 10 62 30  or  %g1, 0x230, %g1
a009a534:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a009a538:  9f c0 40 00  call  %g1
a009a53c:  01 00 00 00  nop
a009a540:  80 8a 20 ff  btst  0xff, %o0
a009a544:  12 bf ff f5  bne  0xa009a518
a009a548:  90 0c 20 ff  and  %l0, 0xff, %o0
a009a54c:  a0 04 20 01  inc  %l0
a009a550:  82 0c 20 ff  and  %l0, 0xff, %g1
a009a554:  80 a0 60 01  cmp  %g1, 1
a009a558:  08 bf ff bc  bleu  0xa009a448
a009a55c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009a560:  31 2a 01 e4  sethi  %hi(0xa8079000), %i0
a009a564:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009a568:  b0 16 21 00  or  %i0, 0x100, %i0
a009a56c:  c2 08 62 30  ldub  [ %g1 + 0x230 ], %g1
a009a570:  c2 26 20 04  st  %g1, [ %i0 + 4 ]
a009a574:  40 00 5f 08  call  0xa00b2194
a009a578:  81 e8 00 00  restore
a009a57c:  01 00 00 00  nop
