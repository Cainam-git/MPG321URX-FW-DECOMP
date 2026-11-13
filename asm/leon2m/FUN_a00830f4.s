# leon2m FUN_a00830f4 0xa00830f4-0xa00837e4 (1776 bytes)
a00830f4:  9d e3 bf 90  save  %sp, -112, %sp
a00830f8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00830fc:  c0 37 bf f4  clrh  [ %fp + -12 ]
a0083100:  c0 37 bf f0  clrh  [ %fp + -16 ]
a0083104:  c0 37 bf f6  clrh  [ %fp + -10 ]
a0083108:  80 a6 20 ff  cmp  %i0, 0xff
a008310c:  02 80 01 b4  be  0xa00837dc
a0083110:  c0 37 bf f2  clrh  [ %fp + -14 ]
a0083114:  92 10 20 0b  mov  0xb, %o1
a0083118:  40 03 09 52  call  0xa0145660
a008311c:  90 10 00 18  mov  %i0, %o0
a0083120:  d0 37 bf f4  sth  %o0, [ %fp + -12 ]
a0083124:  92 10 20 0f  mov  0xf, %o1
a0083128:  40 03 09 4e  call  0xa0145660
a008312c:  90 10 00 18  mov  %i0, %o0
a0083130:  d0 37 bf f0  sth  %o0, [ %fp + -16 ]
a0083134:  92 10 20 07  mov  7, %o1
a0083138:  40 03 09 4a  call  0xa0145660
a008313c:  90 10 00 18  mov  %i0, %o0
a0083140:  d0 37 bf f6  sth  %o0, [ %fp + -10 ]
a0083144:  90 10 00 18  mov  %i0, %o0
a0083148:  40 03 09 46  call  0xa0145660
a008314c:  92 10 20 08  mov  8, %o1
a0083150:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a0083154:  c2 04 22 90  ld  [ %l0 + 0x290 ], %g1	! 0xa802d290
a0083158:  80 88 60 20  btst  0x20, %g1
a008315c:  12 80 00 e7  bne  0xa00834f8
a0083160:  d0 37 bf f2  sth  %o0, [ %fp + -14 ]
a0083164:  80 88 60 40  btst  0x40, %g1
a0083168:  12 80 00 f4  bne  0xa0083538
a008316c:  25 19 99 99  sethi  %hi(0x66666400), %l2
a0083170:  94 14 22 90  or  %l0, 0x290, %o2
a0083174:  d8 0a a0 1f  ldub  [ %o2 + 0x1f ], %o4
a0083178:  80 a0 00 0c  cmp  %g0, %o4
a008317c:  92 60 3f ff  subx  %g0, -1, %o1
a0083180:  9a 1e 20 01  xor  %i0, 1, %o5
a0083184:  80 a0 00 0d  cmp  %g0, %o5
a0083188:  96 60 3f ff  subx  %g0, -1, %o3
a008318c:  80 8a 40 0b  btst  %o1, %o3
a0083190:  02 80 00 70  be  0xa0083350
a0083194:  80 a3 20 02  cmp  %o4, 2
a0083198:  da 0a a0 4c  ldub  [ %o2 + 0x4c ], %o5
a008319c:  80 a3 60 00  cmp  %o5, 0
a00831a0:  12 80 00 e0  bne  0xa0083520
a00831a4:  a4 10 20 0f  mov  0xf, %l2
a00831a8:  a6 14 22 90  or  %l0, 0x290, %l3
a00831ac:  c2 0c e0 4b  ldub  [ %l3 + 0x4b ], %g1
a00831b0:  80 a0 60 01  cmp  %g1, 1
a00831b4:  02 80 01 20  be  0xa0083634
a00831b8:  80 a0 60 02  cmp  %g1, 2
a00831bc:  02 80 01 02  be  0xa00835c4
a00831c0:  01 00 00 00  nop
a00831c4:  40 03 14 6e  call  0xa014837c
a00831c8:  90 10 20 01  mov  1, %o0	! 0x1
a00831cc:  99 2a 20 10  sll  %o0, 0x10, %o4
a00831d0:  91 33 20 12  srl  %o4, 0x12, %o0
a00831d4:  ba 5a 23 e8  smul  %o0, 0x3e8, %i5
a00831d8:  40 03 14 69  call  0xa014837c
a00831dc:  90 10 20 00  clr  %o0
a00831e0:  a3 2a 20 10  sll  %o0, 0x10, %l1
a00831e4:  b9 2f 60 02  sll  %i5, 2, %i4
a00831e8:  ae 07 00 1d  add  %i4, %i5, %l7
a00831ec:  90 10 20 01  mov  1, %o0
a00831f0:  40 03 14 63  call  0xa014837c
a00831f4:  ad 34 60 10  srl  %l1, 0x10, %l6
a00831f8:  aa 05 c0 17  add  %l7, %l7, %l5
a00831fc:  81 80 00 00  mov  %g0, %y
a0083200:  01 00 00 00  nop
a0083204:  01 00 00 00  nop
a0083208:  01 00 00 00  nop
a008320c:  a8 75 40 16  udiv  %l5, %l6, %l4
a0083210:  a2 0c a0 ff  and  %l2, 0xff, %l1
a0083214:  a1 2a 20 10  sll  %o0, 0x10, %l0
a0083218:  81 80 00 00  mov  %g0, %y
a008321c:  01 00 00 00  nop
a0083220:  01 00 00 00  nop
a0083224:  01 00 00 00  nop
a0083228:  a6 75 00 11  udiv  %l4, %l1, %l3
a008322c:  91 34 20 12  srl  %l0, 0x12, %o0
a0083230:  9e 5a 23 e8  smul  %o0, 0x3e8, %o7
a0083234:  97 2b e0 02  sll  %o7, 2, %o3
a0083238:  94 02 c0 0f  add  %o3, %o7, %o2
a008323c:  a8 02 80 0a  add  %o2, %o2, %l4
a0083240:  40 03 14 4f  call  0xa014837c
a0083244:  90 10 20 01  mov  1, %o0
a0083248:  9b 2a 20 10  sll  %o0, 0x10, %o5
a008324c:  93 33 60 10  srl  %o5, 0x10, %o1
a0083250:  81 80 00 00  mov  %g0, %y
a0083254:  01 00 00 00  nop
a0083258:  01 00 00 00  nop
a008325c:  01 00 00 00  nop
a0083260:  a0 75 00 09  udiv  %l4, %o1, %l0
a0083264:  81 80 00 00  mov  %g0, %y
a0083268:  01 00 00 00  nop
a008326c:  01 00 00 00  nop
a0083270:  01 00 00 00  nop
a0083274:  96 74 00 11  udiv  %l0, %l1, %o3
a0083278:  b9 2c e0 10  sll  %l3, 0x10, %i4
a008327c:  a3 2a e0 10  sll  %o3, 0x10, %l1
a0083280:  ad 37 20 10  srl  %i4, 0x10, %l6
a0083284:  a5 34 60 10  srl  %l1, 0x10, %l2
a0083288:  e8 17 bf f6  lduh  [ %fp + -10 ], %l4
a008328c:  e0 17 bf f2  lduh  [ %fp + -14 ], %l0
a0083290:  2f 04 18 93  sethi  %hi(0x10624c00), %l7
a0083294:  aa 15 e1 d3  or  %l7, 0x1d3, %l5	! 0x10624dd3
a0083298:  9e 5d 00 16  smul  %l4, %l6, %o7
a008329c:  96 5c 00 12  smul  %l0, %l2, %o3
a00832a0:  80 52 c0 15  umul  %o3, %l5, %g0
a00832a4:  9b 40 00 00  rd  %y, %o5
a00832a8:  80 53 c0 15  umul  %o7, %l5, %g0
a00832ac:  95 40 00 00  rd  %y, %o2
a00832b0:  93 33 60 07  srl  %o5, 7, %o1
a00832b4:  99 32 a0 09  srl  %o2, 9, %o4
a00832b8:  a4 02 40 09  add  %o1, %o1, %l2
a00832bc:  af 2b 20 03  sll  %o4, 3, %l7
a00832c0:  90 24 00 12  sub  %l0, %l2, %o0
a00832c4:  82 25 00 17  sub  %l4, %l7, %g1
a00832c8:  a3 32 20 01  srl  %o0, 1, %l1
a00832cc:  e6 17 bf f4  lduh  [ %fp + -12 ], %l3
a00832d0:  f8 17 bf f0  lduh  [ %fp + -16 ], %i4
a00832d4:  bb 30 60 01  srl  %g1, 1, %i5
a00832d8:  ac 07 40 13  add  %i5, %l3, %l6
a00832dc:  aa 04 40 1c  add  %l1, %i4, %l5
a00832e0:  ee 37 bf f6  sth  %l7, [ %fp + -10 ]
a00832e4:  ec 37 bf f4  sth  %l6, [ %fp + -12 ]
a00832e8:  e4 37 bf f2  sth  %l2, [ %fp + -14 ]
a00832ec:  ea 37 bf f0  sth  %l5, [ %fp + -16 ]
a00832f0:  90 10 20 01  mov  1, %o0
a00832f4:  40 03 2a a9  call  0xa014dd98
a00832f8:  92 10 20 01  mov  1, %o1
a00832fc:  90 10 00 18  mov  %i0, %o0
a0083300:  d4 17 bf f4  lduh  [ %fp + -12 ], %o2
a0083304:  92 10 20 0c  mov  0xc, %o1
a0083308:  40 03 09 40  call  0xa0145808
a008330c:  96 10 20 00  clr  %o3
a0083310:  90 10 00 18  mov  %i0, %o0
a0083314:  d4 17 bf f0  lduh  [ %fp + -16 ], %o2
a0083318:  92 10 20 10  mov  0x10, %o1
a008331c:  40 03 09 3b  call  0xa0145808
a0083320:  96 10 20 00  clr  %o3
a0083324:  90 10 00 18  mov  %i0, %o0
a0083328:  d4 17 bf f6  lduh  [ %fp + -10 ], %o2
a008332c:  92 10 20 09  mov  9, %o1
a0083330:  40 03 09 36  call  0xa0145808
a0083334:  96 10 20 00  clr  %o3
a0083338:  90 10 00 18  mov  %i0, %o0
a008333c:  92 10 20 0a  mov  0xa, %o1
a0083340:  d4 17 bf f2  lduh  [ %fp + -14 ], %o2
a0083344:  40 03 09 31  call  0xa0145808
a0083348:  96 10 20 01  mov  1, %o3
a008334c:  30 80 01 24  b,a   0xa00837dc
a0083350:  12 bf ff ec  bne  0xa0083300
a0083354:  90 10 00 18  mov  %i0, %o0
a0083358:  e6 0a a0 2f  ldub  [ %o2 + 0x2f ], %l3
a008335c:  80 a0 00 13  cmp  %g0, %l3
a0083360:  ba 60 3f ff  subx  %g0, -1, %i5
a0083364:  80 8f 40 0b  btst  %i5, %o3
a0083368:  02 bf ff e7  be  0xa0083304
a008336c:  d4 17 bf f4  lduh  [ %fp + -12 ], %o2
a0083370:  40 03 04 47  call  0xa014448c
a0083374:  90 10 20 01  mov  1, %o0
a0083378:  90 0a 20 ff  and  %o0, 0xff, %o0
a008337c:  80 a2 20 0d  cmp  %o0, 0xd
a0083380:  32 bf ff e0  bne,a   0xa0083300
a0083384:  90 10 00 18  mov  %i0, %o0
a0083388:  92 10 20 07  mov  7, %o1
a008338c:  40 03 08 b5  call  0xa0145660
a0083390:  90 10 20 01  mov  1, %o0
a0083394:  a0 10 00 08  mov  %o0, %l0
a0083398:  92 10 20 08  mov  8, %o1
a008339c:  40 03 08 b1  call  0xa0145660
a00833a0:  90 10 20 01  mov  1, %o0
a00833a4:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00833a8:  15 2a 00 90  sethi  %hi(0xa8024000), %o2
a00833ac:  97 34 20 10  srl  %l0, 0x10, %o3
a00833b0:  ee 12 a0 06  lduh  [ %o2 + 6 ], %l7
a00833b4:  2d 2a aa aa  sethi  %hi(0xaaaaa800), %l6
a00833b8:  aa 22 c0 17  sub  %o3, %l7, %l5
a00833bc:  a4 15 a2 ab  or  %l6, 0x2ab, %l2
a00833c0:  9f 3d 60 1f  sra  %l5, 0x1f, %o7
a00833c4:  80 52 c0 12  umul  %o3, %l2, %g0
a00833c8:  99 40 00 00  rd  %y, %o4
a00833cc:  9a 1b c0 15  xor  %o7, %l5, %o5
a00833d0:  93 2b 20 0e  sll  %o4, 0xe, %o1
a00833d4:  a8 23 40 0f  sub  %o5, %o7, %l4
a00833d8:  83 32 60 10  srl  %o1, 0x10, %g1
a00833dc:  80 a5 00 01  cmp  %l4, %g1
a00833e0:  a6 07 bf f4  add  %fp, -12, %l3
a00833e4:  a8 07 bf f0  add  %fp, -16, %l4
a00833e8:  aa 07 bf f6  add  %fp, -10, %l5
a00833ec:  ac 07 bf f2  add  %fp, -14, %l6
a00833f0:  ae 10 20 00  clr  %l7
a00833f4:  14 80 00 03  bg  0xa0083400
a00833f8:  ba 10 20 00  clr  %i5
a00833fc:  ba 10 20 01  mov  1, %i5
a0083400:  91 2a 20 10  sll  %o0, 0x10, %o0
a0083404:  23 2a 00 90  sethi  %hi(0xa8024000), %l1
a0083408:  a5 32 20 10  srl  %o0, 0x10, %l2
a008340c:  d2 14 60 04  lduh  [ %l1 + 4 ], %o1
a0083410:  03 2a aa aa  sethi  %hi(0xaaaaa800), %g1
a0083414:  96 24 80 09  sub  %l2, %o1, %o3
a0083418:  b8 10 62 ab  or  %g1, 0x2ab, %i4
a008341c:  80 54 80 1c  umul  %l2, %i4, %g0
a0083420:  99 40 00 00  rd  %y, %o4
a0083424:  9f 3a e0 1f  sra  %o3, 0x1f, %o7
a0083428:  9a 1b c0 0b  xor  %o7, %o3, %o5
a008342c:  93 2b 20 0e  sll  %o4, 0xe, %o1
a0083430:  b9 32 60 10  srl  %o1, 0x10, %i4
a0083434:  82 23 40 0f  sub  %o5, %o7, %g1
a0083438:  80 a0 40 1c  cmp  %g1, %i4
a008343c:  14 80 00 03  bg  0xa0083448
a0083440:  b8 10 20 00  clr  %i4
a0083444:  b8 10 20 01  mov  1, %i4
a0083448:  25 00 03 fa  sethi  %hi(0xfe800), %l2
a008344c:  99 34 20 10  srl  %l0, 0x10, %o4
a0083450:  91 32 20 10  srl  %o0, 0x10, %o0
a0083454:  9e 10 20 00  clr  %o7
a0083458:  92 10 20 00  clr  %o1
a008345c:  a0 14 a3 30  or  %l2, 0x330, %l0
a0083460:  9b 2a 60 03  sll  %o1, 3, %o5
a0083464:  96 03 40 09  add  %o5, %o1, %o3
a0083468:  82 02 c0 0b  add  %o3, %o3, %g1
a008346c:  da 14 00 01  lduh  [ %l0 + %g1 ], %o5
a0083470:  9a 23 00 0d  sub  %o4, %o5, %o5
a0083474:  96 00 40 10  add  %g1, %l0, %o3
a0083478:  83 3b 60 1f  sra  %o5, 0x1f, %g1
a008347c:  9a 18 40 0d  xor  %g1, %o5, %o5
a0083480:  9a 23 40 01  sub  %o5, %g1, %o5
a0083484:  80 a3 60 0a  cmp  %o5, 0xa
a0083488:  04 80 00 ab  ble  0xa0083734
a008348c:  9e 03 e0 01  inc  %o7
a0083490:  92 0b e0 ff  and  %o7, 0xff, %o1
a0083494:  80 a2 60 0b  cmp  %o1, 0xb
a0083498:  08 bf ff f3  bleu  0xa0083464
a008349c:  9b 2a 60 03  sll  %o1, 3, %o5
a00834a0:  80 8d e0 ff  btst  0xff, %l7
a00834a4:  22 bf ff 97  be,a   0xa0083300
a00834a8:  90 10 00 18  mov  %i0, %o0
a00834ac:  9a 0f 60 ff  and  %i5, 0xff, %o5
a00834b0:  80 a3 60 00  cmp  %o5, 0
a00834b4:  12 80 00 aa  bne  0xa008375c
a00834b8:  82 0f 20 ff  and  %i4, 0xff, %g1
a00834bc:  97 2a 60 03  sll  %o1, 3, %o3
a00834c0:  ee 12 a0 06  lduh  [ %o2 + 6 ], %l7
a00834c4:  b8 02 c0 09  add  %o3, %o1, %i4
a00834c8:  21 2a 00 90  sethi  %hi(0xa8024000), %l0
a00834cc:  e8 14 20 0a  lduh  [ %l0 + 0xa ], %l4	! 0xa802400a
a00834d0:  98 14 a3 30  or  %l2, 0x330, %o4
a00834d4:  9e 07 00 1c  add  %i4, %i4, %o7
a00834d8:  ba 05 e0 08  add  %l7, 8, %i5
a00834dc:  fa 35 40 00  sth  %i5, [ %l5 ]
a00834e0:  90 03 c0 0c  add  %o7, %o4, %o0
a00834e4:  a2 05 3f f8  add  %l4, -8, %l1
a00834e8:  d4 12 20 06  lduh  [ %o0 + 6 ], %o2
a00834ec:  e2 34 c0 00  sth  %l1, [ %l3 ]
a00834f0:  10 bf ff 83  b  0xa00832fc
a00834f4:  d4 35 80 00  sth  %o2, [ %l6 ]
a00834f8:  90 10 00 18  mov  %i0, %o0
a00834fc:  92 07 bf f6  add  %fp, -10, %o1
a0083500:  7f ff fd d7  call  0xa0082c5c
a0083504:  94 07 bf f4  add  %fp, -12, %o2
a0083508:  90 10 00 18  mov  %i0, %o0
a008350c:  92 07 bf f2  add  %fp, -14, %o1
a0083510:  7f ff fe 2d  call  0xa0082dc4
a0083514:  94 07 bf f0  add  %fp, -16, %o2
a0083518:  10 bf ff 17  b  0xa0083174
a008351c:  94 14 22 90  or  %l0, 0x290, %o2
a0083520:  9e 1b 60 01  xor  %o5, 1, %o7
a0083524:  80 a0 00 0f  cmp  %g0, %o7
a0083528:  96 60 20 00  subx  %g0, 0, %o3
a008352c:  94 0a e0 0a  and  %o3, 0xa, %o2
a0083530:  10 bf ff 1e  b  0xa00831a8
a0083534:  a4 02 a0 14  add  %o2, 0x14, %l2
a0083538:  de 17 bf f6  lduh  [ %fp + -10 ], %o7
a008353c:  a2 14 a2 67  or  %l2, 0x267, %l1
a0083540:  80 5b c0 11  smul  %o7, %l1, %g0
a0083544:  97 40 00 00  rd  %y, %o3
a0083548:  99 3a e0 05  sra  %o3, 5, %o4
a008354c:  95 2b 20 10  sll  %o4, 0x10, %o2
a0083550:  d2 17 bf f6  lduh  [ %fp + -10 ], %o1
a0083554:  9b 32 a0 0f  srl  %o2, 0xf, %o5
a0083558:  82 22 40 0d  sub  %o1, %o5, %g1
a008355c:  c2 37 bf f6  sth  %g1, [ %fp + -10 ]
a0083560:  d8 37 bf f4  sth  %o4, [ %fp + -12 ]
a0083564:  40 03 15 cc  call  0xa0148c94
a0083568:  90 10 00 18  mov  %i0, %o0
a008356c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0083570:  80 a2 20 01  cmp  %o0, 1
a0083574:  02 80 00 6b  be  0xa0083720
a0083578:  ec 17 bf f2  lduh  [ %fp + -14 ], %l6
a008357c:  80 5d 80 11  smul  %l6, %l1, %g0
a0083580:  ab 40 00 00  rd  %y, %l5
a0083584:  83 3d 60 05  sra  %l5, 5, %g1
a0083588:  f8 17 bf f0  lduh  [ %fp + -16 ], %i4
a008358c:  ae 00 40 1c  add  %g1, %i4, %l7
a0083590:  ee 37 bf f0  sth  %l7, [ %fp + -16 ]
a0083594:  40 03 15 c0  call  0xa0148c94
a0083598:  90 10 00 18  mov  %i0, %o0
a008359c:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00835a0:  80 a4 60 01  cmp  %l1, 1
a00835a4:  02 80 00 5d  be  0xa0083718
a00835a8:  fa 17 bf f0  lduh  [ %fp + -16 ], %i5
a00835ac:  d0 17 bf f0  lduh  [ %fp + -16 ], %o0
a00835b0:  9a 02 00 08  add  %o0, %o0, %o5
a00835b4:  c2 17 bf f2  lduh  [ %fp + -14 ], %g1
a00835b8:  98 20 40 0d  sub  %g1, %o5, %o4
a00835bc:  10 bf fe ed  b  0xa0083170
a00835c0:  d8 37 bf f2  sth  %o4, [ %fp + -14 ]
a00835c4:  40 03 13 6e  call  0xa014837c
a00835c8:  90 10 20 01  mov  1, %o0
a00835cc:  83 2a 20 10  sll  %o0, 0x10, %g1
a00835d0:  99 30 60 11  srl  %g1, 0x11, %o4
a00835d4:  90 5b 23 e8  smul  %o4, 0x3e8, %o0
a00835d8:  a7 2a 20 02  sll  %o0, 2, %l3
a00835dc:  ba 04 c0 08  add  %l3, %o0, %i5
a00835e0:  40 03 13 67  call  0xa014837c
a00835e4:  90 10 20 00  clr  %o0
a00835e8:  b9 2a 20 10  sll  %o0, 0x10, %i4
a00835ec:  a3 37 20 10  srl  %i4, 0x10, %l1
a00835f0:  ae 07 40 1d  add  %i5, %i5, %l7
a00835f4:  81 80 00 00  mov  %g0, %y
a00835f8:  01 00 00 00  nop
a00835fc:  01 00 00 00  nop
a0083600:  01 00 00 00  nop
a0083604:  ac 75 c0 11  udiv  %l7, %l1, %l6
a0083608:  90 10 20 01  mov  1, %o0
a008360c:  40 03 13 5c  call  0xa014837c
a0083610:  a2 0c a0 ff  and  %l2, 0xff, %l1
a0083614:  a5 2a 20 10  sll  %o0, 0x10, %l2
a0083618:  81 80 00 00  mov  %g0, %y
a008361c:  01 00 00 00  nop
a0083620:  01 00 00 00  nop
a0083624:  01 00 00 00  nop
a0083628:  a6 75 80 11  udiv  %l6, %l1, %l3
a008362c:  10 bf ff 01  b  0xa0083230
a0083630:  91 34 a0 11  srl  %l2, 0x11, %o0
a0083634:  40 03 13 52  call  0xa014837c
a0083638:  90 10 20 01  mov  1, %o0
a008363c:  a9 2a 20 10  sll  %o0, 0x10, %l4
a0083640:  2b 2a aa aa  sethi  %hi(0xaaaaa800), %l5
a0083644:  9f 35 20 10  srl  %l4, 0x10, %o7
a0083648:  a2 15 62 ab  or  %l5, 0x2ab, %l1
a008364c:  80 53 c0 11  umul  %o7, %l1, %g0
a0083650:  97 40 00 00  rd  %y, %o3
a0083654:  95 2a e0 0f  sll  %o3, 0xf, %o2
a0083658:  9b 32 a0 10  srl  %o2, 0x10, %o5
a008365c:  92 5b 63 e8  smul  %o5, 0x3e8, %o1
a0083660:  a1 2a 60 02  sll  %o1, 2, %l0
a0083664:  82 04 00 09  add  %l0, %o1, %g1
a0083668:  a6 00 40 01  add  %g1, %g1, %l3
a008366c:  40 03 13 44  call  0xa014837c
a0083670:  90 10 20 00  clr  %o0
a0083674:  99 2a 20 10  sll  %o0, 0x10, %o4
a0083678:  91 33 20 10  srl  %o4, 0x10, %o0
a008367c:  81 80 00 00  mov  %g0, %y
a0083680:  01 00 00 00  nop
a0083684:  01 00 00 00  nop
a0083688:  01 00 00 00  nop
a008368c:  ba 74 c0 08  udiv  %l3, %o0, %i5
a0083690:  40 03 13 3b  call  0xa014837c
a0083694:  90 10 20 01  mov  1, %o0
a0083698:  b9 2a 20 10  sll  %o0, 0x10, %i4
a008369c:  af 37 20 10  srl  %i4, 0x10, %l7
a00836a0:  80 55 c0 11  umul  %l7, %l1, %g0
a00836a4:  ad 40 00 00  rd  %y, %l6
a00836a8:  ab 2d a0 0f  sll  %l6, 0xf, %l5
a00836ac:  a9 35 60 10  srl  %l5, 0x10, %l4
a00836b0:  9e 5d 23 e8  smul  %l4, 0x3e8, %o7
a00836b4:  97 2b e0 02  sll  %o7, 2, %o3
a00836b8:  94 02 c0 0f  add  %o3, %o7, %o2
a00836bc:  a0 02 80 0a  add  %o2, %o2, %l0
a00836c0:  40 03 13 2f  call  0xa014837c
a00836c4:  90 10 20 01  mov  1, %o0
a00836c8:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00836cc:  93 33 60 10  srl  %o5, 0x10, %o1
a00836d0:  a4 0c a0 ff  and  %l2, 0xff, %l2
a00836d4:  81 80 00 00  mov  %g0, %y
a00836d8:  01 00 00 00  nop
a00836dc:  01 00 00 00  nop
a00836e0:  01 00 00 00  nop
a00836e4:  82 74 00 09  udiv  %l0, %o1, %g1
a00836e8:  81 80 00 00  mov  %g0, %y
a00836ec:  01 00 00 00  nop
a00836f0:  01 00 00 00  nop
a00836f4:  01 00 00 00  nop
a00836f8:  a6 77 40 12  udiv  %i5, %l2, %l3
a00836fc:  81 80 00 00  mov  %g0, %y
a0083700:  01 00 00 00  nop
a0083704:  01 00 00 00  nop
a0083708:  01 00 00 00  nop
a008370c:  96 70 40 12  udiv  %g1, %l2, %o3
a0083710:  10 bf fe db  b  0xa008327c
a0083714:  b9 2c e0 10  sll  %l3, 0x10, %i4
a0083718:  10 bf ff a7  b  0xa00835b4
a008371c:  9b 2f 60 02  sll  %i5, 2, %o5
a0083720:  e8 17 bf f2  lduh  [ %fp + -14 ], %l4
a0083724:  80 5d 00 11  smul  %l4, %l1, %g0
a0083728:  a7 40 00 00  rd  %y, %l3
a008372c:  10 bf ff 97  b  0xa0083588
a0083730:  83 3c e0 06  sra  %l3, 6, %g1
a0083734:  da 12 e0 02  lduh  [ %o3 + 2 ], %o5
a0083738:  82 22 00 0d  sub  %o0, %o5, %g1
a008373c:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a0083740:  96 1b 40 01  xor  %o5, %g1, %o3
a0083744:  82 22 c0 0d  sub  %o3, %o5, %g1
a0083748:  80 a0 60 0a  cmp  %g1, 0xa
a008374c:  34 bf ff 52  bg,a   0xa0083494
a0083750:  92 0b e0 ff  and  %o7, 0xff, %o1
a0083754:  10 bf ff 53  b  0xa00834a0
a0083758:  ae 10 20 01  mov  1, %l7
a008375c:  80 ab 40 01  andncc  %o5, %g1, %g0
a0083760:  02 bf fe e8  be  0xa0083300
a0083764:  90 10 00 18  mov  %i0, %o0
a0083768:  da 12 a0 06  lduh  [ %o2 + 6 ], %o5
a008376c:  fa 14 60 04  lduh  [ %l1 + 4 ], %i5
a0083770:  80 a3 40 1d  cmp  %o5, %i5
a0083774:  94 10 00 0d  mov  %o5, %o2
a0083778:  08 80 00 10  bleu  0xa00837b8
a008377c:  96 10 00 1d  mov  %i5, %o3
a0083780:  99 2a 60 03  sll  %o1, 3, %o4
a0083784:  9e 03 00 09  add  %o4, %o1, %o7
a0083788:  11 2a 00 90  sethi  %hi(0xa8024000), %o0
a008378c:  d2 12 20 0a  lduh  [ %o0 + 0xa ], %o1	! 0xa802400a
a0083790:  a0 14 a3 30  or  %l2, 0x330, %l0
a0083794:  ae 03 c0 0f  add  %o7, %o7, %l7
a0083798:  94 03 60 08  add  %o5, 8, %o2
a008379c:  d4 35 40 00  sth  %o2, [ %l5 ]
a00837a0:  a2 05 c0 10  add  %l7, %l0, %l1
a00837a4:  d2 34 c0 00  sth  %o1, [ %l3 ]
a00837a8:  e4 14 60 06  lduh  [ %l1 + 6 ], %l2
a00837ac:  e4 35 80 00  sth  %l2, [ %l6 ]
a00837b0:  10 bf fe d3  b  0xa00832fc
a00837b4:  c0 35 00 00  clrh  [ %l4 ]
a00837b8:  1b 2a 00 90  sethi  %hi(0xa8024000), %o5
a00837bc:  03 2a 00 90  sethi  %hi(0xa8024000), %g1
a00837c0:  fa 13 60 0a  lduh  [ %o5 + 0xa ], %i5
a00837c4:  f8 10 60 08  lduh  [ %g1 + 8 ], %i4
a00837c8:  d4 35 40 00  sth  %o2, [ %l5 ]
a00837cc:  fa 34 c0 00  sth  %i5, [ %l3 ]
a00837d0:  d6 35 80 00  sth  %o3, [ %l6 ]
a00837d4:  10 bf fe ca  b  0xa00832fc
a00837d8:  f8 35 00 00  sth  %i4, [ %l4 ]
a00837dc:  81 c7 e0 08  ret
a00837e0:  81 e8 00 00  restore
