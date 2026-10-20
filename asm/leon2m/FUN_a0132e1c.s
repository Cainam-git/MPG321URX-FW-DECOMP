# leon2m FUN_a0132e1c 0xa0132e1c-0xa0133238 (920 bytes)
a0132e1c:  9d e3 bf 98  save  %sp, -104, %sp
a0132e20:  2b 2a 00 b6  sethi  %hi(0xa802d800), %l5
a0132e24:  9a 10 20 00  clr  %o5
a0132e28:  96 10 20 01  mov  1, %o3
a0132e2c:  82 10 20 00  clr  %g1
a0132e30:  98 15 61 b8  or  %l5, 0x1b8, %o4
a0132e34:  c0 2b 00 01  clrb  [ %o4 + %g1 ]
a0132e38:  9a 03 60 01  inc  %o5
a0132e3c:  82 0b 60 ff  and  %o5, 0xff, %g1
a0132e40:  80 a0 60 0b  cmp  %g1, 0xb
a0132e44:  28 bf ff fd  bleu,a   0xa0132e38
a0132e48:  c0 2b 00 01  clrb  [ %o4 + %g1 ]
a0132e4c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0132e50:  da 00 63 d0  ld  [ %g1 + 0x3d0 ], %o5	! 0xa802e3d0
a0132e54:  80 a3 60 00  cmp  %o5, 0
a0132e58:  06 80 00 6f  bl  0xa0133014
a0132e5c:  a6 10 20 00  clr  %l3
a0132e60:  2d 2a 00 b8  sethi  %hi(0xa802e000), %l6
a0132e64:  c2 0d a1 a7  ldub  [ %l6 + 0x1a7 ], %g1	! 0xa802e1a7
a0132e68:  80 a0 60 07  cmp  %g1, 7
a0132e6c:  18 80 00 0a  bgu  0xa0132e94
a0132e70:  a8 0a e0 ff  and  %o3, 0xff, %l4
a0132e74:  11 00 03 4a  sethi  %hi(0xd2800), %o0
a0132e78:  83 28 60 02  sll  %g1, 2, %g1
a0132e7c:  94 12 23 0c  or  %o0, 0x30c, %o2
a0132e80:  d2 02 80 01  ld  [ %o2 + %g1 ], %o1
a0132e84:  81 c2 40 00  jmp  %o1
a0132e88:  01 00 00 00  nop
a0132e8c:  96 10 20 03  mov  3, %o3	! 0x3
a0132e90:  a8 0a e0 ff  and  %o3, 0xff, %l4
a0132e94:  80 a5 20 00  cmp  %l4, 0
a0132e98:  02 80 00 e6  be  0xa0133230
a0132e9c:  a4 10 20 00  clr  %l2
a0132ea0:  90 10 20 00  clr  %o0
a0132ea4:  2d 2a 00 b8  sethi  %hi(0xa802e000), %l6
a0132ea8:  7f ff f3 72  call  0xa012fc70
a0132eac:  01 00 00 00  nop
a0132eb0:  40 00 3c ae  call  0xa0142168
a0132eb4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0132eb8:  94 0a 20 ff  and  %o0, 0xff, %o2
a0132ebc:  80 a2 a0 07  cmp  %o2, 7
a0132ec0:  a2 40 20 00  addx  %g0, 0, %l1
a0132ec4:  82 20 00 11  neg  %l1, %g1
a0132ec8:  92 0a 80 01  and  %o2, %g1, %o1
a0132ecc:  9b 2a 60 03  sll  %o1, 3, %o5
a0132ed0:  98 03 40 09  add  %o5, %o1, %o4
a0132ed4:  96 03 00 0c  add  %o4, %o4, %o3
a0132ed8:  9e 15 a1 16  or  %l6, 0x116, %o7
a0132edc:  a0 02 c0 0f  add  %o3, %o7, %l0
a0132ee0:  7f ff c9 00  call  0xa01252e0
a0132ee4:  d0 0c 20 10  ldub  [ %l0 + 0x10 ], %o0
a0132ee8:  a2 10 00 08  mov  %o0, %l1
a0132eec:  7f ff c9 04  call  0xa01252fc
a0132ef0:  d0 0c 20 10  ldub  [ %l0 + 0x10 ], %o0
a0132ef4:  92 10 00 08  mov  %o0, %o1
a0132ef8:  90 0c 60 ff  and  %l1, 0xff, %o0
a0132efc:  80 a2 20 12  cmp  %o0, 0x12
a0132f00:  18 80 00 09  bgu  0xa0132f24
a0132f04:  96 10 20 00  clr  %o3
a0132f08:  1b 00 03 4a  sethi  %hi(0xd2800), %o5
a0132f0c:  9f 2a 20 02  sll  %o0, 2, %o7
a0132f10:  98 13 62 c0  or  %o5, 0x2c0, %o4
a0132f14:  e0 03 00 0f  ld  [ %o4 + %o7 ], %l0
a0132f18:  81 c4 00 00  jmp  %l0
a0132f1c:  01 00 00 00  nop
a0132f20:  96 10 20 1d  mov  0x1d, %o3	! 0x1d
a0132f24:  a0 0a 60 ff  and  %o1, 0xff, %l0
a0132f28:  a2 10 00 0b  mov  %o3, %l1
a0132f2c:  67 fd 67 83  call  0x4008cd38
a0132f30:  92 10 00 10  mov  %l0, %o1
a0132f34:  90 38 00 08  xnor  %g0, %o0, %o0
a0132f38:  9a 10 20 00  clr  %o5
a0132f3c:  82 10 20 00  clr  %g1
a0132f40:  97 3c 00 01  sra  %l0, %g1, %o3
a0132f44:  80 a2 e0 01  cmp  %o3, 1
a0132f48:  02 80 00 08  be  0xa0132f68
a0132f4c:  82 0a 20 01  and  %o0, 1, %g1
a0132f50:  9a 03 60 01  inc  %o5
a0132f54:  82 0b 60 ff  and  %o5, 0xff, %g1
a0132f58:  80 a0 60 07  cmp  %g1, 7
a0132f5c:  28 bf ff fa  bleu,a   0xa0132f44
a0132f60:  97 3c 00 01  sra  %l0, %g1, %o3
a0132f64:  82 0a 20 01  and  %o0, 1, %g1
a0132f68:  95 28 60 04  sll  %g1, 4, %o2
a0132f6c:  90 12 80 0d  or  %o2, %o5, %o0
a0132f70:  13 2a 00 b6  sethi  %hi(0xa802d800), %o1
a0132f74:  94 12 61 b8  or  %o1, 0x1b8, %o2	! 0xa802d9b8
a0132f78:  9e 10 20 00  clr  %o7
a0132f7c:  98 10 20 00  clr  %o4
a0132f80:  9a 10 20 00  clr  %o5
a0132f84:  96 0c 60 ff  and  %l1, 0xff, %o3
a0132f88:  10 80 00 06  b  0xa0132fa0
a0132f8c:  92 0a 20 ff  and  %o0, 0xff, %o1
a0132f90:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0132f94:  80 a3 60 0b  cmp  %o5, 0xb
a0132f98:  18 80 00 0d  bgu  0xa0132fcc
a0132f9c:  80 8b e0 ff  btst  0xff, %o7
a0132fa0:  e0 0a 80 0d  ldub  [ %o2 + %o5 ], %l0
a0132fa4:  80 a4 00 0b  cmp  %l0, %o3
a0132fa8:  32 bf ff fa  bne,a   0xa0132f90
a0132fac:  98 03 20 02  add  %o4, 2, %o4
a0132fb0:  82 03 40 0a  add  %o5, %o2, %g1
a0132fb4:  da 08 60 01  ldub  [ %g1 + 1 ], %o5
a0132fb8:  80 a3 40 09  cmp  %o5, %o1
a0132fbc:  32 bf ff f5  bne,a   0xa0132f90
a0132fc0:  98 03 20 02  add  %o4, 2, %o4
a0132fc4:  9e 10 20 01  mov  1, %o7
a0132fc8:  80 8b e0 ff  btst  0xff, %o7
a0132fcc:  32 80 00 0d  bne,a   0xa0133000
a0132fd0:  a4 04 a0 01  inc  %l2
a0132fd4:  92 0c e0 ff  and  %l3, 0xff, %o1
a0132fd8:  96 04 e0 01  add  %l3, 1, %o3
a0132fdc:  98 15 61 b8  or  %l5, 0x1b8, %o4
a0132fe0:  e2 2b 00 09  stb  %l1, [ %o4 + %o1 ]
a0132fe4:  a6 04 e0 02  add  %l3, 2, %l3
a0132fe8:  9e 0a e0 ff  and  %o3, 0xff, %o7
a0132fec:  a2 0c e0 ff  and  %l3, 0xff, %l1
a0132ff0:  80 a4 60 0b  cmp  %l1, 0xb
a0132ff4:  18 80 00 8f  bgu  0xa0133230
a0132ff8:  d0 2b 00 0f  stb  %o0, [ %o4 + %o7 ]
a0132ffc:  a4 04 a0 01  inc  %l2
a0133000:  90 0c a0 ff  and  %l2, 0xff, %o0
a0133004:  80 a2 00 14  cmp  %o0, %l4
a0133008:  0a bf ff a8  bcs  0xa0132ea8
a013300c:  01 00 00 00  nop
a0133010:  30 80 00 88  b,a   0xa0133230
a0133014:  90 10 20 13  mov  0x13, %o0	! 0x13
a0133018:  d0 2d 61 b8  stb  %o0, [ %l5 + 0x1b8 ]
a013301c:  90 10 20 03  mov  3, %o0
a0133020:  67 fd 67 46  call  0x4008cd38
a0133024:  92 10 20 04  mov  4, %o1
a0133028:  98 15 61 b8  or  %l5, 0x1b8, %o4
a013302c:  90 38 00 08  xnor  %g0, %o0, %o0
a0133030:  9a 10 20 00  clr  %o5
a0133034:  82 10 20 00  clr  %g1
a0133038:  96 10 20 04  mov  4, %o3
a013303c:  93 3a c0 01  sra  %o3, %g1, %o1
a0133040:  80 a2 60 01  cmp  %o1, 1
a0133044:  02 80 00 08  be  0xa0133064
a0133048:  a2 0a 20 01  and  %o0, 1, %l1
a013304c:  9a 03 60 01  inc  %o5
a0133050:  82 0b 60 ff  and  %o5, 0xff, %g1
a0133054:  80 a0 60 07  cmp  %g1, 7
a0133058:  08 bf ff fa  bleu  0xa0133040
a013305c:  93 3a c0 01  sra  %o3, %g1, %o1
a0133060:  a2 0a 20 01  and  %o0, 1, %l1
a0133064:  a1 2c 60 04  sll  %l1, 4, %l0
a0133068:  96 14 00 0d  or  %l0, %o5, %o3
a013306c:  d6 2b 20 01  stb  %o3, [ %o4 + 1 ]
a0133070:  1f 2a 00 b6  sethi  %hi(0xa802d800), %o7
a0133074:  94 13 e1 b8  or  %o7, 0x1b8, %o2	! 0xa802d9b8
a0133078:  98 10 20 13  mov  0x13, %o4
a013307c:  d8 2a a0 02  stb  %o4, [ %o2 + 2 ]
a0133080:  a0 10 00 0a  mov  %o2, %l0
a0133084:  90 10 20 03  mov  3, %o0
a0133088:  67 fd 67 2c  call  0x4008cd38
a013308c:  92 10 20 08  mov  8, %o1
a0133090:  90 38 00 08  xnor  %g0, %o0, %o0
a0133094:  9a 10 20 00  clr  %o5
a0133098:  82 10 20 00  clr  %g1
a013309c:  98 10 20 08  mov  8, %o4
a01330a0:  a5 3b 00 01  sra  %o4, %g1, %l2
a01330a4:  80 a4 a0 01  cmp  %l2, 1
a01330a8:  22 80 00 08  be,a   0xa01330c8
a01330ac:  92 0a 20 01  and  %o0, 1, %o1
a01330b0:  9a 03 60 01  inc  %o5
a01330b4:  82 0b 60 ff  and  %o5, 0xff, %g1
a01330b8:  80 a0 60 07  cmp  %g1, 7
a01330bc:  08 bf ff fa  bleu  0xa01330a4
a01330c0:  a5 3b 00 01  sra  %o4, %g1, %l2
a01330c4:  92 0a 20 01  and  %o0, 1, %o1
a01330c8:  83 2a 60 04  sll  %o1, 4, %g1
a01330cc:  aa 10 40 0d  or  %g1, %o5, %l5
a01330d0:  2d 2a 00 b6  sethi  %hi(0xa802d800), %l6
a01330d4:  ea 2c 20 03  stb  %l5, [ %l0 + 3 ]
a01330d8:  a6 15 a1 b8  or  %l6, 0x1b8, %l3
a01330dc:  a8 10 20 1b  mov  0x1b, %l4
a01330e0:  e8 2c e0 04  stb  %l4, [ %l3 + 4 ]
a01330e4:  90 10 20 0b  mov  0xb, %o0
a01330e8:  67 fd 67 14  call  0x4008cd38
a01330ec:  92 10 20 02  mov  2, %o1
a01330f0:  a0 10 00 13  mov  %l3, %l0
a01330f4:  90 38 00 08  xnor  %g0, %o0, %o0
a01330f8:  98 10 20 06  mov  6, %o4
a01330fc:  9a 10 20 00  clr  %o5
a0133100:  82 10 20 00  clr  %g1
a0133104:  96 10 20 02  mov  2, %o3
a0133108:  95 3a c0 01  sra  %o3, %g1, %o2
a013310c:  80 a2 a0 01  cmp  %o2, 1
a0133110:  02 80 00 08  be  0xa0133130
a0133114:  9e 0a 20 01  and  %o0, 1, %o7
a0133118:  9a 03 60 01  inc  %o5
a013311c:  82 0b 60 ff  and  %o5, 0xff, %g1
a0133120:  80 a0 60 07  cmp  %g1, 7
a0133124:  08 bf ff fa  bleu  0xa013310c
a0133128:  95 3a c0 01  sra  %o3, %g1, %o2
a013312c:  9e 0a 20 01  and  %o0, 1, %o7
a0133130:  97 2b e0 04  sll  %o7, 4, %o3
a0133134:  90 12 c0 0d  or  %o3, %o5, %o0
a0133138:  96 0b 20 ff  and  %o4, 0xff, %o3
a013313c:  80 a2 e0 0b  cmp  %o3, 0xb
a0133140:  18 80 00 3c  bgu  0xa0133230
a0133144:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a0133148:  23 2a 00 b6  sethi  %hi(0xa802d800), %l1
a013314c:  a0 14 61 b8  or  %l1, 0x1b8, %l0	! 0xa802d9b8
a0133150:  9a 10 20 12  mov  0x12, %o5
a0133154:  98 03 20 01  inc  %o4
a0133158:  da 2c 00 0b  stb  %o5, [ %l0 + %o3 ]
a013315c:  a2 10 00 10  mov  %l0, %l1
a0133160:  a0 0b 20 ff  and  %o4, 0xff, %l0
a0133164:  90 10 20 02  mov  2, %o0
a0133168:  67 fd 66 f4  call  0x4008cd38
a013316c:  92 10 20 10  mov  0x10, %o1
a0133170:  90 38 00 08  xnor  %g0, %o0, %o0
a0133174:  9a 10 20 00  clr  %o5
a0133178:  82 10 20 00  clr  %g1
a013317c:  98 10 20 10  mov  0x10, %o4
a0133180:  a5 3b 00 01  sra  %o4, %g1, %l2
a0133184:  80 a4 a0 01  cmp  %l2, 1
a0133188:  02 80 00 08  be  0xa01331a8
a013318c:  aa 0a 20 01  and  %o0, 1, %l5
a0133190:  9a 03 60 01  inc  %o5
a0133194:  82 0b 60 ff  and  %o5, 0xff, %g1
a0133198:  80 a0 60 07  cmp  %g1, 7
a013319c:  08 bf ff fa  bleu  0xa0133184
a01331a0:  a5 3b 00 01  sra  %o4, %g1, %l2
a01331a4:  aa 0a 20 01  and  %o0, 1, %l5
a01331a8:  a9 2d 60 04  sll  %l5, 4, %l4
a01331ac:  a6 15 00 0d  or  %l4, %o5, %l3
a01331b0:  10 80 00 20  b  0xa0133230
a01331b4:  e6 2c 40 10  stb  %l3, [ %l1 + %l0 ]
a01331b8:  10 bf ff 5b  b  0xa0132f24
a01331bc:  96 10 20 11  mov  0x11, %o3
a01331c0:  10 bf ff 59  b  0xa0132f24
a01331c4:  96 10 20 14  mov  0x14, %o3
a01331c8:  10 bf ff 57  b  0xa0132f24
a01331cc:  96 10 20 13  mov  0x13, %o3
a01331d0:  10 bf ff 55  b  0xa0132f24
a01331d4:  96 10 20 12  mov  0x12, %o3
a01331d8:  10 bf ff 53  b  0xa0132f24
a01331dc:  96 10 20 1c  mov  0x1c, %o3
a01331e0:  10 bf ff 51  b  0xa0132f24
a01331e4:  96 10 20 1b  mov  0x1b, %o3
a01331e8:  10 bf ff 4f  b  0xa0132f24
a01331ec:  96 10 20 1a  mov  0x1a, %o3
a01331f0:  10 bf ff 4d  b  0xa0132f24
a01331f4:  96 10 20 19  mov  0x19, %o3
a01331f8:  10 bf ff 4b  b  0xa0132f24
a01331fc:  96 10 20 18  mov  0x18, %o3
a0133200:  10 bf ff 49  b  0xa0132f24
a0133204:  96 10 20 17  mov  0x17, %o3
a0133208:  10 bf ff 47  b  0xa0132f24
a013320c:  96 10 20 16  mov  0x16, %o3
a0133210:  10 bf ff 45  b  0xa0132f24
a0133214:  96 10 20 15  mov  0x15, %o3
a0133218:  10 bf ff 1e  b  0xa0132e90
a013321c:  96 10 20 04  mov  4, %o3
a0133220:  10 bf ff 1c  b  0xa0132e90
a0133224:  96 10 20 01  mov  1, %o3
a0133228:  10 bf ff 1a  b  0xa0132e90
a013322c:  96 10 20 02  mov  2, %o3
a0133230:  81 c7 e0 08  ret
a0133234:  81 e8 00 00  restore
