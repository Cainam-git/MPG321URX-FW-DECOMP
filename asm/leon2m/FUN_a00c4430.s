# leon2m FUN_a00c4430 0xa00c4430-0xa00c46d4 (676 bytes)
a00c4430:  9d e3 bf 98  save  %sp, -104, %sp
a00c4434:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00c4438:  80 a4 60 02  cmp  %l1, 2
a00c443c:  02 80 00 5d  be  0xa00c45b0
a00c4440:  80 a4 60 03  cmp  %l1, 3
a00c4444:  02 80 00 7b  be  0xa00c4630
a00c4448:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c444c:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c4450:  96 08 60 ff  and  %g1, 0xff, %o3
a00c4454:  94 02 ff d0  add  %o3, -48, %o2
a00c4458:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00c445c:  80 a3 60 01  cmp  %o5, 1
a00c4460:  18 80 00 9b  bgu  0xa00c46cc
a00c4464:  b0 10 20 ff  mov  0xff, %i0
a00c4468:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c446c:  a0 13 22 90  or  %o4, 0x290, %l0	! 0xa802d290
a00c4470:  d8 04 20 a8  ld  [ %l0 + 0xa8 ], %o4
a00c4474:  b1 33 20 07  srl  %o4, 7, %i0
a00c4478:  9e 0e 20 01  and  %i0, 1, %o7
a00c447c:  80 a3 40 0f  cmp  %o5, %o7
a00c4480:  02 80 00 0d  be  0xa00c44b4
a00c4484:  92 0b 60 01  and  %o5, 1, %o1
a00c4488:  90 0b 3f 7f  and  %o4, -129, %o0
a00c448c:  9b 2a 60 07  sll  %o1, 7, %o5
a00c4490:  82 12 00 0d  or  %o0, %o5, %g1
a00c4494:  7f ff 32 d1  call  0xa0090fd8
a00c4498:  c2 24 20 a8  st  %g1, [ %l0 + 0xa8 ]
a00c449c:  40 01 82 aa  call  0xa0124f44
a00c44a0:  01 00 00 00  nop
a00c44a4:  40 00 53 56  call  0xa00d91fc
a00c44a8:  90 10 20 00  clr  %o0	! 0x0
a00c44ac:  40 00 57 36  call  0xa00da184
a00c44b0:  01 00 00 00  nop
a00c44b4:  d4 04 20 a8  ld  [ %l0 + 0xa8 ], %o2
a00c44b8:  80 8a a0 80  btst  0x80, %o2
a00c44bc:  22 80 00 10  be,a   0xa00c44fc
a00c44c0:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00c44c4:  d6 0c 20 1f  ldub  [ %l0 + 0x1f ], %o3	! 0xa802b01f
a00c44c8:  80 a2 e0 00  cmp  %o3, 0
a00c44cc:  12 80 00 73  bne  0xa00c4698
a00c44d0:  01 00 00 00  nop
a00c44d4:  7f fe fc c4  call  0xa00837e4
a00c44d8:  01 00 00 00  nop
a00c44dc:  9e 0a 20 ff  and  %o0, 0xff, %o7
a00c44e0:  80 a3 e0 01  cmp  %o7, 1
a00c44e4:  22 80 00 76  be,a   0xa00c46bc
a00c44e8:  c0 2c 21 a4  clrb  [ %l0 + 0x1a4 ]
a00c44ec:  c0 2c 20 4a  clrb  [ %l0 + 0x4a ]
a00c44f0:  40 00 46 6f  call  0xa00d5eac
a00c44f4:  90 10 20 00  clr  %o0
a00c44f8:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00c44fc:  d8 0c 20 8e  ldub  [ %l0 + 0x8e ], %o4	! 0xa802b08e
a00c4500:  b0 13 20 02  or  %o4, 2, %i0
a00c4504:  80 a4 60 02  cmp  %l1, 2
a00c4508:  02 80 00 2d  be  0xa00c45bc
a00c450c:  f0 2c 20 8e  stb  %i0, [ %l0 + 0x8e ]
a00c4510:  80 a4 60 03  cmp  %l1, 3
a00c4514:  02 80 00 4a  be  0xa00c463c
a00c4518:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c451c:  94 14 20 78  or  %l0, 0x78, %o2	! 0xa802d078
a00c4520:  92 10 20 30  mov  0x30, %o1
a00c4524:  b0 10 20 35  mov  0x35, %i0
a00c4528:  9e 10 20 36  mov  0x36, %o7
a00c452c:  96 10 20 2b  mov  0x2b, %o3
a00c4530:  9a 10 20 0d  mov  0xd, %o5
a00c4534:  f0 2c 20 78  stb  %i0, [ %l0 + 0x78 ]
a00c4538:  de 2a a0 01  stb  %o7, [ %o2 + 1 ]
a00c453c:  d2 2a a0 03  stb  %o1, [ %o2 + 3 ]
a00c4540:  d6 2a a0 04  stb  %o3, [ %o2 + 4 ]
a00c4544:  da 2a a0 05  stb  %o5, [ %o2 + 5 ]
a00c4548:  80 a4 60 02  cmp  %l1, 2
a00c454c:  02 80 00 29  be  0xa00c45f0
a00c4550:  d2 2a a0 02  stb  %o1, [ %o2 + 2 ]
a00c4554:  80 a4 60 03  cmp  %l1, 3
a00c4558:  02 80 00 46  be  0xa00c4670
a00c455c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c4560:  9a 12 e0 d0  or  %o3, 0xd0, %o5	! 0xa802d0d0
a00c4564:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00c4568:  c0 2b e0 9c  clrb  [ %o7 + 0x9c ]	! 0xa802b09c
a00c456c:  c0 2a e0 d0  clrb  [ %o3 + 0xd0 ]
a00c4570:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00c4574:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00c4578:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00c457c:  80 a4 60 02  cmp  %l1, 2
a00c4580:  02 80 00 25  be  0xa00c4614
a00c4584:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00c4588:  80 a4 60 03  cmp  %l1, 3
a00c458c:  12 80 00 25  bne  0xa00c4620
a00c4590:  90 10 00 11  mov  %l1, %o0
a00c4594:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c4598:  94 16 21 08  or  %i0, 0x108, %o2	! 0xa802d108
a00c459c:  90 10 20 03  mov  3, %o0
a00c45a0:  40 02 10 92  call  0xa01487e8
a00c45a4:  92 10 20 06  mov  6, %o1
a00c45a8:  10 80 00 49  b  0xa00c46cc
a00c45ac:  b0 10 20 00  clr  %i0
a00c45b0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c45b4:  10 bf ff a7  b  0xa00c4450
a00c45b8:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c45bc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c45c0:  a2 12 a1 28  or  %o2, 0x128, %l1	! 0xa802d128
a00c45c4:  90 10 20 30  mov  0x30, %o0
a00c45c8:  96 10 20 35  mov  0x35, %o3
a00c45cc:  92 10 20 0d  mov  0xd, %o1
a00c45d0:  9a 10 20 36  mov  0x36, %o5
a00c45d4:  82 10 20 2b  mov  0x2b, %g1
a00c45d8:  d6 2a a1 28  stb  %o3, [ %o2 + 0x128 ]
a00c45dc:  d2 2c 60 05  stb  %o1, [ %l1 + 5 ]
a00c45e0:  da 2c 60 01  stb  %o5, [ %l1 + 1 ]
a00c45e4:  d0 2c 60 03  stb  %o0, [ %l1 + 3 ]
a00c45e8:  c2 2c 60 04  stb  %g1, [ %l1 + 4 ]
a00c45ec:  d0 2c 60 02  stb  %o0, [ %l1 + 2 ]
a00c45f0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c45f4:  94 13 20 40  or  %o4, 0x40, %o2	! 0xa802d040
a00c45f8:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00c45fc:  c0 2c 60 9a  clrb  [ %l1 + 0x9a ]	! 0xa802b09a
a00c4600:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00c4604:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c4608:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c460c:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c4610:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c4614:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c4618:  94 14 21 28  or  %l0, 0x128, %o2	! 0xa802d128
a00c461c:  90 10 20 02  mov  2, %o0
a00c4620:  40 02 10 72  call  0xa01487e8
a00c4624:  92 10 20 06  mov  6, %o1
a00c4628:  10 80 00 29  b  0xa00c46cc
a00c462c:  b0 10 20 00  clr  %i0
a00c4630:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c4634:  10 bf ff 87  b  0xa00c4450
a00c4638:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c463c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c4640:  9e 12 21 08  or  %o0, 0x108, %o7	! 0xa802d108
a00c4644:  a0 10 20 30  mov  0x30, %l0
a00c4648:  82 10 20 35  mov  0x35, %g1
a00c464c:  a2 10 20 0d  mov  0xd, %l1
a00c4650:  98 10 20 36  mov  0x36, %o4
a00c4654:  b0 10 20 2b  mov  0x2b, %i0
a00c4658:  c2 2a 21 08  stb  %g1, [ %o0 + 0x108 ]
a00c465c:  e2 2b e0 05  stb  %l1, [ %o7 + 5 ]
a00c4660:  d8 2b e0 01  stb  %o4, [ %o7 + 1 ]
a00c4664:  e0 2b e0 03  stb  %l0, [ %o7 + 3 ]
a00c4668:  f0 2b e0 04  stb  %i0, [ %o7 + 4 ]
a00c466c:  e0 2b e0 02  stb  %l0, [ %o7 + 2 ]
a00c4670:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c4674:  90 12 60 98  or  %o1, 0x98, %o0	! 0xa802d098
a00c4678:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c467c:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c4680:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]
a00c4684:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c4688:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c468c:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c4690:  10 bf ff c1  b  0xa00c4594
a00c4694:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c4698:  7f ff 32 50  call  0xa0090fd8
a00c469c:  c0 2c 20 1f  clrb  [ %l0 + 0x1f ]
a00c46a0:  40 01 82 29  call  0xa0124f44
a00c46a4:  01 00 00 00  nop
a00c46a8:  40 00 52 d5  call  0xa00d91fc
a00c46ac:  90 10 20 00  clr  %o0	! 0x0
a00c46b0:  40 00 56 e9  call  0xa00da254
a00c46b4:  01 00 00 00  nop
a00c46b8:  30 bf ff 87  b,a   0xa00c44d4
a00c46bc:  7f fe fa 8e  call  0xa00830f4
a00c46c0:  90 10 20 00  clr  %o0
a00c46c4:  10 bf ff 8b  b  0xa00c44f0
a00c46c8:  c0 2c 20 4a  clrb  [ %l0 + 0x4a ]
a00c46cc:  81 c7 e0 08  ret
a00c46d0:  81 e8 00 00  restore
