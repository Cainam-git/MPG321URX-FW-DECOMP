# leon2s FUN_a00c850c 0xa00c850c-0xa00c85b8 (172 bytes)
a00c850c:  9d e3 bf 90  save  %sp, -112, %sp
a00c8510:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c8514:  90 10 00 18  mov  %i0, %o0
a00c8518:  92 10 20 74  mov  0x74, %o1
a00c851c:  94 10 20 00  clr  %o2
a00c8520:  7f ff fe ca  call  0xa00c8048
a00c8524:  96 10 20 05  mov  5, %o3
a00c8528:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c852c:  80 a2 20 00  cmp  %o0, 0
a00c8530:  12 80 00 20  bne  0xa00c85b0
a00c8534:  a2 07 bf f0  add  %fp, -16, %l1
a00c8538:  90 10 00 18  mov  %i0, %o0
a00c853c:  92 10 00 11  mov  %l1, %o1
a00c8540:  7f ff ff 2e  call  0xa00c81f8
a00c8544:  94 10 20 05  mov  5, %o2
a00c8548:  a0 10 20 00  clr  %l0
a00c854c:  94 0c 20 ff  and  %l0, 0xff, %o2
a00c8550:  82 0c 20 ff  and  %l0, 0xff, %g1
a00c8554:  94 02 a0 10  add  %o2, 0x10, %o2
a00c8558:  82 07 80 01  add  %fp, %g1, %g1
a00c855c:  95 2a a0 10  sll  %o2, 0x10, %o2
a00c8560:  d6 08 7f f0  ldub  [ %g1 + -16 ], %o3
a00c8564:  95 32 a0 10  srl  %o2, 0x10, %o2
a00c8568:  90 10 00 18  mov  %i0, %o0
a00c856c:  40 3b be ba  call  0xa0fb8054
a00c8570:  92 10 20 00  clr  %o1
a00c8574:  a0 04 20 01  inc  %l0
a00c8578:  82 0c 20 ff  and  %l0, 0xff, %g1
a00c857c:  80 a0 60 04  cmp  %g1, 4
a00c8580:  08 bf ff f5  bleu  0xa00c8554
a00c8584:  94 0c 20 ff  and  %l0, 0xff, %o2
a00c8588:  7f ff ff 97  call  0xa00c83e4
a00c858c:  90 10 00 11  mov  %l1, %o0
a00c8590:  91 2a 20 18  sll  %o0, 0x18, %o0
a00c8594:  91 3a 20 18  sra  %o0, 0x18, %o0
a00c8598:  90 1a 20 00  xor  %o0, 0, %o0
a00c859c:  80 a0 00 08  cmp  %g0, %o0
a00c85a0:  82 40 20 00  addx  %g0, 0, %g1
a00c85a4:  82 20 00 01  neg  %g1
a00c85a8:  90 08 7f 88  and  %g1, -120, %o0
a00c85ac:  90 02 20 78  add  %o0, 0x78, %o0
a00c85b0:  81 c7 e0 08  ret
a00c85b4:  91 e8 00 08  restore  %g0, %o0, %o0
