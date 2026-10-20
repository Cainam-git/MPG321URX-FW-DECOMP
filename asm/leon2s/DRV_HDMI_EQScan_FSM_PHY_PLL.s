# leon2s DRV_HDMI_EQScan_FSM_PHY_PLL 0xa007e7c0-0xa007ebd0 (1040 bytes)
a007e7c0:  9d e3 bf 98  save  %sp, -104, %sp
a007e7c4:  a2 0e 20 ff  and  %i0, 0xff, %l1
a007e7c8:  82 04 40 11  add  %l1, %l1, %g1
a007e7cc:  ae 00 40 11  add  %g1, %l1, %l7
a007e7d0:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a007e7d4:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa807cc64
a007e7d8:  9b 2d e0 03  sll  %l7, 3, %o5
a007e7dc:  9a 03 40 01  add  %o5, %g1, %o5
a007e7e0:  2b 2a 01 e1  sethi  %hi(0xa8078400), %l5
a007e7e4:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1	! 0xa8078634
a007e7e8:  ba 10 00 18  mov  %i0, %i5
a007e7ec:  80 88 60 02  btst  2, %g1
a007e7f0:  02 80 00 0a  be  0xa007e818
a007e7f4:  ec 13 60 08  lduh  [ %o5 + 8 ], %l6
a007e7f8:  92 06 20 41  add  %i0, 0x41, %o1
a007e7fc:  93 2a 60 18  sll  %o1, 0x18, %o1
a007e800:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a007e804:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a007e808:  90 12 20 58  or  %o0, 0x58, %o0
a007e80c:  93 3a 60 18  sra  %o1, 0x18, %o1
a007e810:  7f ff d2 0d  call  0xa0073044
a007e814:  94 12 a3 00  or  %o2, 0x300, %o2
a007e818:  29 00 00 07  sethi  %hi(0x1c00), %l4
a007e81c:  90 10 20 00  clr  %o0
a007e820:  92 10 20 15  mov  0x15, %o1
a007e824:  94 10 20 00  clr  %o2
a007e828:  40 00 a2 ff  call  0xa00a7424
a007e82c:  96 15 20 04  or  %l4, 4, %o3
a007e830:  90 10 20 00  clr  %o0
a007e834:  92 10 20 16  mov  0x16, %o1
a007e838:  94 10 20 00  clr  %o2
a007e83c:  40 00 a2 fa  call  0xa00a7424
a007e840:  96 10 00 14  mov  %l4, %o3
a007e844:  90 10 20 00  clr  %o0
a007e848:  92 10 20 17  mov  0x17, %o1
a007e84c:  94 10 20 00  clr  %o2
a007e850:  40 00 a2 f5  call  0xa00a7424
a007e854:  96 10 00 14  mov  %l4, %o3
a007e858:  7f ff d3 32  call  0xa0073520
a007e85c:  90 10 00 11  mov  %l1, %o0
a007e860:  a6 0a 20 ff  and  %o0, 0xff, %l3
a007e864:  80 a4 e0 00  cmp  %l3, 0
a007e868:  02 80 00 13  be  0xa007e8b4
a007e86c:  21 00 00 04  sethi  %hi(0x1000), %l0
a007e870:  21 00 00 0d  sethi  %hi(0x3400), %l0
a007e874:  90 10 20 00  clr  %o0
a007e878:  92 10 20 00  clr  %o1
a007e87c:  94 10 00 11  mov  %l1, %o2
a007e880:  40 00 a2 e9  call  0xa00a7424
a007e884:  96 14 22 00  or  %l0, 0x200, %o3
a007e888:  90 10 20 00  clr  %o0
a007e88c:  92 10 20 01  mov  1, %o1
a007e890:  94 10 00 11  mov  %l1, %o2
a007e894:  40 00 a2 e4  call  0xa00a7424
a007e898:  96 14 22 00  or  %l0, 0x200, %o3
a007e89c:  96 14 22 00  or  %l0, 0x200, %o3
a007e8a0:  90 10 20 00  clr  %o0
a007e8a4:  92 10 20 08  mov  8, %o1
a007e8a8:  40 00 a2 df  call  0xa00a7424
a007e8ac:  94 10 00 11  mov  %l1, %o2
a007e8b0:  21 00 00 04  sethi  %hi(0x1000), %l0
a007e8b4:  25 00 3f ff  sethi  %hi(0xfffc00), %l2
a007e8b8:  90 10 00 11  mov  %l1, %o0
a007e8bc:  92 14 20 28  or  %l0, 0x28, %o1
a007e8c0:  94 14 a3 ff  or  %l2, 0x3ff, %o2
a007e8c4:  40 00 a2 f1  call  0xa00a7488
a007e8c8:  17 0c 00 00  sethi  %hi(0x30000000), %o3
a007e8cc:  31 3f c0 3f  sethi  %hi(0xff00fc00), %i0
a007e8d0:  90 10 00 11  mov  %l1, %o0
a007e8d4:  92 14 20 34  or  %l0, 0x34, %o1
a007e8d8:  94 16 23 ff  or  %i0, 0x3ff, %o2
a007e8dc:  40 00 a2 eb  call  0xa00a7488
a007e8e0:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a007e8e4:  90 10 00 11  mov  %l1, %o0
a007e8e8:  92 14 20 14  or  %l0, 0x14, %o1
a007e8ec:  94 16 23 ff  or  %i0, 0x3ff, %o2
a007e8f0:  40 00 a2 e6  call  0xa00a7488
a007e8f4:  17 00 23 00  sethi  %hi(0x8c0000), %o3
a007e8f8:  96 15 20 04  or  %l4, 4, %o3
a007e8fc:  90 10 20 01  mov  1, %o0
a007e900:  92 10 20 12  mov  0x12, %o1
a007e904:  40 00 a2 c8  call  0xa00a7424
a007e908:  94 10 00 11  mov  %l1, %o2
a007e90c:  92 14 20 14  or  %l0, 0x14, %o1
a007e910:  90 10 00 11  mov  %l1, %o0
a007e914:  94 16 23 ff  or  %i0, 0x3ff, %o2
a007e918:  40 00 a2 dc  call  0xa00a7488
a007e91c:  17 00 23 40  sethi  %hi(0x8d0000), %o3
a007e920:  83 2d a0 10  sll  %l6, 0x10, %g1
a007e924:  93 30 60 10  srl  %g1, 0x10, %o1
a007e928:  80 a2 60 63  cmp  %o1, 0x63
a007e92c:  18 80 00 07  bgu  0xa007e948
a007e930:  80 a2 60 9f  cmp  %o1, 0x9f
a007e934:  94 14 a3 ff  or  %l2, 0x3ff, %o2
a007e938:  90 10 00 11  mov  %l1, %o0
a007e93c:  92 14 20 08  or  %l0, 8, %o1
a007e940:  10 80 00 08  b  0xa007e960
a007e944:  17 0a c0 00  sethi  %hi(0x2b000000), %o3
a007e948:  18 80 00 1a  bgu  0xa007e9b0
a007e94c:  80 a2 61 2b  cmp  %o1, 0x12b
a007e950:  94 14 a3 ff  or  %l2, 0x3ff, %o2
a007e954:  90 10 00 11  mov  %l1, %o0
a007e958:  92 14 20 08  or  %l0, 8, %o1
a007e95c:  17 06 c0 00  sethi  %hi(0x1b000000), %o3
a007e960:  40 00 a2 ca  call  0xa00a7488
a007e964:  01 00 00 00  nop
a007e968:  90 10 20 01  mov  1, %o0	! 0x1
a007e96c:  92 10 20 08  mov  8, %o1
a007e970:  94 10 00 11  mov  %l1, %o2
a007e974:  40 00 a2 ac  call  0xa00a7424
a007e978:  96 14 20 0c  or  %l0, 0xc, %o3
a007e97c:  90 10 00 11  mov  %l1, %o0
a007e980:  92 14 20 0c  or  %l0, 0xc, %o1
a007e984:  94 10 39 ff  mov  -1537, %o2
a007e988:  40 00 a2 c0  call  0xa00a7488
a007e98c:  96 10 26 00  mov  0x600, %o3
a007e990:  80 a4 e0 00  cmp  %l3, 0
a007e994:  22 80 00 85  be,a   0xa007eba8
a007e998:  82 0f 60 ff  and  %i5, 0xff, %g1
a007e99c:  13 00 00 0d  sethi  %hi(0x3400), %o1
a007e9a0:  90 10 00 11  mov  %l1, %o0
a007e9a4:  92 12 62 08  or  %o1, 0x208, %o1
a007e9a8:  10 80 00 1f  b  0xa007ea24
a007e9ac:  94 16 23 ff  or  %i0, 0x3ff, %o2
a007e9b0:  18 80 00 1f  bgu  0xa007ea2c
a007e9b4:  80 a2 62 58  cmp  %o1, 0x258
a007e9b8:  21 00 00 04  sethi  %hi(0x1000), %l0
a007e9bc:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a007e9c0:  94 12 a3 ff  or  %o2, 0x3ff, %o2	! 0xffffff
a007e9c4:  90 10 00 11  mov  %l1, %o0
a007e9c8:  92 14 20 08  or  %l0, 8, %o1
a007e9cc:  40 00 a2 af  call  0xa00a7488
a007e9d0:  17 06 c0 00  sethi  %hi(0x1b000000), %o3
a007e9d4:  90 10 20 01  mov  1, %o0
a007e9d8:  92 10 20 08  mov  8, %o1
a007e9dc:  94 10 00 11  mov  %l1, %o2
a007e9e0:  40 00 a2 91  call  0xa00a7424
a007e9e4:  96 14 20 0c  or  %l0, 0xc, %o3
a007e9e8:  90 10 00 11  mov  %l1, %o0
a007e9ec:  92 14 20 0c  or  %l0, 0xc, %o1
a007e9f0:  94 10 39 ff  mov  -1537, %o2
a007e9f4:  40 00 a2 a5  call  0xa00a7488
a007e9f8:  96 10 24 00  mov  0x400, %o3
a007e9fc:  7f ff d2 c9  call  0xa0073520
a007ea00:  90 10 00 11  mov  %l1, %o0
a007ea04:  80 8a 20 ff  btst  0xff, %o0
a007ea08:  22 80 00 68  be,a   0xa007eba8
a007ea0c:  82 0f 60 ff  and  %i5, 0xff, %g1
a007ea10:  13 00 00 0d  sethi  %hi(0x3400), %o1
a007ea14:  15 3f c0 3f  sethi  %hi(0xff00fc00), %o2
a007ea18:  90 10 00 11  mov  %l1, %o0
a007ea1c:  92 12 62 08  or  %o1, 0x208, %o1
a007ea20:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007ea24:  10 80 00 2f  b  0xa007eae0
a007ea28:  17 00 01 40  sethi  %hi(0x50000), %o3
a007ea2c:  18 80 00 31  bgu  0xa007eaf0
a007ea30:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1
a007ea34:  7f ff f2 1b  call  0xa007b2a0
a007ea38:  90 10 00 11  mov  %l1, %o0
a007ea3c:  80 8a 20 ff  btst  0xff, %o0
a007ea40:  22 bf ff df  be,a   0xa007e9bc
a007ea44:  21 00 00 04  sethi  %hi(0x1000), %l0
a007ea48:  90 10 00 11  mov  %l1, %o0
a007ea4c:  92 14 20 14  or  %l0, 0x14, %o1
a007ea50:  94 16 23 ff  or  %i0, 0x3ff, %o2
a007ea54:  40 00 a2 8d  call  0xa00a7488
a007ea58:  17 00 3f 40  sethi  %hi(0xfd0000), %o3
a007ea5c:  90 10 00 11  mov  %l1, %o0
a007ea60:  94 14 a3 ff  or  %l2, 0x3ff, %o2
a007ea64:  92 14 20 08  or  %l0, 8, %o1
a007ea68:  40 00 a2 88  call  0xa00a7488
a007ea6c:  17 0e c0 00  sethi  %hi(0x3b000000), %o3
a007ea70:  90 10 20 01  mov  1, %o0
a007ea74:  92 10 20 08  mov  8, %o1
a007ea78:  94 10 00 11  mov  %l1, %o2
a007ea7c:  40 00 a2 6a  call  0xa00a7424
a007ea80:  96 14 20 0c  or  %l0, 0xc, %o3
a007ea84:  80 a4 e0 00  cmp  %l3, 0
a007ea88:  02 80 00 13  be  0xa007ead4
a007ea8c:  90 10 00 11  mov  %l1, %o0
a007ea90:  92 14 20 0c  or  %l0, 0xc, %o1
a007ea94:  94 10 39 ff  mov  -1537, %o2
a007ea98:  40 00 a2 7c  call  0xa00a7488
a007ea9c:  96 10 22 00  mov  0x200, %o3
a007eaa0:  21 00 00 0d  sethi  %hi(0x3400), %l0
a007eaa4:  90 10 00 11  mov  %l1, %o0
a007eaa8:  94 16 23 ff  or  %i0, 0x3ff, %o2
a007eaac:  92 14 22 08  or  %l0, 0x208, %o1
a007eab0:  40 00 a2 76  call  0xa00a7488
a007eab4:  17 00 03 00  sethi  %hi(0xc0000), %o3
a007eab8:  94 10 00 11  mov  %l1, %o2
a007eabc:  96 14 22 00  or  %l0, 0x200, %o3
a007eac0:  90 10 20 01  mov  1, %o0
a007eac4:  40 00 a2 58  call  0xa00a7424
a007eac8:  92 10 20 08  mov  8, %o1
a007eacc:  10 80 00 37  b  0xa007eba8
a007ead0:  82 0f 60 ff  and  %i5, 0xff, %g1
a007ead4:  92 14 20 0c  or  %l0, 0xc, %o1
a007ead8:  94 10 39 ff  mov  -1537, %o2
a007eadc:  96 10 20 00  clr  %o3
a007eae0:  40 00 a2 6a  call  0xa00a7488
a007eae4:  01 00 00 00  nop
a007eae8:  10 80 00 30  b  0xa007eba8
a007eaec:  82 0f 60 ff  and  %i5, 0xff, %g1
a007eaf0:  80 88 60 02  btst  2, %g1
a007eaf4:  02 80 00 04  be  0xa007eb04
a007eaf8:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007eafc:  7f ff d1 52  call  0xa0073044
a007eb00:  90 12 21 c8  or  %o0, 0x1c8, %o0	! 0xa00681c8
a007eb04:  7f ff f1 e7  call  0xa007b2a0
a007eb08:  90 10 00 11  mov  %l1, %o0
a007eb0c:  80 8a 20 ff  btst  0xff, %o0
a007eb10:  02 80 00 26  be  0xa007eba8
a007eb14:  82 0f 60 ff  and  %i5, 0xff, %g1
a007eb18:  7f ff f9 4f  call  0xa007d054
a007eb1c:  90 10 00 11  mov  %l1, %o0
a007eb20:  80 8a 20 ff  btst  0xff, %o0
a007eb24:  02 80 00 21  be  0xa007eba8
a007eb28:  82 0f 60 ff  and  %i5, 0xff, %g1
a007eb2c:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a007eb30:  9a 5c 68 98  smul  %l1, 0x898, %o5
a007eb34:  82 10 61 f0  or  %g1, 0x1f0, %g1
a007eb38:  a0 03 40 01  add  %o5, %g1, %l0
a007eb3c:  da 0c 28 96  ldub  [ %l0 + 0x896 ], %o5
a007eb40:  82 03 60 01  add  %o5, 1, %g1
a007eb44:  80 a3 60 03  cmp  %o5, 3
a007eb48:  08 80 00 17  bleu  0xa007eba4
a007eb4c:  c2 2c 28 96  stb  %g1, [ %l0 + 0x896 ]
a007eb50:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1
a007eb54:  80 88 60 02  btst  2, %g1
a007eb58:  02 80 00 06  be  0xa007eb70
a007eb5c:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a007eb60:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007eb64:  7f ff d2 58  call  0xa00734c4
a007eb68:  90 12 22 00  or  %o0, 0x200, %o0	! 0xa0068200
a007eb6c:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a007eb70:  83 2d e0 02  sll  %l7, 2, %g1
a007eb74:  9a 13 60 c4  or  %o5, 0xc4, %o5
a007eb78:  d8 05 62 34  ld  [ %l5 + 0x234 ], %o4
a007eb7c:  c0 23 40 01  clr  [ %o5 + %g1 ]
a007eb80:  80 8b 20 02  btst  2, %o4
a007eb84:  02 80 00 06  be  0xa007eb9c
a007eb88:  c0 2c 28 96  clrb  [ %l0 + 0x896 ]
a007eb8c:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007eb90:  90 12 22 28  or  %o0, 0x228, %o0	! 0xa0068228
a007eb94:  7f ff d1 2c  call  0xa0073044
a007eb98:  92 10 20 05  mov  5, %o1
a007eb9c:  10 80 00 0b  b  0xa007ebc8
a007eba0:  b0 10 20 00  clr  %i0
a007eba4:  82 0f 60 ff  and  %i5, 0xff, %g1
a007eba8:  9a 00 40 01  add  %g1, %g1, %o5
a007ebac:  9a 03 40 01  add  %o5, %g1, %o5
a007ebb0:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a007ebb4:  9b 2b 60 02  sll  %o5, 2, %o5
a007ebb8:  98 10 20 02  mov  2, %o4
a007ebbc:  82 10 60 c4  or  %g1, 0xc4, %g1
a007ebc0:  d8 20 40 0d  st  %o4, [ %g1 + %o5 ]
a007ebc4:  b0 10 20 01  mov  1, %i0
a007ebc8:  81 c7 e0 08  ret
a007ebcc:  81 e8 00 00  restore
