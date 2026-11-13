# leon2s FUN_a00abb30 0xa00abb30-0xa00abba8 (120 bytes)
a00abb30:  9d e3 bf 98  save  %sp, -104, %sp
a00abb34:  21 33 c0 45  sethi  %hi(0xcf011400), %l0
a00abb38:  9a 14 20 3c  or  %l0, 0x3c, %o5	! 0xcf01143c
a00abb3c:  c2 03 40 00  ld  [ %o5 ], %g1
a00abb40:  82 08 7f f8  and  %g1, -8, %g1
a00abb44:  c2 23 40 00  st  %g1, [ %o5 ]
a00abb48:  9a 14 22 74  or  %l0, 0x274, %o5
a00abb4c:  c2 03 40 00  ld  [ %o5 ], %g1
a00abb50:  82 08 7f 7f  and  %g1, -129, %g1
a00abb54:  c2 23 40 00  st  %g1, [ %o5 ]
a00abb58:  90 0e 20 ff  and  %i0, 0xff, %o0
a00abb5c:  92 10 20 c0  mov  0xc0, %o1
a00abb60:  94 10 20 10  mov  0x10, %o2
a00abb64:  7f ff ec 4d  call  0xa00a6c98
a00abb68:  96 10 20 00  clr  %o3
a00abb6c:  a0 14 20 7c  or  %l0, 0x7c, %l0
a00abb70:  c2 04 00 00  ld  [ %l0 ], %g1
a00abb74:  82 08 7f ef  and  %g1, -17, %g1
a00abb78:  c2 24 00 00  st  %g1, [ %l0 ]
a00abb7c:  c2 04 00 00  ld  [ %l0 ], %g1
a00abb80:  82 08 7f fd  and  %g1, -3, %g1
a00abb84:  c2 24 00 00  st  %g1, [ %l0 ]
a00abb88:  c2 04 00 00  ld  [ %l0 ], %g1
a00abb8c:  82 08 7f fb  and  %g1, -5, %g1
a00abb90:  c2 24 00 00  st  %g1, [ %l0 ]
a00abb94:  c2 04 00 00  ld  [ %l0 ], %g1
a00abb98:  82 08 7f f7  and  %g1, -9, %g1
a00abb9c:  c2 24 00 00  st  %g1, [ %l0 ]
a00abba0:  81 c7 e0 08  ret
a00abba4:  81 e8 00 00  restore
