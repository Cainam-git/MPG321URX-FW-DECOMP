# leon2s FUN_a00919e0 0xa00919e0-0xa0091a10 (48 bytes)
a00919e0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00919e4:  9b 2a 20 03  sll  %o0, 3, %o5
a00919e8:  9a 23 40 08  sub  %o5, %o0, %o5
a00919ec:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00919f0:  82 10 61 80  or  %g1, 0x180, %g1	! 0xa807d580
a00919f4:  9b 2b 60 02  sll  %o5, 2, %o5
a00919f8:  9a 03 40 01  add  %o5, %g1, %o5
a00919fc:  c2 03 60 14  ld  [ %o5 + 0x14 ], %g1
a0091a00:  19 00 00 08  sethi  %hi(0x2000), %o4
a0091a04:  82 10 40 0c  or  %g1, %o4, %g1
a0091a08:  81 c3 e0 08  retl
a0091a0c:  c2 23 60 14  st  %g1, [ %o5 + 0x14 ]
