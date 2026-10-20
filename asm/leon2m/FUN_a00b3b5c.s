# leon2m FUN_a00b3b5c 0xa00b3b5c-0xa00b3ba0 (68 bytes)
a00b3b5c:  9d e3 bf 98  save  %sp, -104, %sp
a00b3b60:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00b3b64:  d4 02 e2 90  ld  [ %o3 + 0x290 ], %o2	! 0xa802d290
a00b3b68:  93 32 a0 09  srl  %o2, 9, %o1
a00b3b6c:  92 0a 60 01  and  %o1, 1, %o1
a00b3b70:  7f ff d8 f0  call  0xa00a9f30
a00b3b74:  90 10 20 04  mov  4, %o0
a00b3b78:  82 0e 20 ff  and  %i0, 0xff, %g1
a00b3b7c:  b0 10 20 04  mov  4, %i0
a00b3b80:  80 a0 60 01  cmp  %g1, 1
a00b3b84:  02 80 00 04  be  0xa00b3b94
a00b3b88:  b2 10 20 01  mov  1, %i1
a00b3b8c:  b0 10 20 04  mov  4, %i0
a00b3b90:  b2 10 20 00  clr  %i1
a00b3b94:  7f ff d9 22  call  0xa00aa01c
a00b3b98:  81 e8 00 00  restore
a00b3b9c:  01 00 00 00  nop
