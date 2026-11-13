# leon2m FUN_a0140b78 0xa0140b78-0xa0140e74 (764 bytes)
a0140b78:  9d e3 bf 98  save  %sp, -104, %sp
a0140b7c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0140b80:  2d 00 06 9a  sethi  %hi(0x1a6800), %l6
a0140b84:  90 15 a1 fe  or  %l6, 0x1fe, %o0	! 0x1a69fe
a0140b88:  94 5e 20 26  smul  %i0, 0x26, %o2
a0140b8c:  e2 0a 00 0a  ldub  [ %o0 + %o2 ], %l1
a0140b90:  a7 2c 60 03  sll  %l1, 3, %l3
a0140b94:  a0 04 c0 11  add  %l3, %l1, %l0
a0140b98:  29 00 06 9a  sethi  %hi(0x1a6800), %l4
a0140b9c:  97 2c 20 02  sll  %l0, 2, %o3
a0140ba0:  a4 04 40 11  add  %l1, %l1, %l2
a0140ba4:  9e 15 22 24  or  %l4, 0x224, %o7
a0140ba8:  92 04 80 11  add  %l2, %l1, %o1
a0140bac:  82 02 c0 0f  add  %o3, %o7, %g1
a0140bb0:  97 2a 60 02  sll  %o1, 2, %o3
a0140bb4:  2f 2a 00 b2  sethi  %hi(0xa802c800), %l7
a0140bb8:  da 08 60 02  ldub  [ %g1 + 2 ], %o5
a0140bbc:  92 15 e3 dc  or  %l7, 0x3dc, %o1
a0140bc0:  98 02 c0 09  add  %o3, %o1, %o4
a0140bc4:  80 a3 60 00  cmp  %o5, 0
a0140bc8:  12 80 00 0d  bne  0xa0140bfc
a0140bcc:  da 0b 20 08  ldub  [ %o4 + 8 ], %o5
a0140bd0:  98 0b 60 ff  and  %o5, 0xff, %o4
a0140bd4:  80 a3 20 ff  cmp  %o4, 0xff
a0140bd8:  02 80 00 0f  be  0xa0140c14
a0140bdc:  9a 10 3f ff  mov  -1, %o5
a0140be0:  82 02 80 08  add  %o2, %o0, %g1
a0140be4:  da 08 60 04  ldub  [ %g1 + 4 ], %o5
a0140be8:  ab 2b 60 08  sll  %o5, 8, %l5
a0140bec:  90 5b 00 15  smul  %o4, %l5, %o0
a0140bf0:  d4 12 40 0b  lduh  [ %o1 + %o3 ], %o2
a0140bf4:  10 80 00 08  b  0xa0140c14
a0140bf8:  9a 02 00 0a  add  %o0, %o2, %o5
a0140bfc:  a0 02 80 08  add  %o2, %o0, %l0
a0140c00:  d8 12 40 0b  lduh  [ %o1 + %o3 ], %o4
a0140c04:  de 0c 20 01  ldub  [ %l0 + 1 ], %o7
a0140c08:  97 2b e0 0b  sll  %o7, 0xb, %o3
a0140c0c:  92 02 c0 0c  add  %o3, %o4, %o1
a0140c10:  9a 0a 78 00  and  %o1, -2048, %o5
a0140c14:  11 00 06 9a  sethi  %hi(0x1a6800), %o0
a0140c18:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a0140c1c:  9e 12 21 fe  or  %o0, 0x1fe, %o7
a0140c20:  9b 2b 60 10  sll  %o5, 0x10, %o5
a0140c24:  2b 2a 00 a9  sethi  %hi(0xa802a400), %l5
a0140c28:  90 12 a3 dc  or  %o2, 0x3dc, %o0
a0140c2c:  27 00 06 9a  sethi  %hi(0x1a6800), %l3
a0140c30:  a5 33 60 10  srl  %o5, 0x10, %l2
a0140c34:  a0 14 e2 24  or  %l3, 0x224, %l0
a0140c38:  94 10 20 00  clr  %o2
a0140c3c:  96 10 20 00  clr  %o3
a0140c40:  d2 15 60 7a  lduh  [ %l5 + 0x7a ], %o1
a0140c44:  98 5a e0 26  smul  %o3, 0x26, %o4
a0140c48:  c2 0b c0 0c  ldub  [ %o7 + %o4 ], %g1
a0140c4c:  a7 28 60 03  sll  %g1, 3, %l3
a0140c50:  98 04 c0 01  add  %l3, %g1, %o4
a0140c54:  9a 00 40 01  add  %g1, %g1, %o5
a0140c58:  a6 03 40 01  add  %o5, %g1, %l3
a0140c5c:  83 2c e0 02  sll  %l3, 2, %g1
a0140c60:  da 12 00 01  lduh  [ %o0 + %g1 ], %o5
a0140c64:  99 2b 20 02  sll  %o4, 2, %o4
a0140c68:  80 a3 40 09  cmp  %o5, %o1
a0140c6c:  18 80 00 07  bgu  0xa0140c88
a0140c70:  94 02 a0 01  inc  %o2
a0140c74:  e6 14 00 0c  lduh  [ %l0 + %o4 ], %l3
a0140c78:  82 03 40 13  add  %o5, %l3, %g1
a0140c7c:  80 a2 40 01  cmp  %o1, %g1
a0140c80:  26 80 00 07  bl,a   0xa0140c9c
a0140c84:  90 10 00 0b  mov  %o3, %o0
a0140c88:  96 0a a0 ff  and  %o2, 0xff, %o3
a0140c8c:  80 a2 e0 00  cmp  %o3, 0
a0140c90:  02 bf ff ee  be  0xa0140c48
a0140c94:  98 5a e0 26  smul  %o3, 0x26, %o4
a0140c98:  90 10 20 ff  mov  0xff, %o0
a0140c9c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0140ca0:  a0 5a 20 26  smul  %o0, 0x26, %l0
a0140ca4:  94 15 a1 fe  or  %l6, 0x1fe, %o2
a0140ca8:  1f 00 00 3f  sethi  %hi(0xfc00), %o7
a0140cac:  d6 15 60 7a  lduh  [ %l5 + 0x7a ], %o3
a0140cb0:  e6 0a 80 10  ldub  [ %o2 + %l0 ], %l3
a0140cb4:  92 13 e3 ff  or  %o7, 0x3ff, %o1
a0140cb8:  80 a2 c0 09  cmp  %o3, %o1
a0140cbc:  02 80 00 0b  be  0xa0140ce8
a0140cc0:  a1 2c a0 10  sll  %l2, 0x10, %l0
a0140cc4:  9a 0c e0 ff  and  %l3, 0xff, %o5
a0140cc8:  80 a4 40 0d  cmp  %l1, %o5
a0140ccc:  02 80 00 25  be  0xa0140d60
a0140cd0:  95 2c 60 03  sll  %l1, 3, %o2
a0140cd4:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a0140cd8:  d6 0b 23 d9  ldub  [ %o4 + 0x3d9 ], %o3	! 0xa802cbd9
a0140cdc:  80 a2 e0 00  cmp  %o3, 0
a0140ce0:  12 80 00 2e  bne  0xa0140d98
a0140ce4:  01 00 00 00  nop
a0140ce8:  9f 2c 60 03  sll  %l1, 3, %o7
a0140cec:  92 03 c0 11  add  %o7, %l1, %o1
a0140cf0:  98 15 22 24  or  %l4, 0x224, %o4
a0140cf4:  83 2a 60 02  sll  %o1, 2, %g1
a0140cf8:  90 00 40 0c  add  %g1, %o4, %o0
a0140cfc:  e8 0a 20 02  ldub  [ %o0 + 2 ], %l4
a0140d00:  80 a5 20 00  cmp  %l4, 0
a0140d04:  12 80 00 12  bne  0xa0140d4c
a0140d08:  91 34 20 10  srl  %l0, 0x10, %o0
a0140d0c:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a0140d10:  a0 12 a3 ff  or  %o2, 0x3ff, %l0	! 0xffff
a0140d14:  80 a2 00 10  cmp  %o0, %l0
a0140d18:  22 80 00 24  be,a   0xa0140da8
a0140d1c:  90 15 a1 fe  or  %l6, 0x1fe, %o0
a0140d20:  ae 0c e0 ff  and  %l3, 0xff, %l7
a0140d24:  80 a4 40 17  cmp  %l1, %l7
a0140d28:  02 80 00 50  be  0xa0140e68
a0140d2c:  9a 15 a1 fe  or  %l6, 0x1fe, %o5
a0140d30:  a8 5e 20 26  smul  %i0, 0x26, %l4
a0140d34:  a6 05 00 0d  add  %l4, %o5, %l3
a0140d38:  d2 0c e0 04  ldub  [ %l3 + 4 ], %o1
a0140d3c:  7f ff cd 96  call  0xa0134394
a0140d40:  01 00 00 00  nop
a0140d44:  10 80 00 4a  b  0xa0140e6c
a0140d48:  e4 35 60 7a  sth  %l2, [ %l5 + 0x7a ]
a0140d4c:  d6 15 60 7a  lduh  [ %l5 + 0x7a ], %o3
a0140d50:  80 a2 c0 08  cmp  %o3, %o0
a0140d54:  02 80 00 45  be  0xa0140e68
a0140d58:  92 10 20 08  mov  8, %o1
a0140d5c:  30 bf ff f8  b,a   0xa0140d3c
a0140d60:  a0 02 80 11  add  %o2, %l1, %l0
a0140d64:  93 2c 20 02  sll  %l0, 2, %o1
a0140d68:  9e 15 22 24  or  %l4, 0x224, %o7
a0140d6c:  82 02 40 0f  add  %o1, %o7, %g1
a0140d70:  d8 08 60 02  ldub  [ %g1 + 2 ], %o4
a0140d74:  80 a3 20 01  cmp  %o4, 1
a0140d78:  12 bf ff dc  bne  0xa0140ce8
a0140d7c:  a1 2c a0 10  sll  %l2, 0x10, %l0
a0140d80:  9b 34 20 10  srl  %l0, 0x10, %o5
a0140d84:  80 a3 40 0b  cmp  %o5, %o3
a0140d88:  12 bf ff d4  bne  0xa0140cd8
a0140d8c:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a0140d90:  10 bf ff d7  b  0xa0140cec
a0140d94:  9f 2c 60 03  sll  %l1, 3, %o7
a0140d98:  7f ff fe 0e  call  0xa01405d0
a0140d9c:  01 00 00 00  nop
a0140da0:  10 bf ff d3  b  0xa0140cec
a0140da4:  9f 2c 60 03  sll  %l1, 3, %o7
a0140da8:  94 5e 20 26  smul  %i0, 0x26, %o2
a0140dac:  d6 0a 00 0a  ldub  [ %o0 + %o2 ], %o3
a0140db0:  9f 2a e0 03  sll  %o3, 3, %o7
a0140db4:  92 04 40 11  add  %l1, %l1, %o1
a0140db8:  82 03 c0 0b  add  %o7, %o3, %g1
a0140dbc:  9a 02 40 11  add  %o1, %l1, %o5
a0140dc0:  a9 28 60 02  sll  %g1, 2, %l4
a0140dc4:  a4 05 00 0c  add  %l4, %o4, %l2
a0140dc8:  92 15 e3 dc  or  %l7, 0x3dc, %o1
a0140dcc:  a7 2b 60 02  sll  %o5, 2, %l3
a0140dd0:  ae 04 c0 09  add  %l3, %o1, %l7
a0140dd4:  e2 0c a0 02  ldub  [ %l2 + 2 ], %l1
a0140dd8:  80 a4 60 00  cmp  %l1, 0
a0140ddc:  12 80 00 19  bne  0xa0140e40
a0140de0:  c0 2d e0 08  clrb  [ %l7 + 8 ]
a0140de4:  a2 02 c0 0b  add  %o3, %o3, %l1
a0140de8:  98 04 40 0b  add  %l1, %o3, %o4
a0140dec:  97 2b 20 02  sll  %o4, 2, %o3
a0140df0:  a0 02 c0 09  add  %o3, %o1, %l0
a0140df4:  d8 0c 20 08  ldub  [ %l0 + 8 ], %o4
a0140df8:  80 a3 20 ff  cmp  %o4, 0xff
a0140dfc:  02 80 00 08  be  0xa0140e1c
a0140e00:  82 10 3f ff  mov  -1, %g1
a0140e04:  a6 02 80 08  add  %o2, %o0, %l3
a0140e08:  e4 0c e0 04  ldub  [ %l3 + 4 ], %l2
a0140e0c:  af 2c a0 08  sll  %l2, 8, %l7
a0140e10:  94 5b 00 17  smul  %o4, %l7, %o2
a0140e14:  d0 12 40 0b  lduh  [ %o1 + %o3 ], %o0
a0140e18:  82 02 80 08  add  %o2, %o0, %g1
a0140e1c:  93 28 60 10  sll  %g1, 0x10, %o1
a0140e20:  94 15 a1 fe  or  %l6, 0x1fe, %o2
a0140e24:  90 5e 20 26  smul  %i0, 0x26, %o0
a0140e28:  ad 32 60 10  srl  %o1, 0x10, %l6
a0140e2c:  b0 02 00 0a  add  %o0, %o2, %i0
a0140e30:  90 10 00 16  mov  %l6, %o0
a0140e34:  d2 0e 20 04  ldub  [ %i0 + 4 ], %o1
a0140e38:  10 bf ff c1  b  0xa0140d3c
a0140e3c:  a4 10 00 16  mov  %l6, %l2
a0140e40:  a2 02 c0 0b  add  %o3, %o3, %l1
a0140e44:  98 04 40 0b  add  %l1, %o3, %o4
a0140e48:  a0 02 80 08  add  %o2, %o0, %l0
a0140e4c:  c2 0c 20 01  ldub  [ %l0 + 1 ], %g1
a0140e50:  9f 2b 20 02  sll  %o4, 2, %o7
a0140e54:  a9 28 60 0b  sll  %g1, 0xb, %l4
a0140e58:  d6 12 40 0f  lduh  [ %o1 + %o7 ], %o3
a0140e5c:  9a 05 00 0b  add  %l4, %o3, %o5
a0140e60:  10 bf ff ef  b  0xa0140e1c
a0140e64:  82 0b 78 00  and  %o5, -2048, %g1
a0140e68:  e4 35 60 7a  sth  %l2, [ %l5 + 0x7a ]
a0140e6c:  81 c7 e0 08  ret
a0140e70:  81 e8 00 00  restore
