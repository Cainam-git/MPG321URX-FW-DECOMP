# leon2s FUN_a00c8824 0xa00c8824-0xa00c89b8 (404 bytes)
a00c8824:  9d e3 bd 18  save  %sp, -744, %sp
a00c8828:  83 2e a0 10  sll  %i2, 0x10, %g1
a00c882c:  a1 30 60 10  srl  %g1, 0x10, %l0
a00c8830:  80 a4 22 7b  cmp  %l0, 0x27b
a00c8834:  08 80 00 07  bleu  0xa00c8850
a00c8838:  a6 0e 20 ff  and  %i0, 0xff, %l3
a00c883c:  11 27 c7 07  sethi  %hi(0x9f1c1c00), %o0
a00c8840:  40 3a ea 01  call  0xa0f83044
a00c8844:  90 12 23 f8  or  %o0, 0x3f8, %o0	! 0x9f1c1ff8
a00c8848:  10 80 00 5a  b  0xa00c89b0
a00c884c:  b0 10 20 0b  mov  0xb, %i0
a00c8850:  96 10 00 10  mov  %l0, %o3
a00c8854:  92 10 20 74  mov  0x74, %o1
a00c8858:  94 10 20 43  mov  0x43, %o2
a00c885c:  7f ff fd fb  call  0xa00c8048
a00c8860:  90 10 00 13  mov  %l3, %o0
a00c8864:  92 07 bd 78  add  %fp, -648, %o1
a00c8868:  94 10 00 10  mov  %l0, %o2
a00c886c:  7f ff fe 63  call  0xa00c81f8
a00c8870:  90 10 00 13  mov  %l3, %o0
a00c8874:  a8 10 00 08  mov  %o0, %l4
a00c8878:  90 10 20 02  mov  2, %o0
a00c887c:  92 10 20 88  mov  0x88, %o1
a00c8880:  94 10 20 40  mov  0x40, %o2
a00c8884:  40 3b b7 cd  call  0xa0fb67b8
a00c8888:  96 10 20 01  mov  1, %o3
a00c888c:  a4 0e 60 ff  and  %i1, 0xff, %l2
a00c8890:  90 10 00 12  mov  %l2, %o0
a00c8894:  92 10 20 37  mov  0x37, %o1
a00c8898:  94 10 20 10  mov  0x10, %o2
a00c889c:  40 3b b7 c7  call  0xa0fb67b8
a00c88a0:  96 10 20 00  clr  %o3
a00c88a4:  96 10 20 01  mov  1, %o3
a00c88a8:  90 10 00 12  mov  %l2, %o0
a00c88ac:  92 10 20 37  mov  0x37, %o1
a00c88b0:  40 3b b7 c2  call  0xa0fb67b8
a00c88b4:  94 10 20 10  mov  0x10, %o2
a00c88b8:  15 00 00 10  sethi  %hi(0x4000), %o2
a00c88bc:  90 10 00 13  mov  %l3, %o0
a00c88c0:  94 12 a0 05  or  %o2, 5, %o2
a00c88c4:  7f ff ff c9  call  0xa00c87e8
a00c88c8:  92 10 20 0b  mov  0xb, %o1
a00c88cc:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00c88d0:  40 3a e9 dd  call  0xa0f83044
a00c88d4:  90 12 20 20  or  %o0, 0x20, %o0	! 0x9f1c2020
a00c88d8:  80 a4 20 00  cmp  %l0, 0
a00c88dc:  02 80 00 14  be  0xa00c892c
a00c88e0:  a2 10 20 00  clr  %l1
a00c88e4:  83 2c 60 10  sll  %l1, 0x10, %g1
a00c88e8:  83 30 60 10  srl  %g1, 0x10, %g1
a00c88ec:  a0 07 bf f8  add  %fp, -8, %l0
a00c88f0:  a0 04 00 01  add  %l0, %g1, %l0
a00c88f4:  90 10 00 12  mov  %l2, %o0
a00c88f8:  92 10 20 38  mov  0x38, %o1
a00c88fc:  40 3b b7 32  call  0xa0fb65c4
a00c8900:  d4 0c 3d 80  ldub  [ %l0 + -640 ], %o2
a00c8904:  90 10 00 13  mov  %l3, %o0
a00c8908:  d4 0c 3d 80  ldub  [ %l0 + -640 ], %o2
a00c890c:  7f ff fb 52  call  0xa00c7654
a00c8910:  92 10 20 01  mov  1, %o1
a00c8914:  98 04 60 01  add  %l1, 1, %o4
a00c8918:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00c891c:  83 2e a0 10  sll  %i2, 0x10, %g1
a00c8920:  80 a0 40 0d  cmp  %g1, %o5
a00c8924:  18 bf ff f0  bgu  0xa00c88e4
a00c8928:  a2 10 00 0c  mov  %o4, %l1
a00c892c:  a2 10 20 00  clr  %l1
a00c8930:  94 04 60 10  add  %l1, 0x10, %o2
a00c8934:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c8938:  95 2a a0 10  sll  %o2, 0x10, %o2
a00c893c:  95 32 a0 10  srl  %o2, 0x10, %o2
a00c8940:  92 10 20 00  clr  %o1
a00c8944:  40 3b bd a5  call  0xa0fb7fd8
a00c8948:  90 10 00 10  mov  %l0, %o0
a00c894c:  94 0a 20 ff  and  %o0, 0xff, %o2
a00c8950:  90 10 00 10  mov  %l0, %o0
a00c8954:  7f ff fb 40  call  0xa00c7654
a00c8958:  92 10 20 01  mov  1, %o1
a00c895c:  9a 04 60 01  add  %l1, 1, %o5
a00c8960:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c8964:  83 30 60 10  srl  %g1, 0x10, %g1
a00c8968:  80 a0 60 04  cmp  %g1, 4
a00c896c:  08 bf ff f1  bleu  0xa00c8930
a00c8970:  a2 10 00 0d  mov  %o5, %l1
a00c8974:  90 10 00 10  mov  %l0, %o0
a00c8978:  92 10 20 00  clr  %o1
a00c897c:  7f ff ff 9b  call  0xa00c87e8
a00c8980:  94 10 20 00  clr  %o2
a00c8984:  90 0e 60 ff  and  %i1, 0xff, %o0
a00c8988:  92 10 20 37  mov  0x37, %o1
a00c898c:  94 10 20 10  mov  0x10, %o2
a00c8990:  40 3b b7 8a  call  0xa0fb67b8
a00c8994:  96 10 20 00  clr  %o3
a00c8998:  90 10 20 02  mov  2, %o0
a00c899c:  92 10 20 88  mov  0x88, %o1
a00c89a0:  94 10 20 40  mov  0x40, %o2
a00c89a4:  40 3b b7 85  call  0xa0fb67b8
a00c89a8:  96 10 20 00  clr  %o3
a00c89ac:  b0 0d 20 ff  and  %l4, 0xff, %i0
a00c89b0:  81 c7 e0 08  ret
a00c89b4:  81 e8 00 00  restore
