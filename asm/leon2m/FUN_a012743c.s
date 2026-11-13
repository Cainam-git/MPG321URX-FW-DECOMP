# leon2m FUN_a012743c 0xa012743c-0xa01275b0 (372 bytes)
a012743c:  9d e3 bf 90  save  %sp, -112, %sp
a0127440:  2b 2a 00 b6  sethi  %hi(0xa802d800), %l5
a0127444:  a2 15 60 90  or  %l5, 0x90, %l1	! 0xa802d890
a0127448:  f0 2c 60 01  stb  %i0, [ %l1 + 1 ]
a012744c:  7f ff f5 1f  call  0xa01248c8
a0127450:  c0 2d 60 90  clrb  [ %l5 + 0x90 ]
a0127454:  80 8a 20 ff  btst  0xff, %o0
a0127458:  02 80 00 54  be  0xa01275a8
a012745c:  15 00 06 92  sethi  %hi(0x1a4800), %o2
a0127460:  92 0e 20 ff  and  %i0, 0xff, %o1
a0127464:  7f fe df 43  call  0xa00df170
a0127468:  90 12 a1 00  or  %o2, 0x100, %o0
a012746c:  82 10 20 01  mov  1, %g1
a0127470:  a4 10 20 02  mov  2, %l2
a0127474:  c2 23 a0 60  st  %g1, [ %sp + 0x60 ]
a0127478:  9a 10 00 11  mov  %l1, %o5
a012747c:  92 10 20 02  mov  2, %o1
a0127480:  94 10 21 b2  mov  0x1b2, %o2
a0127484:  96 10 20 05  mov  5, %o3
a0127488:  98 10 20 00  clr  %o4
a012748c:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a0127490:  40 00 81 84  call  0xa0147aa0
a0127494:  90 10 20 60  mov  0x60, %o0
a0127498:  67 fd 97 42  call  0x4008d1a0
a012749c:  90 10 20 32  mov  0x32, %o0
a01274a0:  2d 2a 00 b6  sethi  %hi(0xa802d800), %l6
a01274a4:  96 10 20 05  mov  5, %o3
a01274a8:  98 10 20 00  clr  %o4
a01274ac:  9a 15 a0 88  or  %l6, 0x88, %o5
a01274b0:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a01274b4:  92 10 20 02  mov  2, %o1
a01274b8:  94 10 21 b2  mov  0x1b2, %o2
a01274bc:  40 00 81 8b  call  0xa0147ae8
a01274c0:  90 10 20 60  mov  0x60, %o0
a01274c4:  a0 15 a0 88  or  %l6, 0x88, %l0
a01274c8:  11 00 06 92  sethi  %hi(0x1a4800), %o0
a01274cc:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a01274d0:  d2 0d a0 88  ldub  [ %l6 + 0x88 ], %o1
a01274d4:  7f fe df 27  call  0xa00df170
a01274d8:  90 12 21 28  or  %o0, 0x128, %o0
a01274dc:  a4 10 00 11  mov  %l1, %l2
a01274e0:  90 10 20 32  mov  0x32, %o0
a01274e4:  67 fd 97 2f  call  0x4008d1a0
a01274e8:  a2 10 00 10  mov  %l0, %l1
a01274ec:  a8 10 00 15  mov  %l5, %l4
a01274f0:  a6 10 00 16  mov  %l6, %l3
a01274f4:  10 80 00 1f  b  0xa0127570
a01274f8:  a0 10 20 02  mov  2, %l0
a01274fc:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0127500:  80 a2 e0 09  cmp  %o3, 9
a0127504:  18 80 00 29  bgu  0xa01275a8
a0127508:  d2 0d 20 90  ldub  [ %l4 + 0x90 ], %o1
a012750c:  7f fe df 19  call  0xa00df170
a0127510:  d6 0c e0 88  ldub  [ %l3 + 0x88 ], %o3
a0127514:  98 10 20 01  mov  1, %o4
a0127518:  d8 23 a0 60  st  %o4, [ %sp + 0x60 ]
a012751c:  92 10 20 02  mov  2, %o1
a0127520:  94 10 21 b2  mov  0x1b2, %o2
a0127524:  96 10 20 05  mov  5, %o3
a0127528:  98 10 20 00  clr  %o4
a012752c:  9a 10 00 12  mov  %l2, %o5
a0127530:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a0127534:  40 00 81 5b  call  0xa0147aa0
a0127538:  90 10 20 60  mov  0x60, %o0
a012753c:  67 fd 97 19  call  0x4008d1a0
a0127540:  90 10 20 05  mov  5, %o0
a0127544:  92 10 20 02  mov  2, %o1
a0127548:  96 10 20 05  mov  5, %o3
a012754c:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a0127550:  90 10 20 60  mov  0x60, %o0
a0127554:  94 10 21 b2  mov  0x1b2, %o2
a0127558:  98 10 20 00  clr  %o4
a012755c:  40 00 81 63  call  0xa0147ae8
a0127560:  9a 10 00 11  mov  %l1, %o5
a0127564:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0127568:  92 02 e0 01  add  %o3, 1, %o1
a012756c:  d2 2e 21 fd  stb  %o1, [ %i0 + 0x1fd ]
a0127570:  31 00 06 92  sethi  %hi(0x1a4800), %i0
a0127574:  da 0c a0 01  ldub  [ %l2 + 1 ], %o5
a0127578:  de 0c 60 01  ldub  [ %l1 + 1 ], %o7
a012757c:  90 16 21 50  or  %i0, 0x150, %o0
a0127580:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a0127584:  94 10 00 0d  mov  %o5, %o2
a0127588:  80 a3 40 0f  cmp  %o5, %o7
a012758c:  12 bf ff dc  bne  0xa01274fc
a0127590:  98 10 00 0f  mov  %o7, %o4
a0127594:  d2 0d 60 90  ldub  [ %l5 + 0x90 ], %o1
a0127598:  c2 0d a0 88  ldub  [ %l6 + 0x88 ], %g1
a012759c:  80 a2 40 01  cmp  %o1, %g1
a01275a0:  12 bf ff d8  bne  0xa0127500
a01275a4:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a01275a8:  81 c7 e0 08  ret
a01275ac:  81 e8 00 00  restore
