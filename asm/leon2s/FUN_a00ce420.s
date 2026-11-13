# leon2s FUN_a00ce420 0xa00ce420-0xa00ce4cc (172 bytes)
a00ce420:  9d e3 bf 98  save  %sp, -104, %sp
a00ce424:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ce428:  98 06 00 18  add  %i0, %i0, %o4
a00ce42c:  98 03 00 18  add  %o4, %i0, %o4
a00ce430:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00ce434:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00ce438:  99 2b 20 03  sll  %o4, 3, %o4
a00ce43c:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00ce440:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00ce444:  82 2b 40 01  andn  %o5, %g1, %g1
a00ce448:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00ce44c:  82 10 40 0d  or  %g1, %o5, %g1
a00ce450:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00ce454:  90 10 00 18  mov  %i0, %o0
a00ce458:  92 10 20 05  mov  5, %o1
a00ce45c:  7f ff e8 e3  call  0xa00c87e8
a00ce460:  15 00 00 20  sethi  %hi(0x8000), %o2
a00ce464:  b6 10 20 00  clr  %i3
a00ce468:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ce46c:  b8 10 62 50  or  %g1, 0x250, %i4	! 0xa807ce50
a00ce470:  a0 0e e0 ff  and  %i3, 0xff, %l0
a00ce474:  90 10 00 18  mov  %i0, %o0
a00ce478:  7f ff e4 be  call  0xa00c7770
a00ce47c:  92 10 20 01  mov  1, %o1
a00ce480:  b6 06 e0 01  inc  %i3
a00ce484:  82 0e e0 ff  and  %i3, 0xff, %g1
a00ce488:  80 a0 60 1f  cmp  %g1, 0x1f
a00ce48c:  08 bf ff f7  bleu  0xa00ce468
a00ce490:  d0 2f 00 10  stb  %o0, [ %i4 + %l0 ]
a00ce494:  35 00 01 a4  sethi  %hi(0x69000), %i2
a00ce498:  94 16 a2 a0  or  %i2, 0x2a0, %o2	! 0x692a0
a00ce49c:  98 10 00 1c  mov  %i4, %o4
a00ce4a0:  90 10 20 00  clr  %o0
a00ce4a4:  92 10 20 80  mov  0x80, %o1
a00ce4a8:  40 3b 1f cb  call  0xa0f963d4
a00ce4ac:  96 10 20 0f  mov  0xf, %o3
a00ce4b0:  b4 16 a2 b0  or  %i2, 0x2b0, %i2
a00ce4b4:  b8 07 20 10  add  %i4, 0x10, %i4
a00ce4b8:  b0 10 20 00  clr  %i0
a00ce4bc:  b2 10 20 80  mov  0x80, %i1
a00ce4c0:  40 3b 1f c5  call  0xa0f963d4
a00ce4c4:  97 e8 20 0f  restore  %g0, 0xf, %o3
a00ce4c8:  01 00 00 00  nop
