# leon2m FUN_a0137b1c 0xa0137b1c-0xa0137b5c (64 bytes)
a0137b1c:  9d e3 bf 90  save  %sp, -112, %sp
a0137b20:  c0 27 bf f0  clr  [ %fp + -16 ]
a0137b24:  82 0e 20 ff  and  %i0, 0xff, %g1
a0137b28:  90 10 20 15  mov  0x15, %o0
a0137b2c:  92 10 20 04  mov  4, %o1
a0137b30:  94 07 bf f0  add  %fp, -16, %o2
a0137b34:  96 10 20 01  mov  1, %o3
a0137b38:  f0 2f bf f0  stb  %i0, [ %fp + -16 ]
a0137b3c:  80 a0 60 ff  cmp  %g1, 0xff
a0137b40:  02 80 00 04  be  0xa0137b50
a0137b44:  f2 2f bf f1  stb  %i1, [ %fp + -15 ]
a0137b48:  7f ff fd 65  call  0xa01370dc
a0137b4c:  01 00 00 00  nop
a0137b50:  01 00 00 00  nop
a0137b54:  81 c7 e0 08  ret
a0137b58:  81 e8 00 00  restore
