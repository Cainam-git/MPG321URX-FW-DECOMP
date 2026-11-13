# leon2m FUN_a00bb260 0xa00bb260-0xa00bb414 (436 bytes)
a00bb260:  9d e3 bf 98  save  %sp, -104, %sp
a00bb264:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00bb268:  a6 10 60 d0  or  %g1, 0xd0, %l3	! 0xa802d0d0
a00bb26c:  a4 10 20 00  clr  %l2
a00bb270:  b0 10 20 00  clr  %i0
a00bb274:  a2 10 20 02  mov  2, %l1
a00bb278:  a0 10 20 02  mov  2, %l0
a00bb27c:  92 10 00 10  mov  %l0, %o1
a00bb280:  40 02 65 03  call  0xa015468c
a00bb284:  90 10 00 18  mov  %i0, %o0
a00bb288:  94 0a 20 ff  and  %o0, 0xff, %o2
a00bb28c:  a2 04 60 01  inc  %l1
a00bb290:  92 10 00 10  mov  %l0, %o1
a00bb294:  80 a2 a0 ff  cmp  %o2, 0xff
a00bb298:  02 80 00 09  be  0xa00bb2bc
a00bb29c:  90 10 00 18  mov  %i0, %o0
a00bb2a0:  40 02 64 fb  call  0xa015468c
a00bb2a4:  01 00 00 00  nop
a00bb2a8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00bb2ac:  d2 0c c0 10  ldub  [ %l3 + %l0 ], %o1
a00bb2b0:  80 a2 00 09  cmp  %o0, %o1
a00bb2b4:  12 80 00 07  bne  0xa00bb2d0
a00bb2b8:  80 a4 20 0a  cmp  %l0, 0xa
a00bb2bc:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00bb2c0:  80 a4 20 09  cmp  %l0, 9
a00bb2c4:  08 bf ff ef  bleu  0xa00bb280
a00bb2c8:  92 10 00 10  mov  %l0, %o1
a00bb2cc:  80 a4 20 0a  cmp  %l0, 0xa
a00bb2d0:  02 80 00 4a  be  0xa00bb3f8
a00bb2d4:  a4 04 a0 01  inc  %l2
a00bb2d8:  b0 0c a0 ff  and  %l2, 0xff, %i0
a00bb2dc:  80 a6 20 8c  cmp  %i0, 0x8c
a00bb2e0:  08 bf ff e6  bleu  0xa00bb278
a00bb2e4:  a2 10 20 02  mov  2, %l1
a00bb2e8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00bb2ec:  a6 12 e0 d0  or  %o3, 0xd0, %l3	! 0xa802d0d0
a00bb2f0:  a4 10 20 00  clr  %l2
a00bb2f4:  b0 10 20 00  clr  %i0
a00bb2f8:  a0 10 20 02  mov  2, %l0
a00bb2fc:  92 10 00 10  mov  %l0, %o1
a00bb300:  40 02 64 fb  call  0xa01546ec
a00bb304:  90 10 00 18  mov  %i0, %o0
a00bb308:  98 0a 20 ff  and  %o0, 0xff, %o4
a00bb30c:  a2 04 60 01  inc  %l1
a00bb310:  92 10 00 10  mov  %l0, %o1
a00bb314:  80 a3 20 ff  cmp  %o4, 0xff
a00bb318:  02 80 00 09  be  0xa00bb33c
a00bb31c:  90 10 00 18  mov  %i0, %o0
a00bb320:  40 02 64 f3  call  0xa01546ec
a00bb324:  01 00 00 00  nop
a00bb328:  9e 0a 20 ff  and  %o0, 0xff, %o7
a00bb32c:  da 0c c0 10  ldub  [ %l3 + %l0 ], %o5
a00bb330:  80 a3 c0 0d  cmp  %o7, %o5
a00bb334:  12 80 00 07  bne  0xa00bb350
a00bb338:  80 a4 20 19  cmp  %l0, 0x19
a00bb33c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00bb340:  80 a4 20 18  cmp  %l0, 0x18
a00bb344:  08 bf ff ef  bleu  0xa00bb300
a00bb348:  92 10 00 10  mov  %l0, %o1
a00bb34c:  80 a4 20 19  cmp  %l0, 0x19
a00bb350:  02 80 00 2c  be  0xa00bb400
a00bb354:  a0 04 bf 8d  add  %l2, -115, %l0
a00bb358:  a4 04 a0 01  inc  %l2
a00bb35c:  b0 0c a0 ff  and  %l2, 0xff, %i0
a00bb360:  80 a6 20 0c  cmp  %i0, 0xc
a00bb364:  08 bf ff e5  bleu  0xa00bb2f8
a00bb368:  a2 10 20 02  mov  2, %l1
a00bb36c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00bb370:  a6 14 60 d0  or  %l1, 0xd0, %l3	! 0xa802d0d0
a00bb374:  a4 10 20 00  clr  %l2
a00bb378:  b0 10 20 00  clr  %i0
a00bb37c:  a2 10 20 02  mov  2, %l1
a00bb380:  a0 10 20 02  mov  2, %l0
a00bb384:  92 10 00 10  mov  %l0, %o1
a00bb388:  40 02 64 f2  call  0xa0154750
a00bb38c:  90 10 00 18  mov  %i0, %o0
a00bb390:  82 0a 20 ff  and  %o0, 0xff, %g1
a00bb394:  a2 04 60 01  inc  %l1
a00bb398:  92 10 00 10  mov  %l0, %o1
a00bb39c:  80 a0 60 ff  cmp  %g1, 0xff
a00bb3a0:  02 80 00 09  be  0xa00bb3c4
a00bb3a4:  90 10 00 18  mov  %i0, %o0
a00bb3a8:  40 02 64 ea  call  0xa0154750
a00bb3ac:  01 00 00 00  nop
a00bb3b0:  92 0a 20 ff  and  %o0, 0xff, %o1
a00bb3b4:  d4 0c c0 10  ldub  [ %l3 + %l0 ], %o2
a00bb3b8:  80 a2 40 0a  cmp  %o1, %o2
a00bb3bc:  12 80 00 07  bne  0xa00bb3d8
a00bb3c0:  80 a4 20 06  cmp  %l0, 6
a00bb3c4:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00bb3c8:  80 a4 20 05  cmp  %l0, 5
a00bb3cc:  08 bf ff ef  bleu  0xa00bb388
a00bb3d0:  92 10 00 10  mov  %l0, %o1
a00bb3d4:  80 a4 20 06  cmp  %l0, 6
a00bb3d8:  02 80 00 0c  be  0xa00bb408
a00bb3dc:  a4 04 a0 01  inc  %l2
a00bb3e0:  b0 0c a0 ff  and  %l2, 0xff, %i0
a00bb3e4:  80 a6 20 00  cmp  %i0, 0
a00bb3e8:  22 bf ff e6  be,a   0xa00bb380
a00bb3ec:  a2 10 20 02  mov  2, %l1
a00bb3f0:  10 80 00 07  b  0xa00bb40c
a00bb3f4:  90 10 20 ff  mov  0xff, %o0
a00bb3f8:  10 80 00 05  b  0xa00bb40c
a00bb3fc:  90 10 00 18  mov  %i0, %o0
a00bb400:  10 80 00 03  b  0xa00bb40c
a00bb404:  90 0c 20 ff  and  %l0, 0xff, %o0
a00bb408:  90 10 20 99  mov  0x99, %o0
a00bb40c:  81 c7 e0 08  ret
a00bb410:  91 e8 00 08  restore  %g0, %o0, %o0
