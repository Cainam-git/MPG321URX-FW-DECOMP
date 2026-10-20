# leon2m FUN_a013b754 0xa013b754-0xa013b7e0 (140 bytes)
a013b754:  9d e3 bf 98  save  %sp, -104, %sp
a013b758:  67 fd 47 8c  call  0x4008d588
a013b75c:  01 00 00 00  nop
a013b760:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a013b764:  d2 13 63 d0  lduh  [ %o5 + 0x3d0 ], %o1	! 0xa802cbd0
a013b768:  82 22 00 09  sub  %o0, %o1, %g1
a013b76c:  d0 33 63 d0  sth  %o0, [ %o5 + 0x3d0 ]
a013b770:  99 28 60 10  sll  %g1, 0x10, %o4
a013b774:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a013b778:  90 10 00 01  mov  %g1, %o0
a013b77c:  99 33 20 10  srl  %o4, 0x10, %o4
a013b780:  92 10 20 00  clr  %o1
a013b784:  82 10 20 00  clr  %g1
a013b788:  10 80 00 07  b  0xa013b7a4
a013b78c:  94 13 e3 be  or  %o7, 0x3be, %o2
a013b790:  92 02 60 01  inc  %o1
a013b794:  82 0a 60 ff  and  %o1, 0xff, %g1
a013b798:  80 a0 60 08  cmp  %g1, 8
a013b79c:  18 80 00 0c  bgu  0xa013b7cc
a013b7a0:  c0 32 80 0b  clrh  [ %o2 + %o3 ]
a013b7a4:  96 00 40 01  add  %g1, %g1, %o3
a013b7a8:  c2 12 80 0b  lduh  [ %o2 + %o3 ], %g1
a013b7ac:  80 a0 40 0c  cmp  %g1, %o4
a013b7b0:  0a bf ff f8  bcs  0xa013b790
a013b7b4:  9a 20 40 08  sub  %g1, %o0, %o5
a013b7b8:  92 02 60 01  inc  %o1
a013b7bc:  82 0a 60 ff  and  %o1, 0xff, %g1
a013b7c0:  80 a0 60 08  cmp  %g1, 8
a013b7c4:  08 bf ff f8  bleu  0xa013b7a4
a013b7c8:  da 32 80 0b  sth  %o5, [ %o2 + %o3 ]
a013b7cc:  94 13 e3 be  or  %o7, 0x3be, %o2
a013b7d0:  90 06 00 18  add  %i0, %i0, %o0
a013b7d4:  f2 32 80 08  sth  %i1, [ %o2 + %o0 ]
a013b7d8:  81 c7 e0 08  ret
a013b7dc:  81 e8 00 00  restore
