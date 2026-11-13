# leon2m FUN_a00b2c18 0xa00b2c18-0xa00b2d04 (236 bytes)
a00b2c18:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00b2c1c:  94 10 63 f4  or  %g1, 0x3f4, %o2	! 0xa802cff4
a00b2c20:  da 12 a0 12  lduh  [ %o2 + 0x12 ], %o5
a00b2c24:  80 a3 60 05  cmp  %o5, 5
a00b2c28:  02 80 00 28  be  0xa00b2cc8
a00b2c2c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00b2c30:  98 12 e2 90  or  %o3, 0x290, %o4	! 0xa802d290
a00b2c34:  d6 12 a0 10  lduh  [ %o2 + 0x10 ], %o3
a00b2c38:  80 a2 e0 04  cmp  %o3, 4
a00b2c3c:  22 80 00 1e  be,a   0xa00b2cb4
a00b2c40:  c2 03 21 dc  ld  [ %o4 + 0x1dc ], %g1
a00b2c44:  da 0b 21 e4  ldub  [ %o4 + 0x1e4 ], %o5
a00b2c48:  80 a3 60 01  cmp  %o5, 1
a00b2c4c:  02 80 00 2b  be  0xa00b2cf8
a00b2c50:  01 00 00 00  nop
a00b2c54:  d0 0b 21 e5  ldub  [ %o4 + 0x1e5 ], %o0
a00b2c58:  80 a2 20 01  cmp  %o0, 1
a00b2c5c:  02 80 00 27  be  0xa00b2cf8
a00b2c60:  90 10 20 01  mov  1, %o0
a00b2c64:  d6 12 a0 0e  lduh  [ %o2 + 0xe ], %o3
a00b2c68:  93 2a e0 10  sll  %o3, 0x10, %o1
a00b2c6c:  9b 32 60 1f  srl  %o1, 0x1f, %o5
a00b2c70:  82 22 00 0d  sub  %o0, %o5, %g1
a00b2c74:  92 08 60 ff  and  %g1, 0xff, %o1
a00b2c78:  19 3f ff e0  sethi  %hi(0xffff8000), %o4
a00b2c7c:  91 2a 60 0f  sll  %o1, 0xf, %o0
a00b2c80:  9a 2a c0 0c  andn  %o3, %o4, %o5
a00b2c84:  98 13 40 08  or  %o5, %o0, %o4
a00b2c88:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00b2c8c:  92 0b 00 01  and  %o4, %g1, %o1
a00b2c90:  97 2a 60 10  sll  %o1, 0x10, %o3
a00b2c94:  90 10 20 01  mov  1, %o0
a00b2c98:  92 10 20 01  mov  1, %o1
a00b2c9c:  80 a2 e0 00  cmp  %o3, 0
a00b2ca0:  02 80 00 12  be  0xa00b2ce8
a00b2ca4:  d8 32 a0 0e  sth  %o4, [ %o2 + 0xe ]
a00b2ca8:  82 13 c0 00  mov  %o7, %g1
a00b2cac:  7f ff f6 99  call  0xa00b0710
a00b2cb0:  9e 10 40 00  mov  %g1, %o7
a00b2cb4:  80 a0 60 00  cmp  %g1, 0
a00b2cb8:  06 80 00 10  bl  0xa00b2cf8
a00b2cbc:  01 00 00 00  nop
a00b2cc0:  10 bf ff e2  b  0xa00b2c48
a00b2cc4:  da 0b 21 e4  ldub  [ %o4 + 0x1e4 ], %o5
a00b2cc8:  92 12 e2 90  or  %o3, 0x290, %o1
a00b2ccc:  d8 02 61 dc  ld  [ %o1 + 0x1dc ], %o4
a00b2cd0:  11 10 00 00  sethi  %hi(0x40000000), %o0
a00b2cd4:  80 8b 00 08  btst  %o4, %o0
a00b2cd8:  12 80 00 08  bne  0xa00b2cf8
a00b2cdc:  98 12 e2 90  or  %o3, 0x290, %o4
a00b2ce0:  10 bf ff d6  b  0xa00b2c38
a00b2ce4:  d6 12 a0 10  lduh  [ %o2 + 0x10 ], %o3
a00b2ce8:  92 10 20 00  clr  %o1
a00b2cec:  82 13 c0 00  mov  %o7, %g1
a00b2cf0:  7f ff f6 88  call  0xa00b0710
a00b2cf4:  9e 10 40 00  mov  %g1, %o7
a00b2cf8:  01 00 00 00  nop
a00b2cfc:  81 c3 e0 08  retl
a00b2d00:  01 00 00 00  nop
