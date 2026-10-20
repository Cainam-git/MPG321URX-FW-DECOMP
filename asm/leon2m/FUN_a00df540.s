# leon2m FUN_a00df540 0xa00df540-0xa00df588 (72 bytes)
a00df540:  9d e3 bf 98  save  %sp, -104, %sp
a00df544:  a2 0e a0 ff  and  %i2, 0xff, %l1
a00df548:  82 0e 60 ff  and  %i1, 0xff, %g1
a00df54c:  a0 10 20 01  mov  1, %l0
a00df550:  80 a0 40 11  cmp  %g1, %l1
a00df554:  1a 80 00 04  bcc  0xa00df564
a00df558:  90 10 00 18  mov  %i0, %o0
a00df55c:  a2 10 00 01  mov  %g1, %l1
a00df560:  82 0e a0 ff  and  %i2, 0xff, %g1
a00df564:  83 2c 00 01  sll  %l0, %g1, %g1
a00df568:  95 2c 00 11  sll  %l0, %l1, %o2
a00df56c:  92 20 40 0a  sub  %g1, %o2, %o1
a00df570:  40 00 03 2b  call  0xa00e021c
a00df574:  a0 02 40 01  add  %o1, %g1, %l0
a00df578:  90 0a 00 10  and  %o0, %l0, %o0
a00df57c:  b1 32 00 11  srl  %o0, %l1, %i0
a00df580:  81 c7 e0 08  ret
a00df584:  81 e8 00 00  restore
