# leon2m FUN_a0084330 0xa0084330-0xa00844f8 (456 bytes)
a0084330:  9d e3 bf 98  save  %sp, -104, %sp
a0084334:  80 8e 20 ff  btst  0xff, %i0
a0084338:  02 80 00 07  be  0xa0084354
a008433c:  82 10 3f ff  mov  -1, %g1
a0084340:  1b 2a 00 90  sethi  %hi(0xa8024000), %o5
a0084344:  19 2a 00 ab  sethi  %hi(0xa802ac00), %o4
a0084348:  c2 2b 60 20  stb  %g1, [ %o5 + 0x20 ]
a008434c:  10 80 00 69  b  0xa00844f0
a0084350:  c0 33 23 56  clrh  [ %o4 + 0x356 ]
a0084354:  92 10 20 07  mov  7, %o1
a0084358:  40 03 04 c2  call  0xa0145660
a008435c:  90 10 20 01  mov  1, %o0
a0084360:  11 2a 00 90  sethi  %hi(0xa8024000), %o0
a0084364:  98 12 20 08  or  %o0, 8, %o4	! 0xa8024008
a0084368:  23 2a 00 90  sethi  %hi(0xa8024000), %l1
a008436c:  31 2a 00 90  sethi  %hi(0xa8024000), %i0
a0084370:  21 2a 00 90  sethi  %hi(0xa8024000), %l0
a0084374:  90 10 20 01  mov  1, %o0
a0084378:  92 14 60 06  or  %l1, 6, %o1
a008437c:  94 16 20 04  or  %i0, 4, %o2
a0084380:  40 03 28 4e  call  0xa014e4b8
a0084384:  96 14 20 0a  or  %l0, 0xa, %o3
a0084388:  80 8a 20 ff  btst  0xff, %o0
a008438c:  02 80 00 59  be  0xa00844f0
a0084390:  d0 14 60 06  lduh  [ %l1 + 6 ], %o0
a0084394:  9b 2a 20 02  sll  %o0, 2, %o5
a0084398:  98 03 40 08  add  %o5, %o0, %o4
a008439c:  ac 03 00 0c  add  %o4, %o4, %l6
a00843a0:  c2 16 20 04  lduh  [ %i0 + 4 ], %g1
a00843a4:  99 3d a0 1f  sra  %l6, 0x1f, %o4
a00843a8:  81 83 20 00  mov  %o4, %y
a00843ac:  01 00 00 00  nop
a00843b0:  01 00 00 00  nop
a00843b4:  01 00 00 00  nop
a00843b8:  92 7d 80 01  sdiv  %l6, %g1, %o1
a00843bc:  ab 2a 60 10  sll  %o1, 0x10, %l5
a00843c0:  2d 2a 00 ab  sethi  %hi(0xa802ac00), %l6
a00843c4:  a9 35 60 10  srl  %l5, 0x10, %l4
a00843c8:  e6 15 a3 56  lduh  [ %l6 + 0x356 ], %l3
a00843cc:  a4 24 c0 14  sub  %l3, %l4, %l2
a00843d0:  97 3c a0 1f  sra  %l2, 0x1f, %o3
a00843d4:  9e 1a c0 12  xor  %o3, %l2, %o7
a00843d8:  94 23 c0 0b  sub  %o7, %o3, %o2
a00843dc:  80 a2 a0 05  cmp  %o2, 5
a00843e0:  aa 10 00 09  mov  %o1, %l5
a00843e4:  14 80 00 03  bg  0xa00843f0
a00843e8:  b0 10 20 01  mov  1, %i0
a00843ec:  b0 10 20 00  clr  %i0
a00843f0:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a00843f4:  d2 14 20 0a  lduh  [ %l0 + 0xa ], %o1
a00843f8:  e8 14 a3 58  lduh  [ %l2 + 0x358 ], %l4
a00843fc:  a6 25 00 09  sub  %l4, %o1, %l3
a0084400:  97 3c e0 1f  sra  %l3, 0x1f, %o3
a0084404:  9e 1a c0 13  xor  %o3, %l3, %o7
a0084408:  94 23 c0 0b  sub  %o7, %o3, %o2
a008440c:  80 a2 a0 14  cmp  %o2, 0x14
a0084410:  14 80 00 0c  bg  0xa0084440
a0084414:  96 10 00 09  mov  %o1, %o3
a0084418:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a008441c:  de 12 a3 5a  lduh  [ %o2 + 0x35a ], %o7	! 0xa802af5a
a0084420:  da 14 60 06  lduh  [ %l1 + 6 ], %o5
a0084424:  92 23 c0 0d  sub  %o7, %o5, %o1
a0084428:  99 3a 60 1f  sra  %o1, 0x1f, %o4
a008442c:  90 1b 00 09  xor  %o4, %o1, %o0
a0084430:  82 22 00 0c  sub  %o0, %o4, %g1
a0084434:  80 a0 60 0f  cmp  %g1, 0xf
a0084438:  04 80 00 1a  ble  0xa00844a0
a008443c:  27 2a 00 ab  sethi  %hi(0xa802ac00), %l3
a0084440:  27 2a 00 ab  sethi  %hi(0xa802ac00), %l3
a0084444:  d6 0c e3 5c  ldub  [ %l3 + 0x35c ], %o3	! 0xa802af5c
a0084448:  94 02 e0 01  add  %o3, 1, %o2
a008444c:  d4 2c e3 5c  stb  %o2, [ %l3 + 0x35c ]
a0084450:  29 2a 00 90  sethi  %hi(0xa8024000), %l4
a0084454:  c2 0d 20 20  ldub  [ %l4 + 0x20 ], %g1	! 0xa8024020
a0084458:  9a 0e 20 ff  and  %i0, 0xff, %o5
a008445c:  80 a0 40 0d  cmp  %g1, %o5
a0084460:  02 80 00 14  be  0xa00844b0
a0084464:  d0 0c e3 5c  ldub  [ %l3 + 0x35c ], %o0
a0084468:  80 a3 60 01  cmp  %o5, 1
a008446c:  02 80 00 17  be  0xa00844c8
a0084470:  01 00 00 00  nop
a0084474:  7f ff fb 20  call  0xa00830f4
a0084478:  90 10 20 01  mov  1, %o0	! 0x1
a008447c:  d8 14 20 0a  lduh  [ %l0 + 0xa ], %o4
a0084480:  da 14 60 06  lduh  [ %l1 + 6 ], %o5
a0084484:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0084488:  d8 34 a3 58  sth  %o4, [ %l2 + 0x358 ]
a008448c:  da 34 23 5a  sth  %o5, [ %l0 + 0x35a ]
a0084490:  c0 2c e3 5c  clrb  [ %l3 + 0x35c ]
a0084494:  ea 35 a3 56  sth  %l5, [ %l6 + 0x356 ]
a0084498:  10 80 00 16  b  0xa00844f0
a008449c:  f0 2d 20 20  stb  %i0, [ %l4 + 0x20 ]
a00844a0:  da 32 a3 5a  sth  %o5, [ %o2 + 0x35a ]
a00844a4:  d6 34 a3 58  sth  %o3, [ %l2 + 0x358 ]
a00844a8:  10 bf ff ea  b  0xa0084450
a00844ac:  c0 2c e3 5c  clrb  [ %l3 + 0x35c ]
a00844b0:  80 a2 20 0a  cmp  %o0, 0xa
a00844b4:  18 bf ff ee  bgu  0xa008446c
a00844b8:  80 a3 60 01  cmp  %o5, 1
a00844bc:  ea 35 a3 56  sth  %l5, [ %l6 + 0x356 ]
a00844c0:  10 80 00 0c  b  0xa00844f0
a00844c4:  f0 2d 20 20  stb  %i0, [ %l4 + 0x20 ]
a00844c8:  7f ff fb 0b  call  0xa00830f4
a00844cc:  90 10 20 01  mov  1, %o0
a00844d0:  40 01 4d 94  call  0xa00d7b20
a00844d4:  01 00 00 00  nop
a00844d8:  90 10 20 01  mov  1, %o0	! 0x1
a00844dc:  92 10 20 01  mov  1, %o1
a00844e0:  40 03 18 fd  call  0xa014a8d4
a00844e4:  94 10 21 f4  mov  0x1f4, %o2
a00844e8:  10 bf ff e6  b  0xa0084480
a00844ec:  d8 14 20 0a  lduh  [ %l0 + 0xa ], %o4
a00844f0:  81 c7 e0 08  ret
a00844f4:  81 e8 00 00  restore
