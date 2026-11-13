# leon2m FUN_a012f3b4 0xa012f3b4-0xa012f3ec (56 bytes)
a012f3b4:  90 0a 20 ff  and  %o0, 0xff, %o0
a012f3b8:  9b 2a 20 04  sll  %o0, 4, %o5
a012f3bc:  82 23 40 08  sub  %o5, %o0, %g1
a012f3c0:  80 a2 20 03  cmp  %o0, 3
a012f3c4:  9b 28 60 03  sll  %g1, 3, %o5
a012f3c8:  18 80 00 07  bgu  0xa012f3e4
a012f3cc:  90 10 3f ff  mov  -1, %o0
a012f3d0:  11 2a 00 b7  sethi  %hi(0xa802dc00), %o0
a012f3d4:  82 12 23 30  or  %o0, 0x330, %g1	! 0xa802df30
a012f3d8:  d0 00 40 0d  ld  [ %g1 + %o5 ], %o0
a012f3dc:  83 32 20 0c  srl  %o0, 0xc, %g1
a012f3e0:  90 08 60 0f  and  %g1, 0xf, %o0
a012f3e4:  81 c3 e0 08  retl
a012f3e8:  90 0a 20 ff  and  %o0, 0xff, %o0
