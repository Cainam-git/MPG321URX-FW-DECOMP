# leon2m FUN_a00f381c 0xa00f381c-0xa00f38d4 (184 bytes)
a00f381c:  9d e3 bf 98  save  %sp, -104, %sp
a00f3820:  67 fe 67 5a  call  0x4008d588
a00f3824:  29 33 c0 4a  sethi  %hi(0xcf012800), %l4
a00f3828:  03 3f ff f8  sethi  %hi(0xffffe000), %g1
a00f382c:  1b 00 00 07  sethi  %hi(0x1c00), %o5
a00f3830:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00f3834:  a6 10 60 01  or  %g1, 1, %l3
a00f3838:  aa 13 63 ff  or  %o5, 0x3ff, %l5
a00f383c:  25 2a 00 ad  sethi  %hi(0xa802b400), %l2
a00f3840:  10 80 00 14  b  0xa00f3890
a00f3844:  a2 15 20 44  or  %l4, 0x44, %l1
a00f3848:  d4 04 40 00  ld  [ %l1 ], %o2
a00f384c:  80 a2 a0 0b  cmp  %o2, 0xb
a00f3850:  22 80 00 02  be,a   0xa00f3858
a00f3854:  90 02 00 08  add  %o0, %o0, %o0
a00f3858:  d6 04 a3 94  ld  [ %l2 + 0x394 ], %o3
a00f385c:  82 22 00 0b  sub  %o0, %o3, %g1
a00f3860:  80 a0 40 13  cmp  %g1, %l3
a00f3864:  06 80 00 04  bl  0xa00f3874
a00f3868:  80 a0 40 15  cmp  %g1, %l5
a00f386c:  04 80 00 11  ble  0xa00f38b0
a00f3870:  91 34 20 10  srl  %l0, 0x10, %o0
a00f3874:  67 fe 67 48  call  0x4008d594
a00f3878:  91 34 20 10  srl  %l0, 0x10, %o0
a00f387c:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00f3880:  9f 33 60 10  srl  %o5, 0x10, %o7
a00f3884:  80 a3 e1 2b  cmp  %o7, 0x12b
a00f3888:  18 80 00 11  bgu  0xa00f38cc
a00f388c:  01 00 00 00  nop
a00f3890:  7f ff fe 06  call  0xa00f30a8
a00f3894:  90 15 20 48  or  %l4, 0x48, %o0
a00f3898:  d2 04 40 00  ld  [ %l1 ], %o1
a00f389c:  80 a2 60 0a  cmp  %o1, 0xa
a00f38a0:  12 bf ff ea  bne  0xa00f3848
a00f38a4:  01 00 00 00  nop
a00f38a8:  10 bf ff ec  b  0xa00f3858
a00f38ac:  91 2a 20 02  sll  %o0, 2, %o0
a00f38b0:  67 fe 67 39  call  0x4008d594
a00f38b4:  01 00 00 00  nop
a00f38b8:  99 2a 20 10  sll  %o0, 0x10, %o4
a00f38bc:  91 33 20 10  srl  %o4, 0x10, %o0
a00f38c0:  80 a2 20 1e  cmp  %o0, 0x1e
a00f38c4:  08 bf ff ec  bleu  0xa00f3874
a00f38c8:  01 00 00 00  nop
a00f38cc:  81 c7 e0 08  ret
a00f38d0:  81 e8 00 00  restore
