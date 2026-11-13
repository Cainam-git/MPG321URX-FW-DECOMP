# leon2s FUN_a00a2010 0xa00a2010-0xa00a2080 (112 bytes)
a00a2010:  80 8a 60 ff  btst  0xff, %o1
a00a2014:  02 80 00 0d  be  0xa00a2048
a00a2018:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a201c:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a00a2020:  98 10 63 f0  or  %g1, 0x3f0, %o4	! 0xcf0147f0
a00a2024:  80 a2 20 00  cmp  %o0, 0
a00a2028:  12 80 00 05  bne  0xa00a203c
a00a202c:  9a 10 00 0c  mov  %o4, %o5
a00a2030:  c2 03 00 00  ld  [ %o4 ], %g1
a00a2034:  10 80 00 0c  b  0xa00a2064
a00a2038:  82 10 60 04  or  %g1, 4, %g1
a00a203c:  c2 03 00 00  ld  [ %o4 ], %g1
a00a2040:  10 80 00 0d  b  0xa00a2074
a00a2044:  82 10 60 40  or  %g1, 0x40, %g1
a00a2048:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a00a204c:  98 10 63 f0  or  %g1, 0x3f0, %o4	! 0xcf0147f0
a00a2050:  80 a2 20 00  cmp  %o0, 0
a00a2054:  12 80 00 06  bne  0xa00a206c
a00a2058:  9a 10 00 0c  mov  %o4, %o5
a00a205c:  c2 03 00 00  ld  [ %o4 ], %g1
a00a2060:  82 08 7f fb  and  %g1, -5, %g1
a00a2064:  c2 23 00 00  st  %g1, [ %o4 ]
a00a2068:  30 80 00 04  b,a   0xa00a2078
a00a206c:  c2 03 00 00  ld  [ %o4 ], %g1
a00a2070:  82 08 7f bf  and  %g1, -65, %g1
a00a2074:  c2 23 40 00  st  %g1, [ %o5 ]
a00a2078:  81 c3 e0 08  retl
a00a207c:  01 00 00 00  nop
