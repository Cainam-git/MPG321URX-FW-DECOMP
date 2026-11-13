# leon2s FUN_a00cd31c 0xa00cd31c-0xa00cd4fc (480 bytes)
a00cd31c:  9d e3 bf 90  save  %sp, -112, %sp
a00cd320:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00cd324:  98 04 40 11  add  %l1, %l1, %o4
a00cd328:  98 03 00 11  add  %o4, %l1, %o4
a00cd32c:  25 2a 01 e2  sethi  %hi(0xa8078800), %l2
a00cd330:  99 2b 20 03  sll  %o4, 3, %o4
a00cd334:  96 14 a3 b0  or  %l2, 0x3b0, %o3
a00cd338:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cd33c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cd340:  82 2b 40 01  andn  %o5, %g1, %g1
a00cd344:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cd348:  82 10 40 0d  or  %g1, %o5, %g1
a00cd34c:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cd350:  a0 10 20 00  clr  %l0
a00cd354:  a6 07 bf f0  add  %fp, -16, %l3
a00cd358:  15 00 01 a0  sethi  %hi(0x68000), %o2
a00cd35c:  94 12 a0 29  or  %o2, 0x29, %o2	! 0x68029
a00cd360:  92 10 20 90  mov  0x90, %o1
a00cd364:  96 10 20 00  clr  %o3
a00cd368:  98 10 00 13  mov  %l3, %o4
a00cd36c:  40 3b 24 25  call  0xa0f96400
a00cd370:  90 10 20 00  clr  %o0
a00cd374:  40 3b d1 08  call  0xa0fc1794
a00cd378:  90 10 20 02  mov  2, %o0
a00cd37c:  a0 04 20 01  inc  %l0
a00cd380:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cd384:  80 a0 60 03  cmp  %g1, 3
a00cd388:  82 60 20 00  subx  %g0, 0, %g1
a00cd38c:  d4 0f bf f0  ldub  [ %fp + -16 ], %o2
a00cd390:  82 08 60 01  and  %g1, 1, %g1
a00cd394:  9b 32 a0 01  srl  %o2, 1, %o5
a00cd398:  80 a8 40 0d  andncc  %g1, %o5, %g0
a00cd39c:  32 bf ff ef  bne,a   0xa00cd358
a00cd3a0:  a6 07 bf f0  add  %fp, -16, %l3
a00cd3a4:  80 8a a0 01  btst  1, %o2
a00cd3a8:  02 80 00 0c  be  0xa00cd3d8
a00cd3ac:  80 8a a0 02  btst  2, %o2
a00cd3b0:  98 04 40 11  add  %l1, %l1, %o4
a00cd3b4:  98 03 00 11  add  %o4, %l1, %o4
a00cd3b8:  96 14 a3 b0  or  %l2, 0x3b0, %o3
a00cd3bc:  99 2b 20 03  sll  %o4, 3, %o4
a00cd3c0:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cd3c4:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cd3c8:  82 2b 40 01  andn  %o5, %g1, %g1
a00cd3cc:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00cd3d0:  82 10 40 0d  or  %g1, %o5, %g1
a00cd3d4:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cd3d8:  12 80 00 07  bne  0xa00cd3f4
a00cd3dc:  a2 10 20 00  clr  %l1
a00cd3e0:  10 80 00 3c  b  0xa00cd4d0
a00cd3e4:  82 0e 20 ff  and  %i0, 0xff, %g1
a00cd3e8:  7f ff fd 94  call  0xa00cca38
a00cd3ec:  90 10 20 01  mov  1, %o0
a00cd3f0:  30 80 00 41  b,a   0xa00cd4f4
a00cd3f4:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00cd3f8:  82 10 61 00  or  %g1, 0x100, %g1	! 0xcf018d00
a00cd3fc:  da 00 40 00  ld  [ %g1 ], %o5
a00cd400:  9a 13 60 04  or  %o5, 4, %o5
a00cd404:  da 20 40 00  st  %o5, [ %g1 ]
a00cd408:  c2 00 40 00  ld  [ %g1 ], %g1
a00cd40c:  80 88 60 04  btst  4, %g1
a00cd410:  a0 10 20 00  clr  %l0
a00cd414:  02 80 00 0d  be  0xa00cd448
a00cd418:  15 00 01 a0  sethi  %hi(0x68000), %o2
a00cd41c:  40 3b d0 de  call  0xa0fc1794
a00cd420:  90 10 20 01  mov  1, %o0
a00cd424:  a0 04 20 01  inc  %l0
a00cd428:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cd42c:  80 a0 60 1e  cmp  %g1, 0x1e
a00cd430:  18 80 00 27  bgu  0xa00cd4cc
a00cd434:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00cd438:  82 10 61 00  or  %g1, 0x100, %g1	! 0xcf018d00
a00cd43c:  c2 00 40 00  ld  [ %g1 ], %g1
a00cd440:  10 bf ff f5  b  0xa00cd414
a00cd444:  80 88 60 04  btst  4, %g1
a00cd448:  94 12 a0 05  or  %o2, 5, %o2
a00cd44c:  96 10 20 01  mov  1, %o3
a00cd450:  98 10 00 13  mov  %l3, %o4
a00cd454:  90 10 20 00  clr  %o0
a00cd458:  40 3b 23 ea  call  0xa0f96400
a00cd45c:  92 10 20 90  mov  0x90, %o1
a00cd460:  19 33 c0 63  sethi  %hi(0xcf018c00), %o4
a00cd464:  94 13 21 38  or  %o4, 0x138, %o2	! 0xcf018d38
a00cd468:  d6 0f bf f0  ldub  [ %fp + -16 ], %o3
a00cd46c:  c2 02 80 00  ld  [ %o2 ], %g1
a00cd470:  80 a2 c0 01  cmp  %o3, %g1
a00cd474:  32 80 00 08  bne,a   0xa00cd494
a00cd478:  a2 04 60 01  inc  %l1
a00cd47c:  82 13 21 3c  or  %o4, 0x13c, %g1
a00cd480:  da 00 40 00  ld  [ %g1 ], %o5
a00cd484:  c2 0f bf f1  ldub  [ %fp + -15 ], %g1
a00cd488:  80 a0 40 0d  cmp  %g1, %o5
a00cd48c:  02 bf ff d7  be  0xa00cd3e8
a00cd490:  a2 04 60 01  inc  %l1
a00cd494:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cd498:  80 a0 60 02  cmp  %g1, 2
a00cd49c:  08 bf ff d7  bleu  0xa00cd3f8
a00cd4a0:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00cd4a4:  c2 02 80 00  ld  [ %o2 ], %g1
a00cd4a8:  80 a2 c0 01  cmp  %o3, %g1
a00cd4ac:  12 80 00 09  bne  0xa00cd4d0
a00cd4b0:  82 0e 20 ff  and  %i0, 0xff, %g1
a00cd4b4:  82 13 21 3c  or  %o4, 0x13c, %g1
a00cd4b8:  da 00 40 00  ld  [ %g1 ], %o5
a00cd4bc:  c2 0f bf f1  ldub  [ %fp + -15 ], %g1
a00cd4c0:  80 a0 40 0d  cmp  %g1, %o5
a00cd4c4:  02 80 00 0c  be  0xa00cd4f4
a00cd4c8:  01 00 00 00  nop
a00cd4cc:  82 0e 20 ff  and  %i0, 0xff, %g1
a00cd4d0:  9a 00 40 01  add  %g1, %g1, %o5
a00cd4d4:  9a 03 40 01  add  %o5, %g1, %o5
a00cd4d8:  19 2a 01 e2  sethi  %hi(0xa8078800), %o4
a00cd4dc:  98 13 23 b0  or  %o4, 0x3b0, %o4	! 0xa8078bb0
a00cd4e0:  9b 2b 60 03  sll  %o5, 3, %o5
a00cd4e4:  d6 03 00 0d  ld  [ %o4 + %o5 ], %o3
a00cd4e8:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cd4ec:  82 2a c0 01  andn  %o3, %g1, %g1
a00cd4f0:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a00cd4f4:  81 c7 e0 08  ret
a00cd4f8:  81 e8 00 00  restore
