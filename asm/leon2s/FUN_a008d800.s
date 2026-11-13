# leon2s FUN_a008d800 0xa008d800-0xa008d8d8 (216 bytes)
a008d800:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a008d804:  82 13 60 44  or  %o5, 0x44, %g1	! 0xcf011444
a008d808:  c2 00 40 00  ld  [ %g1 ], %g1
a008d80c:  80 a0 60 16  cmp  %g1, 0x16
a008d810:  12 80 00 0e  bne  0xa008d848
a008d814:  90 10 3f 84  mov  -124, %o0
a008d818:  82 13 60 40  or  %o5, 0x40, %g1
a008d81c:  c2 00 40 00  ld  [ %g1 ], %g1
a008d820:  80 a0 60 01  cmp  %g1, 1
a008d824:  12 80 00 0a  bne  0xa008d84c
a008d828:  82 13 60 44  or  %o5, 0x44, %g1
a008d82c:  03 27 c6 c1  sethi  %hi(0x9f1b0400), %g1
a008d830:  c2 08 62 06  ldub  [ %g1 + 0x206 ], %g1	! 0x9f1b0606
a008d834:  82 18 60 01  xor  %g1, 1, %g1
a008d838:  80 a0 00 01  cmp  %g0, %g1
a008d83c:  82 10 3f 81  mov  -127, %g1
a008d840:  10 80 00 24  b  0xa008d8d0
a008d844:  90 60 60 00  subx  %g1, 0, %o0
a008d848:  82 13 60 44  or  %o5, 0x44, %g1
a008d84c:  c2 00 40 00  ld  [ %g1 ], %g1
a008d850:  80 a0 60 1e  cmp  %g1, 0x1e
a008d854:  32 80 00 09  bne,a   0xa008d878
a008d858:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a008d85c:  82 13 60 40  or  %o5, 0x40, %g1	! 0xcf011440
a008d860:  c2 00 40 00  ld  [ %g1 ], %g1
a008d864:  80 a0 60 01  cmp  %g1, 1
a008d868:  12 80 00 04  bne  0xa008d878
a008d86c:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a008d870:  10 80 00 18  b  0xa008d8d0
a008d874:  90 10 3f 82  mov  -126, %o0
a008d878:  82 13 60 44  or  %o5, 0x44, %g1
a008d87c:  c2 00 40 00  ld  [ %g1 ], %g1
a008d880:  80 a0 60 1f  cmp  %g1, 0x1f
a008d884:  32 80 00 09  bne,a   0xa008d8a8
a008d888:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a008d88c:  82 13 60 40  or  %o5, 0x40, %g1	! 0xcf011440
a008d890:  c2 00 40 00  ld  [ %g1 ], %g1
a008d894:  80 a0 60 01  cmp  %g1, 1
a008d898:  12 80 00 04  bne  0xa008d8a8
a008d89c:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a008d8a0:  10 80 00 0c  b  0xa008d8d0
a008d8a4:  90 10 3f 83  mov  -125, %o0
a008d8a8:  82 13 60 44  or  %o5, 0x44, %g1
a008d8ac:  c2 00 40 00  ld  [ %g1 ], %g1
a008d8b0:  80 a0 60 17  cmp  %g1, 0x17
a008d8b4:  12 80 00 07  bne  0xa008d8d0
a008d8b8:  82 13 60 40  or  %o5, 0x40, %g1
a008d8bc:  c2 00 40 00  ld  [ %g1 ], %g1
a008d8c0:  80 a0 60 01  cmp  %g1, 1
a008d8c4:  12 80 00 03  bne  0xa008d8d0
a008d8c8:  01 00 00 00  nop
a008d8cc:  90 10 3f 84  mov  -124, %o0	! 0xffffff84
a008d8d0:  81 c3 e0 08  retl
a008d8d4:  90 0a 20 ff  and  %o0, 0xff, %o0
