# leon2m FUN_a00d57e8 0xa00d57e8-0xa00d5938 (252 bytes)
a00d57e8:  9d e3 bf 98  save  %sp, -104, %sp
a00d57ec:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a00d57f0:  b2 16 e2 90  or  %i3, 0x290, %i1	! 0xa802d290
a00d57f4:  35 00 06 61  sethi  %hi(0x198400), %i2
a00d57f8:  92 16 a1 24  or  %i2, 0x124, %o1	! 0x198524
a00d57fc:  94 10 21 fc  mov  0x1fc, %o2
a00d5800:  40 01 9c 44  call  0xa013c910
a00d5804:  90 10 00 19  mov  %i1, %o0
a00d5808:  92 10 00 19  mov  %i1, %o1
a00d580c:  94 10 20 00  clr  %o2
a00d5810:  96 10 21 fc  mov  0x1fc, %o3
a00d5814:  40 01 d5 af  call  0xa014aed0
a00d5818:  90 10 20 30  mov  0x30, %o0
a00d581c:  31 00 06 61  sethi  %hi(0x198400), %i0
a00d5820:  82 16 21 08  or  %i0, 0x108, %g1	! 0x198508
a00d5824:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00d5828:  b2 13 22 74  or  %o4, 0x274, %i1	! 0xa802d274
a00d582c:  ec 16 21 08  lduh  [ %i0 + 0x108 ], %l6
a00d5830:  ee 10 60 1a  lduh  [ %g1 + 0x1a ], %l7
a00d5834:  da 10 60 02  lduh  [ %g1 + 2 ], %o5
a00d5838:  d6 10 60 04  lduh  [ %g1 + 4 ], %o3
a00d583c:  d4 10 60 06  lduh  [ %g1 + 6 ], %o2
a00d5840:  d2 10 60 08  lduh  [ %g1 + 8 ], %o1
a00d5844:  d0 10 60 0a  lduh  [ %g1 + 0xa ], %o0
a00d5848:  de 10 60 0c  lduh  [ %g1 + 0xc ], %o7
a00d584c:  e0 10 60 0e  lduh  [ %g1 + 0xe ], %l0
a00d5850:  e2 10 60 10  lduh  [ %g1 + 0x10 ], %l1
a00d5854:  e4 10 60 12  lduh  [ %g1 + 0x12 ], %l2
a00d5858:  e6 10 60 14  lduh  [ %g1 + 0x14 ], %l3
a00d585c:  e8 10 60 16  lduh  [ %g1 + 0x16 ], %l4
a00d5860:  ea 10 60 18  lduh  [ %g1 + 0x18 ], %l5
a00d5864:  ec 33 22 74  sth  %l6, [ %o4 + 0x274 ]
a00d5868:  da 36 60 02  sth  %o5, [ %i1 + 2 ]
a00d586c:  d6 36 60 04  sth  %o3, [ %i1 + 4 ]
a00d5870:  d4 36 60 06  sth  %o2, [ %i1 + 6 ]
a00d5874:  d2 36 60 08  sth  %o1, [ %i1 + 8 ]
a00d5878:  d0 36 60 0a  sth  %o0, [ %i1 + 0xa ]
a00d587c:  de 36 60 0c  sth  %o7, [ %i1 + 0xc ]
a00d5880:  e0 36 60 0e  sth  %l0, [ %i1 + 0xe ]
a00d5884:  e2 36 60 10  sth  %l1, [ %i1 + 0x10 ]
a00d5888:  e4 36 60 12  sth  %l2, [ %i1 + 0x12 ]
a00d588c:  e6 36 60 14  sth  %l3, [ %i1 + 0x14 ]
a00d5890:  e8 36 60 16  sth  %l4, [ %i1 + 0x16 ]
a00d5894:  ea 36 60 18  sth  %l5, [ %i1 + 0x18 ]
a00d5898:  ee 36 60 1a  sth  %l7, [ %i1 + 0x1a ]
a00d589c:  b0 10 20 30  mov  0x30, %i0
a00d58a0:  b4 10 22 e0  mov  0x2e0, %i2
a00d58a4:  40 01 d5 8b  call  0xa014aed0
a00d58a8:  97 e8 20 1c  restore  %g0, 0x1c, %o3
a00d58ac:  01 00 00 00  nop
a00d58b0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d58b4:  d0 08 62 aa  ldub  [ %g1 + 0x2aa ], %o0	! 0xa802d2aa
a00d58b8:  80 a2 20 04  cmp  %o0, 4
a00d58bc:  38 80 00 02  bgu,a   0xa00d58c4
a00d58c0:  90 10 20 04  mov  4, %o0
a00d58c4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d58c8:  82 13 c0 00  mov  %o7, %g1
a00d58cc:  7f fe c8 52  call  0xa0087a14
a00d58d0:  9e 10 40 00  mov  %g1, %o7
a00d58d4:  01 00 00 00  nop
a00d58d8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d58dc:  d2 10 62 c4  lduh  [ %g1 + 0x2c4 ], %o1	! 0xa802d2c4
a00d58e0:  92 0a 60 0f  and  %o1, 0xf, %o1
a00d58e4:  90 10 20 01  mov  1, %o0
a00d58e8:  82 13 c0 00  mov  %o7, %g1
a00d58ec:  40 01 cd de  call  0xa0149064
a00d58f0:  9e 10 40 00  mov  %g1, %o7
a00d58f4:  01 00 00 00  nop
a00d58f8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d58fc:  d2 10 62 c4  lduh  [ %g1 + 0x2c4 ], %o1	! 0xa802d2c4
a00d5900:  92 0a 60 0f  and  %o1, 0xf, %o1
a00d5904:  90 10 20 00  clr  %o0
a00d5908:  82 13 c0 00  mov  %o7, %g1
a00d590c:  40 01 cd d6  call  0xa0149064
a00d5910:  9e 10 40 00  mov  %g1, %o7
a00d5914:  01 00 00 00  nop
a00d5918:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d591c:  d0 00 62 90  ld  [ %g1 + 0x290 ], %o0	! 0xa802d290
a00d5920:  91 32 20 09  srl  %o0, 9, %o0
a00d5924:  90 0a 20 01  and  %o0, 1, %o0
a00d5928:  82 13 c0 00  mov  %o7, %g1
a00d592c:  40 01 cd 1b  call  0xa0148d98
a00d5930:  9e 10 40 00  mov  %g1, %o7
a00d5934:  01 00 00 00  nop
