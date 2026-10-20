# leon2s CED_ALL 0xa0072cb8-0xa0072e60 (424 bytes)
a0072cb8:  9d e3 bf 98  save  %sp, -104, %sp
a0072cbc:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a0072cc0:  7f ff b9 70  call  0xa0061280
a0072cc4:  90 12 23 b8  or  %o0, 0x3b8, %o0	! 0xa00667b8
a0072cc8:  21 2a 01 ff  sethi  %hi(0xa807fc00), %l0
a0072ccc:  82 14 23 84  or  %l0, 0x384, %g1	! 0xa807ff84
a0072cd0:  e6 00 40 00  ld  [ %g1 ], %l3
a0072cd4:  7f ff b9 9d  call  0xa0061348
a0072cd8:  90 10 00 13  mov  %l3, %o0
a0072cdc:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a0072ce0:  7f ff b9 68  call  0xa0061280
a0072ce4:  90 12 23 d0  or  %o0, 0x3d0, %o0	! 0xa00667d0
a0072ce8:  a0 14 23 8c  or  %l0, 0x38c, %l0
a0072cec:  c2 04 00 00  ld  [ %l0 ], %g1
a0072cf0:  82 08 6f f0  and  %g1, 0xff0, %g1
a0072cf4:  97 30 60 04  srl  %g1, 4, %o3
a0072cf8:  a0 10 20 00  clr  %l0
a0072cfc:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0072d00:  9b 2c 20 03  sll  %l0, 3, %o5
a0072d04:  98 10 61 04  or  %g1, 0x104, %o4
a0072d08:  c2 03 00 0d  ld  [ %o4 + %o5 ], %g1
a0072d0c:  80 a0 40 0b  cmp  %g1, %o3
a0072d10:  12 80 00 07  bne  0xa0072d2c
a0072d14:  a0 04 20 01  inc  %l0
a0072d18:  82 03 40 0c  add  %o5, %o4, %g1
a0072d1c:  7f ff b9 59  call  0xa0061280
a0072d20:  d0 00 60 04  ld  [ %g1 + 4 ], %o0
a0072d24:  10 80 00 06  b  0xa0072d3c
a0072d28:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a0072d2c:  80 a4 20 10  cmp  %l0, 0x10
a0072d30:  04 bf ff f4  ble  0xa0072d00
a0072d34:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0072d38:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a0072d3c:  7f ff b9 51  call  0xa0061280
a0072d40:  90 12 23 e0  or  %o0, 0x3e0, %o0	! 0xa00667e0
a0072d44:  03 2a 01 ff  sethi  %hi(0xa807fc00), %g1
a0072d48:  a2 10 63 60  or  %g1, 0x360, %l1	! 0xa807ff60
a0072d4c:  a0 10 20 00  clr  %l0
a0072d50:  83 2c 20 02  sll  %l0, 2, %g1
a0072d54:  d0 04 40 01  ld  [ %l1 + %g1 ], %o0
a0072d58:  7f ff b9 7c  call  0xa0061348
a0072d5c:  25 28 01 b1  sethi  %hi(0xa006c400), %l2
a0072d60:  7f ff b9 48  call  0xa0061280
a0072d64:  90 14 a2 90  or  %l2, 0x290, %o0	! 0xa006c690
a0072d68:  82 0c 20 07  and  %l0, 7, %g1
a0072d6c:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a0072d70:  a0 04 20 01  inc  %l0
a0072d74:  80 a0 60 07  cmp  %g1, 7
a0072d78:  12 80 00 04  bne  0xa0072d88
a0072d7c:  90 12 22 e8  or  %o0, 0x2e8, %o0
a0072d80:  7f ff b9 40  call  0xa0061280
a0072d84:  01 00 00 00  nop
a0072d88:  80 a4 20 27  cmp  %l0, 0x27
a0072d8c:  04 bf ff f2  ble  0xa0072d54
a0072d90:  83 2c 20 02  sll  %l0, 2, %g1
a0072d94:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a0072d98:  7f ff b9 3a  call  0xa0061280
a0072d9c:  90 12 23 f8  or  %o0, 0x3f8, %o0	! 0xa00667f8
a0072da0:  03 2a 01 ff  sethi  %hi(0xa807fc00), %g1
a0072da4:  82 10 63 94  or  %g1, 0x394, %g1	! 0xa807ff94
a0072da8:  e2 00 40 00  ld  [ %g1 ], %l1
a0072dac:  a0 10 20 00  clr  %l0
a0072db0:  83 2c 20 02  sll  %l0, 2, %g1
a0072db4:  d0 04 40 01  ld  [ %l1 + %g1 ], %o0
a0072db8:  7f ff b9 64  call  0xa0061348
a0072dbc:  01 00 00 00  nop
a0072dc0:  7f ff b9 30  call  0xa0061280
a0072dc4:  90 14 a2 90  or  %l2, 0x290, %o0
a0072dc8:  82 0c 20 07  and  %l0, 7, %g1
a0072dcc:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a0072dd0:  a0 04 20 01  inc  %l0
a0072dd4:  80 a0 60 07  cmp  %g1, 7
a0072dd8:  12 80 00 04  bne  0xa0072de8
a0072ddc:  90 12 22 e8  or  %o0, 0x2e8, %o0
a0072de0:  7f ff b9 28  call  0xa0061280
a0072de4:  01 00 00 00  nop
a0072de8:  80 a4 20 0f  cmp  %l0, 0xf
a0072dec:  04 bf ff f2  ble  0xa0072db4
a0072df0:  83 2c 20 02  sll  %l0, 2, %g1
a0072df4:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a0072df8:  7f ff b9 22  call  0xa0061280
a0072dfc:  90 12 20 10  or  %o0, 0x10, %o0	! 0xa0066810
a0072e00:  a2 04 ff f0  add  %l3, -16, %l1
a0072e04:  a0 10 20 00  clr  %l0
a0072e08:  83 2c 20 02  sll  %l0, 2, %g1
a0072e0c:  d0 04 40 01  ld  [ %l1 + %g1 ], %o0
a0072e10:  7f ff b9 4e  call  0xa0061348
a0072e14:  01 00 00 00  nop
a0072e18:  7f ff b9 1a  call  0xa0061280
a0072e1c:  90 14 a2 90  or  %l2, 0x290, %o0
a0072e20:  82 0c 20 07  and  %l0, 7, %g1
a0072e24:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a0072e28:  a0 04 20 01  inc  %l0
a0072e2c:  80 a0 60 07  cmp  %g1, 7
a0072e30:  12 80 00 04  bne  0xa0072e40
a0072e34:  90 12 22 e8  or  %o0, 0x2e8, %o0
a0072e38:  7f ff b9 12  call  0xa0061280
a0072e3c:  01 00 00 00  nop
a0072e40:  80 a4 20 1f  cmp  %l0, 0x1f
a0072e44:  04 bf ff f2  ble  0xa0072e0c
a0072e48:  83 2c 20 02  sll  %l0, 2, %g1
a0072e4c:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a0072e50:  7f ff b9 0c  call  0xa0061280
a0072e54:  90 12 20 28  or  %o0, 0x28, %o0	! 0xa0066828
a0072e58:  10 80 00 00  b  0xa0072e58
a0072e5c:  01 00 00 00  nop
