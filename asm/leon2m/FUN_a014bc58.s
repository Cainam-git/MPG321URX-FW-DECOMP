# leon2m FUN_a014bc58 0xa014bc58-0xa014bcac (84 bytes)
a014bc58:  03 2a 00 b9  sethi  %hi(0xa802e400), %g1
a014bc5c:  9a 10 00 08  mov  %o0, %o5
a014bc60:  92 10 20 00  clr  %o1
a014bc64:  80 a2 20 00  cmp  %o0, 0
a014bc68:  02 80 00 0b  be  0xa014bc94
a014bc6c:  d0 20 60 08  st  %o0, [ %g1 + 8 ]
a014bc70:  80 a2 20 01  cmp  %o0, 1
a014bc74:  02 80 00 08  be  0xa014bc94
a014bc78:  80 a3 60 02  cmp  %o5, 2
a014bc7c:  90 10 20 01  mov  1, %o0
a014bc80:  02 80 00 05  be  0xa014bc94
a014bc84:  92 10 20 01  mov  1, %o1
a014bc88:  80 a3 60 03  cmp  %o5, 3
a014bc8c:  12 80 00 05  bne  0xa014bca0
a014bc90:  01 00 00 00  nop
a014bc94:  82 13 c0 00  mov  %o7, %g1
a014bc98:  40 00 11 22  call  0xa0150120
a014bc9c:  9e 10 40 00  mov  %g1, %o7
a014bca0:  01 00 00 00  nop
a014bca4:  81 c3 e0 08  retl
a014bca8:  01 00 00 00  nop
