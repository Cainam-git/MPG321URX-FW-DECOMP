# leon2s FUN_a00a73ac 0xa00a73ac-0xa00a73d4 (40 bytes)
a00a73ac:  99 32 20 05  srl  %o0, 5, %o4
a00a73b0:  99 2b 20 02  sll  %o4, 2, %o4
a00a73b4:  90 0a 20 1f  and  %o0, 0x1f, %o0
a00a73b8:  9a 10 20 01  mov  1, %o5
a00a73bc:  c2 02 40 0c  ld  [ %o1 + %o4 ], %g1
a00a73c0:  9b 2b 40 08  sll  %o5, %o0, %o5
a00a73c4:  82 10 40 0d  or  %g1, %o5, %g1
a00a73c8:  c2 22 40 0c  st  %g1, [ %o1 + %o4 ]
a00a73cc:  81 c3 e0 08  retl
a00a73d0:  01 00 00 00  nop
