# leon2s FUN_a00a0514 0xa00a0514-0xa00a0558 (68 bytes)
a00a0514:  9d e3 bf 98  save  %sp, -104, %sp
a00a0518:  a0 10 20 00  clr  %l0
a00a051c:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00a0520:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a0524:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00a0528:  9a 5b 60 34  smul  %o5, 0x34, %o5
a00a052c:  d2 00 40 0d  ld  [ %g1 + %o5 ], %o1
a00a0530:  92 02 60 78  add  %o1, 0x78, %o1
a00a0534:  40 00 1b 9e  call  0xa00a73ac
a00a0538:  90 10 20 09  mov  9, %o0
a00a053c:  a0 04 20 01  inc  %l0
a00a0540:  82 0c 20 ff  and  %l0, 0xff, %g1
a00a0544:  80 a0 60 01  cmp  %g1, 1
a00a0548:  08 bf ff f6  bleu  0xa00a0520
a00a054c:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00a0550:  81 c7 e0 08  ret
a00a0554:  81 e8 00 00  restore
