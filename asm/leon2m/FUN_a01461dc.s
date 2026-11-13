# leon2m FUN_a01461dc 0xa01461dc-0xa0146298 (188 bytes)
a01461dc:  9d e3 bf 88  save  %sp, -120, %sp
a01461e0:  90 0e 20 ff  and  %i0, 0xff, %o0
a01461e4:  b0 1a 20 01  xor  %o0, 1, %i0
a01461e8:  80 a0 00 18  cmp  %g0, %i0
a01461ec:  98 10 20 00  clr  %o4
a01461f0:  9a 10 20 00  clr  %o5
a01461f4:  96 60 3f ff  subx  %g0, -1, %o3
a01461f8:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a01461fc:  c2 16 40 00  lduh  [ %i1 ], %g1
a0146200:  d2 0e 60 02  ldub  [ %i1 + 2 ], %o1
a0146204:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a0146208:  c2 37 bf e8  sth  %g1, [ %fp + -24 ]
a014620c:  80 a2 60 01  cmp  %o1, 1
a0146210:  02 80 00 0b  be  0xa014623c
a0146214:  90 10 00 0b  mov  %o3, %o0
a0146218:  80 a2 60 01  cmp  %o1, 1
a014621c:  04 80 00 0e  ble  0xa0146254
a0146220:  80 a2 60 02  cmp  %o1, 2
a0146224:  02 80 00 09  be  0xa0146248
a0146228:  80 a2 60 03  cmp  %o1, 3
a014622c:  32 80 00 11  bne,a   0xa0146270
a0146230:  d2 06 60 04  ld  [ %i1 + 4 ], %o1
a0146234:  10 80 00 0d  b  0xa0146268
a0146238:  82 10 20 c1  mov  0xc1, %g1
a014623c:  82 10 20 b0  mov  0xb0, %g1
a0146240:  10 80 00 0b  b  0xa014626c
a0146244:  c2 27 bf ec  st  %g1, [ %fp + -20 ]
a0146248:  82 10 20 c0  mov  0xc0, %g1
a014624c:  10 80 00 08  b  0xa014626c
a0146250:  c2 27 bf ec  st  %g1, [ %fp + -20 ]
a0146254:  80 a2 60 00  cmp  %o1, 0
a0146258:  02 bf ff fa  be  0xa0146240
a014625c:  82 10 20 a0  mov  0xa0, %g1
a0146260:  10 80 00 04  b  0xa0146270
a0146264:  d2 06 60 04  ld  [ %i1 + 4 ], %o1
a0146268:  c2 27 bf ec  st  %g1, [ %fp + -20 ]
a014626c:  d2 06 60 04  ld  [ %i1 + 4 ], %o1
a0146270:  da 06 60 08  ld  [ %i1 + 8 ], %o5
a0146274:  d2 27 bf f0  st  %o1, [ %fp + -16 ]
a0146278:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a014627c:  90 0a 20 01  and  %o0, 1, %o0
a0146280:  94 0e a0 ff  and  %i2, 0xff, %o2
a0146284:  7f ff 58 92  call  0xa011c4cc
a0146288:  92 07 bf e8  add  %fp, -24, %o1
a014628c:  01 00 00 00  nop
a0146290:  81 c7 e0 08  ret
a0146294:  81 e8 00 00  restore
