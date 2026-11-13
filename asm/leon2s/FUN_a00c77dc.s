# leon2s FUN_a00c77dc 0xa00c77dc-0xa00c79c8 (492 bytes)
a00c77dc:  9d e3 bf 98  save  %sp, -104, %sp
a00c77e0:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00c77e4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c77e8:  90 10 00 18  mov  %i0, %o0
a00c77ec:  92 10 20 0c  mov  0xc, %o1
a00c77f0:  94 10 20 18  mov  0x18, %o2
a00c77f4:  c0 28 61 b8  clrb  [ %g1 + 0x1b8 ]
a00c77f8:  40 3b c1 ba  call  0xa0fb7ee0
a00c77fc:  a2 10 61 b8  or  %g1, 0x1b8, %l1
a00c7800:  90 10 00 18  mov  %i0, %o0
a00c7804:  a0 10 20 00  clr  %l0
a00c7808:  92 10 20 0c  mov  0xc, %o1
a00c780c:  40 3b c1 b5  call  0xa0fb7ee0
a00c7810:  94 10 20 10  mov  0x10, %o2
a00c7814:  25 27 c7 07  sethi  %hi(0x9f1c1c00), %l2
a00c7818:  82 0c 20 ff  and  %l0, 0xff, %g1
a00c781c:  9a 14 a2 a8  or  %l2, 0x2a8, %o5
a00c7820:  d4 0b 40 01  ldub  [ %o5 + %g1 ], %o2
a00c7824:  90 10 00 18  mov  %i0, %o0
a00c7828:  40 3b c1 ae  call  0xa0fb7ee0
a00c782c:  92 10 20 0d  mov  0xd, %o1
a00c7830:  a0 04 20 01  inc  %l0
a00c7834:  82 0c 20 ff  and  %l0, 0xff, %g1
a00c7838:  80 a0 60 1f  cmp  %g1, 0x1f
a00c783c:  28 bf ff f8  bleu,a   0xa00c781c
a00c7840:  25 27 c7 07  sethi  %hi(0x9f1c1c00), %l2
a00c7844:  90 10 00 18  mov  %i0, %o0
a00c7848:  92 10 20 0a  mov  0xa, %o1
a00c784c:  40 3b c1 a5  call  0xa0fb7ee0
a00c7850:  94 10 20 42  mov  0x42, %o2
a00c7854:  10 80 00 05  b  0xa00c7868
a00c7858:  a0 10 3f ff  mov  -1, %l0
a00c785c:  80 8c 20 ff  btst  0xff, %l0
a00c7860:  02 80 00 09  be  0xa00c7884
a00c7864:  90 10 00 18  mov  %i0, %o0
a00c7868:  90 10 00 18  mov  %i0, %o0
a00c786c:  40 3b c1 cd  call  0xa0fb7fa0
a00c7870:  92 10 20 0a  mov  0xa, %o1
a00c7874:  80 8a 20 02  btst  2, %o0
a00c7878:  12 bf ff f9  bne  0xa00c785c
a00c787c:  a0 04 3f ff  add  %l0, -1, %l0
a00c7880:  90 10 00 18  mov  %i0, %o0
a00c7884:  92 10 20 0c  mov  0xc, %o1
a00c7888:  40 3b c1 96  call  0xa0fb7ee0
a00c788c:  94 10 20 28  mov  0x28, %o2
a00c7890:  90 10 00 18  mov  %i0, %o0
a00c7894:  92 10 20 0c  mov  0xc, %o1
a00c7898:  40 3b c1 92  call  0xa0fb7ee0
a00c789c:  94 10 20 20  mov  0x20, %o2
a00c78a0:  a0 10 20 00  clr  %l0
a00c78a4:  90 10 00 18  mov  %i0, %o0
a00c78a8:  40 3b c1 be  call  0xa0fb7fa0
a00c78ac:  92 10 20 0d  mov  0xd, %o1
a00c78b0:  03 27 c7 07  sethi  %hi(0x9f1c1c00), %g1
a00c78b4:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00c78b8:  82 10 62 48  or  %g1, 0x248, %g1
a00c78bc:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a00c78c0:  90 1a 00 01  xor  %o0, %g1, %o0
a00c78c4:  a0 04 20 01  inc  %l0
a00c78c8:  9a 04 40 0d  add  %l1, %o5, %o5
a00c78cc:  82 0c 20 ff  and  %l0, 0xff, %g1
a00c78d0:  80 a0 60 5e  cmp  %g1, 0x5e
a00c78d4:  08 bf ff f4  bleu  0xa00c78a4
a00c78d8:  d0 2b 60 21  stb  %o0, [ %o5 + 0x21 ]
a00c78dc:  90 10 00 18  mov  %i0, %o0
a00c78e0:  92 10 20 0c  mov  0xc, %o1
a00c78e4:  40 3b c1 7f  call  0xa0fb7ee0
a00c78e8:  94 10 20 18  mov  0x18, %o2
a00c78ec:  90 10 00 18  mov  %i0, %o0
a00c78f0:  92 10 20 0c  mov  0xc, %o1
a00c78f4:  40 3b c1 7b  call  0xa0fb7ee0
a00c78f8:  94 10 20 10  mov  0x10, %o2
a00c78fc:  a0 10 20 00  clr  %l0
a00c7900:  82 0c 20 ff  and  %l0, 0xff, %g1
a00c7904:  82 04 40 01  add  %l1, %g1, %g1
a00c7908:  d4 08 60 21  ldub  [ %g1 + 0x21 ], %o2
a00c790c:  90 10 00 18  mov  %i0, %o0
a00c7910:  40 3b c1 74  call  0xa0fb7ee0
a00c7914:  92 10 20 0d  mov  0xd, %o1
a00c7918:  a0 04 20 01  inc  %l0
a00c791c:  82 0c 20 ff  and  %l0, 0xff, %g1
a00c7920:  80 a0 60 5e  cmp  %g1, 0x5e
a00c7924:  08 bf ff f9  bleu  0xa00c7908
a00c7928:  82 04 40 01  add  %l1, %g1, %g1
a00c792c:  90 10 00 18  mov  %i0, %o0
a00c7930:  92 10 20 0a  mov  0xa, %o1
a00c7934:  40 3b c1 6b  call  0xa0fb7ee0
a00c7938:  94 10 20 44  mov  0x44, %o2
a00c793c:  10 80 00 05  b  0xa00c7950
a00c7940:  a0 10 3f ff  mov  -1, %l0
a00c7944:  80 8c 20 ff  btst  0xff, %l0
a00c7948:  02 80 00 09  be  0xa00c796c
a00c794c:  90 10 00 18  mov  %i0, %o0
a00c7950:  90 10 00 18  mov  %i0, %o0
a00c7954:  40 3b c1 93  call  0xa0fb7fa0
a00c7958:  92 10 20 0a  mov  0xa, %o1
a00c795c:  80 8a 20 04  btst  4, %o0
a00c7960:  12 bf ff f9  bne  0xa00c7944
a00c7964:  a0 04 3f ff  add  %l0, -1, %l0
a00c7968:  90 10 00 18  mov  %i0, %o0
a00c796c:  92 10 20 0c  mov  0xc, %o1
a00c7970:  40 3b c1 5c  call  0xa0fb7ee0
a00c7974:  94 10 20 28  mov  0x28, %o2
a00c7978:  90 10 00 18  mov  %i0, %o0
a00c797c:  92 10 20 0c  mov  0xc, %o1
a00c7980:  40 3b c1 58  call  0xa0fb7ee0
a00c7984:  94 10 20 20  mov  0x20, %o2
a00c7988:  a0 10 20 00  clr  %l0
a00c798c:  90 10 00 18  mov  %i0, %o0
a00c7990:  40 3b c1 84  call  0xa0fb7fa0
a00c7994:  92 10 20 0d  mov  0xd, %o1
a00c7998:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00c799c:  82 14 a2 a8  or  %l2, 0x2a8, %g1
a00c79a0:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a00c79a4:  90 1a 00 01  xor  %o0, %g1, %o0
a00c79a8:  a0 04 20 01  inc  %l0
a00c79ac:  9a 04 40 0d  add  %l1, %o5, %o5
a00c79b0:  82 0c 20 ff  and  %l0, 0xff, %g1
a00c79b4:  80 a0 60 1f  cmp  %g1, 0x1f
a00c79b8:  08 bf ff f5  bleu  0xa00c798c
a00c79bc:  d0 2b 60 01  stb  %o0, [ %o5 + 1 ]
a00c79c0:  81 c7 e0 08  ret
a00c79c4:  81 e8 00 00  restore
