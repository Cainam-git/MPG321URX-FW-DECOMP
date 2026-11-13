# leon2m FUN_a011a060 0xa011a060-0xa011a1b0 (336 bytes)
a011a060:  9d e3 bf 98  save  %sp, -104, %sp
a011a064:  94 0e a0 ff  and  %i2, 0xff, %o2
a011a068:  80 a2 a0 02  cmp  %o2, 2
a011a06c:  b6 60 20 00  subx  %g0, 0, %i3
a011a070:  9a 0a a0 ff  and  %o2, 0xff, %o5
a011a074:  80 a3 60 02  cmp  %o5, 2
a011a078:  ba 0e 80 1b  and  %i2, %i3, %i5
a011a07c:  92 10 00 1a  mov  %i2, %o1
a011a080:  b8 40 20 00  addx  %g0, 0, %i4
a011a084:  b4 0f 60 ff  and  %i5, 0xff, %i2
a011a088:  ba 06 80 1a  add  %i2, %i2, %i5
a011a08c:  b6 20 00 1c  neg  %i4, %i3
a011a090:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a011a094:  90 10 62 a8  or  %g1, 0x2a8, %o0	! 0xa8027aa8
a011a098:  b4 0b 40 1b  and  %o5, %i3, %i2
a011a09c:  f6 12 00 1d  lduh  [ %o0 + %i5 ], %i3
a011a0a0:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a011a0a4:  9a 06 80 1a  add  %i2, %i2, %o5
a011a0a8:  ba 10 61 ca  or  %g1, 0x1ca, %i5
a011a0ac:  b8 02 80 0a  add  %o2, %o2, %i4
a011a0b0:  98 06 e0 81  add  %i3, 0x81, %o4
a011a0b4:  f4 17 40 1c  lduh  [ %i5 + %i4 ], %i2
a011a0b8:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a011a0bc:  f8 12 00 0d  lduh  [ %o0 + %o5 ], %i4
a011a0c0:  83 2b 20 02  sll  %o4, 2, %g1
a011a0c4:  9e 10 00 0d  mov  %o5, %o7
a011a0c8:  ba 06 e0 82  add  %i3, 0x82, %i5
a011a0cc:  98 10 40 0b  or  %g1, %o3, %o4
a011a0d0:  9b 2e 20 10  sll  %i0, 0x10, %o5
a011a0d4:  b7 2f 60 02  sll  %i5, 2, %i3
a011a0d8:  82 07 20 83  add  %i4, 0x83, %g1
a011a0dc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a011a0e0:  f0 23 00 00  st  %i0, [ %o4 ]
a011a0e4:  b4 06 bf ff  add  %i2, -1, %i2
a011a0e8:  b6 16 c0 0b  or  %i3, %o3, %i3
a011a0ec:  b9 28 60 02  sll  %g1, 2, %i4
a011a0f0:  fa 12 00 0f  lduh  [ %o0 + %o7 ], %i5
a011a0f4:  9b 33 60 18  srl  %o5, 0x18, %o5
a011a0f8:  da 26 c0 00  st  %o5, [ %i3 ]
a011a0fc:  b0 0e a0 ff  and  %i2, 0xff, %i0
a011a100:  ba 07 60 d3  add  %i5, 0xd3, %i5
a011a104:  b8 17 00 0b  or  %i4, %o3, %i4
a011a108:  83 2e 60 10  sll  %i1, 0x10, %g1
a011a10c:  f0 27 00 00  st  %i0, [ %i4 ]
a011a110:  b7 36 a0 08  srl  %i2, 8, %i3
a011a114:  bb 2f 60 02  sll  %i5, 2, %i5
a011a118:  b1 30 60 18  srl  %g1, 0x18, %i0
a011a11c:  ba 17 40 0b  or  %i5, %o3, %i5
a011a120:  b4 0e e0 ff  and  %i3, 0xff, %i2
a011a124:  f4 27 40 00  st  %i2, [ %i5 ]
a011a128:  80 a2 a0 01  cmp  %o2, 1
a011a12c:  82 10 00 09  mov  %o1, %g1
a011a130:  08 80 00 03  bleu  0xa011a13c
a011a134:  b2 0e 60 ff  and  %i1, 0xff, %i1
a011a138:  82 10 20 00  clr  %g1
a011a13c:  ba 08 60 ff  and  %g1, 0xff, %i5
a011a140:  b4 07 40 1d  add  %i5, %i5, %i2
a011a144:  f8 12 00 1a  lduh  [ %o0 + %i2 ], %i4
a011a148:  82 07 20 84  add  %i4, 0x84, %g1
a011a14c:  bb 28 60 02  sll  %g1, 2, %i5
a011a150:  82 17 40 0b  or  %i5, %o3, %g1
a011a154:  b8 07 20 85  add  %i4, 0x85, %i4
a011a158:  80 a2 a0 02  cmp  %o2, 2
a011a15c:  b6 60 20 00  subx  %g0, 0, %i3
a011a160:  bb 2f 20 02  sll  %i4, 2, %i5
a011a164:  f2 20 40 00  st  %i1, [ %g1 ]
a011a168:  b8 17 40 0b  or  %i5, %o3, %i4
a011a16c:  b4 0a 40 1b  and  %o1, %i3, %i2
a011a170:  f0 27 00 00  st  %i0, [ %i4 ]
a011a174:  b6 0e a0 ff  and  %i2, 0xff, %i3
a011a178:  b4 06 c0 1b  add  %i3, %i3, %i2
a011a17c:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a011a180:  b2 16 21 c8  or  %i0, 0x1c8, %i1	! 0xa802c9c8
a011a184:  fa 12 00 1a  lduh  [ %o0 + %i2 ], %i5
a011a188:  f6 0e 40 0a  ldub  [ %i1 + %o2 ], %i3
a011a18c:  82 07 60 86  add  %i5, 0x86, %g1
a011a190:  b8 06 ff ff  add  %i3, -1, %i4
a011a194:  b5 28 60 02  sll  %g1, 2, %i2
a011a198:  b2 16 80 0b  or  %i2, %o3, %i1
a011a19c:  b0 0f 20 ff  and  %i4, 0xff, %i0
a011a1a0:  f0 26 40 00  st  %i0, [ %i1 ]
a011a1a4:  67 fd d0 40  call  0x4008e2a4
a011a1a8:  81 e8 00 00  restore
a011a1ac:  01 00 00 00  nop
