# leon2s FUN_a0072b7c 0xa0072b7c-0xa0072c6c (240 bytes)
a0072b7c:  9d e3 bf 98  save  %sp, -104, %sp
a0072b80:  21 30 00 00  sethi  %hi(0xc0000000), %l0
a0072b84:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0072b88:  da 04 00 00  ld  [ %l0 ], %o5
a0072b8c:  82 10 60 e8  or  %g1, 0xe8, %g1
a0072b90:  9a 13 60 40  or  %o5, 0x40, %o5
a0072b94:  c0 28 60 80  clrb  [ %g1 + 0x80 ]
a0072b98:  da 24 00 00  st  %o5, [ %l0 ]
a0072b9c:  c0 28 60 81  clrb  [ %g1 + 0x81 ]
a0072ba0:  40 00 fa fd  call  0xa00b1794
a0072ba4:  90 10 20 01  mov  1, %o0
a0072ba8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0072bac:  c2 00 63 dc  ld  [ %g1 + 0x3dc ], %g1	! 0xa80787dc
a0072bb0:  1b 01 6e 36  sethi  %hi(0x5b8d800), %o5
a0072bb4:  82 18 40 0d  xor  %g1, %o5, %g1
a0072bb8:  80 a0 00 01  cmp  %g0, %g1
a0072bbc:  c2 04 00 00  ld  [ %l0 ], %g1
a0072bc0:  82 08 7f bf  and  %g1, -65, %g1
a0072bc4:  c2 24 00 00  st  %g1, [ %l0 ]
a0072bc8:  19 30 03 00  sethi  %hi(0xc00c0000), %o4
a0072bcc:  9a 60 20 00  subx  %g0, 0, %o5
a0072bd0:  96 13 20 0c  or  %o4, 0xc, %o3
a0072bd4:  82 10 20 80  mov  0x80, %g1
a0072bd8:  9a 0b 7f d9  and  %o5, -39, %o5
a0072bdc:  c2 22 c0 00  st  %g1, [ %o3 ]
a0072be0:  9a 03 60 34  add  %o5, 0x34, %o5
a0072be4:  da 23 00 00  st  %o5, [ %o4 ]
a0072be8:  9a 13 20 04  or  %o4, 4, %o5
a0072bec:  c0 23 40 00  clr  [ %o5 ]
a0072bf0:  c0 22 c0 00  clr  [ %o3 ]
a0072bf4:  82 10 20 03  mov  3, %g1
a0072bf8:  c2 22 c0 00  st  %g1, [ %o3 ]
a0072bfc:  98 13 20 08  or  %o4, 8, %o4
a0072c00:  82 10 20 06  mov  6, %g1
a0072c04:  c2 23 00 00  st  %g1, [ %o4 ]
a0072c08:  c0 23 00 00  clr  [ %o4 ]
a0072c0c:  82 10 20 01  mov  1, %g1
a0072c10:  c2 23 40 00  st  %g1, [ %o5 ]
a0072c14:  1b 27 c4 00  sethi  %hi(0x9f100000), %o5
a0072c18:  9a 13 60 90  or  %o5, 0x90, %o5	! 0x9f100090
a0072c1c:  c2 03 40 00  ld  [ %o5 ], %g1
a0072c20:  82 10 60 10  or  %g1, 0x10, %g1
a0072c24:  c2 23 40 00  st  %g1, [ %o5 ]
a0072c28:  19 27 c4 80  sethi  %hi(0x9f120000), %o4
a0072c2c:  9a 13 20 28  or  %o4, 0x28, %o5	! 0x9f120028
a0072c30:  c2 03 40 00  ld  [ %o5 ], %g1
a0072c34:  82 08 7f ef  and  %g1, -17, %g1
a0072c38:  c2 23 40 00  st  %g1, [ %o5 ]
a0072c3c:  9a 13 20 44  or  %o4, 0x44, %o5
a0072c40:  c2 03 40 00  ld  [ %o5 ], %g1
a0072c44:  82 08 7f bf  and  %g1, -65, %g1
a0072c48:  c2 23 40 00  st  %g1, [ %o5 ]
a0072c4c:  9a 13 20 7c  or  %o4, 0x7c, %o5
a0072c50:  82 10 20 40  mov  0x40, %g1
a0072c54:  c2 23 40 00  st  %g1, [ %o5 ]
a0072c58:  98 13 20 34  or  %o4, 0x34, %o4
a0072c5c:  82 10 20 10  mov  0x10, %g1
a0072c60:  c2 23 00 00  st  %g1, [ %o4 ]
a0072c64:  81 c7 e0 08  ret
a0072c68:  81 e8 00 00  restore
