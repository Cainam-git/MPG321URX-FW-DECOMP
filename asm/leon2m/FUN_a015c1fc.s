# leon2m FUN_a015c1fc 0xa015c1fc-0xa015c35c (352 bytes)
a015c1fc:  9d e3 bf 58  save  %sp, -168, %sp
a015c200:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015c204:  80 88 60 02  btst  2, %g1
a015c208:  22 80 00 08  be,a   0xa015c228
a015c20c:  d2 56 20 0e  ldsh  [ %i0 + 0xe ], %o1
a015c210:  9a 06 20 43  add  %i0, 0x43, %o5
a015c214:  82 10 20 01  mov  1, %g1
a015c218:  c2 26 20 14  st  %g1, [ %i0 + 0x14 ]
a015c21c:  da 26 20 10  st  %o5, [ %i0 + 0x10 ]
a015c220:  10 80 00 4d  b  0xa015c354
a015c224:  da 26 00 00  st  %o5, [ %i0 ]
a015c228:  80 a2 60 00  cmp  %o1, 0
a015c22c:  06 80 00 16  bl  0xa015c284
a015c230:  21 2a 00 aa  sethi  %hi(0xa802a800), %l0
a015c234:  d0 04 22 18  ld  [ %l0 + 0x218 ], %o0	! 0xa802aa18
a015c238:  40 00 08 74  call  0xa015e408
a015c23c:  94 07 bf b8  add  %fp, -72, %o2
a015c240:  80 a2 20 00  cmp  %o0, 0
a015c244:  06 80 00 42  bl  0xa015c34c
a015c248:  d8 17 bf c0  lduh  [ %fp + -64 ], %o4
a015c24c:  1b 00 00 3c  sethi  %hi(0xf000), %o5
a015c250:  98 0b 00 0d  and  %o4, %o5, %o4
a015c254:  03 00 00 08  sethi  %hi(0x2000), %g1
a015c258:  82 1b 00 01  xor  %o4, %g1, %g1
a015c25c:  80 a0 00 01  cmp  %g0, %g1
a015c260:  a4 60 3f ff  subx  %g0, -1, %l2
a015c264:  03 00 00 20  sethi  %hi(0x8000), %g1
a015c268:  80 a3 00 01  cmp  %o4, %g1
a015c26c:  02 80 00 25  be  0xa015c300
a015c270:  a2 10 24 00  mov  0x400, %l1
a015c274:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015c278:  82 10 68 00  or  %g1, 0x800, %g1
a015c27c:  10 80 00 06  b  0xa015c294
a015c280:  c2 36 20 0c  sth  %g1, [ %i0 + 0xc ]
a015c284:  82 10 68 00  or  %g1, 0x800, %g1
a015c288:  c2 36 20 0c  sth  %g1, [ %i0 + 0xc ]
a015c28c:  a4 10 20 00  clr  %l2
a015c290:  a2 10 24 00  mov  0x400, %l1
a015c294:  d0 04 22 18  ld  [ %l0 + 0x218 ], %o0
a015c298:  40 00 00 31  call  0xa015c35c
a015c29c:  92 10 24 00  mov  0x400, %o1
a015c2a0:  80 a2 20 00  cmp  %o0, 0
a015c2a4:  02 80 00 21  be  0xa015c328
a015c2a8:  03 2a 00 aa  sethi  %hi(0xa802a800), %g1
a015c2ac:  d8 00 62 18  ld  [ %g1 + 0x218 ], %o4	! 0xa802aa18
a015c2b0:  da 16 20 0c  lduh  [ %i0 + 0xc ], %o5
a015c2b4:  03 00 03 ed  sethi  %hi(0xfb400), %g1
a015c2b8:  9a 13 60 80  or  %o5, 0x80, %o5
a015c2bc:  82 10 61 c4  or  %g1, 0x1c4, %g1
a015c2c0:  c2 23 20 3c  st  %g1, [ %o4 + 0x3c ]
a015c2c4:  da 36 20 0c  sth  %o5, [ %i0 + 0xc ]
a015c2c8:  d0 26 20 10  st  %o0, [ %i0 + 0x10 ]
a015c2cc:  e2 26 20 14  st  %l1, [ %i0 + 0x14 ]
a015c2d0:  80 a4 a0 00  cmp  %l2, 0
a015c2d4:  02 80 00 20  be  0xa015c354
a015c2d8:  d0 26 00 00  st  %o0, [ %i0 ]
a015c2dc:  40 00 09 46  call  0xa015e7f4
a015c2e0:  d0 56 20 0e  ldsh  [ %i0 + 0xe ], %o0
a015c2e4:  80 a2 20 00  cmp  %o0, 0
a015c2e8:  02 80 00 1b  be  0xa015c354
a015c2ec:  01 00 00 00  nop
a015c2f0:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015c2f4:  82 10 60 01  or  %g1, 1, %g1
a015c2f8:  10 80 00 17  b  0xa015c354
a015c2fc:  c2 36 20 0c  sth  %g1, [ %i0 + 0xc ]
a015c300:  03 00 03 f8  sethi  %hi(0xfe000), %g1
a015c304:  da 06 20 28  ld  [ %i0 + 0x28 ], %o5
a015c308:  82 10 60 08  or  %g1, 8, %g1
a015c30c:  80 a3 40 01  cmp  %o5, %g1
a015c310:  12 bf ff da  bne  0xa015c278
a015c314:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015c318:  82 10 64 00  or  %g1, 0x400, %g1
a015c31c:  c2 36 20 0c  sth  %g1, [ %i0 + 0xc ]
a015c320:  10 bf ff dd  b  0xa015c294
a015c324:  e2 26 20 4c  st  %l1, [ %i0 + 0x4c ]
a015c328:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015c32c:  98 06 20 43  add  %i0, 0x43, %o4
a015c330:  82 10 60 02  or  %g1, 2, %g1
a015c334:  9a 10 20 01  mov  1, %o5
a015c338:  da 26 20 14  st  %o5, [ %i0 + 0x14 ]
a015c33c:  c2 36 20 0c  sth  %g1, [ %i0 + 0xc ]
a015c340:  d8 26 20 10  st  %o4, [ %i0 + 0x10 ]
a015c344:  10 80 00 04  b  0xa015c354
a015c348:  d8 26 00 00  st  %o4, [ %i0 ]
a015c34c:  10 bf ff ce  b  0xa015c284
a015c350:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015c354:  81 c7 e0 08  ret
a015c358:  81 e8 00 00  restore
