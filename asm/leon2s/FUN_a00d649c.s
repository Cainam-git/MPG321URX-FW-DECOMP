# leon2s FUN_a00d649c 0xa00d649c-0xa00d64ec (80 bytes)
a00d649c:  19 33 c0 4c  sethi  %hi(0xcf013000), %o4
a00d64a0:  9a 13 20 1c  or  %o4, 0x1c, %o5	! 0xcf01301c
a00d64a4:  82 10 20 ff  mov  0xff, %g1
a00d64a8:  c2 23 40 00  st  %g1, [ %o5 ]
a00d64ac:  9a 13 20 08  or  %o4, 8, %o5
a00d64b0:  c2 03 40 00  ld  [ %o5 ], %g1
a00d64b4:  82 10 60 c0  or  %g1, 0xc0, %g1
a00d64b8:  c2 23 40 00  st  %g1, [ %o5 ]
a00d64bc:  c2 03 40 00  ld  [ %o5 ], %g1
a00d64c0:  82 08 7f 3f  and  %g1, -193, %g1
a00d64c4:  c2 23 40 00  st  %g1, [ %o5 ]
a00d64c8:  98 13 20 20  or  %o4, 0x20, %o4
a00d64cc:  c2 03 00 00  ld  [ %o4 ], %g1
a00d64d0:  82 10 60 02  or  %g1, 2, %g1
a00d64d4:  c2 23 00 00  st  %g1, [ %o4 ]
a00d64d8:  c2 03 00 00  ld  [ %o4 ], %g1
a00d64dc:  82 08 7f fd  and  %g1, -3, %g1
a00d64e0:  c2 23 00 00  st  %g1, [ %o4 ]
a00d64e4:  81 c3 e0 08  retl
a00d64e8:  01 00 00 00  nop
