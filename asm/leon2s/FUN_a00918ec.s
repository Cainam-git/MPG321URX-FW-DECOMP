# leon2s FUN_a00918ec 0xa00918ec-0xa0091918 (44 bytes)
a00918ec:  90 0a 20 ff  and  %o0, 0xff, %o0
a00918f0:  9b 2a 20 03  sll  %o0, 3, %o5
a00918f4:  9a 23 40 08  sub  %o5, %o0, %o5
a00918f8:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00918fc:  82 10 61 80  or  %g1, 0x180, %g1	! 0xa807d580
a0091900:  9b 2b 60 02  sll  %o5, 2, %o5
a0091904:  9a 03 40 01  add  %o5, %g1, %o5
a0091908:  c2 03 60 10  ld  [ %o5 + 0x10 ], %g1
a009190c:  82 10 60 04  or  %g1, 4, %g1
a0091910:  81 c3 e0 08  retl
a0091914:  c2 23 60 10  st  %g1, [ %o5 + 0x10 ]
