# leon2s FUN_a00a0268 0xa00a0268-0xa00a03c8 (352 bytes)
a00a0268:  9d e3 bf 98  save  %sp, -104, %sp
a00a026c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a0270:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a0274:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00a0278:  b0 5e 20 34  smul  %i0, 0x34, %i0
a00a027c:  96 06 00 01  add  %i0, %g1, %o3
a00a0280:  d8 02 e0 08  ld  [ %o3 + 8 ], %o4
a00a0284:  c2 03 20 80  ld  [ %o4 + 0x80 ], %g1
a00a0288:  92 10 20 00  clr  %o1
a00a028c:  94 10 20 22  mov  0x22, %o2
a00a0290:  80 88 60 ff  btst  0xff, %g1
a00a0294:  12 80 00 05  bne  0xa00a02a8
a00a0298:  90 10 00 19  mov  %i1, %o0
a00a029c:  40 00 44 c4  call  0xa00b15ac
a00a02a0:  b0 10 20 01  mov  1, %i0
a00a02a4:  30 80 00 47  b,a   0xa00a03c0
a00a02a8:  f0 03 20 80  ld  [ %o4 + 0x80 ], %i0
a00a02ac:  99 36 20 18  srl  %i0, 0x18, %o4
a00a02b0:  83 36 20 08  srl  %i0, 8, %g1
a00a02b4:  9b 36 20 10  srl  %i0, 0x10, %o5
a00a02b8:  da 2e 60 02  stb  %o5, [ %i1 + 2 ]
a00a02bc:  d8 2e 60 03  stb  %o4, [ %i1 + 3 ]
a00a02c0:  c2 2e 60 01  stb  %g1, [ %i1 + 1 ]
a00a02c4:  f0 2e 40 00  stb  %i0, [ %i1 ]
a00a02c8:  c2 02 e0 08  ld  [ %o3 + 8 ], %g1
a00a02cc:  f0 00 60 84  ld  [ %g1 + 0x84 ], %i0
a00a02d0:  99 36 20 18  srl  %i0, 0x18, %o4
a00a02d4:  83 36 20 08  srl  %i0, 8, %g1
a00a02d8:  9b 36 20 10  srl  %i0, 0x10, %o5
a00a02dc:  da 2e 60 06  stb  %o5, [ %i1 + 6 ]
a00a02e0:  d8 2e 60 07  stb  %o4, [ %i1 + 7 ]
a00a02e4:  c2 2e 60 05  stb  %g1, [ %i1 + 5 ]
a00a02e8:  f0 2e 60 04  stb  %i0, [ %i1 + 4 ]
a00a02ec:  c2 02 e0 08  ld  [ %o3 + 8 ], %g1
a00a02f0:  f0 00 60 88  ld  [ %g1 + 0x88 ], %i0
a00a02f4:  99 36 20 18  srl  %i0, 0x18, %o4
a00a02f8:  83 36 20 08  srl  %i0, 8, %g1
a00a02fc:  9b 36 20 10  srl  %i0, 0x10, %o5
a00a0300:  da 2e 60 0a  stb  %o5, [ %i1 + 0xa ]
a00a0304:  d8 2e 60 0b  stb  %o4, [ %i1 + 0xb ]
a00a0308:  c2 2e 60 09  stb  %g1, [ %i1 + 9 ]
a00a030c:  f0 2e 60 08  stb  %i0, [ %i1 + 8 ]
a00a0310:  c2 02 e0 08  ld  [ %o3 + 8 ], %g1
a00a0314:  f0 00 60 8c  ld  [ %g1 + 0x8c ], %i0
a00a0318:  99 36 20 18  srl  %i0, 0x18, %o4
a00a031c:  83 36 20 08  srl  %i0, 8, %g1
a00a0320:  9b 36 20 10  srl  %i0, 0x10, %o5
a00a0324:  da 2e 60 0e  stb  %o5, [ %i1 + 0xe ]
a00a0328:  d8 2e 60 0f  stb  %o4, [ %i1 + 0xf ]
a00a032c:  c2 2e 60 0d  stb  %g1, [ %i1 + 0xd ]
a00a0330:  f0 2e 60 0c  stb  %i0, [ %i1 + 0xc ]
a00a0334:  c2 02 e0 08  ld  [ %o3 + 8 ], %g1
a00a0338:  f0 00 60 90  ld  [ %g1 + 0x90 ], %i0
a00a033c:  99 36 20 18  srl  %i0, 0x18, %o4
a00a0340:  83 36 20 08  srl  %i0, 8, %g1
a00a0344:  9b 36 20 10  srl  %i0, 0x10, %o5
a00a0348:  da 2e 60 12  stb  %o5, [ %i1 + 0x12 ]
a00a034c:  d8 2e 60 13  stb  %o4, [ %i1 + 0x13 ]
a00a0350:  c2 2e 60 11  stb  %g1, [ %i1 + 0x11 ]
a00a0354:  f0 2e 60 10  stb  %i0, [ %i1 + 0x10 ]
a00a0358:  c2 02 e0 08  ld  [ %o3 + 8 ], %g1
a00a035c:  f0 00 60 94  ld  [ %g1 + 0x94 ], %i0
a00a0360:  83 36 20 08  srl  %i0, 8, %g1
a00a0364:  9b 36 20 10  srl  %i0, 0x10, %o5
a00a0368:  f0 2e 60 14  stb  %i0, [ %i1 + 0x14 ]
a00a036c:  c2 2e 60 15  stb  %g1, [ %i1 + 0x15 ]
a00a0370:  da 2e 60 16  stb  %o5, [ %i1 + 0x16 ]
a00a0374:  99 36 20 18  srl  %i0, 0x18, %o4
a00a0378:  d8 2e 60 17  stb  %o4, [ %i1 + 0x17 ]
a00a037c:  c2 02 e0 08  ld  [ %o3 + 8 ], %g1
a00a0380:  f0 00 60 98  ld  [ %g1 + 0x98 ], %i0
a00a0384:  83 36 20 08  srl  %i0, 8, %g1
a00a0388:  9b 36 20 10  srl  %i0, 0x10, %o5
a00a038c:  99 36 20 18  srl  %i0, 0x18, %o4
a00a0390:  da 2e 60 1a  stb  %o5, [ %i1 + 0x1a ]
a00a0394:  c2 2e 60 19  stb  %g1, [ %i1 + 0x19 ]
a00a0398:  d8 2e 60 1b  stb  %o4, [ %i1 + 0x1b ]
a00a039c:  f0 2e 60 18  stb  %i0, [ %i1 + 0x18 ]
a00a03a0:  c2 02 e0 08  ld  [ %o3 + 8 ], %g1
a00a03a4:  f0 00 60 9c  ld  [ %g1 + 0x9c ], %i0
a00a03a8:  83 36 20 10  srl  %i0, 0x10, %g1
a00a03ac:  9b 36 20 08  srl  %i0, 8, %o5
a00a03b0:  f0 2e 60 1c  stb  %i0, [ %i1 + 0x1c ]
a00a03b4:  c2 2e 60 1e  stb  %g1, [ %i1 + 0x1e ]
a00a03b8:  da 2e 60 1d  stb  %o5, [ %i1 + 0x1d ]
a00a03bc:  b0 10 20 00  clr  %i0
a00a03c0:  81 c7 e0 08  ret
a00a03c4:  81 e8 00 00  restore
