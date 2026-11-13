# leon2m FUN_a009b2c4 0xa009b2c4-0xa009b37c (184 bytes)
a009b2c4:  9d e3 bf 98  save  %sp, -104, %sp
a009b2c8:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009b2cc:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009b2d0:  90 02 60 1e  add  %o1, 0x1e, %o0
a009b2d4:  40 00 38 3a  call  0xa00a93bc
a009b2d8:  90 0a 20 ff  and  %o0, 0xff, %o0
a009b2dc:  03 19 99 99  sethi  %hi(0x66666400), %g1
a009b2e0:  b2 10 62 67  or  %g1, 0x267, %i1	! 0x66666667
a009b2e4:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009b2e8:  9e 02 3f 22  add  %o0, -222, %o7
a009b2ec:  80 5b c0 19  smul  %o7, %i1, %g0
a009b2f0:  97 40 00 00  rd  %y, %o3
a009b2f4:  93 3a e0 01  sra  %o3, 1, %o1
a009b2f8:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009b2fc:  82 22 40 0a  sub  %o1, %o2, %g1
a009b300:  b1 28 60 02  sll  %g1, 2, %i0
a009b304:  98 06 00 01  add  %i0, %g1, %o4
a009b308:  96 23 c0 0c  sub  %o7, %o4, %o3
a009b30c:  9a 02 e0 e2  add  %o3, 0xe2, %o5
a009b310:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009b314:  40 00 3e 87  call  0xa00aad30
a009b318:  90 0a e0 ff  and  %o3, 0xff, %o0
a009b31c:  94 0a 20 ff  and  %o0, 0xff, %o2
a009b320:  80 a2 a0 01  cmp  %o2, 1
a009b324:  12 bf ff f1  bne  0xa009b2e8
a009b328:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009b32c:  f0 06 a3 ec  ld  [ %i2 + 0x3ec ], %i0
a009b330:  9a 06 20 1e  add  %i0, 0x1e, %o5
a009b334:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a009b338:  da 2b 23 cf  stb  %o5, [ %o4 + 0x3cf ]	! 0xa802d3cf
a009b33c:  90 0b 60 ff  and  %o5, 0xff, %o0
a009b340:  40 00 38 c4  call  0xa00a9650
a009b344:  92 10 20 01  mov  1, %o1
a009b348:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009b34c:  9e 06 7f 1e  add  %i1, -226, %o7
a009b350:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009b354:  f2 0e a0 55  ldub  [ %i2 + 0x55 ], %i1	! 0xa8025c55
a009b358:  b0 10 20 01  mov  1, %i0
a009b35c:  80 a3 c0 19  cmp  %o7, %i1
a009b360:  02 80 00 04  be  0xa009b370
a009b364:  b4 10 20 00  clr  %i2
a009b368:  b0 10 20 01  mov  1, %i0
a009b36c:  b4 10 20 01  mov  1, %i2
a009b370:  40 00 33 73  call  0xa00a813c
a009b374:  81 e8 00 00  restore
a009b378:  01 00 00 00  nop
