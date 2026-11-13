# leon2s DRV_HDMI_EQScan_FSM_PHY_PreChkError 0xa007796c-0xa0077e68 (1276 bytes)
a007796c:  9d e3 bf 98  save  %sp, -104, %sp
a0077970:  29 2a 01 e1  sethi  %hi(0xa8078400), %l4
a0077974:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1	! 0xa8078634
a0077978:  80 88 60 02  btst  2, %g1
a007797c:  a2 10 00 18  mov  %i0, %l1
a0077980:  02 80 00 5d  be  0xa0077af4
a0077984:  a0 10 20 00  clr  %l0
a0077988:  13 00 00 04  sethi  %hi(0x1000), %o1
a007798c:  92 12 61 48  or  %o1, 0x148, %o1	! 0x1148
a0077990:  40 00 be 61  call  0xa00a7314
a0077994:  90 0e 20 ff  and  %i0, 0xff, %o0
a0077998:  97 32 20 10  srl  %o0, 0x10, %o3
a007799c:  92 06 20 41  add  %i0, 0x41, %o1
a00779a0:  93 2a 60 18  sll  %o1, 0x18, %o1
a00779a4:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a00779a8:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a00779ac:  90 12 23 30  or  %o0, 0x330, %o0
a00779b0:  93 3a 60 18  sra  %o1, 0x18, %o1
a00779b4:  94 12 a1 38  or  %o2, 0x138, %o2
a00779b8:  7f ff ed a3  call  0xa0073044
a00779bc:  96 0a e0 0f  and  %o3, 0xf, %o3
a00779c0:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a00779c4:  80 88 60 02  btst  2, %g1
a00779c8:  02 80 00 4b  be  0xa0077af4
a00779cc:  13 00 00 05  sethi  %hi(0x1400), %o1
a00779d0:  92 12 61 48  or  %o1, 0x148, %o1	! 0x1548
a00779d4:  40 00 be 50  call  0xa00a7314
a00779d8:  90 0e 20 ff  and  %i0, 0xff, %o0
a00779dc:  97 32 20 10  srl  %o0, 0x10, %o3
a00779e0:  92 06 20 41  add  %i0, 0x41, %o1
a00779e4:  93 2a 60 18  sll  %o1, 0x18, %o1
a00779e8:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a00779ec:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a00779f0:  90 12 23 58  or  %o0, 0x358, %o0
a00779f4:  93 3a 60 18  sra  %o1, 0x18, %o1
a00779f8:  94 12 a1 38  or  %o2, 0x138, %o2
a00779fc:  7f ff ed 92  call  0xa0073044
a0077a00:  96 0a e0 0f  and  %o3, 0xf, %o3
a0077a04:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a0077a08:  80 88 60 02  btst  2, %g1
a0077a0c:  02 80 00 3a  be  0xa0077af4
a0077a10:  13 00 00 06  sethi  %hi(0x1800), %o1
a0077a14:  92 12 61 48  or  %o1, 0x148, %o1	! 0x1948
a0077a18:  40 00 be 3f  call  0xa00a7314
a0077a1c:  90 0e 20 ff  and  %i0, 0xff, %o0
a0077a20:  97 32 20 10  srl  %o0, 0x10, %o3
a0077a24:  92 06 20 41  add  %i0, 0x41, %o1
a0077a28:  93 2a 60 18  sll  %o1, 0x18, %o1
a0077a2c:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a0077a30:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a0077a34:  90 12 22 90  or  %o0, 0x290, %o0
a0077a38:  93 3a 60 18  sra  %o1, 0x18, %o1
a0077a3c:  94 12 a1 38  or  %o2, 0x138, %o2
a0077a40:  7f ff ed 81  call  0xa0073044
a0077a44:  96 0a e0 0f  and  %o3, 0xf, %o3
a0077a48:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a0077a4c:  80 88 60 02  btst  2, %g1
a0077a50:  02 80 00 29  be  0xa0077af4
a0077a54:  13 00 00 04  sethi  %hi(0x1000), %o1
a0077a58:  92 12 61 f0  or  %o1, 0x1f0, %o1	! 0x11f0
a0077a5c:  40 00 be 2e  call  0xa00a7314
a0077a60:  90 0e 20 ff  and  %i0, 0xff, %o0
a0077a64:  94 0a 20 ff  and  %o0, 0xff, %o2
a0077a68:  92 06 20 41  add  %i0, 0x41, %o1
a0077a6c:  93 2a 60 18  sll  %o1, 0x18, %o1
a0077a70:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a0077a74:  90 12 22 c0  or  %o0, 0x2c0, %o0	! 0xa00672c0
a0077a78:  7f ff ed 73  call  0xa0073044
a0077a7c:  93 3a 60 18  sra  %o1, 0x18, %o1
a0077a80:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a0077a84:  80 88 60 02  btst  2, %g1
a0077a88:  02 80 00 1b  be  0xa0077af4
a0077a8c:  13 00 00 04  sethi  %hi(0x1000), %o1
a0077a90:  92 12 61 f4  or  %o1, 0x1f4, %o1	! 0x11f4
a0077a94:  40 00 be 20  call  0xa00a7314
a0077a98:  90 0e 20 ff  and  %i0, 0xff, %o0
a0077a9c:  95 32 20 10  srl  %o0, 0x10, %o2
a0077aa0:  92 06 20 41  add  %i0, 0x41, %o1
a0077aa4:  93 2a 60 18  sll  %o1, 0x18, %o1
a0077aa8:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a0077aac:  90 12 22 f0  or  %o0, 0x2f0, %o0	! 0xa00672f0
a0077ab0:  7f ff ed 65  call  0xa0073044
a0077ab4:  93 3a 60 18  sra  %o1, 0x18, %o1
a0077ab8:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a0077abc:  80 88 60 02  btst  2, %g1
a0077ac0:  02 80 00 0d  be  0xa0077af4
a0077ac4:  13 00 00 04  sethi  %hi(0x1000), %o1
a0077ac8:  92 12 61 f4  or  %o1, 0x1f4, %o1	! 0x11f4
a0077acc:  40 00 be 12  call  0xa00a7314
a0077ad0:  90 0e 20 ff  and  %i0, 0xff, %o0
a0077ad4:  95 32 20 0c  srl  %o0, 0xc, %o2
a0077ad8:  92 06 20 41  add  %i0, 0x41, %o1
a0077adc:  93 2a 60 18  sll  %o1, 0x18, %o1
a0077ae0:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a0077ae4:  90 12 23 18  or  %o0, 0x318, %o0	! 0xa0067318
a0077ae8:  93 3a 60 18  sra  %o1, 0x18, %o1
a0077aec:  7f ff ed 56  call  0xa0073044
a0077af0:  94 0a a0 0f  and  %o2, 0xf, %o2
a0077af4:  b0 0c 60 ff  and  %l1, 0xff, %i0
a0077af8:  13 00 00 04  sethi  %hi(0x1000), %o1
a0077afc:  92 12 61 48  or  %o1, 0x148, %o1	! 0x1148
a0077b00:  40 00 be 05  call  0xa00a7314
a0077b04:  90 10 00 18  mov  %i0, %o0
a0077b08:  91 32 20 10  srl  %o0, 0x10, %o0
a0077b0c:  90 0a 20 0f  and  %o0, 0xf, %o0
a0077b10:  80 a2 20 0f  cmp  %o0, 0xf
a0077b14:  12 80 00 15  bne  0xa0077b68
a0077b18:  25 00 00 04  sethi  %hi(0x1000), %l2
a0077b1c:  13 00 00 05  sethi  %hi(0x1400), %o1
a0077b20:  92 12 61 48  or  %o1, 0x148, %o1	! 0x1548
a0077b24:  40 00 bd fc  call  0xa00a7314
a0077b28:  90 10 00 18  mov  %i0, %o0
a0077b2c:  91 32 20 10  srl  %o0, 0x10, %o0
a0077b30:  90 0a 20 0f  and  %o0, 0xf, %o0
a0077b34:  80 a2 20 0f  cmp  %o0, 0xf
a0077b38:  12 80 00 0c  bne  0xa0077b68
a0077b3c:  25 00 00 04  sethi  %hi(0x1000), %l2
a0077b40:  13 00 00 06  sethi  %hi(0x1800), %o1
a0077b44:  92 12 61 48  or  %o1, 0x148, %o1	! 0x1948
a0077b48:  40 00 bd f3  call  0xa00a7314
a0077b4c:  90 10 00 18  mov  %i0, %o0
a0077b50:  91 32 20 10  srl  %o0, 0x10, %o0
a0077b54:  90 0a 20 0f  and  %o0, 0xf, %o0
a0077b58:  80 a2 20 0f  cmp  %o0, 0xf
a0077b5c:  22 80 00 02  be,a   0xa0077b64
a0077b60:  a0 10 20 01  mov  1, %l0
a0077b64:  25 00 00 04  sethi  %hi(0x1000), %l2
a0077b68:  90 10 00 18  mov  %i0, %o0
a0077b6c:  40 00 bd ea  call  0xa00a7314
a0077b70:  92 14 a0 18  or  %l2, 0x18, %o1
a0077b74:  90 0a 20 ff  and  %o0, 0xff, %o0
a0077b78:  80 a2 20 df  cmp  %o0, 0xdf
a0077b7c:  08 80 00 8e  bleu  0xa0077db4
a0077b80:  80 8c 20 ff  btst  0xff, %l0
a0077b84:  90 10 00 18  mov  %i0, %o0
a0077b88:  40 00 bd e3  call  0xa00a7314
a0077b8c:  92 14 a1 68  or  %l2, 0x168, %o1
a0077b90:  91 32 20 04  srl  %o0, 4, %o0
a0077b94:  a0 0a 20 0f  and  %o0, 0xf, %l0
a0077b98:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a0077b9c:  80 88 60 02  btst  2, %g1
a0077ba0:  02 80 00 0a  be  0xa0077bc8
a0077ba4:  a6 10 00 10  mov  %l0, %l3
a0077ba8:  92 04 60 41  add  %l1, 0x41, %o1
a0077bac:  93 2a 60 18  sll  %o1, 0x18, %o1
a0077bb0:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a0077bb4:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a0077bb8:  90 12 23 58  or  %o0, 0x358, %o0
a0077bbc:  93 3a 60 18  sra  %o1, 0x18, %o1
a0077bc0:  7f ff ed 21  call  0xa0073044
a0077bc4:  94 12 a1 38  or  %o2, 0x138, %o2
a0077bc8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0077bcc:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0077bd0:  80 88 60 02  btst  2, %g1
a0077bd4:  22 80 00 07  be,a   0xa0077bf0
a0077bd8:  96 14 a1 00  or  %l2, 0x100, %o3
a0077bdc:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a0077be0:  90 12 23 88  or  %o0, 0x388, %o0	! 0xa0067388
a0077be4:  7f ff ed 18  call  0xa0073044
a0077be8:  92 0c e0 0f  and  %l3, 0xf, %o1
a0077bec:  96 14 a1 00  or  %l2, 0x100, %o3
a0077bf0:  90 10 20 01  mov  1, %o0
a0077bf4:  92 10 20 15  mov  0x15, %o1
a0077bf8:  40 00 be 0b  call  0xa00a7424
a0077bfc:  94 10 00 18  mov  %i0, %o2
a0077c00:  17 00 00 05  sethi  %hi(0x1400), %o3
a0077c04:  96 12 e1 00  or  %o3, 0x100, %o3	! 0x1500
a0077c08:  90 10 20 01  mov  1, %o0
a0077c0c:  92 10 20 15  mov  0x15, %o1
a0077c10:  40 00 be 05  call  0xa00a7424
a0077c14:  94 10 00 18  mov  %i0, %o2
a0077c18:  17 00 00 06  sethi  %hi(0x1800), %o3
a0077c1c:  96 12 e1 00  or  %o3, 0x100, %o3	! 0x1900
a0077c20:  90 10 20 01  mov  1, %o0
a0077c24:  92 10 20 15  mov  0x15, %o1
a0077c28:  40 00 bd ff  call  0xa00a7424
a0077c2c:  94 10 00 18  mov  %i0, %o2
a0077c30:  aa 0c e0 ff  and  %l3, 0xff, %l5
a0077c34:  80 a5 60 0f  cmp  %l5, 0xf
a0077c38:  12 80 00 03  bne  0xa0077c44
a0077c3c:  96 04 20 01  add  %l0, 1, %o3
a0077c40:  96 10 00 10  mov  %l0, %o3
a0077c44:  21 00 00 04  sethi  %hi(0x1000), %l0
a0077c48:  96 0a e0 0f  and  %o3, 0xf, %o3
a0077c4c:  97 2a e0 08  sll  %o3, 8, %o3
a0077c50:  90 10 00 18  mov  %i0, %o0
a0077c54:  92 14 21 68  or  %l0, 0x168, %o1
a0077c58:  40 00 be 0c  call  0xa00a7488
a0077c5c:  94 10 30 ff  mov  -3841, %o2
a0077c60:  90 10 20 01  mov  1, %o0
a0077c64:  92 10 20 0d  mov  0xd, %o1
a0077c68:  94 10 00 18  mov  %i0, %o2
a0077c6c:  40 00 bd ee  call  0xa00a7424
a0077c70:  96 14 21 68  or  %l0, 0x168, %o3
a0077c74:  90 10 20 00  clr  %o0
a0077c78:  92 10 20 15  mov  0x15, %o1
a0077c7c:  94 10 00 18  mov  %i0, %o2
a0077c80:  40 00 bd e9  call  0xa00a7424
a0077c84:  96 14 21 00  or  %l0, 0x100, %o3
a0077c88:  25 00 00 05  sethi  %hi(0x1400), %l2
a0077c8c:  90 10 20 00  clr  %o0
a0077c90:  92 10 20 15  mov  0x15, %o1
a0077c94:  94 10 00 18  mov  %i0, %o2
a0077c98:  40 00 bd e3  call  0xa00a7424
a0077c9c:  96 14 a1 00  or  %l2, 0x100, %o3
a0077ca0:  27 00 00 06  sethi  %hi(0x1800), %l3
a0077ca4:  92 10 20 15  mov  0x15, %o1
a0077ca8:  94 10 00 18  mov  %i0, %o2
a0077cac:  96 14 e1 00  or  %l3, 0x100, %o3
a0077cb0:  40 00 bd dd  call  0xa00a7424
a0077cb4:  90 10 20 00  clr  %o0
a0077cb8:  40 00 e6 b7  call  0xa00b1794
a0077cbc:  90 10 20 05  mov  5, %o0
a0077cc0:  90 10 00 18  mov  %i0, %o0
a0077cc4:  40 00 bd 94  call  0xa00a7314
a0077cc8:  92 14 20 18  or  %l0, 0x18, %o1
a0077ccc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0077cd0:  80 a2 20 1f  cmp  %o0, 0x1f
a0077cd4:  38 80 00 37  bgu,a   0xa0077db0
a0077cd8:  a0 10 20 01  mov  1, %l0
a0077cdc:  c2 05 22 34  ld  [ %l4 + 0x234 ], %g1
a0077ce0:  80 88 60 02  btst  2, %g1
a0077ce4:  02 80 00 0b  be  0xa0077d10
a0077ce8:  90 10 20 01  mov  1, %o0
a0077cec:  92 04 60 41  add  %l1, 0x41, %o1
a0077cf0:  93 2a 60 18  sll  %o1, 0x18, %o1
a0077cf4:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a0077cf8:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a0077cfc:  90 12 23 98  or  %o0, 0x398, %o0
a0077d00:  93 3a 60 18  sra  %o1, 0x18, %o1
a0077d04:  7f ff ec d0  call  0xa0073044
a0077d08:  94 12 a1 38  or  %o2, 0x138, %o2
a0077d0c:  90 10 20 01  mov  1, %o0
a0077d10:  92 10 20 15  mov  0x15, %o1
a0077d14:  94 10 00 18  mov  %i0, %o2
a0077d18:  40 00 bd c3  call  0xa00a7424
a0077d1c:  96 14 21 00  or  %l0, 0x100, %o3
a0077d20:  90 10 20 01  mov  1, %o0
a0077d24:  92 10 20 15  mov  0x15, %o1
a0077d28:  94 10 00 18  mov  %i0, %o2
a0077d2c:  40 00 bd be  call  0xa00a7424
a0077d30:  96 14 a1 00  or  %l2, 0x100, %o3
a0077d34:  90 10 20 01  mov  1, %o0
a0077d38:  92 10 20 15  mov  0x15, %o1
a0077d3c:  94 10 00 18  mov  %i0, %o2
a0077d40:  40 00 bd b9  call  0xa00a7424
a0077d44:  96 14 e1 00  or  %l3, 0x100, %o3
a0077d48:  90 10 00 18  mov  %i0, %o0
a0077d4c:  97 2d 60 08  sll  %l5, 8, %o3
a0077d50:  92 14 21 68  or  %l0, 0x168, %o1
a0077d54:  40 00 bd cd  call  0xa00a7488
a0077d58:  94 10 30 ff  mov  -3841, %o2
a0077d5c:  90 10 20 00  clr  %o0
a0077d60:  92 10 20 0d  mov  0xd, %o1
a0077d64:  94 10 00 18  mov  %i0, %o2
a0077d68:  40 00 bd af  call  0xa00a7424
a0077d6c:  96 14 21 68  or  %l0, 0x168, %o3
a0077d70:  96 14 21 00  or  %l0, 0x100, %o3
a0077d74:  90 10 20 00  clr  %o0
a0077d78:  92 10 20 15  mov  0x15, %o1
a0077d7c:  40 00 bd aa  call  0xa00a7424
a0077d80:  94 10 00 18  mov  %i0, %o2
a0077d84:  96 14 a1 00  or  %l2, 0x100, %o3
a0077d88:  90 10 20 00  clr  %o0
a0077d8c:  92 10 20 15  mov  0x15, %o1
a0077d90:  40 00 bd a5  call  0xa00a7424
a0077d94:  94 10 00 18  mov  %i0, %o2
a0077d98:  94 10 00 18  mov  %i0, %o2
a0077d9c:  96 14 e1 00  or  %l3, 0x100, %o3
a0077da0:  90 10 20 00  clr  %o0
a0077da4:  40 00 bd a0  call  0xa00a7424
a0077da8:  92 10 20 15  mov  0x15, %o1
a0077dac:  a0 10 20 01  mov  1, %l0
a0077db0:  80 8c 20 ff  btst  0xff, %l0
a0077db4:  94 0c 60 ff  and  %l1, 0xff, %o2
a0077db8:  02 80 00 25  be  0xa0077e4c
a0077dbc:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a0077dc0:  82 02 80 0a  add  %o2, %o2, %g1
a0077dc4:  82 00 40 0a  add  %g1, %o2, %g1
a0077dc8:  b1 28 60 02  sll  %g1, 2, %i0
a0077dcc:  a0 13 60 c4  or  %o5, 0xc4, %l0
a0077dd0:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a0077dd4:  82 10 61 f0  or  %g1, 0x1f0, %g1	! 0xa807a9f0
a0077dd8:  9a 5a a8 98  smul  %o2, 0x898, %o5
a0077ddc:  98 06 00 10  add  %i0, %l0, %o4
a0077de0:  9a 03 40 01  add  %o5, %g1, %o5
a0077de4:  d6 0b 20 08  ldub  [ %o4 + 8 ], %o3
a0077de8:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0077dec:  82 10 61 a0  or  %g1, 0x1a0, %g1	! 0xa80761a0
a0077df0:  98 10 20 06  mov  6, %o4
a0077df4:  d8 28 40 0a  stb  %o4, [ %g1 + %o2 ]
a0077df8:  c0 2b 60 30  clrb  [ %o5 + 0x30 ]
a0077dfc:  80 a2 e0 01  cmp  %o3, 1
a0077e00:  12 80 00 11  bne  0xa0077e44
a0077e04:  82 10 20 06  mov  6, %g1
a0077e08:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0077e0c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0077e10:  80 88 60 02  btst  2, %g1
a0077e14:  02 80 00 0c  be  0xa0077e44
a0077e18:  82 10 20 0b  mov  0xb, %g1
a0077e1c:  40 00 e8 92  call  0xa00b2064
a0077e20:  01 00 00 00  nop
a0077e24:  94 10 00 08  mov  %o0, %o2
a0077e28:  92 04 60 41  add  %l1, 0x41, %o1
a0077e2c:  93 2a 60 18  sll  %o1, 0x18, %o1
a0077e30:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a0077e34:  90 12 23 d0  or  %o0, 0x3d0, %o0	! 0xa00673d0
a0077e38:  7f ff ec 83  call  0xa0073044
a0077e3c:  93 3a 60 18  sra  %o1, 0x18, %o1
a0077e40:  82 10 20 0b  mov  0xb, %g1
a0077e44:  10 80 00 07  b  0xa0077e60
a0077e48:  c2 24 00 18  st  %g1, [ %l0 + %i0 ]
a0077e4c:  82 02 80 0a  add  %o2, %o2, %g1
a0077e50:  82 00 40 0a  add  %g1, %o2, %g1
a0077e54:  9a 13 60 c4  or  %o5, 0xc4, %o5
a0077e58:  83 28 60 02  sll  %g1, 2, %g1
a0077e5c:  c0 23 40 01  clr  [ %o5 + %g1 ]
a0077e60:  81 c7 e0 08  ret
a0077e64:  91 e8 20 00  restore  %g0, 0, %o0
