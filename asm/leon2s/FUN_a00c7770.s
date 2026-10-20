# leon2s FUN_a00c7770 0xa00c7770-0xa00c77dc (108 bytes)
a00c7770:  9d e3 bf 98  save  %sp, -104, %sp
a00c7774:  97 2e 60 10  sll  %i1, 0x10, %o3
a00c7778:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c777c:  11 27 c7 07  sethi  %hi(0x9f1c1c00), %o0
a00c7780:  13 27 c7 07  sethi  %hi(0x9f1c1c00), %o1
a00c7784:  9b 32 e0 10  srl  %o3, 0x10, %o5
a00c7788:  90 12 23 78  or  %o0, 0x378, %o0
a00c778c:  92 12 63 00  or  %o1, 0x300, %o1
a00c7790:  99 2e 20 02  sll  %i0, 2, %o4
a00c7794:  94 10 00 18  mov  %i0, %o2
a00c7798:  80 a6 20 02  cmp  %i0, 2
a00c779c:  08 80 00 05  bleu  0xa00c77b0
a00c77a0:  96 10 00 0d  mov  %o5, %o3
a00c77a4:  40 3a ee 28  call  0xa0f83044
a00c77a8:  b0 10 20 00  clr  %i0
a00c77ac:  30 80 00 0a  b,a   0xa00c77d4
a00c77b0:  03 27 c7 07  sethi  %hi(0x9f1c1c00), %g1
a00c77b4:  82 10 62 c8  or  %g1, 0x2c8, %g1	! 0x9f1c1ec8
a00c77b8:  c2 00 40 0c  ld  [ %g1 + %o4 ], %g1
a00c77bc:  82 00 40 0d  add  %g1, %o5, %g1
a00c77c0:  83 28 60 02  sll  %g1, 2, %g1
a00c77c4:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00c77c8:  82 10 40 0d  or  %g1, %o5, %g1
a00c77cc:  c2 00 40 00  ld  [ %g1 ], %g1
a00c77d0:  b0 08 60 ff  and  %g1, 0xff, %i0
a00c77d4:  81 c7 e0 08  ret
a00c77d8:  81 e8 00 00  restore
