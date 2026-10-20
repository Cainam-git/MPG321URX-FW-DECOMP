# leon2s FUN_a00c7654 0xa00c7654-0xa00c76c0 (108 bytes)
a00c7654:  9d e3 bf 98  save  %sp, -104, %sp
a00c7658:  82 0e 20 ff  and  %i0, 0xff, %g1
a00c765c:  b7 2e 60 10  sll  %i1, 0x10, %i3
a00c7660:  9e 0e a0 ff  and  %i2, 0xff, %o7
a00c7664:  31 27 c7 07  sethi  %hi(0x9f1c1c00), %i0
a00c7668:  9b 36 e0 10  srl  %i3, 0x10, %o5
a00c766c:  33 27 c7 07  sethi  %hi(0x9f1c1c00), %i1
a00c7670:  b0 16 23 18  or  %i0, 0x318, %i0
a00c7674:  b2 16 62 d8  or  %i1, 0x2d8, %i1
a00c7678:  b6 10 00 0d  mov  %o5, %i3
a00c767c:  b4 10 00 01  mov  %g1, %i2
a00c7680:  b8 10 00 0f  mov  %o7, %i4
a00c7684:  80 a0 60 02  cmp  %g1, 2
a00c7688:  08 80 00 04  bleu  0xa00c7698
a00c768c:  bb 28 60 02  sll  %g1, 2, %i5
a00c7690:  40 3a ee 6d  call  0xa0f83044
a00c7694:  81 e8 00 00  restore
a00c7698:  03 27 c7 07  sethi  %hi(0x9f1c1c00), %g1
a00c769c:  82 10 62 c8  or  %g1, 0x2c8, %g1	! 0x9f1c1ec8
a00c76a0:  c2 00 40 1d  ld  [ %g1 + %i5 ], %g1
a00c76a4:  82 00 40 0d  add  %g1, %o5, %g1
a00c76a8:  83 28 60 02  sll  %g1, 2, %g1
a00c76ac:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00c76b0:  82 10 40 1d  or  %g1, %i5, %g1
a00c76b4:  de 20 40 00  st  %o7, [ %g1 ]
a00c76b8:  81 c7 e0 08  ret
a00c76bc:  81 e8 00 00  restore
