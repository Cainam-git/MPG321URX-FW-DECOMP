# leon2m FUN_a00d0fa0 0xa00d0fa0-0xa00d0fe8 (72 bytes)
a00d0fa0:  96 10 3f 88  mov  -120, %o3
a00d0fa4:  9a 10 20 02  mov  2, %o5
a00d0fa8:  d6 2a 20 01  stb  %o3, [ %o0 + 1 ]
a00d0fac:  da 2a 20 08  stb  %o5, [ %o0 + 8 ]
a00d0fb0:  82 10 20 01  mov  1, %g1
a00d0fb4:  c2 2a 20 09  stb  %g1, [ %o0 + 9 ]
a00d0fb8:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00d0fbc:  96 10 20 50  mov  0x50, %o3
a00d0fc0:  98 10 20 00  clr  %o4
a00d0fc4:  9a 10 20 00  clr  %o5
a00d0fc8:  c2 0b 40 08  ldub  [ %o5 + %o0 ], %g1
a00d0fcc:  98 03 20 01  inc  %o4
a00d0fd0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d0fd4:  80 a3 60 0a  cmp  %o5, 0xa
a00d0fd8:  0a bf ff fc  bcs  0xa00d0fc8
a00d0fdc:  96 1a c0 01  xor  %o3, %g1, %o3
a00d0fe0:  81 c3 e0 08  retl
a00d0fe4:  d6 2a 20 0a  stb  %o3, [ %o0 + 0xa ]
