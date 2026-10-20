# leon2s FUN_a00a88b8 0xa00a88b8-0xa00a89c0 (264 bytes)
a00a88b8:  9d e3 bf 98  save  %sp, -104, %sp
a00a88bc:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a88c0:  80 a6 60 51  cmp  %i1, 0x51
a00a88c4:  a0 10 20 01  mov  1, %l0
a00a88c8:  02 80 00 18  be  0xa00a8928
a00a88cc:  94 10 20 02  mov  2, %o2
a00a88d0:  80 a6 60 51  cmp  %i1, 0x51
a00a88d4:  14 80 00 08  bg  0xa00a88f4
a00a88d8:  80 a6 60 71  cmp  %i1, 0x71
a00a88dc:  80 a6 60 31  cmp  %i1, 0x31
a00a88e0:  02 80 00 12  be  0xa00a8928
a00a88e4:  94 10 20 00  clr  %o2
a00a88e8:  80 a6 60 41  cmp  %i1, 0x41
a00a88ec:  10 80 00 0b  b  0xa00a8918
a00a88f0:  94 10 20 01  mov  1, %o2
a00a88f4:  02 80 00 0d  be  0xa00a8928
a00a88f8:  94 10 20 03  mov  3, %o2
a00a88fc:  80 a6 60 71  cmp  %i1, 0x71
a00a8900:  34 80 00 05  bg,a   0xa00a8914
a00a8904:  80 a6 60 81  cmp  %i1, 0x81
a00a8908:  80 a6 60 61  cmp  %i1, 0x61
a00a890c:  10 80 00 03  b  0xa00a8918
a00a8910:  94 10 20 05  mov  5, %o2
a00a8914:  94 10 20 04  mov  4, %o2
a00a8918:  22 80 00 05  be,a   0xa00a892c
a00a891c:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00a8920:  94 10 20 00  clr  %o2
a00a8924:  a0 10 20 00  clr  %l0
a00a8928:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00a892c:  80 a6 a0 01  cmp  %i2, 1
a00a8930:  02 80 00 10  be  0xa00a8970
a00a8934:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00a8938:  14 80 00 07  bg  0xa00a8954
a00a893c:  80 a6 a0 02  cmp  %i2, 2
a00a8940:  80 a6 a0 00  cmp  %i2, 0
a00a8944:  02 80 00 08  be  0xa00a8964
a00a8948:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a894c:  10 80 00 1a  b  0xa00a89b4
a00a8950:  a0 10 20 00  clr  %l0
a00a8954:  02 80 00 0e  be  0xa00a898c
a00a8958:  82 0e 20 ff  and  %i0, 0xff, %g1
a00a895c:  10 80 00 16  b  0xa00a89b4
a00a8960:  a0 10 20 00  clr  %l0
a00a8964:  9b 2b 60 02  sll  %o5, 2, %o5
a00a8968:  10 80 00 05  b  0xa00a897c
a00a896c:  82 10 63 4c  or  %g1, 0x34c, %g1
a00a8970:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a8974:  9b 2b 60 02  sll  %o5, 2, %o5
a00a8978:  82 10 63 58  or  %g1, 0x358, %g1
a00a897c:  d0 00 40 0d  ld  [ %g1 + %o5 ], %o0
a00a8980:  94 0a a0 07  and  %o2, 7, %o2
a00a8984:  10 80 00 09  b  0xa00a89a8
a00a8988:  92 10 20 07  mov  7, %o1
a00a898c:  1b 2a 01 e1  sethi  %hi(0xa8078400), %o5
a00a8990:  83 28 60 02  sll  %g1, 2, %g1
a00a8994:  95 2a a0 04  sll  %o2, 4, %o2
a00a8998:  9a 13 63 58  or  %o5, 0x358, %o5
a00a899c:  d0 03 40 01  ld  [ %o5 + %g1 ], %o0
a00a89a0:  94 0a a0 70  and  %o2, 0x70, %o2
a00a89a4:  92 10 20 70  mov  0x70, %o1
a00a89a8:  7f ff f6 a0  call  0xa00a6428
a00a89ac:  b0 0c 20 01  and  %l0, 1, %i0
a00a89b0:  30 80 00 02  b,a   0xa00a89b8
a00a89b4:  b0 0c 20 01  and  %l0, 1, %i0
a00a89b8:  81 c7 e0 08  ret
a00a89bc:  81 e8 00 00  restore
