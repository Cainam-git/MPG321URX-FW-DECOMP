# leon2m FUN_a00a87cc 0xa00a87cc-0xa00a89e4 (536 bytes)
a00a87cc:  9d e3 bf 90  save  %sp, -112, %sp
a00a87d0:  90 10 21 11  mov  0x111, %o0
a00a87d4:  40 02 78 df  call  0xa0146b50
a00a87d8:  92 10 20 00  clr  %o1
a00a87dc:  90 10 20 00  clr  %o0
a00a87e0:  40 02 78 e3  call  0xa0146b6c
a00a87e4:  92 10 20 00  clr  %o1
a00a87e8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a87ec:  80 a6 20 00  cmp  %i0, 0
a00a87f0:  12 80 00 16  bne  0xa00a8848
a00a87f4:  80 a6 20 01  cmp  %i0, 1
a00a87f8:  a0 10 20 00  clr  %l0
a00a87fc:  23 00 06 34  sethi  %hi(0x18d000), %l1
a00a8800:  92 10 00 18  mov  %i0, %o1
a00a8804:  7f ff ec 10  call  0xa00a3844
a00a8808:  90 14 63 d4  or  %l1, 0x3d4, %o0
a00a880c:  98 10 00 08  mov  %o0, %o4
a00a8810:  94 06 00 18  add  %i0, %i0, %o2
a00a8814:  94 02 a0 06  add  %o2, 6, %o2
a00a8818:  90 10 20 00  clr  %o0
a00a881c:  92 10 20 2a  mov  0x2a, %o1
a00a8820:  96 10 20 01  mov  1, %o3
a00a8824:  9a 10 20 00  clr  %o5
a00a8828:  7f ff ea 5f  call  0xa00a31a4
a00a882c:  a0 04 20 01  inc  %l0
a00a8830:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00a8834:  80 a6 20 06  cmp  %i0, 6
a00a8838:  08 bf ff f3  bleu  0xa00a8804
a00a883c:  92 10 00 18  mov  %i0, %o1
a00a8840:  10 80 00 5e  b  0xa00a89b8
a00a8844:  a2 10 20 28  mov  0x28, %l1
a00a8848:  02 80 00 15  be  0xa00a889c
a00a884c:  80 a6 20 02  cmp  %i0, 2
a00a8850:  02 80 00 43  be  0xa00a895c
a00a8854:  80 a6 20 03  cmp  %i0, 3
a00a8858:  02 80 00 29  be  0xa00a88fc
a00a885c:  80 a6 20 04  cmp  %i0, 4
a00a8860:  32 80 00 56  bne,a   0xa00a89b8
a00a8864:  a2 10 20 28  mov  0x28, %l1
a00a8868:  21 00 06 34  sethi  %hi(0x18d000), %l0
a00a886c:  90 14 23 d4  or  %l0, 0x3d4, %o0	! 0x18d3d4
a00a8870:  7f ff eb f5  call  0xa00a3844
a00a8874:  92 10 20 1c  mov  0x1c, %o1
a00a8878:  98 10 00 08  mov  %o0, %o4
a00a887c:  90 10 20 00  clr  %o0
a00a8880:  92 10 20 2a  mov  0x2a, %o1
a00a8884:  94 10 20 06  mov  6, %o2
a00a8888:  96 10 20 01  mov  1, %o3
a00a888c:  7f ff ea 46  call  0xa00a31a4
a00a8890:  9a 10 20 00  clr  %o5
a00a8894:  10 80 00 49  b  0xa00a89b8
a00a8898:  a2 10 20 28  mov  0x28, %l1
a00a889c:  b0 10 20 00  clr  %i0
a00a88a0:  a0 10 20 00  clr  %l0
a00a88a4:  23 00 06 34  sethi  %hi(0x18d000), %l1
a00a88a8:  96 0e 20 ff  and  %i0, 0xff, %o3
a00a88ac:  90 02 e0 07  add  %o3, 7, %o0
a00a88b0:  93 2a 20 10  sll  %o0, 0x10, %o1
a00a88b4:  93 32 60 10  srl  %o1, 0x10, %o1
a00a88b8:  7f ff eb e3  call  0xa00a3844
a00a88bc:  90 14 63 d4  or  %l1, 0x3d4, %o0
a00a88c0:  82 04 00 10  add  %l0, %l0, %g1
a00a88c4:  98 10 00 08  mov  %o0, %o4
a00a88c8:  94 00 60 06  add  %g1, 6, %o2
a00a88cc:  90 10 20 00  clr  %o0
a00a88d0:  92 10 20 2a  mov  0x2a, %o1
a00a88d4:  96 10 20 01  mov  1, %o3
a00a88d8:  9a 10 20 00  clr  %o5
a00a88dc:  7f ff ea 32  call  0xa00a31a4
a00a88e0:  b0 06 20 01  inc  %i0
a00a88e4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a88e8:  80 a4 20 06  cmp  %l0, 6
a00a88ec:  08 bf ff f0  bleu  0xa00a88ac
a00a88f0:  96 0e 20 ff  and  %i0, 0xff, %o3
a00a88f4:  10 80 00 31  b  0xa00a89b8
a00a88f8:  a2 10 20 28  mov  0x28, %l1
a00a88fc:  a2 10 20 00  clr  %l1
a00a8900:  a0 10 20 00  clr  %l0
a00a8904:  31 00 06 34  sethi  %hi(0x18d000), %i0
a00a8908:  96 0c 60 ff  and  %l1, 0xff, %o3
a00a890c:  90 02 e0 15  add  %o3, 0x15, %o0
a00a8910:  93 2a 20 10  sll  %o0, 0x10, %o1
a00a8914:  93 32 60 10  srl  %o1, 0x10, %o1
a00a8918:  7f ff eb cb  call  0xa00a3844
a00a891c:  90 16 23 d4  or  %i0, 0x3d4, %o0
a00a8920:  82 04 00 10  add  %l0, %l0, %g1
a00a8924:  98 10 00 08  mov  %o0, %o4
a00a8928:  94 00 60 06  add  %g1, 6, %o2
a00a892c:  90 10 20 00  clr  %o0
a00a8930:  92 10 20 2a  mov  0x2a, %o1
a00a8934:  96 10 20 01  mov  1, %o3
a00a8938:  9a 10 20 00  clr  %o5
a00a893c:  7f ff ea 1a  call  0xa00a31a4
a00a8940:  a2 04 60 01  inc  %l1
a00a8944:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a8948:  80 a4 20 06  cmp  %l0, 6
a00a894c:  08 bf ff f0  bleu  0xa00a890c
a00a8950:  96 0c 60 ff  and  %l1, 0xff, %o3
a00a8954:  10 80 00 19  b  0xa00a89b8
a00a8958:  a2 10 20 28  mov  0x28, %l1
a00a895c:  b0 10 20 00  clr  %i0
a00a8960:  a0 10 20 00  clr  %l0
a00a8964:  23 00 06 34  sethi  %hi(0x18d000), %l1
a00a8968:  94 0e 20 ff  and  %i0, 0xff, %o2
a00a896c:  9e 02 a0 0e  add  %o2, 0xe, %o7
a00a8970:  99 2b e0 10  sll  %o7, 0x10, %o4
a00a8974:  93 33 20 10  srl  %o4, 0x10, %o1
a00a8978:  7f ff eb b3  call  0xa00a3844
a00a897c:  90 14 63 d4  or  %l1, 0x3d4, %o0
a00a8980:  9a 04 00 10  add  %l0, %l0, %o5
a00a8984:  98 10 00 08  mov  %o0, %o4
a00a8988:  94 03 60 06  add  %o5, 6, %o2
a00a898c:  90 10 20 00  clr  %o0
a00a8990:  92 10 20 2a  mov  0x2a, %o1
a00a8994:  96 10 20 01  mov  1, %o3
a00a8998:  9a 10 20 00  clr  %o5
a00a899c:  7f ff ea 02  call  0xa00a31a4
a00a89a0:  b0 06 20 01  inc  %i0
a00a89a4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a89a8:  80 a4 20 06  cmp  %l0, 6
a00a89ac:  08 bf ff f0  bleu  0xa00a896c
a00a89b0:  94 0e 20 ff  and  %i0, 0xff, %o2
a00a89b4:  a2 10 20 28  mov  0x28, %l1
a00a89b8:  e2 23 a0 5c  st  %l1, [ %sp + 0x5c ]
a00a89bc:  90 10 20 01  mov  1, %o0
a00a89c0:  92 10 20 01  mov  1, %o1
a00a89c4:  94 10 27 92  mov  0x792, %o2
a00a89c8:  96 10 20 2d  mov  0x2d, %o3
a00a89cc:  98 10 20 15  mov  0x15, %o4
a00a89d0:  40 00 2a 45  call  0xa00b32e4
a00a89d4:  9a 10 20 02  mov  2, %o5
a00a89d8:  01 00 00 00  nop
a00a89dc:  81 c7 e0 08  ret
a00a89e0:  81 e8 00 00  restore
