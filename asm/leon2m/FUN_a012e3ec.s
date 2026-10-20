# leon2m FUN_a012e3ec 0xa012e3ec-0xa012e550 (356 bytes)
a012e3ec:  9d e3 be d8  save  %sp, -296, %sp
a012e3f0:  a2 07 bf 38  add  %fp, -200, %l1
a012e3f4:  90 10 00 11  mov  %l1, %o0
a012e3f8:  92 10 20 00  clr  %o1
a012e3fc:  40 00 a4 bb  call  0xa01576e8
a012e400:  94 10 20 c0  mov  0xc0, %o2
a012e404:  83 2e 20 10  sll  %i0, 0x10, %g1
a012e408:  83 30 60 10  srl  %g1, 0x10, %g1
a012e40c:  80 88 65 08  btst  0x508, %g1
a012e410:  a4 10 20 00  clr  %l2
a012e414:  a0 10 20 60  mov  0x60, %l0
a012e418:  12 80 00 37  bne  0xa012e4f4
a012e41c:  9a 10 20 00  clr  %o5
a012e420:  9a 10 3f ff  mov  -1, %o5
a012e424:  9a 0b 60 ff  and  %o5, 0xff, %o5
a012e428:  92 03 40 0d  add  %o5, %o5, %o1
a012e42c:  90 02 40 0d  add  %o1, %o5, %o0
a012e430:  80 8e 22 00  btst  0x200, %i0
a012e434:  02 80 00 27  be  0xa012e4d0
a012e438:  99 2a 20 05  sll  %o0, 5, %o4
a012e43c:  a0 10 3f c0  mov  -64, %l0
a012e440:  a4 10 20 01  mov  1, %l2
a012e444:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a012e448:  82 16 21 a0  or  %i0, 0x1a0, %g1	! 0xa802e1a0
a012e44c:  d2 00 60 34  ld  [ %g1 + 0x34 ], %o1
a012e450:  91 32 60 08  srl  %o1, 8, %o0
a012e454:  9e 02 00 0c  add  %o0, %o4, %o7
a012e458:  99 2b e0 10  sll  %o7, 0x10, %o4
a012e45c:  a0 0c 20 ff  and  %l0, 0xff, %l0
a012e460:  93 33 20 10  srl  %o4, 0x10, %o1
a012e464:  94 10 00 10  mov  %l0, %o2
a012e468:  d0 08 60 34  ldub  [ %g1 + 0x34 ], %o0
a012e46c:  40 00 47 bd  call  0xa0140360
a012e470:  96 10 00 11  mov  %l1, %o3
a012e474:  a1 34 20 04  srl  %l0, 4, %l0
a012e478:  80 a4 20 00  cmp  %l0, 0
a012e47c:  02 80 00 0d  be  0xa012e4b0
a012e480:  98 10 20 00  clr  %o4
a012e484:  9a 10 20 00  clr  %o5
a012e488:  9a 03 60 01  inc  %o5
a012e48c:  94 0b 60 ff  and  %o5, 0xff, %o2
a012e490:  80 a2 a0 0f  cmp  %o2, 0xf
a012e494:  08 bf ff fe  bleu  0xa012e48c
a012e498:  9a 03 60 01  inc  %o5
a012e49c:  98 03 20 01  inc  %o4
a012e4a0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a012e4a4:  80 a3 40 10  cmp  %o5, %l0
a012e4a8:  0a bf ff f8  bcs  0xa012e488
a012e4ac:  9a 10 20 00  clr  %o5
a012e4b0:  96 16 21 a0  or  %i0, 0x1a0, %o3
a012e4b4:  f0 0a e0 37  ldub  [ %o3 + 0x37 ], %i0
a012e4b8:  80 a6 20 01  cmp  %i0, 1
a012e4bc:  02 80 00 20  be  0xa012e53c
a012e4c0:  90 10 00 11  mov  %l1, %o0
a012e4c4:  7f ff fe d0  call  0xa012e004
a012e4c8:  92 0c a0 01  and  %l2, 1, %o1
a012e4cc:  30 80 00 1e  b,a   0xa012e544
a012e4d0:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a012e4d4:  96 16 21 a0  or  %i0, 0x1a0, %o3	! 0xa802e1a0
a012e4d8:  d4 0a e0 37  ldub  [ %o3 + 0x37 ], %o2
a012e4dc:  80 a2 a0 01  cmp  %o2, 1
a012e4e0:  12 bf ff db  bne  0xa012e44c
a012e4e4:  82 16 21 a0  or  %i0, 0x1a0, %g1
a012e4e8:  a0 10 20 60  mov  0x60, %l0
a012e4ec:  10 bf ff d8  b  0xa012e44c
a012e4f0:  a4 10 20 01  mov  1, %l2
a012e4f4:  80 a0 60 01  cmp  %g1, 1
a012e4f8:  02 bf ff cb  be  0xa012e424
a012e4fc:  94 10 20 00  clr  %o2
a012e500:  92 10 00 01  mov  %g1, %o1
a012e504:  96 10 20 00  clr  %o3
a012e508:  90 10 25 08  mov  0x508, %o0
a012e50c:  9f 3a 00 0b  sra  %o0, %o3, %o7
a012e510:  94 02 a0 01  inc  %o2
a012e514:  96 0a a0 ff  and  %o2, 0xff, %o3
a012e518:  80 8b e0 01  btst  1, %o7
a012e51c:  02 80 00 03  be  0xa012e528
a012e520:  99 3a 40 0b  sra  %o1, %o3, %o4
a012e524:  9a 03 60 01  inc  %o5
a012e528:  80 a3 20 01  cmp  %o4, 1
a012e52c:  12 bf ff f9  bne  0xa012e510
a012e530:  9f 3a 00 0b  sra  %o0, %o3, %o7
a012e534:  10 bf ff bd  b  0xa012e428
a012e538:  9a 0b 60 ff  and  %o5, 0xff, %o5
a012e53c:  7f ff ff 5c  call  0xa012e2ac
a012e540:  92 0c a0 01  and  %l2, 1, %o1
a012e544:  01 00 00 00  nop
a012e548:  81 c7 e0 08  ret
a012e54c:  81 e8 00 00  restore
