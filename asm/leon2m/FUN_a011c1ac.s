# leon2m FUN_a011c1ac 0xa011c1ac-0xa011c338 (396 bytes)
a011c1ac:  9d e3 bf 98  save  %sp, -104, %sp
a011c1b0:  9a 0f 60 ff  and  %i5, 0xff, %o5
a011c1b4:  3b 2a 00 b2  sethi  %hi(0xa802c800), %i5
a011c1b8:  9e 03 40 0d  add  %o5, %o5, %o7
a011c1bc:  82 17 61 ca  or  %i5, 0x1ca, %g1
a011c1c0:  fa 10 40 0f  lduh  [ %g1 + %o7 ], %i5
a011c1c4:  b4 5e 80 1d  smul  %i2, %i5, %i2
a011c1c8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a011c1cc:  b2 06 40 1a  add  %i1, %i2, %i1
a011c1d0:  80 a6 20 01  cmp  %i0, 1
a011c1d4:  02 80 00 3a  be  0xa011c2bc
a011c1d8:  b4 10 00 1c  mov  %i4, %i2
a011c1dc:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011c1e0:  ba 10 20 40  mov  0x40, %i5
a011c1e4:  80 a3 60 00  cmp  %o5, 0
a011c1e8:  12 80 00 31  bne  0xa011c2ac
a011c1ec:  82 10 63 80  or  %g1, 0x380, %g1
a011c1f0:  fa 20 40 00  st  %i5, [ %g1 ]
a011c1f4:  82 10 20 9f  mov  0x9f, %g1
a011c1f8:  01 00 00 00  nop
a011c1fc:  82 80 7f ff  addcc  %g1, -1, %g1
a011c200:  1c bf ff fe  bpos  0xa011c1f8
a011c204:  80 a3 60 00  cmp  %o5, 0
a011c208:  b3 2e 60 10  sll  %i1, 0x10, %i1
a011c20c:  12 80 00 3d  bne  0xa011c300
a011c210:  bb 36 60 10  srl  %i1, 0x10, %i5
a011c214:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011c218:  b0 0f 60 ff  and  %i5, 0xff, %i0
a011c21c:  82 17 23 84  or  %i4, 0x384, %g1
a011c220:  f0 20 40 00  st  %i0, [ %g1 ]
a011c224:  b0 17 23 88  or  %i4, 0x388, %i0
a011c228:  bb 36 60 18  srl  %i1, 0x18, %i5
a011c22c:  fa 26 00 00  st  %i5, [ %i0 ]
a011c230:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a011c234:  b2 10 63 cc  or  %g1, 0x3cc, %i1	! 0xcf00bfcc
a011c238:  c0 26 40 00  clr  [ %i1 ]
a011c23c:  82 10 20 9f  mov  0x9f, %g1
a011c240:  01 00 00 00  nop
a011c244:  82 80 7f ff  addcc  %g1, -1, %g1
a011c248:  1c bf ff fe  bpos  0xa011c240
a011c24c:  01 00 00 00  nop
a011c250:  b6 0e e0 ff  and  %i3, 0xff, %i3
a011c254:  80 a6 e0 00  cmp  %i3, 0
a011c258:  02 80 00 36  be  0xa011c330
a011c25c:  ba 10 20 00  clr  %i5
a011c260:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011c264:  b8 0e a0 ff  and  %i2, 0xff, %i4
a011c268:  b2 16 23 a0  or  %i0, 0x3a0, %i1
a011c26c:  b4 16 23 8c  or  %i0, 0x38c, %i2
a011c270:  80 a3 60 00  cmp  %o5, 0
a011c274:  12 80 00 2c  bne  0xa011c324
a011c278:  01 00 00 00  nop
a011c27c:  f8 26 80 00  st  %i4, [ %i2 ]
a011c280:  82 10 20 9f  mov  0x9f, %g1
a011c284:  01 00 00 00  nop
a011c288:  82 80 7f ff  addcc  %g1, -1, %g1
a011c28c:  1c bf ff fe  bpos  0xa011c284
a011c290:  01 00 00 00  nop
a011c294:  ba 07 60 01  inc  %i5
a011c298:  82 0f 60 ff  and  %i5, 0xff, %g1
a011c29c:  80 a0 40 1b  cmp  %g1, %i3
a011c2a0:  0a bf ff f5  bcs  0xa011c274
a011c2a4:  80 a3 60 00  cmp  %o5, 0
a011c2a8:  30 80 00 22  b,a   0xa011c330
a011c2ac:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011c2b0:  ba 10 20 40  mov  0x40, %i5
a011c2b4:  10 bf ff cf  b  0xa011c1f0
a011c2b8:  82 17 23 94  or  %i4, 0x394, %g1
a011c2bc:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011c2c0:  ba 10 20 90  mov  0x90, %i5
a011c2c4:  80 a3 60 00  cmp  %o5, 0
a011c2c8:  02 80 00 05  be  0xa011c2dc
a011c2cc:  82 17 23 80  or  %i4, 0x380, %g1
a011c2d0:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011c2d4:  ba 10 20 90  mov  0x90, %i5
a011c2d8:  82 16 23 94  or  %i0, 0x394, %g1
a011c2dc:  fa 20 40 00  st  %i5, [ %g1 ]
a011c2e0:  82 10 20 9f  mov  0x9f, %g1
a011c2e4:  01 00 00 00  nop
a011c2e8:  82 80 7f ff  addcc  %g1, -1, %g1
a011c2ec:  1c bf ff fe  bpos  0xa011c2e4
a011c2f0:  80 a3 60 00  cmp  %o5, 0
a011c2f4:  b3 2e 60 10  sll  %i1, 0x10, %i1
a011c2f8:  02 bf ff c7  be  0xa011c214
a011c2fc:  bb 36 60 10  srl  %i1, 0x10, %i5
a011c300:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011c304:  b8 0f 60 ff  and  %i5, 0xff, %i4
a011c308:  82 16 23 98  or  %i0, 0x398, %g1
a011c30c:  f8 20 40 00  st  %i4, [ %g1 ]
a011c310:  b8 16 23 9c  or  %i0, 0x39c, %i4
a011c314:  bb 36 60 18  srl  %i1, 0x18, %i5
a011c318:  fa 27 00 00  st  %i5, [ %i4 ]
a011c31c:  10 bf ff c6  b  0xa011c234
a011c320:  03 33 c0 30  sethi  %hi(0xcf00c000), %g1
a011c324:  f8 26 40 00  st  %i4, [ %i1 ]
a011c328:  10 bf ff d7  b  0xa011c284
a011c32c:  82 10 20 9f  mov  0x9f, %g1
a011c330:  81 c7 e0 08  ret
a011c334:  81 e8 00 00  restore
