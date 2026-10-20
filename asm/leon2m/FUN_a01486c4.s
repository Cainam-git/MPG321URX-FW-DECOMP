# leon2m FUN_a01486c4 0xa01486c4-0xa0148794 (208 bytes)
a01486c4:  9d e3 bf 98  save  %sp, -104, %sp
a01486c8:  80 8e 20 ff  btst  0xff, %i0
a01486cc:  22 80 00 1e  be,a   0xa0148744
a01486d0:  b0 10 20 00  clr  %i0
a01486d4:  a0 10 20 00  clr  %l0
a01486d8:  b0 10 20 00  clr  %i0
a01486dc:  a2 10 20 01  mov  1, %l1
a01486e0:  10 80 00 0c  b  0xa0148710
a01486e4:  a4 10 20 55  mov  0x55, %l2
a01486e8:  7f ff 6f 38  call  0xa01243c8
a01486ec:  a0 04 20 01  inc  %l0
a01486f0:  92 0a 20 ff  and  %o0, 0xff, %o1
a01486f4:  91 2c 40 18  sll  %l1, %i0, %o0
a01486f8:  7f ff ad e1  call  0xa0133e7c
a01486fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0148700:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0148704:  80 a6 20 07  cmp  %i0, 7
a0148708:  18 80 00 21  bgu  0xa014878c
a014870c:  01 00 00 00  nop
a0148710:  83 3c 80 18  sra  %l2, %i0, %g1
a0148714:  90 10 00 18  mov  %i0, %o0
a0148718:  80 88 60 01  btst  1, %g1
a014871c:  12 bf ff f3  bne  0xa01486e8
a0148720:  9b 2c 40 18  sll  %l1, %i0, %o5
a0148724:  90 0b 60 ff  and  %o5, 0xff, %o0
a0148728:  7f ff ad cc  call  0xa0133e58
a014872c:  a0 04 20 01  inc  %l0
a0148730:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0148734:  80 a6 20 07  cmp  %i0, 7
a0148738:  08 bf ff f7  bleu  0xa0148714
a014873c:  83 3c 80 18  sra  %l2, %i0, %g1
a0148740:  30 80 00 13  b,a   0xa014878c
a0148744:  82 10 20 00  clr  %g1
a0148748:  a2 10 20 55  mov  0x55, %l1
a014874c:  10 80 00 06  b  0xa0148764
a0148750:  a0 10 20 01  mov  1, %l0
a0148754:  82 0e 20 ff  and  %i0, 0xff, %g1
a0148758:  80 a0 60 07  cmp  %g1, 7
a014875c:  18 80 00 0c  bgu  0xa014878c
a0148760:  01 00 00 00  nop
a0148764:  93 2c 00 01  sll  %l0, %g1, %o1
a0148768:  95 3c 40 01  sra  %l1, %g1, %o2
a014876c:  b0 06 20 01  inc  %i0
a0148770:  80 8a a0 01  btst  1, %o2
a0148774:  02 bf ff f8  be  0xa0148754
a0148778:  90 0a 60 ff  and  %o1, 0xff, %o0
a014877c:  7f ff ad b7  call  0xa0133e58
a0148780:  01 00 00 00  nop
a0148784:  10 bf ff f5  b  0xa0148758
a0148788:  82 0e 20 ff  and  %i0, 0xff, %g1
a014878c:  81 c7 e0 08  ret
a0148790:  81 e8 00 00  restore
