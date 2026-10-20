# leon2m FUN_a009e538 0xa009e538-0xa009e5ac (116 bytes)
a009e538:  9d e3 bf 98  save  %sp, -104, %sp
a009e53c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a009e540:  b4 12 22 90  or  %o0, 0x290, %i2	! 0xa802d290
a009e544:  40 00 2b 9e  call  0xa00a93bc
a009e548:  d0 0e a1 e0  ldub  [ %i2 + 0x1e0 ], %o0
a009e54c:  c2 0e a1 e0  ldub  [ %i2 + 0x1e0 ], %g1
a009e550:  82 00 60 01  inc  %g1
a009e554:  9a 08 60 ff  and  %g1, 0xff, %o5
a009e558:  80 a3 60 01  cmp  %o5, 1
a009e55c:  28 80 00 03  bleu,a   0xa009e568
a009e560:  c2 2e a1 e0  stb  %g1, [ %i2 + 0x1e0 ]
a009e564:  c0 2e a1 e0  clrb  [ %i2 + 0x1e0 ]
a009e568:  d0 0e a1 e0  ldub  [ %i2 + 0x1e0 ], %o0
a009e56c:  40 00 2c 39  call  0xa00a9650
a009e570:  92 10 20 01  mov  1, %o1
a009e574:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a009e578:  d8 0a a0 55  ldub  [ %o2 + 0x55 ], %o4	! 0xa8025c55
a009e57c:  d2 0e a1 e0  ldub  [ %i2 + 0x1e0 ], %o1
a009e580:  b2 10 00 0c  mov  %o4, %i1
a009e584:  b0 10 20 01  mov  1, %i0
a009e588:  80 a2 40 0c  cmp  %o1, %o4
a009e58c:  02 80 00 05  be  0xa009e5a0
a009e590:  b4 10 20 00  clr  %i2
a009e594:  b2 10 00 0c  mov  %o4, %i1
a009e598:  b0 10 20 01  mov  1, %i0
a009e59c:  b4 10 20 01  mov  1, %i2
a009e5a0:  40 00 26 e7  call  0xa00a813c
a009e5a4:  81 e8 00 00  restore
a009e5a8:  01 00 00 00  nop
