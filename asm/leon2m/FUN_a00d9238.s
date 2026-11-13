# leon2m FUN_a00d9238 0xa00d9238-0xa00d934c (276 bytes)
a00d9238:  9d e3 bf 98  save  %sp, -104, %sp
a00d923c:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00d9240:  a0 16 22 90  or  %i0, 0x290, %l0	! 0xa802d290
a00d9244:  da 0c 20 1f  ldub  [ %l0 + 0x1f ], %o5
a00d9248:  80 a3 60 00  cmp  %o5, 0
a00d924c:  02 80 00 2f  be  0xa00d9308
a00d9250:  90 10 20 00  clr  %o0
a00d9254:  9a 16 22 90  or  %i0, 0x290, %o5
a00d9258:  d2 0b 60 1f  ldub  [ %o5 + 0x1f ], %o1
a00d925c:  80 a2 60 00  cmp  %o1, 0
a00d9260:  02 80 00 15  be  0xa00d92b4
a00d9264:  90 10 20 01  mov  1, %o0
a00d9268:  d6 03 60 a8  ld  [ %o5 + 0xa8 ], %o3
a00d926c:  15 00 00 10  sethi  %hi(0x4000), %o2
a00d9270:  80 8a c0 0a  btst  %o3, %o2
a00d9274:  02 80 00 10  be  0xa00d92b4
a00d9278:  01 00 00 00  nop
a00d927c:  90 10 20 00  clr  %o0	! 0x0
a00d9280:  40 01 c1 be  call  0xa0149978
a00d9284:  d2 0c 20 1e  ldub  [ %l0 + 0x1e ], %o1
a00d9288:  90 10 20 00  clr  %o0
a00d928c:  40 01 bb f7  call  0xa0148268
a00d9290:  92 10 20 01  mov  1, %o1
a00d9294:  d8 0c 20 1f  ldub  [ %l0 + 0x1f ], %o4
a00d9298:  80 a3 20 00  cmp  %o4, 0
a00d929c:  02 80 00 12  be  0xa00d92e4
a00d92a0:  90 10 20 01  mov  1, %o0
a00d92a4:  31 00 00 06  sethi  %hi(0x1800), %i0
a00d92a8:  b0 16 21 64  or  %i0, 0x164, %i0	! 0x1964
a00d92ac:  40 01 bc 2b  call  0xa0148358
a00d92b0:  81 e8 00 00  restore
a00d92b4:  40 01 b9 ce  call  0xa01479ec
a00d92b8:  01 00 00 00  nop
a00d92bc:  90 10 20 00  clr  %o0	! 0x0
a00d92c0:  40 01 c1 ae  call  0xa0149978
a00d92c4:  d2 0c 20 1e  ldub  [ %l0 + 0x1e ], %o1
a00d92c8:  90 10 20 00  clr  %o0
a00d92cc:  40 01 bb e7  call  0xa0148268
a00d92d0:  92 10 20 01  mov  1, %o1
a00d92d4:  d8 0c 20 1f  ldub  [ %l0 + 0x1f ], %o4
a00d92d8:  80 a3 20 00  cmp  %o4, 0
a00d92dc:  12 bf ff f2  bne  0xa00d92a4
a00d92e0:  90 10 20 01  mov  1, %o0
a00d92e4:  40 01 c1 a5  call  0xa0149978
a00d92e8:  d2 0c 20 1e  ldub  [ %l0 + 0x1e ], %o1
a00d92ec:  90 10 20 01  mov  1, %o0
a00d92f0:  92 10 20 01  mov  1, %o1
a00d92f4:  40 01 bb dd  call  0xa0148268
a00d92f8:  31 00 00 06  sethi  %hi(0x1800), %i0
a00d92fc:  b0 16 21 64  or  %i0, 0x164, %i0	! 0x1964
a00d9300:  40 01 bc 16  call  0xa0148358
a00d9304:  81 e8 00 00  restore
a00d9308:  40 01 aa 43  call  0xa0143c14
a00d930c:  01 00 00 00  nop
a00d9310:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d9314:  80 a2 20 0a  cmp  %o0, 0xa
a00d9318:  32 bf ff d0  bne,a   0xa00d9258
a00d931c:  9a 16 22 90  or  %i0, 0x290, %o5
a00d9320:  40 01 2d ba  call  0xa0124a08
a00d9324:  01 00 00 00  nop
a00d9328:  40 01 2d 61  call  0xa01248ac
a00d932c:  01 00 00 00  nop
a00d9330:  92 10 20 00  clr  %o1	! 0x0
a00d9334:  40 01 af 7e  call  0xa014512c
a00d9338:  90 10 20 00  clr  %o0
a00d933c:  67 fe cf 99  call  0x4008d1a0
a00d9340:  90 10 20 32  mov  0x32, %o0
a00d9344:  10 bf ff c5  b  0xa00d9258
a00d9348:  9a 16 22 90  or  %i0, 0x290, %o5
