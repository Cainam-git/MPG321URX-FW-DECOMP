# leon2s DRV_HDMI_InitialSettings 0xa0073c44-0xa0074bf8 (4020 bytes)
a0073c44:  9d e3 bf 68  save  %sp, -152, %sp
a0073c48:  21 2a 01 e1  sethi  %hi(0xa8078400), %l0
a0073c4c:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1	! 0xa8078634
a0073c50:  80 88 60 01  btst  1, %g1
a0073c54:  22 80 00 08  be,a   0xa0073c74
a0073c58:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0073c5c:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a0073c60:  13 28 02 cf  sethi  %hi(0xa00b3c00), %o1
a0073c64:  90 12 20 38  or  %o0, 0x38, %o0
a0073c68:  7f ff fc f7  call  0xa0073044
a0073c6c:  92 12 60 38  or  %o1, 0x38, %o1
a0073c70:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0073c74:  c2 08 61 9f  ldub  [ %g1 + 0x19f ], %g1	! 0xa807619f
a0073c78:  80 a0 60 00  cmp  %g1, 0
a0073c7c:  02 80 00 08  be  0xa0073c9c
a0073c80:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1
a0073c84:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a0073c88:  80 88 60 01  btst  1, %g1
a0073c8c:  12 80 00 09  bne  0xa0073cb0
a0073c90:  90 12 20 48  or  %o0, 0x48, %o0
a0073c94:  10 80 00 0a  b  0xa0073cbc
a0073c98:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a0073c9c:  80 88 60 01  btst  1, %g1
a0073ca0:  02 80 00 07  be  0xa0073cbc
a0073ca4:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a0073ca8:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a0073cac:  90 12 20 60  or  %o0, 0x60, %o0	! 0xa0066860
a0073cb0:  7f ff fe 05  call  0xa00734c4
a0073cb4:  01 00 00 00  nop
a0073cb8:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a0073cbc:  82 10 61 14  or  %g1, 0x114, %g1	! 0xcf011514
a0073cc0:  da 00 40 00  ld  [ %g1 ], %o5
a0073cc4:  9a 13 60 03  or  %o5, 3, %o5
a0073cc8:  21 00 00 0d  sethi  %hi(0x3400), %l0
a0073ccc:  da 20 40 00  st  %o5, [ %g1 ]
a0073cd0:  90 10 20 01  mov  1, %o0
a0073cd4:  92 10 20 00  clr  %o1
a0073cd8:  94 10 20 02  mov  2, %o2
a0073cdc:  40 00 cd d2  call  0xa00a7424
a0073ce0:  96 14 21 34  or  %l0, 0x134, %o3
a0073ce4:  96 14 21 34  or  %l0, 0x134, %o3
a0073ce8:  90 10 20 01  mov  1, %o0
a0073cec:  92 10 20 00  clr  %o1
a0073cf0:  40 00 cd cd  call  0xa00a7424
a0073cf4:  94 10 20 03  mov  3, %o2
a0073cf8:  ae 10 20 00  clr  %l7
a0073cfc:  a0 0d e0 ff  and  %l7, 0xff, %l0
a0073d00:  90 10 00 10  mov  %l0, %o0
a0073d04:  13 00 00 04  sethi  %hi(0x1000), %o1
a0073d08:  94 10 3f 00  mov  -256, %o2
a0073d0c:  40 00 cd df  call  0xa00a7488
a0073d10:  96 10 20 f9  mov  0xf9, %o3
a0073d14:  13 00 00 07  sethi  %hi(0x1c00), %o1
a0073d18:  90 10 00 10  mov  %l0, %o0
a0073d1c:  92 12 63 04  or  %o1, 0x304, %o1
a0073d20:  94 10 3f 00  mov  -256, %o2
a0073d24:  40 00 cd d9  call  0xa00a7488
a0073d28:  96 10 20 5f  mov  0x5f, %o3
a0073d2c:  ae 05 e0 01  inc  %l7
a0073d30:  82 0d e0 ff  and  %l7, 0xff, %g1
a0073d34:  80 a0 60 03  cmp  %g1, 3
a0073d38:  08 bf ff f2  bleu  0xa0073d00
a0073d3c:  a0 0d e0 ff  and  %l7, 0xff, %l0
a0073d40:  ae 10 20 00  clr  %l7
a0073d44:  ac 0d e0 ff  and  %l7, 0xff, %l6
a0073d48:  7f ff fd f6  call  0xa0073520
a0073d4c:  90 10 00 16  mov  %l6, %o0
a0073d50:  ba 0a 20 ff  and  %o0, 0xff, %i5
a0073d54:  80 a7 60 00  cmp  %i5, 0
a0073d58:  02 80 00 19  be  0xa0073dbc
a0073d5c:  13 00 00 04  sethi  %hi(0x1000), %o1
a0073d60:  21 00 00 0d  sethi  %hi(0x3400), %l0
a0073d64:  90 10 20 01  mov  1, %o0
a0073d68:  92 10 20 10  mov  0x10, %o1
a0073d6c:  94 10 00 16  mov  %l6, %o2
a0073d70:  40 00 cd ad  call  0xa00a7424
a0073d74:  96 14 22 1c  or  %l0, 0x21c, %o3
a0073d78:  90 10 20 01  mov  1, %o0
a0073d7c:  92 10 20 11  mov  0x11, %o1
a0073d80:  94 10 00 16  mov  %l6, %o2
a0073d84:  40 00 cd a8  call  0xa00a7424
a0073d88:  96 14 22 1c  or  %l0, 0x21c, %o3
a0073d8c:  90 10 20 01  mov  1, %o0
a0073d90:  92 10 20 12  mov  0x12, %o1
a0073d94:  94 10 00 16  mov  %l6, %o2
a0073d98:  40 00 cd a3  call  0xa00a7424
a0073d9c:  96 14 22 1c  or  %l0, 0x21c, %o3
a0073da0:  15 3f e3 ff  sethi  %hi(0xff8ffc00), %o2
a0073da4:  90 10 00 16  mov  %l6, %o0
a0073da8:  92 14 22 1c  or  %l0, 0x21c, %o1
a0073dac:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0073db0:  40 00 cd b6  call  0xa00a7488
a0073db4:  17 00 18 00  sethi  %hi(0x600000), %o3
a0073db8:  13 00 00 04  sethi  %hi(0x1000), %o1
a0073dbc:  15 3f 3f ff  sethi  %hi(0xfcfffc00), %o2
a0073dc0:  92 12 61 04  or  %o1, 0x104, %o1
a0073dc4:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0073dc8:  90 10 20 00  clr  %o0
a0073dcc:  40 00 cd af  call  0xa00a7488
a0073dd0:  17 00 c0 00  sethi  %hi(0x3000000), %o3
a0073dd4:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a0073dd8:  80 a5 a0 00  cmp  %l6, 0
a0073ddc:  02 80 00 0e  be  0xa0073e14
a0073de0:  a4 10 62 99  or  %g1, 0x299, %l2
a0073de4:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a0073de8:  80 a5 a0 01  cmp  %l6, 1
a0073dec:  02 80 00 0a  be  0xa0073e14
a0073df0:  a4 10 62 a9  or  %g1, 0x2a9, %l2
a0073df4:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a0073df8:  80 a5 a0 02  cmp  %l6, 2
a0073dfc:  02 80 00 64  be  0xa0073f8c
a0073e00:  a4 10 62 b9  or  %g1, 0x2b9, %l2
a0073e04:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a0073e08:  80 a5 a0 01  cmp  %l6, 1
a0073e0c:  18 80 00 60  bgu  0xa0073f8c
a0073e10:  a4 10 62 e9  or  %g1, 0x2e9, %l2
a0073e14:  c2 0c 80 00  ldub  [ %l2 ], %g1
a0073e18:  80 a0 60 a0  cmp  %g1, 0xa0
a0073e1c:  12 80 00 33  bne  0xa0073ee8
a0073e20:  21 2a 01 e1  sethi  %hi(0xa8078400), %l0
a0073e24:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1	! 0xa8078634
a0073e28:  80 88 60 01  btst  1, %g1
a0073e2c:  02 80 00 09  be  0xa0073e50
a0073e30:  21 00 00 07  sethi  %hi(0x1c00), %l0
a0073e34:  92 05 e0 41  add  %l7, 0x41, %o1
a0073e38:  93 2a 60 18  sll  %o1, 0x18, %o1
a0073e3c:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a0073e40:  90 12 20 78  or  %o0, 0x78, %o0	! 0xa0066878
a0073e44:  7f ff fc 80  call  0xa0073044
a0073e48:  93 3a 60 18  sra  %o1, 0x18, %o1
a0073e4c:  21 00 00 07  sethi  %hi(0x1c00), %l0
a0073e50:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a0073e54:  92 14 20 08  or  %l0, 8, %o1
a0073e58:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0073e5c:  e6 0c a0 03  ldub  [ %l2 + 3 ], %l3
a0073e60:  90 10 00 16  mov  %l6, %o0
a0073e64:  40 00 cd 89  call  0xa00a7488
a0073e68:  17 18 00 00  sethi  %hi(0x60000000), %o3
a0073e6c:  92 14 20 08  or  %l0, 8, %o1
a0073e70:  90 10 00 16  mov  %l6, %o0
a0073e74:  96 0c e0 ff  and  %l3, 0xff, %o3
a0073e78:  40 00 cd 84  call  0xa00a7488
a0073e7c:  94 10 3f 00  mov  -256, %o2
a0073e80:  d6 0c a0 0d  ldub  [ %l2 + 0xd ], %o3
a0073e84:  21 07 c0 00  sethi  %hi(0x1f000000), %l0
a0073e88:  23 00 00 3f  sethi  %hi(0xfc00), %l1
a0073e8c:  97 2a e0 10  sll  %o3, 0x10, %o3
a0073e90:  13 00 00 04  sethi  %hi(0x1000), %o1
a0073e94:  92 12 60 3c  or  %o1, 0x3c, %o1	! 0x103c
a0073e98:  96 12 c0 10  or  %o3, %l0, %o3
a0073e9c:  90 10 00 16  mov  %l6, %o0
a0073ea0:  40 00 cd 7a  call  0xa00a7488
a0073ea4:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0073ea8:  d6 0c a0 0e  ldub  [ %l2 + 0xe ], %o3
a0073eac:  97 2a e0 10  sll  %o3, 0x10, %o3
a0073eb0:  13 00 00 05  sethi  %hi(0x1400), %o1
a0073eb4:  92 12 60 3c  or  %o1, 0x3c, %o1	! 0x143c
a0073eb8:  96 12 c0 10  or  %o3, %l0, %o3
a0073ebc:  90 10 00 16  mov  %l6, %o0
a0073ec0:  40 00 cd 72  call  0xa00a7488
a0073ec4:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0073ec8:  d6 0c a0 0f  ldub  [ %l2 + 0xf ], %o3
a0073ecc:  97 2a e0 10  sll  %o3, 0x10, %o3
a0073ed0:  13 00 00 06  sethi  %hi(0x1800), %o1
a0073ed4:  96 12 c0 10  or  %o3, %l0, %o3
a0073ed8:  90 10 00 16  mov  %l6, %o0
a0073edc:  92 12 60 3c  or  %o1, 0x3c, %o1
a0073ee0:  10 80 01 69  b  0xa0074484
a0073ee4:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0073ee8:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1
a0073eec:  80 88 60 01  btst  1, %g1
a0073ef0:  02 80 00 09  be  0xa0073f14
a0073ef4:  21 00 00 07  sethi  %hi(0x1c00), %l0
a0073ef8:  92 05 e0 41  add  %l7, 0x41, %o1
a0073efc:  93 2a 60 18  sll  %o1, 0x18, %o1
a0073f00:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a0073f04:  90 12 20 a8  or  %o0, 0xa8, %o0	! 0xa00668a8
a0073f08:  7f ff fc 4f  call  0xa0073044
a0073f0c:  93 3a 60 18  sra  %o1, 0x18, %o1
a0073f10:  21 00 00 07  sethi  %hi(0x1c00), %l0
a0073f14:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a0073f18:  92 14 20 08  or  %l0, 8, %o1
a0073f1c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0073f20:  90 10 00 16  mov  %l6, %o0
a0073f24:  40 00 cd 59  call  0xa00a7488
a0073f28:  17 18 00 00  sethi  %hi(0x60000000), %o3
a0073f2c:  92 14 20 08  or  %l0, 8, %o1
a0073f30:  90 10 00 16  mov  %l6, %o0
a0073f34:  94 10 3f 00  mov  -256, %o2
a0073f38:  40 00 cd 54  call  0xa00a7488
a0073f3c:  96 10 20 09  mov  9, %o3
a0073f40:  21 00 00 3f  sethi  %hi(0xfc00), %l0
a0073f44:  13 00 00 04  sethi  %hi(0x1000), %o1
a0073f48:  90 10 00 16  mov  %l6, %o0
a0073f4c:  92 12 60 3c  or  %o1, 0x3c, %o1
a0073f50:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0073f54:  40 00 cd 4d  call  0xa00a7488
a0073f58:  17 07 c4 00  sethi  %hi(0x1f100000), %o3
a0073f5c:  13 00 00 05  sethi  %hi(0x1400), %o1
a0073f60:  90 10 00 16  mov  %l6, %o0
a0073f64:  92 12 60 3c  or  %o1, 0x3c, %o1
a0073f68:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0073f6c:  40 00 cd 47  call  0xa00a7488
a0073f70:  17 07 c4 00  sethi  %hi(0x1f100000), %o3
a0073f74:  13 00 00 06  sethi  %hi(0x1800), %o1
a0073f78:  90 10 00 16  mov  %l6, %o0
a0073f7c:  92 12 60 3c  or  %o1, 0x3c, %o1
a0073f80:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0073f84:  10 80 01 40  b  0xa0074484
a0073f88:  17 07 c4 00  sethi  %hi(0x1f100000), %o3
a0073f8c:  c0 37 bf f0  clrh  [ %fp + -16 ]
a0073f90:  c0 2f bf f2  clrb  [ %fp + -14 ]
a0073f94:  c0 27 bf e8  clr  [ %fp + -24 ]
a0073f98:  c0 27 bf e0  clr  [ %fp + -32 ]
a0073f9c:  c0 27 bf d8  clr  [ %fp + -40 ]
a0073fa0:  c0 27 bf d0  clr  [ %fp + -48 ]
a0073fa4:  c0 27 bf c8  clr  [ %fp + -56 ]
a0073fa8:  c2 0c 80 00  ldub  [ %l2 ], %g1
a0073fac:  80 a0 60 a0  cmp  %g1, 0xa0
a0073fb0:  12 80 00 3c  bne  0xa00740a0
a0073fb4:  21 2a 01 e1  sethi  %hi(0xa8078400), %l0
a0073fb8:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1	! 0xa8078634
a0073fbc:  80 88 60 01  btst  1, %g1
a0073fc0:  22 80 00 09  be,a   0xa0073fe4
a0073fc4:  c2 0c a0 10  ldub  [ %l2 + 0x10 ], %g1
a0073fc8:  92 05 e0 41  add  %l7, 0x41, %o1
a0073fcc:  93 2a 60 18  sll  %o1, 0x18, %o1
a0073fd0:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a0073fd4:  90 12 20 d8  or  %o0, 0xd8, %o0	! 0xa00668d8
a0073fd8:  7f ff fc 1b  call  0xa0073044
a0073fdc:  93 3a 60 18  sra  %o1, 0x18, %o1
a0073fe0:  c2 0c a0 10  ldub  [ %l2 + 0x10 ], %g1
a0073fe4:  e6 0c a0 03  ldub  [ %l2 + 3 ], %l3
a0073fe8:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a0073fec:  c2 0c a0 11  ldub  [ %l2 + 0x11 ], %g1
a0073ff0:  c2 2f bf f1  stb  %g1, [ %fp + -15 ]
a0073ff4:  c2 0c a0 12  ldub  [ %l2 + 0x12 ], %g1
a0073ff8:  c2 2f bf f2  stb  %g1, [ %fp + -14 ]
a0073ffc:  c2 0c a0 10  ldub  [ %l2 + 0x10 ], %g1
a0074000:  c2 2f bf e8  stb  %g1, [ %fp + -24 ]
a0074004:  c2 0c a0 11  ldub  [ %l2 + 0x11 ], %g1
a0074008:  c2 2f bf e9  stb  %g1, [ %fp + -23 ]
a007400c:  c2 0c a0 12  ldub  [ %l2 + 0x12 ], %g1
a0074010:  c2 2f bf ea  stb  %g1, [ %fp + -22 ]
a0074014:  c2 0c a0 13  ldub  [ %l2 + 0x13 ], %g1
a0074018:  c2 2f bf eb  stb  %g1, [ %fp + -21 ]
a007401c:  c2 0c a0 14  ldub  [ %l2 + 0x14 ], %g1
a0074020:  c2 2f bf e0  stb  %g1, [ %fp + -32 ]
a0074024:  c2 0c a0 15  ldub  [ %l2 + 0x15 ], %g1
a0074028:  c2 2f bf e1  stb  %g1, [ %fp + -31 ]
a007402c:  c2 0c a0 16  ldub  [ %l2 + 0x16 ], %g1
a0074030:  c2 2f bf e2  stb  %g1, [ %fp + -30 ]
a0074034:  c2 0c a0 17  ldub  [ %l2 + 0x17 ], %g1
a0074038:  c2 2f bf e3  stb  %g1, [ %fp + -29 ]
a007403c:  c2 0c a0 18  ldub  [ %l2 + 0x18 ], %g1
a0074040:  c2 2f bf d8  stb  %g1, [ %fp + -40 ]
a0074044:  c2 0c a0 19  ldub  [ %l2 + 0x19 ], %g1
a0074048:  c2 2f bf d9  stb  %g1, [ %fp + -39 ]
a007404c:  c2 0c a0 1a  ldub  [ %l2 + 0x1a ], %g1
a0074050:  c2 2f bf da  stb  %g1, [ %fp + -38 ]
a0074054:  c2 0c a0 1b  ldub  [ %l2 + 0x1b ], %g1
a0074058:  c2 2f bf db  stb  %g1, [ %fp + -37 ]
a007405c:  c2 0c a0 1c  ldub  [ %l2 + 0x1c ], %g1
a0074060:  c2 2f bf d0  stb  %g1, [ %fp + -48 ]
a0074064:  c2 0c a0 1d  ldub  [ %l2 + 0x1d ], %g1
a0074068:  c2 2f bf d1  stb  %g1, [ %fp + -47 ]
a007406c:  c2 0c a0 1e  ldub  [ %l2 + 0x1e ], %g1
a0074070:  c2 2f bf d2  stb  %g1, [ %fp + -46 ]
a0074074:  c2 0c a0 1f  ldub  [ %l2 + 0x1f ], %g1
a0074078:  c2 2f bf d3  stb  %g1, [ %fp + -45 ]
a007407c:  c2 0c a0 20  ldub  [ %l2 + 0x20 ], %g1
a0074080:  c2 2f bf c8  stb  %g1, [ %fp + -56 ]
a0074084:  c2 0c a0 21  ldub  [ %l2 + 0x21 ], %g1
a0074088:  c2 2f bf c9  stb  %g1, [ %fp + -55 ]
a007408c:  c2 0c a0 22  ldub  [ %l2 + 0x22 ], %g1
a0074090:  c2 2f bf ca  stb  %g1, [ %fp + -54 ]
a0074094:  c2 0c a0 23  ldub  [ %l2 + 0x23 ], %g1
a0074098:  10 80 00 25  b  0xa007412c
a007409c:  c2 2f bf cb  stb  %g1, [ %fp + -53 ]
a00740a0:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1
a00740a4:  80 88 60 01  btst  1, %g1
a00740a8:  02 80 00 09  be  0xa00740cc
a00740ac:  82 10 20 10  mov  0x10, %g1
a00740b0:  92 05 e0 41  add  %l7, 0x41, %o1
a00740b4:  93 2a 60 18  sll  %o1, 0x18, %o1
a00740b8:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a00740bc:  90 12 21 08  or  %o0, 0x108, %o0	! 0xa0066908
a00740c0:  7f ff fb e1  call  0xa0073044
a00740c4:  93 3a 60 18  sra  %o1, 0x18, %o1
a00740c8:  82 10 20 10  mov  0x10, %g1
a00740cc:  c2 2f bf cb  stb  %g1, [ %fp + -53 ]
a00740d0:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a00740d4:  c2 2f bf f1  stb  %g1, [ %fp + -15 ]
a00740d8:  c2 2f bf f2  stb  %g1, [ %fp + -14 ]
a00740dc:  c2 2f bf e8  stb  %g1, [ %fp + -24 ]
a00740e0:  c2 2f bf e9  stb  %g1, [ %fp + -23 ]
a00740e4:  c2 2f bf ea  stb  %g1, [ %fp + -22 ]
a00740e8:  c2 2f bf eb  stb  %g1, [ %fp + -21 ]
a00740ec:  c2 2f bf e0  stb  %g1, [ %fp + -32 ]
a00740f0:  c2 2f bf e1  stb  %g1, [ %fp + -31 ]
a00740f4:  c2 2f bf e2  stb  %g1, [ %fp + -30 ]
a00740f8:  c2 2f bf e3  stb  %g1, [ %fp + -29 ]
a00740fc:  c2 2f bf d8  stb  %g1, [ %fp + -40 ]
a0074100:  c2 2f bf d9  stb  %g1, [ %fp + -39 ]
a0074104:  c2 2f bf da  stb  %g1, [ %fp + -38 ]
a0074108:  c2 2f bf db  stb  %g1, [ %fp + -37 ]
a007410c:  c2 2f bf d0  stb  %g1, [ %fp + -48 ]
a0074110:  c2 2f bf d1  stb  %g1, [ %fp + -47 ]
a0074114:  c2 2f bf d2  stb  %g1, [ %fp + -46 ]
a0074118:  c2 2f bf d3  stb  %g1, [ %fp + -45 ]
a007411c:  c2 2f bf c8  stb  %g1, [ %fp + -56 ]
a0074120:  c2 2f bf c9  stb  %g1, [ %fp + -55 ]
a0074124:  c2 2f bf ca  stb  %g1, [ %fp + -54 ]
a0074128:  a6 10 20 09  mov  9, %l3
a007412c:  25 00 00 07  sethi  %hi(0x1c00), %l2
a0074130:  21 00 3f ff  sethi  %hi(0xfffc00), %l0
a0074134:  92 14 a0 08  or  %l2, 8, %o1
a0074138:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007413c:  90 10 00 16  mov  %l6, %o0
a0074140:  40 00 cc d2  call  0xa00a7488
a0074144:  17 18 00 00  sethi  %hi(0x60000000), %o3
a0074148:  23 00 00 0b  sethi  %hi(0x2c00), %l1
a007414c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0074150:  92 14 60 08  or  %l1, 8, %o1
a0074154:  90 10 00 16  mov  %l6, %o0
a0074158:  40 00 cc cc  call  0xa00a7488
a007415c:  17 18 00 00  sethi  %hi(0x60000000), %o3
a0074160:  a0 0c e0 ff  and  %l3, 0xff, %l0
a0074164:  92 14 a0 08  or  %l2, 8, %o1
a0074168:  96 10 00 10  mov  %l0, %o3
a007416c:  90 10 00 16  mov  %l6, %o0
a0074170:  40 00 cc c6  call  0xa00a7488
a0074174:  94 10 3f 00  mov  -256, %o2
a0074178:  92 14 60 08  or  %l1, 8, %o1
a007417c:  96 10 00 10  mov  %l0, %o3
a0074180:  90 10 00 16  mov  %l6, %o0
a0074184:  40 00 cc c1  call  0xa00a7488
a0074188:  94 10 3f 00  mov  -256, %o2
a007418c:  d6 0f bf f0  ldub  [ %fp + -16 ], %o3
a0074190:  21 07 c0 00  sethi  %hi(0x1f000000), %l0
a0074194:  23 00 00 3f  sethi  %hi(0xfc00), %l1
a0074198:  97 2a e0 10  sll  %o3, 0x10, %o3
a007419c:  13 00 00 04  sethi  %hi(0x1000), %o1
a00741a0:  96 12 c0 10  or  %o3, %l0, %o3
a00741a4:  92 12 60 3c  or  %o1, 0x3c, %o1
a00741a8:  90 10 00 16  mov  %l6, %o0
a00741ac:  40 00 cc b7  call  0xa00a7488
a00741b0:  94 14 63 ff  or  %l1, 0x3ff, %o2
a00741b4:  d6 0f bf f1  ldub  [ %fp + -15 ], %o3
a00741b8:  97 2a e0 10  sll  %o3, 0x10, %o3
a00741bc:  13 00 00 05  sethi  %hi(0x1400), %o1
a00741c0:  96 12 c0 10  or  %o3, %l0, %o3
a00741c4:  92 12 60 3c  or  %o1, 0x3c, %o1
a00741c8:  90 10 00 16  mov  %l6, %o0
a00741cc:  40 00 cc af  call  0xa00a7488
a00741d0:  94 14 63 ff  or  %l1, 0x3ff, %o2
a00741d4:  d6 0f bf f2  ldub  [ %fp + -14 ], %o3
a00741d8:  97 2a e0 10  sll  %o3, 0x10, %o3
a00741dc:  13 00 00 06  sethi  %hi(0x1800), %o1
a00741e0:  96 12 c0 10  or  %o3, %l0, %o3
a00741e4:  92 12 60 3c  or  %o1, 0x3c, %o1
a00741e8:  90 10 00 16  mov  %l6, %o0
a00741ec:  40 00 cc a7  call  0xa00a7488
a00741f0:  94 14 63 ff  or  %l1, 0x3ff, %o2
a00741f4:  d6 0f bf e8  ldub  [ %fp + -24 ], %o3
a00741f8:  2b 00 00 08  sethi  %hi(0x2000), %l5
a00741fc:  97 2a e0 10  sll  %o3, 0x10, %o3
a0074200:  96 12 c0 10  or  %o3, %l0, %o3
a0074204:  90 10 00 16  mov  %l6, %o0
a0074208:  92 15 60 3c  or  %l5, 0x3c, %o1
a007420c:  40 00 cc 9f  call  0xa00a7488
a0074210:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0074214:  d6 0f bf e9  ldub  [ %fp + -23 ], %o3
a0074218:  29 00 00 09  sethi  %hi(0x2400), %l4
a007421c:  97 2a e0 10  sll  %o3, 0x10, %o3
a0074220:  96 12 c0 10  or  %o3, %l0, %o3
a0074224:  90 10 00 16  mov  %l6, %o0
a0074228:  92 15 20 3c  or  %l4, 0x3c, %o1
a007422c:  40 00 cc 97  call  0xa00a7488
a0074230:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0074234:  d6 0f bf ea  ldub  [ %fp + -22 ], %o3
a0074238:  a4 04 ac 00  add  %l2, 0xc00, %l2
a007423c:  97 2a e0 10  sll  %o3, 0x10, %o3
a0074240:  96 12 c0 10  or  %o3, %l0, %o3
a0074244:  90 10 00 16  mov  %l6, %o0
a0074248:  92 14 a0 3c  or  %l2, 0x3c, %o1
a007424c:  40 00 cc 8f  call  0xa00a7488
a0074250:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0074254:  d6 0f bf eb  ldub  [ %fp + -21 ], %o3
a0074258:  27 00 00 0c  sethi  %hi(0x3000), %l3
a007425c:  97 2a e0 10  sll  %o3, 0x10, %o3
a0074260:  96 12 c0 10  or  %o3, %l0, %o3
a0074264:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0074268:  90 10 00 16  mov  %l6, %o0
a007426c:  40 00 cc 87  call  0xa00a7488
a0074270:  92 14 e0 3c  or  %l3, 0x3c, %o1
a0074274:  90 10 00 16  mov  %l6, %o0
a0074278:  92 15 60 34  or  %l5, 0x34, %o1
a007427c:  94 10 3f ff  mov  -1, %o2
a0074280:  40 00 cc 82  call  0xa00a7488
a0074284:  17 3c 00 00  sethi  %hi(0xf0000000), %o3
a0074288:  90 10 00 16  mov  %l6, %o0
a007428c:  92 15 20 34  or  %l4, 0x34, %o1
a0074290:  94 10 3f ff  mov  -1, %o2
a0074294:  40 00 cc 7d  call  0xa00a7488
a0074298:  17 3c 00 00  sethi  %hi(0xf0000000), %o3
a007429c:  90 10 00 16  mov  %l6, %o0
a00742a0:  92 14 a0 34  or  %l2, 0x34, %o1
a00742a4:  94 10 3f ff  mov  -1, %o2
a00742a8:  40 00 cc 78  call  0xa00a7488
a00742ac:  17 3c 00 00  sethi  %hi(0xf0000000), %o3
a00742b0:  90 10 00 16  mov  %l6, %o0
a00742b4:  92 14 e0 34  or  %l3, 0x34, %o1
a00742b8:  94 10 3f ff  mov  -1, %o2
a00742bc:  40 00 cc 73  call  0xa00a7488
a00742c0:  17 3c 00 00  sethi  %hi(0xf0000000), %o3
a00742c4:  d6 0f bf e0  ldub  [ %fp + -32 ], %o3
a00742c8:  21 3f ff c1  sethi  %hi(0xffff0400), %l0
a00742cc:  96 0a e0 1f  and  %o3, 0x1f, %o3
a00742d0:  97 2a e0 0b  sll  %o3, 0xb, %o3
a00742d4:  90 10 00 16  mov  %l6, %o0
a00742d8:  92 15 60 54  or  %l5, 0x54, %o1
a00742dc:  40 00 cc 6b  call  0xa00a7488
a00742e0:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00742e4:  d6 0f bf e1  ldub  [ %fp + -31 ], %o3
a00742e8:  96 0a e0 1f  and  %o3, 0x1f, %o3
a00742ec:  97 2a e0 0b  sll  %o3, 0xb, %o3
a00742f0:  90 10 00 16  mov  %l6, %o0
a00742f4:  92 15 20 54  or  %l4, 0x54, %o1
a00742f8:  40 00 cc 64  call  0xa00a7488
a00742fc:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0074300:  d6 0f bf e2  ldub  [ %fp + -30 ], %o3
a0074304:  96 0a e0 1f  and  %o3, 0x1f, %o3
a0074308:  97 2a e0 0b  sll  %o3, 0xb, %o3
a007430c:  90 10 00 16  mov  %l6, %o0
a0074310:  92 14 a0 54  or  %l2, 0x54, %o1
a0074314:  40 00 cc 5d  call  0xa00a7488
a0074318:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007431c:  d6 0f bf e3  ldub  [ %fp + -29 ], %o3
a0074320:  96 0a e0 1f  and  %o3, 0x1f, %o3
a0074324:  97 2a e0 0b  sll  %o3, 0xb, %o3
a0074328:  90 10 00 16  mov  %l6, %o0
a007432c:  92 14 e0 54  or  %l3, 0x54, %o1
a0074330:  40 00 cc 56  call  0xa00a7488
a0074334:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0074338:  d6 0f bf d8  ldub  [ %fp + -40 ], %o3
a007433c:  96 0a e0 1f  and  %o3, 0x1f, %o3
a0074340:  97 2a e0 03  sll  %o3, 3, %o3
a0074344:  90 10 00 16  mov  %l6, %o0
a0074348:  92 15 60 68  or  %l5, 0x68, %o1
a007434c:  40 00 cc 4f  call  0xa00a7488
a0074350:  94 10 3f 07  mov  -249, %o2
a0074354:  d6 0f bf d9  ldub  [ %fp + -39 ], %o3
a0074358:  96 0a e0 1f  and  %o3, 0x1f, %o3
a007435c:  97 2a e0 03  sll  %o3, 3, %o3
a0074360:  90 10 00 16  mov  %l6, %o0
a0074364:  92 15 20 68  or  %l4, 0x68, %o1
a0074368:  40 00 cc 48  call  0xa00a7488
a007436c:  94 10 3f 07  mov  -249, %o2
a0074370:  d6 0f bf da  ldub  [ %fp + -38 ], %o3
a0074374:  96 0a e0 1f  and  %o3, 0x1f, %o3
a0074378:  97 2a e0 03  sll  %o3, 3, %o3
a007437c:  90 10 00 16  mov  %l6, %o0
a0074380:  92 14 a0 68  or  %l2, 0x68, %o1
a0074384:  40 00 cc 41  call  0xa00a7488
a0074388:  94 10 3f 07  mov  -249, %o2
a007438c:  d6 0f bf db  ldub  [ %fp + -37 ], %o3
a0074390:  96 0a e0 1f  and  %o3, 0x1f, %o3
a0074394:  97 2a e0 03  sll  %o3, 3, %o3
a0074398:  90 10 00 16  mov  %l6, %o0
a007439c:  92 14 e0 68  or  %l3, 0x68, %o1
a00743a0:  40 00 cc 3a  call  0xa00a7488
a00743a4:  94 10 3f 07  mov  -249, %o2
a00743a8:  d6 0f bf d0  ldub  [ %fp + -48 ], %o3
a00743ac:  96 0a e0 1f  and  %o3, 0x1f, %o3
a00743b0:  97 2a e0 0b  sll  %o3, 0xb, %o3
a00743b4:  90 10 00 16  mov  %l6, %o0
a00743b8:  92 15 60 68  or  %l5, 0x68, %o1
a00743bc:  40 00 cc 33  call  0xa00a7488
a00743c0:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00743c4:  d6 0f bf d1  ldub  [ %fp + -47 ], %o3
a00743c8:  96 0a e0 1f  and  %o3, 0x1f, %o3
a00743cc:  97 2a e0 0b  sll  %o3, 0xb, %o3
a00743d0:  90 10 00 16  mov  %l6, %o0
a00743d4:  92 15 20 68  or  %l4, 0x68, %o1
a00743d8:  40 00 cc 2c  call  0xa00a7488
a00743dc:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00743e0:  d6 0f bf d2  ldub  [ %fp + -46 ], %o3
a00743e4:  96 0a e0 1f  and  %o3, 0x1f, %o3
a00743e8:  97 2a e0 0b  sll  %o3, 0xb, %o3
a00743ec:  90 10 00 16  mov  %l6, %o0
a00743f0:  92 14 a0 68  or  %l2, 0x68, %o1
a00743f4:  40 00 cc 25  call  0xa00a7488
a00743f8:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00743fc:  d6 0f bf d3  ldub  [ %fp + -45 ], %o3
a0074400:  96 0a e0 1f  and  %o3, 0x1f, %o3
a0074404:  97 2a e0 0b  sll  %o3, 0xb, %o3
a0074408:  90 10 00 16  mov  %l6, %o0
a007440c:  92 14 e0 68  or  %l3, 0x68, %o1
a0074410:  40 00 cc 1e  call  0xa00a7488
a0074414:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0074418:  d6 0f bf c8  ldub  [ %fp + -56 ], %o3
a007441c:  96 0a e0 1f  and  %o3, 0x1f, %o3
a0074420:  92 15 60 70  or  %l5, 0x70, %o1
a0074424:  97 2a e0 0b  sll  %o3, 0xb, %o3
a0074428:  90 10 00 16  mov  %l6, %o0
a007442c:  40 00 cc 17  call  0xa00a7488
a0074430:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0074434:  d6 0f bf c9  ldub  [ %fp + -55 ], %o3
a0074438:  96 0a e0 1f  and  %o3, 0x1f, %o3
a007443c:  92 15 20 70  or  %l4, 0x70, %o1
a0074440:  97 2a e0 0b  sll  %o3, 0xb, %o3
a0074444:  90 10 00 16  mov  %l6, %o0
a0074448:  40 00 cc 10  call  0xa00a7488
a007444c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0074450:  d6 0f bf ca  ldub  [ %fp + -54 ], %o3
a0074454:  96 0a e0 1f  and  %o3, 0x1f, %o3
a0074458:  92 14 a0 70  or  %l2, 0x70, %o1
a007445c:  97 2a e0 0b  sll  %o3, 0xb, %o3
a0074460:  90 10 00 16  mov  %l6, %o0
a0074464:  40 00 cc 09  call  0xa00a7488
a0074468:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007446c:  d6 0f bf cb  ldub  [ %fp + -53 ], %o3
a0074470:  96 0a e0 1f  and  %o3, 0x1f, %o3
a0074474:  90 10 00 16  mov  %l6, %o0
a0074478:  92 14 e0 70  or  %l3, 0x70, %o1
a007447c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0074480:  97 2a e0 0b  sll  %o3, 0xb, %o3
a0074484:  40 00 cc 01  call  0xa00a7488
a0074488:  a2 0d e0 ff  and  %l7, 0xff, %l1
a007448c:  29 00 00 07  sethi  %hi(0x1c00), %l4
a0074490:  90 10 20 01  mov  1, %o0
a0074494:  92 10 20 11  mov  0x11, %o1
a0074498:  94 10 00 11  mov  %l1, %o2
a007449c:  40 00 cb e2  call  0xa00a7424
a00744a0:  96 15 20 04  or  %l4, 4, %o3
a00744a4:  80 a7 60 00  cmp  %i5, 0
a00744a8:  02 80 00 30  be  0xa0074568
a00744ac:  25 00 00 04  sethi  %hi(0x1000), %l2
a00744b0:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a00744b4:  96 12 e0 04  or  %o3, 4, %o3	! 0x2c04
a00744b8:  92 10 20 11  mov  0x11, %o1
a00744bc:  94 10 00 11  mov  %l1, %o2
a00744c0:  40 00 cb d9  call  0xa00a7424
a00744c4:  90 10 20 01  mov  1, %o0
a00744c8:  90 10 00 11  mov  %l1, %o0
a00744cc:  7f ff fc 9b  call  0xa0073738
a00744d0:  21 00 00 0d  sethi  %hi(0x3400), %l0
a00744d4:  90 10 00 11  mov  %l1, %o0
a00744d8:  92 14 22 1c  or  %l0, 0x21c, %o1
a00744dc:  94 10 3f 00  mov  -256, %o2
a00744e0:  40 00 cb ea  call  0xa00a7488
a00744e4:  96 10 20 b0  mov  0xb0, %o3
a00744e8:  92 14 22 1c  or  %l0, 0x21c, %o1
a00744ec:  94 10 3f 00  mov  -256, %o2
a00744f0:  96 10 20 b3  mov  0xb3, %o3
a00744f4:  40 00 cb e5  call  0xa00a7488
a00744f8:  90 10 00 11  mov  %l1, %o0
a00744fc:  40 00 f4 a6  call  0xa00b1794
a0074500:  90 10 20 01  mov  1, %o0
a0074504:  90 10 00 11  mov  %l1, %o0
a0074508:  92 14 22 1c  or  %l0, 0x21c, %o1
a007450c:  94 10 3f 00  mov  -256, %o2
a0074510:  40 00 cb de  call  0xa00a7488
a0074514:  96 10 20 33  mov  0x33, %o3
a0074518:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a007451c:  17 00 00 0c  sethi  %hi(0x3000), %o3
a0074520:  90 10 00 11  mov  %l1, %o0
a0074524:  94 12 a0 ff  or  %o2, 0xff, %o2
a0074528:  96 12 e3 00  or  %o3, 0x300, %o3
a007452c:  40 00 cb d7  call  0xa00a7488
a0074530:  92 14 22 1c  or  %l0, 0x21c, %o1
a0074534:  15 3f c0 3f  sethi  %hi(0xff00fc00), %o2
a0074538:  90 10 00 11  mov  %l1, %o0
a007453c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0074540:  92 14 22 1c  or  %l0, 0x21c, %o1
a0074544:  40 00 cb d1  call  0xa00a7488
a0074548:  17 00 19 c0  sethi  %hi(0x670000), %o3
a007454c:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a0074550:  90 10 00 11  mov  %l1, %o0
a0074554:  92 14 22 18  or  %l0, 0x218, %o1
a0074558:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007455c:  40 00 cb cb  call  0xa00a7488
a0074560:  17 04 c0 00  sethi  %hi(0x13000000), %o3
a0074564:  25 00 00 04  sethi  %hi(0x1000), %l2
a0074568:  90 10 00 11  mov  %l1, %o0
a007456c:  92 14 a0 28  or  %l2, 0x28, %o1
a0074570:  94 10 3c ff  mov  -769, %o2
a0074574:  40 00 cb c5  call  0xa00a7488
a0074578:  96 10 23 00  mov  0x300, %o3
a007457c:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a0074580:  90 10 00 11  mov  %l1, %o0
a0074584:  94 12 a0 ff  or  %o2, 0xff, %o2
a0074588:  92 14 a0 08  or  %l2, 8, %o1
a007458c:  40 00 cb bf  call  0xa00a7488
a0074590:  96 10 2f 00  mov  0xf00, %o3
a0074594:  90 10 20 01  mov  1, %o0
a0074598:  92 10 20 07  mov  7, %o1
a007459c:  94 10 00 11  mov  %l1, %o2
a00745a0:  40 00 cb a1  call  0xa00a7424
a00745a4:  96 15 20 04  or  %l4, 4, %o3
a00745a8:  27 00 00 0b  sethi  %hi(0x2c00), %l3
a00745ac:  90 10 20 01  mov  1, %o0
a00745b0:  92 10 20 07  mov  7, %o1
a00745b4:  94 10 00 11  mov  %l1, %o2
a00745b8:  40 00 cb 9b  call  0xa00a7424
a00745bc:  96 14 e0 04  or  %l3, 4, %o3
a00745c0:  21 00 3f ff  sethi  %hi(0xfffc00), %l0
a00745c4:  94 14 23 ff  or  %l0, 0x3ff, %o2	! 0xffffff
a00745c8:  90 10 00 11  mov  %l1, %o0
a00745cc:  92 14 a1 00  or  %l2, 0x100, %o1
a00745d0:  40 00 cb ae  call  0xa00a7488
a00745d4:  17 00 80 00  sethi  %hi(0x2000000), %o3
a00745d8:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00745dc:  92 14 a1 00  or  %l2, 0x100, %o1
a00745e0:  17 00 c0 00  sethi  %hi(0x3000000), %o3
a00745e4:  40 00 cb a9  call  0xa00a7488
a00745e8:  90 10 00 11  mov  %l1, %o0
a00745ec:  40 00 f4 6a  call  0xa00b1794
a00745f0:  90 10 20 01  mov  1, %o0
a00745f4:  90 10 20 18  mov  0x18, %o0
a00745f8:  92 10 00 11  mov  %l1, %o1
a00745fc:  40 00 cb 9b  call  0xa00a7468
a0074600:  94 14 a1 00  or  %l2, 0x100, %o2
a0074604:  80 a2 20 00  cmp  %o0, 0
a0074608:  12 80 00 20  bne  0xa0074688
a007460c:  21 2a 01 e1  sethi  %hi(0xa8078400), %l0
a0074610:  92 14 a1 00  or  %l2, 0x100, %o1
a0074614:  40 00 cb 40  call  0xa00a7314
a0074618:  90 10 00 11  mov  %l1, %o0
a007461c:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1
a0074620:  91 32 20 1c  srl  %o0, 0x1c, %o0
a0074624:  80 88 60 01  btst  1, %g1
a0074628:  02 80 00 09  be  0xa007464c
a007462c:  a0 0a 20 07  and  %o0, 7, %l0
a0074630:  92 05 e0 41  add  %l7, 0x41, %o1
a0074634:  93 2a 60 18  sll  %o1, 0x18, %o1
a0074638:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a007463c:  90 12 21 38  or  %o0, 0x138, %o0	! 0xa0066938
a0074640:  93 3a 60 18  sra  %o1, 0x18, %o1
a0074644:  7f ff fa 80  call  0xa0073044
a0074648:  94 0c 20 07  and  %l0, 7, %o2
a007464c:  82 0c 20 07  and  %l0, 7, %g1
a0074650:  a1 28 60 04  sll  %g1, 4, %l0
a0074654:  92 15 20 04  or  %l4, 4, %o1
a0074658:  90 10 00 11  mov  %l1, %o0
a007465c:  94 10 3f 8f  mov  -113, %o2
a0074660:  40 00 cb 8a  call  0xa00a7488
a0074664:  96 10 00 10  mov  %l0, %o3
a0074668:  80 a7 60 00  cmp  %i5, 0
a007466c:  22 80 00 23  be,a   0xa00746f8
a0074670:  21 00 00 04  sethi  %hi(0x1000), %l0
a0074674:  92 14 e0 04  or  %l3, 4, %o1
a0074678:  96 10 00 10  mov  %l0, %o3
a007467c:  90 10 00 11  mov  %l1, %o0
a0074680:  10 80 00 18  b  0xa00746e0
a0074684:  94 10 3f 8f  mov  -113, %o2
a0074688:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1
a007468c:  80 88 60 01  btst  1, %g1
a0074690:  22 80 00 09  be,a   0xa00746b4
a0074694:  92 15 20 04  or  %l4, 4, %o1
a0074698:  92 05 e0 41  add  %l7, 0x41, %o1
a007469c:  93 2a 60 18  sll  %o1, 0x18, %o1
a00746a0:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a00746a4:  90 12 21 68  or  %o0, 0x168, %o0	! 0xa0066968
a00746a8:  7f ff fa 67  call  0xa0073044
a00746ac:  93 3a 60 18  sra  %o1, 0x18, %o1
a00746b0:  92 15 20 04  or  %l4, 4, %o1
a00746b4:  90 10 00 11  mov  %l1, %o0
a00746b8:  94 10 3f 8f  mov  -113, %o2
a00746bc:  40 00 cb 73  call  0xa00a7488
a00746c0:  96 10 20 40  mov  0x40, %o3
a00746c4:  80 a7 60 00  cmp  %i5, 0
a00746c8:  02 80 00 0c  be  0xa00746f8
a00746cc:  21 00 00 04  sethi  %hi(0x1000), %l0
a00746d0:  92 14 e0 04  or  %l3, 4, %o1
a00746d4:  90 10 00 11  mov  %l1, %o0
a00746d8:  94 10 3f 8f  mov  -113, %o2
a00746dc:  96 10 20 40  mov  0x40, %o3
a00746e0:  40 00 cb 6a  call  0xa00a7488
a00746e4:  01 00 00 00  nop
a00746e8:  80 a7 60 00  cmp  %i5, 0
a00746ec:  32 80 00 24  bne,a   0xa007477c
a00746f0:  a2 0d e0 ff  and  %l7, 0xff, %l1
a00746f4:  21 00 00 04  sethi  %hi(0x1000), %l0
a00746f8:  96 14 20 14  or  %l0, 0x14, %o3	! 0x1014
a00746fc:  90 10 20 01  mov  1, %o0
a0074700:  92 10 20 08  mov  8, %o1
a0074704:  40 00 cb 48  call  0xa00a7424
a0074708:  94 10 00 11  mov  %l1, %o2
a007470c:  96 14 20 34  or  %l0, 0x34, %o3
a0074710:  90 10 20 01  mov  1, %o0
a0074714:  92 10 20 08  mov  8, %o1
a0074718:  40 00 cb 43  call  0xa00a7424
a007471c:  94 10 00 11  mov  %l1, %o2
a0074720:  a0 04 24 00  add  %l0, 0x400, %l0
a0074724:  96 14 20 14  or  %l0, 0x14, %o3
a0074728:  90 10 20 01  mov  1, %o0
a007472c:  92 10 20 08  mov  8, %o1
a0074730:  40 00 cb 3d  call  0xa00a7424
a0074734:  94 10 00 11  mov  %l1, %o2
a0074738:  96 14 20 34  or  %l0, 0x34, %o3
a007473c:  90 10 20 01  mov  1, %o0
a0074740:  92 10 20 08  mov  8, %o1
a0074744:  40 00 cb 38  call  0xa00a7424
a0074748:  94 10 00 11  mov  %l1, %o2
a007474c:  a0 04 24 00  add  %l0, 0x400, %l0
a0074750:  90 10 20 01  mov  1, %o0
a0074754:  92 10 20 08  mov  8, %o1
a0074758:  94 10 00 11  mov  %l1, %o2
a007475c:  40 00 cb 32  call  0xa00a7424
a0074760:  96 14 20 14  or  %l0, 0x14, %o3
a0074764:  94 10 00 11  mov  %l1, %o2
a0074768:  96 14 20 34  or  %l0, 0x34, %o3
a007476c:  90 10 20 01  mov  1, %o0
a0074770:  40 00 cb 2d  call  0xa00a7424
a0074774:  92 10 20 08  mov  8, %o1
a0074778:  a2 0d e0 ff  and  %l7, 0xff, %l1
a007477c:  25 00 00 07  sethi  %hi(0x1c00), %l2
a0074780:  90 10 00 11  mov  %l1, %o0
a0074784:  92 14 a3 44  or  %l2, 0x344, %o1
a0074788:  94 10 3f c0  mov  -64, %o2
a007478c:  40 00 cb 3f  call  0xa00a7488
a0074790:  96 10 20 1f  mov  0x1f, %o3
a0074794:  90 10 20 01  mov  1, %o0
a0074798:  92 10 20 15  mov  0x15, %o1
a007479c:  94 10 00 11  mov  %l1, %o2
a00747a0:  40 00 cb 21  call  0xa00a7424
a00747a4:  96 10 00 12  mov  %l2, %o3
a00747a8:  80 a7 60 00  cmp  %i5, 0
a00747ac:  02 80 00 0e  be  0xa00747e4
a00747b0:  27 3f fc 3f  sethi  %hi(0xfff0fc00), %l3
a00747b4:  90 10 20 01  mov  1, %o0
a00747b8:  92 10 20 15  mov  0x15, %o1
a00747bc:  94 10 00 11  mov  %l1, %o2
a00747c0:  40 00 cb 19  call  0xa00a7424
a00747c4:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a00747c8:  15 3f fc 3f  sethi  %hi(0xfff0fc00), %o2
a00747cc:  90 10 00 11  mov  %l1, %o0
a00747d0:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a00747d4:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a00747d8:  40 00 cb 2c  call  0xa00a7488
a00747dc:  17 00 02 00  sethi  %hi(0x80000), %o3
a00747e0:  27 3f fc 3f  sethi  %hi(0xfff0fc00), %l3
a00747e4:  90 10 00 11  mov  %l1, %o0
a00747e8:  92 10 00 12  mov  %l2, %o1
a00747ec:  94 14 e3 ff  or  %l3, 0x3ff, %o2
a00747f0:  40 00 cb 26  call  0xa00a7488
a00747f4:  17 00 02 00  sethi  %hi(0x80000), %o3
a00747f8:  90 10 20 01  mov  1, %o0
a00747fc:  92 10 20 1b  mov  0x1b, %o1
a0074800:  94 10 00 11  mov  %l1, %o2
a0074804:  40 00 cb 08  call  0xa00a7424
a0074808:  96 10 00 12  mov  %l2, %o3
a007480c:  80 a7 60 00  cmp  %i5, 0
a0074810:  02 80 00 08  be  0xa0074830
a0074814:  15 3f c0 3f  sethi  %hi(0xff00fc00), %o2
a0074818:  90 10 20 01  mov  1, %o0
a007481c:  92 10 20 1b  mov  0x1b, %o1
a0074820:  94 10 00 11  mov  %l1, %o2
a0074824:  40 00 cb 00  call  0xa00a7424
a0074828:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a007482c:  15 3f c0 3f  sethi  %hi(0xff00fc00), %o2
a0074830:  94 12 a3 ff  or  %o2, 0x3ff, %o2	! 0xff00ffff
a0074834:  90 10 00 11  mov  %l1, %o0
a0074838:  13 00 00 04  sethi  %hi(0x1000), %o1
a007483c:  40 00 cb 13  call  0xa00a7488
a0074840:  17 00 1b 80  sethi  %hi(0x6e0000), %o3
a0074844:  90 10 20 01  mov  1, %o0
a0074848:  92 10 20 18  mov  0x18, %o1
a007484c:  94 10 00 11  mov  %l1, %o2
a0074850:  40 00 ca f5  call  0xa00a7424
a0074854:  96 14 a3 40  or  %l2, 0x340, %o3
a0074858:  21 00 00 0d  sethi  %hi(0x3400), %l0
a007485c:  90 10 20 01  mov  1, %o0
a0074860:  92 10 20 08  mov  8, %o1
a0074864:  94 10 00 11  mov  %l1, %o2
a0074868:  40 00 ca ef  call  0xa00a7424
a007486c:  96 14 22 08  or  %l0, 0x208, %o3
a0074870:  80 a7 60 00  cmp  %i5, 0
a0074874:  02 80 00 0c  be  0xa00748a4
a0074878:  92 10 20 09  mov  9, %o1
a007487c:  90 10 20 01  mov  1, %o0
a0074880:  94 10 00 11  mov  %l1, %o2
a0074884:  40 00 ca e8  call  0xa00a7424
a0074888:  96 14 22 08  or  %l0, 0x208, %o3
a007488c:  15 3f ff f1  sethi  %hi(0xffffc400), %o2
a0074890:  90 10 00 11  mov  %l1, %o0
a0074894:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0074898:  96 14 23 00  or  %l0, 0x300, %o3
a007489c:  40 00 ca fb  call  0xa00a7488
a00748a0:  92 14 22 08  or  %l0, 0x208, %o1
a00748a4:  40 00 f3 bc  call  0xa00b1794
a00748a8:  90 10 20 01  mov  1, %o0
a00748ac:  96 14 a0 04  or  %l2, 4, %o3
a00748b0:  90 10 20 01  mov  1, %o0
a00748b4:  92 10 20 10  mov  0x10, %o1
a00748b8:  40 00 ca db  call  0xa00a7424
a00748bc:  94 10 00 11  mov  %l1, %o2
a00748c0:  96 14 a0 04  or  %l2, 4, %o3
a00748c4:  90 10 20 00  clr  %o0
a00748c8:  92 10 20 15  mov  0x15, %o1
a00748cc:  40 00 ca d6  call  0xa00a7424
a00748d0:  94 10 20 00  clr  %o2
a00748d4:  96 14 a2 80  or  %l2, 0x280, %o3
a00748d8:  90 10 20 00  clr  %o0
a00748dc:  92 10 20 07  mov  7, %o1
a00748e0:  40 00 ca d1  call  0xa00a7424
a00748e4:  94 10 20 00  clr  %o2
a00748e8:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a00748ec:  17 00 00 13  sethi  %hi(0x4c00), %o3
a00748f0:  92 14 a0 04  or  %l2, 4, %o1
a00748f4:  94 12 a0 ff  or  %o2, 0xff, %o2
a00748f8:  96 12 e1 00  or  %o3, 0x100, %o3
a00748fc:  40 00 ca e3  call  0xa00a7488
a0074900:  90 10 20 00  clr  %o0
a0074904:  96 14 a0 04  or  %l2, 4, %o3
a0074908:  90 10 20 00  clr  %o0
a007490c:  92 10 20 0f  mov  0xf, %o1
a0074910:  40 00 ca c5  call  0xa00a7424
a0074914:  94 10 20 00  clr  %o2
a0074918:  17 00 00 04  sethi  %hi(0x1000), %o3
a007491c:  96 12 e1 60  or  %o3, 0x160, %o3	! 0x1160
a0074920:  90 10 20 00  clr  %o0
a0074924:  92 10 20 19  mov  0x19, %o1
a0074928:  40 00 ca bf  call  0xa00a7424
a007492c:  94 10 20 00  clr  %o2
a0074930:  96 10 00 12  mov  %l2, %o3
a0074934:  90 10 20 00  clr  %o0
a0074938:  92 10 20 16  mov  0x16, %o1
a007493c:  40 00 ca ba  call  0xa00a7424
a0074940:  94 10 20 00  clr  %o2
a0074944:  96 10 00 12  mov  %l2, %o3
a0074948:  90 10 20 00  clr  %o0
a007494c:  92 10 20 17  mov  0x17, %o1
a0074950:  40 00 ca b5  call  0xa00a7424
a0074954:  94 10 20 00  clr  %o2
a0074958:  96 14 a0 0c  or  %l2, 0xc, %o3
a007495c:  90 10 20 01  mov  1, %o0
a0074960:  92 10 20 18  mov  0x18, %o1
a0074964:  40 00 ca b0  call  0xa00a7424
a0074968:  94 10 20 00  clr  %o2
a007496c:  96 14 a0 04  or  %l2, 4, %o3
a0074970:  90 10 20 01  mov  1, %o0
a0074974:  92 10 20 02  mov  2, %o1
a0074978:  40 00 ca ab  call  0xa00a7424
a007497c:  94 10 00 11  mov  %l1, %o2
a0074980:  a0 04 40 11  add  %l1, %l1, %l0
a0074984:  a0 04 00 11  add  %l0, %l1, %l0
a0074988:  11 2a 01 f3  sethi  %hi(0xa807cc00), %o0
a007498c:  83 2c 20 02  sll  %l0, 2, %g1
a0074990:  90 12 20 c4  or  %o0, 0xc4, %o0
a0074994:  90 00 40 08  add  %g1, %o0, %o0
a0074998:  92 10 20 00  clr  %o1
a007499c:  40 00 f3 04  call  0xa00b15ac
a00749a0:  94 10 20 0c  mov  0xc, %o2
a00749a4:  11 2a 01 ea  sethi  %hi(0xa807a800), %o0
a00749a8:  82 5c 68 98  smul  %l1, 0x898, %g1
a00749ac:  90 12 21 f0  or  %o0, 0x1f0, %o0
a00749b0:  90 00 40 08  add  %g1, %o0, %o0
a00749b4:  92 10 20 00  clr  %o1
a00749b8:  40 00 f2 fd  call  0xa00b15ac
a00749bc:  94 10 28 98  mov  0x898, %o2
a00749c0:  11 2a 01 f3  sethi  %hi(0xa807cc00), %o0
a00749c4:  a1 2c 20 03  sll  %l0, 3, %l0
a00749c8:  90 12 20 64  or  %o0, 0x64, %o0
a00749cc:  90 04 00 08  add  %l0, %o0, %o0
a00749d0:  92 10 20 00  clr  %o1
a00749d4:  40 00 f2 f6  call  0xa00b15ac
a00749d8:  94 10 20 18  mov  0x18, %o2
a00749dc:  25 2a 01 e1  sethi  %hi(0xa8078400), %l2
a00749e0:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1	! 0xa8078634
a00749e4:  80 88 60 01  btst  1, %g1
a00749e8:  02 80 00 0a  be  0xa0074a10
a00749ec:  80 a7 60 00  cmp  %i5, 0
a00749f0:  92 05 e0 41  add  %l7, 0x41, %o1
a00749f4:  93 2a 60 18  sll  %o1, 0x18, %o1
a00749f8:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a00749fc:  90 12 21 98  or  %o0, 0x198, %o0	! 0xa0066998
a0074a00:  93 3a 60 18  sra  %o1, 0x18, %o1
a0074a04:  7f ff f9 90  call  0xa0073044
a0074a08:  94 10 00 11  mov  %l1, %o2
a0074a0c:  80 a7 60 00  cmp  %i5, 0
a0074a10:  02 80 00 69  be  0xa0074bb4
a0074a14:  90 10 00 11  mov  %l1, %o0
a0074a18:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1
a0074a1c:  80 88 60 01  btst  1, %g1
a0074a20:  02 80 00 0a  be  0xa0074a48
a0074a24:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a0074a28:  92 05 e0 41  add  %l7, 0x41, %o1
a0074a2c:  93 2a 60 18  sll  %o1, 0x18, %o1
a0074a30:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a0074a34:  90 12 21 c8  or  %o0, 0x1c8, %o0	! 0xa00669c8
a0074a38:  93 3a 60 18  sra  %o1, 0x18, %o1
a0074a3c:  7f ff f9 82  call  0xa0073044
a0074a40:  94 10 00 11  mov  %l1, %o2
a0074a44:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a0074a48:  90 10 20 00  clr  %o0
a0074a4c:  92 10 20 13  mov  0x13, %o1
a0074a50:  94 10 00 11  mov  %l1, %o2
a0074a54:  40 00 ca 74  call  0xa00a7424
a0074a58:  96 14 20 34  or  %l0, 0x34, %o3
a0074a5c:  90 10 20 01  mov  1, %o0
a0074a60:  92 10 20 19  mov  0x19, %o1
a0074a64:  94 10 00 11  mov  %l1, %o2
a0074a68:  40 00 ca 6f  call  0xa00a7424
a0074a6c:  96 14 20 34  or  %l0, 0x34, %o3
a0074a70:  90 10 20 00  clr  %o0
a0074a74:  92 10 20 10  mov  0x10, %o1
a0074a78:  94 10 00 11  mov  %l1, %o2
a0074a7c:  40 00 ca 6a  call  0xa00a7424
a0074a80:  96 14 20 34  or  %l0, 0x34, %o3
a0074a84:  90 10 20 00  clr  %o0
a0074a88:  92 10 20 11  mov  0x11, %o1
a0074a8c:  94 10 00 11  mov  %l1, %o2
a0074a90:  40 00 ca 65  call  0xa00a7424
a0074a94:  96 14 20 34  or  %l0, 0x34, %o3
a0074a98:  90 10 20 00  clr  %o0
a0074a9c:  92 10 20 12  mov  0x12, %o1
a0074aa0:  94 10 00 11  mov  %l1, %o2
a0074aa4:  40 00 ca 60  call  0xa00a7424
a0074aa8:  96 14 20 34  or  %l0, 0x34, %o3
a0074aac:  90 10 00 11  mov  %l1, %o0
a0074ab0:  94 14 e3 ff  or  %l3, 0x3ff, %o2
a0074ab4:  92 14 20 30  or  %l0, 0x30, %o1
a0074ab8:  40 00 ca 74  call  0xa00a7488
a0074abc:  17 00 02 c0  sethi  %hi(0xb0000), %o3
a0074ac0:  15 3f c3 ff  sethi  %hi(0xff0ffc00), %o2
a0074ac4:  90 10 00 11  mov  %l1, %o0
a0074ac8:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0074acc:  92 14 20 30  or  %l0, 0x30, %o1
a0074ad0:  40 00 ca 6e  call  0xa00a7488
a0074ad4:  17 00 10 00  sethi  %hi(0x400000), %o3
a0074ad8:  15 3c 3f ff  sethi  %hi(0xf0fffc00), %o2
a0074adc:  90 10 00 11  mov  %l1, %o0
a0074ae0:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0074ae4:  92 14 20 30  or  %l0, 0x30, %o1
a0074ae8:  40 00 ca 68  call  0xa00a7488
a0074aec:  17 03 40 00  sethi  %hi(0xd000000), %o3
a0074af0:  15 03 ff ff  sethi  %hi(0xffffc00), %o2
a0074af4:  90 10 00 11  mov  %l1, %o0
a0074af8:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0074afc:  92 14 20 30  or  %l0, 0x30, %o1
a0074b00:  40 00 ca 62  call  0xa00a7488
a0074b04:  17 08 00 00  sethi  %hi(0x20000000), %o3
a0074b08:  90 10 20 00  clr  %o0
a0074b0c:  92 10 20 00  clr  %o1
a0074b10:  94 10 00 11  mov  %l1, %o2
a0074b14:  40 00 ca 44  call  0xa00a7424
a0074b18:  96 14 20 30  or  %l0, 0x30, %o3
a0074b1c:  15 3f c7 ff  sethi  %hi(0xff1ffc00), %o2
a0074b20:  90 10 00 11  mov  %l1, %o0
a0074b24:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0074b28:  92 14 20 34  or  %l0, 0x34, %o1
a0074b2c:  40 00 ca 57  call  0xa00a7488
a0074b30:  17 00 30 00  sethi  %hi(0xc00000), %o3
a0074b34:  90 10 00 11  mov  %l1, %o0
a0074b38:  92 14 20 38  or  %l0, 0x38, %o1
a0074b3c:  94 10 31 ff  mov  -3585, %o2
a0074b40:  40 00 ca 52  call  0xa00a7488
a0074b44:  96 10 20 00  clr  %o3
a0074b48:  90 10 00 11  mov  %l1, %o0
a0074b4c:  92 14 20 34  or  %l0, 0x34, %o1
a0074b50:  94 10 33 ff  mov  -3073, %o2
a0074b54:  40 00 ca 4d  call  0xa00a7488
a0074b58:  96 10 20 00  clr  %o3
a0074b5c:  90 10 20 00  clr  %o0
a0074b60:  92 10 20 14  mov  0x14, %o1
a0074b64:  94 10 00 11  mov  %l1, %o2
a0074b68:  40 00 ca 2f  call  0xa00a7424
a0074b6c:  96 14 20 34  or  %l0, 0x34, %o3
a0074b70:  15 3f 3f ff  sethi  %hi(0xfcfffc00), %o2
a0074b74:  90 10 00 11  mov  %l1, %o0
a0074b78:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0074b7c:  92 14 20 24  or  %l0, 0x24, %o1
a0074b80:  40 00 ca 42  call  0xa00a7488
a0074b84:  96 10 20 00  clr  %o3
a0074b88:  90 10 20 00  clr  %o0
a0074b8c:  92 10 20 05  mov  5, %o1
a0074b90:  94 10 00 11  mov  %l1, %o2
a0074b94:  40 00 ca 24  call  0xa00a7424
a0074b98:  96 14 20 20  or  %l0, 0x20, %o3
a0074b9c:  96 14 20 20  or  %l0, 0x20, %o3
a0074ba0:  90 10 20 00  clr  %o0
a0074ba4:  92 10 20 04  mov  4, %o1
a0074ba8:  40 00 ca 1f  call  0xa00a7424
a0074bac:  94 10 00 11  mov  %l1, %o2
a0074bb0:  90 10 00 11  mov  %l1, %o0
a0074bb4:  7f ff fc 1c  call  0xa0073c24
a0074bb8:  92 10 20 01  mov  1, %o1
a0074bbc:  ae 05 e0 01  inc  %l7
a0074bc0:  82 0d e0 ff  and  %l7, 0xff, %g1
a0074bc4:  80 a0 60 03  cmp  %g1, 3
a0074bc8:  28 bf fc 60  bleu,a   0xa0073d48
a0074bcc:  ac 0d e0 ff  and  %l7, 0xff, %l6
a0074bd0:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1
a0074bd4:  80 88 60 01  btst  1, %g1
a0074bd8:  02 80 00 05  be  0xa0074bec
a0074bdc:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a0074be0:  90 12 21 f0  or  %o0, 0x1f0, %o0	! 0xa00669f0
a0074be4:  7f ff f9 18  call  0xa0073044
a0074be8:  92 10 23 78  mov  0x378, %o1
a0074bec:  01 00 00 00  nop
a0074bf0:  81 c7 e0 08  ret
a0074bf4:  81 e8 00 00  restore
