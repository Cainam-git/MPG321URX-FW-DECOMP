# leon2m FUN_a00be1c0 0xa00be1c0-0xa00be208 (72 bytes)
a00be1c0:  9d e3 bf 98  save  %sp, -104, %sp
a00be1c4:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00be1c8:  d0 0a a0 07  ldub  [ %o2 + 7 ], %o0	! 0xa802d407
a00be1cc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be1d0:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be1d4:  98 02 20 30  add  %o0, 0x30, %o4
a00be1d8:  82 10 20 30  mov  0x30, %g1
a00be1dc:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00be1e0:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00be1e4:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00be1e8:  7f ff f2 95  call  0xa00bac3c
a00be1ec:  90 10 20 66  mov  0x66, %o0
a00be1f0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be1f4:  7f ff f1 d7  call  0xa00ba950
a00be1f8:  90 10 00 18  mov  %i0, %o0
a00be1fc:  7f ff f2 7a  call  0xa00babe4
a00be200:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be204:  01 00 00 00  nop
