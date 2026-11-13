# leon2s FUN_a008d980 0xa008d980-0xa008d9d4 (84 bytes)
a008d980:  9d e3 bf 98  save  %sp, -104, %sp
a008d984:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008d988:  90 10 00 18  mov  %i0, %o0
a008d98c:  92 10 20 01  mov  1, %o1
a008d990:  40 00 69 92  call  0xa00a7fd8
a008d994:  94 10 20 05  mov  5, %o2
a008d998:  b2 0e 60 ff  and  %i1, 0xff, %i1
a008d99c:  80 a6 60 01  cmp  %i1, 1
a008d9a0:  02 80 00 07  be  0xa008d9bc
a008d9a4:  90 0a 3f f3  and  %o0, -13, %o0
a008d9a8:  80 a6 60 02  cmp  %i1, 2
a008d9ac:  22 80 00 05  be,a   0xa008d9c0
a008d9b0:  b6 12 20 0c  or  %o0, 0xc, %i3
a008d9b4:  10 80 00 03  b  0xa008d9c0
a008d9b8:  b6 12 20 04  or  %o0, 4, %i3
a008d9bc:  b6 12 20 08  or  %o0, 8, %i3
a008d9c0:  b6 0e e0 ff  and  %i3, 0xff, %i3
a008d9c4:  b2 10 20 01  mov  1, %i1
a008d9c8:  40 00 69 a3  call  0xa00a8054
a008d9cc:  95 e8 20 05  restore  %g0, 5, %o2
a008d9d0:  01 00 00 00  nop
