# leon2s FUN_a0088f4c 0xa0088f4c-0xa0088f84 (56 bytes)
a0088f4c:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a0088f50:  90 0a 20 ff  and  %o0, 0xff, %o0
a0088f54:  80 a2 20 01  cmp  %o0, 1
a0088f58:  12 80 00 06  bne  0xa0088f70
a0088f5c:  98 10 62 80  or  %g1, 0x280, %o4
a0088f60:  c2 03 00 00  ld  [ %o4 ], %g1
a0088f64:  82 08 7f fd  and  %g1, -3, %g1
a0088f68:  c2 23 00 00  st  %g1, [ %o4 ]
a0088f6c:  30 80 00 04  b,a   0xa0088f7c
a0088f70:  c2 03 00 00  ld  [ %o4 ], %g1
a0088f74:  82 10 60 02  or  %g1, 2, %g1
a0088f78:  c2 23 00 00  st  %g1, [ %o4 ]
a0088f7c:  81 c3 e0 08  retl
a0088f80:  01 00 00 00  nop
