# leon2s TxFFE_Max_L 0xa0098468-0xa009860c (420 bytes)  [FUN_a0098604 = unreachable ret/restore tail, merged]
a0098468:  9d e3 bf 98  save  %sp, -104, %sp
a009846c:  b4 0e 20 ff  and  %i0, 0xff, %i2
a0098470:  27 2a 01 f6  sethi  %hi(0xa807d800), %l3
a0098474:  9a 14 e3 00  or  %l3, 0x300, %o5	! 0xa807db00
a0098478:  82 5e a0 34  smul  %i2, 0x34, %g1
a009847c:  a0 00 40 0d  add  %g1, %o5, %l0
a0098480:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0098484:  da 04 20 18  ld  [ %l0 + 0x18 ], %o5
a0098488:  a8 10 62 80  or  %g1, 0x280, %l4
a009848c:  da 03 60 90  ld  [ %o5 + 0x90 ], %o5
a0098490:  a2 5e a0 b0  smul  %i2, 0xb0, %l1
a0098494:  25 03 c0 00  sethi  %hi(0xf000000), %l2
a0098498:  9a 0b 40 12  and  %o5, %l2, %o5
a009849c:  b2 04 40 14  add  %l1, %l4, %i1
a00984a0:  9b 33 60 18  srl  %o5, 0x18, %o5
a00984a4:  c2 0e 60 01  ldub  [ %i1 + 1 ], %g1
a00984a8:  80 a0 40 0d  cmp  %g1, %o5
a00984ac:  02 80 00 29  be  0xa0098550
a00984b0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00984b4:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a00984b8:  80 88 68 00  btst  0x800, %g1
a00984bc:  02 80 00 04  be  0xa00984cc
a00984c0:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a00984c4:  7f ff 6c 00  call  0xa00734c4
a00984c8:  90 12 20 38  or  %o0, 0x38, %o0	! 0xa0069c38
a00984cc:  40 00 66 e6  call  0xa00b2064
a00984d0:  01 00 00 00  nop
a00984d4:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00984d8:  9b 2e a0 02  sll  %i2, 2, %o5
a00984dc:  82 10 60 74  or  %g1, 0x74, %g1
a00984e0:  d0 20 40 0d  st  %o0, [ %g1 + %o5 ]
a00984e4:  c2 04 20 18  ld  [ %l0 + 0x18 ], %g1
a00984e8:  d6 00 60 90  ld  [ %g1 + 0x90 ], %o3
a00984ec:  96 0a c0 12  and  %o3, %l2, %o3
a00984f0:  97 32 e0 18  srl  %o3, 0x18, %o3
a00984f4:  13 00 00 07  sethi  %hi(0x1c00), %o1
a00984f8:  d6 2e 60 01  stb  %o3, [ %i1 + 1 ]
a00984fc:  90 10 00 1a  mov  %i2, %o0
a0098500:  92 12 63 0c  or  %o1, 0x30c, %o1
a0098504:  40 00 3b e1  call  0xa00a7488
a0098508:  94 10 3f f0  mov  -16, %o2
a009850c:  c2 04 20 18  ld  [ %l0 + 0x18 ], %g1
a0098510:  c2 00 60 90  ld  [ %g1 + 0x90 ], %g1
a0098514:  da 0d 00 11  ldub  [ %l4 + %l1 ], %o5
a0098518:  83 30 60 1c  srl  %g1, 0x1c, %g1
a009851c:  c2 2e 60 13  stb  %g1, [ %i1 + 0x13 ]
a0098520:  80 a3 60 00  cmp  %o5, 0
a0098524:  02 80 00 0b  be  0xa0098550
a0098528:  98 10 20 00  clr  %o4
a009852c:  94 10 00 19  mov  %i1, %o2
a0098530:  96 10 00 0d  mov  %o5, %o3
a0098534:  82 0b 20 ff  and  %o4, 0xff, %g1
a0098538:  98 03 20 01  inc  %o4
a009853c:  82 02 80 01  add  %o2, %g1, %g1
a0098540:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0098544:  80 a3 40 0b  cmp  %o5, %o3
a0098548:  0a bf ff fb  bcs  0xa0098534
a009854c:  c0 28 60 0f  clrb  [ %g1 + 0xf ]
a0098550:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0098554:  23 2a 01 f5  sethi  %hi(0xa807d400), %l1
a0098558:  98 14 62 80  or  %l1, 0x280, %o4	! 0xa807d680
a009855c:  9a 5e 20 b0  smul  %i0, 0xb0, %o5
a0098560:  82 03 40 0c  add  %o5, %o4, %g1
a0098564:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a0098568:  80 a0 60 00  cmp  %g1, 0
a009856c:  12 80 00 04  bne  0xa009857c
a0098570:  82 00 7f ff  add  %g1, -1, %g1
a0098574:  10 80 00 17  b  0xa00985d0
a0098578:  c0 2b 00 0d  clrb  [ %o4 + %o5 ]
a009857c:  82 08 60 ff  and  %g1, 0xff, %g1
a0098580:  80 a0 60 01  cmp  %g1, 1
a0098584:  18 80 00 07  bgu  0xa00985a0
a0098588:  82 5e 20 34  smul  %i0, 0x34, %g1
a009858c:  a0 14 e3 00  or  %l3, 0x300, %l0
a0098590:  a0 00 40 10  add  %g1, %l0, %l0
a0098594:  d2 04 20 0c  ld  [ %l0 + 0xc ], %o1
a0098598:  10 80 00 06  b  0xa00985b0
a009859c:  82 10 20 03  mov  3, %g1
a00985a0:  a0 14 e3 00  or  %l3, 0x300, %l0
a00985a4:  a0 00 40 10  add  %g1, %l0, %l0
a00985a8:  d2 04 20 0c  ld  [ %l0 + 0xc ], %o1
a00985ac:  82 10 20 04  mov  4, %g1
a00985b0:  92 02 60 60  add  %o1, 0x60, %o1
a00985b4:  90 10 20 08  mov  8, %o0
a00985b8:  40 00 3b 87  call  0xa00a73d4
a00985bc:  c2 2b 00 0d  stb  %g1, [ %o4 + %o5 ]
a00985c0:  d2 04 20 0c  ld  [ %l0 + 0xc ], %o1
a00985c4:  92 02 60 60  add  %o1, 0x60, %o1
a00985c8:  40 00 3b 83  call  0xa00a73d4
a00985cc:  90 10 20 09  mov  9, %o0
a00985d0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00985d4:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a00985d8:  80 88 68 00  btst  0x800, %g1
a00985dc:  02 80 00 09  be  0xa0098600
a00985e0:  9a 5e 20 b0  smul  %i0, 0xb0, %o5
a00985e4:  82 14 62 80  or  %l1, 0x280, %g1
a00985e8:  9a 03 40 01  add  %o5, %g1, %o5
a00985ec:  31 28 01 a7  sethi  %hi(0xa0069c00), %i0
a00985f0:  f4 0b 60 13  ldub  [ %o5 + 0x13 ], %i2
a00985f4:  f2 0b 60 01  ldub  [ %o5 + 1 ], %i1
a00985f8:  7f ff 6a 93  call  0xa0073044
a00985fc:  91 ee 20 58  restore  %i0, 0x58, %o0
a0098600:  01 00 00 00  nop
a0098604:  81 c7 e0 08  ret
a0098608:  81 e8 00 00  restore
