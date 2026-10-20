# leon2s DRV_HDMI21_RX_SCDC_Chk_Err 0xa0098bb0-0xa0098e88 (728 bytes)
a0098bb0:  9d e3 bf 88  save  %sp, -120, %sp
a0098bb4:  98 10 20 00  clr  %o4
a0098bb8:  9a 10 20 00  clr  %o5
a0098bbc:  a4 0e 20 ff  and  %i0, 0xff, %l2
a0098bc0:  aa 10 00 18  mov  %i0, %l5
a0098bc4:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a0098bc8:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0098bcc:  80 a4 a0 00  cmp  %l2, 0
a0098bd0:  b0 10 20 00  clr  %i0
a0098bd4:  02 80 00 07  be  0xa0098bf0
a0098bd8:  a6 10 20 02  mov  2, %l3
a0098bdc:  80 a4 a0 01  cmp  %l2, 1
a0098be0:  02 80 00 04  be  0xa0098bf0
a0098be4:  a6 10 20 03  mov  3, %l3
a0098be8:  10 80 00 a6  b  0xa0098e80
a0098bec:  b0 10 20 00  clr  %i0
a0098bf0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0098bf4:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0098bf8:  80 88 68 00  btst  0x800, %g1
a0098bfc:  02 80 00 08  be  0xa0098c1c
a0098c00:  a0 0c e0 ff  and  %l3, 0xff, %l0
a0098c04:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a0098c08:  13 28 02 d0  sethi  %hi(0xa00b4000), %o1
a0098c0c:  90 12 20 68  or  %o0, 0x68, %o0
a0098c10:  7f ff 69 0d  call  0xa0073044
a0098c14:  92 12 63 18  or  %o1, 0x318, %o1
a0098c18:  a0 0c e0 ff  and  %l3, 0xff, %l0
a0098c1c:  23 00 00 0b  sethi  %hi(0x2c00), %l1
a0098c20:  90 10 20 01  mov  1, %o0
a0098c24:  92 10 20 14  mov  0x14, %o1
a0098c28:  94 10 00 10  mov  %l0, %o2
a0098c2c:  40 00 39 fe  call  0xa00a7424
a0098c30:  96 14 62 60  or  %l1, 0x260, %o3
a0098c34:  92 10 20 10  mov  0x10, %o1
a0098c38:  94 10 00 10  mov  %l0, %o2
a0098c3c:  96 14 62 60  or  %l1, 0x260, %o3
a0098c40:  40 00 39 f9  call  0xa00a7424
a0098c44:  90 10 20 01  mov  1, %o0
a0098c48:  40 00 62 71  call  0xa00b160c
a0098c4c:  90 10 20 01  mov  1, %o0
a0098c50:  94 10 00 10  mov  %l0, %o2
a0098c54:  96 14 62 60  or  %l1, 0x260, %o3
a0098c58:  90 10 20 00  clr  %o0
a0098c5c:  40 00 39 f2  call  0xa00a7424
a0098c60:  92 10 20 10  mov  0x10, %o1
a0098c64:  40 00 62 cc  call  0xa00b1794
a0098c68:  90 10 20 01  mov  1, %o0
a0098c6c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0098c70:  9a 5c a0 b0  smul  %l2, 0xb0, %o5
a0098c74:  82 10 62 80  or  %g1, 0x280, %g1
a0098c78:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a0098c7c:  80 a0 60 00  cmp  %g1, 0
a0098c80:  02 80 00 76  be  0xa0098e58
a0098c84:  a4 10 20 00  clr  %l2
a0098c88:  a2 0c a0 ff  and  %l2, 0xff, %l1
a0098c8c:  80 a4 60 00  cmp  %l1, 0
a0098c90:  12 80 00 0b  bne  0xa0098cbc
a0098c94:  80 a4 60 01  cmp  %l1, 1
a0098c98:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0098c9c:  92 12 62 64  or  %o1, 0x264, %o1	! 0x2e64
a0098ca0:  40 00 39 9d  call  0xa00a7314
a0098ca4:  90 0c e0 ff  and  %l3, 0xff, %o0
a0098ca8:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a0098cac:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a0098cb0:  90 0a 00 01  and  %o0, %g1, %o0
a0098cb4:  10 80 00 1d  b  0xa0098d28
a0098cb8:  d0 27 bf e8  st  %o0, [ %fp + -24 ]
a0098cbc:  12 80 00 09  bne  0xa0098ce0
a0098cc0:  80 a4 60 02  cmp  %l1, 2
a0098cc4:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0098cc8:  92 12 62 64  or  %o1, 0x264, %o1	! 0x2e64
a0098ccc:  40 00 39 92  call  0xa00a7314
a0098cd0:  90 0c e0 ff  and  %l3, 0xff, %o0
a0098cd4:  91 32 20 10  srl  %o0, 0x10, %o0
a0098cd8:  10 80 00 14  b  0xa0098d28
a0098cdc:  d0 27 bf ec  st  %o0, [ %fp + -20 ]
a0098ce0:  12 80 00 0a  bne  0xa0098d08
a0098ce4:  90 0c e0 ff  and  %l3, 0xff, %o0
a0098ce8:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0098cec:  40 00 39 8a  call  0xa00a7314
a0098cf0:  92 12 62 68  or  %o1, 0x268, %o1	! 0x2e68
a0098cf4:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a0098cf8:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a0098cfc:  90 0a 00 01  and  %o0, %g1, %o0
a0098d00:  10 80 00 0a  b  0xa0098d28
a0098d04:  d0 27 bf f0  st  %o0, [ %fp + -16 ]
a0098d08:  82 07 bf f8  add  %fp, -8, %g1
a0098d0c:  a1 2c 60 02  sll  %l1, 2, %l0
a0098d10:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0098d14:  a0 04 00 01  add  %l0, %g1, %l0
a0098d18:  40 00 39 7f  call  0xa00a7314
a0098d1c:  92 12 62 68  or  %o1, 0x268, %o1
a0098d20:  91 32 20 10  srl  %o0, 0x10, %o0
a0098d24:  d0 24 3f f0  st  %o0, [ %l0 + -16 ]
a0098d28:  a0 0d 60 ff  and  %l5, 0xff, %l0
a0098d2c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0098d30:  82 10 60 50  or  %g1, 0x50, %g1	! 0xa807cc50
a0098d34:  9a 5c 20 2c  smul  %l0, 0x2c, %o5
a0098d38:  d8 08 40 11  ldub  [ %g1 + %l1 ], %o4
a0098d3c:  9a 03 40 11  add  %o5, %l1, %o5
a0098d40:  9a 03 40 0d  add  %o5, %o5, %o5
a0098d44:  83 2c 60 02  sll  %l1, 2, %g1
a0098d48:  9a 03 40 0c  add  %o5, %o4, %o5
a0098d4c:  82 07 80 01  add  %fp, %g1, %g1
a0098d50:  d8 00 7f e8  ld  [ %g1 + -24 ], %o4
a0098d54:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a0098d58:  82 15 22 80  or  %l4, 0x280, %g1	! 0xa807d680
a0098d5c:  9a 03 40 0d  add  %o5, %o5, %o5
a0098d60:  9a 03 40 01  add  %o5, %g1, %o5
a0098d64:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a0098d68:  96 2b 00 01  andn  %o4, %g1, %o3
a0098d6c:  03 00 00 20  sethi  %hi(0x8000), %g1
a0098d70:  80 a3 00 01  cmp  %o4, %g1
a0098d74:  12 80 00 0f  bne  0xa0098db0
a0098d78:  d6 33 60 1a  sth  %o3, [ %o5 + 0x1a ]
a0098d7c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0098d80:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0098d84:  80 88 68 00  btst  0x800, %g1
a0098d88:  02 80 00 1b  be  0xa0098df4
a0098d8c:  82 10 20 01  mov  1, %g1
a0098d90:  92 04 e0 41  add  %l3, 0x41, %o1
a0098d94:  93 2a 60 18  sll  %o1, 0x18, %o1
a0098d98:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a0098d9c:  90 12 20 e8  or  %o0, 0xe8, %o0	! 0xa0069ce8
a0098da0:  93 3a 60 18  sra  %o1, 0x18, %o1
a0098da4:  94 10 00 11  mov  %l1, %o2
a0098da8:  10 80 00 10  b  0xa0098de8
a0098dac:  96 10 20 00  clr  %o3
a0098db0:  82 10 60 1e  or  %g1, 0x1e, %g1
a0098db4:  80 a3 00 01  cmp  %o4, %g1
a0098db8:  18 80 00 12  bgu  0xa0098e00
a0098dbc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0098dc0:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0098dc4:  80 88 68 00  btst  0x800, %g1
a0098dc8:  02 80 00 0b  be  0xa0098df4
a0098dcc:  82 10 20 01  mov  1, %g1
a0098dd0:  92 04 e0 41  add  %l3, 0x41, %o1
a0098dd4:  93 2a 60 18  sll  %o1, 0x18, %o1
a0098dd8:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a0098ddc:  90 12 21 20  or  %o0, 0x120, %o0	! 0xa0069d20
a0098de0:  93 3a 60 18  sra  %o1, 0x18, %o1
a0098de4:  94 10 00 11  mov  %l1, %o2
a0098de8:  7f ff 68 97  call  0xa0073044
a0098dec:  01 00 00 00  nop
a0098df0:  82 10 20 01  mov  1, %g1	! 0x1
a0098df4:  83 28 40 11  sll  %g1, %l1, %g1
a0098df8:  10 80 00 10  b  0xa0098e38
a0098dfc:  b0 2e 00 01  andn  %i0, %g1, %i0
a0098e00:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1
a0098e04:  80 88 68 00  btst  0x800, %g1
a0098e08:  02 80 00 0a  be  0xa0098e30
a0098e0c:  82 10 20 01  mov  1, %g1
a0098e10:  92 04 e0 41  add  %l3, 0x41, %o1
a0098e14:  93 2a 60 18  sll  %o1, 0x18, %o1
a0098e18:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a0098e1c:  90 12 21 60  or  %o0, 0x160, %o0	! 0xa0069d60
a0098e20:  93 3a 60 18  sra  %o1, 0x18, %o1
a0098e24:  7f ff 68 88  call  0xa0073044
a0098e28:  94 10 00 11  mov  %l1, %o2
a0098e2c:  82 10 20 01  mov  1, %g1
a0098e30:  83 28 40 11  sll  %g1, %l1, %g1
a0098e34:  b0 10 40 18  or  %g1, %i0, %i0
a0098e38:  82 5c 20 b0  smul  %l0, 0xb0, %g1
a0098e3c:  9a 15 22 80  or  %l4, 0x280, %o5
a0098e40:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a0098e44:  a4 04 a0 01  inc  %l2
a0098e48:  82 0c a0 ff  and  %l2, 0xff, %g1
a0098e4c:  80 a0 40 0d  cmp  %g1, %o5
a0098e50:  0a bf ff 8f  bcs  0xa0098c8c
a0098e54:  a2 0c a0 ff  and  %l2, 0xff, %l1
a0098e58:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0098e5c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0098e60:  80 88 68 00  btst  0x800, %g1
a0098e64:  22 80 00 07  be,a   0xa0098e80
a0098e68:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0098e6c:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a0098e70:  90 12 21 a0  or  %o0, 0x1a0, %o0	! 0xa0069da0
a0098e74:  7f ff 68 74  call  0xa0073044
a0098e78:  92 0e 20 ff  and  %i0, 0xff, %o1
a0098e7c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0098e80:  81 c7 e0 08  ret
a0098e84:  81 e8 00 00  restore
