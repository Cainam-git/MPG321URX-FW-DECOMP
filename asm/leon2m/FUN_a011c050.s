# leon2m FUN_a011c050 0xa011c050-0xa011c1ac (348 bytes)
a011c050:  9d e3 bf 98  save  %sp, -104, %sp
a011c054:  3b 2a 00 b2  sethi  %hi(0xa802c800), %i5
a011c058:  9e 0f 20 ff  and  %i4, 0xff, %o7
a011c05c:  b8 03 c0 0f  add  %o7, %o7, %i4
a011c060:  82 17 61 ca  or  %i5, 0x1ca, %g1
a011c064:  fa 10 40 1c  lduh  [ %g1 + %i4 ], %i5
a011c068:  b4 5e 80 1d  smul  %i2, %i5, %i2
a011c06c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a011c070:  80 a6 20 01  cmp  %i0, 1
a011c074:  02 80 00 2d  be  0xa011c128
a011c078:  b2 06 40 1a  add  %i1, %i2, %i1
a011c07c:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011c080:  ba 10 20 40  mov  0x40, %i5
a011c084:  80 a3 e0 00  cmp  %o7, 0
a011c088:  12 80 00 24  bne  0xa011c118
a011c08c:  82 17 23 80  or  %i4, 0x380, %g1
a011c090:  fa 20 40 00  st  %i5, [ %g1 ]
a011c094:  82 10 20 9f  mov  0x9f, %g1
a011c098:  01 00 00 00  nop
a011c09c:  82 80 7f ff  addcc  %g1, -1, %g1
a011c0a0:  1c bf ff fe  bpos  0xa011c098
a011c0a4:  80 a3 e0 00  cmp  %o7, 0
a011c0a8:  b3 2e 60 10  sll  %i1, 0x10, %i1
a011c0ac:  12 80 00 2d  bne  0xa011c160
a011c0b0:  bb 36 60 10  srl  %i1, 0x10, %i5
a011c0b4:  35 33 c0 45  sethi  %hi(0xcf011400), %i2
a011c0b8:  82 0f 60 ff  and  %i5, 0xff, %g1
a011c0bc:  b8 16 a3 84  or  %i2, 0x384, %i4
a011c0c0:  c2 27 00 00  st  %g1, [ %i4 ]
a011c0c4:  b0 16 a3 88  or  %i2, 0x388, %i0
a011c0c8:  bb 36 60 18  srl  %i1, 0x18, %i5
a011c0cc:  fa 26 00 00  st  %i5, [ %i0 ]
a011c0d0:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a011c0d4:  b2 10 63 cc  or  %g1, 0x3cc, %i1	! 0xcf00bfcc
a011c0d8:  c0 26 40 00  clr  [ %i1 ]
a011c0dc:  82 10 20 9f  mov  0x9f, %g1
a011c0e0:  01 00 00 00  nop
a011c0e4:  82 80 7f ff  addcc  %g1, -1, %g1
a011c0e8:  1c bf ff fe  bpos  0xa011c0e0
a011c0ec:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011c0f0:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011c0f4:  80 a3 e0 00  cmp  %o7, 0
a011c0f8:  02 80 00 05  be  0xa011c10c
a011c0fc:  82 16 23 8c  or  %i0, 0x38c, %g1
a011c100:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011c104:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011c108:  82 16 e3 a0  or  %i3, 0x3a0, %g1	! 0xcf0117a0
a011c10c:  fa 20 40 00  st  %i5, [ %g1 ]
a011c110:  10 80 00 21  b  0xa011c194
a011c114:  82 10 20 9f  mov  0x9f, %g1
a011c118:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011c11c:  ba 10 20 40  mov  0x40, %i5
a011c120:  10 bf ff dc  b  0xa011c090
a011c124:  82 10 63 94  or  %g1, 0x394, %g1
a011c128:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011c12c:  ba 10 20 90  mov  0x90, %i5
a011c130:  80 a3 e0 00  cmp  %o7, 0
a011c134:  12 80 00 14  bne  0xa011c184
a011c138:  82 16 23 80  or  %i0, 0x380, %g1
a011c13c:  fa 20 40 00  st  %i5, [ %g1 ]
a011c140:  82 10 20 9f  mov  0x9f, %g1
a011c144:  01 00 00 00  nop
a011c148:  82 80 7f ff  addcc  %g1, -1, %g1
a011c14c:  1c bf ff fe  bpos  0xa011c144
a011c150:  80 a3 e0 00  cmp  %o7, 0
a011c154:  b3 2e 60 10  sll  %i1, 0x10, %i1
a011c158:  02 bf ff d7  be  0xa011c0b4
a011c15c:  bb 36 60 10  srl  %i1, 0x10, %i5
a011c160:  35 33 c0 45  sethi  %hi(0xcf011400), %i2
a011c164:  82 0f 60 ff  and  %i5, 0xff, %g1
a011c168:  b8 16 a3 98  or  %i2, 0x398, %i4
a011c16c:  c2 27 00 00  st  %g1, [ %i4 ]
a011c170:  b0 16 a3 9c  or  %i2, 0x39c, %i0
a011c174:  bb 36 60 18  srl  %i1, 0x18, %i5
a011c178:  fa 26 00 00  st  %i5, [ %i0 ]
a011c17c:  10 bf ff d6  b  0xa011c0d4
a011c180:  03 33 c0 30  sethi  %hi(0xcf00c000), %g1
a011c184:  35 33 c0 45  sethi  %hi(0xcf011400), %i2
a011c188:  ba 10 20 90  mov  0x90, %i5
a011c18c:  10 bf ff ec  b  0xa011c13c
a011c190:  82 16 a3 94  or  %i2, 0x394, %g1
a011c194:  01 00 00 00  nop
a011c198:  82 80 7f ff  addcc  %g1, -1, %g1
a011c19c:  1c bf ff fe  bpos  0xa011c194
a011c1a0:  01 00 00 00  nop
a011c1a4:  81 c7 e0 08  ret
a011c1a8:  81 e8 00 00  restore
