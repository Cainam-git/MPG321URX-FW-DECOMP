# leon2m FUN_a01190b0 0xa01190b0-0xa0119114 (100 bytes)
a01190b0:  9d e3 bf 98  save  %sp, -104, %sp
a01190b4:  40 00 0f b5  call  0xa011cf88
a01190b8:  01 00 00 00  nop
a01190bc:  03 33 c0 4b  sethi  %hi(0xcf012c00), %g1
a01190c0:  1b 33 c0 46  sethi  %hi(0xcf011800), %o5
a01190c4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01190c8:  98 13 62 00  or  %o5, 0x200, %o4
a01190cc:  96 10 62 00  or  %g1, 0x200, %o3
a01190d0:  80 a2 20 83  cmp  %o0, 0x83
a01190d4:  08 80 00 0e  bleu  0xa011910c
a01190d8:  94 10 63 74  or  %g1, 0x374, %o2
a01190dc:  de 03 40 00  ld  [ %o5 ], %o7
a01190e0:  92 13 e0 20  or  %o7, 0x20, %o1
a01190e4:  d2 23 40 00  st  %o1, [ %o5 ]
a01190e8:  c2 03 00 00  ld  [ %o4 ], %g1
a01190ec:  90 10 60 20  or  %g1, 0x20, %o0
a01190f0:  d0 23 00 00  st  %o0, [ %o4 ]
a01190f4:  de 02 c0 00  ld  [ %o3 ], %o7
a01190f8:  98 13 e0 01  or  %o7, 1, %o4
a01190fc:  d8 22 c0 00  st  %o4, [ %o3 ]
a0119100:  d2 02 80 00  ld  [ %o2 ], %o1
a0119104:  9a 12 60 02  or  %o1, 2, %o5
a0119108:  da 22 80 00  st  %o5, [ %o2 ]
a011910c:  81 c7 e0 08  ret
a0119110:  81 e8 00 00  restore
