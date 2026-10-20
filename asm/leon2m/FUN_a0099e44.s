# leon2m FUN_a0099e44 0xa0099e44-0xa0099f20 (220 bytes)
a0099e44:  9d e3 bf 98  save  %sp, -104, %sp
a0099e48:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0099e4c:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a0099e50:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1
a0099e54:  80 a0 60 b8  cmp  %g1, 0xb8
a0099e58:  02 80 00 29  be  0xa0099efc
a0099e5c:  98 14 a2 90  or  %l2, 0x290, %o4
a0099e60:  80 a0 60 b9  cmp  %g1, 0xb9
a0099e64:  22 80 00 2b  be,a   0xa0099f10
a0099e68:  d4 03 21 dc  ld  [ %o4 + 0x1dc ], %o2
a0099e6c:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0099e70:  d4 0c 20 56  ldub  [ %l0 + 0x56 ], %o2	! 0xa8025c56
a0099e74:  92 02 a0 48  add  %o2, 0x48, %o1
a0099e78:  40 00 3d 51  call  0xa00a93bc
a0099e7c:  90 0a 60 ff  and  %o1, 0xff, %o0
a0099e80:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a0099e84:  94 10 20 00  clr  %o2
a0099e88:  40 00 38 ad  call  0xa00a813c
a0099e8c:  90 10 20 01  mov  1, %o0
a0099e90:  a0 14 a2 90  or  %l2, 0x290, %l0
a0099e94:  d8 04 21 dc  ld  [ %l0 + 0x1dc ], %o4
a0099e98:  91 33 20 1d  srl  %o4, 0x1d, %o0
a0099e9c:  9a 10 20 34  mov  0x34, %o5
a0099ea0:  da 24 63 ec  st  %o5, [ %l1 + 0x3ec ]
a0099ea4:  90 0a 20 01  and  %o0, 1, %o0
a0099ea8:  40 00 3d ea  call  0xa00a9650
a0099eac:  92 10 20 00  clr  %o1
a0099eb0:  c2 04 21 dc  ld  [ %l0 + 0x1dc ], %g1
a0099eb4:  a5 30 60 1d  srl  %g1, 0x1d, %l2
a0099eb8:  94 10 20 01  mov  1, %o2
a0099ebc:  92 0c a0 01  and  %l2, 1, %o1
a0099ec0:  40 00 38 9f  call  0xa00a813c
a0099ec4:  90 10 20 01  mov  1, %o0
a0099ec8:  e0 04 63 ec  ld  [ %l1 + 0x3ec ], %l0
a0099ecc:  9e 04 3f cc  add  %l0, -52, %o7
a0099ed0:  90 0b e0 ff  and  %o7, 0xff, %o0
a0099ed4:  40 00 3c 4e  call  0xa00a900c
a0099ed8:  92 10 20 01  mov  1, %o1
a0099edc:  90 10 20 01  mov  1, %o0
a0099ee0:  40 00 3d 62  call  0xa00a9468
a0099ee4:  92 10 20 02  mov  2, %o1
a0099ee8:  90 10 20 00  clr  %o0
a0099eec:  40 00 65 7a  call  0xa00b34d4
a0099ef0:  92 10 20 01  mov  1, %o1
a0099ef4:  40 01 02 fd  call  0xa00daae8
a0099ef8:  81 e8 00 00  restore
a0099efc:  da 03 21 dc  ld  [ %o4 + 0x1dc ], %o5
a0099f00:  11 08 00 00  sethi  %hi(0x20000000), %o0
a0099f04:  82 2b 40 08  andn  %o5, %o0, %g1
a0099f08:  10 bf ff d9  b  0xa0099e6c
a0099f0c:  c2 23 21 dc  st  %g1, [ %o4 + 0x1dc ]
a0099f10:  17 08 00 00  sethi  %hi(0x20000000), %o3
a0099f14:  92 12 80 0b  or  %o2, %o3, %o1
a0099f18:  10 bf ff d5  b  0xa0099e6c
a0099f1c:  d2 23 21 dc  st  %o1, [ %o4 + 0x1dc ]
