# leon2s FUN_a00d0d78 0xa00d0d78-0xa00d12e4 (192 bytes)
a00d0d78:  9d e3 bf 98  save  %sp, -104, %sp
a00d0d7c:  94 0e 20 ff  and  %i0, 0xff, %o2
a00d0d80:  82 02 80 0a  add  %o2, %o2, %g1
a00d0d84:  82 00 40 0a  add  %g1, %o2, %g1
a00d0d88:  1f 2a 01 e2  sethi  %hi(0xa8078800), %o7
a00d0d8c:  83 28 60 03  sll  %g1, 3, %g1
a00d0d90:  98 13 e3 b0  or  %o7, 0x3b0, %o4
a00d0d94:  da 10 40 0c  lduh  [ %g1 + %o4 ], %o5
a00d0d98:  96 00 40 0c  add  %g1, %o4, %o3
a00d0d9c:  92 0b 60 03  and  %o5, 3, %o1
a00d0da0:  98 0a 60 ff  and  %o1, 0xff, %o4
a00d0da4:  80 a3 20 03  cmp  %o4, 3
a00d0da8:  02 80 01 4c  be  0xa00d12d8
a00d0dac:  c2 0a e0 02  ldub  [ %o3 + 2 ], %g1
a00d0db0:  9a 08 60 ff  and  %g1, 0xff, %o5
a00d0db4:  82 10 20 64  mov  0x64, %g1
a00d0db8:  80 a3 60 4f  cmp  %o5, 0x4f
a00d0dbc:  18 80 00 dd  bgu  0xa00d1130
a00d0dc0:  c2 32 e0 16  sth  %g1, [ %o3 + 0x16 ]
a00d0dc4:  83 2b 60 02  sll  %o5, 2, %g1
a00d0dc8:  1b 27 c7 03  sethi  %hi(0x9f1c0c00), %o5
a00d0dcc:  9a 13 60 38  or  %o5, 0x38, %o5	! 0x9f1c0c38
a00d0dd0:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00d0dd4:  81 c0 40 00  jmp  %g1
a00d0dd8:  01 00 00 00  nop
a00d0ddc:  80 a3 20 01  cmp  %o4, 1
a00d0de0:  32 80 00 d4  bne,a   0xa00d1130
a00d0de4:  c0 2a e0 02  clrb  [ %o3 + 2 ]
a00d0de8:  10 80 00 d2  b  0xa00d1130
a00d0dec:  d8 2a e0 02  stb  %o4, [ %o3 + 2 ]
a00d0df0:  80 a3 20 01  cmp  %o4, 1
a00d0df4:  02 80 00 ce  be  0xa00d112c
a00d0df8:  82 10 20 10  mov  0x10, %g1
a00d0dfc:  80 a3 20 02  cmp  %o4, 2
a00d0e00:  32 80 00 cc  bne,a   0xa00d1130
a00d0e04:  c0 2a e0 02  clrb  [ %o3 + 2 ]
a00d0e08:  10 80 00 c9  b  0xa00d112c
a00d0e0c:  82 10 20 40  mov  0x40, %g1
a00d0e10:  80 a3 20 01  cmp  %o4, 1
a00d0e14:  02 80 00 c6  be  0xa00d112c
a00d0e18:  82 10 20 11  mov  0x11, %g1
a00d0e1c:  10 80 00 c4  b  0xa00d112c
a00d0e20:  82 10 20 01  mov  1, %g1
a00d0e24:  80 a3 20 01  cmp  %o4, 1
a00d0e28:  02 80 00 c1  be  0xa00d112c
a00d0e2c:  82 10 20 12  mov  0x12, %g1
a00d0e30:  10 80 00 bf  b  0xa00d112c
a00d0e34:  82 10 20 01  mov  1, %g1
a00d0e38:  80 a3 20 00  cmp  %o4, 0
a00d0e3c:  02 80 00 bc  be  0xa00d112c
a00d0e40:  82 10 20 13  mov  0x13, %g1
a00d0e44:  10 80 00 bc  b  0xa00d1134
a00d0e48:  c2 0a e0 02  ldub  [ %o3 + 2 ], %g1
a00d0e4c:  82 02 7f ff  add  %o1, -1, %g1
a00d0e50:  82 08 60 ff  and  %g1, 0xff, %g1
a00d0e54:  80 a0 60 01  cmp  %g1, 1
a00d0e58:  18 80 00 b5  bgu  0xa00d112c
a00d0e5c:  82 10 20 01  mov  1, %g1
a00d0e60:  82 02 80 0a  add  %o2, %o2, %g1
a00d0e64:  82 00 40 0a  add  %g1, %o2, %g1
a00d0e68:  9a 13 e3 b0  or  %o7, 0x3b0, %o5
a00d0e6c:  83 28 60 03  sll  %g1, 3, %g1
a00d0e70:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00d0e74:  83 30 60 1c  srl  %g1, 0x1c, %g1
a00d0e78:  80 88 60 01  btst  1, %g1
a00d0e7c:  22 80 00 ac  be,a   0xa00d112c
a00d0e80:  82 10 20 16  mov  0x16, %g1
a00d0e84:  10 80 00 aa  b  0xa00d112c
a00d0e88:  82 10 20 14  mov  0x14, %g1
a00d0e8c:  80 a3 20 01  cmp  %o4, 1
a00d0e90:  02 80 00 a7  be  0xa00d112c
a00d0e94:  82 10 20 15  mov  0x15, %g1
a00d0e98:  80 a3 20 02  cmp  %o4, 2
a00d0e9c:  02 80 00 84  be  0xa00d10ac
a00d0ea0:  82 10 20 01  mov  1, %g1
a00d0ea4:  10 80 00 a3  b  0xa00d1130
a00d0ea8:  c2 2a e0 02  stb  %g1, [ %o3 + 2 ]
a00d0eac:  80 a3 20 01  cmp  %o4, 1
a00d0eb0:  32 80 00 9f  bne,a   0xa00d112c
a00d0eb4:  82 10 20 01  mov  1, %g1
a00d0eb8:  10 80 00 9d  b  0xa00d112c
a00d0ebc:  82 10 20 16  mov  0x16, %g1
a00d0ec0:  80 a3 20 01  cmp  %o4, 1
a00d0ec4:  02 80 00 7a  be  0xa00d10ac
a00d0ec8:  82 10 20 17  mov  0x17, %g1
a00d0ecc:  10 80 00 98  b  0xa00d112c
a00d0ed0:  82 10 20 01  mov  1, %g1
a00d0ed4:  80 a3 20 01  cmp  %o4, 1
a00d0ed8:  32 80 00 95  bne,a   0xa00d112c
a00d0edc:  82 10 20 01  mov  1, %g1
a00d0ee0:  82 10 20 18  mov  0x18, %g1
a00d0ee4:  c2 2a e0 02  stb  %g1, [ %o3 + 2 ]
a00d0ee8:  da 02 c0 00  ld  [ %o3 ], %o5
a00d0eec:  03 03 c0 00  sethi  %hi(0xf000000), %g1
a00d0ef0:  82 2b 40 01  andn  %o5, %g1, %g1
a00d0ef4:  10 80 00 71  b  0xa00d10b8
a00d0ef8:  1b 00 c0 00  sethi  %hi(0x3000000), %o5
a00d0efc:  80 a3 20 01  cmp  %o4, 1
a00d0f00:  02 80 00 8c  be  0xa00d1130
a00d0f04:  82 10 20 01  mov  1, %g1
a00d0f08:  10 80 00 8a  b  0xa00d1130
a00d0f0c:  c2 2a e0 02  stb  %g1, [ %o3 + 2 ]
a00d0f10:  80 a3 20 01  cmp  %o4, 1
a00d0f14:  12 80 00 09  bne  0xa00d0f38
a00d0f18:  80 a3 20 03  cmp  %o4, 3
a00d0f1c:  82 10 20 41  mov  0x41, %g1
a00d0f20:  c2 2a e0 02  stb  %g1, [ %o3 + 2 ]
a00d0f24:  da 02 c0 00  ld  [ %o3 ], %o5
a00d0f28:  03 03 c0 00  sethi  %hi(0xf000000), %g1
a00d0f2c:  82 2b 40 01  andn  %o5, %g1, %g1
a00d0f30:  10 80 00 62  b  0xa00d10b8
a00d0f34:  1b 02 80 00  sethi  %hi(0xa000000), %o5
a00d0f38:  02 80 00 e8  be  0xa00d12d8
a00d0f3c:  01 00 00 00  nop
a00d0f40:  10 80 00 7c  b  0xa00d1130
a00d0f44:  c0 2a e0 02  clrb  [ %o3 + 2 ]
a00d0f48:  80 a3 20 01  cmp  %o4, 1
a00d0f4c:  02 80 00 78  be  0xa00d112c
a00d0f50:  82 10 20 42  mov  0x42, %g1
a00d0f54:  10 80 00 77  b  0xa00d1130
a00d0f58:  c0 2a e0 02  clrb  [ %o3 + 2 ]
a00d0f5c:  80 a3 20 01  cmp  %o4, 1
a00d0f60:  32 80 00 74  bne,a   0xa00d1130
a00d0f64:  c0 2a e0 02  clrb  [ %o3 + 2 ]
a00d0f68:  c2 02 c0 00  ld  [ %o3 ], %g1
a00d0f6c:  1b 00 02 00  sethi  %hi(0x80000), %o5
a00d0f70:  82 10 40 0d  or  %g1, %o5, %g1
a00d0f74:  1b 08 00 00  sethi  %hi(0x20000000), %o5
a00d0f78:  80 88 40 0d  btst  %g1, %o5
a00d0f7c:  02 80 00 04  be  0xa00d0f8c
a00d0f80:  c2 22 c0 00  st  %g1, [ %o3 ]
a00d0f84:  10 80 00 6a  b  0xa00d112c
a00d0f88:  82 10 20 44  mov  0x44, %g1
a00d0f8c:  10 80 00 68  b  0xa00d112c
a00d0f90:  82 10 20 43  mov  0x43, %g1
a00d0f94:  80 a3 20 01  cmp  %o4, 1
a00d0f98:  02 80 00 65  be  0xa00d112c
a00d0f9c:  82 10 20 45  mov  0x45, %g1
a00d0fa0:  10 80 00 63  b  0xa00d112c
a00d0fa4:  82 10 20 40  mov  0x40, %g1
a00d0fa8:  80 a3 20 01  cmp  %o4, 1
a00d0fac:  12 80 00 60  bne  0xa00d112c
a00d0fb0:  82 10 20 40  mov  0x40, %g1
a00d0fb4:  da 02 c0 00  ld  [ %o3 ], %o5
a00d0fb8:  03 03 c0 00  sethi  %hi(0xf000000), %g1
a00d0fbc:  82 2b 40 01  andn  %o5, %g1, %g1
a00d0fc0:  1b 01 40 00  sethi  %hi(0x5000000), %o5
a00d0fc4:  82 10 40 0d  or  %g1, %o5, %g1
a00d0fc8:  1b 08 00 00  sethi  %hi(0x20000000), %o5
a00d0fcc:  80 88 40 0d  btst  %g1, %o5
a00d0fd0:  12 80 00 07  bne  0xa00d0fec
a00d0fd4:  c2 22 c0 00  st  %g1, [ %o3 ]
a00d0fd8:  10 80 00 55  b  0xa00d112c
a00d0fdc:  82 10 20 46  mov  0x46, %g1
a00d0fe0:  80 a3 20 01  cmp  %o4, 1
a00d0fe4:  32 80 00 52  bne,a   0xa00d112c
a00d0fe8:  82 10 20 40  mov  0x40, %g1
a00d0fec:  10 80 00 50  b  0xa00d112c
a00d0ff0:  82 10 20 47  mov  0x47, %g1
a00d0ff4:  80 a3 20 01  cmp  %o4, 1
a00d0ff8:  02 80 00 4d  be  0xa00d112c
a00d0ffc:  82 10 20 48  mov  0x48, %g1
a00d1000:  10 80 00 4b  b  0xa00d112c
a00d1004:  82 10 20 40  mov  0x40, %g1
a00d1008:  80 a3 20 01  cmp  %o4, 1
a00d100c:  02 80 00 48  be  0xa00d112c
a00d1010:  82 10 20 49  mov  0x49, %g1
a00d1014:  80 a3 20 02  cmp  %o4, 2
a00d1018:  12 80 00 45  bne  0xa00d112c
a00d101c:  82 10 20 40  mov  0x40, %g1
a00d1020:  82 10 20 47  mov  0x47, %g1
a00d1024:  c2 2a e0 02  stb  %g1, [ %o3 + 2 ]
a00d1028:  d8 02 c0 00  ld  [ %o3 ], %o4
a00d102c:  83 33 20 18  srl  %o4, 0x18, %g1
a00d1030:  82 08 60 0f  and  %g1, 0xf, %g1
a00d1034:  82 00 7f ff  add  %g1, -1, %g1
a00d1038:  82 08 60 0f  and  %g1, 0xf, %g1
a00d103c:  1b 03 c0 00  sethi  %hi(0xf000000), %o5
a00d1040:  9a 2b 00 0d  andn  %o4, %o5, %o5
a00d1044:  83 28 60 18  sll  %g1, 0x18, %g1
a00d1048:  9a 13 40 01  or  %o5, %g1, %o5
a00d104c:  10 80 00 39  b  0xa00d1130
a00d1050:  da 22 c0 00  st  %o5, [ %o3 ]
a00d1054:  80 a3 20 01  cmp  %o4, 1
a00d1058:  02 80 00 14  be  0xa00d10a8
a00d105c:  80 a3 20 02  cmp  %o4, 2
a00d1060:  22 80 00 33  be,a   0xa00d112c
a00d1064:  82 10 20 4a  mov  0x4a, %g1
a00d1068:  10 80 00 31  b  0xa00d112c
a00d106c:  82 10 20 40  mov  0x40, %g1
a00d1070:  80 a3 20 01  cmp  %o4, 1
a00d1074:  02 80 00 2e  be  0xa00d112c
a00d1078:  82 10 20 4b  mov  0x4b, %g1
a00d107c:  80 a3 20 02  cmp  %o4, 2
a00d1080:  12 80 00 2b  bne  0xa00d112c
a00d1084:  82 10 20 40  mov  0x40, %g1
a00d1088:  10 80 00 0a  b  0xa00d10b0
a00d108c:  c0 2a e0 02  clrb  [ %o3 + 2 ]
a00d1090:  80 a3 20 01  cmp  %o4, 1
a00d1094:  02 80 00 06  be  0xa00d10ac
a00d1098:  82 10 20 4c  mov  0x4c, %g1
a00d109c:  80 a3 20 02  cmp  %o4, 2
a00d10a0:  12 80 00 23  bne  0xa00d112c
a00d10a4:  82 10 20 40  mov  0x40, %g1
a00d10a8:  82 10 20 4e  mov  0x4e, %g1
a00d10ac:  c2 2a e0 02  stb  %g1, [ %o3 + 2 ]
a00d10b0:  c2 02 c0 00  ld  [ %o3 ], %g1
a00d10b4:  1b 00 20 00  sethi  %hi(0x800000), %o5
a00d10b8:  82 10 40 0d  or  %g1, %o5, %g1
a00d10bc:  10 80 00 1d  b  0xa00d1130
a00d10c0:  c2 22 c0 00  st  %g1, [ %o3 ]
a00d10c4:  80 a3 20 01  cmp  %o4, 1
a00d10c8:  02 80 00 19  be  0xa00d112c
a00d10cc:  82 10 20 4d  mov  0x4d, %g1
a00d10d0:  10 80 00 17  b  0xa00d112c
a00d10d4:  82 10 20 40  mov  0x40, %g1
a00d10d8:  80 a3 20 01  cmp  %o4, 1
a00d10dc:  02 80 00 14  be  0xa00d112c
a00d10e0:  82 10 20 4e  mov  0x4e, %g1
a00d10e4:  80 a3 20 02  cmp  %o4, 2
a00d10e8:  02 80 00 11  be  0xa00d112c
a00d10ec:  82 10 20 4c  mov  0x4c, %g1
a00d10f0:  10 80 00 0f  b  0xa00d112c
a00d10f4:  82 10 20 40  mov  0x40, %g1
a00d10f8:  80 a3 20 00  cmp  %o4, 0
a00d10fc:  02 80 00 0c  be  0xa00d112c
a00d1100:  82 10 20 4f  mov  0x4f, %g1
a00d1104:  10 80 00 0c  b  0xa00d1134
a00d1108:  c2 0a e0 02  ldub  [ %o3 + 2 ], %g1
a00d110c:  80 a3 20 02  cmp  %o4, 2
a00d1110:  12 80 00 04  bne  0xa00d1120
a00d1114:  80 a3 20 00  cmp  %o4, 0
a00d1118:  10 80 00 05  b  0xa00d112c
a00d111c:  82 10 20 4a  mov  0x4a, %g1
a00d1120:  32 80 00 05  bne,a   0xa00d1134
a00d1124:  c2 0a e0 02  ldub  [ %o3 + 2 ], %g1
a00d1128:  82 10 20 01  mov  1, %g1
a00d112c:  c2 2a e0 02  stb  %g1, [ %o3 + 2 ]
a00d1130:  c2 0a e0 02  ldub  [ %o3 + 2 ], %g1
a00d1134:  80 a0 60 4f  cmp  %g1, 0x4f
a00d1138:  38 80 00 5e  bgu,a   0xa00d12b0
a00d113c:  c2 02 c0 00  ld  [ %o3 ], %g1
a00d1140:  1b 27 c7 02  sethi  %hi(0x9f1c0800), %o5
a00d1144:  9a 13 62 f8  or  %o5, 0x2f8, %o5	! 0x9f1c0af8
a00d1148:  83 28 60 02  sll  %g1, 2, %g1
a00d114c:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00d1150:  81 c0 40 00  jmp  %g1
a00d1154:  da 02 c0 00  ld  [ %o3 ], %o5
a00d1158:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00d115c:  82 2b 40 01  andn  %o5, %g1, %g1
a00d1160:  c2 22 c0 00  st  %g1, [ %o3 ]
a00d1164:  10 80 00 58  b  0xa00d12c4
a00d1168:  82 10 21 f4  mov  0x1f4, %g1
a00d116c:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00d1170:  82 2b 40 01  andn  %o5, %g1, %g1
a00d1174:  1b 03 c0 00  sethi  %hi(0xf000000), %o5
a00d1178:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d117c:  10 80 00 24  b  0xa00d120c
a00d1180:  03 02 80 00  sethi  %hi(0xa000000), %g1
a00d1184:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00d1188:  82 13 40 01  or  %o5, %g1, %g1
a00d118c:  1b 03 c0 00  sethi  %hi(0xf000000), %o5
a00d1190:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d1194:  03 02 80 00  sethi  %hi(0xa000000), %g1
a00d1198:  9a 13 40 01  or  %o5, %g1, %o5
a00d119c:  03 00 00 04  sethi  %hi(0x1000), %g1
a00d11a0:  82 10 63 88  or  %g1, 0x388, %g1	! 0x1388
a00d11a4:  10 80 00 1b  b  0xa00d1210
a00d11a8:  c2 32 e0 16  sth  %g1, [ %o3 + 0x16 ]
a00d11ac:  10 80 00 42  b  0xa00d12b4
a00d11b0:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00d11b4:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00d11b8:  82 2b 40 01  andn  %o5, %g1, %g1
a00d11bc:  1b 03 c0 00  sethi  %hi(0xf000000), %o5
a00d11c0:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d11c4:  10 80 00 12  b  0xa00d120c
a00d11c8:  03 00 c0 00  sethi  %hi(0x3000000), %g1
a00d11cc:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00d11d0:  82 2b 40 01  andn  %o5, %g1, %g1
a00d11d4:  1b 03 c0 00  sethi  %hi(0xf000000), %o5
a00d11d8:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d11dc:  10 80 00 0c  b  0xa00d120c
a00d11e0:  03 01 40 00  sethi  %hi(0x5000000), %g1
a00d11e4:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00d11e8:  82 13 40 01  or  %o5, %g1, %g1
a00d11ec:  c2 22 c0 00  st  %g1, [ %o3 ]
a00d11f0:  10 80 00 35  b  0xa00d12c4
a00d11f4:  82 10 20 64  mov  0x64, %g1
a00d11f8:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00d11fc:  82 2b 40 01  andn  %o5, %g1, %g1
a00d1200:  1b 03 c0 00  sethi  %hi(0xf000000), %o5
a00d1204:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d1208:  03 01 00 00  sethi  %hi(0x4000000), %g1
a00d120c:  9a 13 40 01  or  %o5, %g1, %o5
a00d1210:  10 80 00 2e  b  0xa00d12c8
a00d1214:  da 22 c0 00  st  %o5, [ %o3 ]
a00d1218:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00d121c:  82 13 40 01  or  %o5, %g1, %g1
a00d1220:  c2 22 c0 00  st  %g1, [ %o3 ]
a00d1224:  10 80 00 28  b  0xa00d12c4
a00d1228:  82 10 21 2c  mov  0x12c, %g1
a00d122c:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00d1230:  10 80 00 1c  b  0xa00d12a0
a00d1234:  82 13 40 01  or  %o5, %g1, %g1
a00d1238:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00d123c:  82 13 40 01  or  %o5, %g1, %g1
a00d1240:  c2 22 c0 00  st  %g1, [ %o3 ]
a00d1244:  10 80 00 20  b  0xa00d12c4
a00d1248:  82 10 2b b8  mov  0xbb8, %g1
a00d124c:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00d1250:  82 2b 40 01  andn  %o5, %g1, %g1
a00d1254:  c2 22 c0 00  st  %g1, [ %o3 ]
a00d1258:  10 80 00 1b  b  0xa00d12c4
a00d125c:  82 10 20 c8  mov  0xc8, %g1
a00d1260:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00d1264:  82 2b 40 01  andn  %o5, %g1, %g1
a00d1268:  10 80 00 18  b  0xa00d12c8
a00d126c:  c2 22 c0 00  st  %g1, [ %o3 ]
a00d1270:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00d1274:  82 13 40 01  or  %o5, %g1, %g1
a00d1278:  c2 22 c0 00  st  %g1, [ %o3 ]
a00d127c:  10 80 00 12  b  0xa00d12c4
a00d1280:  82 10 20 96  mov  0x96, %g1
a00d1284:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00d1288:  82 13 40 01  or  %o5, %g1, %g1
a00d128c:  c2 22 c0 00  st  %g1, [ %o3 ]
a00d1290:  10 80 00 0d  b  0xa00d12c4
a00d1294:  82 10 20 dc  mov  0xdc, %g1
a00d1298:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00d129c:  82 2b 40 01  andn  %o5, %g1, %g1
a00d12a0:  c2 22 c0 00  st  %g1, [ %o3 ]
a00d12a4:  10 80 00 08  b  0xa00d12c4
a00d12a8:  82 10 23 e8  mov  0x3e8, %g1
a00d12ac:  c2 02 c0 00  ld  [ %o3 ], %g1
a00d12b0:  1b 10 00 00  sethi  %hi(0x40000000), %o5
a00d12b4:  82 10 40 0d  or  %g1, %o5, %g1
a00d12b8:  c2 22 c0 00  st  %g1, [ %o3 ]
a00d12bc:  03 00 00 04  sethi  %hi(0x1000), %g1
a00d12c0:  82 10 63 88  or  %g1, 0x388, %g1	! 0x1388
a00d12c4:  c2 32 e0 16  sth  %g1, [ %o3 + 0x16 ]
a00d12c8:  90 0e 20 ff  and  %i0, 0xff, %o0
a00d12cc:  90 02 20 0b  add  %o0, 0xb, %o0
a00d12d0:  7f ff fc 98  call  0xa00d0530
a00d12d4:  d2 12 e0 16  lduh  [ %o3 + 0x16 ], %o1
a00d12d8:  01 00 00 00  nop
a00d12dc:  81 c7 e0 08  ret
a00d12e0:  81 e8 00 00  restore
