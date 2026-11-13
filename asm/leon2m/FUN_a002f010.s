# leon2m FUN_a002f010 0xa002f010-0xa002f04c (60 bytes)
a002f010:  9d e3 bf 98  save  %sp, -104, %sp
a002f014:  15 33 c0 1c  sethi  %hi(0xcf007000), %o2
a002f018:  96 12 a3 30  or  %o2, 0x330, %o3	! 0xcf007330
a002f01c:  92 12 a3 34  or  %o2, 0x334, %o1
a002f020:  c0 22 c0 00  clr  [ %o3 ]
a002f024:  c0 22 40 00  clr  [ %o1 ]
a002f028:  90 10 20 02  mov  2, %o0
a002f02c:  7f ff fc e6  call  0xa002e3c4
a002f030:  92 10 20 01  mov  1, %o1
a002f034:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a002f038:  d0 03 61 e4  ld  [ %o5 + 0x1e4 ], %o0	! 0xa802c9e4
a002f03c:  82 12 20 04  or  %o0, 4, %g1
a002f040:  c2 23 61 e4  st  %g1, [ %o5 + 0x1e4 ]
a002f044:  81 c7 e0 08  ret
a002f048:  81 e8 00 00  restore
