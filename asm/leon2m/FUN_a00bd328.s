# leon2m FUN_a00bd328 0xa00bd328-0xa00bd4a4 (380 bytes)
a00bd328:  9d e3 bf 98  save  %sp, -104, %sp
a00bd32c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bd330:  d4 0b 62 9c  ldub  [ %o5 + 0x29c ], %o2	! 0xa802d29c
a00bd334:  11 14 7a e1  sethi  %hi(0x51eb8400), %o0
a00bd338:  b2 0a a0 ff  and  %o2, 0xff, %i1
a00bd33c:  82 12 21 1f  or  %o0, 0x11f, %g1
a00bd340:  80 56 40 01  umul  %i1, %g1, %g0
a00bd344:  97 40 00 00  rd  %y, %o3
a00bd348:  b3 32 e0 05  srl  %o3, 5, %i1
a00bd34c:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00bd350:  a0 5e a0 64  smul  %i2, 0x64, %l0
a00bd354:  b4 22 80 10  sub  %o2, %l0, %i2
a00bd358:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a00bd35c:  92 0e a0 ff  and  %i2, 0xff, %o1
a00bd360:  9e 13 20 cd  or  %o4, 0xcd, %o7
a00bd364:  80 52 40 0f  umul  %o1, %o7, %g0
a00bd368:  9b 40 00 00  rd  %y, %o5
a00bd36c:  9f 33 60 03  srl  %o5, 3, %o7
a00bd370:  90 0b e0 ff  and  %o7, 0xff, %o0
a00bd374:  83 2a 20 02  sll  %o0, 2, %g1
a00bd378:  a0 00 40 08  add  %g1, %o0, %l0
a00bd37c:  98 04 00 10  add  %l0, %l0, %o4
a00bd380:  92 26 80 0c  sub  %i2, %o4, %o1
a00bd384:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bd388:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00bd38c:  9a 03 e0 30  add  %o7, 0x30, %o5
a00bd390:  94 02 60 30  add  %o1, 0x30, %o2
a00bd394:  96 06 60 30  add  %i1, 0x30, %o3
a00bd398:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a00bd39c:  d6 2c 20 07  stb  %o3, [ %l0 + 7 ]
a00bd3a0:  d4 2c 20 09  stb  %o2, [ %l0 + 9 ]
a00bd3a4:  92 10 20 00  clr  %o1
a00bd3a8:  40 02 5c a5  call  0xa015463c
a00bd3ac:  90 10 20 27  mov  0x27, %o0
a00bd3b0:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bd3b4:  90 10 20 62  mov  0x62, %o0
a00bd3b8:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bd3bc:  92 10 20 02  mov  2, %o1
a00bd3c0:  40 02 5c 9f  call  0xa015463c
a00bd3c4:  90 10 20 27  mov  0x27, %o0
a00bd3c8:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bd3cc:  92 10 20 03  mov  3, %o1
a00bd3d0:  40 02 5c 9b  call  0xa015463c
a00bd3d4:  90 10 20 27  mov  0x27, %o0
a00bd3d8:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bd3dc:  92 10 20 04  mov  4, %o1
a00bd3e0:  40 02 5c 97  call  0xa015463c
a00bd3e4:  90 10 20 27  mov  0x27, %o0
a00bd3e8:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bd3ec:  92 10 20 05  mov  5, %o1
a00bd3f0:  40 02 5c 93  call  0xa015463c
a00bd3f4:  90 10 20 27  mov  0x27, %o0
a00bd3f8:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bd3fc:  92 10 20 06  mov  6, %o1
a00bd400:  40 02 5c 8f  call  0xa015463c
a00bd404:  90 10 20 27  mov  0x27, %o0
a00bd408:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bd40c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bd410:  82 10 20 0d  mov  0xd, %g1
a00bd414:  9a 13 20 40  or  %o4, 0x40, %o5
a00bd418:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00bd41c:  80 a6 20 02  cmp  %i0, 2
a00bd420:  02 80 00 12  be  0xa00bd468
a00bd424:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bd428:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bd42c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bd430:  96 12 a0 98  or  %o2, 0x98, %o3
a00bd434:  80 a6 20 03  cmp  %i0, 3
a00bd438:  02 80 00 10  be  0xa00bd478
a00bd43c:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bd440:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00bd444:  c0 2a a0 9c  clrb  [ %o2 + 0x9c ]	! 0xa802b09c
a00bd448:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bd44c:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bd450:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bd454:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bd458:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bd45c:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bd460:  40 02 2c e2  call  0xa01487e8
a00bd464:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd468:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00bd46c:  c0 2a 60 9a  clrb  [ %o1 + 0x9a ]	! 0xa802b09a
a00bd470:  10 bf ff f7  b  0xa00bd44c
a00bd474:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bd478:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bd47c:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]	! 0xa802b098
a00bd480:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bd484:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bd488:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bd48c:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bd490:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bd494:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bd498:  40 02 2c d4  call  0xa01487e8
a00bd49c:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd4a0:  01 00 00 00  nop
