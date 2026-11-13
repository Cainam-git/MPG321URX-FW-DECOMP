# leon2m FUN_a00da254 0xa00da254-0xa00da4b8 (516 bytes)
a00da254:  9d e3 bf 78  save  %sp, -136, %sp
a00da258:  90 10 20 02  mov  2, %o0
a00da25c:  7f ff fd e7  call  0xa00d99f8
a00da260:  92 10 20 00  clr  %o1
a00da264:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00da268:  d8 10 60 32  lduh  [ %g1 + 0x32 ], %o4	! 0xa802d032
a00da26c:  1b 00 00 08  sethi  %hi(0x2000), %o5
a00da270:  80 8b 40 0c  btst  %o5, %o4
a00da274:  a0 10 20 00  clr  %l0
a00da278:  02 80 00 69  be  0xa00da41c
a00da27c:  aa 10 20 00  clr  %l5
a00da280:  2d 2a 00 b4  sethi  %hi(0xa802d000), %l6
a00da284:  90 15 a2 90  or  %l6, 0x290, %o0	! 0xa802d290
a00da288:  c2 0a 20 1f  ldub  [ %o0 + 0x1f ], %g1
a00da28c:  80 a0 60 07  cmp  %g1, 7
a00da290:  18 80 00 0b  bgu  0xa00da2bc
a00da294:  27 00 06 62  sethi  %hi(0x198800), %l3
a00da298:  1f 00 01 ce  sethi  %hi(0x73800), %o7
a00da29c:  95 28 60 02  sll  %g1, 2, %o2
a00da2a0:  96 13 e3 7c  or  %o7, 0x37c, %o3
a00da2a4:  d2 02 c0 0a  ld  [ %o3 + %o2 ], %o1
a00da2a8:  81 c2 40 00  jmp  %o1
a00da2ac:  01 00 00 00  nop
a00da2b0:  aa 10 20 03  mov  3, %l5	! 0x3
a00da2b4:  a0 10 20 03  mov  3, %l0
a00da2b8:  27 00 06 62  sethi  %hi(0x198800), %l3
a00da2bc:  90 14 e0 d8  or  %l3, 0xd8, %o0	! 0x1988d8
a00da2c0:  40 00 13 ac  call  0xa00df170
a00da2c4:  92 10 00 15  mov  %l5, %o1
a00da2c8:  a4 0c 20 ff  and  %l0, 0xff, %l2
a00da2cc:  80 a4 a0 00  cmp  %l2, 0
a00da2d0:  02 80 00 14  be  0xa00da320
a00da2d4:  a2 10 20 00  clr  %l1
a00da2d8:  a0 10 20 00  clr  %l0
a00da2dc:  a8 07 bf e8  add  %fp, -24, %l4
a00da2e0:  a6 07 bf d8  add  %fp, -40, %l3
a00da2e4:  90 10 00 10  mov  %l0, %o0
a00da2e8:  7f ff ef 5b  call  0xa00d6054
a00da2ec:  92 10 00 14  mov  %l4, %o1
a00da2f0:  d8 1f bf e8  ldd  [ %fp + -24 ], %o4
a00da2f4:  d4 1f bf f0  ldd  [ %fp + -16 ], %o2
a00da2f8:  90 10 00 10  mov  %l0, %o0
a00da2fc:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a00da300:  d4 3f bf e0  std  %o2, [ %fp + -32 ]
a00da304:  92 10 00 13  mov  %l3, %o1
a00da308:  40 01 be 21  call  0xa0149b8c
a00da30c:  a2 04 60 01  inc  %l1
a00da310:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00da314:  80 a4 00 12  cmp  %l0, %l2
a00da318:  0a bf ff f4  bcs  0xa00da2e8
a00da31c:  90 10 00 10  mov  %l0, %o0
a00da320:  40 01 be 34  call  0xa0149bf0
a00da324:  90 10 00 15  mov  %l5, %o0
a00da328:  82 05 7f fd  add  %l5, -3, %g1
a00da32c:  80 a0 60 02  cmp  %g1, 2
a00da330:  98 40 20 00  addx  %g0, 0, %o4
a00da334:  9a 1d 60 06  xor  %l5, 6, %o5
a00da338:  80 a0 00 0d  cmp  %g0, %o5
a00da33c:  a8 60 3f ff  subx  %g0, -1, %l4
a00da340:  80 93 00 14  orcc  %o4, %l4, %g0
a00da344:  12 80 00 1b  bne  0xa00da3b0
a00da348:  80 a5 60 07  cmp  %l5, 7
a00da34c:  02 80 00 19  be  0xa00da3b0
a00da350:  90 10 20 01  mov  1, %o0
a00da354:  40 01 c1 28  call  0xa014a7f4
a00da358:  a0 15 a2 90  or  %l6, 0x290, %l0
a00da35c:  ea 0c 20 1f  ldub  [ %l0 + 0x1f ], %l5
a00da360:  80 a5 60 00  cmp  %l5, 0
a00da364:  12 80 00 1a  bne  0xa00da3cc
a00da368:  01 00 00 00  nop
a00da36c:  7f ff ff 1c  call  0xa00d9fdc
a00da370:  90 10 20 01  mov  1, %o0	! 0x1
a00da374:  40 01 a6 28  call  0xa0143c14
a00da378:  90 10 20 00  clr  %o0
a00da37c:  ac 0a 20 ff  and  %o0, 0xff, %l6
a00da380:  80 a5 a0 0a  cmp  %l6, 0xa
a00da384:  22 80 00 05  be,a   0xa00da398
a00da388:  d2 0c 20 1e  ldub  [ %l0 + 0x1e ], %o1
a00da38c:  40 01 a8 40  call  0xa014448c
a00da390:  90 10 20 00  clr  %o0
a00da394:  92 0a 20 ff  and  %o0, 0xff, %o1
a00da398:  40 01 bd 78  call  0xa0149978
a00da39c:  90 10 20 01  mov  1, %o0
a00da3a0:  40 01 ab ea  call  0xa0145348
a00da3a4:  90 10 20 00  clr  %o0
a00da3a8:  10 80 00 3f  b  0xa00da4a4
a00da3ac:  90 10 20 00  clr  %o0
a00da3b0:  40 01 c1 11  call  0xa014a7f4
a00da3b4:  90 10 20 00  clr  %o0
a00da3b8:  a0 15 a2 90  or  %l6, 0x290, %l0
a00da3bc:  ea 0c 20 1f  ldub  [ %l0 + 0x1f ], %l5
a00da3c0:  80 a5 60 00  cmp  %l5, 0
a00da3c4:  02 bf ff ea  be  0xa00da36c
a00da3c8:  01 00 00 00  nop
a00da3cc:  40 01 c0 c5  call  0xa014a6e0
a00da3d0:  90 10 20 0c  mov  0xc, %o0	! 0xc
a00da3d4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00da3d8:  80 a2 20 01  cmp  %o0, 1
a00da3dc:  02 80 00 2b  be  0xa00da488
a00da3e0:  90 10 20 0c  mov  0xc, %o0
a00da3e4:  40 01 c0 bf  call  0xa014a6e0
a00da3e8:  90 10 20 0d  mov  0xd, %o0
a00da3ec:  92 0a 20 ff  and  %o0, 0xff, %o1
a00da3f0:  80 a2 60 01  cmp  %o1, 1
a00da3f4:  22 80 00 25  be,a   0xa00da488
a00da3f8:  90 10 20 0c  mov  0xc, %o0
a00da3fc:  94 15 a2 90  or  %l6, 0x290, %o2
a00da400:  d2 0a a0 20  ldub  [ %o2 + 0x20 ], %o1
a00da404:  40 01 bd 5d  call  0xa0149978
a00da408:  90 10 20 01  mov  1, %o0
a00da40c:  40 01 ab cf  call  0xa0145348
a00da410:  90 10 20 01  mov  1, %o0
a00da414:  10 80 00 24  b  0xa00da4a4
a00da418:  90 10 20 01  mov  1, %o0
a00da41c:  90 10 20 04  mov  4, %o0
a00da420:  92 10 20 01  mov  1, %o1
a00da424:  40 01 c1 2c  call  0xa014a8d4
a00da428:  94 10 25 dc  mov  0x5dc, %o2
a00da42c:  10 bf ff 96  b  0xa00da284
a00da430:  2d 2a 00 b4  sethi  %hi(0xa802d000), %l6
a00da434:  aa 10 20 06  mov  6, %l5
a00da438:  10 bf ff a0  b  0xa00da2b8
a00da43c:  a0 10 20 03  mov  3, %l0
a00da440:  7f fe a4 e9  call  0xa00837e4
a00da444:  27 00 06 62  sethi  %hi(0x198800), %l3
a00da448:  a4 0a 20 ff  and  %o0, 0xff, %l2
a00da44c:  a2 1c a0 01  xor  %l2, 1, %l1
a00da450:  80 a0 00 11  cmp  %g0, %l1
a00da454:  a0 40 20 00  addx  %g0, 0, %l0
a00da458:  aa 04 00 10  add  %l0, %l0, %l5
a00da45c:  10 bf ff 98  b  0xa00da2bc
a00da460:  a0 10 20 01  mov  1, %l0
a00da464:  aa 10 20 01  mov  1, %l5
a00da468:  10 bf ff 94  b  0xa00da2b8
a00da46c:  a0 10 20 02  mov  2, %l0
a00da470:  aa 10 20 05  mov  5, %l5
a00da474:  10 bf ff 91  b  0xa00da2b8
a00da478:  a0 10 20 02  mov  2, %l0
a00da47c:  aa 10 20 07  mov  7, %l5
a00da480:  10 bf ff 8e  b  0xa00da2b8
a00da484:  a0 10 20 04  mov  4, %l0
a00da488:  40 01 c0 73  call  0xa014a654
a00da48c:  92 10 20 00  clr  %o1
a00da490:  90 10 20 0d  mov  0xd, %o0
a00da494:  40 01 c0 70  call  0xa014a654
a00da498:  92 10 20 00  clr  %o1
a00da49c:  10 bf ff d9  b  0xa00da400
a00da4a0:  94 15 a2 90  or  %l6, 0x290, %o2
a00da4a4:  40 01 ab ac  call  0xa0145354
a00da4a8:  01 00 00 00  nop
a00da4ac:  01 00 00 00  nop
a00da4b0:  81 c7 e0 08  ret
a00da4b4:  81 e8 00 00  restore
