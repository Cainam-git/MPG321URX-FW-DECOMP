# leon2m FUN_a00b3614 0xa00b3614-0xa00b3708 (244 bytes)
a00b3614:  9d e3 bf 98  save  %sp, -104, %sp
a00b3618:  82 0e 20 ff  and  %i0, 0xff, %g1
a00b361c:  80 a0 60 03  cmp  %g1, 3
a00b3620:  28 80 00 05  bleu,a   0xa00b3634
a00b3624:  b0 00 40 01  add  %g1, %g1, %i0
a00b3628:  82 06 3f fc  add  %i0, -4, %g1
a00b362c:  82 08 60 ff  and  %g1, 0xff, %g1
a00b3630:  b0 00 40 01  add  %g1, %g1, %i0
a00b3634:  98 06 20 05  add  %i0, 5, %o4
a00b3638:  80 8e 60 ff  btst  0xff, %i1
a00b363c:  b1 2b 20 10  sll  %o4, 0x10, %i0
a00b3640:  02 80 00 13  be  0xa00b368c
a00b3644:  b2 10 20 00  clr  %i1
a00b3648:  96 0e 60 ff  and  %i1, 0xff, %o3
a00b364c:  94 02 e0 04  add  %o3, 4, %o2
a00b3650:  93 2a a0 10  sll  %o2, 0x10, %o1
a00b3654:  98 06 60 1c  add  %i1, 0x1c, %o4
a00b3658:  90 10 20 00  clr  %o0
a00b365c:  93 32 60 10  srl  %o1, 0x10, %o1
a00b3660:  98 0b 20 ff  and  %o4, 0xff, %o4
a00b3664:  95 36 20 10  srl  %i0, 0x10, %o2
a00b3668:  96 10 20 01  mov  1, %o3
a00b366c:  40 02 4d 2d  call  0xa0146b20
a00b3670:  9a 10 20 00  clr  %o5
a00b3674:  b2 06 60 01  inc  %i1
a00b3678:  90 0e 60 ff  and  %i1, 0xff, %o0
a00b367c:  80 a2 20 01  cmp  %o0, 1
a00b3680:  08 bf ff f3  bleu  0xa00b364c
a00b3684:  96 0e 60 ff  and  %i1, 0xff, %o3
a00b3688:  30 80 00 1e  b,a   0xa00b3700
a00b368c:  90 0e 60 ff  and  %i1, 0xff, %o0
a00b3690:  82 02 20 04  add  %o0, 4, %g1
a00b3694:  9f 28 60 10  sll  %g1, 0x10, %o7
a00b3698:  9a 10 20 00  clr  %o5
a00b369c:  93 33 e0 10  srl  %o7, 0x10, %o1
a00b36a0:  90 10 20 00  clr  %o0
a00b36a4:  95 36 20 10  srl  %i0, 0x10, %o2
a00b36a8:  96 10 20 01  mov  1, %o3
a00b36ac:  40 02 4d 1d  call  0xa0146b20
a00b36b0:  98 10 20 00  clr  %o4
a00b36b4:  b2 06 60 01  inc  %i1
a00b36b8:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00b36bc:  80 a3 60 01  cmp  %o5, 1
a00b36c0:  18 80 00 10  bgu  0xa00b3700
a00b36c4:  90 0e 60 ff  and  %i1, 0xff, %o0
a00b36c8:  82 02 20 04  add  %o0, 4, %g1
a00b36cc:  9f 28 60 10  sll  %g1, 0x10, %o7
a00b36d0:  9a 10 20 00  clr  %o5
a00b36d4:  93 33 e0 10  srl  %o7, 0x10, %o1
a00b36d8:  90 10 20 00  clr  %o0
a00b36dc:  95 36 20 10  srl  %i0, 0x10, %o2
a00b36e0:  96 10 20 01  mov  1, %o3
a00b36e4:  40 02 4d 0f  call  0xa0146b20
a00b36e8:  98 10 20 00  clr  %o4
a00b36ec:  b2 06 60 01  inc  %i1
a00b36f0:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00b36f4:  80 a3 60 01  cmp  %o5, 1
a00b36f8:  08 bf ff e6  bleu  0xa00b3690
a00b36fc:  90 0e 60 ff  and  %i1, 0xff, %o0
a00b3700:  81 c7 e0 08  ret
a00b3704:  81 e8 00 00  restore
