# leon2m FUN_a0138ae8 0xa0138ae8-0xa0138b98 (176 bytes)
a0138ae8:  9d e3 bf 90  save  %sp, -112, %sp
a0138aec:  1b 2a 00 a9  sethi  %hi(0xa802a400), %o5
a0138af0:  90 13 60 50  or  %o5, 0x50, %o0	! 0xa802a450
a0138af4:  d4 0a 20 01  ldub  [ %o0 + 1 ], %o2
a0138af8:  d8 0a 20 02  ldub  [ %o0 + 2 ], %o4
a0138afc:  d2 0b 60 50  ldub  [ %o5 + 0x50 ], %o1
a0138b00:  83 2a a0 04  sll  %o2, 4, %g1
a0138b04:  da 0a 20 03  ldub  [ %o0 + 3 ], %o5
a0138b08:  96 12 40 01  or  %o1, %g1, %o3
a0138b0c:  9f 2b 20 08  sll  %o4, 8, %o7
a0138b10:  d2 0a 20 04  ldub  [ %o0 + 4 ], %o1
a0138b14:  82 12 c0 0f  or  %o3, %o7, %g1
a0138b18:  95 2b 60 0c  sll  %o5, 0xc, %o2
a0138b1c:  d6 0a 20 05  ldub  [ %o0 + 5 ], %o3
a0138b20:  9e 10 40 0a  or  %g1, %o2, %o7
a0138b24:  99 2a 60 10  sll  %o1, 0x10, %o4
a0138b28:  d2 0a 20 06  ldub  [ %o0 + 6 ], %o1
a0138b2c:  94 13 c0 0c  or  %o7, %o4, %o2
a0138b30:  9b 2a e0 14  sll  %o3, 0x14, %o5
a0138b34:  de 0a 20 07  ldub  [ %o0 + 7 ], %o7
a0138b38:  82 12 80 0d  or  %o2, %o5, %g1
a0138b3c:  99 2a 60 18  sll  %o1, 0x18, %o4
a0138b40:  94 10 40 0c  or  %g1, %o4, %o2
a0138b44:  97 2b e0 1c  sll  %o7, 0x1c, %o3
a0138b48:  92 12 80 0b  or  %o2, %o3, %o1
a0138b4c:  d2 27 bf f4  st  %o1, [ %fp + -12 ]
a0138b50:  90 10 20 01  mov  1, %o0
a0138b54:  92 10 20 04  mov  4, %o1
a0138b58:  94 07 bf f4  add  %fp, -12, %o2
a0138b5c:  96 10 20 01  mov  1, %o3
a0138b60:  67 fd 4e a6  call  0x4008c5f8
a0138b64:  c0 27 bf f0  clr  [ %fp + -16 ]
a0138b68:  1b 2a 00 a9  sethi  %hi(0xa802a400), %o5
a0138b6c:  d0 0b 60 57  ldub  [ %o5 + 0x57 ], %o0	! 0xa802a457
a0138b70:  83 2a 20 10  sll  %o0, 0x10, %g1
a0138b74:  c2 27 bf f0  st  %g1, [ %fp + -16 ]
a0138b78:  90 10 20 01  mov  1, %o0
a0138b7c:  92 10 20 08  mov  8, %o1
a0138b80:  94 07 bf f0  add  %fp, -16, %o2
a0138b84:  67 fd 4e 9d  call  0x4008c5f8
a0138b88:  96 10 20 01  mov  1, %o3
a0138b8c:  01 00 00 00  nop
a0138b90:  81 c7 e0 08  ret
a0138b94:  81 e8 00 00  restore
