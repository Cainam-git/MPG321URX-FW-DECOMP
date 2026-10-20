# leon2m FUN_a002a25c 0xa002a25c-0xa002a344 (232 bytes)
a002a25c:  9d e3 bf 98  save  %sp, -104, %sp
a002a260:  11 27 c0 00  sethi  %hi(0x9f000000), %o0
a002a264:  90 12 20 90  or  %o0, 0x90, %o0	! 0x9f000090
a002a268:  92 10 20 00  clr  %o1
a002a26c:  40 00 07 ff  call  0xa002c268
a002a270:  94 10 22 00  mov  0x200, %o2
a002a274:  35 27 c0 80  sethi  %hi(0x9f020000), %i2
a002a278:  94 10 22 00  mov  0x200, %o2
a002a27c:  92 10 22 00  mov  0x200, %o1
a002a280:  40 00 07 fa  call  0xa002c268
a002a284:  90 16 a0 28  or  %i2, 0x28, %o0
a002a288:  40 00 07 f2  call  0xa002c250
a002a28c:  90 16 a0 90  or  %i2, 0x90, %o0
a002a290:  b0 10 00 08  mov  %o0, %i0
a002a294:  40 00 07 ef  call  0xa002c250
a002a298:  90 16 a0 58  or  %i2, 0x58, %o0
a002a29c:  a0 2e 00 08  andn  %i0, %o0, %l0
a002a2a0:  80 8c 20 01  btst  1, %l0
a002a2a4:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a002a2a8:  a0 10 61 70  or  %g1, 0x170, %l0	! 0xa802b170
a002a2ac:  02 80 00 0f  be  0xa002a2e8
a002a2b0:  9b 32 20 10  srl  %o0, 0x10, %o5
a002a2b4:  c2 04 22 40  ld  [ %l0 + 0x240 ], %g1
a002a2b8:  80 a0 60 00  cmp  %g1, 0
a002a2bc:  22 80 00 0c  be,a   0xa002a2ec
a002a2c0:  35 27 c0 80  sethi  %hi(0x9f020000), %i2
a002a2c4:  90 16 a0 90  or  %i2, 0x90, %o0	! 0x9f020090
a002a2c8:  80 8b 60 01  btst  1, %o5
a002a2cc:  02 80 00 17  be  0xa002a328
a002a2d0:  92 10 20 01  mov  1, %o1
a002a2d4:  9f c0 40 00  call  %g1
a002a2d8:  01 00 00 00  nop
a002a2dc:  90 16 a0 90  or  %i2, 0x90, %o0
a002a2e0:  40 00 07 df  call  0xa002c25c
a002a2e4:  92 10 20 01  mov  1, %o1
a002a2e8:  35 27 c0 80  sethi  %hi(0x9f020000), %i2
a002a2ec:  90 16 a0 34  or  %i2, 0x34, %o0	! 0x9f020034
a002a2f0:  40 00 07 db  call  0xa002c25c
a002a2f4:  92 10 22 00  mov  0x200, %o1
a002a2f8:  33 27 c0 00  sethi  %hi(0x9f000000), %i1
a002a2fc:  90 16 60 9c  or  %i1, 0x9c, %o0	! 0x9f00009c
a002a300:  40 00 07 d7  call  0xa002c25c
a002a304:  92 10 22 00  mov  0x200, %o1
a002a308:  90 16 a0 28  or  %i2, 0x28, %o0
a002a30c:  92 10 20 00  clr  %o1
a002a310:  94 10 22 00  mov  0x200, %o2
a002a314:  40 00 07 d5  call  0xa002c268
a002a318:  b0 16 60 90  or  %i1, 0x90, %i0
a002a31c:  b2 10 22 00  mov  0x200, %i1
a002a320:  40 00 07 d2  call  0xa002c268
a002a324:  95 e8 22 00  restore  %g0, 0x200, %o2
a002a328:  40 00 07 cd  call  0xa002c25c
a002a32c:  35 27 c0 80  sethi  %hi(0x9f020000), %i2
a002a330:  d2 04 22 40  ld  [ %l0 + 0x240 ], %o1
a002a334:  9f c2 40 00  call  %o1
a002a338:  01 00 00 00  nop
a002a33c:  10 bf ff ed  b  0xa002a2f0
a002a340:  90 16 a0 34  or  %i2, 0x34, %o0
