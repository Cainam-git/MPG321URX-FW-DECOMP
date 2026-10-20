# leon2m FUN_a00bc6f0 0xa00bc6f0-0xa00bc86c (380 bytes)
a00bc6f0:  9d e3 bf 98  save  %sp, -104, %sp
a00bc6f4:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bc6f8:  d4 0b 62 a4  ldub  [ %o5 + 0x2a4 ], %o2	! 0xa802d2a4
a00bc6fc:  11 14 7a e1  sethi  %hi(0x51eb8400), %o0
a00bc700:  b2 0a a0 ff  and  %o2, 0xff, %i1
a00bc704:  82 12 21 1f  or  %o0, 0x11f, %g1
a00bc708:  80 56 40 01  umul  %i1, %g1, %g0
a00bc70c:  97 40 00 00  rd  %y, %o3
a00bc710:  b3 32 e0 05  srl  %o3, 5, %i1
a00bc714:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00bc718:  a0 5e a0 64  smul  %i2, 0x64, %l0
a00bc71c:  b4 22 80 10  sub  %o2, %l0, %i2
a00bc720:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a00bc724:  92 0e a0 ff  and  %i2, 0xff, %o1
a00bc728:  9e 13 20 cd  or  %o4, 0xcd, %o7
a00bc72c:  80 52 40 0f  umul  %o1, %o7, %g0
a00bc730:  9b 40 00 00  rd  %y, %o5
a00bc734:  9f 33 60 03  srl  %o5, 3, %o7
a00bc738:  90 0b e0 ff  and  %o7, 0xff, %o0
a00bc73c:  83 2a 20 02  sll  %o0, 2, %g1
a00bc740:  a0 00 40 08  add  %g1, %o0, %l0
a00bc744:  98 04 00 10  add  %l0, %l0, %o4
a00bc748:  92 26 80 0c  sub  %i2, %o4, %o1
a00bc74c:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bc750:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00bc754:  9a 03 e0 30  add  %o7, 0x30, %o5
a00bc758:  94 02 60 30  add  %o1, 0x30, %o2
a00bc75c:  96 06 60 30  add  %i1, 0x30, %o3
a00bc760:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a00bc764:  d6 2c 20 07  stb  %o3, [ %l0 + 7 ]
a00bc768:  d4 2c 20 09  stb  %o2, [ %l0 + 9 ]
a00bc76c:  92 10 20 00  clr  %o1
a00bc770:  40 02 5f b3  call  0xa015463c
a00bc774:  90 10 20 09  mov  9, %o0
a00bc778:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bc77c:  90 10 20 62  mov  0x62, %o0
a00bc780:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bc784:  92 10 20 02  mov  2, %o1
a00bc788:  40 02 5f ad  call  0xa015463c
a00bc78c:  90 10 20 09  mov  9, %o0
a00bc790:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bc794:  92 10 20 03  mov  3, %o1
a00bc798:  40 02 5f a9  call  0xa015463c
a00bc79c:  90 10 20 09  mov  9, %o0
a00bc7a0:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bc7a4:  92 10 20 04  mov  4, %o1
a00bc7a8:  40 02 5f a5  call  0xa015463c
a00bc7ac:  90 10 20 09  mov  9, %o0
a00bc7b0:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bc7b4:  92 10 20 05  mov  5, %o1
a00bc7b8:  40 02 5f a1  call  0xa015463c
a00bc7bc:  90 10 20 09  mov  9, %o0
a00bc7c0:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bc7c4:  92 10 20 06  mov  6, %o1
a00bc7c8:  40 02 5f 9d  call  0xa015463c
a00bc7cc:  90 10 20 09  mov  9, %o0
a00bc7d0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bc7d4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bc7d8:  82 10 20 0d  mov  0xd, %g1
a00bc7dc:  9a 13 20 40  or  %o4, 0x40, %o5
a00bc7e0:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00bc7e4:  80 a6 20 02  cmp  %i0, 2
a00bc7e8:  02 80 00 12  be  0xa00bc830
a00bc7ec:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bc7f0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bc7f4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bc7f8:  96 12 a0 98  or  %o2, 0x98, %o3
a00bc7fc:  80 a6 20 03  cmp  %i0, 3
a00bc800:  02 80 00 10  be  0xa00bc840
a00bc804:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bc808:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00bc80c:  c0 2a a0 9c  clrb  [ %o2 + 0x9c ]	! 0xa802b09c
a00bc810:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bc814:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bc818:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bc81c:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bc820:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bc824:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bc828:  40 02 2f f0  call  0xa01487e8
a00bc82c:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bc830:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00bc834:  c0 2a 60 9a  clrb  [ %o1 + 0x9a ]	! 0xa802b09a
a00bc838:  10 bf ff f7  b  0xa00bc814
a00bc83c:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bc840:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bc844:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]	! 0xa802b098
a00bc848:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bc84c:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bc850:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bc854:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bc858:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bc85c:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bc860:  40 02 2f e2  call  0xa01487e8
a00bc864:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bc868:  01 00 00 00  nop
