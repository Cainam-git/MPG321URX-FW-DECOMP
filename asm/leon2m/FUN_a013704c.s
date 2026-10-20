# leon2m FUN_a013704c 0xa013704c-0xa013707c (48 bytes)
a013704c:  9d e3 bf 90  save  %sp, -112, %sp
a0137050:  c0 27 bf f4  clr  [ %fp + -12 ]
a0137054:  90 10 20 01  mov  1, %o0
a0137058:  92 10 20 0c  mov  0xc, %o1
a013705c:  94 07 bf f4  add  %fp, -12, %o2
a0137060:  67 fd 55 1c  call  0x4008c4d0
a0137064:  96 10 20 01  mov  1, %o3
a0137068:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013706c:  b1 30 60 1b  srl  %g1, 0x1b, %i0
a0137070:  b0 0e 20 01  and  %i0, 1, %i0
a0137074:  81 c7 e0 08  ret
a0137078:  81 e8 00 00  restore
