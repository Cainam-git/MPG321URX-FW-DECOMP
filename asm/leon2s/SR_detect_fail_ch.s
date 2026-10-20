# leon2s SR_detect_fail_ch 0xa009a698-0xa009ae98 (2048 bytes)
a009a698:  9d e3 bf 98  save  %sp, -104, %sp
a009a69c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a009a6a0:  ae 10 00 18  mov  %i0, %l7
a009a6a4:  80 a4 20 00  cmp  %l0, 0
a009a6a8:  ac 10 20 00  clr  %l6
a009a6ac:  a4 10 20 00  clr  %l2
a009a6b0:  02 80 00 06  be  0xa009a6c8
a009a6b4:  a8 10 20 02  mov  2, %l4
a009a6b8:  b0 10 20 00  clr  %i0
a009a6bc:  80 a4 20 01  cmp  %l0, 1
a009a6c0:  12 80 01 f4  bne  0xa009ae90
a009a6c4:  a8 10 20 03  mov  3, %l4
a009a6c8:  7f ff ff ae  call  0xa009a580
a009a6cc:  90 10 00 10  mov  %l0, %o0
a009a6d0:  19 2a 01 f5  sethi  %hi(0xa807d400), %o4
a009a6d4:  9a 13 22 80  or  %o4, 0x280, %o5	! 0xa807d680
a009a6d8:  82 5c 20 b0  smul  %l0, 0xb0, %g1
a009a6dc:  82 00 40 0d  add  %g1, %o5, %g1
a009a6e0:  c2 08 60 02  ldub  [ %g1 + 2 ], %g1
a009a6e4:  9a 08 60 ff  and  %g1, 0xff, %o5
a009a6e8:  80 a3 60 06  cmp  %o5, 6
a009a6ec:  12 80 00 04  bne  0xa009a6fc
a009a6f0:  80 a3 60 05  cmp  %o5, 5
a009a6f4:  10 80 00 16  b  0xa009a74c
a009a6f8:  a4 10 24 b0  mov  0x4b0, %l2
a009a6fc:  12 80 00 04  bne  0xa009a70c
a009a700:  80 a3 60 04  cmp  %o5, 4
a009a704:  10 80 00 12  b  0xa009a74c
a009a708:  a4 10 23 e8  mov  0x3e8, %l2
a009a70c:  12 80 00 04  bne  0xa009a71c
a009a710:  82 00 7f fe  add  %g1, -2, %g1
a009a714:  10 80 00 0e  b  0xa009a74c
a009a718:  a4 10 23 20  mov  0x320, %l2
a009a71c:  82 08 60 ff  and  %g1, 0xff, %g1
a009a720:  80 a0 60 01  cmp  %g1, 1
a009a724:  18 80 00 08  bgu  0xa009a744
a009a728:  80 a3 60 01  cmp  %o5, 1
a009a72c:  10 80 00 08  b  0xa009a74c
a009a730:  a4 10 22 58  mov  0x258, %l2
a009a734:  7f ff 96 c4  call  0xa0080244
a009a738:  90 0d 20 03  and  %l4, 3, %o0
a009a73c:  10 80 00 1a  b  0xa009a7a4
a009a740:  a4 0d 20 ff  and  %l4, 0xff, %l2
a009a744:  22 80 00 02  be,a   0xa009a74c
a009a748:  a4 10 21 2c  mov  0x12c, %l2
a009a74c:  9a 13 22 80  or  %o4, 0x280, %o5
a009a750:  82 5c 20 b0  smul  %l0, 0xb0, %g1
a009a754:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a009a758:  80 a3 60 00  cmp  %o5, 0
a009a75c:  02 80 00 11  be  0xa009a7a0
a009a760:  a2 10 20 00  clr  %l1
a009a764:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009a768:  94 10 60 5a  or  %g1, 0x5a, %o2	! 0xa807905a
a009a76c:  91 2c 20 02  sll  %l0, 2, %o0
a009a770:  96 0c a7 fc  and  %l2, 0x7fc, %o3
a009a774:  82 0c 60 ff  and  %l1, 0xff, %g1
a009a778:  82 02 00 01  add  %o0, %g1, %g1
a009a77c:  82 00 40 01  add  %g1, %g1, %g1
a009a780:  a2 04 60 01  inc  %l1
a009a784:  c2 12 80 01  lduh  [ %o2 + %g1 ], %g1
a009a788:  80 a0 40 0b  cmp  %g1, %o3
a009a78c:  12 bf ff ea  bne  0xa009a734
a009a790:  98 0c 60 ff  and  %l1, 0xff, %o4
a009a794:  80 a3 00 0d  cmp  %o4, %o5
a009a798:  0a bf ff f8  bcs  0xa009a778
a009a79c:  82 0c 60 ff  and  %l1, 0xff, %g1
a009a7a0:  a4 0d 20 ff  and  %l4, 0xff, %l2
a009a7a4:  27 00 00 0b  sethi  %hi(0x2c00), %l3
a009a7a8:  90 10 00 12  mov  %l2, %o0
a009a7ac:  92 14 e2 5c  or  %l3, 0x25c, %o1
a009a7b0:  94 10 3f 0f  mov  -241, %o2
a009a7b4:  96 10 20 00  clr  %o3
a009a7b8:  31 2a 01 f5  sethi  %hi(0xa807d400), %i0
a009a7bc:  40 00 33 33  call  0xa00a7488
a009a7c0:  aa 0d e0 ff  and  %l7, 0xff, %l5
a009a7c4:  a2 16 22 80  or  %i0, 0x280, %l1
a009a7c8:  a0 5d 60 b0  smul  %l5, 0xb0, %l0
a009a7cc:  82 04 00 11  add  %l0, %l1, %g1
a009a7d0:  c2 08 60 3a  ldub  [ %g1 + 0x3a ], %g1
a009a7d4:  82 18 60 01  xor  %g1, 1, %g1
a009a7d8:  80 a0 00 01  cmp  %g0, %g1
a009a7dc:  90 60 3f ff  subx  %g0, -1, %o0
a009a7e0:  94 10 00 12  mov  %l2, %o2
a009a7e4:  96 14 e1 08  or  %l3, 0x108, %o3
a009a7e8:  40 00 33 0f  call  0xa00a7424
a009a7ec:  92 10 20 1c  mov  0x1c, %o1
a009a7f0:  c2 0c 40 10  ldub  [ %l1 + %l0 ], %g1
a009a7f4:  80 a0 60 00  cmp  %g1, 0
a009a7f8:  02 80 00 26  be  0xa009a890
a009a7fc:  a2 10 20 00  clr  %l1
a009a800:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a009a804:  82 0c 60 ff  and  %l1, 0xff, %g1
a009a808:  96 12 e2 08  or  %o3, 0x208, %o3
a009a80c:  90 10 20 00  clr  %o0
a009a810:  92 10 20 0e  mov  0xe, %o1
a009a814:  80 a0 60 00  cmp  %g1, 0
a009a818:  02 80 00 14  be  0xa009a868
a009a81c:  94 0d 20 ff  and  %l4, 0xff, %o2
a009a820:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a009a824:  96 12 e2 18  or  %o3, 0x218, %o3	! 0x2e18
a009a828:  90 10 20 00  clr  %o0
a009a82c:  80 a0 60 01  cmp  %g1, 1
a009a830:  02 80 00 0e  be  0xa009a868
a009a834:  01 00 00 00  nop
a009a838:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a009a83c:  96 12 e2 28  or  %o3, 0x228, %o3	! 0x2e28
a009a840:  90 10 20 00  clr  %o0
a009a844:  80 a0 60 02  cmp  %g1, 2
a009a848:  02 80 00 08  be  0xa009a868
a009a84c:  01 00 00 00  nop
a009a850:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a009a854:  80 a0 60 03  cmp  %g1, 3
a009a858:  96 12 e2 38  or  %o3, 0x238, %o3
a009a85c:  90 10 20 00  clr  %o0
a009a860:  12 80 00 04  bne  0xa009a870
a009a864:  01 00 00 00  nop
a009a868:  40 00 32 ef  call  0xa00a7424
a009a86c:  01 00 00 00  nop
a009a870:  82 5d 60 b0  smul  %l5, 0xb0, %g1
a009a874:  9a 16 22 80  or  %i0, 0x280, %o5
a009a878:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a009a87c:  a2 04 60 01  inc  %l1
a009a880:  82 0c 60 ff  and  %l1, 0xff, %g1
a009a884:  80 a0 40 0d  cmp  %g1, %o5
a009a888:  0a bf ff e0  bcs  0xa009a808
a009a88c:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a009a890:  25 2a 01 f5  sethi  %hi(0xa807d400), %l2
a009a894:  a0 0d e0 ff  and  %l7, 0xff, %l0
a009a898:  82 14 a2 80  or  %l2, 0x280, %g1
a009a89c:  9a 5c 20 b0  smul  %l0, 0xb0, %o5
a009a8a0:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a009a8a4:  80 a0 60 00  cmp  %g1, 0
a009a8a8:  02 80 00 26  be  0xa009a940
a009a8ac:  a2 10 20 00  clr  %l1
a009a8b0:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a009a8b4:  82 0c 60 ff  and  %l1, 0xff, %g1
a009a8b8:  96 12 e2 08  or  %o3, 0x208, %o3
a009a8bc:  90 10 20 01  mov  1, %o0
a009a8c0:  92 10 20 0e  mov  0xe, %o1
a009a8c4:  80 a0 60 00  cmp  %g1, 0
a009a8c8:  02 80 00 14  be  0xa009a918
a009a8cc:  94 0d 20 ff  and  %l4, 0xff, %o2
a009a8d0:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a009a8d4:  96 12 e2 18  or  %o3, 0x218, %o3	! 0x2e18
a009a8d8:  90 10 20 01  mov  1, %o0
a009a8dc:  80 a0 60 01  cmp  %g1, 1
a009a8e0:  02 80 00 0e  be  0xa009a918
a009a8e4:  01 00 00 00  nop
a009a8e8:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a009a8ec:  96 12 e2 28  or  %o3, 0x228, %o3	! 0x2e28
a009a8f0:  90 10 20 01  mov  1, %o0
a009a8f4:  80 a0 60 02  cmp  %g1, 2
a009a8f8:  02 80 00 08  be  0xa009a918
a009a8fc:  01 00 00 00  nop
a009a900:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a009a904:  80 a0 60 03  cmp  %g1, 3
a009a908:  96 12 e2 38  or  %o3, 0x238, %o3
a009a90c:  90 10 20 01  mov  1, %o0
a009a910:  12 80 00 04  bne  0xa009a920
a009a914:  01 00 00 00  nop
a009a918:  40 00 32 c3  call  0xa00a7424
a009a91c:  01 00 00 00  nop
a009a920:  82 5c 20 b0  smul  %l0, 0xb0, %g1
a009a924:  9a 14 a2 80  or  %l2, 0x280, %o5
a009a928:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a009a92c:  a2 04 60 01  inc  %l1
a009a930:  82 0c 60 ff  and  %l1, 0xff, %g1
a009a934:  80 a0 40 0d  cmp  %g1, %o5
a009a938:  0a bf ff e0  bcs  0xa009a8b8
a009a93c:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a009a940:  40 00 5b 95  call  0xa00b1794
a009a944:  90 10 20 01  mov  1, %o0
a009a948:  a2 0d 20 ff  and  %l4, 0xff, %l1
a009a94c:  15 00 00 0b  sethi  %hi(0x2c00), %o2
a009a950:  94 12 a2 08  or  %o2, 0x208, %o2	! 0x2e08
a009a954:  90 10 20 15  mov  0x15, %o0
a009a958:  40 00 32 c4  call  0xa00a7468
a009a95c:  92 10 00 11  mov  %l1, %o1
a009a960:  80 a2 20 00  cmp  %o0, 0
a009a964:  12 80 00 0d  bne  0xa009a998
a009a968:  15 00 00 0b  sethi  %hi(0x2c00), %o2
a009a96c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009a970:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009a974:  80 88 68 00  btst  0x800, %g1
a009a978:  02 80 00 08  be  0xa009a998
a009a97c:  ac 10 20 01  mov  1, %l6
a009a980:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009a984:  90 12 22 c8  or  %o0, 0x2c8, %o0	! 0xa006a2c8
a009a988:  7f ff 61 af  call  0xa0073044
a009a98c:  92 10 20 00  clr  %o1
a009a990:  ac 10 20 01  mov  1, %l6
a009a994:  15 00 00 0b  sethi  %hi(0x2c00), %o2
a009a998:  94 12 a2 18  or  %o2, 0x218, %o2	! 0x2e18
a009a99c:  90 10 20 15  mov  0x15, %o0
a009a9a0:  40 00 32 b2  call  0xa00a7468
a009a9a4:  92 10 00 11  mov  %l1, %o1
a009a9a8:  80 a2 20 00  cmp  %o0, 0
a009a9ac:  12 80 00 0d  bne  0xa009a9e0
a009a9b0:  15 00 00 0b  sethi  %hi(0x2c00), %o2
a009a9b4:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009a9b8:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009a9bc:  80 88 68 00  btst  0x800, %g1
a009a9c0:  22 80 00 08  be,a   0xa009a9e0
a009a9c4:  ac 15 a0 02  or  %l6, 2, %l6
a009a9c8:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009a9cc:  90 12 22 c8  or  %o0, 0x2c8, %o0	! 0xa006a2c8
a009a9d0:  7f ff 61 9d  call  0xa0073044
a009a9d4:  92 10 20 01  mov  1, %o1
a009a9d8:  ac 15 a0 02  or  %l6, 2, %l6
a009a9dc:  15 00 00 0b  sethi  %hi(0x2c00), %o2
a009a9e0:  94 12 a2 28  or  %o2, 0x228, %o2	! 0x2e28
a009a9e4:  90 10 20 15  mov  0x15, %o0
a009a9e8:  40 00 32 a0  call  0xa00a7468
a009a9ec:  92 10 00 11  mov  %l1, %o1
a009a9f0:  80 a2 20 00  cmp  %o0, 0
a009a9f4:  12 80 00 0d  bne  0xa009aa28
a009a9f8:  15 00 00 0b  sethi  %hi(0x2c00), %o2
a009a9fc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009aa00:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009aa04:  80 88 68 00  btst  0x800, %g1
a009aa08:  22 80 00 08  be,a   0xa009aa28
a009aa0c:  ac 15 a0 04  or  %l6, 4, %l6
a009aa10:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009aa14:  90 12 22 c8  or  %o0, 0x2c8, %o0	! 0xa006a2c8
a009aa18:  7f ff 61 8b  call  0xa0073044
a009aa1c:  92 10 20 02  mov  2, %o1
a009aa20:  ac 15 a0 04  or  %l6, 4, %l6
a009aa24:  15 00 00 0b  sethi  %hi(0x2c00), %o2
a009aa28:  94 12 a2 38  or  %o2, 0x238, %o2	! 0x2e38
a009aa2c:  90 10 20 15  mov  0x15, %o0
a009aa30:  40 00 32 8e  call  0xa00a7468
a009aa34:  92 10 00 11  mov  %l1, %o1
a009aa38:  80 a2 20 00  cmp  %o0, 0
a009aa3c:  12 80 00 15  bne  0xa009aa90
a009aa40:  2b 2a 01 e1  sethi  %hi(0xa8078400), %l5
a009aa44:  82 0d e0 ff  and  %l7, 0xff, %g1
a009aa48:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009aa4c:  82 58 60 b0  smul  %g1, 0xb0, %g1
a009aa50:  9a 13 62 80  or  %o5, 0x280, %o5
a009aa54:  c2 0b 40 01  ldub  [ %o5 + %g1 ], %g1
a009aa58:  80 a0 60 04  cmp  %g1, 4
a009aa5c:  12 80 00 0e  bne  0xa009aa94
a009aa60:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1
a009aa64:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009aa68:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009aa6c:  80 88 68 00  btst  0x800, %g1
a009aa70:  22 80 00 08  be,a   0xa009aa90
a009aa74:  ac 15 a0 08  or  %l6, 8, %l6
a009aa78:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009aa7c:  90 12 22 c8  or  %o0, 0x2c8, %o0	! 0xa006a2c8
a009aa80:  7f ff 61 71  call  0xa0073044
a009aa84:  92 10 20 03  mov  3, %o1
a009aa88:  ac 15 a0 08  or  %l6, 8, %l6
a009aa8c:  2b 2a 01 e1  sethi  %hi(0xa8078400), %l5
a009aa90:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1	! 0xa8078634
a009aa94:  80 88 68 00  btst  0x800, %g1
a009aa98:  02 80 00 07  be  0xa009aab4
a009aa9c:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a009aaa0:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009aaa4:  90 12 22 f8  or  %o0, 0x2f8, %o0	! 0xa006a2f8
a009aaa8:  7f ff 61 67  call  0xa0073044
a009aaac:  92 0d a0 ff  and  %l6, 0xff, %o1
a009aab0:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a009aab4:  90 10 00 11  mov  %l1, %o0
a009aab8:  92 14 21 08  or  %l0, 0x108, %o1
a009aabc:  94 10 3f 0f  mov  -241, %o2
a009aac0:  40 00 32 72  call  0xa00a7488
a009aac4:  96 10 20 10  mov  0x10, %o3
a009aac8:  94 10 00 11  mov  %l1, %o2
a009aacc:  96 14 22 04  or  %l0, 0x204, %o3
a009aad0:  90 10 20 01  mov  1, %o0
a009aad4:  40 00 32 54  call  0xa00a7424
a009aad8:  92 10 20 08  mov  8, %o1
a009aadc:  94 10 00 11  mov  %l1, %o2
a009aae0:  96 14 22 04  or  %l0, 0x204, %o3
a009aae4:  90 10 20 01  mov  1, %o0
a009aae8:  40 00 32 4f  call  0xa00a7424
a009aaec:  92 10 20 0c  mov  0xc, %o1
a009aaf0:  94 10 00 11  mov  %l1, %o2
a009aaf4:  96 14 21 08  or  %l0, 0x108, %o3
a009aaf8:  90 10 20 01  mov  1, %o0
a009aafc:  40 00 32 4a  call  0xa00a7424
a009ab00:  92 10 20 19  mov  0x19, %o1
a009ab04:  25 2a 01 f5  sethi  %hi(0xa807d400), %l2
a009ab08:  a0 0d e0 ff  and  %l7, 0xff, %l0
a009ab0c:  9a 14 a2 80  or  %l2, 0x280, %o5
a009ab10:  82 5c 20 b0  smul  %l0, 0xb0, %g1
a009ab14:  c2 0b 40 01  ldub  [ %o5 + %g1 ], %g1
a009ab18:  80 a0 60 00  cmp  %g1, 0
a009ab1c:  02 80 00 56  be  0xa009ac74
a009ab20:  a2 10 20 00  clr  %l1
a009ab24:  82 0c 60 ff  and  %l1, 0xff, %g1
a009ab28:  80 a0 60 00  cmp  %g1, 0
a009ab2c:  12 80 00 0b  bne  0xa009ab58
a009ab30:  80 a0 60 01  cmp  %g1, 1
a009ab34:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009ab38:  15 3f fc 3f  sethi  %hi(0xfff0fc00), %o2
a009ab3c:  92 12 61 04  or  %o1, 0x104, %o1
a009ab40:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a009ab44:  90 0d 20 ff  and  %l4, 0xff, %o0
a009ab48:  40 00 32 50  call  0xa00a7488
a009ab4c:  17 00 01 40  sethi  %hi(0x50000), %o3
a009ab50:  10 80 00 26  b  0xa009abe8
a009ab54:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009ab58:  12 80 00 0b  bne  0xa009ab84
a009ab5c:  80 a0 60 02  cmp  %g1, 2
a009ab60:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009ab64:  15 3f c3 ff  sethi  %hi(0xff0ffc00), %o2
a009ab68:  92 12 61 04  or  %o1, 0x104, %o1
a009ab6c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a009ab70:  90 0d 20 ff  and  %l4, 0xff, %o0
a009ab74:  40 00 32 45  call  0xa00a7488
a009ab78:  17 00 18 00  sethi  %hi(0x600000), %o3
a009ab7c:  10 80 00 20  b  0xa009abfc
a009ab80:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009ab84:  12 80 00 0b  bne  0xa009abb0
a009ab88:  80 a0 60 03  cmp  %g1, 3
a009ab8c:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009ab90:  15 3c 3f ff  sethi  %hi(0xf0fffc00), %o2
a009ab94:  92 12 61 04  or  %o1, 0x104, %o1
a009ab98:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a009ab9c:  90 0d 20 ff  and  %l4, 0xff, %o0
a009aba0:  40 00 32 3a  call  0xa00a7488
a009aba4:  17 01 c0 00  sethi  %hi(0x7000000), %o3
a009aba8:  10 80 00 1a  b  0xa009ac10
a009abac:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009abb0:  12 80 00 0b  bne  0xa009abdc
a009abb4:  80 a0 60 00  cmp  %g1, 0
a009abb8:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009abbc:  15 03 ff ff  sethi  %hi(0xffffc00), %o2
a009abc0:  92 12 61 04  or  %o1, 0x104, %o1
a009abc4:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a009abc8:  90 0d 20 ff  and  %l4, 0xff, %o0
a009abcc:  40 00 32 2f  call  0xa00a7488
a009abd0:  17 20 00 00  sethi  %hi(0x80000000), %o3
a009abd4:  10 80 00 19  b  0xa009ac38
a009abd8:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009abdc:  12 80 00 05  bne  0xa009abf0
a009abe0:  80 a0 60 01  cmp  %g1, 1
a009abe4:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009abe8:  10 80 00 0b  b  0xa009ac14
a009abec:  92 12 61 0c  or  %o1, 0x10c, %o1	! 0x2d0c
a009abf0:  12 80 00 05  bne  0xa009ac04
a009abf4:  80 a0 60 02  cmp  %g1, 2
a009abf8:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009abfc:  10 80 00 10  b  0xa009ac3c
a009ac00:  92 12 61 0c  or  %o1, 0x10c, %o1	! 0x2d0c
a009ac04:  12 80 00 0a  bne  0xa009ac2c
a009ac08:  80 a0 60 03  cmp  %g1, 3
a009ac0c:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009ac10:  92 12 61 10  or  %o1, 0x110, %o1	! 0x2d10
a009ac14:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a009ac18:  17 00 00 3f  sethi  %hi(0xfc00), %o3
a009ac1c:  94 12 a0 ff  or  %o2, 0xff, %o2
a009ac20:  96 12 e3 00  or  %o3, 0x300, %o3
a009ac24:  10 80 00 0a  b  0xa009ac4c
a009ac28:  90 0d 20 ff  and  %l4, 0xff, %o0
a009ac2c:  12 80 00 0b  bne  0xa009ac58
a009ac30:  82 5c 20 b0  smul  %l0, 0xb0, %g1
a009ac34:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009ac38:  92 12 61 10  or  %o1, 0x110, %o1	! 0x2d10
a009ac3c:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a009ac40:  94 12 a3 ff  or  %o2, 0x3ff, %o2	! 0xffffff
a009ac44:  90 0d 20 ff  and  %l4, 0xff, %o0
a009ac48:  17 3f c0 00  sethi  %hi(0xff000000), %o3
a009ac4c:  40 00 32 0f  call  0xa00a7488
a009ac50:  01 00 00 00  nop
a009ac54:  82 5c 20 b0  smul  %l0, 0xb0, %g1
a009ac58:  9a 14 a2 80  or  %l2, 0x280, %o5
a009ac5c:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a009ac60:  a2 04 60 01  inc  %l1
a009ac64:  82 0c 60 ff  and  %l1, 0xff, %g1
a009ac68:  80 a0 40 0d  cmp  %g1, %o5
a009ac6c:  0a bf ff b0  bcs  0xa009ab2c
a009ac70:  80 a0 60 00  cmp  %g1, 0
a009ac74:  a2 0d 20 ff  and  %l4, 0xff, %l1
a009ac78:  25 00 00 0b  sethi  %hi(0x2c00), %l2
a009ac7c:  90 10 00 11  mov  %l1, %o0
a009ac80:  92 14 a1 00  or  %l2, 0x100, %o1
a009ac84:  94 10 3f 00  mov  -256, %o2
a009ac88:  40 00 32 00  call  0xa00a7488
a009ac8c:  96 10 20 00  clr  %o3
a009ac90:  90 10 20 01  mov  1, %o0
a009ac94:  92 10 20 0b  mov  0xb, %o1
a009ac98:  94 10 00 11  mov  %l1, %o2
a009ac9c:  40 00 31 e2  call  0xa00a7424
a009aca0:  96 14 a1 00  or  %l2, 0x100, %o3
a009aca4:  90 10 20 01  mov  1, %o0
a009aca8:  92 10 20 0c  mov  0xc, %o1
a009acac:  94 10 00 11  mov  %l1, %o2
a009acb0:  40 00 31 dd  call  0xa00a7424
a009acb4:  96 14 a1 00  or  %l2, 0x100, %o3
a009acb8:  90 10 20 01  mov  1, %o0
a009acbc:  92 10 20 00  clr  %o1
a009acc0:  94 10 00 11  mov  %l1, %o2
a009acc4:  40 00 31 d8  call  0xa00a7424
a009acc8:  96 14 a1 00  or  %l2, 0x100, %o3
a009accc:  90 10 20 01  mov  1, %o0
a009acd0:  92 10 20 01  mov  1, %o1
a009acd4:  94 10 00 11  mov  %l1, %o2
a009acd8:  40 00 31 d3  call  0xa00a7424
a009acdc:  96 14 a1 00  or  %l2, 0x100, %o3
a009ace0:  90 10 20 00  clr  %o0
a009ace4:  92 10 20 01  mov  1, %o1
a009ace8:  94 10 00 11  mov  %l1, %o2
a009acec:  40 00 31 ce  call  0xa00a7424
a009acf0:  96 14 a1 00  or  %l2, 0x100, %o3
a009acf4:  90 10 20 01  mov  1, %o0
a009acf8:  92 10 20 03  mov  3, %o1
a009acfc:  94 10 00 11  mov  %l1, %o2
a009ad00:  40 00 31 c9  call  0xa00a7424
a009ad04:  96 14 a1 00  or  %l2, 0x100, %o3
a009ad08:  90 10 20 00  clr  %o0
a009ad0c:  92 10 20 03  mov  3, %o1
a009ad10:  94 10 00 11  mov  %l1, %o2
a009ad14:  40 00 31 c4  call  0xa00a7424
a009ad18:  96 14 a1 00  or  %l2, 0x100, %o3
a009ad1c:  90 10 20 01  mov  1, %o0
a009ad20:  92 10 20 01  mov  1, %o1
a009ad24:  94 10 00 11  mov  %l1, %o2
a009ad28:  40 00 31 bf  call  0xa00a7424
a009ad2c:  96 14 a1 00  or  %l2, 0x100, %o3
a009ad30:  90 10 20 00  clr  %o0
a009ad34:  92 10 20 01  mov  1, %o1
a009ad38:  94 10 00 11  mov  %l1, %o2
a009ad3c:  40 00 31 ba  call  0xa00a7424
a009ad40:  96 14 a1 00  or  %l2, 0x100, %o3
a009ad44:  92 10 20 05  mov  5, %o1
a009ad48:  94 10 00 11  mov  %l1, %o2
a009ad4c:  96 14 a1 00  or  %l2, 0x100, %o3
a009ad50:  40 00 31 b5  call  0xa00a7424
a009ad54:  90 10 20 01  mov  1, %o0
a009ad58:  40 00 5a 8f  call  0xa00b1794
a009ad5c:  90 10 20 01  mov  1, %o0
a009ad60:  90 10 00 11  mov  %l1, %o0
a009ad64:  40 00 31 6c  call  0xa00a7314
a009ad68:  92 14 a1 00  or  %l2, 0x100, %o1
a009ad6c:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1
a009ad70:  80 88 68 00  btst  0x800, %g1
a009ad74:  02 80 00 06  be  0xa009ad8c
a009ad78:  a7 32 20 1c  srl  %o0, 0x1c, %l3
a009ad7c:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009ad80:  90 12 23 20  or  %o0, 0x320, %o0	! 0xa006a320
a009ad84:  7f ff 60 b0  call  0xa0073044
a009ad88:  92 0c e0 0f  and  %l3, 0xf, %o1
a009ad8c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009ad90:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009ad94:  80 88 68 00  btst  0x800, %g1
a009ad98:  02 80 00 06  be  0xa009adb0
a009ad9c:  a0 14 c0 16  or  %l3, %l6, %l0
a009ada0:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009ada4:  90 12 23 40  or  %o0, 0x340, %o0	! 0xa006a340
a009ada8:  7f ff 60 a7  call  0xa0073044
a009adac:  92 0c 20 ff  and  %l0, 0xff, %o1
a009adb0:  b0 0c 20 ff  and  %l0, 0xff, %i0
a009adb4:  80 a6 20 00  cmp  %i0, 0
a009adb8:  12 80 00 36  bne  0xa009ae90
a009adbc:  90 10 00 11  mov  %l1, %o0
a009adc0:  92 14 a1 00  or  %l2, 0x100, %o1
a009adc4:  94 10 3f 00  mov  -256, %o2
a009adc8:  40 00 31 b0  call  0xa00a7488
a009adcc:  96 10 20 00  clr  %o3
a009add0:  a0 0d e0 ff  and  %l7, 0xff, %l0
a009add4:  25 2a 01 f5  sethi  %hi(0xa807d400), %l2
a009add8:  82 14 a2 80  or  %l2, 0x280, %g1	! 0xa807d680
a009addc:  9a 5c 20 b0  smul  %l0, 0xb0, %o5
a009ade0:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a009ade4:  80 a6 00 01  cmp  %i0, %g1
a009ade8:  1a 80 00 2a  bcc  0xa009ae90
a009adec:  a2 10 20 00  clr  %l1
a009adf0:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009adf4:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a009adf8:  82 0c 60 ff  and  %l1, 0xff, %g1
a009adfc:  92 12 61 0c  or  %o1, 0x10c, %o1
a009ae00:  94 12 a0 ff  or  %o2, 0xff, %o2
a009ae04:  90 0d 20 ff  and  %l4, 0xff, %o0
a009ae08:  80 a0 60 00  cmp  %g1, 0
a009ae0c:  02 80 00 17  be  0xa009ae68
a009ae10:  96 10 20 00  clr  %o3
a009ae14:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009ae18:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a009ae1c:  92 12 61 0c  or  %o1, 0x10c, %o1
a009ae20:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a009ae24:  80 a0 60 01  cmp  %g1, 1
a009ae28:  02 80 00 10  be  0xa009ae68
a009ae2c:  01 00 00 00  nop
a009ae30:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009ae34:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a009ae38:  92 12 61 10  or  %o1, 0x110, %o1
a009ae3c:  94 12 a0 ff  or  %o2, 0xff, %o2
a009ae40:  80 a0 60 02  cmp  %g1, 2
a009ae44:  02 80 00 09  be  0xa009ae68
a009ae48:  01 00 00 00  nop
a009ae4c:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009ae50:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a009ae54:  80 a0 60 03  cmp  %g1, 3
a009ae58:  92 12 61 10  or  %o1, 0x110, %o1
a009ae5c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a009ae60:  12 80 00 04  bne  0xa009ae70
a009ae64:  01 00 00 00  nop
a009ae68:  40 00 31 88  call  0xa00a7488
a009ae6c:  01 00 00 00  nop
a009ae70:  82 5c 20 b0  smul  %l0, 0xb0, %g1
a009ae74:  9a 14 a2 80  or  %l2, 0x280, %o5
a009ae78:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a009ae7c:  a2 04 60 01  inc  %l1
a009ae80:  82 0c 60 ff  and  %l1, 0xff, %g1
a009ae84:  80 a0 40 0d  cmp  %g1, %o5
a009ae88:  0a bf ff db  bcs  0xa009adf4
a009ae8c:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009ae90:  81 c7 e0 08  ret
a009ae94:  81 e8 00 00  restore
