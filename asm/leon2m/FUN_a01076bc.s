# leon2m FUN_a01076bc 0xa01076bc-0xa010771c (96 bytes)
a01076bc:  1b 33 c0 5a  sethi  %hi(0xcf016800), %o5
a01076c0:  03 33 c0 3b  sethi  %hi(0xcf00ec00), %g1
a01076c4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01076c8:  82 10 61 14  or  %g1, 0x114, %g1
a01076cc:  94 13 60 a8  or  %o5, 0xa8, %o2
a01076d0:  96 13 60 b8  or  %o5, 0xb8, %o3
a01076d4:  80 a2 20 01  cmp  %o0, 1
a01076d8:  02 80 00 06  be  0xa01076f0
a01076dc:  98 13 60 c0  or  %o5, 0xc0, %o4
a01076e0:  19 33 c0 5a  sethi  %hi(0xcf016800), %o4
a01076e4:  96 13 20 a8  or  %o4, 0xa8, %o3	! 0xcf0168a8
a01076e8:  c0 22 c0 00  clr  [ %o3 ]
a01076ec:  30 80 00 0a  b,a   0xa0107714
a01076f0:  da 00 40 00  ld  [ %g1 ], %o5
a01076f4:  90 0b 7f 7f  and  %o5, -129, %o0
a01076f8:  d0 20 40 00  st  %o0, [ %g1 ]
a01076fc:  9a 10 20 33  mov  0x33, %o5
a0107700:  da 22 80 00  st  %o5, [ %o2 ]
a0107704:  90 10 20 90  mov  0x90, %o0
a0107708:  d0 22 c0 00  st  %o0, [ %o3 ]
a010770c:  94 10 20 4e  mov  0x4e, %o2
a0107710:  d4 23 00 00  st  %o2, [ %o4 ]
a0107714:  81 c3 e0 08  retl
a0107718:  01 00 00 00  nop
