# leon2m FUN_a0104eb0 0xa0104eb0-0xa0104f48 (152 bytes)
a0104eb0:  19 33 c0 4a  sethi  %hi(0xcf012800), %o4
a0104eb4:  96 13 20 90  or  %o4, 0x90, %o3	! 0xcf012890
a0104eb8:  d4 02 c0 00  ld  [ %o3 ], %o2
a0104ebc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0104ec0:  9a 0a 20 1e  and  %o0, 0x1e, %o5
a0104ec4:  82 0a bf e1  and  %o2, -31, %g1
a0104ec8:  94 10 40 0d  or  %g1, %o5, %o2
a0104ecc:  82 0a a0 ff  and  %o2, 0xff, %g1
a0104ed0:  c2 22 c0 00  st  %g1, [ %o3 ]
a0104ed4:  94 13 21 90  or  %o4, 0x190, %o2
a0104ed8:  c2 22 80 00  st  %g1, [ %o2 ]
a0104edc:  da 02 c0 00  ld  [ %o3 ], %o5
a0104ee0:  98 0b 60 1f  and  %o5, 0x1f, %o4
a0104ee4:  90 0a 3f e0  and  %o0, -32, %o0
a0104ee8:  82 13 00 08  or  %o4, %o0, %g1
a0104eec:  c2 22 c0 00  st  %g1, [ %o3 ]
a0104ef0:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a0104ef4:  c2 22 80 00  st  %g1, [ %o2 ]
a0104ef8:  da 02 22 a4  ld  [ %o0 + 0x2a4 ], %o5
a0104efc:  d8 03 40 00  ld  [ %o5 ], %o4
a0104f00:  03 01 00 00  sethi  %hi(0x4000000), %g1
a0104f04:  80 8b 00 01  btst  %o4, %g1
a0104f08:  02 80 00 08  be  0xa0104f28
a0104f0c:  01 00 00 00  nop
a0104f10:  d8 02 c0 00  ld  [ %o3 ], %o4
a0104f14:  90 13 20 01  or  %o4, 1, %o0
a0104f18:  d0 22 c0 00  st  %o0, [ %o3 ]
a0104f1c:  d6 02 80 00  ld  [ %o2 ], %o3
a0104f20:  10 80 00 07  b  0xa0104f3c
a0104f24:  9a 12 e0 01  or  %o3, 1, %o5
a0104f28:  d0 02 c0 00  ld  [ %o3 ], %o0
a0104f2c:  9a 0a 3f fe  and  %o0, -2, %o5
a0104f30:  da 22 c0 00  st  %o5, [ %o3 ]
a0104f34:  c2 02 80 00  ld  [ %o2 ], %g1
a0104f38:  9a 08 7f fe  and  %g1, -2, %o5
a0104f3c:  da 22 80 00  st  %o5, [ %o2 ]
a0104f40:  81 c3 e0 08  retl
a0104f44:  01 00 00 00  nop
