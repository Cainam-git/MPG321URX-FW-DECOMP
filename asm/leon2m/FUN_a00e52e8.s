# leon2m FUN_a00e52e8 0xa00e52e8-0xa00e5428 (320 bytes)
a00e52e8:  9d e3 bf 98  save  %sp, -104, %sp
a00e52ec:  80 a6 7f ff  cmp  %i1, -1
a00e52f0:  02 80 00 27  be  0xa00e538c
a00e52f4:  a4 10 00 18  mov  %i0, %l2
a00e52f8:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00e52fc:  9b 2e 60 02  sll  %i1, 2, %o5
a00e5300:  90 14 e2 e8  or  %l3, 0x2e8, %o0
a00e5304:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e5308:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00e530c:  98 15 62 f8  or  %l5, 0x2f8, %o4
a00e5310:  82 15 22 d8  or  %l4, 0x2d8, %g1
a00e5314:  d4 02 00 0d  ld  [ %o0 + %o5 ], %o2
a00e5318:  d6 00 40 0d  ld  [ %g1 + %o5 ], %o3
a00e531c:  d2 03 00 0d  ld  [ %o4 + %o5 ], %o1
a00e5320:  90 10 00 18  mov  %i0, %o0
a00e5324:  7f ff ed 0c  call  0xa00e0754
a00e5328:  b0 10 20 00  clr  %i0
a00e532c:  80 a6 a0 00  cmp  %i2, 0
a00e5330:  02 80 00 3c  be  0xa00e5420
a00e5334:  a0 10 00 08  mov  %o0, %l0
a00e5338:  80 a6 a0 00  cmp  %i2, 0
a00e533c:  04 80 00 1c  ble  0xa00e53ac
a00e5340:  94 10 20 0f  mov  0xf, %o2
a00e5344:  92 22 80 08  sub  %o2, %o0, %o1
a00e5348:  80 a2 40 1a  cmp  %o1, %i2
a00e534c:  06 80 00 2e  bl  0xa00e5404
a00e5350:  a2 02 00 1a  add  %o0, %i2, %l1
a00e5354:  80 a6 7f ff  cmp  %i1, -1
a00e5358:  02 80 00 26  be  0xa00e53f0
a00e535c:  a1 2e 60 02  sll  %i1, 2, %l0
a00e5360:  b0 15 62 f8  or  %l5, 0x2f8, %i0
a00e5364:  aa 14 e2 e8  or  %l3, 0x2e8, %l5
a00e5368:  a6 15 22 d8  or  %l4, 0x2d8, %l3
a00e536c:  d6 04 c0 10  ld  [ %l3 + %l0 ], %o3
a00e5370:  90 10 00 12  mov  %l2, %o0
a00e5374:  d2 06 00 10  ld  [ %i0 + %l0 ], %o1
a00e5378:  d4 05 40 10  ld  [ %l5 + %l0 ], %o2
a00e537c:  7f ff ec fe  call  0xa00e0774
a00e5380:  98 10 00 11  mov  %l1, %o4
a00e5384:  10 80 00 27  b  0xa00e5420
a00e5388:  b0 10 20 00  clr  %i0
a00e538c:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e5390:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00e5394:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00e5398:  90 10 00 18  mov  %i0, %o0
a00e539c:  92 15 62 f8  or  %l5, 0x2f8, %o1
a00e53a0:  94 14 e2 e8  or  %l3, 0x2e8, %o2
a00e53a4:  10 bf ff e0  b  0xa00e5324
a00e53a8:  96 15 22 d8  or  %l4, 0x2d8, %o3
a00e53ac:  16 bf ff ea  bge  0xa00e5354
a00e53b0:  a2 02 00 1a  add  %o0, %i2, %l1
a00e53b4:  a2 82 00 1a  addcc  %o0, %i2, %l1
a00e53b8:  1c bf ff e8  bpos  0xa00e5358
a00e53bc:  80 a6 7f ff  cmp  %i1, -1
a00e53c0:  7f ff e9 13  call  0xa00df80c
a00e53c4:  01 00 00 00  nop
a00e53c8:  7f ff ed fe  call  0xa00e0bc0
a00e53cc:  01 00 00 00  nop
a00e53d0:  1f 00 06 66  sethi  %hi(0x199800), %o7
a00e53d4:  90 13 e0 78  or  %o7, 0x78, %o0	! 0x199878
a00e53d8:  92 10 00 19  mov  %i1, %o1
a00e53dc:  94 10 00 10  mov  %l0, %o2
a00e53e0:  7f ff e7 64  call  0xa00df170
a00e53e4:  96 10 00 1a  mov  %i2, %o3
a00e53e8:  10 80 00 0e  b  0xa00e5420
a00e53ec:  b0 10 3f ff  mov  -1, %i0
a00e53f0:  90 10 00 12  mov  %l2, %o0
a00e53f4:  92 15 62 f8  or  %l5, 0x2f8, %o1
a00e53f8:  94 14 e2 e8  or  %l3, 0x2e8, %o2
a00e53fc:  10 bf ff e0  b  0xa00e537c
a00e5400:  96 15 22 d8  or  %l4, 0x2d8, %o3
a00e5404:  7f ff e9 02  call  0xa00df80c
a00e5408:  01 00 00 00  nop
a00e540c:  7f ff ed ed  call  0xa00e0bc0
a00e5410:  01 00 00 00  nop
a00e5414:  17 00 06 66  sethi  %hi(0x199800), %o3
a00e5418:  10 bf ff f0  b  0xa00e53d8
a00e541c:  90 12 e0 b8  or  %o3, 0xb8, %o0	! 0x1998b8
a00e5420:  81 c7 e0 08  ret
a00e5424:  81 e8 00 00  restore
