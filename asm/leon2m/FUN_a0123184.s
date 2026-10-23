# leon2m FUN_a0123184 0xa0123184-0xa01231e4 (96 bytes)
a0123184:  96 0a 20 ff  and  %o0, 0xff, %o3
a0123188:  80 a2 e0 02  cmp  %o3, 2
a012318c:  98 40 20 00  addx  %g0, 0, %o4
a0123190:  82 20 00 0c  neg  %o4, %g1
a0123194:  90 0a c0 01  and  %o3, %g1, %o0
a0123198:  1b 00 06 8c  sethi  %hi(0x1a3000), %o5
a012319c:  96 02 00 08  add  %o0, %o0, %o3
a01231a0:  98 13 60 70  or  %o5, 0x70, %o4
a01231a4:  da 13 00 0b  lduh  [ %o4 + %o3 ], %o5
a01231a8:  82 03 60 49  add  %o5, 0x49, %g1
a01231ac:  90 03 60 48  add  %o5, 0x48, %o0
a01231b0:  99 28 60 02  sll  %g1, 2, %o4
a01231b4:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a01231b8:  83 2a 20 02  sll  %o0, 2, %g1
a01231bc:  9a 10 40 0b  or  %g1, %o3, %o5
a01231c0:  98 13 00 0b  or  %o4, %o3, %o4
a01231c4:  d6 03 00 00  ld  [ %o4 ], %o3
a01231c8:  d0 03 40 00  ld  [ %o5 ], %o0
a01231cc:  99 2a 20 08  sll  %o0, 8, %o4
a01231d0:  82 0a e0 ff  and  %o3, 0xff, %g1
a01231d4:  96 13 00 01  or  %o4, %g1, %o3
a01231d8:  91 2a e0 13  sll  %o3, 0x13, %o0
a01231dc:  81 c3 e0 08  retl
a01231e0:  91 32 20 10  srl  %o0, 0x10, %o0
