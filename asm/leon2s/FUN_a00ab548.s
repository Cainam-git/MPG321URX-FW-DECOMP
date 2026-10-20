# leon2s FUN_a00ab548 0xa00ab548-0xa00ab584 (60 bytes)
a00ab548:  98 0a 20 0f  and  %o0, 0xf, %o4
a00ab54c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00ab550:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ab554:  9b 2b 20 04  sll  %o4, 4, %o5
a00ab558:  82 10 62 b4  or  %g1, 0x2b4, %g1
a00ab55c:  91 32 20 04  srl  %o0, 4, %o0
a00ab560:  9a 03 40 01  add  %o5, %g1, %o5
a00ab564:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ab568:  80 a3 20 04  cmp  %o4, 4
a00ab56c:  18 80 00 04  bgu  0xa00ab57c
a00ab570:  9a 03 40 08  add  %o5, %o0, %o5
a00ab574:  d4 2b 60 0c  stb  %o2, [ %o5 + 0xc ]
a00ab578:  d2 2b 60 04  stb  %o1, [ %o5 + 4 ]
a00ab57c:  81 c3 e0 08  retl
a00ab580:  01 00 00 00  nop
