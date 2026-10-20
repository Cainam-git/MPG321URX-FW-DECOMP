# leon2m FUN_a00c4144 0xa00c4144-0xa00c4430 (748 bytes)
a00c4144:  9d e3 bf 98  save  %sp, -104, %sp
a00c4148:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c414c:  80 a6 20 02  cmp  %i0, 2
a00c4150:  02 80 00 58  be  0xa00c42b0
a00c4154:  80 a6 20 03  cmp  %i0, 3
a00c4158:  02 80 00 59  be  0xa00c42bc
a00c415c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c4160:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c4164:  96 08 60 ff  and  %g1, 0xff, %o3
a00c4168:  94 02 ff d0  add  %o3, -48, %o2
a00c416c:  a0 0a a0 ff  and  %o2, 0xff, %l0
a00c4170:  80 a4 20 02  cmp  %l0, 2
a00c4174:  38 80 00 ad  bgu,a   0xa00c4428
a00c4178:  b0 10 20 ff  mov  0xff, %i0
a00c417c:  40 00 52 97  call  0xa00d8bd8
a00c4180:  01 00 00 00  nop
a00c4184:  80 8a 20 ff  btst  0xff, %o0
a00c4188:  22 80 00 a8  be,a   0xa00c4428
a00c418c:  b0 10 20 ff  mov  0xff, %i0
a00c4190:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00c4194:  a2 14 a2 90  or  %l2, 0x290, %l1	! 0xa802d290
a00c4198:  d8 04 60 b0  ld  [ %l1 + 0xb0 ], %o4
a00c419c:  80 a3 00 10  cmp  %o4, %l0
a00c41a0:  02 80 00 0c  be  0xa00c41d0
a00c41a4:  01 00 00 00  nop
a00c41a8:  da 0c 60 4a  ldub  [ %l1 + 0x4a ], %o5
a00c41ac:  80 a3 60 00  cmp  %o5, 0
a00c41b0:  12 80 00 74  bne  0xa00c4380
a00c41b4:  e0 24 60 b0  st  %l0, [ %l1 + 0xb0 ]
a00c41b8:  da 04 61 1c  ld  [ %l1 + 0x11c ], %o5
a00c41bc:  80 a3 60 00  cmp  %o5, 0
a00c41c0:  26 80 00 42  bl,a   0xa00c42c8
a00c41c4:  de 04 60 b0  ld  [ %l1 + 0xb0 ], %o7
a00c41c8:  40 00 47 5d  call  0xa00d5f3c
a00c41cc:  01 00 00 00  nop
a00c41d0:  40 00 41 f2  call  0xa00d4998
a00c41d4:  01 00 00 00  nop
a00c41d8:  9a 14 a2 90  or  %l2, 0x290, %o5
a00c41dc:  e2 0b 60 1f  ldub  [ %o5 + 0x1f ], %l1
a00c41e0:  80 a4 60 00  cmp  %l1, 0
a00c41e4:  02 80 00 06  be  0xa00c41fc
a00c41e8:  01 00 00 00  nop
a00c41ec:  d0 03 60 b0  ld  [ %o5 + 0xb0 ], %o0
a00c41f0:  80 a2 20 00  cmp  %o0, 0
a00c41f4:  32 80 00 82  bne,a   0xa00c43fc
a00c41f8:  c0 2b 60 1f  clrb  [ %o5 + 0x1f ]
a00c41fc:  7f fe fd 7a  call  0xa00837e4
a00c4200:  01 00 00 00  nop
a00c4204:  92 0a 20 ff  and  %o0, 0xff, %o1
a00c4208:  80 a2 60 01  cmp  %o1, 1
a00c420c:  22 80 00 53  be,a   0xa00c4358
a00c4210:  a0 14 a2 90  or  %l2, 0x290, %l0
a00c4214:  7f ff d1 ae  call  0xa00b88cc
a00c4218:  01 00 00 00  nop
a00c421c:  80 a6 20 02  cmp  %i0, 2
a00c4220:  02 80 00 31  be  0xa00c42e4
a00c4224:  80 a6 20 03  cmp  %i0, 3
a00c4228:  02 80 00 5b  be  0xa00c4394
a00c422c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c4230:  94 14 20 78  or  %l0, 0x78, %o2	! 0xa802d078
a00c4234:  96 10 20 30  mov  0x30, %o3
a00c4238:  a2 10 20 35  mov  0x35, %l1
a00c423c:  9e 10 20 36  mov  0x36, %o7
a00c4240:  9a 10 20 2b  mov  0x2b, %o5
a00c4244:  98 10 20 0d  mov  0xd, %o4
a00c4248:  e2 2c 20 78  stb  %l1, [ %l0 + 0x78 ]
a00c424c:  de 2a a0 01  stb  %o7, [ %o2 + 1 ]
a00c4250:  d6 2a a0 03  stb  %o3, [ %o2 + 3 ]
a00c4254:  da 2a a0 04  stb  %o5, [ %o2 + 4 ]
a00c4258:  d8 2a a0 05  stb  %o4, [ %o2 + 5 ]
a00c425c:  80 a6 20 02  cmp  %i0, 2
a00c4260:  02 80 00 2e  be  0xa00c4318
a00c4264:  d6 2a a0 02  stb  %o3, [ %o2 + 2 ]
a00c4268:  80 a6 20 03  cmp  %i0, 3
a00c426c:  02 80 00 57  be  0xa00c43c8
a00c4270:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c4274:  96 13 20 d0  or  %o4, 0xd0, %o3	! 0xa802d0d0
a00c4278:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00c427c:  c0 2b 60 9c  clrb  [ %o5 + 0x9c ]	! 0xa802b09c
a00c4280:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00c4284:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00c4288:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00c428c:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00c4290:  80 a6 20 02  cmp  %i0, 2
a00c4294:  02 80 00 2a  be  0xa00c433c
a00c4298:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00c429c:  80 a6 20 03  cmp  %i0, 3
a00c42a0:  12 80 00 2a  bne  0xa00c4348
a00c42a4:  90 10 00 18  mov  %i0, %o0
a00c42a8:  10 80 00 52  b  0xa00c43f0
a00c42ac:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c42b0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c42b4:  10 bf ff ac  b  0xa00c4164
a00c42b8:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c42bc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c42c0:  10 bf ff a9  b  0xa00c4164
a00c42c4:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c42c8:  80 a3 e0 00  cmp  %o7, 0
a00c42cc:  02 bf ff bf  be  0xa00c41c8
a00c42d0:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00c42d4:  a0 2b 40 01  andn  %o5, %g1, %l0
a00c42d8:  40 00 53 49  call  0xa00d8ffc
a00c42dc:  e0 24 61 1c  st  %l0, [ %l1 + 0x11c ]
a00c42e0:  30 bf ff ba  b,a   0xa00c41c8
a00c42e4:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c42e8:  b0 13 e1 28  or  %o7, 0x128, %i0	! 0xa802d128
a00c42ec:  94 10 20 30  mov  0x30, %o2
a00c42f0:  a0 10 20 35  mov  0x35, %l0
a00c42f4:  9a 10 20 0d  mov  0xd, %o5
a00c42f8:  98 10 20 36  mov  0x36, %o4
a00c42fc:  96 10 20 2b  mov  0x2b, %o3
a00c4300:  e0 2b e1 28  stb  %l0, [ %o7 + 0x128 ]
a00c4304:  da 2e 20 05  stb  %o5, [ %i0 + 5 ]
a00c4308:  d8 2e 20 01  stb  %o4, [ %i0 + 1 ]
a00c430c:  d4 2e 20 03  stb  %o2, [ %i0 + 3 ]
a00c4310:  d6 2e 20 04  stb  %o3, [ %i0 + 4 ]
a00c4314:  d4 2e 20 02  stb  %o2, [ %i0 + 2 ]
a00c4318:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c431c:  90 12 60 40  or  %o1, 0x40, %o0	! 0xa802d040
a00c4320:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c4324:  c0 28 60 9a  clrb  [ %g1 + 0x9a ]	! 0xa802b09a
a00c4328:  c0 2a 60 40  clrb  [ %o1 + 0x40 ]
a00c432c:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c4330:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c4334:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c4338:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c433c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c4340:  94 13 e1 28  or  %o7, 0x128, %o2	! 0xa802d128
a00c4344:  90 10 20 02  mov  2, %o0
a00c4348:  40 02 11 28  call  0xa01487e8
a00c434c:  92 10 20 06  mov  6, %o1
a00c4350:  10 80 00 36  b  0xa00c4428
a00c4354:  b0 10 20 00  clr  %i0
a00c4358:  e4 04 20 b0  ld  [ %l0 + 0xb0 ], %l2
a00c435c:  80 a4 a0 00  cmp  %l2, 0
a00c4360:  02 bf ff ad  be  0xa00c4214
a00c4364:  01 00 00 00  nop
a00c4368:  40 00 53 a5  call  0xa00d91fc
a00c436c:  90 10 20 00  clr  %o0	! 0x0
a00c4370:  c0 2c 21 a4  clrb  [ %l0 + 0x1a4 ]
a00c4374:  7f fe fb 60  call  0xa00830f4
a00c4378:  90 10 20 00  clr  %o0
a00c437c:  30 bf ff a6  b,a   0xa00c4214
a00c4380:  c0 2c 60 4a  clrb  [ %l1 + 0x4a ]
a00c4384:  40 00 46 ca  call  0xa00d5eac
a00c4388:  90 10 20 00  clr  %o0
a00c438c:  10 bf ff 8c  b  0xa00c41bc
a00c4390:  da 04 61 1c  ld  [ %l1 + 0x11c ], %o5
a00c4394:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c4398:  a2 16 21 08  or  %i0, 0x108, %l1	! 0xa802d108
a00c439c:  90 10 20 30  mov  0x30, %o0
a00c43a0:  94 10 20 35  mov  0x35, %o2
a00c43a4:  a4 10 20 0d  mov  0xd, %l2
a00c43a8:  92 10 20 36  mov  0x36, %o1
a00c43ac:  82 10 20 2b  mov  0x2b, %g1
a00c43b0:  d4 2e 21 08  stb  %o2, [ %i0 + 0x108 ]
a00c43b4:  e4 2c 60 05  stb  %l2, [ %l1 + 5 ]
a00c43b8:  d2 2c 60 01  stb  %o1, [ %l1 + 1 ]
a00c43bc:  d0 2c 60 03  stb  %o0, [ %l1 + 3 ]
a00c43c0:  c2 2c 60 04  stb  %g1, [ %l1 + 4 ]
a00c43c4:  d0 2c 60 02  stb  %o0, [ %l1 + 2 ]
a00c43c8:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c43cc:  a4 16 20 98  or  %i0, 0x98, %l2	! 0xa802d098
a00c43d0:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00c43d4:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]	! 0xa802b098
a00c43d8:  c0 2e 20 98  clrb  [ %i0 + 0x98 ]
a00c43dc:  c0 2c a0 19  clrb  [ %l2 + 0x19 ]
a00c43e0:  c0 2c a0 01  clrb  [ %l2 + 1 ]
a00c43e4:  c0 2c a0 07  clrb  [ %l2 + 7 ]
a00c43e8:  c0 2c a0 0a  clrb  [ %l2 + 0xa ]
a00c43ec:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c43f0:  94 14 21 08  or  %l0, 0x108, %o2	! 0xa802d108
a00c43f4:  10 bf ff d5  b  0xa00c4348
a00c43f8:  90 10 20 03  mov  3, %o0
a00c43fc:  40 00 53 80  call  0xa00d91fc
a00c4400:  90 10 20 00  clr  %o0
a00c4404:  90 10 20 00  clr  %o0
a00c4408:  40 02 0f 98  call  0xa0148268
a00c440c:  92 10 20 01  mov  1, %o1
a00c4410:  90 10 20 01  mov  1, %o0
a00c4414:  40 02 0f 95  call  0xa0148268
a00c4418:  92 10 20 01  mov  1, %o1
a00c441c:  40 00 57 8e  call  0xa00da254
a00c4420:  01 00 00 00  nop
a00c4424:  30 bf ff 76  b,a   0xa00c41fc
a00c4428:  81 c7 e0 08  ret
a00c442c:  81 e8 00 00  restore
