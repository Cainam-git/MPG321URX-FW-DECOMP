# leon2s FUN_a00b1980 0xa00b1980-0xa00b1a00 (128 bytes)
a00b1980:  19 27 c4 80  sethi  %hi(0x9f120000), %o4
a00b1984:  9a 13 20 30  or  %o4, 0x30, %o5	! 0x9f120030
a00b1988:  c2 03 40 00  ld  [ %o5 ], %g1
a00b198c:  82 10 60 20  or  %g1, 0x20, %g1
a00b1990:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1994:  1b 27 c4 00  sethi  %hi(0x9f100000), %o5
a00b1998:  9a 13 60 90  or  %o5, 0x90, %o5	! 0x9f100090
a00b199c:  c2 03 40 00  ld  [ %o5 ], %g1
a00b19a0:  82 10 60 20  or  %g1, 0x20, %g1
a00b19a4:  c2 23 40 00  st  %g1, [ %o5 ]
a00b19a8:  9a 13 20 28  or  %o4, 0x28, %o5
a00b19ac:  c2 03 40 00  ld  [ %o5 ], %g1
a00b19b0:  82 08 7f df  and  %g1, -33, %g1
a00b19b4:  c2 23 40 00  st  %g1, [ %o5 ]
a00b19b8:  96 13 20 48  or  %o4, 0x48, %o3
a00b19bc:  c2 02 c0 00  ld  [ %o3 ], %g1
a00b19c0:  82 08 7f bf  and  %g1, -65, %g1
a00b19c4:  c2 22 c0 00  st  %g1, [ %o3 ]
a00b19c8:  9a 13 20 80  or  %o4, 0x80, %o5
a00b19cc:  c2 03 40 00  ld  [ %o5 ], %g1
a00b19d0:  82 10 60 40  or  %g1, 0x40, %g1
a00b19d4:  c2 23 40 00  st  %g1, [ %o5 ]
a00b19d8:  c2 02 c0 00  ld  [ %o3 ], %g1
a00b19dc:  1b 00 10 00  sethi  %hi(0x400000), %o5
a00b19e0:  82 10 40 0d  or  %g1, %o5, %g1
a00b19e4:  c2 22 c0 00  st  %g1, [ %o3 ]
a00b19e8:  98 13 20 34  or  %o4, 0x34, %o4
a00b19ec:  c2 03 00 00  ld  [ %o4 ], %g1
a00b19f0:  82 10 60 20  or  %g1, 0x20, %g1
a00b19f4:  c2 23 00 00  st  %g1, [ %o4 ]
a00b19f8:  81 c3 e0 08  retl
a00b19fc:  01 00 00 00  nop
