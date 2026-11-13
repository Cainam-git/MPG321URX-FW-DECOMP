# leon2m FUN_a010e0f4 0xa010e0f4-0xa010e448 (212 bytes)
a010e0f4:  9d e3 bf 98  save  %sp, -104, %sp
a010e0f8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a010e0fc:  9e 10 00 1a  mov  %i2, %o7
a010e100:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010e104:  9a 10 00 1b  mov  %i3, %o5
a010e108:  80 a6 20 01  cmp  %i0, 1
a010e10c:  02 80 00 37  be  0xa010e1e8
a010e110:  b4 10 63 04  or  %g1, 0x304, %i2
a010e114:  80 a6 20 00  cmp  %i0, 0
a010e118:  12 80 00 0f  bne  0xa010e154
a010e11c:  f2 2e a0 27  stb  %i1, [ %i2 + 0x27 ]
a010e120:  31 34 00 c8  sethi  %hi(0xd0032000), %i0
a010e124:  b2 0e 60 ff  and  %i1, 0xff, %i1
a010e128:  b8 16 20 04  or  %i0, 4, %i4
a010e12c:  f0 07 00 00  ld  [ %i4 ], %i0
a010e130:  80 a6 60 04  cmp  %i1, 4
a010e134:  18 80 00 23  bgu  0xa010e1c0
a010e138:  37 34 00 c8  sethi  %hi(0xd0032000), %i3
a010e13c:  37 00 02 ad  sethi  %hi(0xab400), %i3
a010e140:  83 2e 60 02  sll  %i1, 2, %g1
a010e144:  ba 16 e0 30  or  %i3, 0x30, %i5
a010e148:  f2 07 40 01  ld  [ %i5 + %g1 ], %i1
a010e14c:  81 c6 40 00  jmp  %i1
a010e150:  01 00 00 00  nop
a010e154:  31 34 00 c8  sethi  %hi(0xd0032000), %i0
a010e158:  b2 0e 60 ff  and  %i1, 0xff, %i1
a010e15c:  82 16 20 08  or  %i0, 8, %g1
a010e160:  f0 00 40 00  ld  [ %g1 ], %i0
a010e164:  80 a6 60 04  cmp  %i1, 4
a010e168:  08 80 00 1b  bleu  0xa010e1d4
a010e16c:  37 00 02 ad  sethi  %hi(0xab400), %i3
a010e170:  35 34 00 c8  sethi  %hi(0xd0032000), %i2
a010e174:  b8 16 a0 08  or  %i2, 8, %i4	! 0xd0032008
a010e178:  33 34 00 e8  sethi  %hi(0xd003a000), %i1
a010e17c:  f0 27 00 00  st  %i0, [ %i4 ]
a010e180:  10 80 00 af  b  0xa010e43c
a010e184:  ba 16 60 08  or  %i1, 8, %i5
a010e188:  da 26 a0 34  st  %o5, [ %i2 + 0x34 ]
a010e18c:  de 26 a0 30  st  %o7, [ %i2 + 0x30 ]
a010e190:  33 34 00 c8  sethi  %hi(0xd0032000), %i1
a010e194:  35 34 00 e8  sethi  %hi(0xd003a000), %i2
a010e198:  ba 16 61 dc  or  %i1, 0x1dc, %i5
a010e19c:  de 27 40 00  st  %o7, [ %i5 ]
a010e1a0:  82 16 a1 dc  or  %i2, 0x1dc, %g1
a010e1a4:  de 20 40 00  st  %o7, [ %g1 ]
a010e1a8:  b6 16 61 e0  or  %i1, 0x1e0, %i3
a010e1ac:  da 26 c0 00  st  %o5, [ %i3 ]
a010e1b0:  b8 16 a1 e0  or  %i2, 0x1e0, %i4
a010e1b4:  da 27 00 00  st  %o5, [ %i4 ]
a010e1b8:  b0 16 20 40  or  %i0, 0x40, %i0
a010e1bc:  37 34 00 c8  sethi  %hi(0xd0032000), %i3
a010e1c0:  b4 16 e0 04  or  %i3, 4, %i2	! 0xd0032004
a010e1c4:  39 34 00 e8  sethi  %hi(0xd003a000), %i4
a010e1c8:  f0 26 80 00  st  %i0, [ %i2 ]
a010e1cc:  10 80 00 9c  b  0xa010e43c
a010e1d0:  ba 17 20 04  or  %i4, 4, %i5
a010e1d4:  b9 2e 60 02  sll  %i1, 2, %i4
a010e1d8:  ba 16 e0 1c  or  %i3, 0x1c, %i5
a010e1dc:  f2 07 40 1c  ld  [ %i5 + %i4 ], %i1
a010e1e0:  81 c6 40 00  jmp  %i1
a010e1e4:  01 00 00 00  nop
a010e1e8:  37 2a 00 b6  sethi  %hi(0xa802d800), %i3
a010e1ec:  10 bf ff ca  b  0xa010e114
a010e1f0:  b4 16 e0 04  or  %i3, 4, %i2	! 0xa802d804
a010e1f4:  c0 26 a0 34  clr  [ %i2 + 0x34 ]
a010e1f8:  c0 26 a0 30  clr  [ %i2 + 0x30 ]
a010e1fc:  33 34 00 c8  sethi  %hi(0xd0032000), %i1
a010e200:  35 34 00 e8  sethi  %hi(0xd003a000), %i2
a010e204:  ba 16 61 dc  or  %i1, 0x1dc, %i5
a010e208:  c0 27 40 00  clr  [ %i5 ]
a010e20c:  82 16 a1 dc  or  %i2, 0x1dc, %g1
a010e210:  c0 20 40 00  clr  [ %g1 ]
a010e214:  b6 16 61 e0  or  %i1, 0x1e0, %i3
a010e218:  c0 26 c0 00  clr  [ %i3 ]
a010e21c:  b8 16 a1 e0  or  %i2, 0x1e0, %i4
a010e220:  c0 27 00 00  clr  [ %i4 ]
a010e224:  10 bf ff e6  b  0xa010e1bc
a010e228:  b0 0e 3f bf  and  %i0, -65, %i0
a010e22c:  c0 26 a0 2c  clr  [ %i2 + 0x2c ]
a010e230:  c0 26 a0 28  clr  [ %i2 + 0x28 ]
a010e234:  33 34 00 c8  sethi  %hi(0xd0032000), %i1
a010e238:  35 34 00 e8  sethi  %hi(0xd003a000), %i2
a010e23c:  ba 16 61 20  or  %i1, 0x120, %i5
a010e240:  c0 27 40 00  clr  [ %i5 ]
a010e244:  82 16 a1 20  or  %i2, 0x120, %g1
a010e248:  c0 20 40 00  clr  [ %g1 ]
a010e24c:  b6 16 61 24  or  %i1, 0x124, %i3
a010e250:  c0 26 c0 00  clr  [ %i3 ]
a010e254:  b8 16 a1 24  or  %i2, 0x124, %i4
a010e258:  c0 27 00 00  clr  [ %i4 ]
a010e25c:  10 bf ff d8  b  0xa010e1bc
a010e260:  b0 0e 3f df  and  %i0, -33, %i0
a010e264:  da 26 a0 2c  st  %o5, [ %i2 + 0x2c ]
a010e268:  de 26 a0 28  st  %o7, [ %i2 + 0x28 ]
a010e26c:  33 34 00 c8  sethi  %hi(0xd0032000), %i1
a010e270:  35 34 00 e8  sethi  %hi(0xd003a000), %i2
a010e274:  ba 16 61 20  or  %i1, 0x120, %i5
a010e278:  de 27 40 00  st  %o7, [ %i5 ]
a010e27c:  82 16 a1 20  or  %i2, 0x120, %g1
a010e280:  de 20 40 00  st  %o7, [ %g1 ]
a010e284:  b6 16 61 24  or  %i1, 0x124, %i3
a010e288:  da 26 c0 00  st  %o5, [ %i3 ]
a010e28c:  b8 16 a1 24  or  %i2, 0x124, %i4
a010e290:  da 27 00 00  st  %o5, [ %i4 ]
a010e294:  10 bf ff ca  b  0xa010e1bc
a010e298:  b0 16 20 20  or  %i0, 0x20, %i0
a010e29c:  37 34 00 c8  sethi  %hi(0xd0032000), %i3
a010e2a0:  c0 26 a0 34  clr  [ %i2 + 0x34 ]
a010e2a4:  c0 26 a0 28  clr  [ %i2 + 0x28 ]
a010e2a8:  c0 26 a0 2c  clr  [ %i2 + 0x2c ]
a010e2ac:  c0 26 a0 30  clr  [ %i2 + 0x30 ]
a010e2b0:  39 34 00 e8  sethi  %hi(0xd003a000), %i4
a010e2b4:  ba 16 e1 20  or  %i3, 0x120, %i5
a010e2b8:  c0 27 40 00  clr  [ %i5 ]
a010e2bc:  82 17 21 20  or  %i4, 0x120, %g1
a010e2c0:  c0 20 40 00  clr  [ %g1 ]
a010e2c4:  b2 16 e1 dc  or  %i3, 0x1dc, %i1
a010e2c8:  c0 26 40 00  clr  [ %i1 ]
a010e2cc:  b4 17 21 dc  or  %i4, 0x1dc, %i2
a010e2d0:  c0 26 80 00  clr  [ %i2 ]
a010e2d4:  ba 16 e1 24  or  %i3, 0x124, %i5
a010e2d8:  c0 27 40 00  clr  [ %i5 ]
a010e2dc:  82 17 21 24  or  %i4, 0x124, %g1
a010e2e0:  c0 20 40 00  clr  [ %g1 ]
a010e2e4:  b2 16 e1 e0  or  %i3, 0x1e0, %i1
a010e2e8:  c0 26 40 00  clr  [ %i1 ]
a010e2ec:  b4 17 21 e0  or  %i4, 0x1e0, %i2
a010e2f0:  c0 26 80 00  clr  [ %i2 ]
a010e2f4:  10 bf ff b2  b  0xa010e1bc
a010e2f8:  b0 0e 3f 9f  and  %i0, -97, %i0
a010e2fc:  37 34 00 c8  sethi  %hi(0xd0032000), %i3
a010e300:  c0 26 a0 34  clr  [ %i2 + 0x34 ]
a010e304:  c0 26 a0 30  clr  [ %i2 + 0x30 ]
a010e308:  39 34 00 e8  sethi  %hi(0xd003a000), %i4
a010e30c:  ba 16 e1 e4  or  %i3, 0x1e4, %i5
a010e310:  c0 27 40 00  clr  [ %i5 ]
a010e314:  82 17 21 e4  or  %i4, 0x1e4, %g1
a010e318:  c0 20 40 00  clr  [ %g1 ]
a010e31c:  b4 16 e1 e8  or  %i3, 0x1e8, %i2
a010e320:  c0 26 80 00  clr  [ %i2 ]
a010e324:  b2 17 21 e8  or  %i4, 0x1e8, %i1
a010e328:  c0 26 40 00  clr  [ %i1 ]
a010e32c:  10 bf ff 91  b  0xa010e170
a010e330:  b0 0e 3f bf  and  %i0, -65, %i0
a010e334:  37 34 00 c8  sethi  %hi(0xd0032000), %i3
a010e338:  da 26 a0 34  st  %o5, [ %i2 + 0x34 ]
a010e33c:  de 26 a0 30  st  %o7, [ %i2 + 0x30 ]
a010e340:  39 34 00 e8  sethi  %hi(0xd003a000), %i4
a010e344:  ba 16 e1 e4  or  %i3, 0x1e4, %i5
a010e348:  de 27 40 00  st  %o7, [ %i5 ]
a010e34c:  82 17 21 e4  or  %i4, 0x1e4, %g1
a010e350:  de 20 40 00  st  %o7, [ %g1 ]
a010e354:  b4 16 e1 e8  or  %i3, 0x1e8, %i2
a010e358:  da 26 80 00  st  %o5, [ %i2 ]
a010e35c:  b2 17 21 e8  or  %i4, 0x1e8, %i1
a010e360:  da 26 40 00  st  %o5, [ %i1 ]
a010e364:  10 bf ff 83  b  0xa010e170
a010e368:  b0 16 20 40  or  %i0, 0x40, %i0
a010e36c:  37 34 00 c8  sethi  %hi(0xd0032000), %i3
a010e370:  c0 26 a0 2c  clr  [ %i2 + 0x2c ]
a010e374:  c0 26 a0 28  clr  [ %i2 + 0x28 ]
a010e378:  39 34 00 e8  sethi  %hi(0xd003a000), %i4
a010e37c:  ba 16 e1 28  or  %i3, 0x128, %i5
a010e380:  c0 27 40 00  clr  [ %i5 ]
a010e384:  82 17 21 28  or  %i4, 0x128, %g1
a010e388:  c0 20 40 00  clr  [ %g1 ]
a010e38c:  b4 16 e1 2c  or  %i3, 0x12c, %i2
a010e390:  c0 26 80 00  clr  [ %i2 ]
a010e394:  b2 17 21 2c  or  %i4, 0x12c, %i1
a010e398:  c0 26 40 00  clr  [ %i1 ]
a010e39c:  10 bf ff 75  b  0xa010e170
a010e3a0:  b0 0e 3f df  and  %i0, -33, %i0
a010e3a4:  37 34 00 c8  sethi  %hi(0xd0032000), %i3
a010e3a8:  da 26 a0 2c  st  %o5, [ %i2 + 0x2c ]
a010e3ac:  de 26 a0 28  st  %o7, [ %i2 + 0x28 ]
a010e3b0:  39 34 00 e8  sethi  %hi(0xd003a000), %i4
a010e3b4:  ba 16 e1 28  or  %i3, 0x128, %i5
a010e3b8:  de 27 40 00  st  %o7, [ %i5 ]
a010e3bc:  82 17 21 28  or  %i4, 0x128, %g1
a010e3c0:  de 20 40 00  st  %o7, [ %g1 ]
a010e3c4:  b4 16 e1 2c  or  %i3, 0x12c, %i2
a010e3c8:  da 26 80 00  st  %o5, [ %i2 ]
a010e3cc:  b2 17 21 2c  or  %i4, 0x12c, %i1
a010e3d0:  da 26 40 00  st  %o5, [ %i1 ]
a010e3d4:  10 bf ff 67  b  0xa010e170
a010e3d8:  b0 16 20 20  or  %i0, 0x20, %i0
a010e3dc:  39 34 00 c8  sethi  %hi(0xd0032000), %i4
a010e3e0:  c0 26 a0 34  clr  [ %i2 + 0x34 ]
a010e3e4:  c0 26 a0 28  clr  [ %i2 + 0x28 ]
a010e3e8:  c0 26 a0 2c  clr  [ %i2 + 0x2c ]
a010e3ec:  c0 26 a0 30  clr  [ %i2 + 0x30 ]
a010e3f0:  33 34 00 e8  sethi  %hi(0xd003a000), %i1
a010e3f4:  b6 17 21 28  or  %i4, 0x128, %i3
a010e3f8:  c0 26 c0 00  clr  [ %i3 ]
a010e3fc:  ba 16 61 28  or  %i1, 0x128, %i5
a010e400:  c0 27 40 00  clr  [ %i5 ]
a010e404:  82 17 21 e4  or  %i4, 0x1e4, %g1
a010e408:  c0 20 40 00  clr  [ %g1 ]
a010e40c:  b4 16 61 e4  or  %i1, 0x1e4, %i2
a010e410:  c0 26 80 00  clr  [ %i2 ]
a010e414:  b6 17 21 2c  or  %i4, 0x12c, %i3
a010e418:  c0 26 c0 00  clr  [ %i3 ]
a010e41c:  ba 16 61 2c  or  %i1, 0x12c, %i5
a010e420:  c0 27 40 00  clr  [ %i5 ]
a010e424:  82 17 21 e8  or  %i4, 0x1e8, %g1
a010e428:  c0 20 40 00  clr  [ %g1 ]
a010e42c:  b4 16 61 e8  or  %i1, 0x1e8, %i2
a010e430:  c0 26 80 00  clr  [ %i2 ]
a010e434:  10 bf ff 4f  b  0xa010e170
a010e438:  b0 0e 3f 9f  and  %i0, -97, %i0
a010e43c:  f0 27 40 00  st  %i0, [ %i5 ]
a010e440:  81 c7 e0 08  ret
a010e444:  81 e8 00 00  restore
