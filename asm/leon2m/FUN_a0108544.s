# leon2m FUN_a0108544 0xa0108544-0xa01085a4 (96 bytes)
a0108544:  9d e3 bf 98  save  %sp, -104, %sp
a0108548:  17 00 06 6a  sethi  %hi(0x19a800), %o3
a010854c:  90 12 e3 e8  or  %o3, 0x3e8, %o0	! 0x19abe8
a0108550:  92 10 20 04  mov  4, %o1
a0108554:  7f ff 5b 07  call  0xa00df170
a0108558:  94 10 20 00  clr  %o2
a010855c:  17 33 c0 46  sethi  %hi(0xcf011800), %o3
a0108560:  98 12 e3 f8  or  %o3, 0x3f8, %o4	! 0xcf011bf8
a0108564:  da 03 00 00  ld  [ %o4 ], %o5
a0108568:  90 0b 7f ef  and  %o5, -17, %o0
a010856c:  d0 23 00 00  st  %o0, [ %o4 ]
a0108570:  94 12 e2 00  or  %o3, 0x200, %o2
a0108574:  c2 02 80 00  ld  [ %o2 ], %g1
a0108578:  9e 08 7f ef  and  %g1, -17, %o7
a010857c:  de 22 80 00  st  %o7, [ %o2 ]
a0108580:  d2 02 c0 00  ld  [ %o3 ], %o1
a0108584:  9a 0a 7f ef  and  %o1, -17, %o5
a0108588:  11 33 c0 47  sethi  %hi(0xcf011c00), %o0
a010858c:  da 22 c0 00  st  %o5, [ %o3 ]
a0108590:  98 10 20 01  mov  1, %o4
a0108594:  82 12 20 c0  or  %o0, 0xc0, %g1
a0108598:  d8 20 40 00  st  %o4, [ %g1 ]
a010859c:  81 c7 e0 08  ret
a01085a0:  81 e8 00 00  restore
