# leon2m FUN_a0104380 0xa0104380-0xa01045a0 (544 bytes)
a0104380:  9d e3 bf 98  save  %sp, -104, %sp
a0104384:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0104388:  92 10 20 50  mov  0x50, %o1
a010438c:  7f ff b7 b2  call  0xa00f2254
a0104390:  90 10 00 18  mov  %i0, %o0
a0104394:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a0104398:  d0 2c 21 82  stb  %o0, [ %l0 + 0x182 ]	! 0xa802c982
a010439c:  92 10 20 86  mov  0x86, %o1
a01043a0:  7f ff b7 ad  call  0xa00f2254
a01043a4:  90 10 00 18  mov  %i0, %o0
a01043a8:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a01043ac:  d0 2a e1 84  stb  %o0, [ %o3 + 0x184 ]	! 0xa802c984
a01043b0:  92 10 20 88  mov  0x88, %o1
a01043b4:  7f ff b7 a8  call  0xa00f2254
a01043b8:  90 10 00 18  mov  %i0, %o0
a01043bc:  13 33 c0 3a  sethi  %hi(0xcf00e800), %o1
a01043c0:  9e 12 62 c8  or  %o1, 0x2c8, %o7	! 0xcf00eac8
a01043c4:  e4 03 c0 00  ld  [ %o7 ], %l2
a01043c8:  d4 03 c0 00  ld  [ %o7 ], %o2
a01043cc:  82 0a bf ef  and  %o2, -17, %g1
a01043d0:  c2 23 c0 00  st  %g1, [ %o7 ]
a01043d4:  a6 12 61 c4  or  %o1, 0x1c4, %l3
a01043d8:  da 04 c0 00  ld  [ %l3 ], %o5
a01043dc:  35 2a 00 b2  sethi  %hi(0xa802c800), %i2
a01043e0:  a8 13 60 80  or  %o5, 0x80, %l4
a01043e4:  d0 2e a1 83  stb  %o0, [ %i2 + 0x183 ]
a01043e8:  e8 24 c0 00  st  %l4, [ %l3 ]
a01043ec:  a2 0c a0 ff  and  %l2, 0xff, %l1
a01043f0:  e2 23 c0 00  st  %l1, [ %o7 ]
a01043f4:  90 10 00 18  mov  %i0, %o0
a01043f8:  40 00 51 8c  call  0xa0118a28
a01043fc:  92 10 20 00  clr  %o1
a0104400:  94 10 20 00  clr  %o2
a0104404:  90 10 00 18  mov  %i0, %o0
a0104408:  7f ff b7 a4  call  0xa00f2298
a010440c:  92 10 20 54  mov  0x54, %o1
a0104410:  92 10 20 71  mov  0x71, %o1
a0104414:  7f ff b8 79  call  0xa00f25f8
a0104418:  90 10 00 18  mov  %i0, %o0
a010441c:  99 2a 20 10  sll  %o0, 0x10, %o4
a0104420:  a9 33 20 10  srl  %o4, 0x10, %l4
a0104424:  90 10 00 18  mov  %i0, %o0
a0104428:  92 10 20 64  mov  0x64, %o1
a010442c:  7f ff b8 17  call  0xa00f2488
a0104430:  94 10 00 14  mov  %l4, %o2
a0104434:  d6 0c 21 82  ldub  [ %l0 + 0x182 ], %o3
a0104438:  94 12 e0 20  or  %o3, 0x20, %o2
a010443c:  90 10 00 18  mov  %i0, %o0
a0104440:  7f ff b7 96  call  0xa00f2298
a0104444:  92 10 20 50  mov  0x50, %o1
a0104448:  92 10 20 84  mov  0x84, %o1
a010444c:  7f ff b8 af  call  0xa00f2708
a0104450:  90 10 00 18  mov  %i0, %o0
a0104454:  95 2a 20 10  sll  %o0, 0x10, %o2
a0104458:  91 32 a0 10  srl  %o2, 0x10, %o0
a010445c:  93 2a 20 02  sll  %o0, 2, %o1
a0104460:  82 02 40 08  add  %o1, %o0, %g1
a0104464:  9b 2d 20 03  sll  %l4, 3, %o5
a0104468:  82 00 40 01  add  %g1, %g1, %g1
a010446c:  9a 03 40 14  add  %o5, %l4, %o5
a0104470:  80 a0 40 0d  cmp  %g1, %o5
a0104474:  04 80 00 20  ble  0xa01044f4
a0104478:  13 19 99 99  sethi  %hi(0x66666400), %o1
a010447c:  25 19 99 99  sethi  %hi(0x66666400), %l2
a0104480:  a0 20 40 0d  sub  %g1, %o5, %l0
a0104484:  a2 14 a2 67  or  %l2, 0x267, %l1
a0104488:  80 5c 00 11  smul  %l0, %l1, %g0
a010448c:  9f 40 00 00  rd  %y, %o7
a0104490:  99 3b e0 02  sra  %o7, 2, %o4
a0104494:  91 3c 20 1f  sra  %l0, 0x1f, %o0
a0104498:  a0 23 00 08  sub  %o4, %o0, %l0
a010449c:  90 10 00 18  mov  %i0, %o0
a01044a0:  7f ff b8 9a  call  0xa00f2708
a01044a4:  92 10 20 82  mov  0x82, %o1
a01044a8:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a01044ac:  da 02 e2 a4  ld  [ %o3 + 0x2a4 ], %o5	! 0xa802d6a4
a01044b0:  95 2a 20 10  sll  %o0, 0x10, %o2
a01044b4:  b5 32 a0 10  srl  %o2, 0x10, %i2
a01044b8:  c2 13 60 20  lduh  [ %o5 + 0x20 ], %g1
a01044bc:  80 a0 40 1a  cmp  %g1, %i2
a01044c0:  18 80 00 07  bgu  0xa01044dc
a01044c4:  90 10 00 18  mov  %i0, %o0
a01044c8:  d0 13 60 24  lduh  [ %o5 + 0x24 ], %o0
a01044cc:  80 a2 00 1a  cmp  %o0, %i2
a01044d0:  1a 80 00 0f  bcc  0xa010450c
a01044d4:  a3 2c 20 10  sll  %l0, 0x10, %l1
a01044d8:  90 10 00 18  mov  %i0, %o0
a01044dc:  92 10 20 86  mov  0x86, %o1
a01044e0:  7f ff b7 6e  call  0xa00f2298
a01044e4:  94 10 20 01  mov  1, %o2
a01044e8:  b2 10 20 88  mov  0x88, %i1
a01044ec:  7f ff b7 6b  call  0xa00f2298
a01044f0:  95 e8 20 06  restore  %g0, 6, %o2
a01044f4:  b4 00 40 14  add  %g1, %l4, %i2
a01044f8:  9a 12 62 67  or  %o1, 0x267, %o5
a01044fc:  80 5e 80 0d  smul  %i2, %o5, %g0
a0104500:  a7 40 00 00  rd  %y, %l3
a0104504:  10 bf ff e6  b  0xa010449c
a0104508:  a1 34 e0 02  srl  %l3, 2, %l0
a010450c:  e4 1e 40 00  ldd  [ %i1 ], %l2
a0104510:  95 3c 60 10  sra  %l1, 0x10, %o2
a0104514:  91 3c 60 1f  sra  %l1, 0x1f, %o0
a0104518:  a2 54 c0 0a  umul  %l3, %o2, %l1
a010451c:  a1 40 00 00  rd  %y, %l0
a0104520:  96 5c c0 08  smul  %l3, %o0, %o3
a0104524:  82 02 c0 10  add  %o3, %l0, %g1
a0104528:  92 5a 80 12  smul  %o2, %l2, %o1
a010452c:  9a 00 40 09  add  %g1, %o1, %o5
a0104530:  9e 5b 60 64  smul  %o5, 0x64, %o7
a0104534:  92 54 60 64  umul  %l1, 0x64, %o1
a0104538:  91 40 00 00  rd  %y, %o0
a010453c:  90 03 c0 08  add  %o7, %o0, %o0
a0104540:  96 10 00 14  mov  %l4, %o3
a0104544:  40 01 43 31  call  0xa0155208
a0104548:  94 10 20 00  clr  %o2
a010454c:  96 10 00 1a  mov  %i2, %o3
a0104550:  40 01 43 2e  call  0xa0155208
a0104554:  94 10 20 00  clr  %o2
a0104558:  94 10 20 00  clr  %o2
a010455c:  40 01 43 2b  call  0xa0155208
a0104560:  96 10 20 64  mov  0x64, %o3
a0104564:  a6 a4 c0 09  subcc  %l3, %o1, %l3
a0104568:  a9 3a 60 1f  sra  %o1, 0x1f, %l4
a010456c:  a4 64 80 14  subx  %l2, %l4, %l2
a0104570:  e4 3e 40 00  std  %l2, [ %i1 ]
a0104574:  d2 06 60 04  ld  [ %i1 + 4 ], %o1
a0104578:  7f ff f8 5c  call  0xa01026e8
a010457c:  90 10 20 00  clr  %o0
a0104580:  90 10 00 18  mov  %i0, %o0
a0104584:  92 10 20 86  mov  0x86, %o1
a0104588:  7f ff b7 44  call  0xa00f2298
a010458c:  94 10 20 01  mov  1, %o2
a0104590:  b2 10 20 88  mov  0x88, %i1
a0104594:  7f ff b7 41  call  0xa00f2298
a0104598:  95 e8 20 06  restore  %g0, 6, %o2
a010459c:  01 00 00 00  nop
