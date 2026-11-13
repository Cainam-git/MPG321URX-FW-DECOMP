# leon2m FUN_a012e2ac 0xa012e2ac-0xa012e3ec (320 bytes)
a012e2ac:  9d e3 bd 88  save  %sp, -632, %sp
a012e2b0:  96 10 20 0f  mov  0xf, %o3
a012e2b4:  94 10 3f f0  mov  -16, %o2
a012e2b8:  92 10 20 10  mov  0x10, %o1
a012e2bc:  90 10 20 01  mov  1, %o0
a012e2c0:  03 00 06 8c  sethi  %hi(0x1a3000), %g1
a012e2c4:  1b 14 7a e1  sethi  %hi(0x51eb8400), %o5
a012e2c8:  d6 2f bf f0  stb  %o3, [ %fp + -16 ]
a012e2cc:  d4 2f bf f1  stb  %o2, [ %fp + -15 ]
a012e2d0:  d2 2f bf f2  stb  %o1, [ %fp + -14 ]
a012e2d4:  d0 2f bf f3  stb  %o0, [ %fp + -13 ]
a012e2d8:  ba 10 61 a8  or  %g1, 0x1a8, %i5
a012e2dc:  aa 13 61 1f  or  %o5, 0x11f, %l5
a012e2e0:  b6 10 20 00  clr  %i3
a012e2e4:  b8 10 20 00  clr  %i4
a012e2e8:  a4 07 bf f8  add  %fp, -8, %l2
a012e2ec:  b4 07 bd f0  add  %fp, -528, %i2
a012e2f0:  90 10 20 00  clr  %o0
a012e2f4:  ac 10 20 00  clr  %l6
a012e2f8:  a6 10 20 00  clr  %l3
a012e2fc:  ae 0e e0 ff  and  %i3, 0xff, %l7
a012e300:  99 3c e0 1f  sra  %l3, 0x1f, %o4
a012e304:  97 33 20 1e  srl  %o4, 0x1e, %o3
a012e308:  94 04 c0 0b  add  %l3, %o3, %o2
a012e30c:  92 0a bf fc  and  %o2, -4, %o1
a012e310:  82 24 c0 09  sub  %l3, %o1, %g1
a012e314:  a8 04 80 01  add  %l2, %g1, %l4
a012e318:  9a 05 c0 18  add  %l7, %i0, %o5
a012e31c:  e2 0b 40 13  ldub  [ %o5 + %l3 ], %l1
a012e320:  e0 0d 3f f8  ldub  [ %l4 + -8 ], %l0
a012e324:  a8 1c 40 10  xor  %l1, %l0, %l4
a012e328:  9f 2d a0 10  sll  %l6, 0x10, %o7
a012e32c:  98 0d 20 ff  and  %l4, 0xff, %o4
a012e330:  a3 33 e0 0c  srl  %o7, 0xc, %l1
a012e334:  a1 2b 20 04  sll  %o4, 4, %l0
a012e338:  de 0f 40 13  ldub  [ %i5 + %l3 ], %o7
a012e33c:  94 10 20 04  mov  4, %o2
a012e340:  92 10 20 07  mov  7, %o1
a012e344:  83 3a a0 1f  sra  %o2, 0x1f, %g1
a012e348:  9b 30 60 1d  srl  %g1, 0x1d, %o5
a012e34c:  98 02 80 0d  add  %o2, %o5, %o4
a012e350:  97 3b 20 03  sra  %o4, 3, %o3
a012e354:  82 04 40 0b  add  %l1, %o3, %g1
a012e358:  9b 28 60 10  sll  %g1, 0x10, %o5
a012e35c:  99 33 60 10  srl  %o5, 0x10, %o4
a012e360:  96 5b 00 0f  smul  %o4, %o7, %o3
a012e364:  9b 2a 20 10  sll  %o0, 0x10, %o5
a012e368:  80 52 c0 15  umul  %o3, %l5, %g0
a012e36c:  83 40 00 00  rd  %y, %g1
a012e370:  98 02 20 01  add  %o0, 1, %o4
a012e374:  97 33 60 10  srl  %o5, 0x10, %o3
a012e378:  83 30 60 05  srl  %g1, 5, %g1
a012e37c:  9b 2b 20 10  sll  %o4, 0x10, %o5
a012e380:  99 28 60 02  sll  %g1, 2, %o4
a012e384:  96 04 80 0b  add  %l2, %o3, %o3
a012e388:  9b 33 60 10  srl  %o5, 0x10, %o5
a012e38c:  d8 2a fd f8  stb  %o4, [ %o3 + -520 ]
a012e390:  9a 04 80 0d  add  %l2, %o5, %o5
a012e394:  83 30 60 06  srl  %g1, 6, %g1
a012e398:  c2 2b 7d f8  stb  %g1, [ %o5 + -520 ]
a012e39c:  94 02 80 10  add  %o2, %l0, %o2
a012e3a0:  92 82 7f ff  addcc  %o1, -1, %o1
a012e3a4:  1c bf ff e8  bpos  0xa012e344
a012e3a8:  90 02 20 02  add  %o0, 2, %o0
a012e3ac:  9e 0d 20 ff  and  %l4, 0xff, %o7
a012e3b0:  a6 04 e0 01  inc  %l3
a012e3b4:  80 a4 e0 1f  cmp  %l3, 0x1f
a012e3b8:  04 bf ff d2  ble  0xa012e300
a012e3bc:  ac 05 80 0f  add  %l6, %o7, %l6
a012e3c0:  90 10 00 1c  mov  %i4, %o0
a012e3c4:  92 10 20 00  clr  %o1
a012e3c8:  94 10 22 00  mov  0x200, %o2
a012e3cc:  7f ff 72 b0  call  0xa010ae8c
a012e3d0:  96 10 00 1a  mov  %i2, %o3
a012e3d4:  b8 07 20 01  inc  %i4
a012e3d8:  80 a7 20 02  cmp  %i4, 2
a012e3dc:  04 bf ff c5  ble  0xa012e2f0
a012e3e0:  b6 06 e0 20  add  %i3, 0x20, %i3
a012e3e4:  81 c7 e0 08  ret
a012e3e8:  81 e8 00 00  restore
