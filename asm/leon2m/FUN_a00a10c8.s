# leon2m FUN_a00a10c8 0xa00a10c8-0xa00a13d8 (784 bytes)
a00a10c8:  9d e3 bf 98  save  %sp, -104, %sp
a00a10cc:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a00a10d0:  98 14 a3 f4  or  %l2, 0x3f4, %o4	! 0xa802cff4
a00a10d4:  c2 0b 20 34  ldub  [ %o4 + 0x34 ], %g1
a00a10d8:  80 a0 60 02  cmp  %g1, 2
a00a10dc:  02 80 00 9b  be  0xa00a1348
a00a10e0:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00a10e4:  a0 14 e2 90  or  %l3, 0x290, %l0	! 0xa802d290
a00a10e8:  e2 0c 20 4a  ldub  [ %l0 + 0x4a ], %l1
a00a10ec:  80 a4 60 01  cmp  %l1, 1
a00a10f0:  22 80 00 ab  be,a   0xa00a139c
a00a10f4:  c0 2c 20 4a  clrb  [ %l0 + 0x4a ]
a00a10f8:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a00a10fc:  80 88 60 80  btst  0x80, %g1
a00a1100:  32 80 00 5f  bne,a   0xa00a127c
a00a1104:  82 08 7f 7f  and  %g1, -129, %g1
a00a1108:  d2 04 20 ac  ld  [ %l0 + 0xac ], %o1
a00a110c:  15 00 04 00  sethi  %hi(0x100000), %o2
a00a1110:  80 8a 40 0a  btst  %o1, %o2
a00a1114:  02 80 00 0c  be  0xa00a1144
a00a1118:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a00a111c:  da 0c 20 1f  ldub  [ %l0 + 0x1f ], %o5
a00a1120:  d0 0c 60 56  ldub  [ %l1 + 0x56 ], %o0
a00a1124:  80 a3 40 08  cmp  %o5, %o0
a00a1128:  02 80 00 07  be  0xa00a1144
a00a112c:  01 00 00 00  nop
a00a1130:  40 02 8d 33  call  0xa01445fc
a00a1134:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a00a1138:  80 8a 20 ff  btst  0xff, %o0
a00a113c:  02 80 00 77  be  0xa00a1318
a00a1140:  01 00 00 00  nop
a00a1144:  7f ff 89 a8  call  0xa00837e4
a00a1148:  01 00 00 00  nop
a00a114c:  98 0a 20 ff  and  %o0, 0xff, %o4
a00a1150:  80 a3 20 01  cmp  %o4, 1
a00a1154:  02 80 00 6b  be  0xa00a1300
a00a1158:  96 14 e2 90  or  %l3, 0x290, %o3
a00a115c:  a0 14 e2 90  or  %l3, 0x290, %l0
a00a1160:  e6 0c 60 56  ldub  [ %l1 + 0x56 ], %l3
a00a1164:  9e 10 20 02  mov  2, %o7
a00a1168:  de 2c 20 1f  stb  %o7, [ %l0 + 0x1f ]
a00a116c:  80 a4 e0 02  cmp  %l3, 2
a00a1170:  c0 24 20 b0  clr  [ %l0 + 0xb0 ]
a00a1174:  02 80 00 4a  be  0xa00a129c
a00a1178:  c0 2c 20 19  clrb  [ %l0 + 0x19 ]
a00a117c:  98 14 a3 f4  or  %l2, 0x3f4, %o4
a00a1180:  da 13 20 04  lduh  [ %o4 + 4 ], %o5
a00a1184:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00a1188:  a2 0b 40 01  and  %o5, %g1, %l1
a00a118c:  a5 2c 60 10  sll  %l1, 0x10, %l2
a00a1190:  80 a4 a0 00  cmp  %l2, 0
a00a1194:  12 80 00 34  bne  0xa00a1264
a00a1198:  94 13 64 00  or  %o5, 0x400, %o2
a00a119c:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00a11a0:  40 00 4f b8  call  0xa00b5080
a00a11a4:  c0 24 63 ec  clr  [ %l1 + 0x3ec ]	! 0xa802afec
a00a11a8:  40 00 e0 15  call  0xa00d91fc
a00a11ac:  90 10 20 00  clr  %o0
a00a11b0:  90 10 20 00  clr  %o0
a00a11b4:  40 02 9c 2d  call  0xa0148268
a00a11b8:  92 10 20 01  mov  1, %o1
a00a11bc:  92 10 20 01  mov  1, %o1
a00a11c0:  40 02 9c 2a  call  0xa0148268
a00a11c4:  90 10 20 01  mov  1, %o0
a00a11c8:  40 00 e4 23  call  0xa00da254
a00a11cc:  01 00 00 00  nop
a00a11d0:  7f ff 87 c9  call  0xa00830f4
a00a11d4:  90 10 20 00  clr  %o0	! 0x0
a00a11d8:  40 00 de 91  call  0xa00d8c1c
a00a11dc:  01 00 00 00  nop
a00a11e0:  40 00 2f 45  call  0xa00acef4
a00a11e4:  01 00 00 00  nop
a00a11e8:  40 00 cd ec  call  0xa00d4998
a00a11ec:  01 00 00 00  nop
a00a11f0:  d0 04 20 a8  ld  [ %l0 + 0xa8 ], %o0
a00a11f4:  13 00 00 10  sethi  %hi(0x4000), %o1
a00a11f8:  80 8a 00 09  btst  %o0, %o1
a00a11fc:  12 80 00 43  bne  0xa00a1308
a00a1200:  01 00 00 00  nop
a00a1204:  90 10 20 00  clr  %o0	! 0x0
a00a1208:  7f ff 7d a9  call  0xa00808ac
a00a120c:  92 10 20 00  clr  %o1
a00a1210:  90 10 20 01  mov  1, %o0
a00a1214:  7f ff 7d a6  call  0xa00808ac
a00a1218:  92 10 20 00  clr  %o1
a00a121c:  da 0c 20 1f  ldub  [ %l0 + 0x1f ], %o5
a00a1220:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00a1224:  da 2c 20 56  stb  %o5, [ %l0 + 0x56 ]	! 0xa8025c56
a00a1228:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00a122c:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1
a00a1230:  a2 00 7f 81  add  %g1, -127, %l1
a00a1234:  d0 0c 20 54  ldub  [ %l0 + 0x54 ], %o0
a00a1238:  80 a4 40 08  cmp  %l1, %o0
a00a123c:  22 80 00 62  be,a   0xa00a13c4
a00a1240:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00a1244:  40 00 20 5e  call  0xa00a93bc
a00a1248:  01 00 00 00  nop
a00a124c:  d2 0c 20 54  ldub  [ %l0 + 0x54 ], %o1
a00a1250:  90 10 20 01  mov  1, %o0
a00a1254:  40 00 1b ba  call  0xa00a813c
a00a1258:  94 10 20 00  clr  %o2
a00a125c:  10 80 00 5a  b  0xa00a13c4
a00a1260:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00a1264:  d4 33 20 04  sth  %o2, [ %o4 + 4 ]
a00a1268:  90 10 20 04  mov  4, %o0
a00a126c:  7f ff 7d 90  call  0xa00808ac
a00a1270:  92 10 20 00  clr  %o1
a00a1274:  10 bf ff cb  b  0xa00a11a0
a00a1278:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00a127c:  40 02 0f 32  call  0xa0124f44
a00a1280:  c2 24 20 a8  st  %g1, [ %l0 + 0xa8 ]
a00a1284:  40 00 df de  call  0xa00d91fc
a00a1288:  90 10 20 00  clr  %o0
a00a128c:  40 00 e3 be  call  0xa00da184
a00a1290:  01 00 00 00  nop
a00a1294:  10 bf ff 9e  b  0xa00a110c
a00a1298:  d2 04 20 ac  ld  [ %l0 + 0xac ], %o1
a00a129c:  98 14 a3 f4  or  %l2, 0x3f4, %o4
a00a12a0:  da 13 20 04  lduh  [ %o4 + 4 ], %o5
a00a12a4:  1f 3f ff e0  sethi  %hi(0xffff8000), %o7
a00a12a8:  a6 0b 40 0f  and  %o5, %o7, %l3
a00a12ac:  97 2c e0 10  sll  %l3, 0x10, %o3
a00a12b0:  80 a2 e0 00  cmp  %o3, 0
a00a12b4:  12 80 00 3e  bne  0xa00a13ac
a00a12b8:  a4 13 64 00  or  %o5, 0x400, %l2
a00a12bc:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00a12c0:  40 00 4f 70  call  0xa00b5080
a00a12c4:  c0 24 63 ec  clr  [ %l1 + 0x3ec ]	! 0xa802afec
a00a12c8:  40 00 df cd  call  0xa00d91fc
a00a12cc:  90 10 20 00  clr  %o0
a00a12d0:  90 10 20 00  clr  %o0
a00a12d4:  40 02 9b e5  call  0xa0148268
a00a12d8:  92 10 20 01  mov  1, %o1
a00a12dc:  90 10 20 01  mov  1, %o0
a00a12e0:  40 02 9b e2  call  0xa0148268
a00a12e4:  92 10 20 01  mov  1, %o1
a00a12e8:  40 00 e3 db  call  0xa00da254
a00a12ec:  01 00 00 00  nop
a00a12f0:  d8 0c 20 2f  ldub  [ %l0 + 0x2f ], %o4
a00a12f4:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00a12f8:  10 bf ff cd  b  0xa00a122c
a00a12fc:  d8 2c 20 54  stb  %o4, [ %l0 + 0x54 ]	! 0xa8025c54
a00a1300:  10 bf ff 97  b  0xa00a115c
a00a1304:  c0 2a e1 a4  clrb  [ %o3 + 0x1a4 ]
a00a1308:  40 00 d2 74  call  0xa00d5cd8
a00a130c:  01 00 00 00  nop
a00a1310:  10 bf ff be  b  0xa00a1208
a00a1314:  90 10 20 00  clr  %o0	! 0x0
a00a1318:  40 00 df b9  call  0xa00d91fc
a00a131c:  90 10 20 00  clr  %o0
a00a1320:  90 10 20 10  mov  0x10, %o0
a00a1324:  40 02 89 ad  call  0xa01439d8
a00a1328:  92 10 20 01  mov  1, %o1
a00a132c:  90 10 20 00  clr  %o0
a00a1330:  40 02 9b ce  call  0xa0148268
a00a1334:  92 10 20 01  mov  1, %o1
a00a1338:  90 10 20 01  mov  1, %o0
a00a133c:  40 02 9b cb  call  0xa0148268
a00a1340:  92 10 20 01  mov  1, %o1
a00a1344:  30 bf ff 80  b,a   0xa00a1144
a00a1348:  9a 14 e2 90  or  %l3, 0x290, %o5
a00a134c:  d6 13 20 38  lduh  [ %o4 + 0x38 ], %o3
a00a1350:  e0 03 61 ec  ld  [ %o5 + 0x1ec ], %l0
a00a1354:  d8 13 20 36  lduh  [ %o4 + 0x36 ], %o4
a00a1358:  9e 14 20 40  or  %l0, 0x40, %o7
a00a135c:  93 2b 20 10  sll  %o4, 0x10, %o1
a00a1360:  95 2a e0 10  sll  %o3, 0x10, %o2
a00a1364:  11 00 04 20  sethi  %hi(0x108000), %o0
a00a1368:  de 23 61 ec  st  %o7, [ %o5 + 0x1ec ]
a00a136c:  d6 33 61 f2  sth  %o3, [ %o5 + 0x1f2 ]
a00a1370:  d8 33 61 f0  sth  %o4, [ %o5 + 0x1f0 ]
a00a1374:  90 12 21 b0  or  %o0, 0x1b0, %o0
a00a1378:  93 32 60 10  srl  %o1, 0x10, %o1
a00a137c:  40 00 f7 7d  call  0xa00df170
a00a1380:  95 32 a0 10  srl  %o2, 0x10, %o2
a00a1384:  a0 14 e2 90  or  %l3, 0x290, %l0
a00a1388:  e2 0c 20 4a  ldub  [ %l0 + 0x4a ], %l1
a00a138c:  80 a4 60 01  cmp  %l1, 1
a00a1390:  32 bf ff 5b  bne,a   0xa00a10fc
a00a1394:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a00a1398:  c0 2c 20 4a  clrb  [ %l0 + 0x4a ]
a00a139c:  40 00 d2 c4  call  0xa00d5eac
a00a13a0:  90 10 20 00  clr  %o0
a00a13a4:  10 bf ff 56  b  0xa00a10fc
a00a13a8:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a00a13ac:  e4 33 20 04  sth  %l2, [ %o4 + 4 ]
a00a13b0:  90 10 20 04  mov  4, %o0
a00a13b4:  7f ff 7d 3e  call  0xa00808ac
a00a13b8:  92 10 20 00  clr  %o1
a00a13bc:  10 bf ff c1  b  0xa00a12c0
a00a13c0:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00a13c4:  d0 0a a0 8e  ldub  [ %o2 + 0x8e ], %o0
a00a13c8:  92 12 20 02  or  %o0, 2, %o1
a00a13cc:  d2 2a a0 8e  stb  %o1, [ %o2 + 0x8e ]
a00a13d0:  81 c7 e0 08  ret
a00a13d4:  81 e8 00 00  restore
