# leon2m FUN_a014a8d4 0xa014a8d4-0xa014aa48 (372 bytes)
a014a8d4:  9d e3 bf 98  save  %sp, -104, %sp
a014a8d8:  9e 0e 20 ff  and  %i0, 0xff, %o7
a014a8dc:  80 a3 e0 04  cmp  %o7, 4
a014a8e0:  02 80 00 2b  be  0xa014a98c
a014a8e4:  b0 10 00 1a  mov  %i2, %i0
a014a8e8:  80 a3 e0 01  cmp  %o7, 1
a014a8ec:  02 80 00 0b  be  0xa014a918
a014a8f0:  82 10 20 01  mov  1, %g1
a014a8f4:  80 a3 e0 01  cmp  %o7, 1
a014a8f8:  04 80 00 4f  ble  0xa014aa34
a014a8fc:  80 a3 e0 02  cmp  %o7, 2
a014a900:  02 80 00 06  be  0xa014a918
a014a904:  82 10 20 02  mov  2, %g1
a014a908:  80 a3 e0 03  cmp  %o7, 3
a014a90c:  02 80 00 03  be  0xa014a918
a014a910:  82 10 20 03  mov  3, %g1
a014a914:  82 10 3f ff  mov  -1, %g1
a014a918:  9e 08 60 ff  and  %g1, 0xff, %o7
a014a91c:  80 a3 e0 03  cmp  %o7, 3
a014a920:  38 80 00 40  bgu,a   0xa014aa20
a014a924:  1f 00 06 9b  sethi  %hi(0x1a6c00), %o7
a014a928:  a1 2b e0 04  sll  %o7, 4, %l0
a014a92c:  b4 24 00 0f  sub  %l0, %o7, %i2
a014a930:  21 2a 00 b7  sethi  %hi(0xa802dc00), %l0
a014a934:  9b 2e a0 03  sll  %i2, 3, %o5
a014a938:  96 14 23 30  or  %l0, 0x330, %o3
a014a93c:  b4 03 40 0b  add  %o5, %o3, %i2
a014a940:  94 0e 60 01  and  %i1, 1, %o2
a014a944:  f2 06 a0 70  ld  [ %i2 + 0x70 ], %i1
a014a948:  19 00 00 40  sethi  %hi(0x10000), %o4
a014a94c:  90 2e 40 0c  andn  %i1, %o4, %o0
a014a950:  93 2a a0 10  sll  %o2, 0x10, %o1
a014a954:  b3 2b e0 04  sll  %o7, 4, %i1
a014a958:  82 12 00 09  or  %o0, %o1, %g1
a014a95c:  98 26 40 0f  sub  %i1, %o7, %o4
a014a960:  c2 26 a0 70  st  %g1, [ %i2 + 0x70 ]
a014a964:  94 14 23 30  or  %l0, 0x330, %o2
a014a968:  93 2b 20 03  sll  %o4, 3, %o1
a014a96c:  f0 36 a0 74  sth  %i0, [ %i2 + 0x74 ]
a014a970:  82 02 40 0a  add  %o1, %o2, %g1
a014a974:  d0 10 60 70  lduh  [ %g1 + 0x70 ], %o0
a014a978:  31 00 06 9c  sethi  %hi(0x1a7000), %i0
a014a97c:  b2 10 00 0f  mov  %o7, %i1
a014a980:  b4 0a 20 01  and  %o0, 1, %i2
a014a984:  7f fe 51 fb  call  0xa00df170
a014a988:  91 ee 20 48  restore  %i0, 0x48, %o0
a014a98c:  21 2a 00 b7  sethi  %hi(0xa802dc00), %l0
a014a990:  82 14 23 30  or  %l0, 0x330, %g1	! 0xa802df30
a014a994:  17 3f ff bf  sethi  %hi(0xfffefc00), %o3
a014a998:  98 0e 60 01  and  %i1, 1, %o4
a014a99c:  9a 12 e3 ff  or  %o3, 0x3ff, %o5
a014a9a0:  f2 00 61 d8  ld  [ %g1 + 0x1d8 ], %i1
a014a9a4:  f0 00 60 70  ld  [ %g1 + 0x70 ], %i0
a014a9a8:  d4 00 60 e8  ld  [ %g1 + 0xe8 ], %o2
a014a9ac:  90 0e 40 0d  and  %i1, %o5, %o0
a014a9b0:  99 2b 20 10  sll  %o4, 0x10, %o4
a014a9b4:  d2 00 61 60  ld  [ %g1 + 0x160 ], %o1
a014a9b8:  96 0e 00 0d  and  %i0, %o5, %o3
a014a9bc:  b2 0a 80 0d  and  %o2, %o5, %i1
a014a9c0:  94 16 40 0c  or  %i1, %o4, %o2
a014a9c4:  b0 0a 40 0d  and  %o1, %o5, %i0
a014a9c8:  92 16 00 0c  or  %i0, %o4, %o1
a014a9cc:  90 12 00 0c  or  %o0, %o4, %o0
a014a9d0:  96 12 c0 0c  or  %o3, %o4, %o3
a014a9d4:  b3 2b e0 04  sll  %o7, 4, %i1
a014a9d8:  d4 20 60 e8  st  %o2, [ %g1 + 0xe8 ]
a014a9dc:  d2 20 61 60  st  %o1, [ %g1 + 0x160 ]
a014a9e0:  98 26 40 0f  sub  %i1, %o7, %o4
a014a9e4:  f4 30 61 dc  sth  %i2, [ %g1 + 0x1dc ]
a014a9e8:  d6 20 60 70  st  %o3, [ %g1 + 0x70 ]
a014a9ec:  d0 20 61 d8  st  %o0, [ %g1 + 0x1d8 ]
a014a9f0:  f4 30 60 74  sth  %i2, [ %g1 + 0x74 ]
a014a9f4:  f4 30 60 ec  sth  %i2, [ %g1 + 0xec ]
a014a9f8:  f4 30 61 64  sth  %i2, [ %g1 + 0x164 ]
a014a9fc:  94 14 23 30  or  %l0, 0x330, %o2
a014aa00:  93 2b 20 03  sll  %o4, 3, %o1
a014aa04:  82 02 40 0a  add  %o1, %o2, %g1
a014aa08:  d0 10 60 70  lduh  [ %g1 + 0x70 ], %o0
a014aa0c:  31 00 06 9c  sethi  %hi(0x1a7000), %i0
a014aa10:  b2 10 00 0f  mov  %o7, %i1
a014aa14:  b4 0a 20 01  and  %o0, 1, %i2
a014aa18:  7f fe 51 d6  call  0xa00df170
a014aa1c:  91 ee 20 48  restore  %i0, 0x48, %o0
a014aa20:  90 13 e1 d8  or  %o7, 0x1d8, %o0
a014aa24:  7f fe 51 d3  call  0xa00df170
a014aa28:  01 00 00 00  nop
a014aa2c:  10 bf ff bf  b  0xa014a928
a014aa30:  9e 10 20 00  clr  %o7	! 0x0
a014aa34:  80 a3 e0 00  cmp  %o7, 0
a014aa38:  02 bf ff b8  be  0xa014a918
a014aa3c:  82 10 20 00  clr  %g1
a014aa40:  10 bf ff b6  b  0xa014a918
a014aa44:  82 10 3f ff  mov  -1, %g1
