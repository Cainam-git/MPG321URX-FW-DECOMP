# leon2m FUN_a00f51b4 0xa00f51b4-0xa00f557c (968 bytes)
a00f51b4:  9d e3 bf 80  save  %sp, -128, %sp
a00f51b8:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00f51bc:  80 a4 60 07  cmp  %l1, 7
a00f51c0:  18 80 00 04  bgu  0xa00f51d0
a00f51c4:  82 10 20 00  clr  %g1
a00f51c8:  83 2e 20 04  sll  %i0, 4, %g1
a00f51cc:  82 10 40 18  or  %g1, %i0, %g1
a00f51d0:  25 33 c0 80  sethi  %hi(0xcf020000), %l2
a00f51d4:  9a 08 60 ff  and  %g1, 0xff, %o5
a00f51d8:  94 14 a1 0c  or  %l2, 0x10c, %o2
a00f51dc:  da 22 80 00  st  %o5, [ %o2 ]
a00f51e0:  7f ff f9 ee  call  0xa00f3998
a00f51e4:  a0 14 a1 14  or  %l2, 0x114, %l0
a00f51e8:  7f ff f9 f1  call  0xa00f39ac
a00f51ec:  d0 2f bf e0  stb  %o0, [ %fp + -32 ]
a00f51f0:  7f ff f9 f4  call  0xa00f39c0
a00f51f4:  d0 2f bf e1  stb  %o0, [ %fp + -31 ]
a00f51f8:  d0 2f bf e2  stb  %o0, [ %fp + -30 ]
a00f51fc:  90 10 20 80  mov  0x80, %o0
a00f5200:  c0 2f bf e8  clrb  [ %fp + -24 ]
a00f5204:  c0 2f bf e9  clrb  [ %fp + -23 ]
a00f5208:  7f ff f9 c4  call  0xa00f3918
a00f520c:  c0 2f bf ea  clrb  [ %fp + -22 ]
a00f5210:  7f ff f9 c8  call  0xa00f3930
a00f5214:  90 10 20 80  mov  0x80, %o0
a00f5218:  7f ff f9 cc  call  0xa00f3948
a00f521c:  90 10 20 80  mov  0x80, %o0
a00f5220:  90 10 00 11  mov  %l1, %o0
a00f5224:  92 10 20 66  mov  0x66, %o1
a00f5228:  7f ff f2 2b  call  0xa00f1ad4
a00f522c:  94 10 20 00  clr  %o2
a00f5230:  d2 04 00 00  ld  [ %l0 ], %o1
a00f5234:  90 0a 60 07  and  %o1, 7, %o0
a00f5238:  80 a2 20 05  cmp  %o0, 5
a00f523c:  02 80 00 bf  be  0xa00f5538
a00f5240:  90 10 00 11  mov  %l1, %o0
a00f5244:  92 10 20 65  mov  0x65, %o1
a00f5248:  7f ff f2 23  call  0xa00f1ad4
a00f524c:  94 10 20 00  clr  %o2
a00f5250:  90 10 00 11  mov  %l1, %o0
a00f5254:  92 10 20 67  mov  0x67, %o1
a00f5258:  94 10 20 00  clr  %o2
a00f525c:  7f ff f2 1e  call  0xa00f1ad4
a00f5260:  a4 10 20 0a  mov  0xa, %l2
a00f5264:  90 10 00 11  mov  %l1, %o0
a00f5268:  92 10 20 63  mov  0x63, %o1
a00f526c:  7f ff f2 1a  call  0xa00f1ad4
a00f5270:  94 10 20 80  mov  0x80, %o2
a00f5274:  92 10 20 64  mov  0x64, %o1
a00f5278:  94 10 20 03  mov  3, %o2
a00f527c:  7f ff f2 16  call  0xa00f1ad4
a00f5280:  90 10 00 11  mov  %l1, %o0
a00f5284:  90 10 21 2c  mov  0x12c, %o0
a00f5288:  c0 37 bf f0  clrh  [ %fp + -16 ]
a00f528c:  c0 37 bf f2  clrh  [ %fp + -14 ]
a00f5290:  67 fe 5f c4  call  0x4008d1a0
a00f5294:  c0 37 bf f4  clrh  [ %fp + -12 ]
a00f5298:  90 10 00 11  mov  %l1, %o0
a00f529c:  92 10 20 63  mov  0x63, %o1
a00f52a0:  7f ff f2 0d  call  0xa00f1ad4
a00f52a4:  94 10 20 e0  mov  0xe0, %o2
a00f52a8:  67 fe 60 b8  call  0x4008d588
a00f52ac:  01 00 00 00  nop
a00f52b0:  17 33 33 33  sethi  %hi(0xcccccc00), %o3
a00f52b4:  b0 10 00 08  mov  %o0, %i0
a00f52b8:  10 80 00 1a  b  0xa00f5320
a00f52bc:  a6 12 e0 cd  or  %o3, 0xcd, %l3
a00f52c0:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00f52c4:  98 04 00 01  add  %l0, %g1, %o4
a00f52c8:  d6 17 bf f4  lduh  [ %fp + -12 ], %o3
a00f52cc:  94 0a 60 ff  and  %o1, 0xff, %o2
a00f52d0:  a0 02 c0 0a  add  %o3, %o2, %l0
a00f52d4:  d0 17 bf f2  lduh  [ %fp + -14 ], %o0
a00f52d8:  da 0f bf e9  ldub  [ %fp + -23 ], %o5
a00f52dc:  e0 37 bf f4  sth  %l0, [ %fp + -12 ]
a00f52e0:  a4 04 bf ff  add  %l2, -1, %l2
a00f52e4:  9e 02 00 0d  add  %o0, %o5, %o7
a00f52e8:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00f52ec:  d8 37 bf f0  sth  %o4, [ %fp + -16 ]
a00f52f0:  80 a4 20 00  cmp  %l0, 0
a00f52f4:  02 80 00 5b  be  0xa00f5460
a00f52f8:  de 37 bf f2  sth  %o7, [ %fp + -14 ]
a00f52fc:  9f 2e 20 10  sll  %i0, 0x10, %o7
a00f5300:  91 33 e0 10  srl  %o7, 0x10, %o0
a00f5304:  67 fe 60 a4  call  0x4008d594
a00f5308:  d2 2f bf ea  stb  %o1, [ %fp + -22 ]
a00f530c:  83 2a 20 10  sll  %o0, 0x10, %g1
a00f5310:  9b 30 60 10  srl  %g1, 0x10, %o5
a00f5314:  80 a3 61 2b  cmp  %o5, 0x12b
a00f5318:  18 80 00 62  bgu  0xa00f54a0
a00f531c:  90 10 00 11  mov  %l1, %o0
a00f5320:  67 fe 5f a0  call  0x4008d1a0
a00f5324:  90 10 20 14  mov  0x14, %o0
a00f5328:  40 00 b0 13  call  0xa0121374
a00f532c:  90 10 00 11  mov  %l1, %o0
a00f5330:  98 0a 20 ff  and  %o0, 0xff, %o4
a00f5334:  80 a3 20 01  cmp  %o4, 1
a00f5338:  02 80 00 59  be  0xa00f549c
a00f533c:  a0 10 20 0a  mov  0xa, %l0
a00f5340:  7f ff f9 96  call  0xa00f3998
a00f5344:  01 00 00 00  nop
a00f5348:  d4 0f bf e8  ldub  [ %fp + -24 ], %o2
a00f534c:  98 0a 20 ff  and  %o0, 0xff, %o4
a00f5350:  a0 22 80 0c  sub  %o2, %o4, %l0
a00f5354:  93 3c 20 1f  sra  %l0, 0x1f, %o1
a00f5358:  82 1a 40 10  xor  %o1, %l0, %g1
a00f535c:  9e 20 40 09  sub  %g1, %o1, %o7
a00f5360:  80 a3 e0 03  cmp  %o7, 3
a00f5364:  14 80 00 03  bg  0xa00f5370
a00f5368:  9a 10 20 01  mov  1, %o5
a00f536c:  9a 10 20 00  clr  %o5
a00f5370:  80 a3 20 e0  cmp  %o4, 0xe0
a00f5374:  18 80 00 03  bgu  0xa00f5380
a00f5378:  82 10 20 01  mov  1, %g1
a00f537c:  82 10 20 00  clr  %g1
a00f5380:  80 93 40 01  orcc  %o5, %g1, %g0
a00f5384:  32 80 00 02  bne,a   0xa00f538c
a00f5388:  a4 10 20 0a  mov  0xa, %l2
a00f538c:  7f ff f9 88  call  0xa00f39ac
a00f5390:  d0 2f bf e8  stb  %o0, [ %fp + -24 ]
a00f5394:  d2 0f bf e9  ldub  [ %fp + -23 ], %o1
a00f5398:  98 0a 20 ff  and  %o0, 0xff, %o4
a00f539c:  82 22 40 0c  sub  %o1, %o4, %g1
a00f53a0:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a00f53a4:  9e 1b 40 01  xor  %o5, %g1, %o7
a00f53a8:  96 23 c0 0d  sub  %o7, %o5, %o3
a00f53ac:  80 a2 e0 03  cmp  %o3, 3
a00f53b0:  14 80 00 03  bg  0xa00f53bc
a00f53b4:  9a 10 20 01  mov  1, %o5
a00f53b8:  9a 10 20 00  clr  %o5
a00f53bc:  80 a3 20 e0  cmp  %o4, 0xe0
a00f53c0:  18 80 00 03  bgu  0xa00f53cc
a00f53c4:  82 10 20 01  mov  1, %g1
a00f53c8:  82 10 20 00  clr  %g1
a00f53cc:  80 93 40 01  orcc  %o5, %g1, %g0
a00f53d0:  32 80 00 02  bne,a   0xa00f53d8
a00f53d4:  a4 10 20 0a  mov  0xa, %l2
a00f53d8:  7f ff f9 7a  call  0xa00f39c0
a00f53dc:  d0 2f bf e9  stb  %o0, [ %fp + -23 ]
a00f53e0:  98 0a 20 ff  and  %o0, 0xff, %o4
a00f53e4:  de 0f bf ea  ldub  [ %fp + -22 ], %o7
a00f53e8:  96 23 c0 0c  sub  %o7, %o4, %o3
a00f53ec:  95 3a e0 1f  sra  %o3, 0x1f, %o2
a00f53f0:  92 10 00 08  mov  %o0, %o1
a00f53f4:  a0 1a 80 0b  xor  %o2, %o3, %l0
a00f53f8:  90 24 00 0a  sub  %l0, %o2, %o0
a00f53fc:  80 a2 20 03  cmp  %o0, 3
a00f5400:  14 80 00 03  bg  0xa00f540c
a00f5404:  9a 10 20 01  mov  1, %o5
a00f5408:  9a 10 20 00  clr  %o5
a00f540c:  80 a3 20 e0  cmp  %o4, 0xe0
a00f5410:  18 80 00 03  bgu  0xa00f541c
a00f5414:  82 10 20 01  mov  1, %g1
a00f5418:  82 10 20 00  clr  %g1
a00f541c:  80 93 40 01  orcc  %o5, %g1, %g0
a00f5420:  32 80 00 02  bne,a   0xa00f5428
a00f5424:  a4 10 20 0a  mov  0xa, %l2
a00f5428:  98 0c a0 ff  and  %l2, 0xff, %o4
a00f542c:  80 a3 20 0a  cmp  %o4, 0xa
a00f5430:  12 bf ff a4  bne  0xa00f52c0
a00f5434:  e0 17 bf f0  lduh  [ %fp + -16 ], %l0
a00f5438:  a4 04 bf ff  add  %l2, -1, %l2
a00f543c:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00f5440:  da 0f bf e9  ldub  [ %fp + -23 ], %o5
a00f5444:  90 0a 60 ff  and  %o1, 0xff, %o0
a00f5448:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00f544c:  c2 37 bf f0  sth  %g1, [ %fp + -16 ]
a00f5450:  da 37 bf f2  sth  %o5, [ %fp + -14 ]
a00f5454:  80 a4 20 00  cmp  %l0, 0
a00f5458:  12 bf ff a9  bne  0xa00f52fc
a00f545c:  d0 37 bf f4  sth  %o0, [ %fp + -12 ]
a00f5460:  d0 17 bf f0  lduh  [ %fp + -16 ], %o0
a00f5464:  d4 17 bf f2  lduh  [ %fp + -14 ], %o2
a00f5468:  d8 17 bf f4  lduh  [ %fp + -12 ], %o4
a00f546c:  80 52 00 13  umul  %o0, %l3, %g0
a00f5470:  97 40 00 00  rd  %y, %o3
a00f5474:  80 52 80 13  umul  %o2, %l3, %g0
a00f5478:  9f 40 00 00  rd  %y, %o7
a00f547c:  80 53 00 13  umul  %o4, %l3, %g0
a00f5480:  93 40 00 00  rd  %y, %o1
a00f5484:  a5 32 e0 03  srl  %o3, 3, %l2
a00f5488:  b1 33 e0 03  srl  %o7, 3, %i0
a00f548c:  a7 32 60 03  srl  %o1, 3, %l3
a00f5490:  e4 2f bf e8  stb  %l2, [ %fp + -24 ]
a00f5494:  f0 2f bf e9  stb  %i0, [ %fp + -23 ]
a00f5498:  e6 2f bf ea  stb  %l3, [ %fp + -22 ]
a00f549c:  90 10 00 11  mov  %l1, %o0
a00f54a0:  92 10 20 63  mov  0x63, %o1
a00f54a4:  7f ff f1 8c  call  0xa00f1ad4
a00f54a8:  94 10 20 00  clr  %o2
a00f54ac:  90 10 00 11  mov  %l1, %o0
a00f54b0:  92 10 20 64  mov  0x64, %o1
a00f54b4:  7f ff f1 88  call  0xa00f1ad4
a00f54b8:  94 10 20 00  clr  %o2
a00f54bc:  80 a4 20 00  cmp  %l0, 0
a00f54c0:  12 80 00 16  bne  0xa00f5518
a00f54c4:  01 00 00 00  nop
a00f54c8:  31 33 c0 80  sethi  %hi(0xcf020000), %i0
a00f54cc:  a6 16 21 14  or  %i0, 0x114, %l3	! 0xcf020114
a00f54d0:  e0 04 c0 00  ld  [ %l3 ], %l0
a00f54d4:  a2 0c 20 07  and  %l0, 7, %l1
a00f54d8:  80 a4 60 05  cmp  %l1, 5
a00f54dc:  02 80 00 1e  be  0xa00f5554
a00f54e0:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00f54e4:  9a 00 60 04  add  %g1, 4, %o5
a00f54e8:  7f ff f9 0c  call  0xa00f3918
a00f54ec:  90 0b 60 ff  and  %o5, 0xff, %o0
a00f54f0:  d8 0f bf e9  ldub  [ %fp + -23 ], %o4
a00f54f4:  90 03 20 04  add  %o4, 4, %o0
a00f54f8:  7f ff f9 0e  call  0xa00f3930
a00f54fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f5500:  d4 0f bf ea  ldub  [ %fp + -22 ], %o2
a00f5504:  96 02 a0 04  add  %o2, 4, %o3
a00f5508:  90 0a e0 ff  and  %o3, 0xff, %o0
a00f550c:  7f ff f9 0f  call  0xa00f3948
a00f5510:  b0 10 20 01  mov  1, %i0
a00f5514:  30 80 00 18  b,a   0xa00f5574
a00f5518:  7f ff f9 00  call  0xa00f3918
a00f551c:  d0 0f bf e0  ldub  [ %fp + -32 ], %o0
a00f5520:  7f ff f9 04  call  0xa00f3930
a00f5524:  d0 0f bf e1  ldub  [ %fp + -31 ], %o0
a00f5528:  7f ff f9 08  call  0xa00f3948
a00f552c:  d0 0f bf e2  ldub  [ %fp + -30 ], %o0
a00f5530:  10 80 00 11  b  0xa00f5574
a00f5534:  b0 10 20 00  clr  %i0
a00f5538:  92 10 20 65  mov  0x65, %o1
a00f553c:  7f ff f1 66  call  0xa00f1ad4
a00f5540:  94 10 20 80  mov  0x80, %o2
a00f5544:  90 10 00 11  mov  %l1, %o0
a00f5548:  92 10 20 67  mov  0x67, %o1
a00f554c:  10 bf ff 44  b  0xa00f525c
a00f5550:  94 10 20 80  mov  0x80, %o2
a00f5554:  7f ff f8 f1  call  0xa00f3918
a00f5558:  d0 0f bf e8  ldub  [ %fp + -24 ], %o0
a00f555c:  d2 0f bf e9  ldub  [ %fp + -23 ], %o1
a00f5560:  a4 02 60 04  add  %o1, 4, %l2
a00f5564:  7f ff f8 f3  call  0xa00f3930
a00f5568:  90 0c a0 ff  and  %l2, 0xff, %o0
a00f556c:  10 bf ff e8  b  0xa00f550c
a00f5570:  d0 0f bf ea  ldub  [ %fp + -22 ], %o0
a00f5574:  81 c7 e0 08  ret
a00f5578:  81 e8 00 00  restore
