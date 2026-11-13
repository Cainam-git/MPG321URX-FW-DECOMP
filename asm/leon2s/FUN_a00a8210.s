# leon2s FUN_a00a8210 0xa00a8210-0xa00a8260 (80 bytes)
a00a8210:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a8214:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a8218:  9a 02 00 08  add  %o0, %o0, %o5
a00a821c:  80 a2 20 01  cmp  %o0, 1
a00a8220:  18 80 00 0e  bgu  0xa00a8258
a00a8224:  93 32 60 10  srl  %o1, 0x10, %o1
a00a8228:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a822c:  82 10 61 40  or  %g1, 0x140, %g1	! 0xa00b4d40
a00a8230:  da 10 40 0d  lduh  [ %g1 + %o5 ], %o5
a00a8234:  9a 03 40 09  add  %o5, %o1, %o5
a00a8238:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00a823c:  9b 2b 60 02  sll  %o5, 2, %o5
a00a8240:  9a 13 40 01  or  %o5, %g1, %o5
a00a8244:  c2 03 40 00  ld  [ %o5 ], %g1
a00a8248:  82 28 40 0a  andn  %g1, %o2, %g1
a00a824c:  82 10 40 0b  or  %g1, %o3, %g1
a00a8250:  82 08 60 ff  and  %g1, 0xff, %g1
a00a8254:  c2 23 40 00  st  %g1, [ %o5 ]
a00a8258:  81 c3 e0 08  retl
a00a825c:  01 00 00 00  nop
