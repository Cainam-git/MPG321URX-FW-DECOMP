# leon2m FUN_a011e148 0xa011e148-0xa011e220 (116 bytes)
a011e148:  82 0a 20 ff  and  %o0, 0xff, %g1
a011e14c:  80 a0 60 1f  cmp  %g1, 0x1f
a011e150:  18 80 00 09  bgu  0xa011e174
a011e154:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a011e158:  11 00 02 f5  sethi  %hi(0xbd400), %o0
a011e15c:  83 28 60 02  sll  %g1, 2, %g1
a011e160:  9a 12 20 70  or  %o0, 0x70, %o5
a011e164:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a011e168:  81 c3 00 00  jmp  %o4
a011e16c:  01 00 00 00  nop
a011e170:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a011e174:  96 13 61 20  or  %o5, 0x120, %o3	! 0xcf016120
a011e178:  d0 02 c0 00  ld  [ %o3 ], %o0
a011e17c:  98 0a 20 7c  and  %o0, 0x7c, %o4
a011e180:  d8 22 c0 00  st  %o4, [ %o3 ]
a011e184:  98 13 61 38  or  %o5, 0x138, %o4
a011e188:  c2 03 00 00  ld  [ %o4 ], %g1
a011e18c:  90 08 60 7c  and  %g1, 0x7c, %o0
a011e190:  d0 23 00 00  st  %o0, [ %o4 ]
a011e194:  90 13 61 50  or  %o5, 0x150, %o0
a011e198:  d6 02 00 00  ld  [ %o0 ], %o3
a011e19c:  82 0a e0 7c  and  %o3, 0x7c, %g1
a011e1a0:  c2 22 00 00  st  %g1, [ %o0 ]
a011e1a4:  10 80 00 1a  b  0xa011e20c
a011e1a8:  9a 13 61 68  or  %o5, 0x168, %o5
a011e1ac:  10 80 00 18  b  0xa011e20c
a011e1b0:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011e1b4:  17 33 c0 58  sethi  %hi(0xcf016000), %o3
a011e1b8:  10 80 00 15  b  0xa011e20c
a011e1bc:  9a 12 e1 20  or  %o3, 0x120, %o5	! 0xcf016120
a011e1c0:  19 33 c0 58  sethi  %hi(0xcf016000), %o4
a011e1c4:  10 80 00 12  b  0xa011e20c
a011e1c8:  9a 13 21 38  or  %o4, 0x138, %o5	! 0xcf016138
a011e1cc:  03 33 c0 58  sethi  %hi(0xcf016000), %g1
a011e1d0:  10 80 00 0f  b  0xa011e20c
a011e1d4:  9a 10 61 50  or  %g1, 0x150, %o5	! 0xcf016150
a011e1d8:  10 bf ff f3  b  0xa011e1a4
a011e1dc:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a011e1e0:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a011e1e4:  10 80 00 0a  b  0xa011e20c
a011e1e8:  9a 13 61 80  or  %o5, 0x180, %o5	! 0xcf016180
a011e1ec:  11 33 c0 58  sethi  %hi(0xcf016000), %o0
a011e1f0:  10 80 00 07  b  0xa011e20c
a011e1f4:  9a 12 21 98  or  %o0, 0x198, %o5	! 0xcf016198
a011e1f8:  17 33 c0 59  sethi  %hi(0xcf016400), %o3
a011e1fc:  10 80 00 04  b  0xa011e20c
a011e200:  9a 12 e0 94  or  %o3, 0x94, %o5	! 0xcf016494
a011e204:  19 33 c0 59  sethi  %hi(0xcf016400), %o4
a011e208:  9a 13 20 c0  or  %o4, 0xc0, %o5	! 0xcf0164c0
a011e20c:  d6 03 40 00  ld  [ %o5 ], %o3
a011e210:  82 0a e0 7c  and  %o3, 0x7c, %g1
a011e214:  c2 23 40 00  st  %g1, [ %o5 ]
a011e218:  81 c3 e0 08  retl
a011e21c:  01 00 00 00  nop
