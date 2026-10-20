# leon2m FUN_a0123840 0xa0123840-0xa01238e8 (168 bytes)
a0123840:  9d e3 bf 98  save  %sp, -104, %sp
a0123844:  67 fd a7 51  call  0x4008d588
a0123848:  b0 10 20 00  clr  %i0
a012384c:  03 00 00 18  sethi  %hi(0x6000), %g1
a0123850:  a0 10 00 08  mov  %o0, %l0
a0123854:  a2 10 61 a7  or  %g1, 0x1a7, %l1
a0123858:  25 2a 00 b6  sethi  %hi(0xa802d800), %l2
a012385c:  7f ff f6 c6  call  0xa0121374
a0123860:  90 10 20 00  clr  %o0
a0123864:  13 33 c0 f1  sethi  %hi(0xcf03c400), %o1
a0123868:  90 0a 20 ff  and  %o0, 0xff, %o0
a012386c:  9a 12 62 48  or  %o1, 0x248, %o5
a0123870:  80 a2 20 01  cmp  %o0, 1
a0123874:  02 80 00 1a  be  0xa01238dc
a0123878:  82 12 62 40  or  %o1, 0x240, %g1
a012387c:  d4 00 40 00  ld  [ %g1 ], %o2
a0123880:  80 a2 a0 83  cmp  %o2, 0x83
a0123884:  38 80 00 12  bgu,a   0xa01238cc
a0123888:  c0 2c a0 7e  clrb  [ %l2 + 0x7e ]
a012388c:  d6 03 40 00  ld  [ %o5 ], %o3
a0123890:  80 a2 e0 83  cmp  %o3, 0x83
a0123894:  18 80 00 10  bgu  0xa01238d4
a0123898:  98 10 20 01  mov  1, %o4
a012389c:  67 fd a5 8f  call  0x4008ced8
a01238a0:  01 00 00 00  nop
a01238a4:  83 2c 20 10  sll  %l0, 0x10, %g1
a01238a8:  67 fd a7 3b  call  0x4008d594
a01238ac:  91 30 60 10  srl  %g1, 0x10, %o0
a01238b0:  9f 2a 20 10  sll  %o0, 0x10, %o7
a01238b4:  9b 33 e0 10  srl  %o7, 0x10, %o5
a01238b8:  80 a3 40 11  cmp  %o5, %l1
a01238bc:  08 bf ff e8  bleu  0xa012385c
a01238c0:  01 00 00 00  nop
a01238c4:  10 80 00 07  b  0xa01238e0
a01238c8:  b0 0e 20 01  and  %i0, 1, %i0
a01238cc:  10 80 00 04  b  0xa01238dc
a01238d0:  b0 10 20 01  mov  1, %i0
a01238d4:  d8 2c a0 7e  stb  %o4, [ %l2 + 0x7e ]
a01238d8:  b0 10 20 01  mov  1, %i0
a01238dc:  b0 0e 20 01  and  %i0, 1, %i0
a01238e0:  81 c7 e0 08  ret
a01238e4:  81 e8 00 00  restore
