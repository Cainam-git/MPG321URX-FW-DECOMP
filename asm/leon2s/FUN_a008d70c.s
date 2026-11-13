# leon2s FUN_a008d70c 0xa008d70c-0xa008d800 (244 bytes)
a008d70c:  9d e3 bf 98  save  %sp, -104, %sp
a008d710:  15 28 02 d0  sethi  %hi(0xa00b4000), %o2
a008d714:  96 10 20 00  clr  %o3
a008d718:  98 10 20 00  clr  %o4
a008d71c:  90 12 a0 36  or  %o2, 0x36, %o0
a008d720:  83 2b 20 10  sll  %o4, 0x10, %g1
a008d724:  83 30 60 0e  srl  %g1, 0xe, %g1
a008d728:  82 00 40 08  add  %g1, %o0, %g1
a008d72c:  da 10 60 02  lduh  [ %g1 + 2 ], %o5
a008d730:  98 03 20 01  inc  %o4
a008d734:  83 2b 20 10  sll  %o4, 0x10, %g1
a008d738:  92 02 c0 0d  add  %o3, %o5, %o1
a008d73c:  83 30 60 10  srl  %g1, 0x10, %g1
a008d740:  80 a0 60 01  cmp  %g1, 1
a008d744:  08 bf ff f7  bleu  0xa008d720
a008d748:  96 10 00 09  mov  %o1, %o3
a008d74c:  d0 12 a0 36  lduh  [ %o2 + 0x36 ], %o0
a008d750:  93 2a 60 10  sll  %o1, 0x10, %o1
a008d754:  33 2a 01 f4  sethi  %hi(0xa807d000), %i1
a008d758:  93 32 60 10  srl  %o1, 0x10, %o1
a008d75c:  7f ff fe e1  call  0xa008d2e0
a008d760:  94 16 62 7a  or  %i1, 0x27a, %o2
a008d764:  03 28 02 d0  sethi  %hi(0xa00b4000), %g1
a008d768:  b4 10 60 36  or  %g1, 0x36, %i2	! 0xa00b4036
a008d76c:  96 10 20 00  clr  %o3
a008d770:  98 10 20 03  mov  3, %o4
a008d774:  83 2b 20 10  sll  %o4, 0x10, %g1
a008d778:  83 30 60 0e  srl  %g1, 0xe, %g1
a008d77c:  82 00 40 1a  add  %g1, %i2, %g1
a008d780:  da 10 60 02  lduh  [ %g1 + 2 ], %o5
a008d784:  98 03 20 01  inc  %o4
a008d788:  83 2b 20 10  sll  %o4, 0x10, %g1
a008d78c:  92 02 c0 0d  add  %o3, %o5, %o1
a008d790:  83 30 60 10  srl  %g1, 0x10, %g1
a008d794:  80 a0 60 0b  cmp  %g1, 0xb
a008d798:  08 bf ff f7  bleu  0xa008d774
a008d79c:  96 10 00 09  mov  %o1, %o3
a008d7a0:  21 2a 01 f4  sethi  %hi(0xa807d000), %l0
a008d7a4:  93 2a 60 10  sll  %o1, 0x10, %o1
a008d7a8:  d0 16 a0 0c  lduh  [ %i2 + 0xc ], %o0
a008d7ac:  93 32 60 10  srl  %o1, 0x10, %o1
a008d7b0:  7f ff fe cc  call  0xa008d2e0
a008d7b4:  94 14 22 89  or  %l0, 0x289, %o2
a008d7b8:  31 2a 01 f4  sethi  %hi(0xa807d000), %i0
a008d7bc:  d2 16 a0 3a  lduh  [ %i2 + 0x3a ], %o1
a008d7c0:  d0 16 a0 38  lduh  [ %i2 + 0x38 ], %o0
a008d7c4:  7f ff fe c7  call  0xa008d2e0
a008d7c8:  94 16 23 d1  or  %i0, 0x3d1, %o2
a008d7cc:  90 16 62 7a  or  %i1, 0x27a, %o0
a008d7d0:  92 10 20 00  clr  %o1
a008d7d4:  7f ff ff 2f  call  0xa008d490
a008d7d8:  94 10 20 02  mov  2, %o2
a008d7dc:  90 14 22 89  or  %l0, 0x289, %o0
a008d7e0:  92 10 20 03  mov  3, %o1
a008d7e4:  7f ff ff 2b  call  0xa008d490
a008d7e8:  94 10 20 0c  mov  0xc, %o2
a008d7ec:  b0 16 23 d1  or  %i0, 0x3d1, %i0
a008d7f0:  b2 10 20 0e  mov  0xe, %i1
a008d7f4:  7f ff ff 27  call  0xa008d490
a008d7f8:  95 e8 20 0f  restore  %g0, 0xf, %o2
a008d7fc:  01 00 00 00  nop
