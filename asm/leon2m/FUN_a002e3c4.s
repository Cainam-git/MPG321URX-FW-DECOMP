# leon2m FUN_a002e3c4 0xa002e3c4-0xa002e408 (68 bytes)
a002e3c4:  96 10 20 01  mov  1, %o3
a002e3c8:  19 33 c0 47  sethi  %hi(0xcf011c00), %o4
a002e3cc:  94 13 23 c0  or  %o4, 0x3c0, %o2	! 0xcf011fc0
a002e3d0:  83 2a c0 08  sll  %o3, %o0, %g1
a002e3d4:  9a 10 00 0a  mov  %o2, %o5
a002e3d8:  80 8a 60 ff  btst  0xff, %o1
a002e3dc:  02 80 00 06  be  0xa002e3f4
a002e3e0:  96 08 60 ff  and  %g1, 0xff, %o3
a002e3e4:  d2 02 80 00  ld  [ %o2 ], %o1
a002e3e8:  90 12 40 0b  or  %o1, %o3, %o0
a002e3ec:  d0 22 80 00  st  %o0, [ %o2 ]
a002e3f0:  30 80 00 04  b,a   0xa002e400
a002e3f4:  c2 02 80 00  ld  [ %o2 ], %g1
a002e3f8:  94 28 40 0b  andn  %g1, %o3, %o2
a002e3fc:  d4 23 40 00  st  %o2, [ %o5 ]
a002e400:  81 c3 e0 08  retl
a002e404:  01 00 00 00  nop
