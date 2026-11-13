# leon2m FUN_a00b32e4 0xa00b32e4-0xa00b344c (360 bytes)
a00b32e4:  9d e3 bf 98  save  %sp, -104, %sp
a00b32e8:  91 2e a0 10  sll  %i2, 0x10, %o0
a00b32ec:  91 32 20 10  srl  %o0, 0x10, %o0
a00b32f0:  e0 0f a0 5f  ldub  [ %fp + 0x5f ], %l0
a00b32f4:  40 02 4d ef  call  0xa0146ab0
a00b32f8:  92 10 20 00  clr  %o1
a00b32fc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b3300:  80 a6 20 01  cmp  %i0, 1
a00b3304:  02 80 00 2a  be  0xa00b33ac
a00b3308:  ba 0f 60 ff  and  %i5, 0xff, %i5
a00b330c:  80 a7 60 00  cmp  %i5, 0
a00b3310:  02 80 00 4d  be  0xa00b3444
a00b3314:  b4 10 20 00  clr  %i2
a00b3318:  80 8e 60 ff  btst  0xff, %i1
a00b331c:  b7 2e e0 10  sll  %i3, 0x10, %i3
a00b3320:  12 80 00 12  bne  0xa00b3368
a00b3324:  b8 0f 20 ff  and  %i4, 0xff, %i4
a00b3328:  b2 0e a0 ff  and  %i2, 0xff, %i1
a00b332c:  9e 07 00 19  add  %i4, %i1, %o7
a00b3330:  9b 2b e0 10  sll  %o7, 0x10, %o5
a00b3334:  95 33 60 10  srl  %o5, 0x10, %o2
a00b3338:  98 0c 20 ff  and  %l0, 0xff, %o4
a00b333c:  90 10 20 01  mov  1, %o0
a00b3340:  93 36 e0 10  srl  %i3, 0x10, %o1
a00b3344:  96 10 20 01  mov  1, %o3
a00b3348:  40 02 4d f6  call  0xa0146b20
a00b334c:  9a 10 20 00  clr  %o5
a00b3350:  b4 06 a0 01  inc  %i2
a00b3354:  98 0e a0 ff  and  %i2, 0xff, %o4
a00b3358:  80 a3 00 1d  cmp  %o4, %i5
a00b335c:  0a bf ff f4  bcs  0xa00b332c
a00b3360:  b2 0e a0 ff  and  %i2, 0xff, %i1
a00b3364:  30 80 00 38  b,a   0xa00b3444
a00b3368:  94 0e a0 ff  and  %i2, 0xff, %o2
a00b336c:  92 07 00 0a  add  %i4, %o2, %o1
a00b3370:  90 04 00 1a  add  %l0, %i2, %o0
a00b3374:  83 2a 60 10  sll  %o1, 0x10, %g1
a00b3378:  98 0a 20 ff  and  %o0, 0xff, %o4
a00b337c:  95 30 60 10  srl  %g1, 0x10, %o2
a00b3380:  90 10 20 01  mov  1, %o0
a00b3384:  93 36 e0 10  srl  %i3, 0x10, %o1
a00b3388:  96 10 20 01  mov  1, %o3
a00b338c:  9a 10 20 00  clr  %o5
a00b3390:  40 02 4d e4  call  0xa0146b20
a00b3394:  b4 06 a0 01  inc  %i2
a00b3398:  b0 0e a0 ff  and  %i2, 0xff, %i0
a00b339c:  80 a6 00 1d  cmp  %i0, %i5
a00b33a0:  0a bf ff f3  bcs  0xa00b336c
a00b33a4:  94 0e a0 ff  and  %i2, 0xff, %o2
a00b33a8:  30 80 00 27  b,a   0xa00b3444
a00b33ac:  80 a7 60 00  cmp  %i5, 0
a00b33b0:  02 80 00 25  be  0xa00b3444
a00b33b4:  b4 10 20 00  clr  %i2
a00b33b8:  80 8e 60 ff  btst  0xff, %i1
a00b33bc:  12 80 00 12  bne  0xa00b3404
a00b33c0:  b8 0f 20 ff  and  %i4, 0xff, %i4
a00b33c4:  96 0e a0 ff  and  %i2, 0xff, %o3
a00b33c8:  94 02 c0 1b  add  %o3, %i3, %o2
a00b33cc:  93 2a a0 10  sll  %o2, 0x10, %o1
a00b33d0:  93 32 60 10  srl  %o1, 0x10, %o1
a00b33d4:  90 10 20 01  mov  1, %o0
a00b33d8:  94 10 00 1c  mov  %i4, %o2
a00b33dc:  96 10 20 01  mov  1, %o3
a00b33e0:  98 0c 20 ff  and  %l0, 0xff, %o4
a00b33e4:  40 02 4d cf  call  0xa0146b20
a00b33e8:  9a 10 20 00  clr  %o5
a00b33ec:  b4 06 a0 01  inc  %i2
a00b33f0:  82 0e a0 ff  and  %i2, 0xff, %g1
a00b33f4:  80 a0 40 1d  cmp  %g1, %i5
a00b33f8:  0a bf ff f4  bcs  0xa00b33c8
a00b33fc:  96 0e a0 ff  and  %i2, 0xff, %o3
a00b3400:  30 80 00 11  b,a   0xa00b3444
a00b3404:  b2 0e a0 ff  and  %i2, 0xff, %i1
a00b3408:  9e 06 40 1b  add  %i1, %i3, %o7
a00b340c:  9b 2b e0 10  sll  %o7, 0x10, %o5
a00b3410:  98 04 00 1a  add  %l0, %i2, %o4
a00b3414:  93 33 60 10  srl  %o5, 0x10, %o1
a00b3418:  96 10 20 01  mov  1, %o3
a00b341c:  98 0b 20 ff  and  %o4, 0xff, %o4
a00b3420:  90 10 20 01  mov  1, %o0
a00b3424:  94 10 00 1c  mov  %i4, %o2
a00b3428:  40 02 4d be  call  0xa0146b20
a00b342c:  9a 10 20 00  clr  %o5
a00b3430:  b4 06 a0 01  inc  %i2
a00b3434:  96 0e a0 ff  and  %i2, 0xff, %o3
a00b3438:  80 a2 c0 1d  cmp  %o3, %i5
a00b343c:  0a bf ff f3  bcs  0xa00b3408
a00b3440:  b2 0e a0 ff  and  %i2, 0xff, %i1
a00b3444:  81 c7 e0 08  ret
a00b3448:  81 e8 00 00  restore
