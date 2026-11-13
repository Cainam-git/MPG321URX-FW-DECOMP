# leon2s CONV2HDMITX_UpdateInterface_3 0xa00b20dc-0xa00b2194 (184 bytes)
a00b20dc:  9d e3 bf 98  save  %sp, -104, %sp
a00b20e0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b20e4:  c2 08 63 a4  ldub  [ %g1 + 0x3a4 ], %g1	! 0xa80793a4
a00b20e8:  80 a0 60 00  cmp  %g1, 0
a00b20ec:  02 80 00 28  be  0xa00b218c
a00b20f0:  80 a6 20 00  cmp  %i0, 0
a00b20f4:  02 80 00 26  be  0xa00b218c
a00b20f8:  01 00 00 00  nop
a00b20fc:  d8 06 20 08  ld  [ %i0 + 8 ], %o4
a00b2100:  80 a3 20 00  cmp  %o4, 0
a00b2104:  02 80 00 22  be  0xa00b218c
a00b2108:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b210c:  b2 10 63 b8  or  %g1, 0x3b8, %i1	! 0xa80793b8
a00b2110:  ba 10 20 00  clr  %i5
a00b2114:  b6 06 60 10  add  %i1, 0x10, %i3
a00b2118:  9a 10 00 19  mov  %i1, %o5
a00b211c:  9e 10 20 00  clr  %o7
a00b2120:  c2 06 c0 00  ld  [ %i3 ], %g1
a00b2124:  b4 10 00 0f  mov  %o7, %i2
a00b2128:  b8 10 00 0d  mov  %o5, %i4
a00b212c:  b6 06 e0 18  add  %i3, 0x18, %i3
a00b2130:  80 a0 60 00  cmp  %g1, 0
a00b2134:  9e 03 e0 18  add  %o7, 0x18, %o7
a00b2138:  02 80 00 06  be  0xa00b2150
a00b213c:  9a 03 60 18  add  %o5, 0x18, %o5
a00b2140:  ba 07 60 01  inc  %i5
a00b2144:  80 a7 60 0f  cmp  %i5, 0xf
a00b2148:  24 bf ff f7  ble,a   0xa00b2124
a00b214c:  c2 06 c0 00  ld  [ %i3 ], %g1
a00b2150:  80 a7 60 10  cmp  %i5, 0x10
a00b2154:  32 80 00 05  bne,a   0xa00b2168
a00b2158:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a00b215c:  31 28 01 b1  sethi  %hi(0xa006c400), %i0
a00b2160:  7f ff 03 b9  call  0xa0073044
a00b2164:  91 ee 22 28  restore  %i0, 0x228, %o0
a00b2168:  c2 27 20 08  st  %g1, [ %i4 + 8 ]
a00b216c:  c2 06 00 00  ld  [ %i0 ], %g1
a00b2170:  c2 26 80 19  st  %g1, [ %i2 + %i1 ]
a00b2174:  fa 06 20 04  ld  [ %i0 + 4 ], %i5
a00b2178:  82 10 20 01  mov  1, %g1
a00b217c:  c2 2f 20 04  stb  %g1, [ %i4 + 4 ]
a00b2180:  d8 27 20 14  st  %o4, [ %i4 + 0x14 ]
a00b2184:  fa 27 20 0c  st  %i5, [ %i4 + 0xc ]
a00b2188:  f0 27 20 10  st  %i0, [ %i4 + 0x10 ]
a00b218c:  81 c7 e0 08  ret
a00b2190:  81 e8 00 00  restore
