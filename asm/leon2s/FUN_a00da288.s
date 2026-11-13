# leon2s FUN_a00da288 0xa00da288-0xa00da388 (256 bytes)
a00da288:  9d e3 bf 98  save  %sp, -104, %sp
a00da28c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da290:  f8 08 60 32  ldub  [ %g1 + 0x32 ], %i4	! 0xa8078832
a00da294:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da298:  82 10 60 00  mov  %g1, %g1	! 0xa8078800
a00da29c:  fa 08 40 1c  ldub  [ %g1 + %i4 ], %i5
a00da2a0:  82 07 40 1d  add  %i5, %i5, %g1
a00da2a4:  82 00 40 1d  add  %g1, %i5, %g1
a00da2a8:  83 28 60 02  sll  %g1, 2, %g1
a00da2ac:  82 20 40 1d  sub  %g1, %i5, %g1
a00da2b0:  9e 5f 20 b0  smul  %i4, 0xb0, %o7
a00da2b4:  31 2a 01 e8  sethi  %hi(0xa807a000), %i0
a00da2b8:  9e 03 c0 01  add  %o7, %g1, %o7
a00da2bc:  b0 16 23 98  or  %i0, 0x398, %i0
a00da2c0:  f2 0b c0 18  ldub  [ %o7 + %i0 ], %i1
a00da2c4:  82 0e 60 ff  and  %i1, 0xff, %g1
a00da2c8:  99 30 60 04  srl  %g1, 4, %o4
a00da2cc:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da2d0:  b6 07 00 1c  add  %i4, %i4, %i3
a00da2d4:  82 10 60 0a  or  %g1, 0xa, %g1
a00da2d8:  f6 10 40 1b  lduh  [ %g1 + %i3 ], %i3
a00da2dc:  b4 03 3f ff  add  %o4, -1, %i2
a00da2e0:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00da2e4:  82 10 63 98  or  %g1, 0x398, %g1	! 0xa8079f98
a00da2e8:  bb 36 a0 1f  srl  %i2, 0x1f, %i5
a00da2ec:  b9 2f 20 09  sll  %i4, 9, %i4
a00da2f0:  ba 06 80 1d  add  %i2, %i5, %i5
a00da2f4:  b6 0e e1 ff  and  %i3, 0x1ff, %i3
a00da2f8:  b8 07 00 01  add  %i4, %g1, %i4
a00da2fc:  9b 3f 60 01  sra  %i5, 1, %o5
a00da300:  c2 0f 00 1b  ldub  [ %i4 + %i3 ], %g1
a00da304:  b2 0e 60 0f  and  %i1, 0xf, %i1
a00da308:  96 10 20 01  mov  1, %o3
a00da30c:  b6 08 60 7f  and  %g1, 0x7f, %i3
a00da310:  80 8e a0 01  btst  1, %i2
a00da314:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00da318:  ba 10 00 0d  mov  %o5, %i5
a00da31c:  02 80 00 03  be  0xa00da328
a00da320:  9e 03 c0 18  add  %o7, %i0, %o7
a00da324:  ba 03 60 01  add  %o5, 1, %i5
a00da328:  ba 0f 60 ff  and  %i5, 0xff, %i5
a00da32c:  ba 03 c0 1d  add  %o7, %i5, %i5
a00da330:  c2 0f 60 02  ldub  [ %i5 + 2 ], %g1
a00da334:  82 08 60 10  and  %g1, 0x10, %g1
a00da338:  80 a0 00 01  cmp  %g0, %g1
a00da33c:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00da340:  b8 40 20 00  addx  %g0, 0, %i4
a00da344:  82 10 60 3d  or  %g1, 0x3d, %g1
a00da348:  c2 08 40 1c  ldub  [ %g1 + %i4 ], %g1
a00da34c:  82 18 40 1b  xor  %g1, %i3, %g1
a00da350:  80 a0 00 01  cmp  %g0, %g1
a00da354:  b8 40 20 00  addx  %g0, 0, %i4
a00da358:  80 a6 40 0c  cmp  %i1, %o4
a00da35c:  82 40 20 00  addx  %g0, 0, %g1
a00da360:  fa 0f 60 01  ldub  [ %i5 + 1 ], %i5
a00da364:  80 8f 00 01  btst  %i4, %g1
a00da368:  02 80 00 05  be  0xa00da37c
a00da36c:  bb 37 60 07  srl  %i5, 7, %i5
a00da370:  80 a7 60 00  cmp  %i5, 0
a00da374:  02 80 00 03  be  0xa00da380
a00da378:  01 00 00 00  nop
a00da37c:  96 10 20 00  clr  %o3	! 0x0
a00da380:  81 c7 e0 08  ret
a00da384:  91 e8 00 0b  restore  %g0, %o3, %o0
