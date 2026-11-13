# leon2m FUN_a00ac138 0xa00ac138-0xa00ac388 (592 bytes)
a00ac138:  9d e3 bf 98  save  %sp, -104, %sp
a00ac13c:  b1 2e 20 10  sll  %i0, 0x10, %i0
a00ac140:  b1 36 20 10  srl  %i0, 0x10, %i0
a00ac144:  80 a6 20 3a  cmp  %i0, 0x3a
a00ac148:  14 80 00 1a  bg  0xa00ac1b0
a00ac14c:  90 10 20 00  clr  %o0
a00ac150:  80 a6 20 38  cmp  %i0, 0x38
a00ac154:  16 80 00 33  bge  0xa00ac220
a00ac158:  80 a6 20 36  cmp  %i0, 0x36
a00ac15c:  02 80 00 66  be  0xa00ac2f4
a00ac160:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00ac164:  04 80 00 3c  ble  0xa00ac254
a00ac168:  80 a6 20 34  cmp  %i0, 0x34
a00ac16c:  82 0e 60 ff  and  %i1, 0xff, %g1
a00ac170:  80 a0 60 01  cmp  %g1, 1
a00ac174:  18 80 00 48  bgu  0xa00ac294
a00ac178:  9f 28 60 03  sll  %g1, 3, %o7
a00ac17c:  98 23 c0 01  sub  %o7, %g1, %o4
a00ac180:  97 2b 20 02  sll  %o4, 2, %o3
a00ac184:  94 02 c0 01  add  %o3, %g1, %o2
a00ac188:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ac18c:  da 08 62 98  ldub  [ %g1 + 0x298 ], %o5	! 0xa802d298
a00ac190:  92 02 80 0d  add  %o2, %o5, %o1
a00ac194:  93 2a 60 10  sll  %o1, 0x10, %o1
a00ac198:  11 00 06 4c  sethi  %hi(0x193000), %o0
a00ac19c:  90 12 22 48  or  %o0, 0x248, %o0	! 0x193248
a00ac1a0:  93 32 60 10  srl  %o1, 0x10, %o1
a00ac1a4:  7f ff dd a8  call  0xa00a3844
a00ac1a8:  01 00 00 00  nop
a00ac1ac:  30 80 00 75  b,a   0xa00ac380
a00ac1b0:  80 a6 20 bd  cmp  %i0, 0xbd
a00ac1b4:  22 80 00 2c  be,a   0xa00ac264
a00ac1b8:  b0 0e 60 ff  and  %i1, 0xff, %i0
a00ac1bc:  14 80 00 13  bg  0xa00ac208
a00ac1c0:  80 a6 20 be  cmp  %i0, 0xbe
a00ac1c4:  80 a6 20 3b  cmp  %i0, 0x3b
a00ac1c8:  02 80 00 61  be  0xa00ac34c
a00ac1cc:  80 a6 20 ba  cmp  %i0, 0xba
a00ac1d0:  12 80 00 6c  bne  0xa00ac380
a00ac1d4:  94 0e 60 ff  and  %i1, 0xff, %o2
a00ac1d8:  93 2a a0 03  sll  %o2, 3, %o1
a00ac1dc:  9a 22 40 0a  sub  %o1, %o2, %o5
a00ac1e0:  91 2b 60 02  sll  %o5, 2, %o0
a00ac1e4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ac1e8:  b2 02 00 0a  add  %o0, %o2, %i1
a00ac1ec:  f0 08 62 98  ldub  [ %g1 + 0x298 ], %i0
a00ac1f0:  9e 06 40 18  add  %i1, %i0, %o7
a00ac1f4:  93 2b e0 10  sll  %o7, 0x10, %o1
a00ac1f8:  19 00 06 2d  sethi  %hi(0x18b400), %o4
a00ac1fc:  90 13 21 e0  or  %o4, 0x1e0, %o0	! 0x18b5e0
a00ac200:  10 bf ff e9  b  0xa00ac1a4
a00ac204:  93 32 60 10  srl  %o1, 0x10, %o1
a00ac208:  02 80 00 47  be  0xa00ac324
a00ac20c:  80 a6 20 bf  cmp  %i0, 0xbf
a00ac210:  12 80 00 5c  bne  0xa00ac380
a00ac214:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00ac218:  10 80 00 2b  b  0xa00ac2c4
a00ac21c:  d4 0a 60 6f  ldub  [ %o1 + 0x6f ], %o2	! 0xa802d46f
a00ac220:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00ac224:  97 2b 60 03  sll  %o5, 3, %o3
a00ac228:  92 22 c0 0d  sub  %o3, %o5, %o1
a00ac22c:  95 2a 60 02  sll  %o1, 2, %o2
a00ac230:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ac234:  c2 0a 22 98  ldub  [ %o0 + 0x298 ], %g1	! 0xa802d298
a00ac238:  b0 02 80 0d  add  %o2, %o5, %i0
a00ac23c:  b2 06 00 01  add  %i0, %g1, %i1
a00ac240:  93 2e 60 10  sll  %i1, 0x10, %o1
a00ac244:  1f 00 05 b7  sethi  %hi(0x16dc00), %o7
a00ac248:  90 13 e3 60  or  %o7, 0x360, %o0	! 0x16df60
a00ac24c:  10 bf ff d6  b  0xa00ac1a4
a00ac250:  93 32 60 10  srl  %o1, 0x10, %o1
a00ac254:  12 80 00 4b  bne  0xa00ac380
a00ac258:  94 0e 60 ff  and  %i1, 0xff, %o2
a00ac25c:  10 bf ff e0  b  0xa00ac1dc
a00ac260:  93 2a a0 03  sll  %o2, 3, %o1
a00ac264:  91 2e 20 03  sll  %i0, 3, %o0
a00ac268:  82 22 00 18  sub  %o0, %i0, %g1
a00ac26c:  b3 28 60 02  sll  %g1, 2, %i1
a00ac270:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00ac274:  96 06 40 18  add  %i1, %i0, %o3
a00ac278:  d8 0b e2 98  ldub  [ %o7 + 0x298 ], %o4
a00ac27c:  92 02 c0 0c  add  %o3, %o4, %o1
a00ac280:  93 2a 60 10  sll  %o1, 0x10, %o1
a00ac284:  19 00 06 29  sethi  %hi(0x18a400), %o4
a00ac288:  90 13 23 ec  or  %o4, 0x3ec, %o0	! 0x18a7ec
a00ac28c:  10 bf ff c6  b  0xa00ac1a4
a00ac290:  93 32 60 10  srl  %o1, 0x10, %o1
a00ac294:  98 23 c0 01  sub  %o7, %g1, %o4
a00ac298:  97 2b 20 02  sll  %o4, 2, %o3
a00ac29c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00ac2a0:  92 02 c0 01  add  %o3, %g1, %o1
a00ac2a4:  d4 0b 62 98  ldub  [ %o5 + 0x298 ], %o2
a00ac2a8:  90 02 40 0a  add  %o1, %o2, %o0
a00ac2ac:  b0 02 3f c6  add  %o0, -58, %i0
a00ac2b0:  93 2e 20 10  sll  %i0, 0x10, %o1
a00ac2b4:  33 00 06 2e  sethi  %hi(0x18b800), %i1
a00ac2b8:  90 16 61 4c  or  %i1, 0x14c, %o0	! 0x18b94c
a00ac2bc:  10 bf ff ba  b  0xa00ac1a4
a00ac2c0:  93 32 60 10  srl  %o1, 0x10, %o1
a00ac2c4:  1b 00 06 29  sethi  %hi(0x18a400), %o5
a00ac2c8:  90 13 63 94  or  %o5, 0x394, %o0	! 0x18a794
a00ac2cc:  80 a2 a0 06  cmp  %o2, 6
a00ac2d0:  08 bf ff b5  bleu  0xa00ac1a4
a00ac2d4:  92 0e 60 ff  and  %i1, 0xff, %o1
a00ac2d8:  9e 0e 60 ff  and  %i1, 0xff, %o7
a00ac2dc:  98 03 e0 07  add  %o7, 7, %o4
a00ac2e0:  93 2b 20 10  sll  %o4, 0x10, %o1
a00ac2e4:  17 00 06 29  sethi  %hi(0x18a400), %o3
a00ac2e8:  90 12 e3 94  or  %o3, 0x394, %o0	! 0x18a794
a00ac2ec:  10 bf ff ae  b  0xa00ac1a4
a00ac2f0:  93 32 60 10  srl  %o1, 0x10, %o1
a00ac2f4:  97 2b 60 03  sll  %o5, 3, %o3
a00ac2f8:  92 22 c0 0d  sub  %o3, %o5, %o1
a00ac2fc:  95 2a 60 02  sll  %o1, 2, %o2
a00ac300:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ac304:  c2 0a 22 98  ldub  [ %o0 + 0x298 ], %g1	! 0xa802d298
a00ac308:  b0 02 80 0d  add  %o2, %o5, %i0
a00ac30c:  b2 06 00 01  add  %i0, %g1, %i1
a00ac310:  93 2e 60 10  sll  %i1, 0x10, %o1
a00ac314:  1f 00 06 2c  sethi  %hi(0x18b000), %o7
a00ac318:  90 13 e2 9c  or  %o7, 0x29c, %o0	! 0x18b29c
a00ac31c:  10 bf ff a2  b  0xa00ac1a4
a00ac320:  93 32 60 10  srl  %o1, 0x10, %o1
a00ac324:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00ac328:  97 2b 60 03  sll  %o5, 3, %o3
a00ac32c:  92 22 c0 0d  sub  %o3, %o5, %o1
a00ac330:  95 2a 60 02  sll  %o1, 2, %o2
a00ac334:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ac338:  b0 02 80 0d  add  %o2, %o5, %i0
a00ac33c:  c2 0a 22 98  ldub  [ %o0 + 0x298 ], %g1
a00ac340:  b2 06 00 01  add  %i0, %g1, %i1
a00ac344:  10 bf ff cf  b  0xa00ac280
a00ac348:  92 06 60 3a  add  %i1, 0x3a, %o1
a00ac34c:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00ac350:  99 2b 60 03  sll  %o5, 3, %o4
a00ac354:  96 23 00 0d  sub  %o4, %o5, %o3
a00ac358:  93 2a e0 02  sll  %o3, 2, %o1
a00ac35c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ac360:  b0 02 40 0d  add  %o1, %o5, %i0
a00ac364:  d0 0a a2 98  ldub  [ %o2 + 0x298 ], %o0
a00ac368:  b2 06 00 08  add  %i0, %o0, %i1
a00ac36c:  93 2e 60 10  sll  %i1, 0x10, %o1
a00ac370:  03 00 06 16  sethi  %hi(0x185800), %g1
a00ac374:  90 10 63 c0  or  %g1, 0x3c0, %o0	! 0x185bc0
a00ac378:  10 bf ff 8b  b  0xa00ac1a4
a00ac37c:  93 32 60 10  srl  %o1, 0x10, %o1
a00ac380:  81 c7 e0 08  ret
a00ac384:  91 e8 00 08  restore  %g0, %o0, %o0
