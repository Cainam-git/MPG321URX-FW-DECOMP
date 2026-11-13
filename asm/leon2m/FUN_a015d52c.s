# leon2m FUN_a015d52c 0xa015d52c-0xa015d690 (356 bytes)
a015d52c:  9d e3 bf 98  save  %sp, -104, %sp
a015d530:  90 10 00 19  mov  %i1, %o0
a015d534:  7f ff ff e4  call  0xa015d4c4
a015d538:  92 10 00 1a  mov  %i2, %o1
a015d53c:  a0 10 00 08  mov  %o0, %l0
a015d540:  80 a4 20 00  cmp  %l0, 0
a015d544:  02 80 00 46  be  0xa015d65c
a015d548:  90 10 00 18  mov  %i0, %o0
a015d54c:  80 a4 20 00  cmp  %l0, 0
a015d550:  06 80 00 4a  bl  0xa015d678
a015d554:  b0 10 00 19  mov  %i1, %i0
a015d558:  a0 10 20 00  clr  %l0
a015d55c:  7f ff fd ca  call  0xa015cc84
a015d560:  d2 06 60 04  ld  [ %i1 + 4 ], %o1
a015d564:  b0 10 00 08  mov  %o0, %i0
a015d568:  e2 06 60 10  ld  [ %i1 + 0x10 ], %l1
a015d56c:  9b 2c 60 02  sll  %l1, 2, %o5
a015d570:  90 06 60 14  add  %i1, 0x14, %o0
a015d574:  c2 06 a0 10  ld  [ %i2 + 0x10 ], %g1
a015d578:  b2 03 40 08  add  %o5, %o0, %i1
a015d57c:  92 06 a0 14  add  %i2, 0x14, %o1
a015d580:  83 28 60 02  sll  %g1, 2, %g1
a015d584:  e0 26 20 0c  st  %l0, [ %i0 + 0xc ]
a015d588:  1b 00 00 3f  sethi  %hi(0xfc00), %o5
a015d58c:  a0 00 40 09  add  %g1, %o1, %l0
a015d590:  b4 13 63 ff  or  %o5, 0x3ff, %i2
a015d594:  94 06 20 14  add  %i0, 0x14, %o2
a015d598:  9e 10 20 00  clr  %o7
a015d59c:  d6 02 00 00  ld  [ %o0 ], %o3
a015d5a0:  d8 02 40 00  ld  [ %o1 ], %o4
a015d5a4:  9a 0b 00 1a  and  %o4, %i2, %o5
a015d5a8:  82 0a c0 1a  and  %o3, %i2, %g1
a015d5ac:  82 20 40 0d  sub  %g1, %o5, %g1
a015d5b0:  9a 00 40 0f  add  %g1, %o7, %o5
a015d5b4:  97 32 e0 10  srl  %o3, 0x10, %o3
a015d5b8:  99 33 20 10  srl  %o4, 0x10, %o4
a015d5bc:  9f 3b 60 10  sra  %o5, 0x10, %o7
a015d5c0:  96 22 c0 0c  sub  %o3, %o4, %o3
a015d5c4:  82 02 c0 0f  add  %o3, %o7, %g1
a015d5c8:  c2 32 80 00  sth  %g1, [ %o2 ]
a015d5cc:  da 32 a0 02  sth  %o5, [ %o2 + 2 ]
a015d5d0:  92 02 60 04  add  %o1, 4, %o1
a015d5d4:  90 02 20 04  add  %o0, 4, %o0
a015d5d8:  94 02 a0 04  add  %o2, 4, %o2
a015d5dc:  80 a2 40 10  cmp  %o1, %l0
a015d5e0:  0a bf ff ef  bcs  0xa015d59c
a015d5e4:  9f 38 60 10  sra  %g1, 0x10, %o7
a015d5e8:  80 a2 00 19  cmp  %o0, %i1
a015d5ec:  1a 80 00 10  bcc  0xa015d62c
a015d5f0:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a015d5f4:  98 10 63 ff  or  %g1, 0x3ff, %o4	! 0xffff
a015d5f8:  c2 02 00 00  ld  [ %o0 ], %g1
a015d5fc:  9a 08 40 0c  and  %g1, %o4, %o5
a015d600:  9a 03 40 0f  add  %o5, %o7, %o5
a015d604:  9f 3b 60 10  sra  %o5, 0x10, %o7
a015d608:  83 30 60 10  srl  %g1, 0x10, %g1
a015d60c:  82 00 40 0f  add  %g1, %o7, %g1
a015d610:  c2 32 80 00  sth  %g1, [ %o2 ]
a015d614:  da 32 a0 02  sth  %o5, [ %o2 + 2 ]
a015d618:  90 02 20 04  add  %o0, 4, %o0
a015d61c:  94 02 a0 04  add  %o2, 4, %o2
a015d620:  80 a2 00 19  cmp  %o0, %i1
a015d624:  0a bf ff f5  bcs  0xa015d5f8
a015d628:  9f 38 60 10  sra  %g1, 0x10, %o7
a015d62c:  94 02 bf fc  add  %o2, -4, %o2
a015d630:  c2 02 80 00  ld  [ %o2 ], %g1
a015d634:  80 a0 60 00  cmp  %g1, 0
a015d638:  32 80 00 14  bne,a   0xa015d688
a015d63c:  e2 26 20 10  st  %l1, [ %i0 + 0x10 ]
a015d640:  94 02 bf fc  add  %o2, -4, %o2
a015d644:  c2 02 80 00  ld  [ %o2 ], %g1
a015d648:  80 a0 60 00  cmp  %g1, 0
a015d64c:  02 bf ff fd  be  0xa015d640
a015d650:  a2 04 7f ff  add  %l1, -1, %l1
a015d654:  10 80 00 0d  b  0xa015d688
a015d658:  e2 26 20 10  st  %l1, [ %i0 + 0x10 ]
a015d65c:  7f ff fd 8a  call  0xa015cc84
a015d660:  92 10 20 00  clr  %o1
a015d664:  82 10 20 01  mov  1, %g1
a015d668:  b0 10 00 08  mov  %o0, %i0
a015d66c:  c2 22 20 10  st  %g1, [ %o0 + 0x10 ]
a015d670:  10 80 00 06  b  0xa015d688
a015d674:  c0 22 20 14  clr  [ %o0 + 0x14 ]
a015d678:  b2 10 00 1a  mov  %i2, %i1
a015d67c:  b4 10 00 18  mov  %i0, %i2
a015d680:  10 bf ff b7  b  0xa015d55c
a015d684:  a0 10 20 01  mov  1, %l0
a015d688:  81 c7 e0 08  ret
a015d68c:  81 e8 00 00  restore
