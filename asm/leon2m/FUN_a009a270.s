# leon2m FUN_a009a270 0xa009a270-0xa009a2d0 (96 bytes)
a009a270:  9d e3 bf 98  save  %sp, -104, %sp
a009a274:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009a278:  d6 04 63 ec  ld  [ %l1 + 0x3ec ], %o3	! 0xa802afec
a009a27c:  94 02 e0 0f  add  %o3, 0xf, %o2
a009a280:  40 00 3c 4f  call  0xa00a93bc
a009a284:  90 0a a0 ff  and  %o2, 0xff, %o0
a009a288:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a009a28c:  11 2a 00 97  sethi  %hi(0xa8025c00), %o0
a009a290:  da 0a 20 55  ldub  [ %o0 + 0x55 ], %o5	! 0xa8025c55
a009a294:  a0 12 62 90  or  %o1, 0x290, %l0
a009a298:  90 0b 60 ff  and  %o5, 0xff, %o0
a009a29c:  da 2c 21 dd  stb  %o5, [ %l0 + 0x1dd ]
a009a2a0:  40 00 3c ec  call  0xa00a9650
a009a2a4:  92 10 20 02  mov  2, %o1
a009a2a8:  d2 0c 21 dd  ldub  [ %l0 + 0x1dd ], %o1
a009a2ac:  90 10 20 01  mov  1, %o0
a009a2b0:  40 00 37 a3  call  0xa00a813c
a009a2b4:  94 10 20 01  mov  1, %o2
a009a2b8:  82 10 20 34  mov  0x34, %g1
a009a2bc:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a009a2c0:  b0 10 20 00  clr  %i0
a009a2c4:  40 00 3b 52  call  0xa00a900c
a009a2c8:  93 e8 20 01  restore  %g0, 1, %o1
a009a2cc:  01 00 00 00  nop
