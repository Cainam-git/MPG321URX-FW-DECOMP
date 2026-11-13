# leon2m FUN_a0124b88 0xa0124b88-0xa0124bf4 (108 bytes)
a0124b88:  90 0a 20 ff  and  %o0, 0xff, %o0
a0124b8c:  03 00 06 90  sethi  %hi(0x1a4000), %g1
a0124b90:  98 10 62 a8  or  %g1, 0x2a8, %o4	! 0x1a42a8
a0124b94:  9a 5a 20 16  smul  %o0, 0x16, %o5
a0124b98:  90 03 40 0c  add  %o5, %o4, %o0
a0124b9c:  c2 0a 20 01  ldub  [ %o0 + 1 ], %g1
a0124ba0:  80 a0 60 02  cmp  %g1, 2
a0124ba4:  02 80 00 07  be  0xa0124bc0
a0124ba8:  96 10 00 08  mov  %o0, %o3
a0124bac:  c2 0a e0 15  ldub  [ %o3 + 0x15 ], %g1
a0124bb0:  da 0a e0 12  ldub  [ %o3 + 0x12 ], %o5
a0124bb4:  d8 0a e0 13  ldub  [ %o3 + 0x13 ], %o4
a0124bb8:  10 80 00 0a  b  0xa0124be0
a0124bbc:  d6 0a e0 14  ldub  [ %o3 + 0x14 ], %o3
a0124bc0:  da 12 20 14  lduh  [ %o0 + 0x14 ], %o5
a0124bc4:  80 8b 64 00  btst  0x400, %o5
a0124bc8:  22 bf ff fa  be,a   0xa0124bb0
a0124bcc:  c2 0a e0 15  ldub  [ %o3 + 0x15 ], %g1
a0124bd0:  c2 0a 20 15  ldub  [ %o0 + 0x15 ], %g1
a0124bd4:  da 0a 20 12  ldub  [ %o0 + 0x12 ], %o5
a0124bd8:  d8 0a 20 13  ldub  [ %o0 + 0x13 ], %o4
a0124bdc:  d6 0a 20 14  ldub  [ %o0 + 0x14 ], %o3
a0124be0:  c2 2a 60 03  stb  %g1, [ %o1 + 3 ]
a0124be4:  da 2a 40 00  stb  %o5, [ %o1 ]
a0124be8:  d8 2a 60 01  stb  %o4, [ %o1 + 1 ]
a0124bec:  81 c3 e0 08  retl
a0124bf0:  d6 2a 60 02  stb  %o3, [ %o1 + 2 ]
