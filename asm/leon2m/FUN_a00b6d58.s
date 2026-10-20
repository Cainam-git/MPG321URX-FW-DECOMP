# leon2m FUN_a00b6d58 0xa00b6d58-0xa00b6d94 (60 bytes)
a00b6d58:  9d e3 bf 98  save  %sp, -104, %sp
a00b6d5c:  40 00 83 fb  call  0xa00d7d48
a00b6d60:  b0 10 20 01  mov  1, %i0
a00b6d64:  80 a2 20 00  cmp  %o0, 0
a00b6d68:  02 80 00 04  be  0xa00b6d78
a00b6d6c:  b2 10 20 00  clr  %i1
a00b6d70:  7f ff cc 70  call  0xa00a9f30
a00b6d74:  81 e8 00 00  restore
a00b6d78:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00b6d7c:  d0 00 63 ac  ld  [ %g1 + 0x3ac ], %o0	! 0xa802d3ac
a00b6d80:  b3 32 20 04  srl  %o0, 4, %i1
a00b6d84:  b2 0e 60 01  and  %i1, 1, %i1
a00b6d88:  7f ff cc 6a  call  0xa00a9f30
a00b6d8c:  91 e8 20 01  restore  %g0, 1, %o0
a00b6d90:  01 00 00 00  nop
