# leon2m FUN_a00f7534 0xa00f7534-0xa00f7608 (212 bytes)
a00f7534:  9d e3 bf 98  save  %sp, -104, %sp
a00f7538:  13 33 c0 3b  sethi  %hi(0xcf00ec00), %o1
a00f753c:  96 12 62 80  or  %o1, 0x280, %o3	! 0xcf00ee80
a00f7540:  1f 2a 00 ad  sethi  %hi(0xa802b400), %o7
a00f7544:  d8 02 c0 00  ld  [ %o3 ], %o4
a00f7548:  d4 0b e3 b4  ldub  [ %o7 + 0x3b4 ], %o2
a00f754c:  82 0b 20 f9  and  %o4, 0xf9, %g1
a00f7550:  90 02 80 0a  add  %o2, %o2, %o0
a00f7554:  9a 10 40 08  or  %g1, %o0, %o5
a00f7558:  da 22 c0 00  st  %o5, [ %o3 ]
a00f755c:  94 12 62 c0  or  %o1, 0x2c0, %o2
a00f7560:  e0 02 80 00  ld  [ %o2 ], %l0
a00f7564:  9e 0c 20 f3  and  %l0, 0xf3, %o7
a00f7568:  98 13 e0 a8  or  %o7, 0xa8, %o4
a00f756c:  96 12 62 c4  or  %o1, 0x2c4, %o3
a00f7570:  d8 22 80 00  st  %o4, [ %o2 ]
a00f7574:  d0 02 c0 00  ld  [ %o3 ], %o0
a00f7578:  82 12 20 50  or  %o0, 0x50, %g1
a00f757c:  c2 22 c0 00  st  %g1, [ %o3 ]
a00f7580:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f7584:  80 a6 20 00  cmp  %i0, 0
a00f7588:  02 80 00 03  be  0xa00f7594
a00f758c:  96 13 63 34  or  %o5, 0x334, %o3
a00f7590:  96 10 00 18  mov  %i0, %o3
a00f7594:  f0 0a c0 00  ldub  [ %o3 ], %i0
a00f7598:  80 a6 20 00  cmp  %i0, 0
a00f759c:  08 80 00 0f  bleu  0xa00f75d8
a00f75a0:  98 10 20 00  clr  %o4
a00f75a4:  13 33 c0 3b  sethi  %hi(0xcf00ec00), %o1
a00f75a8:  94 12 62 c8  or  %o1, 0x2c8, %o2	! 0xcf00eec8
a00f75ac:  9a 10 20 00  clr  %o5
a00f75b0:  90 03 40 0d  add  %o5, %o5, %o0
a00f75b4:  82 02 00 0b  add  %o0, %o3, %g1
a00f75b8:  da 10 60 02  lduh  [ %g1 + 2 ], %o5
a00f75bc:  da 22 80 00  st  %o5, [ %o2 ]
a00f75c0:  98 03 20 01  inc  %o4
a00f75c4:  e0 0a c0 00  ldub  [ %o3 ], %l0
a00f75c8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f75cc:  80 a4 00 0d  cmp  %l0, %o5
a00f75d0:  18 bf ff f9  bgu  0xa00f75b4
a00f75d4:  90 03 40 0d  add  %o5, %o5, %o0
a00f75d8:  13 33 c0 3b  sethi  %hi(0xcf00ec00), %o1
a00f75dc:  b0 12 62 c4  or  %o1, 0x2c4, %i0	! 0xcf00eec4
a00f75e0:  de 06 00 00  ld  [ %i0 ], %o7
a00f75e4:  98 13 e0 80  or  %o7, 0x80, %o4
a00f75e8:  d8 26 00 00  st  %o4, [ %i0 ]
a00f75ec:  67 fe 5b 2e  call  0x4008e2a4
a00f75f0:  01 00 00 00  nop
a00f75f4:  d4 06 00 00  ld  [ %i0 ], %o2
a00f75f8:  96 0a bf 7f  and  %o2, -129, %o3
a00f75fc:  d6 26 00 00  st  %o3, [ %i0 ]
a00f7600:  81 c7 e0 08  ret
a00f7604:  81 e8 00 00  restore
