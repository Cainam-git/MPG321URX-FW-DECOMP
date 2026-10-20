# leon2m FUN_a00bd760 0xa00bd760-0xa00bd988 (552 bytes)
a00bd760:  9d e3 bf 98  save  %sp, -104, %sp
a00bd764:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bd768:  96 12 a2 90  or  %o2, 0x290, %o3	! 0xa802d290
a00bd76c:  d8 02 e0 a8  ld  [ %o3 + 0xa8 ], %o4
a00bd770:  93 33 20 0b  srl  %o4, 0xb, %o1
a00bd774:  90 0a 60 01  and  %o1, 1, %o0
a00bd778:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bd77c:  94 16 a0 78  or  %i2, 0x78, %o2	! 0xa802d078
a00bd780:  9a 02 20 30  add  %o0, 0x30, %o5
a00bd784:  82 10 20 30  mov  0x30, %g1
a00bd788:  c2 2a a0 07  stb  %g1, [ %o2 + 7 ]
a00bd78c:  80 8b 28 00  btst  0x800, %o4
a00bd790:  12 80 00 3c  bne  0xa00bd880
a00bd794:  da 2a a0 08  stb  %o5, [ %o2 + 8 ]
a00bd798:  d8 0a e1 82  ldub  [ %o3 + 0x182 ], %o4
a00bd79c:  17 0a aa aa  sethi  %hi(0x2aaaa800), %o3
a00bd7a0:  a0 03 20 05  add  %o4, 5, %l0
a00bd7a4:  92 12 e2 ab  or  %o3, 0x2ab, %o1
a00bd7a8:  80 5c 00 09  smul  %l0, %o1, %g0
a00bd7ac:  9b 40 00 00  rd  %y, %o5
a00bd7b0:  90 03 40 0d  add  %o5, %o5, %o0
a00bd7b4:  82 02 00 0d  add  %o0, %o5, %g1
a00bd7b8:  b2 00 40 01  add  %g1, %g1, %i1
a00bd7bc:  9e 24 00 19  sub  %l0, %i1, %o7
a00bd7c0:  96 03 e0 30  add  %o7, 0x30, %o3
a00bd7c4:  d6 2a a0 09  stb  %o3, [ %o2 + 9 ]
a00bd7c8:  92 10 20 00  clr  %o1
a00bd7cc:  40 02 5b 9c  call  0xa015463c
a00bd7d0:  90 10 20 2c  mov  0x2c, %o0
a00bd7d4:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bd7d8:  a0 16 a0 78  or  %i2, 0x78, %l0
a00bd7dc:  90 10 20 62  mov  0x62, %o0
a00bd7e0:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bd7e4:  92 10 20 02  mov  2, %o1
a00bd7e8:  40 02 5b 95  call  0xa015463c
a00bd7ec:  90 10 20 2c  mov  0x2c, %o0
a00bd7f0:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bd7f4:  92 10 20 03  mov  3, %o1
a00bd7f8:  40 02 5b 91  call  0xa015463c
a00bd7fc:  90 10 20 2c  mov  0x2c, %o0
a00bd800:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bd804:  92 10 20 04  mov  4, %o1
a00bd808:  40 02 5b 8d  call  0xa015463c
a00bd80c:  90 10 20 2c  mov  0x2c, %o0
a00bd810:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bd814:  92 10 20 05  mov  5, %o1
a00bd818:  40 02 5b 89  call  0xa015463c
a00bd81c:  90 10 20 2c  mov  0x2c, %o0
a00bd820:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bd824:  90 10 20 2c  mov  0x2c, %o0
a00bd828:  40 02 5b 85  call  0xa015463c
a00bd82c:  92 10 20 06  mov  6, %o1
a00bd830:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bd834:  82 10 20 0d  mov  0xd, %g1
a00bd838:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00bd83c:  80 a6 20 02  cmp  %i0, 2
a00bd840:  02 80 00 1a  be  0xa00bd8a8
a00bd844:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bd848:  80 a6 20 03  cmp  %i0, 3
a00bd84c:  02 80 00 23  be  0xa00bd8d8
a00bd850:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00bd854:  33 2a 00 ac  sethi  %hi(0xa802b000), %i1
a00bd858:  c0 2e 60 9c  clrb  [ %i1 + 0x9c ]	! 0xa802b09c
a00bd85c:  9a 13 e0 d0  or  %o7, 0xd0, %o5
a00bd860:  c0 2b e0 d0  clrb  [ %o7 + 0xd0 ]
a00bd864:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bd868:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bd86c:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bd870:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bd874:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bd878:  40 02 2b dc  call  0xa01487e8
a00bd87c:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd880:  c2 0a e1 81  ldub  [ %o3 + 0x181 ], %g1
a00bd884:  80 a0 60 07  cmp  %g1, 7
a00bd888:  18 bf ff d1  bgu  0xa00bd7cc
a00bd88c:  92 10 20 00  clr  %o1
a00bd890:  33 00 01 69  sethi  %hi(0x5a400), %i1
a00bd894:  9f 28 60 02  sll  %g1, 2, %o7
a00bd898:  a0 16 60 08  or  %i1, 8, %l0
a00bd89c:  d4 04 00 0f  ld  [ %l0 + %o7 ], %o2
a00bd8a0:  81 c2 80 00  jmp  %o2
a00bd8a4:  01 00 00 00  nop
a00bd8a8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bd8ac:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00bd8b0:  9a 12 60 40  or  %o1, 0x40, %o5
a00bd8b4:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]
a00bd8b8:  c0 2a 60 40  clrb  [ %o1 + 0x40 ]
a00bd8bc:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bd8c0:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bd8c4:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bd8c8:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bd8cc:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bd8d0:  40 02 2b c6  call  0xa01487e8
a00bd8d4:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd8d8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bd8dc:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00bd8e0:  9a 13 20 98  or  %o4, 0x98, %o5
a00bd8e4:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bd8e8:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]
a00bd8ec:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bd8f0:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bd8f4:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bd8f8:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bd8fc:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bd900:  40 02 2b ba  call  0xa01487e8
a00bd904:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd908:  9a 16 a0 78  or  %i2, 0x78, %o5
a00bd90c:  82 10 20 37  mov  0x37, %g1
a00bd910:  10 bf ff ae  b  0xa00bd7c8
a00bd914:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bd918:  9a 16 a0 78  or  %i2, 0x78, %o5
a00bd91c:  82 10 20 30  mov  0x30, %g1
a00bd920:  10 bf ff aa  b  0xa00bd7c8
a00bd924:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bd928:  9a 16 a0 78  or  %i2, 0x78, %o5
a00bd92c:  82 10 20 31  mov  0x31, %g1
a00bd930:  10 bf ff a6  b  0xa00bd7c8
a00bd934:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bd938:  9a 16 a0 78  or  %i2, 0x78, %o5
a00bd93c:  82 10 20 32  mov  0x32, %g1
a00bd940:  10 bf ff a2  b  0xa00bd7c8
a00bd944:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bd948:  9a 16 a0 78  or  %i2, 0x78, %o5
a00bd94c:  82 10 20 33  mov  0x33, %g1
a00bd950:  10 bf ff 9e  b  0xa00bd7c8
a00bd954:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bd958:  9a 16 a0 78  or  %i2, 0x78, %o5
a00bd95c:  82 10 20 34  mov  0x34, %g1
a00bd960:  10 bf ff 9a  b  0xa00bd7c8
a00bd964:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bd968:  9a 16 a0 78  or  %i2, 0x78, %o5
a00bd96c:  82 10 20 35  mov  0x35, %g1
a00bd970:  10 bf ff 96  b  0xa00bd7c8
a00bd974:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bd978:  9a 16 a0 78  or  %i2, 0x78, %o5
a00bd97c:  82 10 20 36  mov  0x36, %g1
a00bd980:  10 bf ff 92  b  0xa00bd7c8
a00bd984:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
