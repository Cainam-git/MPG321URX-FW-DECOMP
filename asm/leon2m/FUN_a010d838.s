# leon2m FUN_a010d838 0xa010d838-0xa010d874 (60 bytes)
a010d838:  19 34 00 c0  sethi  %hi(0xd0030000), %o4
a010d83c:  98 13 20 2c  or  %o4, 0x2c, %o4	! 0xd003002c
a010d840:  03 3f fe 3f  sethi  %hi(0xfff8fc00), %g1
a010d844:  da 03 00 00  ld  [ %o4 ], %o5
a010d848:  82 10 63 fe  or  %g1, 0x3fe, %g1
a010d84c:  90 0a 20 ff  and  %o0, 0xff, %o0
a010d850:  9a 0b 40 01  and  %o5, %g1, %o5
a010d854:  83 2a 20 10  sll  %o0, 0x10, %g1
a010d858:  9a 13 40 01  or  %o5, %g1, %o5
a010d85c:  11 34 00 e0  sethi  %hi(0xd0038000), %o0
a010d860:  da 23 00 00  st  %o5, [ %o4 ]
a010d864:  82 12 20 2c  or  %o0, 0x2c, %g1
a010d868:  da 20 40 00  st  %o5, [ %g1 ]
a010d86c:  81 c3 e0 08  retl
a010d870:  01 00 00 00  nop
