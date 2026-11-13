# leon2s FUN_a00919b0 0xa00919b0-0xa00919e0 (48 bytes)
a00919b0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00919b4:  9b 2a 20 03  sll  %o0, 3, %o5
a00919b8:  9a 23 40 08  sub  %o5, %o0, %o5
a00919bc:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00919c0:  82 10 61 80  or  %g1, 0x180, %g1	! 0xa807d580
a00919c4:  9b 2b 60 02  sll  %o5, 2, %o5
a00919c8:  9a 03 40 01  add  %o5, %g1, %o5
a00919cc:  d8 03 60 14  ld  [ %o5 + 0x14 ], %o4
a00919d0:  03 00 00 08  sethi  %hi(0x2000), %g1
a00919d4:  82 2b 00 01  andn  %o4, %g1, %g1
a00919d8:  81 c3 e0 08  retl
a00919dc:  c2 23 60 14  st  %g1, [ %o5 + 0x14 ]
