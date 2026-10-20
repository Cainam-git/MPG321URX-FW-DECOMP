# leon2m FUN_a0151aa4 0xa0151aa4-0xa0151c84 (480 bytes)
a0151aa4:  9d e3 bf 98  save  %sp, -104, %sp
a0151aa8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0151aac:  80 8e 20 04  btst  4, %i0
a0151ab0:  02 80 00 0d  be  0xa0151ae4
a0151ab4:  80 8e 20 08  btst  8, %i0
a0151ab8:  82 0e 60 ff  and  %i1, 0xff, %g1
a0151abc:  80 a0 60 01  cmp  %g1, 1
a0151ac0:  02 80 00 58  be  0xa0151c20
a0151ac4:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a0151ac8:  92 14 21 16  or  %l0, 0x116, %o1	! 0xa802e116
a0151acc:  7f ff 4c 4a  call  0xa0124bf4
a0151ad0:  d0 0a 60 10  ldub  [ %o1 + 0x10 ], %o0
a0151ad4:  80 8a 20 ff  btst  0xff, %o0
a0151ad8:  32 80 00 53  bne,a   0xa0151c24
a0151adc:  a0 14 21 16  or  %l0, 0x116, %l0
a0151ae0:  80 8e 20 08  btst  8, %i0
a0151ae4:  02 80 00 0d  be  0xa0151b18
a0151ae8:  80 8e 20 10  btst  0x10, %i0
a0151aec:  90 0e 60 ff  and  %i1, 0xff, %o0
a0151af0:  80 a2 20 01  cmp  %o0, 1
a0151af4:  02 80 00 3c  be  0xa0151be4
a0151af8:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a0151afc:  94 14 21 16  or  %l0, 0x116, %o2	! 0xa802e116
a0151b00:  7f ff 4c 3d  call  0xa0124bf4
a0151b04:  d0 0a a0 22  ldub  [ %o2 + 0x22 ], %o0
a0151b08:  80 8a 20 ff  btst  0xff, %o0
a0151b0c:  32 80 00 37  bne,a   0xa0151be8
a0151b10:  a0 14 21 16  or  %l0, 0x116, %l0
a0151b14:  80 8e 20 10  btst  0x10, %i0
a0151b18:  02 80 00 17  be  0xa0151b74
a0151b1c:  80 8e 20 20  btst  0x20, %i0
a0151b20:  96 0e 60 ff  and  %i1, 0xff, %o3
a0151b24:  80 a2 e0 01  cmp  %o3, 1
a0151b28:  02 80 00 06  be  0xa0151b40
a0151b2c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0151b30:  da 03 21 a0  ld  [ %o4 + 0x1a0 ], %o5	! 0xa802e1a0
a0151b34:  80 a3 60 00  cmp  %o5, 0
a0151b38:  06 80 00 49  bl  0xa0151c5c
a0151b3c:  01 00 00 00  nop
a0151b40:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0151b44:  7f ff 4c 98  call  0xa0124da4
a0151b48:  d0 08 61 4a  ldub  [ %g1 + 0x14a ], %o0	! 0xa802e14a
a0151b4c:  90 10 20 00  clr  %o0
a0151b50:  7f fe d7 b4  call  0xa0107a20
a0151b54:  92 10 20 00  clr  %o1
a0151b58:  90 10 20 00  clr  %o0
a0151b5c:  7f fe d8 12  call  0xa0107ba4
a0151b60:  92 10 20 00  clr  %o1
a0151b64:  90 10 20 06  mov  6, %o0
a0151b68:  7f ff a6 fb  call  0xa013b754
a0151b6c:  92 10 23 20  mov  0x320, %o1
a0151b70:  80 8e 20 20  btst  0x20, %i0
a0151b74:  02 80 00 42  be  0xa0151c7c
a0151b78:  b0 0e 60 ff  and  %i1, 0xff, %i0
a0151b7c:  80 a6 20 01  cmp  %i0, 1
a0151b80:  02 80 00 06  be  0xa0151b98
a0151b84:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a0151b88:  f2 02 61 a0  ld  [ %o1 + 0x1a0 ], %i1	! 0xa802e1a0
a0151b8c:  80 a6 60 00  cmp  %i1, 0
a0151b90:  06 80 00 0e  bl  0xa0151bc8
a0151b94:  01 00 00 00  nop
a0151b98:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a0151b9c:  7f ff 4c 82  call  0xa0124da4
a0151ba0:  d0 0a a1 5c  ldub  [ %o2 + 0x15c ], %o0	! 0xa802e15c
a0151ba4:  90 10 20 01  mov  1, %o0
a0151ba8:  7f fe d7 9e  call  0xa0107a20
a0151bac:  92 10 20 00  clr  %o1
a0151bb0:  90 10 20 01  mov  1, %o0
a0151bb4:  7f fe d7 fc  call  0xa0107ba4
a0151bb8:  92 10 20 00  clr  %o1
a0151bbc:  b0 10 20 07  mov  7, %i0
a0151bc0:  7f ff a6 e5  call  0xa013b754
a0151bc4:  93 e8 23 20  restore  %g0, 0x320, %o1
a0151bc8:  7f ff 65 f3  call  0xa012b394
a0151bcc:  90 10 20 01  mov  1, %o0
a0151bd0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0151bd4:  80 a2 20 01  cmp  %o0, 1
a0151bd8:  12 bf ff f1  bne  0xa0151b9c
a0151bdc:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a0151be0:  30 80 00 27  b,a   0xa0151c7c
a0151be4:  a0 14 21 16  or  %l0, 0x116, %l0
a0151be8:  7f ff 4c 6f  call  0xa0124da4
a0151bec:  d0 0c 20 22  ldub  [ %l0 + 0x22 ], %o0
a0151bf0:  7f ff 4d 4d  call  0xa0125124
a0151bf4:  d0 0c 20 22  ldub  [ %l0 + 0x22 ], %o0
a0151bf8:  92 10 20 00  clr  %o1
a0151bfc:  7f ff 6c 5b  call  0xa012cd68
a0151c00:  90 0a 20 ff  and  %o0, 0xff, %o0
a0151c04:  7f ff 97 47  call  0xa0137920
a0151c08:  90 10 20 01  mov  1, %o0
a0151c0c:  90 10 20 05  mov  5, %o0
a0151c10:  7f ff a6 d1  call  0xa013b754
a0151c14:  92 10 23 e8  mov  0x3e8, %o1
a0151c18:  10 bf ff c0  b  0xa0151b18
a0151c1c:  80 8e 20 10  btst  0x10, %i0
a0151c20:  a0 14 21 16  or  %l0, 0x116, %l0
a0151c24:  7f ff 4c 60  call  0xa0124da4
a0151c28:  d0 0c 20 10  ldub  [ %l0 + 0x10 ], %o0
a0151c2c:  7f ff 4d 3e  call  0xa0125124
a0151c30:  d0 0c 20 10  ldub  [ %l0 + 0x10 ], %o0
a0151c34:  92 10 20 00  clr  %o1
a0151c38:  7f ff 6c 4c  call  0xa012cd68
a0151c3c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0151c40:  7f ff 97 38  call  0xa0137920
a0151c44:  90 10 20 00  clr  %o0
a0151c48:  90 10 20 04  mov  4, %o0
a0151c4c:  7f ff a6 c2  call  0xa013b754
a0151c50:  92 10 23 e8  mov  0x3e8, %o1
a0151c54:  10 bf ff a4  b  0xa0151ae4
a0151c58:  80 8e 20 08  btst  8, %i0
a0151c5c:  7f ff 65 ce  call  0xa012b394
a0151c60:  90 10 20 00  clr  %o0
a0151c64:  9e 0a 20 ff  and  %o0, 0xff, %o7
a0151c68:  80 a3 e0 01  cmp  %o7, 1
a0151c6c:  12 bf ff b6  bne  0xa0151b44
a0151c70:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0151c74:  10 bf ff c0  b  0xa0151b74
a0151c78:  80 8e 20 20  btst  0x20, %i0
a0151c7c:  81 c7 e0 08  ret
a0151c80:  81 e8 00 00  restore
