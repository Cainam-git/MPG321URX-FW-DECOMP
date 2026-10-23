# leon2m FUN_a010daf8 0xa010daf8-0xa010db2c (52 bytes)
a010daf8:  9a 0a 20 ff  and  %o0, 0xff, %o5
a010dafc:  80 a3 60 02  cmp  %o5, 2
a010db00:  82 40 20 00  addx  %g0, 0, %g1
a010db04:  82 20 00 01  neg  %g1
a010db08:  90 0b 40 01  and  %o5, %g1, %o0
a010db0c:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010db10:  91 2a 20 02  sll  %o0, 2, %o0
a010db14:  82 13 62 c4  or  %o5, 0x2c4, %g1
a010db18:  da 00 40 08  ld  [ %g1 + %o0 ], %o5
a010db1c:  93 2a 60 02  sll  %o1, 2, %o1
a010db20:  d0 03 40 09  ld  [ %o5 + %o1 ], %o0
a010db24:  81 c3 e0 08  retl
a010db28:  01 00 00 00  nop
