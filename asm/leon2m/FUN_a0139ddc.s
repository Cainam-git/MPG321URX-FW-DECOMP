# leon2m FUN_a0139ddc 0xa0139ddc-0xa0139ed0 (244 bytes)
a0139ddc:  9d e3 bf 90  save  %sp, -112, %sp
a0139de0:  9b 2e 20 10  sll  %i0, 0x10, %o5
a0139de4:  25 2a 00 a9  sethi  %hi(0xa802a400), %l2
a0139de8:  9b 33 60 10  srl  %o5, 0x10, %o5
a0139dec:  c2 14 a0 5c  lduh  [ %l2 + 0x5c ], %g1
a0139df0:  80 a0 40 0d  cmp  %g1, %o5
a0139df4:  02 80 00 34  be  0xa0139ec4
a0139df8:  83 2b 60 0c  sll  %o5, 0xc, %g1
a0139dfc:  a0 20 40 0d  sub  %g1, %o5, %l0
a0139e00:  1b 00 10 04  sethi  %hi(0x401000), %o5
a0139e04:  a2 13 60 05  or  %o5, 5, %l1	! 0x401005
a0139e08:  80 54 00 11  umul  %l0, %l1, %g0
a0139e0c:  95 40 00 00  rd  %y, %o2
a0139e10:  9e 24 00 0a  sub  %l0, %o2, %o7
a0139e14:  97 33 e0 01  srl  %o7, 1, %o3
a0139e18:  92 02 80 0b  add  %o2, %o3, %o1
a0139e1c:  98 10 3f ff  mov  -1, %o4
a0139e20:  a3 32 60 09  srl  %o1, 9, %l1
a0139e24:  90 10 20 02  mov  2, %o0
a0139e28:  d8 27 bf f4  st  %o4, [ %fp + -12 ]
a0139e2c:  92 10 20 20  mov  0x20, %o1
a0139e30:  94 07 bf f4  add  %fp, -12, %o2
a0139e34:  67 fd 49 a7  call  0x4008c4d0
a0139e38:  96 10 20 01  mov  1, %o3
a0139e3c:  d0 07 bf f4  ld  [ %fp + -12 ], %o0
a0139e40:  80 a2 20 00  cmp  %o0, 0
a0139e44:  02 80 00 10  be  0xa0139e84
a0139e48:  a0 10 20 64  mov  0x64, %l0
a0139e4c:  67 fd 4c d5  call  0x4008d1a0
a0139e50:  90 10 20 01  mov  1, %o0
a0139e54:  90 10 20 02  mov  2, %o0
a0139e58:  92 10 20 20  mov  0x20, %o1
a0139e5c:  94 07 bf f4  add  %fp, -12, %o2
a0139e60:  67 fd 49 9c  call  0x4008c4d0
a0139e64:  96 10 20 01  mov  1, %o3
a0139e68:  a0 04 3f ff  add  %l0, -1, %l0
a0139e6c:  80 a4 20 00  cmp  %l0, 0
a0139e70:  02 80 00 11  be  0xa0139eb4
a0139e74:  d0 07 bf f4  ld  [ %fp + -12 ], %o0
a0139e78:  80 a2 20 00  cmp  %o0, 0
a0139e7c:  12 bf ff f4  bne  0xa0139e4c
a0139e80:  01 00 00 00  nop
a0139e84:  9f 2c 60 10  sll  %l1, 0x10, %o7
a0139e88:  95 33 e0 10  srl  %o7, 0x10, %o2
a0139e8c:  17 0c 00 00  sethi  %hi(0x30000000), %o3
a0139e90:  98 12 80 0b  or  %o2, %o3, %o4
a0139e94:  d8 27 bf f4  st  %o4, [ %fp + -12 ]
a0139e98:  90 10 20 02  mov  2, %o0
a0139e9c:  92 10 20 20  mov  0x20, %o1
a0139ea0:  94 07 bf f4  add  %fp, -12, %o2
a0139ea4:  67 fd 49 d5  call  0x4008c5f8
a0139ea8:  96 10 20 01  mov  1, %o3
a0139eac:  10 80 00 07  b  0xa0139ec8
a0139eb0:  f0 34 a0 5c  sth  %i0, [ %l2 + 0x5c ]
a0139eb4:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a0139eb8:  80 a2 60 00  cmp  %o1, 0
a0139ebc:  02 bf ff f3  be  0xa0139e88
a0139ec0:  9f 2c 60 10  sll  %l1, 0x10, %o7
a0139ec4:  f0 34 a0 5c  sth  %i0, [ %l2 + 0x5c ]
a0139ec8:  81 c7 e0 08  ret
a0139ecc:  81 e8 00 00  restore
