# leon2m FUN_a0139d38 0xa0139d38-0xa0139ddc (164 bytes)
a0139d38:  9d e3 bf 90  save  %sp, -112, %sp
a0139d3c:  90 10 3f ff  mov  -1, %o0
a0139d40:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a0139d44:  90 10 20 02  mov  2, %o0
a0139d48:  92 10 20 20  mov  0x20, %o1
a0139d4c:  94 07 bf f4  add  %fp, -12, %o2
a0139d50:  67 fd 49 e0  call  0x4008c4d0
a0139d54:  96 10 20 01  mov  1, %o3
a0139d58:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a0139d5c:  80 a0 60 00  cmp  %g1, 0
a0139d60:  02 80 00 10  be  0xa0139da0
a0139d64:  a0 10 20 64  mov  0x64, %l0
a0139d68:  67 fd 4d 0e  call  0x4008d1a0
a0139d6c:  90 10 20 01  mov  1, %o0
a0139d70:  90 10 20 02  mov  2, %o0
a0139d74:  92 10 20 20  mov  0x20, %o1
a0139d78:  94 07 bf f4  add  %fp, -12, %o2
a0139d7c:  67 fd 49 d5  call  0x4008c4d0
a0139d80:  96 10 20 01  mov  1, %o3
a0139d84:  a0 04 3f ff  add  %l0, -1, %l0
a0139d88:  80 a4 20 00  cmp  %l0, 0
a0139d8c:  02 80 00 0e  be  0xa0139dc4
a0139d90:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a0139d94:  80 a2 60 00  cmp  %o1, 0
a0139d98:  12 bf ff f4  bne  0xa0139d68
a0139d9c:  01 00 00 00  nop
a0139da0:  19 08 80 00  sethi  %hi(0x22000000), %o4
a0139da4:  96 13 20 01  or  %o4, 1, %o3	! 0x22000001
a0139da8:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a0139dac:  90 10 20 02  mov  2, %o0
a0139db0:  92 10 20 20  mov  0x20, %o1
a0139db4:  94 07 bf f4  add  %fp, -12, %o2
a0139db8:  67 fd 4a 10  call  0x4008c5f8
a0139dbc:  96 10 20 01  mov  1, %o3
a0139dc0:  30 80 00 05  b,a   0xa0139dd4
a0139dc4:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a0139dc8:  80 a2 a0 00  cmp  %o2, 0
a0139dcc:  02 bf ff f6  be  0xa0139da4
a0139dd0:  19 08 80 00  sethi  %hi(0x22000000), %o4
a0139dd4:  81 c7 e0 08  ret
a0139dd8:  81 e8 00 00  restore
