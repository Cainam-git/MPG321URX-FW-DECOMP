# leon2s FUN_a00aaf94 0xa00aaf94-0xa00ab4a8 (1300 bytes)
a00aaf94:  9d e3 bf 98  save  %sp, -104, %sp
a00aaf98:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00aaf9c:  80 a0 00 10  cmp  %g0, %l0
a00aafa0:  82 40 20 00  addx  %g0, 0, %g1
a00aafa4:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00aafa8:  9a 10 00 01  mov  %g1, %o5
a00aafac:  80 a6 a0 00  cmp  %i2, 0
a00aafb0:  90 10 00 19  mov  %i1, %o0
a00aafb4:  12 80 00 08  bne  0xa00aafd4
a00aafb8:  98 10 20 00  clr  %o4
a00aafbc:  82 0e 60 ff  and  %i1, 0xff, %g1
a00aafc0:  80 a0 60 03  cmp  %g1, 3
a00aafc4:  28 80 00 15  bleu,a   0xa00ab018
a00aafc8:  98 10 00 19  mov  %i1, %o4
a00aafcc:  10 80 00 14  b  0xa00ab01c
a00aafd0:  82 0b 60 ff  and  %o5, 0xff, %g1
a00aafd4:  80 a6 a0 01  cmp  %i2, 1
a00aafd8:  12 80 00 08  bne  0xa00aaff8
a00aafdc:  80 a6 a0 02  cmp  %i2, 2
a00aafe0:  82 0e 60 ff  and  %i1, 0xff, %g1
a00aafe4:  80 a0 60 02  cmp  %g1, 2
a00aafe8:  28 80 00 0c  bleu,a   0xa00ab018
a00aafec:  98 06 60 04  add  %i1, 4, %o4
a00aaff0:  10 80 00 0b  b  0xa00ab01c
a00aaff4:  82 0b 60 ff  and  %o5, 0xff, %g1
a00aaff8:  32 80 00 08  bne,a   0xa00ab018
a00aaffc:  98 10 20 09  mov  9, %o4
a00ab000:  82 0e 60 ff  and  %i1, 0xff, %g1
a00ab004:  80 a0 60 01  cmp  %g1, 1
a00ab008:  28 80 00 04  bleu,a   0xa00ab018
a00ab00c:  98 06 60 07  add  %i1, 7, %o4
a00ab010:  10 80 00 03  b  0xa00ab01c
a00ab014:  82 0b 60 ff  and  %o5, 0xff, %g1
a00ab018:  82 0b 60 ff  and  %o5, 0xff, %g1
a00ab01c:  9b 28 60 02  sll  %g1, 2, %o5
a00ab020:  9a 03 40 01  add  %o5, %g1, %o5
a00ab024:  82 0b 20 ff  and  %o4, 0xff, %g1
a00ab028:  9a 03 40 0d  add  %o5, %o5, %o5
a00ab02c:  9a 03 40 01  add  %o5, %g1, %o5
a00ab030:  19 28 02 d3  sethi  %hi(0xa00b4c00), %o4
a00ab034:  9a 03 40 0d  add  %o5, %o5, %o5
a00ab038:  98 13 21 cc  or  %o4, 0x1cc, %o4
a00ab03c:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00ab040:  d6 13 00 0d  lduh  [ %o4 + %o5 ], %o3
a00ab044:  82 10 63 00  or  %g1, 0x300, %g1
a00ab048:  96 0a c0 01  and  %o3, %g1, %o3
a00ab04c:  d8 13 00 0d  lduh  [ %o4 + %o5 ], %o4
a00ab050:  23 2a 01 e4  sethi  %hi(0xa8079000), %l1
a00ab054:  9a 14 62 b4  or  %l1, 0x2b4, %o5	! 0xa80792b4
a00ab058:  83 2c 20 04  sll  %l0, 4, %g1
a00ab05c:  b0 00 40 0d  add  %g1, %o5, %i0
a00ab060:  97 3a e0 08  sra  %o3, 8, %o3
a00ab064:  98 0b 20 0f  and  %o4, 0xf, %o4
a00ab068:  9e 10 20 00  clr  %o7
a00ab06c:  b4 0b e0 ff  and  %o7, 0xff, %i2
a00ab070:  92 06 00 1a  add  %i0, %i2, %o1
a00ab074:  da 0a 60 04  ldub  [ %o1 + 4 ], %o5
a00ab078:  9a 02 c0 0d  add  %o3, %o5, %o5
a00ab07c:  9e 03 e0 01  inc  %o7
a00ab080:  82 0b 60 ff  and  %o5, 0xff, %g1
a00ab084:  80 a0 60 1f  cmp  %g1, 0x1f
a00ab088:  08 80 00 03  bleu  0xa00ab094
a00ab08c:  b2 0b e0 ff  and  %o7, 0xff, %i1
a00ab090:  9a 10 20 1f  mov  0x1f, %o5
a00ab094:  c2 0a 60 0c  ldub  [ %o1 + 0xc ], %g1
a00ab098:  94 03 00 01  add  %o4, %g1, %o2
a00ab09c:  82 0a a0 ff  and  %o2, 0xff, %g1
a00ab0a0:  80 a0 60 0f  cmp  %g1, 0xf
a00ab0a4:  08 80 00 03  bleu  0xa00ab0b0
a00ab0a8:  da 2e 00 1a  stb  %o5, [ %i0 + %i2 ]
a00ab0ac:  94 10 20 0f  mov  0xf, %o2
a00ab0b0:  80 a6 60 03  cmp  %i1, 3
a00ab0b4:  08 bf ff ee  bleu  0xa00ab06c
a00ab0b8:  d4 2a 60 08  stb  %o2, [ %o1 + 8 ]
a00ab0bc:  80 a4 20 00  cmp  %l0, 0
a00ab0c0:  12 80 00 31  bne  0xa00ab184
a00ab0c4:  80 a4 20 01  cmp  %l0, 1
a00ab0c8:  80 8a 20 ff  btst  0xff, %o0
a00ab0cc:  02 80 00 07  be  0xa00ab0e8
a00ab0d0:  92 10 20 49  mov  0x49, %o1
a00ab0d4:  7f ff f3 2d  call  0xa00a7d88
a00ab0d8:  90 10 20 00  clr  %o0
a00ab0dc:  94 12 20 0f  or  %o0, 0xf, %o2
a00ab0e0:  10 80 00 05  b  0xa00ab0f4
a00ab0e4:  94 0a a0 ff  and  %o2, 0xff, %o2
a00ab0e8:  7f ff f3 28  call  0xa00a7d88
a00ab0ec:  90 10 20 00  clr  %o0
a00ab0f0:  94 0a 20 f0  and  %o0, 0xf0, %o2
a00ab0f4:  90 10 20 00  clr  %o0
a00ab0f8:  7f ff f2 f2  call  0xa00a7cc0
a00ab0fc:  92 10 20 49  mov  0x49, %o1
a00ab100:  d4 0c 62 b4  ldub  [ %l1 + 0x2b4 ], %o2
a00ab104:  90 10 20 00  clr  %o0
a00ab108:  92 10 20 4b  mov  0x4b, %o1
a00ab10c:  7f ff f2 ed  call  0xa00a7cc0
a00ab110:  a0 14 62 b4  or  %l1, 0x2b4, %l0
a00ab114:  90 10 20 00  clr  %o0
a00ab118:  92 10 20 4c  mov  0x4c, %o1
a00ab11c:  7f ff f2 e9  call  0xa00a7cc0
a00ab120:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a00ab124:  90 10 20 00  clr  %o0
a00ab128:  92 10 20 4d  mov  0x4d, %o1
a00ab12c:  7f ff f2 e5  call  0xa00a7cc0
a00ab130:  d4 0c 20 02  ldub  [ %l0 + 2 ], %o2
a00ab134:  90 10 20 00  clr  %o0
a00ab138:  92 10 20 4e  mov  0x4e, %o1
a00ab13c:  7f ff f2 e1  call  0xa00a7cc0
a00ab140:  d4 0c 20 03  ldub  [ %l0 + 3 ], %o2
a00ab144:  90 10 20 00  clr  %o0
a00ab148:  92 10 20 45  mov  0x45, %o1
a00ab14c:  7f ff f2 dd  call  0xa00a7cc0
a00ab150:  d4 0c 20 08  ldub  [ %l0 + 8 ], %o2
a00ab154:  90 10 20 00  clr  %o0
a00ab158:  92 10 20 46  mov  0x46, %o1
a00ab15c:  7f ff f2 d9  call  0xa00a7cc0
a00ab160:  d4 0c 20 09  ldub  [ %l0 + 9 ], %o2
a00ab164:  90 10 20 00  clr  %o0
a00ab168:  92 10 20 47  mov  0x47, %o1
a00ab16c:  7f ff f2 d5  call  0xa00a7cc0
a00ab170:  d4 0c 20 0a  ldub  [ %l0 + 0xa ], %o2
a00ab174:  f4 0c 20 0b  ldub  [ %l0 + 0xb ], %i2
a00ab178:  b0 10 20 00  clr  %i0
a00ab17c:  10 80 00 c8  b  0xa00ab49c
a00ab180:  b2 10 20 48  mov  0x48, %i1
a00ab184:  12 80 00 32  bne  0xa00ab24c
a00ab188:  80 a4 20 02  cmp  %l0, 2
a00ab18c:  80 8a 20 ff  btst  0xff, %o0
a00ab190:  02 80 00 07  be  0xa00ab1ac
a00ab194:  92 10 20 66  mov  0x66, %o1
a00ab198:  7f ff f2 fc  call  0xa00a7d88
a00ab19c:  90 10 20 01  mov  1, %o0
a00ab1a0:  94 12 20 0f  or  %o0, 0xf, %o2
a00ab1a4:  10 80 00 05  b  0xa00ab1b8
a00ab1a8:  94 0a a0 ff  and  %o2, 0xff, %o2
a00ab1ac:  7f ff f2 f7  call  0xa00a7d88
a00ab1b0:  90 10 20 01  mov  1, %o0
a00ab1b4:  94 0a 20 f0  and  %o0, 0xf0, %o2
a00ab1b8:  90 10 20 01  mov  1, %o0
a00ab1bc:  7f ff f2 c1  call  0xa00a7cc0
a00ab1c0:  92 10 20 66  mov  0x66, %o1
a00ab1c4:  a0 14 62 b4  or  %l1, 0x2b4, %l0
a00ab1c8:  d4 0c 20 10  ldub  [ %l0 + 0x10 ], %o2
a00ab1cc:  90 10 20 01  mov  1, %o0
a00ab1d0:  92 10 20 6f  mov  0x6f, %o1
a00ab1d4:  7f ff f2 bb  call  0xa00a7cc0
a00ab1d8:  a0 04 20 10  add  %l0, 0x10, %l0
a00ab1dc:  90 10 20 01  mov  1, %o0
a00ab1e0:  92 10 20 70  mov  0x70, %o1
a00ab1e4:  7f ff f2 b7  call  0xa00a7cc0
a00ab1e8:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a00ab1ec:  90 10 20 01  mov  1, %o0
a00ab1f0:  92 10 20 71  mov  0x71, %o1
a00ab1f4:  7f ff f2 b3  call  0xa00a7cc0
a00ab1f8:  d4 0c 20 02  ldub  [ %l0 + 2 ], %o2
a00ab1fc:  90 10 20 01  mov  1, %o0
a00ab200:  92 10 20 72  mov  0x72, %o1
a00ab204:  7f ff f2 af  call  0xa00a7cc0
a00ab208:  d4 0c 20 03  ldub  [ %l0 + 3 ], %o2
a00ab20c:  d4 0c 20 09  ldub  [ %l0 + 9 ], %o2
a00ab210:  c2 0c 20 08  ldub  [ %l0 + 8 ], %g1
a00ab214:  95 2a a0 04  sll  %o2, 4, %o2
a00ab218:  94 02 80 01  add  %o2, %g1, %o2
a00ab21c:  94 0a a0 ff  and  %o2, 0xff, %o2
a00ab220:  90 10 20 01  mov  1, %o0
a00ab224:  7f ff f2 a7  call  0xa00a7cc0
a00ab228:  92 10 20 62  mov  0x62, %o1
a00ab22c:  f4 0c 20 0b  ldub  [ %l0 + 0xb ], %i2
a00ab230:  b5 2e a0 04  sll  %i2, 4, %i2
a00ab234:  c2 0c 20 0a  ldub  [ %l0 + 0xa ], %g1
a00ab238:  b4 06 80 01  add  %i2, %g1, %i2
a00ab23c:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00ab240:  b0 10 20 01  mov  1, %i0
a00ab244:  10 80 00 96  b  0xa00ab49c
a00ab248:  b2 10 20 63  mov  0x63, %i1
a00ab24c:  12 80 00 32  bne  0xa00ab314
a00ab250:  80 a4 20 03  cmp  %l0, 3
a00ab254:  80 8a 20 ff  btst  0xff, %o0
a00ab258:  02 80 00 07  be  0xa00ab274
a00ab25c:  92 10 20 66  mov  0x66, %o1
a00ab260:  7f ff f2 ca  call  0xa00a7d88
a00ab264:  90 10 20 01  mov  1, %o0
a00ab268:  94 12 3f f0  or  %o0, -16, %o2
a00ab26c:  10 80 00 05  b  0xa00ab280
a00ab270:  94 0a a0 ff  and  %o2, 0xff, %o2
a00ab274:  7f ff f2 c5  call  0xa00a7d88
a00ab278:  90 10 20 01  mov  1, %o0
a00ab27c:  94 0a 20 0f  and  %o0, 0xf, %o2
a00ab280:  90 10 20 01  mov  1, %o0
a00ab284:  7f ff f2 8f  call  0xa00a7cc0
a00ab288:  92 10 20 66  mov  0x66, %o1
a00ab28c:  a0 14 62 b4  or  %l1, 0x2b4, %l0
a00ab290:  d4 0c 20 20  ldub  [ %l0 + 0x20 ], %o2
a00ab294:  90 10 20 01  mov  1, %o0
a00ab298:  92 10 20 73  mov  0x73, %o1
a00ab29c:  7f ff f2 89  call  0xa00a7cc0
a00ab2a0:  a0 04 20 20  add  %l0, 0x20, %l0
a00ab2a4:  90 10 20 01  mov  1, %o0
a00ab2a8:  92 10 20 74  mov  0x74, %o1
a00ab2ac:  7f ff f2 85  call  0xa00a7cc0
a00ab2b0:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a00ab2b4:  90 10 20 01  mov  1, %o0
a00ab2b8:  92 10 20 75  mov  0x75, %o1
a00ab2bc:  7f ff f2 81  call  0xa00a7cc0
a00ab2c0:  d4 0c 20 02  ldub  [ %l0 + 2 ], %o2
a00ab2c4:  90 10 20 01  mov  1, %o0
a00ab2c8:  92 10 20 76  mov  0x76, %o1
a00ab2cc:  7f ff f2 7d  call  0xa00a7cc0
a00ab2d0:  d4 0c 20 03  ldub  [ %l0 + 3 ], %o2
a00ab2d4:  d4 0c 20 09  ldub  [ %l0 + 9 ], %o2
a00ab2d8:  c2 0c 20 08  ldub  [ %l0 + 8 ], %g1
a00ab2dc:  95 2a a0 04  sll  %o2, 4, %o2
a00ab2e0:  94 02 80 01  add  %o2, %g1, %o2
a00ab2e4:  94 0a a0 ff  and  %o2, 0xff, %o2
a00ab2e8:  90 10 20 01  mov  1, %o0
a00ab2ec:  7f ff f2 75  call  0xa00a7cc0
a00ab2f0:  92 10 20 64  mov  0x64, %o1
a00ab2f4:  f4 0c 20 0b  ldub  [ %l0 + 0xb ], %i2
a00ab2f8:  b5 2e a0 04  sll  %i2, 4, %i2
a00ab2fc:  c2 0c 20 0a  ldub  [ %l0 + 0xa ], %g1
a00ab300:  b4 06 80 01  add  %i2, %g1, %i2
a00ab304:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00ab308:  b0 10 20 01  mov  1, %i0
a00ab30c:  10 80 00 64  b  0xa00ab49c
a00ab310:  b2 10 20 65  mov  0x65, %i1
a00ab314:  12 80 00 32  bne  0xa00ab3dc
a00ab318:  82 0a 20 ff  and  %o0, 0xff, %g1
a00ab31c:  80 a0 60 00  cmp  %g1, 0
a00ab320:  02 80 00 07  be  0xa00ab33c
a00ab324:  92 10 20 89  mov  0x89, %o1
a00ab328:  7f ff f2 98  call  0xa00a7d88
a00ab32c:  90 10 20 01  mov  1, %o0
a00ab330:  94 12 20 0f  or  %o0, 0xf, %o2
a00ab334:  10 80 00 05  b  0xa00ab348
a00ab338:  94 0a a0 ff  and  %o2, 0xff, %o2
a00ab33c:  7f ff f2 93  call  0xa00a7d88
a00ab340:  90 10 20 01  mov  1, %o0
a00ab344:  94 0a 20 f0  and  %o0, 0xf0, %o2
a00ab348:  90 10 20 01  mov  1, %o0
a00ab34c:  7f ff f2 5d  call  0xa00a7cc0
a00ab350:  92 10 20 89  mov  0x89, %o1
a00ab354:  a0 14 62 b4  or  %l1, 0x2b4, %l0
a00ab358:  d4 0c 20 30  ldub  [ %l0 + 0x30 ], %o2
a00ab35c:  90 10 20 01  mov  1, %o0
a00ab360:  92 10 20 92  mov  0x92, %o1
a00ab364:  7f ff f2 57  call  0xa00a7cc0
a00ab368:  a0 04 20 30  add  %l0, 0x30, %l0
a00ab36c:  90 10 20 01  mov  1, %o0
a00ab370:  92 10 20 93  mov  0x93, %o1
a00ab374:  7f ff f2 53  call  0xa00a7cc0
a00ab378:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a00ab37c:  90 10 20 01  mov  1, %o0
a00ab380:  92 10 20 94  mov  0x94, %o1
a00ab384:  7f ff f2 4f  call  0xa00a7cc0
a00ab388:  d4 0c 20 02  ldub  [ %l0 + 2 ], %o2
a00ab38c:  90 10 20 01  mov  1, %o0
a00ab390:  92 10 20 95  mov  0x95, %o1
a00ab394:  7f ff f2 4b  call  0xa00a7cc0
a00ab398:  d4 0c 20 03  ldub  [ %l0 + 3 ], %o2
a00ab39c:  d4 0c 20 09  ldub  [ %l0 + 9 ], %o2
a00ab3a0:  c2 0c 20 08  ldub  [ %l0 + 8 ], %g1
a00ab3a4:  95 2a a0 04  sll  %o2, 4, %o2
a00ab3a8:  94 02 80 01  add  %o2, %g1, %o2
a00ab3ac:  94 0a a0 ff  and  %o2, 0xff, %o2
a00ab3b0:  90 10 20 01  mov  1, %o0
a00ab3b4:  7f ff f2 43  call  0xa00a7cc0
a00ab3b8:  92 10 20 85  mov  0x85, %o1
a00ab3bc:  f4 0c 20 0b  ldub  [ %l0 + 0xb ], %i2
a00ab3c0:  b5 2e a0 04  sll  %i2, 4, %i2
a00ab3c4:  c2 0c 20 0a  ldub  [ %l0 + 0xa ], %g1
a00ab3c8:  b4 06 80 01  add  %i2, %g1, %i2
a00ab3cc:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00ab3d0:  b0 10 20 01  mov  1, %i0
a00ab3d4:  10 80 00 32  b  0xa00ab49c
a00ab3d8:  b2 10 20 86  mov  0x86, %i1
a00ab3dc:  80 a0 60 00  cmp  %g1, 0
a00ab3e0:  02 80 00 07  be  0xa00ab3fc
a00ab3e4:  92 10 20 89  mov  0x89, %o1
a00ab3e8:  7f ff f2 68  call  0xa00a7d88
a00ab3ec:  90 10 20 01  mov  1, %o0
a00ab3f0:  94 12 3f f0  or  %o0, -16, %o2
a00ab3f4:  10 80 00 05  b  0xa00ab408
a00ab3f8:  94 0a a0 ff  and  %o2, 0xff, %o2
a00ab3fc:  7f ff f2 63  call  0xa00a7d88
a00ab400:  90 10 20 01  mov  1, %o0
a00ab404:  94 0a 20 0f  and  %o0, 0xf, %o2
a00ab408:  90 10 20 01  mov  1, %o0
a00ab40c:  7f ff f2 2d  call  0xa00a7cc0
a00ab410:  92 10 20 89  mov  0x89, %o1
a00ab414:  a2 14 62 b4  or  %l1, 0x2b4, %l1
a00ab418:  a1 2c 20 04  sll  %l0, 4, %l0
a00ab41c:  d4 0c 40 10  ldub  [ %l1 + %l0 ], %o2
a00ab420:  90 10 20 01  mov  1, %o0
a00ab424:  92 10 20 96  mov  0x96, %o1
a00ab428:  7f ff f2 26  call  0xa00a7cc0
a00ab42c:  a0 04 00 11  add  %l0, %l1, %l0
a00ab430:  90 10 20 01  mov  1, %o0
a00ab434:  92 10 20 97  mov  0x97, %o1
a00ab438:  7f ff f2 22  call  0xa00a7cc0
a00ab43c:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a00ab440:  90 10 20 01  mov  1, %o0
a00ab444:  92 10 20 98  mov  0x98, %o1
a00ab448:  7f ff f2 1e  call  0xa00a7cc0
a00ab44c:  d4 0c 20 02  ldub  [ %l0 + 2 ], %o2
a00ab450:  90 10 20 01  mov  1, %o0
a00ab454:  92 10 20 99  mov  0x99, %o1
a00ab458:  7f ff f2 1a  call  0xa00a7cc0
a00ab45c:  d4 0c 20 03  ldub  [ %l0 + 3 ], %o2
a00ab460:  d4 0c 20 09  ldub  [ %l0 + 9 ], %o2
a00ab464:  c2 0c 20 08  ldub  [ %l0 + 8 ], %g1
a00ab468:  95 2a a0 04  sll  %o2, 4, %o2
a00ab46c:  94 02 80 01  add  %o2, %g1, %o2
a00ab470:  94 0a a0 ff  and  %o2, 0xff, %o2
a00ab474:  90 10 20 01  mov  1, %o0
a00ab478:  7f ff f2 12  call  0xa00a7cc0
a00ab47c:  92 10 20 87  mov  0x87, %o1
a00ab480:  f4 0c 20 0b  ldub  [ %l0 + 0xb ], %i2
a00ab484:  b5 2e a0 04  sll  %i2, 4, %i2
a00ab488:  c2 0c 20 0a  ldub  [ %l0 + 0xa ], %g1
a00ab48c:  b4 06 80 01  add  %i2, %g1, %i2
a00ab490:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00ab494:  b0 10 20 01  mov  1, %i0
a00ab498:  b2 10 20 88  mov  0x88, %i1
a00ab49c:  7f ff f2 09  call  0xa00a7cc0
a00ab4a0:  81 e8 00 00  restore
a00ab4a4:  01 00 00 00  nop
