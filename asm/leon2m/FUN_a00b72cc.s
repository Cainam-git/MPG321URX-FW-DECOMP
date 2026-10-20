# leon2m FUN_a00b72cc 0xa00b72cc-0xa00b7474 (424 bytes)
a00b72cc:  9d e3 bf 98  save  %sp, -104, %sp
a00b72d0:  90 10 20 d7  mov  0xd7, %o0
a00b72d4:  40 02 3e 1f  call  0xa0146b50
a00b72d8:  92 10 20 00  clr  %o1
a00b72dc:  90 10 20 02  mov  2, %o0
a00b72e0:  40 02 3e 23  call  0xa0146b6c
a00b72e4:  92 10 20 00  clr  %o1
a00b72e8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00b72ec:  b0 10 62 90  or  %g1, 0x290, %i0	! 0xa802d290
a00b72f0:  b2 10 20 00  clr  %i1
a00b72f4:  a0 10 20 00  clr  %l0
a00b72f8:  10 80 00 3e  b  0xa00b73f0
a00b72fc:  23 00 06 5f  sethi  %hi(0x197c00), %l1
a00b7300:  90 60 3f ff  subx  %g0, -1, %o0
a00b7304:  9a 1c 20 02  xor  %l0, 2, %o5
a00b7308:  80 a0 00 0d  cmp  %g0, %o5
a00b730c:  98 60 3f ff  subx  %g0, -1, %o4
a00b7310:  80 92 00 0c  orcc  %o0, %o4, %g0
a00b7314:  02 80 00 04  be  0xa00b7324
a00b7318:  80 a2 e0 0d  cmp  %o3, 0xd
a00b731c:  22 80 00 3a  be,a   0xa00b7404
a00b7320:  90 10 20 00  clr  %o0
a00b7324:  9b 2c 20 03  sll  %l0, 3, %o5
a00b7328:  90 23 40 10  sub  %o5, %l0, %o0
a00b732c:  99 2a 20 02  sll  %o0, 2, %o4
a00b7330:  9e 03 00 10  add  %o4, %l0, %o7
a00b7334:  c2 0e 20 08  ldub  [ %i0 + 8 ], %g1
a00b7338:  96 03 c0 01  add  %o7, %g1, %o3
a00b733c:  93 2a e0 10  sll  %o3, 0x10, %o1
a00b7340:  93 32 60 10  srl  %o1, 0x10, %o1
a00b7344:  7f ff b1 40  call  0xa00a3844
a00b7348:  90 14 61 08  or  %l1, 0x108, %o0
a00b734c:  98 10 00 08  mov  %o0, %o4
a00b7350:  94 04 00 10  add  %l0, %l0, %o2
a00b7354:  94 02 a0 06  add  %o2, 6, %o2
a00b7358:  90 10 20 00  clr  %o0
a00b735c:  92 10 20 28  mov  0x28, %o1
a00b7360:  96 10 20 01  mov  1, %o3
a00b7364:  7f ff af 90  call  0xa00a31a4
a00b7368:  9a 10 20 00  clr  %o5
a00b736c:  94 04 00 10  add  %l0, %l0, %o2
a00b7370:  a0 02 a0 06  add  %o2, 6, %l0
a00b7374:  92 10 00 10  mov  %l0, %o1
a00b7378:  90 10 20 2b  mov  0x2b, %o0
a00b737c:  94 10 20 01  mov  1, %o2
a00b7380:  96 10 27 92  mov  0x792, %o3
a00b7384:  40 02 3d bf  call  0xa0146a80
a00b7388:  98 10 20 00  clr  %o4
a00b738c:  9a 10 20 00  clr  %o5
a00b7390:  94 10 00 10  mov  %l0, %o2
a00b7394:  90 10 20 00  clr  %o0
a00b7398:  92 10 20 2b  mov  0x2b, %o1
a00b739c:  96 10 20 01  mov  1, %o3
a00b73a0:  40 02 3d e0  call  0xa0146b20
a00b73a4:  98 10 20 3f  mov  0x3f, %o4
a00b73a8:  92 10 00 10  mov  %l0, %o1
a00b73ac:  90 10 20 32  mov  0x32, %o0
a00b73b0:  94 10 20 01  mov  1, %o2
a00b73b4:  96 10 27 92  mov  0x792, %o3
a00b73b8:  40 02 3d b2  call  0xa0146a80
a00b73bc:  98 10 20 00  clr  %o4
a00b73c0:  94 10 00 10  mov  %l0, %o2
a00b73c4:  90 10 20 00  clr  %o0
a00b73c8:  92 10 20 32  mov  0x32, %o1
a00b73cc:  96 10 20 01  mov  1, %o3
a00b73d0:  98 10 20 40  mov  0x40, %o4
a00b73d4:  9a 10 20 00  clr  %o5
a00b73d8:  40 02 3d d2  call  0xa0146b20
a00b73dc:  b2 06 60 01  inc  %i1
a00b73e0:  a0 0e 60 ff  and  %i1, 0xff, %l0
a00b73e4:  80 a4 20 02  cmp  %l0, 2
a00b73e8:  38 80 00 20  bgu,a   0xa00b7468
a00b73ec:  b0 10 20 00  clr  %i0
a00b73f0:  d6 0e 20 08  ldub  [ %i0 + 8 ], %o3
a00b73f4:  80 a2 e0 13  cmp  %o3, 0x13
a00b73f8:  12 bf ff c2  bne  0xa00b7300
a00b73fc:  80 a0 00 10  cmp  %g0, %l0
a00b7400:  90 10 20 00  clr  %o0
a00b7404:  40 02 3d da  call  0xa0146b6c
a00b7408:  92 10 20 00  clr  %o1
a00b740c:  9b 2c 20 03  sll  %l0, 3, %o5
a00b7410:  90 23 40 10  sub  %o5, %l0, %o0
a00b7414:  99 2a 20 02  sll  %o0, 2, %o4
a00b7418:  9e 03 00 10  add  %o4, %l0, %o7
a00b741c:  c2 0e 20 08  ldub  [ %i0 + 8 ], %g1
a00b7420:  96 03 c0 01  add  %o7, %g1, %o3
a00b7424:  93 2a e0 10  sll  %o3, 0x10, %o1
a00b7428:  93 32 60 10  srl  %o1, 0x10, %o1
a00b742c:  7f ff b1 06  call  0xa00a3844
a00b7430:  90 14 61 08  or  %l1, 0x108, %o0
a00b7434:  98 10 00 08  mov  %o0, %o4
a00b7438:  94 04 00 10  add  %l0, %l0, %o2
a00b743c:  94 02 a0 06  add  %o2, 6, %o2
a00b7440:  90 10 20 00  clr  %o0
a00b7444:  92 10 20 28  mov  0x28, %o1
a00b7448:  96 10 20 01  mov  1, %o3
a00b744c:  7f ff af 56  call  0xa00a31a4
a00b7450:  9a 10 20 00  clr  %o5
a00b7454:  90 10 20 02  mov  2, %o0
a00b7458:  40 02 3d c5  call  0xa0146b6c
a00b745c:  92 10 20 00  clr  %o1
a00b7460:  10 bf ff c4  b  0xa00b7370
a00b7464:  94 04 00 10  add  %l0, %l0, %o2
a00b7468:  40 02 3d c1  call  0xa0146b6c
a00b746c:  93 e8 20 00  restore  %g0, 0, %o1
a00b7470:  01 00 00 00  nop
