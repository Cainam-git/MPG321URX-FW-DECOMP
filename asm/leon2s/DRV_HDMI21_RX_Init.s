# leon2s DRV_HDMI21_RX_Init 0xa00a1cdc-0xa00a1df0 (276 bytes)
a00a1cdc:  9d e3 bf 98  save  %sp, -104, %sp
a00a1ce0:  25 2a 01 e4  sethi  %hi(0xa8079000), %l2
a00a1ce4:  c2 0c a1 92  ldub  [ %l2 + 0x192 ], %g1	! 0xa8079192
a00a1ce8:  80 a0 60 00  cmp  %g1, 0
a00a1cec:  12 80 00 3f  bne  0xa00a1de8
a00a1cf0:  a2 10 20 00  clr  %l1
a00a1cf4:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a1cf8:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a00a1cfc:  80 88 60 01  btst  1, %g1
a00a1d00:  02 80 00 05  be  0xa00a1d14
a00a1d04:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a1d08:  90 12 20 60  or  %o0, 0x60, %o0	! 0xa006b860
a00a1d0c:  7f ff 44 ce  call  0xa0073044
a00a1d10:  92 10 23 e7  mov  0x3e7, %o1
a00a1d14:  7f ff fe 91  call  0xa00a1758
a00a1d18:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a1d1c:  7f ff ff 7b  call  0xa00a1b08
a00a1d20:  90 10 00 10  mov  %l0, %o0
a00a1d24:  7f ff ff 8d  call  0xa00a1b58
a00a1d28:  90 10 00 10  mov  %l0, %o0
a00a1d2c:  a2 04 60 01  inc  %l1
a00a1d30:  82 0c 60 ff  and  %l1, 0xff, %g1
a00a1d34:  80 a0 60 01  cmp  %g1, 1
a00a1d38:  08 bf ff f9  bleu  0xa00a1d1c
a00a1d3c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a1d40:  a0 10 20 00  clr  %l0
a00a1d44:  90 0c 20 ff  and  %l0, 0xff, %o0
a00a1d48:  7f ff ff cb  call  0xa00a1c74
a00a1d4c:  92 10 20 01  mov  1, %o1
a00a1d50:  a0 04 20 01  inc  %l0
a00a1d54:  82 0c 20 ff  and  %l0, 0xff, %g1
a00a1d58:  80 a0 60 01  cmp  %g1, 1
a00a1d5c:  28 bf ff fb  bleu,a   0xa00a1d48
a00a1d60:  90 0c 20 ff  and  %l0, 0xff, %o0
a00a1d64:  a2 10 20 00  clr  %l1
a00a1d68:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a1d6c:  7f ff b5 d9  call  0xa008f4d0
a00a1d70:  90 10 00 10  mov  %l0, %o0
a00a1d74:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a00a1d78:  94 10 3f ff  mov  -1, %o2
a00a1d7c:  96 10 2f 00  mov  0xf00, %o3
a00a1d80:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a1d84:  40 00 15 c1  call  0xa00a7488
a00a1d88:  92 12 62 70  or  %o1, 0x270, %o1
a00a1d8c:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a1d90:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00a1d94:  a0 5c 20 34  smul  %l0, 0x34, %l0
a00a1d98:  a0 04 00 01  add  %l0, %g1, %l0
a00a1d9c:  d2 04 20 18  ld  [ %l0 + 0x18 ], %o1
a00a1da0:  92 02 60 08  add  %o1, 8, %o1
a00a1da4:  40 00 15 82  call  0xa00a73ac
a00a1da8:  90 10 20 0b  mov  0xb, %o0
a00a1dac:  d2 04 20 18  ld  [ %l0 + 0x18 ], %o1
a00a1db0:  92 02 60 08  add  %o1, 8, %o1
a00a1db4:  40 00 15 7e  call  0xa00a73ac
a00a1db8:  90 10 20 09  mov  9, %o0
a00a1dbc:  d2 04 20 18  ld  [ %l0 + 0x18 ], %o1
a00a1dc0:  92 02 60 08  add  %o1, 8, %o1
a00a1dc4:  40 00 15 7a  call  0xa00a73ac
a00a1dc8:  90 10 20 0a  mov  0xa, %o0
a00a1dcc:  a2 04 60 01  inc  %l1
a00a1dd0:  82 0c 60 ff  and  %l1, 0xff, %g1
a00a1dd4:  80 a0 60 01  cmp  %g1, 1
a00a1dd8:  08 bf ff e5  bleu  0xa00a1d6c
a00a1ddc:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a1de0:  82 10 20 01  mov  1, %g1
a00a1de4:  c2 2c a1 92  stb  %g1, [ %l2 + 0x192 ]
a00a1de8:  81 c7 e0 08  ret
a00a1dec:  81 e8 00 00  restore
