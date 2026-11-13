# leon2m FUN_a014a588 0xa014a588-0xa014a654 (204 bytes)
a014a588:  9d e3 bf 98  save  %sp, -104, %sp
a014a58c:  7f ff 6b 03  call  0xa0125198
a014a590:  90 0e 20 ff  and  %i0, 0xff, %o0
a014a594:  7f ff df 21  call  0xa0142218
a014a598:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a59c:  7f ff df 0a  call  0xa01421c4
a014a5a0:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a5a4:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a5a8:  80 a2 20 71  cmp  %o0, 0x71
a014a5ac:  02 80 00 1f  be  0xa014a628
a014a5b0:  80 a2 20 81  cmp  %o0, 0x81
a014a5b4:  02 80 00 23  be  0xa014a640
a014a5b8:  b0 10 3f ff  mov  -1, %i0
a014a5bc:  b2 0e 60 ff  and  %i1, 0xff, %i1
a014a5c0:  80 a6 60 02  cmp  %i1, 2
a014a5c4:  02 80 00 09  be  0xa014a5e8
a014a5c8:  92 10 20 02  mov  2, %o1
a014a5cc:  80 a6 60 02  cmp  %i1, 2
a014a5d0:  14 80 00 0f  bg  0xa014a60c
a014a5d4:  80 a6 60 03  cmp  %i1, 3
a014a5d8:  80 a6 60 01  cmp  %i1, 1
a014a5dc:  02 80 00 03  be  0xa014a5e8
a014a5e0:  92 10 20 01  mov  1, %o1
a014a5e4:  92 10 20 00  clr  %o1
a014a5e8:  90 0e 20 ff  and  %i0, 0xff, %o0
a014a5ec:  80 a2 20 ff  cmp  %o0, 0xff
a014a5f0:  02 80 00 17  be  0xa014a64c
a014a5f4:  92 0a 60 03  and  %o1, 3, %o1
a014a5f8:  7f ff 82 52  call  0xa012af40
a014a5fc:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a014a600:  b0 16 21 a0  or  %i0, 0x1a0, %i0	! 0xa802e1a0
a014a604:  40 00 24 db  call  0xa0153970
a014a608:  93 e8 20 00  restore  %g0, 0, %o1
a014a60c:  12 bf ff f6  bne  0xa014a5e4
a014a610:  92 10 20 03  mov  3, %o1
a014a614:  90 0e 20 ff  and  %i0, 0xff, %o0
a014a618:  80 a2 20 ff  cmp  %o0, 0xff
a014a61c:  32 bf ff f7  bne,a   0xa014a5f8
a014a620:  92 0a 60 03  and  %o1, 3, %o1
a014a624:  30 80 00 0a  b,a   0xa014a64c
a014a628:  b0 10 20 00  clr  %i0
a014a62c:  90 10 20 10  mov  0x10, %o0
a014a630:  40 00 1d 1d  call  0xa0151aa4
a014a634:  92 10 20 01  mov  1, %o1
a014a638:  10 bf ff e2  b  0xa014a5c0
a014a63c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a014a640:  b0 10 20 01  mov  1, %i0
a014a644:  10 bf ff fb  b  0xa014a630
a014a648:  90 10 20 20  mov  0x20, %o0
a014a64c:  81 c7 e0 08  ret
a014a650:  81 e8 00 00  restore
