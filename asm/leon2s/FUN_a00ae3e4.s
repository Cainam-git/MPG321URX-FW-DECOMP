# leon2s FUN_a00ae3e4 0xa00ae3e4-0xa00ae5e4 (512 bytes)
a00ae3e4:  9d e3 bf 98  save  %sp, -104, %sp
a00ae3e8:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a00ae3ec:  98 10 60 40  or  %g1, 0x40, %o4	! 0xcf03c840
a00ae3f0:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00ae3f4:  90 10 63 ff  or  %g1, 0x3ff, %o0	! 0xffff
a00ae3f8:  94 10 3f ff  mov  -1, %o2
a00ae3fc:  92 10 20 02  mov  2, %o1
a00ae400:  82 02 bf ff  add  %o2, -1, %g1
a00ae404:  9b 28 60 10  sll  %g1, 0x10, %o5
a00ae408:  97 33 60 10  srl  %o5, 0x10, %o3
a00ae40c:  da 03 00 00  ld  [ %o4 ], %o5
a00ae410:  80 a3 60 01  cmp  %o5, 1
a00ae414:  02 80 00 03  be  0xa00ae420
a00ae418:  94 10 00 01  mov  %g1, %o2
a00ae41c:  d2 23 00 00  st  %o1, [ %o4 ]
a00ae420:  c2 03 00 00  ld  [ %o4 ], %g1
a00ae424:  80 a0 60 02  cmp  %g1, 2
a00ae428:  02 80 00 04  be  0xa00ae438
a00ae42c:  80 a2 c0 08  cmp  %o3, %o0
a00ae430:  12 bf ff f5  bne  0xa00ae404
a00ae434:  82 02 bf ff  add  %o2, -1, %g1
a00ae438:  82 10 20 02  mov  2, %g1
a00ae43c:  1b 33 c0 1e  sethi  %hi(0xcf007800), %o5
a00ae440:  c2 23 00 00  st  %g1, [ %o4 ]
a00ae444:  9a 13 60 0c  or  %o5, 0xc, %o5
a00ae448:  c2 03 40 00  ld  [ %o5 ], %g1
a00ae44c:  82 10 60 28  or  %g1, 0x28, %g1
a00ae450:  c2 23 40 00  st  %g1, [ %o5 ]
a00ae454:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a00ae458:  c0 23 00 00  clr  [ %o4 ]
a00ae45c:  98 10 60 40  or  %g1, 0x40, %o4
a00ae460:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00ae464:  90 10 63 ff  or  %g1, 0x3ff, %o0	! 0xffff
a00ae468:  94 10 3f ff  mov  -1, %o2
a00ae46c:  92 10 20 02  mov  2, %o1
a00ae470:  82 02 bf ff  add  %o2, -1, %g1
a00ae474:  9b 28 60 10  sll  %g1, 0x10, %o5
a00ae478:  97 33 60 10  srl  %o5, 0x10, %o3
a00ae47c:  da 03 00 00  ld  [ %o4 ], %o5
a00ae480:  80 a3 60 01  cmp  %o5, 1
a00ae484:  02 80 00 03  be  0xa00ae490
a00ae488:  94 10 00 01  mov  %g1, %o2
a00ae48c:  d2 23 00 00  st  %o1, [ %o4 ]
a00ae490:  c2 03 00 00  ld  [ %o4 ], %g1
a00ae494:  80 a0 60 02  cmp  %g1, 2
a00ae498:  02 80 00 04  be  0xa00ae4a8
a00ae49c:  80 a2 c0 08  cmp  %o3, %o0
a00ae4a0:  12 bf ff f5  bne  0xa00ae474
a00ae4a4:  82 02 bf ff  add  %o2, -1, %g1
a00ae4a8:  82 10 20 02  mov  2, %g1
a00ae4ac:  1b 33 c0 b4  sethi  %hi(0xcf02d000), %o5
a00ae4b0:  c2 23 00 00  st  %g1, [ %o4 ]
a00ae4b4:  9a 13 61 00  or  %o5, 0x100, %o5
a00ae4b8:  c2 03 40 00  ld  [ %o5 ], %g1
a00ae4bc:  82 10 60 01  or  %g1, 1, %g1
a00ae4c0:  c2 23 40 00  st  %g1, [ %o5 ]
a00ae4c4:  c0 23 00 00  clr  [ %o4 ]
a00ae4c8:  94 10 20 f1  mov  0xf1, %o2
a00ae4cc:  90 10 20 00  clr  %o0
a00ae4d0:  7f ff e5 0b  call  0xa00a78fc
a00ae4d4:  92 10 20 13  mov  0x13, %o1
a00ae4d8:  92 10 20 14  mov  0x14, %o1
a00ae4dc:  7f ff e4 f6  call  0xa00a78b4
a00ae4e0:  90 10 20 00  clr  %o0
a00ae4e4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ae4e8:  94 0a 20 ff  and  %o0, 0xff, %o2
a00ae4ec:  90 10 00 18  mov  %i0, %o0
a00ae4f0:  7f ff e1 c4  call  0xa00a6c00
a00ae4f4:  92 10 20 ca  mov  0xca, %o1
a00ae4f8:  94 10 20 f9  mov  0xf9, %o2
a00ae4fc:  90 10 20 00  clr  %o0
a00ae500:  7f ff e4 ff  call  0xa00a78fc
a00ae504:  92 10 20 13  mov  0x13, %o1
a00ae508:  92 10 20 14  mov  0x14, %o1
a00ae50c:  7f ff e4 ea  call  0xa00a78b4
a00ae510:  90 10 20 00  clr  %o0
a00ae514:  94 0a 20 ff  and  %o0, 0xff, %o2
a00ae518:  90 10 00 18  mov  %i0, %o0
a00ae51c:  7f ff e1 b9  call  0xa00a6c00
a00ae520:  92 10 20 cb  mov  0xcb, %o1
a00ae524:  94 10 20 f3  mov  0xf3, %o2
a00ae528:  90 10 20 00  clr  %o0
a00ae52c:  7f ff e4 f4  call  0xa00a78fc
a00ae530:  92 10 20 13  mov  0x13, %o1
a00ae534:  92 10 20 14  mov  0x14, %o1
a00ae538:  7f ff e4 df  call  0xa00a78b4
a00ae53c:  90 10 20 00  clr  %o0
a00ae540:  94 0a 20 ff  and  %o0, 0xff, %o2
a00ae544:  90 10 00 18  mov  %i0, %o0
a00ae548:  7f ff e1 ae  call  0xa00a6c00
a00ae54c:  92 10 20 cc  mov  0xcc, %o1
a00ae550:  94 10 20 fb  mov  0xfb, %o2
a00ae554:  90 10 20 00  clr  %o0
a00ae558:  7f ff e4 e9  call  0xa00a78fc
a00ae55c:  92 10 20 13  mov  0x13, %o1
a00ae560:  92 10 20 14  mov  0x14, %o1
a00ae564:  7f ff e4 d4  call  0xa00a78b4
a00ae568:  90 10 20 00  clr  %o0
a00ae56c:  94 0a 20 ff  and  %o0, 0xff, %o2
a00ae570:  90 10 00 18  mov  %i0, %o0
a00ae574:  7f ff e1 a3  call  0xa00a6c00
a00ae578:  92 10 20 cd  mov  0xcd, %o1
a00ae57c:  94 10 20 f5  mov  0xf5, %o2
a00ae580:  90 10 20 00  clr  %o0
a00ae584:  7f ff e4 de  call  0xa00a78fc
a00ae588:  92 10 20 13  mov  0x13, %o1
a00ae58c:  92 10 20 14  mov  0x14, %o1
a00ae590:  7f ff e4 c9  call  0xa00a78b4
a00ae594:  90 10 20 00  clr  %o0
a00ae598:  94 0a 20 ff  and  %o0, 0xff, %o2
a00ae59c:  90 10 00 18  mov  %i0, %o0
a00ae5a0:  7f ff e1 98  call  0xa00a6c00
a00ae5a4:  92 10 20 ce  mov  0xce, %o1
a00ae5a8:  94 10 20 fd  mov  0xfd, %o2
a00ae5ac:  90 10 20 00  clr  %o0
a00ae5b0:  7f ff e4 d3  call  0xa00a78fc
a00ae5b4:  92 10 20 13  mov  0x13, %o1
a00ae5b8:  92 10 20 14  mov  0x14, %o1
a00ae5bc:  7f ff e4 be  call  0xa00a78b4
a00ae5c0:  90 10 20 00  clr  %o0
a00ae5c4:  94 0a 20 ff  and  %o0, 0xff, %o2
a00ae5c8:  90 10 00 18  mov  %i0, %o0
a00ae5cc:  7f ff e1 8d  call  0xa00a6c00
a00ae5d0:  92 10 20 cf  mov  0xcf, %o1
a00ae5d4:  b2 10 20 d6  mov  0xd6, %i1
a00ae5d8:  7f ff e1 8a  call  0xa00a6c00
a00ae5dc:  95 e8 20 7f  restore  %g0, 0x7f, %o2
a00ae5e0:  01 00 00 00  nop
