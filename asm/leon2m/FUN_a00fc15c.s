# leon2m FUN_a00fc15c 0xa00fc15c-0xa00fc1a0 (68 bytes)
a00fc15c:  03 34 01 00  sethi  %hi(0xd0040000), %g1
a00fc160:  96 10 62 00  or  %g1, 0x200, %o3	! 0xd0040200
a00fc164:  90 0a 20 ff  and  %o0, 0xff, %o0
a00fc168:  80 a2 20 01  cmp  %o0, 1
a00fc16c:  02 80 00 07  be  0xa00fc188
a00fc170:  98 10 00 0b  mov  %o3, %o4
a00fc174:  c2 02 c0 00  ld  [ %o3 ], %g1
a00fc178:  11 20 00 00  sethi  %hi(0x80000000), %o0
a00fc17c:  96 10 40 08  or  %g1, %o0, %o3
a00fc180:  d6 23 00 00  st  %o3, [ %o4 ]
a00fc184:  30 80 00 05  b,a   0xa00fc198
a00fc188:  da 02 c0 00  ld  [ %o3 ], %o5
a00fc18c:  11 20 00 00  sethi  %hi(0x80000000), %o0
a00fc190:  98 2b 40 08  andn  %o5, %o0, %o4
a00fc194:  d8 22 c0 00  st  %o4, [ %o3 ]
a00fc198:  81 c3 e0 08  retl
a00fc19c:  01 00 00 00  nop
