# leon2m FUN_a013aae4 0xa013aae4-0xa013ab9c (184 bytes)
a013aae4:  9d e3 bf 90  save  %sp, -112, %sp
a013aae8:  90 10 3f ff  mov  -1, %o0
a013aaec:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a013aaf0:  90 10 20 02  mov  2, %o0
a013aaf4:  92 10 20 20  mov  0x20, %o1
a013aaf8:  94 07 bf f4  add  %fp, -12, %o2
a013aafc:  67 fd 46 75  call  0x4008c4d0
a013ab00:  96 10 20 01  mov  1, %o3
a013ab04:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013ab08:  80 a0 60 00  cmp  %g1, 0
a013ab0c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a013ab10:  02 80 00 10  be  0xa013ab50
a013ab14:  a0 10 20 64  mov  0x64, %l0
a013ab18:  67 fd 49 a2  call  0x4008d1a0
a013ab1c:  90 10 20 01  mov  1, %o0
a013ab20:  90 10 20 02  mov  2, %o0
a013ab24:  92 10 20 20  mov  0x20, %o1
a013ab28:  94 07 bf f4  add  %fp, -12, %o2
a013ab2c:  67 fd 46 69  call  0x4008c4d0
a013ab30:  96 10 20 01  mov  1, %o3
a013ab34:  a0 04 3f ff  add  %l0, -1, %l0
a013ab38:  80 a4 20 00  cmp  %l0, 0
a013ab3c:  02 80 00 12  be  0xa013ab84
a013ab40:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a013ab44:  80 a2 60 00  cmp  %o1, 0
a013ab48:  12 bf ff f4  bne  0xa013ab18
a013ab4c:  01 00 00 00  nop
a013ab50:  82 0e 20 ff  and  %i0, 0xff, %g1
a013ab54:  a1 28 60 10  sll  %g1, 0x10, %l0
a013ab58:  1b 18 40 00  sethi  %hi(0x61000000), %o5
a013ab5c:  9e 14 00 0d  or  %l0, %o5, %o7
a013ab60:  98 0e 60 ff  and  %i1, 0xff, %o4
a013ab64:  96 13 c0 0c  or  %o7, %o4, %o3
a013ab68:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a013ab6c:  90 10 20 02  mov  2, %o0
a013ab70:  92 10 20 20  mov  0x20, %o1
a013ab74:  94 07 bf f4  add  %fp, -12, %o2
a013ab78:  67 fd 46 a0  call  0x4008c5f8
a013ab7c:  96 10 20 01  mov  1, %o3
a013ab80:  30 80 00 05  b,a   0xa013ab94
a013ab84:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a013ab88:  80 a2 a0 00  cmp  %o2, 0
a013ab8c:  02 bf ff f2  be  0xa013ab54
a013ab90:  82 0e 20 ff  and  %i0, 0xff, %g1
a013ab94:  81 c7 e0 08  ret
a013ab98:  81 e8 00 00  restore
