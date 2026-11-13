# leon2m FUN_a00ed530 0xa00ed530-0xa00ed70c (476 bytes)
a00ed530:  9d e3 bf 98  save  %sp, -104, %sp
a00ed534:  80 a6 7f ff  cmp  %i1, -1
a00ed538:  02 80 00 48  be  0xa00ed658
a00ed53c:  b4 0e a0 0f  and  %i2, 0xf, %i2
a00ed540:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ed544:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ed548:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00ed54c:  99 2e 60 02  sll  %i1, 2, %o4
a00ed550:  a0 12 e0 f8  or  %o3, 0xf8, %l0
a00ed554:  9a 13 e1 18  or  %o7, 0x118, %o5
a00ed558:  82 12 21 08  or  %o0, 0x108, %g1
a00ed55c:  d6 04 00 0c  ld  [ %l0 + %o4 ], %o3
a00ed560:  d2 03 40 0c  ld  [ %o5 + %o4 ], %o1
a00ed564:  d4 00 40 0c  ld  [ %g1 + %o4 ], %o2
a00ed568:  98 0e a0 0f  and  %i2, 0xf, %o4
a00ed56c:  7f ff cc 82  call  0xa00e0774
a00ed570:  90 10 00 18  mov  %i0, %o0
a00ed574:  94 06 bf fa  add  %i2, -6, %o2
a00ed578:  b4 0a a0 ff  and  %o2, 0xff, %i2
a00ed57c:  80 a6 a0 05  cmp  %i2, 5
a00ed580:  18 80 00 1c  bgu  0xa00ed5f0
a00ed584:  80 a6 7f ff  cmp  %i1, -1
a00ed588:  02 80 00 4c  be  0xa00ed6b8
a00ed58c:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00ed590:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ed594:  a1 2e 60 02  sll  %i1, 2, %l0
a00ed598:  90 13 63 b8  or  %o5, 0x3b8, %o0
a00ed59c:  98 10 63 a8  or  %g1, 0x3a8, %o4
a00ed5a0:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00ed5a4:  9e 12 63 c8  or  %o1, 0x3c8, %o7	! 0xa80267c8
a00ed5a8:  d4 02 00 10  ld  [ %o0 + %l0 ], %o2
a00ed5ac:  d6 03 00 10  ld  [ %o4 + %l0 ], %o3
a00ed5b0:  d2 03 c0 10  ld  [ %o7 + %l0 ], %o1
a00ed5b4:  90 10 00 18  mov  %i0, %o0
a00ed5b8:  7f ff cc 6f  call  0xa00e0774
a00ed5bc:  98 10 20 00  clr  %o4
a00ed5c0:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ed5c4:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ed5c8:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ed5cc:  b4 12 a0 68  or  %o2, 0x68, %i2
a00ed5d0:  b2 12 e0 48  or  %o3, 0x48, %i1
a00ed5d4:  9a 13 e0 58  or  %o7, 0x58, %o5
a00ed5d8:  d6 06 40 10  ld  [ %i1 + %l0 ], %o3
a00ed5dc:  90 10 00 18  mov  %i0, %o0
a00ed5e0:  d2 06 80 10  ld  [ %i2 + %l0 ], %o1
a00ed5e4:  d4 03 40 10  ld  [ %o5 + %l0 ], %o2
a00ed5e8:  10 80 00 45  b  0xa00ed6fc
a00ed5ec:  98 10 20 00  clr  %o4
a00ed5f0:  02 80 00 21  be  0xa00ed674
a00ed5f4:  a1 2e 60 02  sll  %i1, 2, %l0
a00ed5f8:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ed5fc:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ed600:  98 10 63 c8  or  %g1, 0x3c8, %o4
a00ed604:  96 12 a3 b8  or  %o2, 0x3b8, %o3
a00ed608:  33 2a 00 99  sethi  %hi(0xa8026400), %i1
a00ed60c:  d2 03 00 10  ld  [ %o4 + %l0 ], %o1
a00ed610:  d4 02 c0 10  ld  [ %o3 + %l0 ], %o2
a00ed614:  b4 16 63 a8  or  %i1, 0x3a8, %i2
a00ed618:  d6 06 80 10  ld  [ %i2 + %l0 ], %o3
a00ed61c:  90 10 00 18  mov  %i0, %o0
a00ed620:  7f ff cc 55  call  0xa00e0774
a00ed624:  98 10 20 01  mov  1, %o4
a00ed628:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ed62c:  90 12 60 48  or  %o1, 0x48, %o0	! 0xa8026848
a00ed630:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ed634:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00ed638:  d6 02 00 10  ld  [ %o0 + %l0 ], %o3
a00ed63c:  9a 13 e0 68  or  %o7, 0x68, %o5
a00ed640:  98 10 60 58  or  %g1, 0x58, %o4
a00ed644:  90 10 00 18  mov  %i0, %o0
a00ed648:  d2 03 40 10  ld  [ %o5 + %l0 ], %o1
a00ed64c:  d4 03 00 10  ld  [ %o4 + %l0 ], %o2
a00ed650:  10 80 00 2b  b  0xa00ed6fc
a00ed654:  98 10 20 01  mov  1, %o4
a00ed658:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ed65c:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ed660:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ed664:  92 12 61 18  or  %o1, 0x118, %o1
a00ed668:  94 12 a1 08  or  %o2, 0x108, %o2
a00ed66c:  10 bf ff bf  b  0xa00ed568
a00ed670:  96 12 e0 f8  or  %o3, 0xf8, %o3
a00ed674:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ed678:  92 12 e3 c8  or  %o3, 0x3c8, %o1	! 0xa80267c8
a00ed67c:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ed680:  33 2a 00 99  sethi  %hi(0xa8026400), %i1
a00ed684:  90 10 00 18  mov  %i0, %o0
a00ed688:  94 12 a3 b8  or  %o2, 0x3b8, %o2
a00ed68c:  96 16 63 a8  or  %i1, 0x3a8, %o3
a00ed690:  7f ff cc 39  call  0xa00e0774
a00ed694:  98 10 20 01  mov  1, %o4
a00ed698:  90 10 00 18  mov  %i0, %o0
a00ed69c:  35 2a 00 9a  sethi  %hi(0xa8026800), %i2
a00ed6a0:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00ed6a4:  31 2a 00 9a  sethi  %hi(0xa8026800), %i0
a00ed6a8:  92 16 a0 68  or  %i2, 0x68, %o1
a00ed6ac:  94 14 20 58  or  %l0, 0x58, %o2
a00ed6b0:  10 bf ff e8  b  0xa00ed650
a00ed6b4:  96 16 20 48  or  %i0, 0x48, %o3
a00ed6b8:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00ed6bc:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00ed6c0:  92 12 23 c8  or  %o0, 0x3c8, %o1
a00ed6c4:  96 13 23 a8  or  %o4, 0x3a8, %o3
a00ed6c8:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ed6cc:  90 10 00 18  mov  %i0, %o0
a00ed6d0:  94 10 63 b8  or  %g1, 0x3b8, %o2
a00ed6d4:  7f ff cc 28  call  0xa00e0774
a00ed6d8:  98 10 20 00  clr  %o4
a00ed6dc:  90 10 00 18  mov  %i0, %o0
a00ed6e0:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ed6e4:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00ed6e8:  31 2a 00 9a  sethi  %hi(0xa8026800), %i0
a00ed6ec:  92 12 60 68  or  %o1, 0x68, %o1
a00ed6f0:  94 16 60 58  or  %i1, 0x58, %o2
a00ed6f4:  96 16 20 48  or  %i0, 0x48, %o3
a00ed6f8:  98 10 20 00  clr  %o4
a00ed6fc:  7f ff cc 1e  call  0xa00e0774
a00ed700:  b0 10 20 00  clr  %i0
a00ed704:  81 c7 e0 08  ret
a00ed708:  81 e8 00 00  restore
