# leon2s DRV_HDMI_EQScan_FSM_Done 0xa007f670-0xa007f798 (296 bytes)
a007f670:  9d e3 bf 98  save  %sp, -104, %sp
a007f674:  27 2a 01 e1  sethi  %hi(0xa8078400), %l3
a007f678:  94 06 20 41  add  %i0, 0x41, %o2
a007f67c:  95 2a a0 18  sll  %o2, 0x18, %o2
a007f680:  a2 0e 20 ff  and  %i0, 0xff, %l1
a007f684:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1
a007f688:  13 28 02 cf  sethi  %hi(0xa00b3c00), %o1
a007f68c:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007f690:  a8 10 00 18  mov  %i0, %l4
a007f694:  80 88 60 02  btst  2, %g1
a007f698:  95 3a a0 18  sra  %o2, 0x18, %o2
a007f69c:  92 12 63 40  or  %o1, 0x340, %o1
a007f6a0:  90 12 23 d0  or  %o0, 0x3d0, %o0
a007f6a4:  02 80 00 04  be  0xa007f6b4
a007f6a8:  a4 0c 60 01  and  %l1, 1, %l2
a007f6ac:  7f ff ce 66  call  0xa0073044
a007f6b0:  01 00 00 00  nop
a007f6b4:  a0 04 40 11  add  %l1, %l1, %l0
a007f6b8:  a0 04 00 11  add  %l0, %l1, %l0
a007f6bc:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a007f6c0:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa807cc64
a007f6c4:  a1 2c 20 03  sll  %l0, 3, %l0
a007f6c8:  a0 04 00 01  add  %l0, %g1, %l0
a007f6cc:  7f ff ee f5  call  0xa007b2a0
a007f6d0:  90 10 00 11  mov  %l1, %o0
a007f6d4:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a007f6d8:  7f ff f6 5f  call  0xa007d054
a007f6dc:  90 10 00 11  mov  %l1, %o0
a007f6e0:  9a 0c a0 ff  and  %l2, 0xff, %o5
a007f6e4:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a007f6e8:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a007f6ec:  9a 5b 60 34  smul  %o5, 0x34, %o5
a007f6f0:  9a 03 40 01  add  %o5, %g1, %o5
a007f6f4:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a007f6f8:  d2 03 60 0c  ld  [ %o5 + 0xc ], %o1
a007f6fc:  92 02 60 7c  add  %o1, 0x7c, %o1
a007f700:  40 00 9f 2b  call  0xa00a73ac
a007f704:  90 10 20 0b  mov  0xb, %o0
a007f708:  7f ff ff cb  call  0xa007f634
a007f70c:  90 10 00 11  mov  %l1, %o0
a007f710:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007f714:  9a 10 61 88  or  %g1, 0x188, %o5	! 0xa8078988
a007f718:  c2 0b 40 11  ldub  [ %o5 + %l1 ], %g1
a007f71c:  80 a0 60 01  cmp  %g1, 1
a007f720:  12 80 00 0e  bne  0xa007f758
a007f724:  92 05 20 41  add  %l4, 0x41, %o1
a007f728:  92 06 20 41  add  %i0, 0x41, %o1
a007f72c:  93 2a 60 18  sll  %o1, 0x18, %o1
a007f730:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1
a007f734:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a007f738:  80 88 60 02  btst  2, %g1
a007f73c:  c0 2b 40 11  clrb  [ %o5 + %l1 ]
a007f740:  93 3a 60 18  sra  %o1, 0x18, %o1
a007f744:  02 80 00 10  be  0xa007f784
a007f748:  90 12 20 b0  or  %o0, 0xb0, %o0
a007f74c:  7f ff ce 3e  call  0xa0073044
a007f750:  01 00 00 00  nop
a007f754:  92 05 20 41  add  %l4, 0x41, %o1
a007f758:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1
a007f75c:  93 2a 60 18  sll  %o1, 0x18, %o1
a007f760:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a007f764:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a007f768:  80 88 60 02  btst  2, %g1
a007f76c:  90 12 20 e0  or  %o0, 0xe0, %o0
a007f770:  93 3a 60 18  sra  %o1, 0x18, %o1
a007f774:  02 80 00 04  be  0xa007f784
a007f778:  94 12 a3 40  or  %o2, 0x340, %o2
a007f77c:  7f ff ce 32  call  0xa0073044
a007f780:  01 00 00 00  nop
a007f784:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007f788:  82 10 61 90  or  %g1, 0x190, %g1	! 0xa8078990
a007f78c:  c0 28 40 11  clrb  [ %g1 + %l1 ]
a007f790:  81 c7 e0 08  ret
a007f794:  91 e8 20 00  restore  %g0, 0, %o0
