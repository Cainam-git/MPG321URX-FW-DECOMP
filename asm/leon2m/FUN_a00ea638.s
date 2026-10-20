# leon2m FUN_a00ea638 0xa00ea638-0xa00ea878 (576 bytes)
a00ea638:  9d e3 bf 98  save  %sp, -104, %sp
a00ea63c:  a8 10 00 18  mov  %i0, %l4
a00ea640:  f4 27 a0 4c  st  %i2, [ %fp + 0x4c ]
a00ea644:  f8 27 a0 54  st  %i4, [ %fp + 0x54 ]
a00ea648:  80 a6 ff ff  cmp  %i3, -1
a00ea64c:  02 80 00 80  be  0xa00ea84c
a00ea650:  a6 10 20 00  clr  %l3
a00ea654:  39 2a 00 98  sethi  %hi(0xa8026000), %i4
a00ea658:  9b 2e e0 02  sll  %i3, 2, %o5
a00ea65c:  90 17 22 58  or  %i4, 0x258, %o0
a00ea660:  3b 2a 00 98  sethi  %hi(0xa8026000), %i5
a00ea664:  35 2a 00 ad  sethi  %hi(0xa802b400), %i2
a00ea668:  98 17 62 68  or  %i5, 0x268, %o4
a00ea66c:  82 16 a2 18  or  %i2, 0x218, %g1
a00ea670:  d4 02 00 0d  ld  [ %o0 + %o5 ], %o2
a00ea674:  d6 00 40 0d  ld  [ %g1 + %o5 ], %o3
a00ea678:  d2 03 00 0d  ld  [ %o4 + %o5 ], %o1
a00ea67c:  90 10 00 18  mov  %i0, %o0
a00ea680:  7f ff d8 35  call  0xa00e0754
a00ea684:  aa 10 20 01  mov  1, %l5
a00ea688:  15 2a 00 98  sethi  %hi(0xa8026000), %o2
a00ea68c:  13 2a 00 98  sethi  %hi(0xa8026000), %o1
a00ea690:  a4 10 00 08  mov  %o0, %l2
a00ea694:  ae 12 a2 48  or  %o2, 0x248, %l7
a00ea698:  ac 12 62 38  or  %o1, 0x238, %l6
a00ea69c:  a3 2e e0 02  sll  %i3, 2, %l1
a00ea6a0:  a0 10 20 00  clr  %l0
a00ea6a4:  83 2d 40 10  sll  %l5, %l0, %g1
a00ea6a8:  80 88 40 12  btst  %g1, %l2
a00ea6ac:  12 80 00 05  bne  0xa00ea6c0
a00ea6b0:  9a 10 00 01  mov  %g1, %o5
a00ea6b4:  80 88 40 13  btst  %g1, %l3
a00ea6b8:  02 80 00 30  be  0xa00ea778
a00ea6bc:  90 10 00 14  mov  %l4, %o0
a00ea6c0:  a6 14 c0 0d  or  %l3, %o5, %l3
a00ea6c4:  a0 04 20 01  inc  %l0
a00ea6c8:  80 a4 20 07  cmp  %l0, 7
a00ea6cc:  04 bf ff f7  ble  0xa00ea6a8
a00ea6d0:  83 2d 40 10  sll  %l5, %l0, %g1
a00ea6d4:  90 10 00 14  mov  %l4, %o0
a00ea6d8:  92 10 00 19  mov  %i1, %o1
a00ea6dc:  d4 07 a0 4c  ld  [ %fp + 0x4c ], %o2
a00ea6e0:  7f ff e7 96  call  0xa00e4538
a00ea6e4:  d6 07 a0 54  ld  [ %fp + 0x54 ], %o3
a00ea6e8:  80 a6 ff ff  cmp  %i3, -1
a00ea6ec:  02 80 00 48  be  0xa00ea80c
a00ea6f0:  a0 10 00 08  mov  %o0, %l0
a00ea6f4:  9a 17 62 68  or  %i5, 0x268, %o5
a00ea6f8:  a4 16 a2 18  or  %i2, 0x218, %l2
a00ea6fc:  b0 17 22 58  or  %i4, 0x258, %i0
a00ea700:  d2 03 40 11  ld  [ %o5 + %l1 ], %o1
a00ea704:  d6 04 80 11  ld  [ %l2 + %l1 ], %o3
a00ea708:  d4 06 00 11  ld  [ %i0 + %l1 ], %o2
a00ea70c:  7f ff d8 12  call  0xa00e0754
a00ea710:  90 10 00 14  mov  %l4, %o0
a00ea714:  80 a4 20 02  cmp  %l0, 2
a00ea718:  9a 40 20 00  addx  %g0, 0, %o5
a00ea71c:  98 1c e0 ff  xor  %l3, 0xff, %o4
a00ea720:  80 a0 00 0c  cmp  %g0, %o4
a00ea724:  a4 10 00 08  mov  %o0, %l2
a00ea728:  90 60 3f ff  subx  %g0, -1, %o0
a00ea72c:  80 8b 40 08  btst  %o5, %o0
a00ea730:  12 80 00 50  bne  0xa00ea870
a00ea734:  90 10 20 00  clr  %o0
a00ea738:  80 a0 00 0c  cmp  %g0, %o4
a00ea73c:  98 40 20 00  addx  %g0, 0, %o4
a00ea740:  80 8b 40 0c  btst  %o5, %o4
a00ea744:  32 bf ff d8  bne,a   0xa00ea6a4
a00ea748:  a0 10 20 00  clr  %l0
a00ea74c:  7f ff d4 30  call  0xa00df80c
a00ea750:  23 00 06 67  sethi  %hi(0x199c00), %l1
a00ea754:  7f ff d9 1b  call  0xa00e0bc0
a00ea758:  01 00 00 00  nop
a00ea75c:  90 14 61 c8  or  %l1, 0x1c8, %o0
a00ea760:  92 10 00 10  mov  %l0, %o1
a00ea764:  94 10 00 12  mov  %l2, %o2
a00ea768:  7f ff d2 82  call  0xa00df170
a00ea76c:  96 10 00 13  mov  %l3, %o3
a00ea770:  10 80 00 40  b  0xa00ea870
a00ea774:  90 10 3f ff  mov  -1, %o0
a00ea778:  d6 05 c0 11  ld  [ %l7 + %l1 ], %o3
a00ea77c:  92 02 c0 10  add  %o3, %l0, %o1
a00ea780:  7f ff d7 65  call  0xa00e0514
a00ea784:  d4 05 80 11  ld  [ %l6 + %l1 ], %o2
a00ea788:  96 02 20 01  add  %o0, 1, %o3
a00ea78c:  de 05 c0 11  ld  [ %l7 + %l1 ], %o7
a00ea790:  92 03 c0 10  add  %o7, %l0, %o1
a00ea794:  90 10 00 14  mov  %l4, %o0
a00ea798:  7f ff d7 90  call  0xa00e05d8
a00ea79c:  d4 05 80 11  ld  [ %l6 + %l1 ], %o2
a00ea7a0:  92 10 00 1b  mov  %i3, %o1
a00ea7a4:  94 10 00 10  mov  %l0, %o2
a00ea7a8:  96 10 20 00  clr  %o3
a00ea7ac:  7f ff fe ac  call  0xa00ea25c
a00ea7b0:  90 10 00 14  mov  %l4, %o0
a00ea7b4:  b0 10 00 08  mov  %o0, %i0
a00ea7b8:  94 10 00 10  mov  %l0, %o2
a00ea7bc:  92 10 00 1b  mov  %i3, %o1
a00ea7c0:  96 10 20 01  mov  1, %o3
a00ea7c4:  80 a6 20 00  cmp  %i0, 0
a00ea7c8:  12 80 00 29  bne  0xa00ea86c
a00ea7cc:  90 10 00 14  mov  %l4, %o0
a00ea7d0:  7f ff fe a3  call  0xa00ea25c
a00ea7d4:  01 00 00 00  nop
a00ea7d8:  b0 10 00 08  mov  %o0, %i0
a00ea7dc:  94 10 00 10  mov  %l0, %o2
a00ea7e0:  90 10 00 14  mov  %l4, %o0
a00ea7e4:  92 10 00 1b  mov  %i3, %o1
a00ea7e8:  80 a6 20 00  cmp  %i0, 0
a00ea7ec:  12 80 00 20  bne  0xa00ea86c
a00ea7f0:  96 10 20 00  clr  %o3
a00ea7f4:  7f ff fe 9a  call  0xa00ea25c
a00ea7f8:  01 00 00 00  nop
a00ea7fc:  80 a2 20 00  cmp  %o0, 0
a00ea800:  22 bf ff b2  be,a   0xa00ea6c8
a00ea804:  a0 04 20 01  inc  %l0
a00ea808:  30 80 00 1a  b,a   0xa00ea870
a00ea80c:  90 10 00 14  mov  %l4, %o0
a00ea810:  92 17 62 68  or  %i5, 0x268, %o1
a00ea814:  94 17 22 58  or  %i4, 0x258, %o2
a00ea818:  7f ff d7 cf  call  0xa00e0754
a00ea81c:  96 16 a2 18  or  %i2, 0x218, %o3
a00ea820:  80 a4 20 02  cmp  %l0, 2
a00ea824:  9a 40 20 00  addx  %g0, 0, %o5
a00ea828:  98 1c e0 ff  xor  %l3, 0xff, %o4
a00ea82c:  80 a0 00 0c  cmp  %g0, %o4
a00ea830:  a4 10 00 08  mov  %o0, %l2
a00ea834:  90 60 3f ff  subx  %g0, -1, %o0
a00ea838:  80 8b 40 08  btst  %o5, %o0
a00ea83c:  02 bf ff c0  be  0xa00ea73c
a00ea840:  80 a0 00 0c  cmp  %g0, %o4
a00ea844:  10 80 00 0b  b  0xa00ea870
a00ea848:  90 10 20 00  clr  %o0
a00ea84c:  3b 2a 00 98  sethi  %hi(0xa8026000), %i5
a00ea850:  39 2a 00 98  sethi  %hi(0xa8026000), %i4
a00ea854:  35 2a 00 ad  sethi  %hi(0xa802b400), %i2
a00ea858:  90 10 00 18  mov  %i0, %o0
a00ea85c:  92 17 62 68  or  %i5, 0x268, %o1
a00ea860:  94 17 22 58  or  %i4, 0x258, %o2
a00ea864:  10 bf ff 87  b  0xa00ea680
a00ea868:  96 16 a2 18  or  %i2, 0x218, %o3
a00ea86c:  90 10 00 18  mov  %i0, %o0
a00ea870:  81 c7 e0 08  ret
a00ea874:  91 e8 00 08  restore  %g0, %o0, %o0
