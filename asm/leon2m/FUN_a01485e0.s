# leon2m FUN_a01485e0 0xa01485e0-0xa0148680 (160 bytes)
a01485e0:  9d e3 bf 98  save  %sp, -104, %sp
a01485e4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01485e8:  80 a6 20 01  cmp  %i0, 1
a01485ec:  02 80 00 0b  be  0xa0148618
a01485f0:  82 10 20 01  mov  1, %g1
a01485f4:  80 a6 20 01  cmp  %i0, 1
a01485f8:  04 80 00 11  ble  0xa014863c
a01485fc:  80 a6 20 02  cmp  %i0, 2
a0148600:  02 80 00 06  be  0xa0148618
a0148604:  82 10 20 02  mov  2, %g1
a0148608:  80 a6 20 03  cmp  %i0, 3
a014860c:  02 80 00 03  be  0xa0148618
a0148610:  82 10 20 03  mov  3, %g1
a0148614:  82 10 3f ff  mov  -1, %g1
a0148618:  9a 08 60 ff  and  %g1, 0xff, %o5
a014861c:  80 a3 60 03  cmp  %o5, 3
a0148620:  08 80 00 0d  bleu  0xa0148654
a0148624:  9f 2b 60 04  sll  %o5, 4, %o7
a0148628:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a014862c:  7f fe 5a d1  call  0xa00df170
a0148630:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a0148634:  10 80 00 07  b  0xa0148650
a0148638:  9a 10 20 00  clr  %o5
a014863c:  80 a6 20 00  cmp  %i0, 0
a0148640:  02 bf ff f6  be  0xa0148618
a0148644:  82 10 20 00  clr  %g1
a0148648:  10 bf ff f4  b  0xa0148618
a014864c:  82 10 3f ff  mov  -1, %g1
a0148650:  9f 2b 60 04  sll  %o5, 4, %o7
a0148654:  98 23 c0 0d  sub  %o7, %o5, %o4
a0148658:  17 2a 00 b7  sethi  %hi(0xa802dc00), %o3
a014865c:  95 2b 20 03  sll  %o4, 3, %o2
a0148660:  9a 12 e3 30  or  %o3, 0x330, %o5
a0148664:  d2 03 40 0a  ld  [ %o5 + %o2 ], %o1
a0148668:  83 32 60 0c  srl  %o1, 0xc, %g1
a014866c:  7f ff de 94  call  0xa01400bc
a0148670:  90 08 60 0f  and  %g1, 0xf, %o0
a0148674:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0148678:  81 c7 e0 08  ret
a014867c:  81 e8 00 00  restore
