# leon2s FUN_a006fca8 0xa006fca8-0xa006fd04 (92 bytes)
a006fca8:  9d e3 bf 88  save  %sp, -120, %sp
a006fcac:  98 10 20 00  clr  %o4
a006fcb0:  9a 10 20 00  clr  %o5
a006fcb4:  94 07 bf e8  add  %fp, -24, %o2
a006fcb8:  96 10 20 04  mov  4, %o3
a006fcbc:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a006fcc0:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a006fcc4:  90 10 20 00  clr  %o0
a006fcc8:  7f ff ff 78  call  0xa006faa8
a006fccc:  92 10 20 00  clr  %o1
a006fcd0:  96 10 20 00  clr  %o3
a006fcd4:  d4 07 bf ec  ld  [ %fp + -20 ], %o2
a006fcd8:  82 0a e0 ff  and  %o3, 0xff, %g1
a006fcdc:  9b 28 60 02  sll  %g1, 2, %o5
a006fce0:  9b 32 80 0d  srl  %o2, %o5, %o5
a006fce4:  96 02 e0 01  inc  %o3
a006fce8:  9a 0b 60 0f  and  %o5, 0xf, %o5
a006fcec:  98 0a e0 ff  and  %o3, 0xff, %o4
a006fcf0:  80 a3 20 07  cmp  %o4, 7
a006fcf4:  0a bf ff f9  bcs  0xa006fcd8
a006fcf8:  da 2e 00 01  stb  %o5, [ %i0 + %g1 ]
a006fcfc:  81 c7 e0 08  ret
a006fd00:  81 e8 00 00  restore
