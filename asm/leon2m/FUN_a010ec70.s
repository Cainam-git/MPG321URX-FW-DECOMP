# leon2m FUN_a010ec70 0xa010ec70-0xa010eca8 (56 bytes)
a010ec70:  19 34 00 c0  sethi  %hi(0xd0030000), %o4
a010ec74:  98 13 20 2c  or  %o4, 0x2c, %o4	! 0xd003002c
a010ec78:  c2 03 00 00  ld  [ %o4 ], %g1
a010ec7c:  1b 00 01 c0  sethi  %hi(0x70000), %o5
a010ec80:  90 0a 20 ff  and  %o0, 0xff, %o0
a010ec84:  9a 28 40 0d  andn  %g1, %o5, %o5
a010ec88:  83 2a 20 10  sll  %o0, 0x10, %g1
a010ec8c:  9a 13 40 01  or  %o5, %g1, %o5
a010ec90:  11 34 00 e0  sethi  %hi(0xd0038000), %o0
a010ec94:  da 23 00 00  st  %o5, [ %o4 ]
a010ec98:  82 12 20 2c  or  %o0, 0x2c, %g1
a010ec9c:  da 20 40 00  st  %o5, [ %g1 ]
a010eca0:  81 c3 e0 08  retl
a010eca4:  01 00 00 00  nop
