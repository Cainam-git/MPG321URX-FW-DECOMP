# leon2m FUN_a0139ed0 0xa0139ed0-0xa0139f7c (172 bytes)
a0139ed0:  9d e3 bf 90  save  %sp, -112, %sp
a0139ed4:  90 10 3f ff  mov  -1, %o0
a0139ed8:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a0139edc:  90 10 20 02  mov  2, %o0
a0139ee0:  92 10 20 20  mov  0x20, %o1
a0139ee4:  94 07 bf f4  add  %fp, -12, %o2
a0139ee8:  67 fd 49 7a  call  0x4008c4d0
a0139eec:  96 10 20 01  mov  1, %o3
a0139ef0:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a0139ef4:  80 a0 60 00  cmp  %g1, 0
a0139ef8:  02 80 00 10  be  0xa0139f38
a0139efc:  a0 10 20 64  mov  0x64, %l0
a0139f00:  67 fd 4c a8  call  0x4008d1a0
a0139f04:  90 10 20 01  mov  1, %o0
a0139f08:  90 10 20 02  mov  2, %o0
a0139f0c:  92 10 20 20  mov  0x20, %o1
a0139f10:  94 07 bf f4  add  %fp, -12, %o2
a0139f14:  67 fd 49 6f  call  0x4008c4d0
a0139f18:  96 10 20 01  mov  1, %o3
a0139f1c:  a0 04 3f ff  add  %l0, -1, %l0
a0139f20:  80 a4 20 00  cmp  %l0, 0
a0139f24:  02 80 00 10  be  0xa0139f64
a0139f28:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a0139f2c:  80 a2 60 00  cmp  %o1, 0
a0139f30:  12 bf ff f4  bne  0xa0139f00
a0139f34:  01 00 00 00  nop
a0139f38:  9f 2e 20 10  sll  %i0, 0x10, %o7
a0139f3c:  99 33 e0 10  srl  %o7, 0x10, %o4
a0139f40:  1b 0c 40 00  sethi  %hi(0x31000000), %o5
a0139f44:  96 13 00 0d  or  %o4, %o5, %o3
a0139f48:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a0139f4c:  90 10 20 02  mov  2, %o0
a0139f50:  92 10 20 20  mov  0x20, %o1
a0139f54:  94 07 bf f4  add  %fp, -12, %o2
a0139f58:  67 fd 49 a8  call  0x4008c5f8
a0139f5c:  96 10 20 01  mov  1, %o3
a0139f60:  30 80 00 05  b,a   0xa0139f74
a0139f64:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a0139f68:  80 a2 a0 00  cmp  %o2, 0
a0139f6c:  02 bf ff f4  be  0xa0139f3c
a0139f70:  9f 2e 20 10  sll  %i0, 0x10, %o7
a0139f74:  81 c7 e0 08  ret
a0139f78:  81 e8 00 00  restore
