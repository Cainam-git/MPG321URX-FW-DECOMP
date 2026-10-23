# leon2m FUN_a0109598 0xa0109598-0xa01095bc (36 bytes)
a0109598:  19 33 c0 46  sethi  %hi(0xcf011800), %o4
a010959c:  82 10 20 01  mov  1, %g1
a01095a0:  83 28 40 08  sll  %g1, %o0, %g1
a01095a4:  9a 13 22 00  or  %o4, 0x200, %o5
a01095a8:  d0 03 40 00  ld  [ %o5 ], %o0
a01095ac:  98 0a 00 01  and  %o0, %g1, %o4
a01095b0:  80 a0 00 0c  cmp  %g0, %o4
a01095b4:  81 c3 e0 08  retl
a01095b8:  90 40 20 00  addx  %g0, 0, %o0
