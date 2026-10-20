# leon2m FUN_a00be510 0xa00be510-0xa00be558 (72 bytes)
a00be510:  9d e3 bf 98  save  %sp, -104, %sp
a00be514:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00be518:  d0 0a a0 70  ldub  [ %o2 + 0x70 ], %o0	! 0xa802d470
a00be51c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be520:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be524:  98 02 20 30  add  %o0, 0x30, %o4
a00be528:  82 10 20 30  mov  0x30, %g1
a00be52c:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00be530:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00be534:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00be538:  7f ff f1 c1  call  0xa00bac3c
a00be53c:  90 10 20 74  mov  0x74, %o0
a00be540:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be544:  7f ff f1 03  call  0xa00ba950
a00be548:  90 10 00 18  mov  %i0, %o0
a00be54c:  7f ff f1 a6  call  0xa00babe4
a00be550:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be554:  01 00 00 00  nop
