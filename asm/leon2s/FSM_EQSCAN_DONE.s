# leon2s FSM_EQSCAN_DONE 0xa0079460-0xa00795a0 (320 bytes)
a0079460:  9d e3 bf 98  save  %sp, -104, %sp
a0079464:  a4 0e 20 ff  and  %i0, 0xff, %l2
a0079468:  7f ff fe e0  call  0xa0078fe8
a007946c:  90 10 00 12  mov  %l2, %o0
a0079470:  90 0a 20 ff  and  %o0, 0xff, %o0
a0079474:  80 a2 20 01  cmp  %o0, 1
a0079478:  12 80 00 48  bne  0xa0079598
a007947c:  01 00 00 00  nop
a0079480:  7f ff e8 5a  call  0xa00735e8
a0079484:  90 10 00 12  mov  %l2, %o0
a0079488:  80 8a 20 ff  btst  0xff, %o0
a007948c:  12 80 00 43  bne  0xa0079598
a0079490:  82 04 80 12  add  %l2, %l2, %g1
a0079494:  82 00 40 12  add  %g1, %l2, %g1
a0079498:  29 2a 01 f3  sethi  %hi(0xa807cc00), %l4
a007949c:  83 28 60 03  sll  %g1, 3, %g1
a00794a0:  9a 15 20 64  or  %l4, 0x64, %o5
a00794a4:  82 00 40 0d  add  %g1, %o5, %g1
a00794a8:  c2 08 60 06  ldub  [ %g1 + 6 ], %g1
a00794ac:  80 a0 60 01  cmp  %g1, 1
a00794b0:  12 80 00 3a  bne  0xa0079598
a00794b4:  82 04 80 12  add  %l2, %l2, %g1
a00794b8:  a6 00 40 12  add  %g1, %l2, %l3
a00794bc:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00794c0:  a0 10 60 c4  or  %g1, 0xc4, %l0	! 0xa807ccc4
a00794c4:  a3 2c e0 02  sll  %l3, 2, %l1
a00794c8:  da 04 00 11  ld  [ %l0 + %l1 ], %o5
a00794cc:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00794d0:  9b 2b 60 02  sll  %o5, 2, %o5
a00794d4:  82 10 62 20  or  %g1, 0x220, %g1
a00794d8:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a00794dc:  9f c0 40 00  call  %g1
a00794e0:  90 10 00 12  mov  %l2, %o0
a00794e4:  80 8a 20 ff  btst  0xff, %o0
a00794e8:  12 bf ff f4  bne  0xa00794b8
a00794ec:  82 04 80 12  add  %l2, %l2, %g1
a00794f0:  c2 04 00 11  ld  [ %l0 + %l1 ], %g1
a00794f4:  80 a0 60 10  cmp  %g1, 0x10
a00794f8:  12 80 00 28  bne  0xa0079598
a00794fc:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0079500:  92 10 20 63  mov  0x63, %o1
a0079504:  7f ff e6 d0  call  0xa0073044
a0079508:  90 12 23 a0  or  %o0, 0x3a0, %o0
a007950c:  90 10 00 12  mov  %l2, %o0
a0079510:  7f ff fe d1  call  0xa0079054
a0079514:  92 10 20 01  mov  1, %o1
a0079518:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a007951c:  82 10 61 f0  or  %g1, 0x1f0, %g1	! 0xa807a9f0
a0079520:  a4 5c a8 98  smul  %l2, 0x898, %l2
a0079524:  a0 06 20 41  add  %i0, 0x41, %l0
a0079528:  a4 04 80 01  add  %l2, %g1, %l2
a007952c:  a1 2c 20 18  sll  %l0, 0x18, %l0
a0079530:  23 28 02 ce  sethi  %hi(0xa00b3800), %l1
a0079534:  d4 0c a0 09  ldub  [ %l2 + 9 ], %o2
a0079538:  a1 3c 20 18  sra  %l0, 0x18, %l0
a007953c:  a2 14 62 c8  or  %l1, 0x2c8, %l1
a0079540:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0079544:  d6 0c 40 0a  ldub  [ %l1 + %o2 ], %o3
a0079548:  92 10 00 10  mov  %l0, %o1
a007954c:  7f ff e6 be  call  0xa0073044
a0079550:  90 12 23 c0  or  %o0, 0x3c0, %o0
a0079554:  d4 0c a0 0a  ldub  [ %l2 + 0xa ], %o2
a0079558:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a007955c:  d6 0c 40 0a  ldub  [ %l1 + %o2 ], %o3
a0079560:  92 10 00 10  mov  %l0, %o1
a0079564:  7f ff e6 b8  call  0xa0073044
a0079568:  90 12 23 f8  or  %o0, 0x3f8, %o0
a007956c:  d4 0c a0 0b  ldub  [ %l2 + 0xb ], %o2
a0079570:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a0079574:  90 12 20 30  or  %o0, 0x30, %o0	! 0xa0067830
a0079578:  92 10 00 10  mov  %l0, %o1
a007957c:  7f ff e6 b2  call  0xa0073044
a0079580:  d6 0c 40 0a  ldub  [ %l1 + %o2 ], %o3
a0079584:  9a 15 20 64  or  %l4, 0x64, %o5
a0079588:  83 2c e0 03  sll  %l3, 3, %g1
a007958c:  82 00 40 0d  add  %g1, %o5, %g1
a0079590:  9a 10 20 01  mov  1, %o5
a0079594:  da 28 60 01  stb  %o5, [ %g1 + 1 ]
a0079598:  81 c7 e0 08  ret
a007959c:  81 e8 00 00  restore
