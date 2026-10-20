# leon2s CED_ALL_3 0xa00b24b0-0xa00b258c (220 bytes)  [FUN_a00b2584 = unreachable ret/restore tail, merged]
a00b24b0:  9d e3 bf 98  save  %sp, -104, %sp
a00b24b4:  80 a6 20 00  cmp  %i0, 0
a00b24b8:  02 80 00 32  be  0xa00b2580
a00b24bc:  80 a6 60 00  cmp  %i1, 0
a00b24c0:  12 80 00 03  bne  0xa00b24cc
a00b24c4:  b0 0e 3f fc  and  %i0, -4, %i0
a00b24c8:  b2 10 20 20  mov  0x20, %i1
a00b24cc:  83 2e 60 02  sll  %i1, 2, %g1
a00b24d0:  b2 06 00 01  add  %i0, %g1, %i1
a00b24d4:  82 06 60 1f  add  %i1, 0x1f, %g1
a00b24d8:  29 28 01 a7  sethi  %hi(0xa0069c00), %l4
a00b24dc:  a6 08 7f e0  and  %g1, -32, %l3
a00b24e0:  a0 0e 3f e0  and  %i0, -32, %l0
a00b24e4:  7f fe bb 67  call  0xa0061280
a00b24e8:  90 15 22 e8  or  %l4, 0x2e8, %o0
a00b24ec:  a2 10 00 10  mov  %l0, %l1
a00b24f0:  80 a4 40 13  cmp  %l1, %l3
a00b24f4:  3a 80 00 21  bcc,a   0xa00b2578
a00b24f8:  31 28 01 a7  sethi  %hi(0xa0069c00), %i0
a00b24fc:  7f fe bb 93  call  0xa0061348
a00b2500:  90 10 00 11  mov  %l1, %o0
a00b2504:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b2508:  7f fe bb 5e  call  0xa0061280
a00b250c:  90 12 22 60  or  %o0, 0x260, %o0	! 0xa006c660
a00b2510:  a4 10 20 03  mov  3, %l2
a00b2514:  80 a4 00 18  cmp  %l0, %i0
a00b2518:  9a 40 20 00  addx  %g0, 0, %o5
a00b251c:  80 a4 00 19  cmp  %l0, %i1
a00b2520:  82 60 3f ff  subx  %g0, -1, %g1
a00b2524:  80 93 40 01  orcc  %o5, %g1, %g0
a00b2528:  02 80 00 05  be  0xa00b253c
a00b252c:  90 10 00 10  mov  %l0, %o0
a00b2530:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b2534:  10 80 00 08  b  0xa00b2554
a00b2538:  90 12 22 88  or  %o0, 0x288, %o0	! 0xa006c688
a00b253c:  7f ff ff 70  call  0xa00b22fc
a00b2540:  01 00 00 00  nop
a00b2544:  7f fe bb 81  call  0xa0061348
a00b2548:  01 00 00 00  nop
a00b254c:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b2550:  90 12 22 90  or  %o0, 0x290, %o0	! 0xa006c690
a00b2554:  7f fe bb 4b  call  0xa0061280
a00b2558:  a0 04 20 04  add  %l0, 4, %l0
a00b255c:  a4 84 bf ff  addcc  %l2, -1, %l2
a00b2560:  1c bf ff ee  bpos  0xa00b2518
a00b2564:  80 a4 00 18  cmp  %l0, %i0
a00b2568:  7f fe bb 46  call  0xa0061280
a00b256c:  90 15 22 e8  or  %l4, 0x2e8, %o0
a00b2570:  10 bf ff e0  b  0xa00b24f0
a00b2574:  a2 04 60 10  add  %l1, 0x10, %l1
a00b2578:  7f fe bb 42  call  0xa0061280
a00b257c:  91 ee 22 e8  restore  %i0, 0x2e8, %o0
a00b2580:  01 00 00 00  nop
a00b2584:  81 c7 e0 08  ret
a00b2588:  81 e8 00 00  restore
