# leon2m FUN_a012c090 0xa012c090-0xa012c0f8 (104 bytes)
a012c090:  9d e3 bf 88  save  %sp, -120, %sp
a012c094:  15 2a 00 b6  sethi  %hi(0xa802d800), %o2
a012c098:  9e 12 a0 dc  or  %o2, 0xdc, %o7	! 0xa802d8dc
a012c09c:  96 03 e0 24  add  %o7, 0x24, %o3
a012c0a0:  1b 00 00 08  sethi  %hi(0x2000), %o5
a012c0a4:  d0 12 e0 1c  lduh  [ %o3 + 0x1c ], %o0
a012c0a8:  98 13 60 01  or  %o5, 1, %o4
a012c0ac:  94 12 00 0c  or  %o0, %o4, %o2
a012c0b0:  98 10 20 00  clr  %o4
a012c0b4:  9a 10 20 00  clr  %o5
a012c0b8:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a012c0bc:  d4 32 e0 1c  sth  %o2, [ %o3 + 0x1c ]
a012c0c0:  93 32 a0 08  srl  %o2, 8, %o1
a012c0c4:  82 10 20 01  mov  1, %g1
a012c0c8:  d2 2f bf ea  stb  %o1, [ %fp + -22 ]
a012c0cc:  d4 2f bf e9  stb  %o2, [ %fp + -23 ]
a012c0d0:  c2 2f bf e8  stb  %g1, [ %fp + -24 ]
a012c0d4:  c0 27 bf f0  clr  [ %fp + -16 ]
a012c0d8:  90 10 20 56  mov  0x56, %o0
a012c0dc:  92 10 20 0c  mov  0xc, %o1
a012c0e0:  94 07 bf e8  add  %fp, -24, %o2
a012c0e4:  40 00 2b fe  call  0xa01370dc
a012c0e8:  96 10 20 00  clr  %o3
a012c0ec:  01 00 00 00  nop
a012c0f0:  81 c7 e0 08  ret
a012c0f4:  81 e8 00 00  restore
