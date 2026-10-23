# leon2m FUN_a014e768 0xa014e768-0xa014e7bc (84 bytes)
a014e768:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014e76c:  90 0a 20 ff  and  %o0, 0xff, %o0
a014e770:  9a 10 62 24  or  %g1, 0x224, %o5
a014e774:  98 5a 20 2a  smul  %o0, 0x2a, %o4
a014e778:  d6 13 40 0c  lduh  [ %o5 + %o4 ], %o3
a014e77c:  9b 32 e0 05  srl  %o3, 5, %o5
a014e780:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a014e784:  98 0b 60 01  and  %o5, 1, %o4
a014e788:  80 a3 20 01  cmp  %o4, 1
a014e78c:  02 80 00 08  be  0xa014e7ac
a014e790:  96 10 60 18  or  %g1, 0x18, %o3
a014e794:  c2 0a c0 08  ldub  [ %o3 + %o0 ], %g1
a014e798:  80 a0 60 00  cmp  %g1, 0
a014e79c:  02 80 00 06  be  0xa014e7b4
a014e7a0:  9a 00 7f ff  add  %g1, -1, %o5
a014e7a4:  10 80 00 04  b  0xa014e7b4
a014e7a8:  da 2a c0 08  stb  %o5, [ %o3 + %o0 ]
a014e7ac:  9a 10 20 02  mov  2, %o5
a014e7b0:  da 2a c0 08  stb  %o5, [ %o3 + %o0 ]
a014e7b4:  81 c3 e0 08  retl
a014e7b8:  90 10 00 0c  mov  %o4, %o0
