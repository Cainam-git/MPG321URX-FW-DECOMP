# leon2m FUN_a00e0e44 0xa00e0e44-0xa00e1f50 (4364 bytes)
a00e0e44:  9d e3 bf 70  save  %sp, -144, %sp
a00e0e48:  39 2a 00 b5  sethi  %hi(0xa802d400), %i4
a00e0e4c:  c2 07 22 58  ld  [ %i4 + 0x258 ], %g1	! 0xa802d658
a00e0e50:  80 a6 00 01  cmp  %i0, %g1
a00e0e54:  1a 80 00 8c  bcc  0xa00e1084
a00e0e58:  37 2a 00 b5  sethi  %hi(0xa802d400), %i3
a00e0e5c:  35 00 02 03  sethi  %hi(0x80c00), %i2
a00e0e60:  d0 06 e2 54  ld  [ %i3 + 0x254 ], %o0
a00e0e64:  c2 0a 00 18  ldub  [ %o0 + %i0 ], %g1
a00e0e68:  80 a0 60 3d  cmp  %g1, 0x3d
a00e0e6c:  18 80 00 20  bgu  0xa00e0eec
a00e0e70:  96 10 20 00  clr  %o3
a00e0e74:  93 28 60 02  sll  %g1, 2, %o1
a00e0e78:  9a 16 a1 30  or  %i2, 0x130, %o5
a00e0e7c:  d8 03 40 09  ld  [ %o5 + %o1 ], %o4
a00e0e80:  81 c3 00 00  jmp  %o4
a00e0e84:  01 00 00 00  nop
a00e0e88:  91 3b e0 18  sra  %o7, 0x18, %o0
a00e0e8c:  7f ff f9 92  call  0xa00df4d4
a00e0e90:  01 00 00 00  nop
a00e0e94:  b0 06 20 01  inc  %i0
a00e0e98:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e0e9c:  d0 0e 00 0a  ldub  [ %i0 + %o2 ], %o0
a00e0ea0:  80 a2 20 00  cmp  %o0, 0
a00e0ea4:  12 bf ff f9  bne  0xa00e0e88
a00e0ea8:  9f 2a 20 18  sll  %o0, 0x18, %o7
a00e0eac:  13 00 03 fb  sethi  %hi(0xfec00), %o1
a00e0eb0:  7f ff f8 b0  call  0xa00df170
a00e0eb4:  90 12 63 90  or  %o1, 0x390, %o0	! 0xfef90
a00e0eb8:  10 80 00 08  b  0xa00e0ed8
a00e0ebc:  b0 06 20 01  inc  %i0
a00e0ec0:  e6 06 e2 54  ld  [ %i3 + 0x254 ], %l3
a00e0ec4:  17 00 06 65  sethi  %hi(0x199400), %o3
a00e0ec8:  90 12 e2 58  or  %o3, 0x258, %o0	! 0x199658
a00e0ecc:  7f ff f8 a9  call  0xa00df170
a00e0ed0:  d2 0c c0 18  ldub  [ %l3 + %i0 ], %o1
a00e0ed4:  b0 06 20 01  inc  %i0
a00e0ed8:  e6 07 22 58  ld  [ %i4 + 0x258 ], %l3
a00e0edc:  80 a6 00 13  cmp  %i0, %l3
a00e0ee0:  0a bf ff e1  bcs  0xa00e0e64
a00e0ee4:  d0 06 e2 54  ld  [ %i3 + 0x254 ], %o0
a00e0ee8:  30 80 00 67  b,a   0xa00e1084
a00e0eec:  21 00 06 65  sethi  %hi(0x199400), %l0
a00e0ef0:  7f ff f9 58  call  0xa00df450
a00e0ef4:  90 14 22 78  or  %l0, 0x278, %o0	! 0x199678
a00e0ef8:  10 bf ff f8  b  0xa00e0ed8
a00e0efc:  b0 06 20 01  inc  %i0
a00e0f00:  92 07 bf f8  add  %fp, -8, %o1
a00e0f04:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e0f08:  98 10 20 03  mov  3, %o4
a00e0f0c:  90 0a e0 ff  and  %o3, 0xff, %o0
a00e0f10:  b0 06 20 01  inc  %i0
a00e0f14:  a8 02 40 08  add  %o1, %o0, %l4
a00e0f18:  fa 0a 80 18  ldub  [ %o2 + %i0 ], %i5
a00e0f1c:  fa 2d 3f f0  stb  %i5, [ %l4 + -16 ]
a00e0f20:  98 83 3f ff  addcc  %o4, -1, %o4
a00e0f24:  1c bf ff fa  bpos  0xa00e0f0c
a00e0f28:  96 02 e0 01  inc  %o3
a00e0f2c:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00e0f30:  80 a0 60 ff  cmp  %g1, 0xff
a00e0f34:  e4 0f bf e9  ldub  [ %fp + -23 ], %l2
a00e0f38:  e6 0f bf ea  ldub  [ %fp + -22 ], %l3
a00e0f3c:  e8 0f bf eb  ldub  [ %fp + -21 ], %l4
a00e0f40:  02 80 00 03  be  0xa00e0f4c
a00e0f44:  9a 10 20 04  mov  4, %o5
a00e0f48:  9a 10 00 01  mov  %g1, %o5
a00e0f4c:  21 00 06 65  sethi  %hi(0x199400), %l0
a00e0f50:  82 14 22 2c  or  %l0, 0x22c, %g1	! 0x19962c
a00e0f54:  9b 2b 60 03  sll  %o5, 3, %o5
a00e0f58:  94 03 40 01  add  %o5, %g1, %o2
a00e0f5c:  e0 00 40 0d  ld  [ %g1 + %o5 ], %l0
a00e0f60:  e2 02 a0 04  ld  [ %o2 + 4 ], %l1
a00e0f64:  80 a4 00 11  cmp  %l0, %l1
a00e0f68:  14 bf ff db  bg  0xa00e0ed4
a00e0f6c:  90 10 00 10  mov  %l0, %o0
a00e0f70:  92 10 00 12  mov  %l2, %o1
a00e0f74:  94 10 00 13  mov  %l3, %o2
a00e0f78:  40 00 1b ce  call  0xa00e7eb0
a00e0f7c:  96 10 00 14  mov  %l4, %o3
a00e0f80:  10 bf ff f9  b  0xa00e0f64
a00e0f84:  a0 04 20 01  inc  %l0
a00e0f88:  92 07 bf f8  add  %fp, -8, %o1
a00e0f8c:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e0f90:  98 10 20 07  mov  7, %o4
a00e0f94:  ae 0a e0 ff  and  %o3, 0xff, %l7
a00e0f98:  b0 06 20 01  inc  %i0
a00e0f9c:  aa 02 40 17  add  %o1, %l7, %l5
a00e0fa0:  ec 0a 80 18  ldub  [ %o2 + %i0 ], %l6
a00e0fa4:  ec 2d 7f f0  stb  %l6, [ %l5 + -16 ]
a00e0fa8:  98 83 3f ff  addcc  %o4, -1, %o4
a00e0fac:  1c bf ff fa  bpos  0xa00e0f94
a00e0fb0:  96 02 e0 01  inc  %o3
a00e0fb4:  de 0f bf e9  ldub  [ %fp + -23 ], %o7
a00e0fb8:  91 2b e0 08  sll  %o7, 8, %o0
a00e0fbc:  d8 0f bf e8  ldub  [ %fp + -24 ], %o4
a00e0fc0:  fa 0f bf ea  ldub  [ %fp + -22 ], %i5
a00e0fc4:  92 12 00 1d  or  %o0, %i5, %o1
a00e0fc8:  80 a3 20 ff  cmp  %o4, 0xff
a00e0fcc:  e6 0f bf eb  ldub  [ %fp + -21 ], %l3
a00e0fd0:  e8 0f bf ec  ldub  [ %fp + -20 ], %l4
a00e0fd4:  ea 0f bf ed  ldub  [ %fp + -19 ], %l5
a00e0fd8:  ec 0f bf ee  ldub  [ %fp + -18 ], %l6
a00e0fdc:  ee 0f bf ef  ldub  [ %fp + -17 ], %l7
a00e0fe0:  02 80 00 03  be  0xa00e0fec
a00e0fe4:  9a 10 20 04  mov  4, %o5
a00e0fe8:  9a 10 00 0c  mov  %o4, %o5
a00e0fec:  21 00 06 65  sethi  %hi(0x199400), %l0
a00e0ff0:  a3 2b 60 03  sll  %o5, 3, %l1
a00e0ff4:  82 14 22 2c  or  %l0, 0x22c, %g1
a00e0ff8:  e0 00 40 11  ld  [ %g1 + %l1 ], %l0
a00e0ffc:  a4 04 40 01  add  %l1, %g1, %l2
a00e1000:  e2 04 a0 04  ld  [ %l2 + 4 ], %l1
a00e1004:  80 a4 00 11  cmp  %l0, %l1
a00e1008:  14 bf ff b3  bg  0xa00e0ed4
a00e100c:  a5 2a 60 10  sll  %o1, 0x10, %l2
a00e1010:  ba 10 20 01  mov  1, %i5
a00e1014:  90 10 00 10  mov  %l0, %o0
a00e1018:  ee 23 a0 5c  st  %l7, [ %sp + 0x5c ]
a00e101c:  fa 23 a0 60  st  %i5, [ %sp + 0x60 ]
a00e1020:  93 34 a0 10  srl  %l2, 0x10, %o1
a00e1024:  94 10 00 13  mov  %l3, %o2
a00e1028:  96 10 00 14  mov  %l4, %o3
a00e102c:  98 10 00 15  mov  %l5, %o4
a00e1030:  7f ff fc 41  call  0xa00e0134
a00e1034:  9a 10 00 16  mov  %l6, %o5
a00e1038:  a0 04 20 01  inc  %l0
a00e103c:  80 a4 00 11  cmp  %l0, %l1
a00e1040:  04 bf ff f6  ble  0xa00e1018
a00e1044:  90 10 00 10  mov  %l0, %o0
a00e1048:  10 bf ff a4  b  0xa00e0ed8
a00e104c:  b0 06 20 01  inc  %i0
a00e1050:  92 07 bf f8  add  %fp, -8, %o1
a00e1054:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1058:  98 10 20 01  mov  1, %o4
a00e105c:  ae 0a e0 ff  and  %o3, 0xff, %l7
a00e1060:  b0 06 20 01  inc  %i0
a00e1064:  aa 02 40 17  add  %o1, %l7, %l5
a00e1068:  e4 0a 80 18  ldub  [ %o2 + %i0 ], %l2
a00e106c:  e4 2d 7f f0  stb  %l2, [ %l5 + -16 ]
a00e1070:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1074:  1c bf ff fa  bpos  0xa00e105c
a00e1078:  96 02 e0 01  inc  %o3
a00e107c:  10 bf ff 97  b  0xa00e0ed8
a00e1080:  b0 06 20 01  inc  %i0
a00e1084:  10 80 00 00  b  0xa00e1084
a00e1088:  01 00 00 00  nop
a00e108c:  da 06 e2 54  ld  [ %i3 + 0x254 ], %o5
a00e1090:  92 10 00 0d  mov  %o5, %o1
a00e1094:  d4 0b 40 18  ldub  [ %o5 + %i0 ], %o2
a00e1098:  90 07 bf f8  add  %fp, -8, %o0
a00e109c:  98 10 20 07  mov  7, %o4
a00e10a0:  a6 0a e0 ff  and  %o3, 0xff, %l3
a00e10a4:  b0 06 20 01  inc  %i0
a00e10a8:  82 02 00 13  add  %o0, %l3, %g1
a00e10ac:  e0 0a 40 18  ldub  [ %o1 + %i0 ], %l0
a00e10b0:  e0 28 7f f0  stb  %l0, [ %g1 + -16 ]
a00e10b4:  98 83 3f ff  addcc  %o4, -1, %o4
a00e10b8:  1c bf ff fa  bpos  0xa00e10a0
a00e10bc:  96 02 e0 01  inc  %o3
a00e10c0:  80 a2 a0 3a  cmp  %o2, 0x3a
a00e10c4:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00e10c8:  ec 0f bf e9  ldub  [ %fp + -23 ], %l6
a00e10cc:  ee 0f bf ea  ldub  [ %fp + -22 ], %l7
a00e10d0:  fa 0f bf eb  ldub  [ %fp + -21 ], %i5
a00e10d4:  e4 0f bf ec  ldub  [ %fp + -20 ], %l2
a00e10d8:  e6 0f bf ed  ldub  [ %fp + -19 ], %l3
a00e10dc:  aa 10 20 00  clr  %l5
a00e10e0:  12 80 00 04  bne  0xa00e10f0
a00e10e4:  a8 10 20 00  clr  %l4
a00e10e8:  ea 0f bf ee  ldub  [ %fp + -18 ], %l5
a00e10ec:  e8 0f bf ef  ldub  [ %fp + -17 ], %l4
a00e10f0:  80 a0 60 ff  cmp  %g1, 0xff
a00e10f4:  02 80 00 03  be  0xa00e1100
a00e10f8:  9a 10 20 04  mov  4, %o5
a00e10fc:  9a 10 00 01  mov  %g1, %o5
a00e1100:  23 00 06 65  sethi  %hi(0x199400), %l1
a00e1104:  96 14 62 2c  or  %l1, 0x22c, %o3	! 0x19962c
a00e1108:  93 2b 60 03  sll  %o5, 3, %o1
a00e110c:  9e 02 40 0b  add  %o1, %o3, %o7
a00e1110:  e0 02 c0 09  ld  [ %o3 + %o1 ], %l0
a00e1114:  e2 03 e0 04  ld  [ %o7 + 4 ], %l1
a00e1118:  80 a4 00 11  cmp  %l0, %l1
a00e111c:  14 bf ff 6e  bg  0xa00e0ed4
a00e1120:  90 10 00 10  mov  %l0, %o0
a00e1124:  ea 23 a0 5c  st  %l5, [ %sp + 0x5c ]
a00e1128:  e8 23 a0 60  st  %l4, [ %sp + 0x60 ]
a00e112c:  92 10 00 16  mov  %l6, %o1
a00e1130:  94 10 00 17  mov  %l7, %o2
a00e1134:  96 10 00 1d  mov  %i5, %o3
a00e1138:  98 10 00 12  mov  %l2, %o4
a00e113c:  40 00 31 74  call  0xa00ed70c
a00e1140:  9a 10 00 13  mov  %l3, %o5
a00e1144:  10 bf ff f5  b  0xa00e1118
a00e1148:  a0 04 20 01  inc  %l0
a00e114c:  e6 06 e2 54  ld  [ %i3 + 0x254 ], %l3
a00e1150:  92 10 00 13  mov  %l3, %o1
a00e1154:  d4 0c c0 18  ldub  [ %l3 + %i0 ], %o2
a00e1158:  90 07 bf f8  add  %fp, -8, %o0
a00e115c:  98 10 20 05  mov  5, %o4
a00e1160:  9e 0a e0 ff  and  %o3, 0xff, %o7
a00e1164:  b0 06 20 01  inc  %i0
a00e1168:  aa 02 00 0f  add  %o0, %o7, %l5
a00e116c:  e4 0a 40 18  ldub  [ %o1 + %i0 ], %l2
a00e1170:  e4 2d 7f f0  stb  %l2, [ %l5 + -16 ]
a00e1174:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1178:  1c bf ff fa  bpos  0xa00e1160
a00e117c:  96 02 e0 01  inc  %o3
a00e1180:  80 a2 a0 39  cmp  %o2, 0x39
a00e1184:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00e1188:  e8 0f bf e9  ldub  [ %fp + -23 ], %l4
a00e118c:  ea 0f bf ea  ldub  [ %fp + -22 ], %l5
a00e1190:  ec 0f bf eb  ldub  [ %fp + -21 ], %l6
a00e1194:  a4 10 20 00  clr  %l2
a00e1198:  12 80 00 04  bne  0xa00e11a8
a00e119c:  a6 10 20 00  clr  %l3
a00e11a0:  e4 0f bf ec  ldub  [ %fp + -20 ], %l2
a00e11a4:  e6 0f bf ed  ldub  [ %fp + -19 ], %l3
a00e11a8:  80 a0 60 ff  cmp  %g1, 0xff
a00e11ac:  02 80 00 03  be  0xa00e11b8
a00e11b0:  9a 10 20 04  mov  4, %o5
a00e11b4:  9a 10 00 01  mov  %g1, %o5
a00e11b8:  23 00 06 65  sethi  %hi(0x199400), %l1
a00e11bc:  ae 14 62 2c  or  %l1, 0x22c, %l7	! 0x19962c
a00e11c0:  97 2b 60 03  sll  %o5, 3, %o3
a00e11c4:  92 02 c0 17  add  %o3, %l7, %o1
a00e11c8:  e0 05 c0 0b  ld  [ %l7 + %o3 ], %l0
a00e11cc:  e2 02 60 04  ld  [ %o1 + 4 ], %l1
a00e11d0:  80 a4 00 11  cmp  %l0, %l1
a00e11d4:  14 bf ff 40  bg  0xa00e0ed4
a00e11d8:  90 10 00 10  mov  %l0, %o0
a00e11dc:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a00e11e0:  e6 23 a0 60  st  %l3, [ %sp + 0x60 ]
a00e11e4:  92 10 00 14  mov  %l4, %o1
a00e11e8:  94 10 00 15  mov  %l5, %o2
a00e11ec:  96 10 00 16  mov  %l6, %o3
a00e11f0:  98 10 20 00  clr  %o4
a00e11f4:  40 00 18 18  call  0xa00e7254
a00e11f8:  9a 10 20 00  clr  %o5
a00e11fc:  10 bf ff f5  b  0xa00e11d0
a00e1200:  a0 04 20 01  inc  %l0
a00e1204:  92 07 bf f8  add  %fp, -8, %o1
a00e1208:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e120c:  98 10 20 02  mov  2, %o4
a00e1210:  a4 0a e0 ff  and  %o3, 0xff, %l2
a00e1214:  b0 06 20 01  inc  %i0
a00e1218:  a0 02 40 12  add  %o1, %l2, %l0
a00e121c:  da 0a 80 18  ldub  [ %o2 + %i0 ], %o5
a00e1220:  da 2c 3f f0  stb  %o5, [ %l0 + -16 ]
a00e1224:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1228:  1c bf ff fa  bpos  0xa00e1210
a00e122c:  96 02 e0 01  inc  %o3
a00e1230:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00e1234:  80 a0 60 ff  cmp  %g1, 0xff
a00e1238:  e4 0f bf e9  ldub  [ %fp + -23 ], %l2
a00e123c:  e6 0f bf ea  ldub  [ %fp + -22 ], %l3
a00e1240:  02 80 00 03  be  0xa00e124c
a00e1244:  9a 10 20 04  mov  4, %o5
a00e1248:  9a 10 00 01  mov  %g1, %o5
a00e124c:  17 00 06 65  sethi  %hi(0x199400), %o3
a00e1250:  9e 12 e2 2c  or  %o3, 0x22c, %o7	! 0x19962c
a00e1254:  ab 2b 60 03  sll  %o5, 3, %l5
a00e1258:  92 05 40 0f  add  %l5, %o7, %o1
a00e125c:  e0 03 c0 15  ld  [ %o7 + %l5 ], %l0
a00e1260:  e2 02 60 04  ld  [ %o1 + 4 ], %l1
a00e1264:  80 a4 00 11  cmp  %l0, %l1
a00e1268:  14 bf ff 1b  bg  0xa00e0ed4
a00e126c:  90 10 00 10  mov  %l0, %o0
a00e1270:  92 10 00 12  mov  %l2, %o1
a00e1274:  94 10 00 13  mov  %l3, %o2
a00e1278:  40 00 0a 59  call  0xa00e3bdc
a00e127c:  96 10 20 01  mov  1, %o3
a00e1280:  10 bf ff f9  b  0xa00e1264
a00e1284:  a0 04 20 01  inc  %l0
a00e1288:  92 07 bf f8  add  %fp, -8, %o1
a00e128c:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1290:  98 10 20 02  mov  2, %o4
a00e1294:  a6 0a e0 ff  and  %o3, 0xff, %l3
a00e1298:  b0 06 20 01  inc  %i0
a00e129c:  a2 02 40 13  add  %o1, %l3, %l1
a00e12a0:  e8 0a 80 18  ldub  [ %o2 + %i0 ], %l4
a00e12a4:  e8 2c 7f f0  stb  %l4, [ %l1 + -16 ]
a00e12a8:  98 83 3f ff  addcc  %o4, -1, %o4
a00e12ac:  1c bf ff fa  bpos  0xa00e1294
a00e12b0:  96 02 e0 01  inc  %o3
a00e12b4:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00e12b8:  80 a0 60 ff  cmp  %g1, 0xff
a00e12bc:  e4 0f bf e9  ldub  [ %fp + -23 ], %l2
a00e12c0:  e6 0f bf ea  ldub  [ %fp + -22 ], %l3
a00e12c4:  02 80 00 03  be  0xa00e12d0
a00e12c8:  9a 10 20 04  mov  4, %o5
a00e12cc:  9a 10 00 01  mov  %g1, %o5
a00e12d0:  03 00 06 65  sethi  %hi(0x199400), %g1
a00e12d4:  94 10 62 2c  or  %g1, 0x22c, %o2	! 0x19962c
a00e12d8:  91 2b 60 03  sll  %o5, 3, %o0
a00e12dc:  ba 02 00 0a  add  %o0, %o2, %i5
a00e12e0:  e0 02 80 08  ld  [ %o2 + %o0 ], %l0
a00e12e4:  e2 07 60 04  ld  [ %i5 + 4 ], %l1
a00e12e8:  80 a4 00 11  cmp  %l0, %l1
a00e12ec:  14 bf fe fa  bg  0xa00e0ed4
a00e12f0:  90 10 00 10  mov  %l0, %o0
a00e12f4:  92 10 00 12  mov  %l2, %o1
a00e12f8:  94 10 00 13  mov  %l3, %o2
a00e12fc:  40 00 0a 38  call  0xa00e3bdc
a00e1300:  96 10 20 00  clr  %o3
a00e1304:  10 bf ff f9  b  0xa00e12e8
a00e1308:  a0 04 20 01  inc  %l0
a00e130c:  92 07 bf f8  add  %fp, -8, %o1
a00e1310:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1314:  98 10 20 02  mov  2, %o4
a00e1318:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00e131c:  b0 06 20 01  inc  %i0
a00e1320:  ac 02 40 0d  add  %o1, %o5, %l6
a00e1324:  e8 0a 80 18  ldub  [ %o2 + %i0 ], %l4
a00e1328:  e8 2d bf f0  stb  %l4, [ %l6 + -16 ]
a00e132c:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1330:  1c bf ff fa  bpos  0xa00e1318
a00e1334:  96 02 e0 01  inc  %o3
a00e1338:  10 bf fe e8  b  0xa00e0ed8
a00e133c:  b0 06 20 01  inc  %i0
a00e1340:  92 07 bf f8  add  %fp, -8, %o1
a00e1344:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1348:  98 10 20 07  mov  7, %o4
a00e134c:  a8 0a e0 ff  and  %o3, 0xff, %l4
a00e1350:  b0 06 20 01  inc  %i0
a00e1354:  a6 02 40 14  add  %o1, %l4, %l3
a00e1358:  da 0a 80 18  ldub  [ %o2 + %i0 ], %o5
a00e135c:  da 2c ff f0  stb  %o5, [ %l3 + -16 ]
a00e1360:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1364:  1c bf ff fa  bpos  0xa00e134c
a00e1368:  96 02 e0 01  inc  %o3
a00e136c:  d8 0f bf e9  ldub  [ %fp + -23 ], %o4
a00e1370:  97 2b 20 08  sll  %o4, 8, %o3
a00e1374:  d8 0f bf e8  ldub  [ %fp + -24 ], %o4
a00e1378:  d4 0f bf ea  ldub  [ %fp + -22 ], %o2
a00e137c:  92 12 c0 0a  or  %o3, %o2, %o1
a00e1380:  80 a3 20 ff  cmp  %o4, 0xff
a00e1384:  e6 0f bf eb  ldub  [ %fp + -21 ], %l3
a00e1388:  e8 0f bf ec  ldub  [ %fp + -20 ], %l4
a00e138c:  ea 0f bf ed  ldub  [ %fp + -19 ], %l5
a00e1390:  ec 0f bf ee  ldub  [ %fp + -18 ], %l6
a00e1394:  ee 0f bf ef  ldub  [ %fp + -17 ], %l7
a00e1398:  02 80 00 03  be  0xa00e13a4
a00e139c:  9a 10 20 04  mov  4, %o5
a00e13a0:  9a 10 00 0c  mov  %o4, %o5
a00e13a4:  25 00 06 65  sethi  %hi(0x199400), %l2
a00e13a8:  9e 14 a2 2c  or  %l2, 0x22c, %o7	! 0x19962c
a00e13ac:  91 2b 60 03  sll  %o5, 3, %o0
a00e13b0:  ba 02 00 0f  add  %o0, %o7, %i5
a00e13b4:  e0 03 c0 08  ld  [ %o7 + %o0 ], %l0
a00e13b8:  e4 07 60 04  ld  [ %i5 + 4 ], %l2
a00e13bc:  80 a4 00 12  cmp  %l0, %l2
a00e13c0:  14 bf fe c5  bg  0xa00e0ed4
a00e13c4:  a3 2a 60 10  sll  %o1, 0x10, %l1
a00e13c8:  90 10 00 10  mov  %l0, %o0
a00e13cc:  ee 23 a0 5c  st  %l7, [ %sp + 0x5c ]
a00e13d0:  c0 23 a0 60  clr  [ %sp + 0x60 ]
a00e13d4:  93 34 60 10  srl  %l1, 0x10, %o1
a00e13d8:  94 10 00 13  mov  %l3, %o2
a00e13dc:  96 10 00 14  mov  %l4, %o3
a00e13e0:  98 10 00 15  mov  %l5, %o4
a00e13e4:  7f ff fb 54  call  0xa00e0134
a00e13e8:  9a 10 00 16  mov  %l6, %o5
a00e13ec:  a0 04 20 01  inc  %l0
a00e13f0:  80 a4 00 12  cmp  %l0, %l2
a00e13f4:  04 bf ff f6  ble  0xa00e13cc
a00e13f8:  90 10 00 10  mov  %l0, %o0
a00e13fc:  10 bf fe b7  b  0xa00e0ed8
a00e1400:  b0 06 20 01  inc  %i0
a00e1404:  92 07 bf f8  add  %fp, -8, %o1
a00e1408:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e140c:  98 10 20 06  mov  6, %o4
a00e1410:  a2 0a e0 ff  and  %o3, 0xff, %l1
a00e1414:  b0 06 20 01  inc  %i0
a00e1418:  a0 02 40 11  add  %o1, %l1, %l0
a00e141c:  e6 0a 80 18  ldub  [ %o2 + %i0 ], %l3
a00e1420:  e6 2c 3f f0  stb  %l3, [ %l0 + -16 ]
a00e1424:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1428:  1c bf ff fa  bpos  0xa00e1410
a00e142c:  96 02 e0 01  inc  %o3
a00e1430:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00e1434:  80 a0 60 ff  cmp  %g1, 0xff
a00e1438:  e6 0f bf e9  ldub  [ %fp + -23 ], %l3
a00e143c:  e8 0f bf ea  ldub  [ %fp + -22 ], %l4
a00e1440:  ea 0f bf eb  ldub  [ %fp + -21 ], %l5
a00e1444:  ec 0f bf ec  ldub  [ %fp + -20 ], %l6
a00e1448:  ee 0f bf ed  ldub  [ %fp + -19 ], %l7
a00e144c:  e4 0f bf ee  ldub  [ %fp + -18 ], %l2
a00e1450:  02 80 00 03  be  0xa00e145c
a00e1454:  9a 10 20 04  mov  4, %o5
a00e1458:  9a 10 00 01  mov  %g1, %o5
a00e145c:  11 00 06 65  sethi  %hi(0x199400), %o0
a00e1460:  ba 12 22 2c  or  %o0, 0x22c, %i5	! 0x19962c
a00e1464:  99 2b 60 03  sll  %o5, 3, %o4
a00e1468:  96 03 00 1d  add  %o4, %i5, %o3
a00e146c:  e0 07 40 0c  ld  [ %i5 + %o4 ], %l0
a00e1470:  e2 02 e0 04  ld  [ %o3 + 4 ], %l1
a00e1474:  80 a4 00 11  cmp  %l0, %l1
a00e1478:  14 bf fe 97  bg  0xa00e0ed4
a00e147c:  90 10 00 10  mov  %l0, %o0
a00e1480:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a00e1484:  92 10 00 13  mov  %l3, %o1
a00e1488:  94 10 00 14  mov  %l4, %o2
a00e148c:  96 10 00 15  mov  %l5, %o3
a00e1490:  98 10 00 16  mov  %l6, %o4
a00e1494:  40 00 35 34  call  0xa00ee964
a00e1498:  9a 10 00 17  mov  %l7, %o5
a00e149c:  10 bf ff f6  b  0xa00e1474
a00e14a0:  a0 04 20 01  inc  %l0
a00e14a4:  92 07 bf f8  add  %fp, -8, %o1
a00e14a8:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e14ac:  98 10 20 07  mov  7, %o4
a00e14b0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00e14b4:  b0 06 20 01  inc  %i0
a00e14b8:  ac 02 40 0d  add  %o1, %o5, %l6
a00e14bc:  e8 0a 80 18  ldub  [ %o2 + %i0 ], %l4
a00e14c0:  e8 2d bf f0  stb  %l4, [ %l6 + -16 ]
a00e14c4:  98 83 3f ff  addcc  %o4, -1, %o4
a00e14c8:  1c bf ff fa  bpos  0xa00e14b0
a00e14cc:  96 02 e0 01  inc  %o3
a00e14d0:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00e14d4:  80 a0 60 ff  cmp  %g1, 0xff
a00e14d8:  e8 0f bf e9  ldub  [ %fp + -23 ], %l4
a00e14dc:  ea 0f bf ea  ldub  [ %fp + -22 ], %l5
a00e14e0:  ec 0f bf eb  ldub  [ %fp + -21 ], %l6
a00e14e4:  ee 0f bf ec  ldub  [ %fp + -20 ], %l7
a00e14e8:  fa 0f bf ed  ldub  [ %fp + -19 ], %i5
a00e14ec:  e4 0f bf ee  ldub  [ %fp + -18 ], %l2
a00e14f0:  e6 0f bf ef  ldub  [ %fp + -17 ], %l3
a00e14f4:  02 80 00 03  be  0xa00e1500
a00e14f8:  9a 10 20 04  mov  4, %o5
a00e14fc:  9a 10 00 01  mov  %g1, %o5
a00e1500:  03 00 06 65  sethi  %hi(0x199400), %g1
a00e1504:  92 10 62 2c  or  %g1, 0x22c, %o1	! 0x19962c
a00e1508:  9f 2b 60 03  sll  %o5, 3, %o7
a00e150c:  94 03 c0 09  add  %o7, %o1, %o2
a00e1510:  e0 02 40 0f  ld  [ %o1 + %o7 ], %l0
a00e1514:  e2 02 a0 04  ld  [ %o2 + 4 ], %l1
a00e1518:  80 a4 00 11  cmp  %l0, %l1
a00e151c:  14 bf fe 6e  bg  0xa00e0ed4
a00e1520:  90 10 00 10  mov  %l0, %o0
a00e1524:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a00e1528:  e6 23 a0 60  st  %l3, [ %sp + 0x60 ]
a00e152c:  92 10 00 14  mov  %l4, %o1
a00e1530:  94 10 00 15  mov  %l5, %o2
a00e1534:  96 10 00 16  mov  %l6, %o3
a00e1538:  98 10 00 17  mov  %l7, %o4
a00e153c:  40 00 33 2b  call  0xa00ee1e8
a00e1540:  9a 10 00 1d  mov  %i5, %o5
a00e1544:  10 bf ff f5  b  0xa00e1518
a00e1548:  a0 04 20 01  inc  %l0
a00e154c:  92 07 bf f8  add  %fp, -8, %o1
a00e1550:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1554:  98 10 20 05  mov  5, %o4
a00e1558:  a4 0a e0 ff  and  %o3, 0xff, %l2
a00e155c:  b0 06 20 01  inc  %i0
a00e1560:  a2 02 40 12  add  %o1, %l2, %l1
a00e1564:  ea 0a 80 18  ldub  [ %o2 + %i0 ], %l5
a00e1568:  ea 2c 7f f0  stb  %l5, [ %l1 + -16 ]
a00e156c:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1570:  1c bf ff fa  bpos  0xa00e1558
a00e1574:  96 02 e0 01  inc  %o3
a00e1578:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00e157c:  80 a0 60 ff  cmp  %g1, 0xff
a00e1580:  e6 0f bf e9  ldub  [ %fp + -23 ], %l3
a00e1584:  e8 0f bf ea  ldub  [ %fp + -22 ], %l4
a00e1588:  ea 0f bf eb  ldub  [ %fp + -21 ], %l5
a00e158c:  ec 0f bf ec  ldub  [ %fp + -20 ], %l6
a00e1590:  e4 0f bf ed  ldub  [ %fp + -19 ], %l2
a00e1594:  02 80 00 03  be  0xa00e15a0
a00e1598:  9a 10 20 04  mov  4, %o5
a00e159c:  9a 10 00 01  mov  %g1, %o5
a00e15a0:  11 00 06 65  sethi  %hi(0x199400), %o0
a00e15a4:  ba 12 22 2c  or  %o0, 0x22c, %i5	! 0x19962c
a00e15a8:  99 2b 60 03  sll  %o5, 3, %o4
a00e15ac:  ae 03 00 1d  add  %o4, %i5, %l7
a00e15b0:  e0 07 40 0c  ld  [ %i5 + %o4 ], %l0
a00e15b4:  e2 05 e0 04  ld  [ %l7 + 4 ], %l1
a00e15b8:  80 a4 00 11  cmp  %l0, %l1
a00e15bc:  14 bf fe 46  bg  0xa00e0ed4
a00e15c0:  90 10 00 10  mov  %l0, %o0
a00e15c4:  92 10 00 13  mov  %l3, %o1
a00e15c8:  94 10 00 14  mov  %l4, %o2
a00e15cc:  96 10 00 15  mov  %l5, %o3
a00e15d0:  98 10 00 12  mov  %l2, %o4
a00e15d4:  40 00 21 ab  call  0xa00e9c80
a00e15d8:  9a 10 00 16  mov  %l6, %o5
a00e15dc:  10 bf ff f7  b  0xa00e15b8
a00e15e0:  a0 04 20 01  inc  %l0
a00e15e4:  92 07 bf f8  add  %fp, -8, %o1
a00e15e8:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e15ec:  98 10 20 05  mov  5, %o4
a00e15f0:  ae 0a e0 ff  and  %o3, 0xff, %l7
a00e15f4:  b0 06 20 01  inc  %i0
a00e15f8:  aa 02 40 17  add  %o1, %l7, %l5
a00e15fc:  e4 0a 80 18  ldub  [ %o2 + %i0 ], %l2
a00e1600:  e4 2d 7f f0  stb  %l2, [ %l5 + -16 ]
a00e1604:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1608:  1c bf ff fa  bpos  0xa00e15f0
a00e160c:  96 02 e0 01  inc  %o3
a00e1610:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00e1614:  80 a0 60 ff  cmp  %g1, 0xff
a00e1618:  e6 0f bf e9  ldub  [ %fp + -23 ], %l3
a00e161c:  e8 0f bf ea  ldub  [ %fp + -22 ], %l4
a00e1620:  ea 0f bf eb  ldub  [ %fp + -21 ], %l5
a00e1624:  ee 0f bf ec  ldub  [ %fp + -20 ], %l7
a00e1628:  ec 0f bf ed  ldub  [ %fp + -19 ], %l6
a00e162c:  02 80 00 03  be  0xa00e1638
a00e1630:  9a 10 20 04  mov  4, %o5
a00e1634:  9a 10 00 01  mov  %g1, %o5
a00e1638:  15 00 06 65  sethi  %hi(0x199400), %o2
a00e163c:  90 12 a2 2c  or  %o2, 0x22c, %o0	! 0x19962c
a00e1640:  bb 2b 60 03  sll  %o5, 3, %i5
a00e1644:  98 07 40 08  add  %i5, %o0, %o4
a00e1648:  e0 02 00 1d  ld  [ %o0 + %i5 ], %l0
a00e164c:  e2 03 20 04  ld  [ %o4 + 4 ], %l1
a00e1650:  80 a4 00 11  cmp  %l0, %l1
a00e1654:  14 bf fe 20  bg  0xa00e0ed4
a00e1658:  a4 07 bf e0  add  %fp, -32, %l2
a00e165c:  90 10 00 10  mov  %l0, %o0
a00e1660:  e4 23 a0 40  st  %l2, [ %sp + 0x40 ]
a00e1664:  92 10 00 13  mov  %l3, %o1
a00e1668:  94 10 00 14  mov  %l4, %o2
a00e166c:  96 10 00 15  mov  %l5, %o3
a00e1670:  98 10 00 16  mov  %l6, %o4
a00e1674:  9a 10 00 17  mov  %l7, %o5
a00e1678:  40 00 2c 10  call  0xa00ec6b8
a00e167c:  01 00 00 00  nop
a00e1680:  00 00 00 08  unimp  0x8
a00e1684:  a0 04 20 01  inc  %l0
a00e1688:  80 a4 00 11  cmp  %l0, %l1
a00e168c:  04 bf ff f5  ble  0xa00e1660
a00e1690:  90 10 00 10  mov  %l0, %o0
a00e1694:  10 bf fe 11  b  0xa00e0ed8
a00e1698:  b0 06 20 01  inc  %i0
a00e169c:  92 07 bf f8  add  %fp, -8, %o1
a00e16a0:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e16a4:  98 10 20 04  mov  4, %o4
a00e16a8:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00e16ac:  b0 06 20 01  inc  %i0
a00e16b0:  ac 02 40 0d  add  %o1, %o5, %l6
a00e16b4:  e8 0a 80 18  ldub  [ %o2 + %i0 ], %l4
a00e16b8:  e8 2d bf f0  stb  %l4, [ %l6 + -16 ]
a00e16bc:  98 83 3f ff  addcc  %o4, -1, %o4
a00e16c0:  1c bf ff fa  bpos  0xa00e16a8
a00e16c4:  96 02 e0 01  inc  %o3
a00e16c8:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00e16cc:  80 a0 60 ff  cmp  %g1, 0xff
a00e16d0:  e6 0f bf e9  ldub  [ %fp + -23 ], %l3
a00e16d4:  e8 0f bf ea  ldub  [ %fp + -22 ], %l4
a00e16d8:  ea 0f bf eb  ldub  [ %fp + -21 ], %l5
a00e16dc:  ec 0f bf ec  ldub  [ %fp + -20 ], %l6
a00e16e0:  02 80 00 03  be  0xa00e16ec
a00e16e4:  9a 10 20 04  mov  4, %o5
a00e16e8:  9a 10 00 01  mov  %g1, %o5
a00e16ec:  21 00 06 65  sethi  %hi(0x199400), %l0
a00e16f0:  82 14 22 2c  or  %l0, 0x22c, %g1	! 0x19962c
a00e16f4:  93 2b 60 03  sll  %o5, 3, %o1
a00e16f8:  9e 02 40 01  add  %o1, %g1, %o7
a00e16fc:  e0 00 40 09  ld  [ %g1 + %o1 ], %l0
a00e1700:  e2 03 e0 04  ld  [ %o7 + 4 ], %l1
a00e1704:  80 a4 00 11  cmp  %l0, %l1
a00e1708:  14 bf fd f3  bg  0xa00e0ed4
a00e170c:  a4 07 bf d8  add  %fp, -40, %l2
a00e1710:  90 10 00 10  mov  %l0, %o0
a00e1714:  e4 23 a0 40  st  %l2, [ %sp + 0x40 ]
a00e1718:  92 10 00 13  mov  %l3, %o1
a00e171c:  94 10 00 14  mov  %l4, %o2
a00e1720:  96 10 00 15  mov  %l5, %o3
a00e1724:  98 10 00 16  mov  %l6, %o4
a00e1728:  40 00 1d d1  call  0xa00e8e6c
a00e172c:  01 00 00 00  nop
a00e1730:  00 00 00 08  unimp  0x8
a00e1734:  a0 04 20 01  inc  %l0
a00e1738:  80 a4 00 11  cmp  %l0, %l1
a00e173c:  04 bf ff f6  ble  0xa00e1714
a00e1740:  90 10 00 10  mov  %l0, %o0
a00e1744:  10 bf fd e5  b  0xa00e0ed8
a00e1748:  b0 06 20 01  inc  %i0
a00e174c:  92 07 bf f8  add  %fp, -8, %o1
a00e1750:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1754:  98 10 20 04  mov  4, %o4
a00e1758:  ac 0a e0 ff  and  %o3, 0xff, %l6
a00e175c:  b0 06 20 01  inc  %i0
a00e1760:  a4 02 40 16  add  %o1, %l6, %l2
a00e1764:  de 0a 80 18  ldub  [ %o2 + %i0 ], %o7
a00e1768:  de 2c bf f0  stb  %o7, [ %l2 + -16 ]
a00e176c:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1770:  1c bf ff fa  bpos  0xa00e1758
a00e1774:  96 02 e0 01  inc  %o3
a00e1778:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00e177c:  80 a0 60 ff  cmp  %g1, 0xff
a00e1780:  e6 0f bf e9  ldub  [ %fp + -23 ], %l3
a00e1784:  e8 0f bf ea  ldub  [ %fp + -22 ], %l4
a00e1788:  ea 0f bf eb  ldub  [ %fp + -21 ], %l5
a00e178c:  e4 0f bf ec  ldub  [ %fp + -20 ], %l2
a00e1790:  02 80 00 03  be  0xa00e179c
a00e1794:  9a 10 20 04  mov  4, %o5
a00e1798:  9a 10 00 01  mov  %g1, %o5
a00e179c:  19 00 06 65  sethi  %hi(0x199400), %o4
a00e17a0:  a2 13 22 2c  or  %o4, 0x22c, %l1	! 0x19962c
a00e17a4:  af 2b 60 03  sll  %o5, 3, %l7
a00e17a8:  96 05 c0 11  add  %l7, %l1, %o3
a00e17ac:  e0 04 40 17  ld  [ %l1 + %l7 ], %l0
a00e17b0:  e2 02 e0 04  ld  [ %o3 + 4 ], %l1
a00e17b4:  80 a4 00 11  cmp  %l0, %l1
a00e17b8:  14 bf fd c7  bg  0xa00e0ed4
a00e17bc:  90 10 00 10  mov  %l0, %o0
a00e17c0:  92 10 00 13  mov  %l3, %o1
a00e17c4:  94 10 00 14  mov  %l4, %o2
a00e17c8:  96 10 00 15  mov  %l5, %o3
a00e17cc:  98 10 20 04  mov  4, %o4
a00e17d0:  40 00 24 2a  call  0xa00ea878
a00e17d4:  9a 10 00 12  mov  %l2, %o5
a00e17d8:  10 bf ff f7  b  0xa00e17b4
a00e17dc:  a0 04 20 01  inc  %l0
a00e17e0:  92 07 bf f8  add  %fp, -8, %o1
a00e17e4:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e17e8:  98 10 20 02  mov  2, %o4
a00e17ec:  82 0a e0 ff  and  %o3, 0xff, %g1
a00e17f0:  b0 06 20 01  inc  %i0
a00e17f4:  a6 02 40 01  add  %o1, %g1, %l3
a00e17f8:  e0 0a 80 18  ldub  [ %o2 + %i0 ], %l0
a00e17fc:  e0 2c ff f0  stb  %l0, [ %l3 + -16 ]
a00e1800:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1804:  1c bf ff fa  bpos  0xa00e17ec
a00e1808:  96 02 e0 01  inc  %o3
a00e180c:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00e1810:  80 a0 60 ff  cmp  %g1, 0xff
a00e1814:  e6 0f bf e9  ldub  [ %fp + -23 ], %l3
a00e1818:  e4 0f bf ea  ldub  [ %fp + -22 ], %l2
a00e181c:  02 80 00 03  be  0xa00e1828
a00e1820:  9a 10 20 04  mov  4, %o5
a00e1824:  9a 10 00 01  mov  %g1, %o5
a00e1828:  2b 00 06 65  sethi  %hi(0x199400), %l5
a00e182c:  92 15 62 2c  or  %l5, 0x22c, %o1	! 0x19962c
a00e1830:  9b 2b 60 03  sll  %o5, 3, %o5
a00e1834:  94 03 40 09  add  %o5, %o1, %o2
a00e1838:  e0 02 40 0d  ld  [ %o1 + %o5 ], %l0
a00e183c:  e2 02 a0 04  ld  [ %o2 + 4 ], %l1
a00e1840:  80 a4 00 11  cmp  %l0, %l1
a00e1844:  14 bf fd a4  bg  0xa00e0ed4
a00e1848:  90 10 00 10  mov  %l0, %o0
a00e184c:  92 10 00 13  mov  %l3, %o1
a00e1850:  40 00 0b ea  call  0xa00e47f8
a00e1854:  94 10 00 12  mov  %l2, %o2
a00e1858:  10 bf ff fa  b  0xa00e1840
a00e185c:  a0 04 20 01  inc  %l0
a00e1860:  92 07 bf f8  add  %fp, -8, %o1
a00e1864:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1868:  98 10 20 02  mov  2, %o4
a00e186c:  a2 0a e0 ff  and  %o3, 0xff, %l1
a00e1870:  b0 06 20 01  inc  %i0
a00e1874:  ac 02 40 11  add  %o1, %l1, %l6
a00e1878:  ee 0a 80 18  ldub  [ %o2 + %i0 ], %l7
a00e187c:  ee 2d bf f0  stb  %l7, [ %l6 + -16 ]
a00e1880:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1884:  1c bf ff fa  bpos  0xa00e186c
a00e1888:  96 02 e0 01  inc  %o3
a00e188c:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00e1890:  80 a0 60 ff  cmp  %g1, 0xff
a00e1894:  e4 0f bf e9  ldub  [ %fp + -23 ], %l2
a00e1898:  e6 0f bf ea  ldub  [ %fp + -22 ], %l3
a00e189c:  02 80 00 03  be  0xa00e18a8
a00e18a0:  9a 10 20 04  mov  4, %o5
a00e18a4:  9a 10 00 01  mov  %g1, %o5
a00e18a8:  11 00 06 65  sethi  %hi(0x199400), %o0
a00e18ac:  ba 12 22 2c  or  %o0, 0x22c, %i5	! 0x19962c
a00e18b0:  a9 2b 60 03  sll  %o5, 3, %l4
a00e18b4:  98 05 00 1d  add  %l4, %i5, %o4
a00e18b8:  e0 07 40 14  ld  [ %i5 + %l4 ], %l0
a00e18bc:  e2 03 20 04  ld  [ %o4 + 4 ], %l1
a00e18c0:  80 a4 00 11  cmp  %l0, %l1
a00e18c4:  14 bf fd 84  bg  0xa00e0ed4
a00e18c8:  90 10 00 10  mov  %l0, %o0
a00e18cc:  92 10 00 12  mov  %l2, %o1
a00e18d0:  94 10 00 13  mov  %l3, %o2
a00e18d4:  40 00 08 c2  call  0xa00e3bdc
a00e18d8:  96 10 20 02  mov  2, %o3
a00e18dc:  10 bf ff f9  b  0xa00e18c0
a00e18e0:  a0 04 20 01  inc  %l0
a00e18e4:  b0 06 20 01  inc  %i0
a00e18e8:  d8 06 e2 54  ld  [ %i3 + 0x254 ], %o4
a00e18ec:  ec 0b 00 18  ldub  [ %o4 + %i0 ], %l6
a00e18f0:  ec 2f bf e8  stb  %l6, [ %fp + -24 ]
a00e18f4:  80 a5 a0 ff  cmp  %l6, 0xff
a00e18f8:  02 80 00 03  be  0xa00e1904
a00e18fc:  9a 10 20 04  mov  4, %o5
a00e1900:  9a 10 00 16  mov  %l6, %o5
a00e1904:  15 00 06 65  sethi  %hi(0x199400), %o2
a00e1908:  90 12 a2 2c  or  %o2, 0x22c, %o0	! 0x19962c
a00e190c:  bb 2b 60 03  sll  %o5, 3, %i5
a00e1910:  a8 07 40 08  add  %i5, %o0, %l4
a00e1914:  e0 02 00 1d  ld  [ %o0 + %i5 ], %l0
a00e1918:  e2 05 20 04  ld  [ %l4 + 4 ], %l1
a00e191c:  80 a4 00 11  cmp  %l0, %l1
a00e1920:  14 bf fd 6d  bg  0xa00e0ed4
a00e1924:  90 10 00 10  mov  %l0, %o0
a00e1928:  40 00 34 ea  call  0xa00eecd0
a00e192c:  92 10 20 01  mov  1, %o1
a00e1930:  10 bf ff fb  b  0xa00e191c
a00e1934:  a0 04 20 01  inc  %l0
a00e1938:  92 07 bf f8  add  %fp, -8, %o1
a00e193c:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1940:  98 10 20 0b  mov  0xb, %o4
a00e1944:  a0 0a e0 ff  and  %o3, 0xff, %l0
a00e1948:  b0 06 20 01  inc  %i0
a00e194c:  a8 02 40 10  add  %o1, %l0, %l4
a00e1950:  da 0a 80 18  ldub  [ %o2 + %i0 ], %o5
a00e1954:  da 2d 3f f0  stb  %o5, [ %l4 + -16 ]
a00e1958:  98 83 3f ff  addcc  %o4, -1, %o4
a00e195c:  1c bf ff fa  bpos  0xa00e1944
a00e1960:  96 02 e0 01  inc  %o3
a00e1964:  ec 0f bf e8  ldub  [ %fp + -24 ], %l6
a00e1968:  ea 0f bf e9  ldub  [ %fp + -23 ], %l5
a00e196c:  d8 0f bf ec  ldub  [ %fp + -20 ], %o4
a00e1970:  d6 0f bf ed  ldub  [ %fp + -19 ], %o3
a00e1974:  e4 0f bf f0  ldub  [ %fp + -16 ], %l2
a00e1978:  de 0f bf f1  ldub  [ %fp + -15 ], %o7
a00e197c:  91 2d a0 18  sll  %l6, 0x18, %o0
a00e1980:  93 2b 20 18  sll  %o4, 0x18, %o1
a00e1984:  bb 2a e0 10  sll  %o3, 0x10, %i5
a00e1988:  a7 2b e0 10  sll  %o7, 0x10, %l3
a00e198c:  a1 2d 60 10  sll  %l5, 0x10, %l0
a00e1990:  95 2c a0 18  sll  %l2, 0x18, %o2
a00e1994:  c2 0f bf ea  ldub  [ %fp + -22 ], %g1
a00e1998:  da 0f bf ee  ldub  [ %fp + -18 ], %o5
a00e199c:  e8 0f bf f2  ldub  [ %fp + -14 ], %l4
a00e19a0:  aa 12 40 1d  or  %o1, %i5, %l5
a00e19a4:  a4 12 80 13  or  %o2, %l3, %l2
a00e19a8:  ae 12 00 10  or  %o0, %l0, %l7
a00e19ac:  a3 28 60 08  sll  %g1, 8, %l1
a00e19b0:  ad 2b 60 08  sll  %o5, 8, %l6
a00e19b4:  99 2d 20 08  sll  %l4, 8, %o4
a00e19b8:  90 15 c0 11  or  %l7, %l1, %o0
a00e19bc:  ba 15 40 16  or  %l5, %l6, %i5
a00e19c0:  94 14 80 0c  or  %l2, %o4, %o2
a00e19c4:  de 0f bf eb  ldub  [ %fp + -21 ], %o7
a00e19c8:  d6 0f bf ef  ldub  [ %fp + -17 ], %o3
a00e19cc:  e6 0f bf f3  ldub  [ %fp + -13 ], %l3
a00e19d0:  90 12 00 0f  or  %o0, %o7, %o0
a00e19d4:  92 17 40 0b  or  %i5, %o3, %o1
a00e19d8:  10 80 01 39  b  0xa00e1ebc
a00e19dc:  94 12 80 13  or  %o2, %l3, %o2
a00e19e0:  b0 06 20 01  inc  %i0
a00e19e4:  c2 06 e2 54  ld  [ %i3 + 0x254 ], %g1
a00e19e8:  e2 08 40 18  ldub  [ %g1 + %i0 ], %l1
a00e19ec:  e2 2f bf e8  stb  %l1, [ %fp + -24 ]
a00e19f0:  7f ff f9 a8  call  0xa00e0090
a00e19f4:  90 0c 60 ff  and  %l1, 0xff, %o0
a00e19f8:  10 bf fd 38  b  0xa00e0ed8
a00e19fc:  b0 06 20 01  inc  %i0
a00e1a00:  92 07 bf f8  add  %fp, -8, %o1
a00e1a04:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1a08:  98 10 20 04  mov  4, %o4
a00e1a0c:  90 0a e0 ff  and  %o3, 0xff, %o0
a00e1a10:  b0 06 20 01  inc  %i0
a00e1a14:  a6 02 40 08  add  %o1, %o0, %l3
a00e1a18:  fa 0a 80 18  ldub  [ %o2 + %i0 ], %i5
a00e1a1c:  fa 2c ff f0  stb  %i5, [ %l3 + -16 ]
a00e1a20:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1a24:  1c bf ff fa  bpos  0xa00e1a0c
a00e1a28:  96 02 e0 01  inc  %o3
a00e1a2c:  e4 0f bf e9  ldub  [ %fp + -23 ], %l2
a00e1a30:  98 0c a0 0f  and  %l2, 0xf, %o4
a00e1a34:  9f 2b 20 08  sll  %o4, 8, %o7
a00e1a38:  d8 0f bf e8  ldub  [ %fp + -24 ], %o4
a00e1a3c:  d6 0f bf ea  ldub  [ %fp + -22 ], %o3
a00e1a40:  a4 13 c0 0b  or  %o7, %o3, %l2
a00e1a44:  80 a3 20 ff  cmp  %o4, 0xff
a00e1a48:  e6 0f bf eb  ldub  [ %fp + -21 ], %l3
a00e1a4c:  e8 0f bf ec  ldub  [ %fp + -20 ], %l4
a00e1a50:  02 80 00 03  be  0xa00e1a5c
a00e1a54:  9a 10 20 04  mov  4, %o5
a00e1a58:  9a 10 00 0c  mov  %o4, %o5
a00e1a5c:  2f 00 06 65  sethi  %hi(0x199400), %l7
a00e1a60:  92 15 e2 2c  or  %l7, 0x22c, %o1	! 0x19962c
a00e1a64:  ad 2b 60 03  sll  %o5, 3, %l6
a00e1a68:  aa 05 80 09  add  %l6, %o1, %l5
a00e1a6c:  e0 02 40 16  ld  [ %o1 + %l6 ], %l0
a00e1a70:  e2 05 60 04  ld  [ %l5 + 4 ], %l1
a00e1a74:  80 a4 00 11  cmp  %l0, %l1
a00e1a78:  14 bf fd 17  bg  0xa00e0ed4
a00e1a7c:  90 10 00 10  mov  %l0, %o0
a00e1a80:  92 10 00 12  mov  %l2, %o1
a00e1a84:  94 10 00 13  mov  %l3, %o2
a00e1a88:  7f ff fb 80  call  0xa00e0888
a00e1a8c:  96 10 00 14  mov  %l4, %o3
a00e1a90:  10 bf ff f9  b  0xa00e1a74
a00e1a94:  a0 04 20 01  inc  %l0
a00e1a98:  92 07 bf f8  add  %fp, -8, %o1
a00e1a9c:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1aa0:  98 10 20 03  mov  3, %o4
a00e1aa4:  ac 0a e0 ff  and  %o3, 0xff, %l6
a00e1aa8:  b0 06 20 01  inc  %i0
a00e1aac:  a4 02 40 16  add  %o1, %l6, %l2
a00e1ab0:  ea 0a 80 18  ldub  [ %o2 + %i0 ], %l5
a00e1ab4:  ea 2c bf f0  stb  %l5, [ %l2 + -16 ]
a00e1ab8:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1abc:  1c bf ff fa  bpos  0xa00e1aa4
a00e1ac0:  96 02 e0 01  inc  %o3
a00e1ac4:  c2 0f bf e9  ldub  [ %fp + -23 ], %g1
a00e1ac8:  a2 08 60 0f  and  %g1, 0xf, %l1
a00e1acc:  af 2c 60 08  sll  %l1, 8, %l7
a00e1ad0:  d8 0f bf e8  ldub  [ %fp + -24 ], %o4
a00e1ad4:  d2 0f bf ea  ldub  [ %fp + -22 ], %o1
a00e1ad8:  a6 15 c0 09  or  %l7, %o1, %l3
a00e1adc:  80 a3 20 ff  cmp  %o4, 0xff
a00e1ae0:  e4 0f bf eb  ldub  [ %fp + -21 ], %l2
a00e1ae4:  02 80 00 03  be  0xa00e1af0
a00e1ae8:  9a 10 20 04  mov  4, %o5
a00e1aec:  9a 10 00 0c  mov  %o4, %o5
a00e1af0:  21 00 06 65  sethi  %hi(0x199400), %l0
a00e1af4:  94 14 22 2c  or  %l0, 0x22c, %o2	! 0x19962c
a00e1af8:  9b 2b 60 03  sll  %o5, 3, %o5
a00e1afc:  a8 03 40 0a  add  %o5, %o2, %l4
a00e1b00:  e0 02 80 0d  ld  [ %o2 + %o5 ], %l0
a00e1b04:  e2 05 20 04  ld  [ %l4 + 4 ], %l1
a00e1b08:  80 a4 00 11  cmp  %l0, %l1
a00e1b0c:  14 bf fc f2  bg  0xa00e0ed4
a00e1b10:  90 10 00 10  mov  %l0, %o0
a00e1b14:  92 10 00 13  mov  %l3, %o1
a00e1b18:  7f ff fa 26  call  0xa00e03b0
a00e1b1c:  94 10 00 12  mov  %l2, %o2
a00e1b20:  10 bf ff fa  b  0xa00e1b08
a00e1b24:  a0 04 20 01  inc  %l0
a00e1b28:  92 07 bf f8  add  %fp, -8, %o1
a00e1b2c:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1b30:  98 10 20 02  mov  2, %o4
a00e1b34:  9e 0a e0 ff  and  %o3, 0xff, %o7
a00e1b38:  b0 06 20 01  inc  %i0
a00e1b3c:  a4 02 40 0f  add  %o1, %o7, %l2
a00e1b40:  ea 0a 80 18  ldub  [ %o2 + %i0 ], %l5
a00e1b44:  ea 2c bf f0  stb  %l5, [ %l2 + -16 ]
a00e1b48:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1b4c:  1c bf ff fa  bpos  0xa00e1b34
a00e1b50:  96 02 e0 01  inc  %o3
a00e1b54:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00e1b58:  80 a0 60 ff  cmp  %g1, 0xff
a00e1b5c:  e6 0f bf e9  ldub  [ %fp + -23 ], %l3
a00e1b60:  e4 0f bf ea  ldub  [ %fp + -22 ], %l2
a00e1b64:  02 80 00 03  be  0xa00e1b70
a00e1b68:  9a 10 20 04  mov  4, %o5
a00e1b6c:  9a 10 00 01  mov  %g1, %o5
a00e1b70:  2f 00 06 65  sethi  %hi(0x199400), %l7
a00e1b74:  ac 15 e2 2c  or  %l7, 0x22c, %l6	! 0x19962c
a00e1b78:  99 2b 60 03  sll  %o5, 3, %o4
a00e1b7c:  96 03 00 16  add  %o4, %l6, %o3
a00e1b80:  e0 05 80 0c  ld  [ %l6 + %o4 ], %l0
a00e1b84:  e2 02 e0 04  ld  [ %o3 + 4 ], %l1
a00e1b88:  80 a4 00 11  cmp  %l0, %l1
a00e1b8c:  14 bf fc d2  bg  0xa00e0ed4
a00e1b90:  90 10 00 10  mov  %l0, %o0
a00e1b94:  92 10 00 13  mov  %l3, %o1
a00e1b98:  40 00 01 ea  call  0xa00e2340
a00e1b9c:  94 10 00 12  mov  %l2, %o2
a00e1ba0:  10 bf ff fa  b  0xa00e1b88
a00e1ba4:  a0 04 20 01  inc  %l0
a00e1ba8:  92 07 bf f8  add  %fp, -8, %o1
a00e1bac:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1bb0:  98 10 20 04  mov  4, %o4
a00e1bb4:  a6 0a e0 ff  and  %o3, 0xff, %l3
a00e1bb8:  b0 06 20 01  inc  %i0
a00e1bbc:  82 02 40 13  add  %o1, %l3, %g1
a00e1bc0:  e0 0a 80 18  ldub  [ %o2 + %i0 ], %l0
a00e1bc4:  e0 28 7f f0  stb  %l0, [ %g1 + -16 ]
a00e1bc8:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1bcc:  1c bf ff fa  bpos  0xa00e1bb4
a00e1bd0:  96 02 e0 01  inc  %o3
a00e1bd4:  d6 0f bf e9  ldub  [ %fp + -23 ], %o3
a00e1bd8:  94 0a e0 0f  and  %o3, 0xf, %o2
a00e1bdc:  a9 2a a0 08  sll  %o2, 8, %l4
a00e1be0:  da 0f bf ea  ldub  [ %fp + -22 ], %o5
a00e1be4:  a6 15 00 0d  or  %l4, %o5, %l3
a00e1be8:  d8 0f bf e8  ldub  [ %fp + -24 ], %o4
a00e1bec:  80 a3 20 ff  cmp  %o4, 0xff
a00e1bf0:  e4 0f bf eb  ldub  [ %fp + -21 ], %l2
a00e1bf4:  e8 0f bf ec  ldub  [ %fp + -20 ], %l4
a00e1bf8:  02 80 00 03  be  0xa00e1c04
a00e1bfc:  9a 10 20 04  mov  4, %o5
a00e1c00:  9a 10 00 0c  mov  %o4, %o5
a00e1c04:  1f 00 06 65  sethi  %hi(0x199400), %o7
a00e1c08:  90 13 e2 2c  or  %o7, 0x22c, %o0	! 0x19962c
a00e1c0c:  bb 2b 60 03  sll  %o5, 3, %i5
a00e1c10:  98 07 40 08  add  %i5, %o0, %o4
a00e1c14:  e0 02 00 1d  ld  [ %o0 + %i5 ], %l0
a00e1c18:  e2 03 20 04  ld  [ %o4 + 4 ], %l1
a00e1c1c:  80 a4 00 11  cmp  %l0, %l1
a00e1c20:  14 bf fc ad  bg  0xa00e0ed4
a00e1c24:  90 10 00 10  mov  %l0, %o0
a00e1c28:  92 10 00 13  mov  %l3, %o1
a00e1c2c:  94 10 00 12  mov  %l2, %o2
a00e1c30:  7f ff fa 6a  call  0xa00e05d8
a00e1c34:  96 10 00 14  mov  %l4, %o3
a00e1c38:  10 bf ff f9  b  0xa00e1c1c
a00e1c3c:  a0 04 20 01  inc  %l0
a00e1c40:  b0 06 20 01  inc  %i0
a00e1c44:  e2 06 e2 54  ld  [ %i3 + 0x254 ], %l1
a00e1c48:  ee 0c 40 18  ldub  [ %l1 + %i0 ], %l7
a00e1c4c:  2d 00 06 65  sethi  %hi(0x199400), %l6
a00e1c50:  ee 2f bf e8  stb  %l7, [ %fp + -24 ]
a00e1c54:  7f ff f5 ff  call  0xa00df450
a00e1c58:  90 15 a2 80  or  %l6, 0x280, %o0
a00e1c5c:  10 bf fc 9f  b  0xa00e0ed8
a00e1c60:  b0 06 20 01  inc  %i0
a00e1c64:  92 07 bf f8  add  %fp, -8, %o1
a00e1c68:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1c6c:  98 10 20 07  mov  7, %o4
a00e1c70:  a4 0a e0 ff  and  %o3, 0xff, %l2
a00e1c74:  b0 06 20 01  inc  %i0
a00e1c78:  a2 02 40 12  add  %o1, %l2, %l1
a00e1c7c:  da 0a 80 18  ldub  [ %o2 + %i0 ], %o5
a00e1c80:  da 2c 7f f0  stb  %o5, [ %l1 + -16 ]
a00e1c84:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1c88:  1c bf ff fa  bpos  0xa00e1c70
a00e1c8c:  96 02 e0 01  inc  %o3
a00e1c90:  d6 0f bf e8  ldub  [ %fp + -24 ], %o3
a00e1c94:  e8 0f bf e9  ldub  [ %fp + -23 ], %l4
a00e1c98:  e6 0f bf ec  ldub  [ %fp + -20 ], %l3
a00e1c9c:  d4 0f bf ed  ldub  [ %fp + -19 ], %o2
a00e1ca0:  99 2a e0 18  sll  %o3, 0x18, %o4
a00e1ca4:  e2 0f bf ea  ldub  [ %fp + -22 ], %l1
a00e1ca8:  e0 0f bf ee  ldub  [ %fp + -18 ], %l0
a00e1cac:  93 2d 20 10  sll  %l4, 0x10, %o1
a00e1cb0:  9b 2c e0 18  sll  %l3, 0x18, %o5
a00e1cb4:  a5 2a a0 10  sll  %o2, 0x10, %l2
a00e1cb8:  9e 13 00 09  or  %o4, %o1, %o7
a00e1cbc:  ba 13 40 12  or  %o5, %l2, %i5
a00e1cc0:  83 2c 60 08  sll  %l1, 8, %g1
a00e1cc4:  91 2c 20 08  sll  %l0, 8, %o0
a00e1cc8:  ee 0f bf eb  ldub  [ %fp + -21 ], %l7
a00e1ccc:  ea 0f bf ef  ldub  [ %fp + -17 ], %l5
a00e1cd0:  ac 13 c0 01  or  %o7, %g1, %l6
a00e1cd4:  96 17 40 08  or  %i5, %o0, %o3
a00e1cd8:  98 15 80 17  or  %l6, %l7, %o4
a00e1cdc:  a6 12 c0 15  or  %o3, %l5, %l3
a00e1ce0:  29 30 05 40  sethi  %hi(0xc0150000), %l4
a00e1ce4:  e6 23 00 14  st  %l3, [ %o4 + %l4 ]
a00e1ce8:  15 30 45 40  sethi  %hi(0xc1150000), %o2
a00e1cec:  e6 23 00 0a  st  %l3, [ %o4 + %o2 ]
a00e1cf0:  10 bf fc 7a  b  0xa00e0ed8
a00e1cf4:  b0 06 20 01  inc  %i0
a00e1cf8:  92 07 bf f8  add  %fp, -8, %o1
a00e1cfc:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1d00:  98 10 20 07  mov  7, %o4
a00e1d04:  82 0a e0 ff  and  %o3, 0xff, %g1
a00e1d08:  b0 06 20 01  inc  %i0
a00e1d0c:  ba 02 40 01  add  %o1, %g1, %i5
a00e1d10:  d0 0a 80 18  ldub  [ %o2 + %i0 ], %o0
a00e1d14:  d0 2f 7f f0  stb  %o0, [ %i5 + -16 ]
a00e1d18:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1d1c:  1c bf ff fa  bpos  0xa00e1d04
a00e1d20:  96 02 e0 01  inc  %o3
a00e1d24:  d2 0f bf e8  ldub  [ %fp + -24 ], %o1
a00e1d28:  e0 0f bf e9  ldub  [ %fp + -23 ], %l0
a00e1d2c:  de 0f bf ed  ldub  [ %fp + -19 ], %o7
a00e1d30:  c2 0f bf ec  ldub  [ %fp + -20 ], %g1
a00e1d34:  bb 2a 60 18  sll  %o1, 0x18, %i5
a00e1d38:  91 2c 20 10  sll  %l0, 0x10, %o0
a00e1d3c:  af 2b e0 10  sll  %o7, 0x10, %l7
a00e1d40:  ea 0f bf ea  ldub  [ %fp + -22 ], %l5
a00e1d44:  d6 0f bf ee  ldub  [ %fp + -18 ], %o3
a00e1d48:  ad 28 60 18  sll  %g1, 0x18, %l6
a00e1d4c:  a6 17 40 08  or  %i5, %o0, %l3
a00e1d50:  a4 15 80 17  or  %l6, %l7, %l2
a00e1d54:  a9 2d 60 08  sll  %l5, 8, %l4
a00e1d58:  95 2a e0 08  sll  %o3, 8, %o2
a00e1d5c:  d8 0f bf eb  ldub  [ %fp + -21 ], %o4
a00e1d60:  e2 0f bf ef  ldub  [ %fp + -17 ], %l1
a00e1d64:  9a 14 c0 14  or  %l3, %l4, %o5
a00e1d68:  92 14 80 0a  or  %l2, %o2, %o1
a00e1d6c:  9e 13 40 0c  or  %o5, %o4, %o7
a00e1d70:  a0 12 40 11  or  %o1, %l1, %l0
a00e1d74:  e0 23 c0 00  st  %l0, [ %o7 ]
a00e1d78:  10 bf fc 58  b  0xa00e0ed8
a00e1d7c:  b0 06 20 01  inc  %i0
a00e1d80:  92 07 bf f8  add  %fp, -8, %o1
a00e1d84:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1d88:  98 10 20 04  mov  4, %o4
a00e1d8c:  a0 0a e0 ff  and  %o3, 0xff, %l0
a00e1d90:  b0 06 20 01  inc  %i0
a00e1d94:  9e 02 40 10  add  %o1, %l0, %o7
a00e1d98:  da 0a 80 18  ldub  [ %o2 + %i0 ], %o5
a00e1d9c:  da 2b ff f0  stb  %o5, [ %o7 + -16 ]
a00e1da0:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1da4:  1c bf ff fa  bpos  0xa00e1d8c
a00e1da8:  96 02 e0 01  inc  %o3
a00e1dac:  ee 0f bf e8  ldub  [ %fp + -24 ], %l7
a00e1db0:  ec 0f bf e9  ldub  [ %fp + -23 ], %l6
a00e1db4:  e6 0f bf ea  ldub  [ %fp + -22 ], %l3
a00e1db8:  a9 2d e0 18  sll  %l7, 0x18, %l4
a00e1dbc:  ab 2d a0 10  sll  %l6, 0x10, %l5
a00e1dc0:  96 15 00 15  or  %l4, %l5, %o3
a00e1dc4:  a5 2c e0 08  sll  %l3, 8, %l2
a00e1dc8:  d4 0f bf eb  ldub  [ %fp + -21 ], %o2
a00e1dcc:  a2 12 c0 12  or  %o3, %l2, %l1
a00e1dd0:  92 14 40 0a  or  %l1, %o2, %o1
a00e1dd4:  d8 0f bf ec  ldub  [ %fp + -20 ], %o4
a00e1dd8:  d8 2a 40 00  stb  %o4, [ %o1 ]
a00e1ddc:  10 bf fc 3f  b  0xa00e0ed8
a00e1de0:  b0 06 20 01  inc  %i0
a00e1de4:  b0 06 20 01  inc  %i0
a00e1de8:  ea 06 e2 54  ld  [ %i3 + 0x254 ], %l5
a00e1dec:  d2 0d 40 18  ldub  [ %l5 + %i0 ], %o1
a00e1df0:  10 bf fc 39  b  0xa00e0ed4
a00e1df4:  d2 2f bf e8  stb  %o1, [ %fp + -24 ]
a00e1df8:  d0 06 e2 54  ld  [ %i3 + 0x254 ], %o0
a00e1dfc:  b0 06 20 01  inc  %i0
a00e1e00:  ee 0a 00 18  ldub  [ %o0 + %i0 ], %l7
a00e1e04:  bb 2d e0 02  sll  %l7, 2, %i5
a00e1e08:  ac 07 40 17  add  %i5, %l7, %l6
a00e1e0c:  ee 2f bf e8  stb  %l7, [ %fp + -24 ]
a00e1e10:  7f ff f8 65  call  0xa00dffa4
a00e1e14:  90 05 80 16  add  %l6, %l6, %o0
a00e1e18:  10 bf fc 30  b  0xa00e0ed8
a00e1e1c:  b0 06 20 01  inc  %i0
a00e1e20:  92 07 bf f8  add  %fp, -8, %o1
a00e1e24:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1e28:  98 10 20 09  mov  9, %o4
a00e1e2c:  a8 0a e0 ff  and  %o3, 0xff, %l4
a00e1e30:  b0 06 20 01  inc  %i0
a00e1e34:  ae 02 40 14  add  %o1, %l4, %l7
a00e1e38:  e2 0a 80 18  ldub  [ %o2 + %i0 ], %l1
a00e1e3c:  e2 2d ff f0  stb  %l1, [ %l7 + -16 ]
a00e1e40:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1e44:  1c bf ff fa  bpos  0xa00e1e2c
a00e1e48:  96 02 e0 01  inc  %o3
a00e1e4c:  e0 0f bf ee  ldub  [ %fp + -18 ], %l0
a00e1e50:  d2 0f bf ef  ldub  [ %fp + -17 ], %o1
a00e1e54:  da 0f bf e8  ldub  [ %fp + -24 ], %o5
a00e1e58:  d0 0f bf e9  ldub  [ %fp + -23 ], %o0
a00e1e5c:  95 2c 20 18  sll  %l0, 0x18, %o2
a00e1e60:  83 2a 60 10  sll  %o1, 0x10, %g1
a00e1e64:  a7 2a 20 10  sll  %o0, 0x10, %l3
a00e1e68:  fa 0f bf f0  ldub  [ %fp + -16 ], %i5
a00e1e6c:  a9 2b 60 18  sll  %o5, 0x18, %l4
a00e1e70:  ae 12 80 01  or  %o2, %g1, %l7
a00e1e74:  a3 2f 60 08  sll  %i5, 8, %l1
a00e1e78:  aa 15 00 13  or  %l4, %l3, %l5
a00e1e7c:  ec 0f bf ea  ldub  [ %fp + -22 ], %l6
a00e1e80:  de 0f bf ec  ldub  [ %fp + -20 ], %o7
a00e1e84:  92 10 20 01  mov  1, %o1
a00e1e88:  e6 0f bf ed  ldub  [ %fp + -19 ], %l3
a00e1e8c:  a4 15 c0 11  or  %l7, %l1, %l2
a00e1e90:  99 2d a0 08  sll  %l6, 8, %o4
a00e1e94:  a0 03 e0 01  add  %o7, 1, %l0
a00e1e98:  d6 0f bf f1  ldub  [ %fp + -15 ], %o3
a00e1e9c:  9a 15 40 0c  or  %l5, %o4, %o5
a00e1ea0:  94 14 80 0b  or  %l2, %o3, %o2
a00e1ea4:  bb 2a 40 10  sll  %o1, %l0, %i5
a00e1ea8:  83 2a 40 13  sll  %o1, %l3, %g1
a00e1eac:  d0 0f bf eb  ldub  [ %fp + -21 ], %o0
a00e1eb0:  90 13 40 08  or  %o5, %o0, %o0
a00e1eb4:  92 27 40 01  sub  %i5, %g1, %o1
a00e1eb8:  95 2a 80 13  sll  %o2, %l3, %o2
a00e1ebc:  40 00 00 b1  call  0xa00e2180
a00e1ec0:  b0 06 20 01  inc  %i0
a00e1ec4:  10 bf fc 06  b  0xa00e0edc
a00e1ec8:  e6 07 22 58  ld  [ %i4 + 0x258 ], %l3
a00e1ecc:  92 07 bf f8  add  %fp, -8, %o1
a00e1ed0:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1ed4:  98 10 20 04  mov  4, %o4
a00e1ed8:  a2 0a e0 ff  and  %o3, 0xff, %l1
a00e1edc:  b0 06 20 01  inc  %i0
a00e1ee0:  9e 02 40 11  add  %o1, %l1, %o7
a00e1ee4:  e0 0a 80 18  ldub  [ %o2 + %i0 ], %l0
a00e1ee8:  e0 2b ff f0  stb  %l0, [ %o7 + -16 ]
a00e1eec:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1ef0:  1c bf ff fa  bpos  0xa00e1ed8
a00e1ef4:  96 02 e0 01  inc  %o3
a00e1ef8:  ea 0f bf e9  ldub  [ %fp + -23 ], %l5
a00e1efc:  e8 0f bf eb  ldub  [ %fp + -21 ], %l4
a00e1f00:  a5 2d 60 08  sll  %l5, 8, %l2
a00e1f04:  95 2d 20 08  sll  %l4, 8, %o2
a00e1f08:  e6 0f bf ea  ldub  [ %fp + -22 ], %l3
a00e1f0c:  d6 0f bf ec  ldub  [ %fp + -20 ], %o3
a00e1f10:  92 14 80 13  or  %l2, %l3, %o1
a00e1f14:  94 12 80 0b  or  %o2, %o3, %o2
a00e1f18:  7f ff f8 30  call  0xa00dffd8
a00e1f1c:  d0 0f bf e8  ldub  [ %fp + -24 ], %o0
a00e1f20:  10 bf fb ee  b  0xa00e0ed8
a00e1f24:  b0 06 20 01  inc  %i0
a00e1f28:  da 06 e2 54  ld  [ %i3 + 0x254 ], %o5
a00e1f2c:  b0 06 20 01  inc  %i0
a00e1f30:  c2 0e 00 0d  ldub  [ %i0 + %o5 ], %g1
a00e1f34:  80 a0 60 00  cmp  %g1, 0
a00e1f38:  12 bf ff fe  bne  0xa00e1f30
a00e1f3c:  b0 06 20 01  inc  %i0
a00e1f40:  10 bf fb e7  b  0xa00e0edc
a00e1f44:  e6 07 22 58  ld  [ %i4 + 0x258 ], %l3
a00e1f48:  81 c7 e0 08  ret
a00e1f4c:  81 e8 00 00  restore
