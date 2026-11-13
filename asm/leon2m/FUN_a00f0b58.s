# leon2m FUN_a00f0b58 0xa00f0b58-0xa00f1100 (1448 bytes)
a00f0b58:  9d e3 bf 98  save  %sp, -104, %sp
a00f0b5c:  a2 10 00 18  mov  %i0, %l1
a00f0b60:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f0b64:  80 a6 20 02  cmp  %i0, 2
a00f0b68:  02 80 00 0a  be  0xa00f0b90
a00f0b6c:  80 a6 20 03  cmp  %i0, 3
a00f0b70:  02 80 00 be  be  0xa00f0e68
a00f0b74:  80 a6 20 06  cmp  %i0, 6
a00f0b78:  02 80 00 06  be  0xa00f0b90
a00f0b7c:  80 a6 20 07  cmp  %i0, 7
a00f0b80:  12 80 01 5e  bne  0xa00f10f8
a00f0b84:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00f0b88:  10 80 00 ba  b  0xa00f0e70
a00f0b8c:  15 2a 00 ad  sethi  %hi(0xa802b400), %o2
a00f0b90:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00f0b94:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f0b98:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f0b9c:  a4 12 23 46  or  %o0, 0x346, %l2
a00f0ba0:  b4 13 63 44  or  %o5, 0x344, %i2
a00f0ba4:  a6 10 63 4a  or  %g1, 0x34a, %l3
a00f0ba8:  b2 10 20 02  mov  2, %i1
a00f0bac:  90 10 00 18  mov  %i0, %o0
a00f0bb0:  40 00 05 a9  call  0xa00f2254
a00f0bb4:  92 10 20 8e  mov  0x8e, %o1
a00f0bb8:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f0bbc:  d8 0b 63 47  ldub  [ %o5 + 0x347 ], %o4	! 0xa802b747
a00f0bc0:  80 a3 20 00  cmp  %o4, 0
a00f0bc4:  12 80 00 1c  bne  0xa00f0c34
a00f0bc8:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00f0bcc:  80 8c 20 03  btst  3, %l0
a00f0bd0:  02 80 00 ae  be  0xa00f0e88
a00f0bd4:  c2 16 80 00  lduh  [ %i2 ], %g1
a00f0bd8:  a5 28 60 10  sll  %g1, 0x10, %l2
a00f0bdc:  9f 34 a0 10  srl  %l2, 0x10, %o7
a00f0be0:  80 a3 e1 2b  cmp  %o7, 0x12b
a00f0be4:  08 80 00 06  bleu  0xa00f0bfc
a00f0be8:  80 8c 20 03  btst  3, %l0
a00f0bec:  a6 10 20 01  mov  1, %l3
a00f0bf0:  e6 2b 63 47  stb  %l3, [ %o5 + 0x347 ]
a00f0bf4:  c0 36 80 00  clrh  [ %i2 ]
a00f0bf8:  80 8c 20 03  btst  3, %l0
a00f0bfc:  02 80 00 06  be  0xa00f0c14
a00f0c00:  82 04 7f fa  add  %l1, -6, %g1
a00f0c04:  d2 16 80 00  lduh  [ %i2 ], %o1
a00f0c08:  80 a2 61 2b  cmp  %o1, 0x12b
a00f0c0c:  28 80 01 03  bleu,a   0xa00f1018
a00f0c10:  33 00 06 68  sethi  %hi(0x19a000), %i1
a00f0c14:  a0 08 60 ff  and  %g1, 0xff, %l0
a00f0c18:  80 a4 20 01  cmp  %l0, 1
a00f0c1c:  18 80 00 d6  bgu  0xa00f0f74
a00f0c20:  90 10 00 18  mov  %i0, %o0
a00f0c24:  d8 16 80 00  lduh  [ %i2 ], %o4
a00f0c28:  b0 03 20 01  add  %o4, 1, %i0
a00f0c2c:  10 80 01 33  b  0xa00f10f8
a00f0c30:  f0 36 80 00  sth  %i0, [ %i2 ]
a00f0c34:  80 8c 20 03  btst  3, %l0
a00f0c38:  22 80 00 99  be,a   0xa00f0e9c
a00f0c3c:  90 10 00 18  mov  %i0, %o0
a00f0c40:  de 16 80 00  lduh  [ %i2 ], %o7
a00f0c44:  80 a3 e1 2b  cmp  %o7, 0x12b
a00f0c48:  18 80 00 9b  bgu  0xa00f0eb4
a00f0c4c:  82 10 20 01  mov  1, %g1
a00f0c50:  80 8c 20 03  btst  3, %l0
a00f0c54:  12 80 00 9c  bne  0xa00f0ec4
a00f0c58:  90 10 00 18  mov  %i0, %o0
a00f0c5c:  90 10 00 18  mov  %i0, %o0
a00f0c60:  40 00 05 7d  call  0xa00f2254
a00f0c64:  92 10 20 88  mov  0x88, %o1
a00f0c68:  80 8a 20 20  btst  0x20, %o0
a00f0c6c:  12 80 01 23  bne  0xa00f10f8
a00f0c70:  a0 0e 60 ff  and  %i1, 0xff, %l0
a00f0c74:  80 a4 20 04  cmp  %l0, 4
a00f0c78:  82 60 20 00  subx  %g0, 0, %g1
a00f0c7c:  a4 08 40 19  and  %g1, %i1, %l2
a00f0c80:  98 0c a0 ff  and  %l2, 0xff, %o4
a00f0c84:  1f 00 06 67  sethi  %hi(0x199c00), %o7
a00f0c88:  a4 13 e3 fc  or  %o7, 0x3fc, %l2	! 0x199ffc
a00f0c8c:  96 03 00 0c  add  %o4, %o4, %o3
a00f0c90:  e2 14 80 0b  lduh  [ %l2 + %o3 ], %l1
a00f0c94:  95 2c 60 02  sll  %l1, 2, %o2
a00f0c98:  23 33 c0 00  sethi  %hi(0xcf000000), %l1
a00f0c9c:  90 12 80 11  or  %o2, %l1, %o0
a00f0ca0:  f4 02 00 00  ld  [ %o0 ], %i2
a00f0ca4:  13 00 06 68  sethi  %hi(0x19a000), %o1
a00f0ca8:  90 12 62 00  or  %o1, 0x200, %o0	! 0x19a200
a00f0cac:  94 0e a0 ff  and  %i2, 0xff, %o2
a00f0cb0:  7f ff b9 30  call  0xa00df170
a00f0cb4:  92 10 00 10  mov  %l0, %o1
a00f0cb8:  80 a4 20 03  cmp  %l0, 3
a00f0cbc:  08 80 00 03  bleu  0xa00f0cc8
a00f0cc0:  82 10 00 19  mov  %i1, %g1
a00f0cc4:  82 10 20 00  clr  %g1
a00f0cc8:  98 08 60 ff  and  %g1, 0xff, %o4
a00f0ccc:  96 03 00 0c  add  %o4, %o4, %o3
a00f0cd0:  d4 14 80 0b  lduh  [ %l2 + %o3 ], %o2
a00f0cd4:  90 02 a0 0f  add  %o2, 0xf, %o0
a00f0cd8:  93 2a 20 02  sll  %o0, 2, %o1
a00f0cdc:  9a 12 40 11  or  %o1, %l1, %o5
a00f0ce0:  f4 03 40 00  ld  [ %o5 ], %i2
a00f0ce4:  9e 0e a0 ff  and  %i2, 0xff, %o7
a00f0ce8:  80 a4 20 03  cmp  %l0, 3
a00f0cec:  08 80 00 03  bleu  0xa00f0cf8
a00f0cf0:  82 10 00 19  mov  %i1, %g1
a00f0cf4:  82 10 20 00  clr  %g1
a00f0cf8:  96 08 60 ff  and  %g1, 0xff, %o3
a00f0cfc:  94 02 c0 0b  add  %o3, %o3, %o2
a00f0d00:  d0 14 80 0a  lduh  [ %l2 + %o2 ], %o0
a00f0d04:  92 02 20 0e  add  %o0, 0xe, %o1
a00f0d08:  9b 2a 60 02  sll  %o1, 2, %o5
a00f0d0c:  b4 13 40 11  or  %o5, %l1, %i2
a00f0d10:  c2 06 80 00  ld  [ %i2 ], %g1
a00f0d14:  98 08 60 ff  and  %g1, 0xff, %o4
a00f0d18:  80 a4 20 03  cmp  %l0, 3
a00f0d1c:  08 80 00 03  bleu  0xa00f0d28
a00f0d20:  82 10 00 19  mov  %i1, %g1
a00f0d24:  82 10 20 00  clr  %g1
a00f0d28:  96 08 60 ff  and  %g1, 0xff, %o3
a00f0d2c:  94 02 c0 0b  add  %o3, %o3, %o2
a00f0d30:  d0 14 80 0a  lduh  [ %l2 + %o2 ], %o0
a00f0d34:  92 02 20 0d  add  %o0, 0xd, %o1
a00f0d38:  9b 2a 60 02  sll  %o1, 2, %o5
a00f0d3c:  b4 13 40 11  or  %o5, %l1, %i2
a00f0d40:  c2 06 80 00  ld  [ %i2 ], %g1
a00f0d44:  96 08 60 ff  and  %g1, 0xff, %o3
a00f0d48:  80 a4 20 03  cmp  %l0, 3
a00f0d4c:  08 80 00 03  bleu  0xa00f0d58
a00f0d50:  82 10 00 19  mov  %i1, %g1
a00f0d54:  82 10 20 00  clr  %g1
a00f0d58:  82 08 60 ff  and  %g1, 0xff, %g1
a00f0d5c:  94 00 40 01  add  %g1, %g1, %o2
a00f0d60:  d0 14 80 0a  lduh  [ %l2 + %o2 ], %o0
a00f0d64:  92 02 20 0c  add  %o0, 0xc, %o1
a00f0d68:  9b 2a 60 02  sll  %o1, 2, %o5
a00f0d6c:  b4 13 40 11  or  %o5, %l1, %i2
a00f0d70:  c2 06 80 00  ld  [ %i2 ], %g1
a00f0d74:  94 08 60 ff  and  %g1, 0xff, %o2
a00f0d78:  80 a4 20 03  cmp  %l0, 3
a00f0d7c:  08 80 00 03  bleu  0xa00f0d88
a00f0d80:  9a 10 00 19  mov  %i1, %o5
a00f0d84:  9a 10 20 00  clr  %o5
a00f0d88:  92 0b 60 ff  and  %o5, 0xff, %o1
a00f0d8c:  9a 02 40 09  add  %o1, %o1, %o5
a00f0d90:  f4 14 80 0d  lduh  [ %l2 + %o5 ], %i2
a00f0d94:  82 06 a0 0b  add  %i2, 0xb, %g1
a00f0d98:  91 28 60 02  sll  %g1, 2, %o0
a00f0d9c:  92 12 00 11  or  %o0, %l1, %o1
a00f0da0:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f0da4:  f4 02 40 00  ld  [ %o1 ], %i2
a00f0da8:  90 13 62 20  or  %o5, 0x220, %o0
a00f0dac:  9a 10 00 0f  mov  %o7, %o5
a00f0db0:  7f ff b8 f0  call  0xa00df170
a00f0db4:  92 0e a0 ff  and  %i2, 0xff, %o1
a00f0db8:  80 a4 20 03  cmp  %l0, 3
a00f0dbc:  08 80 00 03  bleu  0xa00f0dc8
a00f0dc0:  82 10 00 19  mov  %i1, %g1
a00f0dc4:  82 10 20 00  clr  %g1
a00f0dc8:  94 08 60 ff  and  %g1, 0xff, %o2
a00f0dcc:  96 02 80 0a  add  %o2, %o2, %o3
a00f0dd0:  d8 14 80 0b  lduh  [ %l2 + %o3 ], %o4
a00f0dd4:  a5 2b 20 02  sll  %o4, 2, %l2
a00f0dd8:  9e 14 80 11  or  %l2, %l1, %o7
a00f0ddc:  e0 03 c0 00  ld  [ %o7 ], %l0
a00f0de0:  b2 0c 20 a0  and  %l0, 0xa0, %i1
a00f0de4:  80 a6 60 a0  cmp  %i1, 0xa0
a00f0de8:  12 80 00 c4  bne  0xa00f10f8
a00f0dec:  01 00 00 00  nop
a00f0df0:  67 fe 71 e9  call  0x4008d594
a00f0df4:  d0 14 c0 00  lduh  [ %l3 ], %o0
a00f0df8:  83 2a 20 10  sll  %o0, 0x10, %g1
a00f0dfc:  11 00 06 68  sethi  %hi(0x19a000), %o0
a00f0e00:  95 30 60 10  srl  %g1, 0x10, %o2
a00f0e04:  92 10 00 18  mov  %i0, %o1
a00f0e08:  7f ff b8 da  call  0xa00df170
a00f0e0c:  90 12 22 40  or  %o0, 0x240, %o0
a00f0e10:  67 fe 71 e1  call  0x4008d594
a00f0e14:  d0 14 c0 00  lduh  [ %l3 ], %o0
a00f0e18:  a3 2a 20 10  sll  %o0, 0x10, %l1
a00f0e1c:  a7 34 60 10  srl  %l1, 0x10, %l3
a00f0e20:  80 a4 e0 32  cmp  %l3, 0x32
a00f0e24:  08 80 00 b5  bleu  0xa00f10f8
a00f0e28:  01 00 00 00  nop
a00f0e2c:  40 00 c3 90  call  0xa0121c6c
a00f0e30:  90 10 00 18  mov  %i0, %o0
a00f0e34:  67 fe 70 db  call  0x4008d1a0
a00f0e38:  90 10 20 05  mov  5, %o0
a00f0e3c:  90 10 00 18  mov  %i0, %o0
a00f0e40:  92 10 20 88  mov  0x88, %o1
a00f0e44:  94 10 20 20  mov  0x20, %o2
a00f0e48:  40 00 05 39  call  0xa00f232c
a00f0e4c:  96 10 20 01  mov  1, %o3
a00f0e50:  35 00 06 68  sethi  %hi(0x19a000), %i2
a00f0e54:  7f ff b8 c7  call  0xa00df170
a00f0e58:  90 16 a2 60  or  %i2, 0x260, %o0	! 0x19a260
a00f0e5c:  b2 10 20 8e  mov  0x8e, %i1
a00f0e60:  40 00 05 0e  call  0xa00f2298
a00f0e64:  95 e8 20 03  restore  %g0, 3, %o2
a00f0e68:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00f0e6c:  15 2a 00 ad  sethi  %hi(0xa802b400), %o2
a00f0e70:  13 2a 00 ad  sethi  %hi(0xa802b400), %o1
a00f0e74:  a4 12 e3 42  or  %o3, 0x342, %l2
a00f0e78:  b4 12 a3 40  or  %o2, 0x340, %i2
a00f0e7c:  a6 12 63 48  or  %o1, 0x348, %l3
a00f0e80:  10 bf ff 4b  b  0xa00f0bac
a00f0e84:  b2 10 20 03  mov  3, %i1
a00f0e88:  80 a0 60 95  cmp  %g1, 0x95
a00f0e8c:  38 bf ff 59  bgu,a   0xa00f0bf0
a00f0e90:  a6 10 20 01  mov  1, %l3
a00f0e94:  10 bf ff 52  b  0xa00f0bdc
a00f0e98:  a5 28 60 10  sll  %g1, 0x10, %l2
a00f0e9c:  40 00 04 ee  call  0xa00f2254
a00f0ea0:  92 10 20 88  mov  0x88, %o1
a00f0ea4:  80 8a 20 20  btst  0x20, %o0
a00f0ea8:  22 bf ff 67  be,a   0xa00f0c44
a00f0eac:  de 16 80 00  lduh  [ %i2 ], %o7
a00f0eb0:  82 10 20 01  mov  1, %g1
a00f0eb4:  80 8c 20 03  btst  3, %l0
a00f0eb8:  02 bf ff 69  be  0xa00f0c5c
a00f0ebc:  c2 2c 80 00  stb  %g1, [ %l2 ]
a00f0ec0:  90 10 00 18  mov  %i0, %o0
a00f0ec4:  40 00 04 e4  call  0xa00f2254
a00f0ec8:  92 10 20 88  mov  0x88, %o1
a00f0ecc:  80 8a 20 20  btst  0x20, %o0
a00f0ed0:  02 bf ff 64  be  0xa00f0c60
a00f0ed4:  90 10 00 18  mov  %i0, %o0
a00f0ed8:  e4 16 80 00  lduh  [ %i2 ], %l2
a00f0edc:  80 a4 a1 2b  cmp  %l2, 0x12b
a00f0ee0:  18 bf ff 60  bgu  0xa00f0c60
a00f0ee4:  96 10 20 00  clr  %o3
a00f0ee8:  90 10 00 18  mov  %i0, %o0
a00f0eec:  92 10 20 88  mov  0x88, %o1
a00f0ef0:  40 00 05 0f  call  0xa00f232c
a00f0ef4:  94 10 20 20  mov  0x20, %o2
a00f0ef8:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f0efc:  90 13 62 70  or  %o5, 0x270, %o0	! 0x19a270
a00f0f00:  d2 16 80 00  lduh  [ %i2 ], %o1
a00f0f04:  7f ff b8 9b  call  0xa00df170
a00f0f08:  94 10 00 10  mov  %l0, %o2
a00f0f0c:  90 10 00 18  mov  %i0, %o0
a00f0f10:  94 10 00 10  mov  %l0, %o2
a00f0f14:  7f ff fd 1b  call  0xa00f0380
a00f0f18:  d2 16 80 00  lduh  [ %i2 ], %o1
a00f0f1c:  80 8a 20 ff  btst  0xff, %o0
a00f0f20:  02 80 00 04  be  0xa00f0f30
a00f0f24:  92 04 7f fa  add  %l1, -6, %o1
a00f0f28:  a0 10 21 2c  mov  0x12c, %l0
a00f0f2c:  e0 36 80 00  sth  %l0, [ %i2 ]
a00f0f30:  a2 0a 60 ff  and  %o1, 0xff, %l1
a00f0f34:  80 a4 60 01  cmp  %l1, 1
a00f0f38:  18 80 00 47  bgu  0xa00f1054
a00f0f3c:  90 10 00 18  mov  %i0, %o0
a00f0f40:  92 10 20 8e  mov  0x8e, %o1
a00f0f44:  94 10 20 03  mov  3, %o2
a00f0f48:  40 00 04 d4  call  0xa00f2298
a00f0f4c:  90 10 00 18  mov  %i0, %o0
a00f0f50:  40 00 c3 47  call  0xa0121c6c
a00f0f54:  90 10 00 18  mov  %i0, %o0
a00f0f58:  67 fe 71 8c  call  0x4008d588
a00f0f5c:  01 00 00 00  nop
a00f0f60:  d0 34 c0 00  sth  %o0, [ %l3 ]
a00f0f64:  da 16 80 00  lduh  [ %i2 ], %o5
a00f0f68:  82 03 60 01  add  %o5, 1, %g1
a00f0f6c:  10 bf ff 3c  b  0xa00f0c5c
a00f0f70:  c2 36 80 00  sth  %g1, [ %i2 ]
a00f0f74:  40 00 04 b8  call  0xa00f2254
a00f0f78:  92 10 20 54  mov  0x54, %o1
a00f0f7c:  80 8a 20 80  btst  0x80, %o0
a00f0f80:  32 bf ff 2a  bne,a   0xa00f0c28
a00f0f84:  d8 16 80 00  lduh  [ %i2 ], %o4
a00f0f88:  92 10 20 78  mov  0x78, %o1
a00f0f8c:  40 00 04 b2  call  0xa00f2254
a00f0f90:  90 10 00 18  mov  %i0, %o0
a00f0f94:  96 0a 20 7f  and  %o0, 0x7f, %o3
a00f0f98:  b3 2a e0 08  sll  %o3, 8, %i1
a00f0f9c:  92 10 20 77  mov  0x77, %o1
a00f0fa0:  40 00 04 ad  call  0xa00f2254
a00f0fa4:  90 10 00 18  mov  %i0, %o0
a00f0fa8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f0fac:  a2 16 40 08  or  %i1, %o0, %l1
a00f0fb0:  92 10 20 53  mov  0x53, %o1
a00f0fb4:  40 00 04 a8  call  0xa00f2254
a00f0fb8:  90 10 00 18  mov  %i0, %o0
a00f0fbc:  94 0a 20 7f  and  %o0, 0x7f, %o2
a00f0fc0:  a7 2a a0 08  sll  %o2, 8, %l3
a00f0fc4:  92 10 20 52  mov  0x52, %o1
a00f0fc8:  40 00 04 a3  call  0xa00f2254
a00f0fcc:  90 10 00 18  mov  %i0, %o0
a00f0fd0:  92 0a 20 ff  and  %o0, 0xff, %o1
a00f0fd4:  94 14 c0 09  or  %l3, %o1, %o2
a00f0fd8:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f0fdc:  a5 2c 60 10  sll  %l1, 0x10, %l2
a00f0fe0:  90 13 62 90  or  %o5, 0x290, %o0
a00f0fe4:  92 10 00 18  mov  %i0, %o1
a00f0fe8:  7f ff b8 62  call  0xa00df170
a00f0fec:  97 34 a0 10  srl  %l2, 0x10, %o3
a00f0ff0:  90 10 00 18  mov  %i0, %o0
a00f0ff4:  94 0c 60 ff  and  %l1, 0xff, %o2
a00f0ff8:  40 00 04 a8  call  0xa00f2298
a00f0ffc:  92 10 20 52  mov  0x52, %o1
a00f1000:  90 10 00 18  mov  %i0, %o0
a00f1004:  95 34 a0 18  srl  %l2, 0x18, %o2
a00f1008:  40 00 04 a4  call  0xa00f2298
a00f100c:  92 10 20 53  mov  0x53, %o1
a00f1010:  10 bf ff 06  b  0xa00f0c28
a00f1014:  d8 16 80 00  lduh  [ %i2 ], %o4
a00f1018:  94 10 00 10  mov  %l0, %o2
a00f101c:  7f ff b8 55  call  0xa00df170
a00f1020:  90 16 61 e0  or  %i1, 0x1e0, %o0
a00f1024:  94 10 00 10  mov  %l0, %o2
a00f1028:  d2 16 80 00  lduh  [ %i2 ], %o1
a00f102c:  7f ff fc d5  call  0xa00f0380
a00f1030:  90 10 00 18  mov  %i0, %o0
a00f1034:  90 10 00 18  mov  %i0, %o0
a00f1038:  92 10 20 8e  mov  0x8e, %o1
a00f103c:  40 00 04 97  call  0xa00f2298
a00f1040:  94 10 20 03  mov  3, %o2
a00f1044:  40 00 c3 0a  call  0xa0121c6c
a00f1048:  90 10 00 18  mov  %i0, %o0
a00f104c:  10 bf fe f2  b  0xa00f0c14
a00f1050:  82 04 7f fa  add  %l1, -6, %g1
a00f1054:  40 00 04 80  call  0xa00f2254
a00f1058:  92 10 20 54  mov  0x54, %o1
a00f105c:  80 8a 20 80  btst  0x80, %o0
a00f1060:  32 bf ff b9  bne,a   0xa00f0f44
a00f1064:  92 10 20 8e  mov  0x8e, %o1
a00f1068:  92 10 20 78  mov  0x78, %o1
a00f106c:  40 00 04 7a  call  0xa00f2254
a00f1070:  90 10 00 18  mov  %i0, %o0
a00f1074:  9e 0a 20 7f  and  %o0, 0x7f, %o7
a00f1078:  a5 2b e0 08  sll  %o7, 8, %l2
a00f107c:  92 10 20 77  mov  0x77, %o1
a00f1080:  40 00 04 75  call  0xa00f2254
a00f1084:  90 10 00 18  mov  %i0, %o0
a00f1088:  98 0a 20 ff  and  %o0, 0xff, %o4
a00f108c:  a2 14 80 0c  or  %l2, %o4, %l1
a00f1090:  92 10 20 53  mov  0x53, %o1
a00f1094:  40 00 04 70  call  0xa00f2254
a00f1098:  90 10 00 18  mov  %i0, %o0
a00f109c:  96 0a 20 7f  and  %o0, 0x7f, %o3
a00f10a0:  a1 2a e0 08  sll  %o3, 8, %l0
a00f10a4:  92 10 20 52  mov  0x52, %o1
a00f10a8:  40 00 04 6b  call  0xa00f2254
a00f10ac:  90 10 00 18  mov  %i0, %o0
a00f10b0:  94 0a 20 ff  and  %o0, 0xff, %o2
a00f10b4:  a5 2c 60 10  sll  %l1, 0x10, %l2
a00f10b8:  11 00 06 68  sethi  %hi(0x19a000), %o0
a00f10bc:  94 14 00 0a  or  %l0, %o2, %o2
a00f10c0:  92 10 00 18  mov  %i0, %o1
a00f10c4:  97 34 a0 10  srl  %l2, 0x10, %o3
a00f10c8:  7f ff b8 2a  call  0xa00df170
a00f10cc:  90 12 22 b0  or  %o0, 0x2b0, %o0
a00f10d0:  90 10 00 18  mov  %i0, %o0
a00f10d4:  94 0c 60 ff  and  %l1, 0xff, %o2
a00f10d8:  40 00 04 70  call  0xa00f2298
a00f10dc:  92 10 20 52  mov  0x52, %o1
a00f10e0:  90 10 00 18  mov  %i0, %o0
a00f10e4:  95 34 a0 18  srl  %l2, 0x18, %o2
a00f10e8:  40 00 04 6c  call  0xa00f2298
a00f10ec:  92 10 20 53  mov  0x53, %o1
a00f10f0:  10 bf ff 95  b  0xa00f0f44
a00f10f4:  92 10 20 8e  mov  0x8e, %o1
a00f10f8:  81 c7 e0 08  ret
a00f10fc:  81 e8 00 00  restore
