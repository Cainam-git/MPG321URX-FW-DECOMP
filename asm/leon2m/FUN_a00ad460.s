# leon2m FUN_a00ad460 0xa00ad460-0xa00ad5a4 (324 bytes)
a00ad460:  9d e3 bf 90  save  %sp, -112, %sp
a00ad464:  67 ff 83 90  call  0x4008e2a4
a00ad468:  b2 10 20 06  mov  6, %i1
a00ad46c:  82 10 20 06  mov  6, %g1
a00ad470:  80 a0 60 05  cmp  %g1, 5
a00ad474:  02 80 00 14  be  0xa00ad4c4
a00ad478:  80 a0 60 07  cmp  %g1, 7
a00ad47c:  02 80 00 12  be  0xa00ad4c4
a00ad480:  90 10 20 01  mov  1, %o0
a00ad484:  92 10 20 00  clr  %o1
a00ad488:  94 10 27 c2  mov  0x7c2, %o2
a00ad48c:  96 10 20 07  mov  7, %o3
a00ad490:  98 10 20 06  mov  6, %o4
a00ad494:  80 a0 60 06  cmp  %g1, 6
a00ad498:  02 80 00 41  be  0xa00ad59c
a00ad49c:  9a 10 20 0a  mov  0xa, %o5
a00ad4a0:  98 10 00 01  mov  %g1, %o4
a00ad4a4:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ad4a8:  90 10 20 01  mov  1, %o0
a00ad4ac:  92 10 20 00  clr  %o1
a00ad4b0:  94 10 27 92  mov  0x792, %o2
a00ad4b4:  96 10 20 07  mov  7, %o3
a00ad4b8:  9a 10 20 0b  mov  0xb, %o5
a00ad4bc:  40 00 17 8a  call  0xa00b32e4
a00ad4c0:  01 00 00 00  nop
a00ad4c4:  b2 06 60 01  inc  %i1
a00ad4c8:  82 0e 60 ff  and  %i1, 0xff, %g1
a00ad4cc:  80 a0 60 15  cmp  %g1, 0x15
a00ad4d0:  08 bf ff e9  bleu  0xa00ad474
a00ad4d4:  80 a0 60 05  cmp  %g1, 5
a00ad4d8:  40 00 1a 0f  call  0xa00b3d14
a00ad4dc:  90 10 20 01  mov  1, %o0
a00ad4e0:  90 10 20 07  mov  7, %o0
a00ad4e4:  40 00 1b 18  call  0xa00b4144
a00ad4e8:  92 10 20 02  mov  2, %o1
a00ad4ec:  67 ff 83 6e  call  0x4008e2a4
a00ad4f0:  b0 10 20 05  mov  5, %i0
a00ad4f4:  b2 10 20 05  mov  5, %i1
a00ad4f8:  94 10 00 19  mov  %i1, %o2
a00ad4fc:  90 10 20 00  clr  %o0
a00ad500:  92 10 20 13  mov  0x13, %o1
a00ad504:  96 10 20 13  mov  0x13, %o3
a00ad508:  98 10 20 00  clr  %o4
a00ad50c:  40 02 65 85  call  0xa0146b20
a00ad510:  9a 10 20 00  clr  %o5
a00ad514:  92 10 00 19  mov  %i1, %o1
a00ad518:  90 10 20 13  mov  0x13, %o0
a00ad51c:  94 10 20 13  mov  0x13, %o2
a00ad520:  96 10 27 92  mov  0x792, %o3
a00ad524:  98 10 20 00  clr  %o4
a00ad528:  40 02 65 56  call  0xa0146a80
a00ad52c:  b0 06 20 01  inc  %i0
a00ad530:  b2 0e 20 ff  and  %i0, 0xff, %i1
a00ad534:  80 a6 60 14  cmp  %i1, 0x14
a00ad538:  28 bf ff f1  bleu,a   0xa00ad4fc
a00ad53c:  94 10 00 19  mov  %i1, %o2
a00ad540:  9a 10 20 00  clr  %o5
a00ad544:  96 10 20 02  mov  2, %o3
a00ad548:  98 10 20 00  clr  %o4
a00ad54c:  90 10 20 00  clr  %o0
a00ad550:  92 10 20 1c  mov  0x1c, %o1
a00ad554:  40 02 65 73  call  0xa0146b20
a00ad558:  94 10 20 15  mov  0x15, %o2
a00ad55c:  94 10 20 00  clr  %o2
a00ad560:  92 10 20 00  clr  %o1
a00ad564:  40 02 65 b7  call  0xa0146c40
a00ad568:  90 10 20 05  mov  5, %o0
a00ad56c:  7f ff ff 15  call  0xa00ad1c0
a00ad570:  90 10 20 00  clr  %o0
a00ad574:  90 10 20 00  clr  %o0
a00ad578:  7f ff ee a5  call  0xa00a900c
a00ad57c:  92 10 20 02  mov  2, %o1
a00ad580:  40 00 18 b8  call  0xa00b3860
a00ad584:  b0 10 20 00  clr  %i0
a00ad588:  9a 10 3f ff  mov  -1, %o5
a00ad58c:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00ad590:  da 28 60 19  stb  %o5, [ %g1 + 0x19 ]	! 0xa802d419
a00ad594:  40 00 17 d0  call  0xa00b34d4
a00ad598:  93 e8 20 04  restore  %g0, 4, %o1
a00ad59c:  10 bf ff c8  b  0xa00ad4bc
a00ad5a0:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
