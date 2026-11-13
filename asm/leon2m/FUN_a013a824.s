# leon2m FUN_a013a824 0xa013a824-0xa013a85c (56 bytes)
a013a824:  9d e3 bf 90  save  %sp, -112, %sp
a013a828:  90 10 20 02  mov  2, %o0
a013a82c:  92 10 20 4c  mov  0x4c, %o1
a013a830:  c0 27 bf f4  clr  [ %fp + -12 ]
a013a834:  94 07 bf f4  add  %fp, -12, %o2
a013a838:  67 fd 47 26  call  0x4008c4d0
a013a83c:  96 10 20 01  mov  1, %o3
a013a840:  13 00 00 3f  sethi  %hi(0xfc00), %o1
a013a844:  d0 07 bf f4  ld  [ %fp + -12 ], %o0
a013a848:  82 12 63 00  or  %o1, 0x300, %g1
a013a84c:  b0 0a 00 01  and  %o0, %g1, %i0
a013a850:  b1 36 20 08  srl  %i0, 8, %i0
a013a854:  81 c7 e0 08  ret
a013a858:  81 e8 00 00  restore
