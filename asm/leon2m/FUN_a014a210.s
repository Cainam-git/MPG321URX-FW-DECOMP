# leon2m FUN_a014a210 0xa014a210-0xa014a258 (72 bytes)
a014a210:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a214:  80 a2 20 01  cmp  %o0, 1
a014a218:  22 80 00 08  be,a   0xa014a238
a014a21c:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014a220:  04 80 00 08  ble  0xa014a240
a014a224:  80 a2 20 02  cmp  %o0, 2
a014a228:  12 80 00 0a  bne  0xa014a250
a014a22c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014a230:  10 80 00 08  b  0xa014a250
a014a234:  d2 28 63 e4  stb  %o1, [ %g1 + 0x3e4 ]	! 0xa802e3e4
a014a238:  10 80 00 06  b  0xa014a250
a014a23c:  d2 2a 23 e3  stb  %o1, [ %o0 + 0x3e3 ]
a014a240:  80 a2 20 00  cmp  %o0, 0
a014a244:  12 80 00 03  bne  0xa014a250
a014a248:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014a24c:  d2 28 63 e2  stb  %o1, [ %g1 + 0x3e2 ]	! 0xa802e3e2
a014a250:  81 c3 e0 08  retl
a014a254:  01 00 00 00  nop
