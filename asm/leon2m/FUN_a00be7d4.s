# leon2m FUN_a00be7d4 0xa00be7d4-0xa00be81c (72 bytes)
a00be7d4:  9d e3 bf 98  save  %sp, -104, %sp
a00be7d8:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00be7dc:  d0 0a a0 7e  ldub  [ %o2 + 0x7e ], %o0	! 0xa802d47e
a00be7e0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be7e4:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be7e8:  98 02 20 30  add  %o0, 0x30, %o4
a00be7ec:  82 10 20 30  mov  0x30, %g1
a00be7f0:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00be7f4:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00be7f8:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00be7fc:  7f ff f1 10  call  0xa00bac3c
a00be800:  90 10 20 82  mov  0x82, %o0
a00be804:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be808:  7f ff f0 52  call  0xa00ba950
a00be80c:  90 10 00 18  mov  %i0, %o0
a00be810:  7f ff f0 f5  call  0xa00babe4
a00be814:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be818:  01 00 00 00  nop
