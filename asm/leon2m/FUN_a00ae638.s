# leon2m FUN_a00ae638 0xa00ae638-0xa00ae790 (344 bytes)
a00ae638:  9d e3 bf 90  save  %sp, -112, %sp
a00ae63c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ae640:  94 14 62 90  or  %l1, 0x290, %o2	! 0xa802d290
a00ae644:  d2 0a a1 82  ldub  [ %o2 + 0x182 ], %o1
a00ae648:  90 0a 60 03  and  %o1, 3, %o0
a00ae64c:  82 02 00 08  add  %o0, %o0, %g1
a00ae650:  a0 00 60 04  add  %g1, 4, %l0
a00ae654:  90 10 20 00  clr  %o0
a00ae658:  92 10 20 00  clr  %o1
a00ae65c:  94 10 20 00  clr  %o2
a00ae660:  40 00 16 1c  call  0xa00b3ed0
a00ae664:  96 10 20 00  clr  %o3
a00ae668:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00ae66c:  90 10 20 00  clr  %o0
a00ae670:  92 10 20 00  clr  %o1
a00ae674:  94 10 27 92  mov  0x792, %o2
a00ae678:  96 10 20 03  mov  3, %o3
a00ae67c:  98 10 20 0a  mov  0xa, %o4
a00ae680:  80 a4 20 0a  cmp  %l0, 0xa
a00ae684:  02 80 00 2c  be  0xa00ae734
a00ae688:  9a 10 20 02  mov  2, %o5
a00ae68c:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae690:  90 10 20 00  clr  %o0
a00ae694:  92 10 20 00  clr  %o1
a00ae698:  94 10 27 92  mov  0x792, %o2
a00ae69c:  96 10 20 03  mov  3, %o3
a00ae6a0:  98 10 00 10  mov  %l0, %o4
a00ae6a4:  9a 10 20 03  mov  3, %o5
a00ae6a8:  40 00 13 0f  call  0xa00b32e4
a00ae6ac:  01 00 00 00  nop
a00ae6b0:  98 10 00 10  mov  %l0, %o4
a00ae6b4:  94 10 27 92  mov  0x792, %o2
a00ae6b8:  96 10 20 12  mov  0x12, %o3
a00ae6bc:  9a 10 20 03  mov  3, %o5
a00ae6c0:  90 10 20 00  clr  %o0
a00ae6c4:  92 10 20 00  clr  %o1
a00ae6c8:  40 00 13 07  call  0xa00b32e4
a00ae6cc:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae6d0:  a0 14 62 90  or  %l1, 0x290, %l0
a00ae6d4:  d8 0c 21 82  ldub  [ %l0 + 0x182 ], %o4
a00ae6d8:  92 03 20 01  add  %o4, 1, %o1
a00ae6dc:  99 3a 60 1f  sra  %o1, 0x1f, %o4
a00ae6e0:  81 83 20 00  mov  %o4, %y
a00ae6e4:  01 00 00 00  nop
a00ae6e8:  01 00 00 00  nop
a00ae6ec:  01 00 00 00  nop
a00ae6f0:  96 7a 60 06  sdiv  %o1, 6, %o3
a00ae6f4:  94 5a e0 06  smul  %o3, 6, %o2
a00ae6f8:  9a 22 40 0a  sub  %o1, %o2, %o5
a00ae6fc:  9e 0b 60 ff  and  %o5, 0xff, %o7
a00ae700:  90 1b e0 04  xor  %o7, 4, %o0
a00ae704:  80 a0 00 08  cmp  %g0, %o0
a00ae708:  82 60 3f ff  subx  %g0, -1, %g1
a00ae70c:  80 a0 00 0f  cmp  %g0, %o7
a00ae710:  a2 60 3f ff  subx  %g0, -1, %l1
a00ae714:  80 90 40 11  orcc  %g1, %l1, %g0
a00ae718:  da 2c 21 82  stb  %o5, [ %l0 + 0x182 ]
a00ae71c:  02 80 00 12  be  0xa00ae764
a00ae720:  91 33 e0 02  srl  %o7, 2, %o0
a00ae724:  40 00 29 61  call  0xa00b8ca8
a00ae728:  01 00 00 00  nop
a00ae72c:  10 80 00 0f  b  0xa00ae768
a00ae730:  e2 0c 21 82  ldub  [ %l0 + 0x182 ], %l1
a00ae734:  40 00 12 ec  call  0xa00b32e4
a00ae738:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae73c:  98 10 20 11  mov  0x11, %o4
a00ae740:  17 00 00 0c  sethi  %hi(0x3000), %o3
a00ae744:  d8 23 a0 5c  st  %o4, [ %sp + 0x5c ]
a00ae748:  94 12 e0 92  or  %o3, 0x92, %o2
a00ae74c:  90 10 20 01  mov  1, %o0
a00ae750:  92 10 20 00  clr  %o1
a00ae754:  96 10 20 03  mov  3, %o3
a00ae758:  98 10 20 0c  mov  0xc, %o4
a00ae75c:  10 bf ff d3  b  0xa00ae6a8
a00ae760:  9a 10 20 01  mov  1, %o5
a00ae764:  e2 0c 21 82  ldub  [ %l0 + 0x182 ], %l1
a00ae768:  90 0c 60 03  and  %l1, 3, %o0
a00ae76c:  7f ff fc 40  call  0xa00ad86c
a00ae770:  92 10 20 01  mov  1, %o1
a00ae774:  40 00 b5 5f  call  0xa00dbcf0
a00ae778:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00ae77c:  da 0c 20 8e  ldub  [ %l0 + 0x8e ], %o5	! 0xa802b08e
a00ae780:  9e 13 60 02  or  %o5, 2, %o7
a00ae784:  de 2c 20 8e  stb  %o7, [ %l0 + 0x8e ]
a00ae788:  81 c7 e0 08  ret
a00ae78c:  81 e8 00 00  restore
