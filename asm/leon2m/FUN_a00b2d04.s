# leon2m FUN_a00b2d04 0xa00b2d04-0xa00b3070 (876 bytes)
a00b2d04:  9d e3 bf 98  save  %sp, -104, %sp
a00b2d08:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00b2d0c:  b0 14 22 90  or  %l0, 0x290, %i0	! 0xa802d290
a00b2d10:  da 0e 21 e4  ldub  [ %i0 + 0x1e4 ], %o5
a00b2d14:  80 a3 60 01  cmp  %o5, 1
a00b2d18:  02 80 00 49  be  0xa00b2e3c
a00b2d1c:  c2 0e 21 e5  ldub  [ %i0 + 0x1e5 ], %g1
a00b2d20:  80 a0 60 01  cmp  %g1, 1
a00b2d24:  02 80 00 3b  be  0xa00b2e10
a00b2d28:  80 a3 60 01  cmp  %o5, 1
a00b2d2c:  7f ff 78 ab  call  0xa0090fd8
a00b2d30:  01 00 00 00  nop
a00b2d34:  17 2a 00 97  sethi  %hi(0xa8025c00), %o3
a00b2d38:  d4 0a e0 55  ldub  [ %o3 + 0x55 ], %o2	! 0xa8025c55
a00b2d3c:  80 a2 a0 02  cmp  %o2, 2
a00b2d40:  02 80 00 63  be  0xa00b2ecc
a00b2d44:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a00b2d48:  90 13 e3 f4  or  %o7, 0x3f4, %o0	! 0xa802cff4
a00b2d4c:  f0 0a 20 3f  ldub  [ %o0 + 0x3f ], %i0
a00b2d50:  80 a6 20 00  cmp  %i0, 0
a00b2d54:  12 80 00 45  bne  0xa00b2e68
a00b2d58:  d8 0a e0 55  ldub  [ %o3 + 0x55 ], %o4
a00b2d5c:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a00b2d60:  d2 0a a0 56  ldub  [ %o2 + 0x56 ], %o1	! 0xa8025c56
a00b2d64:  80 a2 60 00  cmp  %o1, 0
a00b2d68:  12 80 00 0a  bne  0xa00b2d90
a00b2d6c:  d6 0a a0 56  ldub  [ %o2 + 0x56 ], %o3
a00b2d70:  96 14 22 90  or  %l0, 0x290, %o3
a00b2d74:  31 30 00 00  sethi  %hi(0xc0000000), %i0
a00b2d78:  d0 02 e1 dc  ld  [ %o3 + 0x1dc ], %o0
a00b2d7c:  9a 0a 00 18  and  %o0, %i0, %o5
a00b2d80:  80 a3 40 18  cmp  %o5, %i0
a00b2d84:  02 80 00 86  be  0xa00b2f9c
a00b2d88:  98 13 e3 f4  or  %o7, 0x3f4, %o4
a00b2d8c:  d6 0a a0 56  ldub  [ %o2 + 0x56 ], %o3
a00b2d90:  80 a2 e0 01  cmp  %o3, 1
a00b2d94:  22 80 00 60  be,a   0xa00b2f14
a00b2d98:  92 14 22 90  or  %l0, 0x290, %o1
a00b2d9c:  9a 13 e3 f4  or  %o7, 0x3f4, %o5
a00b2da0:  d0 13 60 0e  lduh  [ %o5 + 0xe ], %o0
a00b2da4:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00b2da8:  92 0a 00 01  and  %o0, %g1, %o1
a00b2dac:  97 2a 60 10  sll  %o1, 0x10, %o3
a00b2db0:  80 a2 e0 00  cmp  %o3, 0
a00b2db4:  02 80 00 a2  be  0xa00b303c
a00b2db8:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a00b2dbc:  96 14 22 90  or  %l0, 0x290, %o3
a00b2dc0:  d8 02 e1 dc  ld  [ %o3 + 0x1dc ], %o4
a00b2dc4:  80 a3 20 00  cmp  %o4, 0
a00b2dc8:  06 80 00 07  bl  0xa00b2de4
a00b2dcc:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00b2dd0:  d0 13 e3 f4  lduh  [ %o7 + 0x3f4 ], %o0
a00b2dd4:  b0 0a 3e ff  and  %o0, -257, %i0
a00b2dd8:  f0 33 e3 f4  sth  %i0, [ %o7 + 0x3f4 ]
a00b2ddc:  9e 10 20 01  mov  1, %o7
a00b2de0:  de 2a e1 e4  stb  %o7, [ %o3 + 0x1e4 ]
a00b2de4:  80 8b 00 01  btst  %o4, %g1
a00b2de8:  12 80 00 06  bne  0xa00b2e00
a00b2dec:  de 12 63 f4  lduh  [ %o1 + 0x3f4 ], %o7
a00b2df0:  9a 10 20 01  mov  1, %o5
a00b2df4:  98 0b fe ff  and  %o7, -257, %o4
a00b2df8:  da 2a e1 e5  stb  %o5, [ %o3 + 0x1e5 ]
a00b2dfc:  d8 32 63 f4  sth  %o4, [ %o1 + 0x3f4 ]
a00b2e00:  40 00 9f 53  call  0xa00dab4c
a00b2e04:  d0 0a a0 56  ldub  [ %o2 + 0x56 ], %o0
a00b2e08:  10 80 00 8e  b  0xa00b3040
a00b2e0c:  94 14 22 90  or  %l0, 0x290, %o2
a00b2e10:  02 80 00 0c  be  0xa00b2e40
a00b2e14:  82 08 60 ff  and  %g1, 0xff, %g1
a00b2e18:  80 a0 60 01  cmp  %g1, 1
a00b2e1c:  02 80 00 0d  be  0xa00b2e50
a00b2e20:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00b2e24:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00b2e28:  d2 0b 60 8e  ldub  [ %o5 + 0x8e ], %o1	! 0xa802b08e
a00b2e2c:  90 12 60 02  or  %o1, 2, %o0
a00b2e30:  d0 2b 60 8e  stb  %o0, [ %o5 + 0x8e ]
a00b2e34:  7f ff 78 69  call  0xa0090fd8
a00b2e38:  81 e8 00 00  restore
a00b2e3c:  82 08 60 ff  and  %g1, 0xff, %g1
a00b2e40:  80 a0 60 01  cmp  %g1, 1
a00b2e44:  12 bf ff f8  bne  0xa00b2e24
a00b2e48:  c0 2e 21 e4  clrb  [ %i0 + 0x1e4 ]
a00b2e4c:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00b2e50:  d2 0b 60 8e  ldub  [ %o5 + 0x8e ], %o1	! 0xa802b08e
a00b2e54:  90 12 60 02  or  %o1, 2, %o0
a00b2e58:  c0 2e 21 e5  clrb  [ %i0 + 0x1e5 ]
a00b2e5c:  d0 2b 60 8e  stb  %o0, [ %o5 + 0x8e ]
a00b2e60:  7f ff 78 5e  call  0xa0090fd8
a00b2e64:  81 e8 00 00  restore
a00b2e68:  80 a3 20 03  cmp  %o4, 3
a00b2e6c:  02 80 00 3c  be  0xa00b2f5c
a00b2e70:  92 14 22 90  or  %l0, 0x290, %o1
a00b2e74:  d4 0a 61 e2  ldub  [ %o1 + 0x1e2 ], %o2
a00b2e78:  80 a2 a0 02  cmp  %o2, 2
a00b2e7c:  08 80 00 05  bleu  0xa00b2e90
a00b2e80:  c2 0a e0 55  ldub  [ %o3 + 0x55 ], %g1
a00b2e84:  80 a3 20 02  cmp  %o4, 2
a00b2e88:  02 80 00 36  be  0xa00b2f60
a00b2e8c:  96 14 22 90  or  %l0, 0x290, %o3
a00b2e90:  80 a0 60 02  cmp  %g1, 2
a00b2e94:  02 80 00 50  be  0xa00b2fd4
a00b2e98:  96 10 20 01  mov  1, %o3
a00b2e9c:  92 22 c0 01  sub  %o3, %g1, %o1
a00b2ea0:  b0 13 e3 f4  or  %o7, 0x3f4, %i0
a00b2ea4:  d8 16 20 0e  lduh  [ %i0 + 0xe ], %o4
a00b2ea8:  90 0a 60 ff  and  %o1, 0xff, %o0
a00b2eac:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00b2eb0:  9b 2a 20 0f  sll  %o0, 0xf, %o5
a00b2eb4:  94 2b 00 01  andn  %o4, %g1, %o2
a00b2eb8:  98 12 80 0d  or  %o2, %o5, %o4
a00b2ebc:  d8 36 20 0e  sth  %o4, [ %i0 + 0xe ]
a00b2ec0:  11 2a 00 97  sethi  %hi(0xa8025c00), %o0
a00b2ec4:  10 bf ff a6  b  0xa00b2d5c
a00b2ec8:  d2 2a 20 55  stb  %o1, [ %o0 + 0x55 ]	! 0xa8025c55
a00b2ecc:  94 13 e3 f4  or  %o7, 0x3f4, %o2
a00b2ed0:  d8 0a a0 3f  ldub  [ %o2 + 0x3f ], %o4
a00b2ed4:  80 a3 20 00  cmp  %o4, 0
a00b2ed8:  32 bf ff 9d  bne,a   0xa00b2d4c
a00b2edc:  90 13 e3 f4  or  %o7, 0x3f4, %o0
a00b2ee0:  d8 06 21 dc  ld  [ %i0 + 0x1dc ], %o4
a00b2ee4:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00b2ee8:  d6 12 a0 0e  lduh  [ %o2 + 0xe ], %o3
a00b2eec:  92 13 00 01  or  %o4, %g1, %o1
a00b2ef0:  11 3f ff e0  sethi  %hi(0xffff8000), %o0
a00b2ef4:  82 2a c0 08  andn  %o3, %o0, %g1
a00b2ef8:  1b 10 00 00  sethi  %hi(0x40000000), %o5
a00b2efc:  c2 32 a0 0e  sth  %g1, [ %o2 + 0xe ]
a00b2f00:  90 12 40 0d  or  %o1, %o5, %o0
a00b2f04:  96 10 20 01  mov  1, %o3
a00b2f08:  d0 26 21 dc  st  %o0, [ %i0 + 0x1dc ]
a00b2f0c:  10 bf ff 94  b  0xa00b2d5c
a00b2f10:  d6 2e 21 ee  stb  %o3, [ %i0 + 0x1ee ]
a00b2f14:  19 30 00 00  sethi  %hi(0xc0000000), %o4
a00b2f18:  da 02 61 dc  ld  [ %o1 + 0x1dc ], %o5
a00b2f1c:  90 0b 40 0c  and  %o5, %o4, %o0
a00b2f20:  80 a2 00 0c  cmp  %o0, %o4
a00b2f24:  32 bf ff 9f  bne,a   0xa00b2da0
a00b2f28:  9a 13 e3 f4  or  %o7, 0x3f4, %o5
a00b2f2c:  98 13 e3 f4  or  %o7, 0x3f4, %o4
a00b2f30:  c2 13 20 0e  lduh  [ %o4 + 0xe ], %g1
a00b2f34:  1b 3f ff e0  sethi  %hi(0xffff8000), %o5
a00b2f38:  90 08 40 0d  and  %g1, %o5, %o0
a00b2f3c:  83 2a 20 10  sll  %o0, 0x10, %g1
a00b2f40:  f0 13 20 12  lduh  [ %o4 + 0x12 ], %i0
a00b2f44:  f0 2a 61 e3  stb  %i0, [ %o1 + 0x1e3 ]
a00b2f48:  80 a0 60 00  cmp  %g1, 0
a00b2f4c:  12 80 00 37  bne  0xa00b3028
a00b2f50:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a00b2f54:  10 bf ff 92  b  0xa00b2d9c
a00b2f58:  c0 2a 61 e7  clrb  [ %o1 + 0x1e7 ]
a00b2f5c:  96 14 22 90  or  %l0, 0x290, %o3
a00b2f60:  e0 12 20 0e  lduh  [ %o0 + 0xe ], %l0
a00b2f64:  1b 3f ff e0  sethi  %hi(0xffff8000), %o5
a00b2f68:  d2 0a e1 e2  ldub  [ %o3 + 0x1e2 ], %o1
a00b2f6c:  9e 14 00 0d  or  %l0, %o5, %o7
a00b2f70:  de 32 20 0e  sth  %o7, [ %o0 + 0xe ]
a00b2f74:  80 a2 60 02  cmp  %o1, 2
a00b2f78:  08 80 00 14  bleu  0xa00b2fc8
a00b2f7c:  c0 2a 20 3f  clrb  [ %o0 + 0x3f ]
a00b2f80:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a00b2f84:  d0 0b 20 56  ldub  [ %o4 + 0x56 ], %o0	! 0xa8025c56
a00b2f88:  92 10 20 03  mov  3, %o1
a00b2f8c:  7f ff fb 06  call  0xa00b1ba4
a00b2f90:  b0 10 21 0a  mov  0x10a, %i0
a00b2f94:  7f ff 78 03  call  0xa0090fa0
a00b2f98:  81 e8 00 00  restore
a00b2f9c:  d0 13 20 0e  lduh  [ %o4 + 0xe ], %o0
a00b2fa0:  1b 3f ff e0  sethi  %hi(0xffff8000), %o5
a00b2fa4:  b0 0a 00 0d  and  %o0, %o5, %i0
a00b2fa8:  d2 13 20 10  lduh  [ %o4 + 0x10 ], %o1
a00b2fac:  83 2e 20 10  sll  %i0, 0x10, %g1
a00b2fb0:  d2 2a e1 e2  stb  %o1, [ %o3 + 0x1e2 ]
a00b2fb4:  80 a0 60 00  cmp  %g1, 0
a00b2fb8:  12 80 00 16  bne  0xa00b3010
a00b2fbc:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a00b2fc0:  10 bf ff 73  b  0xa00b2d8c
a00b2fc4:  c0 2a e1 e6  clrb  [ %o3 + 0x1e6 ]
a00b2fc8:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a00b2fcc:  10 bf ff f0  b  0xa00b2f8c
a00b2fd0:  d0 08 60 56  ldub  [ %g1 + 0x56 ], %o0	! 0xa8025c56
a00b2fd4:  90 14 22 90  or  %l0, 0x290, %o0
a00b2fd8:  d4 02 21 dc  ld  [ %o0 + 0x1dc ], %o2
a00b2fdc:  92 13 e3 f4  or  %o7, 0x3f4, %o1
a00b2fe0:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00b2fe4:  f0 12 60 0e  lduh  [ %o1 + 0xe ], %i0
a00b2fe8:  98 12 80 01  or  %o2, %g1, %o4
a00b2fec:  1b 3f ff e0  sethi  %hi(0xffff8000), %o5
a00b2ff0:  82 2e 00 0d  andn  %i0, %o5, %g1
a00b2ff4:  17 10 00 00  sethi  %hi(0x40000000), %o3
a00b2ff8:  c2 32 60 0e  sth  %g1, [ %o1 + 0xe ]
a00b2ffc:  94 13 00 0b  or  %o4, %o3, %o2
a00b3000:  b0 10 20 01  mov  1, %i0
a00b3004:  d4 22 21 dc  st  %o2, [ %o0 + 0x1dc ]
a00b3008:  10 bf ff 55  b  0xa00b2d5c
a00b300c:  f0 2a 21 ee  stb  %i0, [ %o0 + 0x1ee ]
a00b3010:  f0 13 23 f4  lduh  [ %o4 + 0x3f4 ], %i0
a00b3014:  92 10 20 01  mov  1, %o1
a00b3018:  82 0e 3e ff  and  %i0, -257, %g1
a00b301c:  d2 2a e1 e6  stb  %o1, [ %o3 + 0x1e6 ]
a00b3020:  10 bf ff 5b  b  0xa00b2d8c
a00b3024:  c2 33 23 f4  sth  %g1, [ %o4 + 0x3f4 ]
a00b3028:  d8 13 63 f4  lduh  [ %o5 + 0x3f4 ], %o4
a00b302c:  b0 0b 3e ff  and  %o4, -257, %i0
a00b3030:  d6 2a 61 e7  stb  %o3, [ %o1 + 0x1e7 ]
a00b3034:  10 bf ff 5a  b  0xa00b2d9c
a00b3038:  f0 33 63 f4  sth  %i0, [ %o5 + 0x3f4 ]
a00b303c:  94 14 22 90  or  %l0, 0x290, %o2
a00b3040:  d8 02 a1 dc  ld  [ %o2 + 0x1dc ], %o4
a00b3044:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a00b3048:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00b304c:  90 13 00 0d  or  %o4, %o5, %o0
a00b3050:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00b3054:  f0 0c 20 8e  ldub  [ %l0 + 0x8e ], %i0
a00b3058:  92 12 00 01  or  %o0, %g1, %o1
a00b305c:  96 16 20 02  or  %i0, 2, %o3
a00b3060:  d2 22 a1 dc  st  %o1, [ %o2 + 0x1dc ]
a00b3064:  d6 2c 20 8e  stb  %o3, [ %l0 + 0x8e ]
a00b3068:  81 c7 e0 08  ret
a00b306c:  81 e8 00 00  restore
