# leon2m FUN_a010b5dc 0xa010b5dc-0xa010b610 (52 bytes)
a010b5dc:  9a 0a 20 ff  and  %o0, 0xff, %o5
a010b5e0:  80 a3 60 03  cmp  %o5, 3
a010b5e4:  82 40 20 00  addx  %g0, 0, %g1
a010b5e8:  82 20 00 01  neg  %g1
a010b5ec:  90 0b 40 01  and  %o5, %g1, %o0
a010b5f0:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010b5f4:  91 2a 20 02  sll  %o0, 2, %o0
a010b5f8:  82 13 62 d8  or  %o5, 0x2d8, %g1
a010b5fc:  da 00 40 08  ld  [ %g1 + %o0 ], %o5
a010b600:  93 2a 60 02  sll  %o1, 2, %o1
a010b604:  d0 03 40 09  ld  [ %o5 + %o1 ], %o0
a010b608:  81 c3 e0 08  retl
a010b60c:  01 00 00 00  nop
