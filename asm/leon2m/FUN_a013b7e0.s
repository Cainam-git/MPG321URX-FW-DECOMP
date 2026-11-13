# leon2m FUN_a013b7e0 0xa013b7e0-0xa013b86c (140 bytes)
a013b7e0:  9d e3 bf 98  save  %sp, -104, %sp
a013b7e4:  67 fd 47 69  call  0x4008d588
a013b7e8:  01 00 00 00  nop
a013b7ec:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a013b7f0:  d2 13 63 d0  lduh  [ %o5 + 0x3d0 ], %o1	! 0xa802cbd0
a013b7f4:  82 22 00 09  sub  %o0, %o1, %g1
a013b7f8:  d0 33 63 d0  sth  %o0, [ %o5 + 0x3d0 ]
a013b7fc:  99 28 60 10  sll  %g1, 0x10, %o4
a013b800:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a013b804:  90 10 00 01  mov  %g1, %o0
a013b808:  99 33 20 10  srl  %o4, 0x10, %o4
a013b80c:  92 10 20 00  clr  %o1
a013b810:  82 10 20 00  clr  %g1
a013b814:  10 80 00 07  b  0xa013b830
a013b818:  94 13 e3 be  or  %o7, 0x3be, %o2
a013b81c:  92 02 60 01  inc  %o1
a013b820:  82 0a 60 ff  and  %o1, 0xff, %g1
a013b824:  80 a0 60 08  cmp  %g1, 8
a013b828:  18 80 00 0c  bgu  0xa013b858
a013b82c:  c0 32 80 0b  clrh  [ %o2 + %o3 ]
a013b830:  96 00 40 01  add  %g1, %g1, %o3
a013b834:  c2 12 80 0b  lduh  [ %o2 + %o3 ], %g1
a013b838:  80 a0 40 0c  cmp  %g1, %o4
a013b83c:  0a bf ff f8  bcs  0xa013b81c
a013b840:  9a 20 40 08  sub  %g1, %o0, %o5
a013b844:  92 02 60 01  inc  %o1
a013b848:  82 0a 60 ff  and  %o1, 0xff, %g1
a013b84c:  80 a0 60 08  cmp  %g1, 8
a013b850:  08 bf ff f8  bleu  0xa013b830
a013b854:  da 32 80 0b  sth  %o5, [ %o2 + %o3 ]
a013b858:  94 13 e3 be  or  %o7, 0x3be, %o2
a013b85c:  90 06 00 18  add  %i0, %i0, %o0
a013b860:  f0 12 80 08  lduh  [ %o2 + %o0 ], %i0
a013b864:  81 c7 e0 08  ret
a013b868:  81 e8 00 00  restore
