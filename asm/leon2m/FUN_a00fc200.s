# leon2m FUN_a00fc200 0xa00fc200-0xa00fc2fc (252 bytes)
a00fc200:  9d e3 bf 98  save  %sp, -104, %sp
a00fc204:  11 33 c0 48  sethi  %hi(0xcf012000), %o0
a00fc208:  96 12 20 1c  or  %o0, 0x1c, %o3	! 0xcf01201c
a00fc20c:  92 10 20 28  mov  0x28, %o1
a00fc210:  d2 22 c0 00  st  %o1, [ %o3 ]
a00fc214:  9a 10 20 01  mov  1, %o5
a00fc218:  da 22 00 00  st  %o5, [ %o0 ]
a00fc21c:  98 12 20 44  or  %o0, 0x44, %o4
a00fc220:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00fc224:  82 10 20 53  mov  0x53, %g1
a00fc228:  c2 23 00 00  st  %g1, [ %o4 ]
a00fc22c:  80 a6 20 01  cmp  %i0, 1
a00fc230:  22 80 00 2b  be,a   0xa00fc2dc
a00fc234:  90 10 20 03  mov  3, %o0
a00fc238:  04 80 00 23  ble  0xa00fc2c4
a00fc23c:  80 a6 20 02  cmp  %i0, 2
a00fc240:  02 80 00 29  be  0xa00fc2e4
a00fc244:  80 a6 20 03  cmp  %i0, 3
a00fc248:  02 80 00 1a  be  0xa00fc2b0
a00fc24c:  90 10 20 03  mov  3, %o0
a00fc250:  13 33 c0 48  sethi  %hi(0xcf012000), %o1
a00fc254:  94 12 60 34  or  %o1, 0x34, %o2	! 0xcf012034
a00fc258:  9e 10 20 ff  mov  0xff, %o7
a00fc25c:  17 33 c0 45  sethi  %hi(0xcf011400), %o3
a00fc260:  de 22 80 00  st  %o7, [ %o2 ]
a00fc264:  9a 12 e0 80  or  %o3, 0x80, %o5
a00fc268:  d4 03 40 00  ld  [ %o5 ], %o2
a00fc26c:  b0 10 20 0f  mov  0xf, %i0
a00fc270:  11 2a 00 b2  sethi  %hi(0xa802c800), %o0
a00fc274:  98 10 3f ff  mov  -1, %o4
a00fc278:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a00fc27c:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a00fc280:  f0 2a 21 7e  stb  %i0, [ %o0 + 0x17e ]
a00fc284:  d8 28 61 7f  stb  %o4, [ %g1 + 0x17f ]
a00fc288:  94 8a a0 03  andcc  %o2, 3, %o2
a00fc28c:  12 80 00 05  bne  0xa00fc2a0
a00fc290:  f0 2b e1 7d  stb  %i0, [ %o7 + 0x17d ]
a00fc294:  9a 12 60 04  or  %o1, 4, %o5
a00fc298:  10 80 00 16  b  0xa00fc2f0
a00fc29c:  82 10 20 78  mov  0x78, %g1
a00fc2a0:  b0 10 20 78  mov  0x78, %i0
a00fc2a4:  83 3e 00 0a  sra  %i0, %o2, %g1
a00fc2a8:  10 80 00 12  b  0xa00fc2f0
a00fc2ac:  9a 12 60 04  or  %o1, 4, %o5
a00fc2b0:  92 10 20 08  mov  8, %o1
a00fc2b4:  40 00 09 73  call  0xa00fe880
a00fc2b8:  94 10 20 01  mov  1, %o2
a00fc2bc:  10 bf ff e6  b  0xa00fc254
a00fc2c0:  13 33 c0 48  sethi  %hi(0xcf012000), %o1
a00fc2c4:  80 a6 20 00  cmp  %i0, 0
a00fc2c8:  32 bf ff e3  bne,a   0xa00fc254
a00fc2cc:  13 33 c0 48  sethi  %hi(0xcf012000), %o1
a00fc2d0:  90 10 20 03  mov  3, %o0
a00fc2d4:  10 bf ff f8  b  0xa00fc2b4
a00fc2d8:  92 10 20 01  mov  1, %o1
a00fc2dc:  10 bf ff f6  b  0xa00fc2b4
a00fc2e0:  92 10 20 02  mov  2, %o1
a00fc2e4:  90 10 20 03  mov  3, %o0
a00fc2e8:  10 bf ff f3  b  0xa00fc2b4
a00fc2ec:  92 10 20 04  mov  4, %o1
a00fc2f0:  c2 23 40 00  st  %g1, [ %o5 ]
a00fc2f4:  81 c7 e0 08  ret
a00fc2f8:  81 e8 00 00  restore
