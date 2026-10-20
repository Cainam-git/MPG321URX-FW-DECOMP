# leon2m FUN_a00ce348 0xa00ce348-0xa00ce5dc (660 bytes)
a00ce348:  9d e3 bf 98  save  %sp, -104, %sp
a00ce34c:  7f ff b2 eb  call  0xa00baef8
a00ce350:  90 10 20 04  mov  4, %o0
a00ce354:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ce358:  80 a2 20 10  cmp  %o0, 0x10
a00ce35c:  02 80 00 26  be  0xa00ce3f4
a00ce360:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ce364:  14 80 00 08  bg  0xa00ce384
a00ce368:  80 a2 20 40  cmp  %o0, 0x40
a00ce36c:  80 a2 20 02  cmp  %o0, 2
a00ce370:  02 80 00 45  be  0xa00ce484
a00ce374:  80 a2 20 04  cmp  %o0, 4
a00ce378:  12 80 00 97  bne  0xa00ce5d4
a00ce37c:  01 00 00 00  nop
a00ce380:  30 80 00 7c  b,a   0xa00ce570
a00ce384:  02 80 00 36  be  0xa00ce45c
a00ce388:  80 a2 20 40  cmp  %o0, 0x40
a00ce38c:  14 80 00 32  bg  0xa00ce454
a00ce390:  80 a2 20 80  cmp  %o0, 0x80
a00ce394:  80 a2 20 20  cmp  %o0, 0x20
a00ce398:  12 80 00 8f  bne  0xa00ce5d4
a00ce39c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ce3a0:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ce3a4:  b4 12 e0 78  or  %o3, 0x78, %i2	! 0xa802d078
a00ce3a8:  98 12 a0 d0  or  %o2, 0xd0, %o4
a00ce3ac:  92 10 20 36  mov  0x36, %o1
a00ce3b0:  90 10 20 30  mov  0x30, %o0
a00ce3b4:  9e 10 20 35  mov  0x35, %o7
a00ce3b8:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00ce3bc:  82 10 20 0d  mov  0xd, %g1
a00ce3c0:  de 2a e0 78  stb  %o7, [ %o3 + 0x78 ]
a00ce3c4:  c0 2b 60 9c  clrb  [ %o5 + 0x9c ]
a00ce3c8:  c0 2a a0 d0  clrb  [ %o2 + 0xd0 ]
a00ce3cc:  c0 2b 20 19  clrb  [ %o4 + 0x19 ]
a00ce3d0:  d0 2e a0 03  stb  %o0, [ %i2 + 3 ]
a00ce3d4:  d2 2e a0 04  stb  %o1, [ %i2 + 4 ]
a00ce3d8:  c2 2e a0 05  stb  %g1, [ %i2 + 5 ]
a00ce3dc:  c0 2b 20 01  clrb  [ %o4 + 1 ]
a00ce3e0:  c0 2b 20 07  clrb  [ %o4 + 7 ]
a00ce3e4:  c0 2b 20 0a  clrb  [ %o4 + 0xa ]
a00ce3e8:  d2 2e a0 01  stb  %o1, [ %i2 + 1 ]
a00ce3ec:  10 80 00 17  b  0xa00ce448
a00ce3f0:  d0 2e a0 02  stb  %o0, [ %i2 + 2 ]
a00ce3f4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ce3f8:  b4 12 a0 78  or  %o2, 0x78, %i2	! 0xa802d078
a00ce3fc:  a2 12 60 d0  or  %o1, 0xd0, %l1
a00ce400:  a0 10 20 30  mov  0x30, %l0
a00ce404:  82 10 20 35  mov  0x35, %g1
a00ce408:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00ce40c:  90 10 20 36  mov  0x36, %o0
a00ce410:  b2 10 20 2d  mov  0x2d, %i1
a00ce414:  b0 10 20 0d  mov  0xd, %i0
a00ce418:  c2 2a a0 78  stb  %g1, [ %o2 + 0x78 ]
a00ce41c:  c0 2b 20 9c  clrb  [ %o4 + 0x9c ]
a00ce420:  c0 2a 60 d0  clrb  [ %o1 + 0xd0 ]
a00ce424:  c0 2c 60 19  clrb  [ %l1 + 0x19 ]
a00ce428:  d0 2e a0 01  stb  %o0, [ %i2 + 1 ]
a00ce42c:  e0 2e a0 03  stb  %l0, [ %i2 + 3 ]
a00ce430:  f2 2e a0 04  stb  %i1, [ %i2 + 4 ]
a00ce434:  f0 2e a0 05  stb  %i0, [ %i2 + 5 ]
a00ce438:  c0 2c 60 01  clrb  [ %l1 + 1 ]
a00ce43c:  c0 2c 60 07  clrb  [ %l1 + 7 ]
a00ce440:  c0 2c 60 0a  clrb  [ %l1 + 0xa ]
a00ce444:  e0 2e a0 02  stb  %l0, [ %i2 + 2 ]
a00ce448:  b0 10 20 04  mov  4, %i0
a00ce44c:  40 01 e8 e7  call  0xa01487e8
a00ce450:  93 e8 20 06  restore  %g0, 6, %o1
a00ce454:  12 80 00 60  bne  0xa00ce5d4
a00ce458:  01 00 00 00  nop
a00ce45c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ce460:  94 12 e0 d0  or  %o3, 0xd0, %o2	! 0xa802d0d0
a00ce464:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00ce468:  c0 2b e0 9c  clrb  [ %o7 + 0x9c ]	! 0xa802b09c
a00ce46c:  c0 2a e0 d0  clrb  [ %o3 + 0xd0 ]
a00ce470:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00ce474:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00ce478:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00ce47c:  10 80 00 56  b  0xa00ce5d4
a00ce480:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00ce484:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00ce488:  a2 16 a0 d0  or  %i2, 0xd0, %l1	! 0xa802d0d0
a00ce48c:  a0 10 20 00  clr  %l0
a00ce490:  b0 10 20 00  clr  %i0
a00ce494:  b2 10 20 02  mov  2, %i1
a00ce498:  b4 10 20 02  mov  2, %i2
a00ce49c:  92 10 00 1a  mov  %i2, %o1
a00ce4a0:  40 02 18 67  call  0xa015463c
a00ce4a4:  90 10 00 18  mov  %i0, %o0
a00ce4a8:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00ce4ac:  b2 06 60 01  inc  %i1
a00ce4b0:  92 10 00 1a  mov  %i2, %o1
a00ce4b4:  80 a3 60 ff  cmp  %o5, 0xff
a00ce4b8:  02 80 00 09  be  0xa00ce4dc
a00ce4bc:  90 10 00 18  mov  %i0, %o0
a00ce4c0:  40 02 18 5f  call  0xa015463c
a00ce4c4:  01 00 00 00  nop
a00ce4c8:  9e 0a 20 ff  and  %o0, 0xff, %o7
a00ce4cc:  d6 0c 40 1a  ldub  [ %l1 + %i2 ], %o3
a00ce4d0:  80 a3 c0 0b  cmp  %o7, %o3
a00ce4d4:  12 80 00 07  bne  0xa00ce4f0
a00ce4d8:  80 a6 a0 07  cmp  %i2, 7
a00ce4dc:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00ce4e0:  80 a6 a0 06  cmp  %i2, 6
a00ce4e4:  08 bf ff ef  bleu  0xa00ce4a0
a00ce4e8:  92 10 00 1a  mov  %i2, %o1
a00ce4ec:  80 a6 a0 07  cmp  %i2, 7
a00ce4f0:  02 80 00 08  be  0xa00ce510
a00ce4f4:  90 10 00 18  mov  %i0, %o0
a00ce4f8:  a0 04 20 01  inc  %l0
a00ce4fc:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00ce500:  80 a6 20 82  cmp  %i0, 0x82
a00ce504:  28 bf ff e5  bleu,a   0xa00ce498
a00ce508:  b2 10 20 02  mov  2, %i1
a00ce50c:  90 10 20 ff  mov  0xff, %o0
a00ce510:  92 0a 20 ff  and  %o0, 0xff, %o1
a00ce514:  80 a2 60 82  cmp  %o1, 0x82
a00ce518:  38 80 00 06  bgu,a   0xa00ce530
a00ce51c:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00ce520:  7f ff c5 e9  call  0xa00bfcc4
a00ce524:  90 10 20 04  mov  4, %o0
a00ce528:  10 bf ff ce  b  0xa00ce460
a00ce52c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ce530:  94 16 20 78  or  %i0, 0x78, %o2
a00ce534:  a0 10 20 36  mov  0x36, %l0
a00ce538:  96 10 20 30  mov  0x30, %o3
a00ce53c:  b2 10 20 35  mov  0x35, %i1
a00ce540:  a2 10 20 0d  mov  0xd, %l1
a00ce544:  f2 2e 20 78  stb  %i1, [ %i0 + 0x78 ]
a00ce548:  d6 2a a0 03  stb  %o3, [ %o2 + 3 ]
a00ce54c:  e0 2a a0 04  stb  %l0, [ %o2 + 4 ]
a00ce550:  e2 2a a0 05  stb  %l1, [ %o2 + 5 ]
a00ce554:  e0 2a a0 01  stb  %l0, [ %o2 + 1 ]
a00ce558:  d6 2a a0 02  stb  %o3, [ %o2 + 2 ]
a00ce55c:  90 10 20 04  mov  4, %o0
a00ce560:  40 01 e8 a2  call  0xa01487e8
a00ce564:  92 10 20 06  mov  6, %o1
a00ce568:  10 bf ff be  b  0xa00ce460
a00ce56c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ce570:  7f ff b3 3c  call  0xa00bb260
a00ce574:  90 10 20 04  mov  4, %o0
a00ce578:  92 0a 20 ff  and  %o0, 0xff, %o1
a00ce57c:  80 a2 60 99  cmp  %o1, 0x99
a00ce580:  18 80 00 09  bgu  0xa00ce5a4
a00ce584:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00ce588:  7f ff fa 6b  call  0xa00ccf34
a00ce58c:  90 10 20 04  mov  4, %o0
a00ce590:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ce594:  80 a2 20 ff  cmp  %o0, 0xff
a00ce598:  32 bf ff b2  bne,a   0xa00ce460
a00ce59c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ce5a0:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00ce5a4:  94 16 a0 78  or  %i2, 0x78, %o2	! 0xa802d078
a00ce5a8:  96 10 20 30  mov  0x30, %o3
a00ce5ac:  9a 10 20 35  mov  0x35, %o5
a00ce5b0:  82 10 20 36  mov  0x36, %g1
a00ce5b4:  98 10 20 2d  mov  0x2d, %o4
a00ce5b8:  92 10 20 0d  mov  0xd, %o1
a00ce5bc:  da 2e a0 78  stb  %o5, [ %i2 + 0x78 ]
a00ce5c0:  c2 2a a0 01  stb  %g1, [ %o2 + 1 ]
a00ce5c4:  d6 2a a0 03  stb  %o3, [ %o2 + 3 ]
a00ce5c8:  d8 2a a0 04  stb  %o4, [ %o2 + 4 ]
a00ce5cc:  10 bf ff e3  b  0xa00ce558
a00ce5d0:  d2 2a a0 05  stb  %o1, [ %o2 + 5 ]
a00ce5d4:  81 c7 e0 08  ret
a00ce5d8:  81 e8 00 00  restore
