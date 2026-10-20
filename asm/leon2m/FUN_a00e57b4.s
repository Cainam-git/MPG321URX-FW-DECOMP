# leon2m FUN_a00e57b4 0xa00e57b4-0xa00e5fc8 (2068 bytes)
a00e57b4:  9d e3 bf 98  save  %sp, -104, %sp
a00e57b8:  90 10 00 18  mov  %i0, %o0
a00e57bc:  92 10 00 1a  mov  %i2, %o1
a00e57c0:  7f ff ff 8b  call  0xa00e55ec
a00e57c4:  94 10 3f fc  mov  -4, %o2
a00e57c8:  80 a2 20 00  cmp  %o0, 0
a00e57cc:  12 80 01 fd  bne  0xa00e5fc0
a00e57d0:  80 a6 bf ff  cmp  %i2, -1
a00e57d4:  02 80 01 35  be  0xa00e5ca8
a00e57d8:  a1 2e a0 02  sll  %i2, 2, %l0
a00e57dc:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e57e0:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e57e4:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00e57e8:  a2 15 62 38  or  %l5, 0x238, %l1
a00e57ec:  a4 15 a2 28  or  %l6, 0x228, %l2
a00e57f0:  a6 15 22 18  or  %l4, 0x218, %l3
a00e57f4:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a00e57f8:  d4 04 80 10  ld  [ %l2 + %l0 ], %o2
a00e57fc:  d6 04 c0 10  ld  [ %l3 + %l0 ], %o3
a00e5800:  7f ff eb d5  call  0xa00e0754
a00e5804:  90 10 00 18  mov  %i0, %o0
a00e5808:  98 12 20 02  or  %o0, 2, %o4
a00e580c:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a00e5810:  d4 04 80 10  ld  [ %l2 + %l0 ], %o2
a00e5814:  d6 04 c0 10  ld  [ %l3 + %l0 ], %o3
a00e5818:  7f ff eb d7  call  0xa00e0774
a00e581c:  90 10 00 18  mov  %i0, %o0
a00e5820:  3b 2a 00 99  sethi  %hi(0xa8026400), %i5
a00e5824:  39 2a 00 99  sethi  %hi(0xa8026400), %i4
a00e5828:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00e582c:  9a 17 61 d8  or  %i5, 0x1d8, %o5
a00e5830:  98 17 21 c8  or  %i4, 0x1c8, %o4
a00e5834:  82 15 e1 b8  or  %l7, 0x1b8, %g1
a00e5838:  d6 00 40 10  ld  [ %g1 + %l0 ], %o3
a00e583c:  d2 03 40 10  ld  [ %o5 + %l0 ], %o1
a00e5840:  d4 03 00 10  ld  [ %o4 + %l0 ], %o2
a00e5844:  90 10 00 18  mov  %i0, %o0
a00e5848:  7f ff eb cb  call  0xa00e0774
a00e584c:  98 10 20 01  mov  1, %o4
a00e5850:  7f ff ea 10  call  0xa00e0090
a00e5854:  90 10 00 18  mov  %i0, %o0
a00e5858:  80 a6 60 03  cmp  %i1, 3
a00e585c:  02 80 01 a5  be  0xa00e5ef0
a00e5860:  90 10 00 18  mov  %i0, %o0
a00e5864:  80 a6 60 04  cmp  %i1, 4
a00e5868:  02 80 01 a3  be  0xa00e5ef4
a00e586c:  92 10 20 05  mov  5, %o1
a00e5870:  80 a6 bf ff  cmp  %i2, -1
a00e5874:  02 80 01 97  be  0xa00e5ed0
a00e5878:  b3 2e a0 02  sll  %i2, 2, %i1
a00e587c:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e5880:  37 2a 00 99  sethi  %hi(0xa8026400), %i3
a00e5884:  90 16 e2 58  or  %i3, 0x258, %o0	! 0xa8026658
a00e5888:  92 12 e2 48  or  %o3, 0x248, %o1
a00e588c:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00e5890:  a0 13 22 68  or  %o4, 0x268, %l0	! 0xa8026668
a00e5894:  d6 02 40 19  ld  [ %o1 + %i1 ], %o3
a00e5898:  d4 02 00 19  ld  [ %o0 + %i1 ], %o2
a00e589c:  d2 04 00 19  ld  [ %l0 + %i1 ], %o1
a00e58a0:  90 10 00 18  mov  %i0, %o0
a00e58a4:  7f ff eb ac  call  0xa00e0754
a00e58a8:  01 00 00 00  nop
a00e58ac:  80 8a 20 02  btst  2, %o0
a00e58b0:  12 80 00 9e  bne  0xa00e5b28
a00e58b4:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00e58b8:  80 a6 bf ff  cmp  %i2, -1
a00e58bc:  02 80 01 11  be  0xa00e5d00
a00e58c0:  a2 15 62 38  or  %l5, 0x238, %l1
a00e58c4:  a6 15 22 18  or  %l4, 0x218, %l3
a00e58c8:  a9 2e a0 02  sll  %i2, 2, %l4
a00e58cc:  a4 15 a2 28  or  %l6, 0x228, %l2
a00e58d0:  d2 04 40 14  ld  [ %l1 + %l4 ], %o1
a00e58d4:  d4 04 80 14  ld  [ %l2 + %l4 ], %o2
a00e58d8:  d6 04 c0 14  ld  [ %l3 + %l4 ], %o3
a00e58dc:  7f ff eb 9e  call  0xa00e0754
a00e58e0:  90 10 00 18  mov  %i0, %o0
a00e58e4:  98 0a 3f fd  and  %o0, -3, %o4
a00e58e8:  d2 04 40 14  ld  [ %l1 + %l4 ], %o1
a00e58ec:  d4 04 80 14  ld  [ %l2 + %l4 ], %o2
a00e58f0:  d6 04 c0 14  ld  [ %l3 + %l4 ], %o3
a00e58f4:  90 10 00 18  mov  %i0, %o0
a00e58f8:  7f ff eb 9f  call  0xa00e0774
a00e58fc:  aa 17 21 c8  or  %i4, 0x1c8, %l5
a00e5900:  ac 17 61 d8  or  %i5, 0x1d8, %l6
a00e5904:  b8 15 e1 b8  or  %l7, 0x1b8, %i4
a00e5908:  d6 07 00 14  ld  [ %i4 + %l4 ], %o3
a00e590c:  d2 05 80 14  ld  [ %l6 + %l4 ], %o1
a00e5910:  d4 05 40 14  ld  [ %l5 + %l4 ], %o2
a00e5914:  90 10 00 18  mov  %i0, %o0
a00e5918:  98 10 20 00  clr  %o4
a00e591c:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e5920:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e5924:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00e5928:  7f ff eb 93  call  0xa00e0774
a00e592c:  3b 2a 00 99  sethi  %hi(0xa8026400), %i5
a00e5930:  ae 17 62 68  or  %i5, 0x268, %l7	! 0xa8026668
a00e5934:  b2 15 a1 18  or  %l6, 0x118, %i1
a00e5938:  a1 2e a0 02  sll  %i2, 2, %l0
a00e593c:  a6 15 61 08  or  %l5, 0x108, %l3
a00e5940:  10 80 00 2c  b  0xa00e59f0
a00e5944:  a4 15 20 f8  or  %l4, 0xf8, %l2
a00e5948:  d2 06 40 10  ld  [ %i1 + %l0 ], %o1
a00e594c:  d4 04 c0 10  ld  [ %l3 + %l0 ], %o2
a00e5950:  7f ff eb 81  call  0xa00e0754
a00e5954:  d6 04 80 10  ld  [ %l2 + %l0 ], %o3
a00e5958:  80 a6 bf ff  cmp  %i2, -1
a00e595c:  02 80 00 2f  be  0xa00e5a18
a00e5960:  98 02 20 01  add  %o0, 1, %o4
a00e5964:  d2 06 40 10  ld  [ %i1 + %l0 ], %o1
a00e5968:  d4 04 c0 10  ld  [ %l3 + %l0 ], %o2
a00e596c:  d6 04 80 10  ld  [ %l2 + %l0 ], %o3
a00e5970:  7f ff eb 81  call  0xa00e0774
a00e5974:  90 10 00 18  mov  %i0, %o0
a00e5978:  7f ff e9 c6  call  0xa00e0090
a00e597c:  90 10 00 18  mov  %i0, %o0
a00e5980:  90 10 00 18  mov  %i0, %o0
a00e5984:  92 10 20 05  mov  5, %o1
a00e5988:  94 10 20 00  clr  %o2
a00e598c:  7f ff f9 b8  call  0xa00e406c
a00e5990:  17 00 00 04  sethi  %hi(0x1000), %o3
a00e5994:  80 a6 bf ff  cmp  %i2, -1
a00e5998:  02 80 00 30  be  0xa00e5a58
a00e599c:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00e59a0:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e59a4:  9e 12 a2 48  or  %o2, 0x248, %o7	! 0xa8026648
a00e59a8:  90 16 e2 58  or  %i3, 0x258, %o0
a00e59ac:  d4 02 00 10  ld  [ %o0 + %l0 ], %o2
a00e59b0:  d6 03 c0 10  ld  [ %o7 + %l0 ], %o3
a00e59b4:  d2 05 c0 10  ld  [ %l7 + %l0 ], %o1
a00e59b8:  7f ff eb 67  call  0xa00e0754
a00e59bc:  90 10 00 18  mov  %i0, %o0
a00e59c0:  a2 10 00 08  mov  %o0, %l1
a00e59c4:  90 10 00 18  mov  %i0, %o0
a00e59c8:  d2 06 40 10  ld  [ %i1 + %l0 ], %o1
a00e59cc:  d4 04 c0 10  ld  [ %l3 + %l0 ], %o2
a00e59d0:  d6 04 80 10  ld  [ %l2 + %l0 ], %o3
a00e59d4:  7f ff eb 60  call  0xa00e0754
a00e59d8:  01 00 00 00  nop
a00e59dc:  80 8c 60 02  btst  2, %l1
a00e59e0:  02 80 00 2a  be  0xa00e5a88
a00e59e4:  80 a2 20 07  cmp  %o0, 7
a00e59e8:  02 80 00 d6  be  0xa00e5d40
a00e59ec:  01 00 00 00  nop
a00e59f0:  80 a6 bf ff  cmp  %i2, -1
a00e59f4:  12 bf ff d5  bne  0xa00e5948
a00e59f8:  90 10 00 18  mov  %i0, %o0
a00e59fc:  92 15 a1 18  or  %l6, 0x118, %o1
a00e5a00:  94 15 61 08  or  %l5, 0x108, %o2
a00e5a04:  7f ff eb 54  call  0xa00e0754
a00e5a08:  96 15 20 f8  or  %l4, 0xf8, %o3
a00e5a0c:  80 a6 bf ff  cmp  %i2, -1
a00e5a10:  12 bf ff d5  bne  0xa00e5964
a00e5a14:  98 02 20 01  add  %o0, 1, %o4
a00e5a18:  92 15 a1 18  or  %l6, 0x118, %o1
a00e5a1c:  94 15 61 08  or  %l5, 0x108, %o2
a00e5a20:  96 15 20 f8  or  %l4, 0xf8, %o3
a00e5a24:  7f ff eb 54  call  0xa00e0774
a00e5a28:  90 10 00 18  mov  %i0, %o0
a00e5a2c:  7f ff e9 99  call  0xa00e0090
a00e5a30:  90 10 00 18  mov  %i0, %o0
a00e5a34:  90 10 00 18  mov  %i0, %o0
a00e5a38:  92 10 20 05  mov  5, %o1
a00e5a3c:  94 10 20 00  clr  %o2
a00e5a40:  7f ff f9 8b  call  0xa00e406c
a00e5a44:  17 00 00 04  sethi  %hi(0x1000), %o3
a00e5a48:  80 a6 bf ff  cmp  %i2, -1
a00e5a4c:  32 bf ff d6  bne,a   0xa00e59a4
a00e5a50:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e5a54:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00e5a58:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e5a5c:  92 10 62 68  or  %g1, 0x268, %o1
a00e5a60:  94 16 e2 58  or  %i3, 0x258, %o2
a00e5a64:  96 13 62 48  or  %o5, 0x248, %o3
a00e5a68:  7f ff eb 3b  call  0xa00e0754
a00e5a6c:  90 10 00 18  mov  %i0, %o0
a00e5a70:  a2 10 00 08  mov  %o0, %l1
a00e5a74:  90 10 00 18  mov  %i0, %o0
a00e5a78:  92 15 a1 18  or  %l6, 0x118, %o1
a00e5a7c:  94 15 61 08  or  %l5, 0x108, %o2
a00e5a80:  10 bf ff d5  b  0xa00e59d4
a00e5a84:  96 15 20 f8  or  %l4, 0xf8, %o3
a00e5a88:  90 10 00 18  mov  %i0, %o0
a00e5a8c:  92 10 00 1a  mov  %i2, %o1
a00e5a90:  7f ff fe d7  call  0xa00e55ec
a00e5a94:  94 10 20 04  mov  4, %o2
a00e5a98:  80 a2 20 00  cmp  %o0, 0
a00e5a9c:  12 80 01 49  bne  0xa00e5fc0
a00e5aa0:  01 00 00 00  nop
a00e5aa4:  7f ff e9 7b  call  0xa00e0090
a00e5aa8:  90 10 00 18  mov  %i0, %o0
a00e5aac:  90 10 00 18  mov  %i0, %o0
a00e5ab0:  92 10 20 61  mov  0x61, %o1
a00e5ab4:  94 10 20 08  mov  8, %o2
a00e5ab8:  7f ff eb 27  call  0xa00e0754
a00e5abc:  96 10 20 03  mov  3, %o3
a00e5ac0:  80 a2 20 01  cmp  %o0, 1
a00e5ac4:  02 80 01 1f  be  0xa00e5f40
a00e5ac8:  80 a6 bf ff  cmp  %i2, -1
a00e5acc:  02 80 01 0f  be  0xa00e5f08
a00e5ad0:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e5ad4:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e5ad8:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e5adc:  99 2e a0 02  sll  %i2, 2, %o4
a00e5ae0:  82 12 e1 e8  or  %o3, 0x1e8, %g1
a00e5ae4:  9e 12 62 08  or  %o1, 0x208, %o7
a00e5ae8:  a2 13 61 f8  or  %o5, 0x1f8, %l1
a00e5aec:  d6 00 40 0c  ld  [ %g1 + %o4 ], %o3
a00e5af0:  d2 03 c0 0c  ld  [ %o7 + %o4 ], %o1
a00e5af4:  d4 04 40 0c  ld  [ %l1 + %o4 ], %o2
a00e5af8:  90 10 00 18  mov  %i0, %o0
a00e5afc:  7f ff eb 1e  call  0xa00e0774
a00e5b00:  98 10 20 00  clr  %o4
a00e5b04:  90 10 00 18  mov  %i0, %o0
a00e5b08:  92 10 20 54  mov  0x54, %o1
a00e5b0c:  7f ff ea 29  call  0xa00e03b0
a00e5b10:  94 10 20 00  clr  %o2
a00e5b14:  90 10 20 00  clr  %o0
a00e5b18:  80 a2 20 00  cmp  %o0, 0
a00e5b1c:  22 80 01 29  be,a   0xa00e5fc0
a00e5b20:  90 10 20 00  clr  %o0
a00e5b24:  30 80 01 27  b,a   0xa00e5fc0
a00e5b28:  33 2a 00 99  sethi  %hi(0xa8026400), %i1
a00e5b2c:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e5b30:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e5b34:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00e5b38:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e5b3c:  ba 14 20 d8  or  %l0, 0xd8, %i5
a00e5b40:  ae 16 60 c8  or  %i1, 0xc8, %l7
a00e5b44:  b8 12 60 e8  or  %o1, 0xe8, %i4
a00e5b48:  b2 15 a1 18  or  %l6, 0x118, %i1
a00e5b4c:  a1 2e a0 02  sll  %i2, 2, %l0
a00e5b50:  a6 15 61 08  or  %l5, 0x108, %l3
a00e5b54:  10 80 00 2f  b  0xa00e5c10
a00e5b58:  a4 15 20 f8  or  %l4, 0xf8, %l2
a00e5b5c:  d2 06 40 10  ld  [ %i1 + %l0 ], %o1
a00e5b60:  d4 04 c0 10  ld  [ %l3 + %l0 ], %o2
a00e5b64:  7f ff ea fc  call  0xa00e0754
a00e5b68:  d6 04 80 10  ld  [ %l2 + %l0 ], %o3
a00e5b6c:  80 a6 bf ff  cmp  %i2, -1
a00e5b70:  02 80 00 32  be  0xa00e5c38
a00e5b74:  98 02 20 01  add  %o0, 1, %o4
a00e5b78:  d2 06 40 10  ld  [ %i1 + %l0 ], %o1
a00e5b7c:  d4 04 c0 10  ld  [ %l3 + %l0 ], %o2
a00e5b80:  d6 04 80 10  ld  [ %l2 + %l0 ], %o3
a00e5b84:  7f ff ea fc  call  0xa00e0774
a00e5b88:  90 10 00 18  mov  %i0, %o0
a00e5b8c:  7f ff e9 41  call  0xa00e0090
a00e5b90:  90 10 00 18  mov  %i0, %o0
a00e5b94:  90 10 00 18  mov  %i0, %o0
a00e5b98:  92 10 20 05  mov  5, %o1
a00e5b9c:  94 10 20 00  clr  %o2
a00e5ba0:  7f ff f9 33  call  0xa00e406c
a00e5ba4:  17 00 00 04  sethi  %hi(0x1000), %o3
a00e5ba8:  80 a6 bf ff  cmp  %i2, -1
a00e5bac:  02 80 00 33  be  0xa00e5c78
a00e5bb0:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e5bb4:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e5bb8:  90 12 a2 68  or  %o2, 0x268, %o0	! 0xa8026668
a00e5bbc:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00e5bc0:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e5bc4:  d2 02 00 10  ld  [ %o0 + %l0 ], %o1
a00e5bc8:  a2 13 62 48  or  %o5, 0x248, %l1
a00e5bcc:  82 13 e2 58  or  %o7, 0x258, %g1
a00e5bd0:  d6 04 40 10  ld  [ %l1 + %l0 ], %o3
a00e5bd4:  d4 00 40 10  ld  [ %g1 + %l0 ], %o2
a00e5bd8:  7f ff ea df  call  0xa00e0754
a00e5bdc:  90 10 00 18  mov  %i0, %o0
a00e5be0:  a2 10 00 08  mov  %o0, %l1
a00e5be4:  90 10 00 18  mov  %i0, %o0
a00e5be8:  d2 06 40 10  ld  [ %i1 + %l0 ], %o1
a00e5bec:  d4 04 c0 10  ld  [ %l3 + %l0 ], %o2
a00e5bf0:  d6 04 80 10  ld  [ %l2 + %l0 ], %o3
a00e5bf4:  7f ff ea d8  call  0xa00e0754
a00e5bf8:  01 00 00 00  nop
a00e5bfc:  80 8c 60 02  btst  2, %l1
a00e5c00:  02 bf ff a2  be  0xa00e5a88
a00e5c04:  80 a2 20 07  cmp  %o0, 7
a00e5c08:  22 80 00 58  be,a   0xa00e5d68
a00e5c0c:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00e5c10:  80 a6 bf ff  cmp  %i2, -1
a00e5c14:  12 bf ff d2  bne  0xa00e5b5c
a00e5c18:  90 10 00 18  mov  %i0, %o0
a00e5c1c:  92 15 a1 18  or  %l6, 0x118, %o1
a00e5c20:  94 15 61 08  or  %l5, 0x108, %o2
a00e5c24:  7f ff ea cc  call  0xa00e0754
a00e5c28:  96 15 20 f8  or  %l4, 0xf8, %o3
a00e5c2c:  80 a6 bf ff  cmp  %i2, -1
a00e5c30:  12 bf ff d2  bne  0xa00e5b78
a00e5c34:  98 02 20 01  add  %o0, 1, %o4
a00e5c38:  92 15 a1 18  or  %l6, 0x118, %o1
a00e5c3c:  94 15 61 08  or  %l5, 0x108, %o2
a00e5c40:  96 15 20 f8  or  %l4, 0xf8, %o3
a00e5c44:  7f ff ea cc  call  0xa00e0774
a00e5c48:  90 10 00 18  mov  %i0, %o0
a00e5c4c:  7f ff e9 11  call  0xa00e0090
a00e5c50:  90 10 00 18  mov  %i0, %o0
a00e5c54:  90 10 00 18  mov  %i0, %o0
a00e5c58:  92 10 20 05  mov  5, %o1
a00e5c5c:  94 10 20 00  clr  %o2
a00e5c60:  7f ff f9 03  call  0xa00e406c
a00e5c64:  17 00 00 04  sethi  %hi(0x1000), %o3
a00e5c68:  80 a6 bf ff  cmp  %i2, -1
a00e5c6c:  32 bf ff d3  bne,a   0xa00e5bb8
a00e5c70:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e5c74:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e5c78:  92 12 e2 68  or  %o3, 0x268, %o1	! 0xa8026668
a00e5c7c:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00e5c80:  94 16 e2 58  or  %i3, 0x258, %o2
a00e5c84:  96 13 22 48  or  %o4, 0x248, %o3
a00e5c88:  7f ff ea b3  call  0xa00e0754
a00e5c8c:  90 10 00 18  mov  %i0, %o0
a00e5c90:  a2 10 00 08  mov  %o0, %l1
a00e5c94:  90 10 00 18  mov  %i0, %o0
a00e5c98:  92 15 a1 18  or  %l6, 0x118, %o1
a00e5c9c:  94 15 61 08  or  %l5, 0x108, %o2
a00e5ca0:  10 bf ff d5  b  0xa00e5bf4
a00e5ca4:  96 15 20 f8  or  %l4, 0xf8, %o3
a00e5ca8:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e5cac:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e5cb0:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00e5cb4:  92 15 62 38  or  %l5, 0x238, %o1
a00e5cb8:  94 15 a2 28  or  %l6, 0x228, %o2
a00e5cbc:  96 15 22 18  or  %l4, 0x218, %o3
a00e5cc0:  7f ff ea a5  call  0xa00e0754
a00e5cc4:  90 10 00 18  mov  %i0, %o0
a00e5cc8:  98 12 20 02  or  %o0, 2, %o4
a00e5ccc:  90 10 00 18  mov  %i0, %o0
a00e5cd0:  92 15 62 38  or  %l5, 0x238, %o1
a00e5cd4:  94 15 a2 28  or  %l6, 0x228, %o2
a00e5cd8:  7f ff ea a7  call  0xa00e0774
a00e5cdc:  96 15 22 18  or  %l4, 0x218, %o3
a00e5ce0:  3b 2a 00 99  sethi  %hi(0xa8026400), %i5
a00e5ce4:  39 2a 00 99  sethi  %hi(0xa8026400), %i4
a00e5ce8:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00e5cec:  90 10 00 18  mov  %i0, %o0
a00e5cf0:  92 17 61 d8  or  %i5, 0x1d8, %o1
a00e5cf4:  94 17 21 c8  or  %i4, 0x1c8, %o2
a00e5cf8:  10 bf fe d4  b  0xa00e5848
a00e5cfc:  96 15 e1 b8  or  %l7, 0x1b8, %o3
a00e5d00:  92 15 62 38  or  %l5, 0x238, %o1
a00e5d04:  94 15 a2 28  or  %l6, 0x228, %o2
a00e5d08:  96 15 22 18  or  %l4, 0x218, %o3
a00e5d0c:  7f ff ea 92  call  0xa00e0754
a00e5d10:  90 10 00 18  mov  %i0, %o0
a00e5d14:  98 0a 3f fd  and  %o0, -3, %o4
a00e5d18:  92 15 62 38  or  %l5, 0x238, %o1
a00e5d1c:  94 15 a2 28  or  %l6, 0x228, %o2
a00e5d20:  96 15 22 18  or  %l4, 0x218, %o3
a00e5d24:  7f ff ea 94  call  0xa00e0774
a00e5d28:  90 10 00 18  mov  %i0, %o0
a00e5d2c:  90 10 00 18  mov  %i0, %o0
a00e5d30:  92 17 61 d8  or  %i5, 0x1d8, %o1
a00e5d34:  94 17 21 c8  or  %i4, 0x1c8, %o2
a00e5d38:  10 bf fe f8  b  0xa00e5918
a00e5d3c:  96 15 e1 b8  or  %l7, 0x1b8, %o3
a00e5d40:  7f ff e6 b3  call  0xa00df80c
a00e5d44:  2f 00 06 66  sethi  %hi(0x199800), %l7
a00e5d48:  7f ff eb 9e  call  0xa00e0bc0
a00e5d4c:  01 00 00 00  nop
a00e5d50:  92 10 00 1a  mov  %i2, %o1
a00e5d54:  90 15 e1 88  or  %l7, 0x188, %o0
a00e5d58:  7f ff e5 06  call  0xa00df170
a00e5d5c:  94 10 00 09  mov  %o1, %o2
a00e5d60:  10 80 00 98  b  0xa00e5fc0
a00e5d64:  90 10 3f ff  mov  -1, %o0
a00e5d68:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00e5d6c:  10 80 00 33  b  0xa00e5e38
a00e5d70:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00e5d74:  d2 07 00 10  ld  [ %i4 + %l0 ], %o1
a00e5d78:  d4 07 40 10  ld  [ %i5 + %l0 ], %o2
a00e5d7c:  7f ff ea 76  call  0xa00e0754
a00e5d80:  d6 05 c0 10  ld  [ %l7 + %l0 ], %o3
a00e5d84:  80 a6 bf ff  cmp  %i2, -1
a00e5d88:  02 80 00 36  be  0xa00e5e60
a00e5d8c:  98 02 20 01  add  %o0, 1, %o4
a00e5d90:  d2 07 00 10  ld  [ %i4 + %l0 ], %o1
a00e5d94:  d4 07 40 10  ld  [ %i5 + %l0 ], %o2
a00e5d98:  d6 05 c0 10  ld  [ %l7 + %l0 ], %o3
a00e5d9c:  7f ff ea 76  call  0xa00e0774
a00e5da0:  90 10 00 18  mov  %i0, %o0
a00e5da4:  7f ff e8 bb  call  0xa00e0090
a00e5da8:  90 10 00 18  mov  %i0, %o0
a00e5dac:  90 10 00 18  mov  %i0, %o0
a00e5db0:  92 10 20 05  mov  5, %o1
a00e5db4:  94 10 20 00  clr  %o2
a00e5db8:  7f ff f8 ad  call  0xa00e406c
a00e5dbc:  17 00 00 04  sethi  %hi(0x1000), %o3
a00e5dc0:  80 a6 bf ff  cmp  %i2, -1
a00e5dc4:  02 80 00 37  be  0xa00e5ea0
a00e5dc8:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e5dcc:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00e5dd0:  96 14 62 58  or  %l1, 0x258, %o3	! 0xa8026658
a00e5dd4:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e5dd8:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00e5ddc:  d4 02 c0 10  ld  [ %o3 + %l0 ], %o2
a00e5de0:  9a 12 62 68  or  %o1, 0x268, %o5
a00e5de4:  b2 13 22 48  or  %o4, 0x248, %i1
a00e5de8:  d2 03 40 10  ld  [ %o5 + %l0 ], %o1
a00e5dec:  d6 06 40 10  ld  [ %i1 + %l0 ], %o3
a00e5df0:  7f ff ea 59  call  0xa00e0754
a00e5df4:  90 10 00 18  mov  %i0, %o0
a00e5df8:  a2 10 00 08  mov  %o0, %l1
a00e5dfc:  90 10 00 18  mov  %i0, %o0
a00e5e00:  d2 07 00 10  ld  [ %i4 + %l0 ], %o1
a00e5e04:  d4 07 40 10  ld  [ %i5 + %l0 ], %o2
a00e5e08:  d6 05 c0 10  ld  [ %l7 + %l0 ], %o3
a00e5e0c:  7f ff ea 52  call  0xa00e0754
a00e5e10:  01 00 00 00  nop
a00e5e14:  94 1a 20 07  xor  %o0, 7, %o2
a00e5e18:  80 a0 00 0a  cmp  %g0, %o2
a00e5e1c:  9e 60 3f ff  subx  %g0, -1, %o7
a00e5e20:  83 34 60 01  srl  %l1, 1, %g1
a00e5e24:  80 88 40 0f  btst  %g1, %o7
a00e5e28:  12 80 00 3f  bne  0xa00e5f24
a00e5e2c:  80 8c 60 02  btst  2, %l1
a00e5e30:  02 bf ff 17  be  0xa00e5a8c
a00e5e34:  90 10 00 18  mov  %i0, %o0
a00e5e38:  80 a6 bf ff  cmp  %i2, -1
a00e5e3c:  12 bf ff ce  bne  0xa00e5d74
a00e5e40:  90 10 00 18  mov  %i0, %o0
a00e5e44:  92 15 20 e8  or  %l4, 0xe8, %o1
a00e5e48:  94 14 e0 d8  or  %l3, 0xd8, %o2
a00e5e4c:  7f ff ea 42  call  0xa00e0754
a00e5e50:  96 14 a0 c8  or  %l2, 0xc8, %o3
a00e5e54:  80 a6 bf ff  cmp  %i2, -1
a00e5e58:  12 bf ff ce  bne  0xa00e5d90
a00e5e5c:  98 02 20 01  add  %o0, 1, %o4
a00e5e60:  92 15 20 e8  or  %l4, 0xe8, %o1
a00e5e64:  94 14 e0 d8  or  %l3, 0xd8, %o2
a00e5e68:  96 14 a0 c8  or  %l2, 0xc8, %o3
a00e5e6c:  7f ff ea 42  call  0xa00e0774
a00e5e70:  90 10 00 18  mov  %i0, %o0
a00e5e74:  7f ff e8 87  call  0xa00e0090
a00e5e78:  90 10 00 18  mov  %i0, %o0
a00e5e7c:  90 10 00 18  mov  %i0, %o0
a00e5e80:  92 10 20 05  mov  5, %o1
a00e5e84:  94 10 20 00  clr  %o2
a00e5e88:  7f ff f8 79  call  0xa00e406c
a00e5e8c:  17 00 00 04  sethi  %hi(0x1000), %o3
a00e5e90:  80 a6 bf ff  cmp  %i2, -1
a00e5e94:  32 bf ff cf  bne,a   0xa00e5dd0
a00e5e98:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00e5e9c:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e5ea0:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e5ea4:  92 15 a2 68  or  %l6, 0x268, %o1
a00e5ea8:  94 16 e2 58  or  %i3, 0x258, %o2
a00e5eac:  96 15 62 48  or  %l5, 0x248, %o3
a00e5eb0:  7f ff ea 29  call  0xa00e0754
a00e5eb4:  90 10 00 18  mov  %i0, %o0
a00e5eb8:  a2 10 00 08  mov  %o0, %l1
a00e5ebc:  90 10 00 18  mov  %i0, %o0
a00e5ec0:  92 15 20 e8  or  %l4, 0xe8, %o1
a00e5ec4:  94 14 e0 d8  or  %l3, 0xd8, %o2
a00e5ec8:  10 bf ff d1  b  0xa00e5e0c
a00e5ecc:  96 14 a0 c8  or  %l2, 0xc8, %o3
a00e5ed0:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e5ed4:  37 2a 00 99  sethi  %hi(0xa8026400), %i3
a00e5ed8:  92 12 a2 68  or  %o2, 0x268, %o1
a00e5edc:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00e5ee0:  90 10 00 18  mov  %i0, %o0
a00e5ee4:  94 16 e2 58  or  %i3, 0x258, %o2
a00e5ee8:  10 bf fe 6f  b  0xa00e58a4
a00e5eec:  96 13 e2 48  or  %o7, 0x248, %o3
a00e5ef0:  92 10 20 05  mov  5, %o1
a00e5ef4:  94 10 20 00  clr  %o2
a00e5ef8:  7f ff f8 5d  call  0xa00e406c
a00e5efc:  17 00 00 04  sethi  %hi(0x1000), %o3
a00e5f00:  10 bf fe 5d  b  0xa00e5874
a00e5f04:  80 a6 bf ff  cmp  %i2, -1
a00e5f08:  33 2a 00 99  sethi  %hi(0xa8026400), %i1
a00e5f0c:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e5f10:  35 2a 00 99  sethi  %hi(0xa8026400), %i2
a00e5f14:  92 16 62 08  or  %i1, 0x208, %o1
a00e5f18:  94 15 a1 f8  or  %l6, 0x1f8, %o2
a00e5f1c:  10 bf fe f7  b  0xa00e5af8
a00e5f20:  96 16 a1 e8  or  %i2, 0x1e8, %o3
a00e5f24:  7f ff e6 3a  call  0xa00df80c
a00e5f28:  31 00 06 66  sethi  %hi(0x199800), %i0
a00e5f2c:  7f ff eb 25  call  0xa00e0bc0
a00e5f30:  01 00 00 00  nop
a00e5f34:  92 10 00 1a  mov  %i2, %o1
a00e5f38:  10 bf ff 88  b  0xa00e5d58
a00e5f3c:  90 16 21 c8  or  %i0, 0x1c8, %o0
a00e5f40:  02 80 00 19  be  0xa00e5fa4
a00e5f44:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e5f48:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00e5f4c:  3b 2a 00 99  sethi  %hi(0xa8026400), %i5
a00e5f50:  a7 2e a0 02  sll  %i2, 2, %l3
a00e5f54:  90 15 61 e8  or  %l5, 0x1e8, %o0
a00e5f58:  ae 14 22 08  or  %l0, 0x208, %l7
a00e5f5c:  a4 17 61 f8  or  %i5, 0x1f8, %l2
a00e5f60:  d6 02 00 13  ld  [ %o0 + %l3 ], %o3
a00e5f64:  d2 05 c0 13  ld  [ %l7 + %l3 ], %o1
a00e5f68:  d4 04 80 13  ld  [ %l2 + %l3 ], %o2
a00e5f6c:  90 10 00 18  mov  %i0, %o0
a00e5f70:  7f ff ea 01  call  0xa00e0774
a00e5f74:  98 10 20 01  mov  1, %o4
a00e5f78:  92 10 00 1a  mov  %i2, %o1
a00e5f7c:  90 10 00 18  mov  %i0, %o0
a00e5f80:  7f ff fd 9b  call  0xa00e55ec
a00e5f84:  94 10 3f f8  mov  -8, %o2
a00e5f88:  80 a2 20 00  cmp  %o0, 0
a00e5f8c:  12 bf fe e4  bne  0xa00e5b1c
a00e5f90:  01 00 00 00  nop
a00e5f94:  7f ff e8 3f  call  0xa00e0090
a00e5f98:  90 10 00 18  mov  %i0, %o0
a00e5f9c:  10 bf fe db  b  0xa00e5b08
a00e5fa0:  90 10 00 18  mov  %i0, %o0
a00e5fa4:  39 2a 00 99  sethi  %hi(0xa8026400), %i4
a00e5fa8:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00e5fac:  37 2a 00 99  sethi  %hi(0xa8026400), %i3
a00e5fb0:  92 17 22 08  or  %i4, 0x208, %o1
a00e5fb4:  94 15 21 f8  or  %l4, 0x1f8, %o2
a00e5fb8:  10 bf ff ed  b  0xa00e5f6c
a00e5fbc:  96 16 e1 e8  or  %i3, 0x1e8, %o3
a00e5fc0:  81 c7 e0 08  ret
a00e5fc4:  91 e8 00 08  restore  %g0, %o0, %o0
