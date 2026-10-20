# leon2s FUN_a008e7c0 0xa008e7c0-0xa008e940 (384 bytes)
a008e7c0:  94 0a a0 ff  and  %o2, 0xff, %o2
a008e7c4:  80 a2 a0 01  cmp  %o2, 1
a008e7c8:  32 80 00 4a  bne,a   0xa008e8f0
a008e7cc:  90 0a 20 ff  and  %o0, 0xff, %o0
a008e7d0:  92 0a 60 ff  and  %o1, 0xff, %o1
a008e7d4:  82 1a 60 31  xor  %o1, 0x31, %g1
a008e7d8:  80 a0 00 01  cmp  %g0, %g1
a008e7dc:  9a 60 3f ff  subx  %g0, -1, %o5
a008e7e0:  82 1a 60 41  xor  %o1, 0x41, %g1
a008e7e4:  80 a0 00 01  cmp  %g0, %g1
a008e7e8:  82 60 3f ff  subx  %g0, -1, %g1
a008e7ec:  80 93 40 01  orcc  %o5, %g1, %g0
a008e7f0:  12 80 00 0b  bne  0xa008e81c
a008e7f4:  90 0a 20 ff  and  %o0, 0xff, %o0
a008e7f8:  82 1a 60 51  xor  %o1, 0x51, %g1
a008e7fc:  80 a0 00 01  cmp  %g0, %g1
a008e800:  9a 60 3f ff  subx  %g0, -1, %o5
a008e804:  82 1a 60 61  xor  %o1, 0x61, %g1
a008e808:  80 a0 00 01  cmp  %g0, %g1
a008e80c:  82 60 3f ff  subx  %g0, -1, %g1
a008e810:  80 93 40 01  orcc  %o5, %g1, %g0
a008e814:  02 80 00 37  be  0xa008e8f0
a008e818:  01 00 00 00  nop
a008e81c:  80 a2 20 00  cmp  %o0, 0
a008e820:  12 80 00 07  bne  0xa008e83c
a008e824:  80 a2 20 01  cmp  %o0, 1
a008e828:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a008e82c:  9a 13 62 b4  or  %o5, 0x2b4, %o5	! 0xcf0116b4
a008e830:  c2 03 40 00  ld  [ %o5 ], %g1
a008e834:  10 80 00 0b  b  0xa008e860
a008e838:  82 10 60 01  or  %g1, 1, %g1
a008e83c:  12 80 00 06  bne  0xa008e854
a008e840:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a008e844:  9a 13 62 b4  or  %o5, 0x2b4, %o5	! 0xcf0116b4
a008e848:  c2 03 40 00  ld  [ %o5 ], %g1
a008e84c:  10 80 00 05  b  0xa008e860
a008e850:  82 10 60 02  or  %g1, 2, %g1
a008e854:  9a 13 62 b4  or  %o5, 0x2b4, %o5
a008e858:  c2 03 40 00  ld  [ %o5 ], %g1
a008e85c:  82 08 60 fc  and  %g1, 0xfc, %g1
a008e860:  c2 23 40 00  st  %g1, [ %o5 ]
a008e864:  80 a2 60 51  cmp  %o1, 0x51
a008e868:  02 80 00 06  be  0xa008e880
a008e86c:  80 a2 60 61  cmp  %o1, 0x61
a008e870:  02 80 00 12  be  0xa008e8b8
a008e874:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a008e878:  10 80 00 2d  b  0xa008e92c
a008e87c:  9a 13 62 b4  or  %o5, 0x2b4, %o5	! 0xcf0116b4
a008e880:  80 a2 20 00  cmp  %o0, 0
a008e884:  12 80 00 07  bne  0xa008e8a0
a008e888:  80 a2 20 01  cmp  %o0, 1
a008e88c:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a008e890:  9a 13 62 b4  or  %o5, 0x2b4, %o5	! 0xcf0116b4
a008e894:  c2 03 40 00  ld  [ %o5 ], %g1
a008e898:  10 80 00 27  b  0xa008e934
a008e89c:  82 08 60 fb  and  %g1, 0xfb, %g1
a008e8a0:  12 80 00 22  bne  0xa008e928
a008e8a4:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a008e8a8:  9a 13 62 b4  or  %o5, 0x2b4, %o5	! 0xcf0116b4
a008e8ac:  c2 03 40 00  ld  [ %o5 ], %g1
a008e8b0:  10 80 00 21  b  0xa008e934
a008e8b4:  82 08 60 f7  and  %g1, 0xf7, %g1
a008e8b8:  80 a2 20 00  cmp  %o0, 0
a008e8bc:  12 80 00 07  bne  0xa008e8d8
a008e8c0:  80 a2 20 01  cmp  %o0, 1
a008e8c4:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a008e8c8:  9a 13 62 b4  or  %o5, 0x2b4, %o5	! 0xcf0116b4
a008e8cc:  c2 03 40 00  ld  [ %o5 ], %g1
a008e8d0:  10 80 00 19  b  0xa008e934
a008e8d4:  82 10 60 04  or  %g1, 4, %g1
a008e8d8:  12 80 00 14  bne  0xa008e928
a008e8dc:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a008e8e0:  9a 13 62 b4  or  %o5, 0x2b4, %o5	! 0xcf0116b4
a008e8e4:  c2 03 40 00  ld  [ %o5 ], %g1
a008e8e8:  10 80 00 13  b  0xa008e934
a008e8ec:  82 10 60 08  or  %g1, 8, %g1
a008e8f0:  80 a2 20 00  cmp  %o0, 0
a008e8f4:  12 80 00 07  bne  0xa008e910
a008e8f8:  80 a2 20 01  cmp  %o0, 1
a008e8fc:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a008e900:  9a 13 62 b4  or  %o5, 0x2b4, %o5	! 0xcf0116b4
a008e904:  c2 03 40 00  ld  [ %o5 ], %g1
a008e908:  10 80 00 0b  b  0xa008e934
a008e90c:  82 08 60 fe  and  %g1, 0xfe, %g1
a008e910:  12 80 00 06  bne  0xa008e928
a008e914:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a008e918:  9a 13 62 b4  or  %o5, 0x2b4, %o5	! 0xcf0116b4
a008e91c:  c2 03 40 00  ld  [ %o5 ], %g1
a008e920:  10 80 00 05  b  0xa008e934
a008e924:  82 08 60 fd  and  %g1, 0xfd, %g1
a008e928:  9a 13 62 b4  or  %o5, 0x2b4, %o5
a008e92c:  c2 03 40 00  ld  [ %o5 ], %g1
a008e930:  82 08 60 fc  and  %g1, 0xfc, %g1
a008e934:  c2 23 40 00  st  %g1, [ %o5 ]
a008e938:  81 c3 e0 08  retl
a008e93c:  01 00 00 00  nop
