# leon2m FUN_a0157a60 0xa0157a60-0xa01595c8 (4304 bytes)
a0157a60:  9d e3 b8 58  save  %sp, -1960, %sp
a0157a64:  40 00 11 e0  call  0xa015c1e4
a0157a68:  01 00 00 00  nop
a0157a6c:  c2 16 60 0c  lduh  [ %i1 + 0xc ], %g1
a0157a70:  d0 02 00 00  ld  [ %o0 ], %o0
a0157a74:  80 88 62 00  btst  0x200, %g1
a0157a78:  f0 27 a0 44  st  %i0, [ %fp + 0x44 ]
a0157a7c:  d0 27 b8 e8  st  %o0, [ %fp + -1816 ]
a0157a80:  c0 27 b8 e0  clr  [ %fp + -1824 ]
a0157a84:  c0 27 b8 e4  clr  [ %fp + -1820 ]
a0157a88:  c0 27 b8 dc  clr  [ %fp + -1828 ]
a0157a8c:  c0 27 b8 d8  clr  [ %fp + -1832 ]
a0157a90:  02 80 00 a8  be  0xa0157d30
a0157a94:  c0 27 b8 d4  clr  [ %fp + -1836 ]
a0157a98:  03 2a 00 aa  sethi  %hi(0xa802a800), %g1
a0157a9c:  d0 00 62 18  ld  [ %g1 + 0x218 ], %o0	! 0xa802aa18
a0157aa0:  80 a2 20 00  cmp  %o0, 0
a0157aa4:  22 80 00 07  be,a   0xa0157ac0
a0157aa8:  c2 16 60 0c  lduh  [ %i1 + 0xc ], %g1
a0157aac:  c2 02 20 38  ld  [ %o0 + 0x38 ], %g1
a0157ab0:  80 a0 60 00  cmp  %g1, 0
a0157ab4:  02 80 02 de  be  0xa015862c
a0157ab8:  01 00 00 00  nop
a0157abc:  c2 16 60 0c  lduh  [ %i1 + 0xc ], %g1
a0157ac0:  80 88 60 08  btst  8, %g1
a0157ac4:  02 80 00 4d  be  0xa0157bf8
a0157ac8:  98 10 00 01  mov  %g1, %o4
a0157acc:  c2 06 60 10  ld  [ %i1 + 0x10 ], %g1
a0157ad0:  80 a0 60 00  cmp  %g1, 0
a0157ad4:  02 80 00 49  be  0xa0157bf8
a0157ad8:  83 2b 20 10  sll  %o4, 0x10, %g1
a0157adc:  97 30 60 10  srl  %g1, 0x10, %o3
a0157ae0:  9a 0a e0 1a  and  %o3, 0x1a, %o5
a0157ae4:  80 a3 60 0a  cmp  %o5, 0xa
a0157ae8:  22 80 00 51  be,a   0xa0157c2c
a0157aec:  c2 56 60 0e  ldsh  [ %i1 + 0xe ], %g1
a0157af0:  b8 07 bf a0  add  %fp, -96, %i4
a0157af4:  f8 27 bf e0  st  %i4, [ %fp + -32 ]
a0157af8:  c0 27 bf e8  clr  [ %fp + -24 ]
a0157afc:  c0 27 bf e4  clr  [ %fp + -28 ]
a0157b00:  a4 10 00 1c  mov  %i4, %l2
a0157b04:  c0 27 b8 f0  clr  [ %fp + -1808 ]
a0157b08:  c2 4e 80 00  ldsb  [ %i2 ], %g1
a0157b0c:  80 a0 00 01  cmp  %g0, %g1
a0157b10:  98 40 20 00  addx  %g0, 0, %o4
a0157b14:  82 18 60 25  xor  %g1, 0x25, %g1
a0157b18:  80 a0 00 01  cmp  %g0, %g1
a0157b1c:  9a 40 20 00  addx  %g0, 0, %o5
a0157b20:  a6 10 00 1a  mov  %i2, %l3
a0157b24:  80 8b 00 0d  btst  %o4, %o5
a0157b28:  02 80 00 0c  be  0xa0157b58
a0157b2c:  c2 0e 80 00  ldub  [ %i2 ], %g1
a0157b30:  b4 06 a0 01  inc  %i2
a0157b34:  c2 4e 80 00  ldsb  [ %i2 ], %g1
a0157b38:  80 a0 00 01  cmp  %g0, %g1
a0157b3c:  98 40 20 00  addx  %g0, 0, %o4
a0157b40:  82 18 60 25  xor  %g1, 0x25, %g1
a0157b44:  80 a0 00 01  cmp  %g0, %g1
a0157b48:  9a 40 20 00  addx  %g0, 0, %o5
a0157b4c:  80 8b 00 0d  btst  %o4, %o5
a0157b50:  12 bf ff f8  bne  0xa0157b30
a0157b54:  c2 0e 80 00  ldub  [ %i2 ], %g1
a0157b58:  a2 a6 80 13  subcc  %i2, %l3, %l1
a0157b5c:  02 80 00 12  be  0xa0157ba4
a0157b60:  83 28 60 18  sll  %g1, 0x18, %g1
a0157b64:  e2 24 a0 04  st  %l1, [ %l2 + 4 ]
a0157b68:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a0157b6c:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0157b70:  9a 03 60 01  inc  %o5
a0157b74:  e6 24 80 00  st  %l3, [ %l2 ]
a0157b78:  82 00 40 11  add  %g1, %l1, %g1
a0157b7c:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0157b80:  80 a3 60 07  cmp  %o5, 7
a0157b84:  a4 04 a0 08  add  %l2, 8, %l2
a0157b88:  14 80 00 62  bg  0xa0157d10
a0157b8c:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a0157b90:  c2 07 b8 f0  ld  [ %fp + -1808 ], %g1
a0157b94:  82 00 40 11  add  %g1, %l1, %g1
a0157b98:  c2 27 b8 f0  st  %g1, [ %fp + -1808 ]
a0157b9c:  c2 0e 80 00  ldub  [ %i2 ], %g1
a0157ba0:  83 28 60 18  sll  %g1, 0x18, %g1
a0157ba4:  80 a0 60 00  cmp  %g1, 0
a0157ba8:  02 80 06 43  be  0xa01594b4
a0157bac:  b4 06 a0 01  inc  %i2
a0157bb0:  c0 2f b8 f7  clrb  [ %fp + -1801 ]
a0157bb4:  ba 10 20 00  clr  %i5
a0157bb8:  b0 10 20 00  clr  %i0
a0157bbc:  c0 27 b8 ec  clr  [ %fp + -1812 ]
a0157bc0:  ac 10 3f ff  mov  -1, %l6
a0157bc4:  c2 0e 80 00  ldub  [ %i2 ], %g1
a0157bc8:  83 28 60 18  sll  %g1, 0x18, %g1
a0157bcc:  ab 38 60 18  sra  %g1, 0x18, %l5
a0157bd0:  b4 06 a0 01  inc  %i2
a0157bd4:  82 05 7f e0  add  %l5, -32, %g1
a0157bd8:  80 a0 60 58  cmp  %g1, 0x58
a0157bdc:  18 80 01 a5  bgu  0xa0158270
a0157be0:  1b 00 03 de  sethi  %hi(0xf7800), %o5
a0157be4:  83 28 60 02  sll  %g1, 2, %g1
a0157be8:  9a 13 60 bc  or  %o5, 0xbc, %o5
a0157bec:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a0157bf0:  81 c3 00 00  jmp  %o4
a0157bf4:  01 00 00 00  nop
a0157bf8:  40 00 08 3e  call  0xa0159cf0
a0157bfc:  90 10 00 19  mov  %i1, %o0
a0157c00:  80 a2 20 00  cmp  %o0, 0
a0157c04:  32 80 05 f5  bne,a   0xa01593d8
a0157c08:  c2 16 60 0c  lduh  [ %i1 + 0xc ], %g1
a0157c0c:  d8 16 60 0c  lduh  [ %i1 + 0xc ], %o4
a0157c10:  83 2b 20 10  sll  %o4, 0x10, %g1
a0157c14:  97 30 60 10  srl  %g1, 0x10, %o3
a0157c18:  9a 0a e0 1a  and  %o3, 0x1a, %o5
a0157c1c:  80 a3 60 0a  cmp  %o5, 0xa
a0157c20:  12 bf ff b5  bne  0xa0157af4
a0157c24:  b8 07 bf a0  add  %fp, -96, %i4
a0157c28:  c2 56 60 0e  ldsh  [ %i1 + 0xe ], %g1
a0157c2c:  80 a0 60 00  cmp  %g1, 0
a0157c30:  06 bf ff b0  bl  0xa0157af0
a0157c34:  d2 16 60 0e  lduh  [ %i1 + 0xe ], %o1
a0157c38:  80 8a e2 00  btst  0x200, %o3
a0157c3c:  02 80 02 80  be  0xa015863c
a0157c40:  01 00 00 00  nop
a0157c44:  82 07 b9 68  add  %fp, -1688, %g1
a0157c48:  9a 10 24 00  mov  0x400, %o5
a0157c4c:  98 0b 3f fd  and  %o4, -3, %o4
a0157c50:  d6 06 60 1c  ld  [ %i1 + 0x1c ], %o3
a0157c54:  d4 06 60 24  ld  [ %i1 + 0x24 ], %o2
a0157c58:  a0 07 b9 58  add  %fp, -1704, %l0
a0157c5c:  d8 37 bd 74  sth  %o4, [ %fp + -652 ]
a0157c60:  d6 27 bd 84  st  %o3, [ %fp + -636 ]
a0157c64:  d4 27 bd 8c  st  %o2, [ %fp + -628 ]
a0157c68:  c2 27 bd 78  st  %g1, [ %fp + -648 ]
a0157c6c:  da 27 bd 7c  st  %o5, [ %fp + -644 ]
a0157c70:  c2 27 bd 68  st  %g1, [ %fp + -664 ]
a0157c74:  da 27 bd 70  st  %o5, [ %fp + -656 ]
a0157c78:  d2 37 bd 76  sth  %o1, [ %fp + -650 ]
a0157c7c:  90 10 00 10  mov  %l0, %o0
a0157c80:  40 00 1b 86  call  0xa015ea98
a0157c84:  c0 27 bd 80  clr  [ %fp + -640 ]
a0157c88:  90 10 00 10  mov  %l0, %o0
a0157c8c:  40 00 1b 9b  call  0xa015eaf8
a0157c90:  92 10 20 01  mov  1, %o1
a0157c94:  a2 07 bd c0  add  %fp, -576, %l1
a0157c98:  92 10 00 10  mov  %l0, %o1
a0157c9c:  40 00 1b 42  call  0xa015e9a4
a0157ca0:  90 10 00 11  mov  %l1, %o0
a0157ca4:  40 00 1b 89  call  0xa015eac8
a0157ca8:  90 10 00 10  mov  %l0, %o0
a0157cac:  a0 07 bd 68  add  %fp, -664, %l0
a0157cb0:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a0157cb4:  92 10 00 10  mov  %l0, %o1
a0157cb8:  94 10 00 1a  mov  %i2, %o2
a0157cbc:  7f ff ff 69  call  0xa0157a60
a0157cc0:  96 10 00 1b  mov  %i3, %o3
a0157cc4:  b0 92 20 00  orcc  %o0, 0, %i0
a0157cc8:  06 80 00 08  bl  0xa0157ce8
a0157ccc:  c2 17 bd 74  lduh  [ %fp + -652 ], %g1
a0157cd0:  40 00 0d 8c  call  0xa015b300
a0157cd4:  90 10 00 10  mov  %l0, %o0
a0157cd8:  80 a2 20 00  cmp  %o0, 0
a0157cdc:  32 80 00 02  bne,a   0xa0157ce4
a0157ce0:  b0 10 3f ff  mov  -1, %i0
a0157ce4:  c2 17 bd 74  lduh  [ %fp + -652 ], %g1
a0157ce8:  80 88 60 40  btst  0x40, %g1
a0157cec:  02 80 00 05  be  0xa0157d00
a0157cf0:  01 00 00 00  nop
a0157cf4:  c2 16 60 0c  lduh  [ %i1 + 0xc ], %g1
a0157cf8:  82 10 60 40  or  %g1, 0x40, %g1
a0157cfc:  c2 36 60 0c  sth  %g1, [ %i1 + 0xc ]
a0157d00:  40 00 1b 36  call  0xa015e9d8
a0157d04:  90 10 00 11  mov  %l1, %o0
a0157d08:  10 80 06 2e  b  0xa01595c0
a0157d0c:  90 10 00 18  mov  %i0, %o0
a0157d10:  90 10 00 19  mov  %i1, %o0
a0157d14:  7f ff ff 43  call  0xa0157a20
a0157d18:  92 07 bf e0  add  %fp, -32, %o1
a0157d1c:  80 a2 20 00  cmp  %o0, 0
a0157d20:  12 80 03 1d  bne  0xa0158994
a0157d24:  a4 10 00 1c  mov  %i4, %l2
a0157d28:  10 bf ff 9b  b  0xa0157b94
a0157d2c:  c2 07 b8 f0  ld  [ %fp + -1808 ], %g1
a0157d30:  40 00 1b 36  call  0xa015ea08
a0157d34:  90 06 60 58  add  %i1, 0x58, %o0
a0157d38:  10 bf ff 59  b  0xa0157a9c
a0157d3c:  03 2a 00 aa  sethi  %hi(0xa802a800), %g1
a0157d40:  ba 17 60 10  or  %i5, 0x10, %i5
a0157d44:  80 8f 60 10  btst  0x10, %i5
a0157d48:  12 80 03 5e  bne  0xa0158ac0
a0157d4c:  82 10 00 1b  mov  %i3, %g1
a0157d50:  80 8f 60 40  btst  0x40, %i5
a0157d54:  22 80 03 5c  be,a   0xa0158ac4
a0157d58:  b6 06 e0 04  add  %i3, 4, %i3
a0157d5c:  82 10 00 1b  mov  %i3, %g1
a0157d60:  b6 06 e0 04  add  %i3, 4, %i3
a0157d64:  e0 10 60 02  lduh  [ %g1 + 2 ], %l0
a0157d68:  98 10 20 01  mov  1, %o4
a0157d6c:  10 80 00 1d  b  0xa0157de0
a0157d70:  c0 2f b8 f7  clrb  [ %fp + -1801 ]
a0157d74:  ba 17 60 10  or  %i5, 0x10, %i5
a0157d78:  80 8f 60 10  btst  0x10, %i5
a0157d7c:  12 80 03 4a  bne  0xa0158aa4
a0157d80:  82 10 00 1b  mov  %i3, %g1
a0157d84:  80 8f 60 40  btst  0x40, %i5
a0157d88:  22 80 03 48  be,a   0xa0158aa8
a0157d8c:  b6 06 e0 04  add  %i3, 4, %i3
a0157d90:  82 10 00 1b  mov  %i3, %g1
a0157d94:  b6 06 e0 04  add  %i3, 4, %i3
a0157d98:  e0 10 60 02  lduh  [ %g1 + 2 ], %l0
a0157d9c:  98 10 20 00  clr  %o4
a0157da0:  10 80 00 10  b  0xa0157de0
a0157da4:  c0 2f b8 f7  clrb  [ %fp + -1801 ]
a0157da8:  ba 17 60 10  or  %i5, 0x10, %i5
a0157dac:  80 8f 60 10  btst  0x10, %i5
a0157db0:  12 80 03 41  bne  0xa0158ab4
a0157db4:  82 10 00 1b  mov  %i3, %g1
a0157db8:  80 8f 60 40  btst  0x40, %i5
a0157dbc:  22 80 03 3f  be,a   0xa0158ab8
a0157dc0:  b6 06 e0 04  add  %i3, 4, %i3
a0157dc4:  82 10 00 1b  mov  %i3, %g1
a0157dc8:  b6 06 e0 04  add  %i3, 4, %i3
a0157dcc:  e0 50 60 02  ldsh  [ %g1 + 2 ], %l0
a0157dd0:  80 a4 20 00  cmp  %l0, 0
a0157dd4:  06 80 02 13  bl  0xa0158620
a0157dd8:  82 10 20 2d  mov  0x2d, %g1
a0157ddc:  98 10 20 01  mov  1, %o4
a0157de0:  b0 95 a0 00  orcc  %l6, 0, %i0
a0157de4:  36 80 00 02  bge,a   0xa0157dec
a0157de8:  ba 0f 7f 7f  and  %i5, -129, %i5
a0157dec:  80 a0 00 10  cmp  %g0, %l0
a0157df0:  9a 40 20 00  addx  %g0, 0, %o5
a0157df4:  80 a0 00 18  cmp  %g0, %i0
a0157df8:  82 40 20 00  addx  %g0, 0, %g1
a0157dfc:  80 93 40 01  orcc  %o5, %g1, %g0
a0157e00:  02 80 02 d3  be  0xa015894c
a0157e04:  a6 07 bf 9c  add  %fp, -100, %l3
a0157e08:  82 0b 20 ff  and  %o4, 0xff, %g1
a0157e0c:  80 a0 60 01  cmp  %g1, 1
a0157e10:  22 80 00 f2  be,a   0xa01581d8
a0157e14:  80 a4 20 09  cmp  %l0, 9
a0157e18:  04 80 03 99  ble  0xa0158c7c
a0157e1c:  80 a0 60 02  cmp  %g1, 2
a0157e20:  02 80 00 f7  be  0xa01581fc
a0157e24:  82 0c 20 0f  and  %l0, 0xf, %g1
a0157e28:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a0157e2c:  a6 10 60 08  or  %g1, 8, %l3	! 0x1a8408
a0157e30:  7f ff fe 8a  call  0xa0157858
a0157e34:  90 10 00 13  mov  %l3, %o0
a0157e38:  a8 10 00 08  mov  %o0, %l4
a0157e3c:  80 a5 00 18  cmp  %l4, %i0
a0157e40:  16 80 00 03  bge  0xa0157e4c
a0157e44:  ac 10 00 14  mov  %l4, %l6
a0157e48:  ac 10 00 18  mov  %i0, %l6
a0157e4c:  c2 4f b8 f7  ldsb  [ %fp + -1801 ], %g1
a0157e50:  80 a0 60 00  cmp  %g1, 0
a0157e54:  02 80 01 ff  be  0xa0158650
a0157e58:  c2 0f b8 f7  ldub  [ %fp + -1801 ], %g1
a0157e5c:  ac 05 a0 01  inc  %l6
a0157e60:  ae 8f 60 84  andcc  %i5, 0x84, %l7
a0157e64:  32 80 00 33  bne,a   0xa0157f30
a0157e68:  83 28 60 18  sll  %g1, 0x18, %g1
a0157e6c:  d2 07 b8 ec  ld  [ %fp + -1812 ], %o1
a0157e70:  a0 22 40 16  sub  %o1, %l6, %l0
a0157e74:  80 a4 20 00  cmp  %l0, 0
a0157e78:  04 80 00 2d  ble  0xa0157f2c
a0157e7c:  80 a4 20 10  cmp  %l0, 0x10
a0157e80:  04 80 00 1d  ble  0xa0157ef4
a0157e84:  17 00 06 a0  sethi  %hi(0x1a8000), %o3
a0157e88:  10 80 00 06  b  0xa0157ea0
a0157e8c:  a2 12 e3 e8  or  %o3, 0x3e8, %l1	! 0x1a83e8
a0157e90:  a0 04 3f f0  add  %l0, -16, %l0
a0157e94:  80 a4 20 10  cmp  %l0, 0x10
a0157e98:  04 80 00 18  ble  0xa0157ef8
a0157e9c:  19 00 06 a0  sethi  %hi(0x1a8000), %o4
a0157ea0:  82 10 20 10  mov  0x10, %g1
a0157ea4:  c2 24 a0 04  st  %g1, [ %l2 + 4 ]
a0157ea8:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a0157eac:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0157eb0:  9a 03 60 01  inc  %o5
a0157eb4:  e2 24 80 00  st  %l1, [ %l2 ]
a0157eb8:  82 00 60 10  add  %g1, 0x10, %g1
a0157ebc:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0157ec0:  80 a3 60 07  cmp  %o5, 7
a0157ec4:  a4 04 a0 08  add  %l2, 8, %l2
a0157ec8:  04 bf ff f2  ble  0xa0157e90
a0157ecc:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a0157ed0:  90 10 00 19  mov  %i1, %o0
a0157ed4:  7f ff fe d3  call  0xa0157a20
a0157ed8:  92 07 bf e0  add  %fp, -32, %o1
a0157edc:  80 a2 20 00  cmp  %o0, 0
a0157ee0:  12 80 02 ad  bne  0xa0158994
a0157ee4:  a0 04 3f f0  add  %l0, -16, %l0
a0157ee8:  80 a4 20 10  cmp  %l0, 0x10
a0157eec:  14 bf ff ed  bg  0xa0157ea0
a0157ef0:  a4 10 00 1c  mov  %i4, %l2
a0157ef4:  19 00 06 a0  sethi  %hi(0x1a8000), %o4
a0157ef8:  82 13 23 e8  or  %o4, 0x3e8, %g1	! 0x1a83e8
a0157efc:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a0157f00:  c2 24 80 00  st  %g1, [ %l2 ]
a0157f04:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a0157f08:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a0157f0c:  82 00 60 01  inc  %g1
a0157f10:  9a 03 40 10  add  %o5, %l0, %o5
a0157f14:  da 27 bf e8  st  %o5, [ %fp + -24 ]
a0157f18:  80 a0 60 07  cmp  %g1, 7
a0157f1c:  a4 04 a0 08  add  %l2, 8, %l2
a0157f20:  14 80 02 83  bg  0xa015892c
a0157f24:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a0157f28:  c2 0f b8 f7  ldub  [ %fp + -1801 ], %g1
a0157f2c:  83 28 60 18  sll  %g1, 0x18, %g1
a0157f30:  80 a0 60 00  cmp  %g1, 0
a0157f34:  02 80 01 cc  be  0xa0158664
a0157f38:  80 8f 60 02  btst  2, %i5
a0157f3c:  82 10 20 01  mov  1, %g1
a0157f40:  c2 24 a0 04  st  %g1, [ %l2 + 4 ]
a0157f44:  d8 07 bf e4  ld  [ %fp + -28 ], %o4
a0157f48:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0157f4c:  9a 07 b8 f7  add  %fp, -1801, %o5
a0157f50:  98 03 20 01  inc  %o4
a0157f54:  da 24 80 00  st  %o5, [ %l2 ]
a0157f58:  82 00 60 01  inc  %g1
a0157f5c:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0157f60:  80 a3 20 07  cmp  %o4, 7
a0157f64:  a4 04 a0 08  add  %l2, 8, %l2
a0157f68:  14 80 01 d1  bg  0xa01586ac
a0157f6c:  d8 27 bf e4  st  %o4, [ %fp + -28 ]
a0157f70:  80 a5 e0 80  cmp  %l7, 0x80
a0157f74:  02 80 01 d7  be  0xa01586d0
a0157f78:  da 07 b8 ec  ld  [ %fp + -1812 ], %o5
a0157f7c:  a0 26 00 14  sub  %i0, %l4, %l0
a0157f80:  80 a4 20 00  cmp  %l0, 0
a0157f84:  04 80 00 31  ble  0xa0158048
a0157f88:  80 a4 20 10  cmp  %l0, 0x10
a0157f8c:  04 80 00 1d  ble  0xa0158000
a0157f90:  2f 00 06 a0  sethi  %hi(0x1a8000), %l7
a0157f94:  10 80 00 06  b  0xa0157fac
a0157f98:  a2 15 e3 f8  or  %l7, 0x3f8, %l1	! 0x1a83f8
a0157f9c:  a0 04 3f f0  add  %l0, -16, %l0
a0157fa0:  80 a4 20 10  cmp  %l0, 0x10
a0157fa4:  04 80 00 18  ble  0xa0158004
a0157fa8:  82 15 e3 f8  or  %l7, 0x3f8, %g1
a0157fac:  82 10 20 10  mov  0x10, %g1
a0157fb0:  c2 24 a0 04  st  %g1, [ %l2 + 4 ]
a0157fb4:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a0157fb8:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0157fbc:  9a 03 60 01  inc  %o5
a0157fc0:  e2 24 80 00  st  %l1, [ %l2 ]
a0157fc4:  82 00 60 10  add  %g1, 0x10, %g1
a0157fc8:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0157fcc:  80 a3 60 07  cmp  %o5, 7
a0157fd0:  a4 04 a0 08  add  %l2, 8, %l2
a0157fd4:  04 bf ff f2  ble  0xa0157f9c
a0157fd8:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a0157fdc:  90 10 00 19  mov  %i1, %o0
a0157fe0:  7f ff fe 90  call  0xa0157a20
a0157fe4:  92 07 bf e0  add  %fp, -32, %o1
a0157fe8:  80 a2 20 00  cmp  %o0, 0
a0157fec:  12 80 02 6a  bne  0xa0158994
a0157ff0:  a0 04 3f f0  add  %l0, -16, %l0
a0157ff4:  80 a4 20 10  cmp  %l0, 0x10
a0157ff8:  14 bf ff ed  bg  0xa0157fac
a0157ffc:  a4 10 00 1c  mov  %i4, %l2
a0158000:  82 15 e3 f8  or  %l7, 0x3f8, %g1
a0158004:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a0158008:  c2 24 80 00  st  %g1, [ %l2 ]
a015800c:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a0158010:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a0158014:  82 00 60 01  inc  %g1
a0158018:  9a 03 40 10  add  %o5, %l0, %o5
a015801c:  da 27 bf e8  st  %o5, [ %fp + -24 ]
a0158020:  80 a0 60 07  cmp  %g1, 7
a0158024:  a4 04 a0 08  add  %l2, 8, %l2
a0158028:  04 80 00 08  ble  0xa0158048
a015802c:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a0158030:  90 10 00 19  mov  %i1, %o0
a0158034:  7f ff fe 7b  call  0xa0157a20
a0158038:  92 07 bf e0  add  %fp, -32, %o1
a015803c:  80 a2 20 00  cmp  %o0, 0
a0158040:  12 80 02 55  bne  0xa0158994
a0158044:  a4 10 00 1c  mov  %i4, %l2
a0158048:  80 8f 61 00  btst  0x100, %i5
a015804c:  12 80 01 d6  bne  0xa01587a4
a0158050:  80 a5 60 65  cmp  %l5, 0x65
a0158054:  e8 24 a0 04  st  %l4, [ %l2 + 4 ]
a0158058:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a015805c:  e6 24 80 00  st  %l3, [ %l2 ]
a0158060:  82 00 40 14  add  %g1, %l4, %g1
a0158064:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a0158068:  9a 03 60 01  inc  %o5
a015806c:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0158070:  80 a3 60 07  cmp  %o5, 7
a0158074:  a4 04 a0 08  add  %l2, 8, %l2
a0158078:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a015807c:  14 80 02 25  bg  0xa0158910
a0158080:  90 10 00 19  mov  %i1, %o0
a0158084:  80 8f 60 04  btst  4, %i5
a0158088:  02 80 00 36  be  0xa0158160
a015808c:  d2 07 b8 ec  ld  [ %fp + -1812 ], %o1
a0158090:  a0 22 40 16  sub  %o1, %l6, %l0
a0158094:  80 a4 20 00  cmp  %l0, 0
a0158098:  04 80 00 32  ble  0xa0158160
a015809c:  80 a4 20 10  cmp  %l0, 0x10
a01580a0:  04 80 00 1d  ble  0xa0158114
a01580a4:  17 00 06 a0  sethi  %hi(0x1a8000), %o3
a01580a8:  10 80 00 06  b  0xa01580c0
a01580ac:  a2 12 e3 e8  or  %o3, 0x3e8, %l1	! 0x1a83e8
a01580b0:  a0 04 3f f0  add  %l0, -16, %l0
a01580b4:  80 a4 20 10  cmp  %l0, 0x10
a01580b8:  24 80 00 18  ble,a   0xa0158118
a01580bc:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a01580c0:  82 10 20 10  mov  0x10, %g1
a01580c4:  c2 24 a0 04  st  %g1, [ %l2 + 4 ]
a01580c8:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a01580cc:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a01580d0:  9a 03 60 01  inc  %o5
a01580d4:  e2 24 80 00  st  %l1, [ %l2 ]
a01580d8:  82 00 60 10  add  %g1, 0x10, %g1
a01580dc:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a01580e0:  80 a3 60 07  cmp  %o5, 7
a01580e4:  a4 04 a0 08  add  %l2, 8, %l2
a01580e8:  04 bf ff f2  ble  0xa01580b0
a01580ec:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a01580f0:  90 10 00 19  mov  %i1, %o0
a01580f4:  7f ff fe 4b  call  0xa0157a20
a01580f8:  92 07 bf e0  add  %fp, -32, %o1
a01580fc:  80 a2 20 00  cmp  %o0, 0
a0158100:  12 80 02 25  bne  0xa0158994
a0158104:  a0 04 3f f0  add  %l0, -16, %l0
a0158108:  80 a4 20 10  cmp  %l0, 0x10
a015810c:  14 bf ff ed  bg  0xa01580c0
a0158110:  a4 10 00 1c  mov  %i4, %l2
a0158114:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a0158118:  d8 07 bf e8  ld  [ %fp + -24 ], %o4
a015811c:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a0158120:  11 00 06 a0  sethi  %hi(0x1a8000), %o0
a0158124:  9a 03 60 01  inc  %o5
a0158128:  98 03 00 10  add  %o4, %l0, %o4
a015812c:  82 12 23 e8  or  %o0, 0x3e8, %g1
a0158130:  c2 24 80 00  st  %g1, [ %l2 ]
a0158134:  d8 27 bf e8  st  %o4, [ %fp + -24 ]
a0158138:  80 a3 60 07  cmp  %o5, 7
a015813c:  04 80 00 08  ble  0xa015815c
a0158140:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a0158144:  90 10 00 19  mov  %i1, %o0
a0158148:  7f ff fe 36  call  0xa0157a20
a015814c:  92 07 bf e0  add  %fp, -32, %o1
a0158150:  80 a2 20 00  cmp  %o0, 0
a0158154:  12 80 02 11  bne  0xa0158998
a0158158:  da 07 b8 d4  ld  [ %fp + -1836 ], %o5
a015815c:  d2 07 b8 ec  ld  [ %fp + -1812 ], %o1
a0158160:  80 a5 80 09  cmp  %l6, %o1
a0158164:  16 80 00 03  bge  0xa0158170
a0158168:  82 10 00 16  mov  %l6, %g1
a015816c:  82 10 00 09  mov  %o1, %g1
a0158170:  d6 07 b8 f0  ld  [ %fp + -1808 ], %o3
a0158174:  96 02 c0 01  add  %o3, %g1, %o3
a0158178:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a015817c:  80 a0 60 00  cmp  %g1, 0
a0158180:  12 80 01 ff  bne  0xa015897c
a0158184:  d6 27 b8 f0  st  %o3, [ %fp + -1808 ]
a0158188:  d8 07 b8 d4  ld  [ %fp + -1836 ], %o4
a015818c:  c0 27 bf e4  clr  [ %fp + -28 ]
a0158190:  80 a3 20 00  cmp  %o4, 0
a0158194:  02 bf fe 5d  be  0xa0157b08
a0158198:  a4 10 00 1c  mov  %i4, %l2
a015819c:  92 10 00 0c  mov  %o4, %o1
a01581a0:  40 00 0d c8  call  0xa015b8c0
a01581a4:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a01581a8:  10 bf fe 58  b  0xa0157b08
a01581ac:  c0 27 b8 d4  clr  [ %fp + -1836 ]
a01581b0:  40 00 18 c5  call  0xa015e4c4
a01581b4:  92 10 20 0a  mov  0xa, %o1
a01581b8:  90 02 20 30  add  %o0, 0x30, %o0
a01581bc:  a6 04 ff ff  add  %l3, -1, %l3
a01581c0:  d0 2c c0 00  stb  %o0, [ %l3 ]
a01581c4:  90 10 00 10  mov  %l0, %o0
a01581c8:  7f ff fa 29  call  0xa0156a6c
a01581cc:  92 10 20 0a  mov  0xa, %o1
a01581d0:  a0 10 00 08  mov  %o0, %l0
a01581d4:  80 a4 20 09  cmp  %l0, 9
a01581d8:  18 bf ff f6  bgu  0xa01581b0
a01581dc:  90 10 00 10  mov  %l0, %o0
a01581e0:  a6 04 ff ff  add  %l3, -1, %l3
a01581e4:  82 04 20 30  add  %l0, 0x30, %g1
a01581e8:  c2 2c c0 00  stb  %g1, [ %l3 ]
a01581ec:  82 27 80 13  sub  %fp, %l3, %g1
a01581f0:  10 bf ff 13  b  0xa0157e3c
a01581f4:  a8 00 7f 9c  add  %g1, -100, %l4
a01581f8:  82 0c 20 0f  and  %l0, 0xf, %g1
a01581fc:  d0 07 b8 d8  ld  [ %fp + -1832 ], %o0
a0158200:  a6 04 ff ff  add  %l3, -1, %l3
a0158204:  da 08 40 08  ldub  [ %g1 + %o0 ], %o5
a0158208:  a1 34 20 04  srl  %l0, 4, %l0
a015820c:  80 a4 20 00  cmp  %l0, 0
a0158210:  02 bf ff f7  be  0xa01581ec
a0158214:  da 2c c0 00  stb  %o5, [ %l3 ]
a0158218:  82 0c 20 0f  and  %l0, 0xf, %g1
a015821c:  d0 07 b8 d8  ld  [ %fp + -1832 ], %o0
a0158220:  a6 04 ff ff  add  %l3, -1, %l3
a0158224:  da 08 40 08  ldub  [ %g1 + %o0 ], %o5
a0158228:  a1 34 20 04  srl  %l0, 4, %l0
a015822c:  80 a4 20 00  cmp  %l0, 0
a0158230:  12 bf ff f2  bne  0xa01581f8
a0158234:  da 2c c0 00  stb  %o5, [ %l3 ]
a0158238:  10 bf ff ee  b  0xa01581f0
a015823c:  82 27 80 13  sub  %fp, %l3, %g1
a0158240:  c2 06 c0 00  ld  [ %i3 ], %g1
a0158244:  c2 27 b8 ec  st  %g1, [ %fp + -1812 ]
a0158248:  80 a0 60 00  cmp  %g1, 0
a015824c:  16 bf fe 5e  bge  0xa0157bc4
a0158250:  b6 06 e0 04  add  %i3, 4, %i3
a0158254:  82 20 00 01  neg  %g1
a0158258:  c2 27 b8 ec  st  %g1, [ %fp + -1812 ]
a015825c:  10 bf fe 5a  b  0xa0157bc4
a0158260:  ba 17 60 04  or  %i5, 4, %i5
a0158264:  b4 06 a0 01  inc  %i2
a0158268:  10 bf fe 57  b  0xa0157bc4
a015826c:  ba 17 60 10  or  %i5, 0x10, %i5
a0158270:  80 a5 60 00  cmp  %l5, 0
a0158274:  02 80 04 90  be  0xa01594b4
a0158278:  a6 07 be 40  add  %fp, -448, %l3
a015827c:  ea 2f be 40  stb  %l5, [ %fp + -448 ]
a0158280:  c0 2f b8 f7  clrb  [ %fp + -1801 ]
a0158284:  10 bf fe ee  b  0xa0157e3c
a0158288:  a8 10 20 01  mov  1, %l4
a015828c:  82 10 20 2b  mov  0x2b, %g1
a0158290:  10 bf fe 4d  b  0xa0157bc4
a0158294:  c2 2f b8 f7  stb  %g1, [ %fp + -1801 ]
a0158298:  10 bf fe 4b  b  0xa0157bc4
a015829c:  ba 17 60 01  or  %i5, 1, %i5
a01582a0:  c2 4f b8 f7  ldsb  [ %fp + -1801 ], %g1
a01582a4:  80 a0 60 00  cmp  %g1, 0
a01582a8:  32 bf fe 48  bne,a   0xa0157bc8
a01582ac:  c2 0e 80 00  ldub  [ %i2 ], %g1
a01582b0:  82 10 20 20  mov  0x20, %g1
a01582b4:  10 bf fe 44  b  0xa0157bc4
a01582b8:  c2 2f b8 f7  stb  %g1, [ %fp + -1801 ]
a01582bc:  a0 10 20 00  clr  %l0
a01582c0:  83 2c 20 02  sll  %l0, 2, %g1
a01582c4:  82 00 40 10  add  %g1, %l0, %g1
a01582c8:  82 00 40 01  add  %g1, %g1, %g1
a01582cc:  82 00 40 15  add  %g1, %l5, %g1
a01582d0:  ea 4e 80 00  ldsb  [ %i2 ], %l5
a01582d4:  9a 05 7f d0  add  %l5, -48, %o5
a01582d8:  80 a3 60 09  cmp  %o5, 9
a01582dc:  a0 00 7f d0  add  %g1, -48, %l0
a01582e0:  08 bf ff f8  bleu  0xa01582c0
a01582e4:  b4 06 a0 01  inc  %i2
a01582e8:  10 bf fe 3b  b  0xa0157bd4
a01582ec:  e0 27 b8 ec  st  %l0, [ %fp + -1812 ]
a01582f0:  10 bf fe 35  b  0xa0157bc4
a01582f4:  ba 17 60 80  or  %i5, 0x80, %i5
a01582f8:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a01582fc:  82 10 60 28  or  %g1, 0x28, %g1	! 0x1a8428
a0158300:  80 8f 60 10  btst  0x10, %i5
a0158304:  12 80 00 9d  bne  0xa0158578
a0158308:  c2 27 b8 d8  st  %g1, [ %fp + -1832 ]
a015830c:  80 8f 60 40  btst  0x40, %i5
a0158310:  02 80 00 9b  be  0xa015857c
a0158314:  82 10 00 1b  mov  %i3, %g1
a0158318:  b6 06 e0 04  add  %i3, 4, %i3
a015831c:  e0 10 60 02  lduh  [ %g1 + 2 ], %l0
a0158320:  80 a0 00 10  cmp  %g0, %l0
a0158324:  82 40 20 00  addx  %g0, 0, %g1
a0158328:  80 8f 40 01  btst  %i5, %g1
a015832c:  02 bf fe 90  be  0xa0157d6c
a0158330:  98 10 20 02  mov  2, %o4
a0158334:  ba 17 60 02  or  %i5, 2, %i5
a0158338:  10 bf fe aa  b  0xa0157de0
a015833c:  c0 2f b8 f7  clrb  [ %fp + -1801 ]
a0158340:  c2 4e 80 00  ldsb  [ %i2 ], %g1
a0158344:  80 a0 60 6c  cmp  %g1, 0x6c
a0158348:  02 bf ff c7  be  0xa0158264
a015834c:  c2 0e 80 00  ldub  [ %i2 ], %g1
a0158350:  10 bf fe 1e  b  0xa0157bc8
a0158354:  ba 17 60 10  or  %i5, 0x10, %i5
a0158358:  ea 4e 80 00  ldsb  [ %i2 ], %l5
a015835c:  80 a5 60 2a  cmp  %l5, 0x2a
a0158360:  02 80 04 92  be  0xa01595a8
a0158364:  b4 06 a0 01  inc  %i2
a0158368:  82 05 7f d0  add  %l5, -48, %g1
a015836c:  80 a0 60 09  cmp  %g1, 9
a0158370:  18 80 00 0c  bgu  0xa01583a0
a0158374:  a0 10 20 00  clr  %l0
a0158378:  83 2c 20 02  sll  %l0, 2, %g1
a015837c:  82 00 40 10  add  %g1, %l0, %g1
a0158380:  82 00 40 01  add  %g1, %g1, %g1
a0158384:  82 00 40 15  add  %g1, %l5, %g1
a0158388:  ea 4e 80 00  ldsb  [ %i2 ], %l5
a015838c:  9a 05 7f d0  add  %l5, -48, %o5
a0158390:  80 a3 60 09  cmp  %o5, 9
a0158394:  a0 00 7f d0  add  %g1, -48, %l0
a0158398:  08 bf ff f8  bleu  0xa0158378
a015839c:  b4 06 a0 01  inc  %i2
a01583a0:  80 a4 3f ff  cmp  %l0, -1
a01583a4:  16 bf fe 0c  bge  0xa0157bd4
a01583a8:  ac 10 00 10  mov  %l0, %l6
a01583ac:  10 bf fe 0a  b  0xa0157bd4
a01583b0:  ac 10 3f ff  mov  -1, %l6
a01583b4:  10 bf fe 04  b  0xa0157bc4
a01583b8:  ba 17 60 40  or  %i5, 0x40, %i5
a01583bc:  e6 06 c0 00  ld  [ %i3 ], %l3
a01583c0:  c0 2f b8 f7  clrb  [ %fp + -1801 ]
a01583c4:  80 a4 e0 00  cmp  %l3, 0
a01583c8:  02 80 03 b2  be  0xa0159290
a01583cc:  b6 06 e0 04  add  %i3, 4, %i3
a01583d0:  80 a5 60 53  cmp  %l5, 0x53
a01583d4:  02 80 00 04  be  0xa01583e4
a01583d8:  80 8f 60 10  btst  0x10, %i5
a01583dc:  02 80 03 41  be  0xa01590e0
a01583e0:  80 a5 a0 00  cmp  %l6, 0
a01583e4:  ae 07 b9 10  add  %fp, -1776, %l7
a01583e8:  e6 27 b8 f8  st  %l3, [ %fp + -1800 ]
a01583ec:  90 10 00 17  mov  %l7, %o0
a01583f0:  92 10 20 00  clr  %o1
a01583f4:  7f ff fc bd  call  0xa01576e8
a01583f8:  94 10 20 08  mov  8, %o2
a01583fc:  80 a5 a0 00  cmp  %l6, 0
a0158400:  a2 10 20 00  clr  %l1
a0158404:  06 80 04 12  bl  0xa015944c
a0158408:  a8 10 20 00  clr  %l4
a015840c:  9b 2c 60 02  sll  %l1, 2, %o5
a0158410:  c2 07 b8 f8  ld  [ %fp + -1800 ], %g1
a0158414:  d4 00 40 0d  ld  [ %g1 + %o5 ], %o2
a0158418:  80 a2 a0 00  cmp  %o2, 0
a015841c:  02 80 00 0e  be  0xa0158454
a0158420:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a0158424:  92 07 be 40  add  %fp, -448, %o1
a0158428:  40 00 04 a4  call  0xa01596b8
a015842c:  96 10 00 17  mov  %l7, %o3
a0158430:  80 a2 3f ff  cmp  %o0, -1
a0158434:  02 80 03 fa  be  0xa015941c
a0158438:  82 02 00 14  add  %o0, %l4, %g1
a015843c:  80 a0 40 16  cmp  %g1, %l6
a0158440:  34 80 00 06  bg,a   0xa0158458
a0158444:  80 a5 20 00  cmp  %l4, 0
a0158448:  a8 10 00 01  mov  %g1, %l4
a015844c:  12 bf ff f0  bne  0xa015840c
a0158450:  a2 04 60 01  inc  %l1
a0158454:  80 a5 20 00  cmp  %l4, 0
a0158458:  02 bf fe 7a  be  0xa0157e40
a015845c:  80 a5 00 18  cmp  %l4, %i0
a0158460:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a0158464:  40 00 0f be  call  0xa015c35c
a0158468:  92 05 20 01  add  %l4, 1, %o1
a015846c:  80 a2 20 00  cmp  %o0, 0
a0158470:  02 80 04 4a  be  0xa0159598
a0158474:  d0 27 b8 d4  st  %o0, [ %fp + -1836 ]
a0158478:  92 10 20 00  clr  %o1
a015847c:  94 10 20 08  mov  8, %o2
a0158480:  7f ff fc 9a  call  0xa01576e8
a0158484:  90 10 00 17  mov  %l7, %o0
a0158488:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a015848c:  d2 07 b8 d4  ld  [ %fp + -1836 ], %o1
a0158490:  98 10 00 17  mov  %l7, %o4
a0158494:  94 07 b8 f8  add  %fp, -1800, %o2
a0158498:  40 00 04 a7  call  0xa0159734
a015849c:  96 10 00 14  mov  %l4, %o3
a01584a0:  80 a2 00 14  cmp  %o0, %l4
a01584a4:  12 80 03 de  bne  0xa015941c
a01584a8:  d8 07 b8 d4  ld  [ %fp + -1836 ], %o4
a01584ac:  c0 2b 00 14  clrb  [ %o4 + %l4 ]
a01584b0:  10 bf fe 63  b  0xa0157e3c
a01584b4:  e6 07 b8 d4  ld  [ %fp + -1836 ], %l3
a01584b8:  80 8f 60 10  btst  0x10, %i5
a01584bc:  02 80 02 37  be  0xa0158d98
a01584c0:  80 8f 60 40  btst  0x40, %i5
a01584c4:  da 06 c0 00  ld  [ %i3 ], %o5
a01584c8:  d0 07 b8 f0  ld  [ %fp + -1808 ], %o0
a01584cc:  d0 23 40 00  st  %o0, [ %o5 ]
a01584d0:  10 bf fd 8e  b  0xa0157b08
a01584d4:  b6 06 e0 04  add  %i3, 4, %i3
a01584d8:  9a 10 00 1b  mov  %i3, %o5
a01584dc:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a01584e0:  e0 03 40 00  ld  [ %o5 ], %l0
a01584e4:  82 10 60 28  or  %g1, 0x28, %g1
a01584e8:  b6 06 e0 04  add  %i3, 4, %i3
a01584ec:  c2 27 b8 d8  st  %g1, [ %fp + -1832 ]
a01584f0:  ba 17 60 02  or  %i5, 2, %i5
a01584f4:  98 10 20 02  mov  2, %o4
a01584f8:  aa 10 20 78  mov  0x78, %l5
a01584fc:  10 bf fe 39  b  0xa0157de0
a0158500:  c0 2f b8 f7  clrb  [ %fp + -1801 ]
a0158504:  10 bf fd b0  b  0xa0157bc4
a0158508:  ba 17 60 08  or  %i5, 8, %i5
a015850c:  80 a5 60 43  cmp  %l5, 0x43
a0158510:  02 80 00 05  be  0xa0158524
a0158514:  a6 07 be 40  add  %fp, -448, %l3
a0158518:  80 8f 60 10  btst  0x10, %i5
a015851c:  22 80 02 cb  be,a   0xa0159048
a0158520:  da 06 c0 00  ld  [ %i3 ], %o5
a0158524:  a0 07 b9 50  add  %fp, -1712, %l0
a0158528:  92 10 20 00  clr  %o1
a015852c:  94 10 20 08  mov  8, %o2
a0158530:  7f ff fc 6e  call  0xa01576e8
a0158534:  90 10 00 10  mov  %l0, %o0
a0158538:  d4 06 c0 00  ld  [ %i3 ], %o2
a015853c:  96 10 00 10  mov  %l0, %o3
a0158540:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a0158544:  40 00 04 5d  call  0xa01596b8
a0158548:  92 10 00 13  mov  %l3, %o1
a015854c:  a8 10 00 08  mov  %o0, %l4
a0158550:  80 a2 3f ff  cmp  %o0, -1
a0158554:  02 80 03 b2  be  0xa015941c
a0158558:  b6 06 e0 04  add  %i3, 4, %i3
a015855c:  10 bf fe 38  b  0xa0157e3c
a0158560:  c0 2f b8 f7  clrb  [ %fp + -1801 ]
a0158564:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a0158568:  82 10 60 40  or  %g1, 0x40, %g1	! 0x1a8440
a015856c:  80 8f 60 10  btst  0x10, %i5
a0158570:  02 bf ff 67  be  0xa015830c
a0158574:  c2 27 b8 d8  st  %g1, [ %fp + -1832 ]
a0158578:  82 10 00 1b  mov  %i3, %g1
a015857c:  b6 06 e0 04  add  %i3, 4, %i3
a0158580:  10 bf ff 68  b  0xa0158320
a0158584:  e0 00 40 00  ld  [ %g1 ], %l0
a0158588:  80 a5 bf ff  cmp  %l6, -1
a015858c:  02 80 03 3b  be  0xa0159278
a0158590:  82 1d 60 67  xor  %l5, 0x67, %g1
a0158594:  80 a0 00 01  cmp  %g0, %g1
a0158598:  98 60 3f ff  subx  %g0, -1, %o4
a015859c:  82 1d 60 47  xor  %l5, 0x47, %g1
a01585a0:  80 a0 00 01  cmp  %g0, %g1
a01585a4:  9a 60 3f ff  subx  %g0, -1, %o5
a01585a8:  80 93 00 0d  orcc  %o4, %o5, %g0
a01585ac:  02 80 00 06  be  0xa01585c4
a01585b0:  80 8f 60 08  btst  8, %i5
a01585b4:  80 a5 a0 00  cmp  %l6, 0
a01585b8:  22 80 00 02  be,a   0xa01585c0
a01585bc:  ac 10 20 01  mov  1, %l6
a01585c0:  80 8f 60 08  btst  8, %i5
a01585c4:  02 80 01 fb  be  0xa0158db0
a01585c8:  d8 06 e0 04  ld  [ %i3 + 4 ], %o4
a01585cc:  da 06 c0 00  ld  [ %i3 ], %o5
a01585d0:  da 27 b9 48  st  %o5, [ %fp + -1720 ]
a01585d4:  d8 27 b9 4c  st  %o4, [ %fp + -1716 ]
a01585d8:  d0 1f b9 48  ldd  [ %fp + -1720 ], %o0
a01585dc:  d0 3f b8 e0  std  %o0, [ %fp + -1824 ]
a01585e0:  40 00 16 3d  call  0xa015ded4
a01585e4:  d0 1f b8 e0  ldd  [ %fp + -1824 ], %o0
a01585e8:  80 a2 20 00  cmp  %o0, 0
a01585ec:  02 80 01 fb  be  0xa0158dd8
a01585f0:  b6 06 e0 08  add  %i3, 8, %i3
a01585f4:  1b 00 06 a0  sethi  %hi(0x1a8000), %o5
a01585f8:  d0 1f b8 e0  ldd  [ %fp + -1824 ], %o0
a01585fc:  40 00 18 5e  call  0xa015e774
a0158600:  d4 1b 62 08  ldd  [ %o5 + 0x208 ], %o2
a0158604:  80 a2 20 00  cmp  %o0, 0
a0158608:  06 80 03 3e  bl  0xa0159300
a015860c:  82 10 20 2d  mov  0x2d, %g1
a0158610:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a0158614:  a6 10 60 58  or  %g1, 0x58, %l3	! 0x1a8458
a0158618:  10 bf fe 09  b  0xa0157e3c
a015861c:  a8 10 20 03  mov  3, %l4
a0158620:  c2 2f b8 f7  stb  %g1, [ %fp + -1801 ]
a0158624:  10 bf fd ee  b  0xa0157ddc
a0158628:  a0 20 00 10  neg  %l0
a015862c:  40 00 0b cb  call  0xa015b558
a0158630:  01 00 00 00  nop
a0158634:  10 bf fd 23  b  0xa0157ac0
a0158638:  c2 16 60 0c  lduh  [ %i1 + 0xc ], %g1
a015863c:  40 00 19 0b  call  0xa015ea68
a0158640:  90 06 60 58  add  %i1, 0x58, %o0
a0158644:  d8 16 60 0c  lduh  [ %i1 + 0xc ], %o4
a0158648:  10 bf fd 7f  b  0xa0157c44
a015864c:  d2 16 60 0e  lduh  [ %i1 + 0xe ], %o1
a0158650:  80 8f 60 02  btst  2, %i5
a0158654:  32 bf fe 03  bne,a   0xa0157e60
a0158658:  ac 05 a0 02  add  %l6, 2, %l6
a015865c:  10 bf fe 02  b  0xa0157e64
a0158660:  ae 8f 60 84  andcc  %i5, 0x84, %l7
a0158664:  02 bf fe 44  be  0xa0157f74
a0158668:  80 a5 e0 80  cmp  %l7, 0x80
a015866c:  82 10 20 30  mov  0x30, %g1
a0158670:  c2 2f be 38  stb  %g1, [ %fp + -456 ]
a0158674:  ea 2f be 39  stb  %l5, [ %fp + -455 ]
a0158678:  82 10 20 02  mov  2, %g1
a015867c:  c2 24 a0 04  st  %g1, [ %l2 + 4 ]
a0158680:  d8 07 bf e4  ld  [ %fp + -28 ], %o4
a0158684:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0158688:  9a 07 be 38  add  %fp, -456, %o5
a015868c:  98 03 20 01  inc  %o4
a0158690:  da 24 80 00  st  %o5, [ %l2 ]
a0158694:  82 00 60 02  add  %g1, 2, %g1
a0158698:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a015869c:  80 a3 20 07  cmp  %o4, 7
a01586a0:  a4 04 a0 08  add  %l2, 8, %l2
a01586a4:  04 bf fe 33  ble  0xa0157f70
a01586a8:  d8 27 bf e4  st  %o4, [ %fp + -28 ]
a01586ac:  90 10 00 19  mov  %i1, %o0
a01586b0:  7f ff fc dc  call  0xa0157a20
a01586b4:  92 07 bf e0  add  %fp, -32, %o1
a01586b8:  80 a2 20 00  cmp  %o0, 0
a01586bc:  12 80 00 b6  bne  0xa0158994
a01586c0:  80 a5 e0 80  cmp  %l7, 0x80
a01586c4:  12 bf fe 2e  bne  0xa0157f7c
a01586c8:  a4 10 00 1c  mov  %i4, %l2
a01586cc:  da 07 b8 ec  ld  [ %fp + -1812 ], %o5
a01586d0:  a0 23 40 16  sub  %o5, %l6, %l0
a01586d4:  80 a4 20 00  cmp  %l0, 0
a01586d8:  04 bf fe 29  ble  0xa0157f7c
a01586dc:  80 a4 20 10  cmp  %l0, 0x10
a01586e0:  04 80 00 1d  ble  0xa0158754
a01586e4:  2f 00 06 a0  sethi  %hi(0x1a8000), %l7
a01586e8:  10 80 00 06  b  0xa0158700
a01586ec:  a2 15 e3 f8  or  %l7, 0x3f8, %l1	! 0x1a83f8
a01586f0:  a0 04 3f f0  add  %l0, -16, %l0
a01586f4:  80 a4 20 10  cmp  %l0, 0x10
a01586f8:  04 80 00 18  ble  0xa0158758
a01586fc:  82 15 e3 f8  or  %l7, 0x3f8, %g1
a0158700:  82 10 20 10  mov  0x10, %g1
a0158704:  c2 24 a0 04  st  %g1, [ %l2 + 4 ]
a0158708:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a015870c:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0158710:  9a 03 60 01  inc  %o5
a0158714:  e2 24 80 00  st  %l1, [ %l2 ]
a0158718:  82 00 60 10  add  %g1, 0x10, %g1
a015871c:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0158720:  80 a3 60 07  cmp  %o5, 7
a0158724:  a4 04 a0 08  add  %l2, 8, %l2
a0158728:  04 bf ff f2  ble  0xa01586f0
a015872c:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a0158730:  90 10 00 19  mov  %i1, %o0
a0158734:  7f ff fc bb  call  0xa0157a20
a0158738:  92 07 bf e0  add  %fp, -32, %o1
a015873c:  80 a2 20 00  cmp  %o0, 0
a0158740:  12 80 00 95  bne  0xa0158994
a0158744:  a0 04 3f f0  add  %l0, -16, %l0
a0158748:  80 a4 20 10  cmp  %l0, 0x10
a015874c:  14 bf ff ed  bg  0xa0158700
a0158750:  a4 10 00 1c  mov  %i4, %l2
a0158754:  82 15 e3 f8  or  %l7, 0x3f8, %g1
a0158758:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a015875c:  c2 24 80 00  st  %g1, [ %l2 ]
a0158760:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a0158764:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a0158768:  82 00 60 01  inc  %g1
a015876c:  9a 03 40 10  add  %o5, %l0, %o5
a0158770:  da 27 bf e8  st  %o5, [ %fp + -24 ]
a0158774:  80 a0 60 07  cmp  %g1, 7
a0158778:  a4 04 a0 08  add  %l2, 8, %l2
a015877c:  04 bf fe 00  ble  0xa0157f7c
a0158780:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a0158784:  90 10 00 19  mov  %i1, %o0
a0158788:  7f ff fc a6  call  0xa0157a20
a015878c:  92 07 bf e0  add  %fp, -32, %o1
a0158790:  80 a2 20 00  cmp  %o0, 0
a0158794:  12 80 00 80  bne  0xa0158994
a0158798:  a4 10 00 1c  mov  %i4, %l2
a015879c:  10 bf fd f9  b  0xa0157f80
a01587a0:  a0 26 00 14  sub  %i0, %l4, %l0
a01587a4:  04 80 00 8b  ble  0xa01589d0
a01587a8:  c2 07 b9 04  ld  [ %fp + -1788 ], %g1
a01587ac:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a01587b0:  d0 1f b8 e0  ldd  [ %fp + -1824 ], %o0
a01587b4:  7f ff f7 bf  call  0xa01566b0
a01587b8:  d4 18 62 08  ldd  [ %g1 + 0x208 ], %o2
a01587bc:  80 a2 20 00  cmp  %o0, 0
a01587c0:  12 80 00 c4  bne  0xa0158ad0
a01587c4:  c2 07 b9 08  ld  [ %fp + -1784 ], %g1
a01587c8:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a01587cc:  82 10 60 60  or  %g1, 0x60, %g1	! 0x1a8460
a01587d0:  a0 10 20 01  mov  1, %l0
a01587d4:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a01587d8:  c2 24 80 00  st  %g1, [ %l2 ]
a01587dc:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a01587e0:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a01587e4:  9a 03 60 01  inc  %o5
a01587e8:  82 00 60 01  inc  %g1
a01587ec:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a01587f0:  80 a3 60 07  cmp  %o5, 7
a01587f4:  a4 04 a0 08  add  %l2, 8, %l2
a01587f8:  14 80 02 0c  bg  0xa0159028
a01587fc:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a0158800:  da 07 b9 08  ld  [ %fp + -1784 ], %o5
a0158804:  c2 07 b9 04  ld  [ %fp + -1788 ], %g1
a0158808:  80 a3 40 01  cmp  %o5, %g1
a015880c:  26 80 00 06  bl,a   0xa0158824
a0158810:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a0158814:  80 8f 60 01  btst  1, %i5
a0158818:  02 bf fe 1c  be  0xa0158088
a015881c:  80 8f 60 04  btst  4, %i5
a0158820:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a0158824:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a0158828:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a015882c:  d0 07 b8 e8  ld  [ %fp + -1816 ], %o0
a0158830:  9a 03 60 01  inc  %o5
a0158834:  d0 24 80 00  st  %o0, [ %l2 ]
a0158838:  82 00 60 01  inc  %g1
a015883c:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0158840:  80 a3 60 07  cmp  %o5, 7
a0158844:  a4 04 a0 08  add  %l2, 8, %l2
a0158848:  14 80 02 34  bg  0xa0159118
a015884c:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a0158850:  c2 07 b9 04  ld  [ %fp + -1788 ], %g1
a0158854:  a0 00 7f ff  add  %g1, -1, %l0
a0158858:  80 a4 20 00  cmp  %l0, 0
a015885c:  04 bf fe 0a  ble  0xa0158084
a0158860:  80 a4 20 10  cmp  %l0, 0x10
a0158864:  04 80 02 35  ble  0xa0159138
a0158868:  2f 00 06 a0  sethi  %hi(0x1a8000), %l7
a015886c:  10 80 00 06  b  0xa0158884
a0158870:  a2 15 e3 f8  or  %l7, 0x3f8, %l1	! 0x1a83f8
a0158874:  a0 04 3f f0  add  %l0, -16, %l0
a0158878:  80 a4 20 10  cmp  %l0, 0x10
a015887c:  04 80 00 18  ble  0xa01588dc
a0158880:  82 15 e3 f8  or  %l7, 0x3f8, %g1
a0158884:  82 10 20 10  mov  0x10, %g1
a0158888:  c2 24 a0 04  st  %g1, [ %l2 + 4 ]
a015888c:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a0158890:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0158894:  9a 03 60 01  inc  %o5
a0158898:  e2 24 80 00  st  %l1, [ %l2 ]
a015889c:  82 00 60 10  add  %g1, 0x10, %g1
a01588a0:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a01588a4:  80 a3 60 07  cmp  %o5, 7
a01588a8:  a4 04 a0 08  add  %l2, 8, %l2
a01588ac:  04 bf ff f2  ble  0xa0158874
a01588b0:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a01588b4:  90 10 00 19  mov  %i1, %o0
a01588b8:  7f ff fc 5a  call  0xa0157a20
a01588bc:  92 07 bf e0  add  %fp, -32, %o1
a01588c0:  80 a2 20 00  cmp  %o0, 0
a01588c4:  12 80 00 34  bne  0xa0158994
a01588c8:  a0 04 3f f0  add  %l0, -16, %l0
a01588cc:  80 a4 20 10  cmp  %l0, 0x10
a01588d0:  14 bf ff ed  bg  0xa0158884
a01588d4:  a4 10 00 1c  mov  %i4, %l2
a01588d8:  82 15 e3 f8  or  %l7, 0x3f8, %g1
a01588dc:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a01588e0:  c2 24 80 00  st  %g1, [ %l2 ]
a01588e4:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a01588e8:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a01588ec:  82 00 60 01  inc  %g1
a01588f0:  9a 03 40 10  add  %o5, %l0, %o5
a01588f4:  da 27 bf e8  st  %o5, [ %fp + -24 ]
a01588f8:  80 a0 60 07  cmp  %g1, 7
a01588fc:  a4 04 a0 08  add  %l2, 8, %l2
a0158900:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a0158904:  04 bf fd e1  ble  0xa0158088
a0158908:  80 8f 60 04  btst  4, %i5
a015890c:  90 10 00 19  mov  %i1, %o0
a0158910:  7f ff fc 44  call  0xa0157a20
a0158914:  92 07 bf e0  add  %fp, -32, %o1
a0158918:  80 a2 20 00  cmp  %o0, 0
a015891c:  12 80 00 1e  bne  0xa0158994
a0158920:  a4 10 00 1c  mov  %i4, %l2
a0158924:  10 bf fd d9  b  0xa0158088
a0158928:  80 8f 60 04  btst  4, %i5
a015892c:  90 10 00 19  mov  %i1, %o0
a0158930:  7f ff fc 3c  call  0xa0157a20
a0158934:  92 07 bf e0  add  %fp, -32, %o1
a0158938:  80 a2 20 00  cmp  %o0, 0
a015893c:  12 80 00 16  bne  0xa0158994
a0158940:  a4 10 00 1c  mov  %i4, %l2
a0158944:  10 bf fd 7a  b  0xa0157f2c
a0158948:  c2 0f b8 f7  ldub  [ %fp + -1801 ], %g1
a015894c:  80 8b 20 ff  btst  0xff, %o4
a0158950:  12 bf fe 28  bne  0xa01581f0
a0158954:  82 27 80 13  sub  %fp, %l3, %g1
a0158958:  80 8f 60 01  btst  1, %i5
a015895c:  22 bf fd 38  be,a   0xa0157e3c
a0158960:  a8 00 7f 9c  add  %g1, -100, %l4
a0158964:  82 10 20 30  mov  0x30, %g1
a0158968:  c2 2f bf 9b  stb  %g1, [ %fp + -101 ]
a015896c:  a6 07 bf 9b  add  %fp, -101, %l3
a0158970:  82 27 80 13  sub  %fp, %l3, %g1
a0158974:  10 bf fd 32  b  0xa0157e3c
a0158978:  a8 00 7f 9c  add  %g1, -100, %l4
a015897c:  90 10 00 19  mov  %i1, %o0
a0158980:  7f ff fc 28  call  0xa0157a20
a0158984:  92 07 bf e0  add  %fp, -32, %o1
a0158988:  80 a2 20 00  cmp  %o0, 0
a015898c:  02 bf fe 00  be  0xa015818c
a0158990:  d8 07 b8 d4  ld  [ %fp + -1836 ], %o4
a0158994:  da 07 b8 d4  ld  [ %fp + -1836 ], %o5
a0158998:  80 a3 60 00  cmp  %o5, 0
a015899c:  02 80 00 04  be  0xa01589ac
a01589a0:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a01589a4:  40 00 0b c7  call  0xa015b8c0
a01589a8:  92 10 00 0d  mov  %o5, %o1
a01589ac:  c2 16 60 0c  lduh  [ %i1 + 0xc ], %g1
a01589b0:  80 88 62 00  btst  0x200, %g1
a01589b4:  02 80 00 c5  be  0xa0158cc8
a01589b8:  98 10 00 01  mov  %g1, %o4
a01589bc:  80 8b 20 40  btst  0x40, %o4
a01589c0:  02 80 03 00  be  0xa01595c0
a01589c4:  d0 07 b8 f0  ld  [ %fp + -1808 ], %o0
a01589c8:  10 80 02 fe  b  0xa01595c0
a01589cc:  90 10 3f ff  mov  -1, %o0
a01589d0:  80 a0 60 01  cmp  %g1, 1
a01589d4:  04 80 00 c1  ble  0xa0158cd8
a01589d8:  80 8f 60 01  btst  1, %i5
a01589dc:  c2 0c c0 00  ldub  [ %l3 ], %g1
a01589e0:  c2 2f be 38  stb  %g1, [ %fp + -456 ]
a01589e4:  9a 10 20 2e  mov  0x2e, %o5
a01589e8:  da 2f be 39  stb  %o5, [ %fp + -455 ]
a01589ec:  82 10 20 02  mov  2, %g1
a01589f0:  c2 24 a0 04  st  %g1, [ %l2 + 4 ]
a01589f4:  d8 07 bf e4  ld  [ %fp + -28 ], %o4
a01589f8:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a01589fc:  9a 07 be 38  add  %fp, -456, %o5
a0158a00:  98 03 20 01  inc  %o4
a0158a04:  da 24 80 00  st  %o5, [ %l2 ]
a0158a08:  82 00 60 02  add  %g1, 2, %g1
a0158a0c:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0158a10:  80 a3 20 07  cmp  %o4, 7
a0158a14:  a6 04 e0 01  inc  %l3
a0158a18:  a4 04 a0 08  add  %l2, 8, %l2
a0158a1c:  14 80 00 89  bg  0xa0158c40
a0158a20:  d8 27 bf e4  st  %o4, [ %fp + -28 ]
a0158a24:  19 00 06 a0  sethi  %hi(0x1a8000), %o4
a0158a28:  d0 1f b8 e0  ldd  [ %fp + -1824 ], %o0
a0158a2c:  7f ff f7 3a  call  0xa0156714
a0158a30:  d4 1b 22 08  ldd  [ %o4 + 0x208 ], %o2
a0158a34:  80 a2 20 00  cmp  %o0, 0
a0158a38:  02 80 00 59  be  0xa0158b9c
a0158a3c:  c2 07 b9 04  ld  [ %fp + -1788 ], %g1
a0158a40:  d8 07 b9 04  ld  [ %fp + -1788 ], %o4
a0158a44:  82 03 3f ff  add  %o4, -1, %g1
a0158a48:  c2 24 a0 04  st  %g1, [ %l2 + 4 ]
a0158a4c:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a0158a50:  9a 03 40 0c  add  %o5, %o4, %o5
a0158a54:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a0158a58:  e6 24 80 00  st  %l3, [ %l2 ]
a0158a5c:  82 00 60 01  inc  %g1
a0158a60:  9a 03 7f ff  add  %o5, -1, %o5
a0158a64:  da 27 bf e8  st  %o5, [ %fp + -24 ]
a0158a68:  80 a0 60 07  cmp  %g1, 7
a0158a6c:  a4 04 a0 08  add  %l2, 8, %l2
a0158a70:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a0158a74:  14 80 00 7b  bg  0xa0158c60
a0158a78:  90 10 00 19  mov  %i1, %o0
a0158a7c:  da 07 b8 dc  ld  [ %fp + -1828 ], %o5
a0158a80:  82 07 bf f0  add  %fp, -16, %g1
a0158a84:  da 24 a0 04  st  %o5, [ %l2 + 4 ]
a0158a88:  c2 24 80 00  st  %g1, [ %l2 ]
a0158a8c:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a0158a90:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0158a94:  d0 07 b8 dc  ld  [ %fp + -1828 ], %o0
a0158a98:  9a 03 60 01  inc  %o5
a0158a9c:  10 bf fd 74  b  0xa015806c
a0158aa0:  82 00 40 08  add  %g1, %o0, %g1
a0158aa4:  b6 06 e0 04  add  %i3, 4, %i3
a0158aa8:  e0 00 40 00  ld  [ %g1 ], %l0
a0158aac:  10 bf fc bd  b  0xa0157da0
a0158ab0:  98 10 20 00  clr  %o4
a0158ab4:  b6 06 e0 04  add  %i3, 4, %i3
a0158ab8:  10 bf fc c6  b  0xa0157dd0
a0158abc:  e0 00 40 00  ld  [ %g1 ], %l0
a0158ac0:  b6 06 e0 04  add  %i3, 4, %i3
a0158ac4:  e0 00 40 00  ld  [ %g1 ], %l0
a0158ac8:  10 bf fc a9  b  0xa0157d6c
a0158acc:  98 10 20 01  mov  1, %o4
a0158ad0:  80 a0 60 00  cmp  %g1, 0
a0158ad4:  04 80 01 a5  ble  0xa0159168
a0158ad8:  da 07 b9 04  ld  [ %fp + -1788 ], %o5
a0158adc:  80 a0 40 0d  cmp  %g1, %o5
a0158ae0:  26 80 00 8c  bl,a   0xa0158d10
a0158ae4:  c2 24 a0 04  st  %g1, [ %l2 + 4 ]
a0158ae8:  da 24 a0 04  st  %o5, [ %l2 + 4 ]
a0158aec:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0158af0:  82 00 40 0d  add  %g1, %o5, %g1
a0158af4:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a0158af8:  9a 03 60 01  inc  %o5
a0158afc:  e6 24 80 00  st  %l3, [ %l2 ]
a0158b00:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0158b04:  80 a3 60 07  cmp  %o5, 7
a0158b08:  a4 04 a0 08  add  %l2, 8, %l2
a0158b0c:  14 80 01 e5  bg  0xa01592a0
a0158b10:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a0158b14:  da 07 b9 08  ld  [ %fp + -1784 ], %o5
a0158b18:  c2 07 b9 04  ld  [ %fp + -1788 ], %g1
a0158b1c:  a0 23 40 01  sub  %o5, %g1, %l0
a0158b20:  80 a4 20 00  cmp  %l0, 0
a0158b24:  04 80 01 5a  ble  0xa015908c
a0158b28:  80 a4 20 10  cmp  %l0, 0x10
a0158b2c:  04 80 01 4c  ble  0xa015905c
a0158b30:  2f 00 06 a0  sethi  %hi(0x1a8000), %l7
a0158b34:  10 80 00 06  b  0xa0158b4c
a0158b38:  a2 15 e3 f8  or  %l7, 0x3f8, %l1	! 0x1a83f8
a0158b3c:  a0 04 3f f0  add  %l0, -16, %l0
a0158b40:  80 a4 20 10  cmp  %l0, 0x10
a0158b44:  04 80 01 47  ble  0xa0159060
a0158b48:  82 15 e3 f8  or  %l7, 0x3f8, %g1
a0158b4c:  82 10 20 10  mov  0x10, %g1
a0158b50:  c2 24 a0 04  st  %g1, [ %l2 + 4 ]
a0158b54:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a0158b58:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0158b5c:  9a 03 60 01  inc  %o5
a0158b60:  e2 24 80 00  st  %l1, [ %l2 ]
a0158b64:  82 00 60 10  add  %g1, 0x10, %g1
a0158b68:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0158b6c:  80 a3 60 07  cmp  %o5, 7
a0158b70:  a4 04 a0 08  add  %l2, 8, %l2
a0158b74:  04 bf ff f2  ble  0xa0158b3c
a0158b78:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a0158b7c:  90 10 00 19  mov  %i1, %o0
a0158b80:  7f ff fb a8  call  0xa0157a20
a0158b84:  92 07 bf e0  add  %fp, -32, %o1
a0158b88:  80 a2 20 00  cmp  %o0, 0
a0158b8c:  12 bf ff 82  bne  0xa0158994
a0158b90:  a4 10 00 1c  mov  %i4, %l2
a0158b94:  10 bf ff eb  b  0xa0158b40
a0158b98:  a0 04 3f f0  add  %l0, -16, %l0
a0158b9c:  a0 00 7f ff  add  %g1, -1, %l0
a0158ba0:  80 a4 20 00  cmp  %l0, 0
a0158ba4:  04 bf ff b6  ble  0xa0158a7c
a0158ba8:  80 a4 20 10  cmp  %l0, 0x10
a0158bac:  04 80 01 45  ble  0xa01590c0
a0158bb0:  2f 00 06 a0  sethi  %hi(0x1a8000), %l7
a0158bb4:  10 80 00 06  b  0xa0158bcc
a0158bb8:  a2 15 e3 f8  or  %l7, 0x3f8, %l1	! 0x1a83f8
a0158bbc:  a0 04 3f f0  add  %l0, -16, %l0
a0158bc0:  80 a4 20 10  cmp  %l0, 0x10
a0158bc4:  04 80 00 18  ble  0xa0158c24
a0158bc8:  82 15 e3 f8  or  %l7, 0x3f8, %g1
a0158bcc:  82 10 20 10  mov  0x10, %g1
a0158bd0:  c2 24 a0 04  st  %g1, [ %l2 + 4 ]
a0158bd4:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a0158bd8:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0158bdc:  9a 03 60 01  inc  %o5
a0158be0:  e2 24 80 00  st  %l1, [ %l2 ]
a0158be4:  82 00 60 10  add  %g1, 0x10, %g1
a0158be8:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0158bec:  80 a3 60 07  cmp  %o5, 7
a0158bf0:  a4 04 a0 08  add  %l2, 8, %l2
a0158bf4:  04 bf ff f2  ble  0xa0158bbc
a0158bf8:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a0158bfc:  90 10 00 19  mov  %i1, %o0
a0158c00:  7f ff fb 88  call  0xa0157a20
a0158c04:  92 07 bf e0  add  %fp, -32, %o1
a0158c08:  80 a2 20 00  cmp  %o0, 0
a0158c0c:  12 bf ff 62  bne  0xa0158994
a0158c10:  a0 04 3f f0  add  %l0, -16, %l0
a0158c14:  80 a4 20 10  cmp  %l0, 0x10
a0158c18:  14 bf ff ed  bg  0xa0158bcc
a0158c1c:  a4 10 00 1c  mov  %i4, %l2
a0158c20:  82 15 e3 f8  or  %l7, 0x3f8, %g1
a0158c24:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a0158c28:  c2 24 80 00  st  %g1, [ %l2 ]
a0158c2c:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a0158c30:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a0158c34:  9a 03 40 10  add  %o5, %l0, %o5
a0158c38:  10 bf ff 8b  b  0xa0158a64
a0158c3c:  82 00 60 01  inc  %g1
a0158c40:  90 10 00 19  mov  %i1, %o0
a0158c44:  7f ff fb 77  call  0xa0157a20
a0158c48:  92 07 bf e0  add  %fp, -32, %o1
a0158c4c:  80 a2 20 00  cmp  %o0, 0
a0158c50:  12 bf ff 51  bne  0xa0158994
a0158c54:  a4 10 00 1c  mov  %i4, %l2
a0158c58:  10 bf ff 74  b  0xa0158a28
a0158c5c:  19 00 06 a0  sethi  %hi(0x1a8000), %o4
a0158c60:  7f ff fb 70  call  0xa0157a20
a0158c64:  92 07 bf e0  add  %fp, -32, %o1
a0158c68:  80 a2 20 00  cmp  %o0, 0
a0158c6c:  12 bf ff 4a  bne  0xa0158994
a0158c70:  a4 10 00 1c  mov  %i4, %l2
a0158c74:  10 bf ff 83  b  0xa0158a80
a0158c78:  da 07 b8 dc  ld  [ %fp + -1828 ], %o5
a0158c7c:  80 a0 60 00  cmp  %g1, 0
a0158c80:  12 bf fc 6b  bne  0xa0157e2c
a0158c84:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a0158c88:  82 0c 20 07  and  %l0, 7, %g1
a0158c8c:  a6 04 ff ff  add  %l3, -1, %l3
a0158c90:  82 00 60 30  add  %g1, 0x30, %g1
a0158c94:  a1 34 20 03  srl  %l0, 3, %l0
a0158c98:  80 a4 20 00  cmp  %l0, 0
a0158c9c:  12 bf ff fb  bne  0xa0158c88
a0158ca0:  c2 2c c0 00  stb  %g1, [ %l3 ]
a0158ca4:  80 8f 60 01  btst  1, %i5
a0158ca8:  22 bf fd 52  be,a   0xa01581f0
a0158cac:  82 27 80 13  sub  %fp, %l3, %g1
a0158cb0:  80 a0 60 30  cmp  %g1, 0x30
a0158cb4:  02 bf fd 4e  be  0xa01581ec
a0158cb8:  82 10 20 30  mov  0x30, %g1
a0158cbc:  a6 04 ff ff  add  %l3, -1, %l3
a0158cc0:  10 bf fd 4b  b  0xa01581ec
a0158cc4:  c2 2c c0 00  stb  %g1, [ %l3 ]
a0158cc8:  40 00 17 68  call  0xa015ea68
a0158ccc:  90 06 60 58  add  %i1, 0x58, %o0
a0158cd0:  10 bf ff 3b  b  0xa01589bc
a0158cd4:  d8 16 60 0c  lduh  [ %i1 + 0xc ], %o4
a0158cd8:  32 bf ff 42  bne,a   0xa01589e0
a0158cdc:  c2 0c c0 00  ldub  [ %l3 ], %g1
a0158ce0:  82 10 20 01  mov  1, %g1
a0158ce4:  c2 24 a0 04  st  %g1, [ %l2 + 4 ]
a0158ce8:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a0158cec:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0158cf0:  9a 03 60 01  inc  %o5
a0158cf4:  e6 24 80 00  st  %l3, [ %l2 ]
a0158cf8:  82 00 60 01  inc  %g1
a0158cfc:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0158d00:  80 a3 60 07  cmp  %o5, 7
a0158d04:  a4 04 a0 08  add  %l2, 8, %l2
a0158d08:  10 bf ff 5b  b  0xa0158a74
a0158d0c:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a0158d10:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a0158d14:  9a 03 40 01  add  %o5, %g1, %o5
a0158d18:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a0158d1c:  82 00 60 01  inc  %g1
a0158d20:  e6 24 80 00  st  %l3, [ %l2 ]
a0158d24:  da 27 bf e8  st  %o5, [ %fp + -24 ]
a0158d28:  80 a0 60 07  cmp  %g1, 7
a0158d2c:  a4 04 a0 08  add  %l2, 8, %l2
a0158d30:  14 80 01 6c  bg  0xa01592e0
a0158d34:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a0158d38:  03 00 06 62  sethi  %hi(0x198800), %g1
a0158d3c:  9a 10 20 01  mov  1, %o5
a0158d40:  82 10 63 80  or  %g1, 0x380, %g1
a0158d44:  da 24 a0 04  st  %o5, [ %l2 + 4 ]
a0158d48:  c2 24 80 00  st  %g1, [ %l2 ]
a0158d4c:  d8 07 bf e4  ld  [ %fp + -28 ], %o4
a0158d50:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0158d54:  98 03 20 01  inc  %o4
a0158d58:  82 00 60 01  inc  %g1
a0158d5c:  da 07 b9 08  ld  [ %fp + -1784 ], %o5
a0158d60:  a6 04 c0 0d  add  %l3, %o5, %l3
a0158d64:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0158d68:  80 a3 20 07  cmp  %o4, 7
a0158d6c:  a4 04 a0 08  add  %l2, 8, %l2
a0158d70:  14 80 01 54  bg  0xa01592c0
a0158d74:  d8 27 bf e4  st  %o4, [ %fp + -28 ]
a0158d78:  c2 07 b9 08  ld  [ %fp + -1784 ], %g1
a0158d7c:  d8 07 b9 04  ld  [ %fp + -1788 ], %o4
a0158d80:  98 23 00 01  sub  %o4, %g1, %o4
a0158d84:  d8 24 a0 04  st  %o4, [ %l2 + 4 ]
a0158d88:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0158d8c:  e6 24 80 00  st  %l3, [ %l2 ]
a0158d90:  10 bf fc b5  b  0xa0158064
a0158d94:  82 00 40 0c  add  %g1, %o4, %g1
a0158d98:  02 80 01 3a  be  0xa0159280
a0158d9c:  da 06 c0 00  ld  [ %i3 ], %o5
a0158da0:  d2 07 b8 f0  ld  [ %fp + -1808 ], %o1
a0158da4:  d2 33 40 00  sth  %o1, [ %o5 ]
a0158da8:  10 bf fb 58  b  0xa0157b08
a0158dac:  b6 06 e0 04  add  %i3, 4, %i3
a0158db0:  da 06 c0 00  ld  [ %i3 ], %o5
a0158db4:  da 27 b9 40  st  %o5, [ %fp + -1728 ]
a0158db8:  d8 27 b9 44  st  %o4, [ %fp + -1724 ]
a0158dbc:  d8 1f b9 40  ldd  [ %fp + -1728 ], %o4
a0158dc0:  d8 3f b8 e0  std  %o4, [ %fp + -1824 ]
a0158dc4:  40 00 14 44  call  0xa015ded4
a0158dc8:  d0 1f b8 e0  ldd  [ %fp + -1824 ], %o0
a0158dcc:  80 a2 20 00  cmp  %o0, 0
a0158dd0:  12 bf fe 09  bne  0xa01585f4
a0158dd4:  b6 06 e0 08  add  %i3, 8, %i3
a0158dd8:  7f ff f0 a7  call  0xa0155074
a0158ddc:  d0 1f b8 e0  ldd  [ %fp + -1824 ], %o0
a0158de0:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a0158de4:  80 a2 20 00  cmp  %o0, 0
a0158de8:  a6 10 60 68  or  %g1, 0x68, %l3
a0158dec:  12 bf fc 14  bne  0xa0157e3c
a0158df0:  a8 10 20 03  mov  3, %l4
a0158df4:  d0 1f b8 e0  ldd  [ %fp + -1824 ], %o0
a0158df8:  ba 17 61 00  or  %i5, 0x100, %i5
a0158dfc:  80 a5 60 66  cmp  %l5, 0x66
a0158e00:  d0 3f b8 c8  std  %o0, [ %fp + -1848 ]
a0158e04:  a2 10 00 16  mov  %l6, %l1
a0158e08:  94 07 b9 0f  add  %fp, -1777, %o2
a0158e0c:  a8 07 b9 08  add  %fp, -1784, %l4
a0158e10:  02 80 00 0c  be  0xa0158e40
a0158e14:  96 10 20 03  mov  3, %o3
a0158e18:  82 1d 60 65  xor  %l5, 0x65, %g1
a0158e1c:  80 a0 00 01  cmp  %g0, %g1
a0158e20:  98 60 3f ff  subx  %g0, -1, %o4
a0158e24:  82 1d 60 45  xor  %l5, 0x45, %g1
a0158e28:  80 a0 00 01  cmp  %g0, %g1
a0158e2c:  9a 60 3f ff  subx  %g0, -1, %o5
a0158e30:  80 93 00 0d  orcc  %o4, %o5, %g0
a0158e34:  32 80 00 02  bne,a   0xa0158e3c
a0158e38:  a2 05 a0 01  add  %l6, 1, %l1
a0158e3c:  96 10 20 02  mov  2, %o3
a0158e40:  d8 1f b8 c8  ldd  [ %fp + -1848 ], %o4
a0158e44:  80 a3 20 00  cmp  %o4, 0
a0158e48:  06 80 01 93  bl  0xa0159494
a0158e4c:  82 10 20 2d  mov  0x2d, %g1
a0158e50:  c0 2a 80 00  clrb  [ %o2 ]
a0158e54:  9a 07 b8 fc  add  %fp, -1796, %o5
a0158e58:  82 07 b9 00  add  %fp, -1792, %g1
a0158e5c:  da 23 a0 60  st  %o5, [ %sp + 0x60 ]
a0158e60:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a0158e64:  d2 07 b8 c8  ld  [ %fp + -1848 ], %o1
a0158e68:  9a 10 00 14  mov  %l4, %o5
a0158e6c:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a0158e70:  d4 07 b8 cc  ld  [ %fp + -1844 ], %o2
a0158e74:  40 00 04 71  call  0xa015a038
a0158e78:  98 10 00 11  mov  %l1, %o4
a0158e7c:  92 1d 60 67  xor  %l5, 0x67, %o1
a0158e80:  80 a0 00 09  cmp  %g0, %o1
a0158e84:  9a 40 20 00  addx  %g0, 0, %o5
a0158e88:  ae 1d 60 47  xor  %l5, 0x47, %l7
a0158e8c:  80 a0 00 17  cmp  %g0, %l7
a0158e90:  82 40 20 00  addx  %g0, 0, %g1
a0158e94:  a6 10 00 08  mov  %o0, %l3
a0158e98:  80 8b 40 01  btst  %o5, %g1
a0158e9c:  12 80 00 05  bne  0xa0158eb0
a0158ea0:  d2 27 b8 c4  st  %o1, [ %fp + -1852 ]
a0158ea4:  80 8f 60 01  btst  1, %i5
a0158ea8:  02 80 00 16  be  0xa0158f00
a0158eac:  da 07 b8 fc  ld  [ %fp + -1796 ], %o5
a0158eb0:  80 a5 60 66  cmp  %l5, 0x66
a0158eb4:  02 80 01 8d  be  0xa01594e8
a0158eb8:  a0 04 c0 11  add  %l3, %l1, %l0
a0158ebc:  1b 00 06 a0  sethi  %hi(0x1a8000), %o5
a0158ec0:  d0 1f b8 c8  ldd  [ %fp + -1848 ], %o0
a0158ec4:  7f ff f5 fb  call  0xa01566b0
a0158ec8:  d4 1b 62 08  ldd  [ %o5 + 0x208 ], %o2
a0158ecc:  80 a2 20 00  cmp  %o0, 0
a0158ed0:  12 80 00 04  bne  0xa0158ee0
a0158ed4:  da 07 b8 fc  ld  [ %fp + -1796 ], %o5
a0158ed8:  9a 10 00 10  mov  %l0, %o5
a0158edc:  e0 27 b8 fc  st  %l0, [ %fp + -1796 ]
a0158ee0:  80 a3 40 10  cmp  %o5, %l0
a0158ee4:  1a 80 00 07  bcc  0xa0158f00
a0158ee8:  82 10 20 30  mov  0x30, %g1
a0158eec:  c2 2b 40 00  stb  %g1, [ %o5 ]
a0158ef0:  9a 03 60 01  inc  %o5
a0158ef4:  80 a3 40 10  cmp  %o5, %l0
a0158ef8:  0a bf ff fd  bcs  0xa0158eec
a0158efc:  da 27 b8 fc  st  %o5, [ %fp + -1796 ]
a0158f00:  c2 07 b8 c4  ld  [ %fp + -1852 ], %g1
a0158f04:  80 a0 00 01  cmp  %g0, %g1
a0158f08:  82 60 3f ff  subx  %g0, -1, %g1
a0158f0c:  80 a0 00 17  cmp  %g0, %l7
a0158f10:  9a 23 40 13  sub  %o5, %l3, %o5
a0158f14:  98 60 3f ff  subx  %g0, -1, %o4
a0158f18:  80 90 40 0c  orcc  %g1, %o4, %g0
a0158f1c:  02 80 01 36  be  0xa01593f4
a0158f20:  da 27 b9 04  st  %o5, [ %fp + -1788 ]
a0158f24:  d0 07 b9 08  ld  [ %fp + -1784 ], %o0
a0158f28:  80 a2 3f fc  cmp  %o0, -4
a0158f2c:  04 80 00 06  ble  0xa0158f44
a0158f30:  9a 1d 60 67  xor  %l5, 0x67, %o5
a0158f34:  80 a2 00 16  cmp  %o0, %l6
a0158f38:  24 80 01 0e  ble,a   0xa0159370
a0158f3c:  aa 10 20 67  mov  0x67, %l5
a0158f40:  9a 1d 60 67  xor  %l5, 0x67, %o5
a0158f44:  80 a0 00 0d  cmp  %g0, %o5
a0158f48:  82 60 20 00  subx  %g0, 0, %g1
a0158f4c:  82 08 7f e0  and  %g1, -32, %g1
a0158f50:  aa 00 60 65  add  %g1, 0x65, %l5
a0158f54:  80 a5 60 65  cmp  %l5, 0x65
a0158f58:  14 80 01 04  bg  0xa0159368
a0158f5c:  80 a5 60 66  cmp  %l5, 0x66
a0158f60:  90 02 3f ff  add  %o0, -1, %o0
a0158f64:  d0 27 b9 08  st  %o0, [ %fp + -1784 ]
a0158f68:  ea 2f bf f0  stb  %l5, [ %fp + -16 ]
a0158f6c:  80 a2 20 00  cmp  %o0, 0
a0158f70:  06 80 01 7f  bl  0xa015956c
a0158f74:  a0 10 00 08  mov  %o0, %l0
a0158f78:  82 10 20 2b  mov  0x2b, %g1
a0158f7c:  c2 2f bf f1  stb  %g1, [ %fp + -15 ]
a0158f80:  ac 07 b9 40  add  %fp, -1728, %l6
a0158f84:  a8 07 bf f2  add  %fp, -14, %l4
a0158f88:  80 a4 20 09  cmp  %l0, 9
a0158f8c:  04 80 01 3b  ble  0xa0159478
a0158f90:  a2 10 00 16  mov  %l6, %l1
a0158f94:  90 10 00 10  mov  %l0, %o0
a0158f98:  40 00 15 4d  call  0xa015e4cc
a0158f9c:  92 10 20 0a  mov  0xa, %o1
a0158fa0:  90 02 20 30  add  %o0, 0x30, %o0
a0158fa4:  a2 04 7f ff  add  %l1, -1, %l1
a0158fa8:  d0 2c 40 00  stb  %o0, [ %l1 ]
a0158fac:  90 10 00 10  mov  %l0, %o0
a0158fb0:  7f ff f6 b1  call  0xa0156a74
a0158fb4:  92 10 20 0a  mov  0xa, %o1
a0158fb8:  80 a2 20 09  cmp  %o0, 9
a0158fbc:  14 bf ff f6  bg  0xa0158f94
a0158fc0:  a0 10 00 08  mov  %o0, %l0
a0158fc4:  a2 04 7f ff  add  %l1, -1, %l1
a0158fc8:  82 02 20 30  add  %o0, 0x30, %g1
a0158fcc:  10 80 00 05  b  0xa0158fe0
a0158fd0:  c2 2c 40 00  stb  %g1, [ %l1 ]
a0158fd4:  c2 2d 00 00  stb  %g1, [ %l4 ]
a0158fd8:  a2 04 60 01  inc  %l1
a0158fdc:  a8 05 20 01  inc  %l4
a0158fe0:  80 a5 80 11  cmp  %l6, %l1
a0158fe4:  38 bf ff fc  bgu,a   0xa0158fd4
a0158fe8:  c2 0c 40 00  ldub  [ %l1 ], %g1
a0158fec:  82 07 bf f0  add  %fp, -16, %g1
a0158ff0:  a8 25 00 01  sub  %l4, %g1, %l4
a0158ff4:  da 07 b9 04  ld  [ %fp + -1788 ], %o5
a0158ff8:  e8 27 b8 dc  st  %l4, [ %fp + -1828 ]
a0158ffc:  80 a3 60 01  cmp  %o5, 1
a0159000:  04 80 00 e1  ble  0xa0159384
a0159004:  a8 05 00 0d  add  %l4, %o5, %l4
a0159008:  a8 05 20 01  inc  %l4
a015900c:  c2 4f b9 0f  ldsb  [ %fp + -1777 ], %g1
a0159010:  80 a0 60 00  cmp  %g1, 0
a0159014:  02 bf fb 8b  be  0xa0157e40
a0159018:  80 a5 00 18  cmp  %l4, %i0
a015901c:  82 10 20 2d  mov  0x2d, %g1
a0159020:  10 bf fb 88  b  0xa0157e40
a0159024:  c2 2f b8 f7  stb  %g1, [ %fp + -1801 ]
a0159028:  90 10 00 19  mov  %i1, %o0
a015902c:  7f ff fa 7d  call  0xa0157a20
a0159030:  92 07 bf e0  add  %fp, -32, %o1
a0159034:  80 a2 20 00  cmp  %o0, 0
a0159038:  12 bf fe 57  bne  0xa0158994
a015903c:  a4 10 00 1c  mov  %i4, %l2
a0159040:  10 bf fd f1  b  0xa0158804
a0159044:  da 07 b9 08  ld  [ %fp + -1784 ], %o5
a0159048:  da 2f be 40  stb  %o5, [ %fp + -448 ]
a015904c:  b6 06 e0 04  add  %i3, 4, %i3
a0159050:  a8 10 20 01  mov  1, %l4
a0159054:  10 bf fb 7a  b  0xa0157e3c
a0159058:  c0 2f b8 f7  clrb  [ %fp + -1801 ]
a015905c:  82 15 e3 f8  or  %l7, 0x3f8, %g1
a0159060:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a0159064:  c2 24 80 00  st  %g1, [ %l2 ]
a0159068:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a015906c:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a0159070:  82 00 60 01  inc  %g1
a0159074:  9a 03 40 10  add  %o5, %l0, %o5
a0159078:  da 27 bf e8  st  %o5, [ %fp + -24 ]
a015907c:  80 a0 60 07  cmp  %g1, 7
a0159080:  a4 04 a0 08  add  %l2, 8, %l2
a0159084:  14 80 00 c5  bg  0xa0159398
a0159088:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a015908c:  80 8f 60 01  btst  1, %i5
a0159090:  02 bf fb fe  be  0xa0158088
a0159094:  80 8f 60 04  btst  4, %i5
a0159098:  03 00 06 62  sethi  %hi(0x198800), %g1
a015909c:  9a 10 20 01  mov  1, %o5
a01590a0:  82 10 63 80  or  %g1, 0x380, %g1
a01590a4:  da 24 a0 04  st  %o5, [ %l2 + 4 ]
a01590a8:  c2 24 80 00  st  %g1, [ %l2 ]
a01590ac:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a01590b0:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a01590b4:  9a 03 60 01  inc  %o5
a01590b8:  10 bf fb ed  b  0xa015806c
a01590bc:  82 00 60 01  inc  %g1
a01590c0:  82 15 e3 f8  or  %l7, 0x3f8, %g1
a01590c4:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a01590c8:  c2 24 80 00  st  %g1, [ %l2 ]
a01590cc:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a01590d0:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a01590d4:  9a 03 40 10  add  %o5, %l0, %o5
a01590d8:  10 bf fe 63  b  0xa0158a64
a01590dc:  82 00 60 01  inc  %g1
a01590e0:  06 bf fb 54  bl  0xa0157e30
a01590e4:  90 10 00 13  mov  %l3, %o0
a01590e8:  92 10 20 00  clr  %o1
a01590ec:  40 00 0e 59  call  0xa015ca50
a01590f0:  94 10 00 16  mov  %l6, %o2
a01590f4:  80 a2 20 00  cmp  %o0, 0
a01590f8:  02 bf fb 51  be  0xa0157e3c
a01590fc:  a8 10 00 16  mov  %l6, %l4
a0159100:  a8 22 00 13  sub  %o0, %l3, %l4
a0159104:  80 a5 00 16  cmp  %l4, %l6
a0159108:  34 bf fb 4d  bg,a   0xa0157e3c
a015910c:  a8 10 00 16  mov  %l6, %l4
a0159110:  10 bf fb 4c  b  0xa0157e40
a0159114:  80 a5 00 18  cmp  %l4, %i0
a0159118:  90 10 00 19  mov  %i1, %o0
a015911c:  7f ff fa 41  call  0xa0157a20
a0159120:  92 07 bf e0  add  %fp, -32, %o1
a0159124:  80 a2 20 00  cmp  %o0, 0
a0159128:  12 bf fe 1b  bne  0xa0158994
a015912c:  a4 10 00 1c  mov  %i4, %l2
a0159130:  10 bf fd c9  b  0xa0158854
a0159134:  c2 07 b9 04  ld  [ %fp + -1788 ], %g1
a0159138:  82 15 e3 f8  or  %l7, 0x3f8, %g1
a015913c:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a0159140:  c2 24 80 00  st  %g1, [ %l2 ]
a0159144:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a0159148:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a015914c:  82 00 60 01  inc  %g1
a0159150:  9a 03 40 10  add  %o5, %l0, %o5
a0159154:  da 27 bf e8  st  %o5, [ %fp + -24 ]
a0159158:  80 a0 60 07  cmp  %g1, 7
a015915c:  a4 04 a0 08  add  %l2, 8, %l2
a0159160:  10 bf fd e9  b  0xa0158904
a0159164:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a0159168:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015916c:  82 10 60 60  or  %g1, 0x60, %g1	! 0x1a8460
a0159170:  a0 10 20 01  mov  1, %l0
a0159174:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a0159178:  c2 24 80 00  st  %g1, [ %l2 ]
a015917c:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a0159180:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0159184:  9a 03 60 01  inc  %o5
a0159188:  82 00 60 01  inc  %g1
a015918c:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0159190:  80 a3 60 07  cmp  %o5, 7
a0159194:  a4 04 a0 08  add  %l2, 8, %l2
a0159198:  14 80 00 88  bg  0xa01593b8
a015919c:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a01591a0:  c2 07 b9 08  ld  [ %fp + -1784 ], %g1
a01591a4:  80 a0 60 00  cmp  %g1, 0
a01591a8:  32 80 00 07  bne,a   0xa01591c4
a01591ac:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a01591b0:  c2 07 b9 04  ld  [ %fp + -1788 ], %g1
a01591b4:  80 a0 60 00  cmp  %g1, 0
a01591b8:  02 bf fb b4  be  0xa0158088
a01591bc:  80 8f 60 04  btst  4, %i5
a01591c0:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a01591c4:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a01591c8:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a01591cc:  d2 07 b8 e8  ld  [ %fp + -1816 ], %o1
a01591d0:  9a 03 60 01  inc  %o5
a01591d4:  d2 24 80 00  st  %o1, [ %l2 ]
a01591d8:  82 00 60 01  inc  %g1
a01591dc:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a01591e0:  80 a3 60 07  cmp  %o5, 7
a01591e4:  a4 04 a0 08  add  %l2, 8, %l2
a01591e8:  14 80 00 85  bg  0xa01593fc
a01591ec:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a01591f0:  c2 07 b9 08  ld  [ %fp + -1784 ], %g1
a01591f4:  a0 20 00 01  neg  %g1, %l0
a01591f8:  80 a4 20 00  cmp  %l0, 0
a01591fc:  04 80 00 50  ble  0xa015933c
a0159200:  c2 07 b9 04  ld  [ %fp + -1788 ], %g1
a0159204:  80 a4 20 10  cmp  %l0, 0x10
a0159208:  04 80 00 40  ble  0xa0159308
a015920c:  2f 00 06 a0  sethi  %hi(0x1a8000), %l7
a0159210:  10 80 00 06  b  0xa0159228
a0159214:  a2 15 e3 f8  or  %l7, 0x3f8, %l1	! 0x1a83f8
a0159218:  a0 04 3f f0  add  %l0, -16, %l0
a015921c:  80 a4 20 10  cmp  %l0, 0x10
a0159220:  04 80 00 3b  ble  0xa015930c
a0159224:  82 15 e3 f8  or  %l7, 0x3f8, %g1
a0159228:  82 10 20 10  mov  0x10, %g1
a015922c:  c2 24 a0 04  st  %g1, [ %l2 + 4 ]
a0159230:  da 07 bf e4  ld  [ %fp + -28 ], %o5
a0159234:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0159238:  9a 03 60 01  inc  %o5
a015923c:  e2 24 80 00  st  %l1, [ %l2 ]
a0159240:  82 00 60 10  add  %g1, 0x10, %g1
a0159244:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0159248:  80 a3 60 07  cmp  %o5, 7
a015924c:  a4 04 a0 08  add  %l2, 8, %l2
a0159250:  04 bf ff f2  ble  0xa0159218
a0159254:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a0159258:  90 10 00 19  mov  %i1, %o0
a015925c:  7f ff f9 f1  call  0xa0157a20
a0159260:  92 07 bf e0  add  %fp, -32, %o1
a0159264:  80 a2 20 00  cmp  %o0, 0
a0159268:  12 bf fd cb  bne  0xa0158994
a015926c:  a4 10 00 1c  mov  %i4, %l2
a0159270:  10 bf ff eb  b  0xa015921c
a0159274:  a0 04 3f f0  add  %l0, -16, %l0
a0159278:  10 bf fc d2  b  0xa01585c0
a015927c:  ac 10 20 06  mov  6, %l6
a0159280:  d6 07 b8 f0  ld  [ %fp + -1808 ], %o3
a0159284:  d6 23 40 00  st  %o3, [ %o5 ]
a0159288:  10 bf fa 20  b  0xa0157b08
a015928c:  b6 06 e0 04  add  %i3, 4, %i3
a0159290:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a0159294:  a6 10 60 70  or  %g1, 0x70, %l3	! 0x1a8470
a0159298:  10 bf fa e9  b  0xa0157e3c
a015929c:  a8 10 20 06  mov  6, %l4
a01592a0:  90 10 00 19  mov  %i1, %o0
a01592a4:  7f ff f9 df  call  0xa0157a20
a01592a8:  92 07 bf e0  add  %fp, -32, %o1
a01592ac:  80 a2 20 00  cmp  %o0, 0
a01592b0:  12 bf fd b9  bne  0xa0158994
a01592b4:  a4 10 00 1c  mov  %i4, %l2
a01592b8:  10 bf fe 18  b  0xa0158b18
a01592bc:  da 07 b9 08  ld  [ %fp + -1784 ], %o5
a01592c0:  90 10 00 19  mov  %i1, %o0
a01592c4:  7f ff f9 d7  call  0xa0157a20
a01592c8:  92 07 bf e0  add  %fp, -32, %o1
a01592cc:  80 a2 20 00  cmp  %o0, 0
a01592d0:  12 bf fd b1  bne  0xa0158994
a01592d4:  a4 10 00 1c  mov  %i4, %l2
a01592d8:  10 bf fe a9  b  0xa0158d7c
a01592dc:  c2 07 b9 08  ld  [ %fp + -1784 ], %g1
a01592e0:  90 10 00 19  mov  %i1, %o0
a01592e4:  7f ff f9 cf  call  0xa0157a20
a01592e8:  92 07 bf e0  add  %fp, -32, %o1
a01592ec:  80 a2 20 00  cmp  %o0, 0
a01592f0:  12 bf fd a9  bne  0xa0158994
a01592f4:  a4 10 00 1c  mov  %i4, %l2
a01592f8:  10 bf fe 91  b  0xa0158d3c
a01592fc:  03 00 06 62  sethi  %hi(0x198800), %g1
a0159300:  10 bf fc c4  b  0xa0158610
a0159304:  c2 2f b8 f7  stb  %g1, [ %fp + -1801 ]
a0159308:  82 15 e3 f8  or  %l7, 0x3f8, %g1
a015930c:  e0 24 a0 04  st  %l0, [ %l2 + 4 ]
a0159310:  c2 24 80 00  st  %g1, [ %l2 ]
a0159314:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a0159318:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a015931c:  82 00 60 01  inc  %g1
a0159320:  9a 03 40 10  add  %o5, %l0, %o5
a0159324:  da 27 bf e8  st  %o5, [ %fp + -24 ]
a0159328:  80 a0 60 07  cmp  %g1, 7
a015932c:  a4 04 a0 08  add  %l2, 8, %l2
a0159330:  14 80 00 3f  bg  0xa015942c
a0159334:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a0159338:  c2 07 b9 04  ld  [ %fp + -1788 ], %g1
a015933c:  c2 24 a0 04  st  %g1, [ %l2 + 4 ]
a0159340:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a0159344:  d8 07 bf e4  ld  [ %fp + -28 ], %o4
a0159348:  98 03 20 01  inc  %o4
a015934c:  e6 24 80 00  st  %l3, [ %l2 ]
a0159350:  9a 03 40 01  add  %o5, %g1, %o5
a0159354:  da 27 bf e8  st  %o5, [ %fp + -24 ]
a0159358:  80 a3 20 07  cmp  %o4, 7
a015935c:  a4 04 a0 08  add  %l2, 8, %l2
a0159360:  10 bf fb 47  b  0xa015807c
a0159364:  d8 27 bf e4  st  %o4, [ %fp + -28 ]
a0159368:  02 80 00 77  be  0xa0159544
a015936c:  80 a2 20 00  cmp  %o0, 0
a0159370:  da 07 b9 04  ld  [ %fp + -1788 ], %o5
a0159374:  80 a2 00 0d  cmp  %o0, %o5
a0159378:  06 80 00 6e  bl  0xa0159530
a015937c:  82 23 40 08  sub  %o5, %o0, %g1
a0159380:  a8 10 00 08  mov  %o0, %l4
a0159384:  80 8f 60 01  btst  1, %i5
a0159388:  02 bf ff 22  be  0xa0159010
a015938c:  c2 4f b9 0f  ldsb  [ %fp + -1777 ], %g1
a0159390:  10 bf ff 20  b  0xa0159010
a0159394:  a8 05 20 01  inc  %l4
a0159398:  90 10 00 19  mov  %i1, %o0
a015939c:  7f ff f9 a1  call  0xa0157a20
a01593a0:  92 07 bf e0  add  %fp, -32, %o1
a01593a4:  80 a2 20 00  cmp  %o0, 0
a01593a8:  12 bf fd 7b  bne  0xa0158994
a01593ac:  a4 10 00 1c  mov  %i4, %l2
a01593b0:  10 bf ff 38  b  0xa0159090
a01593b4:  80 8f 60 01  btst  1, %i5
a01593b8:  90 10 00 19  mov  %i1, %o0
a01593bc:  7f ff f9 99  call  0xa0157a20
a01593c0:  92 07 bf e0  add  %fp, -32, %o1
a01593c4:  80 a2 20 00  cmp  %o0, 0
a01593c8:  12 bf fd 73  bne  0xa0158994
a01593cc:  a4 10 00 1c  mov  %i4, %l2
a01593d0:  10 bf ff 75  b  0xa01591a4
a01593d4:  c2 07 b9 08  ld  [ %fp + -1784 ], %g1
a01593d8:  80 88 62 00  btst  0x200, %g1
a01593dc:  32 80 00 79  bne,a   0xa01595c0
a01593e0:  90 10 3f ff  mov  -1, %o0
a01593e4:  40 00 15 a1  call  0xa015ea68
a01593e8:  90 06 60 58  add  %i1, 0x58, %o0
a01593ec:  10 80 00 75  b  0xa01595c0
a01593f0:  90 10 3f ff  mov  -1, %o0
a01593f4:  10 bf fe d8  b  0xa0158f54
a01593f8:  d0 07 b9 08  ld  [ %fp + -1784 ], %o0
a01593fc:  90 10 00 19  mov  %i1, %o0
a0159400:  7f ff f9 88  call  0xa0157a20
a0159404:  92 07 bf e0  add  %fp, -32, %o1
a0159408:  80 a2 20 00  cmp  %o0, 0
a015940c:  12 bf fd 62  bne  0xa0158994
a0159410:  a4 10 00 1c  mov  %i4, %l2
a0159414:  10 bf ff 78  b  0xa01591f4
a0159418:  c2 07 b9 08  ld  [ %fp + -1784 ], %g1
a015941c:  c2 16 60 0c  lduh  [ %i1 + 0xc ], %g1
a0159420:  82 10 60 40  or  %g1, 0x40, %g1
a0159424:  10 bf fd 5c  b  0xa0158994
a0159428:  c2 36 60 0c  sth  %g1, [ %i1 + 0xc ]
a015942c:  90 10 00 19  mov  %i1, %o0
a0159430:  7f ff f9 7c  call  0xa0157a20
a0159434:  92 07 bf e0  add  %fp, -32, %o1
a0159438:  80 a2 20 00  cmp  %o0, 0
a015943c:  12 bf fd 56  bne  0xa0158994
a0159440:  a4 10 00 1c  mov  %i4, %l2
a0159444:  10 bf ff be  b  0xa015933c
a0159448:  c2 07 b9 04  ld  [ %fp + -1788 ], %g1
a015944c:  d0 07 a0 44  ld  [ %fp + 0x44 ], %o0
a0159450:  92 10 20 00  clr  %o1
a0159454:  94 07 b8 f8  add  %fp, -1800, %o2
a0159458:  96 10 20 00  clr  %o3
a015945c:  40 00 00 b6  call  0xa0159734
a0159460:  98 10 00 17  mov  %l7, %o4
a0159464:  80 a2 3f ff  cmp  %o0, -1
a0159468:  02 bf ff ed  be  0xa015941c
a015946c:  a8 10 00 08  mov  %o0, %l4
a0159470:  10 bf fb f9  b  0xa0158454
a0159474:  e6 27 b8 f8  st  %l3, [ %fp + -1800 ]
a0159478:  82 10 20 30  mov  0x30, %g1
a015947c:  c2 2d 00 00  stb  %g1, [ %l4 ]
a0159480:  a8 05 20 01  inc  %l4
a0159484:  82 04 20 30  add  %l0, 0x30, %g1
a0159488:  c2 2d 00 00  stb  %g1, [ %l4 ]
a015948c:  10 bf fe d8  b  0xa0158fec
a0159490:  a8 05 20 01  inc  %l4
a0159494:  c2 2a 80 00  stb  %g1, [ %o2 ]
a0159498:  d0 1f b8 c8  ldd  [ %fp + -1848 ], %o0
a015949c:  19 20 00 00  sethi  %hi(0x80000000), %o4
a01594a0:  9a 10 20 00  clr  %o5
a01594a4:  90 1b 00 08  xor  %o4, %o0, %o0
a01594a8:  92 1b 40 09  xor  %o5, %o1, %o1
a01594ac:  10 bf fe 6a  b  0xa0158e54
a01594b0:  d0 3f b8 c8  std  %o0, [ %fp + -1848 ]
a01594b4:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a01594b8:  80 a0 60 00  cmp  %g1, 0
a01594bc:  12 80 00 04  bne  0xa01594cc
a01594c0:  90 10 00 19  mov  %i1, %o0
a01594c4:  10 bf fd 34  b  0xa0158994
a01594c8:  c0 27 bf e4  clr  [ %fp + -28 ]
a01594cc:  7f ff f9 55  call  0xa0157a20
a01594d0:  92 07 bf e0  add  %fp, -32, %o1
a01594d4:  80 a2 20 00  cmp  %o0, 0
a01594d8:  22 bf fd 2f  be,a   0xa0158994
a01594dc:  c0 27 bf e4  clr  [ %fp + -28 ]
a01594e0:  10 bf fd 2e  b  0xa0158998
a01594e4:  da 07 b8 d4  ld  [ %fp + -1836 ], %o5
a01594e8:  c2 4c c0 00  ldsb  [ %l3 ], %g1
a01594ec:  80 a0 60 30  cmp  %g1, 0x30
a01594f0:  02 80 00 05  be  0xa0159504
a01594f4:  19 00 06 a0  sethi  %hi(0x1a8000), %o4
a01594f8:  c2 05 00 00  ld  [ %l4 ], %g1
a01594fc:  10 bf fe 70  b  0xa0158ebc
a0159500:  a0 04 00 01  add  %l0, %g1, %l0
a0159504:  d0 1f b8 c8  ldd  [ %fp + -1848 ], %o0
a0159508:  7f ff f4 83  call  0xa0156714
a015950c:  d4 1b 22 08  ldd  [ %o4 + 0x208 ], %o2
a0159510:  80 a2 20 00  cmp  %o0, 0
a0159514:  22 bf ff fa  be,a   0xa01594fc
a0159518:  c2 05 00 00  ld  [ %l4 ], %g1
a015951c:  82 10 20 01  mov  1, %g1
a0159520:  82 20 40 11  sub  %g1, %l1, %g1
a0159524:  c2 25 00 00  st  %g1, [ %l4 ]
a0159528:  10 bf fe 65  b  0xa0158ebc
a015952c:  a0 04 00 01  add  %l0, %g1, %l0
a0159530:  80 a2 20 00  cmp  %o0, 0
a0159534:  04 bf fe b6  ble  0xa015900c
a0159538:  a8 00 60 02  add  %g1, 2, %l4
a015953c:  10 bf fe b4  b  0xa015900c
a0159540:  a8 03 60 01  add  %o5, 1, %l4
a0159544:  04 80 00 0e  ble  0xa015957c
a0159548:  80 a5 a0 00  cmp  %l6, 0
a015954c:  12 80 00 05  bne  0xa0159560
a0159550:  a8 10 00 08  mov  %o0, %l4
a0159554:  80 8f 60 01  btst  1, %i5
a0159558:  02 bf fe ae  be  0xa0159010
a015955c:  c2 4f b9 0f  ldsb  [ %fp + -1777 ], %g1
a0159560:  82 05 80 14  add  %l6, %l4, %g1
a0159564:  10 bf fe aa  b  0xa015900c
a0159568:  a8 00 60 01  add  %g1, 1, %l4
a015956c:  82 10 20 2d  mov  0x2d, %g1
a0159570:  c2 2f bf f1  stb  %g1, [ %fp + -15 ]
a0159574:  10 bf fe 83  b  0xa0158f80
a0159578:  a0 20 00 08  neg  %o0, %l0
a015957c:  12 bf fe a4  bne  0xa015900c
a0159580:  a8 05 a0 02  add  %l6, 2, %l4
a0159584:  80 8f 60 01  btst  1, %i5
a0159588:  02 bf fe a1  be  0xa015900c
a015958c:  a8 10 20 01  mov  1, %l4
a0159590:  10 bf fe 9f  b  0xa015900c
a0159594:  a8 05 a0 02  add  %l6, 2, %l4
a0159598:  c2 16 60 0c  lduh  [ %i1 + 0xc ], %g1
a015959c:  82 10 60 40  or  %g1, 0x40, %g1
a01595a0:  10 bf fd 03  b  0xa01589ac
a01595a4:  c2 36 60 0c  sth  %g1, [ %i1 + 0xc ]
a01595a8:  ec 06 c0 00  ld  [ %i3 ], %l6
a01595ac:  80 a5 a0 00  cmp  %l6, 0
a01595b0:  16 bf f9 85  bge  0xa0157bc4
a01595b4:  b6 06 e0 04  add  %i3, 4, %i3
a01595b8:  10 bf f9 83  b  0xa0157bc4
a01595bc:  ac 10 3f ff  mov  -1, %l6
a01595c0:  81 c7 e0 08  ret
a01595c4:  91 e8 00 08  restore  %g0, %o0, %o0
