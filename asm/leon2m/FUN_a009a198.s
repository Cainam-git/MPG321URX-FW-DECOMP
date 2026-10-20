# leon2m FUN_a009a198 0xa009a198-0xa009a1ec (84 bytes)
a009a198:  9d e3 bf 98  save  %sp, -104, %sp
a009a19c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a009a1a0:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009a1a4:  a0 12 e2 90  or  %o3, 0x290, %l0
a009a1a8:  d4 04 63 ec  ld  [ %l1 + 0x3ec ], %o2
a009a1ac:  90 02 a0 48  add  %o2, 0x48, %o0
a009a1b0:  da 0c 21 dd  ldub  [ %l0 + 0x1dd ], %o5
a009a1b4:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a009a1b8:  da 2a 60 55  stb  %o5, [ %o1 + 0x55 ]	! 0xa8025c55
a009a1bc:  40 00 3c 80  call  0xa00a93bc
a009a1c0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009a1c4:  40 00 3a b1  call  0xa00a8c88
a009a1c8:  b2 10 20 01  mov  1, %i1
a009a1cc:  40 00 49 53  call  0xa00ac718
a009a1d0:  90 10 20 ba  mov  0xba, %o0
a009a1d4:  f0 0c 21 dd  ldub  [ %l0 + 0x1dd ], %i0
a009a1d8:  82 06 20 f1  add  %i0, 0xf1, %g1
a009a1dc:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a009a1e0:  40 00 3d 1c  call  0xa00a9650
a009a1e4:  81 e8 00 00  restore
a009a1e8:  01 00 00 00  nop
