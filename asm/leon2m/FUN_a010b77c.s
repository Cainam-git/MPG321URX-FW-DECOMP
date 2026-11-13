# leon2m FUN_a010b77c 0xa010b77c-0xa010b884 (264 bytes)
a010b77c:  9d e3 bf 98  save  %sp, -104, %sp
a010b780:  23 33 c0 2e  sethi  %hi(0xcf00b800), %l1
a010b784:  e4 04 40 00  ld  [ %l1 ], %l2
a010b788:  a0 14 a0 10  or  %l2, 0x10, %l0
a010b78c:  e0 24 40 00  st  %l0, [ %l1 ]
a010b790:  25 34 00 c0  sethi  %hi(0xd0030000), %l2
a010b794:  a0 14 a0 f0  or  %l2, 0xf0, %l0	! 0xd00300f0
a010b798:  d4 04 00 00  ld  [ %l0 ], %o2
a010b79c:  13 01 00 00  sethi  %hi(0x4000000), %o1
a010b7a0:  82 2a 80 09  andn  %o2, %o1, %g1
a010b7a4:  c2 24 00 00  st  %g1, [ %l0 ]
a010b7a8:  67 fe 06 7e  call  0x4008d1a0
a010b7ac:  90 10 20 01  mov  1, %o0
a010b7b0:  de 04 00 00  ld  [ %l0 ], %o7
a010b7b4:  11 01 00 00  sethi  %hi(0x4000000), %o0
a010b7b8:  9a 13 c0 08  or  %o7, %o0, %o5
a010b7bc:  da 24 00 00  st  %o5, [ %l0 ]
a010b7c0:  d8 04 00 00  ld  [ %l0 ], %o4
a010b7c4:  96 13 20 10  or  %o4, 0x10, %o3
a010b7c8:  d6 24 00 00  st  %o3, [ %l0 ]
a010b7cc:  67 fe 06 75  call  0x4008d1a0
a010b7d0:  90 10 20 02  mov  2, %o0
a010b7d4:  d4 04 00 00  ld  [ %l0 ], %o2
a010b7d8:  92 0a bf ef  and  %o2, -17, %o1
a010b7dc:  d2 24 00 00  st  %o1, [ %l0 ]
a010b7e0:  40 00 45 ea  call  0xa011cf88
a010b7e4:  01 00 00 00  nop
a010b7e8:  03 34 00 e0  sethi  %hi(0xd0038000), %g1
a010b7ec:  90 0a 20 ff  and  %o0, 0xff, %o0
a010b7f0:  17 00 00 10  sethi  %hi(0x4000), %o3
a010b7f4:  80 a2 20 81  cmp  %o0, 0x81
a010b7f8:  18 80 00 0e  bgu  0xa010b830
a010b7fc:  98 10 60 f0  or  %g1, 0xf0, %o4
a010b800:  de 04 00 00  ld  [ %l0 ], %o7
a010b804:  9a 13 e4 00  or  %o7, 0x400, %o5
a010b808:  da 24 00 00  st  %o5, [ %l0 ]
a010b80c:  d4 04 00 00  ld  [ %l0 ], %o2
a010b810:  92 12 80 0b  or  %o2, %o3, %o1
a010b814:  d2 24 00 00  st  %o1, [ %l0 ]
a010b818:  c2 03 00 00  ld  [ %o4 ], %g1
a010b81c:  90 10 64 00  or  %g1, 0x400, %o0
a010b820:  d0 23 00 00  st  %o0, [ %o4 ]
a010b824:  de 03 00 00  ld  [ %o4 ], %o7
a010b828:  9a 13 c0 0b  or  %o7, %o3, %o5
a010b82c:  da 23 00 00  st  %o5, [ %o4 ]
a010b830:  40 00 45 d6  call  0xa011cf88
a010b834:  01 00 00 00  nop
a010b838:  9a 14 60 44  or  %l1, 0x44, %o5
a010b83c:  96 14 60 70  or  %l1, 0x70, %o3
a010b840:  a2 0a 20 ff  and  %o0, 0xff, %l1
a010b844:  94 14 a0 08  or  %l2, 8, %o2
a010b848:  80 a4 60 81  cmp  %l1, 0x81
a010b84c:  08 80 00 08  bleu  0xa010b86c
a010b850:  98 10 21 00  mov  0x100, %o4
a010b854:  c2 03 40 00  ld  [ %o5 ], %g1
a010b858:  90 10 60 40  or  %g1, 0x40, %o0
a010b85c:  d0 23 40 00  st  %o0, [ %o5 ]
a010b860:  e4 02 c0 00  ld  [ %o3 ], %l2
a010b864:  a0 14 a0 80  or  %l2, 0x80, %l0
a010b868:  e0 22 c0 00  st  %l0, [ %o3 ]
a010b86c:  13 34 00 e0  sethi  %hi(0xd0038000), %o1
a010b870:  d8 22 80 00  st  %o4, [ %o2 ]
a010b874:  96 12 60 08  or  %o1, 8, %o3
a010b878:  d8 22 c0 00  st  %o4, [ %o3 ]
a010b87c:  81 c7 e0 08  ret
a010b880:  81 e8 00 00  restore
