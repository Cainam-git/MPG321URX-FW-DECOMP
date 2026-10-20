# leon2s FUN_a00d7e6c 0xa00d7e6c-0xa00d82c8 (1116 bytes)
a00d7e6c:  9d e3 bf 10  save  %sp, -240, %sp
a00d7e70:  c2 07 bf 70  ld  [ %fp + -144 ], %g1
a00d7e74:  1b 1f c0 00  sethi  %hi(0x7f000000), %o5
a00d7e78:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d7e7c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d7e80:  d2 08 60 32  ldub  [ %g1 + 0x32 ], %o1	! 0xa8078832
a00d7e84:  03 00 40 00  sethi  %hi(0x1000000), %g1
a00d7e88:  9a 13 40 01  or  %o5, %g1, %o5
a00d7e8c:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00d7e90:  82 10 60 a4  or  %g1, 0xa4, %g1	! 0xa80760a4
a00d7e94:  99 2a 60 02  sll  %o1, 2, %o4
a00d7e98:  da 27 bf 70  st  %o5, [ %fp + -144 ]
a00d7e9c:  d4 00 40 0c  ld  [ %g1 + %o4 ], %o2
a00d7ea0:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00d7ea4:  9e 10 60 3c  or  %g1, 0x3c, %o7	! 0xa00b383c
a00d7ea8:  96 10 20 00  clr  %o3
a00d7eac:  90 07 bf f8  add  %fp, -8, %o0
a00d7eb0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00d7eb4:  82 03 40 0d  add  %o5, %o5, %g1
a00d7eb8:  82 00 40 0f  add  %g1, %o7, %g1
a00d7ebc:  c2 10 60 1e  lduh  [ %g1 + 0x1e ], %g1
a00d7ec0:  83 28 60 02  sll  %g1, 2, %g1
a00d7ec4:  d8 02 80 01  ld  [ %o2 + %g1 ], %o4
a00d7ec8:  96 02 e0 01  inc  %o3
a00d7ecc:  9a 02 00 0d  add  %o0, %o5, %o5
a00d7ed0:  82 0a e0 ff  and  %o3, 0xff, %g1
a00d7ed4:  80 a0 60 0f  cmp  %g1, 0xf
a00d7ed8:  08 bf ff f6  bleu  0xa00d7eb0
a00d7edc:  d8 2b 7f 79  stb  %o4, [ %o5 + -135 ]
a00d7ee0:  80 a2 60 00  cmp  %o1, 0
a00d7ee4:  12 80 00 0c  bne  0xa00d7f14
a00d7ee8:  d6 07 bf 80  ld  [ %fp + -128 ], %o3
a00d7eec:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00d7ef0:  c2 08 60 ac  ldub  [ %g1 + 0xac ], %g1	! 0xa80760ac
a00d7ef4:  98 00 60 02  add  %g1, 2, %o4
a00d7ef8:  9a 0b 20 0f  and  %o4, 0xf, %o5
a00d7efc:  03 00 03 c0  sethi  %hi(0xf0000), %g1
a00d7f00:  82 2a c0 01  andn  %o3, %g1, %g1
a00d7f04:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00d7f08:  82 10 40 0d  or  %g1, %o5, %g1
a00d7f0c:  10 80 00 08  b  0xa00d7f2c
a00d7f10:  c2 27 bf 80  st  %g1, [ %fp + -128 ]
a00d7f14:  03 00 03 c0  sethi  %hi(0xf0000), %g1
a00d7f18:  82 2a c0 01  andn  %o3, %g1, %g1
a00d7f1c:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00d7f20:  82 10 40 0d  or  %g1, %o5, %g1
a00d7f24:  c2 27 bf 80  st  %g1, [ %fp + -128 ]
a00d7f28:  98 10 20 02  mov  2, %o4
a00d7f2c:  ad 2b 20 10  sll  %o4, 0x10, %l6
a00d7f30:  80 a5 a0 00  cmp  %l6, 0
a00d7f34:  a4 10 20 12  mov  0x12, %l2
a00d7f38:  02 80 00 d6  be  0xa00d8290
a00d7f3c:  aa 10 20 00  clr  %l5
a00d7f40:  82 0d 60 ff  and  %l5, 0xff, %g1
a00d7f44:  80 a0 60 00  cmp  %g1, 0
a00d7f48:  12 80 00 0e  bne  0xa00d7f80
a00d7f4c:  80 a0 60 01  cmp  %g1, 1
a00d7f50:  da 07 bf 80  ld  [ %fp + -128 ], %o5
a00d7f54:  03 00 00 20  sethi  %hi(0x8000), %g1
a00d7f58:  9a 13 40 01  or  %o5, %g1, %o5
a00d7f5c:  82 00 70 00  add  %g1, -4096, %g1
a00d7f60:  82 2b 40 01  andn  %o5, %g1, %g1
a00d7f64:  1b 00 00 04  sethi  %hi(0x1000), %o5
a00d7f68:  82 10 40 0d  or  %g1, %o5, %g1
a00d7f6c:  82 08 70 ff  and  %g1, -3841, %g1
a00d7f70:  82 10 60 c0  or  %g1, 0xc0, %g1
a00d7f74:  c2 27 bf 80  st  %g1, [ %fp + -128 ]
a00d7f78:  10 80 00 c0  b  0xa00d8278
a00d7f7c:  a4 04 a0 02  add  %l2, 2, %l2
a00d7f80:  12 80 00 34  bne  0xa00d8050
a00d7f84:  80 a0 60 02  cmp  %g1, 2
a00d7f88:  da 07 bf 94  ld  [ %fp + -108 ], %o5
a00d7f8c:  03 00 00 20  sethi  %hi(0x8000), %g1
a00d7f90:  82 2b 40 01  andn  %o5, %g1, %g1
a00d7f94:  1b 00 00 1c  sethi  %hi(0x7000), %o5
a00d7f98:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d7f9c:  03 00 00 0c  sethi  %hi(0x3000), %g1
a00d7fa0:  9a 13 40 01  or  %o5, %g1, %o5
a00d7fa4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d7fa8:  d8 08 60 32  ldub  [ %g1 + 0x32 ], %o4	! 0xa8078832
a00d7fac:  9a 0b 70 ff  and  %o5, -3841, %o5
a00d7fb0:  9a 13 68 00  or  %o5, 0x800, %o5
a00d7fb4:  15 28 02 ce  sethi  %hi(0xa00b3800), %o2
a00d7fb8:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00d7fbc:  82 10 60 a4  or  %g1, 0xa4, %g1	! 0xa80760a4
a00d7fc0:  94 12 a0 3c  or  %o2, 0x3c, %o2
a00d7fc4:  9a 0b 7f 7f  and  %o5, -129, %o5
a00d7fc8:  99 2b 20 02  sll  %o4, 2, %o4
a00d7fcc:  d8 00 40 0c  ld  [ %g1 + %o4 ], %o4
a00d7fd0:  9a 13 60 40  or  %o5, 0x40, %o5
a00d7fd4:  d6 12 a0 ca  lduh  [ %o2 + 0xca ], %o3
a00d7fd8:  97 2a e0 02  sll  %o3, 2, %o3
a00d7fdc:  da 27 bf 94  st  %o5, [ %fp + -108 ]
a00d7fe0:  c2 03 00 0b  ld  [ %o4 + %o3 ], %g1
a00d7fe4:  c2 2f bf 98  stb  %g1, [ %fp + -104 ]
a00d7fe8:  90 10 00 0c  mov  %o4, %o0
a00d7fec:  96 10 20 00  clr  %o3
a00d7ff0:  92 07 a0 0c  add  %fp, 0xc, %o1
a00d7ff4:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00d7ff8:  82 03 40 0d  add  %o5, %o5, %g1
a00d7ffc:  82 00 40 0a  add  %g1, %o2, %g1
a00d8000:  c2 10 60 1e  lduh  [ %g1 + 0x1e ], %g1
a00d8004:  83 28 60 02  sll  %g1, 2, %g1
a00d8008:  d8 02 00 01  ld  [ %o0 + %g1 ], %o4
a00d800c:  96 02 e0 01  inc  %o3
a00d8010:  9a 02 40 0d  add  %o1, %o5, %o5
a00d8014:  82 0a e0 ff  and  %o3, 0xff, %g1
a00d8018:  80 a0 60 0f  cmp  %g1, 0xf
a00d801c:  08 bf ff f6  bleu  0xa00d7ff4
a00d8020:  d8 2b 7f 8d  stb  %o4, [ %o5 + -115 ]
a00d8024:  c2 02 7f 9c  ld  [ %o1 + -100 ], %g1
a00d8028:  1b 00 3c 00  sethi  %hi(0xf00000), %o5
a00d802c:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d8030:  03 00 04 00  sethi  %hi(0x100000), %g1
a00d8034:  9a 13 40 01  or  %o5, %g1, %o5
a00d8038:  03 00 03 c0  sethi  %hi(0xf0000), %g1
a00d803c:  82 2b 40 01  andn  %o5, %g1, %g1
a00d8040:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00d8044:  82 10 40 0d  or  %g1, %o5, %g1
a00d8048:  10 80 00 8b  b  0xa00d8274
a00d804c:  c2 22 7f 9c  st  %g1, [ %o1 + -100 ]
a00d8050:  32 80 00 8b  bne,a   0xa00d827c
a00d8054:  aa 05 60 01  inc  %l5
a00d8058:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d805c:  c2 08 60 3f  ldub  [ %g1 + 0x3f ], %g1	! 0xa807883f
a00d8060:  80 a0 60 00  cmp  %g1, 0
a00d8064:  02 80 00 60  be  0xa00d81e4
a00d8068:  da 07 bf a8  ld  [ %fp + -88 ], %o5
a00d806c:  a6 07 bf e8  add  %fp, -24, %l3
a00d8070:  92 10 20 90  mov  0x90, %o1
a00d8074:  94 10 20 00  clr  %o2
a00d8078:  96 10 20 00  clr  %o3
a00d807c:  98 10 00 13  mov  %l3, %o4
a00d8080:  40 3a f8 e0  call  0xa0f96400
a00d8084:  90 10 20 00  clr  %o0
a00d8088:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00d808c:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a00d8090:  c2 2c 60 46  stb  %g1, [ %l1 + 0x46 ]	! 0xa8078846
a00d8094:  96 10 20 00  clr  %o3
a00d8098:  98 10 00 13  mov  %l3, %o4
a00d809c:  90 10 20 00  clr  %o0
a00d80a0:  92 10 20 90  mov  0x90, %o1
a00d80a4:  40 3a f8 d7  call  0xa0f96400
a00d80a8:  94 10 20 21  mov  0x21, %o2
a00d80ac:  da 07 bf a8  ld  [ %fp + -88 ], %o5
a00d80b0:  03 00 00 20  sethi  %hi(0x8000), %g1
a00d80b4:  82 2b 40 01  andn  %o5, %g1, %g1
a00d80b8:  98 08 70 ff  and  %g1, -3841, %o4
a00d80bc:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00d80c0:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00d80c4:  98 13 21 00  or  %o4, 0x100, %o4
a00d80c8:  da 0c 60 46  ldub  [ %l1 + 0x46 ], %o5
a00d80cc:  c2 2a e0 43  stb  %g1, [ %o3 + 0x43 ]
a00d80d0:  80 a3 60 11  cmp  %o5, 0x11
a00d80d4:  18 80 00 07  bgu  0xa00d80f0
a00d80d8:  d8 27 bf a8  st  %o4, [ %fp + -88 ]
a00d80dc:  03 3f ff e3  sethi  %hi(0xffff8c00), %g1
a00d80e0:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff8fff
a00d80e4:  82 0b 00 01  and  %o4, %g1, %g1
a00d80e8:  10 80 00 06  b  0xa00d8100
a00d80ec:  1b 00 00 0c  sethi  %hi(0x3000), %o5
a00d80f0:  03 3f ff e3  sethi  %hi(0xffff8c00), %g1
a00d80f4:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff8fff
a00d80f8:  82 0b 00 01  and  %o4, %g1, %g1
a00d80fc:  1b 00 00 08  sethi  %hi(0x2000), %o5
a00d8100:  82 10 40 0d  or  %g1, %o5, %g1
a00d8104:  c2 27 bf a8  st  %g1, [ %fp + -88 ]
a00d8108:  c2 0a e0 43  ldub  [ %o3 + 0x43 ], %g1
a00d810c:  80 88 60 01  btst  1, %g1
a00d8110:  02 80 00 05  be  0xa00d8124
a00d8114:  9a 0d 60 ff  and  %l5, 0xff, %o5
a00d8118:  c2 07 bf a8  ld  [ %fp + -88 ], %g1
a00d811c:  10 80 00 04  b  0xa00d812c
a00d8120:  82 10 60 80  or  %g1, 0x80, %g1
a00d8124:  c2 07 bf a8  ld  [ %fp + -88 ], %g1
a00d8128:  82 08 7f 7f  and  %g1, -129, %g1
a00d812c:  a1 2b 60 02  sll  %o5, 2, %l0
a00d8130:  a0 04 00 0d  add  %l0, %o5, %l0
a00d8134:  a1 2c 20 02  sll  %l0, 2, %l0
a00d8138:  a8 07 bf f8  add  %fp, -8, %l4
a00d813c:  c2 27 bf a8  st  %g1, [ %fp + -88 ]
a00d8140:  a0 04 00 14  add  %l0, %l4, %l0
a00d8144:  c2 04 3f 88  ld  [ %l0 + -120 ], %g1
a00d8148:  82 10 60 40  or  %g1, 0x40, %g1
a00d814c:  da 0c 60 46  ldub  [ %l1 + 0x46 ], %o5
a00d8150:  82 08 7f df  and  %g1, -33, %g1
a00d8154:  96 10 20 0f  mov  0xf, %o3
a00d8158:  c2 24 3f 88  st  %g1, [ %l0 + -120 ]
a00d815c:  da 2c 3f 8c  stb  %o5, [ %l0 + -116 ]
a00d8160:  98 10 00 13  mov  %l3, %o4
a00d8164:  90 10 20 00  clr  %o0
a00d8168:  92 10 20 90  mov  0x90, %o1
a00d816c:  40 3a f8 a5  call  0xa0f96400
a00d8170:  94 10 20 30  mov  0x30, %o2
a00d8174:  96 10 20 00  clr  %o3
a00d8178:  82 0a e0 ff  and  %o3, 0xff, %g1
a00d817c:  9a 05 00 01  add  %l4, %g1, %o5
a00d8180:  d8 0b 7f f0  ldub  [ %o5 + -16 ], %o4
a00d8184:  96 02 e0 01  inc  %o3
a00d8188:  82 04 00 01  add  %l0, %g1, %g1
a00d818c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00d8190:  80 a3 60 0f  cmp  %o5, 0xf
a00d8194:  08 bf ff f9  bleu  0xa00d8178
a00d8198:  d8 28 7f 8d  stb  %o4, [ %g1 + -115 ]
a00d819c:  c2 04 3f 9c  ld  [ %l0 + -100 ], %g1
a00d81a0:  1b 00 3c 00  sethi  %hi(0xf00000), %o5
a00d81a4:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d81a8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d81ac:  d6 08 60 32  ldub  [ %g1 + 0x32 ], %o3	! 0xa8078832
a00d81b0:  19 00 03 c0  sethi  %hi(0xf0000), %o4
a00d81b4:  98 2b 40 0c  andn  %o5, %o4, %o4
a00d81b8:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00d81bc:  da 10 60 46  lduh  [ %g1 + 0x46 ], %o5	! 0xa00b3846
a00d81c0:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00d81c4:  d8 24 3f 9c  st  %o4, [ %l0 + -100 ]
a00d81c8:  82 10 60 a4  or  %g1, 0xa4, %g1
a00d81cc:  97 2a e0 02  sll  %o3, 2, %o3
a00d81d0:  d8 00 40 0b  ld  [ %g1 + %o3 ], %o4
a00d81d4:  9b 2b 60 02  sll  %o5, 2, %o5
a00d81d8:  c2 03 00 0d  ld  [ %o4 + %o5 ], %g1
a00d81dc:  10 80 00 25  b  0xa00d8270
a00d81e0:  82 10 60 01  or  %g1, 1, %g1
a00d81e4:  03 00 00 20  sethi  %hi(0x8000), %g1
a00d81e8:  82 2b 40 01  andn  %o5, %g1, %g1
a00d81ec:  1b 00 00 1c  sethi  %hi(0x7000), %o5
a00d81f0:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d81f4:  9a 0b 70 ff  and  %o5, -3841, %o5
a00d81f8:  9a 13 61 00  or  %o5, 0x100, %o5
a00d81fc:  9a 0b 7f 1f  and  %o5, -225, %o5
a00d8200:  da 27 bf a8  st  %o5, [ %fp + -88 ]
a00d8204:  c0 2f bf ac  clrb  [ %fp + -84 ]
a00d8208:  96 10 20 00  clr  %o3
a00d820c:  94 07 a0 20  add  %fp, 0x20, %o2
a00d8210:  82 0a e0 ff  and  %o3, 0xff, %g1
a00d8214:  96 02 e0 01  inc  %o3
a00d8218:  82 02 80 01  add  %o2, %g1, %g1
a00d821c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00d8220:  80 a3 60 0f  cmp  %o5, 0xf
a00d8224:  08 bf ff fb  bleu  0xa00d8210
a00d8228:  c0 28 7f 8d  clrb  [ %g1 + -115 ]
a00d822c:  c2 02 bf 9c  ld  [ %o2 + -100 ], %g1
a00d8230:  1b 00 3c 00  sethi  %hi(0xf00000), %o5
a00d8234:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d8238:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d823c:  d6 08 60 32  ldub  [ %g1 + 0x32 ], %o3	! 0xa8078832
a00d8240:  19 00 03 c0  sethi  %hi(0xf0000), %o4
a00d8244:  98 2b 40 0c  andn  %o5, %o4, %o4
a00d8248:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00d824c:  da 10 60 46  lduh  [ %g1 + 0x46 ], %o5	! 0xa00b3846
a00d8250:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00d8254:  d8 22 bf 9c  st  %o4, [ %o2 + -100 ]
a00d8258:  82 10 60 a4  or  %g1, 0xa4, %g1
a00d825c:  97 2a e0 02  sll  %o3, 2, %o3
a00d8260:  d8 00 40 0b  ld  [ %g1 + %o3 ], %o4
a00d8264:  9b 2b 60 02  sll  %o5, 2, %o5
a00d8268:  c2 03 00 0d  ld  [ %o4 + %o5 ], %g1
a00d826c:  82 08 7f fe  and  %g1, -2, %g1
a00d8270:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a00d8274:  a4 04 a0 14  add  %l2, 0x14, %l2
a00d8278:  aa 05 60 01  inc  %l5
a00d827c:  9a 0d 60 ff  and  %l5, 0xff, %o5
a00d8280:  83 35 a0 10  srl  %l6, 0x10, %g1
a00d8284:  80 a3 40 01  cmp  %o5, %g1
a00d8288:  0a bf ff 2f  bcs  0xa00d7f44
a00d828c:  82 0d 60 ff  and  %l5, 0xff, %g1
a00d8290:  99 2c a0 10  sll  %l2, 0x10, %o4
a00d8294:  99 33 20 10  srl  %o4, 0x10, %o4
a00d8298:  90 07 bf 70  add  %fp, -144, %o0
a00d829c:  92 10 20 02  mov  2, %o1
a00d82a0:  94 10 20 01  mov  1, %o2
a00d82a4:  7f ff fd 9e  call  0xa00d791c
a00d82a8:  96 10 20 00  clr  %o3
a00d82ac:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d82b0:  9a 10 20 01  mov  1, %o5
a00d82b4:  da 28 60 40  stb  %o5, [ %g1 + 0x40 ]
a00d82b8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00d82bc:  c0 30 63 f8  clrh  [ %g1 + 0x3f8 ]	! 0xa80787f8
a00d82c0:  81 c7 e0 08  ret
a00d82c4:  81 e8 00 00  restore
