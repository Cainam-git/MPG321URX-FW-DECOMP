# leon2m FUN_a013d918 0xa013d918-0xa013dbcc (692 bytes)
a013d918:  9d e3 bf 90  save  %sp, -112, %sp
a013d91c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013d920:  93 2e 20 04  sll  %i0, 4, %o1
a013d924:  90 22 40 18  sub  %o1, %i0, %o0
a013d928:  25 2a 00 b7  sethi  %hi(0xa802dc00), %l2
a013d92c:  83 2a 20 03  sll  %o0, 3, %g1
a013d930:  98 14 a3 30  or  %l2, 0x330, %o4
a013d934:  d6 00 40 0c  ld  [ %g1 + %o4 ], %o3
a013d938:  9b 32 e0 0c  srl  %o3, 0xc, %o5
a013d93c:  b2 0b 60 0f  and  %o5, 0xf, %i1
a013d940:  80 a6 60 ff  cmp  %i1, 0xff
a013d944:  a6 10 20 00  clr  %l3
a013d948:  a8 10 20 00  clr  %l4
a013d94c:  02 80 00 9e  be  0xa013dbc4
a013d950:  a0 00 40 0c  add  %g1, %o4, %l0
a013d954:  80 a6 20 00  cmp  %i0, 0
a013d958:  12 80 00 15  bne  0xa013d9ac
a013d95c:  80 a6 20 03  cmp  %i0, 3
a013d960:  80 8a e0 01  btst  1, %o3
a013d964:  32 80 00 0e  bne,a   0xa013d99c
a013d968:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a013d96c:  d6 04 20 40  ld  [ %l0 + 0x40 ], %o3
a013d970:  15 10 00 00  sethi  %hi(0x40000000), %o2
a013d974:  80 8a c0 0a  btst  %o3, %o2
a013d978:  32 80 00 09  bne,a   0xa013d99c
a013d97c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a013d980:  35 2a 00 b8  sethi  %hi(0xa802e000), %i2
a013d984:  e2 06 a3 d0  ld  [ %i2 + 0x3d0 ], %l1	! 0xa802e3d0
a013d988:  1f 01 00 00  sethi  %hi(0x4000000), %o7
a013d98c:  80 8c 40 0f  btst  %l1, %o7
a013d990:  02 80 00 07  be  0xa013d9ac
a013d994:  80 a6 20 03  cmp  %i0, 3
a013d998:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a013d99c:  82 13 23 78  or  %o4, 0x378, %g1	! 0xa802e378
a013d9a0:  d8 10 60 30  lduh  [ %g1 + 0x30 ], %o4
a013d9a4:  10 80 00 05  b  0xa013d9b8
a013d9a8:  d6 10 60 26  lduh  [ %g1 + 0x26 ], %o3
a013d9ac:  02 80 00 60  be  0xa013db2c
a013d9b0:  96 10 20 10  mov  0x10, %o3
a013d9b4:  98 10 20 02  mov  2, %o4
a013d9b8:  b5 2e 20 04  sll  %i0, 4, %i2
a013d9bc:  a2 26 80 18  sub  %i2, %i0, %l1
a013d9c0:  9b 2c 60 03  sll  %l1, 3, %o5
a013d9c4:  a2 14 a3 30  or  %l2, 0x330, %l1
a013d9c8:  b4 03 40 11  add  %o5, %l1, %i2
a013d9cc:  9f 2a e0 10  sll  %o3, 0x10, %o7
a013d9d0:  82 0b 20 ff  and  %o4, 0xff, %g1
a013d9d4:  d2 16 a0 4a  lduh  [ %i2 + 0x4a ], %o1
a013d9d8:  d4 16 a0 52  lduh  [ %i2 + 0x52 ], %o2
a013d9dc:  d6 16 a0 4e  lduh  [ %i2 + 0x4e ], %o3
a013d9e0:  d8 16 a0 58  lduh  [ %i2 + 0x58 ], %o4
a013d9e4:  90 10 00 19  mov  %i1, %o0
a013d9e8:  9b 33 e0 10  srl  %o7, 0x10, %o5
a013d9ec:  7f ff 1f c9  call  0xa0105910
a013d9f0:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a013d9f4:  90 10 00 19  mov  %i1, %o0
a013d9f8:  d4 16 a0 54  lduh  [ %i2 + 0x54 ], %o2
a013d9fc:  d2 16 a0 4c  lduh  [ %i2 + 0x4c ], %o1
a013da00:  d6 16 a0 50  lduh  [ %i2 + 0x50 ], %o3
a013da04:  7f ff 20 0e  call  0xa0105a3c
a013da08:  d8 16 a0 56  lduh  [ %i2 + 0x56 ], %o4
a013da0c:  d4 04 00 00  ld  [ %l0 ], %o2
a013da10:  b2 0a a0 f0  and  %o2, 0xf0, %i1
a013da14:  80 a6 60 40  cmp  %i1, 0x40
a013da18:  02 80 00 34  be  0xa013dae8
a013da1c:  80 a6 20 03  cmp  %i0, 3
a013da20:  7f fe e4 b5  call  0xa00f6cf4
a013da24:  01 00 00 00  nop
a013da28:  d2 04 00 00  ld  [ %l0 ], %o1
a013da2c:  b2 10 00 08  mov  %o0, %i1
a013da30:  91 32 60 04  srl  %o1, 4, %o0
a013da34:  7f fe e2 62  call  0xa00f63bc
a013da38:  90 0a 20 0f  and  %o0, 0xf, %o0
a013da3c:  d8 16 a0 4c  lduh  [ %i2 + 0x4c ], %o4
a013da40:  d6 16 a0 4a  lduh  [ %i2 + 0x4a ], %o3
a013da44:  80 a3 00 0b  cmp  %o4, %o3
a013da48:  2a 80 00 36  bcs,a   0xa013db20
a013da4c:  de 16 a0 50  lduh  [ %i2 + 0x50 ], %o7
a013da50:  da 16 a0 54  lduh  [ %i2 + 0x54 ], %o5
a013da54:  c2 16 a0 52  lduh  [ %i2 + 0x52 ], %g1
a013da58:  80 a3 40 01  cmp  %o5, %g1
a013da5c:  1a 80 00 05  bcc  0xa013da70
a013da60:  80 a6 20 00  cmp  %i0, 0
a013da64:  d6 16 a0 58  lduh  [ %i2 + 0x58 ], %o3
a013da68:  d8 16 a0 56  lduh  [ %i2 + 0x56 ], %o4
a013da6c:  a8 23 00 0b  sub  %o4, %o3, %l4
a013da70:  12 80 00 0b  bne  0xa013da9c
a013da74:  93 2e 20 04  sll  %i0, 4, %o1
a013da78:  f4 04 00 00  ld  [ %l0 ], %i2
a013da7c:  80 8e a0 01  btst  1, %i2
a013da80:  32 80 00 39  bne,a   0xa013db64
a013da84:  27 2a 00 b8  sethi  %hi(0xa802e000), %l3
a013da88:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a013da8c:  e2 0a 23 d3  ldub  [ %o0 + 0x3d3 ], %l1	! 0xa802e3d3
a013da90:  80 a4 60 00  cmp  %l1, 0
a013da94:  32 80 00 46  bne,a   0xa013dbac
a013da98:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a013da9c:  90 22 40 18  sub  %o1, %i0, %o0
a013daa0:  83 2a 20 03  sll  %o0, 3, %g1
a013daa4:  a2 14 a3 30  or  %l2, 0x330, %l1
a013daa8:  9e 00 40 11  add  %g1, %l1, %o7
a013daac:  d6 13 e0 5c  lduh  [ %o7 + 0x5c ], %o3
a013dab0:  b4 02 c0 14  add  %o3, %l4, %i2
a013dab4:  e0 13 e0 5a  lduh  [ %o7 + 0x5a ], %l0
a013dab8:  95 2e a0 10  sll  %i2, 0x10, %o2
a013dabc:  98 04 00 13  add  %l0, %l3, %o4
a013dac0:  9b 2b 20 10  sll  %o4, 0x10, %o5
a013dac4:  93 32 a0 10  srl  %o2, 0x10, %o1
a013dac8:  91 33 60 10  srl  %o5, 0x10, %o0
a013dacc:  d6 13 e0 54  lduh  [ %o7 + 0x54 ], %o3
a013dad0:  d4 13 e0 4c  lduh  [ %o7 + 0x4c ], %o2
a013dad4:  7f fe e4 8b  call  0xa00f6d00
a013dad8:  01 00 00 00  nop
a013dadc:  7f fe e2 38  call  0xa00f63bc
a013dae0:  90 0e 60 ff  and  %i1, 0xff, %o0
a013dae4:  80 a6 20 03  cmp  %i0, 3
a013dae8:  12 80 00 37  bne  0xa013dbc4
a013daec:  27 2a 00 b8  sethi  %hi(0xa802e000), %l3
a013daf0:  f2 04 e3 d0  ld  [ %l3 + 0x3d0 ], %i1	! 0xa802e3d0
a013daf4:  31 00 08 00  sethi  %hi(0x200000), %i0
a013daf8:  80 8e 40 18  btst  %i1, %i0
a013dafc:  22 80 00 14  be,a   0xa013db4c
a013db00:  b4 14 a3 30  or  %l2, 0x330, %i2
a013db04:  9e 14 a3 30  or  %l2, 0x330, %o7
a013db08:  e8 03 e1 68  ld  [ %o7 + 0x168 ], %l4
a013db0c:  a5 35 20 0c  srl  %l4, 0xc, %l2
a013db10:  b0 0c a0 0f  and  %l2, 0xf, %i0
a013db14:  b2 10 20 3f  mov  0x3f, %i1
a013db18:  7f ff 24 89  call  0xa0106d3c
a013db1c:  95 e8 20 ff  restore  %g0, 0xff, %o2
a013db20:  d4 16 a0 4e  lduh  [ %i2 + 0x4e ], %o2
a013db24:  10 bf ff cb  b  0xa013da50
a013db28:  a6 23 c0 0a  sub  %o7, %o2, %l3
a013db2c:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a013db30:  d0 02 63 d0  ld  [ %o1 + 0x3d0 ], %o0	! 0xa802e3d0
a013db34:  1b 00 08 00  sethi  %hi(0x200000), %o5
a013db38:  80 8a 00 0d  btst  %o0, %o5
a013db3c:  12 bf ff 9f  bne  0xa013d9b8
a013db40:  98 10 20 01  mov  1, %o4
a013db44:  10 bf ff 9d  b  0xa013d9b8
a013db48:  98 10 20 02  mov  2, %o4
a013db4c:  da 06 a1 68  ld  [ %i2 + 0x168 ], %o5
a013db50:  95 33 60 0c  srl  %o5, 0xc, %o2
a013db54:  b0 0a a0 0f  and  %o2, 0xf, %i0
a013db58:  b2 10 20 30  mov  0x30, %i1
a013db5c:  7f ff 24 78  call  0xa0106d3c
a013db60:  95 e8 20 c0  restore  %g0, 0xc0, %o2
a013db64:  a0 14 e3 78  or  %l3, 0x378, %l0
a013db68:  d6 14 20 28  lduh  [ %l0 + 0x28 ], %o3
a013db6c:  f4 14 20 32  lduh  [ %l0 + 0x32 ], %i2
a013db70:  d8 14 20 26  lduh  [ %l0 + 0x26 ], %o4
a013db74:  da 14 20 30  lduh  [ %l0 + 0x30 ], %o5
a013db78:  82 03 00 0b  add  %o4, %o3, %g1
a013db7c:  d4 14 60 50  lduh  [ %l1 + 0x50 ], %o2
a013db80:  d2 14 60 56  lduh  [ %l1 + 0x56 ], %o1
a013db84:  9e 03 40 1a  add  %o5, %i2, %o7
a013db88:  90 22 80 01  sub  %o2, %g1, %o0
a013db8c:  a8 22 40 0f  sub  %o1, %o7, %l4
a013db90:  a7 2a 20 10  sll  %o0, 0x10, %l3
a013db94:  a1 2d 20 10  sll  %l4, 0x10, %l0
a013db98:  91 34 e0 10  srl  %l3, 0x10, %o0
a013db9c:  93 34 20 10  srl  %l0, 0x10, %o1
a013dba0:  d6 14 60 54  lduh  [ %l1 + 0x54 ], %o3
a013dba4:  10 bf ff cc  b  0xa013dad4
a013dba8:  d4 14 60 4c  lduh  [ %l1 + 0x4c ], %o2
a013dbac:  a8 12 63 78  or  %o1, 0x378, %l4
a013dbb0:  d6 15 20 0a  lduh  [ %l4 + 0xa ], %o3
a013dbb4:  90 10 20 00  clr  %o0
a013dbb8:  92 10 20 00  clr  %o1
a013dbbc:  10 bf ff c6  b  0xa013dad4
a013dbc0:  d4 15 20 08  lduh  [ %l4 + 8 ], %o2
a013dbc4:  81 c7 e0 08  ret
a013dbc8:  81 e8 00 00  restore
