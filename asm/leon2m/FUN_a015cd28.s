# leon2m FUN_a015cd28 0xa015cd28-0xa015cd54 (44 bytes)
a015cd28:  80 a2 60 00  cmp  %o1, 0
a015cd2c:  02 80 00 08  be  0xa015cd4c
a015cd30:  01 00 00 00  nop
a015cd34:  c2 02 60 04  ld  [ %o1 + 4 ], %g1
a015cd38:  d8 02 20 4c  ld  [ %o0 + 0x4c ], %o4
a015cd3c:  83 28 60 02  sll  %g1, 2, %g1
a015cd40:  da 03 00 01  ld  [ %o4 + %g1 ], %o5
a015cd44:  da 22 40 00  st  %o5, [ %o1 ]
a015cd48:  d2 23 00 01  st  %o1, [ %o4 + %g1 ]
a015cd4c:  81 c3 e0 08  retl
a015cd50:  01 00 00 00  nop
