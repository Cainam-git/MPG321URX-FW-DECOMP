# leon2m FUN_a014b4b4 0xa014b4b4-0xa014b65c (424 bytes)
a014b4b4:  9d e3 bf 98  save  %sp, -104, %sp
a014b4b8:  90 0e 20 ff  and  %i0, 0xff, %o0
a014b4bc:  80 a2 20 fe  cmp  %o0, 0xfe
a014b4c0:  9a 10 20 00  clr  %o5
a014b4c4:  02 80 00 20  be  0xa014b544
a014b4c8:  82 10 20 07  mov  7, %g1
a014b4cc:  7f ff 67 33  call  0xa0125198
a014b4d0:  01 00 00 00  nop
a014b4d4:  7f ff db 51  call  0xa0142218
a014b4d8:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b4dc:  7f ff db 3a  call  0xa01421c4
a014b4e0:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b4e4:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b4e8:  80 a2 20 61  cmp  %o0, 0x61
a014b4ec:  02 80 00 4a  be  0xa014b614
a014b4f0:  9a 10 20 00  clr  %o5
a014b4f4:  80 a2 20 61  cmp  %o0, 0x61
a014b4f8:  04 80 00 08  ble  0xa014b518
a014b4fc:  9e 0b 60 03  and  %o5, 3, %o7
a014b500:  80 a2 20 71  cmp  %o0, 0x71
a014b504:  02 80 00 52  be  0xa014b64c
a014b508:  80 a2 20 81  cmp  %o0, 0x81
a014b50c:  22 80 00 02  be,a   0xa014b514
a014b510:  9a 10 20 03  mov  3, %o5
a014b514:  9e 0b 60 03  and  %o5, 3, %o7
a014b518:  99 2b e0 03  sll  %o7, 3, %o4
a014b51c:  96 03 00 0f  add  %o4, %o7, %o3
a014b520:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014b524:  9a 12 a1 16  or  %o2, 0x116, %o5	! 0xa802e116
a014b528:  92 02 c0 0b  add  %o3, %o3, %o1
a014b52c:  82 02 40 0d  add  %o1, %o5, %g1
a014b530:  7f ff 66 fd  call  0xa0125124
a014b534:  d0 08 60 10  ldub  [ %g1 + 0x10 ], %o0
a014b538:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b53c:  9a 10 00 08  mov  %o0, %o5
a014b540:  82 10 00 08  mov  %o0, %g1
a014b544:  a6 08 60 ff  and  %g1, 0xff, %l3
a014b548:  b0 0b 60 ff  and  %o5, 0xff, %i0
a014b54c:  80 a6 00 13  cmp  %i0, %l3
a014b550:  1a 80 00 41  bcc  0xa014b654
a014b554:  a4 10 00 0d  mov  %o5, %l2
a014b558:  b2 0e 60 ff  and  %i1, 0xff, %i1
a014b55c:  7f ff 67 7d  call  0xa0125350
a014b560:  90 10 00 18  mov  %i0, %o0
a014b564:  a2 10 20 01  mov  1, %l1
a014b568:  a1 2c 40 18  sll  %l1, %i0, %l0
a014b56c:  80 8a 20 ff  btst  0xff, %o0
a014b570:  92 10 00 19  mov  %i1, %o1
a014b574:  12 80 00 24  bne  0xa014b604
a014b578:  90 0c 20 ff  and  %l0, 0xff, %o0
a014b57c:  80 a6 60 00  cmp  %i1, 0
a014b580:  02 80 00 14  be  0xa014b5d0
a014b584:  90 10 00 18  mov  %i0, %o0
a014b588:  7f ff 67 dc  call  0xa01254f8
a014b58c:  01 00 00 00  nop
a014b590:  a2 0a 20 ff  and  %o0, 0xff, %l1
a014b594:  7f ff 67 e7  call  0xa0125530
a014b598:  90 10 00 18  mov  %i0, %o0
a014b59c:  a0 0a 20 ff  and  %o0, 0xff, %l0
a014b5a0:  7f ff 67 f2  call  0xa0125568
a014b5a4:  90 10 00 18  mov  %i0, %o0
a014b5a8:  94 0a 20 ff  and  %o0, 0xff, %o2
a014b5ac:  90 10 00 11  mov  %l1, %o0
a014b5b0:  92 10 00 10  mov  %l0, %o1
a014b5b4:  67 fd 04 ae  call  0x4008c86c
a014b5b8:  a4 04 a0 01  inc  %l2
a014b5bc:  b0 0c a0 ff  and  %l2, 0xff, %i0
a014b5c0:  80 a6 00 13  cmp  %i0, %l3
a014b5c4:  0a bf ff e6  bcs  0xa014b55c
a014b5c8:  01 00 00 00  nop
a014b5cc:  30 80 00 22  b,a   0xa014b654
a014b5d0:  7f ff 67 ca  call  0xa01254f8
a014b5d4:  90 10 00 18  mov  %i0, %o0
a014b5d8:  a2 0a 20 ff  and  %o0, 0xff, %l1
a014b5dc:  7f ff 67 d5  call  0xa0125530
a014b5e0:  90 10 00 18  mov  %i0, %o0
a014b5e4:  a0 0a 20 ff  and  %o0, 0xff, %l0
a014b5e8:  7f ff 67 e0  call  0xa0125568
a014b5ec:  90 10 00 18  mov  %i0, %o0
a014b5f0:  b0 38 00 08  xnor  %g0, %o0, %i0
a014b5f4:  90 10 00 11  mov  %l1, %o0
a014b5f8:  92 10 00 10  mov  %l0, %o1
a014b5fc:  10 bf ff ee  b  0xa014b5b4
a014b600:  94 0e 20 ff  and  %i0, 0xff, %o2
a014b604:  7f ff a2 ab  call  0xa01340b0
a014b608:  a4 04 a0 01  inc  %l2
a014b60c:  10 bf ff ed  b  0xa014b5c0
a014b610:  b0 0c a0 ff  and  %l2, 0xff, %i0
a014b614:  9a 10 20 01  mov  1, %o5
a014b618:  9e 0b 60 03  and  %o5, 3, %o7
a014b61c:  99 2b e0 03  sll  %o7, 3, %o4
a014b620:  96 03 00 0f  add  %o4, %o7, %o3
a014b624:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014b628:  9a 12 a1 16  or  %o2, 0x116, %o5	! 0xa802e116
a014b62c:  92 02 c0 0b  add  %o3, %o3, %o1
a014b630:  82 02 40 0d  add  %o1, %o5, %g1
a014b634:  7f ff 66 bc  call  0xa0125124
a014b638:  d0 08 60 10  ldub  [ %g1 + 0x10 ], %o0
a014b63c:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b640:  9a 10 00 08  mov  %o0, %o5
a014b644:  10 bf ff c0  b  0xa014b544
a014b648:  82 10 00 08  mov  %o0, %g1
a014b64c:  10 bf ff b2  b  0xa014b514
a014b650:  9a 10 20 02  mov  2, %o5
a014b654:  81 c7 e0 08  ret
a014b658:  81 e8 00 00  restore
