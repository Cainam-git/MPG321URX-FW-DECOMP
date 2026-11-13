# leon2m FUN_a00e2040 0xa00e2040-0xa00e20dc (156 bytes)
a00e2040:  9d e3 bf 98  save  %sp, -104, %sp
a00e2044:  96 1e 20 03  xor  %i0, 3, %o3
a00e2048:  80 a0 00 0b  cmp  %g0, %o3
a00e204c:  9a 40 20 00  addx  %g0, 0, %o5
a00e2050:  98 1e 20 ff  xor  %i0, 0xff, %o4
a00e2054:  80 a0 00 0c  cmp  %g0, %o4
a00e2058:  82 40 20 00  addx  %g0, 0, %g1
a00e205c:  80 8b 40 01  btst  %o5, %g1
a00e2060:  12 80 00 03  bne  0xa00e206c
a00e2064:  a0 10 00 18  mov  %i0, %l0
a00e2068:  a0 10 20 00  clr  %l0
a00e206c:  80 a0 00 0b  cmp  %g0, %o3
a00e2070:  92 40 20 00  addx  %g0, 0, %o1
a00e2074:  80 a0 00 0c  cmp  %g0, %o4
a00e2078:  90 40 20 00  addx  %g0, 0, %o0
a00e207c:  80 8a 40 08  btst  %o1, %o0
a00e2080:  12 80 00 0f  bne  0xa00e20bc
a00e2084:  b3 2e 60 10  sll  %i1, 0x10, %i1
a00e2088:  10 80 00 05  b  0xa00e209c
a00e208c:  90 10 00 10  mov  %l0, %o0
a00e2090:  7f ff f8 c8  call  0xa00e03b0
a00e2094:  01 00 00 00  nop
a00e2098:  90 10 00 10  mov  %l0, %o0
a00e209c:  80 a4 20 02  cmp  %l0, 2
a00e20a0:  93 36 60 10  srl  %i1, 0x10, %o1
a00e20a4:  94 0e a0 ff  and  %i2, 0xff, %o2
a00e20a8:  04 bf ff fa  ble  0xa00e2090
a00e20ac:  a0 04 20 01  inc  %l0
a00e20b0:  30 80 00 09  b,a   0xa00e20d4
a00e20b4:  7f ff f8 bf  call  0xa00e03b0
a00e20b8:  01 00 00 00  nop
a00e20bc:  90 10 00 10  mov  %l0, %o0
a00e20c0:  80 a4 00 18  cmp  %l0, %i0
a00e20c4:  93 36 60 10  srl  %i1, 0x10, %o1
a00e20c8:  94 0e a0 ff  and  %i2, 0xff, %o2
a00e20cc:  04 bf ff fa  ble  0xa00e20b4
a00e20d0:  a0 04 20 01  inc  %l0
a00e20d4:  81 c7 e0 08  ret
a00e20d8:  81 e8 00 00  restore
