# leon2m FUN_a00aa83c 0xa00aa83c-0xa00aa9d8 (412 bytes)
a00aa83c:  9d e3 bf 90  save  %sp, -112, %sp
a00aa840:  67 ff 8e 99  call  0x4008e2a4
a00aa844:  a2 10 20 05  mov  5, %l1
a00aa848:  a0 10 20 05  mov  5, %l0
a00aa84c:  94 10 00 10  mov  %l0, %o2
a00aa850:  90 10 20 00  clr  %o0
a00aa854:  92 10 20 13  mov  0x13, %o1
a00aa858:  96 10 20 13  mov  0x13, %o3
a00aa85c:  98 10 20 00  clr  %o4
a00aa860:  40 02 70 b0  call  0xa0146b20
a00aa864:  9a 10 20 00  clr  %o5
a00aa868:  92 10 00 10  mov  %l0, %o1
a00aa86c:  90 10 20 13  mov  0x13, %o0
a00aa870:  94 10 20 13  mov  0x13, %o2
a00aa874:  96 10 27 92  mov  0x792, %o3
a00aa878:  98 10 20 00  clr  %o4
a00aa87c:  40 02 70 81  call  0xa0146a80
a00aa880:  a2 04 60 01  inc  %l1
a00aa884:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00aa888:  80 a4 20 14  cmp  %l0, 0x14
a00aa88c:  08 bf ff f1  bleu  0xa00aa850
a00aa890:  94 10 00 10  mov  %l0, %o2
a00aa894:  96 10 20 02  mov  2, %o3
a00aa898:  98 10 20 00  clr  %o4
a00aa89c:  9a 10 20 00  clr  %o5
a00aa8a0:  90 10 20 00  clr  %o0
a00aa8a4:  92 10 20 1c  mov  0x1c, %o1
a00aa8a8:  40 02 70 9e  call  0xa0146b20
a00aa8ac:  94 10 20 15  mov  0x15, %o2
a00aa8b0:  94 10 20 00  clr  %o2
a00aa8b4:  90 10 20 05  mov  5, %o0
a00aa8b8:  40 02 70 e2  call  0xa0146c40
a00aa8bc:  92 10 20 00  clr  %o1
a00aa8c0:  90 10 20 92  mov  0x92, %o0
a00aa8c4:  40 02 70 a3  call  0xa0146b50
a00aa8c8:  92 10 20 00  clr  %o1
a00aa8cc:  90 10 20 00  clr  %o0
a00aa8d0:  40 02 70 a7  call  0xa0146b6c
a00aa8d4:  92 10 20 00  clr  %o1
a00aa8d8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00aa8dc:  80 a0 00 18  cmp  %g0, %i0
a00aa8e0:  90 40 3f ff  addx  %g0, -1, %o0
a00aa8e4:  82 0a 20 06  and  %o0, 6, %g1
a00aa8e8:  a6 80 60 01  addcc  %g1, 1, %l3
a00aa8ec:  02 80 00 2f  be  0xa00aa9a8
a00aa8f0:  a4 10 20 00  clr  %l2
a00aa8f4:  93 2e 20 03  sll  %i0, 3, %o1
a00aa8f8:  b0 22 40 18  sub  %o1, %i0, %i0
a00aa8fc:  a0 10 20 00  clr  %l0
a00aa900:  2b 2a 00 b4  sethi  %hi(0xa802d000), %l5
a00aa904:  10 80 00 1b  b  0xa00aa970
a00aa908:  29 00 06 17  sethi  %hi(0x185c00), %l4
a00aa90c:  94 04 00 18  add  %l0, %i0, %o2
a00aa910:  97 2a a0 03  sll  %o2, 3, %o3
a00aa914:  92 22 c0 0a  sub  %o3, %o2, %o1
a00aa918:  91 2a 60 02  sll  %o1, 2, %o0
a00aa91c:  82 15 62 90  or  %l5, 0x290, %g1
a00aa920:  9e 02 00 0a  add  %o0, %o2, %o7
a00aa924:  e0 08 60 08  ldub  [ %g1 + 8 ], %l0
a00aa928:  9a 03 c0 10  add  %o7, %l0, %o5
a00aa92c:  99 2b 60 10  sll  %o5, 0x10, %o4
a00aa930:  93 33 20 10  srl  %o4, 0x10, %o1
a00aa934:  7f ff e3 c4  call  0xa00a3844
a00aa938:  90 15 22 78  or  %l4, 0x278, %o0
a00aa93c:  96 04 60 06  add  %l1, 6, %o3
a00aa940:  98 10 00 08  mov  %o0, %o4
a00aa944:  95 2a e0 10  sll  %o3, 0x10, %o2
a00aa948:  95 32 a0 10  srl  %o2, 0x10, %o2
a00aa94c:  90 10 20 00  clr  %o0
a00aa950:  92 10 20 14  mov  0x14, %o1
a00aa954:  96 10 20 01  mov  1, %o3
a00aa958:  7f ff e2 13  call  0xa00a31a4
a00aa95c:  9a 10 20 00  clr  %o5
a00aa960:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00aa964:  80 a4 00 13  cmp  %l0, %l3
a00aa968:  1a 80 00 11  bcc  0xa00aa9ac
a00aa96c:  a2 10 20 28  mov  0x28, %l1
a00aa970:  7f ff fe ec  call  0xa00aa520
a00aa974:  90 10 00 10  mov  %l0, %o0
a00aa978:  80 8a 20 ff  btst  0xff, %o0
a00aa97c:  a4 04 a0 01  inc  %l2
a00aa980:  a2 04 00 10  add  %l0, %l0, %l1
a00aa984:  94 10 20 11  mov  0x11, %o2
a00aa988:  96 10 22 92  mov  0x292, %o3
a00aa98c:  98 10 20 00  clr  %o4
a00aa990:  12 bf ff df  bne  0xa00aa90c
a00aa994:  90 10 20 14  mov  0x14, %o0
a00aa998:  40 02 70 3a  call  0xa0146a80
a00aa99c:  92 04 60 06  add  %l1, 6, %o1
a00aa9a0:  10 bf ff dc  b  0xa00aa910
a00aa9a4:  94 04 00 18  add  %l0, %i0, %o2
a00aa9a8:  a2 10 20 28  mov  0x28, %l1
a00aa9ac:  e2 23 a0 5c  st  %l1, [ %sp + 0x5c ]
a00aa9b0:  90 10 20 01  mov  1, %o0
a00aa9b4:  92 10 20 01  mov  1, %o1
a00aa9b8:  94 10 27 92  mov  0x792, %o2
a00aa9bc:  96 10 20 1c  mov  0x1c, %o3
a00aa9c0:  98 10 20 15  mov  0x15, %o4
a00aa9c4:  40 00 22 48  call  0xa00b32e4
a00aa9c8:  9a 10 20 02  mov  2, %o5
a00aa9cc:  01 00 00 00  nop
a00aa9d0:  81 c7 e0 08  ret
a00aa9d4:  81 e8 00 00  restore
