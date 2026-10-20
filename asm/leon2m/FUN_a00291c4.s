# leon2m FUN_a00291c4 0xa00291c4-0xa00295a4 (992 bytes)
a00291c4:  81 c5 40 00  jmp  %l5
a00291c8:  81 cd 80 00  rett  %l6
a00291cc:  9c 10 00 1e  mov  %fp, %sp
a00291d0:  29 2a 00 9e  sethi  %hi(0xa8027800), %l4
a00291d4:  a8 15 23 50  or  %l4, 0x350, %l4	! 0xa8027b50
a00291d8:  a7 34 e0 04  srl  %l3, 4, %l3
a00291dc:  a6 0c e0 ff  and  %l3, 0xff, %l3
a00291e0:  a6 24 e0 11  sub  %l3, 0x11, %l3
a00291e4:  a7 2c e0 02  sll  %l3, 2, %l3
a00291e8:  e6 05 00 13  ld  [ %l4 + %l3 ], %l3
a00291ec:  9f c4 c0 00  call  %l3
a00291f0:  01 00 00 00  nop
a00291f4:  81 c4 40 00  jmp  %l1
a00291f8:  81 cc 80 00  rett  %l2
a00291fc:  01 00 00 00  nop
a0029200:  81 c4 40 00  jmp  %l1
a0029204:  81 cc 80 00  rett  %l2
a0029208:  01 00 00 00  nop
a002920c:  01 00 00 00  nop
a0029210:  81 c4 80 00  jmp  %l2
a0029214:  81 cc a0 04  rett  %l2 + 4
a0029218:  01 00 00 00  nop
a002921c:  01 00 00 00  nop
a0029220:  ea 04 40 00  ld  [ %l1 ], %l5
a0029224:  2d 2a 00 9e  sethi  %hi(0xa8027800), %l6
a0029228:  ac 15 a3 9c  or  %l6, 0x39c, %l6	! 0xa8027b9c
a002922c:  ea 25 80 00  st  %l5, [ %l6 ]
a0029230:  82 10 00 12  mov  %l2, %g1
a0029234:  81 c5 80 00  jmp  %l6
a0029238:  81 cd a0 04  rett  %l6 + 4
a002923c:  81 c4 80 00  jmp  %l2
a0029240:  81 cc a0 04  rett  %l2 + 4
a0029244:  29 2a 00 9e  sethi  %hi(0xa8027800), %l4
a0029248:  a8 15 23 10  or  %l4, 0x310, %l4	! 0xa8027b10
a002924c:  ea 05 00 00  ld  [ %l4 ], %l5
a0029250:  aa a5 60 01  deccc  %l5
a0029254:  ea 25 00 00  st  %l5, [ %l4 ]
a0029258:  06 80 00 04  bl  0xa0029268
a002925c:  01 00 00 00  nop
a0029260:  81 c4 40 00  jmp  %l1
a0029264:  81 cc 80 00  rett  %l2
a0029268:  91 d0 20 00  ta  0
a002926c:  01 00 00 00  nop
a0029270:  01 00 00 00  nop
a0029274:  91 d0 20 00  ta  0
a0029278:  a7 50 00 00  rd  %wim, %l3
a002927c:  ae 10 00 01  mov  %g1, %l7
a0029280:  83 34 e0 01  srl  %l3, 1, %g1
a0029284:  a9 2c e0 0f  sll  %l3, 0xf, %l4
a0029288:  82 15 00 01  or  %l4, %g1, %g1
a002928c:  81 e0 00 00  save
a0029290:  81 90 40 00  mov  %g1, %wim
a0029294:  01 00 00 00  nop
a0029298:  01 00 00 00  nop
a002929c:  01 00 00 00  nop
a00292a0:  e0 3b a0 00  std  %l0, [ %sp ]
a00292a4:  e4 3b a0 08  std  %l2, [ %sp + 8 ]
a00292a8:  e8 3b a0 10  std  %l4, [ %sp + 0x10 ]
a00292ac:  ec 3b a0 18  std  %l6, [ %sp + 0x18 ]
a00292b0:  f0 3b a0 20  std  %i0, [ %sp + 0x20 ]
a00292b4:  f4 3b a0 28  std  %i2, [ %sp + 0x28 ]
a00292b8:  f8 3b a0 30  std  %i4, [ %sp + 0x30 ]
a00292bc:  fc 3b a0 38  std  %fp, [ %sp + 0x38 ]
a00292c0:  81 e8 00 00  restore
a00292c4:  82 10 00 17  mov  %l7, %g1
a00292c8:  81 c4 40 00  jmp  %l1
a00292cc:  81 cc 80 00  rett  %l2
a00292d0:  a7 50 00 00  rd  %wim, %l3
a00292d4:  a9 2c e0 01  sll  %l3, 1, %l4
a00292d8:  ab 34 e0 0f  srl  %l3, 0xf, %l5
a00292dc:  aa 15 40 14  or  %l5, %l4, %l5
a00292e0:  81 95 40 00  mov  %l5, %wim
a00292e4:  01 00 00 00  nop
a00292e8:  01 00 00 00  nop
a00292ec:  01 00 00 00  nop
a00292f0:  81 e8 00 00  restore
a00292f4:  81 e8 00 00  restore
a00292f8:  e0 1b a0 00  ldd  [ %sp ], %l0
a00292fc:  e4 1b a0 08  ldd  [ %sp + 8 ], %l2
a0029300:  e8 1b a0 10  ldd  [ %sp + 0x10 ], %l4
a0029304:  ec 1b a0 18  ldd  [ %sp + 0x18 ], %l6
a0029308:  f0 1b a0 20  ldd  [ %sp + 0x20 ], %i0
a002930c:  f4 1b a0 28  ldd  [ %sp + 0x28 ], %i2
a0029310:  f8 1b a0 30  ldd  [ %sp + 0x30 ], %i4
a0029314:  fc 1b a0 38  ldd  [ %sp + 0x38 ], %fp
a0029318:  81 e0 00 00  save
a002931c:  81 e0 00 00  save
a0029320:  81 c4 40 00  jmp  %l1
a0029324:  81 cc 80 00  rett  %l2
a0029328:  83 48 00 00  rd  %psr, %g1
a002932c:  84 10 6f 00  or  %g1, 0xf00, %g2
a0029330:  81 e8 00 00  restore
a0029334:  81 88 a0 20  wr  %g2, 0x20, %psr
a0029338:  01 00 00 00  nop
a002933c:  01 00 00 00  nop
a0029340:  01 00 00 00  nop
a0029344:  81 e0 00 00  save
a0029348:  81 e0 00 00  save
a002934c:  81 e0 00 00  save
a0029350:  81 e0 00 00  save
a0029354:  81 e0 00 00  save
a0029358:  81 e0 00 00  save
a002935c:  81 e8 00 00  restore
a0029360:  81 e8 00 00  restore
a0029364:  81 e8 00 00  restore
a0029368:  81 e8 00 00  restore
a002936c:  81 e8 00 00  restore
a0029370:  81 88 40 00  mov  %g1, %psr
a0029374:  01 00 00 00  nop
a0029378:  01 00 00 00  nop
a002937c:  01 00 00 00  nop
a0029380:  81 c4 80 00  jmp  %l2
a0029384:  81 cc a0 04  rett  %l2 + 4
a0029388:  c0 00 20 01  ld  [ 1 ], %g0
a002938c:  81 c4 80 00  jmp  %l2
a0029390:  81 cc a0 04  rett  %l2 + 4
a0029394:  01 00 00 00  nop
a0029398:  82 10 00 00  mov  %g0, %g1
a002939c:  84 10 00 0f  mov  %o7, %g2
a00293a0:  88 10 00 00  mov  %g0, %g4
a00293a4:  8a 10 00 00  mov  %g0, %g5
a00293a8:  8c 10 00 00  mov  %g0, %g6
a00293ac:  8e 10 00 00  mov  %g0, %g7
a00293b0:  8f 50 00 00  rd  %wim, %g7
a00293b4:  81 90 00 00  mov  %g0, %wim
a00293b8:  01 00 00 00  nop
a00293bc:  01 00 00 00  nop
a00293c0:  01 00 00 00  nop
a00293c4:  a0 10 00 00  mov  %g0, %l0
a00293c8:  a2 10 00 00  mov  %g0, %l1
a00293cc:  a4 10 00 00  mov  %g0, %l2
a00293d0:  a6 10 00 00  mov  %g0, %l3
a00293d4:  a8 10 00 00  mov  %g0, %l4
a00293d8:  aa 10 00 00  mov  %g0, %l5
a00293dc:  ac 10 00 00  mov  %g0, %l6
a00293e0:  ae 10 00 00  mov  %g0, %l7
a00293e4:  90 10 00 00  mov  %g0, %o0
a00293e8:  92 10 00 00  mov  %g0, %o1
a00293ec:  94 10 00 00  mov  %g0, %o2
a00293f0:  96 10 00 00  mov  %g0, %o3
a00293f4:  98 10 00 00  mov  %g0, %o4
a00293f8:  9a 10 00 00  mov  %g0, %o5
a00293fc:  9c 10 00 00  mov  %g0, %sp
a0029400:  9e 10 00 00  mov  %g0, %o7
a0029404:  81 e0 00 00  save
a0029408:  80 a0 60 07  cmp  %g1, 7
a002940c:  12 bf ff ee  bne  0xa00293c4
a0029410:  82 00 60 01  inc  %g1
a0029414:  81 91 c0 00  mov  %g7, %wim
a0029418:  01 00 00 00  nop
a002941c:  01 00 00 00  nop
a0029420:  01 00 00 00  nop
a0029424:  9e 10 00 02  mov  %g2, %o7
a0029428:  81 c3 e0 08  retl
a002942c:  01 00 00 00  nop
a0029430:  81 c3 e0 08  retl
a0029434:  91 d0 20 02  ta  2
a0029438:  a9 48 00 00  rd  %psr, %l4
a002943c:  ab 35 20 08  srl  %l4, 8, %l5
a0029440:  a8 2d 2f 00  andn  %l4, 0xf00, %l4
a0029444:  b1 2e 20 08  sll  %i0, 8, %i0
a0029448:  b0 0e 2f 00  and  %i0, 0xf00, %i0
a002944c:  a8 16 00 14  or  %i0, %l4, %l4
a0029450:  81 8d 00 00  mov  %l4, %psr
a0029454:  b0 0d 60 0f  and  %l5, 0xf, %i0
a0029458:  81 c4 80 00  jmp  %l2
a002945c:  81 cc a0 04  rett  %l2 + 4
a0029460:  a9 50 00 00  rd  %wim, %l4
a0029464:  aa 10 00 0e  mov  %sp, %l5
a0029468:  ad 40 00 00  rd  %y, %l6
a002946c:  2f 2a 00 ff  sethi  %hi(0xa803fc00), %l7
a0029470:  ae 15 e3 60  or  %l7, 0x360, %l7	! 0xa803ff60
a0029474:  c0 25 e0 00  clr  [ %l7 ]
a0029478:  c2 25 e0 04  st  %g1, [ %l7 + 4 ]
a002947c:  c4 25 e0 08  st  %g2, [ %l7 + 8 ]
a0029480:  c6 25 e0 0c  st  %g3, [ %l7 + 0xc ]
a0029484:  c8 25 e0 10  st  %g4, [ %l7 + 0x10 ]
a0029488:  ca 25 e0 14  st  %g5, [ %l7 + 0x14 ]
a002948c:  cc 25 e0 18  st  %g6, [ %l7 + 0x18 ]
a0029490:  ce 25 e0 1c  st  %g7, [ %l7 + 0x1c ]
a0029494:  07 2a 00 ff  sethi  %hi(0xa803fc00), %g3
a0029498:  86 10 e3 60  or  %g3, 0x360, %g3	! 0xa803ff60
a002949c:  ae 10 00 1e  mov  %fp, %l7
a00294a0:  e0 20 e0 20  st  %l0, [ %g3 + 0x20 ]
a00294a4:  e2 20 e0 24  st  %l1, [ %g3 + 0x24 ]
a00294a8:  e4 20 e0 28  st  %l2, [ %g3 + 0x28 ]
a00294ac:  e6 20 e0 2c  st  %l3, [ %g3 + 0x2c ]
a00294b0:  e8 20 e0 30  st  %l4, [ %g3 + 0x30 ]
a00294b4:  ea 20 e0 34  st  %l5, [ %g3 + 0x34 ]
a00294b8:  ec 20 e0 38  st  %l6, [ %g3 + 0x38 ]
a00294bc:  ee 20 e0 3c  st  %l7, [ %g3 + 0x3c ]
a00294c0:  f0 20 e0 40  st  %i0, [ %g3 + 0x40 ]
a00294c4:  f2 20 e0 44  st  %i1, [ %g3 + 0x44 ]
a00294c8:  f4 20 e0 48  st  %i2, [ %g3 + 0x48 ]
a00294cc:  f6 20 e0 4c  st  %i3, [ %g3 + 0x4c ]
a00294d0:  f8 20 e0 50  st  %i4, [ %g3 + 0x50 ]
a00294d4:  fa 20 e0 54  st  %i5, [ %g3 + 0x54 ]
a00294d8:  fc 20 e0 58  st  %fp, [ %g3 + 0x58 ]
a00294dc:  fe 20 e0 5c  st  %i7, [ %g3 + 0x5c ]
a00294e0:  81 e8 00 00  restore
a00294e4:  f0 20 e0 60  st  %i0, [ %g3 + 0x60 ]
a00294e8:  f2 20 e0 64  st  %i1, [ %g3 + 0x64 ]
a00294ec:  f4 20 e0 68  st  %i2, [ %g3 + 0x68 ]
a00294f0:  f6 20 e0 6c  st  %i3, [ %g3 + 0x6c ]
a00294f4:  f8 20 e0 70  st  %i4, [ %g3 + 0x70 ]
a00294f8:  fa 20 e0 74  st  %i5, [ %g3 + 0x74 ]
a00294fc:  fc 20 e0 78  st  %fp, [ %g3 + 0x78 ]
a0029500:  fe 20 e0 7c  st  %i7, [ %g3 + 0x7c ]
a0029504:  e0 20 e0 80  st  %l0, [ %g3 + 0x80 ]
a0029508:  e2 20 e0 84  st  %l1, [ %g3 + 0x84 ]
a002950c:  e4 20 e0 88  st  %l2, [ %g3 + 0x88 ]
a0029510:  e6 20 e0 8c  st  %l3, [ %g3 + 0x8c ]
a0029514:  e8 20 e0 90  st  %l4, [ %g3 + 0x90 ]
a0029518:  ea 20 e0 94  st  %l5, [ %g3 + 0x94 ]
a002951c:  ec 20 e0 98  st  %l6, [ %g3 + 0x98 ]
a0029520:  ee 20 e0 9c  st  %l7, [ %g3 + 0x9c ]
a0029524:  81 e0 00 00  save
a0029528:  2f 2a 00 ff  sethi  %hi(0xa803fc00), %l7
a002952c:  ae 15 e3 60  or  %l7, 0x360, %l7	! 0xa803ff60
a0029530:  c6 05 e0 0c  ld  [ %l7 + 0xc ], %g3
a0029534:  27 2a 00 9e  sethi  %hi(0xa8027800), %l3
a0029538:  a6 14 e3 98  or  %l3, 0x398, %l3	! 0xa8027b98
a002953c:  ee 04 c0 00  ld  [ %l3 ], %l7
a0029540:  a6 10 00 00  mov  %g0, %l3
a0029544:  a8 10 00 01  mov  %g1, %l4
a0029548:  aa 10 00 02  mov  %g2, %l5
a002954c:  ac 10 00 03  mov  %g3, %l6
a0029550:  9f c5 c0 00  call  %l7
a0029554:  01 00 00 00  nop
a0029558:  81 e8 00 00  restore
a002955c:  81 e0 00 00  save
a0029560:  80 10 00 13  mov  %l3, %g0
a0029564:  82 10 00 14  mov  %l4, %g1
a0029568:  84 10 00 15  mov  %l5, %g2
a002956c:  86 10 00 16  mov  %l6, %g3
a0029570:  01 00 00 00  nop
a0029574:  81 8c 20 20  wr  %l0, 0x20, %psr
a0029578:  a8 2c 2f 00  andn  %l0, 0xf00, %l4
a002957c:  81 8d 20 20  wr  %l4, 0x20, %psr
a0029580:  01 00 00 00  nop
a0029584:  01 00 00 00  nop
a0029588:  01 00 00 00  nop
a002958c:  81 c4 40 00  jmp  %l1
a0029590:  81 cc 80 00  rett  %l2
a0029594:  53 74 61 72  call  0xedd41b5c
a0029598:  74 69 6e 67  call  0x71a84f34
a002959c:  20 74 65 73  unknown
a00295a0:  74 00 00 00  call  0x700295a0
