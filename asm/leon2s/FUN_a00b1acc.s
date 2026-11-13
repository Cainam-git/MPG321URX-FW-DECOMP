# leon2s FUN_a00b1acc 0xa00b1acc-0xa00b1b18 (76 bytes)
a00b1acc:  17 27 c4 80  sethi  %hi(0x9f120000), %o3
a00b1ad0:  9a 12 e0 48  or  %o3, 0x48, %o5	! 0x9f120048
a00b1ad4:  c2 03 40 00  ld  [ %o5 ], %g1
a00b1ad8:  82 10 60 80  or  %g1, 0x80, %g1
a00b1adc:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1ae0:  d8 03 40 00  ld  [ %o5 ], %o4
a00b1ae4:  03 00 20 00  sethi  %hi(0x800000), %g1
a00b1ae8:  82 2b 00 01  andn  %o4, %g1, %g1
a00b1aec:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1af0:  9a 12 e0 80  or  %o3, 0x80, %o5
a00b1af4:  c2 03 40 00  ld  [ %o5 ], %g1
a00b1af8:  82 10 60 80  or  %g1, 0x80, %g1
a00b1afc:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1b00:  96 12 e0 34  or  %o3, 0x34, %o3
a00b1b04:  c2 02 c0 00  ld  [ %o3 ], %g1
a00b1b08:  82 10 60 20  or  %g1, 0x20, %g1
a00b1b0c:  c2 22 c0 00  st  %g1, [ %o3 ]
a00b1b10:  81 c3 e0 08  retl
a00b1b14:  01 00 00 00  nop
