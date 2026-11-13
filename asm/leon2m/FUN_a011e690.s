# leon2m FUN_a011e690 0xa011e690-0xa011e6dc (76 bytes)
a011e690:  9d e3 bf 98  save  %sp, -104, %sp
a011e694:  67 fd bf 04  call  0x4008e2a4
a011e698:  b0 0e 20 ff  and  %i0, 0xff, %i0
a011e69c:  03 33 c0 59  sethi  %hi(0xcf016400), %g1
a011e6a0:  98 10 60 04  or  %g1, 4, %o4	! 0xcf016404
a011e6a4:  80 a6 20 01  cmp  %i0, 1
a011e6a8:  02 80 00 07  be  0xa011e6c4
a011e6ac:  9a 10 00 0c  mov  %o4, %o5
a011e6b0:  de 03 00 00  ld  [ %o4 ], %o7
a011e6b4:  98 0b e0 3f  and  %o7, 0x3f, %o4
a011e6b8:  96 13 20 40  or  %o4, 0x40, %o3
a011e6bc:  d6 23 40 00  st  %o3, [ %o5 ]
a011e6c0:  30 80 00 05  b,a   0xa011e6d4
a011e6c4:  d4 03 00 00  ld  [ %o4 ], %o2
a011e6c8:  92 0a a0 3f  and  %o2, 0x3f, %o1
a011e6cc:  90 12 60 80  or  %o1, 0x80, %o0
a011e6d0:  d0 23 00 00  st  %o0, [ %o4 ]
a011e6d4:  81 c7 e0 08  ret
a011e6d8:  81 e8 00 00  restore
