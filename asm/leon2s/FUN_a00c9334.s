# leon2s FUN_a00c9334 0xa00c9334-0xa00c9368 (52 bytes)
a00c9334:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c9338:  98 02 00 08  add  %o0, %o0, %o4
a00c933c:  98 03 00 08  add  %o4, %o0, %o4
a00c9340:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00c9344:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00c9348:  99 2b 20 03  sll  %o4, 3, %o4
a00c934c:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00c9350:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00c9354:  82 2b 40 01  andn  %o5, %g1, %g1
a00c9358:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00c935c:  82 10 40 0d  or  %g1, %o5, %g1
a00c9360:  81 c3 e0 08  retl
a00c9364:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
