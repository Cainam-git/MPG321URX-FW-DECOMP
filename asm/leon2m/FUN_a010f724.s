# leon2m FUN_a010f724 0xa010f724-0xa010f7a4 (128 bytes)
a010f724:  90 0a 20 ff  and  %o0, 0xff, %o0
a010f728:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010f72c:  80 a2 20 01  cmp  %o0, 1
a010f730:  02 80 00 17  be  0xa010f78c
a010f734:  98 10 63 04  or  %g1, 0x304, %o4
a010f738:  da 0b 20 3e  ldub  [ %o4 + 0x3e ], %o5
a010f73c:  82 0b 7f fd  and  %o5, -3, %g1
a010f740:  80 a2 20 00  cmp  %o0, 0
a010f744:  12 80 00 0a  bne  0xa010f76c
a010f748:  c2 2b 20 3e  stb  %g1, [ %o4 + 0x3e ]
a010f74c:  11 34 00 c8  sethi  %hi(0xd0032000), %o0
a010f750:  82 12 22 80  or  %o0, 0x280, %g1	! 0xd0032280
a010f754:  da 03 20 04  ld  [ %o4 + 4 ], %o5
a010f758:  da 20 40 00  st  %o5, [ %g1 ]
a010f75c:  11 34 00 e8  sethi  %hi(0xd003a000), %o0
a010f760:  d8 03 20 08  ld  [ %o4 + 8 ], %o4
a010f764:  10 80 00 0d  b  0xa010f798
a010f768:  82 12 22 80  or  %o0, 0x280, %g1
a010f76c:  03 34 00 c8  sethi  %hi(0xd0032000), %g1
a010f770:  da 03 20 04  ld  [ %o4 + 4 ], %o5
a010f774:  90 10 62 84  or  %g1, 0x284, %o0
a010f778:  da 22 00 00  st  %o5, [ %o0 ]
a010f77c:  03 34 00 e8  sethi  %hi(0xd003a000), %g1
a010f780:  d8 03 20 08  ld  [ %o4 + 8 ], %o4
a010f784:  10 80 00 05  b  0xa010f798
a010f788:  82 10 62 84  or  %g1, 0x284, %g1
a010f78c:  1b 2a 00 b6  sethi  %hi(0xa802d800), %o5
a010f790:  10 bf ff ea  b  0xa010f738
a010f794:  98 13 60 04  or  %o5, 4, %o4	! 0xa802d804
a010f798:  d8 20 40 00  st  %o4, [ %g1 ]
a010f79c:  81 c3 e0 08  retl
a010f7a0:  01 00 00 00  nop
