# leon2m FUN_a0139f7c 0xa0139f7c-0xa013a028 (172 bytes)
a0139f7c:  9d e3 bf 90  save  %sp, -112, %sp
a0139f80:  90 10 3f ff  mov  -1, %o0
a0139f84:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a0139f88:  90 10 20 02  mov  2, %o0
a0139f8c:  92 10 20 20  mov  0x20, %o1
a0139f90:  94 07 bf f4  add  %fp, -12, %o2
a0139f94:  67 fd 49 4f  call  0x4008c4d0
a0139f98:  96 10 20 01  mov  1, %o3
a0139f9c:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a0139fa0:  80 a0 60 00  cmp  %g1, 0
a0139fa4:  02 80 00 10  be  0xa0139fe4
a0139fa8:  a0 10 20 64  mov  0x64, %l0
a0139fac:  67 fd 4c 7d  call  0x4008d1a0
a0139fb0:  90 10 20 01  mov  1, %o0
a0139fb4:  90 10 20 02  mov  2, %o0
a0139fb8:  92 10 20 20  mov  0x20, %o1
a0139fbc:  94 07 bf f4  add  %fp, -12, %o2
a0139fc0:  67 fd 49 44  call  0x4008c4d0
a0139fc4:  96 10 20 01  mov  1, %o3
a0139fc8:  a0 04 3f ff  add  %l0, -1, %l0
a0139fcc:  80 a4 20 00  cmp  %l0, 0
a0139fd0:  02 80 00 10  be  0xa013a010
a0139fd4:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a0139fd8:  80 a2 60 00  cmp  %o1, 0
a0139fdc:  12 bf ff f4  bne  0xa0139fac
a0139fe0:  01 00 00 00  nop
a0139fe4:  9f 2e 20 10  sll  %i0, 0x10, %o7
a0139fe8:  99 33 e0 10  srl  %o7, 0x10, %o4
a0139fec:  1b 0c c0 00  sethi  %hi(0x33000000), %o5
a0139ff0:  96 13 00 0d  or  %o4, %o5, %o3
a0139ff4:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a0139ff8:  90 10 20 02  mov  2, %o0
a0139ffc:  92 10 20 20  mov  0x20, %o1
a013a000:  94 07 bf f4  add  %fp, -12, %o2
a013a004:  67 fd 49 7d  call  0x4008c5f8
a013a008:  96 10 20 01  mov  1, %o3
a013a00c:  30 80 00 05  b,a   0xa013a020
a013a010:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a013a014:  80 a2 a0 00  cmp  %o2, 0
a013a018:  02 bf ff f4  be  0xa0139fe8
a013a01c:  9f 2e 20 10  sll  %i0, 0x10, %o7
a013a020:  81 c7 e0 08  ret
a013a024:  81 e8 00 00  restore
