# leon2s DRV_HDMI_EQScan_FSM_PHY_PICDR 0xa007c4b8-0xa007cea4 (2540 bytes)
a007c4b8:  9d e3 bf 98  save  %sp, -104, %sp
a007c4bc:  aa 0e 20 ff  and  %i0, 0xff, %l5
a007c4c0:  82 05 40 15  add  %l5, %l5, %g1
a007c4c4:  82 00 40 15  add  %g1, %l5, %g1
a007c4c8:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a007c4cc:  9a 13 60 64  or  %o5, 0x64, %o5	! 0xa807cc64
a007c4d0:  83 28 60 03  sll  %g1, 3, %g1
a007c4d4:  82 00 40 0d  add  %g1, %o5, %g1
a007c4d8:  37 2a 01 e1  sethi  %hi(0xa8078400), %i3
a007c4dc:  da 06 e2 34  ld  [ %i3 + 0x234 ], %o5	! 0xa8078634
a007c4e0:  b2 10 00 18  mov  %i0, %i1
a007c4e4:  80 8b 60 02  btst  2, %o5
a007c4e8:  02 80 00 0a  be  0xa007c510
a007c4ec:  e2 10 60 08  lduh  [ %g1 + 8 ], %l1
a007c4f0:  92 06 20 41  add  %i0, 0x41, %o1
a007c4f4:  93 2a 60 18  sll  %o1, 0x18, %o1
a007c4f8:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007c4fc:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a007c500:  90 12 22 c0  or  %o0, 0x2c0, %o0
a007c504:  93 3a 60 18  sra  %o1, 0x18, %o1
a007c508:  7f ff da cf  call  0xa0073044
a007c50c:  94 12 a2 70  or  %o2, 0x270, %o2
a007c510:  3b 3f ff c0  sethi  %hi(0xffff0000), %i5
a007c514:  35 00 00 0d  sethi  %hi(0x3400), %i2
a007c518:  90 10 00 15  mov  %l5, %o0
a007c51c:  92 16 a1 34  or  %i2, 0x134, %o1
a007c520:  94 17 60 ff  or  %i5, 0xff, %o2
a007c524:  17 00 00 10  sethi  %hi(0x4000), %o3
a007c528:  40 00 ab d8  call  0xa00a7488
a007c52c:  27 00 00 04  sethi  %hi(0x1000), %l3
a007c530:  21 00 3f ff  sethi  %hi(0xfffc00), %l0
a007c534:  90 10 00 15  mov  %l5, %o0
a007c538:  92 14 e1 54  or  %l3, 0x154, %o1
a007c53c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c540:  40 00 ab d2  call  0xa00a7488
a007c544:  17 00 80 00  sethi  %hi(0x2000000), %o3
a007c548:  90 10 00 15  mov  %l5, %o0
a007c54c:  92 14 e1 04  or  %l3, 0x104, %o1
a007c550:  94 10 3f 00  mov  -256, %o2
a007c554:  40 00 ab cd  call  0xa00a7488
a007c558:  96 10 20 03  mov  3, %o3
a007c55c:  90 10 00 15  mov  %l5, %o0
a007c560:  92 14 e1 08  or  %l3, 0x108, %o1
a007c564:  94 10 3f 00  mov  -256, %o2
a007c568:  40 00 ab c8  call  0xa00a7488
a007c56c:  96 10 20 05  mov  5, %o3
a007c570:  90 10 00 15  mov  %l5, %o0
a007c574:  92 14 e1 08  or  %l3, 0x108, %o1
a007c578:  94 17 60 ff  or  %i5, 0xff, %o2
a007c57c:  40 00 ab c3  call  0xa00a7488
a007c580:  96 10 21 00  mov  0x100, %o3
a007c584:  2d 00 00 05  sethi  %hi(0x1400), %l6
a007c588:  90 10 00 15  mov  %l5, %o0
a007c58c:  92 15 a1 04  or  %l6, 0x104, %o1
a007c590:  94 10 3f 00  mov  -256, %o2
a007c594:  40 00 ab bd  call  0xa00a7488
a007c598:  96 10 20 03  mov  3, %o3
a007c59c:  90 10 00 15  mov  %l5, %o0
a007c5a0:  92 15 a1 08  or  %l6, 0x108, %o1
a007c5a4:  94 10 3f 00  mov  -256, %o2
a007c5a8:  40 00 ab b8  call  0xa00a7488
a007c5ac:  96 10 20 05  mov  5, %o3
a007c5b0:  90 10 00 15  mov  %l5, %o0
a007c5b4:  92 15 a1 08  or  %l6, 0x108, %o1
a007c5b8:  94 17 60 ff  or  %i5, 0xff, %o2
a007c5bc:  40 00 ab b3  call  0xa00a7488
a007c5c0:  96 10 21 00  mov  0x100, %o3
a007c5c4:  2f 00 00 06  sethi  %hi(0x1800), %l7
a007c5c8:  90 10 00 15  mov  %l5, %o0
a007c5cc:  92 15 e1 04  or  %l7, 0x104, %o1
a007c5d0:  94 10 3f 00  mov  -256, %o2
a007c5d4:  40 00 ab ad  call  0xa00a7488
a007c5d8:  96 10 20 03  mov  3, %o3
a007c5dc:  90 10 00 15  mov  %l5, %o0
a007c5e0:  92 15 e1 08  or  %l7, 0x108, %o1
a007c5e4:  94 10 3f 00  mov  -256, %o2
a007c5e8:  40 00 ab a8  call  0xa00a7488
a007c5ec:  96 10 20 05  mov  5, %o3
a007c5f0:  90 10 00 15  mov  %l5, %o0
a007c5f4:  92 15 e1 08  or  %l7, 0x108, %o1
a007c5f8:  94 17 60 ff  or  %i5, 0xff, %o2
a007c5fc:  40 00 ab a3  call  0xa00a7488
a007c600:  96 10 21 00  mov  0x100, %o3
a007c604:  90 10 00 15  mov  %l5, %o0
a007c608:  92 14 e1 54  or  %l3, 0x154, %o1
a007c60c:  94 10 3f 00  mov  -256, %o2
a007c610:  40 00 ab 9e  call  0xa00a7488
a007c614:  96 10 20 f0  mov  0xf0, %o3
a007c618:  15 3f ff f8  sethi  %hi(0xffffe000), %o2
a007c61c:  90 10 00 15  mov  %l5, %o0
a007c620:  94 12 a0 ff  or  %o2, 0xff, %o2
a007c624:  92 14 e1 54  or  %l3, 0x154, %o1
a007c628:  40 00 ab 98  call  0xa00a7488
a007c62c:  96 10 20 00  clr  %o3
a007c630:  90 10 00 15  mov  %l5, %o0
a007c634:  92 14 e1 4c  or  %l3, 0x14c, %o1
a007c638:  94 17 60 ff  or  %i5, 0xff, %o2
a007c63c:  40 00 ab 93  call  0xa00a7488
a007c640:  96 10 26 00  mov  0x600, %o3
a007c644:  15 3f ff 3f  sethi  %hi(0xfffcfc00), %o2
a007c648:  90 10 00 15  mov  %l5, %o0
a007c64c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007c650:  92 14 e1 5c  or  %l3, 0x15c, %o1
a007c654:  40 00 ab 8d  call  0xa00a7488
a007c658:  96 10 20 00  clr  %o3
a007c65c:  90 10 20 01  mov  1, %o0
a007c660:  92 10 20 12  mov  0x12, %o1
a007c664:  94 10 00 15  mov  %l5, %o2
a007c668:  40 00 ab 6f  call  0xa00a7424
a007c66c:  96 14 e1 5c  or  %l3, 0x15c, %o3
a007c670:  90 10 20 00  clr  %o0
a007c674:  92 10 20 13  mov  0x13, %o1
a007c678:  94 10 00 15  mov  %l5, %o2
a007c67c:  40 00 ab 6a  call  0xa00a7424
a007c680:  96 14 e1 5c  or  %l3, 0x15c, %o3
a007c684:  90 10 20 00  clr  %o0
a007c688:  92 10 20 14  mov  0x14, %o1
a007c68c:  94 10 00 15  mov  %l5, %o2
a007c690:  40 00 ab 65  call  0xa00a7424
a007c694:  96 14 e1 5c  or  %l3, 0x15c, %o3
a007c698:  90 10 20 00  clr  %o0
a007c69c:  92 10 20 15  mov  0x15, %o1
a007c6a0:  94 10 00 15  mov  %l5, %o2
a007c6a4:  40 00 ab 60  call  0xa00a7424
a007c6a8:  96 14 e1 5c  or  %l3, 0x15c, %o3
a007c6ac:  b9 2c 60 10  sll  %l1, 0x10, %i4
a007c6b0:  90 10 20 01  mov  1, %o0
a007c6b4:  92 10 20 16  mov  0x16, %o1
a007c6b8:  94 10 00 15  mov  %l5, %o2
a007c6bc:  40 00 ab 5a  call  0xa00a7424
a007c6c0:  96 14 e1 5c  or  %l3, 0x15c, %o3
a007c6c4:  a9 37 20 10  srl  %i4, 0x10, %l4
a007c6c8:  80 a5 20 63  cmp  %l4, 0x63
a007c6cc:  18 80 00 6b  bgu  0xa007c878
a007c6d0:  80 a5 20 9f  cmp  %l4, 0x9f
a007c6d4:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c6d8:  90 10 00 15  mov  %l5, %o0
a007c6dc:  92 14 e0 14  or  %l3, 0x14, %o1
a007c6e0:  40 00 ab 6a  call  0xa00a7488
a007c6e4:  17 3c c0 00  sethi  %hi(0xf3000000), %o3
a007c6e8:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c6ec:  90 10 00 15  mov  %l5, %o0
a007c6f0:  92 15 a0 14  or  %l6, 0x14, %o1
a007c6f4:  40 00 ab 65  call  0xa00a7488
a007c6f8:  17 3c c0 00  sethi  %hi(0xf3000000), %o3
a007c6fc:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c700:  90 10 00 15  mov  %l5, %o0
a007c704:  92 15 e0 14  or  %l7, 0x14, %o1
a007c708:  40 00 ab 60  call  0xa00a7488
a007c70c:  17 3c c0 00  sethi  %hi(0xf3000000), %o3
a007c710:  25 00 00 07  sethi  %hi(0x1c00), %l2
a007c714:  90 10 20 00  clr  %o0
a007c718:  92 10 20 1a  mov  0x1a, %o1
a007c71c:  94 10 00 15  mov  %l5, %o2
a007c720:  40 00 ab 41  call  0xa00a7424
a007c724:  96 14 a3 40  or  %l2, 0x340, %o3
a007c728:  21 3f f8 3f  sethi  %hi(0xffe0fc00), %l0
a007c72c:  90 10 00 15  mov  %l5, %o0
a007c730:  92 14 e0 18  or  %l3, 0x18, %o1
a007c734:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c738:  40 00 ab 54  call  0xa00a7488
a007c73c:  17 00 01 00  sethi  %hi(0x40000), %o3
a007c740:  23 3f e7 ff  sethi  %hi(0xff9ffc00), %l1
a007c744:  90 10 00 15  mov  %l5, %o0
a007c748:  92 14 e0 18  or  %l3, 0x18, %o1
a007c74c:  94 14 63 ff  or  %l1, 0x3ff, %o2
a007c750:  40 00 ab 4e  call  0xa00a7488
a007c754:  17 00 10 00  sethi  %hi(0x400000), %o3
a007c758:  90 10 00 15  mov  %l5, %o0
a007c75c:  92 15 a0 18  or  %l6, 0x18, %o1
a007c760:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c764:  40 00 ab 49  call  0xa00a7488
a007c768:  17 00 01 00  sethi  %hi(0x40000), %o3
a007c76c:  90 10 00 15  mov  %l5, %o0
a007c770:  92 15 a0 18  or  %l6, 0x18, %o1
a007c774:  94 14 63 ff  or  %l1, 0x3ff, %o2
a007c778:  40 00 ab 44  call  0xa00a7488
a007c77c:  17 00 10 00  sethi  %hi(0x400000), %o3
a007c780:  90 10 00 15  mov  %l5, %o0
a007c784:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c788:  92 15 e0 18  or  %l7, 0x18, %o1
a007c78c:  40 00 ab 3f  call  0xa00a7488
a007c790:  17 00 01 00  sethi  %hi(0x40000), %o3
a007c794:  90 10 00 15  mov  %l5, %o0
a007c798:  92 15 e0 18  or  %l7, 0x18, %o1
a007c79c:  94 14 63 ff  or  %l1, 0x3ff, %o2
a007c7a0:  40 00 ab 3a  call  0xa00a7488
a007c7a4:  17 00 10 00  sethi  %hi(0x400000), %o3
a007c7a8:  90 10 00 15  mov  %l5, %o0
a007c7ac:  92 14 a3 00  or  %l2, 0x300, %o1
a007c7b0:  94 17 60 ff  or  %i5, 0xff, %o2
a007c7b4:  40 00 ab 35  call  0xa00a7488
a007c7b8:  96 10 20 00  clr  %o3
a007c7bc:  15 3f 3f ff  sethi  %hi(0xfcfffc00), %o2
a007c7c0:  90 10 00 15  mov  %l5, %o0
a007c7c4:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007c7c8:  92 14 e1 60  or  %l3, 0x160, %o1
a007c7cc:  40 00 ab 2f  call  0xa00a7488
a007c7d0:  96 10 20 00  clr  %o3
a007c7d4:  15 3c ff ff  sethi  %hi(0xf3fffc00), %o2
a007c7d8:  90 10 00 15  mov  %l5, %o0
a007c7dc:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007c7e0:  92 14 e1 60  or  %l3, 0x160, %o1
a007c7e4:  40 00 ab 29  call  0xa00a7488
a007c7e8:  17 01 00 00  sethi  %hi(0x4000000), %o3
a007c7ec:  90 10 20 00  clr  %o0
a007c7f0:  92 10 20 1c  mov  0x1c, %o1
a007c7f4:  94 10 00 15  mov  %l5, %o2
a007c7f8:  40 00 ab 0b  call  0xa00a7424
a007c7fc:  96 14 e1 60  or  %l3, 0x160, %o3
a007c800:  90 10 20 01  mov  1, %o0
a007c804:  92 10 20 1d  mov  0x1d, %o1
a007c808:  94 10 00 15  mov  %l5, %o2
a007c80c:  40 00 ab 06  call  0xa00a7424
a007c810:  96 14 e1 60  or  %l3, 0x160, %o3
a007c814:  90 10 20 01  mov  1, %o0
a007c818:  92 10 20 1e  mov  0x1e, %o1
a007c81c:  94 10 00 15  mov  %l5, %o2
a007c820:  40 00 ab 01  call  0xa00a7424
a007c824:  96 14 e1 60  or  %l3, 0x160, %o3
a007c828:  c2 06 e2 34  ld  [ %i3 + 0x234 ], %g1
a007c82c:  80 88 60 02  btst  2, %g1
a007c830:  22 80 00 0a  be,a   0xa007c858
a007c834:  90 10 00 15  mov  %l5, %o0
a007c838:  92 06 20 41  add  %i0, 0x41, %o1
a007c83c:  93 2a 60 18  sll  %o1, 0x18, %o1
a007c840:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007c844:  90 12 22 e0  or  %o0, 0x2e0, %o0	! 0xa0067ae0
a007c848:  93 3a 60 18  sra  %o1, 0x18, %o1
a007c84c:  7f ff d9 fe  call  0xa0073044
a007c850:  94 10 00 14  mov  %l4, %o2
a007c854:  90 10 00 15  mov  %l5, %o0
a007c858:  92 14 e1 f0  or  %l3, 0x1f0, %o1
a007c85c:  96 10 20 00  clr  %o3
a007c860:  40 00 ab 0a  call  0xa00a7488
a007c864:  94 10 3f 00  mov  -256, %o2
a007c868:  90 10 00 15  mov  %l5, %o0
a007c86c:  92 14 e1 f4  or  %l3, 0x1f4, %o1
a007c870:  10 80 00 6d  b  0xa007ca24
a007c874:  96 0d 23 ff  and  %l4, 0x3ff, %o3
a007c878:  18 80 00 6d  bgu  0xa007ca2c
a007c87c:  80 a5 21 2b  cmp  %l4, 0x12b
a007c880:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c884:  90 10 00 15  mov  %l5, %o0
a007c888:  92 14 e0 14  or  %l3, 0x14, %o1
a007c88c:  40 00 aa ff  call  0xa00a7488
a007c890:  17 3d c0 00  sethi  %hi(0xf7000000), %o3
a007c894:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c898:  90 10 00 15  mov  %l5, %o0
a007c89c:  92 15 a0 14  or  %l6, 0x14, %o1
a007c8a0:  40 00 aa fa  call  0xa00a7488
a007c8a4:  17 3d c0 00  sethi  %hi(0xf7000000), %o3
a007c8a8:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c8ac:  90 10 00 15  mov  %l5, %o0
a007c8b0:  92 15 e0 14  or  %l7, 0x14, %o1
a007c8b4:  40 00 aa f5  call  0xa00a7488
a007c8b8:  17 3d c0 00  sethi  %hi(0xf7000000), %o3
a007c8bc:  25 00 00 07  sethi  %hi(0x1c00), %l2
a007c8c0:  90 10 20 01  mov  1, %o0
a007c8c4:  92 10 20 1a  mov  0x1a, %o1
a007c8c8:  94 10 00 15  mov  %l5, %o2
a007c8cc:  40 00 aa d6  call  0xa00a7424
a007c8d0:  96 14 a3 40  or  %l2, 0x340, %o3
a007c8d4:  21 3f f8 3f  sethi  %hi(0xffe0fc00), %l0
a007c8d8:  90 10 00 15  mov  %l5, %o0
a007c8dc:  92 14 e0 18  or  %l3, 0x18, %o1
a007c8e0:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c8e4:  40 00 aa e9  call  0xa00a7488
a007c8e8:  17 00 01 00  sethi  %hi(0x40000), %o3
a007c8ec:  23 3f e7 ff  sethi  %hi(0xff9ffc00), %l1
a007c8f0:  90 10 00 15  mov  %l5, %o0
a007c8f4:  92 14 e0 18  or  %l3, 0x18, %o1
a007c8f8:  94 14 63 ff  or  %l1, 0x3ff, %o2
a007c8fc:  40 00 aa e3  call  0xa00a7488
a007c900:  17 00 10 00  sethi  %hi(0x400000), %o3
a007c904:  90 10 00 15  mov  %l5, %o0
a007c908:  92 15 a0 18  or  %l6, 0x18, %o1
a007c90c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c910:  40 00 aa de  call  0xa00a7488
a007c914:  17 00 01 00  sethi  %hi(0x40000), %o3
a007c918:  90 10 00 15  mov  %l5, %o0
a007c91c:  92 15 a0 18  or  %l6, 0x18, %o1
a007c920:  94 14 63 ff  or  %l1, 0x3ff, %o2
a007c924:  40 00 aa d9  call  0xa00a7488
a007c928:  17 00 10 00  sethi  %hi(0x400000), %o3
a007c92c:  90 10 00 15  mov  %l5, %o0
a007c930:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007c934:  92 15 e0 18  or  %l7, 0x18, %o1
a007c938:  40 00 aa d4  call  0xa00a7488
a007c93c:  17 00 01 00  sethi  %hi(0x40000), %o3
a007c940:  90 10 00 15  mov  %l5, %o0
a007c944:  92 15 e0 18  or  %l7, 0x18, %o1
a007c948:  94 14 63 ff  or  %l1, 0x3ff, %o2
a007c94c:  40 00 aa cf  call  0xa00a7488
a007c950:  17 00 10 00  sethi  %hi(0x400000), %o3
a007c954:  90 10 00 15  mov  %l5, %o0
a007c958:  92 14 a3 00  or  %l2, 0x300, %o1
a007c95c:  94 17 60 ff  or  %i5, 0xff, %o2
a007c960:  40 00 aa ca  call  0xa00a7488
a007c964:  96 10 27 00  mov  0x700, %o3
a007c968:  15 3f 3f ff  sethi  %hi(0xfcfffc00), %o2
a007c96c:  90 10 00 15  mov  %l5, %o0
a007c970:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007c974:  92 14 e1 60  or  %l3, 0x160, %o1
a007c978:  40 00 aa c4  call  0xa00a7488
a007c97c:  96 10 20 00  clr  %o3
a007c980:  15 3c ff ff  sethi  %hi(0xf3fffc00), %o2
a007c984:  90 10 00 15  mov  %l5, %o0
a007c988:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007c98c:  92 14 e1 60  or  %l3, 0x160, %o1
a007c990:  40 00 aa be  call  0xa00a7488
a007c994:  17 01 00 00  sethi  %hi(0x4000000), %o3
a007c998:  90 10 20 00  clr  %o0
a007c99c:  92 10 20 1c  mov  0x1c, %o1
a007c9a0:  94 10 00 15  mov  %l5, %o2
a007c9a4:  40 00 aa a0  call  0xa00a7424
a007c9a8:  96 14 e1 60  or  %l3, 0x160, %o3
a007c9ac:  90 10 20 01  mov  1, %o0
a007c9b0:  92 10 20 1d  mov  0x1d, %o1
a007c9b4:  94 10 00 15  mov  %l5, %o2
a007c9b8:  40 00 aa 9b  call  0xa00a7424
a007c9bc:  96 14 e1 60  or  %l3, 0x160, %o3
a007c9c0:  90 10 20 01  mov  1, %o0
a007c9c4:  92 10 20 1e  mov  0x1e, %o1
a007c9c8:  94 10 00 15  mov  %l5, %o2
a007c9cc:  40 00 aa 96  call  0xa00a7424
a007c9d0:  96 14 e1 60  or  %l3, 0x160, %o3
a007c9d4:  c2 06 e2 34  ld  [ %i3 + 0x234 ], %g1
a007c9d8:  80 88 60 02  btst  2, %g1
a007c9dc:  22 80 00 0a  be,a   0xa007ca04
a007c9e0:  90 10 00 15  mov  %l5, %o0
a007c9e4:  92 06 20 41  add  %i0, 0x41, %o1
a007c9e8:  93 2a 60 18  sll  %o1, 0x18, %o1
a007c9ec:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007c9f0:  90 12 22 e0  or  %o0, 0x2e0, %o0	! 0xa0067ae0
a007c9f4:  93 3a 60 18  sra  %o1, 0x18, %o1
a007c9f8:  7f ff d9 93  call  0xa0073044
a007c9fc:  95 37 20 11  srl  %i4, 0x11, %o2
a007ca00:  90 10 00 15  mov  %l5, %o0
a007ca04:  92 14 e1 f0  or  %l3, 0x1f0, %o1
a007ca08:  96 10 20 00  clr  %o3
a007ca0c:  40 00 aa 9f  call  0xa00a7488
a007ca10:  94 10 3f 00  mov  -256, %o2
a007ca14:  97 37 20 11  srl  %i4, 0x11, %o3
a007ca18:  90 10 00 15  mov  %l5, %o0
a007ca1c:  92 14 e1 f4  or  %l3, 0x1f4, %o1
a007ca20:  96 0a e3 ff  and  %o3, 0x3ff, %o3
a007ca24:  10 80 00 e0  b  0xa007cda4
a007ca28:  94 10 3c 00  mov  -1024, %o2
a007ca2c:  18 80 00 73  bgu  0xa007cbf8
a007ca30:  80 a5 22 58  cmp  %l4, 0x258
a007ca34:  21 00 3f ff  sethi  %hi(0xfffc00), %l0
a007ca38:  2d 00 00 04  sethi  %hi(0x1000), %l6
a007ca3c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007ca40:  90 10 00 15  mov  %l5, %o0
a007ca44:  92 15 a0 14  or  %l6, 0x14, %o1
a007ca48:  40 00 aa 90  call  0xa00a7488
a007ca4c:  17 3d c0 00  sethi  %hi(0xf7000000), %o3
a007ca50:  25 00 00 05  sethi  %hi(0x1400), %l2
a007ca54:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007ca58:  90 10 00 15  mov  %l5, %o0
a007ca5c:  92 14 a0 14  or  %l2, 0x14, %o1
a007ca60:  40 00 aa 8a  call  0xa00a7488
a007ca64:  17 3d c0 00  sethi  %hi(0xf7000000), %o3
a007ca68:  27 00 00 06  sethi  %hi(0x1800), %l3
a007ca6c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007ca70:  90 10 00 15  mov  %l5, %o0
a007ca74:  92 14 e0 14  or  %l3, 0x14, %o1
a007ca78:  40 00 aa 84  call  0xa00a7488
a007ca7c:  17 3d c0 00  sethi  %hi(0xf7000000), %o3
a007ca80:  29 00 00 07  sethi  %hi(0x1c00), %l4
a007ca84:  90 10 20 01  mov  1, %o0
a007ca88:  92 10 20 1a  mov  0x1a, %o1
a007ca8c:  94 10 00 15  mov  %l5, %o2
a007ca90:  40 00 aa 65  call  0xa00a7424
a007ca94:  96 15 23 40  or  %l4, 0x340, %o3
a007ca98:  21 3f f8 3f  sethi  %hi(0xffe0fc00), %l0
a007ca9c:  90 10 00 15  mov  %l5, %o0
a007caa0:  92 15 a0 18  or  %l6, 0x18, %o1
a007caa4:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007caa8:  40 00 aa 78  call  0xa00a7488
a007caac:  17 00 01 00  sethi  %hi(0x40000), %o3
a007cab0:  23 3f e7 ff  sethi  %hi(0xff9ffc00), %l1
a007cab4:  90 10 00 15  mov  %l5, %o0
a007cab8:  92 15 a0 18  or  %l6, 0x18, %o1
a007cabc:  94 14 63 ff  or  %l1, 0x3ff, %o2
a007cac0:  40 00 aa 72  call  0xa00a7488
a007cac4:  17 00 08 00  sethi  %hi(0x200000), %o3
a007cac8:  90 10 00 15  mov  %l5, %o0
a007cacc:  92 14 a0 18  or  %l2, 0x18, %o1
a007cad0:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007cad4:  40 00 aa 6d  call  0xa00a7488
a007cad8:  17 00 01 00  sethi  %hi(0x40000), %o3
a007cadc:  90 10 00 15  mov  %l5, %o0
a007cae0:  92 14 a0 18  or  %l2, 0x18, %o1
a007cae4:  94 14 63 ff  or  %l1, 0x3ff, %o2
a007cae8:  40 00 aa 68  call  0xa00a7488
a007caec:  17 00 08 00  sethi  %hi(0x200000), %o3
a007caf0:  90 10 00 15  mov  %l5, %o0
a007caf4:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007caf8:  92 14 e0 18  or  %l3, 0x18, %o1
a007cafc:  40 00 aa 63  call  0xa00a7488
a007cb00:  17 00 01 00  sethi  %hi(0x40000), %o3
a007cb04:  90 10 00 15  mov  %l5, %o0
a007cb08:  92 14 e0 18  or  %l3, 0x18, %o1
a007cb0c:  94 14 63 ff  or  %l1, 0x3ff, %o2
a007cb10:  40 00 aa 5e  call  0xa00a7488
a007cb14:  17 00 08 00  sethi  %hi(0x200000), %o3
a007cb18:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a007cb1c:  90 10 00 15  mov  %l5, %o0
a007cb20:  94 12 a0 ff  or  %o2, 0xff, %o2
a007cb24:  92 15 23 00  or  %l4, 0x300, %o1
a007cb28:  40 00 aa 58  call  0xa00a7488
a007cb2c:  96 10 27 00  mov  0x700, %o3
a007cb30:  94 15 22 80  or  %l4, 0x280, %o2
a007cb34:  90 10 20 06  mov  6, %o0
a007cb38:  40 00 aa 4c  call  0xa00a7468
a007cb3c:  92 10 20 00  clr  %o1
a007cb40:  80 a2 20 01  cmp  %o0, 1
a007cb44:  12 80 00 07  bne  0xa007cb60
a007cb48:  15 3f 3f ff  sethi  %hi(0xfcfffc00), %o2
a007cb4c:  92 15 a1 60  or  %l6, 0x160, %o1
a007cb50:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007cb54:  90 10 00 15  mov  %l5, %o0
a007cb58:  10 80 00 06  b  0xa007cb70
a007cb5c:  17 00 c0 00  sethi  %hi(0x3000000), %o3
a007cb60:  92 15 a1 60  or  %l6, 0x160, %o1
a007cb64:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007cb68:  90 10 00 15  mov  %l5, %o0
a007cb6c:  96 10 20 00  clr  %o3
a007cb70:  40 00 aa 46  call  0xa00a7488
a007cb74:  21 00 00 04  sethi  %hi(0x1000), %l0
a007cb78:  15 3c ff ff  sethi  %hi(0xf3fffc00), %o2
a007cb7c:  94 12 a3 ff  or  %o2, 0x3ff, %o2	! 0xf3ffffff
a007cb80:  90 10 00 15  mov  %l5, %o0
a007cb84:  92 14 21 60  or  %l0, 0x160, %o1
a007cb88:  40 00 aa 40  call  0xa00a7488
a007cb8c:  17 01 00 00  sethi  %hi(0x4000000), %o3
a007cb90:  94 10 00 15  mov  %l5, %o2
a007cb94:  96 14 21 60  or  %l0, 0x160, %o3
a007cb98:  90 10 20 00  clr  %o0
a007cb9c:  40 00 aa 22  call  0xa00a7424
a007cba0:  92 10 20 1c  mov  0x1c, %o1
a007cba4:  94 10 00 15  mov  %l5, %o2
a007cba8:  96 14 21 60  or  %l0, 0x160, %o3
a007cbac:  90 10 20 01  mov  1, %o0
a007cbb0:  40 00 aa 1d  call  0xa00a7424
a007cbb4:  92 10 20 1d  mov  0x1d, %o1
a007cbb8:  94 10 00 15  mov  %l5, %o2
a007cbbc:  96 14 21 60  or  %l0, 0x160, %o3
a007cbc0:  90 10 20 01  mov  1, %o0
a007cbc4:  40 00 aa 18  call  0xa00a7424
a007cbc8:  92 10 20 1e  mov  0x1e, %o1
a007cbcc:  90 10 00 15  mov  %l5, %o0
a007cbd0:  92 14 21 f0  or  %l0, 0x1f0, %o1
a007cbd4:  94 10 3f 00  mov  -256, %o2
a007cbd8:  40 00 aa 2c  call  0xa00a7488
a007cbdc:  96 10 20 80  mov  0x80, %o3
a007cbe0:  15 3f ff c3  sethi  %hi(0xffff0c00), %o2
a007cbe4:  90 10 00 15  mov  %l5, %o0
a007cbe8:  92 14 21 f4  or  %l0, 0x1f4, %o1
a007cbec:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007cbf0:  10 80 00 6d  b  0xa007cda4
a007cbf4:  17 00 00 20  sethi  %hi(0x8000), %o3
a007cbf8:  18 80 00 6e  bgu  0xa007cdb0
a007cbfc:  c2 06 e2 34  ld  [ %i3 + 0x234 ], %g1
a007cc00:  7f ff f9 a8  call  0xa007b2a0
a007cc04:  90 10 00 15  mov  %l5, %o0
a007cc08:  80 8a 20 ff  btst  0xff, %o0
a007cc0c:  22 bf ff 8b  be,a   0xa007ca38
a007cc10:  21 00 3f ff  sethi  %hi(0xfffc00), %l0
a007cc14:  94 14 23 ff  or  %l0, 0x3ff, %o2	! 0xffffff
a007cc18:  90 10 00 15  mov  %l5, %o0
a007cc1c:  92 14 e0 14  or  %l3, 0x14, %o1
a007cc20:  40 00 aa 1a  call  0xa00a7488
a007cc24:  17 3d c0 00  sethi  %hi(0xf7000000), %o3
a007cc28:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007cc2c:  90 10 00 15  mov  %l5, %o0
a007cc30:  92 15 a0 14  or  %l6, 0x14, %o1
a007cc34:  40 00 aa 15  call  0xa00a7488
a007cc38:  17 3d c0 00  sethi  %hi(0xf7000000), %o3
a007cc3c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007cc40:  90 10 00 15  mov  %l5, %o0
a007cc44:  92 15 e0 14  or  %l7, 0x14, %o1
a007cc48:  40 00 aa 10  call  0xa00a7488
a007cc4c:  17 3d c0 00  sethi  %hi(0xf7000000), %o3
a007cc50:  25 00 00 07  sethi  %hi(0x1c00), %l2
a007cc54:  94 10 00 15  mov  %l5, %o2
a007cc58:  96 14 a3 40  or  %l2, 0x340, %o3
a007cc5c:  90 10 20 01  mov  1, %o0
a007cc60:  40 00 a9 f1  call  0xa00a7424
a007cc64:  92 10 20 1a  mov  0x1a, %o1
a007cc68:  90 10 00 15  mov  %l5, %o0
a007cc6c:  92 16 a1 34  or  %i2, 0x134, %o1
a007cc70:  94 17 60 ff  or  %i5, 0xff, %o2
a007cc74:  40 00 aa 05  call  0xa00a7488
a007cc78:  17 00 00 10  sethi  %hi(0x4000), %o3
a007cc7c:  21 3f f8 3f  sethi  %hi(0xffe0fc00), %l0
a007cc80:  90 10 00 15  mov  %l5, %o0
a007cc84:  92 14 e0 18  or  %l3, 0x18, %o1
a007cc88:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007cc8c:  40 00 a9 ff  call  0xa00a7488
a007cc90:  17 00 01 00  sethi  %hi(0x40000), %o3
a007cc94:  23 3f e7 ff  sethi  %hi(0xff9ffc00), %l1
a007cc98:  90 10 00 15  mov  %l5, %o0
a007cc9c:  92 14 e0 18  or  %l3, 0x18, %o1
a007cca0:  94 14 63 ff  or  %l1, 0x3ff, %o2
a007cca4:  40 00 a9 f9  call  0xa00a7488
a007cca8:  17 00 08 00  sethi  %hi(0x200000), %o3
a007ccac:  90 10 00 15  mov  %l5, %o0
a007ccb0:  92 15 a0 18  or  %l6, 0x18, %o1
a007ccb4:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007ccb8:  40 00 a9 f4  call  0xa00a7488
a007ccbc:  17 00 01 00  sethi  %hi(0x40000), %o3
a007ccc0:  90 10 00 15  mov  %l5, %o0
a007ccc4:  92 15 a0 18  or  %l6, 0x18, %o1
a007ccc8:  94 14 63 ff  or  %l1, 0x3ff, %o2
a007cccc:  40 00 a9 ef  call  0xa00a7488
a007ccd0:  17 00 08 00  sethi  %hi(0x200000), %o3
a007ccd4:  90 10 00 15  mov  %l5, %o0
a007ccd8:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007ccdc:  92 15 e0 18  or  %l7, 0x18, %o1
a007cce0:  40 00 a9 ea  call  0xa00a7488
a007cce4:  17 00 01 00  sethi  %hi(0x40000), %o3
a007cce8:  90 10 00 15  mov  %l5, %o0
a007ccec:  92 15 e0 18  or  %l7, 0x18, %o1
a007ccf0:  94 14 63 ff  or  %l1, 0x3ff, %o2
a007ccf4:  40 00 a9 e5  call  0xa00a7488
a007ccf8:  17 00 08 00  sethi  %hi(0x200000), %o3
a007ccfc:  90 10 00 15  mov  %l5, %o0
a007cd00:  92 14 a3 00  or  %l2, 0x300, %o1
a007cd04:  94 17 60 ff  or  %i5, 0xff, %o2
a007cd08:  40 00 a9 e0  call  0xa00a7488
a007cd0c:  96 10 27 00  mov  0x700, %o3
a007cd10:  15 3f 3f ff  sethi  %hi(0xfcfffc00), %o2
a007cd14:  90 10 00 15  mov  %l5, %o0
a007cd18:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007cd1c:  92 14 e1 60  or  %l3, 0x160, %o1
a007cd20:  40 00 a9 da  call  0xa00a7488
a007cd24:  17 00 c0 00  sethi  %hi(0x3000000), %o3
a007cd28:  15 3c ff ff  sethi  %hi(0xf3fffc00), %o2
a007cd2c:  90 10 00 15  mov  %l5, %o0
a007cd30:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007cd34:  92 14 e1 60  or  %l3, 0x160, %o1
a007cd38:  40 00 a9 d4  call  0xa00a7488
a007cd3c:  17 01 00 00  sethi  %hi(0x4000000), %o3
a007cd40:  94 10 00 15  mov  %l5, %o2
a007cd44:  96 14 e1 60  or  %l3, 0x160, %o3
a007cd48:  90 10 20 00  clr  %o0
a007cd4c:  40 00 a9 b6  call  0xa00a7424
a007cd50:  92 10 20 1c  mov  0x1c, %o1
a007cd54:  94 10 00 15  mov  %l5, %o2
a007cd58:  96 14 e1 60  or  %l3, 0x160, %o3
a007cd5c:  90 10 20 01  mov  1, %o0
a007cd60:  40 00 a9 b1  call  0xa00a7424
a007cd64:  92 10 20 1d  mov  0x1d, %o1
a007cd68:  94 10 00 15  mov  %l5, %o2
a007cd6c:  96 14 e1 60  or  %l3, 0x160, %o3
a007cd70:  90 10 20 01  mov  1, %o0
a007cd74:  40 00 a9 ac  call  0xa00a7424
a007cd78:  92 10 20 1e  mov  0x1e, %o1
a007cd7c:  90 10 00 15  mov  %l5, %o0
a007cd80:  92 14 e1 f0  or  %l3, 0x1f0, %o1
a007cd84:  94 10 3f 00  mov  -256, %o2
a007cd88:  40 00 a9 c0  call  0xa00a7488
a007cd8c:  96 10 20 80  mov  0x80, %o3
a007cd90:  15 3f ff c3  sethi  %hi(0xffff0c00), %o2
a007cd94:  90 10 00 15  mov  %l5, %o0
a007cd98:  92 14 e1 f4  or  %l3, 0x1f4, %o1
a007cd9c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007cda0:  17 00 00 3c  sethi  %hi(0xf000), %o3
a007cda4:  40 00 a9 b9  call  0xa00a7488
a007cda8:  a0 0e 60 ff  and  %i1, 0xff, %l0
a007cdac:  30 80 00 08  b,a   0xa007cdcc
a007cdb0:  80 88 60 02  btst  2, %g1
a007cdb4:  02 80 00 06  be  0xa007cdcc
a007cdb8:  a0 0e 60 ff  and  %i1, 0xff, %l0
a007cdbc:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007cdc0:  7f ff d9 c1  call  0xa00734c4
a007cdc4:  90 12 23 10  or  %o0, 0x310, %o0	! 0xa0067b10
a007cdc8:  a0 0e 60 ff  and  %i1, 0xff, %l0
a007cdcc:  7f ff d9 d5  call  0xa0073520
a007cdd0:  90 10 00 10  mov  %l0, %o0
a007cdd4:  80 8a 20 ff  btst  0xff, %o0
a007cdd8:  02 80 00 12  be  0xa007ce20
a007cddc:  17 00 00 04  sethi  %hi(0x1000), %o3
a007cde0:  83 37 20 10  srl  %i4, 0x10, %g1
a007cde4:  80 a0 61 2c  cmp  %g1, 0x12c
a007cde8:  18 80 00 07  bgu  0xa007ce04
a007cdec:  13 00 00 07  sethi  %hi(0x1c00), %o1
a007cdf0:  92 12 63 44  or  %o1, 0x344, %o1	! 0x1f44
a007cdf4:  90 10 00 10  mov  %l0, %o0
a007cdf8:  94 10 3f c0  mov  -64, %o2
a007cdfc:  10 80 00 06  b  0xa007ce14
a007ce00:  96 10 20 1f  mov  0x1f, %o3
a007ce04:  92 12 63 44  or  %o1, 0x344, %o1
a007ce08:  90 10 00 10  mov  %l0, %o0
a007ce0c:  94 10 3f c0  mov  -64, %o2
a007ce10:  96 10 20 3f  mov  0x3f, %o3
a007ce14:  40 00 a9 9d  call  0xa00a7488
a007ce18:  01 00 00 00  nop
a007ce1c:  17 00 00 04  sethi  %hi(0x1000), %o3
a007ce20:  96 12 e1 40  or  %o3, 0x140, %o3	! 0x1140
a007ce24:  90 10 20 00  clr  %o0
a007ce28:  92 10 20 00  clr  %o1
a007ce2c:  40 00 a9 7e  call  0xa00a7424
a007ce30:  94 10 00 10  mov  %l0, %o2
a007ce34:  17 00 00 05  sethi  %hi(0x1400), %o3
a007ce38:  96 12 e1 40  or  %o3, 0x140, %o3	! 0x1540
a007ce3c:  90 10 20 01  mov  1, %o0
a007ce40:  92 10 20 00  clr  %o1
a007ce44:  40 00 a9 78  call  0xa00a7424
a007ce48:  94 10 00 10  mov  %l0, %o2
a007ce4c:  17 00 00 06  sethi  %hi(0x1800), %o3
a007ce50:  96 12 e1 40  or  %o3, 0x140, %o3	! 0x1940
a007ce54:  90 10 20 01  mov  1, %o0
a007ce58:  92 10 20 00  clr  %o1
a007ce5c:  40 00 a9 72  call  0xa00a7424
a007ce60:  94 10 00 10  mov  %l0, %o2
a007ce64:  90 10 00 10  mov  %l0, %o0
a007ce68:  13 00 00 07  sethi  %hi(0x1c00), %o1
a007ce6c:  94 10 3f 00  mov  -256, %o2
a007ce70:  40 00 a9 86  call  0xa00a7488
a007ce74:  96 10 20 00  clr  %o3
a007ce78:  40 00 d2 47  call  0xa00b1794
a007ce7c:  90 10 20 01  mov  1, %o0
a007ce80:  9a 04 00 10  add  %l0, %l0, %o5
a007ce84:  9a 03 40 10  add  %o5, %l0, %o5
a007ce88:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a007ce8c:  9b 2b 60 02  sll  %o5, 2, %o5
a007ce90:  98 10 20 04  mov  4, %o4
a007ce94:  82 10 60 c4  or  %g1, 0xc4, %g1
a007ce98:  d8 20 40 0d  st  %o4, [ %g1 + %o5 ]
a007ce9c:  81 c7 e0 08  ret
a007cea0:  91 e8 20 00  restore  %g0, 0, %o0
