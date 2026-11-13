# leon2m FUN_a0127b24 0xa0127b24-0xa0127c78 (340 bytes)
a0127b24:  9d e3 bf 98  save  %sp, -104, %sp
a0127b28:  23 2a 00 b6  sethi  %hi(0xa802d800), %l1
a0127b2c:  82 14 60 96  or  %l1, 0x96, %g1	! 0xa802d896
a0127b30:  da 08 60 0a  ldub  [ %g1 + 0xa ], %o5
a0127b34:  80 a3 60 01  cmp  %o5, 1
a0127b38:  02 80 00 4d  be  0xa0127c6c
a0127b3c:  b0 10 20 02  mov  2, %i0
a0127b40:  40 00 77 ee  call  0xa0145af8
a0127b44:  90 10 20 10  mov  0x10, %o0
a0127b48:  91 2a 20 10  sll  %o0, 0x10, %o0
a0127b4c:  80 a2 20 00  cmp  %o0, 0
a0127b50:  12 80 00 19  bne  0xa0127bb4
a0127b54:  01 00 00 00  nop
a0127b58:  40 00 77 e8  call  0xa0145af8
a0127b5c:  90 10 20 0d  mov  0xd, %o0	! 0xd
a0127b60:  95 2a 20 10  sll  %o0, 0x10, %o2
a0127b64:  93 32 a0 10  srl  %o2, 0x10, %o1
a0127b68:  80 a2 60 04  cmp  %o1, 4
a0127b6c:  82 60 3f ff  subx  %g0, -1, %g1
a0127b70:  80 88 60 ff  btst  0xff, %g1
a0127b74:  12 80 00 3e  bne  0xa0127c6c
a0127b78:  b0 10 20 02  mov  2, %i0
a0127b7c:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a0127b80:  98 16 22 90  or  %i0, 0x290, %o4	! 0xa802d290
a0127b84:  21 00 00 15  sethi  %hi(0x5400), %l0
a0127b88:  d4 13 21 f6  lduh  [ %o4 + 0x1f6 ], %o2
a0127b8c:  92 14 21 aa  or  %l0, 0x1aa, %o1
a0127b90:  80 a2 80 09  cmp  %o2, %o1
a0127b94:  22 80 00 19  be,a   0xa0127bf8
a0127b98:  d6 0b 21 d5  ldub  [ %o4 + 0x1d5 ], %o3
a0127b9c:  82 10 20 00  clr  %g1
a0127ba0:  80 88 60 ff  btst  0xff, %g1
a0127ba4:  12 80 00 24  bne  0xa0127c34
a0127ba8:  01 00 00 00  nop
a0127bac:  10 80 00 30  b  0xa0127c6c
a0127bb0:  b0 10 20 00  clr  %i0	! 0x0
a0127bb4:  40 00 77 d1  call  0xa0145af8
a0127bb8:  90 10 20 0d  mov  0xd, %o0
a0127bbc:  91 2a 20 10  sll  %o0, 0x10, %o0
a0127bc0:  83 32 20 10  srl  %o0, 0x10, %g1
a0127bc4:  9b 28 60 04  sll  %g1, 4, %o5
a0127bc8:  9e 23 40 01  sub  %o5, %g1, %o7
a0127bcc:  b1 2b e0 02  sll  %o7, 2, %i0
a0127bd0:  40 00 77 ca  call  0xa0145af8
a0127bd4:  90 10 20 0b  mov  0xb, %o0
a0127bd8:  99 2a 20 10  sll  %o0, 0x10, %o4
a0127bdc:  97 33 20 10  srl  %o4, 0x10, %o3
a0127be0:  a0 06 00 0b  add  %i0, %o3, %l0
a0127be4:  80 a4 20 13  cmp  %l0, 0x13
a0127be8:  14 bf ff e2  bg  0xa0127b70
a0127bec:  82 10 20 01  mov  1, %g1
a0127bf0:  10 bf ff e0  b  0xa0127b70
a0127bf4:  82 10 20 00  clr  %g1
a0127bf8:  80 a2 e0 00  cmp  %o3, 0
a0127bfc:  02 bf ff e9  be  0xa0127ba0
a0127c00:  82 10 20 00  clr  %g1
a0127c04:  40 00 77 bd  call  0xa0145af8
a0127c08:  90 10 20 11  mov  0x11, %o0
a0127c0c:  99 2a 20 10  sll  %o0, 0x10, %o4
a0127c10:  91 33 20 10  srl  %o4, 0x10, %o0
a0127c14:  80 a2 20 01  cmp  %o0, 1
a0127c18:  32 bf ff e2  bne,a   0xa0127ba0
a0127c1c:  82 10 20 00  clr  %g1
a0127c20:  9e 14 60 96  or  %l1, 0x96, %o7
a0127c24:  d0 2b e0 09  stb  %o0, [ %o7 + 9 ]
a0127c28:  c0 2b e0 0f  clrb  [ %o7 + 0xf ]
a0127c2c:  10 bf ff dd  b  0xa0127ba0
a0127c30:  82 10 20 01  mov  1, %g1
a0127c34:  40 00 77 b1  call  0xa0145af8
a0127c38:  90 10 20 0d  mov  0xd, %o0
a0127c3c:  95 2a 20 10  sll  %o0, 0x10, %o2
a0127c40:  91 32 a0 10  srl  %o2, 0x10, %o0
a0127c44:  93 2a 20 04  sll  %o0, 4, %o1
a0127c48:  82 22 40 08  sub  %o1, %o0, %g1
a0127c4c:  a1 28 60 02  sll  %g1, 2, %l0
a0127c50:  40 00 77 aa  call  0xa0145af8
a0127c54:  90 10 20 0b  mov  0xb, %o0
a0127c58:  9b 2a 20 10  sll  %o0, 0x10, %o5
a0127c5c:  a3 33 60 10  srl  %o5, 0x10, %l1
a0127c60:  80 84 00 11  addcc  %l0, %l1, %g0
a0127c64:  0c bf ff d2  bneg  0xa0127bac
a0127c68:  b0 10 20 02  mov  2, %i0
a0127c6c:  b0 0e 20 02  and  %i0, 2, %i0
a0127c70:  81 c7 e0 08  ret
a0127c74:  81 e8 00 00  restore
