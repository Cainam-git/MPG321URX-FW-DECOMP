# leon2m FUN_a010777c 0xa010777c-0xa01077dc (96 bytes)
a010777c:  1b 33 c0 5a  sethi  %hi(0xcf016800), %o5
a0107780:  03 33 c0 3b  sethi  %hi(0xcf00ec00), %g1
a0107784:  90 0a 20 ff  and  %o0, 0xff, %o0
a0107788:  82 10 61 14  or  %g1, 0x114, %g1
a010778c:  94 13 61 a8  or  %o5, 0x1a8, %o2
a0107790:  96 13 61 b8  or  %o5, 0x1b8, %o3
a0107794:  80 a2 20 01  cmp  %o0, 1
a0107798:  02 80 00 06  be  0xa01077b0
a010779c:  98 13 61 c0  or  %o5, 0x1c0, %o4
a01077a0:  19 33 c0 5a  sethi  %hi(0xcf016800), %o4
a01077a4:  96 13 21 a8  or  %o4, 0x1a8, %o3	! 0xcf0169a8
a01077a8:  c0 22 c0 00  clr  [ %o3 ]
a01077ac:  30 80 00 0a  b,a   0xa01077d4
a01077b0:  da 00 40 00  ld  [ %g1 ], %o5
a01077b4:  90 0b 7f 7f  and  %o5, -129, %o0
a01077b8:  d0 20 40 00  st  %o0, [ %g1 ]
a01077bc:  9a 10 20 33  mov  0x33, %o5
a01077c0:  da 22 80 00  st  %o5, [ %o2 ]
a01077c4:  90 10 20 90  mov  0x90, %o0
a01077c8:  d0 22 c0 00  st  %o0, [ %o3 ]
a01077cc:  94 10 20 4e  mov  0x4e, %o2
a01077d0:  d4 23 00 00  st  %o2, [ %o4 ]
a01077d4:  81 c3 e0 08  retl
a01077d8:  01 00 00 00  nop
