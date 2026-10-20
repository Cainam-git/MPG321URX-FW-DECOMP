# leon2m FUN_a00d93c8 0xa00d93c8-0xa00d94fc (308 bytes)
a00d93c8:  9d e3 bf 98  save  %sp, -104, %sp
a00d93cc:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00d93d0:  b0 14 62 90  or  %l1, 0x290, %i0	! 0xa802d290
a00d93d4:  d0 06 20 ac  ld  [ %i0 + 0xac ], %o0
a00d93d8:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00d93dc:  82 12 00 0d  or  %o0, %o5, %g1
a00d93e0:  d8 06 20 a8  ld  [ %i0 + 0xa8 ], %o4
a00d93e4:  21 00 00 10  sethi  %hi(0x4000), %l0
a00d93e8:  80 8b 00 10  btst  %o4, %l0
a00d93ec:  02 80 00 22  be  0xa00d9474
a00d93f0:  c2 26 20 ac  st  %g1, [ %i0 + 0xac ]
a00d93f4:  40 01 ac 82  call  0xa01445fc
a00d93f8:  d0 0e 20 1e  ldub  [ %i0 + 0x1e ], %o0
a00d93fc:  96 02 20 01  add  %o0, 1, %o3
a00d9400:  40 01 ac a3  call  0xa014468c
a00d9404:  90 0a e0 ff  and  %o3, 0xff, %o0
a00d9408:  d4 06 20 a8  ld  [ %i0 + 0xa8 ], %o2
a00d940c:  82 2a 80 10  andn  %o2, %l0, %g1
a00d9410:  d0 2e 20 3e  stb  %o0, [ %i0 + 0x3e ]
a00d9414:  c2 26 20 a8  st  %g1, [ %i0 + 0xa8 ]
a00d9418:  40 01 b9 75  call  0xa01479ec
a00d941c:  90 10 20 01  mov  1, %o0
a00d9420:  7f ff f2 2e  call  0xa00d5cd8
a00d9424:  21 00 00 10  sethi  %hi(0x4000), %l0
a00d9428:  82 14 62 90  or  %l1, 0x290, %g1
a00d942c:  f0 00 60 a8  ld  [ %g1 + 0xa8 ], %i0
a00d9430:  80 8e 00 10  btst  %i0, %l0
a00d9434:  02 80 00 22  be  0xa00d94bc
a00d9438:  01 00 00 00  nop
a00d943c:  40 01 a9 f6  call  0xa0143c14
a00d9440:  90 10 20 01  mov  1, %o0	! 0x1
a00d9444:  96 0a 20 ff  and  %o0, 0xff, %o3
a00d9448:  80 a2 e0 0a  cmp  %o3, 0xa
a00d944c:  02 80 00 28  be  0xa00d94ec
a00d9450:  01 00 00 00  nop
a00d9454:  9e 14 62 90  or  %l1, 0x290, %o7
a00d9458:  c2 0b e0 10  ldub  [ %o7 + 0x10 ], %g1
a00d945c:  80 a0 60 64  cmp  %g1, 0x64
a00d9460:  38 80 00 02  bgu,a   0xa00d9468
a00d9464:  82 10 20 64  mov  0x64, %g1
a00d9468:  b0 08 60 ff  and  %g1, 0xff, %i0
a00d946c:  40 01 b9 6a  call  0xa0147a14
a00d9470:  81 e8 00 00  restore
a00d9474:  40 01 ac 62  call  0xa01445fc
a00d9478:  d0 0e 20 20  ldub  [ %i0 + 0x20 ], %o0
a00d947c:  98 02 20 01  add  %o0, 1, %o4
a00d9480:  40 01 ac 83  call  0xa014468c
a00d9484:  90 0b 20 ff  and  %o4, 0xff, %o0
a00d9488:  de 06 20 a8  ld  [ %i0 + 0xa8 ], %o7
a00d948c:  82 13 c0 10  or  %o7, %l0, %g1
a00d9490:  d0 2e 20 3e  stb  %o0, [ %i0 + 0x3e ]
a00d9494:  c2 26 20 a8  st  %g1, [ %i0 + 0xa8 ]
a00d9498:  40 01 b9 55  call  0xa01479ec
a00d949c:  90 10 20 01  mov  1, %o0
a00d94a0:  7f ff f2 0e  call  0xa00d5cd8
a00d94a4:  21 00 00 10  sethi  %hi(0x4000), %l0
a00d94a8:  82 14 62 90  or  %l1, 0x290, %g1
a00d94ac:  f0 00 60 a8  ld  [ %g1 + 0xa8 ], %i0
a00d94b0:  80 8e 00 10  btst  %i0, %l0
a00d94b4:  12 bf ff e2  bne  0xa00d943c
a00d94b8:  01 00 00 00  nop
a00d94bc:  40 01 a9 d6  call  0xa0143c14
a00d94c0:  90 10 20 00  clr  %o0	! 0x0
a00d94c4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d94c8:  80 a2 20 0a  cmp  %o0, 0xa
a00d94cc:  02 80 00 08  be  0xa00d94ec
a00d94d0:  94 14 62 90  or  %l1, 0x290, %o2
a00d94d4:  d2 02 a0 a8  ld  [ %o2 + 0xa8 ], %o1
a00d94d8:  1b 00 00 10  sethi  %hi(0x4000), %o5
a00d94dc:  80 8a 40 0d  btst  %o1, %o5
a00d94e0:  02 bf ff de  be  0xa00d9458
a00d94e4:  9e 14 62 90  or  %l1, 0x290, %o7
a00d94e8:  30 bf ff d5  b,a   0xa00d943c
a00d94ec:  40 01 b9 40  call  0xa01479ec
a00d94f0:  90 10 20 00  clr  %o0
a00d94f4:  10 bf ff d9  b  0xa00d9458
a00d94f8:  9e 14 62 90  or  %l1, 0x290, %o7
