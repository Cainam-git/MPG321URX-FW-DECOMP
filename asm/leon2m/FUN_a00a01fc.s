# leon2m FUN_a00a01fc 0xa00a01fc-0xa00a03e8 (492 bytes)
a00a01fc:  9d e3 bf 98  save  %sp, -104, %sp
a00a0200:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00a0204:  a4 10 62 90  or  %g1, 0x290, %l2	! 0xa802d290
a00a0208:  da 0c a1 a9  ldub  [ %l2 + 0x1a9 ], %o5
a00a020c:  80 a3 60 01  cmp  %o5, 1
a00a0210:  02 80 00 54  be  0xa00a0360
a00a0214:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a00a0218:  d2 04 a0 a8  ld  [ %l2 + 0xa8 ], %o1
a00a021c:  91 32 60 0b  srl  %o1, 0xb, %o0
a00a0220:  82 0a 20 01  and  %o0, 1, %g1
a00a0224:  de 0c a1 81  ldub  [ %l2 + 0x181 ], %o7
a00a0228:  e6 0c a0 11  ldub  [ %l2 + 0x11 ], %l3
a00a022c:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a00a0230:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a00a0234:  e6 2c 60 54  stb  %l3, [ %l1 + 0x54 ]	! 0xa8025c54
a00a0238:  de 2b 20 56  stb  %o7, [ %o4 + 0x56 ]
a00a023c:  c2 2b 60 55  stb  %g1, [ %o5 + 0x55 ]
a00a0240:  90 0b e0 ff  and  %o7, 0xff, %o0
a00a0244:  40 00 5a 51  call  0xa00b6b88
a00a0248:  92 10 20 00  clr  %o1
a00a024c:  27 2a 00 ab  sethi  %hi(0xa802ac00), %l3
a00a0250:  d6 04 e3 ec  ld  [ %l3 + 0x3ec ], %o3	! 0xa802afec
a00a0254:  a0 10 00 08  mov  %o0, %l0
a00a0258:  94 02 ff eb  add  %o3, -21, %o2
a00a025c:  92 10 20 02  mov  2, %o1
a00a0260:  40 00 23 6b  call  0xa00a900c
a00a0264:  90 0a a0 ff  and  %o2, 0xff, %o0
a00a0268:  a2 0c 20 ff  and  %l0, 0xff, %l1
a00a026c:  d8 04 a0 a8  ld  [ %l2 + 0xa8 ], %o4
a00a0270:  92 04 60 5c  add  %l1, 0x5c, %o1
a00a0274:  80 8b 28 00  btst  0x800, %o4
a00a0278:  02 80 00 23  be  0xa00a0304
a00a027c:  d2 24 e3 ec  st  %o1, [ %l3 + 0x3ec ]
a00a0280:  21 09 24 92  sethi  %hi(0x24924800), %l0
a00a0284:  a4 14 21 25  or  %l0, 0x125, %l2	! 0x24924925
a00a0288:  80 54 40 12  umul  %l1, %l2, %g0
a00a028c:  83 40 00 00  rd  %y, %g1
a00a0290:  90 24 40 01  sub  %l1, %g1, %o0
a00a0294:  93 32 20 01  srl  %o0, 1, %o1
a00a0298:  98 00 40 09  add  %g1, %o1, %o4
a00a029c:  9b 33 20 02  srl  %o4, 2, %o5
a00a02a0:  9f 2b 60 03  sll  %o5, 3, %o7
a00a02a4:  96 23 c0 0d  sub  %o7, %o5, %o3
a00a02a8:  94 24 40 0b  sub  %l1, %o3, %o2
a00a02ac:  92 0a a0 ff  and  %o2, 0xff, %o1
a00a02b0:  90 10 20 01  mov  1, %o0
a00a02b4:  40 00 1f a2  call  0xa00a813c
a00a02b8:  94 10 20 00  clr  %o2
a00a02bc:  d0 04 e3 ec  ld  [ %l3 + 0x3ec ], %o0
a00a02c0:  94 02 3f a4  add  %o0, -92, %o2
a00a02c4:  80 52 80 12  umul  %o2, %l2, %g0
a00a02c8:  99 40 00 00  rd  %y, %o4
a00a02cc:  92 22 80 0c  sub  %o2, %o4, %o1
a00a02d0:  83 32 60 01  srl  %o1, 1, %g1
a00a02d4:  9a 03 00 01  add  %o4, %g1, %o5
a00a02d8:  a1 33 60 02  srl  %o5, 2, %l0
a00a02dc:  9f 2c 20 03  sll  %l0, 3, %o7
a00a02e0:  96 23 c0 10  sub  %o7, %l0, %o3
a00a02e4:  a6 22 80 0b  sub  %o2, %o3, %l3
a00a02e8:  90 0c e0 ff  and  %l3, 0xff, %o0
a00a02ec:  40 00 24 d9  call  0xa00a9650
a00a02f0:  92 10 20 01  mov  1, %o1
a00a02f4:  a2 10 20 0c  mov  0xc, %l1
a00a02f8:  25 2a 00 ac  sethi  %hi(0xa802b000), %l2
a00a02fc:  10 80 00 39  b  0xa00a03e0
a00a0300:  e2 2c a0 8f  stb  %l1, [ %l2 + 0x8f ]	! 0xa802b08f
a00a0304:  1b 00 3f ff  sethi  %hi(0xfffc00), %o5
a00a0308:  d6 04 a1 80  ld  [ %l2 + 0x180 ], %o3
a00a030c:  9e 13 63 00  or  %o5, 0x300, %o7
a00a0310:  a0 0a c0 0f  and  %o3, %o7, %l0
a00a0314:  94 13 28 00  or  %o4, 0x800, %o2
a00a0318:  80 a4 21 00  cmp  %l0, 0x100
a00a031c:  02 80 00 0c  be  0xa00a034c
a00a0320:  d4 24 a0 a8  st  %o2, [ %l2 + 0xa8 ]
a00a0324:  d0 0c a1 81  ldub  [ %l2 + 0x181 ], %o0
a00a0328:  82 02 3f fc  add  %o0, -4, %g1
a00a032c:  98 08 60 ff  and  %g1, 0xff, %o4
a00a0330:  80 a3 20 02  cmp  %o4, 2
a00a0334:  18 80 00 04  bgu  0xa00a0344
a00a0338:  01 00 00 00  nop
a00a033c:  92 10 20 01  mov  1, %o1	! 0x1
a00a0340:  d2 2c a0 11  stb  %o1, [ %l2 + 0x11 ]
a00a0344:  40 00 ec fd  call  0xa00db738
a00a0348:  01 00 00 00  nop
a00a034c:  90 10 20 02  mov  2, %o0	! 0x2
a00a0350:  40 00 2a 59  call  0xa00aacb4
a00a0354:  92 10 20 01  mov  1, %o1
a00a0358:  10 bf ff cb  b  0xa00a0284
a00a035c:  21 09 24 92  sethi  %hi(0x24924800), %l0
a00a0360:  17 2a 00 b3  sethi  %hi(0xa802cc00), %o3
a00a0364:  a2 12 e3 f4  or  %o3, 0x3f4, %l1	! 0xa802cff4
a00a0368:  da 14 60 04  lduh  [ %l1 + 4 ], %o5
a00a036c:  15 3f ff e0  sethi  %hi(0xffff8000), %o2
a00a0370:  92 0b 40 0a  and  %o5, %o2, %o1
a00a0374:  91 2a 60 10  sll  %o1, 0x10, %o0
a00a0378:  80 a2 20 00  cmp  %o0, 0
a00a037c:  12 80 00 13  bne  0xa00a03c8
a00a0380:  98 13 64 00  or  %o5, 0x400, %o4
a00a0384:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00a0388:  40 00 53 3e  call  0xa00b5080
a00a038c:  c0 24 23 ec  clr  [ %l0 + 0x3ec ]	! 0xa802afec
a00a0390:  90 10 20 02  mov  2, %o0
a00a0394:  40 00 42 ed  call  0xa00b0f48
a00a0398:  d0 2c 60 0a  stb  %o0, [ %l1 + 0xa ]
a00a039c:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00a03a0:  c2 0c 60 8e  ldub  [ %l1 + 0x8e ], %g1	! 0xa802b08e
a00a03a4:  a6 10 60 02  or  %g1, 2, %l3
a00a03a8:  9a 10 21 16  mov  0x116, %o5
a00a03ac:  da 24 23 ec  st  %o5, [ %l0 + 0x3ec ]
a00a03b0:  e6 2c 60 8e  stb  %l3, [ %l1 + 0x8e ]
a00a03b4:  67 ff b4 75  call  0x4008d588
a00a03b8:  c0 2c a1 aa  clrb  [ %l2 + 0x1aa ]
a00a03bc:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00a03c0:  10 80 00 08  b  0xa00a03e0
a00a03c4:  d0 33 e0 3c  sth  %o0, [ %o7 + 0x3c ]	! 0xa802d03c
a00a03c8:  d8 34 60 04  sth  %o4, [ %l1 + 4 ]
a00a03cc:  90 10 20 04  mov  4, %o0
a00a03d0:  7f ff 81 37  call  0xa00808ac
a00a03d4:  92 10 20 00  clr  %o1
a00a03d8:  10 bf ff ec  b  0xa00a0388
a00a03dc:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00a03e0:  81 c7 e0 08  ret
a00a03e4:  81 e8 00 00  restore
