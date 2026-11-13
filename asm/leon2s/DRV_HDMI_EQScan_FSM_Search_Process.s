# leon2s DRV_HDMI_EQScan_FSM_Search_Process 0xa007890c-0xa0078dc8 (1212 bytes)
a007890c:  9d e3 bf 90  save  %sp, -112, %sp
a0078910:  27 2a 01 e1  sethi  %hi(0xa8078400), %l3
a0078914:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1	! 0xa8078634
a0078918:  80 88 60 02  btst  2, %g1
a007891c:  a4 10 00 18  mov  %i0, %l2
a0078920:  02 80 00 0a  be  0xa0078948
a0078924:  a8 10 20 00  clr  %l4
a0078928:  92 06 20 41  add  %i0, 0x41, %o1
a007892c:  93 2a 60 18  sll  %o1, 0x18, %o1
a0078930:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a0078934:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a0078938:  90 12 20 58  or  %o0, 0x58, %o0
a007893c:  93 3a 60 18  sra  %o1, 0x18, %o1
a0078940:  7f ff e9 c1  call  0xa0073044
a0078944:  94 12 a1 88  or  %o2, 0x188, %o2
a0078948:  a0 0c a0 ff  and  %l2, 0xff, %l0
a007894c:  82 04 00 10  add  %l0, %l0, %g1
a0078950:  82 00 40 10  add  %g1, %l0, %g1
a0078954:  23 2a 01 f3  sethi  %hi(0xa807cc00), %l1
a0078958:  97 28 60 02  sll  %g1, 2, %o3
a007895c:  94 14 60 c4  or  %l1, 0xc4, %o2
a0078960:  82 02 c0 0a  add  %o3, %o2, %g1
a0078964:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0078968:  80 a0 60 01  cmp  %g1, 1
a007896c:  12 80 00 f3  bne  0xa0078d38
a0078970:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a0078974:  2d 2a 01 ea  sethi  %hi(0xa807a800), %l6
a0078978:  94 0c a0 ff  and  %l2, 0xff, %o2
a007897c:  82 15 a1 f0  or  %l6, 0x1f0, %g1
a0078980:  9a 5a a8 98  smul  %o2, 0x898, %o5
a0078984:  9a 03 40 01  add  %o5, %g1, %o5
a0078988:  b0 0d 20 ff  and  %l4, 0xff, %i0
a007898c:  98 03 40 18  add  %o5, %i0, %o4
a0078990:  c2 0b 20 31  ldub  [ %o4 + 0x31 ], %g1
a0078994:  80 a0 60 01  cmp  %g1, 1
a0078998:  02 80 00 bb  be  0xa0078c84
a007899c:  82 02 80 0a  add  %o2, %o2, %g1
a00789a0:  82 00 40 0a  add  %g1, %o2, %g1
a00789a4:  2f 2a 01 f3  sethi  %hi(0xa807cc00), %l7
a00789a8:  9a 15 e0 c4  or  %l7, 0xc4, %o5	! 0xa807ccc4
a00789ac:  83 28 60 02  sll  %g1, 2, %g1
a00789b0:  82 00 40 0d  add  %g1, %o5, %g1
a00789b4:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a00789b8:  80 a0 60 00  cmp  %g1, 0
a00789bc:  02 80 00 04  be  0xa00789cc
a00789c0:  da 0b 20 09  ldub  [ %o4 + 9 ], %o5
a00789c4:  10 80 00 03  b  0xa00789d0
a00789c8:  80 a3 60 03  cmp  %o5, 3
a00789cc:  80 a3 60 01  cmp  %o5, 1
a00789d0:  38 80 00 ae  bgu,a   0xa0078c88
a00789d4:  a8 05 20 01  inc  %l4
a00789d8:  82 02 80 0a  add  %o2, %o2, %g1
a00789dc:  82 00 40 0a  add  %g1, %o2, %g1
a00789e0:  83 28 60 02  sll  %g1, 2, %g1
a00789e4:  98 15 e0 c4  or  %l7, 0xc4, %o4
a00789e8:  96 15 a1 f0  or  %l6, 0x1f0, %o3
a00789ec:  9a 5a a8 98  smul  %o2, 0x898, %o5
a00789f0:  82 00 40 0c  add  %g1, %o4, %g1
a00789f4:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a00789f8:  9a 03 40 0b  add  %o5, %o3, %o5
a00789fc:  9a 03 40 18  add  %o5, %i0, %o5
a0078a00:  80 a0 60 00  cmp  %g1, 0
a0078a04:  02 80 00 07  be  0xa0078a20
a0078a08:  c2 0b 60 09  ldub  [ %o5 + 9 ], %g1
a0078a0c:  80 a0 60 02  cmp  %g1, 2
a0078a10:  08 80 00 08  bleu  0xa0078a30
a0078a14:  80 a6 20 02  cmp  %i0, 2
a0078a18:  10 80 00 38  b  0xa0078af8
a0078a1c:  82 5a a2 26  smul  %o2, 0x226, %g1
a0078a20:  80 a0 60 00  cmp  %g1, 0
a0078a24:  12 80 00 35  bne  0xa0078af8
a0078a28:  82 5a a2 26  smul  %o2, 0x226, %g1
a0078a2c:  80 a6 20 02  cmp  %i0, 2
a0078a30:  18 80 00 1b  bgu  0xa0078a9c
a0078a34:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0078a38:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0078a3c:  82 10 63 96  or  %g1, 0x396, %g1	! 0xa00b3b96
a0078a40:  a0 06 00 18  add  %i0, %i0, %l0
a0078a44:  d6 10 40 10  lduh  [ %g1 + %l0 ], %o3
a0078a48:  90 10 20 01  mov  1, %o0
a0078a4c:  40 00 ba 76  call  0xa00a7424
a0078a50:  92 10 20 0f  mov  0xf, %o1
a0078a54:  90 0c a0 ff  and  %l2, 0xff, %o0
a0078a58:  9a 15 a1 f0  or  %l6, 0x1f0, %o5
a0078a5c:  82 5a 28 98  smul  %o0, 0x898, %g1
a0078a60:  82 00 40 0d  add  %g1, %o5, %g1
a0078a64:  82 00 40 18  add  %g1, %i0, %g1
a0078a68:  da 08 60 09  ldub  [ %g1 + 9 ], %o5
a0078a6c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0078a70:  82 10 62 c8  or  %g1, 0x2c8, %g1	! 0xa00b3ac8
a0078a74:  d6 08 40 0d  ldub  [ %g1 + %o5 ], %o3
a0078a78:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0078a7c:  96 0a e0 0f  and  %o3, 0xf, %o3
a0078a80:  82 10 63 90  or  %g1, 0x390, %g1
a0078a84:  15 3f c3 ff  sethi  %hi(0xff0ffc00), %o2
a0078a88:  d2 10 40 10  lduh  [ %g1 + %l0 ], %o1
a0078a8c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0078a90:  40 00 ba 7e  call  0xa00a7488
a0078a94:  97 2a e0 14  sll  %o3, 0x14, %o3
a0078a98:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0078a9c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0078aa0:  80 88 60 02  btst  2, %g1
a0078aa4:  22 80 00 79  be,a   0xa0078c88
a0078aa8:  a8 05 20 01  inc  %l4
a0078aac:  82 0c a0 ff  and  %l2, 0xff, %g1
a0078ab0:  1b 2a 01 ea  sethi  %hi(0xa807a800), %o5
a0078ab4:  9a 13 61 f0  or  %o5, 0x1f0, %o5	! 0xa807a9f0
a0078ab8:  82 58 68 98  smul  %g1, 0x898, %g1
a0078abc:  82 00 40 0d  add  %g1, %o5, %g1
a0078ac0:  82 00 40 18  add  %g1, %i0, %g1
a0078ac4:  d6 08 60 09  ldub  [ %g1 + 9 ], %o3
a0078ac8:  92 04 a0 41  add  %l2, 0x41, %o1
a0078acc:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0078ad0:  82 10 62 c8  or  %g1, 0x2c8, %g1	! 0xa00b3ac8
a0078ad4:  93 2a 60 18  sll  %o1, 0x18, %o1
a0078ad8:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0078adc:  93 3a 60 18  sra  %o1, 0x18, %o1
a0078ae0:  94 10 00 18  mov  %i0, %o2
a0078ae4:  d8 08 40 0b  ldub  [ %g1 + %o3 ], %o4
a0078ae8:  7f ff e9 57  call  0xa0073044
a0078aec:  90 12 21 30  or  %o0, 0x130, %o0
a0078af0:  10 80 00 66  b  0xa0078c88
a0078af4:  a8 05 20 01  inc  %l4
a0078af8:  82 00 40 18  add  %g1, %i0, %g1
a0078afc:  83 28 60 02  sll  %g1, 2, %g1
a0078b00:  9a 15 a1 f0  or  %l6, 0x1f0, %o5
a0078b04:  82 00 40 0d  add  %g1, %o5, %g1
a0078b08:  e2 00 60 38  ld  [ %g1 + 0x38 ], %l1
a0078b0c:  aa 10 20 00  clr  %l5
a0078b10:  10 80 00 0e  b  0xa0078b48
a0078b14:  a6 10 20 01  mov  1, %l3
a0078b18:  e0 03 20 38  ld  [ %o4 + 0x38 ], %l0
a0078b1c:  80 88 60 02  btst  2, %g1
a0078b20:  02 80 00 04  be  0xa0078b30
a0078b24:  98 10 00 10  mov  %l0, %o4
a0078b28:  7f ff e9 47  call  0xa0073044
a0078b2c:  e2 23 a0 5c  st  %l1, [ %sp + 0x5c ]
a0078b30:  80 a4 00 11  cmp  %l0, %l1
a0078b34:  3a 80 00 05  bcc,a   0xa0078b48
a0078b38:  a6 04 e0 01  inc  %l3
a0078b3c:  a2 10 00 10  mov  %l0, %l1
a0078b40:  aa 10 00 13  mov  %l3, %l5
a0078b44:  a6 04 e0 01  inc  %l3
a0078b48:  a0 0c a0 ff  and  %l2, 0xff, %l0
a0078b4c:  82 04 00 10  add  %l0, %l0, %g1
a0078b50:  82 00 40 10  add  %g1, %l0, %g1
a0078b54:  9a 15 e0 c4  or  %l7, 0xc4, %o5
a0078b58:  83 28 60 02  sll  %g1, 2, %g1
a0078b5c:  82 00 40 0d  add  %g1, %o5, %g1
a0078b60:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0078b64:  9e 0c e0 ff  and  %l3, 0xff, %o7
a0078b68:  80 a0 60 00  cmp  %g1, 0
a0078b6c:  82 03 c0 0f  add  %o7, %o7, %g1
a0078b70:  98 5c 22 26  smul  %l0, 0x226, %o4
a0078b74:  82 00 40 0f  add  %g1, %o7, %g1
a0078b78:  82 00 40 0c  add  %g1, %o4, %g1
a0078b7c:  82 00 40 18  add  %g1, %i0, %g1
a0078b80:  9a 15 a1 f0  or  %l6, 0x1f0, %o5
a0078b84:  83 28 60 02  sll  %g1, 2, %g1
a0078b88:  92 04 a0 41  add  %l2, 0x41, %o1
a0078b8c:  98 00 40 0d  add  %g1, %o5, %o4
a0078b90:  93 2a 60 18  sll  %o1, 0x18, %o1
a0078b94:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0078b98:  90 12 21 70  or  %o0, 0x170, %o0	! 0xa0067570
a0078b9c:  93 3a 60 18  sra  %o1, 0x18, %o1
a0078ba0:  96 10 00 0f  mov  %o7, %o3
a0078ba4:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0078ba8:  9a 0d 60 ff  and  %l5, 0xff, %o5
a0078bac:  02 80 00 07  be  0xa0078bc8
a0078bb0:  94 10 00 18  mov  %i0, %o2
a0078bb4:  80 a3 e0 02  cmp  %o7, 2
a0078bb8:  08 bf ff d8  bleu  0xa0078b18
a0078bbc:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1
a0078bc0:  10 80 00 06  b  0xa0078bd8
a0078bc4:  80 88 60 02  btst  2, %g1
a0078bc8:  80 a3 e0 00  cmp  %o7, 0
a0078bcc:  02 bf ff d3  be  0xa0078b18
a0078bd0:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1
a0078bd4:  80 88 60 02  btst  2, %g1
a0078bd8:  02 80 00 0a  be  0xa0078c00
a0078bdc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0078be0:  92 04 a0 41  add  %l2, 0x41, %o1
a0078be4:  93 2a 60 18  sll  %o1, 0x18, %o1
a0078be8:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0078bec:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0xa00675d8
a0078bf0:  93 3a 60 18  sra  %o1, 0x18, %o1
a0078bf4:  7f ff e9 14  call  0xa0073044
a0078bf8:  94 0d 20 ff  and  %l4, 0xff, %o2
a0078bfc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0078c00:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0078c04:  80 88 60 02  btst  2, %g1
a0078c08:  02 80 00 0e  be  0xa0078c40
a0078c0c:  98 0d 20 ff  and  %l4, 0xff, %o4
a0078c10:  92 04 a0 41  add  %l2, 0x41, %o1
a0078c14:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0078c18:  96 0d 60 ff  and  %l5, 0xff, %o3
a0078c1c:  93 2a 60 18  sll  %o1, 0x18, %o1
a0078c20:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0078c24:  82 10 62 c8  or  %g1, 0x2c8, %g1
a0078c28:  90 12 22 18  or  %o0, 0x218, %o0
a0078c2c:  93 3a 60 18  sra  %o1, 0x18, %o1
a0078c30:  d8 08 40 0b  ldub  [ %g1 + %o3 ], %o4
a0078c34:  7f ff e9 04  call  0xa0073044
a0078c38:  94 0d 20 ff  and  %l4, 0xff, %o2
a0078c3c:  98 0d 20 ff  and  %l4, 0xff, %o4
a0078c40:  80 a3 20 02  cmp  %o4, 2
a0078c44:  38 80 00 11  bgu,a   0xa0078c88
a0078c48:  a8 05 20 01  inc  %l4
a0078c4c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0078c50:  9a 0d 60 ff  and  %l5, 0xff, %o5
a0078c54:  82 10 62 c8  or  %g1, 0x2c8, %g1
a0078c58:  d6 08 40 0d  ldub  [ %g1 + %o5 ], %o3
a0078c5c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0078c60:  9a 03 00 0c  add  %o4, %o4, %o5
a0078c64:  96 0a e0 0f  and  %o3, 0xf, %o3
a0078c68:  82 10 63 90  or  %g1, 0x390, %g1
a0078c6c:  15 3f c3 ff  sethi  %hi(0xff0ffc00), %o2
a0078c70:  d2 10 40 0d  lduh  [ %g1 + %o5 ], %o1
a0078c74:  90 10 00 10  mov  %l0, %o0
a0078c78:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0078c7c:  40 00 ba 03  call  0xa00a7488
a0078c80:  97 2a e0 14  sll  %o3, 0x14, %o3
a0078c84:  a8 05 20 01  inc  %l4
a0078c88:  82 0d 20 ff  and  %l4, 0xff, %g1
a0078c8c:  80 a0 60 02  cmp  %g1, 2
a0078c90:  28 bf ff 3a  bleu,a   0xa0078978
a0078c94:  2d 2a 01 ea  sethi  %hi(0xa807a800), %l6
a0078c98:  a0 0c a0 ff  and  %l2, 0xff, %l0
a0078c9c:  7f ff fe d6  call  0xa00787f4
a0078ca0:  90 10 00 10  mov  %l0, %o0
a0078ca4:  15 2a 01 ea  sethi  %hi(0xa807a800), %o2
a0078ca8:  82 12 a1 f0  or  %o2, 0x1f0, %g1	! 0xa807a9f0
a0078cac:  9a 5c 28 98  smul  %l0, 0x898, %o5
a0078cb0:  9a 03 40 01  add  %o5, %g1, %o5
a0078cb4:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0078cb8:  82 10 61 a0  or  %g1, 0x1a0, %g1	! 0xa80761a0
a0078cbc:  98 10 20 06  mov  6, %o4
a0078cc0:  d8 28 40 10  stb  %o4, [ %g1 + %l0 ]
a0078cc4:  82 10 20 01  mov  1, %g1
a0078cc8:  c2 2b 60 28  stb  %g1, [ %o5 + 0x28 ]
a0078ccc:  c0 2b 60 30  clrb  [ %o5 + 0x30 ]
a0078cd0:  a8 10 20 00  clr  %l4
a0078cd4:  82 0d 20 ff  and  %l4, 0xff, %g1
a0078cd8:  98 03 40 01  add  %o5, %g1, %o4
a0078cdc:  a8 05 20 01  inc  %l4
a0078ce0:  c2 0b 20 31  ldub  [ %o4 + 0x31 ], %g1
a0078ce4:  80 a0 60 01  cmp  %g1, 1
a0078ce8:  02 80 00 05  be  0xa0078cfc
a0078cec:  96 0d 20 ff  and  %l4, 0xff, %o3
a0078cf0:  c0 2b 20 34  clrb  [ %o4 + 0x34 ]
a0078cf4:  c0 2b 20 03  clrb  [ %o4 + 3 ]
a0078cf8:  c0 2b 20 2a  clrb  [ %o4 + 0x2a ]
a0078cfc:  80 a2 e0 02  cmp  %o3, 2
a0078d00:  08 bf ff f6  bleu  0xa0078cd8
a0078d04:  82 0d 20 ff  and  %l4, 0xff, %g1
a0078d08:  82 12 a1 f0  or  %o2, 0x1f0, %g1
a0078d0c:  98 5c 28 98  smul  %l0, 0x898, %o4
a0078d10:  98 03 00 01  add  %o4, %g1, %o4
a0078d14:  9a 04 00 10  add  %l0, %l0, %o5
a0078d18:  9a 03 40 10  add  %o5, %l0, %o5
a0078d1c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0078d20:  9b 2b 60 02  sll  %o5, 2, %o5
a0078d24:  96 10 20 0b  mov  0xb, %o3
a0078d28:  82 10 60 c4  or  %g1, 0xc4, %g1
a0078d2c:  d6 20 40 0d  st  %o3, [ %g1 + %o5 ]
a0078d30:  10 80 00 24  b  0xa0078dc0
a0078d34:  c0 2b 20 30  clrb  [ %o4 + 0x30 ]
a0078d38:  98 10 61 f0  or  %g1, 0x1f0, %o4
a0078d3c:  9a 5c 28 98  smul  %l0, 0x898, %o5
a0078d40:  c2 0b 00 0d  ldub  [ %o4 + %o5 ], %g1
a0078d44:  80 a0 60 17  cmp  %g1, 0x17
a0078d48:  08 80 00 0c  bleu  0xa0078d78
a0078d4c:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1
a0078d50:  9a 03 40 0c  add  %o5, %o4, %o5
a0078d54:  c2 0b 60 01  ldub  [ %o5 + 1 ], %g1
a0078d58:  80 a0 60 17  cmp  %g1, 0x17
a0078d5c:  08 80 00 07  bleu  0xa0078d78
a0078d60:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1
a0078d64:  c2 0b 60 02  ldub  [ %o5 + 2 ], %g1
a0078d68:  80 a0 60 17  cmp  %g1, 0x17
a0078d6c:  18 80 00 13  bgu  0xa0078db8
a0078d70:  82 10 20 10  mov  0x10, %g1
a0078d74:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1
a0078d78:  80 88 60 02  btst  2, %g1
a0078d7c:  02 80 00 09  be  0xa0078da0
a0078d80:  82 04 00 10  add  %l0, %l0, %g1
a0078d84:  92 04 a0 41  add  %l2, 0x41, %o1
a0078d88:  93 2a 60 18  sll  %o1, 0x18, %o1
a0078d8c:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0078d90:  90 12 22 58  or  %o0, 0x258, %o0	! 0xa0067658
a0078d94:  7f ff e8 ac  call  0xa0073044
a0078d98:  93 3a 60 18  sra  %o1, 0x18, %o1
a0078d9c:  82 04 00 10  add  %l0, %l0, %g1
a0078da0:  82 00 40 10  add  %g1, %l0, %g1
a0078da4:  98 14 60 c4  or  %l1, 0xc4, %o4
a0078da8:  83 28 60 02  sll  %g1, 2, %g1
a0078dac:  9a 10 20 0e  mov  0xe, %o5
a0078db0:  10 80 00 04  b  0xa0078dc0
a0078db4:  da 23 00 01  st  %o5, [ %o4 + %g1 ]
a0078db8:  c2 22 80 0b  st  %g1, [ %o2 + %o3 ]
a0078dbc:  c0 2b 68 96  clrb  [ %o5 + 0x896 ]
a0078dc0:  81 c7 e0 08  ret
a0078dc4:  91 e8 20 01  restore  %g0, 1, %o0
