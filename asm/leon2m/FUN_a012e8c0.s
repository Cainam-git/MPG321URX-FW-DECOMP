# leon2m FUN_a012e8c0 0xa012e8c0-0xa012e928 (52 bytes)
a012e8c0:  90 0a 20 ff  and  %o0, 0xff, %o0
a012e8c4:  82 02 3f f0  add  %o0, -16, %g1
a012e8c8:  80 a0 60 06  cmp  %g1, 6
a012e8cc:  18 80 00 15  bgu  0xa012e920
a012e8d0:  90 10 20 01  mov  1, %o0
a012e8d4:  11 00 03 33  sethi  %hi(0xccc00), %o0
a012e8d8:  83 28 60 02  sll  %g1, 2, %g1
a012e8dc:  9a 12 22 a0  or  %o0, 0x2a0, %o5
a012e8e0:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a012e8e4:  81 c3 00 00  jmp  %o4
a012e8e8:  01 00 00 00  nop
a012e8ec:  10 80 00 0d  b  0xa012e920
a012e8f0:  90 10 20 01  mov  1, %o0	! 0x1
a012e8f4:  10 80 00 0b  b  0xa012e920
a012e8f8:  90 10 3f 80  mov  -128, %o0
a012e8fc:  10 80 00 09  b  0xa012e920
a012e900:  90 10 20 02  mov  2, %o0
a012e904:  10 80 00 07  b  0xa012e920
a012e908:  90 10 20 04  mov  4, %o0
a012e90c:  10 80 00 05  b  0xa012e920
a012e910:  90 10 20 10  mov  0x10, %o0
a012e914:  10 80 00 03  b  0xa012e920
a012e918:  90 10 20 20  mov  0x20, %o0
a012e91c:  90 10 20 40  mov  0x40, %o0
a012e920:  81 c3 e0 08  retl
a012e924:  90 0a 20 f7  and  %o0, 0xf7, %o0
