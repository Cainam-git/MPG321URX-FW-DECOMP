# leon2m FUN_a0139c3c 0xa0139c3c-0xa0139d38 (252 bytes)
a0139c3c:  9d e3 bf 90  save  %sp, -112, %sp
a0139c40:  82 10 20 20  mov  0x20, %g1
a0139c44:  94 10 20 40  mov  0x40, %o2
a0139c48:  96 10 20 00  clr  %o3
a0139c4c:  83 28 60 10  sll  %g1, 0x10, %g1
a0139c50:  83 30 60 11  srl  %g1, 0x11, %g1
a0139c54:  9b 30 60 01  srl  %g1, 1, %o5
a0139c58:  80 a3 60 00  cmp  %o5, 0
a0139c5c:  12 bf ff fc  bne  0xa0139c4c
a0139c60:  96 02 e0 01  inc  %o3
a0139c64:  93 2a a0 10  sll  %o2, 0x10, %o1
a0139c68:  91 32 60 11  srl  %o1, 0x11, %o0
a0139c6c:  98 03 60 01  add  %o5, 1, %o4
a0139c70:  9b 32 20 01  srl  %o0, 1, %o5
a0139c74:  80 a3 60 00  cmp  %o5, 0
a0139c78:  94 10 00 08  mov  %o0, %o2
a0139c7c:  12 bf ff fa  bne  0xa0139c64
a0139c80:  9a 10 00 0c  mov  %o4, %o5
a0139c84:  9f 2b 20 10  sll  %o4, 0x10, %o7
a0139c88:  99 33 e0 08  srl  %o7, 8, %o4
a0139c8c:  a2 13 00 0b  or  %o4, %o3, %l1
a0139c90:  96 10 3f ff  mov  -1, %o3
a0139c94:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a0139c98:  94 07 bf f4  add  %fp, -12, %o2
a0139c9c:  90 10 20 02  mov  2, %o0
a0139ca0:  92 10 20 20  mov  0x20, %o1
a0139ca4:  67 fd 4a 0b  call  0x4008c4d0
a0139ca8:  96 10 20 01  mov  1, %o3
a0139cac:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a0139cb0:  80 a2 a0 00  cmp  %o2, 0
a0139cb4:  02 80 00 10  be  0xa0139cf4
a0139cb8:  a0 10 20 64  mov  0x64, %l0
a0139cbc:  67 fd 4d 39  call  0x4008d1a0
a0139cc0:  90 10 20 01  mov  1, %o0
a0139cc4:  90 10 20 02  mov  2, %o0
a0139cc8:  92 10 20 20  mov  0x20, %o1
a0139ccc:  94 07 bf f4  add  %fp, -12, %o2
a0139cd0:  67 fd 4a 00  call  0x4008c4d0
a0139cd4:  96 10 20 01  mov  1, %o3
a0139cd8:  a0 04 3f ff  add  %l0, -1, %l0
a0139cdc:  80 a4 20 00  cmp  %l0, 0
a0139ce0:  02 80 00 10  be  0xa0139d20
a0139ce4:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a0139ce8:  80 a0 60 00  cmp  %g1, 0
a0139cec:  12 bf ff f4  bne  0xa0139cbc
a0139cf0:  01 00 00 00  nop
a0139cf4:  93 2c 60 10  sll  %l1, 0x10, %o1
a0139cf8:  91 32 60 10  srl  %o1, 0x10, %o0
a0139cfc:  1b 0a c0 00  sethi  %hi(0x2b000000), %o5
a0139d00:  a2 12 00 0d  or  %o0, %o5, %l1
a0139d04:  e2 27 bf f4  st  %l1, [ %fp + -12 ]
a0139d08:  90 10 20 02  mov  2, %o0
a0139d0c:  92 10 20 20  mov  0x20, %o1
a0139d10:  94 07 bf f4  add  %fp, -12, %o2
a0139d14:  67 fd 4a 39  call  0x4008c5f8
a0139d18:  96 10 20 01  mov  1, %o3
a0139d1c:  30 80 00 05  b,a   0xa0139d30
a0139d20:  e0 07 bf f4  ld  [ %fp + -12 ], %l0
a0139d24:  80 a4 20 00  cmp  %l0, 0
a0139d28:  02 bf ff f4  be  0xa0139cf8
a0139d2c:  93 2c 60 10  sll  %l1, 0x10, %o1
a0139d30:  81 c7 e0 08  ret
a0139d34:  81 e8 00 00  restore
