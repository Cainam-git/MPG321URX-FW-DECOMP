# leon2m FUN_a00f42b8 0xa00f42b8-0xa00f4434 (380 bytes)
a00f42b8:  9d e3 bf 98  save  %sp, -104, %sp
a00f42bc:  7f ff fc 9b  call  0xa00f3528
a00f42c0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f42c4:  a2 10 00 08  mov  %o0, %l1
a00f42c8:  83 2e 60 10  sll  %i1, 0x10, %g1
a00f42cc:  9b 2c 60 10  sll  %l1, 0x10, %o5
a00f42d0:  a7 30 60 10  srl  %g1, 0x10, %l3
a00f42d4:  a9 33 60 10  srl  %o5, 0x10, %l4
a00f42d8:  80 a4 c0 14  cmp  %l3, %l4
a00f42dc:  02 80 00 26  be  0xa00f4374
a00f42e0:  a5 2c 60 10  sll  %l1, 0x10, %l2
a00f42e4:  80 a4 c0 14  cmp  %l3, %l4
a00f42e8:  08 80 00 33  bleu  0xa00f43b4
a00f42ec:  96 04 7f fc  add  %l1, -4, %o3
a00f42f0:  90 04 60 04  add  %l1, 4, %o0
a00f42f4:  95 2a 20 10  sll  %o0, 0x10, %o2
a00f42f8:  93 32 a0 10  srl  %o2, 0x10, %o1
a00f42fc:  80 a2 40 13  cmp  %o1, %l3
a00f4300:  18 80 00 32  bgu  0xa00f43c8
a00f4304:  a2 10 00 08  mov  %o0, %l1
a00f4308:  67 fe 67 e7  call  0x4008e2a4
a00f430c:  a5 2c 60 10  sll  %l1, 0x10, %l2
a00f4310:  a1 34 a0 10  srl  %l2, 0x10, %l0
a00f4314:  92 10 00 10  mov  %l0, %o1
a00f4318:  7f ff fc e8  call  0xa00f36b8
a00f431c:  90 10 00 18  mov  %i0, %o0
a00f4320:  40 00 12 ad  call  0xa00f8dd4
a00f4324:  90 10 00 18  mov  %i0, %o0
a00f4328:  83 2a 20 10  sll  %o0, 0x10, %g1
a00f432c:  9b 30 60 10  srl  %g1, 0x10, %o5
a00f4330:  80 a3 40 10  cmp  %o5, %l0
a00f4334:  18 80 00 27  bgu  0xa00f43d0
a00f4338:  a0 10 00 11  mov  %l1, %l0
a00f433c:  80 a6 20 00  cmp  %i0, 0
a00f4340:  12 80 00 07  bne  0xa00f435c
a00f4344:  01 00 00 00  nop
a00f4348:  40 00 b1 19  call  0xa01207ac
a00f434c:  90 10 20 00  clr  %o0	! 0x0
a00f4350:  80 8a 20 ff  btst  0xff, %o0
a00f4354:  12 80 00 23  bne  0xa00f43e0
a00f4358:  91 2c 20 10  sll  %l0, 0x10, %o0
a00f435c:  40 00 b0 b7  call  0xa0120638
a00f4360:  01 00 00 00  nop
a00f4364:  92 0a 20 ff  and  %o0, 0xff, %o1
a00f4368:  80 a2 40 18  cmp  %o1, %i0
a00f436c:  02 80 00 22  be  0xa00f43f4
a00f4370:  01 00 00 00  nop
a00f4374:  97 34 a0 10  srl  %l2, 0x10, %o3
a00f4378:  80 a2 c0 13  cmp  %o3, %l3
a00f437c:  12 bf ff d8  bne  0xa00f42dc
a00f4380:  80 a4 c0 14  cmp  %l3, %l4
a00f4384:  80 a6 20 00  cmp  %i0, 0
a00f4388:  12 80 00 28  bne  0xa00f4428
a00f438c:  25 33 c0 46  sethi  %hi(0xcf011800), %l2
a00f4390:  e2 04 80 00  ld  [ %l2 ], %l1
a00f4394:  80 8c 60 10  btst  0x10, %l1
a00f4398:  02 80 00 24  be  0xa00f4428
a00f439c:  27 2a 00 ad  sethi  %hi(0xa802b400), %l3
a00f43a0:  c2 04 e3 a8  ld  [ %l3 + 0x3a8 ], %g1	! 0xa802b7a8
a00f43a4:  80 a0 60 00  cmp  %g1, 0
a00f43a8:  02 80 00 20  be  0xa00f4428
a00f43ac:  01 00 00 00  nop
a00f43b0:  30 80 00 1c  b,a   0xa00f4420
a00f43b4:  9f 2a e0 10  sll  %o3, 0x10, %o7
a00f43b8:  99 33 e0 10  srl  %o7, 0x10, %o4
a00f43bc:  80 a3 00 13  cmp  %o4, %l3
a00f43c0:  1a bf ff d2  bcc  0xa00f4308
a00f43c4:  a2 10 00 0b  mov  %o3, %l1
a00f43c8:  10 bf ff d0  b  0xa00f4308
a00f43cc:  a2 10 00 19  mov  %i1, %l1
a00f43d0:  40 00 12 81  call  0xa00f8dd4
a00f43d4:  90 10 00 18  mov  %i0, %o0
a00f43d8:  10 bf ff d9  b  0xa00f433c
a00f43dc:  a0 02 20 14  add  %o0, 0x14, %l0
a00f43e0:  93 32 20 10  srl  %o0, 0x10, %o1
a00f43e4:  40 00 ae d1  call  0xa011ff28
a00f43e8:  90 10 20 00  clr  %o0
a00f43ec:  10 bf ff e3  b  0xa00f4378
a00f43f0:  97 34 a0 10  srl  %l2, 0x10, %o3
a00f43f4:  40 00 b0 ee  call  0xa01207ac
a00f43f8:  90 10 20 01  mov  1, %o0
a00f43fc:  80 8a 20 ff  btst  0xff, %o0
a00f4400:  22 bf ff de  be,a   0xa00f4378
a00f4404:  97 34 a0 10  srl  %l2, 0x10, %o3
a00f4408:  95 2c 20 10  sll  %l0, 0x10, %o2
a00f440c:  93 32 a0 10  srl  %o2, 0x10, %o1
a00f4410:  40 00 ae c6  call  0xa011ff28
a00f4414:  90 10 20 01  mov  1, %o0
a00f4418:  10 bf ff d8  b  0xa00f4378
a00f441c:  97 34 a0 10  srl  %l2, 0x10, %o3
a00f4420:  9f c0 40 00  call  %g1
a00f4424:  01 00 00 00  nop
a00f4428:  01 00 00 00  nop
a00f442c:  81 c7 e0 08  ret
a00f4430:  81 e8 00 00  restore
