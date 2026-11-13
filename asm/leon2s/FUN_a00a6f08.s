# leon2s FUN_a00a6f08 0xa00a6f08-0xa00a6f78 (112 bytes)
a00a6f08:  9d e3 bf 98  save  %sp, -104, %sp
a00a6f0c:  93 2e 60 10  sll  %i1, 0x10, %o1
a00a6f10:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a6f14:  93 32 60 10  srl  %o1, 0x10, %o1
a00a6f18:  7f ff ff be  call  0xa00a6e10
a00a6f1c:  90 10 00 18  mov  %i0, %o0
a00a6f20:  10 80 00 04  b  0xa00a6f30
a00a6f24:  a4 10 20 00  clr  %l2
a00a6f28:  7f ff ff ba  call  0xa00a6e10
a00a6f2c:  01 00 00 00  nop
a00a6f30:  a1 2e 60 10  sll  %i1, 0x10, %l0
a00a6f34:  83 2a 20 10  sll  %o0, 0x10, %g1
a00a6f38:  a1 34 20 10  srl  %l0, 0x10, %l0
a00a6f3c:  a3 30 60 10  srl  %g1, 0x10, %l1
a00a6f40:  92 10 00 10  mov  %l0, %o1
a00a6f44:  7f ff ff b3  call  0xa00a6e10
a00a6f48:  90 10 00 18  mov  %i0, %o0
a00a6f4c:  82 0c a0 ff  and  %l2, 0xff, %g1
a00a6f50:  80 a4 40 08  cmp  %l1, %o0
a00a6f54:  92 10 00 10  mov  %l0, %o1
a00a6f58:  90 10 00 18  mov  %i0, %o0
a00a6f5c:  02 80 00 05  be  0xa00a6f70
a00a6f60:  a4 04 a0 01  inc  %l2
a00a6f64:  80 a0 60 04  cmp  %g1, 4
a00a6f68:  08 bf ff f0  bleu  0xa00a6f28
a00a6f6c:  01 00 00 00  nop
a00a6f70:  81 c7 e0 08  ret
a00a6f74:  91 e8 00 11  restore  %g0, %l1, %o0
