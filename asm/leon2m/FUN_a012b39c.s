# leon2m FUN_a012b39c 0xa012b39c-0xa012b3f0 (84 bytes)
a012b39c:  82 10 20 01  mov  1, %g1
a012b3a0:  9b 28 40 08  sll  %g1, %o0, %o5
a012b3a4:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a012b3a8:  98 10 20 01  mov  1, %o4
a012b3ac:  90 0a 20 ff  and  %o0, 0xff, %o0
a012b3b0:  96 10 00 0a  mov  %o2, %o3
a012b3b4:  80 8a 60 ff  btst  0xff, %o1
a012b3b8:  02 80 00 06  be  0xa012b3d0
a012b3bc:  83 2b 00 08  sll  %o4, %o0, %g1
a012b3c0:  d2 0a a2 f8  ldub  [ %o2 + 0x2f8 ], %o1
a012b3c4:  90 13 40 09  or  %o5, %o1, %o0
a012b3c8:  10 80 00 08  b  0xa012b3e8
a012b3cc:  d0 2a a2 f8  stb  %o0, [ %o2 + 0x2f8 ]
a012b3d0:  d2 0a a2 f8  ldub  [ %o2 + 0x2f8 ], %o1
a012b3d4:  9a 2a 40 01  andn  %o1, %g1, %o5
a012b3d8:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a012b3dc:  94 10 63 00  or  %g1, 0x300, %o2	! 0xa802cb00
a012b3e0:  d8 2a 80 08  stb  %o4, [ %o2 + %o0 ]
a012b3e4:  da 2a e2 f8  stb  %o5, [ %o3 + 0x2f8 ]
a012b3e8:  81 c3 e0 08  retl
a012b3ec:  01 00 00 00  nop
