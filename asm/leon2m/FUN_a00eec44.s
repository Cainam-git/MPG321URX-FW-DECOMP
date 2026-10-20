# leon2m FUN_a00eec44 0xa00eec44-0xa00eecc8 (132 bytes)
a00eec44:  9d e3 bf 90  save  %sp, -112, %sp
a00eec48:  e0 07 a0 64  ld  [ %fp + 0x64 ], %l0
a00eec4c:  90 10 00 18  mov  %i0, %o0
a00eec50:  fa 23 a0 60  st  %i5, [ %sp + 0x60 ]
a00eec54:  f8 23 a0 5c  st  %i4, [ %sp + 0x5c ]
a00eec58:  92 10 00 19  mov  %i1, %o1
a00eec5c:  94 10 00 1a  mov  %i2, %o2
a00eec60:  96 10 00 1b  mov  %i3, %o3
a00eec64:  98 10 00 10  mov  %l0, %o4
a00eec68:  9a 10 20 04  mov  4, %o5
a00eec6c:  7f ff fd 5f  call  0xa00ee1e8
a00eec70:  a2 10 00 18  mov  %i0, %l1
a00eec74:  80 a2 20 00  cmp  %o0, 0
a00eec78:  06 80 00 12  bl  0xa00eecc0
a00eec7c:  b0 10 3f ff  mov  -1, %i0
a00eec80:  90 10 00 11  mov  %l1, %o0
a00eec84:  92 10 00 19  mov  %i1, %o1
a00eec88:  94 10 00 1a  mov  %i2, %o2
a00eec8c:  96 10 00 10  mov  %l0, %o3
a00eec90:  98 10 00 1c  mov  %i4, %o4
a00eec94:  80 a6 e0 03  cmp  %i3, 3
a00eec98:  02 80 00 04  be  0xa00eeca8
a00eec9c:  da 07 a0 5c  ld  [ %fp + 0x5c ], %o5
a00eeca0:  10 80 00 08  b  0xa00eecc0
a00eeca4:  b0 10 20 00  clr  %i0
a00eeca8:  c2 07 a0 60  ld  [ %fp + 0x60 ], %g1
a00eecac:  7f ff ff 2e  call  0xa00ee964
a00eecb0:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a00eecb4:  80 a2 20 00  cmp  %o0, 0
a00eecb8:  22 80 00 02  be,a   0xa00eecc0
a00eecbc:  b0 10 20 00  clr  %i0
a00eecc0:  81 c7 e0 08  ret
a00eecc4:  81 e8 00 00  restore
