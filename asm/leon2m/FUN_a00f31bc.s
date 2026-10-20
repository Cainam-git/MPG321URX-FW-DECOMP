# leon2m FUN_a00f31bc 0xa00f31bc-0xa00f328c (208 bytes)
a00f31bc:  9d e3 bf 98  save  %sp, -104, %sp
a00f31c0:  03 33 c0 80  sethi  %hi(0xcf020000), %g1
a00f31c4:  ba 10 60 80  or  %g1, 0x80, %i5	! 0xcf020080
a00f31c8:  b6 10 60 6c  or  %g1, 0x6c, %i3
a00f31cc:  80 a6 20 03  cmp  %i0, 3
a00f31d0:  18 80 00 1a  bgu  0xa00f3238
a00f31d4:  b2 10 60 3c  or  %g1, 0x3c, %i1
a00f31d8:  b4 10 00 1b  mov  %i3, %i2
a00f31dc:  b8 10 00 1d  mov  %i5, %i4
a00f31e0:  80 a6 20 02  cmp  %i0, 2
a00f31e4:  02 80 00 1f  be  0xa00f3260
a00f31e8:  9e 10 00 19  mov  %i1, %o7
a00f31ec:  03 33 c0 80  sethi  %hi(0xcf020000), %g1
a00f31f0:  b4 10 60 6c  or  %g1, 0x6c, %i2	! 0xcf02006c
a00f31f4:  b8 10 60 80  or  %g1, 0x80, %i4
a00f31f8:  80 a6 20 00  cmp  %i0, 0
a00f31fc:  12 80 00 0f  bne  0xa00f3238
a00f3200:  9e 10 60 3c  or  %g1, 0x3c, %o7
a00f3204:  f6 06 80 00  ld  [ %i2 ], %i3
a00f3208:  b2 0e ff 1f  and  %i3, -225, %i1
a00f320c:  f2 26 80 00  st  %i1, [ %i2 ]
a00f3210:  fa 07 00 00  ld  [ %i4 ], %i5
a00f3214:  b0 0f 7f 7f  and  %i5, -129, %i0
a00f3218:  f0 27 00 00  st  %i0, [ %i4 ]
a00f321c:  f4 07 00 00  ld  [ %i4 ], %i2
a00f3220:  82 16 a0 10  or  %i2, 0x10, %g1
a00f3224:  c2 27 00 00  st  %g1, [ %i4 ]
a00f3228:  c2 03 c0 00  ld  [ %o7 ], %g1
a00f322c:  b8 08 7f 1f  and  %g1, -225, %i4
a00f3230:  f8 23 c0 00  st  %i4, [ %o7 ]
a00f3234:  30 80 00 14  b,a   0xa00f3284
a00f3238:  f4 07 40 00  ld  [ %i5 ], %i2
a00f323c:  82 0e bf 6f  and  %i2, -145, %g1
a00f3240:  c2 27 40 00  st  %g1, [ %i5 ]
a00f3244:  f8 06 c0 00  ld  [ %i3 ], %i4
a00f3248:  ba 17 20 e0  or  %i4, 0xe0, %i5
a00f324c:  fa 26 c0 00  st  %i5, [ %i3 ]
a00f3250:  f0 06 40 00  ld  [ %i1 ], %i0
a00f3254:  b4 16 20 e0  or  %i0, 0xe0, %i2
a00f3258:  f4 26 40 00  st  %i2, [ %i1 ]
a00f325c:  30 80 00 0a  b,a   0xa00f3284
a00f3260:  c2 06 c0 00  ld  [ %i3 ], %g1
a00f3264:  b6 08 7f 1f  and  %g1, -225, %i3
a00f3268:  f6 26 80 00  st  %i3, [ %i2 ]
a00f326c:  f2 07 40 00  ld  [ %i5 ], %i1
a00f3270:  ba 0e 7f ef  and  %i1, -17, %i5
a00f3274:  fa 27 00 00  st  %i5, [ %i4 ]
a00f3278:  f0 07 00 00  ld  [ %i4 ], %i0
a00f327c:  10 bf ff ea  b  0xa00f3224
a00f3280:  82 16 20 80  or  %i0, 0x80, %g1
a00f3284:  81 c7 e0 08  ret
a00f3288:  81 e8 00 00  restore
