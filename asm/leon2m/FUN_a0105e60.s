# leon2m FUN_a0105e60 0xa0105e60-0xa01061c0 (864 bytes)
a0105e60:  9d e3 bf 98  save  %sp, -104, %sp
a0105e64:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a0105e68:  90 12 62 6c  or  %o1, 0x26c, %o0	! 0xcf01166c
a0105e6c:  b5 2e a0 10  sll  %i2, 0x10, %i2
a0105e70:  21 00 06 69  sethi  %hi(0x19a400), %l0
a0105e74:  03 33 33 33  sethi  %hi(0xcccccc00), %g1
a0105e78:  da 02 00 00  ld  [ %o0 ], %o5
a0105e7c:  94 10 60 cd  or  %g1, 0xcd, %o2
a0105e80:  b5 36 a0 10  srl  %i2, 0x10, %i2
a0105e84:  96 10 20 00  clr  %o3
a0105e88:  a2 10 20 00  clr  %l1
a0105e8c:  92 14 22 40  or  %l0, 0x240, %o1
a0105e90:  83 2c 60 03  sll  %l1, 3, %g1
a0105e94:  98 00 40 11  add  %g1, %l1, %o4
a0105e98:  a6 03 00 0c  add  %o4, %o4, %l3
a0105e9c:  98 04 c0 09  add  %l3, %o1, %o4
a0105ea0:  de 13 20 06  lduh  [ %o4 + 6 ], %o7
a0105ea4:  a5 2b e0 10  sll  %o7, 0x10, %l2
a0105ea8:  9b 34 a0 10  srl  %l2, 0x10, %o5
a0105eac:  80 53 40 0a  umul  %o5, %o2, %g0
a0105eb0:  83 40 00 00  rd  %y, %g1
a0105eb4:  90 23 c0 18  sub  %o7, %i0, %o0
a0105eb8:  a7 2a 20 10  sll  %o0, 0x10, %l3
a0105ebc:  a5 28 60 0d  sll  %g1, 0xd, %l2
a0105ec0:  9b 34 e0 10  srl  %l3, 0x10, %o5
a0105ec4:  9f 34 a0 10  srl  %l2, 0x10, %o7
a0105ec8:  80 a3 40 0f  cmp  %o5, %o7
a0105ecc:  1a 80 00 15  bcc  0xa0105f20
a0105ed0:  96 02 e0 01  inc  %o3
a0105ed4:  de 13 20 0e  lduh  [ %o4 + 0xe ], %o7
a0105ed8:  a5 2b e0 10  sll  %o7, 0x10, %l2
a0105edc:  83 34 a0 10  srl  %l2, 0x10, %g1
a0105ee0:  90 23 c0 19  sub  %o7, %i1, %o0
a0105ee4:  80 50 40 0a  umul  %g1, %o2, %g0
a0105ee8:  a7 40 00 00  rd  %y, %l3
a0105eec:  9b 2a 20 10  sll  %o0, 0x10, %o5
a0105ef0:  a5 2c e0 0d  sll  %l3, 0xd, %l2
a0105ef4:  9f 33 60 10  srl  %o5, 0x10, %o7
a0105ef8:  91 34 a0 10  srl  %l2, 0x10, %o0
a0105efc:  80 a3 c0 08  cmp  %o7, %o0
a0105f00:  3a 80 00 09  bcc,a   0xa0105f24
a0105f04:  a2 0a e0 ff  and  %o3, 0xff, %l1
a0105f08:  e6 13 20 10  lduh  [ %o4 + 0x10 ], %l3
a0105f0c:  9a 24 c0 1a  sub  %l3, %i2, %o5
a0105f10:  98 03 60 09  add  %o5, 9, %o4
a0105f14:  80 a3 20 12  cmp  %o4, 0x12
a0105f18:  08 80 00 07  bleu  0xa0105f34
a0105f1c:  80 a4 60 08  cmp  %l1, 8
a0105f20:  a2 0a e0 ff  and  %o3, 0xff, %l1
a0105f24:  80 a4 60 07  cmp  %l1, 7
a0105f28:  08 bf ff db  bleu  0xa0105e94
a0105f2c:  83 2c 60 03  sll  %l1, 3, %g1
a0105f30:  80 a4 60 08  cmp  %l1, 8
a0105f34:  02 80 00 9f  be  0xa01061b0
a0105f38:  15 00 06 6a  sethi  %hi(0x19a800), %o2
a0105f3c:  83 2e 60 10  sll  %i1, 0x10, %g1
a0105f40:  a7 2e 20 10  sll  %i0, 0x10, %l3
a0105f44:  b3 30 60 10  srl  %g1, 0x10, %i1
a0105f48:  1f 00 06 6a  sethi  %hi(0x19a800), %o7
a0105f4c:  a5 34 e0 10  srl  %l3, 0x10, %l2
a0105f50:  92 10 00 11  mov  %l1, %o1
a0105f54:  96 10 00 19  mov  %i1, %o3
a0105f58:  90 13 e0 e8  or  %o7, 0xe8, %o0
a0105f5c:  7f ff 64 85  call  0xa00df170
a0105f60:  94 10 00 12  mov  %l2, %o2
a0105f64:  b5 2c 60 03  sll  %l1, 3, %i2
a0105f68:  90 06 80 11  add  %i2, %l1, %o0
a0105f6c:  b4 14 22 40  or  %l0, 0x240, %i2
a0105f70:  a0 02 00 08  add  %o0, %o0, %l0
a0105f74:  d2 16 80 10  lduh  [ %i2 + %l0 ], %o1
a0105f78:  a3 2a 60 10  sll  %o1, 0x10, %l1
a0105f7c:  97 34 60 10  srl  %l1, 0x10, %o3
a0105f80:  9b 34 60 13  srl  %l1, 0x13, %o5
a0105f84:  80 8a e0 07  btst  7, %o3
a0105f88:  02 80 00 03  be  0xa0105f94
a0105f8c:  a2 10 00 0d  mov  %o5, %l1
a0105f90:  a2 03 60 01  add  %o5, 1, %l1
a0105f94:  80 a4 a7 80  cmp  %l2, 0x780
a0105f98:  08 80 00 03  bleu  0xa0105fa4
a0105f9c:  a3 2c 60 03  sll  %l1, 3, %l1
a0105fa0:  b1 34 e0 11  srl  %l3, 0x11, %i0
a0105fa4:  90 10 20 05  mov  5, %o0
a0105fa8:  92 10 20 25  mov  0x25, %o1
a0105fac:  7f ff b0 bb  call  0xa00f2298
a0105fb0:  94 10 20 1a  mov  0x1a, %o2
a0105fb4:  94 10 00 19  mov  %i1, %o2
a0105fb8:  90 10 20 05  mov  5, %o0
a0105fbc:  7f ff b1 33  call  0xa00f2488
a0105fc0:  92 10 20 18  mov  0x18, %o1
a0105fc4:  94 10 00 12  mov  %l2, %o2
a0105fc8:  90 10 20 05  mov  5, %o0
a0105fcc:  7f ff b1 2f  call  0xa00f2488
a0105fd0:  92 10 20 1a  mov  0x1a, %o1
a0105fd4:  90 10 20 05  mov  5, %o0
a0105fd8:  92 10 20 24  mov  0x24, %o1
a0105fdc:  7f ff b0 af  call  0xa00f2298
a0105fe0:  94 10 20 00  clr  %o2
a0105fe4:  90 10 20 05  mov  5, %o0
a0105fe8:  92 10 20 54  mov  0x54, %o1
a0105fec:  94 10 20 00  clr  %o2
a0105ff0:  7f ff b0 aa  call  0xa00f2298
a0105ff4:  a0 04 00 1a  add  %l0, %i2, %l0
a0105ff8:  d4 14 20 08  lduh  [ %l0 + 8 ], %o2
a0105ffc:  90 10 20 05  mov  5, %o0
a0106000:  7f ff b1 22  call  0xa00f2488
a0106004:  92 10 20 5b  mov  0x5b, %o1
a0106008:  d4 14 20 0a  lduh  [ %l0 + 0xa ], %o2
a010600c:  90 10 20 05  mov  5, %o0
a0106010:  7f ff b1 1e  call  0xa00f2488
a0106014:  92 10 20 be  mov  0xbe, %o1
a0106018:  9b 2c 60 10  sll  %l1, 0x10, %o5
a010601c:  a3 33 60 10  srl  %o5, 0x10, %l1
a0106020:  90 10 20 05  mov  5, %o0
a0106024:  92 10 20 5e  mov  0x5e, %o1
a0106028:  7f ff b1 18  call  0xa00f2488
a010602c:  94 10 00 11  mov  %l1, %o2
a0106030:  d4 14 20 02  lduh  [ %l0 + 2 ], %o2
a0106034:  90 10 20 05  mov  5, %o0
a0106038:  7f ff b1 14  call  0xa00f2488
a010603c:  92 10 20 a0  mov  0xa0, %o1
a0106040:  e6 14 20 0c  lduh  [ %l0 + 0xc ], %l3
a0106044:  90 10 20 05  mov  5, %o0
a0106048:  92 10 20 62  mov  0x62, %o1
a010604c:  7f ff b1 0f  call  0xa00f2488
a0106050:  94 10 00 13  mov  %l3, %o2
a0106054:  94 10 00 19  mov  %i1, %o2
a0106058:  90 10 20 05  mov  5, %o0
a010605c:  7f ff b1 0b  call  0xa00f2488
a0106060:  92 10 20 64  mov  0x64, %o1
a0106064:  e4 14 20 04  lduh  [ %l0 + 4 ], %l2
a0106068:  90 10 20 05  mov  5, %o0
a010606c:  92 10 20 66  mov  0x66, %o1
a0106070:  7f ff b1 06  call  0xa00f2488
a0106074:  94 10 00 12  mov  %l2, %o2
a0106078:  99 2e 20 10  sll  %i0, 0x10, %o4
a010607c:  a1 33 20 10  srl  %o4, 0x10, %l0
a0106080:  90 10 20 05  mov  5, %o0
a0106084:  92 10 20 68  mov  0x68, %o1
a0106088:  7f ff b1 00  call  0xa00f2488
a010608c:  94 10 00 10  mov  %l0, %o2
a0106090:  90 10 20 05  mov  5, %o0
a0106094:  92 10 20 6e  mov  0x6e, %o1
a0106098:  7f ff b0 80  call  0xa00f2298
a010609c:  94 10 20 07  mov  7, %o2
a01060a0:  94 10 00 13  mov  %l3, %o2
a01060a4:  90 10 20 05  mov  5, %o0
a01060a8:  7f ff b0 f8  call  0xa00f2488
a01060ac:  92 10 20 6f  mov  0x6f, %o1
a01060b0:  94 10 00 19  mov  %i1, %o2
a01060b4:  90 10 20 05  mov  5, %o0
a01060b8:  7f ff b0 f4  call  0xa00f2488
a01060bc:  92 10 20 71  mov  0x71, %o1
a01060c0:  94 10 00 12  mov  %l2, %o2
a01060c4:  90 10 20 05  mov  5, %o0
a01060c8:  7f ff b0 f0  call  0xa00f2488
a01060cc:  92 10 20 73  mov  0x73, %o1
a01060d0:  94 10 00 10  mov  %l0, %o2
a01060d4:  90 10 20 05  mov  5, %o0
a01060d8:  7f ff b0 ec  call  0xa00f2488
a01060dc:  92 10 20 75  mov  0x75, %o1
a01060e0:  94 10 00 11  mov  %l1, %o2
a01060e4:  90 10 20 05  mov  5, %o0
a01060e8:  7f ff b0 e8  call  0xa00f2488
a01060ec:  92 10 20 79  mov  0x79, %o1
a01060f0:  90 10 20 05  mov  5, %o0
a01060f4:  92 10 20 55  mov  0x55, %o1
a01060f8:  7f ff b0 68  call  0xa00f2298
a01060fc:  94 10 20 00  clr  %o2
a0106100:  90 10 20 05  mov  5, %o0
a0106104:  92 10 20 88  mov  0x88, %o1
a0106108:  7f ff b0 64  call  0xa00f2298
a010610c:  94 10 20 02  mov  2, %o2
a0106110:  90 10 20 05  mov  5, %o0
a0106114:  92 10 20 90  mov  0x90, %o1
a0106118:  7f ff b0 60  call  0xa00f2298
a010611c:  94 10 20 00  clr  %o2
a0106120:  90 10 20 05  mov  5, %o0
a0106124:  92 10 20 95  mov  0x95, %o1
a0106128:  7f ff b0 5c  call  0xa00f2298
a010612c:  94 10 20 40  mov  0x40, %o2
a0106130:  90 10 20 05  mov  5, %o0
a0106134:  92 10 20 50  mov  0x50, %o1
a0106138:  7f ff b0 58  call  0xa00f2298
a010613c:  94 10 20 c1  mov  0xc1, %o2
a0106140:  90 10 20 05  mov  5, %o0
a0106144:  92 10 20 7d  mov  0x7d, %o1
a0106148:  7f ff b0 54  call  0xa00f2298
a010614c:  94 10 20 c8  mov  0xc8, %o2
a0106150:  90 10 20 05  mov  5, %o0
a0106154:  92 10 20 4b  mov  0x4b, %o1
a0106158:  7f ff b0 50  call  0xa00f2298
a010615c:  94 10 20 08  mov  8, %o2
a0106160:  90 10 20 05  mov  5, %o0
a0106164:  92 10 20 61  mov  0x61, %o1
a0106168:  7f ff b0 4c  call  0xa00f2298
a010616c:  94 10 20 2e  mov  0x2e, %o2
a0106170:  90 10 20 05  mov  5, %o0
a0106174:  92 10 20 a4  mov  0xa4, %o1
a0106178:  7f ff b0 48  call  0xa00f2298
a010617c:  94 10 20 00  clr  %o2
a0106180:  90 10 20 05  mov  5, %o0
a0106184:  92 10 20 86  mov  0x86, %o1
a0106188:  7f ff b0 44  call  0xa00f2298
a010618c:  94 10 20 84  mov  0x84, %o2
a0106190:  90 10 20 05  mov  5, %o0
a0106194:  92 10 20 8d  mov  0x8d, %o1
a0106198:  7f ff b0 40  call  0xa00f2298
a010619c:  94 10 20 20  mov  0x20, %o2
a01061a0:  b0 10 20 05  mov  5, %i0
a01061a4:  b2 10 20 59  mov  0x59, %i1
a01061a8:  7f ff b0 3c  call  0xa00f2298
a01061ac:  95 e8 20 83  restore  %g0, 0x83, %o2
a01061b0:  7f ff 63 f0  call  0xa00df170
a01061b4:  90 12 a0 c0  or  %o2, 0xc0, %o0
a01061b8:  10 bf ff 61  b  0xa0105f3c
a01061bc:  a2 10 20 02  mov  2, %l1
