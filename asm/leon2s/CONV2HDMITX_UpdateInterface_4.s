# leon2s CONV2HDMITX_UpdateInterface_4 0xa00b2194-0xa00b222c (152 bytes)
a00b2194:  9d e3 bf 98  save  %sp, -104, %sp
a00b2198:  80 a6 20 00  cmp  %i0, 0
a00b219c:  02 80 00 22  be  0xa00b2224
a00b21a0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b21a4:  b2 10 63 b8  or  %g1, 0x3b8, %i1	! 0xa80793b8
a00b21a8:  ba 10 20 00  clr  %i5
a00b21ac:  b8 06 60 10  add  %i1, 0x10, %i4
a00b21b0:  9a 10 00 19  mov  %i1, %o5
a00b21b4:  9e 10 20 00  clr  %o7
a00b21b8:  c2 07 00 00  ld  [ %i4 ], %g1
a00b21bc:  b4 10 00 0f  mov  %o7, %i2
a00b21c0:  b6 10 00 0d  mov  %o5, %i3
a00b21c4:  b8 07 20 18  add  %i4, 0x18, %i4
a00b21c8:  80 a0 40 18  cmp  %g1, %i0
a00b21cc:  9e 03 e0 18  add  %o7, 0x18, %o7
a00b21d0:  02 80 00 06  be  0xa00b21e8
a00b21d4:  9a 03 60 18  add  %o5, 0x18, %o5
a00b21d8:  ba 07 60 01  inc  %i5
a00b21dc:  80 a7 60 0f  cmp  %i5, 0xf
a00b21e0:  24 bf ff f7  ble,a   0xa00b21bc
a00b21e4:  c2 07 00 00  ld  [ %i4 ], %g1
a00b21e8:  80 a7 60 10  cmp  %i5, 0x10
a00b21ec:  32 80 00 05  bne,a   0xa00b2200
a00b21f0:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a00b21f4:  31 28 01 b1  sethi  %hi(0xa006c400), %i0
a00b21f8:  7f ff 03 93  call  0xa0073044
a00b21fc:  91 ee 22 40  restore  %i0, 0x240, %o0
a00b2200:  c2 26 e0 08  st  %g1, [ %i3 + 8 ]
a00b2204:  c2 06 00 00  ld  [ %i0 ], %g1
a00b2208:  c2 26 80 19  st  %g1, [ %i2 + %i1 ]
a00b220c:  f8 06 20 08  ld  [ %i0 + 8 ], %i4
a00b2210:  fa 06 20 04  ld  [ %i0 + 4 ], %i5
a00b2214:  82 10 20 01  mov  1, %g1
a00b2218:  c2 2e e0 04  stb  %g1, [ %i3 + 4 ]
a00b221c:  fa 26 e0 0c  st  %i5, [ %i3 + 0xc ]
a00b2220:  f8 26 e0 14  st  %i4, [ %i3 + 0x14 ]
a00b2224:  81 c7 e0 08  ret
a00b2228:  81 e8 00 00  restore
