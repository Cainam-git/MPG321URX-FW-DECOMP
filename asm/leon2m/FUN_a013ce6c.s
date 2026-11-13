# leon2m FUN_a013ce6c 0xa013ce6c-0xa013cea0 (52 bytes)
a013ce6c:  90 0a 20 ff  and  %o0, 0xff, %o0
a013ce70:  9b 2a 20 04  sll  %o0, 4, %o5
a013ce74:  82 23 40 08  sub  %o5, %o0, %g1
a013ce78:  80 a2 20 03  cmp  %o0, 3
a013ce7c:  9b 28 60 03  sll  %g1, 3, %o5
a013ce80:  18 80 00 06  bgu  0xa013ce98
a013ce84:  90 10 20 0d  mov  0xd, %o0
a013ce88:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a013ce8c:  90 10 63 30  or  %g1, 0x330, %o0	! 0xa802df30
a013ce90:  da 03 40 08  ld  [ %o5 + %o0 ], %o5
a013ce94:  91 33 60 1c  srl  %o5, 0x1c, %o0
a013ce98:  81 c3 e0 08  retl
a013ce9c:  01 00 00 00  nop
