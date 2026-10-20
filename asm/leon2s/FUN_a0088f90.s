# leon2s FUN_a0088f90 0xa0088f90-0xa0088fb0 (32 bytes)
a0088f90:  90 0a 20 ff  and  %o0, 0xff, %o0
a0088f94:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0088f98:  82 10 62 00  or  %g1, 0x200, %g1	! 0xa8078a00
a0088f9c:  90 02 00 08  add  %o0, %o0, %o0
a0088fa0:  da 10 40 08  lduh  [ %g1 + %o0 ], %o5
a0088fa4:  92 12 40 0d  or  %o1, %o5, %o1
a0088fa8:  81 c3 e0 08  retl
a0088fac:  d2 30 40 08  sth  %o1, [ %g1 + %o0 ]
