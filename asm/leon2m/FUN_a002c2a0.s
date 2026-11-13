# leon2m FUN_a002c2a0 0xa002c2a0-0xa002c2d4 (52 bytes)
a002c2a0:  98 0a 20 03  and  %o0, 3, %o4
a002c2a4:  99 2b 20 03  sll  %o4, 3, %o4
a002c2a8:  90 0a 3f fc  and  %o0, -4, %o0
a002c2ac:  82 10 20 ff  mov  0xff, %g1
a002c2b0:  da 02 00 00  ld  [ %o0 ], %o5
a002c2b4:  83 28 40 0c  sll  %g1, %o4, %g1
a002c2b8:  92 0a 60 ff  and  %o1, 0xff, %o1
a002c2bc:  82 2b 40 01  andn  %o5, %g1, %g1
a002c2c0:  93 2a 40 0c  sll  %o1, %o4, %o1
a002c2c4:  82 10 40 09  or  %g1, %o1, %g1
a002c2c8:  c2 22 00 00  st  %g1, [ %o0 ]
a002c2cc:  81 c3 e0 08  retl
a002c2d0:  01 00 00 00  nop
