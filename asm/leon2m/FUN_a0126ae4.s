# leon2m FUN_a0126ae4 0xa0126ae4-0xa0126c58 (372 bytes)
a0126ae4:  9d e3 bf 90  save  %sp, -112, %sp
a0126ae8:  2b 2a 00 b6  sethi  %hi(0xa802d800), %l5
a0126aec:  a2 15 60 90  or  %l5, 0x90, %l1	! 0xa802d890
a0126af0:  f0 2c 60 01  stb  %i0, [ %l1 + 1 ]
a0126af4:  7f ff f7 75  call  0xa01248c8
a0126af8:  c0 2d 60 90  clrb  [ %l5 + 0x90 ]
a0126afc:  80 8a 20 ff  btst  0xff, %o0
a0126b00:  02 80 00 54  be  0xa0126c50
a0126b04:  15 00 06 91  sethi  %hi(0x1a4400), %o2
a0126b08:  92 0e 20 ff  and  %i0, 0xff, %o1
a0126b0c:  7f fe e1 99  call  0xa00df170
a0126b10:  90 12 a1 d0  or  %o2, 0x1d0, %o0
a0126b14:  82 10 20 01  mov  1, %g1
a0126b18:  a4 10 20 02  mov  2, %l2
a0126b1c:  c2 23 a0 60  st  %g1, [ %sp + 0x60 ]
a0126b20:  9a 10 00 11  mov  %l1, %o5
a0126b24:  92 10 20 02  mov  2, %o1
a0126b28:  94 10 20 70  mov  0x70, %o2
a0126b2c:  96 10 20 05  mov  5, %o3
a0126b30:  98 10 20 00  clr  %o4
a0126b34:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a0126b38:  40 00 83 da  call  0xa0147aa0
a0126b3c:  90 10 20 60  mov  0x60, %o0
a0126b40:  67 fd 99 98  call  0x4008d1a0
a0126b44:  90 10 20 32  mov  0x32, %o0
a0126b48:  2d 2a 00 b6  sethi  %hi(0xa802d800), %l6
a0126b4c:  96 10 20 05  mov  5, %o3
a0126b50:  98 10 20 00  clr  %o4
a0126b54:  9a 15 a0 88  or  %l6, 0x88, %o5
a0126b58:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a0126b5c:  92 10 20 02  mov  2, %o1
a0126b60:  94 10 20 70  mov  0x70, %o2
a0126b64:  40 00 83 e1  call  0xa0147ae8
a0126b68:  90 10 20 60  mov  0x60, %o0
a0126b6c:  a0 15 a0 88  or  %l6, 0x88, %l0
a0126b70:  11 00 06 91  sethi  %hi(0x1a4400), %o0
a0126b74:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a0126b78:  d2 0d a0 88  ldub  [ %l6 + 0x88 ], %o1
a0126b7c:  7f fe e1 7d  call  0xa00df170
a0126b80:  90 12 22 00  or  %o0, 0x200, %o0
a0126b84:  a4 10 00 11  mov  %l1, %l2
a0126b88:  90 10 20 32  mov  0x32, %o0
a0126b8c:  67 fd 99 85  call  0x4008d1a0
a0126b90:  a2 10 00 10  mov  %l0, %l1
a0126b94:  a8 10 00 15  mov  %l5, %l4
a0126b98:  a6 10 00 16  mov  %l6, %l3
a0126b9c:  10 80 00 1f  b  0xa0126c18
a0126ba0:  a0 10 20 02  mov  2, %l0
a0126ba4:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0126ba8:  80 a2 e0 09  cmp  %o3, 9
a0126bac:  18 80 00 29  bgu  0xa0126c50
a0126bb0:  d2 0d 20 90  ldub  [ %l4 + 0x90 ], %o1
a0126bb4:  7f fe e1 6f  call  0xa00df170
a0126bb8:  d6 0c e0 88  ldub  [ %l3 + 0x88 ], %o3
a0126bbc:  98 10 20 01  mov  1, %o4
a0126bc0:  d8 23 a0 60  st  %o4, [ %sp + 0x60 ]
a0126bc4:  92 10 20 02  mov  2, %o1
a0126bc8:  94 10 20 70  mov  0x70, %o2
a0126bcc:  96 10 20 05  mov  5, %o3
a0126bd0:  98 10 20 00  clr  %o4
a0126bd4:  9a 10 00 12  mov  %l2, %o5
a0126bd8:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a0126bdc:  40 00 83 b1  call  0xa0147aa0
a0126be0:  90 10 20 60  mov  0x60, %o0
a0126be4:  67 fd 99 6f  call  0x4008d1a0
a0126be8:  90 10 20 32  mov  0x32, %o0
a0126bec:  92 10 20 02  mov  2, %o1
a0126bf0:  96 10 20 05  mov  5, %o3
a0126bf4:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a0126bf8:  90 10 20 60  mov  0x60, %o0
a0126bfc:  94 10 20 70  mov  0x70, %o2
a0126c00:  98 10 20 00  clr  %o4
a0126c04:  40 00 83 b9  call  0xa0147ae8
a0126c08:  9a 10 00 11  mov  %l1, %o5
a0126c0c:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0126c10:  92 02 e0 01  add  %o3, 1, %o1
a0126c14:  d2 2e 21 fd  stb  %o1, [ %i0 + 0x1fd ]
a0126c18:  31 00 06 91  sethi  %hi(0x1a4400), %i0
a0126c1c:  da 0c a0 01  ldub  [ %l2 + 1 ], %o5
a0126c20:  de 0c 60 01  ldub  [ %l1 + 1 ], %o7
a0126c24:  90 16 22 30  or  %i0, 0x230, %o0
a0126c28:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a0126c2c:  94 10 00 0d  mov  %o5, %o2
a0126c30:  80 a3 40 0f  cmp  %o5, %o7
a0126c34:  12 bf ff dc  bne  0xa0126ba4
a0126c38:  98 10 00 0f  mov  %o7, %o4
a0126c3c:  d2 0d 60 90  ldub  [ %l5 + 0x90 ], %o1
a0126c40:  c2 0d a0 88  ldub  [ %l6 + 0x88 ], %g1
a0126c44:  80 a2 40 01  cmp  %o1, %g1
a0126c48:  12 bf ff d8  bne  0xa0126ba8
a0126c4c:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0126c50:  81 c7 e0 08  ret
a0126c54:  81 e8 00 00  restore
