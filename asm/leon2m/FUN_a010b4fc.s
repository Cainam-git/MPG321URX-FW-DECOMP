# leon2m FUN_a010b4fc 0xa010b4fc-0xa010b530 (52 bytes)
a010b4fc:  9a 0a 20 ff  and  %o0, 0xff, %o5
a010b500:  80 a3 60 03  cmp  %o5, 3
a010b504:  82 40 20 00  addx  %g0, 0, %g1
a010b508:  82 20 00 01  neg  %g1
a010b50c:  90 0b 40 01  and  %o5, %g1, %o0
a010b510:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010b514:  91 2a 20 02  sll  %o0, 2, %o0
a010b518:  82 13 62 f0  or  %o5, 0x2f0, %g1
a010b51c:  da 00 40 08  ld  [ %g1 + %o0 ], %o5
a010b520:  93 2a 60 02  sll  %o1, 2, %o1
a010b524:  d0 03 40 09  ld  [ %o5 + %o1 ], %o0
a010b528:  81 c3 e0 08  retl
a010b52c:  01 00 00 00  nop
