# leon2m FUN_a0109bbc 0xa0109bbc-0xa010a2b0 (1780 bytes)
a0109bbc:  9d e3 bf 98  save  %sp, -104, %sp
a0109bc0:  21 2a 00 b5  sethi  %hi(0xa802d400), %l0
a0109bc4:  c2 04 22 a4  ld  [ %l0 + 0x2a4 ], %g1	! 0xa802d6a4
a0109bc8:  80 8e 20 ff  btst  0xff, %i0
a0109bcc:  02 80 00 8c  be  0xa0109dfc
a0109bd0:  ee 10 60 0a  lduh  [ %g1 + 0xa ], %l7
a0109bd4:  67 fe 11 b4  call  0x4008e2a4
a0109bd8:  23 33 c0 47  sethi  %hi(0xcf011c00), %l1
a0109bdc:  13 00 00 0f  sethi  %hi(0x3c00), %o1
a0109be0:  90 14 60 38  or  %l1, 0x38, %o0
a0109be4:  7f ff a5 2a  call  0xa00f308c
a0109be8:  92 12 63 ff  or  %o1, 0x3ff, %o1
a0109bec:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a0109bf0:  90 16 22 80  or  %i0, 0x280, %o0	! 0xcf011a80
a0109bf4:  da 02 00 00  ld  [ %o0 ], %o5
a0109bf8:  80 8b 60 80  btst  0x80, %o5
a0109bfc:  12 80 00 bb  bne  0xa0109ee8
a0109c00:  01 00 00 00  nop
a0109c04:  7f ff e4 f3  call  0xa0102fd0
a0109c08:  90 10 20 00  clr  %o0	! 0x0
a0109c0c:  95 2a 20 10  sll  %o0, 0x10, %o2
a0109c10:  a1 3a a0 10  sra  %o2, 0x10, %l0
a0109c14:  40 01 30 0b  call  0xa0155c40
a0109c18:  90 10 00 10  mov  %l0, %o0
a0109c1c:  80 a4 20 00  cmp  %l0, 0
a0109c20:  06 80 01 69  bl  0xa010a1c4
a0109c24:  17 00 06 68  sethi  %hi(0x19a000), %o3
a0109c28:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a0109c2c:  ea 06 20 cc  ld  [ %i0 + 0xcc ], %l5	! 0x19accc
a0109c30:  40 01 2f 00  call  0xa0155830
a0109c34:  92 10 00 15  mov  %l5, %o1
a0109c38:  a6 10 00 08  mov  %o0, %l3
a0109c3c:  92 10 20 82  mov  0x82, %o1
a0109c40:  7f ff a2 6e  call  0xa00f25f8
a0109c44:  90 10 20 00  clr  %o0
a0109c48:  af 2a 20 10  sll  %o0, 0x10, %l7
a0109c4c:  40 01 2f fd  call  0xa0155c40
a0109c50:  91 35 e0 10  srl  %l7, 0x10, %o0
a0109c54:  92 10 00 08  mov  %o0, %o1
a0109c58:  40 01 2f 70  call  0xa0155a18
a0109c5c:  90 10 00 13  mov  %l3, %o0
a0109c60:  25 00 06 61  sethi  %hi(0x198400), %l2
a0109c64:  e6 04 a3 60  ld  [ %l2 + 0x360 ], %l3	! 0x198760
a0109c68:  40 01 2e f2  call  0xa0155830
a0109c6c:  92 10 00 13  mov  %l3, %o1
a0109c70:  9f 2e e0 10  sll  %i3, 0x10, %o7
a0109c74:  a8 10 00 08  mov  %o0, %l4
a0109c78:  91 33 e0 10  srl  %o7, 0x10, %o0
a0109c7c:  40 01 2f f1  call  0xa0155c40
a0109c80:  01 00 00 00  nop
a0109c84:  a4 10 00 08  mov  %o0, %l2
a0109c88:  92 10 00 12  mov  %l2, %o1
a0109c8c:  40 01 2f 63  call  0xa0155a18
a0109c90:  90 10 00 14  mov  %l4, %o0
a0109c94:  40 01 2d 4a  call  0xa01551bc
a0109c98:  01 00 00 00  nop
a0109c9c:  a8 10 00 08  mov  %o0, %l4
a0109ca0:  92 10 20 64  mov  0x64, %o1
a0109ca4:  7f ff a2 55  call  0xa00f25f8
a0109ca8:  90 10 20 00  clr  %o0
a0109cac:  b6 10 00 08  mov  %o0, %i3
a0109cb0:  7f ff a4 f2  call  0xa00f3078
a0109cb4:  90 14 60 20  or  %l1, 0x20, %o0
a0109cb8:  a2 10 00 08  mov  %o0, %l1
a0109cbc:  7f ff e4 c5  call  0xa0102fd0
a0109cc0:  90 10 20 04  mov  4, %o0
a0109cc4:  99 2a 20 10  sll  %o0, 0x10, %o4
a0109cc8:  ad 3b 20 10  sra  %o4, 0x10, %l6
a0109ccc:  40 01 2f dd  call  0xa0155c40
a0109cd0:  90 10 00 16  mov  %l6, %o0
a0109cd4:  80 a5 a0 00  cmp  %l6, 0
a0109cd8:  06 80 01 67  bl  0xa010a274
a0109cdc:  b8 10 00 14  mov  %l4, %i4
a0109ce0:  40 01 2e d4  call  0xa0155830
a0109ce4:  92 10 00 15  mov  %l5, %o1
a0109ce8:  83 2c 60 10  sll  %l1, 0x10, %g1
a0109cec:  a0 10 00 08  mov  %o0, %l0
a0109cf0:  40 01 2f d4  call  0xa0155c40
a0109cf4:  91 30 60 10  srl  %g1, 0x10, %o0
a0109cf8:  92 10 00 08  mov  %o0, %o1
a0109cfc:  40 01 2f 47  call  0xa0155a18
a0109d00:  90 10 00 10  mov  %l0, %o0
a0109d04:  40 01 2e cb  call  0xa0155830
a0109d08:  92 10 00 13  mov  %l3, %o1
a0109d0c:  40 01 2f 43  call  0xa0155a18
a0109d10:  92 10 00 12  mov  %l2, %o1
a0109d14:  40 01 2d 2a  call  0xa01551bc
a0109d18:  b7 2e e0 10  sll  %i3, 0x10, %i3
a0109d1c:  b0 10 00 08  mov  %o0, %i0
a0109d20:  ab 3e e0 10  sra  %i3, 0x10, %l5
a0109d24:  40 01 2f c7  call  0xa0155c40
a0109d28:  90 10 00 15  mov  %l5, %o0
a0109d2c:  a2 10 00 08  mov  %o0, %l1
a0109d30:  80 a5 60 00  cmp  %l5, 0
a0109d34:  06 80 01 4b  bl  0xa010a260
a0109d38:  ac 10 00 18  mov  %i0, %l6
a0109d3c:  91 2d 20 10  sll  %l4, 0x10, %o0
a0109d40:  ab 32 20 10  srl  %o0, 0x10, %l5
a0109d44:  40 01 2f bf  call  0xa0155c40
a0109d48:  90 10 00 15  mov  %l5, %o0
a0109d4c:  a6 10 00 08  mov  %o0, %l3
a0109d50:  90 10 00 11  mov  %l1, %o0
a0109d54:  40 01 2f 31  call  0xa0155a18
a0109d58:  92 10 00 13  mov  %l3, %o1
a0109d5c:  9b 2e a0 10  sll  %i2, 0x10, %o5
a0109d60:  b5 3b 60 10  sra  %o5, 0x10, %i2
a0109d64:  a4 10 00 08  mov  %o0, %l2
a0109d68:  40 01 2f b6  call  0xa0155c40
a0109d6c:  90 10 00 1a  mov  %i2, %o0
a0109d70:  80 a6 a0 00  cmp  %i2, 0
a0109d74:  06 80 01 36  bl  0xa010a24c
a0109d78:  a2 10 00 08  mov  %o0, %l1
a0109d7c:  93 2e 20 10  sll  %i0, 0x10, %o1
a0109d80:  40 01 2f b0  call  0xa0155c40
a0109d84:  91 32 60 10  srl  %o1, 0x10, %o0
a0109d88:  92 10 00 08  mov  %o0, %o1
a0109d8c:  40 01 2f 23  call  0xa0155a18
a0109d90:  90 10 00 11  mov  %l1, %o0
a0109d94:  92 10 00 08  mov  %o0, %o1
a0109d98:  40 01 2e 90  call  0xa01557d8
a0109d9c:  90 10 00 12  mov  %l2, %o0
a0109da0:  17 00 06 6b  sethi  %hi(0x19ac00), %o3
a0109da4:  a2 10 00 08  mov  %o0, %l1
a0109da8:  40 01 2f 74  call  0xa0155b78
a0109dac:  d2 02 e0 d0  ld  [ %o3 + 0xd0 ], %o1
a0109db0:  80 a2 20 00  cmp  %o0, 0
a0109db4:  04 80 00 db  ble  0xa010a120
a0109db8:  a0 10 20 05  mov  5, %l0
a0109dbc:  92 10 00 11  mov  %l1, %o1
a0109dc0:  40 01 2e 9c  call  0xa0155830
a0109dc4:  90 10 00 13  mov  %l3, %o0
a0109dc8:  27 00 06 6b  sethi  %hi(0x19ac00), %l3
a0109dcc:  40 01 2e 70  call  0xa015578c
a0109dd0:  d2 04 e0 d4  ld  [ %l3 + 0xd4 ], %o1	! 0x19acd4
a0109dd4:  40 01 2c fa  call  0xa01551bc
a0109dd8:  01 00 00 00  nop
a0109ddc:  a5 2a 20 10  sll  %o0, 0x10, %l2
a0109de0:  9f 34 a0 10  srl  %l2, 0x10, %o7
a0109de4:  98 05 7f fb  add  %l5, -5, %o4
a0109de8:  80 a3 c0 0c  cmp  %o7, %o4
a0109dec:  04 80 00 cd  ble  0xa010a120
a0109df0:  a0 10 00 08  mov  %o0, %l0
a0109df4:  10 80 00 cb  b  0xa010a120
a0109df8:  a0 05 3f fb  add  %l4, -5, %l0
a0109dfc:  37 00 06 6b  sethi  %hi(0x19ac00), %i3
a0109e00:  7f ff 54 dc  call  0xa00df170
a0109e04:  90 16 e0 58  or  %i3, 0x58, %o0	! 0x19ac58
a0109e08:  23 33 c0 47  sethi  %hi(0xcf011c00), %l1
a0109e0c:  e8 04 22 a4  ld  [ %l0 + 0x2a4 ], %l4
a0109e10:  ae 14 60 04  or  %l1, 4, %l7
a0109e14:  aa 10 20 60  mov  0x60, %l5
a0109e18:  d2 15 20 2c  lduh  [ %l4 + 0x2c ], %o1
a0109e1c:  90 14 60 38  or  %l1, 0x38, %o0
a0109e20:  ea 25 c0 00  st  %l5, [ %l7 ]
a0109e24:  7f ff a4 9a  call  0xa00f308c
a0109e28:  01 00 00 00  nop
a0109e2c:  fa 04 22 a4  ld  [ %l0 + 0x2a4 ], %i5
a0109e30:  d2 17 60 2c  lduh  [ %i5 + 0x2c ], %o1
a0109e34:  7f ff a4 96  call  0xa00f308c
a0109e38:  90 14 60 48  or  %l1, 0x48, %o0
a0109e3c:  40 00 4c 53  call  0xa011cf88
a0109e40:  01 00 00 00  nop
a0109e44:  98 0a 20 ff  and  %o0, 0xff, %o4
a0109e48:  80 a3 20 82  cmp  %o4, 0x82
a0109e4c:  08 80 00 06  bleu  0xa0109e64
a0109e50:  90 14 62 40  or  %l1, 0x240, %o0
a0109e54:  f8 02 00 00  ld  [ %o0 ], %i4
a0109e58:  80 8f 20 08  btst  8, %i4
a0109e5c:  12 80 00 e2  bne  0xa010a1e4
a0109e60:  01 00 00 00  nop
a0109e64:  40 00 4c 49  call  0xa011cf88
a0109e68:  01 00 00 00  nop
a0109e6c:  a2 0a 20 ff  and  %o0, 0xff, %l1
a0109e70:  80 a4 60 83  cmp  %l1, 0x83
a0109e74:  08 80 00 07  bleu  0xa0109e90
a0109e78:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a0109e7c:  98 10 62 40  or  %g1, 0x240, %o4	! 0xcf011e40
a0109e80:  e0 03 00 00  ld  [ %o4 ], %l0
a0109e84:  80 8c 20 04  btst  4, %l0
a0109e88:  12 80 00 c6  bne  0xa010a1a0
a0109e8c:  01 00 00 00  nop
a0109e90:  40 00 4c 3e  call  0xa011cf88
a0109e94:  01 00 00 00  nop
a0109e98:  94 0a 20 ff  and  %o0, 0xff, %o2
a0109e9c:  80 a2 a0 83  cmp  %o2, 0x83
a0109ea0:  08 80 00 07  bleu  0xa0109ebc
a0109ea4:  29 33 c0 47  sethi  %hi(0xcf011c00), %l4
a0109ea8:  98 15 22 40  or  %l4, 0x240, %o4	! 0xcf011e40
a0109eac:  fa 03 00 00  ld  [ %o4 ], %i5
a0109eb0:  80 8f 60 02  btst  2, %i5
a0109eb4:  12 80 00 dd  bne  0xa010a228
a0109eb8:  01 00 00 00  nop
a0109ebc:  11 33 c0 46  sethi  %hi(0xcf011800), %o0
a0109ec0:  2d 2a 00 b5  sethi  %hi(0xa802d400), %l6
a0109ec4:  90 12 22 e8  or  %o0, 0x2e8, %o0
a0109ec8:  d2 15 a3 02  lduh  [ %l6 + 0x302 ], %o1
a0109ecc:  7f ff a4 70  call  0xa00f308c
a0109ed0:  23 33 c0 47  sethi  %hi(0xcf011c00), %l1
a0109ed4:  92 14 62 c0  or  %l1, 0x2c0, %o1	! 0xcf011ec0
a0109ed8:  f0 02 40 00  ld  [ %o1 ], %i0
a0109edc:  9e 0e 3f bf  and  %i0, -65, %o7
a0109ee0:  de 22 40 00  st  %o7, [ %o1 ]
a0109ee4:  30 80 00 f1  b,a   0xa010a2a8
a0109ee8:  7f ff e4 3a  call  0xa0102fd0
a0109eec:  90 10 20 00  clr  %o0
a0109ef0:  ad 2a 20 10  sll  %o0, 0x10, %l6
a0109ef4:  b9 3d a0 10  sra  %l6, 0x10, %i4
a0109ef8:  40 01 2f 52  call  0xa0155c40
a0109efc:  90 10 00 1c  mov  %i4, %o0
a0109f00:  80 a7 20 00  cmp  %i4, 0
a0109f04:  06 80 00 b4  bl  0xa010a1d4
a0109f08:  29 00 06 68  sethi  %hi(0x19a000), %l4
a0109f0c:  17 00 06 6b  sethi  %hi(0x19ac00), %o3
a0109f10:  fa 02 e0 cc  ld  [ %o3 + 0xcc ], %i5	! 0x19accc
a0109f14:  40 01 2e 47  call  0xa0155830
a0109f18:  92 10 00 1d  mov  %i5, %o1
a0109f1c:  a6 10 00 08  mov  %o0, %l3
a0109f20:  92 10 20 82  mov  0x82, %o1
a0109f24:  7f ff a1 b5  call  0xa00f25f8
a0109f28:  90 10 20 00  clr  %o0
a0109f2c:  91 2a 20 10  sll  %o0, 0x10, %o0
a0109f30:  40 01 2f 44  call  0xa0155c40
a0109f34:  91 32 20 10  srl  %o0, 0x10, %o0
a0109f38:  92 10 00 08  mov  %o0, %o1
a0109f3c:  40 01 2e b7  call  0xa0155a18
a0109f40:  90 10 00 13  mov  %l3, %o0
a0109f44:  15 00 06 61  sethi  %hi(0x198400), %o2
a0109f48:  ec 02 a3 60  ld  [ %o2 + 0x360 ], %l6	! 0x198760
a0109f4c:  40 01 2e 39  call  0xa0155830
a0109f50:  92 10 00 16  mov  %l6, %o1
a0109f54:  9b 2e e0 10  sll  %i3, 0x10, %o5
a0109f58:  aa 10 00 08  mov  %o0, %l5
a0109f5c:  40 01 2f 39  call  0xa0155c40
a0109f60:  91 33 60 10  srl  %o5, 0x10, %o0
a0109f64:  a6 10 00 08  mov  %o0, %l3
a0109f68:  92 10 00 13  mov  %l3, %o1
a0109f6c:  40 01 2e ab  call  0xa0155a18
a0109f70:  90 10 00 15  mov  %l5, %o0
a0109f74:  40 01 2c 92  call  0xa01551bc
a0109f78:  01 00 00 00  nop
a0109f7c:  a8 10 00 08  mov  %o0, %l4
a0109f80:  92 10 20 62  mov  0x62, %o1
a0109f84:  7f ff a1 9d  call  0xa00f25f8
a0109f88:  90 10 20 00  clr  %o0
a0109f8c:  aa 10 00 08  mov  %o0, %l5
a0109f90:  92 10 20 64  mov  0x64, %o1
a0109f94:  7f ff a1 99  call  0xa00f25f8
a0109f98:  90 10 20 00  clr  %o0
a0109f9c:  b6 10 00 08  mov  %o0, %i3
a0109fa0:  7f ff a4 36  call  0xa00f3078
a0109fa4:  90 16 22 c0  or  %i0, 0x2c0, %o0
a0109fa8:  a0 10 00 08  mov  %o0, %l0
a0109fac:  7f ff a4 33  call  0xa00f3078
a0109fb0:  90 16 22 c8  or  %i0, 0x2c8, %o0
a0109fb4:  a4 10 00 08  mov  %o0, %l2
a0109fb8:  7f ff a4 30  call  0xa00f3078
a0109fbc:  90 16 22 d0  or  %i0, 0x2d0, %o0
a0109fc0:  b8 10 00 08  mov  %o0, %i4
a0109fc4:  7f ff a4 2d  call  0xa00f3078
a0109fc8:  90 16 22 d8  or  %i0, 0x2d8, %o0
a0109fcc:  a2 04 00 12  add  %l0, %l2, %l1
a0109fd0:  82 07 00 11  add  %i4, %l1, %g1
a0109fd4:  a2 02 00 01  add  %o0, %g1, %l1
a0109fd8:  7f ff e3 fe  call  0xa0102fd0
a0109fdc:  90 10 20 04  mov  4, %o0
a0109fe0:  a1 2a 20 10  sll  %o0, 0x10, %l0
a0109fe4:  b1 3c 20 10  sra  %l0, 0x10, %i0
a0109fe8:  40 01 2f 16  call  0xa0155c40
a0109fec:  90 10 00 18  mov  %i0, %o0
a0109ff0:  80 a6 20 00  cmp  %i0, 0
a0109ff4:  06 80 00 a9  bl  0xa010a298
a0109ff8:  b8 10 00 14  mov  %l4, %i4
a0109ffc:  40 01 2e 0d  call  0xa0155830
a010a000:  92 10 00 1d  mov  %i5, %o1
a010a004:  a5 2c 60 10  sll  %l1, 0x10, %l2
a010a008:  a0 10 00 08  mov  %o0, %l0
a010a00c:  40 01 2f 0d  call  0xa0155c40
a010a010:  91 34 a0 10  srl  %l2, 0x10, %o0
a010a014:  92 10 00 08  mov  %o0, %o1
a010a018:  40 01 2e 80  call  0xa0155a18
a010a01c:  90 10 00 10  mov  %l0, %o0
a010a020:  40 01 2e 04  call  0xa0155830
a010a024:  92 10 00 16  mov  %l6, %o1
a010a028:  40 01 2e 7c  call  0xa0155a18
a010a02c:  92 10 00 13  mov  %l3, %o1
a010a030:  40 01 2c 63  call  0xa01551bc
a010a034:  a3 2d 60 10  sll  %l5, 0x10, %l1
a010a038:  b7 2e e0 10  sll  %i3, 0x10, %i3
a010a03c:  83 36 e0 10  srl  %i3, 0x10, %g1
a010a040:  b1 34 60 10  srl  %l1, 0x10, %i0
a010a044:  a4 10 00 08  mov  %o0, %l2
a010a048:  40 01 2e fe  call  0xa0155c40
a010a04c:  90 06 00 01  add  %i0, %g1, %o0
a010a050:  9f 2d 20 10  sll  %l4, 0x10, %o7
a010a054:  ab 33 e0 10  srl  %o7, 0x10, %l5
a010a058:  ac 10 00 08  mov  %o0, %l6
a010a05c:  40 01 2e f9  call  0xa0155c40
a010a060:  90 10 00 15  mov  %l5, %o0
a010a064:  a6 10 00 08  mov  %o0, %l3
a010a068:  90 10 00 16  mov  %l6, %o0
a010a06c:  40 01 2e 6b  call  0xa0155a18
a010a070:  92 10 00 13  mov  %l3, %o1
a010a074:  93 2e a0 10  sll  %i2, 0x10, %o1
a010a078:  bb 3a 60 10  sra  %o1, 0x10, %i5
a010a07c:  b0 10 00 08  mov  %o0, %i0
a010a080:  40 01 2e f0  call  0xa0155c40
a010a084:  90 10 00 1d  mov  %i5, %o0
a010a088:  a2 10 00 08  mov  %o0, %l1
a010a08c:  80 a7 60 00  cmp  %i5, 0
a010a090:  06 80 00 7d  bl  0xa010a284
a010a094:  ac 10 00 12  mov  %l2, %l6
a010a098:  95 2c a0 10  sll  %l2, 0x10, %o2
a010a09c:  40 01 2e e9  call  0xa0155c40
a010a0a0:  91 32 a0 10  srl  %o2, 0x10, %o0
a010a0a4:  92 10 00 08  mov  %o0, %o1
a010a0a8:  40 01 2e 5c  call  0xa0155a18
a010a0ac:  90 10 00 11  mov  %l1, %o0
a010a0b0:  92 10 00 08  mov  %o0, %o1
a010a0b4:  40 01 2d c9  call  0xa01557d8
a010a0b8:  90 10 00 18  mov  %i0, %o0
a010a0bc:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010a0c0:  a2 10 00 08  mov  %o0, %l1
a010a0c4:  40 01 2e ad  call  0xa0155b78
a010a0c8:  d2 03 60 d0  ld  [ %o5 + 0xd0 ], %o1
a010a0cc:  80 a2 20 00  cmp  %o0, 0
a010a0d0:  04 80 00 10  ble  0xa010a110
a010a0d4:  a0 10 20 10  mov  0x10, %l0
a010a0d8:  92 10 00 11  mov  %l1, %o1
a010a0dc:  40 01 2d d5  call  0xa0155830
a010a0e0:  90 10 00 13  mov  %l3, %o0
a010a0e4:  3b 00 06 6b  sethi  %hi(0x19ac00), %i5
a010a0e8:  40 01 2d a9  call  0xa015578c
a010a0ec:  d2 07 60 d8  ld  [ %i5 + 0xd8 ], %o1	! 0x19acd8
a010a0f0:  40 01 2c 33  call  0xa01551bc
a010a0f4:  a6 05 7f f0  add  %l5, -16, %l3
a010a0f8:  99 2a 20 10  sll  %o0, 0x10, %o4
a010a0fc:  97 33 20 10  srl  %o4, 0x10, %o3
a010a100:  80 a2 c0 13  cmp  %o3, %l3
a010a104:  04 80 00 03  ble  0xa010a110
a010a108:  a0 10 00 08  mov  %o0, %l0
a010a10c:  a0 05 3f f0  add  %l4, -16, %l0
a010a110:  a9 2d e0 10  sll  %l7, 0x10, %l4
a010a114:  80 a5 00 1b  cmp  %l4, %i3
a010a118:  18 80 00 3c  bgu  0xa010a208
a010a11c:  93 36 e0 10  srl  %i3, 0x10, %o1
a010a120:  a1 2c 20 10  sll  %l0, 0x10, %l0
a010a124:  a3 34 20 10  srl  %l0, 0x10, %l1
a010a128:  95 2f 20 10  sll  %i4, 0x10, %o2
a010a12c:  97 2d a0 10  sll  %l6, 0x10, %o3
a010a130:  27 00 06 6b  sethi  %hi(0x19ac00), %l3
a010a134:  95 32 a0 10  srl  %o2, 0x10, %o2
a010a138:  97 32 e0 10  srl  %o3, 0x10, %o3
a010a13c:  93 36 e0 10  srl  %i3, 0x10, %o1
a010a140:  98 10 00 11  mov  %l1, %o4
a010a144:  7f ff 54 0b  call  0xa00df170
a010a148:  90 14 e0 70  or  %l3, 0x70, %o0
a010a14c:  2d 33 c0 47  sethi  %hi(0xcf011c00), %l6
a010a150:  90 15 a0 48  or  %l6, 0x48, %o0	! 0xcf011c48
a010a154:  7f ff a3 ce  call  0xa00f308c
a010a158:  92 10 00 11  mov  %l1, %o1
a010a15c:  9a 10 20 a0  mov  0xa0, %o5
a010a160:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a010a164:  b4 15 a0 04  or  %l6, 4, %i2
a010a168:  25 33 c0 46  sethi  %hi(0xcf011800), %l2
a010a16c:  90 14 a2 e8  or  %l2, 0x2e8, %o0	! 0xcf011ae8
a010a170:  92 10 63 ff  or  %g1, 0x3ff, %o1
a010a174:  da 26 80 00  st  %o5, [ %i2 ]
a010a178:  7f ff a3 c5  call  0xa00f308c
a010a17c:  b1 34 20 18  srl  %l0, 0x18, %i0
a010a180:  9e 0c 60 ff  and  %l1, 0xff, %o7
a010a184:  90 0e 20 3f  and  %i0, 0x3f, %o0
a010a188:  92 15 a2 c4  or  %l6, 0x2c4, %o1
a010a18c:  de 22 40 00  st  %o7, [ %o1 ]
a010a190:  b6 15 a2 c0  or  %l6, 0x2c0, %i3
a010a194:  b8 12 20 40  or  %o0, 0x40, %i4
a010a198:  f8 26 c0 00  st  %i4, [ %i3 ]
a010a19c:  30 80 00 43  b,a   0xa010a2a8
a010a1a0:  d6 03 00 00  ld  [ %o4 ], %o3
a010a1a4:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a010a1a8:  a6 0a ff f5  and  %o3, -11, %l3
a010a1ac:  e4 13 63 02  lduh  [ %o5 + 0x302 ], %l2
a010a1b0:  35 33 c0 46  sethi  %hi(0xcf011800), %i2
a010a1b4:  e6 23 00 00  st  %l3, [ %o4 ]
a010a1b8:  90 16 a2 e8  or  %i2, 0x2e8, %o0
a010a1bc:  10 bf ff 44  b  0xa0109ecc
a010a1c0:  93 34 a0 02  srl  %l2, 2, %o1
a010a1c4:  40 01 2d 72  call  0xa015578c
a010a1c8:  d2 02 e2 d0  ld  [ %o3 + 0x2d0 ], %o1
a010a1cc:  10 bf fe 98  b  0xa0109c2c
a010a1d0:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010a1d4:  40 01 2d 6e  call  0xa015578c
a010a1d8:  d2 05 22 d0  ld  [ %l4 + 0x2d0 ], %o1
a010a1dc:  10 bf ff 4d  b  0xa0109f10
a010a1e0:  17 00 06 6b  sethi  %hi(0x19ac00), %o3
a010a1e4:  f0 02 00 00  ld  [ %o0 ], %i0
a010a1e8:  92 0e 3f f9  and  %i0, -7, %o1
a010a1ec:  d2 22 00 00  st  %o1, [ %o0 ]
a010a1f0:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a010a1f4:  ec 13 e3 02  lduh  [ %o7 + 0x302 ], %l6	! 0xa802d702
a010a1f8:  11 33 c0 46  sethi  %hi(0xcf011800), %o0
a010a1fc:  90 12 22 e8  or  %o0, 0x2e8, %o0	! 0xcf011ae8
a010a200:  10 bf ff 33  b  0xa0109ecc
a010a204:  93 35 a0 01  srl  %l6, 1, %o1
a010a208:  af 36 e0 11  srl  %i3, 0x11, %l7
a010a20c:  2b 00 06 9c  sethi  %hi(0x1a7000), %l5
a010a210:  90 15 60 18  or  %l5, 0x18, %o0	! 0x1a7018
a010a214:  94 10 00 17  mov  %l7, %o2
a010a218:  7f ff 53 d6  call  0xa00df170
a010a21c:  a0 10 00 17  mov  %l7, %l0
a010a220:  10 bf ff c1  b  0xa010a124
a010a224:  a1 2c 20 10  sll  %l0, 0x10, %l0
a010a228:  f8 03 00 00  ld  [ %o4 ], %i4
a010a22c:  aa 0f 3f f3  and  %i4, -13, %l5
a010a230:  37 2a 00 b5  sethi  %hi(0xa802d400), %i3
a010a234:  ea 23 00 00  st  %l5, [ %o4 ]
a010a238:  ee 16 e3 02  lduh  [ %i3 + 0x302 ], %l7
a010a23c:  19 33 c0 46  sethi  %hi(0xcf011800), %o4
a010a240:  90 13 22 e8  or  %o4, 0x2e8, %o0	! 0xcf011ae8
a010a244:  10 bf ff 22  b  0xa0109ecc
a010a248:  93 35 e0 03  srl  %l7, 3, %o1
a010a24c:  15 00 06 68  sethi  %hi(0x19a000), %o2
a010a250:  40 01 2d 4f  call  0xa015578c
a010a254:  d2 02 a2 d0  ld  [ %o2 + 0x2d0 ], %o1	! 0x19a2d0
a010a258:  10 bf fe c9  b  0xa0109d7c
a010a25c:  a2 10 00 08  mov  %o0, %l1
a010a260:  23 00 06 68  sethi  %hi(0x19a000), %l1
a010a264:  40 01 2d 4a  call  0xa015578c
a010a268:  d2 04 62 d0  ld  [ %l1 + 0x2d0 ], %o1	! 0x19a2d0
a010a26c:  10 bf fe b4  b  0xa0109d3c
a010a270:  a2 10 00 08  mov  %o0, %l1
a010a274:  3b 00 06 68  sethi  %hi(0x19a000), %i5
a010a278:  40 01 2d 45  call  0xa015578c
a010a27c:  d2 07 62 d0  ld  [ %i5 + 0x2d0 ], %o1	! 0x19a2d0
a010a280:  30 bf fe 98  b,a   0xa0109ce0
a010a284:  35 00 06 68  sethi  %hi(0x19a000), %i2
a010a288:  40 01 2d 41  call  0xa015578c
a010a28c:  d2 06 a2 d0  ld  [ %i2 + 0x2d0 ], %o1	! 0x19a2d0
a010a290:  10 bf ff 82  b  0xa010a098
a010a294:  a2 10 00 08  mov  %o0, %l1
a010a298:  19 00 06 68  sethi  %hi(0x19a000), %o4
a010a29c:  40 01 2d 3c  call  0xa015578c
a010a2a0:  d2 03 22 d0  ld  [ %o4 + 0x2d0 ], %o1	! 0x19a2d0
a010a2a4:  30 bf ff 56  b,a   0xa0109ffc
a010a2a8:  81 c7 e0 08  ret
a010a2ac:  81 e8 00 00  restore
