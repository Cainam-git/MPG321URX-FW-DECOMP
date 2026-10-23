# leon2m FUN_a00f6c38 0xa00f6c38-0xa00f6c6c (52 bytes)
a00f6c38:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f6c3c:  da 08 63 b4  ldub  [ %g1 + 0x3b4 ], %o5	! 0xa802b7b4
a00f6c40:  98 03 60 04  add  %o5, 4, %o4
a00f6c44:  82 10 20 01  mov  1, %g1
a00f6c48:  17 33 c0 3b  sethi  %hi(0xcf00ec00), %o3
a00f6c4c:  96 12 e2 80  or  %o3, 0x280, %o3	! 0xcf00ee80
a00f6c50:  9b 28 40 0c  sll  %g1, %o4, %o5
a00f6c54:  c2 02 c0 00  ld  [ %o3 ], %g1
a00f6c58:  98 10 40 0d  or  %g1, %o5, %o4
a00f6c5c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00f6c60:  c2 22 c0 00  st  %g1, [ %o3 ]
a00f6c64:  81 c3 e0 08  retl
a00f6c68:  01 00 00 00  nop
