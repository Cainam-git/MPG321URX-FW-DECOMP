# leon2s FUN_a00a832c 0xa00a832c-0xa00a8370 (68 bytes)
a00a832c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a8330:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a8334:  9a 02 00 08  add  %o0, %o0, %o5
a00a8338:  93 32 60 10  srl  %o1, 0x10, %o1
a00a833c:  80 a2 20 08  cmp  %o0, 8
a00a8340:  18 80 00 0a  bgu  0xa00a8368
a00a8344:  94 0a a0 ff  and  %o2, 0xff, %o2
a00a8348:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a834c:  82 10 61 30  or  %g1, 0x130, %g1	! 0xa00b4d30
a00a8350:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00a8354:  82 00 40 09  add  %g1, %o1, %g1
a00a8358:  83 28 60 02  sll  %g1, 2, %g1
a00a835c:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a8360:  82 10 40 0d  or  %g1, %o5, %g1
a00a8364:  d4 20 40 00  st  %o2, [ %g1 ]
a00a8368:  81 c3 e0 08  retl
a00a836c:  01 00 00 00  nop
