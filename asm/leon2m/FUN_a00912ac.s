# leon2m FUN_a00912ac 0xa00912ac-0xa009145c (432 bytes)
a00912ac:  9d e3 bf 98  save  %sp, -104, %sp
a00912b0:  31 2a 00 ab  sethi  %hi(0xa802ac00), %i0
a00912b4:  d6 06 23 ec  ld  [ %i0 + 0x3ec ], %o3	! 0xa802afec
a00912b8:  80 a2 e0 02  cmp  %o3, 2
a00912bc:  02 80 00 4e  be  0xa00913f4
a00912c0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00912c4:  80 a2 e0 01  cmp  %o3, 1
a00912c8:  02 80 00 2e  be  0xa0091380
a00912cc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00912d0:  da 06 23 ec  ld  [ %i0 + 0x3ec ], %o5
a00912d4:  a0 03 7f fe  add  %o5, -2, %l0
a00912d8:  40 00 5a ca  call  0xa00a7e00
a00912dc:  90 0c 20 ff  and  %l0, 0xff, %o0
a00912e0:  1f 0e 38 e3  sethi  %hi(0x38e38c00), %o7
a00912e4:  a0 13 e2 39  or  %o7, 0x239, %l0	! 0x38e38e39
a00912e8:  d8 16 23 ee  lduh  [ %i0 + 0x3ee ], %o4
a00912ec:  92 03 20 06  add  %o4, 6, %o1
a00912f0:  80 5a 40 10  smul  %o1, %l0, %g0
a00912f4:  9b 40 00 00  rd  %y, %o5
a00912f8:  9f 3b 60 01  sra  %o5, 1, %o7
a00912fc:  97 2b e0 03  sll  %o7, 3, %o3
a0091300:  94 02 c0 0f  add  %o3, %o7, %o2
a0091304:  90 22 40 0a  sub  %o1, %o2, %o0
a0091308:  82 02 20 02  add  %o0, 2, %g1
a009130c:  c2 26 23 ec  st  %g1, [ %i0 + 0x3ec ]
a0091310:  40 00 64 74  call  0xa00aa4e0
a0091314:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091318:  98 0a 20 ff  and  %o0, 0xff, %o4
a009131c:  80 a3 20 01  cmp  %o4, 1
a0091320:  32 bf ff f3  bne,a   0xa00912ec
a0091324:  d8 16 23 ee  lduh  [ %i0 + 0x3ee ], %o4
a0091328:  c2 06 23 ec  ld  [ %i0 + 0x3ec ], %g1
a009132c:  80 a0 60 08  cmp  %g1, 8
a0091330:  02 80 00 37  be  0xa009140c
a0091334:  80 a0 60 0a  cmp  %g1, 0xa
a0091338:  12 80 00 27  bne  0xa00913d4
a009133c:  90 00 7f fe  add  %g1, -2, %o0
a0091340:  40 00 67 50  call  0xa00ab080
a0091344:  01 00 00 00  nop
a0091348:  40 00 59 e9  call  0xa00a7aec
a009134c:  90 10 20 01  mov  1, %o0	! 0x1
a0091350:  40 00 8a 71  call  0xa00b3d14
a0091354:  90 10 20 01  mov  1, %o0
a0091358:  c2 06 23 ec  ld  [ %i0 + 0x3ec ], %g1
a009135c:  90 00 7f fe  add  %g1, -2, %o0
a0091360:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091364:  40 00 8b 78  call  0xa00b4144
a0091368:  92 10 20 01  mov  1, %o1
a009136c:  e0 06 23 ec  ld  [ %i0 + 0x3ec ], %l0
a0091370:  b0 04 3f fe  add  %l0, -2, %i0
a0091374:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0091378:  40 00 7b 2f  call  0xa00b0034
a009137c:  81 e8 00 00  restore
a0091380:  d2 02 a2 90  ld  [ %o2 + 0x290 ], %o1
a0091384:  11 00 00 10  sethi  %hi(0x4000), %o0
a0091388:  80 8a 40 08  btst  %o1, %o0
a009138c:  02 bf ff d2  be  0xa00912d4
a0091390:  da 06 23 ec  ld  [ %i0 + 0x3ec ], %o5
a0091394:  40 00 67 3b  call  0xa00ab080
a0091398:  01 00 00 00  nop
a009139c:  40 00 59 d4  call  0xa00a7aec
a00913a0:  90 10 20 01  mov  1, %o0	! 0x1
a00913a4:  40 00 8a 5c  call  0xa00b3d14
a00913a8:  90 10 20 01  mov  1, %o0
a00913ac:  96 10 20 0a  mov  0xa, %o3
a00913b0:  d6 26 23 ec  st  %o3, [ %i0 + 0x3ec ]
a00913b4:  90 10 20 01  mov  1, %o0
a00913b8:  92 10 20 05  mov  5, %o1
a00913bc:  94 10 20 01  mov  1, %o2
a00913c0:  96 10 27 92  mov  0x792, %o3
a00913c4:  40 02 d5 af  call  0xa0146a80
a00913c8:  98 10 20 00  clr  %o4
a00913cc:  c2 06 23 ec  ld  [ %i0 + 0x3ec ], %g1
a00913d0:  90 00 7f fe  add  %g1, -2, %o0
a00913d4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00913d8:  40 00 8b 5b  call  0xa00b4144
a00913dc:  92 10 20 01  mov  1, %o1
a00913e0:  e0 06 23 ec  ld  [ %i0 + 0x3ec ], %l0
a00913e4:  b0 04 3f fe  add  %l0, -2, %i0
a00913e8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00913ec:  40 00 7b 12  call  0xa00b0034
a00913f0:  81 e8 00 00  restore
a00913f4:  d8 00 62 90  ld  [ %g1 + 0x290 ], %o4
a00913f8:  1b 00 00 10  sethi  %hi(0x4000), %o5
a00913fc:  80 8b 00 0d  btst  %o4, %o5
a0091400:  02 bf ff b2  be  0xa00912c8
a0091404:  80 a2 e0 01  cmp  %o3, 1
a0091408:  30 80 00 09  b,a   0xa009142c
a009140c:  40 00 67 1d  call  0xa00ab080
a0091410:  01 00 00 00  nop
a0091414:  40 00 59 b6  call  0xa00a7aec
a0091418:  90 10 20 00  clr  %o0	! 0x0
a009141c:  40 00 8a 3e  call  0xa00b3d14
a0091420:  90 10 20 00  clr  %o0
a0091424:  10 bf ff ce  b  0xa009135c
a0091428:  c2 06 23 ec  ld  [ %i0 + 0x3ec ], %g1
a009142c:  40 00 5a 75  call  0xa00a7e00
a0091430:  90 10 20 00  clr  %o0
a0091434:  92 10 20 05  mov  5, %o1
a0091438:  90 10 20 01  mov  1, %o0
a009143c:  94 10 20 01  mov  1, %o2
a0091440:  96 10 25 92  mov  0x592, %o3
a0091444:  40 02 d5 8f  call  0xa0146a80
a0091448:  98 10 20 00  clr  %o4
a009144c:  92 10 20 01  mov  1, %o1
a0091450:  d2 26 23 ec  st  %o1, [ %i0 + 0x3ec ]
a0091454:  81 c7 e0 08  ret
a0091458:  81 e8 00 00  restore
