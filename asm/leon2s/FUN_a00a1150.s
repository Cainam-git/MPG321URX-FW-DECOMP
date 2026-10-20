# leon2s FUN_a00a1150 0xa00a1150-0xa00a13a0 (592 bytes)
a00a1150:  9d e3 bf 40  save  %sp, -192, %sp
a00a1154:  a8 0e 20 ff  and  %i0, 0xff, %l4
a00a1158:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a00a115c:  a0 14 23 00  or  %l0, 0x300, %l0	! 0xa807db00
a00a1160:  a2 5d 20 34  smul  %l4, 0x34, %l1
a00a1164:  c2 04 00 11  ld  [ %l0 + %l1 ], %g1
a00a1168:  e6 00 60 70  ld  [ %g1 + 0x70 ], %l3
a00a116c:  93 34 e0 08  srl  %l3, 8, %o1
a00a1170:  15 2a 01 e1  sethi  %hi(0xa8078400), %o2
a00a1174:  92 0a 60 04  and  %o1, 4, %o1
a00a1178:  94 12 a2 f0  or  %o2, 0x2f0, %o2
a00a117c:  7f ff ff c7  call  0xa00a1098
a00a1180:  90 10 00 14  mov  %l4, %o0
a00a1184:  93 34 e0 10  srl  %l3, 0x10, %o1
a00a1188:  15 2a 01 e1  sethi  %hi(0xa8078400), %o2
a00a118c:  92 0a 60 02  and  %o1, 2, %o1
a00a1190:  94 12 a2 d0  or  %o2, 0x2d0, %o2
a00a1194:  7f ff ff c1  call  0xa00a1098
a00a1198:  90 10 00 14  mov  %l4, %o0
a00a119c:  93 34 e0 18  srl  %l3, 0x18, %o1
a00a11a0:  15 2a 01 e1  sethi  %hi(0xa8078400), %o2
a00a11a4:  92 0a 60 06  and  %o1, 6, %o1
a00a11a8:  94 12 a2 b0  or  %o2, 0x2b0, %o2
a00a11ac:  7f ff ff bb  call  0xa00a1098
a00a11b0:  90 10 00 14  mov  %l4, %o0
a00a11b4:  03 01 80 81  sethi  %hi(0x6020400), %g1
a00a11b8:  82 14 c0 01  or  %l3, %g1, %g1
a00a11bc:  da 04 00 11  ld  [ %l0 + %l1 ], %o5
a00a11c0:  c2 23 60 70  st  %g1, [ %o5 + 0x70 ]
a00a11c4:  e6 03 60 74  ld  [ %o5 + 0x74 ], %l3
a00a11c8:  15 2a 01 e1  sethi  %hi(0xa8078400), %o2
a00a11cc:  92 0c e0 03  and  %l3, 3, %o1
a00a11d0:  94 12 a2 90  or  %o2, 0x290, %o2
a00a11d4:  7f ff ff b1  call  0xa00a1098
a00a11d8:  90 10 00 14  mov  %l4, %o0
a00a11dc:  9a 14 e0 03  or  %l3, 3, %o5
a00a11e0:  c2 04 00 11  ld  [ %l0 + %l1 ], %g1
a00a11e4:  da 20 60 74  st  %o5, [ %g1 + 0x74 ]
a00a11e8:  15 2a 01 e4  sethi  %hi(0xa8079000), %o2
a00a11ec:  e6 00 60 78  ld  [ %g1 + 0x78 ], %l3
a00a11f0:  94 12 a1 58  or  %o2, 0x158, %o2
a00a11f4:  90 10 00 14  mov  %l4, %o0
a00a11f8:  7f ff ff a8  call  0xa00a1098
a00a11fc:  92 10 20 00  clr  %o1
a00a1200:  c2 04 00 11  ld  [ %l0 + %l1 ], %g1
a00a1204:  e6 20 60 78  st  %l3, [ %g1 + 0x78 ]
a00a1208:  e6 00 60 7c  ld  [ %g1 + 0x7c ], %l3
a00a120c:  15 2a 01 e1  sethi  %hi(0xa8078400), %o2
a00a1210:  92 0c e0 08  and  %l3, 8, %o1
a00a1214:  94 12 a2 70  or  %o2, 0x270, %o2
a00a1218:  7f ff ff a0  call  0xa00a1098
a00a121c:  90 10 00 14  mov  %l4, %o0
a00a1220:  3b 2a 01 f5  sethi  %hi(0xa807d400), %i5
a00a1224:  da 04 00 11  ld  [ %l0 + %l1 ], %o5
a00a1228:  82 14 e0 08  or  %l3, 8, %g1
a00a122c:  ae 17 63 e0  or  %i5, 0x3e0, %l7
a00a1230:  ac 5d 21 90  smul  %l4, 0x190, %l6
a00a1234:  c2 23 60 7c  st  %g1, [ %o5 + 0x7c ]
a00a1238:  aa 05 80 17  add  %l6, %l7, %l5
a00a123c:  c0 2d 61 58  clrb  [ %l5 + 0x158 ]
a00a1240:  e6 03 60 80  ld  [ %o5 + 0x80 ], %l3
a00a1244:  93 34 e0 18  srl  %l3, 0x18, %o1
a00a1248:  15 2a 01 e1  sethi  %hi(0xa8078400), %o2
a00a124c:  92 0a 60 20  and  %o1, 0x20, %o1
a00a1250:  94 12 a2 50  or  %o2, 0x250, %o2
a00a1254:  7f ff ff 91  call  0xa00a1098
a00a1258:  90 10 00 14  mov  %l4, %o0
a00a125c:  03 08 00 00  sethi  %hi(0x20000000), %g1
a00a1260:  82 14 c0 01  or  %l3, %g1, %g1
a00a1264:  da 04 00 11  ld  [ %l0 + %l1 ], %o5
a00a1268:  c2 23 60 80  st  %g1, [ %o5 + 0x80 ]
a00a126c:  15 2a 01 e4  sethi  %hi(0xa8079000), %o2
a00a1270:  e6 03 60 90  ld  [ %o5 + 0x90 ], %l3
a00a1274:  94 12 a1 38  or  %o2, 0x138, %o2
a00a1278:  90 10 00 14  mov  %l4, %o0
a00a127c:  7f ff ff 87  call  0xa00a1098
a00a1280:  92 10 20 00  clr  %o1
a00a1284:  c2 04 00 11  ld  [ %l0 + %l1 ], %g1
a00a1288:  e6 20 60 90  st  %l3, [ %g1 + 0x90 ]
a00a128c:  a4 04 40 10  add  %l1, %l0, %l2
a00a1290:  c2 04 a0 24  ld  [ %l2 + 0x24 ], %g1
a00a1294:  15 2a 01 e4  sethi  %hi(0xa8079000), %o2
a00a1298:  e6 00 60 c4  ld  [ %g1 + 0xc4 ], %l3
a00a129c:  94 12 a1 18  or  %o2, 0x118, %o2
a00a12a0:  90 10 00 14  mov  %l4, %o0
a00a12a4:  7f ff ff 7d  call  0xa00a1098
a00a12a8:  92 10 20 00  clr  %o1
a00a12ac:  c2 04 a0 24  ld  [ %l2 + 0x24 ], %g1
a00a12b0:  e6 20 60 c4  st  %l3, [ %g1 + 0xc4 ]
a00a12b4:  c2 0d 60 08  ldub  [ %l5 + 8 ], %g1
a00a12b8:  80 a0 60 01  cmp  %g1, 1
a00a12bc:  12 80 00 36  bne  0xa00a1394
a00a12c0:  01 00 00 00  nop
a00a12c4:  c2 0d 60 01  ldub  [ %l5 + 1 ], %g1
a00a12c8:  80 a0 60 01  cmp  %g1, 1
a00a12cc:  12 80 00 32  bne  0xa00a1394
a00a12d0:  c0 2d 60 08  clrb  [ %l5 + 8 ]
a00a12d4:  7f ff da ff  call  0xa0097ed0
a00a12d8:  90 10 00 14  mov  %l4, %o0
a00a12dc:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00a12e0:  80 a4 60 01  cmp  %l1, 1
a00a12e4:  12 80 00 2c  bne  0xa00a1394
a00a12e8:  a0 05 e0 4c  add  %l7, 0x4c, %l0
a00a12ec:  a0 05 80 10  add  %l6, %l0, %l0
a00a12f0:  92 10 00 10  mov  %l0, %o1
a00a12f4:  94 10 20 58  mov  0x58, %o2
a00a12f8:  40 00 40 b8  call  0xa00b15d8
a00a12fc:  90 07 bf a0  add  %fp, -96, %o0
a00a1300:  90 10 00 14  mov  %l4, %o0
a00a1304:  7f ff f9 0d  call  0xa009f738
a00a1308:  92 10 00 10  mov  %l0, %o1
a00a130c:  da 0d 60 7c  ldub  [ %l5 + 0x7c ], %o5
a00a1310:  c2 0f bf d0  ldub  [ %fp + -48 ], %g1
a00a1314:  80 a3 40 01  cmp  %o5, %g1
a00a1318:  02 80 00 09  be  0xa00a133c
a00a131c:  82 05 00 14  add  %l4, %l4, %g1
a00a1320:  82 00 40 14  add  %g1, %l4, %g1
a00a1324:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00a1328:  83 28 60 03  sll  %g1, 3, %g1
a00a132c:  9a 13 62 50  or  %o5, 0x250, %o5
a00a1330:  82 00 40 0d  add  %g1, %o5, %g1
a00a1334:  10 80 00 0b  b  0xa00a1360
a00a1338:  e2 28 60 14  stb  %l1, [ %g1 + 0x14 ]
a00a133c:  da 05 60 50  ld  [ %l5 + 0x50 ], %o5
a00a1340:  c2 07 bf a4  ld  [ %fp + -92 ], %g1
a00a1344:  80 a3 40 01  cmp  %o5, %g1
a00a1348:  02 80 00 07  be  0xa00a1364
a00a134c:  90 0e 20 ff  and  %i0, 0xff, %o0
a00a1350:  7f ff f5 9f  call  0xa009e9cc
a00a1354:  90 10 00 14  mov  %l4, %o0
a00a1358:  7f ff ed 49  call  0xa009c87c
a00a135c:  90 10 00 14  mov  %l4, %o0
a00a1360:  90 0e 20 ff  and  %i0, 0xff, %o0
a00a1364:  92 17 63 e0  or  %i5, 0x3e0, %o1
a00a1368:  96 5a 21 90  smul  %o0, 0x190, %o3
a00a136c:  82 02 c0 09  add  %o3, %o1, %g1
a00a1370:  9a 10 20 01  mov  1, %o5
a00a1374:  d8 08 60 a3  ldub  [ %g1 + 0xa3 ], %o4
a00a1378:  da 28 60 a2  stb  %o5, [ %g1 + 0xa2 ]
a00a137c:  80 a3 20 00  cmp  %o4, 0
a00a1380:  12 80 00 05  bne  0xa00a1394
a00a1384:  da 28 60 a1  stb  %o5, [ %g1 + 0xa1 ]
a00a1388:  92 02 60 4c  add  %o1, 0x4c, %o1
a00a138c:  7f ff f8 eb  call  0xa009f738
a00a1390:  92 02 c0 09  add  %o3, %o1, %o1
a00a1394:  01 00 00 00  nop
a00a1398:  81 c7 e0 08  ret
a00a139c:  81 e8 00 00  restore
