# leon2s FUN_a00ac550 0xa00ac550-0xa00ac584 (52 bytes)
a00ac550:  83 2a 60 10  sll  %o1, 0x10, %g1
a00ac554:  83 30 60 10  srl  %g1, 0x10, %g1
a00ac558:  92 10 00 01  mov  %g1, %o1
a00ac55c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ac560:  80 a0 61 ff  cmp  %g1, 0x1ff
a00ac564:  18 80 00 05  bgu  0xa00ac578
a00ac568:  94 0a a0 ff  and  %o2, 0xff, %o2
a00ac56c:  82 13 c0 00  mov  %o7, %g1
a00ac570:  7f ff e9 a4  call  0xa00a6c00
a00ac574:  9e 10 40 00  mov  %g1, %o7
a00ac578:  01 00 00 00  nop
a00ac57c:  81 c3 e0 08  retl
a00ac580:  01 00 00 00  nop
