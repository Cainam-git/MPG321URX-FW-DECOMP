# leon2m FUN_a00e02ec 0xa00e02ec-0xa00e03b0 (196 bytes)
a00e02ec:  9d e3 bf 88  save  %sp, -120, %sp
a00e02f0:  80 a6 20 02  cmp  %i0, 2
a00e02f4:  14 80 00 21  bg  0xa00e0378
a00e02f8:  01 00 00 00  nop
a00e02fc:  1f 2a 00 97  sethi  %hi(0xa8025c00), %o7
a00e0300:  a8 13 e1 10  or  %o7, 0x110, %l4	! 0xa8025d10
a00e0304:  a1 36 60 08  srl  %i1, 8, %l0
a00e0308:  97 2e 20 02  sll  %i0, 2, %o3
a00e030c:  9e 0c 20 0f  and  %l0, 0xf, %o7
a00e0310:  15 2a 00 ad  sethi  %hi(0xa802b400), %o2
a00e0314:  13 00 06 64  sethi  %hi(0x199000), %o1
a00e0318:  c2 0d 00 18  ldub  [ %l4 + %i0 ], %g1
a00e031c:  23 33 c0 8a  sethi  %hi(0xcf022800), %l1
a00e0320:  25 33 c0 8b  sethi  %hi(0xcf022c00), %l2
a00e0324:  27 33 c0 8c  sethi  %hi(0xcf023000), %l3
a00e0328:  e2 27 bf e8  st  %l1, [ %fp + -24 ]
a00e032c:  e4 27 bf ec  st  %l2, [ %fp + -20 ]
a00e0330:  e6 27 bf f0  st  %l3, [ %fp + -16 ]
a00e0334:  98 07 80 0b  add  %fp, %o3, %o4
a00e0338:  e0 02 a1 50  ld  [ %o2 + 0x150 ], %l0
a00e033c:  90 12 63 d0  or  %o1, 0x3d0, %o0
a00e0340:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00e0344:  80 a0 40 0f  cmp  %g1, %o7
a00e0348:  92 10 00 18  mov  %i0, %o1
a00e034c:  94 10 00 19  mov  %i1, %o2
a00e0350:  d6 03 3f e8  ld  [ %o4 + -24 ], %o3
a00e0354:  02 80 00 04  be  0xa00e0364
a00e0358:  83 2b 60 02  sll  %o5, 2, %g1
a00e035c:  de 22 e3 f8  st  %o7, [ %o3 + 0x3f8 ]
a00e0360:  de 2d 00 18  stb  %o7, [ %l4 + %i0 ]
a00e0364:  f0 02 c0 01  ld  [ %o3 + %g1 ], %i0
a00e0368:  80 a4 20 00  cmp  %l0, 0
a00e036c:  02 80 00 0f  be  0xa00e03a8
a00e0370:  96 10 00 18  mov  %i0, %o3
a00e0374:  30 80 00 0b  b,a   0xa00e03a0
a00e0378:  7f ff fd 25  call  0xa00df80c
a00e037c:  01 00 00 00  nop
a00e0380:  40 00 02 16  call  0xa00e0bd8
a00e0384:  01 00 00 00  nop
a00e0388:  11 00 06 64  sethi  %hi(0x199000), %o0
a00e038c:  92 10 00 18  mov  %i0, %o1
a00e0390:  7f ff fb 78  call  0xa00df170
a00e0394:  90 12 23 f0  or  %o0, 0x3f0, %o0
a00e0398:  10 bf ff da  b  0xa00e0300
a00e039c:  1f 2a 00 97  sethi  %hi(0xa8025c00), %o7
a00e03a0:  7f ff fb 74  call  0xa00df170
a00e03a4:  01 00 00 00  nop
a00e03a8:  81 c7 e0 08  ret
a00e03ac:  81 e8 00 00  restore
