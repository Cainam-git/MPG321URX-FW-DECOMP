# leon2m FUN_a00c7e3c 0xa00c7e3c-0xa00c8410 (1492 bytes)
a00c7e3c:  9d e3 bf 98  save  %sp, -104, %sp
a00c7e40:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c7e44:  80 a6 20 02  cmp  %i0, 2
a00c7e48:  02 80 00 d8  be  0xa00c81a8
a00c7e4c:  80 a6 20 03  cmp  %i0, 3
a00c7e50:  02 80 00 fd  be  0xa00c8244
a00c7e54:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c7e58:  c2 0a 60 d6  ldub  [ %o1 + 0xd6 ], %g1	! 0xa802d0d6
a00c7e5c:  94 08 60 ff  and  %g1, 0xff, %o2
a00c7e60:  98 02 bf d0  add  %o2, -48, %o4
a00c7e64:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c7e68:  96 10 00 0c  mov  %o4, %o3
a00c7e6c:  80 a3 60 02  cmp  %o5, 2
a00c7e70:  18 80 01 66  bgu  0xa00c8408
a00c7e74:  94 10 20 ff  mov  0xff, %o2
a00c7e78:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00c7e7c:  9e 14 a2 90  or  %l2, 0x290, %o7	! 0xa802d290
a00c7e80:  80 a3 60 00  cmp  %o5, 0
a00c7e84:  12 80 00 90  bne  0xa00c80c4
a00c7e88:  d8 2b e0 1f  stb  %o4, [ %o7 + 0x1f ]
a00c7e8c:  9e 14 a2 90  or  %l2, 0x290, %o7
a00c7e90:  d0 0b e0 1f  ldub  [ %o7 + 0x1f ], %o0
a00c7e94:  80 a2 20 01  cmp  %o0, 1
a00c7e98:  02 80 00 a1  be  0xa00c811c
a00c7e9c:  80 a6 20 02  cmp  %i0, 2
a00c7ea0:  96 14 a2 90  or  %l2, 0x290, %o3
a00c7ea4:  de 0a e0 1f  ldub  [ %o3 + 0x1f ], %o7
a00c7ea8:  80 a3 e0 02  cmp  %o7, 2
a00c7eac:  12 80 00 28  bne  0xa00c7f4c
a00c7eb0:  80 a6 20 02  cmp  %i0, 2
a00c7eb4:  02 80 01 0a  be  0xa00c82dc
a00c7eb8:  80 a6 20 03  cmp  %i0, 3
a00c7ebc:  02 80 01 2d  be  0xa00c8370
a00c7ec0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c7ec4:  c2 0c 20 df  ldub  [ %l0 + 0xdf ], %g1	! 0xa802d0df
a00c7ec8:  92 08 60 ff  and  %g1, 0xff, %o1
a00c7ecc:  98 02 7f d0  add  %o1, -48, %o4
a00c7ed0:  a2 0b 20 ff  and  %o4, 0xff, %l1
a00c7ed4:  80 a4 60 02  cmp  %l1, 2
a00c7ed8:  18 80 01 4c  bgu  0xa00c8408
a00c7edc:  94 10 20 ff  mov  0xff, %o2
a00c7ee0:  94 14 a2 90  or  %l2, 0x290, %o2
a00c7ee4:  80 a6 20 02  cmp  %i0, 2
a00c7ee8:  02 80 01 18  be  0xa00c8348
a00c7eec:  d8 2a a0 2f  stb  %o4, [ %o2 + 0x2f ]
a00c7ef0:  80 a6 20 03  cmp  %i0, 3
a00c7ef4:  02 80 01 22  be  0xa00c837c
a00c7ef8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c7efc:  c2 0b e0 e0  ldub  [ %o7 + 0xe0 ], %g1	! 0xa802d0e0
a00c7f00:  98 08 60 ff  and  %g1, 0xff, %o4
a00c7f04:  96 03 3f d0  add  %o4, -48, %o3
a00c7f08:  90 0a e0 ff  and  %o3, 0xff, %o0
a00c7f0c:  80 a2 20 03  cmp  %o0, 3
a00c7f10:  18 80 01 3e  bgu  0xa00c8408
a00c7f14:  94 10 20 ff  mov  0xff, %o2
a00c7f18:  a2 14 a2 90  or  %l2, 0x290, %l1
a00c7f1c:  40 01 f1 a0  call  0xa014459c
a00c7f20:  e0 0c 60 1e  ldub  [ %l1 + 0x1e ], %l0
a00c7f24:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00c7f28:  80 a3 40 10  cmp  %o5, %l0
a00c7f2c:  02 80 00 08  be  0xa00c7f4c
a00c7f30:  d0 2c 60 1e  stb  %o0, [ %l1 + 0x1e ]
a00c7f34:  40 00 44 c1  call  0xa00d9238
a00c7f38:  01 00 00 00  nop
a00c7f3c:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a00c7f40:  c2 12 63 f4  lduh  [ %o1 + 0x3f4 ], %g1	! 0xa802cff4
a00c7f44:  94 10 64 00  or  %g1, 0x400, %o2
a00c7f48:  d4 32 63 f4  sth  %o2, [ %o1 + 0x3f4 ]
a00c7f4c:  40 00 44 ac  call  0xa00d91fc
a00c7f50:  90 10 20 00  clr  %o0
a00c7f54:  9a 14 a2 90  or  %l2, 0x290, %o5
a00c7f58:  d0 0b 60 1f  ldub  [ %o5 + 0x1f ], %o0
a00c7f5c:  80 a2 20 00  cmp  %o0, 0
a00c7f60:  22 80 00 1b  be,a   0xa00c7fcc
a00c7f64:  90 10 20 00  clr  %o0
a00c7f68:  d8 03 60 ac  ld  [ %o5 + 0xac ], %o4
a00c7f6c:  03 00 04 00  sethi  %hi(0x100000), %g1
a00c7f70:  80 8b 00 01  btst  %o4, %g1
a00c7f74:  12 80 00 ea  bne  0xa00c831c
a00c7f78:  9e 2b 00 01  andn  %o4, %g1, %o7
a00c7f7c:  a0 14 a2 90  or  %l2, 0x290, %l0
a00c7f80:  d6 0c 20 4a  ldub  [ %l0 + 0x4a ], %o3
a00c7f84:  80 a2 e0 01  cmp  %o3, 1
a00c7f88:  22 80 01 07  be,a   0xa00c83a4
a00c7f8c:  c0 2c 20 4a  clrb  [ %l0 + 0x4a ]
a00c7f90:  d8 04 20 b0  ld  [ %l0 + 0xb0 ], %o4
a00c7f94:  80 a3 20 00  cmp  %o4, 0
a00c7f98:  12 80 00 de  bne  0xa00c8310
a00c7f9c:  01 00 00 00  nop
a00c7fa0:  7f fe ee 11  call  0xa00837e4
a00c7fa4:  01 00 00 00  nop
a00c7fa8:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00c7fac:  80 a4 60 01  cmp  %l1, 1
a00c7fb0:  22 80 00 f9  be,a   0xa00c8394
a00c7fb4:  c0 2c 21 a4  clrb  [ %l0 + 0x1a4 ]
a00c7fb8:  da 04 20 a8  ld  [ %l0 + 0xa8 ], %o5
a00c7fbc:  80 8b 60 80  btst  0x80, %o5
a00c7fc0:  12 80 00 ca  bne  0xa00c82e8
a00c7fc4:  01 00 00 00  nop
a00c7fc8:  90 10 20 00  clr  %o0	! 0x0
a00c7fcc:  40 02 00 a7  call  0xa0148268
a00c7fd0:  92 10 20 01  mov  1, %o1
a00c7fd4:  90 10 20 01  mov  1, %o0
a00c7fd8:  40 02 00 a4  call  0xa0148268
a00c7fdc:  92 10 20 01  mov  1, %o1
a00c7fe0:  40 00 48 9d  call  0xa00da254
a00c7fe4:  01 00 00 00  nop
a00c7fe8:  40 00 43 0d  call  0xa00d8c1c
a00c7fec:  01 00 00 00  nop
a00c7ff0:  40 00 32 6a  call  0xa00d4998
a00c7ff4:  01 00 00 00  nop
a00c7ff8:  82 14 a2 90  or  %l2, 0x290, %g1
a00c7ffc:  e0 00 60 a8  ld  [ %g1 + 0xa8 ], %l0
a00c8000:  25 00 00 10  sethi  %hi(0x4000), %l2
a00c8004:  80 8c 00 12  btst  %l0, %l2
a00c8008:  12 80 00 6b  bne  0xa00c81b4
a00c800c:  01 00 00 00  nop
a00c8010:  7f ff c2 2f  call  0xa00b88cc
a00c8014:  01 00 00 00  nop
a00c8018:  80 a6 20 02  cmp  %i0, 2
a00c801c:  02 80 00 6e  be  0xa00c81d4
a00c8020:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c8024:  80 a6 20 03  cmp  %i0, 3
a00c8028:  02 80 00 8d  be  0xa00c825c
a00c802c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c8030:  94 13 60 78  or  %o5, 0x78, %o2	! 0xa802d078
a00c8034:  9e 10 20 30  mov  0x30, %o7
a00c8038:  92 10 20 35  mov  0x35, %o1
a00c803c:  a2 10 20 36  mov  0x36, %l1
a00c8040:  98 10 20 2b  mov  0x2b, %o4
a00c8044:  96 10 20 0d  mov  0xd, %o3
a00c8048:  d2 2b 60 78  stb  %o1, [ %o5 + 0x78 ]
a00c804c:  e2 2a a0 01  stb  %l1, [ %o2 + 1 ]
a00c8050:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00c8054:  d8 2a a0 04  stb  %o4, [ %o2 + 4 ]
a00c8058:  d6 2a a0 05  stb  %o3, [ %o2 + 5 ]
a00c805c:  80 a6 20 02  cmp  %i0, 2
a00c8060:  02 80 00 69  be  0xa00c8204
a00c8064:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00c8068:  80 a6 20 03  cmp  %i0, 3
a00c806c:  02 80 00 89  be  0xa00c8290
a00c8070:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c8074:  9e 12 e0 d0  or  %o3, 0xd0, %o7	! 0xa802d0d0
a00c8078:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00c807c:  c0 2b 20 9c  clrb  [ %o4 + 0x9c ]	! 0xa802b09c
a00c8080:  c0 2a e0 d0  clrb  [ %o3 + 0xd0 ]
a00c8084:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00c8088:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00c808c:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00c8090:  80 a6 20 02  cmp  %i0, 2
a00c8094:  02 80 00 65  be  0xa00c8228
a00c8098:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00c809c:  80 a6 20 03  cmp  %i0, 3
a00c80a0:  12 80 00 65  bne  0xa00c8234
a00c80a4:  90 10 00 18  mov  %i0, %o0
a00c80a8:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c80ac:  94 13 61 08  or  %o5, 0x108, %o2	! 0xa802d108
a00c80b0:  90 10 20 03  mov  3, %o0
a00c80b4:  40 02 01 cd  call  0xa01487e8
a00c80b8:  92 10 20 06  mov  6, %o1
a00c80bc:  10 80 00 d3  b  0xa00c8408
a00c80c0:  94 10 20 00  clr  %o2
a00c80c4:  80 a3 60 01  cmp  %o5, 1
a00c80c8:  02 80 00 7c  be  0xa00c82b8
a00c80cc:  80 a3 60 02  cmp  %o5, 2
a00c80d0:  02 80 00 a1  be  0xa00c8354
a00c80d4:  80 a6 20 02  cmp  %i0, 2
a00c80d8:  92 02 ff d0  add  %o3, -48, %o1
a00c80dc:  90 0a 60 ff  and  %o1, 0xff, %o0
a00c80e0:  80 a2 20 03  cmp  %o0, 3
a00c80e4:  18 80 00 c9  bgu  0xa00c8408
a00c80e8:  94 10 20 ff  mov  0xff, %o2
a00c80ec:  40 01 f1 2c  call  0xa014459c
a00c80f0:  01 00 00 00  nop
a00c80f4:  94 14 a2 90  or  %l2, 0x290, %o2
a00c80f8:  d0 2a a0 20  stb  %o0, [ %o2 + 0x20 ]
a00c80fc:  40 00 36 0f  call  0xa00d5938
a00c8100:  90 10 20 01  mov  1, %o0
a00c8104:  9e 14 a2 90  or  %l2, 0x290, %o7
a00c8108:  d0 0b e0 1f  ldub  [ %o7 + 0x1f ], %o0
a00c810c:  80 a2 20 01  cmp  %o0, 1
a00c8110:  12 bf ff 65  bne  0xa00c7ea4
a00c8114:  96 14 a2 90  or  %l2, 0x290, %o3
a00c8118:  80 a6 20 02  cmp  %i0, 2
a00c811c:  02 80 00 4d  be  0xa00c8250
a00c8120:  80 a6 20 03  cmp  %i0, 3
a00c8124:  02 80 00 a4  be  0xa00c83b4
a00c8128:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c812c:  c2 0b 60 d9  ldub  [ %o5 + 0xd9 ], %g1	! 0xa802d0d9
a00c8130:  a2 08 60 ff  and  %g1, 0xff, %l1
a00c8134:  98 04 7f d0  add  %l1, -48, %o4
a00c8138:  a0 0b 20 ff  and  %o4, 0xff, %l0
a00c813c:  80 a4 20 02  cmp  %l0, 2
a00c8140:  18 80 00 b2  bgu  0xa00c8408
a00c8144:  94 10 20 ff  mov  0xff, %o2
a00c8148:  94 10 20 02  mov  2, %o2
a00c814c:  82 22 80 0c  sub  %o2, %o4, %g1
a00c8150:  92 14 a2 90  or  %l2, 0x290, %o1
a00c8154:  80 a6 20 02  cmp  %i0, 2
a00c8158:  02 80 00 8c  be  0xa00c8388
a00c815c:  c2 2a 60 31  stb  %g1, [ %o1 + 0x31 ]
a00c8160:  80 a6 20 03  cmp  %i0, 3
a00c8164:  02 80 00 97  be  0xa00c83c0
a00c8168:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c816c:  c2 0a e0 da  ldub  [ %o3 + 0xda ], %g1	! 0xa802d0da
a00c8170:  9a 08 60 ff  and  %g1, 0xff, %o5
a00c8174:  98 03 7f d0  add  %o5, -48, %o4
a00c8178:  82 0b 20 ff  and  %o4, 0xff, %g1
a00c817c:  80 a0 60 04  cmp  %g1, 4
a00c8180:  18 80 00 a2  bgu  0xa00c8408
a00c8184:  94 10 20 ff  mov  0xff, %o2
a00c8188:  a0 14 a2 90  or  %l2, 0x290, %l0
a00c818c:  90 08 60 0f  and  %g1, 0xf, %o0
a00c8190:  c2 04 20 30  ld  [ %l0 + 0x30 ], %g1
a00c8194:  95 2a 20 04  sll  %o0, 4, %o2
a00c8198:  92 08 7f 0f  and  %g1, -241, %o1
a00c819c:  a2 12 40 0a  or  %o1, %o2, %l1
a00c81a0:  10 bf ff 40  b  0xa00c7ea0
a00c81a4:  e2 24 20 30  st  %l1, [ %l0 + 0x30 ]
a00c81a8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c81ac:  10 bf ff 2c  b  0xa00c7e5c
a00c81b0:  c2 08 60 46  ldub  [ %g1 + 0x46 ], %g1	! 0xa802d046
a00c81b4:  40 00 36 c9  call  0xa00d5cd8
a00c81b8:  01 00 00 00  nop
a00c81bc:  7f ff c1 c4  call  0xa00b88cc
a00c81c0:  01 00 00 00  nop
a00c81c4:  80 a6 20 02  cmp  %i0, 2
a00c81c8:  12 bf ff 98  bne  0xa00c8028
a00c81cc:  80 a6 20 03  cmp  %i0, 3
a00c81d0:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c81d4:  b0 14 61 28  or  %l1, 0x128, %i0	! 0xa802d128
a00c81d8:  90 10 20 30  mov  0x30, %o0
a00c81dc:  9a 10 20 35  mov  0x35, %o5
a00c81e0:  98 10 20 0d  mov  0xd, %o4
a00c81e4:  96 10 20 36  mov  0x36, %o3
a00c81e8:  9e 10 20 2b  mov  0x2b, %o7
a00c81ec:  da 2c 61 28  stb  %o5, [ %l1 + 0x128 ]
a00c81f0:  d8 2e 20 05  stb  %o4, [ %i0 + 5 ]
a00c81f4:  d6 2e 20 01  stb  %o3, [ %i0 + 1 ]
a00c81f8:  d0 2e 20 03  stb  %o0, [ %i0 + 3 ]
a00c81fc:  de 2e 20 04  stb  %o7, [ %i0 + 4 ]
a00c8200:  d0 2e 20 02  stb  %o0, [ %i0 + 2 ]
a00c8204:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00c8208:  94 14 a0 40  or  %l2, 0x40, %o2	! 0xa802d040
a00c820c:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00c8210:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00c8214:  c0 2c a0 40  clrb  [ %l2 + 0x40 ]
a00c8218:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c821c:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c8220:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c8224:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c8228:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c822c:  94 14 61 28  or  %l1, 0x128, %o2	! 0xa802d128
a00c8230:  90 10 20 02  mov  2, %o0
a00c8234:  40 02 01 6d  call  0xa01487e8
a00c8238:  92 10 20 06  mov  6, %o1
a00c823c:  10 80 00 73  b  0xa00c8408
a00c8240:  94 10 20 00  clr  %o2
a00c8244:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c8248:  10 bf ff 05  b  0xa00c7e5c
a00c824c:  c2 0a 20 9e  ldub  [ %o0 + 0x9e ], %g1	! 0xa802d09e
a00c8250:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c8254:  10 bf ff b7  b  0xa00c8130
a00c8258:  c2 0a e0 49  ldub  [ %o3 + 0x49 ], %g1	! 0xa802d049
a00c825c:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c8260:  92 16 21 08  or  %i0, 0x108, %o1	! 0xa802d108
a00c8264:  94 10 20 30  mov  0x30, %o2
a00c8268:  90 10 20 35  mov  0x35, %o0
a00c826c:  82 10 20 0d  mov  0xd, %g1
a00c8270:  a0 10 20 36  mov  0x36, %l0
a00c8274:  a4 10 20 2b  mov  0x2b, %l2
a00c8278:  d0 2e 21 08  stb  %o0, [ %i0 + 0x108 ]
a00c827c:  c2 2a 60 05  stb  %g1, [ %o1 + 5 ]
a00c8280:  e0 2a 60 01  stb  %l0, [ %o1 + 1 ]
a00c8284:  d4 2a 60 03  stb  %o2, [ %o1 + 3 ]
a00c8288:  e4 2a 60 04  stb  %l2, [ %o1 + 4 ]
a00c828c:  d4 2a 60 02  stb  %o2, [ %o1 + 2 ]
a00c8290:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c8294:  b0 12 20 98  or  %o0, 0x98, %i0	! 0xa802d098
a00c8298:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c829c:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c82a0:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00c82a4:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00c82a8:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00c82ac:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00c82b0:  10 bf ff 7e  b  0xa00c80a8
a00c82b4:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00c82b8:  80 a6 20 02  cmp  %i0, 2
a00c82bc:  02 80 00 48  be  0xa00c83dc
a00c82c0:  80 a6 20 03  cmp  %i0, 3
a00c82c4:  02 80 00 4e  be  0xa00c83fc
a00c82c8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c82cc:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c82d0:  c2 0b 60 d8  ldub  [ %o5 + 0xd8 ], %g1	! 0xa802d0d8
a00c82d4:  10 bf ff 81  b  0xa00c80d8
a00c82d8:  96 10 00 01  mov  %g1, %o3
a00c82dc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c82e0:  10 bf fe fa  b  0xa00c7ec8
a00c82e4:  c2 0b 20 4f  ldub  [ %o4 + 0x4f ], %g1	! 0xa802d04f
a00c82e8:  7f ff 23 3c  call  0xa0090fd8
a00c82ec:  01 00 00 00  nop
a00c82f0:  d4 04 20 a8  ld  [ %l0 + 0xa8 ], %o2
a00c82f4:  92 0a bf 7f  and  %o2, -129, %o1
a00c82f8:  40 01 73 13  call  0xa0124f44
a00c82fc:  d2 24 20 a8  st  %o1, [ %l0 + 0xa8 ]
a00c8300:  40 00 47 a1  call  0xa00da184
a00c8304:  01 00 00 00  nop
a00c8308:  10 bf ff 31  b  0xa00c7fcc
a00c830c:  90 10 20 00  clr  %o0	! 0x0
a00c8310:  40 00 37 0b  call  0xa00d5f3c
a00c8314:  c0 24 20 b0  clr  [ %l0 + 0xb0 ]
a00c8318:  30 bf ff 22  b,a   0xa00c7fa0
a00c831c:  de 23 60 ac  st  %o7, [ %o5 + 0xac ]
a00c8320:  40 01 f0 b7  call  0xa01445fc
a00c8324:  d0 0b 60 1e  ldub  [ %o5 + 0x1e ], %o0
a00c8328:  80 8a 20 ff  btst  0xff, %o0
a00c832c:  32 bf ff 15  bne,a   0xa00c7f80
a00c8330:  a0 14 a2 90  or  %l2, 0x290, %l0
a00c8334:  90 10 20 01  mov  1, %o0
a00c8338:  40 01 ed a8  call  0xa01439d8
a00c833c:  92 10 20 01  mov  1, %o1
a00c8340:  10 bf ff 10  b  0xa00c7f80
a00c8344:  a0 14 a2 90  or  %l2, 0x290, %l0
a00c8348:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c834c:  10 bf fe ed  b  0xa00c7f00
a00c8350:  c2 08 60 50  ldub  [ %g1 + 0x50 ], %g1	! 0xa802d050
a00c8354:  02 80 00 26  be  0xa00c83ec
a00c8358:  80 a6 20 03  cmp  %i0, 3
a00c835c:  02 80 00 1c  be  0xa00c83cc
a00c8360:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c8364:  c2 08 60 e1  ldub  [ %g1 + 0xe1 ], %g1	! 0xa802d0e1
a00c8368:  10 bf ff 5c  b  0xa00c80d8
a00c836c:  96 10 00 01  mov  %g1, %o3
a00c8370:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c8374:  10 bf fe d5  b  0xa00c7ec8
a00c8378:  c2 0b 60 a7  ldub  [ %o5 + 0xa7 ], %g1	! 0xa802d0a7
a00c837c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c8380:  10 bf fe e0  b  0xa00c7f00
a00c8384:  c2 0a 20 a8  ldub  [ %o0 + 0xa8 ], %g1	! 0xa802d0a8
a00c8388:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c838c:  10 bf ff 79  b  0xa00c8170
a00c8390:  c2 0a 20 4a  ldub  [ %o0 + 0x4a ], %g1	! 0xa802d04a
a00c8394:  7f fe eb 58  call  0xa00830f4
a00c8398:  90 10 20 00  clr  %o0
a00c839c:  10 bf ff 08  b  0xa00c7fbc
a00c83a0:  da 04 20 a8  ld  [ %l0 + 0xa8 ], %o5
a00c83a4:  40 00 36 c2  call  0xa00d5eac
a00c83a8:  90 10 20 00  clr  %o0
a00c83ac:  10 bf fe fa  b  0xa00c7f94
a00c83b0:  d8 04 20 b0  ld  [ %l0 + 0xb0 ], %o4
a00c83b4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c83b8:  10 bf ff 5e  b  0xa00c8130
a00c83bc:  c2 0b 20 a1  ldub  [ %o4 + 0xa1 ], %g1	! 0xa802d0a1
a00c83c0:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c83c4:  10 bf ff 6b  b  0xa00c8170
a00c83c8:  c2 0b e0 a2  ldub  [ %o7 + 0xa2 ], %g1	! 0xa802d0a2
a00c83cc:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c83d0:  c2 0c 60 a9  ldub  [ %l1 + 0xa9 ], %g1	! 0xa802d0a9
a00c83d4:  10 bf ff 41  b  0xa00c80d8
a00c83d8:  96 10 00 01  mov  %g1, %o3
a00c83dc:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c83e0:  c2 0a e0 48  ldub  [ %o3 + 0x48 ], %g1	! 0xa802d048
a00c83e4:  10 bf ff 3d  b  0xa00c80d8
a00c83e8:  96 10 00 01  mov  %g1, %o3
a00c83ec:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c83f0:  c2 0c 20 51  ldub  [ %l0 + 0x51 ], %g1	! 0xa802d051
a00c83f4:  10 bf ff 39  b  0xa00c80d8
a00c83f8:  96 10 00 01  mov  %g1, %o3
a00c83fc:  c2 0b 20 a0  ldub  [ %o4 + 0xa0 ], %g1
a00c8400:  10 bf ff 36  b  0xa00c80d8
a00c8404:  96 10 00 01  mov  %g1, %o3
a00c8408:  81 c7 e0 08  ret
a00c840c:  91 e8 00 0a  restore  %g0, %o2, %o0
