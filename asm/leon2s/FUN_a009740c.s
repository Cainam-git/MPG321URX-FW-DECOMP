# leon2s FUN_a009740c 0xa009740c-0xa00974ec (224 bytes)  [FUN_a00974e4 = unreachable ret/restore tail, merged]
a009740c:  9d e3 bf 98  save  %sp, -104, %sp
a0097410:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0097414:  23 2a 01 f6  sethi  %hi(0xa807d800), %l1
a0097418:  a4 5c 20 34  smul  %l0, 0x34, %l2
a009741c:  a6 14 63 00  or  %l1, 0x300, %l3
a0097420:  b2 04 80 13  add  %l2, %l3, %i1
a0097424:  d2 06 60 0c  ld  [ %i1 + 0xc ], %o1
a0097428:  92 02 60 60  add  %o1, 0x60, %o1
a009742c:  40 00 3f f7  call  0xa00a7408
a0097430:  90 10 20 08  mov  8, %o0
a0097434:  80 a2 20 00  cmp  %o0, 0
a0097438:  02 80 00 08  be  0xa0097458
a009743c:  90 10 20 11  mov  0x11, %o0
a0097440:  d2 06 60 0c  ld  [ %i1 + 0xc ], %o1
a0097444:  40 00 3f f1  call  0xa00a7408
a0097448:  92 02 60 74  add  %o1, 0x74, %o1
a009744c:  80 a2 20 00  cmp  %o0, 0
a0097450:  12 80 00 12  bne  0xa0097498
a0097454:  b0 10 20 10  mov  0x10, %i0
a0097458:  82 14 63 00  or  %l1, 0x300, %g1
a009745c:  9a 5c 20 34  smul  %l0, 0x34, %o5
a0097460:  b2 03 40 01  add  %o5, %g1, %i1
a0097464:  d2 06 60 0c  ld  [ %i1 + 0xc ], %o1
a0097468:  92 02 60 74  add  %o1, 0x74, %o1
a009746c:  40 00 3f e7  call  0xa00a7408
a0097470:  90 10 20 11  mov  0x11, %o0
a0097474:  80 a2 20 00  cmp  %o0, 0
a0097478:  12 80 00 0b  bne  0xa00974a4
a009747c:  90 10 20 10  mov  0x10, %o0
a0097480:  d2 06 60 0c  ld  [ %i1 + 0xc ], %o1
a0097484:  40 00 3f e1  call  0xa00a7408
a0097488:  92 02 60 74  add  %o1, 0x74, %o1
a009748c:  80 a2 20 00  cmp  %o0, 0
a0097490:  02 80 00 05  be  0xa00974a4
a0097494:  b0 10 20 10  mov  0x10, %i0
a0097498:  f2 06 60 04  ld  [ %i1 + 4 ], %i1
a009749c:  40 00 3f c4  call  0xa00a73ac
a00974a0:  93 ee 60 34  restore  %i1, 0x34, %o1
a00974a4:  82 04 80 13  add  %l2, %l3, %g1
a00974a8:  d2 00 60 04  ld  [ %g1 + 4 ], %o1
a00974ac:  92 02 60 34  add  %o1, 0x34, %o1
a00974b0:  40 00 3f c9  call  0xa00a73d4
a00974b4:  90 10 20 10  mov  0x10, %o0
a00974b8:  d2 04 c0 12  ld  [ %l3 + %l2 ], %o1
a00974bc:  92 02 60 ec  add  %o1, 0xec, %o1
a00974c0:  40 00 3f d2  call  0xa00a7408
a00974c4:  90 10 20 14  mov  0x14, %o0
a00974c8:  80 a2 20 00  cmp  %o0, 0
a00974cc:  02 80 00 05  be  0xa00974e0
a00974d0:  b0 10 20 15  mov  0x15, %i0
a00974d4:  f2 04 c0 12  ld  [ %l3 + %l2 ], %i1
a00974d8:  40 00 3f bf  call  0xa00a73d4
a00974dc:  93 ee 60 ec  restore  %i1, 0xec, %o1
a00974e0:  01 00 00 00  nop
a00974e4:  81 c7 e0 08  ret
a00974e8:  81 e8 00 00  restore
