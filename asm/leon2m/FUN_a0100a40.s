# leon2m FUN_a0100a40 0xa0100a40-0xa0100e6c (264 bytes)
a0100a40:  9d e3 bf 98  save  %sp, -104, %sp
a0100a44:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a0100a48:  d4 00 62 78  ld  [ %g1 + 0x278 ], %o2	! 0xa8027a78
a0100a4c:  80 a2 a0 02  cmp  %o2, 2
a0100a50:  22 80 00 32  be,a   0xa0100b18
a0100a54:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0100a58:  80 a2 a0 01  cmp  %o2, 1
a0100a5c:  18 80 00 22  bgu  0xa0100ae4
a0100a60:  11 2a 00 9e  sethi  %hi(0xa8027800), %o0
a0100a64:  c2 0a 22 75  ldub  [ %o0 + 0x275 ], %g1	! 0xa8027a75
a0100a68:  80 a0 60 2a  cmp  %g1, 0x2a
a0100a6c:  18 80 00 07  bgu  0xa0100a88
a0100a70:  15 00 02 81  sethi  %hi(0xa0400), %o2
a0100a74:  93 28 60 02  sll  %g1, 2, %o1
a0100a78:  9a 12 a2 2c  or  %o2, 0x22c, %o5
a0100a7c:  d8 03 40 09  ld  [ %o5 + %o1 ], %o4
a0100a80:  81 c3 00 00  jmp  %o4
a0100a84:  01 00 00 00  nop
a0100a88:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0100a8c:  90 10 00 18  mov  %i0, %o0
a0100a90:  92 10 20 19  mov  0x19, %o1
a0100a94:  7f ff c4 10  call  0xa00f1ad4
a0100a98:  94 10 20 00  clr  %o2
a0100a9c:  90 10 00 18  mov  %i0, %o0
a0100aa0:  92 10 20 1a  mov  0x1a, %o1
a0100aa4:  94 10 20 01  mov  1, %o2
a0100aa8:  7f ff c4 2d  call  0xa00f1b5c
a0100aac:  96 10 20 00  clr  %o3
a0100ab0:  90 10 00 18  mov  %i0, %o0
a0100ab4:  92 10 20 1a  mov  0x1a, %o1
a0100ab8:  94 10 20 20  mov  0x20, %o2
a0100abc:  96 10 20 00  clr  %o3
a0100ac0:  7f ff c4 27  call  0xa00f1b5c
a0100ac4:  01 00 00 00  nop
a0100ac8:  80 a6 20 04  cmp  %i0, 4
a0100acc:  12 80 00 e6  bne  0xa0100e64
a0100ad0:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a0100ad4:  d0 08 62 75  ldub  [ %g1 + 0x275 ], %o0	! 0xa8027a75
a0100ad8:  31 2a 00 9e  sethi  %hi(0xa8027800), %i0
a0100adc:  10 80 00 e2  b  0xa0100e64
a0100ae0:  d0 2e 22 7c  stb  %o0, [ %i0 + 0x27c ]	! 0xa8027a7c
a0100ae4:  9f 2a a0 03  sll  %o2, 3, %o7
a0100ae8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0100aec:  96 13 ff 80  or  %o7, -128, %o3
a0100af0:  94 0a e0 f8  and  %o3, 0xf8, %o2
a0100af4:  90 10 00 18  mov  %i0, %o0
a0100af8:  7f ff c3 f7  call  0xa00f1ad4
a0100afc:  92 10 20 19  mov  0x19, %o1
a0100b00:  90 10 00 18  mov  %i0, %o0
a0100b04:  92 10 20 1a  mov  0x1a, %o1
a0100b08:  7f ff c3 f3  call  0xa00f1ad4
a0100b0c:  94 10 20 19  mov  0x19, %o2
a0100b10:  10 bf ff ef  b  0xa0100acc
a0100b14:  80 a6 20 04  cmp  %i0, 4
a0100b18:  90 10 00 18  mov  %i0, %o0
a0100b1c:  92 10 20 19  mov  0x19, %o1
a0100b20:  7f ff c3 ed  call  0xa00f1ad4
a0100b24:  94 10 20 00  clr  %o2
a0100b28:  90 10 00 18  mov  %i0, %o0
a0100b2c:  92 10 20 1a  mov  0x1a, %o1
a0100b30:  7f ff c3 e9  call  0xa00f1ad4
a0100b34:  94 10 20 00  clr  %o2
a0100b38:  10 bf ff e5  b  0xa0100acc
a0100b3c:  80 a6 20 04  cmp  %i0, 4
a0100b40:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0100b44:  90 10 00 18  mov  %i0, %o0
a0100b48:  92 10 20 19  mov  0x19, %o1
a0100b4c:  7f ff c3 e2  call  0xa00f1ad4
a0100b50:  94 10 20 00  clr  %o2
a0100b54:  90 10 00 18  mov  %i0, %o0
a0100b58:  92 10 20 1a  mov  0x1a, %o1
a0100b5c:  7f ff c3 de  call  0xa00f1ad4
a0100b60:  94 10 20 fe  mov  0xfe, %o2
a0100b64:  10 bf ff d4  b  0xa0100ab4
a0100b68:  90 10 00 18  mov  %i0, %o0
a0100b6c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0100b70:  90 10 00 18  mov  %i0, %o0
a0100b74:  92 10 20 19  mov  0x19, %o1
a0100b78:  7f ff c3 d7  call  0xa00f1ad4
a0100b7c:  94 10 20 b0  mov  0xb0, %o2
a0100b80:  90 10 00 18  mov  %i0, %o0
a0100b84:  92 10 20 1a  mov  0x1a, %o1
a0100b88:  7f ff c3 d3  call  0xa00f1ad4
a0100b8c:  94 10 20 39  mov  0x39, %o2
a0100b90:  10 bf ff cf  b  0xa0100acc
a0100b94:  80 a6 20 04  cmp  %i0, 4
a0100b98:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0100b9c:  90 10 00 18  mov  %i0, %o0
a0100ba0:  92 10 20 19  mov  0x19, %o1
a0100ba4:  7f ff c3 cc  call  0xa00f1ad4
a0100ba8:  94 10 20 00  clr  %o2
a0100bac:  90 10 00 18  mov  %i0, %o0
a0100bb0:  92 10 20 1a  mov  0x1a, %o1
a0100bb4:  94 10 20 01  mov  1, %o2
a0100bb8:  7f ff c3 e9  call  0xa00f1b5c
a0100bbc:  96 10 20 00  clr  %o3
a0100bc0:  90 10 00 18  mov  %i0, %o0
a0100bc4:  92 10 20 1a  mov  0x1a, %o1
a0100bc8:  94 10 20 20  mov  0x20, %o2
a0100bcc:  10 bf ff bd  b  0xa0100ac0
a0100bd0:  96 10 20 01  mov  1, %o3
a0100bd4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0100bd8:  90 10 00 18  mov  %i0, %o0
a0100bdc:  92 10 20 19  mov  0x19, %o1
a0100be0:  94 10 20 b0  mov  0xb0, %o2
a0100be4:  7f ff c3 bc  call  0xa00f1ad4
a0100be8:  01 00 00 00  nop
a0100bec:  90 10 00 18  mov  %i0, %o0
a0100bf0:  92 10 20 1a  mov  0x1a, %o1
a0100bf4:  94 10 20 19  mov  0x19, %o2
a0100bf8:  7f ff c3 b7  call  0xa00f1ad4
a0100bfc:  01 00 00 00  nop
a0100c00:  10 bf ff ad  b  0xa0100ab4
a0100c04:  90 10 00 18  mov  %i0, %o0
a0100c08:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0100c0c:  90 10 00 18  mov  %i0, %o0
a0100c10:  92 10 20 19  mov  0x19, %o1
a0100c14:  10 bf ff f4  b  0xa0100be4
a0100c18:  94 10 20 88  mov  0x88, %o2
a0100c1c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0100c20:  90 10 00 18  mov  %i0, %o0
a0100c24:  92 10 20 19  mov  0x19, %o1
a0100c28:  10 bf ff ef  b  0xa0100be4
a0100c2c:  94 10 20 f8  mov  0xf8, %o2
a0100c30:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0100c34:  90 10 20 00  clr  %o0
a0100c38:  92 10 20 19  mov  0x19, %o1
a0100c3c:  80 a6 20 00  cmp  %i0, 0
a0100c40:  02 80 00 05  be  0xa0100c54
a0100c44:  94 10 20 88  mov  0x88, %o2
a0100c48:  90 10 00 18  mov  %i0, %o0
a0100c4c:  92 10 20 19  mov  0x19, %o1
a0100c50:  94 10 20 b0  mov  0xb0, %o2
a0100c54:  7f ff c3 a0  call  0xa00f1ad4
a0100c58:  01 00 00 00  nop
a0100c5c:  90 10 00 18  mov  %i0, %o0
a0100c60:  92 10 20 1a  mov  0x1a, %o1
a0100c64:  7f ff c3 9c  call  0xa00f1ad4
a0100c68:  94 10 20 19  mov  0x19, %o2
a0100c6c:  10 bf ff d6  b  0xa0100bc4
a0100c70:  90 10 00 18  mov  %i0, %o0
a0100c74:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0100c78:  80 a6 20 00  cmp  %i0, 0
a0100c7c:  32 bf ff c9  bne,a   0xa0100ba0
a0100c80:  90 10 00 18  mov  %i0, %o0
a0100c84:  90 10 20 00  clr  %o0
a0100c88:  92 10 20 19  mov  0x19, %o1
a0100c8c:  7f ff c3 92  call  0xa00f1ad4
a0100c90:  94 10 20 f8  mov  0xf8, %o2
a0100c94:  10 bf ff f3  b  0xa0100c60
a0100c98:  90 10 20 00  clr  %o0
a0100c9c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0100ca0:  80 a6 20 00  cmp  %i0, 0
a0100ca4:  12 bf ff cd  bne  0xa0100bd8
a0100ca8:  90 10 20 00  clr  %o0
a0100cac:  92 10 20 19  mov  0x19, %o1
a0100cb0:  10 bf ff cd  b  0xa0100be4
a0100cb4:  94 10 20 88  mov  0x88, %o2
a0100cb8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0100cbc:  80 a6 20 00  cmp  %i0, 0
a0100cc0:  32 bf ff 74  bne,a   0xa0100a90
a0100cc4:  90 10 00 18  mov  %i0, %o0
a0100cc8:  90 10 20 00  clr  %o0
a0100ccc:  92 10 20 19  mov  0x19, %o1
a0100cd0:  7f ff c3 81  call  0xa00f1ad4
a0100cd4:  94 10 20 f8  mov  0xf8, %o2
a0100cd8:  90 10 20 00  clr  %o0
a0100cdc:  92 10 20 1a  mov  0x1a, %o1
a0100ce0:  10 bf ff c6  b  0xa0100bf8
a0100ce4:  94 10 20 19  mov  0x19, %o2
a0100ce8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0100cec:  90 10 00 18  mov  %i0, %o0
a0100cf0:  92 10 20 19  mov  0x19, %o1
a0100cf4:  7f ff c3 78  call  0xa00f1ad4
a0100cf8:  94 10 20 00  clr  %o2
a0100cfc:  90 10 00 18  mov  %i0, %o0
a0100d00:  92 10 20 1a  mov  0x1a, %o1
a0100d04:  7f ff c3 74  call  0xa00f1ad4
a0100d08:  94 10 20 00  clr  %o2
a0100d0c:  21 00 06 69  sethi  %hi(0x19a400), %l0
a0100d10:  d4 14 21 bc  lduh  [ %l0 + 0x1bc ], %o2	! 0x19a5bc
a0100d14:  90 10 00 18  mov  %i0, %o0
a0100d18:  92 10 20 1b  mov  0x1b, %o1
a0100d1c:  7f ff c4 0b  call  0xa00f1d48
a0100d20:  a0 14 21 bc  or  %l0, 0x1bc, %l0
a0100d24:  90 10 00 18  mov  %i0, %o0
a0100d28:  d4 14 20 02  lduh  [ %l0 + 2 ], %o2
a0100d2c:  7f ff c4 07  call  0xa00f1d48
a0100d30:  92 10 20 1d  mov  0x1d, %o1
a0100d34:  90 10 00 18  mov  %i0, %o0
a0100d38:  d4 14 20 04  lduh  [ %l0 + 4 ], %o2
a0100d3c:  7f ff c4 03  call  0xa00f1d48
a0100d40:  92 10 20 1f  mov  0x1f, %o1
a0100d44:  90 10 00 18  mov  %i0, %o0
a0100d48:  d4 14 20 06  lduh  [ %l0 + 6 ], %o2
a0100d4c:  7f ff c3 ff  call  0xa00f1d48
a0100d50:  92 10 20 21  mov  0x21, %o1
a0100d54:  90 10 00 18  mov  %i0, %o0
a0100d58:  d4 14 20 08  lduh  [ %l0 + 8 ], %o2
a0100d5c:  7f ff c3 fb  call  0xa00f1d48
a0100d60:  92 10 20 23  mov  0x23, %o1
a0100d64:  90 10 00 18  mov  %i0, %o0
a0100d68:  92 10 20 1a  mov  0x1a, %o1
a0100d6c:  7f ff c3 5a  call  0xa00f1ad4
a0100d70:  94 10 20 08  mov  8, %o2
a0100d74:  90 10 00 18  mov  %i0, %o0
a0100d78:  92 10 20 1a  mov  0x1a, %o1
a0100d7c:  7f ff c3 56  call  0xa00f1ad4
a0100d80:  94 10 20 02  mov  2, %o2
a0100d84:  90 10 00 18  mov  %i0, %o0
a0100d88:  d4 14 20 0a  lduh  [ %l0 + 0xa ], %o2
a0100d8c:  7f ff c3 ef  call  0xa00f1d48
a0100d90:  92 10 20 1b  mov  0x1b, %o1
a0100d94:  90 10 00 18  mov  %i0, %o0
a0100d98:  d4 14 20 0c  lduh  [ %l0 + 0xc ], %o2
a0100d9c:  7f ff c3 eb  call  0xa00f1d48
a0100da0:  92 10 20 1d  mov  0x1d, %o1
a0100da4:  90 10 00 18  mov  %i0, %o0
a0100da8:  d4 14 20 0e  lduh  [ %l0 + 0xe ], %o2
a0100dac:  7f ff c3 e7  call  0xa00f1d48
a0100db0:  92 10 20 1f  mov  0x1f, %o1
a0100db4:  90 10 00 18  mov  %i0, %o0
a0100db8:  d4 14 20 10  lduh  [ %l0 + 0x10 ], %o2
a0100dbc:  7f ff c3 e3  call  0xa00f1d48
a0100dc0:  92 10 20 21  mov  0x21, %o1
a0100dc4:  90 10 00 18  mov  %i0, %o0
a0100dc8:  d4 14 20 12  lduh  [ %l0 + 0x12 ], %o2
a0100dcc:  7f ff c3 df  call  0xa00f1d48
a0100dd0:  92 10 20 23  mov  0x23, %o1
a0100dd4:  90 10 00 18  mov  %i0, %o0
a0100dd8:  92 10 20 1a  mov  0x1a, %o1
a0100ddc:  7f ff c3 3e  call  0xa00f1ad4
a0100de0:  94 10 20 0a  mov  0xa, %o2
a0100de4:  90 10 00 18  mov  %i0, %o0
a0100de8:  92 10 20 1a  mov  0x1a, %o1
a0100dec:  7f ff c3 3a  call  0xa00f1ad4
a0100df0:  94 10 20 04  mov  4, %o2
a0100df4:  90 10 00 18  mov  %i0, %o0
a0100df8:  d4 14 20 14  lduh  [ %l0 + 0x14 ], %o2
a0100dfc:  7f ff c3 d3  call  0xa00f1d48
a0100e00:  92 10 20 1b  mov  0x1b, %o1
a0100e04:  90 10 00 18  mov  %i0, %o0
a0100e08:  d4 14 20 16  lduh  [ %l0 + 0x16 ], %o2
a0100e0c:  7f ff c3 cf  call  0xa00f1d48
a0100e10:  92 10 20 1d  mov  0x1d, %o1
a0100e14:  90 10 00 18  mov  %i0, %o0
a0100e18:  d4 14 20 18  lduh  [ %l0 + 0x18 ], %o2
a0100e1c:  7f ff c3 cb  call  0xa00f1d48
a0100e20:  92 10 20 1f  mov  0x1f, %o1
a0100e24:  90 10 00 18  mov  %i0, %o0
a0100e28:  d4 14 20 1a  lduh  [ %l0 + 0x1a ], %o2
a0100e2c:  7f ff c3 c7  call  0xa00f1d48
a0100e30:  92 10 20 21  mov  0x21, %o1
a0100e34:  90 10 00 18  mov  %i0, %o0
a0100e38:  d4 14 20 1c  lduh  [ %l0 + 0x1c ], %o2
a0100e3c:  7f ff c3 c3  call  0xa00f1d48
a0100e40:  92 10 20 23  mov  0x23, %o1
a0100e44:  90 10 00 18  mov  %i0, %o0
a0100e48:  92 10 20 1a  mov  0x1a, %o1
a0100e4c:  7f ff c3 22  call  0xa00f1ad4
a0100e50:  94 10 20 0c  mov  0xc, %o2
a0100e54:  90 10 00 18  mov  %i0, %o0
a0100e58:  92 10 20 1a  mov  0x1a, %o1
a0100e5c:  10 bf ff 62  b  0xa0100be4
a0100e60:  94 10 20 09  mov  9, %o2
a0100e64:  81 c7 e0 08  ret
a0100e68:  81 e8 00 00  restore
