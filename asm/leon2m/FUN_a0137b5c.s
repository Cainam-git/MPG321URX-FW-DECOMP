# leon2m FUN_a0137b5c 0xa0137b5c-0xa0137bb0 (84 bytes)
a0137b5c:  9d e3 bf 90  save  %sp, -112, %sp
a0137b60:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0137b64:  c0 27 bf f0  clr  [ %fp + -16 ]
a0137b68:  80 a6 20 00  cmp  %i0, 0
a0137b6c:  02 80 00 06  be  0xa0137b84
a0137b70:  82 10 20 02  mov  2, %g1
a0137b74:  80 a6 20 01  cmp  %i0, 1
a0137b78:  12 80 00 03  bne  0xa0137b84
a0137b7c:  82 10 3f ff  mov  -1, %g1
a0137b80:  82 10 20 03  mov  3, %g1
a0137b84:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a0137b88:  f2 2f bf f1  stb  %i1, [ %fp + -15 ]
a0137b8c:  f4 2f bf f2  stb  %i2, [ %fp + -14 ]
a0137b90:  90 10 20 16  mov  0x16, %o0
a0137b94:  92 10 20 04  mov  4, %o1
a0137b98:  94 07 bf f0  add  %fp, -16, %o2
a0137b9c:  7f ff fd 50  call  0xa01370dc
a0137ba0:  96 10 20 01  mov  1, %o3
a0137ba4:  01 00 00 00  nop
a0137ba8:  81 c7 e0 08  ret
a0137bac:  81 e8 00 00  restore
