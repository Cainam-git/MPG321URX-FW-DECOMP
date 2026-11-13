# leon2m FUN_a00e20dc 0xa00e20dc-0xa00e2180 (164 bytes)
a00e20dc:  9d e3 bf 98  save  %sp, -104, %sp
a00e20e0:  96 1e 20 03  xor  %i0, 3, %o3
a00e20e4:  80 a0 00 0b  cmp  %g0, %o3
a00e20e8:  9a 40 20 00  addx  %g0, 0, %o5
a00e20ec:  98 1e 20 ff  xor  %i0, 0xff, %o4
a00e20f0:  80 a0 00 0c  cmp  %g0, %o4
a00e20f4:  82 40 20 00  addx  %g0, 0, %g1
a00e20f8:  80 8b 40 01  btst  %o5, %g1
a00e20fc:  12 80 00 03  bne  0xa00e2108
a00e2100:  a0 10 00 18  mov  %i0, %l0
a00e2104:  a0 10 20 00  clr  %l0
a00e2108:  80 a0 00 0b  cmp  %g0, %o3
a00e210c:  92 40 20 00  addx  %g0, 0, %o1
a00e2110:  80 a0 00 0c  cmp  %g0, %o4
a00e2114:  90 40 20 00  addx  %g0, 0, %o0
a00e2118:  80 8a 40 08  btst  %o1, %o0
a00e211c:  12 80 00 10  bne  0xa00e215c
a00e2120:  b3 2e 60 10  sll  %i1, 0x10, %i1
a00e2124:  10 80 00 05  b  0xa00e2138
a00e2128:  90 10 00 10  mov  %l0, %o0
a00e212c:  7f ff f9 2b  call  0xa00e05d8
a00e2130:  01 00 00 00  nop
a00e2134:  90 10 00 10  mov  %l0, %o0
a00e2138:  80 a4 20 02  cmp  %l0, 2
a00e213c:  93 36 60 10  srl  %i1, 0x10, %o1
a00e2140:  94 0e a0 ff  and  %i2, 0xff, %o2
a00e2144:  96 0e e0 ff  and  %i3, 0xff, %o3
a00e2148:  04 bf ff f9  ble  0xa00e212c
a00e214c:  a0 04 20 01  inc  %l0
a00e2150:  30 80 00 0a  b,a   0xa00e2178
a00e2154:  7f ff f9 21  call  0xa00e05d8
a00e2158:  01 00 00 00  nop
a00e215c:  90 10 00 10  mov  %l0, %o0
a00e2160:  80 a4 00 18  cmp  %l0, %i0
a00e2164:  93 36 60 10  srl  %i1, 0x10, %o1
a00e2168:  94 0e a0 ff  and  %i2, 0xff, %o2
a00e216c:  96 0e e0 ff  and  %i3, 0xff, %o3
a00e2170:  04 bf ff f9  ble  0xa00e2154
a00e2174:  a0 04 20 01  inc  %l0
a00e2178:  81 c7 e0 08  ret
a00e217c:  81 e8 00 00  restore
