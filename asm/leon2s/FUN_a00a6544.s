# leon2s FUN_a00a6544 0xa00a6544-0xa00a657c (56 bytes)
a00a6544:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a6548:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a654c:  91 2a 20 02  sll  %o0, 2, %o0
a00a6550:  82 10 61 a0  or  %g1, 0x1a0, %g1
a00a6554:  c2 00 40 08  ld  [ %g1 + %o0 ], %g1
a00a6558:  95 2a a0 10  sll  %o2, 0x10, %o2
a00a655c:  c2 10 40 00  lduh  [ %g1 ], %g1
a00a6560:  95 32 a0 10  srl  %o2, 0x10, %o2
a00a6564:  82 00 40 0a  add  %g1, %o2, %g1
a00a6568:  1b 33 80 00  sethi  %hi(0xce000000), %o5
a00a656c:  82 10 40 0d  or  %g1, %o5, %g1
a00a6570:  d0 00 40 00  ld  [ %g1 ], %o0
a00a6574:  81 c3 e0 08  retl
a00a6578:  01 00 00 00  nop
