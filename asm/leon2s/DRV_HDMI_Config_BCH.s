# leon2s DRV_HDMI_Config_BCH 0xa009c5b4-0xa009c6e4 (304 bytes)
a009c5b4:  9d e3 bf 98  save  %sp, -104, %sp
a009c5b8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a009c5bc:  9a 04 00 10  add  %l0, %l0, %o5
a009c5c0:  9a 03 40 10  add  %o5, %l0, %o5
a009c5c4:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a009c5c8:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa807cc64
a009c5cc:  9b 2b 60 03  sll  %o5, 3, %o5
a009c5d0:  9a 03 40 01  add  %o5, %g1, %o5
a009c5d4:  25 2a 01 e1  sethi  %hi(0xa8078400), %l2
a009c5d8:  92 06 20 41  add  %i0, 0x41, %o1
a009c5dc:  93 2a 60 18  sll  %o1, 0x18, %o1
a009c5e0:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1
a009c5e4:  15 28 02 d1  sethi  %hi(0xa00b4400), %o2
a009c5e8:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009c5ec:  80 88 60 02  btst  2, %g1
a009c5f0:  e2 13 60 08  lduh  [ %o5 + 8 ], %l1
a009c5f4:  93 3a 60 18  sra  %o1, 0x18, %o1
a009c5f8:  94 12 a0 98  or  %o2, 0x98, %o2
a009c5fc:  02 80 00 04  be  0xa009c60c
a009c600:  90 12 22 58  or  %o0, 0x258, %o0
a009c604:  7f ff 5a 90  call  0xa0073044
a009c608:  01 00 00 00  nop
a009c60c:  82 0e 60 ff  and  %i1, 0xff, %g1
a009c610:  80 a0 00 01  cmp  %g0, %g1
a009c614:  9a 40 20 00  addx  %g0, 0, %o5
a009c618:  98 5c 20 34  smul  %l0, 0x34, %o4
a009c61c:  80 a4 60 64  cmp  %l1, 0x64
a009c620:  18 80 00 03  bgu  0xa009c62c
a009c624:  82 10 20 01  mov  1, %g1
a009c628:  82 10 20 00  clr  %g1
a009c62c:  80 8b 40 01  btst  %o5, %g1
a009c630:  02 80 00 1c  be  0xa009c6a0
a009c634:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009c638:  92 06 20 41  add  %i0, 0x41, %o1
a009c63c:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1
a009c640:  93 2a 60 18  sll  %o1, 0x18, %o1
a009c644:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009c648:  80 88 60 02  btst  2, %g1
a009c64c:  90 12 22 70  or  %o0, 0x270, %o0
a009c650:  02 80 00 04  be  0xa009c660
a009c654:  93 3a 60 18  sra  %o1, 0x18, %o1
a009c658:  7f ff 5a 7b  call  0xa0073044
a009c65c:  01 00 00 00  nop
a009c660:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009c664:  9a 5c 20 34  smul  %l0, 0x34, %o5
a009c668:  82 10 63 00  or  %g1, 0x300, %g1
a009c66c:  d8 00 40 0d  ld  [ %g1 + %o5 ], %o4
a009c670:  da 03 20 c0  ld  [ %o4 + 0xc0 ], %o5
a009c674:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a009c678:  82 2b 40 01  andn  %o5, %g1, %g1
a009c67c:  1b 01 40 00  sethi  %hi(0x5000000), %o5
a009c680:  82 10 40 0d  or  %g1, %o5, %g1
a009c684:  c2 23 20 c0  st  %g1, [ %o4 + 0xc0 ]
a009c688:  c2 03 20 c4  ld  [ %o4 + 0xc4 ], %g1
a009c68c:  82 08 7f 00  and  %g1, -256, %g1
a009c690:  c2 23 20 c4  st  %g1, [ %o4 + 0xc4 ]
a009c694:  c2 03 20 bc  ld  [ %o4 + 0xbc ], %g1
a009c698:  10 80 00 10  b  0xa009c6d8
a009c69c:  82 10 60 1f  or  %g1, 0x1f, %g1
a009c6a0:  82 10 63 00  or  %g1, 0x300, %g1
a009c6a4:  d8 00 40 0c  ld  [ %g1 + %o4 ], %o4
a009c6a8:  da 03 20 c0  ld  [ %o4 + 0xc0 ], %o5
a009c6ac:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a009c6b0:  82 2b 40 01  andn  %o5, %g1, %g1
a009c6b4:  1b 14 00 00  sethi  %hi(0x50000000), %o5
a009c6b8:  82 10 40 0d  or  %g1, %o5, %g1
a009c6bc:  c2 23 20 c0  st  %g1, [ %o4 + 0xc0 ]
a009c6c0:  c2 03 20 c4  ld  [ %o4 + 0xc4 ], %g1
a009c6c4:  82 08 7f 00  and  %g1, -256, %g1
a009c6c8:  c2 23 20 c4  st  %g1, [ %o4 + 0xc4 ]
a009c6cc:  c2 03 20 bc  ld  [ %o4 + 0xbc ], %g1
a009c6d0:  82 08 7f e0  and  %g1, -32, %g1
a009c6d4:  82 10 60 01  or  %g1, 1, %g1
a009c6d8:  c2 23 20 bc  st  %g1, [ %o4 + 0xbc ]
a009c6dc:  81 c7 e0 08  ret
a009c6e0:  81 e8 00 00  restore
