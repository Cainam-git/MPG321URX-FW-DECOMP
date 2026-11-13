# leon2m FUN_a010b884 0xa010b884-0xa010b8e8 (100 bytes)
a010b884:  1b 33 c0 2e  sethi  %hi(0xcf00b800), %o5
a010b888:  92 13 60 70  or  %o5, 0x70, %o1	! 0xcf00b870
a010b88c:  90 0a 20 ff  and  %o0, 0xff, %o0
a010b890:  98 13 60 44  or  %o5, 0x44, %o4
a010b894:  80 a2 20 01  cmp  %o0, 1
a010b898:  02 80 00 09  be  0xa010b8bc
a010b89c:  94 10 00 09  mov  %o1, %o2
a010b8a0:  da 03 00 00  ld  [ %o4 ], %o5
a010b8a4:  90 13 60 c0  or  %o5, 0xc0, %o0
a010b8a8:  d0 23 00 00  st  %o0, [ %o4 ]
a010b8ac:  d8 02 40 00  ld  [ %o1 ], %o4
a010b8b0:  92 0b 3f 7f  and  %o4, -129, %o1
a010b8b4:  d2 22 80 00  st  %o1, [ %o2 ]
a010b8b8:  30 80 00 0a  b,a   0xa010b8e0
a010b8bc:  c2 03 00 00  ld  [ %o4 ], %g1
a010b8c0:  9a 08 7f 7f  and  %g1, -129, %o5
a010b8c4:  da 23 00 00  st  %o5, [ %o4 ]
a010b8c8:  d0 03 00 00  ld  [ %o4 ], %o0
a010b8cc:  96 12 20 40  or  %o0, 0x40, %o3
a010b8d0:  d6 23 00 00  st  %o3, [ %o4 ]
a010b8d4:  d4 02 40 00  ld  [ %o1 ], %o2
a010b8d8:  82 12 a0 80  or  %o2, 0x80, %g1
a010b8dc:  c2 22 40 00  st  %g1, [ %o1 ]
a010b8e0:  81 c3 e0 08  retl
a010b8e4:  01 00 00 00  nop
