# leon2m FUN_a00b7f9c 0xa00b7f9c-0xa00b83e4 (1096 bytes)
a00b7f9c:  9d e3 bf 98  save  %sp, -104, %sp
a00b7fa0:  90 10 20 00  clr  %o0
a00b7fa4:  40 02 3b 87  call  0xa0146dc0
a00b7fa8:  92 10 20 00  clr  %o1
a00b7fac:  94 10 20 00  clr  %o2
a00b7fb0:  90 10 20 08  mov  8, %o0
a00b7fb4:  40 02 3b 23  call  0xa0146c40
a00b7fb8:  92 10 20 00  clr  %o1
a00b7fbc:  92 10 20 24  mov  0x24, %o1
a00b7fc0:  33 2a 00 ac  sethi  %hi(0xa802b000), %i1
a00b7fc4:  d2 2e 60 8f  stb  %o1, [ %i1 + 0x8f ]	! 0xa802b08f
a00b7fc8:  90 10 20 00  clr  %o0
a00b7fcc:  40 02 3b 7d  call  0xa0146dc0
a00b7fd0:  92 10 20 01  mov  1, %o1
a00b7fd4:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a00b7fd8:  98 14 a3 f4  or  %l2, 0x3f4, %o4	! 0xa802cff4
a00b7fdc:  da 13 20 3e  lduh  [ %o4 + 0x3e ], %o5
a00b7fe0:  11 3f ff e0  sethi  %hi(0xffff8000), %o0
a00b7fe4:  82 2b 40 08  andn  %o5, %o0, %g1
a00b7fe8:  67 ff 58 af  call  0x4008e2a4
a00b7fec:  c2 33 20 3e  sth  %g1, [ %o4 + 0x3e ]
a00b7ff0:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00b7ff4:  80 a4 20 11  cmp  %l0, 0x11
a00b7ff8:  02 80 00 4a  be  0xa00b8120
a00b7ffc:  01 00 00 00  nop
a00b8000:  7f ff f4 36  call  0xa00b50d8
a00b8004:  90 10 20 03  mov  3, %o0	! 0x3
a00b8008:  90 10 20 00  clr  %o0
a00b800c:  40 02 3b 6d  call  0xa0146dc0
a00b8010:  92 10 20 00  clr  %o1
a00b8014:  90 10 20 08  mov  8, %o0
a00b8018:  92 10 20 00  clr  %o1
a00b801c:  40 02 3b 09  call  0xa0146c40
a00b8020:  94 10 20 00  clr  %o2
a00b8024:  96 10 20 00  clr  %o3
a00b8028:  98 10 20 00  clr  %o4
a00b802c:  90 10 20 00  clr  %o0
a00b8030:  92 10 20 00  clr  %o1
a00b8034:  40 02 39 85  call  0xa0146648
a00b8038:  94 10 20 00  clr  %o2
a00b803c:  90 10 20 0e  mov  0xe, %o0
a00b8040:  92 10 20 05  mov  5, %o1
a00b8044:  40 02 38 3e  call  0xa014613c
a00b8048:  94 10 20 00  clr  %o2
a00b804c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00b8050:  9e 14 62 90  or  %l1, 0x290, %o7	! 0xa802d290
a00b8054:  d2 0b e0 0e  ldub  [ %o7 + 0xe ], %o1
a00b8058:  d0 0b e0 0d  ldub  [ %o7 + 0xd ], %o0
a00b805c:  40 02 39 2f  call  0xa0146518
a00b8060:  94 10 20 00  clr  %o2
a00b8064:  92 10 20 00  clr  %o1
a00b8068:  40 02 3a 92  call  0xa0146ab0
a00b806c:  90 10 27 92  mov  0x792, %o0
a00b8070:  40 02 38 26  call  0xa0146108
a00b8074:  90 10 20 00  clr  %o0
a00b8078:  90 10 20 00  clr  %o0
a00b807c:  7f ff b5 a6  call  0xa00a5714
a00b8080:  92 10 20 00  clr  %o1
a00b8084:  90 10 20 32  mov  0x32, %o0
a00b8088:  92 10 20 32  mov  0x32, %o1
a00b808c:  40 02 39 23  call  0xa0146518
a00b8090:  94 10 20 00  clr  %o2
a00b8094:  90 10 20 64  mov  0x64, %o0
a00b8098:  40 02 3a ae  call  0xa0146b50
a00b809c:  92 10 20 00  clr  %o1
a00b80a0:  90 10 20 02  mov  2, %o0
a00b80a4:  40 02 3a b2  call  0xa0146b6c
a00b80a8:  92 10 20 00  clr  %o1
a00b80ac:  90 10 27 92  mov  0x792, %o0
a00b80b0:  40 02 3a 80  call  0xa0146ab0
a00b80b4:  92 10 20 00  clr  %o1
a00b80b8:  82 04 3f ef  add  %l0, -17, %g1
a00b80bc:  80 a0 60 0d  cmp  %g1, 0xd
a00b80c0:  18 80 00 15  bgu  0xa00b8114
a00b80c4:  f0 2e 60 8f  stb  %i0, [ %i1 + 0x8f ]
a00b80c8:  33 00 01 4c  sethi  %hi(0x53000), %i1
a00b80cc:  a1 28 60 02  sll  %g1, 2, %l0
a00b80d0:  b0 16 62 ac  or  %i1, 0x2ac, %i0
a00b80d4:  d4 06 00 10  ld  [ %i0 + %l0 ], %o2
a00b80d8:  81 c2 80 00  jmp  %o2
a00b80dc:  01 00 00 00  nop
a00b80e0:  82 14 62 90  or  %l1, 0x290, %g1
a00b80e4:  19 00 06 4b  sethi  %hi(0x192c00), %o4
a00b80e8:  d2 08 60 08  ldub  [ %g1 + 8 ], %o1
a00b80ec:  90 13 21 8c  or  %o4, 0x18c, %o0
a00b80f0:  7f ff ad d5  call  0xa00a3844
a00b80f4:  01 00 00 00  nop
a00b80f8:  98 10 00 08  mov  %o0, %o4
a00b80fc:  90 10 20 01  mov  1, %o0
a00b8100:  92 10 20 01  mov  1, %o1
a00b8104:  94 10 20 02  mov  2, %o2
a00b8108:  96 10 20 0c  mov  0xc, %o3
a00b810c:  7f ff ac 26  call  0xa00a31a4
a00b8110:  9a 10 20 00  clr  %o5
a00b8114:  b0 10 20 01  mov  1, %i0
a00b8118:  40 02 3b 2a  call  0xa0146dc0
a00b811c:  93 e8 20 00  restore  %g0, 0, %o1
a00b8120:  7f ff f3 ee  call  0xa00b50d8
a00b8124:  90 10 20 04  mov  4, %o0
a00b8128:  90 10 20 00  clr  %o0
a00b812c:  40 02 3b 25  call  0xa0146dc0
a00b8130:  92 10 20 00  clr  %o1
a00b8134:  90 10 20 08  mov  8, %o0
a00b8138:  92 10 20 00  clr  %o1
a00b813c:  40 02 3a c1  call  0xa0146c40
a00b8140:  94 10 20 00  clr  %o2
a00b8144:  98 10 20 00  clr  %o4
a00b8148:  96 10 20 00  clr  %o3
a00b814c:  90 10 20 00  clr  %o0
a00b8150:  92 10 20 00  clr  %o1
a00b8154:  40 02 39 3d  call  0xa0146648
a00b8158:  94 10 20 00  clr  %o2
a00b815c:  90 10 20 08  mov  8, %o0
a00b8160:  92 10 20 03  mov  3, %o1
a00b8164:  40 02 37 f6  call  0xa014613c
a00b8168:  94 10 20 00  clr  %o2
a00b816c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00b8170:  96 14 62 90  or  %l1, 0x290, %o3	! 0xa802d290
a00b8174:  d2 0a e0 0e  ldub  [ %o3 + 0xe ], %o1
a00b8178:  d0 0a e0 0d  ldub  [ %o3 + 0xd ], %o0
a00b817c:  40 02 38 e7  call  0xa0146518
a00b8180:  94 10 20 00  clr  %o2
a00b8184:  92 10 20 00  clr  %o1
a00b8188:  40 02 3a 4a  call  0xa0146ab0
a00b818c:  90 10 27 92  mov  0x792, %o0
a00b8190:  40 02 37 de  call  0xa0146108
a00b8194:  90 10 20 00  clr  %o0
a00b8198:  90 10 20 63  mov  0x63, %o0
a00b819c:  10 bf ff bc  b  0xa00b808c
a00b81a0:  92 10 20 62  mov  0x62, %o1
a00b81a4:  98 14 62 90  or  %l1, 0x290, %o4
a00b81a8:  e4 03 20 ac  ld  [ %o4 + 0xac ], %l2
a00b81ac:  23 00 04 00  sethi  %hi(0x100000), %l1
a00b81b0:  80 8c 80 11  btst  %l2, %l1
a00b81b4:  02 80 00 06  be  0xa00b81cc
a00b81b8:  01 00 00 00  nop
a00b81bc:  c2 0b 20 1f  ldub  [ %o4 + 0x1f ], %g1
a00b81c0:  80 a0 60 00  cmp  %g1, 0
a00b81c4:  02 80 00 57  be  0xa00b8320
a00b81c8:  01 00 00 00  nop
a00b81cc:  40 02 30 b0  call  0xa014448c
a00b81d0:  90 10 20 00  clr  %o0	! 0x0
a00b81d4:  40 02 31 0a  call  0xa01445fc
a00b81d8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b81dc:  92 0a 20 ff  and  %o0, 0xff, %o1
a00b81e0:  17 00 06 5a  sethi  %hi(0x196800), %o3
a00b81e4:  10 bf ff c3  b  0xa00b80f0
a00b81e8:  90 12 e3 24  or  %o3, 0x324, %o0	! 0x196b24
a00b81ec:  23 00 00 25  sethi  %hi(0x9400), %l1
a00b81f0:  90 14 63 0a  or  %l1, 0x30a, %o0	! 0x970a
a00b81f4:  40 02 3a 2f  call  0xa0146ab0
a00b81f8:  92 10 20 00  clr  %o1
a00b81fc:  a2 10 20 00  clr  %l1
a00b8200:  a0 10 20 00  clr  %l0
a00b8204:  b2 10 20 00  clr  %i1
a00b8208:  92 10 20 00  clr  %o1
a00b820c:  b1 2c 20 03  sll  %l0, 3, %i0
a00b8210:  a4 06 00 19  add  %i0, %i1, %l2
a00b8214:  98 0c a0 ff  and  %l2, 0xff, %o4
a00b8218:  90 10 20 01  mov  1, %o0
a00b821c:  94 10 00 10  mov  %l0, %o2
a00b8220:  96 10 20 01  mov  1, %o3
a00b8224:  40 02 3a 3f  call  0xa0146b20
a00b8228:  9a 10 20 00  clr  %o5
a00b822c:  b2 06 60 01  inc  %i1
a00b8230:  92 0e 60 ff  and  %i1, 0xff, %o1
a00b8234:  80 a2 60 07  cmp  %o1, 7
a00b8238:  28 bf ff f7  bleu,a   0xa00b8214
a00b823c:  a4 06 00 19  add  %i0, %i1, %l2
a00b8240:  a2 04 60 01  inc  %l1
a00b8244:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00b8248:  80 a4 20 02  cmp  %l0, 2
a00b824c:  28 bf ff ef  bleu,a   0xa00b8208
a00b8250:  b2 10 20 00  clr  %i1
a00b8254:  90 10 2e 10  mov  0xe10, %o0
a00b8258:  92 10 20 48  mov  0x48, %o1
a00b825c:  40 02 38 bc  call  0xa014654c
a00b8260:  94 10 20 00  clr  %o2
a00b8264:  10 bf ff ad  b  0xa00b8118
a00b8268:  b0 10 20 01  mov  1, %i0
a00b826c:  90 10 20 32  mov  0x32, %o0
a00b8270:  92 10 20 32  mov  0x32, %o1
a00b8274:  40 02 38 a9  call  0xa0146518
a00b8278:  94 10 20 00  clr  %o2
a00b827c:  10 bf ff a7  b  0xa00b8118
a00b8280:  b0 10 20 01  mov  1, %i0
a00b8284:  a0 14 62 90  or  %l1, 0x290, %l0
a00b8288:  d0 0c 20 1f  ldub  [ %l0 + 0x1f ], %o0
a00b828c:  80 a2 20 00  cmp  %o0, 0
a00b8290:  02 80 00 46  be  0xa00b83a8
a00b8294:  96 14 a3 f4  or  %l2, 0x3f4, %o3
a00b8298:  d2 0a e0 01  ldub  [ %o3 + 1 ], %o1
a00b829c:  80 a2 60 00  cmp  %o1, 0
a00b82a0:  22 80 00 03  be,a   0xa00b82ac
a00b82a4:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a00b82a8:  d0 0c 20 20  ldub  [ %l0 + 0x20 ], %o0
a00b82ac:  40 02 30 d4  call  0xa01445fc
a00b82b0:  01 00 00 00  nop
a00b82b4:  92 0a 20 ff  and  %o0, 0xff, %o1
a00b82b8:  15 00 06 5a  sethi  %hi(0x196800), %o2
a00b82bc:  7f ff ad 62  call  0xa00a3844
a00b82c0:  90 12 a3 24  or  %o2, 0x324, %o0	! 0x196b24
a00b82c4:  98 10 00 08  mov  %o0, %o4
a00b82c8:  92 10 20 01  mov  1, %o1
a00b82cc:  90 10 20 01  mov  1, %o0
a00b82d0:  94 10 20 01  mov  1, %o2
a00b82d4:  96 10 20 0c  mov  0xc, %o3
a00b82d8:  7f ff ab b3  call  0xa00a31a4
a00b82dc:  9a 10 20 00  clr  %o5
a00b82e0:  9e 14 62 90  or  %l1, 0x290, %o7
a00b82e4:  d2 0b e0 08  ldub  [ %o7 + 8 ], %o1
a00b82e8:  21 00 06 4c  sethi  %hi(0x193000), %l0
a00b82ec:  90 14 20 08  or  %l0, 8, %o0	! 0x193008
a00b82f0:  7f ff ad 55  call  0xa00a3844
a00b82f4:  01 00 00 00  nop
a00b82f8:  98 10 00 08  mov  %o0, %o4
a00b82fc:  90 10 20 01  mov  1, %o0
a00b8300:  92 10 20 01  mov  1, %o1
a00b8304:  10 bf ff 81  b  0xa00b8108
a00b8308:  94 10 20 03  mov  3, %o2
a00b830c:  b2 14 62 90  or  %l1, 0x290, %i1
a00b8310:  31 00 06 4c  sethi  %hi(0x193000), %i0
a00b8314:  d2 0e 60 08  ldub  [ %i1 + 8 ], %o1
a00b8318:  10 bf ff 76  b  0xa00b80f0
a00b831c:  90 16 20 08  or  %i0, 8, %o0
a00b8320:  40 02 30 5b  call  0xa014448c
a00b8324:  90 10 20 00  clr  %o0
a00b8328:  40 02 30 b5  call  0xa01445fc
a00b832c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b8330:  80 8a 20 ff  btst  0xff, %o0
a00b8334:  12 bf ff a6  bne  0xa00b81cc
a00b8338:  01 00 00 00  nop
a00b833c:  7f ff 2e 91  call  0xa0083d80
a00b8340:  01 00 00 00  nop
a00b8344:  98 0a 20 ff  and  %o0, 0xff, %o4
a00b8348:  80 a3 20 ff  cmp  %o4, 0xff
a00b834c:  02 bf ff a0  be  0xa00b81cc
a00b8350:  01 00 00 00  nop
a00b8354:  40 02 30 4e  call  0xa014448c
a00b8358:  90 10 20 00  clr  %o0	! 0x0
a00b835c:  40 02 30 a8  call  0xa01445fc
a00b8360:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b8364:  92 0a 20 ff  and  %o0, 0xff, %o1
a00b8368:  1b 00 06 5a  sethi  %hi(0x196800), %o5
a00b836c:  7f ff ad 36  call  0xa00a3844
a00b8370:  90 13 63 24  or  %o5, 0x324, %o0	! 0x196b24
a00b8374:  98 10 00 08  mov  %o0, %o4
a00b8378:  92 10 20 01  mov  1, %o1
a00b837c:  94 10 20 01  mov  1, %o2
a00b8380:  96 10 20 0c  mov  0xc, %o3
a00b8384:  9a 10 20 00  clr  %o5
a00b8388:  7f ff ab 87  call  0xa00a31a4
a00b838c:  90 10 20 01  mov  1, %o0
a00b8390:  7f ff 2e 7c  call  0xa0083d80
a00b8394:  01 00 00 00  nop
a00b8398:  92 0a 20 ff  and  %o0, 0xff, %o1
a00b839c:  11 00 06 4a  sethi  %hi(0x192800), %o0
a00b83a0:  10 bf ff d4  b  0xa00b82f0
a00b83a4:  90 12 20 60  or  %o0, 0x60, %o0	! 0x192860
a00b83a8:  40 02 30 95  call  0xa01445fc
a00b83ac:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a00b83b0:  92 0a 20 ff  and  %o0, 0xff, %o1
a00b83b4:  1b 00 06 5a  sethi  %hi(0x196800), %o5
a00b83b8:  7f ff ad 23  call  0xa00a3844
a00b83bc:  90 13 63 24  or  %o5, 0x324, %o0	! 0x196b24
a00b83c0:  98 10 00 08  mov  %o0, %o4
a00b83c4:  92 10 20 01  mov  1, %o1
a00b83c8:  94 10 20 01  mov  1, %o2
a00b83cc:  96 10 20 0c  mov  0xc, %o3
a00b83d0:  9a 10 20 00  clr  %o5
a00b83d4:  7f ff ab 74  call  0xa00a31a4
a00b83d8:  90 10 20 01  mov  1, %o0
a00b83dc:  10 bf ff c3  b  0xa00b82e8
a00b83e0:  d2 0c 20 08  ldub  [ %l0 + 8 ], %o1
