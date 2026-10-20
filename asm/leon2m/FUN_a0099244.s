# leon2m FUN_a0099244 0xa0099244-0xa009934c (264 bytes)
a0099244:  9d e3 bf 98  save  %sp, -104, %sp
a0099248:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a009924c:  a0 12 62 90  or  %o1, 0x290, %l0	! 0xa802d290
a0099250:  d8 04 20 ac  ld  [ %l0 + 0xac ], %o4
a0099254:  9b 33 20 14  srl  %o4, 0x14, %o5
a0099258:  82 38 00 0d  xnor  %g0, %o5, %g1
a009925c:  96 08 60 01  and  %g1, 1, %o3
a0099260:  1f 00 04 00  sethi  %hi(0x100000), %o7
a0099264:  90 2b 00 0f  andn  %o4, %o7, %o0
a0099268:  95 2a e0 14  sll  %o3, 0x14, %o2
a009926c:  9a 12 00 0a  or  %o0, %o2, %o5
a0099270:  93 33 60 14  srl  %o5, 0x14, %o1
a0099274:  90 10 20 06  mov  6, %o0
a0099278:  92 0a 60 01  and  %o1, 1, %o1
a009927c:  40 00 30 69  call  0xa00a5420
a0099280:  da 24 20 ac  st  %o5, [ %l0 + 0xac ]
a0099284:  c2 0c 20 1f  ldub  [ %l0 + 0x1f ], %g1
a0099288:  80 a0 60 00  cmp  %g1, 0
a009928c:  12 80 00 08  bne  0xa00992ac
a0099290:  90 10 20 00  clr  %o0
a0099294:  40 02 ac da  call  0xa01445fc
a0099298:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a009929c:  80 8a 20 ff  btst  0xff, %o0
a00992a0:  12 80 00 25  bne  0xa0099334
a00992a4:  90 10 20 00  clr  %o0
a00992a8:  30 80 00 10  b,a   0xa00992e8
a00992ac:  40 00 ff d4  call  0xa00d91fc
a00992b0:  c0 2c 20 1f  clrb  [ %l0 + 0x1f ]
a00992b4:  90 10 20 00  clr  %o0
a00992b8:  40 02 bb ec  call  0xa0148268
a00992bc:  92 10 20 01  mov  1, %o1
a00992c0:  92 10 20 01  mov  1, %o1
a00992c4:  40 02 bb e9  call  0xa0148268
a00992c8:  90 10 20 01  mov  1, %o0
a00992cc:  40 01 03 e2  call  0xa00da254
a00992d0:  01 00 00 00  nop
a00992d4:  40 02 ac ca  call  0xa01445fc
a00992d8:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a00992dc:  80 8a 20 ff  btst  0xff, %o0
a00992e0:  12 80 00 15  bne  0xa0099334
a00992e4:  90 10 20 00  clr  %o0
a00992e8:  40 00 ff c5  call  0xa00d91fc
a00992ec:  01 00 00 00  nop
a00992f0:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a00992f4:  80 a2 20 05  cmp  %o0, 5
a00992f8:  90 10 20 10  mov  0x10, %o0
a00992fc:  02 80 00 0a  be  0xa0099324
a0099300:  92 10 20 01  mov  1, %o1
a0099304:  90 10 20 00  clr  %o0
a0099308:  40 02 bb d8  call  0xa0148268
a009930c:  92 10 20 01  mov  1, %o1
a0099310:  90 10 20 01  mov  1, %o0
a0099314:  40 02 bb d5  call  0xa0148268
a0099318:  92 10 20 01  mov  1, %o1
a009931c:  10 80 00 07  b  0xa0099338
a0099320:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a0099324:  40 02 a9 ad  call  0xa01439d8
a0099328:  01 00 00 00  nop
a009932c:  10 bf ff f7  b  0xa0099308
a0099330:  90 10 20 00  clr  %o0	! 0x0
a0099334:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a0099338:  d6 0c 20 8e  ldub  [ %l0 + 0x8e ], %o3	! 0xa802b08e
a009933c:  94 12 e0 02  or  %o3, 2, %o2
a0099340:  d4 2c 20 8e  stb  %o2, [ %l0 + 0x8e ]
a0099344:  81 c7 e0 08  ret
a0099348:  81 e8 00 00  restore
