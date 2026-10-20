# leon2m FUN_a009e780 0xa009e780-0xa009e820 (160 bytes)
a009e780:  9d e3 bf 98  save  %sp, -104, %sp
a009e784:  7f ff 89 15  call  0xa0080bd8
a009e788:  90 10 20 00  clr  %o0
a009e78c:  31 2a 00 b3  sethi  %hi(0xa802cc00), %i0
a009e790:  98 16 23 f4  or  %i0, 0x3f4, %o4	! 0xa802cff4
a009e794:  1f 00 00 1f  sethi  %hi(0x7c00), %o7
a009e798:  d6 13 20 04  lduh  [ %o4 + 4 ], %o3
a009e79c:  94 13 e3 7f  or  %o7, 0x37f, %o2
a009e7a0:  92 0a 80 0b  and  %o2, %o3, %o1
a009e7a4:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a009e7a8:  d2 33 20 04  sth  %o1, [ %o4 + 4 ]
a009e7ac:  40 00 5a 35  call  0xa00b5080
a009e7b0:  c0 22 23 ec  clr  [ %o0 + 0x3ec ]
a009e7b4:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a009e7b8:  da 08 60 65  ldub  [ %g1 + 0x65 ], %o5	! 0xa802d465
a009e7bc:  90 10 20 00  clr  %o0
a009e7c0:  b0 10 20 00  clr  %i0
a009e7c4:  80 a3 60 00  cmp  %o5, 0
a009e7c8:  12 80 00 0a  bne  0xa009e7f0
a009e7cc:  b2 10 20 00  clr  %i1
a009e7d0:  40 02 95 11  call  0xa0143c14
a009e7d4:  90 10 20 00  clr  %o0
a009e7d8:  82 0a 20 ff  and  %o0, 0xff, %g1
a009e7dc:  80 a0 60 0a  cmp  %g1, 0xa
a009e7e0:  02 80 00 0e  be  0xa009e818
a009e7e4:  01 00 00 00  nop
a009e7e8:  40 02 9a 51  call  0xa014512c
a009e7ec:  81 e8 00 00  restore
a009e7f0:  40 02 95 09  call  0xa0143c14
a009e7f4:  01 00 00 00  nop
a009e7f8:  9a 0a 20 ff  and  %o0, 0xff, %o5
a009e7fc:  80 a3 60 0a  cmp  %o5, 0xa
a009e800:  92 10 20 00  clr  %o1
a009e804:  02 bf ff f3  be  0xa009e7d0
a009e808:  90 10 20 04  mov  4, %o0
a009e80c:  7f ff 88 28  call  0xa00808ac
a009e810:  01 00 00 00  nop
a009e814:  30 bf ff ef  b,a   0xa009e7d0
a009e818:  81 c7 e0 08  ret
a009e81c:  81 e8 00 00  restore
