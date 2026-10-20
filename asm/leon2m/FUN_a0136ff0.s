# leon2m FUN_a0136ff0 0xa0136ff0-0xa013701c (44 bytes)
a0136ff0:  9d e3 bf 90  save  %sp, -112, %sp
a0136ff4:  c0 27 bf f4  clr  [ %fp + -12 ]
a0136ff8:  90 10 20 01  mov  1, %o0
a0136ffc:  92 10 20 0c  mov  0xc, %o1
a0137000:  94 07 bf f4  add  %fp, -12, %o2
a0137004:  67 fd 55 33  call  0x4008c4d0
a0137008:  96 10 20 01  mov  1, %o3
a013700c:  f0 0f bf f4  ldub  [ %fp + -12 ], %i0
a0137010:  b0 0e 20 01  and  %i0, 1, %i0
a0137014:  81 c7 e0 08  ret
a0137018:  81 e8 00 00  restore
