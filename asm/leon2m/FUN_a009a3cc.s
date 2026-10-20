# leon2m FUN_a009a3cc 0xa009a3cc-0xa009a424 (88 bytes)
a009a3cc:  9d e3 bf 98  save  %sp, -104, %sp
a009a3d0:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a009a3d4:  d4 04 23 ec  ld  [ %l0 + 0x3ec ], %o2	! 0xa802afec
a009a3d8:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a009a3dc:  da 0a e0 6f  ldub  [ %o3 + 0x6f ], %o5	! 0xa802d46f
a009a3e0:  90 02 a0 45  add  %o2, 0x45, %o0
a009a3e4:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a009a3e8:  da 2a 60 55  stb  %o5, [ %o1 + 0x55 ]	! 0xa8025c55
a009a3ec:  40 00 3b f4  call  0xa00a93bc
a009a3f0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009a3f4:  40 00 3a 25  call  0xa00a8c88
a009a3f8:  b0 10 20 bf  mov  0xbf, %i0
a009a3fc:  40 00 76 46  call  0xa00b7d14
a009a400:  90 10 20 01  mov  1, %o0
a009a404:  82 10 20 f5  mov  0xf5, %g1
a009a408:  c2 24 23 ec  st  %g1, [ %l0 + 0x3ec ]
a009a40c:  90 10 20 00  clr  %o0
a009a410:  40 00 3c 90  call  0xa00a9650
a009a414:  92 10 20 01  mov  1, %o1
a009a418:  40 00 52 8b  call  0xa00aee44
a009a41c:  93 e8 20 00  restore  %g0, 0, %o1
a009a420:  01 00 00 00  nop
