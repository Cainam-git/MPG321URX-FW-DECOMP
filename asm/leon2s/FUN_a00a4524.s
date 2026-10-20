# leon2s FUN_a00a4524 0xa00a4524-0xa00a45d8 (180 bytes)
a00a4524:  9d e3 bf 98  save  %sp, -104, %sp
a00a4528:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a452c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a4530:  27 2a 01 f6  sethi  %hi(0xa807d800), %l3
a00a4534:  a1 2e 20 02  sll  %i0, 2, %l0
a00a4538:  a4 10 63 3c  or  %g1, 0x33c, %l2
a00a453c:  a2 14 e3 6c  or  %l3, 0x36c, %l1
a00a4540:  11 28 01 af  sethi  %hi(0xa006bc00), %o0
a00a4544:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00a4548:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00a454c:  90 12 23 e0  or  %o0, 0x3e0, %o0
a00a4550:  80 a3 40 01  cmp  %o5, %g1
a00a4554:  02 80 00 14  be  0xa00a45a4
a00a4558:  92 10 00 18  mov  %i0, %o1
a00a455c:  7f ff 3a ba  call  0xa0073044
a00a4560:  01 00 00 00  nop
a00a4564:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00a4568:  94 10 20 00  clr  %o2
a00a456c:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a00a4570:  90 10 00 18  mov  %i0, %o0
a00a4574:  7f ff b5 e0  call  0xa0091cf4
a00a4578:  92 10 20 31  mov  0x31, %o1
a00a457c:  92 10 20 10  mov  0x10, %o1
a00a4580:  7f ff b5 f9  call  0xa0091d64
a00a4584:  90 10 00 18  mov  %i0, %o0
a00a4588:  80 8a 20 20  btst  0x20, %o0
a00a458c:  90 10 00 18  mov  %i0, %o0
a00a4590:  92 10 20 10  mov  0x10, %o1
a00a4594:  02 80 00 04  be  0xa00a45a4
a00a4598:  94 10 20 20  mov  0x20, %o2
a00a459c:  7f ff b5 d6  call  0xa0091cf4
a00a45a0:  01 00 00 00  nop
a00a45a4:  7f ff b4 ef  call  0xa0091960
a00a45a8:  90 10 00 18  mov  %i0, %o0
a00a45ac:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a45b0:  9a 14 e3 6c  or  %l3, 0x36c, %o5
a00a45b4:  80 a2 20 01  cmp  %o0, 1
a00a45b8:  12 80 00 04  bne  0xa00a45c8
a00a45bc:  93 2e 20 02  sll  %i0, 2, %o1
a00a45c0:  82 10 20 02  mov  2, %g1
a00a45c4:  c2 23 40 09  st  %g1, [ %o5 + %o1 ]
a00a45c8:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a45cc:  c0 28 61 aa  clrb  [ %g1 + 0x1aa ]	! 0xa80791aa
a00a45d0:  81 c7 e0 08  ret
a00a45d4:  91 e8 20 00  restore  %g0, 0, %o0
