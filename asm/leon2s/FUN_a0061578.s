# leon2s FUN_a0061578 0xa0061578-0xa00615ac (52 bytes)
a0061578:  9a 0a 20 03  and  %o0, 3, %o5
a006157c:  9b 2b 60 03  sll  %o5, 3, %o5
a0061580:  90 0a 3f fc  and  %o0, -4, %o0
a0061584:  82 10 20 ff  mov  0xff, %g1
a0061588:  d8 02 00 00  ld  [ %o0 ], %o4
a006158c:  83 28 40 0d  sll  %g1, %o5, %g1
a0061590:  92 0a 60 ff  and  %o1, 0xff, %o1
a0061594:  82 2b 00 01  andn  %o4, %g1, %g1
a0061598:  93 2a 40 0d  sll  %o1, %o5, %o1
a006159c:  98 10 40 09  or  %g1, %o1, %o4
a00615a0:  d8 22 00 00  st  %o4, [ %o0 ]
a00615a4:  81 c3 e0 08  retl
a00615a8:  01 00 00 00  nop
