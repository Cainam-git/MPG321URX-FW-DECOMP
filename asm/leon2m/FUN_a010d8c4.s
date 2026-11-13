# leon2m FUN_a010d8c4 0xa010d8c4-0xa010d914 (80 bytes)
a010d8c4:  90 0a 20 ff  and  %o0, 0xff, %o0
a010d8c8:  17 10 00 80  sethi  %hi(0x40020000), %o3
a010d8cc:  80 a2 20 01  cmp  %o0, 1
a010d8d0:  02 80 00 09  be  0xa010d8f4
a010d8d4:  19 10 00 00  sethi  %hi(0x40000000), %o4
a010d8d8:  11 34 00 c8  sethi  %hi(0xd0032000), %o0
a010d8dc:  82 12 21 0c  or  %o0, 0x10c, %g1	! 0xd003210c
a010d8e0:  1b 34 00 e8  sethi  %hi(0xd003a000), %o5
a010d8e4:  d8 20 40 00  st  %o4, [ %g1 ]
a010d8e8:  96 13 61 0c  or  %o5, 0x10c, %o3
a010d8ec:  d8 22 c0 00  st  %o4, [ %o3 ]
a010d8f0:  30 80 00 07  b,a   0xa010d90c
a010d8f4:  11 34 00 c8  sethi  %hi(0xd0032000), %o0
a010d8f8:  98 12 21 0c  or  %o0, 0x10c, %o4	! 0xd003210c
a010d8fc:  03 34 00 e8  sethi  %hi(0xd003a000), %g1
a010d900:  d6 23 00 00  st  %o3, [ %o4 ]
a010d904:  9a 10 61 0c  or  %g1, 0x10c, %o5
a010d908:  d6 23 40 00  st  %o3, [ %o5 ]
a010d90c:  81 c3 e0 08  retl
a010d910:  01 00 00 00  nop
