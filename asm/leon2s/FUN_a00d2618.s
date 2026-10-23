# leon2s FUN_a00d2618 0xa00d2618-0xa00d264c (52 bytes)
a00d2618:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d261c:  82 10 20 01  mov  1, %g1
a00d2620:  80 8a 60 ff  btst  0xff, %o1
a00d2624:  97 28 40 08  sll  %g1, %o0, %o3
a00d2628:  02 80 00 05  be  0xa00d263c
a00d262c:  1b 2a 01 e3  sethi  %hi(0xa8078c00), %o5
a00d2630:  c2 0b 60 36  ldub  [ %o5 + 0x36 ], %g1	! 0xa8078c36
a00d2634:  10 80 00 04  b  0xa00d2644
a00d2638:  82 12 c0 01  or  %o3, %g1, %g1
a00d263c:  c2 0b 60 36  ldub  [ %o5 + 0x36 ], %g1
a00d2640:  82 28 40 0b  andn  %g1, %o3, %g1
a00d2644:  81 c3 e0 08  retl
a00d2648:  c2 2b 60 36  stb  %g1, [ %o5 + 0x36 ]
