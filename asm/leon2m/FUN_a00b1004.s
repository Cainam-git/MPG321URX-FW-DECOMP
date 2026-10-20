# leon2m FUN_a00b1004 0xa00b1004-0xa00b1654 (1568 bytes)
a00b1004:  9d e3 bf 90  save  %sp, -112, %sp
a00b1008:  40 00 10 1e  call  0xa00b5080
a00b100c:  a2 10 20 05  mov  5, %l1
a00b1010:  40 00 10 da  call  0xa00b5378
a00b1014:  a0 10 20 05  mov  5, %l0
a00b1018:  67 ff 74 a3  call  0x4008e2a4
a00b101c:  01 00 00 00  nop
a00b1020:  94 10 00 10  mov  %l0, %o2
a00b1024:  90 10 20 00  clr  %o0
a00b1028:  92 10 20 13  mov  0x13, %o1
a00b102c:  96 10 20 13  mov  0x13, %o3
a00b1030:  98 10 20 00  clr  %o4
a00b1034:  40 02 56 bb  call  0xa0146b20
a00b1038:  9a 10 20 00  clr  %o5
a00b103c:  92 10 00 10  mov  %l0, %o1
a00b1040:  90 10 20 13  mov  0x13, %o0
a00b1044:  94 10 20 13  mov  0x13, %o2
a00b1048:  96 10 27 92  mov  0x792, %o3
a00b104c:  98 10 20 00  clr  %o4
a00b1050:  40 02 56 8c  call  0xa0146a80
a00b1054:  a2 04 60 01  inc  %l1
a00b1058:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00b105c:  80 a4 20 14  cmp  %l0, 0x14
a00b1060:  08 bf ff f1  bleu  0xa00b1024
a00b1064:  94 10 00 10  mov  %l0, %o2
a00b1068:  96 10 20 02  mov  2, %o3
a00b106c:  98 10 20 00  clr  %o4
a00b1070:  9a 10 20 00  clr  %o5
a00b1074:  90 10 20 00  clr  %o0
a00b1078:  92 10 20 1c  mov  0x1c, %o1
a00b107c:  40 02 56 a9  call  0xa0146b20
a00b1080:  94 10 20 15  mov  0x15, %o2
a00b1084:  90 10 20 05  mov  5, %o0
a00b1088:  92 10 20 00  clr  %o1
a00b108c:  40 02 56 ed  call  0xa0146c40
a00b1090:  94 10 20 00  clr  %o2
a00b1094:  7f ff de fd  call  0xa00a8c88
a00b1098:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b109c:  80 a6 20 02  cmp  %i0, 2
a00b10a0:  02 80 00 82  be  0xa00b12a8
a00b10a4:  90 10 20 02  mov  2, %o0
a00b10a8:  14 80 00 09  bg  0xa00b10cc
a00b10ac:  80 a6 20 07  cmp  %i0, 7
a00b10b0:  80 a6 20 00  cmp  %i0, 0
a00b10b4:  02 80 00 e9  be  0xa00b1458
a00b10b8:  90 10 20 01  mov  1, %o0
a00b10bc:  40 00 8d b1  call  0xa00d4780
a00b10c0:  b0 10 20 01  mov  1, %i0
a00b10c4:  40 02 57 3f  call  0xa0146dc0
a00b10c8:  93 e8 20 00  restore  %g0, 0, %o1
a00b10cc:  12 bf ff fc  bne  0xa00b10bc
a00b10d0:  01 00 00 00  nop
a00b10d4:  67 ff 74 74  call  0x4008e2a4
a00b10d8:  a2 10 20 05  mov  5, %l1	! 0x5
a00b10dc:  a0 10 20 05  mov  5, %l0
a00b10e0:  92 10 00 10  mov  %l0, %o1
a00b10e4:  90 10 20 01  mov  1, %o0
a00b10e8:  94 10 20 11  mov  0x11, %o2
a00b10ec:  96 10 27 92  mov  0x792, %o3
a00b10f0:  40 02 56 64  call  0xa0146a80
a00b10f4:  98 10 20 00  clr  %o4
a00b10f8:  94 10 00 10  mov  %l0, %o2
a00b10fc:  90 10 20 00  clr  %o0
a00b1100:  92 10 20 01  mov  1, %o1
a00b1104:  96 10 20 11  mov  0x11, %o3
a00b1108:  98 10 20 00  clr  %o4
a00b110c:  9a 10 20 00  clr  %o5
a00b1110:  40 02 56 84  call  0xa0146b20
a00b1114:  a2 04 60 01  inc  %l1
a00b1118:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00b111c:  80 a4 20 15  cmp  %l0, 0x15
a00b1120:  08 bf ff f1  bleu  0xa00b10e4
a00b1124:  92 10 00 10  mov  %l0, %o1
a00b1128:  a4 10 20 00  clr  %l2
a00b112c:  b0 10 20 07  mov  7, %i0
a00b1130:  82 10 20 07  mov  7, %g1
a00b1134:  96 10 20 07  mov  7, %o3
a00b1138:  80 a0 60 08  cmp  %g1, 8
a00b113c:  18 80 00 0a  bgu  0xa00b1164
a00b1140:  1f 09 24 92  sethi  %hi(0x24924800), %o7
a00b1144:  33 00 01 10  sethi  %hi(0x44000), %i1
a00b1148:  83 28 60 02  sll  %g1, 2, %g1
a00b114c:  9a 16 62 20  or  %i1, 0x220, %o5
a00b1150:  e2 03 40 01  ld  [ %o5 + %g1 ], %l1
a00b1154:  81 c4 40 00  jmp  %l1
a00b1158:  01 00 00 00  nop
a00b115c:  a4 10 20 70  mov  0x70, %l2	! 0x70
a00b1160:  1f 09 24 92  sethi  %hi(0x24924800), %o7
a00b1164:  a6 13 e1 25  or  %o7, 0x125, %l3	! 0x24924925
a00b1168:  80 52 c0 13  umul  %o3, %l3, %g0
a00b116c:  93 40 00 00  rd  %y, %o1
a00b1170:  98 22 c0 09  sub  %o3, %o1, %o4
a00b1174:  a1 33 20 01  srl  %o4, 1, %l0
a00b1178:  9a 02 40 10  add  %o1, %l0, %o5
a00b117c:  83 33 60 02  srl  %o5, 2, %g1
a00b1180:  90 06 3f fa  add  %i0, -6, %o0
a00b1184:  b2 0a 20 ff  and  %o0, 0xff, %i1
a00b1188:  a3 28 60 03  sll  %g1, 3, %l1
a00b118c:  80 a6 60 02  cmp  %i1, 2
a00b1190:  94 24 40 01  sub  %l1, %g1, %o2
a00b1194:  98 60 20 00  subx  %g0, 0, %o4
a00b1198:  9e 22 c0 0a  sub  %o3, %o2, %o7
a00b119c:  80 a0 00 0b  cmp  %g0, %o3
a00b11a0:  a6 0b e0 ff  and  %o7, 0xff, %l3
a00b11a4:  a2 04 c0 13  add  %l3, %l3, %l1
a00b11a8:  a0 0b 20 01  and  %o4, 1, %l0
a00b11ac:  96 60 3f ff  subx  %g0, -1, %o3
a00b11b0:  80 94 00 0b  orcc  %l0, %o3, %g0
a00b11b4:  02 80 00 37  be  0xa00b1290
a00b11b8:  b2 04 60 06  add  %l1, 6, %i1
a00b11bc:  98 0c a0 ff  and  %l2, 0xff, %o4
a00b11c0:  92 04 60 05  add  %l1, 5, %o1
a00b11c4:  d8 23 a0 5c  st  %o4, [ %sp + 0x5c ]
a00b11c8:  21 00 00 18  sethi  %hi(0x6000), %l0
a00b11cc:  98 0a 60 ff  and  %o1, 0xff, %o4
a00b11d0:  94 14 22 9a  or  %l0, 0x29a, %o2
a00b11d4:  90 10 20 01  mov  1, %o0
a00b11d8:  92 10 20 01  mov  1, %o1
a00b11dc:  96 10 20 02  mov  2, %o3
a00b11e0:  40 00 08 41  call  0xa00b32e4
a00b11e4:  9a 10 20 03  mov  3, %o5
a00b11e8:  9a 04 a0 03  add  %l2, 3, %o5
a00b11ec:  90 0b 60 ff  and  %o5, 0xff, %o0
a00b11f0:  d0 23 a0 5c  st  %o0, [ %sp + 0x5c ]
a00b11f4:  98 0e 60 fe  and  %i1, 0xfe, %o4
a00b11f8:  94 14 22 9a  or  %l0, 0x29a, %o2
a00b11fc:  96 10 20 02  mov  2, %o3
a00b1200:  90 10 20 01  mov  1, %o0
a00b1204:  92 10 20 01  mov  1, %o1
a00b1208:  40 00 08 37  call  0xa00b32e4
a00b120c:  9a 10 20 03  mov  3, %o5
a00b1210:  82 04 a0 06  add  %l2, 6, %g1
a00b1214:  94 08 60 ff  and  %g1, 0xff, %o2
a00b1218:  96 04 60 07  add  %l1, 7, %o3
a00b121c:  d4 23 a0 5c  st  %o2, [ %sp + 0x5c ]
a00b1220:  94 14 22 9a  or  %l0, 0x29a, %o2
a00b1224:  98 0a e0 ff  and  %o3, 0xff, %o4
a00b1228:  96 10 20 02  mov  2, %o3
a00b122c:  90 10 20 01  mov  1, %o0
a00b1230:  92 10 20 01  mov  1, %o1
a00b1234:  40 00 08 2c  call  0xa00b32e4
a00b1238:  9a 10 20 03  mov  3, %o5
a00b123c:  b0 06 20 01  inc  %i0
a00b1240:  96 0e 20 ff  and  %i0, 0xff, %o3
a00b1244:  80 a2 e0 09  cmp  %o3, 9
a00b1248:  0a bf ff bc  bcs  0xa00b1138
a00b124c:  82 10 00 0b  mov  %o3, %g1
a00b1250:  40 00 0a b1  call  0xa00b3d14
a00b1254:  90 10 20 01  mov  1, %o0
a00b1258:  7f ff e5 79  call  0xa00aa83c
a00b125c:  90 10 20 00  clr  %o0
a00b1260:  7f ff ed 2e  call  0xa00ac718
a00b1264:  90 10 20 35  mov  0x35, %o0
a00b1268:  90 10 20 08  mov  8, %o0
a00b126c:  40 00 0b b6  call  0xa00b4144
a00b1270:  92 10 20 01  mov  1, %o1
a00b1274:  90 10 20 08  mov  8, %o0
a00b1278:  40 00 0b b3  call  0xa00b4144
a00b127c:  92 10 20 02  mov  2, %o1
a00b1280:  90 10 20 01  mov  1, %o0
a00b1284:  7f ff df 62  call  0xa00a900c
a00b1288:  92 10 20 01  mov  1, %o1
a00b128c:  30 bf ff 8c  b,a   0xa00b10bc
a00b1290:  a6 0c a0 ff  and  %l2, 0xff, %l3
a00b1294:  23 00 00 19  sethi  %hi(0x6400), %l1
a00b1298:  e6 23 a0 5c  st  %l3, [ %sp + 0x5c ]
a00b129c:  94 14 61 9a  or  %l1, 0x19a, %o2
a00b12a0:  10 bf ff e2  b  0xa00b1228
a00b12a4:  98 0e 60 fe  and  %i1, 0xfe, %o4
a00b12a8:  40 00 0b a7  call  0xa00b4144
a00b12ac:  92 10 20 01  mov  1, %o1
a00b12b0:  90 10 20 02  mov  2, %o0
a00b12b4:  40 00 0b a4  call  0xa00b4144
a00b12b8:  92 10 20 02  mov  2, %o1
a00b12bc:  90 10 20 92  mov  0x92, %o0
a00b12c0:  40 02 56 24  call  0xa0146b50
a00b12c4:  92 10 20 00  clr  %o1
a00b12c8:  90 10 20 00  clr  %o0
a00b12cc:  40 02 56 28  call  0xa0146b6c
a00b12d0:  92 10 20 00  clr  %o1
a00b12d4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00b12d8:  a4 13 22 90  or  %o4, 0x290, %l2	! 0xa802d290
a00b12dc:  b0 10 20 00  clr  %i0
a00b12e0:  a0 10 20 00  clr  %l0
a00b12e4:  10 80 00 1a  b  0xa00b134c
a00b12e8:  27 00 06 21  sethi  %hi(0x188400), %l3
a00b12ec:  99 2c 20 03  sll  %l0, 3, %o4
a00b12f0:  96 23 00 10  sub  %o4, %l0, %o3
a00b12f4:  93 2a e0 02  sll  %o3, 2, %o1
a00b12f8:  90 02 40 10  add  %o1, %l0, %o0
a00b12fc:  d4 0c a0 08  ldub  [ %l2 + 8 ], %o2
a00b1300:  a0 02 00 0a  add  %o0, %o2, %l0
a00b1304:  83 2c 20 10  sll  %l0, 0x10, %g1
a00b1308:  93 30 60 10  srl  %g1, 0x10, %o1
a00b130c:  7f ff c9 4e  call  0xa00a3844
a00b1310:  90 14 e2 34  or  %l3, 0x234, %o0
a00b1314:  9e 04 60 06  add  %l1, 6, %o7
a00b1318:  9b 2b e0 10  sll  %o7, 0x10, %o5
a00b131c:  98 10 00 08  mov  %o0, %o4
a00b1320:  95 33 60 10  srl  %o5, 0x10, %o2
a00b1324:  90 10 20 00  clr  %o0
a00b1328:  92 10 20 14  mov  0x14, %o1
a00b132c:  96 10 20 01  mov  1, %o3
a00b1330:  9a 10 20 00  clr  %o5
a00b1334:  7f ff c7 9c  call  0xa00a31a4
a00b1338:  b0 06 20 01  inc  %i0
a00b133c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00b1340:  80 a4 20 02  cmp  %l0, 2
a00b1344:  18 80 00 0f  bgu  0xa00b1380
a00b1348:  01 00 00 00  nop
a00b134c:  7f ff e4 75  call  0xa00aa520
a00b1350:  90 10 00 10  mov  %l0, %o0
a00b1354:  80 8a 20 ff  btst  0xff, %o0
a00b1358:  12 bf ff e5  bne  0xa00b12ec
a00b135c:  a2 04 00 10  add  %l0, %l0, %l1
a00b1360:  90 10 20 14  mov  0x14, %o0
a00b1364:  92 04 60 06  add  %l1, 6, %o1
a00b1368:  94 10 20 0f  mov  0xf, %o2
a00b136c:  96 10 22 92  mov  0x292, %o3
a00b1370:  40 02 55 c4  call  0xa0146a80
a00b1374:  98 10 20 00  clr  %o4
a00b1378:  10 bf ff de  b  0xa00b12f0
a00b137c:  99 2c 20 03  sll  %l0, 3, %o4
a00b1380:  40 00 16 76  call  0xa00b6d58
a00b1384:  a0 10 00 12  mov  %l2, %l0
a00b1388:  92 10 20 00  clr  %o1
a00b138c:  40 00 15 ff  call  0xa00b6b88
a00b1390:  d0 0c a1 81  ldub  [ %l2 + 0x181 ], %o0
a00b1394:  15 09 24 92  sethi  %hi(0x24924800), %o2
a00b1398:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b139c:  a2 12 a1 25  or  %o2, 0x125, %l1
a00b13a0:  80 52 00 11  umul  %o0, %l1, %g0
a00b13a4:  9b 40 00 00  rd  %y, %o5
a00b13a8:  82 22 00 0d  sub  %o0, %o5, %g1
a00b13ac:  9f 30 60 01  srl  %g1, 1, %o7
a00b13b0:  b0 03 40 0f  add  %o5, %o7, %i0
a00b13b4:  a7 36 20 02  srl  %i0, 2, %l3
a00b13b8:  40 00 16 0d  call  0xa00b6bec
a00b13bc:  90 0c e0 ff  and  %l3, 0xff, %o0
a00b13c0:  80 8e 60 ff  btst  0xff, %i1
a00b13c4:  02 80 00 51  be  0xa00b1508
a00b13c8:  90 10 20 00  clr  %o0
a00b13cc:  7f ff df 10  call  0xa00a900c
a00b13d0:  92 10 20 02  mov  2, %o1
a00b13d4:  d0 0c a1 81  ldub  [ %l2 + 0x181 ], %o0
a00b13d8:  40 00 15 ec  call  0xa00b6b88
a00b13dc:  92 10 20 00  clr  %o1
a00b13e0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b13e4:  80 52 00 11  umul  %o0, %l1, %g0
a00b13e8:  a5 40 00 00  rd  %y, %l2
a00b13ec:  96 22 00 12  sub  %o0, %l2, %o3
a00b13f0:  93 32 e0 01  srl  %o3, 1, %o1
a00b13f4:  b2 04 80 09  add  %l2, %o1, %i1
a00b13f8:  83 36 60 02  srl  %i1, 2, %g1
a00b13fc:  95 28 60 03  sll  %g1, 3, %o2
a00b1400:  9a 22 80 01  sub  %o2, %g1, %o5
a00b1404:  9e 22 00 0d  sub  %o0, %o5, %o7
a00b1408:  90 0b e0 ff  and  %o7, 0xff, %o0
a00b140c:  7f ff e0 91  call  0xa00a9650
a00b1410:  92 10 20 00  clr  %o1
a00b1414:  d0 0c 21 81  ldub  [ %l0 + 0x181 ], %o0
a00b1418:  40 00 15 dc  call  0xa00b6b88
a00b141c:  92 10 20 00  clr  %o1
a00b1420:  a4 0a 20 ff  and  %o0, 0xff, %l2
a00b1424:  80 54 80 11  umul  %l2, %l1, %g0
a00b1428:  99 40 00 00  rd  %y, %o4
a00b142c:  b0 24 80 0c  sub  %l2, %o4, %i0
a00b1430:  a7 36 20 01  srl  %i0, 1, %l3
a00b1434:  96 03 00 13  add  %o4, %l3, %o3
a00b1438:  93 32 e0 02  srl  %o3, 2, %o1
a00b143c:  a1 2a 60 03  sll  %o1, 3, %l0
a00b1440:  a2 24 00 09  sub  %l0, %o1, %l1
a00b1444:  b2 24 80 11  sub  %l2, %l1, %i1
a00b1448:  90 0e 60 ff  and  %i1, 0xff, %o0
a00b144c:  7f ff e0 81  call  0xa00a9650
a00b1450:  92 10 20 01  mov  1, %o1
a00b1454:  30 bf ff 1a  b,a   0xa00b10bc
a00b1458:  40 00 0b 3b  call  0xa00b4144
a00b145c:  92 10 20 01  mov  1, %o1
a00b1460:  90 10 20 01  mov  1, %o0
a00b1464:  40 00 0b 38  call  0xa00b4144
a00b1468:  92 10 20 02  mov  2, %o1
a00b146c:  90 10 20 00  clr  %o0
a00b1470:  7f ff ee ef  call  0xa00ad02c
a00b1474:  92 10 20 00  clr  %o1
a00b1478:  40 00 13 41  call  0xa00b617c
a00b147c:  01 00 00 00  nop
a00b1480:  80 8e 60 ff  btst  0xff, %i1
a00b1484:  02 80 00 58  be  0xa00b15e4
a00b1488:  90 10 20 00  clr  %o0
a00b148c:  7f ff de e0  call  0xa00a900c
a00b1490:  92 10 20 02  mov  2, %o1
a00b1494:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00b1498:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a00b149c:  d0 0c 21 82  ldub  [ %l0 + 0x182 ], %o0
a00b14a0:  7f ff e0 6c  call  0xa00a9650
a00b14a4:  92 10 20 00  clr  %o1
a00b14a8:  d0 0c 21 82  ldub  [ %l0 + 0x182 ], %o0
a00b14ac:  7f ff e0 69  call  0xa00a9650
a00b14b0:  92 10 20 01  mov  1, %o1
a00b14b4:  da 0c 21 82  ldub  [ %l0 + 0x182 ], %o5
a00b14b8:  82 03 40 0d  add  %o5, %o5, %g1
a00b14bc:  80 a3 60 06  cmp  %o5, 6
a00b14c0:  08 80 00 04  bleu  0xa00b14d0
a00b14c4:  82 00 60 06  add  %g1, 6, %g1
a00b14c8:  92 03 40 0d  add  %o5, %o5, %o1
a00b14cc:  82 02 7f f8  add  %o1, -8, %g1
a00b14d0:  a2 08 60 ff  and  %g1, 0xff, %l1
a00b14d4:  94 10 00 11  mov  %l1, %o2
a00b14d8:  90 10 20 00  clr  %o0
a00b14dc:  92 10 20 28  mov  0x28, %o1
a00b14e0:  96 10 20 01  mov  1, %o3
a00b14e4:  98 10 20 00  clr  %o4
a00b14e8:  40 02 55 8e  call  0xa0146b20
a00b14ec:  9a 10 20 00  clr  %o5
a00b14f0:  94 10 00 11  mov  %l1, %o2
a00b14f4:  90 10 20 00  clr  %o0
a00b14f8:  92 10 20 29  mov  0x29, %o1
a00b14fc:  96 10 20 01  mov  1, %o3
a00b1500:  10 80 00 33  b  0xa00b15cc
a00b1504:  98 10 20 00  clr  %o4
a00b1508:  7f ff de c1  call  0xa00a900c
a00b150c:  92 10 20 01  mov  1, %o1
a00b1510:  92 10 20 00  clr  %o1
a00b1514:  40 00 15 9d  call  0xa00b6b88
a00b1518:  d0 0c a1 81  ldub  [ %l2 + 0x181 ], %o0
a00b151c:  92 0a 20 ff  and  %o0, 0xff, %o1
a00b1520:  80 52 40 11  umul  %o1, %l1, %g0
a00b1524:  b1 40 00 00  rd  %y, %i0
a00b1528:  94 22 40 18  sub  %o1, %i0, %o2
a00b152c:  9f 32 a0 01  srl  %o2, 1, %o7
a00b1530:  a6 06 00 0f  add  %i0, %o7, %l3
a00b1534:  99 34 e0 02  srl  %l3, 2, %o4
a00b1538:  a1 2b 20 03  sll  %o4, 3, %l0
a00b153c:  96 24 00 0c  sub  %l0, %o4, %o3
a00b1540:  90 22 40 0b  sub  %o1, %o3, %o0
a00b1544:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b1548:  7f ff e0 42  call  0xa00a9650
a00b154c:  92 10 20 02  mov  2, %o1
a00b1550:  d0 0c a1 81  ldub  [ %l2 + 0x181 ], %o0
a00b1554:  40 00 15 8d  call  0xa00b6b88
a00b1558:  92 10 20 00  clr  %o1
a00b155c:  98 0a 20 ff  and  %o0, 0xff, %o4
a00b1560:  80 53 00 11  umul  %o4, %l1, %g0
a00b1564:  83 40 00 00  rd  %y, %g1
a00b1568:  b2 23 00 01  sub  %o4, %g1, %i1
a00b156c:  9b 36 60 01  srl  %i1, 1, %o5
a00b1570:  94 00 40 0d  add  %g1, %o5, %o2
a00b1574:  9f 32 a0 02  srl  %o2, 2, %o7
a00b1578:  b1 2b e0 03  sll  %o7, 3, %i0
a00b157c:  a6 26 00 0f  sub  %i0, %o7, %l3
a00b1580:  a0 23 00 13  sub  %o4, %l3, %l0
a00b1584:  90 0c 20 ff  and  %l0, 0xff, %o0
a00b1588:  a2 02 00 08  add  %o0, %o0, %l1
a00b158c:  80 a2 20 06  cmp  %o0, 6
a00b1590:  18 80 00 2e  bgu  0xa00b1648
a00b1594:  82 04 60 06  add  %l1, 6, %g1
a00b1598:  a4 08 60 ff  and  %g1, 0xff, %l2
a00b159c:  94 10 00 12  mov  %l2, %o2
a00b15a0:  90 10 20 00  clr  %o0
a00b15a4:  92 10 20 28  mov  0x28, %o1
a00b15a8:  96 10 20 01  mov  1, %o3
a00b15ac:  98 10 20 0f  mov  0xf, %o4
a00b15b0:  40 02 55 5c  call  0xa0146b20
a00b15b4:  9a 10 20 00  clr  %o5
a00b15b8:  94 10 00 12  mov  %l2, %o2
a00b15bc:  90 10 20 00  clr  %o0
a00b15c0:  92 10 20 29  mov  0x29, %o1
a00b15c4:  96 10 20 01  mov  1, %o3
a00b15c8:  98 10 20 10  mov  0x10, %o4
a00b15cc:  40 02 55 55  call  0xa0146b20
a00b15d0:  9a 10 20 00  clr  %o5
a00b15d4:  40 00 8c 6b  call  0xa00d4780
a00b15d8:  b0 10 20 01  mov  1, %i0
a00b15dc:  40 02 55 f9  call  0xa0146dc0
a00b15e0:  93 e8 20 00  restore  %g0, 0, %o1
a00b15e4:  7f ff de 8a  call  0xa00a900c
a00b15e8:  92 10 20 01  mov  1, %o1
a00b15ec:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00b15f0:  a4 12 e2 90  or  %o3, 0x290, %l2	! 0xa802d290
a00b15f4:  d0 0c a1 82  ldub  [ %l2 + 0x182 ], %o0
a00b15f8:  7f ff e0 16  call  0xa00a9650
a00b15fc:  92 10 20 02  mov  2, %o1
a00b1600:  da 0c a1 82  ldub  [ %l2 + 0x182 ], %o5
a00b1604:  94 03 40 0d  add  %o5, %o5, %o2
a00b1608:  80 a3 60 06  cmp  %o5, 6
a00b160c:  08 bf ff e3  bleu  0xa00b1598
a00b1610:  82 02 a0 06  add  %o2, 6, %g1
a00b1614:  82 03 40 0d  add  %o5, %o5, %g1
a00b1618:  10 bf ff e0  b  0xa00b1598
a00b161c:  82 00 7f f8  add  %g1, -8, %g1
a00b1620:  10 bf fe d0  b  0xa00b1160
a00b1624:  a4 10 20 7c  mov  0x7c, %l2
a00b1628:  10 bf fe ce  b  0xa00b1160
a00b162c:  a4 10 20 64  mov  0x64, %l2
a00b1630:  92 02 c0 0b  add  %o3, %o3, %o1
a00b1634:  90 02 40 0b  add  %o1, %o3, %o0
a00b1638:  10 bf fe ca  b  0xa00b1160
a00b163c:  a4 02 20 52  add  %o0, 0x52, %l2
a00b1640:  10 bf fe c8  b  0xa00b1160
a00b1644:  a4 10 20 49  mov  0x49, %l2
a00b1648:  82 02 00 08  add  %o0, %o0, %g1
a00b164c:  10 bf ff d3  b  0xa00b1598
a00b1650:  82 00 7f f8  add  %g1, -8, %g1
