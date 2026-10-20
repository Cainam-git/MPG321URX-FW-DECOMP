# leon2m FUN_a0148500 0xa0148500-0xa0148540 (64 bytes)
a0148500:  9d e3 bf 98  save  %sp, -104, %sp
a0148504:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0148508:  da 0a 23 d3  ldub  [ %o0 + 0x3d3 ], %o5	! 0xa802e3d3
a014850c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0148510:  a0 10 63 78  or  %g1, 0x378, %l0	! 0xa802e378
a0148514:  80 a0 00 0d  cmp  %g0, %o5
a0148518:  90 40 20 00  addx  %g0, 0, %o0
a014851c:  d2 14 20 52  lduh  [ %l0 + 0x52 ], %o1
a0148520:  7f fe fe 49  call  0xa0107e44
a0148524:  94 10 20 01  mov  1, %o2
a0148528:  f6 14 20 52  lduh  [ %l0 + 0x52 ], %i3
a014852c:  b0 10 20 00  clr  %i0
a0148530:  b2 10 20 00  clr  %i1
a0148534:  7f ff 05 a2  call  0xa0109bbc
a0148538:  95 e8 20 00  restore  %g0, 0, %o2
a014853c:  01 00 00 00  nop
