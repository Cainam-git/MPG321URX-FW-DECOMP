# leon2m FUN_a0108eec 0xa0108eec-0xa0108f70 (132 bytes)
a0108eec:  03 33 c0 46  sethi  %hi(0xcf011800), %g1
a0108ef0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0108ef4:  98 10 62 a8  or  %g1, 0x2a8, %o4
a0108ef8:  80 a2 20 02  cmp  %o0, 2
a0108efc:  02 80 00 15  be  0xa0108f50
a0108f00:  96 0a 60 07  and  %o1, 7, %o3
a0108f04:  80 a2 20 02  cmp  %o0, 2
a0108f08:  04 80 00 07  ble  0xa0108f24
a0108f0c:  80 a2 20 01  cmp  %o0, 1
a0108f10:  80 a2 20 03  cmp  %o0, 3
a0108f14:  12 80 00 15  bne  0xa0108f68
a0108f18:  17 33 c0 46  sethi  %hi(0xcf011800), %o3
a0108f1c:  10 80 00 05  b  0xa0108f30
a0108f20:  9a 12 e2 ac  or  %o3, 0x2ac, %o5	! 0xcf011aac
a0108f24:  12 80 00 11  bne  0xa0108f68
a0108f28:  1b 33 c0 46  sethi  %hi(0xcf011800), %o5
a0108f2c:  9a 13 62 a4  or  %o5, 0x2a4, %o5	! 0xcf011aa4
a0108f30:  d6 03 40 00  ld  [ %o5 ], %o3
a0108f34:  82 0a ff f8  and  %o3, -8, %g1
a0108f38:  c2 23 40 00  st  %g1, [ %o5 ]
a0108f3c:  98 0a 60 07  and  %o1, 7, %o4
a0108f40:  d2 03 40 00  ld  [ %o5 ], %o1
a0108f44:  90 12 40 0c  or  %o1, %o4, %o0
a0108f48:  d0 23 40 00  st  %o0, [ %o5 ]
a0108f4c:  30 80 00 07  b,a   0xa0108f68
a0108f50:  da 03 00 00  ld  [ %o4 ], %o5
a0108f54:  82 0b 7f f8  and  %o5, -8, %g1
a0108f58:  c2 23 00 00  st  %g1, [ %o4 ]
a0108f5c:  d2 03 00 00  ld  [ %o4 ], %o1
a0108f60:  90 12 40 0b  or  %o1, %o3, %o0
a0108f64:  d0 23 00 00  st  %o0, [ %o4 ]
a0108f68:  81 c3 e0 08  retl
a0108f6c:  01 00 00 00  nop
