# leon2s FUN_a00cdc40 0xa00cdc40-0xa00cdc74 (52 bytes)
a00cdc40:  90 0a 20 ff  and  %o0, 0xff, %o0
a00cdc44:  98 02 00 08  add  %o0, %o0, %o4
a00cdc48:  98 03 00 08  add  %o4, %o0, %o4
a00cdc4c:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00cdc50:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00cdc54:  99 2b 20 03  sll  %o4, 3, %o4
a00cdc58:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cdc5c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cdc60:  82 2b 40 01  andn  %o5, %g1, %g1
a00cdc64:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cdc68:  82 10 40 0d  or  %g1, %o5, %g1
a00cdc6c:  81 c3 e0 08  retl
a00cdc70:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
