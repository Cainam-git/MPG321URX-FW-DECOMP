# leon2m FUN_a009a2d0 0xa009a2d0-0xa009a324 (84 bytes)
a009a2d0:  9d e3 bf 98  save  %sp, -104, %sp
a009a2d4:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009a2d8:  d2 04 63 ec  ld  [ %l1 + 0x3ec ], %o1	! 0xa802afec
a009a2dc:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a009a2e0:  da 0a a0 70  ldub  [ %o2 + 0x70 ], %o5	! 0xa802d470
a009a2e4:  90 02 60 45  add  %o1, 0x45, %o0
a009a2e8:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a009a2ec:  da 2c 20 55  stb  %o5, [ %l0 + 0x55 ]	! 0xa8025c55
a009a2f0:  40 00 3c 33  call  0xa00a93bc
a009a2f4:  90 0a 20 ff  and  %o0, 0xff, %o0
a009a2f8:  40 00 49 08  call  0xa00ac718
a009a2fc:  90 10 20 bd  mov  0xbd, %o0
a009a300:  82 10 20 f4  mov  0xf4, %g1
a009a304:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a009a308:  d0 0c 20 55  ldub  [ %l0 + 0x55 ], %o0
a009a30c:  40 00 3c d1  call  0xa00a9650
a009a310:  92 10 20 00  clr  %o1
a009a314:  f0 0c 20 55  ldub  [ %l0 + 0x55 ], %i0
a009a318:  40 00 3c ce  call  0xa00a9650
a009a31c:  93 e8 20 01  restore  %g0, 1, %o1
a009a320:  01 00 00 00  nop
