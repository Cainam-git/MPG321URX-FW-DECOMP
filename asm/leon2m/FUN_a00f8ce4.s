# leon2m FUN_a00f8ce4 0xa00f8ce4-0xa00f8dd4 (136 bytes)
a00f8ce4:  9d e3 bf 98  save  %sp, -104, %sp
a00f8ce8:  a3 2e 60 10  sll  %i1, 0x10, %l1
a00f8cec:  83 34 60 10  srl  %l1, 0x10, %g1
a00f8cf0:  80 a0 67 80  cmp  %g1, 0x780
a00f8cf4:  18 80 00 1f  bgu  0xa00f8d70
a00f8cf8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00f8cfc:  80 8e e0 ff  btst  0xff, %i3
a00f8d00:  02 80 00 05  be  0xa00f8d14
a00f8d04:  80 a4 20 07  cmp  %l0, 7
a00f8d08:  92 10 00 19  mov  %i1, %o1
a00f8d0c:  b2 10 00 1a  mov  %i2, %i1
a00f8d10:  b4 10 00 09  mov  %o1, %i2
a00f8d14:  18 80 00 2e  bgu  0xa00f8dcc
a00f8d18:  17 00 02 61  sethi  %hi(0x98400), %o3
a00f8d1c:  95 2c 20 02  sll  %l0, 2, %o2
a00f8d20:  9a 12 e3 bc  or  %o3, 0x3bc, %o5
a00f8d24:  d8 03 40 0a  ld  [ %o5 + %o2 ], %o4
a00f8d28:  81 c3 00 00  jmp  %o4
a00f8d2c:  01 00 00 00  nop
a00f8d30:  17 33 c0 25  sethi  %hi(0xcf009400), %o3
a00f8d34:  91 2e a0 10  sll  %i2, 0x10, %o0
a00f8d38:  98 0e a0 ff  and  %i2, 0xff, %o4
a00f8d3c:  92 12 e0 60  or  %o3, 0x60, %o1
a00f8d40:  d8 22 40 00  st  %o4, [ %o1 ]
a00f8d44:  83 32 20 18  srl  %o0, 0x18, %g1
a00f8d48:  b6 12 e0 64  or  %o3, 0x64, %i3
a00f8d4c:  c2 26 c0 00  st  %g1, [ %i3 ]
a00f8d50:  a3 2e 60 10  sll  %i1, 0x10, %l1
a00f8d54:  b0 12 e0 68  or  %o3, 0x68, %i0
a00f8d58:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00f8d5c:  f4 26 00 00  st  %i2, [ %i0 ]
a00f8d60:  9e 12 e0 6c  or  %o3, 0x6c, %o7
a00f8d64:  a1 34 60 18  srl  %l1, 0x18, %l0
a00f8d68:  e0 23 c0 00  st  %l0, [ %o7 ]
a00f8d6c:  30 80 00 18  b,a   0xa00f8dcc
a00f8d70:  40 00 6d 7c  call  0xa0114360
a00f8d74:  90 10 00 10  mov  %l0, %o0
a00f8d78:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f8d7c:  80 a2 00 10  cmp  %o0, %l0
a00f8d80:  12 bf ff e0  bne  0xa00f8d00
a00f8d84:  80 8e e0 ff  btst  0xff, %i3
a00f8d88:  40 00 6d a1  call  0xa011440c
a00f8d8c:  01 00 00 00  nop
a00f8d90:  80 8a 20 ff  btst  0xff, %o0
a00f8d94:  32 bf ff da  bne,a   0xa00f8cfc
a00f8d98:  b3 34 60 11  srl  %l1, 0x11, %i1
a00f8d9c:  10 bf ff d9  b  0xa00f8d00
a00f8da0:  80 8e e0 ff  btst  0xff, %i3
a00f8da4:  10 bf ff e4  b  0xa00f8d34
a00f8da8:  17 33 c0 26  sethi  %hi(0xcf009800), %o3
a00f8dac:  10 bf ff e2  b  0xa00f8d34
a00f8db0:  17 33 c0 27  sethi  %hi(0xcf009c00), %o3
a00f8db4:  10 bf ff e0  b  0xa00f8d34
a00f8db8:  17 33 c0 28  sethi  %hi(0xcf00a000), %o3
a00f8dbc:  10 bf ff de  b  0xa00f8d34
a00f8dc0:  17 33 c0 29  sethi  %hi(0xcf00a400), %o3
a00f8dc4:  10 bf ff dc  b  0xa00f8d34
a00f8dc8:  17 33 c0 24  sethi  %hi(0xcf009000), %o3
a00f8dcc:  81 c7 e0 08  ret
a00f8dd0:  81 e8 00 00  restore
