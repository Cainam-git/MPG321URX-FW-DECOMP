# leon2s FUN_a00c8360 0xa00c8360-0xa00c83e4 (132 bytes)
a00c8360:  9d e3 bf 98  save  %sp, -104, %sp
a00c8364:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c8368:  92 10 20 74  mov  0x74, %o1
a00c836c:  94 10 20 40  mov  0x40, %o2
a00c8370:  96 10 20 01  mov  1, %o3
a00c8374:  7f ff ff 35  call  0xa00c8048
a00c8378:  90 10 00 18  mov  %i0, %o0
a00c837c:  82 0a 20 ff  and  %o0, 0xff, %g1
a00c8380:  94 10 20 01  mov  1, %o2
a00c8384:  90 10 00 18  mov  %i0, %o0
a00c8388:  80 a0 60 00  cmp  %g1, 0
a00c838c:  12 80 00 14  bne  0xa00c83dc
a00c8390:  92 10 00 19  mov  %i1, %o1
a00c8394:  7f ff ff 99  call  0xa00c81f8
a00c8398:  01 00 00 00  nop
a00c839c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c83a0:  82 92 20 00  orcc  %o0, 0, %g1
a00c83a4:  12 80 00 0e  bne  0xa00c83dc
a00c83a8:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00c83ac:  82 06 00 18  add  %i0, %i0, %g1
a00c83b0:  82 00 40 18  add  %g1, %i0, %g1
a00c83b4:  91 28 60 03  sll  %g1, 3, %o0
a00c83b8:  c2 0e 40 00  ldub  [ %i1 ], %g1
a00c83bc:  80 88 60 40  btst  0x40, %g1
a00c83c0:  02 80 00 06  be  0xa00c83d8
a00c83c4:  98 13 63 b0  or  %o5, 0x3b0, %o4
a00c83c8:  c2 03 00 08  ld  [ %o4 + %o0 ], %g1
a00c83cc:  1b 04 00 00  sethi  %hi(0x10000000), %o5
a00c83d0:  82 10 40 0d  or  %g1, %o5, %g1
a00c83d4:  c2 23 00 08  st  %g1, [ %o4 + %o0 ]
a00c83d8:  82 10 20 00  clr  %g1
a00c83dc:  81 c7 e0 08  ret
a00c83e0:  91 e8 00 01  restore  %g0, %g1, %o0
