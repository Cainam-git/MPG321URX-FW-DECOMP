# leon2m FUN_a0114374 0xa0114374-0xa011440c (152 bytes)
a0114374:  9d e3 bf 98  save  %sp, -104, %sp
a0114378:  1f 33 c0 45  sethi  %hi(0xcf011400), %o7
a011437c:  82 13 e2 6c  or  %o7, 0x26c, %g1	! 0xcf01166c
a0114380:  f4 00 40 00  ld  [ %g1 ], %i2
a0114384:  b8 0e 60 ff  and  %i1, 0xff, %i4
a0114388:  ba 0e a0 03  and  %i2, 3, %i5
a011438c:  82 10 00 18  mov  %i0, %g1
a0114390:  b2 10 20 00  clr  %i1
a0114394:  b4 10 20 40  mov  0x40, %i2
a0114398:  b6 10 20 00  clr  %i3
a011439c:  80 a7 00 1d  cmp  %i4, %i5
a01143a0:  02 80 00 04  be  0xa01143b0
a01143a4:  b0 10 00 1c  mov  %i4, %i0
a01143a8:  7f ff 75 ed  call  0xa00f1b5c
a01143ac:  81 e8 00 00  restore
a01143b0:  ba 10 20 01  mov  1, %i5
a01143b4:  9a 13 e2 70  or  %o7, 0x270, %o5
a01143b8:  b2 10 20 00  clr  %i1
a01143bc:  b4 10 20 40  mov  0x40, %i2
a01143c0:  80 88 60 ff  btst  0xff, %g1
a01143c4:  02 80 00 08  be  0xa01143e4
a01143c8:  b6 10 20 01  mov  1, %i3
a01143cc:  03 33 c0 56  sethi  %hi(0xcf015800), %g1
a01143d0:  b8 10 62 00  or  %g1, 0x200, %i4	! 0xcf015a00
a01143d4:  fa 27 00 00  st  %i5, [ %i4 ]
a01143d8:  fa 23 40 00  st  %i5, [ %o5 ]
a01143dc:  7f ff 75 e0  call  0xa00f1b5c
a01143e0:  81 e8 00 00  restore
a01143e4:  33 33 c0 56  sethi  %hi(0xcf015800), %i1
a01143e8:  b0 16 62 00  or  %i1, 0x200, %i0	! 0xcf015a00
a01143ec:  c0 26 00 00  clr  [ %i0 ]
a01143f0:  c0 23 40 00  clr  [ %o5 ]
a01143f4:  b0 10 00 1c  mov  %i4, %i0
a01143f8:  b2 10 20 00  clr  %i1
a01143fc:  b4 10 20 40  mov  0x40, %i2
a0114400:  7f ff 75 d7  call  0xa00f1b5c
a0114404:  97 e8 20 00  restore  %g0, 0, %o3
a0114408:  01 00 00 00  nop
