# leon2m FUN_a0104d18 0xa0104d18-0xa0104e50 (312 bytes)
a0104d18:  9d e3 bf 98  save  %sp, -104, %sp
a0104d1c:  35 33 c0 4a  sethi  %hi(0xcf012800), %i2
a0104d20:  a0 16 a0 90  or  %i2, 0x90, %l0	! 0xcf012890
a0104d24:  90 16 a1 90  or  %i2, 0x190, %o0
a0104d28:  ba 06 3f e7  add  %i0, -25, %i5
a0104d2c:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a0104d30:  b8 16 a0 98  or  %i2, 0x98, %i4
a0104d34:  98 16 a0 9c  or  %i2, 0x9c, %o4
a0104d38:  9e 16 a1 98  or  %i2, 0x198, %o7
a0104d3c:  96 16 a1 9c  or  %i2, 0x19c, %o3
a0104d40:  b5 2f 60 10  sll  %i5, 0x10, %i2
a0104d44:  da 00 62 a4  ld  [ %g1 + 0x2a4 ], %o5
a0104d48:  b6 06 7f fb  add  %i1, -5, %i3
a0104d4c:  83 2e e0 10  sll  %i3, 0x10, %g1
a0104d50:  bb 36 a0 10  srl  %i2, 0x10, %i5
a0104d54:  b5 30 60 10  srl  %g1, 0x10, %i2
a0104d58:  92 10 00 10  mov  %l0, %o1
a0104d5c:  94 10 00 08  mov  %o0, %o2
a0104d60:  80 a7 61 db  cmp  %i5, 0x1db
a0104d64:  08 80 00 03  bleu  0xa0104d70
a0104d68:  82 10 00 18  mov  %i0, %g1
a0104d6c:  82 10 20 64  mov  0x64, %g1
a0104d70:  83 28 60 10  sll  %g1, 0x10, %g1
a0104d74:  b1 30 60 10  srl  %g1, 0x10, %i0
a0104d78:  b6 10 25 dc  mov  0x5dc, %i3
a0104d7c:  83 3e e0 1f  sra  %i3, 0x1f, %g1
a0104d80:  81 80 60 00  mov  %g1, %y
a0104d84:  01 00 00 00  nop
a0104d88:  01 00 00 00  nop
a0104d8c:  01 00 00 00  nop
a0104d90:  ba 7e c0 18  sdiv  %i3, %i0, %i5
a0104d94:  b6 0f 60 ff  and  %i5, 0xff, %i3
a0104d98:  3b 00 00 04  sethi  %hi(0x1000), %i5
a0104d9c:  82 17 63 83  or  %i5, 0x383, %g1	! 0x1383
a0104da0:  80 a6 80 01  cmp  %i2, %g1
a0104da4:  38 80 00 02  bgu,a   0xa0104dac
a0104da8:  b2 10 20 96  mov  0x96, %i1
a0104dac:  bb 2e 60 10  sll  %i1, 0x10, %i5
a0104db0:  83 37 60 10  srl  %i5, 0x10, %g1
a0104db4:  b4 58 40 18  smul  %g1, %i0, %i2
a0104db8:  b3 2e a0 0f  sll  %i2, 0xf, %i1
a0104dbc:  31 00 8f 2a  sethi  %hi(0x23ca800), %i0
a0104dc0:  83 36 60 06  srl  %i1, 6, %g1
a0104dc4:  ba 16 21 8d  or  %i0, 0x18d, %i5
a0104dc8:  80 50 40 1d  umul  %g1, %i5, %g0
a0104dcc:  b5 40 00 00  rd  %y, %i2
a0104dd0:  b3 36 a0 0b  srl  %i2, 0xb, %i1
a0104dd4:  f6 27 00 00  st  %i3, [ %i4 ]
a0104dd8:  82 0e 60 ff  and  %i1, 0xff, %g1
a0104ddc:  c2 23 00 00  st  %g1, [ %o4 ]
a0104de0:  f0 07 00 00  ld  [ %i4 ], %i0
a0104de4:  ba 16 20 80  or  %i0, 0x80, %i5
a0104de8:  fa 27 00 00  st  %i5, [ %i4 ]
a0104dec:  f6 23 c0 00  st  %i3, [ %o7 ]
a0104df0:  c2 22 c0 00  st  %g1, [ %o3 ]
a0104df4:  f4 03 c0 00  ld  [ %o7 ], %i2
a0104df8:  b2 16 a0 80  or  %i2, 0x80, %i1
a0104dfc:  f2 23 c0 00  st  %i1, [ %o7 ]
a0104e00:  f8 03 40 00  ld  [ %o5 ], %i4
a0104e04:  31 01 00 00  sethi  %hi(0x4000000), %i0
a0104e08:  80 8f 00 18  btst  %i4, %i0
a0104e0c:  02 80 00 09  be  0xa0104e30
a0104e10:  01 00 00 00  nop
a0104e14:  f2 04 00 00  ld  [ %l0 ], %i1
a0104e18:  b0 16 60 01  or  %i1, 1, %i0
a0104e1c:  f0 24 00 00  st  %i0, [ %l0 ]
a0104e20:  f8 02 00 00  ld  [ %o0 ], %i4
a0104e24:  b6 17 20 01  or  %i4, 1, %i3
a0104e28:  f6 22 00 00  st  %i3, [ %o0 ]
a0104e2c:  30 80 00 07  b,a   0xa0104e48
a0104e30:  f6 02 40 00  ld  [ %o1 ], %i3
a0104e34:  ba 0e ff fe  and  %i3, -2, %i5
a0104e38:  fa 22 40 00  st  %i5, [ %o1 ]
a0104e3c:  c2 02 80 00  ld  [ %o2 ], %g1
a0104e40:  b4 08 7f fe  and  %g1, -2, %i2
a0104e44:  f4 22 80 00  st  %i2, [ %o2 ]
a0104e48:  81 c7 e0 08  ret
a0104e4c:  81 e8 00 00  restore
