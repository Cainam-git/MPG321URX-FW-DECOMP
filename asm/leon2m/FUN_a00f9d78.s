# leon2m FUN_a00f9d78 0xa00f9d78-0xa00f9f10 (408 bytes)
a00f9d78:  9d e3 bf 98  save  %sp, -104, %sp
a00f9d7c:  33 34 01 00  sethi  %hi(0xd0040000), %i1
a00f9d80:  82 16 60 98  or  %i1, 0x98, %g1	! 0xd0040098
a00f9d84:  f0 00 40 00  ld  [ %g1 ], %i0
a00f9d88:  bb 2e 20 10  sll  %i0, 0x10, %i5
a00f9d8c:  37 2a 00 9b  sethi  %hi(0xa8026c00), %i3
a00f9d90:  35 2a 00 b2  sethi  %hi(0xa802c800), %i2
a00f9d94:  b9 37 60 1c  srl  %i5, 0x1c, %i4
a00f9d98:  a6 16 e2 d6  or  %i3, 0x2d6, %l3
a00f9d9c:  80 a7 20 03  cmp  %i4, 3
a00f9da0:  02 80 00 0a  be  0xa00f9dc8
a00f9da4:  a4 16 a0 64  or  %i2, 0x64, %l2
a00f9da8:  33 2a 00 9b  sethi  %hi(0xa8026c00), %i1
a00f9dac:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a00f9db0:  a4 16 60 b6  or  %i1, 0xb6, %l2
a00f9db4:  80 a7 20 04  cmp  %i4, 4
a00f9db8:  12 80 00 54  bne  0xa00f9f08
a00f9dbc:  a6 16 20 64  or  %i0, 0x64, %l3
a00f9dc0:  10 80 00 2b  b  0xa00f9e6c
a00f9dc4:  fa 14 a0 0a  lduh  [ %l2 + 0xa ], %i5
a00f9dc8:  c2 14 e0 04  lduh  [ %l3 + 4 ], %g1
a00f9dcc:  fa 14 e0 0a  lduh  [ %l3 + 0xa ], %i5
a00f9dd0:  f8 14 e0 10  lduh  [ %l3 + 0x10 ], %i4
a00f9dd4:  f0 14 e0 b4  lduh  [ %l3 + 0xb4 ], %i0
a00f9dd8:  f6 14 e0 16  lduh  [ %l3 + 0x16 ], %i3
a00f9ddc:  f4 14 e0 1c  lduh  [ %l3 + 0x1c ], %i2
a00f9de0:  f2 14 e0 ae  lduh  [ %l3 + 0xae ], %i1
a00f9de4:  de 14 e0 ba  lduh  [ %l3 + 0xba ], %o7
a00f9de8:  da 14 e0 c0  lduh  [ %l3 + 0xc0 ], %o5
a00f9dec:  d8 14 e0 c6  lduh  [ %l3 + 0xc6 ], %o4
a00f9df0:  d6 14 e1 58  lduh  [ %l3 + 0x158 ], %o3
a00f9df4:  d4 14 e1 5e  lduh  [ %l3 + 0x15e ], %o2
a00f9df8:  d2 14 e1 64  lduh  [ %l3 + 0x164 ], %o1
a00f9dfc:  d0 14 e1 6a  lduh  [ %l3 + 0x16a ], %o0
a00f9e00:  e0 14 e1 70  lduh  [ %l3 + 0x170 ], %l0
a00f9e04:  e2 14 e2 02  lduh  [ %l3 + 0x202 ], %l1
a00f9e08:  c2 34 a0 c0  sth  %g1, [ %l2 + 0xc0 ]
a00f9e0c:  fa 34 a0 c2  sth  %i5, [ %l2 + 0xc2 ]
a00f9e10:  f8 34 a0 c4  sth  %i4, [ %l2 + 0xc4 ]
a00f9e14:  f0 34 a0 d2  sth  %i0, [ %l2 + 0xd2 ]
a00f9e18:  f6 34 a0 c6  sth  %i3, [ %l2 + 0xc6 ]
a00f9e1c:  f4 34 a0 c8  sth  %i2, [ %l2 + 0xc8 ]
a00f9e20:  f2 34 a0 d0  sth  %i1, [ %l2 + 0xd0 ]
a00f9e24:  de 34 a0 d4  sth  %o7, [ %l2 + 0xd4 ]
a00f9e28:  da 34 a0 d6  sth  %o5, [ %l2 + 0xd6 ]
a00f9e2c:  d8 34 a0 d8  sth  %o4, [ %l2 + 0xd8 ]
a00f9e30:  d6 34 a0 e0  sth  %o3, [ %l2 + 0xe0 ]
a00f9e34:  d4 34 a0 e2  sth  %o2, [ %l2 + 0xe2 ]
a00f9e38:  d2 34 a0 e4  sth  %o1, [ %l2 + 0xe4 ]
a00f9e3c:  d0 34 a0 e6  sth  %o0, [ %l2 + 0xe6 ]
a00f9e40:  e0 34 a0 e8  sth  %l0, [ %l2 + 0xe8 ]
a00f9e44:  e2 34 a0 f0  sth  %l1, [ %l2 + 0xf0 ]
a00f9e48:  c2 14 e2 08  lduh  [ %l3 + 0x208 ], %g1
a00f9e4c:  c2 34 a0 f2  sth  %g1, [ %l2 + 0xf2 ]
a00f9e50:  fa 14 e2 1a  lduh  [ %l3 + 0x21a ], %i5
a00f9e54:  f0 14 e2 0e  lduh  [ %l3 + 0x20e ], %i0
a00f9e58:  f8 14 e2 14  lduh  [ %l3 + 0x214 ], %i4
a00f9e5c:  fa 34 a0 f8  sth  %i5, [ %l2 + 0xf8 ]
a00f9e60:  f0 34 a0 f4  sth  %i0, [ %l2 + 0xf4 ]
a00f9e64:  10 80 00 29  b  0xa00f9f08
a00f9e68:  f8 34 a0 f6  sth  %i4, [ %l2 + 0xf6 ]
a00f9e6c:  f8 14 a0 10  lduh  [ %l2 + 0x10 ], %i4
a00f9e70:  f6 14 a0 16  lduh  [ %l2 + 0x16 ], %i3
a00f9e74:  f4 14 a0 1c  lduh  [ %l2 + 0x1c ], %i2
a00f9e78:  c2 14 a0 04  lduh  [ %l2 + 4 ], %g1
a00f9e7c:  f2 14 a0 ae  lduh  [ %l2 + 0xae ], %i1
a00f9e80:  f0 14 a0 b4  lduh  [ %l2 + 0xb4 ], %i0
a00f9e84:  de 14 a0 ba  lduh  [ %l2 + 0xba ], %o7
a00f9e88:  da 14 a0 c0  lduh  [ %l2 + 0xc0 ], %o5
a00f9e8c:  d8 14 a0 c6  lduh  [ %l2 + 0xc6 ], %o4
a00f9e90:  d6 14 a1 58  lduh  [ %l2 + 0x158 ], %o3
a00f9e94:  d4 14 a1 5e  lduh  [ %l2 + 0x15e ], %o2
a00f9e98:  d2 14 a1 64  lduh  [ %l2 + 0x164 ], %o1
a00f9e9c:  d0 14 a1 6a  lduh  [ %l2 + 0x16a ], %o0
a00f9ea0:  e0 14 a1 70  lduh  [ %l2 + 0x170 ], %l0
a00f9ea4:  e2 14 a2 02  lduh  [ %l2 + 0x202 ], %l1
a00f9ea8:  fa 34 e0 c2  sth  %i5, [ %l3 + 0xc2 ]
a00f9eac:  f8 34 e0 c4  sth  %i4, [ %l3 + 0xc4 ]
a00f9eb0:  f6 34 e0 c6  sth  %i3, [ %l3 + 0xc6 ]
a00f9eb4:  f4 34 e0 c8  sth  %i2, [ %l3 + 0xc8 ]
a00f9eb8:  c2 34 e0 c0  sth  %g1, [ %l3 + 0xc0 ]
a00f9ebc:  f2 34 e0 d0  sth  %i1, [ %l3 + 0xd0 ]
a00f9ec0:  f0 34 e0 d2  sth  %i0, [ %l3 + 0xd2 ]
a00f9ec4:  de 34 e0 d4  sth  %o7, [ %l3 + 0xd4 ]
a00f9ec8:  da 34 e0 d6  sth  %o5, [ %l3 + 0xd6 ]
a00f9ecc:  d8 34 e0 d8  sth  %o4, [ %l3 + 0xd8 ]
a00f9ed0:  d6 34 e0 e0  sth  %o3, [ %l3 + 0xe0 ]
a00f9ed4:  d4 34 e0 e2  sth  %o2, [ %l3 + 0xe2 ]
a00f9ed8:  d2 34 e0 e4  sth  %o1, [ %l3 + 0xe4 ]
a00f9edc:  d0 34 e0 e6  sth  %o0, [ %l3 + 0xe6 ]
a00f9ee0:  e0 34 e0 e8  sth  %l0, [ %l3 + 0xe8 ]
a00f9ee4:  e2 34 e0 f0  sth  %l1, [ %l3 + 0xf0 ]
a00f9ee8:  fa 14 a2 08  lduh  [ %l2 + 0x208 ], %i5
a00f9eec:  fa 34 e0 f2  sth  %i5, [ %l3 + 0xf2 ]
a00f9ef0:  f8 14 a2 1a  lduh  [ %l2 + 0x21a ], %i4
a00f9ef4:  f6 14 a2 0e  lduh  [ %l2 + 0x20e ], %i3
a00f9ef8:  f4 14 a2 14  lduh  [ %l2 + 0x214 ], %i2
a00f9efc:  f8 34 e0 f8  sth  %i4, [ %l3 + 0xf8 ]
a00f9f00:  f6 34 e0 f4  sth  %i3, [ %l3 + 0xf4 ]
a00f9f04:  f4 34 e0 f6  sth  %i2, [ %l3 + 0xf6 ]
a00f9f08:  81 c7 e0 08  ret
a00f9f0c:  91 e8 20 01  restore  %g0, 1, %o0
