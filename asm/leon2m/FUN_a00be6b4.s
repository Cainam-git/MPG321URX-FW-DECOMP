# leon2m FUN_a00be6b4 0xa00be6b4-0xa00be6fc (72 bytes)
a00be6b4:  9d e3 bf 98  save  %sp, -104, %sp
a00be6b8:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00be6bc:  d0 0a a0 7a  ldub  [ %o2 + 0x7a ], %o0	! 0xa802d47a
a00be6c0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be6c4:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be6c8:  98 02 20 30  add  %o0, 0x30, %o4
a00be6cc:  82 10 20 30  mov  0x30, %g1
a00be6d0:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00be6d4:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00be6d8:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00be6dc:  7f ff f1 58  call  0xa00bac3c
a00be6e0:  90 10 20 7e  mov  0x7e, %o0
a00be6e4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be6e8:  7f ff f0 9a  call  0xa00ba950
a00be6ec:  90 10 00 18  mov  %i0, %o0
a00be6f0:  7f ff f1 3d  call  0xa00babe4
a00be6f4:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be6f8:  01 00 00 00  nop
