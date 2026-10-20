# leon2m FUN_a0143c14 0xa0143c14-0xa0143d14 (172 bytes)
a0143c14:  9d e3 bf 98  save  %sp, -104, %sp
a0143c18:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0143c1c:  80 a6 20 01  cmp  %i0, 1
a0143c20:  02 80 00 0b  be  0xa0143c4c
a0143c24:  90 10 20 01  mov  1, %o0
a0143c28:  80 a6 20 01  cmp  %i0, 1
a0143c2c:  04 80 00 1f  ble  0xa0143ca8
a0143c30:  80 a6 20 02  cmp  %i0, 2
a0143c34:  02 80 00 06  be  0xa0143c4c
a0143c38:  90 10 20 02  mov  2, %o0
a0143c3c:  80 a6 20 03  cmp  %i0, 3
a0143c40:  02 80 00 03  be  0xa0143c4c
a0143c44:  90 10 20 03  mov  3, %o0
a0143c48:  90 10 3f ff  mov  -1, %o0
a0143c4c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0143c50:  80 a2 20 03  cmp  %o0, 3
a0143c54:  12 80 00 07  bne  0xa0143c70
a0143c58:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0143c5c:  d8 00 63 d0  ld  [ %g1 + 0x3d0 ], %o4	! 0xa802e3d0
a0143c60:  1b 00 08 00  sethi  %hi(0x200000), %o5
a0143c64:  80 8b 00 0d  btst  %o4, %o5
a0143c68:  12 80 00 28  bne  0xa0143d08
a0143c6c:  b0 10 20 04  mov  4, %i0
a0143c70:  7f ff e4 7f  call  0xa013ce6c
a0143c74:  01 00 00 00  nop
a0143c78:  82 0a 20 ff  and  %o0, 0xff, %g1
a0143c7c:  80 a0 60 0c  cmp  %g1, 0xc
a0143c80:  38 80 00 22  bgu,a   0xa0143d08
a0143c84:  b0 10 20 04  mov  4, %i0
a0143c88:  17 00 03 8c  sethi  %hi(0xe3000), %o3
a0143c8c:  93 28 60 02  sll  %g1, 2, %o1
a0143c90:  94 12 e0 74  or  %o3, 0x74, %o2
a0143c94:  d0 02 80 09  ld  [ %o2 + %o1 ], %o0
a0143c98:  81 c2 00 00  jmp  %o0
a0143c9c:  01 00 00 00  nop
a0143ca0:  10 80 00 1a  b  0xa0143d08
a0143ca4:  b0 10 20 04  mov  4, %i0	! 0x4
a0143ca8:  80 a6 20 00  cmp  %i0, 0
a0143cac:  02 bf ff e8  be  0xa0143c4c
a0143cb0:  90 10 20 00  clr  %o0
a0143cb4:  10 bf ff e6  b  0xa0143c4c
a0143cb8:  90 10 3f ff  mov  -1, %o0
a0143cbc:  10 80 00 13  b  0xa0143d08
a0143cc0:  b0 10 20 0a  mov  0xa, %i0
a0143cc4:  10 80 00 11  b  0xa0143d08
a0143cc8:  b0 10 20 00  clr  %i0
a0143ccc:  10 80 00 0f  b  0xa0143d08
a0143cd0:  b0 10 20 01  mov  1, %i0
a0143cd4:  10 80 00 0d  b  0xa0143d08
a0143cd8:  b0 10 20 02  mov  2, %i0
a0143cdc:  10 80 00 0b  b  0xa0143d08
a0143ce0:  b0 10 20 03  mov  3, %i0
a0143ce4:  10 80 00 09  b  0xa0143d08
a0143ce8:  b0 10 20 05  mov  5, %i0
a0143cec:  10 80 00 07  b  0xa0143d08
a0143cf0:  b0 10 20 06  mov  6, %i0
a0143cf4:  10 80 00 05  b  0xa0143d08
a0143cf8:  b0 10 20 07  mov  7, %i0
a0143cfc:  10 80 00 03  b  0xa0143d08
a0143d00:  b0 10 20 08  mov  8, %i0
a0143d04:  b0 10 20 09  mov  9, %i0
a0143d08:  b0 0e 20 0f  and  %i0, 0xf, %i0
a0143d0c:  81 c7 e0 08  ret
a0143d10:  81 e8 00 00  restore
