# leon2m FUN_a013cecc 0xa013cecc-0xa013cf84 (92 bytes)
a013cecc:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a013ced0:  c2 08 61 a7  ldub  [ %g1 + 0x1a7 ], %g1	! 0xa802e1a7
a013ced4:  80 a0 60 07  cmp  %g1, 7
a013ced8:  96 10 20 00  clr  %o3
a013cedc:  18 80 00 0d  bgu  0xa013cf10
a013cee0:  9a 0a 20 ff  and  %o0, 0xff, %o5
a013cee4:  19 00 03 72  sethi  %hi(0xdc800), %o4
a013cee8:  83 28 60 02  sll  %g1, 2, %g1
a013ceec:  9a 13 20 9c  or  %o4, 0x9c, %o5
a013cef0:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a013cef4:  81 c3 00 00  jmp  %o4
a013cef8:  01 00 00 00  nop
a013cefc:  9a 0a 20 ff  and  %o0, 0xff, %o5
a013cf00:  80 a3 60 01  cmp  %o5, 1
a013cf04:  18 80 00 04  bgu  0xa013cf14
a013cf08:  80 a3 60 03  cmp  %o5, 3
a013cf0c:  96 10 20 01  mov  1, %o3
a013cf10:  80 a3 60 03  cmp  %o5, 3
a013cf14:  12 80 00 1a  bne  0xa013cf7c
a013cf18:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a013cf1c:  da 00 63 d0  ld  [ %g1 + 0x3d0 ], %o5	! 0xa802e3d0
a013cf20:  11 00 08 00  sethi  %hi(0x200000), %o0
a013cf24:  80 8b 40 08  btst  %o5, %o0
a013cf28:  32 80 00 15  bne,a   0xa013cf7c
a013cf2c:  96 10 20 01  mov  1, %o3
a013cf30:  30 80 00 13  b,a   0xa013cf7c
a013cf34:  9a 0a 20 ff  and  %o0, 0xff, %o5
a013cf38:  80 a3 60 00  cmp  %o5, 0
a013cf3c:  12 bf ff f6  bne  0xa013cf14
a013cf40:  80 a3 60 03  cmp  %o5, 3
a013cf44:  10 80 00 0e  b  0xa013cf7c
a013cf48:  96 10 20 01  mov  1, %o3
a013cf4c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a013cf50:  80 a3 60 02  cmp  %o5, 2
a013cf54:  18 bf ff f0  bgu  0xa013cf14
a013cf58:  80 a3 60 03  cmp  %o5, 3
a013cf5c:  10 bf ff ee  b  0xa013cf14
a013cf60:  96 10 20 01  mov  1, %o3
a013cf64:  9a 0a 20 ff  and  %o0, 0xff, %o5
a013cf68:  80 a3 60 03  cmp  %o5, 3
a013cf6c:  18 80 00 04  bgu  0xa013cf7c
a013cf70:  01 00 00 00  nop
a013cf74:  10 bf ff e8  b  0xa013cf14
a013cf78:  96 10 20 01  mov  1, %o3	! 0x1
a013cf7c:  81 c3 e0 08  retl
a013cf80:  90 0a e0 01  and  %o3, 1, %o0
