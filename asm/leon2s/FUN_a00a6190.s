# leon2s FUN_a00a6190 0xa00a6190-0xa00a61d4 (68 bytes)
a00a6190:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a6194:  80 a2 20 51  cmp  %o0, 0x51
a00a6198:  12 80 00 05  bne  0xa00a61ac
a00a619c:  9a 10 20 00  clr  %o5
a00a61a0:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a61a4:  10 80 00 06  b  0xa00a61bc
a00a61a8:  c2 08 60 0d  ldub  [ %g1 + 0xd ], %g1	! 0xa807d80d
a00a61ac:  80 a2 20 61  cmp  %o0, 0x61
a00a61b0:  12 80 00 07  bne  0xa00a61cc
a00a61b4:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a61b8:  c2 08 61 9d  ldub  [ %g1 + 0x19d ], %g1	! 0xa807d99d
a00a61bc:  80 a0 60 01  cmp  %g1, 1
a00a61c0:  12 80 00 03  bne  0xa00a61cc
a00a61c4:  01 00 00 00  nop
a00a61c8:  9a 10 20 01  mov  1, %o5	! 0x1
a00a61cc:  81 c3 e0 08  retl
a00a61d0:  90 0b 60 01  and  %o5, 1, %o0
