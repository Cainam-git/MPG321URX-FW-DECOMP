# leon2s FUN_a008b53c 0xa008b53c-0xa008b5d0 (148 bytes)
a008b53c:  9d e3 bf 98  save  %sp, -104, %sp
a008b540:  03 2a aa aa  sethi  %hi(0xaaaaa800), %g1
a008b544:  82 10 62 ab  or  %g1, 0x2ab, %g1	! 0xaaaaaaab
a008b548:  b3 2e 60 11  sll  %i1, 0x11, %i1
a008b54c:  80 56 40 01  umul  %i1, %g1, %g0
a008b550:  b3 40 00 00  rd  %y, %i1
a008b554:  b3 36 60 03  srl  %i1, 3, %i1
a008b558:  03 34 6d c5  sethi  %hi(0xd1b71400), %g1
a008b55c:  82 10 63 59  or  %g1, 0x359, %g1	! 0xd1b71759
a008b560:  b3 2e 60 09  sll  %i1, 9, %i1
a008b564:  80 56 40 01  umul  %i1, %g1, %g0
a008b568:  b3 40 00 00  rd  %y, %i1
a008b56c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008b570:  95 36 60 0d  srl  %i1, 0xd, %o2
a008b574:  94 0a a0 ff  and  %o2, 0xff, %o2
a008b578:  90 10 00 18  mov  %i0, %o0
a008b57c:  40 00 6e fb  call  0xa00a7168
a008b580:  92 10 20 04  mov  4, %o1
a008b584:  95 36 60 15  srl  %i1, 0x15, %o2
a008b588:  94 0a a0 ff  and  %o2, 0xff, %o2
a008b58c:  90 10 00 18  mov  %i0, %o0
a008b590:  40 00 6e f6  call  0xa00a7168
a008b594:  92 10 20 05  mov  5, %o1
a008b598:  95 36 60 1d  srl  %i1, 0x1d, %o2
a008b59c:  90 10 00 18  mov  %i0, %o0
a008b5a0:  40 00 6e f2  call  0xa00a7168
a008b5a4:  92 10 20 06  mov  6, %o1
a008b5a8:  90 10 00 18  mov  %i0, %o0
a008b5ac:  92 10 20 02  mov  2, %o1
a008b5b0:  94 10 20 04  mov  4, %o2
a008b5b4:  40 00 6f 12  call  0xa00a71fc
a008b5b8:  96 10 20 00  clr  %o3
a008b5bc:  b2 10 20 07  mov  7, %i1
a008b5c0:  b4 10 20 10  mov  0x10, %i2
a008b5c4:  40 00 6f 0e  call  0xa00a71fc
a008b5c8:  97 e8 20 00  restore  %g0, 0, %o3
a008b5cc:  01 00 00 00  nop
