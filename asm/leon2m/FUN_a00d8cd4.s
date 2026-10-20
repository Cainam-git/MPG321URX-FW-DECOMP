# leon2m FUN_a00d8cd4 0xa00d8cd4-0xa00d8ffc (808 bytes)
a00d8cd4:  9d e3 bf 98  save  %sp, -104, %sp
a00d8cd8:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00d8cdc:  82 14 62 90  or  %l1, 0x290, %g1	! 0xa802d290
a00d8ce0:  e0 08 60 09  ldub  [ %g1 + 9 ], %l0
a00d8ce4:  80 a4 20 64  cmp  %l0, 0x64
a00d8ce8:  38 80 00 02  bgu,a   0xa00d8cf0
a00d8cec:  a0 10 20 64  mov  0x64, %l0
a00d8cf0:  e0 28 60 09  stb  %l0, [ %g1 + 9 ]
a00d8cf4:  40 01 cc 1f  call  0xa014bd70
a00d8cf8:  90 10 20 00  clr  %o0
a00d8cfc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d8d00:  80 a2 20 01  cmp  %o0, 1
a00d8d04:  02 80 00 5b  be  0xa00d8e70
a00d8d08:  b0 10 20 64  mov  0x64, %i0
a00d8d0c:  40 01 aa f4  call  0xa01438dc
a00d8d10:  90 10 20 00  clr  %o0
a00d8d14:  82 0a 20 ff  and  %o0, 0xff, %g1
a00d8d18:  80 a0 60 01  cmp  %g1, 1
a00d8d1c:  02 80 00 47  be  0xa00d8e38
a00d8d20:  92 14 62 90  or  %l1, 0x290, %o1
a00d8d24:  da 02 60 b0  ld  [ %o1 + 0xb0 ], %o5
a00d8d28:  80 a3 60 00  cmp  %o5, 0
a00d8d2c:  12 80 00 8e  bne  0xa00d8f64
a00d8d30:  92 10 20 01  mov  1, %o1
a00d8d34:  96 14 62 90  or  %l1, 0x290, %o3
a00d8d38:  c2 02 e1 d4  ld  [ %o3 + 0x1d4 ], %g1
a00d8d3c:  80 88 60 40  btst  0x40, %g1
a00d8d40:  02 80 00 0a  be  0xa00d8d68
a00d8d44:  98 14 62 90  or  %l1, 0x290, %o4
a00d8d48:  da 02 e0 a8  ld  [ %o3 + 0xa8 ], %o5
a00d8d4c:  80 8b 68 00  btst  0x800, %o5
a00d8d50:  22 80 00 07  be,a   0xa00d8d6c
a00d8d54:  d6 03 20 a8  ld  [ %o4 + 0xa8 ], %o3
a00d8d58:  d2 0a e1 81  ldub  [ %o3 + 0x181 ], %o1
a00d8d5c:  80 a2 60 07  cmp  %o1, 7
a00d8d60:  02 80 00 90  be  0xa00d8fa0
a00d8d64:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00d8d68:  d6 03 20 a8  ld  [ %o4 + 0xa8 ], %o3
a00d8d6c:  80 8a e8 00  btst  0x800, %o3
a00d8d70:  12 80 00 50  bne  0xa00d8eb0
a00d8d74:  9a 10 00 10  mov  %l0, %o5
a00d8d78:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00d8d7c:  80 a3 60 45  cmp  %o5, 0x45
a00d8d80:  08 80 00 70  bleu  0xa00d8f40
a00d8d84:  82 5b 62 f1  smul  %o5, 0x2f1, %g1
a00d8d88:  99 2b 60 03  sll  %o5, 3, %o4
a00d8d8c:  82 03 00 0d  add  %o4, %o5, %g1
a00d8d90:  15 3f ff f6  sethi  %hi(0xffffd800), %o2
a00d8d94:  a1 28 60 04  sll  %g1, 4, %l0
a00d8d98:  9a 12 a0 af  or  %o2, 0xaf, %o5
a00d8d9c:  13 22 22 22  sethi  %hi(0x88888800), %o1
a00d8da0:  b0 04 00 0d  add  %l0, %o5, %i0
a00d8da4:  90 12 60 89  or  %o1, 0x89, %o0
a00d8da8:  80 56 00 08  umul  %i0, %o0, %g0
a00d8dac:  9f 40 00 00  rd  %y, %o7
a00d8db0:  97 33 e0 04  srl  %o7, 4, %o3
a00d8db4:  82 02 e3 6f  add  %o3, 0x36f, %g1
a00d8db8:  99 28 60 10  sll  %g1, 0x10, %o4
a00d8dbc:  95 33 20 10  srl  %o4, 0x10, %o2
a00d8dc0:  1b 3f ff f3  sethi  %hi(0xffffcc00), %o5
a00d8dc4:  92 5a a0 64  smul  %o2, 0x64, %o1
a00d8dc8:  a0 13 62 c8  or  %o5, 0x2c8, %l0
a00d8dcc:  11 24 87 d9  sethi  %hi(0x921f6400), %o0
a00d8dd0:  96 02 40 10  add  %o1, %l0, %o3
a00d8dd4:  b0 12 20 bf  or  %o0, 0xbf, %i0
a00d8dd8:  80 5a c0 18  smul  %o3, %i0, %g0
a00d8ddc:  9f 40 00 00  rd  %y, %o7
a00d8de0:  82 03 c0 0b  add  %o7, %o3, %g1
a00d8de4:  99 3a e0 1f  sra  %o3, 0x1f, %o4
a00d8de8:  95 38 60 09  sra  %g1, 9, %o2
a00d8dec:  9a 22 80 0c  sub  %o2, %o4, %o5
a00d8df0:  b0 0b 60 ff  and  %o5, 0xff, %i0
a00d8df4:  40 01 cb df  call  0xa014bd70
a00d8df8:  90 10 20 00  clr  %o0
a00d8dfc:  96 0a 20 ff  and  %o0, 0xff, %o3
a00d8e00:  80 a2 e0 01  cmp  %o3, 1
a00d8e04:  12 80 00 21  bne  0xa00d8e88
a00d8e08:  01 00 00 00  nop
a00d8e0c:  90 14 62 90  or  %l1, 0x290, %o0
a00d8e10:  de 02 20 ac  ld  [ %o0 + 0xac ], %o7
a00d8e14:  23 00 03 00  sethi  %hi(0xc0000), %l1
a00d8e18:  80 8b c0 11  btst  %o7, %l1
a00d8e1c:  12 80 00 21  bne  0xa00d8ea0
a00d8e20:  90 10 20 00  clr  %o0
a00d8e24:  40 01 35 c6  call  0xa012653c
a00d8e28:  90 10 20 01  mov  1, %o0
a00d8e2c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d8e30:  40 01 cc 4d  call  0xa014bf64
a00d8e34:  81 e8 00 00  restore
a00d8e38:  40 01 cb 0c  call  0xa014ba68
a00d8e3c:  01 00 00 00  nop
a00d8e40:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d8e44:  80 a2 20 02  cmp  %o0, 2
a00d8e48:  02 80 00 0a  be  0xa00d8e70
a00d8e4c:  b0 10 20 64  mov  0x64, %i0
a00d8e50:  04 80 00 63  ble  0xa00d8fdc
a00d8e54:  80 a2 20 01  cmp  %o0, 1
a00d8e58:  80 a2 20 03  cmp  %o0, 3
a00d8e5c:  02 80 00 05  be  0xa00d8e70
a00d8e60:  80 a2 20 04  cmp  %o0, 4
a00d8e64:  12 bf ff b0  bne  0xa00d8d24
a00d8e68:  92 14 62 90  or  %l1, 0x290, %o1
a00d8e6c:  b0 10 20 64  mov  0x64, %i0
a00d8e70:  40 01 cb c0  call  0xa014bd70
a00d8e74:  90 10 20 00  clr  %o0
a00d8e78:  96 0a 20 ff  and  %o0, 0xff, %o3
a00d8e7c:  80 a2 e0 01  cmp  %o3, 1
a00d8e80:  02 bf ff e4  be  0xa00d8e10
a00d8e84:  90 14 62 90  or  %l1, 0x290, %o0
a00d8e88:  40 01 aa 95  call  0xa01438dc
a00d8e8c:  90 10 20 00  clr  %o0
a00d8e90:  82 0a 20 ff  and  %o0, 0xff, %g1
a00d8e94:  80 a0 60 01  cmp  %g1, 1
a00d8e98:  02 80 00 19  be  0xa00d8efc
a00d8e9c:  90 10 20 02  mov  2, %o0
a00d8ea0:  40 01 35 a7  call  0xa012653c
a00d8ea4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d8ea8:  40 01 cc 2f  call  0xa014bf64
a00d8eac:  81 e8 00 00  restore
a00d8eb0:  de 0b 21 81  ldub  [ %o4 + 0x181 ], %o7
a00d8eb4:  80 a3 e0 07  cmp  %o7, 7
a00d8eb8:  12 bf ff b1  bne  0xa00d8d7c
a00d8ebc:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00d8ec0:  82 0c 20 ff  and  %l0, 0xff, %g1
a00d8ec4:  80 a0 60 45  cmp  %g1, 0x45
a00d8ec8:  28 80 00 1e  bleu,a   0xa00d8f40
a00d8ecc:  82 58 60 92  smul  %g1, 0x92, %g1
a00d8ed0:  19 3f ff cc  sethi  %hi(0xffff3000), %o4
a00d8ed4:  82 58 62 ef  smul  %g1, 0x2ef, %g1
a00d8ed8:  94 13 22 b5  or  %o4, 0x2b5, %o2
a00d8edc:  21 22 22 22  sethi  %hi(0x88888800), %l0
a00d8ee0:  92 00 40 0a  add  %g1, %o2, %o1
a00d8ee4:  9a 14 20 89  or  %l0, 0x89, %o5
a00d8ee8:  80 52 40 0d  umul  %o1, %o5, %g0
a00d8eec:  91 40 00 00  rd  %y, %o0
a00d8ef0:  b1 32 20 04  srl  %o0, 4, %i0
a00d8ef4:  10 bf ff b1  b  0xa00d8db8
a00d8ef8:  82 06 21 10  add  %i0, 0x110, %g1
a00d8efc:  40 01 ca db  call  0xa014ba68
a00d8f00:  01 00 00 00  nop
a00d8f04:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d8f08:  80 a2 20 02  cmp  %o0, 2
a00d8f0c:  22 bf ff c1  be,a   0xa00d8e10
a00d8f10:  90 14 62 90  or  %l1, 0x290, %o0
a00d8f14:  04 80 00 36  ble  0xa00d8fec
a00d8f18:  80 a2 20 01  cmp  %o0, 1
a00d8f1c:  80 a2 20 03  cmp  %o0, 3
a00d8f20:  02 bf ff bb  be  0xa00d8e0c
a00d8f24:  80 a2 20 04  cmp  %o0, 4
a00d8f28:  32 bf ff de  bne,a   0xa00d8ea0
a00d8f2c:  90 10 20 02  mov  2, %o0
a00d8f30:  10 bf ff b8  b  0xa00d8e10
a00d8f34:  90 14 62 90  or  %l1, 0x290, %o0
a00d8f38:  94 03 3f 82  add  %o4, -126, %o2
a00d8f3c:  82 5b 40 0a  smul  %o5, %o2, %g1
a00d8f40:  a0 00 60 23  add  %g1, 0x23, %l0
a00d8f44:  13 3a 83 a8  sethi  %hi(0xea0ea000), %o1
a00d8f48:  b1 34 20 01  srl  %l0, 1, %i0
a00d8f4c:  90 12 60 eb  or  %o1, 0xeb, %o0
a00d8f50:  80 56 00 08  umul  %i0, %o0, %g0
a00d8f54:  9f 40 00 00  rd  %y, %o7
a00d8f58:  97 33 e0 05  srl  %o7, 5, %o3
a00d8f5c:  10 bf ff 97  b  0xa00d8db8
a00d8f60:  82 02 e0 7e  add  %o3, 0x7e, %g1
a00d8f64:  40 01 b1 bf  call  0xa0145660
a00d8f68:  90 10 20 00  clr  %o0
a00d8f6c:  91 2a 20 10  sll  %o0, 0x10, %o0
a00d8f70:  31 33 33 33  sethi  %hi(0xcccccc00), %i0
a00d8f74:  99 32 20 10  srl  %o0, 0x10, %o4
a00d8f78:  9e 16 20 cd  or  %i0, 0xcd, %o7
a00d8f7c:  80 53 00 0f  umul  %o4, %o7, %g0
a00d8f80:  97 40 00 00  rd  %y, %o3
a00d8f84:  95 2a e0 0d  sll  %o3, 0xd, %o2
a00d8f88:  7f fe b9 34  call  0xa0087458
a00d8f8c:  91 32 a0 10  srl  %o2, 0x10, %o0
a00d8f90:  80 a2 20 00  cmp  %o0, 0
a00d8f94:  02 bf ff 68  be  0xa00d8d34
a00d8f98:  b0 10 20 64  mov  0x64, %i0
a00d8f9c:  30 bf ff b5  b,a   0xa00d8e70
a00d8fa0:  80 a3 60 45  cmp  %o5, 0x45
a00d8fa4:  08 bf ff e5  bleu  0xa00d8f38
a00d8fa8:  d8 12 e1 da  lduh  [ %o3 + 0x1da ], %o4
a00d8fac:  a0 10 23 ff  mov  0x3ff, %l0
a00d8fb0:  82 24 00 0c  sub  %l0, %o4, %g1
a00d8fb4:  92 03 7f ba  add  %o5, -70, %o1
a00d8fb8:  9a 5a 40 01  smul  %o1, %g1, %o5
a00d8fbc:  11 22 22 22  sethi  %hi(0x88888800), %o0
a00d8fc0:  9e 03 60 0f  add  %o5, 0xf, %o7
a00d8fc4:  b0 12 20 89  or  %o0, 0x89, %i0
a00d8fc8:  80 53 c0 18  umul  %o7, %i0, %g0
a00d8fcc:  97 40 00 00  rd  %y, %o3
a00d8fd0:  95 32 e0 04  srl  %o3, 4, %o2
a00d8fd4:  10 bf ff 79  b  0xa00d8db8
a00d8fd8:  82 02 80 0c  add  %o2, %o4, %g1
a00d8fdc:  12 bf ff 52  bne  0xa00d8d24
a00d8fe0:  92 14 62 90  or  %l1, 0x290, %o1
a00d8fe4:  10 bf ff a3  b  0xa00d8e70
a00d8fe8:  b0 10 20 64  mov  0x64, %i0
a00d8fec:  32 bf ff ad  bne,a   0xa00d8ea0
a00d8ff0:  90 10 20 02  mov  2, %o0
a00d8ff4:  10 bf ff 87  b  0xa00d8e10
a00d8ff8:  90 14 62 90  or  %l1, 0x290, %o0
