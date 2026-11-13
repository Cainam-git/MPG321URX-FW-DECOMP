# leon2m FUN_a0139a30 0xa0139a30-0xa0139b90 (352 bytes)
a0139a30:  9d e3 bf 90  save  %sp, -112, %sp
a0139a34:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0139a38:  92 13 23 78  or  %o4, 0x378, %o1	! 0xa802e378
a0139a3c:  d6 12 60 08  lduh  [ %o1 + 8 ], %o3
a0139a40:  d4 12 60 0a  lduh  [ %o1 + 0xa ], %o2
a0139a44:  91 2a e0 10  sll  %o3, 0x10, %o0
a0139a48:  82 02 00 0a  add  %o0, %o2, %g1
a0139a4c:  c2 27 bf f4  st  %g1, [ %fp + -12 ]
a0139a50:  90 10 20 02  mov  2, %o0
a0139a54:  92 10 20 a0  mov  0xa0, %o1
a0139a58:  94 07 bf f4  add  %fp, -12, %o2
a0139a5c:  67 fd 4a e7  call  0x4008c5f8
a0139a60:  96 10 20 01  mov  1, %o3
a0139a64:  a0 10 2f ff  mov  0xfff, %l0
a0139a68:  e0 27 bf f4  st  %l0, [ %fp + -12 ]
a0139a6c:  90 10 20 02  mov  2, %o0
a0139a70:  92 10 20 a4  mov  0xa4, %o1
a0139a74:  94 07 bf f4  add  %fp, -12, %o2
a0139a78:  67 fd 4a e0  call  0x4008c5f8
a0139a7c:  96 10 20 01  mov  1, %o3
a0139a80:  1f 00 00 04  sethi  %hi(0x1000), %o7
a0139a84:  9a 03 e0 01  add  %o7, 1, %o5	! 0x1001
a0139a88:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a0139a8c:  90 10 20 02  mov  2, %o0
a0139a90:  92 10 20 a8  mov  0xa8, %o1
a0139a94:  94 07 bf f4  add  %fp, -12, %o2
a0139a98:  67 fd 4a d8  call  0x4008c5f8
a0139a9c:  96 10 20 01  mov  1, %o3
a0139aa0:  19 00 3f c0  sethi  %hi(0xff0000), %o4
a0139aa4:  96 03 21 01  add  %o4, 0x101, %o3	! 0xff0101
a0139aa8:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a0139aac:  90 10 20 02  mov  2, %o0
a0139ab0:  92 10 20 ac  mov  0xac, %o1
a0139ab4:  94 07 bf f4  add  %fp, -12, %o2
a0139ab8:  67 fd 4a d0  call  0x4008c5f8
a0139abc:  96 10 20 01  mov  1, %o3
a0139ac0:  13 00 06 94  sethi  %hi(0x1a5000), %o1
a0139ac4:  94 12 63 40  or  %o1, 0x340, %o2	! 0x1a5340
a0139ac8:  90 10 20 02  mov  2, %o0
a0139acc:  92 10 20 c0  mov  0xc0, %o1
a0139ad0:  67 fd 4a ca  call  0x4008c5f8
a0139ad4:  96 10 20 08  mov  8, %o3
a0139ad8:  15 00 06 94  sethi  %hi(0x1a5000), %o2
a0139adc:  94 12 a3 20  or  %o2, 0x320, %o2	! 0x1a5320
a0139ae0:  90 10 20 02  mov  2, %o0
a0139ae4:  92 10 20 e0  mov  0xe0, %o1
a0139ae8:  67 fd 4a c4  call  0x4008c5f8
a0139aec:  96 10 20 08  mov  8, %o3
a0139af0:  90 10 3f ff  mov  -1, %o0
a0139af4:  d0 27 bf f0  st  %o0, [ %fp + -16 ]
a0139af8:  90 10 20 02  mov  2, %o0
a0139afc:  92 10 20 20  mov  0x20, %o1
a0139b00:  94 07 bf f0  add  %fp, -16, %o2
a0139b04:  67 fd 4a 73  call  0x4008c4d0
a0139b08:  96 10 20 01  mov  1, %o3
a0139b0c:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a0139b10:  80 a0 60 00  cmp  %g1, 0
a0139b14:  02 80 00 10  be  0xa0139b54
a0139b18:  a0 10 20 64  mov  0x64, %l0
a0139b1c:  67 fd 4d a1  call  0x4008d1a0
a0139b20:  90 10 20 01  mov  1, %o0
a0139b24:  90 10 20 02  mov  2, %o0
a0139b28:  92 10 20 20  mov  0x20, %o1
a0139b2c:  94 07 bf f0  add  %fp, -16, %o2
a0139b30:  67 fd 4a 68  call  0x4008c4d0
a0139b34:  96 10 20 01  mov  1, %o3
a0139b38:  a0 04 3f ff  add  %l0, -1, %l0
a0139b3c:  80 a4 20 00  cmp  %l0, 0
a0139b40:  02 80 00 0e  be  0xa0139b78
a0139b44:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a0139b48:  80 a3 60 00  cmp  %o5, 0
a0139b4c:  12 bf ff f4  bne  0xa0139b1c
a0139b50:  01 00 00 00  nop
a0139b54:  03 08 40 00  sethi  %hi(0x21000000), %g1
a0139b58:  a0 10 60 01  or  %g1, 1, %l0	! 0x21000001
a0139b5c:  e0 27 bf f0  st  %l0, [ %fp + -16 ]
a0139b60:  90 10 20 02  mov  2, %o0
a0139b64:  92 10 20 20  mov  0x20, %o1
a0139b68:  94 07 bf f0  add  %fp, -16, %o2
a0139b6c:  67 fd 4a a3  call  0x4008c5f8
a0139b70:  96 10 20 01  mov  1, %o3
a0139b74:  30 80 00 05  b,a   0xa0139b88
a0139b78:  de 07 bf f0  ld  [ %fp + -16 ], %o7
a0139b7c:  80 a3 e0 00  cmp  %o7, 0
a0139b80:  02 bf ff f6  be  0xa0139b58
a0139b84:  03 08 40 00  sethi  %hi(0x21000000), %g1
a0139b88:  81 c7 e0 08  ret
a0139b8c:  81 e8 00 00  restore
