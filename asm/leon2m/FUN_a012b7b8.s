# leon2m FUN_a012b7b8 0xa012b7b8-0xa012b86c (180 bytes)
a012b7b8:  9d e3 bf 98  save  %sp, -104, %sp
a012b7bc:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a012b7c0:  d0 04 21 a0  ld  [ %l0 + 0x1a0 ], %o0	! 0xa802e1a0
a012b7c4:  83 32 20 19  srl  %o0, 0x19, %g1
a012b7c8:  80 88 60 01  btst  1, %g1
a012b7cc:  12 80 00 03  bne  0xa012b7d8
a012b7d0:  90 10 20 01  mov  1, %o0
a012b7d4:  90 10 20 00  clr  %o0
a012b7d8:  7f ff ff 20  call  0xa012b458
a012b7dc:  01 00 00 00  nop
a012b7e0:  d4 04 21 a0  ld  [ %l0 + 0x1a0 ], %o2
a012b7e4:  93 32 a0 19  srl  %o2, 0x19, %o1
a012b7e8:  80 8a 60 01  btst  1, %o1
a012b7ec:  12 80 00 03  bne  0xa012b7f8
a012b7f0:  90 10 20 00  clr  %o0
a012b7f4:  90 10 20 01  mov  1, %o0
a012b7f8:  7f ff ff 18  call  0xa012b458
a012b7fc:  01 00 00 00  nop
a012b800:  d8 04 21 a0  ld  [ %l0 + 0x1a0 ], %o4
a012b804:  97 33 20 19  srl  %o4, 0x19, %o3
a012b808:  80 8a e0 01  btst  1, %o3
a012b80c:  12 80 00 03  bne  0xa012b818
a012b810:  90 10 20 01  mov  1, %o0
a012b814:  90 10 20 00  clr  %o0
a012b818:  7f ff 70 7f  call  0xa0107a14
a012b81c:  b0 10 20 01  mov  1, %i0
a012b820:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a012b824:  a0 13 61 16  or  %o5, 0x116, %l0	! 0xa802e116
a012b828:  7f ff e6 3f  call  0xa0125124
a012b82c:  d0 0c 20 34  ldub  [ %l0 + 0x34 ], %o0
a012b830:  92 0a 20 ff  and  %o0, 0xff, %o1
a012b834:  94 10 20 01  mov  1, %o2
a012b838:  96 10 20 00  clr  %o3
a012b83c:  7f ff 70 dc  call  0xa0107bac
a012b840:  90 10 20 00  clr  %o0
a012b844:  7f ff e6 38  call  0xa0125124
a012b848:  d0 0c 20 46  ldub  [ %l0 + 0x46 ], %o0
a012b84c:  92 0a 20 ff  and  %o0, 0xff, %o1
a012b850:  90 10 20 01  mov  1, %o0
a012b854:  94 10 20 01  mov  1, %o2
a012b858:  7f ff 70 d5  call  0xa0107bac
a012b85c:  96 10 20 00  clr  %o3
a012b860:  40 00 31 38  call  0xa0137d40
a012b864:  81 e8 00 00  restore
a012b868:  01 00 00 00  nop
