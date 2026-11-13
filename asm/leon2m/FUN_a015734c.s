# leon2m FUN_a015734c 0xa015734c-0xa0157480 (308 bytes)
a015734c:  9d e3 bf 98  save  %sp, -104, %sp
a0157350:  d8 1e 00 00  ldd  [ %i0 ], %o4
a0157354:  b7 33 20 1f  srl  %o4, 0x1f, %i3
a0157358:  82 0e e0 01  and  %i3, 1, %g1
a015735c:  35 00 03 ff  sethi  %hi(0xffc00), %i2
a0157360:  bb 33 20 14  srl  %o4, 0x14, %i5
a0157364:  b0 10 00 19  mov  %i1, %i0
a0157368:  c2 26 60 04  st  %g1, [ %i1 + 4 ]
a015736c:  b4 16 a3 ff  or  %i2, 0x3ff, %i2
a0157370:  b6 10 3f ff  mov  -1, %i3
a0157374:  98 0b 00 1a  and  %o4, %i2, %o4
a0157378:  b2 8f 67 ff  andcc  %i5, 0x7ff, %i1
a015737c:  12 80 00 07  bne  0xa0157398
a0157380:  9a 0b 40 1b  and  %o5, %i3, %o5
a0157384:  80 93 00 0d  orcc  %o4, %o5, %g0
a0157388:  12 80 00 13  bne  0xa01573d4
a015738c:  82 10 20 02  mov  2, %g1
a0157390:  10 80 00 3a  b  0xa0157478
a0157394:  c2 26 00 00  st  %g1, [ %i0 ]
a0157398:  80 a6 67 ff  cmp  %i1, 0x7ff
a015739c:  02 80 00 2b  be  0xa0157448
a01573a0:  b7 33 60 18  srl  %o5, 0x18, %i3
a01573a4:  83 2b 20 08  sll  %o4, 8, %g1
a01573a8:  b8 16 c0 01  or  %i3, %g1, %i4
a01573ac:  bb 2b 60 08  sll  %o5, 8, %i5
a01573b0:  35 04 00 00  sethi  %hi(0x10000000), %i2
a01573b4:  b6 10 20 00  clr  %i3
a01573b8:  b8 17 00 1a  or  %i4, %i2, %i4
a01573bc:  ba 17 40 1b  or  %i5, %i3, %i5
a01573c0:  b2 06 7c 01  add  %i1, -1023, %i1
a01573c4:  f8 3e 20 10  std  %i4, [ %i0 + 0x10 ]
a01573c8:  f2 26 20 08  st  %i1, [ %i0 + 8 ]
a01573cc:  10 bf ff f1  b  0xa0157390
a01573d0:  82 10 20 03  mov  3, %g1
a01573d4:  b7 33 60 18  srl  %o5, 0x18, %i3
a01573d8:  83 2b 20 08  sll  %o4, 8, %g1
a01573dc:  b8 16 c0 01  or  %i3, %g1, %i4
a01573e0:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a01573e4:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xfffffff
a01573e8:  bb 2b 60 08  sll  %o5, 8, %i5
a01573ec:  b6 10 20 03  mov  3, %i3
a01573f0:  80 a7 00 01  cmp  %i4, %g1
a01573f4:  98 10 00 1c  mov  %i4, %o4
a01573f8:  9a 10 00 1d  mov  %i5, %o5
a01573fc:  f6 26 00 00  st  %i3, [ %i0 ]
a0157400:  b4 10 3c 02  mov  -1022, %i2
a0157404:  18 80 00 0e  bgu  0xa015743c
a0157408:  82 10 3c 02  mov  -1022, %g1
a015740c:  82 03 00 0c  add  %o4, %o4, %g1
a0157410:  b7 33 60 1f  srl  %o5, 0x1f, %i3
a0157414:  b8 16 c0 01  or  %i3, %g1, %i4
a0157418:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a015741c:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xfffffff
a0157420:  ba 03 40 0d  add  %o5, %o5, %i5
a0157424:  b4 06 bf ff  add  %i2, -1, %i2
a0157428:  80 a7 00 01  cmp  %i4, %g1
a015742c:  98 10 00 1c  mov  %i4, %o4
a0157430:  9a 10 00 1d  mov  %i5, %o5
a0157434:  08 bf ff f6  bleu  0xa015740c
a0157438:  82 10 00 1a  mov  %i2, %g1
a015743c:  d8 3e 20 10  std  %o4, [ %i0 + 0x10 ]
a0157440:  10 80 00 0e  b  0xa0157478
a0157444:  c2 26 20 08  st  %g1, [ %i0 + 8 ]
a0157448:  80 93 00 0d  orcc  %o4, %o5, %g0
a015744c:  02 bf ff d1  be  0xa0157390
a0157450:  82 10 20 04  mov  4, %g1
a0157454:  bb 33 20 13  srl  %o4, 0x13, %i5
a0157458:  80 8f 60 01  btst  1, %i5
a015745c:  22 80 00 06  be,a   0xa0157474
a0157460:  c0 26 00 00  clr  [ %i0 ]
a0157464:  82 10 20 01  mov  1, %g1
a0157468:  c2 26 00 00  st  %g1, [ %i0 ]
a015746c:  10 80 00 03  b  0xa0157478
a0157470:  d8 3e 20 10  std  %o4, [ %i0 + 0x10 ]
a0157474:  d8 3e 20 10  std  %o4, [ %i0 + 0x10 ]
a0157478:  81 c7 e0 08  ret
a015747c:  81 e8 00 00  restore
