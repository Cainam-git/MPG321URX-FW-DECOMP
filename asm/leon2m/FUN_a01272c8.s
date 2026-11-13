# leon2m FUN_a01272c8 0xa01272c8-0xa012743c (372 bytes)
a01272c8:  9d e3 bf 90  save  %sp, -112, %sp
a01272cc:  2b 2a 00 b6  sethi  %hi(0xa802d800), %l5
a01272d0:  a2 15 60 90  or  %l5, 0x90, %l1	! 0xa802d890
a01272d4:  f0 2c 60 01  stb  %i0, [ %l1 + 1 ]
a01272d8:  7f ff f5 7c  call  0xa01248c8
a01272dc:  c0 2d 60 90  clrb  [ %l5 + 0x90 ]
a01272e0:  80 8a 20 ff  btst  0xff, %o0
a01272e4:  02 80 00 54  be  0xa0127434
a01272e8:  15 00 06 92  sethi  %hi(0x1a4800), %o2
a01272ec:  92 0e 20 ff  and  %i0, 0xff, %o1
a01272f0:  7f fe df a0  call  0xa00df170
a01272f4:  90 12 a0 78  or  %o2, 0x78, %o0
a01272f8:  82 10 20 01  mov  1, %g1
a01272fc:  a4 10 20 02  mov  2, %l2
a0127300:  c2 23 a0 60  st  %g1, [ %sp + 0x60 ]
a0127304:  9a 10 00 11  mov  %l1, %o5
a0127308:  92 10 20 02  mov  2, %o1
a012730c:  94 10 21 b6  mov  0x1b6, %o2
a0127310:  96 10 20 05  mov  5, %o3
a0127314:  98 10 20 00  clr  %o4
a0127318:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a012731c:  40 00 81 e1  call  0xa0147aa0
a0127320:  90 10 20 60  mov  0x60, %o0
a0127324:  67 fd 97 9f  call  0x4008d1a0
a0127328:  90 10 20 32  mov  0x32, %o0
a012732c:  2d 2a 00 b6  sethi  %hi(0xa802d800), %l6
a0127330:  96 10 20 05  mov  5, %o3
a0127334:  98 10 20 00  clr  %o4
a0127338:  9a 15 a0 88  or  %l6, 0x88, %o5
a012733c:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a0127340:  92 10 20 02  mov  2, %o1
a0127344:  94 10 21 b6  mov  0x1b6, %o2
a0127348:  40 00 81 e8  call  0xa0147ae8
a012734c:  90 10 20 60  mov  0x60, %o0
a0127350:  a0 15 a0 88  or  %l6, 0x88, %l0
a0127354:  11 00 06 92  sethi  %hi(0x1a4800), %o0
a0127358:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a012735c:  d2 0d a0 88  ldub  [ %l6 + 0x88 ], %o1
a0127360:  7f fe df 84  call  0xa00df170
a0127364:  90 12 20 a0  or  %o0, 0xa0, %o0
a0127368:  a4 10 00 11  mov  %l1, %l2
a012736c:  90 10 20 32  mov  0x32, %o0
a0127370:  67 fd 97 8c  call  0x4008d1a0
a0127374:  a2 10 00 10  mov  %l0, %l1
a0127378:  a8 10 00 15  mov  %l5, %l4
a012737c:  a6 10 00 16  mov  %l6, %l3
a0127380:  10 80 00 1f  b  0xa01273fc
a0127384:  a0 10 20 02  mov  2, %l0
a0127388:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a012738c:  80 a2 e0 09  cmp  %o3, 9
a0127390:  18 80 00 29  bgu  0xa0127434
a0127394:  d2 0d 20 90  ldub  [ %l4 + 0x90 ], %o1
a0127398:  7f fe df 76  call  0xa00df170
a012739c:  d6 0c e0 88  ldub  [ %l3 + 0x88 ], %o3
a01273a0:  98 10 20 01  mov  1, %o4
a01273a4:  d8 23 a0 60  st  %o4, [ %sp + 0x60 ]
a01273a8:  92 10 20 02  mov  2, %o1
a01273ac:  94 10 21 b6  mov  0x1b6, %o2
a01273b0:  96 10 20 05  mov  5, %o3
a01273b4:  98 10 20 00  clr  %o4
a01273b8:  9a 10 00 12  mov  %l2, %o5
a01273bc:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a01273c0:  40 00 81 b8  call  0xa0147aa0
a01273c4:  90 10 20 60  mov  0x60, %o0
a01273c8:  67 fd 97 76  call  0x4008d1a0
a01273cc:  90 10 20 05  mov  5, %o0
a01273d0:  92 10 20 02  mov  2, %o1
a01273d4:  96 10 20 05  mov  5, %o3
a01273d8:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a01273dc:  90 10 20 60  mov  0x60, %o0
a01273e0:  94 10 21 b6  mov  0x1b6, %o2
a01273e4:  98 10 20 00  clr  %o4
a01273e8:  40 00 81 c0  call  0xa0147ae8
a01273ec:  9a 10 00 11  mov  %l1, %o5
a01273f0:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a01273f4:  92 02 e0 01  add  %o3, 1, %o1
a01273f8:  d2 2e 21 fd  stb  %o1, [ %i0 + 0x1fd ]
a01273fc:  31 00 06 92  sethi  %hi(0x1a4800), %i0
a0127400:  da 0c a0 01  ldub  [ %l2 + 1 ], %o5
a0127404:  de 0c 60 01  ldub  [ %l1 + 1 ], %o7
a0127408:  90 16 20 c8  or  %i0, 0xc8, %o0
a012740c:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a0127410:  94 10 00 0d  mov  %o5, %o2
a0127414:  80 a3 40 0f  cmp  %o5, %o7
a0127418:  12 bf ff dc  bne  0xa0127388
a012741c:  98 10 00 0f  mov  %o7, %o4
a0127420:  d2 0d 60 90  ldub  [ %l5 + 0x90 ], %o1
a0127424:  c2 0d a0 88  ldub  [ %l6 + 0x88 ], %g1
a0127428:  80 a2 40 01  cmp  %o1, %g1
a012742c:  12 bf ff d8  bne  0xa012738c
a0127430:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0127434:  81 c7 e0 08  ret
a0127438:  81 e8 00 00  restore
