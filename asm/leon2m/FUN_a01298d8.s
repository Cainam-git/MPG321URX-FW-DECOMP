# leon2m FUN_a01298d8 0xa01298d8-0xa0129980 (168 bytes)
a01298d8:  9d e3 bf 98  save  %sp, -104, %sp
a01298dc:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a01298e0:  a8 10 61 16  or  %g1, 0x116, %l4	! 0xa802e116
a01298e4:  a2 10 20 00  clr  %l1
a01298e8:  a0 10 20 00  clr  %l0
a01298ec:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a01298f0:  10 80 00 0a  b  0xa0129918
a01298f4:  a6 10 20 01  mov  1, %l3
a01298f8:  9f 2c c0 10  sll  %l3, %l0, %o7
a01298fc:  da 14 a1 fe  lduh  [ %l2 + 0x1fe ], %o5
a0129900:  a2 04 60 01  inc  %l1
a0129904:  82 2b 40 0f  andn  %o5, %o7, %g1
a0129908:  a0 0c 60 ff  and  %l1, 0xff, %l0
a012990c:  80 a4 20 06  cmp  %l0, 6
a0129910:  18 80 00 18  bgu  0xa0129970
a0129914:  c2 34 a1 fe  sth  %g1, [ %l2 + 0x1fe ]
a0129918:  95 2c 20 03  sll  %l0, 3, %o2
a012991c:  92 02 80 10  add  %o2, %l0, %o1
a0129920:  90 02 40 09  add  %o1, %o1, %o0
a0129924:  b0 02 00 14  add  %o0, %l4, %i0
a0129928:  7f ff ec b3  call  0xa0124bf4
a012992c:  d0 0e 20 10  ldub  [ %i0 + 0x10 ], %o0
a0129930:  80 8a 20 ff  btst  0xff, %o0
a0129934:  02 bf ff f2  be  0xa01298fc
a0129938:  9f 2c c0 10  sll  %l3, %l0, %o7
a012993c:  7f ff ee 01  call  0xa0125140
a0129940:  d0 0e 20 10  ldub  [ %i0 + 0x10 ], %o0
a0129944:  96 0a 20 ff  and  %o0, 0xff, %o3
a0129948:  80 a2 e0 ff  cmp  %o3, 0xff
a012994c:  02 bf ff eb  be  0xa01298f8
a0129950:  9b 2c c0 10  sll  %l3, %l0, %o5
a0129954:  d8 14 a1 fe  lduh  [ %l2 + 0x1fe ], %o4
a0129958:  a2 04 60 01  inc  %l1
a012995c:  82 13 40 0c  or  %o5, %o4, %g1
a0129960:  a0 0c 60 ff  and  %l1, 0xff, %l0
a0129964:  80 a4 20 06  cmp  %l0, 6
a0129968:  08 bf ff ec  bleu  0xa0129918
a012996c:  c2 34 a1 fe  sth  %g1, [ %l2 + 0x1fe ]
a0129970:  f0 14 a1 fe  lduh  [ %l2 + 0x1fe ], %i0
a0129974:  40 00 35 76  call  0xa0136f4c
a0129978:  81 e8 00 00  restore
a012997c:  01 00 00 00  nop
