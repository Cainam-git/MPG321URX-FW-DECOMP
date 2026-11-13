# leon2m FUN_a014a258 0xa014a258-0xa014a2a0 (72 bytes)
a014a258:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a25c:  80 a2 20 01  cmp  %o0, 1
a014a260:  22 80 00 08  be,a   0xa014a280
a014a264:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014a268:  04 80 00 08  ble  0xa014a288
a014a26c:  80 a2 20 02  cmp  %o0, 2
a014a270:  12 80 00 0a  bne  0xa014a298
a014a274:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014a278:  10 80 00 08  b  0xa014a298
a014a27c:  d2 28 63 e7  stb  %o1, [ %g1 + 0x3e7 ]	! 0xa802e3e7
a014a280:  10 80 00 06  b  0xa014a298
a014a284:  d2 2a 23 e6  stb  %o1, [ %o0 + 0x3e6 ]
a014a288:  80 a2 20 00  cmp  %o0, 0
a014a28c:  12 80 00 03  bne  0xa014a298
a014a290:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014a294:  d2 28 63 e5  stb  %o1, [ %g1 + 0x3e5 ]	! 0xa802e3e5
a014a298:  81 c3 e0 08  retl
a014a29c:  01 00 00 00  nop
