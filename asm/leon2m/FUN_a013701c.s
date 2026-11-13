# leon2m FUN_a013701c 0xa013701c-0xa013704c (48 bytes)
a013701c:  9d e3 bf 90  save  %sp, -112, %sp
a0137020:  c0 27 bf f4  clr  [ %fp + -12 ]
a0137024:  90 10 20 01  mov  1, %o0
a0137028:  92 10 20 0c  mov  0xc, %o1
a013702c:  94 07 bf f4  add  %fp, -12, %o2
a0137030:  67 fd 55 28  call  0x4008c4d0
a0137034:  96 10 20 01  mov  1, %o3
a0137038:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013703c:  b1 30 60 1a  srl  %g1, 0x1a, %i0
a0137040:  b0 0e 20 01  and  %i0, 1, %i0
a0137044:  81 c7 e0 08  ret
a0137048:  81 e8 00 00  restore
