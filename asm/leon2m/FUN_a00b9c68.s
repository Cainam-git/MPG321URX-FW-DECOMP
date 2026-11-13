# leon2m FUN_a00b9c68 0xa00b9c68-0xa00b9f30 (712 bytes)
a00b9c68:  9d e3 bf 98  save  %sp, -104, %sp
a00b9c6c:  83 2e 20 10  sll  %i0, 0x10, %g1
a00b9c70:  bb 2e 60 10  sll  %i1, 0x10, %i5
a00b9c74:  b7 38 60 10  sra  %g1, 0x10, %i3
a00b9c78:  bb 3f 60 10  sra  %i5, 0x10, %i5
a00b9c7c:  80 a6 c0 1d  cmp  %i3, %i5
a00b9c80:  98 10 00 18  mov  %i0, %o4
a00b9c84:  94 10 00 19  mov  %i1, %o2
a00b9c88:  92 10 00 1a  mov  %i2, %o1
a00b9c8c:  90 10 20 00  clr  %o0
a00b9c90:  16 80 00 03  bge  0xa00b9c9c
a00b9c94:  9e 10 20 01  mov  1, %o7
a00b9c98:  9e 10 20 00  clr  %o7
a00b9c9c:  83 2e a0 10  sll  %i2, 0x10, %g1
a00b9ca0:  b9 38 60 10  sra  %g1, 0x10, %i4
a00b9ca4:  80 a6 c0 1c  cmp  %i3, %i4
a00b9ca8:  16 80 00 03  bge  0xa00b9cb4
a00b9cac:  82 10 20 01  mov  1, %g1
a00b9cb0:  82 10 20 00  clr  %g1
a00b9cb4:  80 8b c0 01  btst  %o7, %g1
a00b9cb8:  12 80 00 0d  bne  0xa00b9cec
a00b9cbc:  9e 10 00 18  mov  %i0, %o7
a00b9cc0:  80 a7 40 1b  cmp  %i5, %i3
a00b9cc4:  06 80 00 52  bl  0xa00b9e0c
a00b9cc8:  b6 10 20 01  mov  1, %i3
a00b9ccc:  80 a7 40 1c  cmp  %i5, %i4
a00b9cd0:  16 80 00 03  bge  0xa00b9cdc
a00b9cd4:  82 10 20 01  mov  1, %g1
a00b9cd8:  82 10 20 00  clr  %g1
a00b9cdc:  80 8e c0 01  btst  %i3, %g1
a00b9ce0:  12 80 00 03  bne  0xa00b9cec
a00b9ce4:  9e 10 00 19  mov  %i1, %o7
a00b9ce8:  9e 10 00 1a  mov  %i2, %o7
a00b9cec:  97 2b 20 10  sll  %o4, 0x10, %o3
a00b9cf0:  9b 2a a0 10  sll  %o2, 0x10, %o5
a00b9cf4:  bb 3a e0 10  sra  %o3, 0x10, %i5
a00b9cf8:  b7 3b 60 10  sra  %o5, 0x10, %i3
a00b9cfc:  80 a7 40 1b  cmp  %i5, %i3
a00b9d00:  04 80 00 03  ble  0xa00b9d0c
a00b9d04:  b2 10 20 01  mov  1, %i1
a00b9d08:  b2 10 20 00  clr  %i1
a00b9d0c:  b9 2a 60 10  sll  %o1, 0x10, %i4
a00b9d10:  b5 3f 20 10  sra  %i4, 0x10, %i2
a00b9d14:  80 a7 40 1a  cmp  %i5, %i2
a00b9d18:  04 80 00 03  ble  0xa00b9d24
a00b9d1c:  82 10 20 01  mov  1, %g1
a00b9d20:  82 10 20 00  clr  %g1
a00b9d24:  80 8e 40 01  btst  %i1, %g1
a00b9d28:  12 80 00 0d  bne  0xa00b9d5c
a00b9d2c:  82 10 00 0c  mov  %o4, %g1
a00b9d30:  80 a6 c0 1d  cmp  %i3, %i5
a00b9d34:  14 80 00 34  bg  0xa00b9e04
a00b9d38:  ba 10 20 01  mov  1, %i5
a00b9d3c:  80 a6 c0 1a  cmp  %i3, %i2
a00b9d40:  04 80 00 03  ble  0xa00b9d4c
a00b9d44:  82 10 20 01  mov  1, %g1
a00b9d48:  82 10 20 00  clr  %g1
a00b9d4c:  80 8f 40 01  btst  %i5, %g1
a00b9d50:  12 80 00 03  bne  0xa00b9d5c
a00b9d54:  82 10 00 0a  mov  %o2, %g1
a00b9d58:  82 10 00 09  mov  %o1, %g1
a00b9d5c:  b4 23 c0 01  sub  %o7, %g1, %i2
a00b9d60:  b1 2e a0 10  sll  %i2, 0x10, %i0
a00b9d64:  b7 3e 20 10  sra  %i0, 0x10, %i3
a00b9d68:  33 00 00 3f  sethi  %hi(0xfc00), %i1
a00b9d6c:  80 a6 e0 03  cmp  %i3, 3
a00b9d70:  04 80 00 6e  ble  0xa00b9f28
a00b9d74:  b0 16 63 ff  or  %i1, 0x3ff, %i0
a00b9d78:  80 a6 e0 00  cmp  %i3, 0
a00b9d7c:  02 80 00 1c  be  0xa00b9dec
a00b9d80:  b1 2a 20 10  sll  %o0, 0x10, %i0
a00b9d84:  bb 2b e0 10  sll  %o7, 0x10, %i5
a00b9d88:  b1 3f 60 10  sra  %i5, 0x10, %i0
a00b9d8c:  b5 3a e0 10  sra  %o3, 0x10, %i2
a00b9d90:  80 a6 00 1a  cmp  %i0, %i2
a00b9d94:  02 80 00 39  be  0xa00b9e78
a00b9d98:  bb 3b 60 10  sra  %o5, 0x10, %i5
a00b9d9c:  80 a6 00 1d  cmp  %i0, %i5
a00b9da0:  02 80 00 57  be  0xa00b9efc
a00b9da4:  83 3f 20 10  sra  %i4, 0x10, %g1
a00b9da8:  80 a6 00 01  cmp  %i0, %g1
a00b9dac:  02 80 00 2a  be  0xa00b9e54
a00b9db0:  b8 26 80 1d  sub  %i2, %i5, %i4
a00b9db4:  b1 2a 20 10  sll  %o0, 0x10, %i0
a00b9db8:  bb 3e 20 10  sra  %i0, 0x10, %i5
a00b9dbc:  b3 2f 60 04  sll  %i5, 4, %i1
a00b9dc0:  b6 26 40 1d  sub  %i1, %i5, %i3
a00b9dc4:  bb 2e e0 12  sll  %i3, 0x12, %i5
a00b9dc8:  39 14 7a e1  sethi  %hi(0x51eb8400), %i4
a00b9dcc:  b5 3f 60 10  sra  %i5, 0x10, %i2
a00b9dd0:  82 17 21 1f  or  %i4, 0x11f, %g1
a00b9dd4:  80 5e 80 01  smul  %i2, %g1, %g0
a00b9dd8:  b1 40 00 00  rd  %y, %i0
a00b9ddc:  b3 3e 20 05  sra  %i0, 5, %i1
a00b9de0:  b7 3f 60 1f  sra  %i5, 0x1f, %i3
a00b9de4:  90 26 40 1b  sub  %i1, %i3, %o0
a00b9de8:  b1 2a 20 10  sll  %o0, 0x10, %i0
a00b9dec:  b7 3e 20 10  sra  %i0, 0x10, %i3
a00b9df0:  80 a6 e0 00  cmp  %i3, 0
a00b9df4:  06 80 00 08  bl  0xa00b9e14
a00b9df8:  33 2d 82 d8  sethi  %hi(0xb60b6000), %i1
a00b9dfc:  10 80 00 4b  b  0xa00b9f28
a00b9e00:  b1 36 20 10  srl  %i0, 0x10, %i0
a00b9e04:  10 bf ff ce  b  0xa00b9d3c
a00b9e08:  ba 10 20 00  clr  %i5
a00b9e0c:  10 bf ff b0  b  0xa00b9ccc
a00b9e10:  b6 10 20 00  clr  %i3
a00b9e14:  b8 16 60 b7  or  %i1, 0xb7, %i4
a00b9e18:  80 5e c0 1c  smul  %i3, %i4, %g0
a00b9e1c:  83 40 00 00  rd  %y, %g1
a00b9e20:  b4 00 40 1b  add  %g1, %i3, %i2
a00b9e24:  b3 3e a0 08  sra  %i2, 8, %i1
a00b9e28:  bb 3e 20 1f  sra  %i0, 0x1f, %i5
a00b9e2c:  b8 26 40 1d  sub  %i1, %i5, %i4
a00b9e30:  82 5f 21 68  smul  %i4, 0x168, %g1
a00b9e34:  82 26 c0 01  sub  %i3, %g1, %g1
a00b9e38:  b5 28 60 10  sll  %g1, 0x10, %i2
a00b9e3c:  80 a6 a0 00  cmp  %i2, 0
a00b9e40:  22 80 00 3a  be,a   0xa00b9f28
a00b9e44:  b1 36 20 10  srl  %i0, 0x10, %i0
a00b9e48:  b6 00 61 68  add  %g1, 0x168, %i3
a00b9e4c:  10 bf ff ec  b  0xa00b9dfc
a00b9e50:  b1 2e e0 10  sll  %i3, 0x10, %i0
a00b9e54:  b4 5f 20 64  smul  %i4, 0x64, %i2
a00b9e58:  9b 3e a0 1f  sra  %i2, 0x1f, %o5
a00b9e5c:  81 83 60 00  mov  %o5, %y
a00b9e60:  01 00 00 00  nop
a00b9e64:  01 00 00 00  nop
a00b9e68:  01 00 00 00  nop
a00b9e6c:  b0 7e 80 1b  sdiv  %i2, %i3, %i0
a00b9e70:  10 bf ff d1  b  0xa00b9db4
a00b9e74:  90 06 21 90  add  %i0, 0x190, %o0
a00b9e78:  b5 3f 20 10  sra  %i4, 0x10, %i2
a00b9e7c:  b1 3b 60 10  sra  %o5, 0x10, %i0
a00b9e80:  b2 26 00 1a  sub  %i0, %i2, %i1
a00b9e84:  ba 5e 60 64  smul  %i1, 0x64, %i5
a00b9e88:  83 3f 60 1f  sra  %i5, 0x1f, %g1
a00b9e8c:  81 80 60 00  mov  %g1, %y
a00b9e90:  01 00 00 00  nop
a00b9e94:  01 00 00 00  nop
a00b9e98:  01 00 00 00  nop
a00b9e9c:  b2 7f 40 1b  sdiv  %i5, %i3, %i1
a00b9ea0:  03 06 d3 a0  sethi  %hi(0x1b4e8000), %g1
a00b9ea4:  b6 10 61 b5  or  %g1, 0x1b5, %i3	! 0x1b4e81b5
a00b9ea8:  80 5e 40 1b  smul  %i1, %i3, %g0
a00b9eac:  b5 40 00 00  rd  %y, %i2
a00b9eb0:  b1 3e a0 06  sra  %i2, 6, %i0
a00b9eb4:  b9 3e 60 1f  sra  %i1, 0x1f, %i4
a00b9eb8:  82 26 00 1c  sub  %i0, %i4, %g1
a00b9ebc:  b6 58 62 58  smul  %g1, 0x258, %i3
a00b9ec0:  90 26 40 1b  sub  %i1, %i3, %o0
a00b9ec4:  b1 2a 20 10  sll  %o0, 0x10, %i0
a00b9ec8:  bb 3e 20 10  sra  %i0, 0x10, %i5
a00b9ecc:  b3 2f 60 04  sll  %i5, 4, %i1
a00b9ed0:  b6 26 40 1d  sub  %i1, %i5, %i3
a00b9ed4:  bb 2e e0 12  sll  %i3, 0x12, %i5
a00b9ed8:  39 14 7a e1  sethi  %hi(0x51eb8400), %i4
a00b9edc:  b5 3f 60 10  sra  %i5, 0x10, %i2
a00b9ee0:  82 17 21 1f  or  %i4, 0x11f, %g1
a00b9ee4:  80 5e 80 01  smul  %i2, %g1, %g0
a00b9ee8:  b1 40 00 00  rd  %y, %i0
a00b9eec:  b3 3e 20 05  sra  %i0, 5, %i1
a00b9ef0:  b7 3f 60 1f  sra  %i5, 0x1f, %i3
a00b9ef4:  10 bf ff bd  b  0xa00b9de8
a00b9ef8:  90 26 40 1b  sub  %i1, %i3, %o0
a00b9efc:  b3 3f 20 10  sra  %i4, 0x10, %i1
a00b9f00:  ba 26 40 1a  sub  %i1, %i2, %i5
a00b9f04:  82 5f 60 64  smul  %i5, 0x64, %g1
a00b9f08:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a00b9f0c:  81 83 60 00  mov  %o5, %y
a00b9f10:  01 00 00 00  nop
a00b9f14:  01 00 00 00  nop
a00b9f18:  01 00 00 00  nop
a00b9f1c:  b8 78 40 1b  sdiv  %g1, %i3, %i4
a00b9f20:  10 bf ff a5  b  0xa00b9db4
a00b9f24:  90 07 20 c8  add  %i4, 0xc8, %o0
a00b9f28:  81 c7 e0 08  ret
a00b9f2c:  81 e8 00 00  restore
