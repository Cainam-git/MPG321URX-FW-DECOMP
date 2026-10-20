# leon2s FUN_a00a7a5c 0xa00a7a5c-0xa00a7acc (112 bytes)
a00a7a5c:  9d e3 bf 98  save  %sp, -104, %sp
a00a7a60:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00a7a64:  93 2e 60 10  sll  %i1, 0x10, %o1
a00a7a68:  93 32 60 10  srl  %o1, 0x10, %o1
a00a7a6c:  7f ff ff d6  call  0xa00a79c4
a00a7a70:  90 10 00 11  mov  %l1, %o0
a00a7a74:  b0 10 00 08  mov  %o0, %i0
a00a7a78:  10 80 00 05  b  0xa00a7a8c
a00a7a7c:  a4 10 20 00  clr  %l2
a00a7a80:  7f ff ff d1  call  0xa00a79c4
a00a7a84:  01 00 00 00  nop
a00a7a88:  b0 10 00 08  mov  %o0, %i0
a00a7a8c:  a1 2e 60 10  sll  %i1, 0x10, %l0
a00a7a90:  a1 34 20 10  srl  %l0, 0x10, %l0
a00a7a94:  92 10 00 10  mov  %l0, %o1
a00a7a98:  7f ff ff cb  call  0xa00a79c4
a00a7a9c:  90 10 00 11  mov  %l1, %o0
a00a7aa0:  82 0c a0 ff  and  %l2, 0xff, %g1
a00a7aa4:  80 a6 00 08  cmp  %i0, %o0
a00a7aa8:  92 10 00 10  mov  %l0, %o1
a00a7aac:  90 10 00 11  mov  %l1, %o0
a00a7ab0:  02 80 00 05  be  0xa00a7ac4
a00a7ab4:  a4 04 a0 01  inc  %l2
a00a7ab8:  80 a0 60 04  cmp  %g1, 4
a00a7abc:  08 bf ff f1  bleu  0xa00a7a80
a00a7ac0:  01 00 00 00  nop
a00a7ac4:  81 c7 e0 08  ret
a00a7ac8:  81 e8 00 00  restore
