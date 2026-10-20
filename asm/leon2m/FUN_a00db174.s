# leon2m FUN_a00db174 0xa00db174-0xa00db1a8 (52 bytes)
a00db174:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a00db178:  da 02 20 84  ld  [ %o0 + 0x84 ], %o5	! 0xa802d484
a00db17c:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00db180:  80 8b 40 01  btst  %o5, %g1
a00db184:  02 80 00 05  be  0xa00db198
a00db188:  90 10 20 01  mov  1, %o0
a00db18c:  82 13 c0 00  mov  %o7, %g1
a00db190:  40 01 24 8b  call  0xa01243bc
a00db194:  9e 10 40 00  mov  %g1, %o7
a00db198:  90 10 20 00  clr  %o0
a00db19c:  82 13 c0 00  mov  %o7, %g1
a00db1a0:  40 01 24 87  call  0xa01243bc
a00db1a4:  9e 10 40 00  mov  %g1, %o7
