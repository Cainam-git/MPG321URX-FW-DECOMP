# leon2m FUN_a0135dc0 0xa0135dc0-0xa0136054 (660 bytes)
a0135dc0:  9d e3 bf 50  save  %sp, -176, %sp
a0135dc4:  ba 07 bf c8  add  %fp, -56, %i5
a0135dc8:  13 00 06 94  sethi  %hi(0x1a5000), %o1
a0135dcc:  94 10 20 30  mov  0x30, %o2
a0135dd0:  92 12 63 ac  or  %o1, 0x3ac, %o1
a0135dd4:  40 00 1a cf  call  0xa013c910
a0135dd8:  90 10 00 1d  mov  %i5, %o0
a0135ddc:  9a 10 20 00  clr  %o5
a0135de0:  98 10 20 00  clr  %o4
a0135de4:  d8 3f bf c0  std  %o4, [ %fp + -64 ]
a0135de8:  d8 3f bf b8  std  %o4, [ %fp + -72 ]
a0135dec:  b8 10 20 10  mov  0x10, %i4
a0135df0:  a6 10 20 00  clr  %l3
a0135df4:  9a 10 20 00  clr  %o5
a0135df8:  94 07 bf f8  add  %fp, -8, %o2
a0135dfc:  96 10 3f ff  mov  -1, %o3
a0135e00:  a1 2b 60 10  sll  %o5, 0x10, %l0
a0135e04:  82 03 60 01  add  %o5, 1, %g1
a0135e08:  9f 34 20 10  srl  %l0, 0x10, %o7
a0135e0c:  9a 02 80 0f  add  %o2, %o7, %o5
a0135e10:  91 28 60 10  sll  %g1, 0x10, %o0
a0135e14:  99 32 20 10  srl  %o0, 0x10, %o4
a0135e18:  d6 2b 7f d0  stb  %o3, [ %o5 + -48 ]
a0135e1c:  80 a3 20 2f  cmp  %o4, 0x2f
a0135e20:  08 bf ff f8  bleu  0xa0135e00
a0135e24:  9a 10 00 01  mov  %g1, %o5
a0135e28:  40 00 74 00  call  0xa0152e28
a0135e2c:  90 10 00 1d  mov  %i5, %o0
a0135e30:  aa 0a 20 ff  and  %o0, 0xff, %l5
a0135e34:  a8 10 00 08  mov  %o0, %l4
a0135e38:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a0135e3c:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a0135e40:  10 80 00 04  b  0xa0135e50
a0135e44:  a0 0d 60 ff  and  %l5, 0xff, %l0
a0135e48:  7f ff fc a5  call  0xa01350dc
a0135e4c:  01 00 00 00  nop
a0135e50:  d6 0c 63 97  ldub  [ %l1 + 0x397 ], %o3
a0135e54:  d8 0c a3 96  ldub  [ %l2 + 0x396 ], %o4
a0135e58:  94 0b 20 ff  and  %o4, 0xff, %o2
a0135e5c:  ae 0a e0 ff  and  %o3, 0xff, %l7
a0135e60:  ac 22 80 17  sub  %o2, %l7, %l6
a0135e64:  92 0a e0 ff  and  %o3, 0xff, %o1
a0135e68:  94 0b 20 ff  and  %o4, 0xff, %o2
a0135e6c:  80 a2 40 0a  cmp  %o1, %o2
a0135e70:  18 80 00 09  bgu  0xa0135e94
a0135e74:  82 05 a0 24  add  %l6, 0x24, %g1
a0135e78:  82 0a e0 ff  and  %o3, 0xff, %g1
a0135e7c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0135e80:  9a 23 40 01  sub  %o5, %g1, %o5
a0135e84:  80 a2 40 0a  cmp  %o1, %o2
a0135e88:  1a 80 00 03  bcc  0xa0135e94
a0135e8c:  82 10 20 24  mov  0x24, %g1
a0135e90:  82 03 7f ff  add  %o5, -1, %g1
a0135e94:  93 28 60 14  sll  %g1, 0x14, %o1
a0135e98:  97 32 60 10  srl  %o1, 0x10, %o3
a0135e9c:  80 a4 00 0b  cmp  %l0, %o3
a0135ea0:  18 bf ff ea  bgu  0xa0135e48
a0135ea4:  9a 0d 60 ff  and  %l5, 0xff, %o5
a0135ea8:  80 a3 60 00  cmp  %o5, 0
a0135eac:  08 80 00 46  bleu  0xa0135fc4
a0135eb0:  a0 10 20 00  clr  %l0
a0135eb4:  2b 2a 00 b6  sethi  %hi(0xa802d800), %l5
a0135eb8:  ae 15 62 6c  or  %l5, 0x26c, %l7	! 0xa802da6c
a0135ebc:  ac 10 00 0d  mov  %o5, %l6
a0135ec0:  aa 0d 20 ff  and  %l4, 0xff, %l5
a0135ec4:  90 07 bf b8  add  %fp, -72, %o0
a0135ec8:  de 0c 63 97  ldub  [ %l1 + 0x397 ], %o7
a0135ecc:  95 2c 20 10  sll  %l0, 0x10, %o2
a0135ed0:  83 32 a0 10  srl  %o2, 0x10, %g1
a0135ed4:  98 25 40 01  sub  %l5, %g1, %o4
a0135ed8:  80 a3 20 0f  cmp  %o4, 0xf
a0135edc:  24 80 00 02  ble,a   0xa0135ee4
a0135ee0:  b8 25 00 10  sub  %l4, %l0, %i4
a0135ee4:  92 07 40 01  add  %i5, %g1, %o1
a0135ee8:  94 10 20 00  clr  %o2
a0135eec:  9a 10 20 00  clr  %o5
a0135ef0:  97 2b 60 02  sll  %o5, 2, %o3
a0135ef4:  c2 0a 40 0b  ldub  [ %o1 + %o3 ], %g1
a0135ef8:  c2 22 00 0b  st  %g1, [ %o0 + %o3 ]
a0135efc:  98 02 c0 09  add  %o3, %o1, %o4
a0135f00:  da 0b 20 01  ldub  [ %o4 + 1 ], %o5
a0135f04:  83 28 60 08  sll  %g1, 8, %g1
a0135f08:  82 00 40 0d  add  %g1, %o5, %g1
a0135f0c:  c2 22 00 0b  st  %g1, [ %o0 + %o3 ]
a0135f10:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a0135f14:  83 28 60 08  sll  %g1, 8, %g1
a0135f18:  82 00 40 0d  add  %g1, %o5, %g1
a0135f1c:  c2 22 00 0b  st  %g1, [ %o0 + %o3 ]
a0135f20:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a0135f24:  99 28 60 08  sll  %g1, 8, %o4
a0135f28:  82 03 00 0d  add  %o4, %o5, %g1
a0135f2c:  94 02 a0 01  inc  %o2
a0135f30:  9a 0a a0 ff  and  %o2, 0xff, %o5
a0135f34:  80 a3 60 04  cmp  %o5, 4
a0135f38:  0a bf ff ee  bcs  0xa0135ef0
a0135f3c:  c2 22 00 0b  st  %g1, [ %o0 + %o3 ]
a0135f40:  96 0b e0 ff  and  %o7, 0xff, %o3
a0135f44:  83 2a e0 02  sll  %o3, 2, %g1
a0135f48:  94 00 40 0b  add  %g1, %o3, %o2
a0135f4c:  92 0f 20 ff  and  %i4, 0xff, %o1
a0135f50:  83 2a a0 02  sll  %o2, 2, %g1
a0135f54:  99 2a 60 10  sll  %o1, 0x10, %o4
a0135f58:  9b 2c e0 18  sll  %l3, 0x18, %o5
a0135f5c:  92 03 40 0c  add  %o5, %o4, %o1
a0135f60:  94 03 e0 01  add  %o7, 1, %o2
a0135f64:  9e 02 60 09  add  %o1, 9, %o7
a0135f68:  de 25 c0 01  st  %o7, [ %l7 + %g1 ]
a0135f6c:  92 00 40 17  add  %g1, %l7, %o1
a0135f70:  d6 07 bf c4  ld  [ %fp + -60 ], %o3
a0135f74:  9e 0a a0 ff  and  %o2, 0xff, %o7
a0135f78:  d6 22 60 10  st  %o3, [ %o1 + 0x10 ]
a0135f7c:  da 07 bf b8  ld  [ %fp + -72 ], %o5
a0135f80:  d8 07 bf bc  ld  [ %fp + -68 ], %o4
a0135f84:  d6 07 bf c0  ld  [ %fp + -64 ], %o3
a0135f88:  80 a3 e0 24  cmp  %o7, 0x24
a0135f8c:  da 22 60 04  st  %o5, [ %o1 + 4 ]
a0135f90:  d8 22 60 08  st  %o4, [ %o1 + 8 ]
a0135f94:  d6 22 60 0c  st  %o3, [ %o1 + 0xc ]
a0135f98:  18 80 00 03  bgu  0xa0135fa4
a0135f9c:  9e 10 20 00  clr  %o7
a0135fa0:  9e 10 00 0a  mov  %o2, %o7
a0135fa4:  94 04 20 10  add  %l0, 0x10, %o2
a0135fa8:  9b 2a a0 10  sll  %o2, 0x10, %o5
a0135fac:  a1 33 60 10  srl  %o5, 0x10, %l0
a0135fb0:  80 a5 80 10  cmp  %l6, %l0
a0135fb4:  a6 04 e0 01  inc  %l3
a0135fb8:  18 bf ff c5  bgu  0xa0135ecc
a0135fbc:  a0 10 00 0a  mov  %o2, %l0
a0135fc0:  de 2c 63 97  stb  %o7, [ %l1 + 0x397 ]
a0135fc4:  10 80 00 04  b  0xa0135fd4
a0135fc8:  c0 27 bf b4  clr  [ %fp + -76 ]
a0135fcc:  7f ff fc 44  call  0xa01350dc
a0135fd0:  01 00 00 00  nop
a0135fd4:  e8 0c 63 97  ldub  [ %l1 + 0x397 ], %l4
a0135fd8:  e6 0c a3 96  ldub  [ %l2 + 0x396 ], %l3
a0135fdc:  80 a5 00 13  cmp  %l4, %l3
a0135fe0:  12 bf ff fb  bne  0xa0135fcc
a0135fe4:  01 00 00 00  nop
a0135fe8:  a2 10 20 00  clr  %l1	! 0x0
a0135fec:  a0 10 20 00  clr  %l0
a0135ff0:  98 10 20 00  clr  %o4
a0135ff4:  83 2b 20 02  sll  %o4, 2, %g1
a0135ff8:  9e 00 40 0c  add  %g1, %o4, %o7
a0135ffc:  ab 2b e0 02  sll  %o7, 2, %l5
a0136000:  ae 05 60 10  add  %l5, 0x10, %l7
a0136004:  90 10 20 00  clr  %o0
a0136008:  92 0d e0 fc  and  %l7, 0xfc, %o1
a013600c:  94 07 bf b4  add  %fp, -76, %o2
a0136010:  67 fd 59 30  call  0x4008c4d0
a0136014:  96 10 20 01  mov  1, %o3
a0136018:  a0 04 20 01  inc  %l0
a013601c:  98 0c 20 ff  and  %l0, 0xff, %o4
a0136020:  ad 2b 20 02  sll  %o4, 2, %l6
a0136024:  90 05 80 0c  add  %l6, %o4, %o0
a0136028:  bb 2a 20 02  sll  %o0, 2, %i5
a013602c:  a4 07 60 10  add  %i5, 0x10, %l2
a0136030:  f8 07 bf b4  ld  [ %fp + -76 ], %i4
a0136034:  80 a4 a0 50  cmp  %l2, 0x50
a0136038:  04 bf ff ef  ble  0xa0135ff4
a013603c:  a2 14 40 1c  or  %l1, %i4, %l1
a0136040:  80 a4 60 00  cmp  %l1, 0
a0136044:  12 bf ff ea  bne  0xa0135fec
a0136048:  a2 10 20 00  clr  %l1
a013604c:  81 c7 e0 08  ret
a0136050:  81 e8 00 00  restore
