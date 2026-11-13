# leon2m FUN_a011e028 0xa011e028-0xa011e148 (188 bytes)
a011e028:  92 0a 60 ff  and  %o1, 0xff, %o1
a011e02c:  80 a2 60 00  cmp  %o1, 0
a011e030:  32 80 00 02  bne,a   0xa011e038
a011e034:  92 10 20 80  mov  0x80, %o1
a011e038:  82 0a 20 ff  and  %o0, 0xff, %g1
a011e03c:  80 a0 60 1f  cmp  %g1, 0x1f
a011e040:  18 80 00 09  bgu  0xa011e064
a011e044:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a011e048:  11 00 02 f4  sethi  %hi(0xbd000), %o0
a011e04c:  83 28 60 02  sll  %g1, 2, %g1
a011e050:  9a 12 23 f0  or  %o0, 0x3f0, %o5
a011e054:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a011e058:  81 c3 00 00  jmp  %o4
a011e05c:  01 00 00 00  nop
a011e060:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a011e064:  90 13 61 20  or  %o5, 0x120, %o0	! 0xcf016120
a011e068:  d8 02 00 00  ld  [ %o0 ], %o4
a011e06c:  96 0b 20 7f  and  %o4, 0x7f, %o3
a011e070:  82 12 c0 09  or  %o3, %o1, %g1
a011e074:  c2 22 00 00  st  %g1, [ %o0 ]
a011e078:  90 13 61 38  or  %o5, 0x138, %o0
a011e07c:  d8 02 00 00  ld  [ %o0 ], %o4
a011e080:  96 0b 20 7f  and  %o4, 0x7f, %o3
a011e084:  82 12 c0 09  or  %o3, %o1, %g1
a011e088:  c2 22 00 00  st  %g1, [ %o0 ]
a011e08c:  90 13 61 50  or  %o5, 0x150, %o0
a011e090:  d8 02 00 00  ld  [ %o0 ], %o4
a011e094:  96 0b 20 7f  and  %o4, 0x7f, %o3
a011e098:  82 12 c0 09  or  %o3, %o1, %g1
a011e09c:  c2 22 00 00  st  %g1, [ %o0 ]
a011e0a0:  90 13 61 68  or  %o5, 0x168, %o0
a011e0a4:  d8 02 00 00  ld  [ %o0 ], %o4
a011e0a8:  96 0b 20 7f  and  %o4, 0x7f, %o3
a011e0ac:  82 12 c0 09  or  %o3, %o1, %g1
a011e0b0:  c2 22 00 00  st  %g1, [ %o0 ]
a011e0b4:  90 13 61 80  or  %o5, 0x180, %o0
a011e0b8:  d8 02 00 00  ld  [ %o0 ], %o4
a011e0bc:  96 0b 20 7f  and  %o4, 0x7f, %o3
a011e0c0:  82 12 c0 09  or  %o3, %o1, %g1
a011e0c4:  c2 22 00 00  st  %g1, [ %o0 ]
a011e0c8:  10 80 00 1a  b  0xa011e130
a011e0cc:  9a 13 61 98  or  %o5, 0x198, %o5
a011e0d0:  10 80 00 18  b  0xa011e130
a011e0d4:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011e0d8:  17 33 c0 58  sethi  %hi(0xcf016000), %o3
a011e0dc:  10 80 00 15  b  0xa011e130
a011e0e0:  9a 12 e1 20  or  %o3, 0x120, %o5	! 0xcf016120
a011e0e4:  19 33 c0 58  sethi  %hi(0xcf016000), %o4
a011e0e8:  10 80 00 12  b  0xa011e130
a011e0ec:  9a 13 21 38  or  %o4, 0x138, %o5	! 0xcf016138
a011e0f0:  03 33 c0 58  sethi  %hi(0xcf016000), %g1
a011e0f4:  10 80 00 0f  b  0xa011e130
a011e0f8:  9a 10 61 50  or  %g1, 0x150, %o5	! 0xcf016150
a011e0fc:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a011e100:  10 80 00 0c  b  0xa011e130
a011e104:  9a 13 61 68  or  %o5, 0x168, %o5	! 0xcf016168
a011e108:  11 33 c0 58  sethi  %hi(0xcf016000), %o0
a011e10c:  10 80 00 09  b  0xa011e130
a011e110:  9a 12 21 80  or  %o0, 0x180, %o5	! 0xcf016180
a011e114:  10 bf ff ed  b  0xa011e0c8
a011e118:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a011e11c:  17 33 c0 59  sethi  %hi(0xcf016400), %o3
a011e120:  10 80 00 04  b  0xa011e130
a011e124:  9a 12 e0 94  or  %o3, 0x94, %o5	! 0xcf016494
a011e128:  19 33 c0 59  sethi  %hi(0xcf016400), %o4
a011e12c:  9a 13 20 c0  or  %o4, 0xc0, %o5	! 0xcf0164c0
a011e130:  d6 03 40 00  ld  [ %o5 ], %o3
a011e134:  82 0a e0 7f  and  %o3, 0x7f, %g1
a011e138:  90 10 40 09  or  %g1, %o1, %o0
a011e13c:  d0 23 40 00  st  %o0, [ %o5 ]
a011e140:  81 c3 e0 08  retl
a011e144:  01 00 00 00  nop
