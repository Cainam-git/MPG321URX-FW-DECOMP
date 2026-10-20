# leon2s FUN_a00c8c64 0xa00c8c64-0xa00c90b4 (1104 bytes)
a00c8c64:  9d e3 bf 70  save  %sp, -144, %sp
a00c8c68:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c8c6c:  96 06 00 18  add  %i0, %i0, %o3
a00c8c70:  96 02 c0 18  add  %o3, %i0, %o3
a00c8c74:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a00c8c78:  97 2a e0 03  sll  %o3, 3, %o3
a00c8c7c:  94 14 63 b0  or  %l1, 0x3b0, %o2
a00c8c80:  c2 02 80 0b  ld  [ %o2 + %o3 ], %g1
a00c8c84:  19 00 00 c0  sethi  %hi(0x30000), %o4
a00c8c88:  98 28 40 0c  andn  %g1, %o4, %o4
a00c8c8c:  9b 2e 20 03  sll  %i0, 3, %o5
a00c8c90:  9a 23 40 18  sub  %o5, %i0, %o5
a00c8c94:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c8c98:  82 10 61 80  or  %g1, 0x180, %g1	! 0xa807d580
a00c8c9c:  9b 2b 60 02  sll  %o5, 2, %o5
a00c8ca0:  9a 03 40 01  add  %o5, %g1, %o5
a00c8ca4:  03 00 00 40  sethi  %hi(0x10000), %g1
a00c8ca8:  98 13 00 01  or  %o4, %g1, %o4
a00c8cac:  c2 0b 60 01  ldub  [ %o5 + 1 ], %g1
a00c8cb0:  d8 22 80 0b  st  %o4, [ %o2 + %o3 ]
a00c8cb4:  80 a0 60 41  cmp  %g1, 0x41
a00c8cb8:  02 80 00 09  be  0xa00c8cdc
a00c8cbc:  a8 10 20 00  clr  %l4
a00c8cc0:  80 a0 60 41  cmp  %g1, 0x41
a00c8cc4:  04 80 00 07  ble  0xa00c8ce0
a00c8cc8:  80 a0 60 51  cmp  %g1, 0x51
a00c8ccc:  02 80 00 05  be  0xa00c8ce0
a00c8cd0:  80 a0 60 61  cmp  %g1, 0x61
a00c8cd4:  12 80 00 03  bne  0xa00c8ce0
a00c8cd8:  01 00 00 00  nop
a00c8cdc:  a8 10 20 01  mov  1, %l4	! 0x1
a00c8ce0:  7f ff df 49  call  0xa00c0a04
a00c8ce4:  90 10 00 18  mov  %i0, %o0
a00c8ce8:  80 8a 20 ff  btst  0xff, %o0
a00c8cec:  02 80 00 0a  be  0xa00c8d14
a00c8cf0:  82 06 00 18  add  %i0, %i0, %g1
a00c8cf4:  98 00 40 18  add  %g1, %i0, %o4
a00c8cf8:  96 14 63 b0  or  %l1, 0x3b0, %o3
a00c8cfc:  99 2b 20 03  sll  %o4, 3, %o4
a00c8d00:  c2 02 c0 0c  ld  [ %o3 + %o4 ], %g1
a00c8d04:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00c8d08:  82 10 40 0d  or  %g1, %o5, %g1
a00c8d0c:  10 80 00 e8  b  0xa00c90ac
a00c8d10:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00c8d14:  82 00 40 18  add  %g1, %i0, %g1
a00c8d18:  a1 28 60 03  sll  %g1, 3, %l0
a00c8d1c:  a4 14 63 b0  or  %l1, 0x3b0, %l2
a00c8d20:  da 04 80 10  ld  [ %l2 + %l0 ], %o5
a00c8d24:  03 00 20 00  sethi  %hi(0x800000), %g1
a00c8d28:  82 2b 40 01  andn  %o5, %g1, %g1
a00c8d2c:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a00c8d30:  90 10 00 18  mov  %i0, %o0
a00c8d34:  7f ff fd 8b  call  0xa00c8360
a00c8d38:  92 07 bf d7  add  %fp, -41, %o1
a00c8d3c:  80 8a 20 ff  btst  0xff, %o0
a00c8d40:  32 80 00 31  bne,a   0xa00c8e04
a00c8d44:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00c8d48:  c2 0f bf d7  ldub  [ %fp + -41 ], %g1
a00c8d4c:  80 88 60 20  btst  0x20, %g1
a00c8d50:  22 80 00 2d  be,a   0xa00c8e04
a00c8d54:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00c8d58:  90 10 00 18  mov  %i0, %o0
a00c8d5c:  7f ff fd 60  call  0xa00c82dc
a00c8d60:  92 07 bf d8  add  %fp, -40, %o1
a00c8d64:  80 8a 20 ff  btst  0xff, %o0
a00c8d68:  32 80 00 27  bne,a   0xa00c8e04
a00c8d6c:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00c8d70:  c2 4f bf d8  ldsb  [ %fp + -40 ], %g1
a00c8d74:  80 a0 60 00  cmp  %g1, 0
a00c8d78:  16 80 00 06  bge  0xa00c8d90
a00c8d7c:  d8 0f bf d8  ldub  [ %fp + -40 ], %o4
a00c8d80:  9a 04 00 12  add  %l0, %l2, %o5
a00c8d84:  82 10 20 01  mov  1, %g1
a00c8d88:  10 80 00 09  b  0xa00c8dac
a00c8d8c:  c2 2b 60 05  stb  %g1, [ %o5 + 5 ]
a00c8d90:  d6 0f bf d9  ldub  [ %fp + -39 ], %o3
a00c8d94:  82 0a e0 ff  and  %o3, 0xff, %g1
a00c8d98:  80 88 60 08  btst  8, %g1
a00c8d9c:  02 80 00 09  be  0xa00c8dc0
a00c8da0:  94 04 00 12  add  %l0, %l2, %o2
a00c8da4:  82 10 20 01  mov  1, %g1
a00c8da8:  c2 2a a0 06  stb  %g1, [ %o2 + 6 ]
a00c8dac:  da 04 80 10  ld  [ %l2 + %l0 ], %o5
a00c8db0:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00c8db4:  82 2b 40 01  andn  %o5, %g1, %g1
a00c8db8:  10 80 00 14  b  0xa00c8e08
a00c8dbc:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00c8dc0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c8dc4:  83 30 60 03  srl  %g1, 3, %g1
a00c8dc8:  98 0b 20 7f  and  %o4, 0x7f, %o4
a00c8dcc:  96 0a e0 07  and  %o3, 7, %o3
a00c8dd0:  9b 33 60 07  srl  %o5, 7, %o5
a00c8dd4:  82 08 60 01  and  %g1, 1, %g1
a00c8dd8:  c2 2a a0 06  stb  %g1, [ %o2 + 6 ]
a00c8ddc:  d8 2a a0 03  stb  %o4, [ %o2 + 3 ]
a00c8de0:  d6 2a a0 04  stb  %o3, [ %o2 + 4 ]
a00c8de4:  da 2a a0 05  stb  %o5, [ %o2 + 5 ]
a00c8de8:  a2 10 00 0c  mov  %o4, %l1
a00c8dec:  7f ff fb 83  call  0xa00c7bf8
a00c8df0:  90 10 00 18  mov  %i0, %o0
a00c8df4:  80 8a 20 ff  btst  0xff, %o0
a00c8df8:  02 80 00 07  be  0xa00c8e14
a00c8dfc:  a6 0c 60 ff  and  %l1, 0xff, %l3
a00c8e00:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00c8e04:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00c8e08:  82 10 40 0d  or  %g1, %o5, %g1
a00c8e0c:  10 80 00 a8  b  0xa00c90ac
a00c8e10:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a00c8e14:  a2 0d 20 ff  and  %l4, 0xff, %l1
a00c8e18:  95 2c e0 02  sll  %l3, 2, %o2
a00c8e1c:  94 02 80 13  add  %o2, %l3, %o2
a00c8e20:  90 10 00 18  mov  %i0, %o0
a00c8e24:  7f ff fe 80  call  0xa00c8824
a00c8e28:  92 10 00 11  mov  %l1, %o1
a00c8e2c:  80 a4 e0 00  cmp  %l3, 0
a00c8e30:  32 80 00 0a  bne,a   0xa00c8e58
a00c8e34:  90 10 00 11  mov  %l1, %o0
a00c8e38:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00c8e3c:  40 3a e8 82  call  0xa0f83044
a00c8e40:  90 12 20 88  or  %o0, 0x88, %o0	! 0x9f1c2088
a00c8e44:  da 04 80 10  ld  [ %l2 + %l0 ], %o5
a00c8e48:  03 04 00 00  sethi  %hi(0x10000000), %g1
a00c8e4c:  82 2b 40 01  andn  %o5, %g1, %g1
a00c8e50:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a00c8e54:  90 10 00 11  mov  %l1, %o0
a00c8e58:  92 10 22 00  mov  0x200, %o1
a00c8e5c:  40 3b b5 da  call  0xa0fb65c4
a00c8e60:  d4 0f bf d8  ldub  [ %fp + -40 ], %o2
a00c8e64:  90 10 00 11  mov  %l1, %o0
a00c8e68:  92 10 22 01  mov  0x201, %o1
a00c8e6c:  40 3b b5 d6  call  0xa0fb65c4
a00c8e70:  d4 0f bf d9  ldub  [ %fp + -39 ], %o2
a00c8e74:  90 10 00 18  mov  %i0, %o0
a00c8e78:  92 07 bf e0  add  %fp, -32, %o1
a00c8e7c:  7f ff fd da  call  0xa00c85e4
a00c8e80:  94 10 20 01  mov  1, %o2
a00c8e84:  a0 10 20 00  clr  %l0
a00c8e88:  92 0c 20 ff  and  %l0, 0xff, %o1
a00c8e8c:  82 0c 20 ff  and  %l0, 0xff, %g1
a00c8e90:  92 02 62 02  add  %o1, 0x202, %o1
a00c8e94:  82 07 80 01  add  %fp, %g1, %g1
a00c8e98:  93 2a 60 10  sll  %o1, 0x10, %o1
a00c8e9c:  d4 08 7f e0  ldub  [ %g1 + -32 ], %o2
a00c8ea0:  93 32 60 10  srl  %o1, 0x10, %o1
a00c8ea4:  40 3b b5 c8  call  0xa0fb65c4
a00c8ea8:  90 10 00 11  mov  %l1, %o0
a00c8eac:  a0 04 20 01  inc  %l0
a00c8eb0:  82 0c 20 ff  and  %l0, 0xff, %g1
a00c8eb4:  80 a0 60 07  cmp  %g1, 7
a00c8eb8:  28 bf ff f6  bleu,a   0xa00c8e90
a00c8ebc:  92 0c 20 ff  and  %l0, 0xff, %o1
a00c8ec0:  90 10 00 11  mov  %l1, %o0
a00c8ec4:  92 10 20 33  mov  0x33, %o1
a00c8ec8:  40 3b b5 bf  call  0xa0fb65c4
a00c8ecc:  94 10 20 00  clr  %o2
a00c8ed0:  90 10 00 11  mov  %l1, %o0
a00c8ed4:  92 10 20 34  mov  0x34, %o1
a00c8ed8:  94 10 20 00  clr  %o2
a00c8edc:  40 3b b5 ba  call  0xa0fb65c4
a00c8ee0:  a1 2c e0 02  sll  %l3, 2, %l0
a00c8ee4:  a0 04 00 13  add  %l0, %l3, %l0
a00c8ee8:  90 10 00 11  mov  %l1, %o0
a00c8eec:  94 0c 20 ff  and  %l0, 0xff, %o2
a00c8ef0:  40 3b b5 b5  call  0xa0fb65c4
a00c8ef4:  92 10 20 35  mov  0x35, %o1
a00c8ef8:  90 10 00 11  mov  %l1, %o0
a00c8efc:  95 34 20 08  srl  %l0, 8, %o2
a00c8f00:  40 3b b5 b1  call  0xa0fb65c4
a00c8f04:  92 10 20 36  mov  0x36, %o1
a00c8f08:  90 10 00 11  mov  %l1, %o0
a00c8f0c:  92 10 20 37  mov  0x37, %o1
a00c8f10:  94 10 20 04  mov  4, %o2
a00c8f14:  40 3b b6 29  call  0xa0fb67b8
a00c8f18:  96 10 20 01  mov  1, %o3
a00c8f1c:  92 10 20 37  mov  0x37, %o1
a00c8f20:  94 10 20 01  mov  1, %o2
a00c8f24:  96 10 20 00  clr  %o3
a00c8f28:  40 3b b6 24  call  0xa0fb67b8
a00c8f2c:  90 10 00 11  mov  %l1, %o0
a00c8f30:  40 3b e2 19  call  0xa0fc1794
a00c8f34:  90 10 20 0a  mov  0xa, %o0
a00c8f38:  90 10 00 11  mov  %l1, %o0
a00c8f3c:  92 10 20 37  mov  0x37, %o1
a00c8f40:  94 10 20 01  mov  1, %o2
a00c8f44:  40 3b b6 1d  call  0xa0fb67b8
a00c8f48:  96 10 20 01  mov  1, %o3
a00c8f4c:  90 10 00 11  mov  %l1, %o0
a00c8f50:  40 3b b5 8b  call  0xa0fb657c
a00c8f54:  92 10 20 37  mov  0x37, %o1
a00c8f58:  80 8a 20 01  btst  1, %o0
a00c8f5c:  22 bf ff fd  be,a   0xa00c8f50
a00c8f60:  90 10 00 11  mov  %l1, %o0
a00c8f64:  92 10 22 0d  mov  0x20d, %o1
a00c8f68:  40 3b b5 85  call  0xa0fb657c
a00c8f6c:  90 10 00 11  mov  %l1, %o0
a00c8f70:  21 2a 01 f4  sethi  %hi(0xa807d000), %l0
a00c8f74:  d0 2c 22 38  stb  %o0, [ %l0 + 0x238 ]	! 0xa807d238
a00c8f78:  92 10 22 0c  mov  0x20c, %o1
a00c8f7c:  90 10 00 11  mov  %l1, %o0
a00c8f80:  40 3b b5 7f  call  0xa0fb657c
a00c8f84:  a0 14 22 38  or  %l0, 0x238, %l0
a00c8f88:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00c8f8c:  92 10 22 0b  mov  0x20b, %o1
a00c8f90:  40 3b b5 7b  call  0xa0fb657c
a00c8f94:  90 10 00 11  mov  %l1, %o0
a00c8f98:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00c8f9c:  92 10 22 0a  mov  0x20a, %o1
a00c8fa0:  40 3b b5 77  call  0xa0fb657c
a00c8fa4:  90 10 00 11  mov  %l1, %o0
a00c8fa8:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00c8fac:  92 10 22 11  mov  0x211, %o1
a00c8fb0:  40 3b b5 73  call  0xa0fb657c
a00c8fb4:  90 10 00 11  mov  %l1, %o0
a00c8fb8:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00c8fbc:  92 10 22 10  mov  0x210, %o1
a00c8fc0:  40 3b b5 6f  call  0xa0fb657c
a00c8fc4:  90 10 00 11  mov  %l1, %o0
a00c8fc8:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00c8fcc:  92 10 22 0f  mov  0x20f, %o1
a00c8fd0:  40 3b b5 6b  call  0xa0fb657c
a00c8fd4:  90 10 00 11  mov  %l1, %o0
a00c8fd8:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00c8fdc:  92 10 22 0e  mov  0x20e, %o1
a00c8fe0:  40 3b b5 67  call  0xa0fb657c
a00c8fe4:  90 10 00 11  mov  %l1, %o0
a00c8fe8:  d0 2c 20 07  stb  %o0, [ %l0 + 7 ]
a00c8fec:  92 10 22 15  mov  0x215, %o1
a00c8ff0:  40 3b b5 63  call  0xa0fb657c
a00c8ff4:  90 10 00 11  mov  %l1, %o0
a00c8ff8:  d0 2c 20 08  stb  %o0, [ %l0 + 8 ]
a00c8ffc:  92 10 22 14  mov  0x214, %o1
a00c9000:  40 3b b5 5f  call  0xa0fb657c
a00c9004:  90 10 00 11  mov  %l1, %o0
a00c9008:  d0 2c 20 09  stb  %o0, [ %l0 + 9 ]
a00c900c:  92 10 22 13  mov  0x213, %o1
a00c9010:  40 3b b5 5b  call  0xa0fb657c
a00c9014:  90 10 00 11  mov  %l1, %o0
a00c9018:  d0 2c 20 0a  stb  %o0, [ %l0 + 0xa ]
a00c901c:  92 10 22 12  mov  0x212, %o1
a00c9020:  40 3b b5 57  call  0xa0fb657c
a00c9024:  90 10 00 11  mov  %l1, %o0
a00c9028:  d0 2c 20 0b  stb  %o0, [ %l0 + 0xb ]
a00c902c:  92 10 22 19  mov  0x219, %o1
a00c9030:  40 3b b5 53  call  0xa0fb657c
a00c9034:  90 10 00 11  mov  %l1, %o0
a00c9038:  d0 2c 20 0c  stb  %o0, [ %l0 + 0xc ]
a00c903c:  92 10 22 18  mov  0x218, %o1
a00c9040:  40 3b b5 4f  call  0xa0fb657c
a00c9044:  90 10 00 11  mov  %l1, %o0
a00c9048:  d0 2c 20 0d  stb  %o0, [ %l0 + 0xd ]
a00c904c:  92 10 22 17  mov  0x217, %o1
a00c9050:  40 3b b5 4b  call  0xa0fb657c
a00c9054:  90 10 00 11  mov  %l1, %o0
a00c9058:  d0 2c 20 0e  stb  %o0, [ %l0 + 0xe ]
a00c905c:  92 10 22 16  mov  0x216, %o1
a00c9060:  40 3b b5 47  call  0xa0fb657c
a00c9064:  90 10 00 11  mov  %l1, %o0
a00c9068:  d0 2c 20 0f  stb  %o0, [ %l0 + 0xf ]
a00c906c:  92 10 22 1d  mov  0x21d, %o1
a00c9070:  40 3b b5 43  call  0xa0fb657c
a00c9074:  90 10 00 11  mov  %l1, %o0
a00c9078:  d0 2c 20 10  stb  %o0, [ %l0 + 0x10 ]
a00c907c:  92 10 22 1c  mov  0x21c, %o1
a00c9080:  40 3b b5 3f  call  0xa0fb657c
a00c9084:  90 10 00 11  mov  %l1, %o0
a00c9088:  d0 2c 20 11  stb  %o0, [ %l0 + 0x11 ]
a00c908c:  92 10 22 1b  mov  0x21b, %o1
a00c9090:  40 3b b5 3b  call  0xa0fb657c
a00c9094:  90 10 00 11  mov  %l1, %o0
a00c9098:  d0 2c 20 12  stb  %o0, [ %l0 + 0x12 ]
a00c909c:  90 10 00 11  mov  %l1, %o0
a00c90a0:  40 3b b5 37  call  0xa0fb657c
a00c90a4:  92 10 22 1a  mov  0x21a, %o1
a00c90a8:  d0 2c 20 13  stb  %o0, [ %l0 + 0x13 ]
a00c90ac:  81 c7 e0 08  ret
a00c90b0:  81 e8 00 00  restore
