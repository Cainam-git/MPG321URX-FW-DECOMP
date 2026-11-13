# leon2m FUN_a013f224 0xa013f224-0xa013f284 (96 bytes)
a013f224:  91 2a 20 10  sll  %o0, 0x10, %o0
a013f228:  03 00 06 96  sethi  %hi(0x1a5800), %g1
a013f22c:  92 10 61 e2  or  %g1, 0x1e2, %o1	! 0x1a59e2
a013f230:  91 32 20 10  srl  %o0, 0x10, %o0
a013f234:  94 10 20 00  clr  %o2
a013f238:  10 80 00 05  b  0xa013f24c
a013f23c:  98 10 20 00  clr  %o4
a013f240:  80 a3 20 0c  cmp  %o4, 0xc
a013f244:  38 80 00 0e  bgu,a   0xa013f27c
a013f248:  90 10 20 00  clr  %o0
a013f24c:  9b 2b 20 02  sll  %o4, 2, %o5
a013f250:  94 02 a0 01  inc  %o2
a013f254:  c2 0a 40 0d  ldub  [ %o1 + %o5 ], %g1
a013f258:  96 03 40 09  add  %o5, %o1, %o3
a013f25c:  80 a0 60 0c  cmp  %g1, 0xc
a013f260:  12 bf ff f8  bne  0xa013f240
a013f264:  98 0a a0 ff  and  %o2, 0xff, %o4
a013f268:  c2 12 e0 02  lduh  [ %o3 + 2 ], %g1
a013f26c:  80 a0 40 08  cmp  %g1, %o0
a013f270:  12 bf ff f5  bne  0xa013f244
a013f274:  80 a3 20 0c  cmp  %o4, 0xc
a013f278:  90 10 20 01  mov  1, %o0
a013f27c:  81 c3 e0 08  retl
a013f280:  01 00 00 00  nop
