# leon2m FUN_a0139b90 0xa0139b90-0xa0139c3c (172 bytes)
a0139b90:  9d e3 bf 90  save  %sp, -112, %sp
a0139b94:  90 10 3f ff  mov  -1, %o0
a0139b98:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a0139b9c:  90 10 20 02  mov  2, %o0
a0139ba0:  92 10 20 20  mov  0x20, %o1
a0139ba4:  94 07 bf f4  add  %fp, -12, %o2
a0139ba8:  67 fd 4a 4a  call  0x4008c4d0
a0139bac:  96 10 20 01  mov  1, %o3
a0139bb0:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a0139bb4:  80 a0 60 00  cmp  %g1, 0
a0139bb8:  02 80 00 10  be  0xa0139bf8
a0139bbc:  a0 10 20 64  mov  0x64, %l0
a0139bc0:  67 fd 4d 78  call  0x4008d1a0
a0139bc4:  90 10 20 01  mov  1, %o0
a0139bc8:  90 10 20 02  mov  2, %o0
a0139bcc:  92 10 20 20  mov  0x20, %o1
a0139bd0:  94 07 bf f4  add  %fp, -12, %o2
a0139bd4:  67 fd 4a 3f  call  0x4008c4d0
a0139bd8:  96 10 20 01  mov  1, %o3
a0139bdc:  a0 04 3f ff  add  %l0, -1, %l0
a0139be0:  80 a4 20 00  cmp  %l0, 0
a0139be4:  02 80 00 10  be  0xa0139c24
a0139be8:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a0139bec:  80 a2 60 00  cmp  %o1, 0
a0139bf0:  12 bf ff f4  bne  0xa0139bc0
a0139bf4:  01 00 00 00  nop
a0139bf8:  1f 04 08 00  sethi  %hi(0x10200000), %o7
a0139bfc:  17 0a 80 00  sethi  %hi(0x2a000000), %o3
a0139c00:  99 33 e0 10  srl  %o7, 0x10, %o4
a0139c04:  9a 12 c0 0c  or  %o3, %o4, %o5
a0139c08:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a0139c0c:  90 10 20 02  mov  2, %o0
a0139c10:  92 10 20 20  mov  0x20, %o1
a0139c14:  94 07 bf f4  add  %fp, -12, %o2
a0139c18:  67 fd 4a 78  call  0x4008c5f8
a0139c1c:  96 10 20 01  mov  1, %o3
a0139c20:  30 80 00 05  b,a   0xa0139c34
a0139c24:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a0139c28:  80 a2 a0 00  cmp  %o2, 0
a0139c2c:  02 bf ff f4  be  0xa0139bfc
a0139c30:  1f 04 08 00  sethi  %hi(0x10200000), %o7
a0139c34:  81 c7 e0 08  ret
a0139c38:  81 e8 00 00  restore
