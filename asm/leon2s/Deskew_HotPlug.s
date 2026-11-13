# leon2s Deskew_HotPlug 0xa0077e7c-0xa0077f04 (136 bytes)
a0077e7c:  9d e3 bf 98  save  %sp, -104, %sp
a0077e80:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0077e84:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0077e88:  90 12 20 00  mov  %o0, %o0	! 0xa0067400
a0077e8c:  7f ff ec 6e  call  0xa0073044
a0077e90:  92 10 00 18  mov  %i0, %o1
a0077e94:  80 a6 20 01  cmp  %i0, 1
a0077e98:  02 80 00 0f  be  0xa0077ed4
a0077e9c:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0077ea0:  14 80 00 06  bg  0xa0077eb8
a0077ea4:  80 a6 20 02  cmp  %i0, 2
a0077ea8:  80 a6 20 00  cmp  %i0, 0
a0077eac:  02 80 00 08  be  0xa0077ecc
a0077eb0:  c2 0b 60 d2  ldub  [ %o5 + 0xd2 ], %g1
a0077eb4:  30 80 00 12  b,a   0xa0077efc
a0077eb8:  02 80 00 0a  be  0xa0077ee0
a0077ebc:  80 a6 20 03  cmp  %i0, 3
a0077ec0:  02 80 00 0c  be  0xa0077ef0
a0077ec4:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0077ec8:  30 80 00 0d  b,a   0xa0077efc
a0077ecc:  10 80 00 0b  b  0xa0077ef8
a0077ed0:  82 10 60 01  or  %g1, 1, %g1
a0077ed4:  c2 0b 60 d2  ldub  [ %o5 + 0xd2 ], %g1
a0077ed8:  10 80 00 08  b  0xa0077ef8
a0077edc:  82 10 60 02  or  %g1, 2, %g1
a0077ee0:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0077ee4:  c2 0b 60 d2  ldub  [ %o5 + 0xd2 ], %g1	! 0xa80788d2
a0077ee8:  10 80 00 04  b  0xa0077ef8
a0077eec:  82 10 60 04  or  %g1, 4, %g1
a0077ef0:  c2 0b 60 d2  ldub  [ %o5 + 0xd2 ], %g1
a0077ef4:  82 10 60 08  or  %g1, 8, %g1
a0077ef8:  c2 2b 60 d2  stb  %g1, [ %o5 + 0xd2 ]
a0077efc:  81 c7 e0 08  ret
a0077f00:  81 e8 00 00  restore
