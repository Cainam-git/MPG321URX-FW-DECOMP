# leon2m FUN_a012f31c 0xa012f31c-0xa012f3b4 (152 bytes)
a012f31c:  03 00 06 94  sethi  %hi(0x1a5000), %g1
a012f320:  d6 0a 20 0a  ldub  [ %o0 + 0xa ], %o3
a012f324:  94 10 62 38  or  %g1, 0x238, %o2
a012f328:  98 10 20 00  clr  %o4
a012f32c:  9a 10 20 00  clr  %o5
a012f330:  d0 0a 80 0d  ldub  [ %o2 + %o5 ], %o0
a012f334:  80 a2 c0 08  cmp  %o3, %o0
a012f338:  02 80 00 1b  be  0xa012f3a4
a012f33c:  98 03 20 01  inc  %o4
a012f340:  9a 0b 20 ff  and  %o4, 0xff, %o5
a012f344:  80 a3 60 03  cmp  %o5, 3
a012f348:  28 bf ff fb  bleu,a   0xa012f334
a012f34c:  d0 0a 80 0d  ldub  [ %o2 + %o5 ], %o0
a012f350:  82 10 20 ff  mov  0xff, %g1
a012f354:  17 00 06 94  sethi  %hi(0x1a5000), %o3
a012f358:  92 12 e2 38  or  %o3, 0x238, %o1	! 0x1a5238
a012f35c:  94 08 60 ff  and  %g1, 0xff, %o2
a012f360:  da 0a 40 0a  ldub  [ %o1 + %o2 ], %o5
a012f364:  9a 0b 60 fc  and  %o5, 0xfc, %o5
a012f368:  96 10 20 01  mov  1, %o3
a012f36c:  98 10 20 01  mov  1, %o4
a012f370:  82 02 80 0c  add  %o2, %o4, %g1
a012f374:  90 08 60 03  and  %g1, 3, %o0
a012f378:  c2 0a 40 08  ldub  [ %o1 + %o0 ], %g1
a012f37c:  96 02 e0 01  inc  %o3
a012f380:  82 08 60 fc  and  %g1, 0xfc, %g1
a012f384:  80 a0 40 0d  cmp  %g1, %o5
a012f388:  02 80 00 09  be  0xa012f3ac
a012f38c:  98 0a e0 ff  and  %o3, 0xff, %o4
a012f390:  80 a3 20 04  cmp  %o4, 4
a012f394:  08 bf ff f8  bleu  0xa012f374
a012f398:  82 02 80 0c  add  %o2, %o4, %g1
a012f39c:  10 80 00 04  b  0xa012f3ac
a012f3a0:  90 10 00 0a  mov  %o2, %o0
a012f3a4:  10 bf ff ec  b  0xa012f354
a012f3a8:  82 10 00 0d  mov  %o5, %g1
a012f3ac:  81 c3 e0 08  retl
a012f3b0:  01 00 00 00  nop
