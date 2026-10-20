# leon2m FUN_a0137c4c 0xa0137c4c-0xa0137cac (96 bytes)
a0137c4c:  9d e3 bf 90  save  %sp, -112, %sp
a0137c50:  80 a6 20 02  cmp  %i0, 2
a0137c54:  02 80 00 12  be  0xa0137c9c
a0137c58:  c0 27 bf f0  clr  [ %fp + -16 ]
a0137c5c:  80 a6 20 03  cmp  %i0, 3
a0137c60:  02 80 00 0d  be  0xa0137c94
a0137c64:  82 10 3f ff  mov  -1, %g1
a0137c68:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a0137c6c:  c2 0f bf f0  ldub  [ %fp + -16 ], %g1
a0137c70:  90 10 20 2b  mov  0x2b, %o0
a0137c74:  92 10 20 01  mov  1, %o1
a0137c78:  94 07 bf f0  add  %fp, -16, %o2
a0137c7c:  80 a0 60 ff  cmp  %g1, 0xff
a0137c80:  02 80 00 09  be  0xa0137ca4
a0137c84:  96 10 20 01  mov  1, %o3
a0137c88:  7f ff fd 15  call  0xa01370dc
a0137c8c:  01 00 00 00  nop
a0137c90:  30 80 00 05  b,a   0xa0137ca4
a0137c94:  10 bf ff f5  b  0xa0137c68
a0137c98:  82 10 20 01  mov  1, %g1
a0137c9c:  10 bf ff f4  b  0xa0137c6c
a0137ca0:  c0 2f bf f0  clrb  [ %fp + -16 ]
a0137ca4:  81 c7 e0 08  ret
a0137ca8:  81 e8 00 00  restore
