# leon2m FUN_a00d0f68 0xa00d0f68-0xa00d0fa0 (56 bytes)
a00d0f68:  d6 0a 20 01  ldub  [ %o0 + 1 ], %o3
a00d0f6c:  82 0a e0 7f  and  %o3, 0x7f, %g1
a00d0f70:  96 80 60 02  addcc  %g1, 2, %o3
a00d0f74:  02 80 00 09  be  0xa00d0f98
a00d0f78:  98 10 20 00  clr  %o4
a00d0f7c:  9a 10 20 00  clr  %o5
a00d0f80:  c2 0b 40 08  ldub  [ %o5 + %o0 ], %g1
a00d0f84:  98 03 20 01  inc  %o4
a00d0f88:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d0f8c:  80 a3 40 0b  cmp  %o5, %o3
a00d0f90:  0a bf ff fc  bcs  0xa00d0f80
a00d0f94:  92 1a 40 01  xor  %o1, %g1, %o1
a00d0f98:  81 c3 e0 08  retl
a00d0f9c:  90 0a 60 ff  and  %o1, 0xff, %o0
