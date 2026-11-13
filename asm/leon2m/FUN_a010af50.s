# leon2m FUN_a010af50 0xa010af50-0xa010af6c (28 bytes)
a010af50:  1b 33 c0 3a  sethi  %hi(0xcf00e800), %o5
a010af54:  9a 13 62 c8  or  %o5, 0x2c8, %o5	! 0xcf00eac8
a010af58:  c2 03 40 00  ld  [ %o5 ], %g1
a010af5c:  82 08 7f f7  and  %g1, -9, %g1
a010af60:  c2 23 40 00  st  %g1, [ %o5 ]
a010af64:  81 c3 e0 08  retl
a010af68:  01 00 00 00  nop
