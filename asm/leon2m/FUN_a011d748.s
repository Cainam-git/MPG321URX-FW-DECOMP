# leon2m FUN_a011d748 0xa011d748-0xa011dd9c (472 bytes)
a011d748:  9d e3 bf 98  save  %sp, -104, %sp
a011d74c:  82 06 3f f0  add  %i0, -16, %g1
a011d750:  b8 08 60 ff  and  %g1, 0xff, %i4
a011d754:  80 a7 20 09  cmp  %i4, 9
a011d758:  9e 0e 20 ff  and  %i0, 0xff, %o7
a011d75c:  82 60 20 00  subx  %g0, 0, %g1
a011d760:  ba 1b e0 1f  xor  %o7, 0x1f, %i5
a011d764:  80 a0 00 1d  cmp  %g0, %i5
a011d768:  b8 60 3f ff  subx  %g0, -1, %i4
a011d76c:  b0 08 60 01  and  %g1, 1, %i0
a011d770:  82 16 00 1c  or  %i0, %i4, %g1
a011d774:  80 a0 00 01  cmp  %g0, %g1
a011d778:  ba 40 3f ff  addx  %g0, -1, %i5
a011d77c:  b6 0e c0 1d  and  %i3, %i5, %i3
a011d780:  9a 0e e0 03  and  %i3, 3, %o5
a011d784:  b0 10 00 1a  mov  %i2, %i0
a011d788:  98 10 00 19  mov  %i1, %o4
a011d78c:  80 a3 60 01  cmp  %o5, 1
a011d790:  02 80 00 06  be  0xa011d7a8
a011d794:  35 01 6e 36  sethi  %hi(0x5b8d800), %i2
a011d798:  33 00 2d c6  sethi  %hi(0xb71800), %i1
a011d79c:  80 a3 60 00  cmp  %o5, 0
a011d7a0:  12 80 00 41  bne  0xa011d8a4
a011d7a4:  b4 16 63 00  or  %i1, 0x300, %i2
a011d7a8:  b3 2e a0 02  sll  %i2, 2, %i1
a011d7ac:  ba 06 40 1a  add  %i1, %i2, %i5
a011d7b0:  b8 07 40 1d  add  %i5, %i5, %i4
a011d7b4:  81 80 00 00  mov  %g0, %y
a011d7b8:  01 00 00 00  nop
a011d7bc:  01 00 00 00  nop
a011d7c0:  01 00 00 00  nop
a011d7c4:  82 77 00 18  udiv  %i4, %i0, %g1
a011d7c8:  37 33 33 33  sethi  %hi(0xcccccc00), %i3
a011d7cc:  b8 00 7f fb  add  %g1, -5, %i4
a011d7d0:  ba 16 e0 cd  or  %i3, 0xcd, %i5
a011d7d4:  80 57 00 1d  umul  %i4, %i5, %g0
a011d7d8:  b7 40 00 00  rd  %y, %i3
a011d7dc:  83 36 e0 03  srl  %i3, 3, %g1
a011d7e0:  80 a0 63 ff  cmp  %g1, 0x3ff
a011d7e4:  b6 10 20 0a  mov  0xa, %i3
a011d7e8:  18 80 00 08  bgu  0xa011d808
a011d7ec:  b8 10 24 00  mov  0x400, %i4
a011d7f0:  80 a0 60 ff  cmp  %g1, 0xff
a011d7f4:  b6 10 20 08  mov  8, %i3
a011d7f8:  18 80 00 04  bgu  0xa011d808
a011d7fc:  b8 10 21 00  mov  0x100, %i4
a011d800:  b6 10 20 04  mov  4, %i3
a011d804:  b8 10 20 10  mov  0x10, %i4
a011d808:  ba 06 40 1a  add  %i1, %i2, %i5
a011d80c:  b4 07 40 1d  add  %i5, %i5, %i2
a011d810:  82 0f 25 10  and  %i4, 0x510, %g1
a011d814:  81 80 00 00  mov  %g0, %y
a011d818:  01 00 00 00  nop
a011d81c:  01 00 00 00  nop
a011d820:  01 00 00 00  nop
a011d824:  b2 76 80 01  udiv  %i2, %g1, %i1
a011d828:  81 80 00 00  mov  %g0, %y
a011d82c:  01 00 00 00  nop
a011d830:  01 00 00 00  nop
a011d834:  01 00 00 00  nop
a011d838:  ba 76 40 18  udiv  %i1, %i0, %i5
a011d83c:  39 33 33 33  sethi  %hi(0xcccccc00), %i4
a011d840:  b4 07 7f fb  add  %i5, -5, %i2
a011d844:  82 17 20 cd  or  %i4, 0xcd, %g1
a011d848:  80 56 80 01  umul  %i2, %g1, %g0
a011d84c:  b1 40 00 00  rd  %y, %i0
a011d850:  b2 0e e0 ff  and  %i3, 0xff, %i1
a011d854:  80 a6 60 0e  cmp  %i1, 0xe
a011d858:  18 80 00 0a  bgu  0xa011d880
a011d85c:  b5 36 20 03  srl  %i0, 3, %i2
a011d860:  80 a6 a3 ff  cmp  %i2, 0x3ff
a011d864:  08 80 00 08  bleu  0xa011d884
a011d868:  80 a3 e0 1f  cmp  %o7, 0x1f
a011d86c:  b6 06 e0 01  inc  %i3
a011d870:  b0 0e e0 ff  and  %i3, 0xff, %i0
a011d874:  80 a6 20 0e  cmp  %i0, 0xe
a011d878:  08 bf ff fa  bleu  0xa011d860
a011d87c:  b5 36 a0 01  srl  %i2, 1, %i2
a011d880:  80 a3 e0 1f  cmp  %o7, 0x1f
a011d884:  18 80 00 0b  bgu  0xa011d8b0
a011d888:  b0 10 20 00  clr  %i0
a011d88c:  3b 00 02 f4  sethi  %hi(0xbd000), %i5
a011d890:  b3 2b e0 02  sll  %o7, 2, %i1
a011d894:  82 17 63 04  or  %i5, 0x304, %g1
a011d898:  f8 00 40 19  ld  [ %g1 + %i1 ], %i4
a011d89c:  81 c7 00 00  jmp  %i4
a011d8a0:  01 00 00 00  nop
a011d8a4:  35 00 06 8b  sethi  %hi(0x1a2c00), %i2
a011d8a8:  7f ff 06 32  call  0xa00df170
a011d8ac:  91 ee a3 70  restore  %i2, 0x370, %o0
a011d8b0:  ba 10 20 00  clr  %i5
a011d8b4:  b0 10 20 01  mov  1, %i0
a011d8b8:  80 8e 20 ff  btst  0xff, %i0
a011d8bc:  12 80 01 36  bne  0xa011dd94
a011d8c0:  b9 36 a0 04  srl  %i2, 4, %i4
a011d8c4:  b0 17 40 1b  or  %i5, %i3, %i0
a011d8c8:  82 0f 20 30  and  %i4, 0x30, %g1
a011d8cc:  b6 10 40 18  or  %g1, %i0, %i3
a011d8d0:  80 a3 e0 1f  cmp  %o7, 0x1f
a011d8d4:  08 80 00 0b  bleu  0xa011d900
a011d8d8:  b0 10 00 1a  mov  %i2, %i0
a011d8dc:  82 0b 20 ff  and  %o4, 0xff, %g1
a011d8e0:  80 a0 60 1b  cmp  %g1, 0x1b
a011d8e4:  18 80 01 2c  bgu  0xa011dd94
a011d8e8:  39 00 02 f4  sethi  %hi(0xbd000), %i4
a011d8ec:  b7 28 60 02  sll  %g1, 2, %i3
a011d8f0:  b4 17 22 94  or  %i4, 0x294, %i2
a011d8f4:  f0 06 80 1b  ld  [ %i2 + %i3 ], %i0
a011d8f8:  81 c6 00 00  jmp  %i0
a011d8fc:  01 00 00 00  nop
a011d900:  03 00 02 f4  sethi  %hi(0xbd000), %g1
a011d904:  b3 2b e0 02  sll  %o7, 2, %i1
a011d908:  ba 10 62 14  or  %g1, 0x214, %i5
a011d90c:  f4 07 40 19  ld  [ %i5 + %i1 ], %i2
a011d910:  81 c6 80 00  jmp  %i2
a011d914:  01 00 00 00  nop
a011d918:  39 33 c0 58  sethi  %hi(0xcf016000), %i4
a011d91c:  82 17 21 24  or  %i4, 0x124, %g1	! 0xcf016124
a011d920:  f2 00 40 00  ld  [ %g1 ], %i1
a011d924:  10 bf ff e5  b  0xa011d8b8
a011d928:  ba 0e 60 c0  and  %i1, 0xc0, %i5
a011d92c:  3b 33 c0 58  sethi  %hi(0xcf016000), %i5
a011d930:  82 17 61 6c  or  %i5, 0x16c, %g1	! 0xcf01616c
a011d934:  f2 00 40 00  ld  [ %g1 ], %i1
a011d938:  10 bf ff e0  b  0xa011d8b8
a011d93c:  ba 0e 60 c0  and  %i1, 0xc0, %i5
a011d940:  39 33 c0 58  sethi  %hi(0xcf016000), %i4
a011d944:  82 17 21 84  or  %i4, 0x184, %g1	! 0xcf016184
a011d948:  f2 00 40 00  ld  [ %g1 ], %i1
a011d94c:  10 bf ff db  b  0xa011d8b8
a011d950:  ba 0e 60 c0  and  %i1, 0xc0, %i5
a011d954:  33 33 c0 58  sethi  %hi(0xcf016000), %i1
a011d958:  82 16 61 9c  or  %i1, 0x19c, %g1	! 0xcf01619c
a011d95c:  f2 00 40 00  ld  [ %g1 ], %i1
a011d960:  10 bf ff d6  b  0xa011d8b8
a011d964:  ba 0e 60 c0  and  %i1, 0xc0, %i5
a011d968:  3b 33 c0 59  sethi  %hi(0xcf016400), %i5
a011d96c:  82 17 60 98  or  %i5, 0x98, %g1	! 0xcf016498
a011d970:  f2 00 40 00  ld  [ %g1 ], %i1
a011d974:  10 bf ff d1  b  0xa011d8b8
a011d978:  ba 0e 60 c0  and  %i1, 0xc0, %i5
a011d97c:  33 33 c0 58  sethi  %hi(0xcf016000), %i1
a011d980:  82 16 61 3c  or  %i1, 0x13c, %g1	! 0xcf01613c
a011d984:  f2 00 40 00  ld  [ %g1 ], %i1
a011d988:  10 bf ff cc  b  0xa011d8b8
a011d98c:  ba 0e 60 c0  and  %i1, 0xc0, %i5
a011d990:  03 33 c0 58  sethi  %hi(0xcf016000), %g1
a011d994:  82 10 61 54  or  %g1, 0x154, %g1	! 0xcf016154
a011d998:  f2 00 40 00  ld  [ %g1 ], %i1
a011d99c:  10 bf ff c7  b  0xa011d8b8
a011d9a0:  ba 0e 60 c0  and  %i1, 0xc0, %i5
a011d9a4:  39 33 c0 59  sethi  %hi(0xcf016400), %i4
a011d9a8:  82 17 20 c4  or  %i4, 0xc4, %g1	! 0xcf0164c4
a011d9ac:  f2 00 40 00  ld  [ %g1 ], %i1
a011d9b0:  10 bf ff c2  b  0xa011d8b8
a011d9b4:  ba 0e 60 c0  and  %i1, 0xc0, %i5
a011d9b8:  03 33 c0 59  sethi  %hi(0xcf016400), %g1
a011d9bc:  82 10 60 04  or  %g1, 4, %g1	! 0xcf016404
a011d9c0:  f2 00 40 00  ld  [ %g1 ], %i1
a011d9c4:  10 bf ff bd  b  0xa011d8b8
a011d9c8:  ba 0e 60 c0  and  %i1, 0xc0, %i5
a011d9cc:  3b 33 c0 59  sethi  %hi(0xcf016400), %i5
a011d9d0:  f4 07 40 00  ld  [ %i5 ], %i2
a011d9d4:  82 0e a0 fc  and  %i2, 0xfc, %g1
a011d9d8:  c2 27 40 00  st  %g1, [ %i5 ]
a011d9dc:  b8 0e e0 ff  and  %i3, 0xff, %i4
a011d9e0:  b2 17 60 04  or  %i5, 4, %i1
a011d9e4:  f8 26 40 00  st  %i4, [ %i1 ]
a011d9e8:  b4 17 60 08  or  %i5, 8, %i2
a011d9ec:  b6 0e 20 ff  and  %i0, 0xff, %i3
a011d9f0:  f6 26 80 00  st  %i3, [ %i2 ]
a011d9f4:  10 bf ff bb  b  0xa011d8e0
a011d9f8:  82 0b 20 ff  and  %o4, 0xff, %g1
a011d9fc:  33 33 c0 59  sethi  %hi(0xcf016400), %i1
a011da00:  b4 16 60 c0  or  %i1, 0xc0, %i2	! 0xcf0164c0
a011da04:  fa 06 80 00  ld  [ %i2 ], %i5
a011da08:  b8 0f 60 fc  and  %i5, 0xfc, %i4
a011da0c:  f8 26 80 00  st  %i4, [ %i2 ]
a011da10:  c2 06 80 00  ld  [ %i2 ], %g1
a011da14:  ba 10 40 0d  or  %g1, %o5, %i5
a011da18:  fa 26 80 00  st  %i5, [ %i2 ]
a011da1c:  b8 16 60 c4  or  %i1, 0xc4, %i4
a011da20:  b4 16 60 c8  or  %i1, 0xc8, %i2
a011da24:  b6 0e e0 ff  and  %i3, 0xff, %i3
a011da28:  f6 27 00 00  st  %i3, [ %i4 ]
a011da2c:  b2 0e 20 ff  and  %i0, 0xff, %i1
a011da30:  f2 26 80 00  st  %i1, [ %i2 ]
a011da34:  10 bf ff ab  b  0xa011d8e0
a011da38:  82 0b 20 ff  and  %o4, 0xff, %g1
a011da3c:  33 33 c0 59  sethi  %hi(0xcf016400), %i1
a011da40:  b8 16 60 94  or  %i1, 0x94, %i4	! 0xcf016494
a011da44:  c2 07 00 00  ld  [ %i4 ], %g1
a011da48:  ba 08 60 fc  and  %g1, 0xfc, %i5
a011da4c:  fa 27 00 00  st  %i5, [ %i4 ]
a011da50:  f4 07 00 00  ld  [ %i4 ], %i2
a011da54:  82 16 80 0d  or  %i2, %o5, %g1
a011da58:  c2 27 00 00  st  %g1, [ %i4 ]
a011da5c:  ba 16 60 98  or  %i1, 0x98, %i5
a011da60:  b4 16 60 9c  or  %i1, 0x9c, %i2
a011da64:  b6 0e e0 ff  and  %i3, 0xff, %i3
a011da68:  f6 27 40 00  st  %i3, [ %i5 ]
a011da6c:  b2 0e 20 ff  and  %i0, 0xff, %i1
a011da70:  f2 26 80 00  st  %i1, [ %i2 ]
a011da74:  10 bf ff 9b  b  0xa011d8e0
a011da78:  82 0b 20 ff  and  %o4, 0xff, %g1
a011da7c:  35 33 c0 58  sethi  %hi(0xcf016000), %i2
a011da80:  b8 16 a1 98  or  %i2, 0x198, %i4	! 0xcf016198
a011da84:  c2 07 00 00  ld  [ %i4 ], %g1
a011da88:  b2 08 60 fc  and  %g1, 0xfc, %i1
a011da8c:  f2 27 00 00  st  %i1, [ %i4 ]
a011da90:  fa 07 00 00  ld  [ %i4 ], %i5
a011da94:  82 17 40 0d  or  %i5, %o5, %g1
a011da98:  b2 16 a1 9c  or  %i2, 0x19c, %i1
a011da9c:  c2 27 00 00  st  %g1, [ %i4 ]
a011daa0:  b6 0e e0 ff  and  %i3, 0xff, %i3
a011daa4:  f6 26 40 00  st  %i3, [ %i1 ]
a011daa8:  b4 16 a1 a0  or  %i2, 0x1a0, %i2
a011daac:  b2 0e 20 ff  and  %i0, 0xff, %i1
a011dab0:  f2 26 80 00  st  %i1, [ %i2 ]
a011dab4:  10 bf ff 8b  b  0xa011d8e0
a011dab8:  82 0b 20 ff  and  %o4, 0xff, %g1
a011dabc:  35 33 c0 58  sethi  %hi(0xcf016000), %i2
a011dac0:  b2 16 a1 80  or  %i2, 0x180, %i1	! 0xcf016180
a011dac4:  fa 06 40 00  ld  [ %i1 ], %i5
a011dac8:  b8 0f 60 fc  and  %i5, 0xfc, %i4
a011dacc:  f8 26 40 00  st  %i4, [ %i1 ]
a011dad0:  c2 06 40 00  ld  [ %i1 ], %g1
a011dad4:  ba 10 40 0d  or  %g1, %o5, %i5
a011dad8:  fa 26 40 00  st  %i5, [ %i1 ]
a011dadc:  b8 16 a1 84  or  %i2, 0x184, %i4
a011dae0:  b6 0e e0 ff  and  %i3, 0xff, %i3
a011dae4:  f6 27 00 00  st  %i3, [ %i4 ]
a011dae8:  b4 16 a1 88  or  %i2, 0x188, %i2
a011daec:  b2 0e 20 ff  and  %i0, 0xff, %i1
a011daf0:  f2 26 80 00  st  %i1, [ %i2 ]
a011daf4:  10 bf ff 7b  b  0xa011d8e0
a011daf8:  82 0b 20 ff  and  %o4, 0xff, %g1
a011dafc:  35 33 c0 58  sethi  %hi(0xcf016000), %i2
a011db00:  b8 16 a1 68  or  %i2, 0x168, %i4	! 0xcf016168
a011db04:  c2 07 00 00  ld  [ %i4 ], %g1
a011db08:  b2 08 60 fc  and  %g1, 0xfc, %i1
a011db0c:  f2 27 00 00  st  %i1, [ %i4 ]
a011db10:  fa 07 00 00  ld  [ %i4 ], %i5
a011db14:  82 17 40 0d  or  %i5, %o5, %g1
a011db18:  b2 16 a1 6c  or  %i2, 0x16c, %i1
a011db1c:  c2 27 00 00  st  %g1, [ %i4 ]
a011db20:  b6 0e e0 ff  and  %i3, 0xff, %i3
a011db24:  f6 26 40 00  st  %i3, [ %i1 ]
a011db28:  b4 16 a1 70  or  %i2, 0x170, %i2
a011db2c:  b2 0e 20 ff  and  %i0, 0xff, %i1
a011db30:  f2 26 80 00  st  %i1, [ %i2 ]
a011db34:  10 bf ff 6b  b  0xa011d8e0
a011db38:  82 0b 20 ff  and  %o4, 0xff, %g1
a011db3c:  35 33 c0 58  sethi  %hi(0xcf016000), %i2
a011db40:  b2 16 a1 50  or  %i2, 0x150, %i1	! 0xcf016150
a011db44:  fa 06 40 00  ld  [ %i1 ], %i5
a011db48:  b8 0f 60 fc  and  %i5, 0xfc, %i4
a011db4c:  f8 26 40 00  st  %i4, [ %i1 ]
a011db50:  c2 06 40 00  ld  [ %i1 ], %g1
a011db54:  ba 10 40 0d  or  %g1, %o5, %i5
a011db58:  fa 26 40 00  st  %i5, [ %i1 ]
a011db5c:  b8 16 a1 54  or  %i2, 0x154, %i4
a011db60:  b6 0e e0 ff  and  %i3, 0xff, %i3
a011db64:  f6 27 00 00  st  %i3, [ %i4 ]
a011db68:  b4 16 a1 58  or  %i2, 0x158, %i2
a011db6c:  b2 0e 20 ff  and  %i0, 0xff, %i1
a011db70:  f2 26 80 00  st  %i1, [ %i2 ]
a011db74:  10 bf ff 5b  b  0xa011d8e0
a011db78:  82 0b 20 ff  and  %o4, 0xff, %g1
a011db7c:  35 33 c0 58  sethi  %hi(0xcf016000), %i2
a011db80:  b8 16 a1 38  or  %i2, 0x138, %i4	! 0xcf016138
a011db84:  c2 07 00 00  ld  [ %i4 ], %g1
a011db88:  b2 08 60 fc  and  %g1, 0xfc, %i1
a011db8c:  f2 27 00 00  st  %i1, [ %i4 ]
a011db90:  fa 07 00 00  ld  [ %i4 ], %i5
a011db94:  82 17 40 0d  or  %i5, %o5, %g1
a011db98:  b2 16 a1 3c  or  %i2, 0x13c, %i1
a011db9c:  c2 27 00 00  st  %g1, [ %i4 ]
a011dba0:  b6 0e e0 ff  and  %i3, 0xff, %i3
a011dba4:  f6 26 40 00  st  %i3, [ %i1 ]
a011dba8:  b4 16 a1 40  or  %i2, 0x140, %i2
a011dbac:  b2 0e 20 ff  and  %i0, 0xff, %i1
a011dbb0:  f2 26 80 00  st  %i1, [ %i2 ]
a011dbb4:  10 bf ff 4b  b  0xa011d8e0
a011dbb8:  82 0b 20 ff  and  %o4, 0xff, %g1
a011dbbc:  35 33 c0 58  sethi  %hi(0xcf016000), %i2
a011dbc0:  b2 16 a1 20  or  %i2, 0x120, %i1	! 0xcf016120
a011dbc4:  fa 06 40 00  ld  [ %i1 ], %i5
a011dbc8:  b8 0f 60 fc  and  %i5, 0xfc, %i4
a011dbcc:  f8 26 40 00  st  %i4, [ %i1 ]
a011dbd0:  c2 06 40 00  ld  [ %i1 ], %g1
a011dbd4:  ba 10 40 0d  or  %g1, %o5, %i5
a011dbd8:  fa 26 40 00  st  %i5, [ %i1 ]
a011dbdc:  b8 16 a1 24  or  %i2, 0x124, %i4
a011dbe0:  b6 0e e0 ff  and  %i3, 0xff, %i3
a011dbe4:  f6 27 00 00  st  %i3, [ %i4 ]
a011dbe8:  b4 16 a1 28  or  %i2, 0x128, %i2
a011dbec:  b2 0e 20 ff  and  %i0, 0xff, %i1
a011dbf0:  f2 26 80 00  st  %i1, [ %i2 ]
a011dbf4:  10 bf ff 3b  b  0xa011d8e0
a011dbf8:  82 0b 20 ff  and  %o4, 0xff, %g1
a011dbfc:  b0 10 20 09  mov  9, %i0
a011dc00:  b2 10 20 80  mov  0x80, %i1
a011dc04:  b4 10 20 0a  mov  0xa, %i2
a011dc08:  7f ff 83 1e  call  0xa00fe880
a011dc0c:  81 e8 00 00  restore
a011dc10:  b0 10 20 09  mov  9, %i0
a011dc14:  b2 10 20 40  mov  0x40, %i1
a011dc18:  10 bf ff fc  b  0xa011dc08
a011dc1c:  b4 10 20 0a  mov  0xa, %i2
a011dc20:  b0 10 20 09  mov  9, %i0
a011dc24:  b2 10 20 20  mov  0x20, %i1
a011dc28:  10 bf ff f8  b  0xa011dc08
a011dc2c:  b4 10 20 0a  mov  0xa, %i2
a011dc30:  b0 10 20 09  mov  9, %i0
a011dc34:  b2 10 20 10  mov  0x10, %i1
a011dc38:  10 bf ff f4  b  0xa011dc08
a011dc3c:  b4 10 20 0a  mov  0xa, %i2
a011dc40:  b0 10 20 0b  mov  0xb, %i0
a011dc44:  b2 10 20 04  mov  4, %i1
a011dc48:  b4 10 20 05  mov  5, %i2
a011dc4c:  7f ff 83 0d  call  0xa00fe880
a011dc50:  81 e8 00 00  restore
a011dc54:  b0 10 20 05  mov  5, %i0
a011dc58:  10 bf ff fc  b  0xa011dc48
a011dc5c:  b2 10 20 04  mov  4, %i1
a011dc60:  b0 10 20 0a  mov  0xa, %i0
a011dc64:  b2 10 20 02  mov  2, %i1
a011dc68:  10 bf ff f9  b  0xa011dc4c
a011dc6c:  b4 10 20 05  mov  5, %i2
a011dc70:  b0 10 20 0f  mov  0xf, %i0
a011dc74:  b2 10 20 08  mov  8, %i1
a011dc78:  10 bf ff f5  b  0xa011dc4c
a011dc7c:  b4 10 20 05  mov  5, %i2
a011dc80:  b0 10 20 0b  mov  0xb, %i0
a011dc84:  10 bf ff f9  b  0xa011dc68
a011dc88:  b2 10 20 02  mov  2, %i1
a011dc8c:  b0 10 20 0a  mov  0xa, %i0
a011dc90:  b2 10 20 01  mov  1, %i1
a011dc94:  10 bf ff ee  b  0xa011dc4c
a011dc98:  b4 10 20 05  mov  5, %i2
a011dc9c:  b0 10 20 0f  mov  0xf, %i0
a011dca0:  10 bf ff ea  b  0xa011dc48
a011dca4:  b2 10 20 04  mov  4, %i1
a011dca8:  b0 10 20 0b  mov  0xb, %i0
a011dcac:  10 bf ff fa  b  0xa011dc94
a011dcb0:  b2 10 20 01  mov  1, %i1
a011dcb4:  b0 10 20 0b  mov  0xb, %i0
a011dcb8:  b2 10 20 08  mov  8, %i1
a011dcbc:  10 bf ff d3  b  0xa011dc08
a011dcc0:  b4 10 20 0a  mov  0xa, %i2
a011dcc4:  b0 10 20 09  mov  9, %i0
a011dcc8:  10 bf ff fd  b  0xa011dcbc
a011dccc:  b2 10 20 08  mov  8, %i1
a011dcd0:  b0 10 20 0b  mov  0xb, %i0
a011dcd4:  b2 10 20 04  mov  4, %i1
a011dcd8:  10 bf ff cc  b  0xa011dc08
a011dcdc:  b4 10 20 0a  mov  0xa, %i2
a011dce0:  b0 10 20 09  mov  9, %i0
a011dce4:  10 bf ff fd  b  0xa011dcd8
a011dce8:  b2 10 20 04  mov  4, %i1
a011dcec:  b0 10 20 0b  mov  0xb, %i0
a011dcf0:  b2 10 20 02  mov  2, %i1
a011dcf4:  10 bf ff c5  b  0xa011dc08
a011dcf8:  b4 10 20 0a  mov  0xa, %i2
a011dcfc:  b0 10 20 09  mov  9, %i0
a011dd00:  10 bf ff fd  b  0xa011dcf4
a011dd04:  b2 10 20 02  mov  2, %i1
a011dd08:  b0 10 20 0b  mov  0xb, %i0
a011dd0c:  b2 10 20 01  mov  1, %i1
a011dd10:  10 bf ff be  b  0xa011dc08
a011dd14:  b4 10 20 0a  mov  0xa, %i2
a011dd18:  b0 10 20 09  mov  9, %i0
a011dd1c:  10 bf ff fd  b  0xa011dd10
a011dd20:  b2 10 20 01  mov  1, %i1
a011dd24:  b0 10 20 0d  mov  0xd, %i0
a011dd28:  b2 10 20 80  mov  0x80, %i1
a011dd2c:  10 bf ff c8  b  0xa011dc4c
a011dd30:  b4 10 20 05  mov  5, %i2
a011dd34:  b0 10 20 0f  mov  0xf, %i0
a011dd38:  10 bf ff fd  b  0xa011dd2c
a011dd3c:  b2 10 20 80  mov  0x80, %i1
a011dd40:  b0 10 20 0d  mov  0xd, %i0
a011dd44:  b2 10 20 40  mov  0x40, %i1
a011dd48:  10 bf ff c1  b  0xa011dc4c
a011dd4c:  b4 10 20 05  mov  5, %i2
a011dd50:  b0 10 20 0f  mov  0xf, %i0
a011dd54:  10 bf ff fd  b  0xa011dd48
a011dd58:  b2 10 20 40  mov  0x40, %i1
a011dd5c:  b0 10 20 0f  mov  0xf, %i0
a011dd60:  b2 10 20 20  mov  0x20, %i1
a011dd64:  10 bf ff ba  b  0xa011dc4c
a011dd68:  b4 10 20 05  mov  5, %i2
a011dd6c:  b0 10 20 0b  mov  0xb, %i0
a011dd70:  10 bf ff c2  b  0xa011dc78
a011dd74:  b2 10 20 08  mov  8, %i1
a011dd78:  b0 10 20 05  mov  5, %i0
a011dd7c:  10 bf ff bf  b  0xa011dc78
a011dd80:  b2 10 20 08  mov  8, %i1
a011dd84:  b0 10 20 0f  mov  0xf, %i0
a011dd88:  b2 10 20 10  mov  0x10, %i1
a011dd8c:  10 bf ff b0  b  0xa011dc4c
a011dd90:  b4 10 20 05  mov  5, %i2
a011dd94:  81 c7 e0 08  ret
a011dd98:  81 e8 00 00  restore
