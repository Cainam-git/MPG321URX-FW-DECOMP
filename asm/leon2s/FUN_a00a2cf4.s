# leon2s FUN_a00a2cf4 0xa00a2cf4-0xa00a2e48 (340 bytes)
a00a2cf4:  9d e3 bf 98  save  %sp, -104, %sp
a00a2cf8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a2cfc:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a2d00:  a6 10 63 00  or  %g1, 0x300, %l3	! 0xa807db00
a00a2d04:  a2 5e 20 34  smul  %i0, 0x34, %l1
a00a2d08:  80 a6 20 00  cmp  %i0, 0
a00a2d0c:  02 80 00 06  be  0xa00a2d24
a00a2d10:  90 10 20 02  mov  2, %o0
a00a2d14:  80 a6 20 01  cmp  %i0, 1
a00a2d18:  90 10 20 03  mov  3, %o0
a00a2d1c:  12 80 00 49  bne  0xa00a2e40
a00a2d20:  82 10 20 23  mov  0x23, %g1
a00a2d24:  d8 04 c0 11  ld  [ %l3 + %l1 ], %o4
a00a2d28:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a2d2c:  da 03 20 38  ld  [ %o4 + 0x38 ], %o5
a00a2d30:  82 10 60 a8  or  %g1, 0xa8, %g1
a00a2d34:  c2 08 40 18  ldub  [ %g1 + %i0 ], %g1
a00a2d38:  9b 33 60 10  srl  %o5, 0x10, %o5
a00a2d3c:  9b 2b 40 01  sll  %o5, %g1, %o5
a00a2d40:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00a2d44:  b1 33 60 10  srl  %o5, 0x10, %i0
a00a2d48:  c2 03 20 3c  ld  [ %o4 + 0x3c ], %g1
a00a2d4c:  80 a0 00 18  cmp  %g0, %i0
a00a2d50:  83 28 60 10  sll  %g1, 0x10, %g1
a00a2d54:  a5 30 60 10  srl  %g1, 0x10, %l2
a00a2d58:  9a 60 3f ff  subx  %g0, -1, %o5
a00a2d5c:  80 a0 00 12  cmp  %g0, %l2
a00a2d60:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00a2d64:  13 00 00 07  sethi  %hi(0x1c00), %o1
a00a2d68:  82 60 3f ff  subx  %g0, -1, %g1
a00a2d6c:  92 12 63 1c  or  %o1, 0x31c, %o1
a00a2d70:  80 93 40 01  orcc  %o5, %g1, %g0
a00a2d74:  02 80 00 05  be  0xa00a2d88
a00a2d78:  90 10 00 10  mov  %l0, %o0
a00a2d7c:  c0 26 40 00  clr  [ %i1 ]
a00a2d80:  10 80 00 2f  b  0xa00a2e3c
a00a2d84:  c0 26 80 00  clr  [ %i2 ]
a00a2d88:  40 00 11 63  call  0xa00a7314
a00a2d8c:  01 00 00 00  nop
a00a2d90:  c2 04 c0 11  ld  [ %l3 + %l1 ], %g1
a00a2d94:  99 32 20 0c  srl  %o0, 0xc, %o4
a00a2d98:  da 00 60 08  ld  [ %g1 + 8 ], %o5
a00a2d9c:  96 04 00 10  add  %l0, %l0, %o3
a00a2da0:  15 00 03 d0  sethi  %hi(0xf4000), %o2
a00a2da4:  94 12 a2 40  or  %o2, 0x240, %o2	! 0xf4240
a00a2da8:  96 02 c0 10  add  %o3, %l0, %o3
a00a2dac:  98 0b 20 0f  and  %o4, 0xf, %o4
a00a2db0:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00a2db4:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa807cc64
a00a2db8:  98 5b 00 0a  smul  %o4, %o2, %o4
a00a2dbc:  90 0a 23 ff  and  %o0, 0x3ff, %o0
a00a2dc0:  9a 0b 60 c0  and  %o5, 0xc0, %o5
a00a2dc4:  97 2a e0 03  sll  %o3, 3, %o3
a00a2dc8:  96 02 c0 01  add  %o3, %g1, %o3
a00a2dcc:  90 5a 00 0a  smul  %o0, %o2, %o0
a00a2dd0:  99 33 20 04  srl  %o4, 4, %o4
a00a2dd4:  9b 33 60 06  srl  %o5, 6, %o5
a00a2dd8:  98 02 00 0c  add  %o0, %o4, %o4
a00a2ddc:  9a 03 60 01  inc  %o5
a00a2de0:  c2 0a e0 04  ldub  [ %o3 + 4 ], %g1
a00a2de4:  81 80 00 00  mov  %g0, %y
a00a2de8:  01 00 00 00  nop
a00a2dec:  01 00 00 00  nop
a00a2df0:  01 00 00 00  nop
a00a2df4:  98 73 00 0d  udiv  %o4, %o5, %o4
a00a2df8:  80 a0 60 00  cmp  %g1, 0
a00a2dfc:  32 80 00 02  bne,a   0xa00a2e04
a00a2e00:  99 2b 20 02  sll  %o4, 2, %o4
a00a2e04:  81 80 00 00  mov  %g0, %y
a00a2e08:  01 00 00 00  nop
a00a2e0c:  01 00 00 00  nop
a00a2e10:  01 00 00 00  nop
a00a2e14:  9a 73 00 18  udiv  %o4, %i0, %o5
a00a2e18:  d8 22 e0 0c  st  %o4, [ %o3 + 0xc ]
a00a2e1c:  82 5b 60 64  smul  %o5, 0x64, %g1
a00a2e20:  da 26 40 00  st  %o5, [ %i1 ]
a00a2e24:  81 80 00 00  mov  %g0, %y
a00a2e28:  01 00 00 00  nop
a00a2e2c:  01 00 00 00  nop
a00a2e30:  01 00 00 00  nop
a00a2e34:  82 70 40 12  udiv  %g1, %l2, %g1
a00a2e38:  c2 26 80 00  st  %g1, [ %i2 ]
a00a2e3c:  82 10 20 00  clr  %g1
a00a2e40:  81 c7 e0 08  ret
a00a2e44:  91 e8 00 01  restore  %g0, %g1, %o0
