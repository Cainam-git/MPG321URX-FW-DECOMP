# leon2s FUN_a00b2070 0xa00b2070-0xa00b20dc (108 bytes)
a00b2070:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b2074:  96 10 63 a4  or  %g1, 0x3a4, %o3	! 0xa80793a4
a00b2078:  83 2a 20 03  sll  %o0, 3, %g1
a00b207c:  82 00 40 0b  add  %g1, %o3, %g1
a00b2080:  9a 00 60 0c  add  %g1, 0xc, %o5
a00b2084:  98 10 20 00  clr  %o4
a00b2088:  90 02 00 08  add  %o0, %o0, %o0
a00b208c:  c2 03 40 00  ld  [ %o5 ], %g1
a00b2090:  80 a0 60 00  cmp  %g1, 0
a00b2094:  02 80 00 06  be  0xa00b20ac
a00b2098:  9a 03 60 04  add  %o5, 4, %o5
a00b209c:  98 03 20 01  inc  %o4
a00b20a0:  80 a3 20 01  cmp  %o4, 1
a00b20a4:  24 bf ff fb  ble,a   0xa00b2090
a00b20a8:  c2 03 40 00  ld  [ %o5 ], %g1
a00b20ac:  80 a3 20 02  cmp  %o4, 2
a00b20b0:  12 80 00 07  bne  0xa00b20cc
a00b20b4:  82 02 00 0c  add  %o0, %o4, %g1
a00b20b8:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b20bc:  90 12 22 08  or  %o0, 0x208, %o0	! 0xa006c608
a00b20c0:  82 13 c0 00  mov  %o7, %g1
a00b20c4:  7f ff 03 e0  call  0xa0073044
a00b20c8:  9e 10 40 00  mov  %g1, %o7
a00b20cc:  83 28 60 02  sll  %g1, 2, %g1
a00b20d0:  82 00 40 0b  add  %g1, %o3, %g1
a00b20d4:  81 c3 e0 08  retl
a00b20d8:  d2 20 60 0c  st  %o1, [ %g1 + 0xc ]
