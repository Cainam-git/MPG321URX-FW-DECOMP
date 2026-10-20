# leon2m FUN_a00be3dc 0xa00be3dc-0xa00be424 (72 bytes)
a00be3dc:  9d e3 bf 98  save  %sp, -104, %sp
a00be3e0:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00be3e4:  d0 0a a0 6d  ldub  [ %o2 + 0x6d ], %o0	! 0xa802d46d
a00be3e8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be3ec:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be3f0:  98 02 20 30  add  %o0, 0x30, %o4
a00be3f4:  82 10 20 30  mov  0x30, %g1
a00be3f8:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00be3fc:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00be400:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00be404:  7f ff f2 0e  call  0xa00bac3c
a00be408:  90 10 20 70  mov  0x70, %o0
a00be40c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be410:  7f ff f1 50  call  0xa00ba950
a00be414:  90 10 00 18  mov  %i0, %o0
a00be418:  7f ff f1 f3  call  0xa00babe4
a00be41c:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be420:  01 00 00 00  nop
