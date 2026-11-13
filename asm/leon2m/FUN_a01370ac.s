# leon2m FUN_a01370ac 0xa01370ac-0xa01370dc (48 bytes)
a01370ac:  9d e3 bf 90  save  %sp, -112, %sp
a01370b0:  c0 27 bf f4  clr  [ %fp + -12 ]
a01370b4:  90 10 20 01  mov  1, %o0
a01370b8:  92 10 20 0c  mov  0xc, %o1
a01370bc:  94 07 bf f4  add  %fp, -12, %o2
a01370c0:  67 fd 55 04  call  0x4008c4d0
a01370c4:  96 10 20 01  mov  1, %o3
a01370c8:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a01370cc:  b1 30 60 1d  srl  %g1, 0x1d, %i0
a01370d0:  b0 0e 20 01  and  %i0, 1, %i0
a01370d4:  81 c7 e0 08  ret
a01370d8:  81 e8 00 00  restore
