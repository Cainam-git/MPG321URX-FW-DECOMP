# leon2m FUN_a00e5428 0xa00e5428-0xa00e55ec (452 bytes)
a00e5428:  9d e3 bf 98  save  %sp, -104, %sp
a00e542c:  82 06 a0 01  add  %i2, 1, %g1
a00e5430:  80 a0 60 02  cmp  %g1, 2
a00e5434:  18 80 00 5a  bgu  0xa00e559c
a00e5438:  80 a6 a0 00  cmp  %i2, 0
a00e543c:  02 80 00 6a  be  0xa00e55e4
a00e5440:  90 10 20 00  clr  %o0
a00e5444:  80 a6 7f ff  cmp  %i1, -1
a00e5448:  02 80 00 23  be  0xa00e54d4
a00e544c:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00e5450:  9b 2e 60 02  sll  %i1, 2, %o5
a00e5454:  92 14 e2 a8  or  %l3, 0x2a8, %o1
a00e5458:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00e545c:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00e5460:  98 14 62 c8  or  %l1, 0x2c8, %o4
a00e5464:  9e 14 a2 b8  or  %l2, 0x2b8, %o7
a00e5468:  d6 02 40 0d  ld  [ %o1 + %o5 ], %o3
a00e546c:  d2 03 00 0d  ld  [ %o4 + %o5 ], %o1
a00e5470:  d4 03 c0 0d  ld  [ %o7 + %o5 ], %o2
a00e5474:  7f ff ec b8  call  0xa00e0754
a00e5478:  90 10 00 18  mov  %i0, %o0
a00e547c:  80 a2 20 01  cmp  %o0, 1
a00e5480:  02 80 00 1f  be  0xa00e54fc
a00e5484:  a0 10 00 08  mov  %o0, %l0
a00e5488:  80 a2 20 03  cmp  %o0, 3
a00e548c:  12 80 00 4d  bne  0xa00e55c0
a00e5490:  80 a6 a0 01  cmp  %i2, 1
a00e5494:  02 80 00 35  be  0xa00e5568
a00e5498:  80 a6 7f ff  cmp  %i1, -1
a00e549c:  02 80 00 27  be  0xa00e5538
a00e54a0:  b5 2e 60 02  sll  %i1, 2, %i2
a00e54a4:  9a 14 62 c8  or  %l1, 0x2c8, %o5
a00e54a8:  b2 14 a2 b8  or  %l2, 0x2b8, %i1
a00e54ac:  82 14 e2 a8  or  %l3, 0x2a8, %g1
a00e54b0:  d6 00 40 1a  ld  [ %g1 + %i2 ], %o3
a00e54b4:  90 10 00 18  mov  %i0, %o0
a00e54b8:  d2 03 40 1a  ld  [ %o5 + %i2 ], %o1
a00e54bc:  d4 06 40 1a  ld  [ %i1 + %i2 ], %o2
a00e54c0:  98 10 20 01  mov  1, %o4
a00e54c4:  7f ff ec ac  call  0xa00e0774
a00e54c8:  01 00 00 00  nop
a00e54cc:  10 80 00 46  b  0xa00e55e4
a00e54d0:  90 10 20 00  clr  %o0	! 0x0
a00e54d4:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00e54d8:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00e54dc:  90 10 00 18  mov  %i0, %o0
a00e54e0:  92 14 62 c8  or  %l1, 0x2c8, %o1
a00e54e4:  94 14 a2 b8  or  %l2, 0x2b8, %o2
a00e54e8:  7f ff ec 9b  call  0xa00e0754
a00e54ec:  96 14 e2 a8  or  %l3, 0x2a8, %o3
a00e54f0:  80 a2 20 01  cmp  %o0, 1
a00e54f4:  12 bf ff e5  bne  0xa00e5488
a00e54f8:  a0 10 00 08  mov  %o0, %l0
a00e54fc:  80 a6 a0 01  cmp  %i2, 1
a00e5500:  32 80 00 13  bne,a   0xa00e554c
a00e5504:  90 10 00 18  mov  %i0, %o0
a00e5508:  80 a6 7f ff  cmp  %i1, -1
a00e550c:  02 80 00 1f  be  0xa00e5588
a00e5510:  90 10 00 18  mov  %i0, %o0
a00e5514:  94 14 62 c8  or  %l1, 0x2c8, %o2
a00e5518:  a1 2e 60 02  sll  %i1, 2, %l0
a00e551c:  a2 14 a2 b8  or  %l2, 0x2b8, %l1
a00e5520:  a4 14 e2 a8  or  %l3, 0x2a8, %l2
a00e5524:  d2 02 80 10  ld  [ %o2 + %l0 ], %o1
a00e5528:  d6 04 80 10  ld  [ %l2 + %l0 ], %o3
a00e552c:  d4 04 40 10  ld  [ %l1 + %l0 ], %o2
a00e5530:  10 bf ff e5  b  0xa00e54c4
a00e5534:  98 10 20 03  mov  3, %o4
a00e5538:  90 10 00 18  mov  %i0, %o0
a00e553c:  92 14 62 c8  or  %l1, 0x2c8, %o1
a00e5540:  94 14 a2 b8  or  %l2, 0x2b8, %o2
a00e5544:  10 bf ff df  b  0xa00e54c0
a00e5548:  96 14 e2 a8  or  %l3, 0x2a8, %o3
a00e554c:  92 10 00 19  mov  %i1, %o1
a00e5550:  7f ff ff 66  call  0xa00e52e8
a00e5554:  94 10 3f ff  mov  -1, %o2
a00e5558:  80 a2 20 00  cmp  %o0, 0
a00e555c:  12 80 00 22  bne  0xa00e55e4
a00e5560:  80 a6 7f ff  cmp  %i1, -1
a00e5564:  30 bf ff ea  b,a   0xa00e550c
a00e5568:  90 10 00 18  mov  %i0, %o0
a00e556c:  92 10 00 19  mov  %i1, %o1
a00e5570:  7f ff ff 5e  call  0xa00e52e8
a00e5574:  94 10 20 01  mov  1, %o2
a00e5578:  80 a2 20 00  cmp  %o0, 0
a00e557c:  12 80 00 1a  bne  0xa00e55e4
a00e5580:  80 a6 7f ff  cmp  %i1, -1
a00e5584:  30 bf ff c6  b,a   0xa00e549c
a00e5588:  92 14 62 c8  or  %l1, 0x2c8, %o1
a00e558c:  94 14 a2 b8  or  %l2, 0x2b8, %o2
a00e5590:  96 14 e2 a8  or  %l3, 0x2a8, %o3
a00e5594:  10 bf ff cc  b  0xa00e54c4
a00e5598:  98 10 20 03  mov  3, %o4
a00e559c:  7f ff e8 9c  call  0xa00df80c
a00e55a0:  01 00 00 00  nop
a00e55a4:  7f ff ed 87  call  0xa00e0bc0
a00e55a8:  01 00 00 00  nop
a00e55ac:  11 00 06 66  sethi  %hi(0x199800), %o0
a00e55b0:  7f ff e6 f0  call  0xa00df170
a00e55b4:  90 12 20 f8  or  %o0, 0xf8, %o0	! 0x1998f8
a00e55b8:  10 80 00 0b  b  0xa00e55e4
a00e55bc:  90 10 3f ff  mov  -1, %o0
a00e55c0:  7f ff e8 93  call  0xa00df80c
a00e55c4:  01 00 00 00  nop
a00e55c8:  7f ff ed 7e  call  0xa00e0bc0
a00e55cc:  01 00 00 00  nop
a00e55d0:  17 00 06 66  sethi  %hi(0x199800), %o3
a00e55d4:  90 12 e1 40  or  %o3, 0x140, %o0	! 0x199940
a00e55d8:  7f ff e6 e6  call  0xa00df170
a00e55dc:  92 10 00 10  mov  %l0, %o1
a00e55e0:  90 10 3f ff  mov  -1, %o0
a00e55e4:  81 c7 e0 08  ret
a00e55e8:  91 e8 00 08  restore  %g0, %o0, %o0
