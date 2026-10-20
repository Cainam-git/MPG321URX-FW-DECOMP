# leon2m FUN_a00b88e0 0xa00b88e0-0xa00b89c4 (228 bytes)
a00b88e0:  9d e3 bf 88  save  %sp, -120, %sp
a00b88e4:  90 10 20 c8  mov  0xc8, %o0
a00b88e8:  40 02 38 9a  call  0xa0146b50
a00b88ec:  92 10 20 00  clr  %o1
a00b88f0:  90 10 20 02  mov  2, %o0
a00b88f4:  40 02 38 9e  call  0xa0146b6c
a00b88f8:  92 10 20 00  clr  %o1
a00b88fc:  98 06 20 03  add  %i0, 3, %o4
a00b8900:  96 06 60 0b  add  %i1, 0xb, %o3
a00b8904:  83 2a e0 10  sll  %o3, 0x10, %g1
a00b8908:  91 2b 20 10  sll  %o4, 0x10, %o0
a00b890c:  93 30 60 10  srl  %g1, 0x10, %o1
a00b8910:  96 10 27 92  mov  0x792, %o3
a00b8914:  98 10 20 00  clr  %o4
a00b8918:  94 10 20 10  mov  0x10, %o2
a00b891c:  40 02 38 59  call  0xa0146a80
a00b8920:  91 32 20 10  srl  %o0, 0x10, %o0
a00b8924:  40 00 80 85  call  0xa00d8b38
a00b8928:  01 00 00 00  nop
a00b892c:  95 2a 20 10  sll  %o0, 0x10, %o2
a00b8930:  a0 07 bf e8  add  %fp, -24, %l0
a00b8934:  13 00 06 60  sethi  %hi(0x198000), %o1
a00b8938:  92 12 61 d8  or  %o1, 0x1d8, %o1	! 0x1981d8
a00b893c:  95 32 a0 10  srl  %o2, 0x10, %o2
a00b8940:  40 02 7b ad  call  0xa01577f4
a00b8944:  90 10 00 10  mov  %l0, %o0
a00b8948:  92 10 00 18  mov  %i0, %o1
a00b894c:  94 10 00 19  mov  %i1, %o2
a00b8950:  98 10 20 00  clr  %o4
a00b8954:  82 10 20 00  clr  %g1
a00b8958:  96 07 bf f8  add  %fp, -8, %o3
a00b895c:  9e 02 c0 01  add  %o3, %g1, %o7
a00b8960:  da 0b ff f0  ldub  [ %o7 + -16 ], %o5
a00b8964:  80 a3 60 00  cmp  %o5, 0
a00b8968:  22 80 00 08  be,a   0xa00b8988
a00b896c:  90 03 3f ff  add  %o4, -1, %o0
a00b8970:  98 03 20 01  inc  %o4
a00b8974:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b8978:  80 a0 60 0f  cmp  %g1, 0xf
a00b897c:  08 bf ff f9  bleu  0xa00b8960
a00b8980:  9e 02 c0 01  add  %o3, %g1, %o7
a00b8984:  90 03 3f ff  add  %o4, -1, %o0
a00b8988:  92 02 60 08  add  %o1, 8, %o1
a00b898c:  94 02 a0 0b  add  %o2, 0xb, %o2
a00b8990:  b3 2a 60 10  sll  %o1, 0x10, %i1
a00b8994:  b1 2a a0 10  sll  %o2, 0x10, %i0
a00b8998:  d0 2f bf e8  stb  %o0, [ %fp + -24 ]
a00b899c:  93 36 60 10  srl  %i1, 0x10, %o1
a00b89a0:  95 36 20 10  srl  %i0, 0x10, %o2
a00b89a4:  98 10 00 10  mov  %l0, %o4
a00b89a8:  90 10 20 00  clr  %o0
a00b89ac:  96 10 20 06  mov  6, %o3
a00b89b0:  7f ff a9 fd  call  0xa00a31a4
a00b89b4:  9a 10 20 00  clr  %o5
a00b89b8:  01 00 00 00  nop
a00b89bc:  81 c7 e0 08  ret
a00b89c0:  81 e8 00 00  restore
