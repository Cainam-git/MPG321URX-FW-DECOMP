# leon2s FUN_a006d568 0xa006d568-0xa006d5a8 (64 bytes)
a006d568:  9d e3 bf 98  save  %sp, -104, %sp
a006d56c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a006d570:  a0 10 00 18  mov  %i0, %l0
a006d574:  b0 96 60 00  orcc  %i1, 0, %i0
a006d578:  12 80 00 04  bne  0xa006d588
a006d57c:  90 10 20 00  clr  %o0
a006d580:  7f c5 64 45  call  0x9f1c6694
a006d584:  01 00 00 00  nop
a006d588:  40 00 76 24  call  0xa008ae18
a006d58c:  90 10 00 19  mov  %i1, %o0
a006d590:  c2 14 20 12  lduh  [ %l0 + 0x12 ], %g1
a006d594:  82 08 7f bf  and  %g1, -65, %g1
a006d598:  c2 34 20 12  sth  %g1, [ %l0 + 0x12 ]
a006d59c:  40 00 f9 63  call  0xa00abb28
a006d5a0:  81 e8 00 00  restore
a006d5a4:  01 00 00 00  nop
