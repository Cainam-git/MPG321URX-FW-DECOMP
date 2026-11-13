# leon2s FUN_a00a82e4 0xa00a82e4-0xa00a832c (72 bytes)
a00a82e4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a82e8:  9a 02 00 08  add  %o0, %o0, %o5
a00a82ec:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a82f0:  80 a2 20 01  cmp  %o0, 1
a00a82f4:  93 32 60 10  srl  %o1, 0x10, %o1
a00a82f8:  18 80 00 0b  bgu  0xa00a8324
a00a82fc:  90 10 20 00  clr  %o0
a00a8300:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a8304:  82 10 61 40  or  %g1, 0x140, %g1	! 0xa00b4d40
a00a8308:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a00a830c:  82 00 40 09  add  %g1, %o1, %g1
a00a8310:  83 28 60 02  sll  %g1, 2, %g1
a00a8314:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a8318:  82 10 40 0d  or  %g1, %o5, %g1
a00a831c:  c2 00 40 00  ld  [ %g1 ], %g1
a00a8320:  90 08 60 ff  and  %g1, 0xff, %o0
a00a8324:  81 c3 e0 08  retl
a00a8328:  01 00 00 00  nop
