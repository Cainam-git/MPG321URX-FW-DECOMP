# leon2s DRV_HDMI21_LTS_STS_InitialSettings 0xa009b5f4-0xa009bba8 (1460 bytes)  [FUN_a009bba0 = unreachable ret/restore tail, merged]
a009b5f4:  9d e3 bf 98  save  %sp, -104, %sp
a009b5f8:  a8 0e 20 ff  and  %i0, 0xff, %l4
a009b5fc:  80 a5 20 00  cmp  %l4, 0
a009b600:  02 80 00 05  be  0xa009b614
a009b604:  a0 10 20 02  mov  2, %l0
a009b608:  80 a5 20 01  cmp  %l4, 1
a009b60c:  12 80 01 64  bne  0xa009bb9c
a009b610:  a0 10 20 03  mov  3, %l0
a009b614:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009b618:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009b61c:  80 88 68 00  btst  0x800, %g1
a009b620:  02 80 00 09  be  0xa009b644
a009b624:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009b628:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009b62c:  13 28 02 d0  sethi  %hi(0xa00b4000), %o1
a009b630:  90 12 21 b0  or  %o0, 0x1b0, %o0
a009b634:  92 12 63 d0  or  %o1, 0x3d0, %o1
a009b638:  7f ff 5e 83  call  0xa0073044
a009b63c:  94 10 00 14  mov  %l4, %o2
a009b640:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009b644:  9a 13 62 80  or  %o5, 0x280, %o5	! 0xa807d680
a009b648:  98 5d 20 b0  smul  %l4, 0xb0, %o4
a009b64c:  82 03 00 0d  add  %o4, %o5, %g1
a009b650:  c0 28 60 01  clrb  [ %g1 + 1 ]
a009b654:  c0 28 60 02  clrb  [ %g1 + 2 ]
a009b658:  c0 28 60 14  clrb  [ %g1 + 0x14 ]
a009b65c:  96 10 00 01  mov  %g1, %o3
a009b660:  c0 2b 40 0c  clrb  [ %o5 + %o4 ]
a009b664:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009b668:  b0 10 00 14  mov  %l4, %i0
a009b66c:  9e 10 00 0d  mov  %o5, %o7
a009b670:  d0 08 62 40  ldub  [ %g1 + 0x240 ], %o0
a009b674:  94 10 20 00  clr  %o2
a009b678:  92 5d 20 2c  smul  %l4, 0x2c, %o1
a009b67c:  82 0a a0 ff  and  %o2, 0xff, %g1
a009b680:  9a 02 40 01  add  %o1, %g1, %o5
a009b684:  9b 2b 60 02  sll  %o5, 2, %o5
a009b688:  94 02 a0 01  inc  %o2
a009b68c:  82 02 c0 01  add  %o3, %g1, %g1
a009b690:  9a 03 40 0f  add  %o5, %o7, %o5
a009b694:  98 0a a0 ff  and  %o2, 0xff, %o4
a009b698:  d0 28 60 03  stb  %o0, [ %g1 + 3 ]
a009b69c:  c0 33 60 1c  clrh  [ %o5 + 0x1c ]
a009b6a0:  80 a3 20 03  cmp  %o4, 3
a009b6a4:  c0 28 60 07  clrb  [ %g1 + 7 ]
a009b6a8:  c0 28 60 0b  clrb  [ %g1 + 0xb ]
a009b6ac:  c0 28 60 0f  clrb  [ %g1 + 0xf ]
a009b6b0:  08 bf ff f3  bleu  0xa009b67c
a009b6b4:  c0 33 60 1a  clrh  [ %o5 + 0x1a ]
a009b6b8:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009b6bc:  9b 2e 20 02  sll  %i0, 2, %o5
a009b6c0:  82 10 60 6c  or  %g1, 0x6c, %g1
a009b6c4:  c0 20 40 0d  clr  [ %g1 + %o5 ]
a009b6c8:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009b6cc:  82 10 60 74  or  %g1, 0x74, %g1	! 0xa8079074
a009b6d0:  c0 2a e0 39  clrb  [ %o3 + 0x39 ]
a009b6d4:  c0 20 40 0d  clr  [ %g1 + %o5 ]
a009b6d8:  a0 0c 20 ff  and  %l0, 0xff, %l0
a009b6dc:  29 00 00 08  sethi  %hi(0x2000), %l4
a009b6e0:  c0 2a e0 13  clrb  [ %o3 + 0x13 ]
a009b6e4:  c0 2a e0 2a  clrb  [ %o3 + 0x2a ]
a009b6e8:  c0 2a e0 2b  clrb  [ %o3 + 0x2b ]
a009b6ec:  c0 2a e0 34  clrb  [ %o3 + 0x34 ]
a009b6f0:  c0 2a e0 35  clrb  [ %o3 + 0x35 ]
a009b6f4:  c0 2a e0 36  clrb  [ %o3 + 0x36 ]
a009b6f8:  c0 2a e0 37  clrb  [ %o3 + 0x37 ]
a009b6fc:  c0 2a e0 38  clrb  [ %o3 + 0x38 ]
a009b700:  96 15 20 70  or  %l4, 0x70, %o3
a009b704:  90 10 20 00  clr  %o0
a009b708:  92 10 20 03  mov  3, %o1
a009b70c:  40 00 2f 46  call  0xa00a7424
a009b710:  94 10 00 10  mov  %l0, %o2
a009b714:  2f 00 00 09  sethi  %hi(0x2400), %l7
a009b718:  90 10 20 00  clr  %o0
a009b71c:  92 10 20 03  mov  3, %o1
a009b720:  94 10 00 10  mov  %l0, %o2
a009b724:  40 00 2f 40  call  0xa00a7424
a009b728:  96 15 e0 70  or  %l7, 0x70, %o3
a009b72c:  2d 00 00 0a  sethi  %hi(0x2800), %l6
a009b730:  90 10 20 00  clr  %o0
a009b734:  92 10 20 03  mov  3, %o1
a009b738:  94 10 00 10  mov  %l0, %o2
a009b73c:  40 00 2f 3a  call  0xa00a7424
a009b740:  96 15 a0 70  or  %l6, 0x70, %o3
a009b744:  2b 00 00 0c  sethi  %hi(0x3000), %l5
a009b748:  90 10 20 00  clr  %o0
a009b74c:  92 10 20 03  mov  3, %o1
a009b750:  94 10 00 10  mov  %l0, %o2
a009b754:  40 00 2f 34  call  0xa00a7424
a009b758:  96 15 60 70  or  %l5, 0x70, %o3
a009b75c:  23 3f f3 ff  sethi  %hi(0xffcffc00), %l1
a009b760:  92 15 20 60  or  %l4, 0x60, %o1
a009b764:  94 14 63 ff  or  %l1, 0x3ff, %o2
a009b768:  90 10 00 10  mov  %l0, %o0
a009b76c:  40 00 2f 47  call  0xa00a7488
a009b770:  96 10 20 00  clr  %o3
a009b774:  94 14 63 ff  or  %l1, 0x3ff, %o2
a009b778:  90 10 00 10  mov  %l0, %o0
a009b77c:  92 15 e0 60  or  %l7, 0x60, %o1
a009b780:  40 00 2f 42  call  0xa00a7488
a009b784:  96 10 20 00  clr  %o3
a009b788:  94 14 63 ff  or  %l1, 0x3ff, %o2
a009b78c:  90 10 00 10  mov  %l0, %o0
a009b790:  92 15 a0 60  or  %l6, 0x60, %o1
a009b794:  40 00 2f 3d  call  0xa00a7488
a009b798:  96 10 20 00  clr  %o3
a009b79c:  94 14 63 ff  or  %l1, 0x3ff, %o2
a009b7a0:  90 10 00 10  mov  %l0, %o0
a009b7a4:  92 15 60 60  or  %l5, 0x60, %o1
a009b7a8:  40 00 2f 38  call  0xa00a7488
a009b7ac:  96 10 20 00  clr  %o3
a009b7b0:  96 15 20 28  or  %l4, 0x28, %o3
a009b7b4:  90 10 20 00  clr  %o0
a009b7b8:  92 10 20 18  mov  0x18, %o1
a009b7bc:  40 00 2f 1a  call  0xa00a7424
a009b7c0:  94 10 00 10  mov  %l0, %o2
a009b7c4:  96 15 20 28  or  %l4, 0x28, %o3
a009b7c8:  90 10 20 00  clr  %o0
a009b7cc:  92 10 20 11  mov  0x11, %o1
a009b7d0:  40 00 2f 15  call  0xa00a7424
a009b7d4:  94 10 00 10  mov  %l0, %o2
a009b7d8:  90 10 20 00  clr  %o0
a009b7dc:  92 10 20 11  mov  0x11, %o1
a009b7e0:  94 10 00 10  mov  %l0, %o2
a009b7e4:  40 00 2f 10  call  0xa00a7424
a009b7e8:  96 15 e0 28  or  %l7, 0x28, %o3
a009b7ec:  90 10 20 00  clr  %o0
a009b7f0:  92 10 20 11  mov  0x11, %o1
a009b7f4:  94 10 00 10  mov  %l0, %o2
a009b7f8:  40 00 2f 0b  call  0xa00a7424
a009b7fc:  96 15 a0 28  or  %l6, 0x28, %o3
a009b800:  90 10 20 00  clr  %o0
a009b804:  92 10 20 11  mov  0x11, %o1
a009b808:  94 10 00 10  mov  %l0, %o2
a009b80c:  96 15 60 28  or  %l5, 0x28, %o3
a009b810:  40 00 2f 05  call  0xa00a7424
a009b814:  25 00 00 0b  sethi  %hi(0x2c00), %l2
a009b818:  90 10 20 00  clr  %o0
a009b81c:  92 10 20 13  mov  0x13, %o1
a009b820:  94 10 00 10  mov  %l0, %o2
a009b824:  40 00 2f 00  call  0xa00a7424
a009b828:  96 14 a0 34  or  %l2, 0x34, %o3
a009b82c:  90 10 20 01  mov  1, %o0
a009b830:  92 10 20 19  mov  0x19, %o1
a009b834:  94 10 00 10  mov  %l0, %o2
a009b838:  40 00 2e fb  call  0xa00a7424
a009b83c:  96 14 a0 34  or  %l2, 0x34, %o3
a009b840:  90 10 20 00  clr  %o0
a009b844:  92 10 20 10  mov  0x10, %o1
a009b848:  94 10 00 10  mov  %l0, %o2
a009b84c:  40 00 2e f6  call  0xa00a7424
a009b850:  96 14 a0 34  or  %l2, 0x34, %o3
a009b854:  90 10 20 00  clr  %o0
a009b858:  92 10 20 11  mov  0x11, %o1
a009b85c:  94 10 00 10  mov  %l0, %o2
a009b860:  40 00 2e f1  call  0xa00a7424
a009b864:  96 14 a0 34  or  %l2, 0x34, %o3
a009b868:  90 10 20 00  clr  %o0
a009b86c:  92 10 20 12  mov  0x12, %o1
a009b870:  94 10 00 10  mov  %l0, %o2
a009b874:  40 00 2e ec  call  0xa00a7424
a009b878:  96 14 a0 34  or  %l2, 0x34, %o3
a009b87c:  15 3f fc 3f  sethi  %hi(0xfff0fc00), %o2
a009b880:  90 10 00 10  mov  %l0, %o0
a009b884:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a009b888:  92 14 a0 30  or  %l2, 0x30, %o1
a009b88c:  40 00 2e ff  call  0xa00a7488
a009b890:  17 00 02 c0  sethi  %hi(0xb0000), %o3
a009b894:  15 3f c3 ff  sethi  %hi(0xff0ffc00), %o2
a009b898:  90 10 00 10  mov  %l0, %o0
a009b89c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a009b8a0:  92 14 a0 30  or  %l2, 0x30, %o1
a009b8a4:  40 00 2e f9  call  0xa00a7488
a009b8a8:  17 00 10 00  sethi  %hi(0x400000), %o3
a009b8ac:  15 3c 3f ff  sethi  %hi(0xf0fffc00), %o2
a009b8b0:  90 10 00 10  mov  %l0, %o0
a009b8b4:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a009b8b8:  92 14 a0 30  or  %l2, 0x30, %o1
a009b8bc:  40 00 2e f3  call  0xa00a7488
a009b8c0:  17 03 40 00  sethi  %hi(0xd000000), %o3
a009b8c4:  15 03 ff ff  sethi  %hi(0xffffc00), %o2
a009b8c8:  90 10 00 10  mov  %l0, %o0
a009b8cc:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a009b8d0:  92 14 a0 30  or  %l2, 0x30, %o1
a009b8d4:  40 00 2e ed  call  0xa00a7488
a009b8d8:  17 08 00 00  sethi  %hi(0x20000000), %o3
a009b8dc:  90 10 20 00  clr  %o0
a009b8e0:  92 10 20 00  clr  %o1
a009b8e4:  94 10 00 10  mov  %l0, %o2
a009b8e8:  40 00 2e cf  call  0xa00a7424
a009b8ec:  96 14 a0 30  or  %l2, 0x30, %o3
a009b8f0:  15 3f c7 ff  sethi  %hi(0xff1ffc00), %o2
a009b8f4:  90 10 00 10  mov  %l0, %o0
a009b8f8:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a009b8fc:  92 14 a0 34  or  %l2, 0x34, %o1
a009b900:  40 00 2e e2  call  0xa00a7488
a009b904:  17 00 30 00  sethi  %hi(0xc00000), %o3
a009b908:  90 10 00 10  mov  %l0, %o0
a009b90c:  92 14 a0 38  or  %l2, 0x38, %o1
a009b910:  94 10 31 ff  mov  -3585, %o2
a009b914:  40 00 2e dd  call  0xa00a7488
a009b918:  96 10 20 00  clr  %o3
a009b91c:  90 10 00 10  mov  %l0, %o0
a009b920:  92 14 a0 34  or  %l2, 0x34, %o1
a009b924:  94 10 33 ff  mov  -3073, %o2
a009b928:  40 00 2e d8  call  0xa00a7488
a009b92c:  96 10 20 00  clr  %o3
a009b930:  90 10 20 00  clr  %o0
a009b934:  92 10 20 12  mov  0x12, %o1
a009b938:  94 10 00 10  mov  %l0, %o2
a009b93c:  40 00 2e ba  call  0xa00a7424
a009b940:  96 14 a0 34  or  %l2, 0x34, %o3
a009b944:  15 3f 3f ff  sethi  %hi(0xfcfffc00), %o2
a009b948:  90 10 00 10  mov  %l0, %o0
a009b94c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a009b950:  92 14 a0 24  or  %l2, 0x24, %o1
a009b954:  40 00 2e cd  call  0xa00a7488
a009b958:  96 10 20 00  clr  %o3
a009b95c:  90 10 20 00  clr  %o0
a009b960:  92 10 20 05  mov  5, %o1
a009b964:  94 10 00 10  mov  %l0, %o2
a009b968:  40 00 2e af  call  0xa00a7424
a009b96c:  96 14 a0 20  or  %l2, 0x20, %o3
a009b970:  90 10 20 00  clr  %o0
a009b974:  92 10 20 04  mov  4, %o1
a009b978:  94 10 00 10  mov  %l0, %o2
a009b97c:  40 00 2e aa  call  0xa00a7424
a009b980:  96 14 a0 20  or  %l2, 0x20, %o3
a009b984:  27 00 00 0d  sethi  %hi(0x3400), %l3
a009b988:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a009b98c:  92 14 e1 34  or  %l3, 0x134, %o1
a009b990:  90 10 00 10  mov  %l0, %o0
a009b994:  94 12 a0 ff  or  %o2, 0xff, %o2
a009b998:  40 00 2e bc  call  0xa00a7488
a009b99c:  17 00 00 10  sethi  %hi(0x4000), %o3
a009b9a0:  23 3f cf ff  sethi  %hi(0xff3ffc00), %l1
a009b9a4:  92 15 20 60  or  %l4, 0x60, %o1
a009b9a8:  94 14 63 ff  or  %l1, 0x3ff, %o2
a009b9ac:  90 10 00 10  mov  %l0, %o0
a009b9b0:  40 00 2e b6  call  0xa00a7488
a009b9b4:  17 00 20 00  sethi  %hi(0x800000), %o3
a009b9b8:  94 14 63 ff  or  %l1, 0x3ff, %o2
a009b9bc:  90 10 00 10  mov  %l0, %o0
a009b9c0:  92 15 e0 60  or  %l7, 0x60, %o1
a009b9c4:  40 00 2e b1  call  0xa00a7488
a009b9c8:  17 00 20 00  sethi  %hi(0x800000), %o3
a009b9cc:  94 14 63 ff  or  %l1, 0x3ff, %o2
a009b9d0:  90 10 00 10  mov  %l0, %o0
a009b9d4:  92 15 a0 60  or  %l6, 0x60, %o1
a009b9d8:  40 00 2e ac  call  0xa00a7488
a009b9dc:  17 00 20 00  sethi  %hi(0x800000), %o3
a009b9e0:  94 14 63 ff  or  %l1, 0x3ff, %o2
a009b9e4:  90 10 00 10  mov  %l0, %o0
a009b9e8:  92 15 60 60  or  %l5, 0x60, %o1
a009b9ec:  40 00 2e a7  call  0xa00a7488
a009b9f0:  17 00 20 00  sethi  %hi(0x800000), %o3
a009b9f4:  23 3f c0 3f  sethi  %hi(0xff00fc00), %l1
a009b9f8:  92 15 20 68  or  %l4, 0x68, %o1
a009b9fc:  94 14 63 ff  or  %l1, 0x3ff, %o2
a009ba00:  90 10 00 10  mov  %l0, %o0
a009ba04:  40 00 2e a1  call  0xa00a7488
a009ba08:  17 00 04 c0  sethi  %hi(0x130000), %o3
a009ba0c:  94 14 63 ff  or  %l1, 0x3ff, %o2
a009ba10:  90 10 00 10  mov  %l0, %o0
a009ba14:  92 15 e0 68  or  %l7, 0x68, %o1
a009ba18:  40 00 2e 9c  call  0xa00a7488
a009ba1c:  17 00 04 c0  sethi  %hi(0x130000), %o3
a009ba20:  94 14 63 ff  or  %l1, 0x3ff, %o2
a009ba24:  90 10 00 10  mov  %l0, %o0
a009ba28:  92 15 a0 68  or  %l6, 0x68, %o1
a009ba2c:  40 00 2e 97  call  0xa00a7488
a009ba30:  17 00 04 c0  sethi  %hi(0x130000), %o3
a009ba34:  94 14 63 ff  or  %l1, 0x3ff, %o2
a009ba38:  90 10 00 10  mov  %l0, %o0
a009ba3c:  92 15 60 68  or  %l5, 0x68, %o1
a009ba40:  40 00 2e 92  call  0xa00a7488
a009ba44:  17 00 04 c0  sethi  %hi(0x130000), %o3
a009ba48:  96 14 e2 08  or  %l3, 0x208, %o3
a009ba4c:  90 10 20 00  clr  %o0
a009ba50:  92 10 20 04  mov  4, %o1
a009ba54:  40 00 2e 74  call  0xa00a7424
a009ba58:  94 10 00 10  mov  %l0, %o2
a009ba5c:  96 14 e2 18  or  %l3, 0x218, %o3
a009ba60:  90 10 20 00  clr  %o0
a009ba64:  92 10 20 1d  mov  0x1d, %o1
a009ba68:  40 00 2e 6f  call  0xa00a7424
a009ba6c:  94 10 00 10  mov  %l0, %o2
a009ba70:  96 14 e2 18  or  %l3, 0x218, %o3
a009ba74:  90 10 20 01  mov  1, %o0
a009ba78:  92 10 20 1c  mov  0x1c, %o1
a009ba7c:  40 00 2e 6a  call  0xa00a7424
a009ba80:  94 10 00 10  mov  %l0, %o2
a009ba84:  92 14 e2 18  or  %l3, 0x218, %o1
a009ba88:  15 3e 3f ff  sethi  %hi(0xf8fffc00), %o2
a009ba8c:  94 12 a3 ff  or  %o2, 0x3ff, %o2	! 0xf8ffffff
a009ba90:  17 00 c0 00  sethi  %hi(0x3000000), %o3
a009ba94:  90 10 00 10  mov  %l0, %o0
a009ba98:  40 00 2e 7c  call  0xa00a7488
a009ba9c:  27 2a 01 f6  sethi  %hi(0xa807d800), %l3
a009baa0:  a8 5e 20 34  smul  %i0, 0x34, %l4
a009baa4:  a6 14 e3 00  or  %l3, 0x300, %l3
a009baa8:  d2 04 c0 14  ld  [ %l3 + %l4 ], %o1
a009baac:  92 02 60 04  add  %o1, 4, %o1
a009bab0:  90 10 20 15  mov  0x15, %o0
a009bab4:  40 00 2e 3e  call  0xa00a73ac
a009bab8:  a2 05 00 13  add  %l4, %l3, %l1
a009babc:  d2 04 60 0c  ld  [ %l1 + 0xc ], %o1
a009bac0:  92 02 60 60  add  %o1, 0x60, %o1
a009bac4:  40 00 2e 44  call  0xa00a73d4
a009bac8:  90 10 20 00  clr  %o0
a009bacc:  d2 04 60 0c  ld  [ %l1 + 0xc ], %o1
a009bad0:  92 02 60 60  add  %o1, 0x60, %o1
a009bad4:  40 00 2e 40  call  0xa00a73d4
a009bad8:  90 10 20 01  mov  1, %o0
a009badc:  d2 04 60 0c  ld  [ %l1 + 0xc ], %o1
a009bae0:  92 02 60 60  add  %o1, 0x60, %o1
a009bae4:  40 00 2e 3c  call  0xa00a73d4
a009bae8:  90 10 20 02  mov  2, %o0
a009baec:  d2 04 60 18  ld  [ %l1 + 0x18 ], %o1
a009baf0:  92 02 60 80  add  %o1, 0x80, %o1
a009baf4:  40 00 2e 38  call  0xa00a73d4
a009baf8:  90 10 20 03  mov  3, %o0
a009bafc:  d2 04 60 18  ld  [ %l1 + 0x18 ], %o1
a009bb00:  92 02 60 80  add  %o1, 0x80, %o1
a009bb04:  40 00 2e 34  call  0xa00a73d4
a009bb08:  90 10 20 04  mov  4, %o0
a009bb0c:  d2 04 60 18  ld  [ %l1 + 0x18 ], %o1
a009bb10:  92 02 60 80  add  %o1, 0x80, %o1
a009bb14:  40 00 2e 30  call  0xa00a73d4
a009bb18:  90 10 20 05  mov  5, %o0
a009bb1c:  d2 04 60 18  ld  [ %l1 + 0x18 ], %o1
a009bb20:  92 02 60 80  add  %o1, 0x80, %o1
a009bb24:  40 00 2e 2c  call  0xa00a73d4
a009bb28:  90 10 20 06  mov  6, %o0
a009bb2c:  d2 04 60 18  ld  [ %l1 + 0x18 ], %o1
a009bb30:  92 02 60 80  add  %o1, 0x80, %o1
a009bb34:  40 00 2e 28  call  0xa00a73d4
a009bb38:  90 10 20 07  mov  7, %o0
a009bb3c:  d2 04 60 18  ld  [ %l1 + 0x18 ], %o1
a009bb40:  92 02 60 90  add  %o1, 0x90, %o1
a009bb44:  40 00 2e 24  call  0xa00a73d4
a009bb48:  90 10 20 11  mov  0x11, %o0
a009bb4c:  7f ff 7c 12  call  0xa007ab94
a009bb50:  90 10 00 10  mov  %l0, %o0
a009bb54:  7f ff 5e ec  call  0xa0073704
a009bb58:  90 10 00 10  mov  %l0, %o0
a009bb5c:  d2 04 c0 14  ld  [ %l3 + %l4 ], %o1
a009bb60:  92 02 60 08  add  %o1, 8, %o1
a009bb64:  40 00 2e 1c  call  0xa00a73d4
a009bb68:  90 10 20 0b  mov  0xb, %o0
a009bb6c:  90 10 20 0d  mov  0xd, %o0
a009bb70:  40 00 2e 19  call  0xa00a73d4
a009bb74:  d2 04 60 18  ld  [ %l1 + 0x18 ], %o1
a009bb78:  94 10 00 10  mov  %l0, %o2
a009bb7c:  96 14 a2 60  or  %l2, 0x260, %o3
a009bb80:  90 10 20 00  clr  %o0
a009bb84:  40 00 2e 28  call  0xa00a7424
a009bb88:  92 10 20 14  mov  0x14, %o1
a009bb8c:  f2 04 60 0c  ld  [ %l1 + 0xc ], %i1
a009bb90:  b2 06 60 7c  add  %i1, 0x7c, %i1
a009bb94:  40 00 2e 10  call  0xa00a73d4
a009bb98:  91 e8 20 0b  restore  %g0, 0xb, %o0
a009bb9c:  01 00 00 00  nop
a009bba0:  81 c7 e0 08  ret
a009bba4:  81 e8 00 00  restore
