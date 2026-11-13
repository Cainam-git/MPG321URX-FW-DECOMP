# leon2m FUN_a01412b8 0xa01412b8-0xa01413d0 (280 bytes)
a01412b8:  90 0a 20 ff  and  %o0, 0xff, %o0
a01412bc:  80 a2 20 01  cmp  %o0, 1
a01412c0:  02 80 00 27  be  0xa014135c
a01412c4:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a01412c8:  80 a2 20 00  cmp  %o0, 0
a01412cc:  02 80 00 1c  be  0xa014133c
a01412d0:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a01412d4:  80 a2 20 01  cmp  %o0, 1
a01412d8:  02 80 00 29  be  0xa014137c
a01412dc:  c2 0b 61 10  ldub  [ %o5 + 0x110 ], %g1
a01412e0:  80 a2 20 00  cmp  %o0, 0
a01412e4:  12 80 00 2c  bne  0xa0141394
a01412e8:  80 a2 20 01  cmp  %o0, 1
a01412ec:  c2 0b 61 10  ldub  [ %o5 + 0x110 ], %g1
a01412f0:  80 a0 60 01  cmp  %g1, 1
a01412f4:  22 80 00 35  be,a   0xa01413c8
a01412f8:  c0 2b 20 09  clrb  [ %o4 + 9 ]
a01412fc:  c2 0b 61 10  ldub  [ %o5 + 0x110 ], %g1
a0141300:  82 00 7f fe  add  %g1, -2, %g1
a0141304:  82 08 60 ff  and  %g1, 0xff, %g1
a0141308:  80 a0 60 03  cmp  %g1, 3
a014130c:  38 80 00 25  bgu,a   0xa01413a0
a0141310:  c0 2b 20 09  clrb  [ %o4 + 9 ]
a0141314:  82 10 20 01  mov  1, %g1
a0141318:  80 a2 20 01  cmp  %o0, 1
a014131c:  12 80 00 2b  bne  0xa01413c8
a0141320:  c2 2b 20 09  stb  %g1, [ %o4 + 9 ]
a0141324:  90 13 61 10  or  %o5, 0x110, %o0
a0141328:  c2 12 20 04  lduh  [ %o0 + 4 ], %g1
a014132c:  19 3f ff e0  sethi  %hi(0xffff8000), %o4
a0141330:  9a 10 40 0c  or  %g1, %o4, %o5
a0141334:  10 80 00 25  b  0xa01413c8
a0141338:  da 32 20 04  sth  %o5, [ %o0 + 4 ]
a014133c:  c2 0b 61 10  ldub  [ %o5 + 0x110 ], %g1
a0141340:  82 00 7f f9  add  %g1, -7, %g1
a0141344:  82 08 60 ff  and  %g1, 0xff, %g1
a0141348:  80 a0 60 02  cmp  %g1, 2
a014134c:  18 bf ff e6  bgu  0xa01412e4
a0141350:  80 a2 20 00  cmp  %o0, 0
a0141354:  10 80 00 1d  b  0xa01413c8
a0141358:  c0 2b 20 09  clrb  [ %o4 + 9 ]
a014135c:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a0141360:  c2 0b 61 10  ldub  [ %o5 + 0x110 ], %g1	! 0xa802e110
a0141364:  82 00 7f fe  add  %g1, -2, %g1
a0141368:  82 08 60 ff  and  %g1, 0xff, %g1
a014136c:  80 a0 60 03  cmp  %g1, 3
a0141370:  28 80 00 16  bleu,a   0xa01413c8
a0141374:  c0 2b 20 09  clrb  [ %o4 + 9 ]
a0141378:  c2 0b 61 10  ldub  [ %o5 + 0x110 ], %g1
a014137c:  80 a0 60 06  cmp  %g1, 6
a0141380:  02 bf ff f5  be  0xa0141354
a0141384:  80 a2 20 00  cmp  %o0, 0
a0141388:  02 bf ff de  be  0xa0141300
a014138c:  c2 0b 61 10  ldub  [ %o5 + 0x110 ], %g1
a0141390:  80 a2 20 01  cmp  %o0, 1
a0141394:  02 80 00 09  be  0xa01413b8
a0141398:  c2 0b 61 10  ldub  [ %o5 + 0x110 ], %g1
a014139c:  c0 2b 20 09  clrb  [ %o4 + 9 ]
a01413a0:  80 a2 20 01  cmp  %o0, 1
a01413a4:  02 80 00 03  be  0xa01413b0
a01413a8:  82 10 20 02  mov  2, %g1
a01413ac:  82 10 20 07  mov  7, %g1
a01413b0:  10 80 00 06  b  0xa01413c8
a01413b4:  c2 2b 61 10  stb  %g1, [ %o5 + 0x110 ]
a01413b8:  82 00 7f f9  add  %g1, -7, %g1
a01413bc:  82 08 60 ff  and  %g1, 0xff, %g1
a01413c0:  10 bf ff d3  b  0xa014130c
a01413c4:  80 a0 60 02  cmp  %g1, 2
a01413c8:  81 c3 e0 08  retl
a01413cc:  01 00 00 00  nop
