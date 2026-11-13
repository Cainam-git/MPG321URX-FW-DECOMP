# leon2m FUN_a014e478 0xa014e478-0xa014e4b8 (64 bytes)
a014e478:  9d e3 bf 98  save  %sp, -104, %sp
a014e47c:  a2 0e 20 ff  and  %i0, 0xff, %l1
a014e480:  a0 10 20 00  clr  %l0
a014e484:  b0 10 20 00  clr  %i0
a014e488:  7f ff 5b 6a  call  0xa0125230
a014e48c:  90 10 00 18  mov  %i0, %o0
a014e490:  90 0a 20 ff  and  %o0, 0xff, %o0
a014e494:  80 a2 00 11  cmp  %o0, %l1
a014e498:  02 80 00 06  be  0xa014e4b0
a014e49c:  a0 04 20 01  inc  %l0
a014e4a0:  b0 0c 20 ff  and  %l0, 0xff, %i0
a014e4a4:  80 a6 20 07  cmp  %i0, 7
a014e4a8:  08 bf ff f8  bleu  0xa014e488
a014e4ac:  01 00 00 00  nop
a014e4b0:  81 c7 e0 08  ret
a014e4b4:  81 e8 00 00  restore
