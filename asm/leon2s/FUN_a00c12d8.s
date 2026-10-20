# leon2s FUN_a00c12d8 0xa00c12d8-0xa00c1318 (64 bytes)
a00c12d8:  03 27 c7 07  sethi  %hi(0x9f1c1c00), %g1
a00c12dc:  92 10 62 38  or  %g1, 0x238, %o1	! 0x9f1c1e38
a00c12e0:  96 10 20 00  clr  %o3
a00c12e4:  94 10 20 0f  mov  0xf, %o2
a00c12e8:  99 2a e0 10  sll  %o3, 0x10, %o4
a00c12ec:  99 33 20 10  srl  %o4, 0x10, %o4
a00c12f0:  96 02 e0 01  inc  %o3
a00c12f4:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00c12f8:  82 22 80 0c  sub  %o2, %o4, %g1
a00c12fc:  c2 0a 40 01  ldub  [ %o1 + %g1 ], %g1
a00c1300:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c1304:  80 a3 60 0f  cmp  %o5, 0xf
a00c1308:  08 bf ff f8  bleu  0xa00c12e8
a00c130c:  c2 2a 00 0c  stb  %g1, [ %o0 + %o4 ]
a00c1310:  81 c3 e0 08  retl
a00c1314:  01 00 00 00  nop
