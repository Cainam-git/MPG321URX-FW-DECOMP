# leon2m FUN_a002a344 0xa002a344-0xa002a45c (280 bytes)
a002a344:  9d e3 bf 98  save  %sp, -104, %sp
a002a348:  17 27 c0 00  sethi  %hi(0x9f000000), %o3
a002a34c:  90 12 e0 90  or  %o3, 0x90, %o0	! 0x9f000090
a002a350:  92 10 20 00  clr  %o1
a002a354:  40 00 07 c5  call  0xa002c268
a002a358:  94 10 24 00  mov  0x400, %o2
a002a35c:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a002a360:  92 10 24 00  mov  0x400, %o1
a002a364:  94 10 24 00  mov  0x400, %o2
a002a368:  40 00 07 c0  call  0xa002c268
a002a36c:  90 14 60 28  or  %l1, 0x28, %o0
a002a370:  40 00 07 b8  call  0xa002c250
a002a374:  90 14 60 94  or  %l1, 0x94, %o0
a002a378:  a4 10 00 08  mov  %o0, %l2
a002a37c:  40 00 07 b5  call  0xa002c250
a002a380:  90 14 60 5c  or  %l1, 0x5c, %o0
a002a384:  a0 2c 80 08  andn  %l2, %o0, %l0
a002a388:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a002a38c:  92 12 a3 ff  or  %o2, 0x3ff, %o1	! 0xffff
a002a390:  91 32 20 10  srl  %o0, 0x10, %o0
a002a394:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a002a398:  a4 0a 00 09  and  %o0, %o1, %l2
a002a39c:  a0 0c 00 09  and  %l0, %o1, %l0
a002a3a0:  b0 10 61 70  or  %g1, 0x170, %i0
a002a3a4:  b2 10 20 00  clr  %i1
a002a3a8:  98 10 20 01  mov  1, %o4
a002a3ac:  b5 2b 00 19  sll  %o4, %i1, %i2
a002a3b0:  80 8e 80 10  btst  %i2, %l0
a002a3b4:  22 80 00 0f  be,a   0xa002a3f0
a002a3b8:  b2 06 60 01  inc  %i1
a002a3bc:  c2 06 22 80  ld  [ %i0 + 0x280 ], %g1
a002a3c0:  80 a0 60 00  cmp  %g1, 0
a002a3c4:  22 80 00 0b  be,a   0xa002a3f0
a002a3c8:  b2 06 60 01  inc  %i1
a002a3cc:  92 10 00 1a  mov  %i2, %o1
a002a3d0:  80 8e 80 12  btst  %i2, %l2
a002a3d4:  02 80 00 1b  be  0xa002a440
a002a3d8:  90 14 60 94  or  %l1, 0x94, %o0
a002a3dc:  9f c0 40 00  call  %g1
a002a3e0:  b2 06 60 01  inc  %i1
a002a3e4:  92 10 00 1a  mov  %i2, %o1
a002a3e8:  40 00 07 9d  call  0xa002c25c
a002a3ec:  90 14 60 94  or  %l1, 0x94, %o0
a002a3f0:  b0 06 20 04  add  %i0, 4, %i0
a002a3f4:  80 a6 60 01  cmp  %i1, 1
a002a3f8:  08 bf ff ed  bleu  0xa002a3ac
a002a3fc:  98 10 20 01  mov  1, %o4
a002a400:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a002a404:  90 14 60 34  or  %l1, 0x34, %o0	! 0x9f020034
a002a408:  40 00 07 95  call  0xa002c25c
a002a40c:  92 10 24 00  mov  0x400, %o1
a002a410:  31 27 c0 00  sethi  %hi(0x9f000000), %i0
a002a414:  90 16 20 9c  or  %i0, 0x9c, %o0	! 0x9f00009c
a002a418:  40 00 07 91  call  0xa002c25c
a002a41c:  92 10 24 00  mov  0x400, %o1
a002a420:  90 14 60 28  or  %l1, 0x28, %o0
a002a424:  92 10 20 00  clr  %o1
a002a428:  40 00 07 90  call  0xa002c268
a002a42c:  94 10 24 00  mov  0x400, %o2
a002a430:  b0 16 20 90  or  %i0, 0x90, %i0
a002a434:  b2 10 24 00  mov  0x400, %i1
a002a438:  40 00 07 8c  call  0xa002c268
a002a43c:  95 e8 24 00  restore  %g0, 0x400, %o2
a002a440:  40 00 07 87  call  0xa002c25c
a002a444:  b2 06 60 01  inc  %i1
a002a448:  da 06 22 80  ld  [ %i0 + 0x280 ], %o5
a002a44c:  9f c3 40 00  call  %o5
a002a450:  b0 06 20 04  add  %i0, 4, %i0
a002a454:  10 bf ff e9  b  0xa002a3f8
a002a458:  80 a6 60 01  cmp  %i1, 1
