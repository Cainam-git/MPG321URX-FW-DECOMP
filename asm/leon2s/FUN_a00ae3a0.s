# leon2s FUN_a00ae3a0 0xa00ae3a0-0xa00ae3e4 (68 bytes)
a00ae3a0:  9d e3 bf 98  save  %sp, -104, %sp
a00ae3a4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ae3a8:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00ae3ac:  82 10 60 18  or  %g1, 0x18, %g1	! 0xa807dc18
a00ae3b0:  a0 5e 21 2c  smul  %i0, 0x12c, %l0
a00ae3b4:  a0 04 00 01  add  %l0, %g1, %l0
a00ae3b8:  90 10 00 18  mov  %i0, %o0
a00ae3bc:  7f ff 5a 2e  call  0xa0084c74
a00ae3c0:  d2 0c 21 18  ldub  [ %l0 + 0x118 ], %o1
a00ae3c4:  90 10 00 18  mov  %i0, %o0
a00ae3c8:  7f ff 5a 33  call  0xa0084c94
a00ae3cc:  d2 0c 21 1a  ldub  [ %l0 + 0x11a ], %o1
a00ae3d0:  f6 0c 21 1b  ldub  [ %l0 + 0x11b ], %i3
a00ae3d4:  b2 10 20 c8  mov  0xc8, %i1
a00ae3d8:  7f ff e2 30  call  0xa00a6c98
a00ae3dc:  95 e8 20 30  restore  %g0, 0x30, %o2
a00ae3e0:  01 00 00 00  nop
