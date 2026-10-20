# leon2s FUN_a0083e34 0xa0083e34-0xa0083ec4 (144 bytes)
a0083e34:  9d e3 bf 98  save  %sp, -104, %sp
a0083e38:  03 33 c0 4c  sethi  %hi(0xcf013000), %g1
a0083e3c:  96 10 63 c0  or  %g1, 0x3c0, %o3	! 0xcf0133c0
a0083e40:  15 33 c0 d1  sethi  %hi(0xcf034400), %o2
a0083e44:  80 8e 20 ff  btst  0xff, %i0
a0083e48:  02 80 00 13  be  0xa0083e94
a0083e4c:  13 2a 01 e2  sethi  %hi(0xa8078800), %o1
a0083e50:  c2 02 c0 00  ld  [ %o3 ], %g1
a0083e54:  82 10 60 01  or  %g1, 1, %g1
a0083e58:  c2 22 c0 00  st  %g1, [ %o3 ]
a0083e5c:  c2 02 80 00  ld  [ %o2 ], %g1
a0083e60:  82 10 60 01  or  %g1, 1, %g1
a0083e64:  c2 22 80 00  st  %g1, [ %o2 ]
a0083e68:  82 10 20 01  mov  1, %g1
a0083e6c:  40 00 26 65  call  0xa008d800
a0083e70:  c2 2a 61 ec  stb  %g1, [ %o1 + 0x1ec ]
a0083e74:  90 0a 20 ff  and  %o0, 0xff, %o0
a0083e78:  80 a2 20 81  cmp  %o0, 0x81
a0083e7c:  08 80 00 10  bleu  0xa0083ebc
a0083e80:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a0083e84:  9a 10 20 65  mov  0x65, %o5
a0083e88:  82 10 63 78  or  %g1, 0x378, %g1
a0083e8c:  da 20 40 00  st  %o5, [ %g1 ]
a0083e90:  30 80 00 0b  b,a   0xa0083ebc
a0083e94:  c2 02 c0 00  ld  [ %o3 ], %g1
a0083e98:  82 08 7f fe  and  %g1, -2, %g1
a0083e9c:  c2 22 c0 00  st  %g1, [ %o3 ]
a0083ea0:  c2 02 80 00  ld  [ %o2 ], %g1
a0083ea4:  82 08 7f fe  and  %g1, -2, %g1
a0083ea8:  c2 22 80 00  st  %g1, [ %o2 ]
a0083eac:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a0083eb0:  c0 2a 61 ec  clrb  [ %o1 + 0x1ec ]
a0083eb4:  82 10 63 78  or  %g1, 0x378, %g1
a0083eb8:  c0 20 40 00  clr  [ %g1 ]
a0083ebc:  81 c7 e0 08  ret
a0083ec0:  81 e8 00 00  restore
