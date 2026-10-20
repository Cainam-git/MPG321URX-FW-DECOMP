# leon2m FUN_a01199ac 0xa01199ac-0xa011a060 (1716 bytes)
a01199ac:  9d e3 bf 98  save  %sp, -104, %sp
a01199b0:  a4 0f 20 ff  and  %i4, 0xff, %l2
a01199b4:  1f 2a 00 9e  sethi  %hi(0xa8027800), %o7
a01199b8:  a0 04 80 12  add  %l2, %l2, %l0
a01199bc:  9a 13 e2 a8  or  %o7, 0x2a8, %o5
a01199c0:  d0 13 40 10  lduh  [ %o5 + %l0 ], %o0
a01199c4:  ad 2a 20 02  sll  %o0, 2, %l6
a01199c8:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a01199cc:  a6 15 80 01  or  %l6, %g1, %l3
a01199d0:  ea 04 c0 00  ld  [ %l3 ], %l5
a01199d4:  a8 0d 60 7f  and  %l5, 0x7f, %l4
a01199d8:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a01199dc:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a01199e0:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a01199e4:  11 2a 00 b2  sethi  %hi(0xa802c800), %o0
a01199e8:  e8 24 c0 00  st  %l4, [ %l3 ]
a01199ec:  a2 12 61 ca  or  %o1, 0x1ca, %l1
a01199f0:  96 13 21 c0  or  %o4, 0x1c0, %o3
a01199f4:  9a 12 a1 b8  or  %o2, 0x1b8, %o5
a01199f8:  82 12 21 c8  or  %o0, 0x1c8, %g1
a01199fc:  d2 14 40 10  lduh  [ %l1 + %l0 ], %o1
a0119a00:  ac 10 00 0f  mov  %o7, %l6
a0119a04:  e8 0a c0 12  ldub  [ %o3 + %l2 ], %l4
a0119a08:  e6 0b 40 12  ldub  [ %o5 + %l2 ], %l3
a0119a0c:  80 a4 a0 00  cmp  %l2, 0
a0119a10:  12 80 00 8e  bne  0xa0119c48
a0119a14:  ea 08 40 12  ldub  [ %g1 + %l2 ], %l5
a0119a18:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a0119a1c:  d6 0b 21 b0  ldub  [ %o4 + 0x1b0 ], %o3	! 0xa802c9b0
a0119a20:  94 0a e0 0c  and  %o3, 0xc, %o2
a0119a24:  83 3a a0 02  sra  %o2, 2, %g1
a0119a28:  80 a0 60 02  cmp  %g1, 2
a0119a2c:  22 80 00 8f  be,a   0xa0119c68
a0119a30:  93 2a 60 10  sll  %o1, 0x10, %o1
a0119a34:  80 a0 60 02  cmp  %g1, 2
a0119a38:  04 80 00 ca  ble  0xa0119d60
a0119a3c:  80 a0 60 01  cmp  %g1, 1
a0119a40:  80 a0 60 03  cmp  %g1, 3
a0119a44:  02 80 01 3e  be  0xa0119f3c
a0119a48:  a3 2e a0 10  sll  %i2, 0x10, %l1
a0119a4c:  93 2a 60 10  sll  %o1, 0x10, %o1
a0119a50:  91 2e a0 10  sll  %i2, 0x10, %o0
a0119a54:  9e 0d 20 ff  and  %l4, 0xff, %o7
a0119a58:  95 32 60 10  srl  %o1, 0x10, %o2
a0119a5c:  9a 5b c0 0a  smul  %o7, %o2, %o5
a0119a60:  99 32 20 10  srl  %o0, 0x10, %o4
a0119a64:  80 a3 00 0d  cmp  %o4, %o5
a0119a68:  06 80 00 0b  bl  0xa0119a94
a0119a6c:  b4 10 20 00  clr  %i2
a0119a70:  a9 2e 20 10  sll  %i0, 0x10, %l4
a0119a74:  96 23 00 0d  sub  %o4, %o5, %o3
a0119a78:  35 14 7a e1  sethi  %hi(0x51eb8400), %i2
a0119a7c:  83 35 20 10  srl  %l4, 0x10, %g1
a0119a80:  9a 16 a1 1f  or  %i2, 0x11f, %o5
a0119a84:  a0 5a c0 01  smul  %o3, %g1, %l0
a0119a88:  80 54 00 0d  umul  %l0, %o5, %g0
a0119a8c:  a3 40 00 00  rd  %y, %l1
a0119a90:  b5 34 60 05  srl  %l1, 5, %i2
a0119a94:  80 a4 a0 01  cmp  %l2, 1
a0119a98:  08 80 00 03  bleu  0xa0119aa4
a0119a9c:  82 10 00 1c  mov  %i4, %g1
a0119aa0:  82 10 20 00  clr  %g1
a0119aa4:  90 0c a0 ff  and  %l2, 0xff, %o0
a0119aa8:  80 a2 20 02  cmp  %o0, 2
a0119aac:  96 40 20 00  addx  %g0, 0, %o3
a0119ab0:  98 20 00 0b  neg  %o3, %o4
a0119ab4:  82 08 60 ff  and  %g1, 0xff, %g1
a0119ab8:  a2 0a 00 0c  and  %o0, %o4, %l1
a0119abc:  a0 00 40 01  add  %g1, %g1, %l0
a0119ac0:  a8 15 a2 a8  or  %l6, 0x2a8, %l4
a0119ac4:  f0 15 00 10  lduh  [ %l4 + %l0 ], %i0
a0119ac8:  9e 04 40 11  add  %l1, %l1, %o7
a0119acc:  d8 15 00 0f  lduh  [ %l4 + %o7 ], %o4
a0119ad0:  94 06 20 81  add  %i0, 0x81, %o2
a0119ad4:  96 06 20 82  add  %i0, 0x82, %o3
a0119ad8:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a0119adc:  9b 2a a0 02  sll  %o2, 2, %o5
a0119ae0:  b0 10 00 0c  mov  %o4, %i0
a0119ae4:  a3 2e a0 10  sll  %i2, 0x10, %l1
a0119ae8:  82 0e a0 ff  and  %i2, 0xff, %g1
a0119aec:  90 13 40 0f  or  %o5, %o7, %o0
a0119af0:  93 32 60 10  srl  %o1, 0x10, %o1
a0119af4:  b4 06 20 d3  add  %i0, 0xd3, %i2
a0119af8:  c2 22 00 00  st  %g1, [ %o0 ]
a0119afc:  a8 02 7f ff  add  %o1, -1, %l4
a0119b00:  a1 2a e0 02  sll  %o3, 2, %l0
a0119b04:  94 03 20 83  add  %o4, 0x83, %o2
a0119b08:  b1 2e e0 10  sll  %i3, 0x10, %i0
a0119b0c:  96 14 00 0f  or  %l0, %o7, %o3
a0119b10:  99 2a a0 02  sll  %o2, 2, %o4
a0119b14:  9b 34 60 18  srl  %l1, 0x18, %o5
a0119b18:  91 35 20 08  srl  %l4, 8, %o0
a0119b1c:  b6 0c e0 ff  and  %l3, 0xff, %i3
a0119b20:  da 22 c0 00  st  %o5, [ %o3 ]
a0119b24:  a2 13 00 0f  or  %o4, %o7, %l1
a0119b28:  92 0a 20 ff  and  %o0, 0xff, %o1
a0119b2c:  a0 0d 20 ff  and  %l4, 0xff, %l0
a0119b30:  95 2e a0 02  sll  %i2, 2, %o2
a0119b34:  a6 0d 60 ff  and  %l5, 0xff, %l3
a0119b38:  98 12 80 0f  or  %o2, %o7, %o4
a0119b3c:  e0 24 40 00  st  %l0, [ %l1 ]
a0119b40:  96 5e c0 13  smul  %i3, %l3, %o3
a0119b44:  91 36 20 10  srl  %i0, 0x10, %o0
a0119b48:  d2 23 00 00  st  %o1, [ %o4 ]
a0119b4c:  80 a2 00 0b  cmp  %o0, %o3
a0119b50:  06 80 00 0d  bl  0xa0119b84
a0119b54:  9e 10 20 00  clr  %o7
a0119b58:  a7 2e 60 10  sll  %i1, 0x10, %l3
a0119b5c:  b7 34 e0 10  srl  %l3, 0x10, %i3
a0119b60:  b2 10 20 64  mov  0x64, %i1
a0119b64:  98 22 00 0b  sub  %o0, %o3, %o4
a0119b68:  82 26 40 1b  sub  %i1, %i3, %g1
a0119b6c:  29 14 7a e1  sethi  %hi(0x51eb8400), %l4
a0119b70:  9e 15 21 1f  or  %l4, 0x11f, %o7	! 0x51eb851f
a0119b74:  92 5b 00 01  smul  %o4, %g1, %o1
a0119b78:  80 52 40 0f  umul  %o1, %o7, %g0
a0119b7c:  b5 40 00 00  rd  %y, %i2
a0119b80:  9f 36 a0 05  srl  %i2, 5, %o7
a0119b84:  80 a4 a0 01  cmp  %l2, 1
a0119b88:  08 80 00 03  bleu  0xa0119b94
a0119b8c:  9a 10 00 1c  mov  %i4, %o5
a0119b90:  9a 10 20 00  clr  %o5
a0119b94:  80 a4 a0 02  cmp  %l2, 2
a0119b98:  b6 60 20 00  subx  %g0, 0, %i3
a0119b9c:  a6 0b 60 ff  and  %o5, 0xff, %l3
a0119ba0:  b2 0e c0 1c  and  %i3, %i4, %i1
a0119ba4:  96 15 a2 a8  or  %l6, 0x2a8, %o3
a0119ba8:  9a 04 c0 13  add  %l3, %l3, %o5
a0119bac:  82 0e 60 ff  and  %i1, 0xff, %g1
a0119bb0:  e0 12 c0 0d  lduh  [ %o3 + %o5 ], %l0
a0119bb4:  98 00 40 01  add  %g1, %g1, %o4
a0119bb8:  f0 12 c0 0c  lduh  [ %o3 + %o4 ], %i0
a0119bbc:  94 04 20 85  add  %l0, 0x85, %o2
a0119bc0:  90 04 20 84  add  %l0, 0x84, %o0
a0119bc4:  a3 2a 20 02  sll  %o0, 2, %l1
a0119bc8:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a0119bcc:  99 2a a0 02  sll  %o2, 2, %o4
a0119bd0:  96 14 40 09  or  %l1, %o1, %o3
a0119bd4:  95 2b e0 10  sll  %o7, 0x10, %o2
a0119bd8:  9a 06 20 86  add  %i0, 0x86, %o5
a0119bdc:  82 0b e0 ff  and  %o7, 0xff, %g1
a0119be0:  c2 22 c0 00  st  %g1, [ %o3 ]
a0119be4:  9e 05 7f ff  add  %l5, -1, %o7
a0119be8:  b0 13 00 09  or  %o4, %o1, %i0
a0119bec:  95 32 a0 18  srl  %o2, 0x18, %o2
a0119bf0:  a9 2b 60 02  sll  %o5, 2, %l4
a0119bf4:  d4 26 00 00  st  %o2, [ %i0 ]
a0119bf8:  aa 15 00 09  or  %l4, %o1, %l5
a0119bfc:  b4 0b e0 ff  and  %o7, 0xff, %i2
a0119c00:  f4 25 40 00  st  %i2, [ %l5 ]
a0119c04:  80 a4 a0 01  cmp  %l2, 1
a0119c08:  38 80 00 02  bgu,a   0xa0119c10
a0119c0c:  b8 10 20 00  clr  %i4
a0119c10:  96 0f 20 ff  and  %i4, 0xff, %o3
a0119c14:  98 15 a2 a8  or  %l6, 0x2a8, %o4
a0119c18:  90 02 c0 0b  add  %o3, %o3, %o0
a0119c1c:  e0 13 00 08  lduh  [ %o4 + %o0 ], %l0
a0119c20:  a2 04 20 80  add  %l0, 0x80, %l1
a0119c24:  ad 2c 60 02  sll  %l1, 2, %l6
a0119c28:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a0119c2c:  b8 15 80 09  or  %l6, %o1, %i4
a0119c30:  e4 07 00 00  ld  [ %i4 ], %l2
a0119c34:  80 8c a0 01  btst  1, %l2
a0119c38:  12 80 00 af  bne  0xa0119ef4
a0119c3c:  01 00 00 00  nop
a0119c40:  67 fd d1 99  call  0x4008e2a4
a0119c44:  81 e8 00 00  restore
a0119c48:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a0119c4c:  e0 0c 61 b0  ldub  [ %l1 + 0x1b0 ], %l0	! 0xa802c9b0
a0119c50:  9e 0c 20 30  and  %l0, 0x30, %o7
a0119c54:  83 3b e0 04  sra  %o7, 4, %g1
a0119c58:  80 a0 60 02  cmp  %g1, 2
a0119c5c:  12 bf ff 77  bne  0xa0119a38
a0119c60:  01 00 00 00  nop
a0119c64:  93 2a 60 10  sll  %o1, 0x10, %o1
a0119c68:  9f 2e a0 10  sll  %i2, 0x10, %o7
a0119c6c:  a3 32 60 10  srl  %o1, 0x10, %l1
a0119c70:  9a 0d 20 ff  and  %l4, 0xff, %o5
a0119c74:  b4 5b 40 11  smul  %o5, %l1, %i2
a0119c78:  99 33 e0 10  srl  %o7, 0x10, %o4
a0119c7c:  80 a3 00 1a  cmp  %o4, %i2
a0119c80:  16 80 00 a3  bge  0xa0119f0c
a0119c84:  a2 10 20 00  clr  %l1
a0119c88:  80 a4 a0 01  cmp  %l2, 1
a0119c8c:  08 80 00 03  bleu  0xa0119c98
a0119c90:  82 10 00 1c  mov  %i4, %g1
a0119c94:  82 10 20 00  clr  %g1
a0119c98:  a0 0c a0 ff  and  %l2, 0xff, %l0
a0119c9c:  80 a4 20 02  cmp  %l0, 2
a0119ca0:  98 40 20 00  addx  %g0, 0, %o4
a0119ca4:  b0 20 00 0c  neg  %o4, %i0
a0119ca8:  82 08 60 ff  and  %g1, 0xff, %g1
a0119cac:  9e 0c 00 18  and  %l0, %i0, %o7
a0119cb0:  96 00 40 01  add  %g1, %g1, %o3
a0119cb4:  a8 15 a2 a8  or  %l6, 0x2a8, %l4
a0119cb8:  d4 15 00 0b  lduh  [ %l4 + %o3 ], %o2
a0119cbc:  b4 03 c0 0f  add  %o7, %o7, %i2
a0119cc0:  f0 15 00 1a  lduh  [ %l4 + %i2 ], %i0
a0119cc4:  9a 02 a0 81  add  %o2, 0x81, %o5
a0119cc8:  98 02 a0 82  add  %o2, 0x82, %o4
a0119ccc:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a0119cd0:  91 2b 60 02  sll  %o5, 2, %o0
a0119cd4:  97 2b 20 02  sll  %o4, 2, %o3
a0119cd8:  94 10 00 18  mov  %i0, %o2
a0119cdc:  a0 12 00 1a  or  %o0, %i2, %l0
a0119ce0:  9b 2c 60 10  sll  %l1, 0x10, %o5
a0119ce4:  98 06 20 83  add  %i0, 0x83, %o4
a0119ce8:  82 0c 60 ff  and  %l1, 0xff, %g1
a0119cec:  c2 24 00 00  st  %g1, [ %l0 ]
a0119cf0:  b0 12 c0 1a  or  %o3, %i2, %i0
a0119cf4:  91 33 60 18  srl  %o5, 0x18, %o0
a0119cf8:  93 32 60 10  srl  %o1, 0x10, %o1
a0119cfc:  d0 26 00 00  st  %o0, [ %i0 ]
a0119d00:  a8 02 7f ff  add  %o1, -1, %l4
a0119d04:  9f 2b 20 02  sll  %o4, 2, %o7
a0119d08:  a0 02 a0 d3  add  %o2, 0xd3, %l0
a0119d0c:  98 13 c0 1a  or  %o7, %i2, %o4
a0119d10:  82 0d 20 ff  and  %l4, 0xff, %g1
a0119d14:  91 35 20 08  srl  %l4, 8, %o0
a0119d18:  95 2c 20 02  sll  %l0, 2, %o2
a0119d1c:  c2 23 00 00  st  %g1, [ %o4 ]
a0119d20:  b1 2e e0 10  sll  %i3, 0x10, %i0
a0119d24:  96 0c e0 ff  and  %l3, 0xff, %o3
a0119d28:  9e 0a 20 ff  and  %o0, 0xff, %o7
a0119d2c:  9a 0d 60 ff  and  %l5, 0xff, %o5
a0119d30:  a2 12 80 1a  or  %o2, %i2, %l1
a0119d34:  b6 5a c0 0d  smul  %o3, %o5, %i3
a0119d38:  a7 36 20 10  srl  %i0, 0x10, %l3
a0119d3c:  de 24 40 00  st  %o7, [ %l1 ]
a0119d40:  93 2e 60 10  sll  %i1, 0x10, %o1
a0119d44:  98 24 c0 1b  sub  %l3, %i3, %o4
a0119d48:  83 32 60 10  srl  %o1, 0x10, %g1
a0119d4c:  80 a4 c0 1b  cmp  %l3, %i3
a0119d50:  16 bf ff 87  bge  0xa0119b6c
a0119d54:  9e 10 20 00  clr  %o7
a0119d58:  10 bf ff 8c  b  0xa0119b88
a0119d5c:  80 a4 a0 01  cmp  %l2, 1
a0119d60:  32 bf ff 3c  bne,a   0xa0119a50
a0119d64:  93 2a 60 10  sll  %o1, 0x10, %o1
a0119d68:  91 2e a0 10  sll  %i2, 0x10, %o0
a0119d6c:  82 0c e0 ff  and  %l3, 0xff, %g1
a0119d70:  b4 0d 60 ff  and  %l5, 0xff, %i2
a0119d74:  96 58 40 1a  smul  %g1, %i2, %o3
a0119d78:  99 32 20 10  srl  %o0, 0x10, %o4
a0119d7c:  80 a3 00 0b  cmp  %o4, %o3
a0119d80:  06 80 00 0b  bl  0xa0119dac
a0119d84:  a6 10 20 00  clr  %l3
a0119d88:  9f 2e 60 10  sll  %i1, 0x10, %o7
a0119d8c:  98 23 00 0b  sub  %o4, %o3, %o4
a0119d90:  97 33 e0 10  srl  %o7, 0x10, %o3
a0119d94:  15 14 7a e1  sethi  %hi(0x51eb8400), %o2
a0119d98:  a6 5b 00 0b  smul  %o4, %o3, %l3
a0119d9c:  9a 12 a1 1f  or  %o2, 0x11f, %o5
a0119da0:  80 54 c0 0d  umul  %l3, %o5, %g0
a0119da4:  b3 40 00 00  rd  %y, %i1
a0119da8:  a7 36 60 05  srl  %i1, 5, %l3
a0119dac:  80 a4 a0 01  cmp  %l2, 1
a0119db0:  08 80 00 03  bleu  0xa0119dbc
a0119db4:  82 10 00 1c  mov  %i4, %g1
a0119db8:  82 10 20 00  clr  %g1
a0119dbc:  98 0c a0 ff  and  %l2, 0xff, %o4
a0119dc0:  80 a3 20 02  cmp  %o4, 2
a0119dc4:  96 40 20 00  addx  %g0, 0, %o3
a0119dc8:  94 20 00 0b  neg  %o3, %o2
a0119dcc:  b4 08 60 ff  and  %g1, 0xff, %i2
a0119dd0:  90 0b 00 0a  and  %o4, %o2, %o0
a0119dd4:  82 06 80 1a  add  %i2, %i2, %g1
a0119dd8:  9e 15 a2 a8  or  %l6, 0x2a8, %o7
a0119ddc:  f2 13 c0 01  lduh  [ %o7 + %g1 ], %i1
a0119de0:  a0 02 00 08  add  %o0, %o0, %l0
a0119de4:  d8 13 c0 10  lduh  [ %o7 + %l0 ], %o4
a0119de8:  9a 06 60 81  add  %i1, 0x81, %o5
a0119dec:  21 33 c0 00  sethi  %hi(0xcf000000), %l0
a0119df0:  b5 2b 60 02  sll  %o5, 2, %i2
a0119df4:  96 06 60 82  add  %i1, 0x82, %o3
a0119df8:  a3 2a 60 10  sll  %o1, 0x10, %l1
a0119dfc:  92 16 80 10  or  %i2, %l0, %o1
a0119e00:  9b 2c e0 10  sll  %l3, 0x10, %o5
a0119e04:  82 0c e0 ff  and  %l3, 0xff, %g1
a0119e08:  95 2a e0 02  sll  %o3, 2, %o2
a0119e0c:  c2 22 40 00  st  %g1, [ %o1 ]
a0119e10:  90 10 00 0c  mov  %o4, %o0
a0119e14:  96 12 80 10  or  %o2, %l0, %o3
a0119e18:  b5 33 60 18  srl  %o5, 0x18, %i2
a0119e1c:  a3 34 60 10  srl  %l1, 0x10, %l1
a0119e20:  b2 03 20 83  add  %o4, 0x83, %i1
a0119e24:  f4 22 c0 00  st  %i2, [ %o3 ]
a0119e28:  99 2e 60 02  sll  %i1, 2, %o4
a0119e2c:  9e 04 7f ff  add  %l1, -1, %o7
a0119e30:  94 02 20 d3  add  %o0, 0xd3, %o2
a0119e34:  9a 13 00 10  or  %o4, %l0, %o5
a0119e38:  91 33 e0 08  srl  %o7, 8, %o0
a0119e3c:  b5 2e e0 10  sll  %i3, 0x10, %i2
a0119e40:  82 0b e0 ff  and  %o7, 0xff, %g1
a0119e44:  a7 2a a0 02  sll  %o2, 2, %l3
a0119e48:  b2 0d 20 ff  and  %l4, 0xff, %i1
a0119e4c:  92 0a 20 ff  and  %o0, 0xff, %o1
a0119e50:  c2 23 40 00  st  %g1, [ %o5 ]
a0119e54:  b6 14 c0 10  or  %l3, %l0, %i3
a0119e58:  98 5e 40 11  smul  %i1, %l1, %o4
a0119e5c:  97 36 a0 10  srl  %i2, 0x10, %o3
a0119e60:  d2 26 c0 00  st  %o1, [ %i3 ]
a0119e64:  80 a2 c0 0c  cmp  %o3, %o4
a0119e68:  06 80 00 0b  bl  0xa0119e94
a0119e6c:  90 10 20 00  clr  %o0
a0119e70:  a9 2e 20 10  sll  %i0, 0x10, %l4
a0119e74:  98 22 c0 0c  sub  %o3, %o4, %o4
a0119e78:  83 35 20 10  srl  %l4, 0x10, %g1
a0119e7c:  15 14 7a e1  sethi  %hi(0x51eb8400), %o2
a0119e80:  92 5b 00 01  smul  %o4, %g1, %o1
a0119e84:  9e 12 a1 1f  or  %o2, 0x11f, %o7
a0119e88:  80 52 40 0f  umul  %o1, %o7, %g0
a0119e8c:  a7 40 00 00  rd  %y, %l3
a0119e90:  91 34 e0 05  srl  %l3, 5, %o0
a0119e94:  80 a4 a0 01  cmp  %l2, 1
a0119e98:  08 80 00 03  bleu  0xa0119ea4
a0119e9c:  9a 10 00 1c  mov  %i4, %o5
a0119ea0:  9a 10 20 00  clr  %o5
a0119ea4:  80 a4 a0 02  cmp  %l2, 2
a0119ea8:  a6 0b 60 ff  and  %o5, 0xff, %l3
a0119eac:  b6 60 20 00  subx  %g0, 0, %i3
a0119eb0:  98 15 a2 a8  or  %l6, 0x2a8, %o4
a0119eb4:  b0 04 c0 13  add  %l3, %l3, %i0
a0119eb8:  a8 0e c0 1c  and  %i3, %i4, %l4
a0119ebc:  e0 13 00 18  lduh  [ %o4 + %i0 ], %l0
a0119ec0:  82 0d 20 ff  and  %l4, 0xff, %g1
a0119ec4:  96 00 40 01  add  %g1, %g1, %o3
a0119ec8:  b4 04 20 84  add  %l0, 0x84, %i2
a0119ecc:  da 13 00 0b  lduh  [ %o4 + %o3 ], %o5
a0119ed0:  b3 2e a0 02  sll  %i2, 2, %i1
a0119ed4:  a2 04 20 85  add  %l0, 0x85, %l1
a0119ed8:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a0119edc:  96 16 40 09  or  %i1, %o1, %o3
a0119ee0:  99 2c 60 02  sll  %l1, 2, %o4
a0119ee4:  95 2a 20 10  sll  %o0, 0x10, %o2
a0119ee8:  9a 03 60 86  add  %o5, 0x86, %o5
a0119eec:  10 bf ff 3d  b  0xa0119be0
a0119ef0:  82 0a 20 ff  and  %o0, 0xff, %g1
a0119ef4:  67 fd d0 ec  call  0x4008e2a4
a0119ef8:  01 00 00 00  nop
a0119efc:  67 fd d0 ea  call  0x4008e2a4
a0119f00:  01 00 00 00  nop
a0119f04:  67 fd d0 e8  call  0x4008e2a4
a0119f08:  81 e8 00 00  restore
a0119f0c:  a9 2e 20 10  sll  %i0, 0x10, %l4
a0119f10:  98 23 00 1a  sub  %o4, %i2, %o4
a0119f14:  a1 35 20 10  srl  %l4, 0x10, %l0
a0119f18:  b4 10 20 64  mov  0x64, %i2
a0119f1c:  96 26 80 10  sub  %i2, %l0, %o3
a0119f20:  15 14 7a e1  sethi  %hi(0x51eb8400), %o2
a0119f24:  90 5b 00 0b  smul  %o4, %o3, %o0
a0119f28:  82 12 a1 1f  or  %o2, 0x11f, %g1
a0119f2c:  80 52 00 01  umul  %o0, %g1, %g0
a0119f30:  b1 40 00 00  rd  %y, %i0
a0119f34:  10 bf ff 55  b  0xa0119c88
a0119f38:  a3 36 20 05  srl  %i0, 5, %l1
a0119f3c:  b4 0c e0 ff  and  %l3, 0xff, %i2
a0119f40:  a6 0d 60 ff  and  %l5, 0xff, %l3
a0119f44:  96 5e 80 13  smul  %i2, %l3, %o3
a0119f48:  99 34 60 10  srl  %l1, 0x10, %o4
a0119f4c:  80 a3 00 0b  cmp  %o4, %o3
a0119f50:  06 80 00 0d  bl  0xa0119f84
a0119f54:  a6 10 20 00  clr  %l3
a0119f58:  a3 2e 60 10  sll  %i1, 0x10, %l1
a0119f5c:  a0 23 00 0b  sub  %o4, %o3, %l0
a0119f60:  91 34 60 10  srl  %l1, 0x10, %o0
a0119f64:  82 10 20 64  mov  0x64, %g1
a0119f68:  96 20 40 08  sub  %g1, %o0, %o3
a0119f6c:  1f 14 7a e1  sethi  %hi(0x51eb8400), %o7
a0119f70:  94 5c 00 0b  smul  %l0, %o3, %o2
a0119f74:  9a 13 e1 1f  or  %o7, 0x11f, %o5
a0119f78:  80 52 80 0d  umul  %o2, %o5, %g0
a0119f7c:  b3 40 00 00  rd  %y, %i1
a0119f80:  a7 36 60 05  srl  %i1, 5, %l3
a0119f84:  80 a4 a0 01  cmp  %l2, 1
a0119f88:  08 80 00 03  bleu  0xa0119f94
a0119f8c:  82 10 00 1c  mov  %i4, %g1
a0119f90:  82 10 20 00  clr  %g1
a0119f94:  b4 0c a0 ff  and  %l2, 0xff, %i2
a0119f98:  80 a6 a0 02  cmp  %i2, 2
a0119f9c:  98 40 20 00  addx  %g0, 0, %o4
a0119fa0:  96 20 00 0c  neg  %o4, %o3
a0119fa4:  82 08 60 ff  and  %g1, 0xff, %g1
a0119fa8:  b2 0e 80 0b  and  %i2, %o3, %i1
a0119fac:  a0 00 40 01  add  %g1, %g1, %l0
a0119fb0:  9e 15 a2 a8  or  %l6, 0x2a8, %o7
a0119fb4:  d4 13 c0 10  lduh  [ %o7 + %l0 ], %o2
a0119fb8:  90 06 40 19  add  %i1, %i1, %o0
a0119fbc:  f4 13 c0 08  lduh  [ %o7 + %o0 ], %i2
a0119fc0:  9a 02 a0 81  add  %o2, 0x81, %o5
a0119fc4:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a0119fc8:  99 2b 60 02  sll  %o5, 2, %o4
a0119fcc:  a3 2a 60 10  sll  %o1, 0x10, %l1
a0119fd0:  96 02 a0 82  add  %o2, 0x82, %o3
a0119fd4:  92 13 00 0f  or  %o4, %o7, %o1
a0119fd8:  94 10 00 1a  mov  %i2, %o2
a0119fdc:  9b 2c e0 10  sll  %l3, 0x10, %o5
a0119fe0:  98 06 a0 83  add  %i2, 0x83, %o4
a0119fe4:  82 0c e0 ff  and  %l3, 0xff, %g1
a0119fe8:  a1 2a e0 02  sll  %o3, 2, %l0
a0119fec:  c2 22 40 00  st  %g1, [ %o1 ]
a0119ff0:  96 14 00 0f  or  %l0, %o7, %o3
a0119ff4:  b5 33 60 18  srl  %o5, 0x18, %i2
a0119ff8:  b3 34 60 10  srl  %l1, 0x10, %i1
a0119ffc:  a7 2b 20 02  sll  %o4, 2, %l3
a011a000:  f4 22 c0 00  st  %i2, [ %o3 ]
a011a004:  90 06 7f ff  add  %i1, -1, %o0
a011a008:  92 02 a0 d3  add  %o2, 0xd3, %o1
a011a00c:  98 14 c0 0f  or  %l3, %o7, %o4
a011a010:  a0 0a 20 ff  and  %o0, 0xff, %l0
a011a014:  b5 32 20 08  srl  %o0, 8, %i2
a011a018:  95 2a 60 02  sll  %o1, 2, %o2
a011a01c:  a7 2e e0 10  sll  %i3, 0x10, %l3
a011a020:  9a 0d 20 ff  and  %l4, 0xff, %o5
a011a024:  e0 23 00 00  st  %l0, [ %o4 ]
a011a028:  b6 12 80 0f  or  %o2, %o7, %i3
a011a02c:  82 5b 40 19  smul  %o5, %i1, %g1
a011a030:  92 0e a0 ff  and  %i2, 0xff, %o1
a011a034:  97 34 e0 10  srl  %l3, 0x10, %o3
a011a038:  d2 26 c0 00  st  %o1, [ %i3 ]
a011a03c:  80 a2 c0 01  cmp  %o3, %g1
a011a040:  06 bf ff 95  bl  0xa0119e94
a011a044:  90 10 20 00  clr  %o0
a011a048:  b7 2e 20 10  sll  %i0, 0x10, %i3
a011a04c:  b1 36 e0 10  srl  %i3, 0x10, %i0
a011a050:  98 22 c0 01  sub  %o3, %g1, %o4
a011a054:  a8 10 20 64  mov  0x64, %l4
a011a058:  10 bf ff 89  b  0xa0119e7c
a011a05c:  82 25 00 18  sub  %l4, %i0, %g1
