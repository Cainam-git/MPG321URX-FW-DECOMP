# leon2m FUN_a01266b0 0xa01266b0-0xa0126704 (84 bytes)
a01266b0:  9d e3 bf 90  save  %sp, -112, %sp
a01266b4:  7f ff f8 85  call  0xa01248c8
a01266b8:  21 2a 00 b6  sethi  %hi(0xa802d800), %l0
a01266bc:  80 8a 20 ff  btst  0xff, %o0
a01266c0:  90 10 20 60  mov  0x60, %o0
a01266c4:  92 10 20 02  mov  2, %o1
a01266c8:  94 10 20 1e  mov  0x1e, %o2
a01266cc:  96 10 20 05  mov  5, %o3
a01266d0:  02 80 00 06  be  0xa01266e8
a01266d4:  98 10 20 00  clr  %o4
a01266d8:  82 10 20 02  mov  2, %g1
a01266dc:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a01266e0:  40 00 85 02  call  0xa0147ae8
a01266e4:  9a 14 20 88  or  %l0, 0x88, %o5
a01266e8:  d2 0c 20 88  ldub  [ %l0 + 0x88 ], %o1
a01266ec:  9a 14 20 88  or  %l0, 0x88, %o5
a01266f0:  b1 2a 60 08  sll  %o1, 8, %i0
a01266f4:  d0 0b 60 01  ldub  [ %o5 + 1 ], %o0
a01266f8:  b0 12 00 18  or  %o0, %i0, %i0
a01266fc:  81 c7 e0 08  ret
a0126700:  81 e8 00 00  restore
