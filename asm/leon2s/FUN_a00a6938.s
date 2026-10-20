# leon2s FUN_a00a6938 0xa00a6938-0xa00a69b4 (124 bytes)
a00a6938:  9d e3 bf 98  save  %sp, -104, %sp
a00a693c:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00a6940:  93 2e 60 10  sll  %i1, 0x10, %o1
a00a6944:  93 32 60 10  srl  %o1, 0x10, %o1
a00a6948:  7f ff ff e2  call  0xa00a68d0
a00a694c:  90 10 00 11  mov  %l1, %o0
a00a6950:  b0 10 00 08  mov  %o0, %i0
a00a6954:  10 80 00 05  b  0xa00a6968
a00a6958:  a4 10 20 00  clr  %l2
a00a695c:  7f ff ff dd  call  0xa00a68d0
a00a6960:  01 00 00 00  nop
a00a6964:  b0 10 00 08  mov  %o0, %i0
a00a6968:  a1 2e 60 10  sll  %i1, 0x10, %l0
a00a696c:  a1 34 20 10  srl  %l0, 0x10, %l0
a00a6970:  92 10 00 10  mov  %l0, %o1
a00a6974:  7f ff ff d7  call  0xa00a68d0
a00a6978:  90 10 00 11  mov  %l1, %o0
a00a697c:  9b 2e 20 10  sll  %i0, 0x10, %o5
a00a6980:  83 2a 20 10  sll  %o0, 0x10, %g1
a00a6984:  98 0c a0 ff  and  %l2, 0xff, %o4
a00a6988:  92 10 00 10  mov  %l0, %o1
a00a698c:  90 10 00 11  mov  %l1, %o0
a00a6990:  80 a0 40 0d  cmp  %g1, %o5
a00a6994:  b1 33 60 10  srl  %o5, 0x10, %i0
a00a6998:  02 80 00 05  be  0xa00a69ac
a00a699c:  a4 04 a0 01  inc  %l2
a00a69a0:  80 a3 20 04  cmp  %o4, 4
a00a69a4:  08 bf ff ee  bleu  0xa00a695c
a00a69a8:  01 00 00 00  nop
a00a69ac:  81 c7 e0 08  ret
a00a69b0:  81 e8 00 00  restore
