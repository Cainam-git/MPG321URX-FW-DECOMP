# leon2s FUN_a00cc834 0xa00cc834-0xa00cc8d4 (160 bytes)
a00cc834:  82 0a 20 ff  and  %o0, 0xff, %g1
a00cc838:  80 a0 60 02  cmp  %g1, 2
a00cc83c:  12 80 00 16  bne  0xa00cc894
a00cc840:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00cc844:  80 a3 60 00  cmp  %o5, 0
a00cc848:  02 80 00 0a  be  0xa00cc870
a00cc84c:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00cc850:  82 10 61 00  or  %g1, 0x100, %g1	! 0xcf018d00
a00cc854:  da 00 40 00  ld  [ %g1 ], %o5
a00cc858:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00cc85c:  9b 2b 60 02  sll  %o5, 2, %o5
a00cc860:  9a 13 40 01  or  %o5, %g1, %o5
a00cc864:  c2 03 40 00  ld  [ %o5 ], %g1
a00cc868:  10 80 00 09  b  0xa00cc88c
a00cc86c:  82 10 60 02  or  %g1, 2, %g1
a00cc870:  82 10 61 00  or  %g1, 0x100, %g1
a00cc874:  da 00 40 00  ld  [ %g1 ], %o5
a00cc878:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00cc87c:  9b 2b 60 02  sll  %o5, 2, %o5
a00cc880:  9a 13 40 01  or  %o5, %g1, %o5
a00cc884:  c2 03 40 00  ld  [ %o5 ], %g1
a00cc888:  82 08 7f fd  and  %g1, -3, %g1
a00cc88c:  c2 23 40 00  st  %g1, [ %o5 ]
a00cc890:  30 80 00 0e  b,a   0xa00cc8c8
a00cc894:  90 10 00 01  mov  %g1, %o0
a00cc898:  92 10 20 04  mov  4, %o1
a00cc89c:  94 10 20 10  mov  0x10, %o2
a00cc8a0:  80 a3 60 00  cmp  %o5, 0
a00cc8a4:  12 80 00 06  bne  0xa00cc8bc
a00cc8a8:  96 10 20 01  mov  1, %o3
a00cc8ac:  90 10 00 01  mov  %g1, %o0
a00cc8b0:  92 10 20 04  mov  4, %o1
a00cc8b4:  94 10 20 10  mov  0x10, %o2
a00cc8b8:  96 10 20 00  clr  %o3
a00cc8bc:  82 13 c0 00  mov  %o7, %g1
a00cc8c0:  7f ff eb 80  call  0xa00c76c0
a00cc8c4:  9e 10 40 00  mov  %g1, %o7
a00cc8c8:  01 00 00 00  nop
a00cc8cc:  81 c3 e0 08  retl
a00cc8d0:  01 00 00 00  nop
