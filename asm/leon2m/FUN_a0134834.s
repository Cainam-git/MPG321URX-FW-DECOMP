# leon2m FUN_a0134834 0xa0134834-0xa01348a0 (108 bytes)
a0134834:  9d e3 bf 98  save  %sp, -104, %sp
a0134838:  b9 2e a0 10  sll  %i2, 0x10, %i4
a013483c:  b7 37 20 10  srl  %i4, 0x10, %i3
a0134840:  82 06 e0 03  add  %i3, 3, %g1
a0134844:  b5 30 60 02  srl  %g1, 2, %i2
a0134848:  9e 0e a0 ff  and  %i2, 0xff, %o7
a013484c:  80 a3 e0 00  cmp  %o7, 0
a0134850:  02 80 00 12  be  0xa0134898
a0134854:  b4 10 20 00  clr  %i2
a0134858:  b8 10 20 00  clr  %i4
a013485c:  b9 2f 20 02  sll  %i4, 2, %i4
a0134860:  f6 0e 40 1c  ldub  [ %i1 + %i4 ], %i3
a0134864:  f6 2e 00 1c  stb  %i3, [ %i0 + %i4 ]
a0134868:  c2 16 40 1c  lduh  [ %i1 + %i4 ], %g1
a013486c:  b6 07 00 18  add  %i4, %i0, %i3
a0134870:  c2 2e e0 01  stb  %g1, [ %i3 + 1 ]
a0134874:  fa 06 40 1c  ld  [ %i1 + %i4 ], %i5
a0134878:  83 37 60 08  srl  %i5, 8, %g1
a013487c:  c2 2e e0 02  stb  %g1, [ %i3 + 2 ]
a0134880:  fa 06 40 1c  ld  [ %i1 + %i4 ], %i5
a0134884:  b4 06 a0 01  inc  %i2
a0134888:  b8 0e a0 ff  and  %i2, 0xff, %i4
a013488c:  80 a7 00 0f  cmp  %i4, %o7
a0134890:  0a bf ff f3  bcs  0xa013485c
a0134894:  fa 2e e0 03  stb  %i5, [ %i3 + 3 ]
a0134898:  81 c7 e0 08  ret
a013489c:  81 e8 00 00  restore
