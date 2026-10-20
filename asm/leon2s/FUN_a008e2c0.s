# leon2s FUN_a008e2c0 0xa008e2c0-0xa008e3c0 (256 bytes)
a008e2c0:  9d e3 bf 98  save  %sp, -104, %sp
a008e2c4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a008e2c8:  80 a6 60 01  cmp  %i1, 1
a008e2cc:  02 80 00 0d  be  0xa008e300
a008e2d0:  b6 10 20 01  mov  1, %i3
a008e2d4:  80 a6 60 01  cmp  %i1, 1
a008e2d8:  34 80 00 04  bg,a   0xa008e2e8
a008e2dc:  80 a6 60 02  cmp  %i1, 2
a008e2e0:  10 80 00 06  b  0xa008e2f8
a008e2e4:  80 a6 60 00  cmp  %i1, 0
a008e2e8:  02 80 00 06  be  0xa008e300
a008e2ec:  b6 10 20 01  mov  1, %i3
a008e2f0:  80 a6 60 03  cmp  %i1, 3
a008e2f4:  b6 10 00 1a  mov  %i2, %i3
a008e2f8:  32 80 00 02  bne,a   0xa008e300
a008e2fc:  b6 10 20 03  mov  3, %i3
a008e300:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008e304:  92 10 20 01  mov  1, %o1
a008e308:  94 10 20 0a  mov  0xa, %o2
a008e30c:  40 00 67 33  call  0xa00a7fd8
a008e310:  90 10 00 18  mov  %i0, %o0
a008e314:  a0 0e e0 ff  and  %i3, 0xff, %l0
a008e318:  a3 2c 20 06  sll  %l0, 6, %l1
a008e31c:  96 0a 20 3f  and  %o0, 0x3f, %o3
a008e320:  96 12 c0 11  or  %o3, %l1, %o3
a008e324:  96 0a e0 ff  and  %o3, 0xff, %o3
a008e328:  90 10 00 18  mov  %i0, %o0
a008e32c:  92 10 20 01  mov  1, %o1
a008e330:  40 00 67 49  call  0xa00a8054
a008e334:  94 10 20 0a  mov  0xa, %o2
a008e338:  92 10 20 01  mov  1, %o1
a008e33c:  94 10 20 0a  mov  0xa, %o2
a008e340:  40 00 67 26  call  0xa00a7fd8
a008e344:  90 10 00 18  mov  %i0, %o0
a008e348:  96 0a 3f fc  and  %o0, -4, %o3
a008e34c:  96 12 c0 1b  or  %o3, %i3, %o3
a008e350:  96 0a e0 ff  and  %o3, 0xff, %o3
a008e354:  90 10 00 18  mov  %i0, %o0
a008e358:  92 10 20 01  mov  1, %o1
a008e35c:  40 00 67 3e  call  0xa00a8054
a008e360:  94 10 20 0a  mov  0xa, %o2
a008e364:  92 10 20 01  mov  1, %o1
a008e368:  94 10 20 99  mov  0x99, %o2
a008e36c:  40 00 67 1b  call  0xa00a7fd8
a008e370:  90 10 00 18  mov  %i0, %o0
a008e374:  96 0a 20 3f  and  %o0, 0x3f, %o3
a008e378:  96 12 c0 11  or  %o3, %l1, %o3
a008e37c:  96 0a e0 ff  and  %o3, 0xff, %o3
a008e380:  90 10 00 18  mov  %i0, %o0
a008e384:  92 10 20 01  mov  1, %o1
a008e388:  40 00 67 33  call  0xa00a8054
a008e38c:  94 10 20 99  mov  0x99, %o2
a008e390:  90 10 00 18  mov  %i0, %o0
a008e394:  92 10 20 01  mov  1, %o1
a008e398:  40 00 67 10  call  0xa00a7fd8
a008e39c:  94 10 20 99  mov  0x99, %o2
a008e3a0:  90 0a 3f cf  and  %o0, -49, %o0
a008e3a4:  a1 2c 20 04  sll  %l0, 4, %l0
a008e3a8:  90 12 00 10  or  %o0, %l0, %o0
a008e3ac:  b6 0a 20 ff  and  %o0, 0xff, %i3
a008e3b0:  b2 10 20 01  mov  1, %i1
a008e3b4:  40 00 67 28  call  0xa00a8054
a008e3b8:  95 e8 20 99  restore  %g0, 0x99, %o2
a008e3bc:  01 00 00 00  nop
