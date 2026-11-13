# leon2m FUN_a0101a4c 0xa0101a4c-0xa0101a70 (36 bytes)
a0101a4c:  92 0a 60 ff  and  %o1, 0xff, %o1
a0101a50:  83 2a 60 04  sll  %o1, 4, %g1
a0101a54:  90 0a 20 ff  and  %o0, 0xff, %o0
a0101a58:  92 10 40 08  or  %g1, %o0, %o1
a0101a5c:  11 33 c0 58  sethi  %hi(0xcf016000), %o0
a0101a60:  82 12 21 08  or  %o0, 0x108, %g1	! 0xcf016108
a0101a64:  d2 20 40 00  st  %o1, [ %g1 ]
a0101a68:  81 c3 e0 08  retl
a0101a6c:  01 00 00 00  nop
