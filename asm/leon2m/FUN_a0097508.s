# leon2m FUN_a0097508 0xa0097508-0xa00976a8 (416 bytes)
a0097508:  9d e3 bf 98  save  %sp, -104, %sp
a009750c:  31 2a 00 ab  sethi  %hi(0xa802ac00), %i0
a0097510:  c2 06 23 ec  ld  [ %i0 + 0x3ec ], %g1	! 0xa802afec
a0097514:  80 a0 60 23  cmp  %g1, 0x23
a0097518:  02 80 00 35  be  0xa00975ec
a009751c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a0097520:  7f ff b0 b1  call  0xa00837e4
a0097524:  01 00 00 00  nop
a0097528:  92 0a 20 ff  and  %o0, 0xff, %o1
a009752c:  80 a2 60 01  cmp  %o1, 1
a0097530:  02 80 00 36  be  0xa0097608
a0097534:  b2 14 22 90  or  %l0, 0x290, %i1
a0097538:  de 0e 61 a4  ldub  [ %i1 + 0x1a4 ], %o7
a009753c:  80 a3 e0 03  cmp  %o7, 3
a0097540:  02 80 00 38  be  0xa0097620
a0097544:  c2 06 60 b0  ld  [ %i1 + 0xb0 ], %g1
a0097548:  80 a0 60 00  cmp  %g1, 0
a009754c:  12 80 00 38  bne  0xa009762c
a0097550:  01 00 00 00  nop
a0097554:  da 06 60 ac  ld  [ %i1 + 0xac ], %o5
a0097558:  17 00 04 00  sethi  %hi(0x100000), %o3
a009755c:  98 2b 40 0b  andn  %o5, %o3, %o4
a0097560:  da 06 61 f4  ld  [ %i1 + 0x1f4 ], %o5
a0097564:  80 a3 60 00  cmp  %o5, 0
a0097568:  16 80 00 05  bge  0xa009757c
a009756c:  d8 26 60 ac  st  %o4, [ %i1 + 0xac ]
a0097570:  13 20 00 00  sethi  %hi(0x80000000), %o1
a0097574:  90 2b 40 09  andn  %o5, %o1, %o0
a0097578:  d0 26 61 f4  st  %o0, [ %i1 + 0x1f4 ]
a009757c:  d4 0e 60 4a  ldub  [ %i1 + 0x4a ], %o2
a0097580:  80 a2 a0 01  cmp  %o2, 1
a0097584:  22 80 00 43  be,a   0xa0097690
a0097588:  c0 2e 60 4a  clrb  [ %i1 + 0x4a ]
a009758c:  c2 06 60 a8  ld  [ %i1 + 0xa8 ], %g1
a0097590:  80 88 60 80  btst  0x80, %g1
a0097594:  12 80 00 36  bne  0xa009766c
a0097598:  9e 08 7f 7f  and  %g1, -129, %o7
a009759c:  96 14 22 90  or  %l0, 0x290, %o3
a00975a0:  f2 06 23 ec  ld  [ %i0 + 0x3ec ], %i1
a00975a4:  98 06 7f dd  add  %i1, -35, %o4
a00975a8:  f0 02 e0 ac  ld  [ %o3 + 0xac ], %i0
a00975ac:  21 00 04 00  sethi  %hi(0x100000), %l0
a00975b0:  80 8e 00 10  btst  %i0, %l0
a00975b4:  02 80 00 3b  be  0xa00976a0
a00975b8:  d8 2a e0 1f  stb  %o4, [ %o3 + 0x1f ]
a00975bc:  82 0b 20 ff  and  %o4, 0xff, %g1
a00975c0:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a00975c4:  d8 0b 60 56  ldub  [ %o5 + 0x56 ], %o4	! 0xa8025c56
a00975c8:  80 a0 40 0c  cmp  %g1, %o4
a00975cc:  02 80 00 35  be  0xa00976a0
a00975d0:  01 00 00 00  nop
a00975d4:  40 02 b4 0a  call  0xa01445fc
a00975d8:  d0 0a e0 1e  ldub  [ %o3 + 0x1e ], %o0
a00975dc:  80 8a 20 ff  btst  0xff, %o0
a00975e0:  12 80 00 30  bne  0xa00976a0
a00975e4:  01 00 00 00  nop
a00975e8:  30 80 00 15  b,a   0xa009763c
a00975ec:  98 14 22 90  or  %l0, 0x290, %o4
a00975f0:  11 2a 00 97  sethi  %hi(0xa8025c00), %o0
a00975f4:  d6 0a 20 55  ldub  [ %o0 + 0x55 ], %o3	! 0xa8025c55
a00975f8:  da 0b 20 8f  ldub  [ %o4 + 0x8f ], %o5
a00975fc:  da 2b 20 19  stb  %o5, [ %o4 + 0x19 ]
a0097600:  10 bf ff e7  b  0xa009759c
a0097604:  d6 2b 21 a4  stb  %o3, [ %o4 + 0x1a4 ]
a0097608:  94 14 22 90  or  %l0, 0x290, %o2
a009760c:  c0 2a a1 a4  clrb  [ %o2 + 0x1a4 ]
a0097610:  de 0e 61 a4  ldub  [ %i1 + 0x1a4 ], %o7
a0097614:  80 a3 e0 03  cmp  %o7, 3
a0097618:  12 bf ff cc  bne  0xa0097548
a009761c:  c2 06 60 b0  ld  [ %i1 + 0xb0 ], %g1
a0097620:  80 a0 60 00  cmp  %g1, 0
a0097624:  02 bf ff cc  be  0xa0097554
a0097628:  c0 2e 61 a4  clrb  [ %i1 + 0x1a4 ]
a009762c:  40 00 fa 44  call  0xa00d5f3c
a0097630:  c0 26 60 b0  clr  [ %i1 + 0xb0 ]
a0097634:  10 bf ff c9  b  0xa0097558
a0097638:  da 06 60 ac  ld  [ %i1 + 0xac ], %o5
a009763c:  40 02 36 42  call  0xa0124f44
a0097640:  b0 10 20 01  mov  1, %i0
a0097644:  40 01 06 ee  call  0xa00d91fc
a0097648:  90 10 20 00  clr  %o0
a009764c:  90 10 20 10  mov  0x10, %o0
a0097650:  40 02 b0 e2  call  0xa01439d8
a0097654:  92 10 20 01  mov  1, %o1
a0097658:  90 10 20 00  clr  %o0
a009765c:  40 02 c3 03  call  0xa0148268
a0097660:  92 10 20 01  mov  1, %o1
a0097664:  40 02 c3 01  call  0xa0148268
a0097668:  93 e8 20 01  restore  %g0, 1, %o1
a009766c:  de 26 60 a8  st  %o7, [ %i1 + 0xa8 ]
a0097670:  40 02 36 35  call  0xa0124f44
a0097674:  01 00 00 00  nop
a0097678:  40 01 06 e1  call  0xa00d91fc
a009767c:  90 10 20 00  clr  %o0	! 0x0
a0097680:  40 01 0a c1  call  0xa00da184
a0097684:  01 00 00 00  nop
a0097688:  10 bf ff c6  b  0xa00975a0
a009768c:  96 14 22 90  or  %l0, 0x290, %o3
a0097690:  40 00 fa 07  call  0xa00d5eac
a0097694:  90 10 20 00  clr  %o0
a0097698:  10 bf ff be  b  0xa0097590
a009769c:  c2 06 60 a8  ld  [ %i1 + 0xa8 ], %g1
a00976a0:  81 c7 e0 08  ret
a00976a4:  81 e8 00 00  restore
