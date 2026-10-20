# leon2s FUN_a0086540 0xa0086540-0xa00865b8 (120 bytes)
a0086540:  9d e3 bf 90  save  %sp, -112, %sp
a0086544:  82 0e a0 ff  and  %i2, 0xff, %g1
a0086548:  80 a0 60 02  cmp  %g1, 2
a008654c:  96 0e 60 0f  and  %i1, 0xf, %o3
a0086550:  92 10 20 80  mov  0x80, %o1
a0086554:  94 10 21 03  mov  0x103, %o2
a0086558:  98 07 bf f0  add  %fp, -16, %o4
a008655c:  9e 10 00 1a  mov  %i2, %o7
a0086560:  90 0e 20 ff  and  %i0, 0xff, %o0
a0086564:  96 02 ff ff  add  %o3, -1, %o3
a0086568:  82 10 00 1b  mov  %i3, %g1
a008656c:  08 80 00 03  bleu  0xa0086578
a0086570:  9a 0e e0 ff  and  %i3, 0xff, %o5
a0086574:  9e 16 a0 04  or  %i2, 4, %o7
a0086578:  80 a3 60 02  cmp  %o5, 2
a008657c:  38 80 00 02  bgu,a   0xa0086584
a0086580:  82 16 e0 04  or  %i3, 4, %g1
a0086584:  82 08 60 ff  and  %g1, 0xff, %g1
a0086588:  83 28 60 03  sll  %g1, 3, %g1
a008658c:  82 10 40 0f  or  %g1, %o7, %g1
a0086590:  c2 2f bf f3  stb  %g1, [ %fp + -13 ]
a0086594:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a0086598:  c2 2f bf f1  stb  %g1, [ %fp + -15 ]
a008659c:  7f ff ff 8e  call  0xa00863d4
a00865a0:  c2 2f bf f2  stb  %g1, [ %fp + -14 ]
a00865a4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00865a8:  80 a0 00 08  cmp  %g0, %o0
a00865ac:  b0 40 20 00  addx  %g0, 0, %i0
a00865b0:  81 c7 e0 08  ret
a00865b4:  81 e8 00 00  restore
