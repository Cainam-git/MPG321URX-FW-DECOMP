# leon2m FUN_a013707c 0xa013707c-0xa01370ac (48 bytes)
a013707c:  9d e3 bf 90  save  %sp, -112, %sp
a0137080:  c0 27 bf f4  clr  [ %fp + -12 ]
a0137084:  90 10 20 01  mov  1, %o0
a0137088:  92 10 20 0c  mov  0xc, %o1
a013708c:  94 07 bf f4  add  %fp, -12, %o2
a0137090:  67 fd 55 10  call  0x4008c4d0
a0137094:  96 10 20 01  mov  1, %o3
a0137098:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013709c:  b1 30 60 1c  srl  %g1, 0x1c, %i0
a01370a0:  b0 0e 20 01  and  %i0, 1, %i0
a01370a4:  81 c7 e0 08  ret
a01370a8:  81 e8 00 00  restore
