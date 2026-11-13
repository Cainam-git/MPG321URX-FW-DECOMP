# leon2m FUN_a009a500 0xa009a500-0xa009a554 (84 bytes)
a009a500:  9d e3 bf 98  save  %sp, -104, %sp
a009a504:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009a508:  d2 04 63 ec  ld  [ %l1 + 0x3ec ], %o1	! 0xa802afec
a009a50c:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a009a510:  da 0a a0 71  ldub  [ %o2 + 0x71 ], %o5	! 0xa802d471
a009a514:  90 02 60 45  add  %o1, 0x45, %o0
a009a518:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a009a51c:  da 2c 20 55  stb  %o5, [ %l0 + 0x55 ]	! 0xa8025c55
a009a520:  40 00 3b a7  call  0xa00a93bc
a009a524:  90 0a 20 ff  and  %o0, 0xff, %o0
a009a528:  40 00 48 7c  call  0xa00ac718
a009a52c:  90 10 20 be  mov  0xbe, %o0
a009a530:  82 10 20 f6  mov  0xf6, %g1
a009a534:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a009a538:  d0 0c 20 55  ldub  [ %l0 + 0x55 ], %o0
a009a53c:  40 00 3c 45  call  0xa00a9650
a009a540:  92 10 20 00  clr  %o1
a009a544:  f0 0c 20 55  ldub  [ %l0 + 0x55 ], %i0
a009a548:  40 00 3c 42  call  0xa00a9650
a009a54c:  93 e8 20 01  restore  %g0, 1, %o1
a009a550:  01 00 00 00  nop
