# leon2m FUN_a0151818 0xa0151818-0xa01518c8 (176 bytes)
a0151818:  9d e3 bf 98  save  %sp, -104, %sp
a015181c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0151820:  80 a6 20 02  cmp  %i0, 2
a0151824:  02 80 00 19  be  0xa0151888
a0151828:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a015182c:  14 80 00 12  bg  0xa0151874
a0151830:  80 a6 20 03  cmp  %i0, 3
a0151834:  80 a6 20 01  cmp  %i0, 1
a0151838:  02 80 00 20  be  0xa01518b8
a015183c:  11 2a 00 b7  sethi  %hi(0xa802dc00), %o0
a0151840:  1b 2a 00 b7  sethi  %hi(0xa802dc00), %o5
a0151844:  c2 03 63 30  ld  [ %o5 + 0x330 ], %g1	! 0xa802df30
a0151848:  97 30 60 0c  srl  %g1, 0xc, %o3
a015184c:  82 0a e0 0f  and  %o3, 0xf, %g1
a0151850:  80 88 60 ff  btst  0xff, %g1
a0151854:  12 80 00 1b  bne  0xa01518c0
a0151858:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a015185c:  d8 06 23 d0  ld  [ %i0 + 0x3d0 ], %o4	! 0xa802e3d0
a0151860:  1f 00 08 00  sethi  %hi(0x200000), %o7
a0151864:  80 8b 00 0f  btst  %o4, %o7
a0151868:  02 80 00 16  be  0xa01518c0
a015186c:  01 00 00 00  nop
a0151870:  30 80 00 08  b,a   0xa0151890
a0151874:  12 bf ff f4  bne  0xa0151844
a0151878:  1b 2a 00 b7  sethi  %hi(0xa802dc00), %o5
a015187c:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a0151880:  10 bf ff f2  b  0xa0151848
a0151884:  c2 02 a0 98  ld  [ %o2 + 0x98 ], %g1	! 0xa802e098
a0151888:  10 bf ff f0  b  0xa0151848
a015188c:  c2 02 60 20  ld  [ %o1 + 0x20 ], %g1
a0151890:  7f ff ad 46  call  0xa013cda8
a0151894:  90 10 20 03  mov  3, %o0
a0151898:  90 0a 20 ff  and  %o0, 0xff, %o0
a015189c:  7f fe db 03  call  0xa01084a8
a01518a0:  92 10 20 01  mov  1, %o1
a01518a4:  7f ff ad 41  call  0xa013cda8
a01518a8:  90 10 20 03  mov  3, %o0
a01518ac:  b0 0a 20 ff  and  %o0, 0xff, %i0
a01518b0:  7f fe df 29  call  0xa0109554
a01518b4:  93 e8 20 00  restore  %g0, 0, %o1
a01518b8:  10 bf ff e4  b  0xa0151848
a01518bc:  c2 02 23 a8  ld  [ %o0 + 0x3a8 ], %g1
a01518c0:  81 c7 e0 08  ret
a01518c4:  81 e8 00 00  restore
