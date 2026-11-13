# leon2m FUN_a010b6e4 0xa010b6e4-0xa010b77c (152 bytes)
a010b6e4:  9d e3 bf 98  save  %sp, -104, %sp
a010b6e8:  23 34 00 c0  sethi  %hi(0xd0030000), %l1
a010b6ec:  a2 14 60 f0  or  %l1, 0xf0, %l1	! 0xd00300f0
a010b6f0:  d0 04 40 00  ld  [ %l1 ], %o0
a010b6f4:  82 12 24 00  or  %o0, 0x400, %g1
a010b6f8:  21 34 00 e0  sethi  %hi(0xd0038000), %l0
a010b6fc:  c2 24 40 00  st  %g1, [ %l1 ]
a010b700:  a0 14 20 f0  or  %l0, 0xf0, %l0
a010b704:  da 04 00 00  ld  [ %l0 ], %o5
a010b708:  9e 13 64 00  or  %o5, 0x400, %o7
a010b70c:  de 24 00 00  st  %o7, [ %l0 ]
a010b710:  d6 04 40 00  ld  [ %l1 ], %o3
a010b714:  19 00 00 10  sethi  %hi(0x4000), %o4
a010b718:  94 12 c0 0c  or  %o3, %o4, %o2
a010b71c:  d4 24 40 00  st  %o2, [ %l1 ]
a010b720:  d2 04 00 00  ld  [ %l0 ], %o1
a010b724:  90 12 40 0c  or  %o1, %o4, %o0
a010b728:  d0 24 00 00  st  %o0, [ %l0 ]
a010b72c:  67 fe 0a de  call  0x4008e2a4
a010b730:  01 00 00 00  nop
a010b734:  67 fe 0a dc  call  0x4008e2a4
a010b738:  01 00 00 00  nop
a010b73c:  c2 04 40 00  ld  [ %l1 ], %g1
a010b740:  9a 08 7b ff  and  %g1, -1025, %o5
a010b744:  da 24 40 00  st  %o5, [ %l1 ]
a010b748:  de 04 00 00  ld  [ %l0 ], %o7
a010b74c:  96 0b fb ff  and  %o7, -1025, %o3
a010b750:  d6 24 00 00  st  %o3, [ %l0 ]
a010b754:  15 3f ff ef  sethi  %hi(0xffffbc00), %o2
a010b758:  d2 04 40 00  ld  [ %l1 ], %o1
a010b75c:  98 12 a3 ff  or  %o2, 0x3ff, %o4
a010b760:  90 0a 40 0c  and  %o1, %o4, %o0
a010b764:  d0 24 40 00  st  %o0, [ %l1 ]
a010b768:  c2 04 00 00  ld  [ %l0 ], %g1
a010b76c:  9a 08 40 0c  and  %g1, %o4, %o5
a010b770:  da 24 00 00  st  %o5, [ %l0 ]
a010b774:  81 c7 e0 08  ret
a010b778:  81 e8 00 00  restore
