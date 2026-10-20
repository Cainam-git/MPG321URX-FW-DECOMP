# leon2m FUN_a0141a98 0xa0141a98-0xa0141ad0 (56 bytes)
a0141a98:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0141a9c:  da 08 61 10  ldub  [ %g1 + 0x110 ], %o5	! 0xa802e110
a0141aa0:  80 a3 60 06  cmp  %o5, 6
a0141aa4:  02 80 00 04  be  0xa0141ab4
a0141aa8:  90 10 20 01  mov  1, %o0
a0141aac:  10 80 00 07  b  0xa0141ac8
a0141ab0:  90 10 20 00  clr  %o0
a0141ab4:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a0141ab8:  da 08 60 08  ldub  [ %g1 + 8 ], %o5	! 0xa802cc08
a0141abc:  80 a3 60 01  cmp  %o5, 1
a0141ac0:  32 80 00 02  bne,a   0xa0141ac8
a0141ac4:  90 10 20 00  clr  %o0
a0141ac8:  81 c3 e0 08  retl
a0141acc:  01 00 00 00  nop
