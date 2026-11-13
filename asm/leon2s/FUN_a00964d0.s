# leon2s FUN_a00964d0 0xa00964d0-0xa0096538 (104 bytes)
a00964d0:  9d e3 bf 98  save  %sp, -104, %sp
a00964d4:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a00964d8:  96 10 62 c0  or  %g1, 0x2c0, %o3	! 0xcf0146c0
a00964dc:  94 10 62 c8  or  %g1, 0x2c8, %o2
a00964e0:  9a 10 63 00  or  %g1, 0x300, %o5
a00964e4:  98 10 62 cc  or  %g1, 0x2cc, %o4
a00964e8:  9e 10 63 08  or  %g1, 0x308, %o7
a00964ec:  ba 10 63 0c  or  %g1, 0x30c, %i5
a00964f0:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00964f4:  83 2e a0 04  sll  %i2, 4, %g1
a00964f8:  80 8e 20 ff  btst  0xff, %i0
a00964fc:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0096500:  b0 10 40 19  or  %g1, %i1, %i0
a0096504:  83 2e e0 10  sll  %i3, 0x10, %g1
a0096508:  b9 30 60 18  srl  %g1, 0x18, %i4
a009650c:  12 80 00 06  bne  0xa0096524
a0096510:  b6 0e e0 ff  and  %i3, 0xff, %i3
a0096514:  f0 22 c0 00  st  %i0, [ %o3 ]
a0096518:  f6 22 80 00  st  %i3, [ %o2 ]
a009651c:  f8 23 00 00  st  %i4, [ %o4 ]
a0096520:  30 80 00 04  b,a   0xa0096530
a0096524:  f0 23 40 00  st  %i0, [ %o5 ]
a0096528:  f6 23 c0 00  st  %i3, [ %o7 ]
a009652c:  f8 27 40 00  st  %i4, [ %i5 ]
a0096530:  81 c7 e0 08  ret
a0096534:  81 e8 00 00  restore
