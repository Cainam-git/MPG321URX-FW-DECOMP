# leon2s FUN_a00a4370 0xa00a4370-0xa00a4524 (436 bytes)
a00a4370:  9d e3 bf 98  save  %sp, -104, %sp
a00a4374:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a4378:  a4 10 63 6c  or  %g1, 0x36c, %l2	! 0xa807db6c
a00a437c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a4380:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a4384:  a1 2e 20 02  sll  %i0, 2, %l0
a00a4388:  a2 10 63 3c  or  %g1, 0x33c, %l1
a00a438c:  da 04 80 10  ld  [ %l2 + %l0 ], %o5
a00a4390:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00a4394:  80 a3 40 01  cmp  %o5, %g1
a00a4398:  02 80 00 1b  be  0xa00a4404
a00a439c:  11 28 01 af  sethi  %hi(0xa006bc00), %o0
a00a43a0:  92 10 00 18  mov  %i0, %o1
a00a43a4:  7f ff 3b 28  call  0xa0073044
a00a43a8:  90 12 23 18  or  %o0, 0x318, %o0
a00a43ac:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00a43b0:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00a43b4:  98 10 20 00  clr  %o4
a00a43b8:  90 10 00 18  mov  %i0, %o0
a00a43bc:  92 10 20 01  mov  1, %o1
a00a43c0:  94 10 20 39  mov  0x39, %o2
a00a43c4:  40 00 0f 42  call  0xa00a80cc
a00a43c8:  96 10 20 10  mov  0x10, %o3
a00a43cc:  90 10 00 18  mov  %i0, %o0
a00a43d0:  92 10 20 04  mov  4, %o1
a00a43d4:  94 10 20 e0  mov  0xe0, %o2
a00a43d8:  40 00 0f 1f  call  0xa00a8054
a00a43dc:  96 10 20 00  clr  %o3
a00a43e0:  90 10 00 18  mov  %i0, %o0
a00a43e4:  92 10 20 04  mov  4, %o1
a00a43e8:  94 10 20 e1  mov  0xe1, %o2
a00a43ec:  40 00 0f 1a  call  0xa00a8054
a00a43f0:  96 10 20 00  clr  %o3
a00a43f4:  90 10 00 18  mov  %i0, %o0
a00a43f8:  92 10 20 10  mov  0x10, %o1
a00a43fc:  7f ff b6 3e  call  0xa0091cf4
a00a4400:  94 10 20 20  mov  0x20, %o2
a00a4404:  90 10 00 18  mov  %i0, %o0
a00a4408:  7f ff b6 57  call  0xa0091d64
a00a440c:  92 10 20 10  mov  0x10, %o1
a00a4410:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a4414:  9a 10 62 08  or  %g1, 0x208, %o5	! 0xa8079208
a00a4418:  c2 0b 40 18  ldub  [ %o5 + %i0 ], %g1
a00a441c:  80 a0 60 00  cmp  %g1, 0
a00a4420:  22 80 00 06  be,a   0xa00a4438
a00a4424:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a4428:  82 10 20 02  mov  2, %g1
a00a442c:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a00a4430:  10 80 00 3b  b  0xa00a451c
a00a4434:  c0 2b 40 18  clrb  [ %o5 + %i0 ]
a00a4438:  a2 8a 20 10  andcc  %o0, 0x10, %l1
a00a443c:  12 80 00 07  bne  0xa00a4458
a00a4440:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a4444:  82 10 61 b0  or  %g1, 0x1b0, %g1	! 0xa80791b0
a00a4448:  c2 08 40 18  ldub  [ %g1 + %i0 ], %g1
a00a444c:  80 a0 60 00  cmp  %g1, 0
a00a4450:  02 80 00 26  be  0xa00a44e8
a00a4454:  80 8a 20 20  btst  0x20, %o0
a00a4458:  98 10 20 00  clr  %o4
a00a445c:  90 10 00 18  mov  %i0, %o0
a00a4460:  92 10 20 01  mov  1, %o1
a00a4464:  94 10 20 39  mov  0x39, %o2
a00a4468:  40 00 0f 19  call  0xa00a80cc
a00a446c:  96 10 20 10  mov  0x10, %o3
a00a4470:  90 10 00 18  mov  %i0, %o0
a00a4474:  92 10 20 04  mov  4, %o1
a00a4478:  94 10 20 e0  mov  0xe0, %o2
a00a447c:  40 00 0e f6  call  0xa00a8054
a00a4480:  96 10 20 00  clr  %o3
a00a4484:  90 10 00 18  mov  %i0, %o0
a00a4488:  92 10 20 04  mov  4, %o1
a00a448c:  94 10 20 e1  mov  0xe1, %o2
a00a4490:  40 00 0e f1  call  0xa00a8054
a00a4494:  96 10 20 00  clr  %o3
a00a4498:  90 10 00 18  mov  %i0, %o0
a00a449c:  7f ff c1 8a  call  0xa0094ac4
a00a44a0:  92 10 20 00  clr  %o1
a00a44a4:  80 a4 60 00  cmp  %l1, 0
a00a44a8:  02 80 00 07  be  0xa00a44c4
a00a44ac:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a44b0:  90 10 00 18  mov  %i0, %o0
a00a44b4:  92 10 20 10  mov  0x10, %o1
a00a44b8:  7f ff b6 0f  call  0xa0091cf4
a00a44bc:  94 10 20 10  mov  0x10, %o2
a00a44c0:  30 80 00 07  b,a   0xa00a44dc
a00a44c4:  82 10 61 b0  or  %g1, 0x1b0, %g1
a00a44c8:  11 28 01 af  sethi  %hi(0xa006bc00), %o0
a00a44cc:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a00a44d0:  90 12 23 68  or  %o0, 0x368, %o0
a00a44d4:  7f ff 3a dc  call  0xa0073044
a00a44d8:  92 10 00 18  mov  %i0, %o1
a00a44dc:  7f ff b5 5c  call  0xa0091a4c
a00a44e0:  90 10 00 18  mov  %i0, %o0
a00a44e4:  30 80 00 0e  b,a   0xa00a451c
a00a44e8:  02 80 00 0c  be  0xa00a4518
a00a44ec:  82 10 20 05  mov  5, %g1
a00a44f0:  90 10 00 18  mov  %i0, %o0
a00a44f4:  92 10 20 10  mov  0x10, %o1
a00a44f8:  7f ff b5 ff  call  0xa0091cf4
a00a44fc:  94 10 20 20  mov  0x20, %o2
a00a4500:  82 10 20 03  mov  3, %g1
a00a4504:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a00a4508:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a450c:  82 10 61 e8  or  %g1, 0x1e8, %g1	! 0xa80791e8
a00a4510:  10 80 00 03  b  0xa00a451c
a00a4514:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a00a4518:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a00a451c:  81 c7 e0 08  ret
a00a4520:  91 e8 20 00  restore  %g0, 0, %o0
