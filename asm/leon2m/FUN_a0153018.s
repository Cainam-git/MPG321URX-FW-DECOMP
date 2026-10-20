# leon2m FUN_a0153018 0xa0153018-0xa015373c (1828 bytes)
a0153018:  9d e3 bf 98  save  %sp, -104, %sp
a015301c:  67 fc f1 4d  call  0x4008f550
a0153020:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a0153024:  7f ff be 3b  call  0xa0142910
a0153028:  01 00 00 00  nop
a015302c:  7f ff 5a 2b  call  0xa01298d8
a0153030:  01 00 00 00  nop
a0153034:  7f ff ab 0e  call  0xa013dc6c
a0153038:  01 00 00 00  nop
a015303c:  7f ff 79 37  call  0xa0131518
a0153040:  01 00 00 00  nop
a0153044:  7f ff b8 e3  call  0xa01413d0
a0153048:  01 00 00 00  nop
a015304c:  67 fc e9 52  call  0x4008d594
a0153050:  d0 14 23 94  lduh  [ %l0 + 0x394 ], %o0
a0153054:  83 2a 20 10  sll  %o0, 0x10, %g1
a0153058:  91 30 60 10  srl  %g1, 0x10, %o0
a015305c:  80 a2 20 c8  cmp  %o0, 0xc8
a0153060:  18 80 01 1c  bgu  0xa01534d0
a0153064:  01 00 00 00  nop
a0153068:  a0 10 20 00  clr  %l0	! 0x0
a015306c:  b0 10 20 00  clr  %i0
a0153070:  82 10 20 00  clr  %g1
a0153074:  7f ff a7 7e  call  0xa013ce6c
a0153078:  90 10 00 01  mov  %g1, %o0
a015307c:  b0 06 20 01  inc  %i0
a0153080:  94 0a 20 ff  and  %o0, 0xff, %o2
a0153084:  80 a2 a0 0c  cmp  %o2, 0xc
a0153088:  02 80 00 86  be  0xa01532a0
a015308c:  82 0e 20 ff  and  %i0, 0xff, %g1
a0153090:  80 a0 60 03  cmp  %g1, 3
a0153094:  08 bf ff f8  bleu  0xa0153074
a0153098:  80 8c 20 ff  btst  0xff, %l0
a015309c:  12 80 00 85  bne  0xa01532b0
a01530a0:  01 00 00 00  nop
a01530a4:  7f ff b6 84  call  0xa0140ab4
a01530a8:  01 00 00 00  nop
a01530ac:  7f ff a1 cd  call  0xa013b7e0
a01530b0:  90 10 20 00  clr  %o0	! 0x0
a01530b4:  97 2a 20 10  sll  %o0, 0x10, %o3
a01530b8:  80 a2 e0 00  cmp  %o3, 0
a01530bc:  02 80 00 87  be  0xa01532d8
a01530c0:  01 00 00 00  nop
a01530c4:  7f ff 91 a4  call  0xa0137754
a01530c8:  a4 10 3f ff  mov  -1, %l2	! 0xffffffff
a01530cc:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a01530d0:  f0 0b 63 96  ldub  [ %o5 + 0x396 ], %i0	! 0xa802cf96
a01530d4:  a6 0a 20 ff  and  %o0, 0xff, %l3
a01530d8:  80 a6 00 13  cmp  %i0, %l3
a01530dc:  02 80 00 06  be  0xa01530f4
a01530e0:  1f 00 06 9d  sethi  %hi(0x1a7400), %o7
a01530e4:  d0 2b 63 96  stb  %o0, [ %o5 + 0x396 ]
a01530e8:  7f ff 91 a5  call  0xa013777c
a01530ec:  90 10 00 13  mov  %l3, %o0
a01530f0:  1f 00 06 9d  sethi  %hi(0x1a7400), %o7
a01530f4:  a8 13 e0 a6  or  %o7, 0xa6, %l4	! 0x1a74a6
a01530f8:  91 34 e0 02  srl  %l3, 2, %o0
a01530fc:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0153100:  aa 12 e1 16  or  %o3, 0x116, %l5	! 0xa802e116
a0153104:  ac 0a 20 01  and  %o0, 1, %l6
a0153108:  a2 10 20 00  clr  %l1
a015310c:  b0 10 20 00  clr  %i0
a0153110:  10 80 00 14  b  0xa0153160
a0153114:  ae 10 00 14  mov  %l4, %l7
a0153118:  22 80 00 5c  be,a   0xa0153288
a015311c:  e4 0d 60 10  ldub  [ %l5 + 0x10 ], %l2
a0153120:  90 0c a0 ff  and  %l2, 0xff, %o0
a0153124:  80 a2 20 ff  cmp  %o0, 0xff
a0153128:  22 80 00 0a  be,a   0xa0153150
a015312c:  a2 04 60 01  inc  %l1
a0153130:  7f ff 47 45  call  0xa0124e44
a0153134:  01 00 00 00  nop
a0153138:  80 8a 20 ff  btst  0xff, %o0
a015313c:  02 80 00 1e  be  0xa01531b4
a0153140:  80 8c 20 ff  btst  0xff, %l0
a0153144:  32 80 00 4c  bne,a   0xa0153274
a0153148:  a0 06 00 18  add  %i0, %i0, %l0
a015314c:  a2 04 60 01  inc  %l1
a0153150:  b0 0c 60 ff  and  %l1, 0xff, %i0
a0153154:  80 a6 20 03  cmp  %i0, 3
a0153158:  18 80 00 29  bgu  0xa01531fc
a015315c:  1b 2a 00 b7  sethi  %hi(0xa802dc00), %o5
a0153160:  82 06 00 18  add  %i0, %i0, %g1
a0153164:  c2 0d 00 01  ldub  [ %l4 + %g1 ], %g1
a0153168:  80 a0 60 08  cmp  %g1, 8
a015316c:  02 80 00 0e  be  0xa01531a4
a0153170:  a0 10 20 00  clr  %l0
a0153174:  80 a0 60 08  cmp  %g1, 8
a0153178:  04 bf ff e8  ble  0xa0153118
a015317c:  80 a0 60 04  cmp  %g1, 4
a0153180:  80 a0 60 10  cmp  %g1, 0x10
a0153184:  02 80 00 43  be  0xa0153290
a0153188:  80 a0 60 20  cmp  %g1, 0x20
a015318c:  12 bf ff e6  bne  0xa0153124
a0153190:  90 0c a0 ff  and  %l2, 0xff, %o0
a0153194:  a5 34 e0 05  srl  %l3, 5, %l2
a0153198:  a0 0c a0 01  and  %l2, 1, %l0
a015319c:  10 bf ff e1  b  0xa0153120
a01531a0:  e4 0d 60 46  ldub  [ %l5 + 0x46 ], %l2
a01531a4:  93 34 e0 03  srl  %l3, 3, %o1
a01531a8:  a0 0a 60 01  and  %o1, 1, %l0
a01531ac:  10 bf ff dd  b  0xa0153120
a01531b0:  e4 0d 60 22  ldub  [ %l5 + 0x22 ], %l2
a01531b4:  b0 06 00 18  add  %i0, %i0, %i0
a01531b8:  94 06 00 17  add  %i0, %l7, %o2
a01531bc:  7f ff a1 89  call  0xa013b7e0
a01531c0:  d0 0a a0 01  ldub  [ %o2 + 1 ], %o0
a01531c4:  99 2a 20 10  sll  %o0, 0x10, %o4
a01531c8:  80 a3 20 00  cmp  %o4, 0
a01531cc:  12 bf ff e1  bne  0xa0153150
a01531d0:  a2 04 60 01  inc  %l1
a01531d4:  80 8c 20 ff  btst  0xff, %l0
a01531d8:  12 bf ff de  bne  0xa0153150
a01531dc:  01 00 00 00  nop
a01531e0:  7f ff f9 fe  call  0xa01519d8
a01531e4:  d0 0d c0 18  ldub  [ %l7 + %i0 ], %o0
a01531e8:  b0 0c 60 ff  and  %l1, 0xff, %i0
a01531ec:  80 a6 20 03  cmp  %i0, 3
a01531f0:  08 bf ff dd  bleu  0xa0153164
a01531f4:  82 06 00 18  add  %i0, %i0, %g1
a01531f8:  1b 2a 00 b7  sethi  %hi(0xa802dc00), %o5
a01531fc:  d2 03 63 30  ld  [ %o5 + 0x330 ], %o1	! 0xa802df30
a0153200:  83 32 60 0c  srl  %o1, 0xc, %g1
a0153204:  9e 08 60 0f  and  %g1, 0xf, %o7
a0153208:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a015320c:  90 12 e2 24  or  %o3, 0x224, %o0	! 0xa802e224
a0153210:  b0 5b e0 2a  smul  %o7, 0x2a, %i0
a0153214:  ae 06 00 08  add  %i0, %o0, %l7
a0153218:  2d 33 33 33  sethi  %hi(0xcccccc00), %l6
a015321c:  ea 15 e0 20  lduh  [ %l7 + 0x20 ], %l5
a0153220:  a0 15 a0 cd  or  %l6, 0xcd, %l0
a0153224:  80 55 40 10  umul  %l5, %l0, %g0
a0153228:  a9 40 00 00  rd  %y, %l4
a015322c:  a7 2d 20 0d  sll  %l4, 0xd, %l3
a0153230:  7f ff f4 06  call  0xa0150248
a0153234:  91 34 e0 10  srl  %l3, 0x10, %o0
a0153238:  67 fc e3 d7  call  0x4008c194
a015323c:  90 10 20 01  mov  1, %o0
a0153240:  a2 0a 20 ff  and  %o0, 0xff, %l1
a0153244:  80 a4 60 55  cmp  %l1, 0x55
a0153248:  02 80 00 d7  be  0xa01535a4
a015324c:  01 00 00 00  nop
a0153250:  7f ff e8 e9  call  0xa014d5f4
a0153254:  25 00 08 00  sethi  %hi(0x200000), %l2
a0153258:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a015325c:  d8 02 a3 d0  ld  [ %o2 + 0x3d0 ], %o4	! 0xa802e3d0
a0153260:  80 8b 00 12  btst  %o4, %l2
a0153264:  12 80 00 b4  bne  0xa0153534
a0153268:  01 00 00 00  nop
a015326c:  40 00 04 c5  call  0xa0154580
a0153270:  81 e8 00 00  restore
a0153274:  d0 0d 00 10  ldub  [ %l4 + %l0 ], %o0
a0153278:  7f ff fa 0b  call  0xa0151aa4
a015327c:  92 10 20 01  mov  1, %o1
a0153280:  10 bf ff b4  b  0xa0153150
a0153284:  a2 04 60 01  inc  %l1
a0153288:  10 bf ff a6  b  0xa0153120
a015328c:  a0 10 00 16  mov  %l6, %l0
a0153290:  9b 34 e0 04  srl  %l3, 4, %o5
a0153294:  a0 0b 60 01  and  %o5, 1, %l0
a0153298:  10 bf ff a2  b  0xa0153120
a015329c:  e4 0d 60 34  ldub  [ %l5 + 0x34 ], %l2
a01532a0:  a0 10 20 01  mov  1, %l0
a01532a4:  80 8c 20 ff  btst  0xff, %l0
a01532a8:  02 bf ff 7f  be  0xa01530a4
a01532ac:  01 00 00 00  nop
a01532b0:  7f ff 5d 31  call  0xa012a774
a01532b4:  90 10 20 00  clr  %o0	! 0x0
a01532b8:  7f ff b5 ff  call  0xa0140ab4
a01532bc:  01 00 00 00  nop
a01532c0:  7f ff a1 48  call  0xa013b7e0
a01532c4:  90 10 20 00  clr  %o0	! 0x0
a01532c8:  97 2a 20 10  sll  %o0, 0x10, %o3
a01532cc:  80 a2 e0 00  cmp  %o3, 0
a01532d0:  12 bf ff 7d  bne  0xa01530c4
a01532d4:  01 00 00 00  nop
a01532d8:  7f ff 45 54  call  0xa0124828
a01532dc:  01 00 00 00  nop
a01532e0:  80 8a 20 ff  btst  0xff, %o0
a01532e4:  02 bf ff 78  be  0xa01530c4
a01532e8:  19 00 00 13  sethi  %hi(0x4c00), %o4
a01532ec:  92 13 22 20  or  %o4, 0x220, %o1	! 0x4e20
a01532f0:  7f ff a1 19  call  0xa013b754
a01532f4:  90 10 20 00  clr  %o0
a01532f8:  7f ff 51 8d  call  0xa012792c
a01532fc:  01 00 00 00  nop
a0153300:  80 8a 20 ff  btst  0xff, %o0
a0153304:  02 80 00 b1  be  0xa01535c8
a0153308:  01 00 00 00  nop
a015330c:  7f ff 51 88  call  0xa012792c
a0153310:  01 00 00 00  nop
a0153314:  80 8a 20 ff  btst  0xff, %o0
a0153318:  12 bf ff 6b  bne  0xa01530c4
a015331c:  01 00 00 00  nop
a0153320:  7f ff 51 89  call  0xa0127944
a0153324:  01 00 00 00  nop
a0153328:  80 8a 20 ff  btst  0xff, %o0
a015332c:  12 bf ff 66  bne  0xa01530c4
a0153330:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a0153334:  d6 0a 63 91  ldub  [ %o1 + 0x391 ], %o3	! 0xa802cf91
a0153338:  82 02 e0 01  add  %o3, 1, %g1
a015333c:  90 08 60 ff  and  %g1, 0xff, %o0
a0153340:  80 a2 20 03  cmp  %o0, 3
a0153344:  28 bf ff 60  bleu,a   0xa01530c4
a0153348:  c2 2a 63 91  stb  %g1, [ %o1 + 0x391 ]
a015334c:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a0153350:  96 14 21 a0  or  %l0, 0x1a0, %o3	! 0xa802e1a0
a0153354:  ea 0a e0 0f  ldub  [ %o3 + 0xf ], %l5
a0153358:  e8 0a e0 10  ldub  [ %o3 + 0x10 ], %l4
a015335c:  94 05 60 01  add  %l5, 1, %o2
a0153360:  a4 05 20 01  add  %l4, 1, %l2
a0153364:  a2 0a a0 ff  and  %o2, 0xff, %l1
a0153368:  a6 10 20 01  mov  1, %l3
a015336c:  e6 2a 63 91  stb  %l3, [ %o1 + 0x391 ]
a0153370:  80 a4 60 3b  cmp  %l1, 0x3b
a0153374:  08 80 00 bf  bleu  0xa0153670
a0153378:  e4 2a e0 10  stb  %l2, [ %o3 + 0x10 ]
a015337c:  d4 02 e0 10  ld  [ %o3 + 0x10 ], %o2
a0153380:  99 32 a0 08  srl  %o2, 8, %o4
a0153384:  83 2b 20 10  sll  %o4, 0x10, %g1
a0153388:  31 00 00 3f  sethi  %hi(0xfc00), %i0
a015338c:  af 30 60 10  srl  %g1, 0x10, %l7
a0153390:  ac 16 23 ff  or  %i0, 0x3ff, %l6
a0153394:  80 a5 c0 16  cmp  %l7, %l6
a0153398:  02 80 00 0f  be  0xa01533d4
a015339c:  c0 2a e0 0f  clrb  [ %o3 + 0xf ]
a01533a0:  a6 03 20 01  add  %o4, 1, %l3
a01533a4:  25 3f c0 00  sethi  %hi(0xff000000), %l2
a01533a8:  91 2c e0 10  sll  %l3, 0x10, %o0
a01533ac:  a2 14 a0 ff  or  %l2, 0xff, %l1
a01533b0:  9e 0a 80 11  and  %o2, %l1, %o7
a01533b4:  9b 32 20 08  srl  %o0, 8, %o5
a01533b8:  98 13 c0 0d  or  %o7, %o5, %o4
a01533bc:  93 2b 20 08  sll  %o4, 8, %o1
a01533c0:  15 00 06 9d  sethi  %hi(0x1a7400), %o2
a01533c4:  d8 22 e0 10  st  %o4, [ %o3 + 0x10 ]
a01533c8:  90 12 a1 c0  or  %o2, 0x1c0, %o0
a01533cc:  7f fe 2f 69  call  0xa00df170
a01533d0:  93 32 60 10  srl  %o1, 0x10, %o1
a01533d4:  94 14 21 a0  or  %l0, 0x1a0, %o2
a01533d8:  d6 0a a0 10  ldub  [ %o2 + 0x10 ], %o3
a01533dc:  80 a2 e0 3b  cmp  %o3, 0x3b
a01533e0:  08 80 00 1e  bleu  0xa0153458
a01533e4:  2b 00 00 3f  sethi  %hi(0xfc00), %l5
a01533e8:  c0 2a a0 10  clrb  [ %o2 + 0x10 ]
a01533ec:  d6 02 a0 10  ld  [ %o2 + 0x10 ], %o3
a01533f0:  b0 0a e0 ff  and  %o3, 0xff, %i0
a01533f4:  d2 02 a0 14  ld  [ %o2 + 0x14 ], %o1
a01533f8:  af 2e 20 08  sll  %i0, 8, %l7
a01533fc:  ad 32 60 18  srl  %o1, 0x18, %l6
a0153400:  98 15 80 17  or  %l6, %l7, %o4
a0153404:  a8 15 63 ff  or  %l5, 0x3ff, %l4
a0153408:  80 a3 00 14  cmp  %o4, %l4
a015340c:  02 80 00 13  be  0xa0153458
a0153410:  ac 03 20 01  add  %o4, 1, %l6
a0153414:  a7 2d a0 10  sll  %l6, 0x10, %l3
a0153418:  96 0a ff 00  and  %o3, -256, %o3
a015341c:  ab 34 e0 18  srl  %l3, 0x18, %l5
a0153420:  29 3f c0 00  sethi  %hi(0xff000000), %l4
a0153424:  9e 12 c0 15  or  %o3, %l5, %o7
a0153428:  a2 2a 40 14  andn  %o1, %l4, %l1
a015342c:  a5 2c e0 08  sll  %l3, 8, %l2
a0153430:  9a 14 40 12  or  %l1, %l2, %o5
a0153434:  90 0b e0 ff  and  %o7, 0xff, %o0
a0153438:  93 2a 20 08  sll  %o0, 8, %o1
a015343c:  99 33 60 18  srl  %o5, 0x18, %o4
a0153440:  03 00 06 9d  sethi  %hi(0x1a7400), %g1
a0153444:  da 22 a0 14  st  %o5, [ %o2 + 0x14 ]
a0153448:  92 13 00 09  or  %o4, %o1, %o1
a015344c:  de 22 a0 10  st  %o7, [ %o2 + 0x10 ]
a0153450:  7f fe 2f 48  call  0xa00df170
a0153454:  90 10 61 d8  or  %g1, 0x1d8, %o0
a0153458:  7f ff 51 98  call  0xa0127ab8
a015345c:  01 00 00 00  nop
a0153460:  80 8a 20 ff  btst  0xff, %o0
a0153464:  02 80 00 85  be  0xa0153678
a0153468:  90 14 21 a0  or  %l0, 0x1a0, %o0
a015346c:  13 2a aa aa  sethi  %hi(0xaaaaa800), %o1
a0153470:  d4 0a 20 0f  ldub  [ %o0 + 0xf ], %o2
a0153474:  96 12 62 ab  or  %o1, 0x2ab, %o3
a0153478:  80 52 80 0b  umul  %o2, %o3, %g0
a015347c:  9f 40 00 00  rd  %y, %o7
a0153480:  83 33 e0 01  srl  %o7, 1, %g1
a0153484:  b0 00 40 01  add  %g1, %g1, %i0
a0153488:  ae 06 00 01  add  %i0, %g1, %l7
a015348c:  a0 22 80 17  sub  %o2, %l7, %l0
a0153490:  80 8c 20 ff  btst  0xff, %l0
a0153494:  02 80 00 0c  be  0xa01534c4
a0153498:  01 00 00 00  nop
a015349c:  d8 0a 20 10  ldub  [ %o0 + 0x10 ], %o4
a01534a0:  80 53 00 0b  umul  %o4, %o3, %g0
a01534a4:  a5 40 00 00  rd  %y, %l2
a01534a8:  9b 34 a0 01  srl  %l2, 1, %o5
a01534ac:  a2 03 40 0d  add  %o5, %o5, %l1
a01534b0:  82 04 40 0d  add  %l1, %o5, %g1
a01534b4:  ae 23 00 01  sub  %o4, %g1, %l7
a01534b8:  80 8d e0 ff  btst  0xff, %l7
a01534bc:  12 bf ff 02  bne  0xa01530c4
a01534c0:  01 00 00 00  nop
a01534c4:  40 00 01 2b  call  0xa0153970
a01534c8:  92 10 20 00  clr  %o1	! 0x0
a01534cc:  30 bf fe fe  b,a   0xa01530c4
a01534d0:  67 fc e8 2e  call  0x4008d588
a01534d4:  01 00 00 00  nop
a01534d8:  d0 34 23 94  sth  %o0, [ %l0 + 0x394 ]
a01534dc:  7f ff 19 24  call  0xa011996c
a01534e0:  90 10 20 00  clr  %o0
a01534e4:  80 8a 20 ff  btst  0xff, %o0
a01534e8:  02 80 00 0c  be  0xa0153518
a01534ec:  a0 10 20 00  clr  %l0
a01534f0:  a0 10 3f ff  mov  -1, %l0
a01534f4:  23 2a 00 a9  sethi  %hi(0xa802a400), %l1
a01534f8:  d2 04 60 bc  ld  [ %l1 + 0xbc ], %o1	! 0xa802a4bc
a01534fc:  80 a4 00 09  cmp  %l0, %o1
a0153500:  22 bf fe da  be,a   0xa0153068
a0153504:  e0 24 60 bc  st  %l0, [ %l1 + 0xbc ]
a0153508:  7f ff 9c 88  call  0xa013a728
a015350c:  90 10 00 10  mov  %l0, %o0
a0153510:  10 bf fe d6  b  0xa0153068
a0153514:  e0 24 60 bc  st  %l0, [ %l1 + 0xbc ]
a0153518:  7f ff 19 15  call  0xa011996c
a015351c:  90 10 20 01  mov  1, %o0
a0153520:  80 8a 20 ff  btst  0xff, %o0
a0153524:  02 bf ff f5  be  0xa01534f8
a0153528:  23 2a 00 a9  sethi  %hi(0xa802a400), %l1
a015352c:  10 bf ff f3  b  0xa01534f8
a0153530:  a0 10 3f ff  mov  -1, %l0
a0153534:  7f ff a6 4e  call  0xa013ce6c
a0153538:  90 10 20 00  clr  %o0
a015353c:  a2 0a 20 ff  and  %o0, 0xff, %l1
a0153540:  80 a4 60 0c  cmp  %l1, 0xc
a0153544:  12 bf ff 4a  bne  0xa015326c
a0153548:  01 00 00 00  nop
a015354c:  7f ff a6 48  call  0xa013ce6c
a0153550:  90 10 20 03  mov  3, %o0	! 0x3
a0153554:  a6 0a 20 ff  and  %o0, 0xff, %l3
a0153558:  80 a4 e0 0c  cmp  %l3, 0xc
a015355c:  12 bf ff 44  bne  0xa015326c
a0153560:  01 00 00 00  nop
a0153564:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a0153568:  d6 0c 63 97  ldub  [ %l1 + 0x397 ], %o3	! 0xa802cf97
a015356c:  a8 0a e0 ff  and  %o3, 0xff, %l4
a0153570:  80 55 00 10  umul  %l4, %l0, %g0
a0153574:  91 40 00 00  rd  %y, %o0
a0153578:  b1 32 20 04  srl  %o0, 4, %i0
a015357c:  af 2e 20 02  sll  %i0, 2, %l7
a0153580:  ac 05 c0 18  add  %l7, %i0, %l6
a0153584:  ab 2d a0 02  sll  %l6, 2, %l5
a0153588:  a0 25 00 15  sub  %l4, %l5, %l0
a015358c:  80 8c 20 ff  btst  0xff, %l0
a0153590:  02 80 00 08  be  0xa01535b0
a0153594:  9e 02 e0 01  add  %o3, 1, %o7
a0153598:  de 2c 63 97  stb  %o7, [ %l1 + 0x397 ]
a015359c:  40 00 03 f9  call  0xa0154580
a01535a0:  81 e8 00 00  restore
a01535a4:  67 fc f1 24  call  0x4008fa34
a01535a8:  01 00 00 00  nop
a01535ac:  30 bf ff 29  b,a   0xa0153250
a01535b0:  7f ff f6 12  call  0xa0150df8
a01535b4:  01 00 00 00  nop
a01535b8:  d6 0c 63 97  ldub  [ %l1 + 0x397 ], %o3
a01535bc:  9e 02 e0 01  add  %o3, 1, %o7
a01535c0:  10 bf ff f7  b  0xa015359c
a01535c4:  de 2c 63 97  stb  %o7, [ %l1 + 0x397 ]
a01535c8:  7f ff 50 df  call  0xa0127944
a01535cc:  01 00 00 00  nop
a01535d0:  80 8a 20 ff  btst  0xff, %o0
a01535d4:  12 bf ff 4e  bne  0xa015330c
a01535d8:  17 2a 00 b3  sethi  %hi(0xa802cc00), %o3
a01535dc:  de 0a e3 92  ldub  [ %o3 + 0x392 ], %o7	! 0xa802cf92
a01535e0:  82 03 e0 01  add  %o7, 1, %g1
a01535e4:  9a 08 60 ff  and  %g1, 0xff, %o5
a01535e8:  80 a3 60 03  cmp  %o5, 3
a01535ec:  28 bf ff 48  bleu,a   0xa015330c
a01535f0:  c2 2a e3 92  stb  %g1, [ %o3 + 0x392 ]
a01535f4:  27 2a 00 b8  sethi  %hi(0xa802e000), %l3
a01535f8:  90 14 e1 a0  or  %l3, 0x1a0, %o0	! 0xa802e1a0
a01535fc:  e4 0a 20 08  ldub  [ %o0 + 8 ], %l2
a0153600:  9a 04 a0 01  add  %l2, 1, %o5
a0153604:  a0 0b 60 ff  and  %o5, 0xff, %l0
a0153608:  a2 10 20 01  mov  1, %l1
a015360c:  80 a4 20 3b  cmp  %l0, 0x3b
a0153610:  08 80 00 16  bleu  0xa0153668
a0153614:  e2 2a e3 92  stb  %l1, [ %o3 + 0x392 ]
a0153618:  c0 2a 20 08  clrb  [ %o0 + 8 ]
a015361c:  d6 02 20 08  ld  [ %o0 + 8 ], %o3
a0153620:  99 32 e0 08  srl  %o3, 8, %o4
a0153624:  af 2b 20 10  sll  %o4, 0x10, %l7
a0153628:  2d 00 00 3f  sethi  %hi(0xfc00), %l6
a015362c:  ab 35 e0 10  srl  %l7, 0x10, %l5
a0153630:  a8 15 a3 ff  or  %l6, 0x3ff, %l4
a0153634:  80 a5 40 14  cmp  %l5, %l4
a0153638:  02 bf ff 35  be  0xa015330c
a015363c:  9a 03 20 01  add  %o4, 1, %o5
a0153640:  1f 3f c0 00  sethi  %hi(0xff000000), %o7
a0153644:  95 2b 60 10  sll  %o5, 0x10, %o2
a0153648:  98 13 e0 ff  or  %o7, 0xff, %o4
a015364c:  93 32 a0 08  srl  %o2, 8, %o1
a0153650:  82 0a c0 0c  and  %o3, %o4, %g1
a0153654:  b0 10 40 09  or  %g1, %o1, %i0
a0153658:  f0 22 20 08  st  %i0, [ %o0 + 8 ]
a015365c:  40 00 00 c5  call  0xa0153970
a0153660:  92 10 20 00  clr  %o1
a0153664:  30 bf ff 2a  b,a   0xa015330c
a0153668:  10 bf ff 29  b  0xa015330c
a015366c:  da 2a 20 08  stb  %o5, [ %o0 + 8 ]
a0153670:  10 bf ff 59  b  0xa01533d4
a0153674:  d4 2a e0 0f  stb  %o2, [ %o3 + 0xf ]
a0153678:  7f ff c9 20  call  0xa0145af8
a015367c:  90 10 20 10  mov  0x10, %o0
a0153680:  91 2a 20 10  sll  %o0, 0x10, %o0
a0153684:  99 32 20 10  srl  %o0, 0x10, %o4
a0153688:  80 a3 20 01  cmp  %o4, 1
a015368c:  02 80 00 17  be  0xa01536e8
a0153690:  90 14 21 a0  or  %l0, 0x1a0, %o0
a0153694:  2b 22 22 22  sethi  %hi(0x88888800), %l5
a0153698:  e2 0a 20 0f  ldub  [ %o0 + 0xf ], %l1
a015369c:  96 15 60 89  or  %l5, 0x89, %o3
a01536a0:  80 54 40 0b  umul  %l1, %o3, %g0
a01536a4:  a9 40 00 00  rd  %y, %l4
a01536a8:  a7 35 20 04  srl  %l4, 4, %l3
a01536ac:  99 2c e0 04  sll  %l3, 4, %o4
a01536b0:  a4 23 00 13  sub  %o4, %l3, %l2
a01536b4:  9a 04 80 12  add  %l2, %l2, %o5
a01536b8:  92 24 40 0d  sub  %l1, %o5, %o1
a01536bc:  80 8a 60 ff  btst  0xff, %o1
a01536c0:  02 bf ff 81  be  0xa01534c4
a01536c4:  01 00 00 00  nop
a01536c8:  d8 0a 20 10  ldub  [ %o0 + 0x10 ], %o4
a01536cc:  80 53 00 0b  umul  %o4, %o3, %g0
a01536d0:  95 40 00 00  rd  %y, %o2
a01536d4:  a1 32 a0 04  srl  %o2, 4, %l0
a01536d8:  ad 2c 20 04  sll  %l0, 4, %l6
a01536dc:  82 25 80 10  sub  %l6, %l0, %g1
a01536e0:  10 bf ff 75  b  0xa01534b4
a01536e4:  82 00 40 01  add  %g1, %g1, %g1
a01536e8:  31 33 33 33  sethi  %hi(0xcccccc00), %i0
a01536ec:  e8 0a 20 0f  ldub  [ %o0 + 0xf ], %l4
a01536f0:  96 16 20 cd  or  %i0, 0xcd, %o3
a01536f4:  80 55 00 0b  umul  %l4, %o3, %g0
a01536f8:  af 40 00 00  rd  %y, %l7
a01536fc:  95 35 e0 03  srl  %l7, 3, %o2
a0153700:  a1 2a a0 02  sll  %o2, 2, %l0
a0153704:  ac 04 00 0a  add  %l0, %o2, %l6
a0153708:  aa 05 80 16  add  %l6, %l6, %l5
a015370c:  a6 25 00 15  sub  %l4, %l5, %l3
a0153710:  80 8c e0 ff  btst  0xff, %l3
a0153714:  02 bf ff 6c  be  0xa01534c4
a0153718:  01 00 00 00  nop
a015371c:  d8 0a 20 10  ldub  [ %o0 + 0x10 ], %o4
a0153720:  80 53 00 0b  umul  %o4, %o3, %g0
a0153724:  83 40 00 00  rd  %y, %g1
a0153728:  9f 30 60 03  srl  %g1, 3, %o7
a015372c:  97 2b e0 02  sll  %o7, 2, %o3
a0153730:  82 02 c0 0f  add  %o3, %o7, %g1
a0153734:  10 bf ff 60  b  0xa01534b4
a0153738:  82 00 40 01  add  %g1, %g1, %g1
