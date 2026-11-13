# leon2m FUN_a01257f0 0xa01257f0-0xa012587c (140 bytes)
a01257f0:  9d e3 bf 88  save  %sp, -120, %sp
a01257f4:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a01257f8:  9e 10 60 30  or  %g1, 0x30, %o7	! 0xa802a430
a01257fc:  da 07 a0 5c  ld  [ %fp + 0x5c ], %o5
a0125800:  b8 0f 20 ff  and  %i4, 0xff, %i4
a0125804:  82 10 00 18  mov  %i0, %g1
a0125808:  95 2e a0 10  sll  %i2, 0x10, %o2
a012580c:  99 2b 60 10  sll  %o5, 0x10, %o4
a0125810:  90 07 bf e8  add  %fp, -24, %o0
a0125814:  92 10 00 19  mov  %i1, %o1
a0125818:  95 32 a0 10  srl  %o2, 0x10, %o2
a012581c:  96 10 00 1d  mov  %i5, %o3
a0125820:  80 a7 20 00  cmp  %i4, 0
a0125824:  99 33 20 10  srl  %o4, 0x10, %o4
a0125828:  12 80 00 11  bne  0xa012586c
a012582c:  b0 10 20 00  clr  %i0
a0125830:  b4 10 20 01  mov  1, %i2
a0125834:  c2 2b e0 06  stb  %g1, [ %o7 + 6 ]
a0125838:  f4 2b e0 07  stb  %i2, [ %o7 + 7 ]
a012583c:  f6 33 e0 04  sth  %i3, [ %o7 + 4 ]
a0125840:  f0 13 e0 02  lduh  [ %o7 + 2 ], %i0
a0125844:  f2 13 c0 1c  lduh  [ %o7 + %i4 ], %i1
a0125848:  e0 13 e0 08  lduh  [ %o7 + 8 ], %l0
a012584c:  de 13 e0 06  lduh  [ %o7 + 6 ], %o7
a0125850:  f0 37 bf ea  sth  %i0, [ %fp + -22 ]
a0125854:  f2 37 bf e8  sth  %i1, [ %fp + -24 ]
a0125858:  f6 37 bf ec  sth  %i3, [ %fp + -20 ]
a012585c:  de 37 bf ee  sth  %o7, [ %fp + -18 ]
a0125860:  67 fd 97 be  call  0x4008b758
a0125864:  e0 37 bf f0  sth  %l0, [ %fp + -16 ]
a0125868:  b0 10 00 08  mov  %o0, %i0
a012586c:  91 2e 20 10  sll  %i0, 0x10, %o0
a0125870:  b1 32 20 10  srl  %o0, 0x10, %i0
a0125874:  81 c7 e0 08  ret
a0125878:  81 e8 00 00  restore
