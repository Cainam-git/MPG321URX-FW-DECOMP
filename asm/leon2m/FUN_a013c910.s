# leon2m FUN_a013c910 0xa013c910-0xa013c944 (52 bytes)
a013c910:  94 02 bf ff  add  %o2, -1, %o2
a013c914:  80 a2 bf ff  cmp  %o2, -1
a013c918:  02 80 00 09  be  0xa013c93c
a013c91c:  9a 10 00 08  mov  %o0, %o5
a013c920:  c2 0a 40 00  ldub  [ %o1 ], %g1
a013c924:  c2 2b 40 00  stb  %g1, [ %o5 ]
a013c928:  94 02 bf ff  add  %o2, -1, %o2
a013c92c:  92 02 60 01  inc  %o1
a013c930:  80 a2 bf ff  cmp  %o2, -1
a013c934:  12 bf ff fb  bne  0xa013c920
a013c938:  9a 03 60 01  inc  %o5
a013c93c:  81 c3 e0 08  retl
a013c940:  01 00 00 00  nop
