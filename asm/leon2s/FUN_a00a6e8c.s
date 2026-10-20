# leon2s FUN_a00a6e8c 0xa00a6e8c-0xa00a6f08 (124 bytes)
a00a6e8c:  9d e3 bf 98  save  %sp, -104, %sp
a00a6e90:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00a6e94:  93 2e 60 10  sll  %i1, 0x10, %o1
a00a6e98:  93 32 60 10  srl  %o1, 0x10, %o1
a00a6e9c:  7f ff ff c3  call  0xa00a6da8
a00a6ea0:  90 10 00 11  mov  %l1, %o0
a00a6ea4:  b0 10 00 08  mov  %o0, %i0
a00a6ea8:  10 80 00 05  b  0xa00a6ebc
a00a6eac:  a4 10 20 00  clr  %l2
a00a6eb0:  7f ff ff be  call  0xa00a6da8
a00a6eb4:  01 00 00 00  nop
a00a6eb8:  b0 10 00 08  mov  %o0, %i0
a00a6ebc:  a1 2e 60 10  sll  %i1, 0x10, %l0
a00a6ec0:  a1 34 20 10  srl  %l0, 0x10, %l0
a00a6ec4:  92 10 00 10  mov  %l0, %o1
a00a6ec8:  7f ff ff b8  call  0xa00a6da8
a00a6ecc:  90 10 00 11  mov  %l1, %o0
a00a6ed0:  9b 2e 20 10  sll  %i0, 0x10, %o5
a00a6ed4:  83 2a 20 10  sll  %o0, 0x10, %g1
a00a6ed8:  98 0c a0 ff  and  %l2, 0xff, %o4
a00a6edc:  92 10 00 10  mov  %l0, %o1
a00a6ee0:  90 10 00 11  mov  %l1, %o0
a00a6ee4:  80 a0 40 0d  cmp  %g1, %o5
a00a6ee8:  b1 33 60 10  srl  %o5, 0x10, %i0
a00a6eec:  02 80 00 05  be  0xa00a6f00
a00a6ef0:  a4 04 a0 01  inc  %l2
a00a6ef4:  80 a3 20 04  cmp  %o4, 4
a00a6ef8:  08 bf ff ee  bleu  0xa00a6eb0
a00a6efc:  01 00 00 00  nop
a00a6f00:  81 c7 e0 08  ret
a00a6f04:  81 e8 00 00  restore
