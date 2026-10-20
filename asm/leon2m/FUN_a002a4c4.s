# leon2m FUN_a002a4c4 0xa002a4c4-0xa002a5e4 (288 bytes)
a002a4c4:  9d e3 bf 98  save  %sp, -104, %sp
a002a4c8:  17 27 c0 00  sethi  %hi(0x9f000000), %o3
a002a4cc:  90 12 e0 90  or  %o3, 0x90, %o0	! 0x9f000090
a002a4d0:  92 10 20 00  clr  %o1
a002a4d4:  40 00 07 65  call  0xa002c268
a002a4d8:  15 00 00 04  sethi  %hi(0x1000), %o2
a002a4dc:  13 00 00 04  sethi  %hi(0x1000), %o1
a002a4e0:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a002a4e4:  94 10 00 09  mov  %o1, %o2
a002a4e8:  40 00 07 60  call  0xa002c268
a002a4ec:  90 14 60 28  or  %l1, 0x28, %o0
a002a4f0:  40 00 07 58  call  0xa002c250
a002a4f4:  90 14 60 9c  or  %l1, 0x9c, %o0
a002a4f8:  a4 10 00 08  mov  %o0, %l2
a002a4fc:  40 00 07 55  call  0xa002c250
a002a500:  90 14 60 64  or  %l1, 0x64, %o0
a002a504:  a0 2c 80 08  andn  %l2, %o0, %l0
a002a508:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a002a50c:  92 12 a3 ff  or  %o2, 0x3ff, %o1	! 0xffff
a002a510:  91 32 20 10  srl  %o0, 0x10, %o0
a002a514:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a002a518:  a4 0a 00 09  and  %o0, %o1, %l2
a002a51c:  a0 0c 00 09  and  %l0, %o1, %l0
a002a520:  b0 10 61 70  or  %g1, 0x170, %i0
a002a524:  10 80 00 0a  b  0xa002a54c
a002a528:  b2 10 20 00  clr  %i1
a002a52c:  9f c0 40 00  call  %g1
a002a530:  b2 06 60 01  inc  %i1
a002a534:  92 10 00 1a  mov  %i2, %o1
a002a538:  40 00 07 49  call  0xa002c25c
a002a53c:  90 14 60 9c  or  %l1, 0x9c, %o0
a002a540:  80 a6 60 09  cmp  %i1, 9
a002a544:  18 80 00 17  bgu  0xa002a5a0
a002a548:  b0 06 20 04  add  %i0, 4, %i0
a002a54c:  98 10 20 01  mov  1, %o4
a002a550:  b5 2b 00 19  sll  %o4, %i1, %i2
a002a554:  80 8e 80 10  btst  %i2, %l0
a002a558:  22 bf ff fa  be,a   0xa002a540
a002a55c:  b2 06 60 01  inc  %i1
a002a560:  c2 06 23 00  ld  [ %i0 + 0x300 ], %g1
a002a564:  80 a0 60 00  cmp  %g1, 0
a002a568:  22 bf ff f6  be,a   0xa002a540
a002a56c:  b2 06 60 01  inc  %i1
a002a570:  92 10 00 1a  mov  %i2, %o1
a002a574:  80 8e 80 12  btst  %i2, %l2
a002a578:  12 bf ff ed  bne  0xa002a52c
a002a57c:  90 14 60 9c  or  %l1, 0x9c, %o0
a002a580:  40 00 07 37  call  0xa002c25c
a002a584:  b2 06 60 01  inc  %i1
a002a588:  da 06 23 00  ld  [ %i0 + 0x300 ], %o5
a002a58c:  9f c3 40 00  call  %o5
a002a590:  b0 06 20 04  add  %i0, 4, %i0
a002a594:  80 a6 60 09  cmp  %i1, 9
a002a598:  08 bf ff ee  bleu  0xa002a550
a002a59c:  98 10 20 01  mov  1, %o4
a002a5a0:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a002a5a4:  90 14 60 34  or  %l1, 0x34, %o0	! 0x9f020034
a002a5a8:  40 00 07 2d  call  0xa002c25c
a002a5ac:  13 00 00 04  sethi  %hi(0x1000), %o1
a002a5b0:  31 27 c0 00  sethi  %hi(0x9f000000), %i0
a002a5b4:  90 16 20 9c  or  %i0, 0x9c, %o0	! 0x9f00009c
a002a5b8:  40 00 07 29  call  0xa002c25c
a002a5bc:  13 00 00 04  sethi  %hi(0x1000), %o1
a002a5c0:  15 00 00 04  sethi  %hi(0x1000), %o2
a002a5c4:  b2 10 00 0a  mov  %o2, %i1
a002a5c8:  90 14 60 28  or  %l1, 0x28, %o0
a002a5cc:  40 00 07 27  call  0xa002c268
a002a5d0:  92 10 20 00  clr  %o1
a002a5d4:  b0 16 20 90  or  %i0, 0x90, %i0
a002a5d8:  40 00 07 24  call  0xa002c268
a002a5dc:  95 e8 00 19  restore  %g0, %i1, %o2
a002a5e0:  01 00 00 00  nop
