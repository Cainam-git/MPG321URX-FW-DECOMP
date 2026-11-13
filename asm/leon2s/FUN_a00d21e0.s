# leon2s FUN_a00d21e0 0xa00d21e0-0xa00d2210 (48 bytes)
a00d21e0:  82 10 20 01  mov  1, %g1
a00d21e4:  93 28 40 09  sll  %g1, %o1, %o1
a00d21e8:  83 28 40 0a  sll  %g1, %o2, %g1
a00d21ec:  82 22 40 01  sub  %o1, %g1, %g1
a00d21f0:  82 10 40 09  or  %g1, %o1, %g1
a00d21f4:  da 02 00 00  ld  [ %o0 ], %o5
a00d21f8:  97 2a c0 0a  sll  %o3, %o2, %o3
a00d21fc:  96 0a c0 01  and  %o3, %g1, %o3
a00d2200:  9a 2b 40 01  andn  %o5, %g1, %o5
a00d2204:  9a 13 40 0b  or  %o5, %o3, %o5
a00d2208:  81 c3 e0 08  retl
a00d220c:  da 22 00 00  st  %o5, [ %o0 ]
