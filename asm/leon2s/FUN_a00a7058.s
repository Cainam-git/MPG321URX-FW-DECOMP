# leon2s FUN_a00a7058 0xa00a7058-0xa00a7168 (272 bytes)
a00a7058:  9d e3 bf 98  save  %sp, -104, %sp
a00a705c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a7060:  80 a6 20 02  cmp  %i0, 2
a00a7064:  9a 10 00 19  mov  %i1, %o5
a00a7068:  18 80 00 3e  bgu  0xa00a7160
a00a706c:  98 10 00 1a  mov  %i2, %o4
a00a7070:  80 a6 20 02  cmp  %i0, 2
a00a7074:  12 80 00 21  bne  0xa00a70f8
a00a7078:  1f 28 02 d3  sethi  %hi(0xa00b4c00), %o7
a00a707c:  bb 2e 60 10  sll  %i1, 0x10, %i5
a00a7080:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7084:  96 10 61 90  or  %g1, 0x190, %o3	! 0xa00b4d90
a00a7088:  b3 37 60 10  srl  %i5, 0x10, %i1
a00a708c:  9e 0e e0 ff  and  %i3, 0xff, %o7
a00a7090:  b4 38 00 1a  xnor  %g0, %i2, %i2
a00a7094:  b8 10 20 00  clr  %i4
a00a7098:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a709c:  82 0f 20 ff  and  %i4, 0xff, %g1
a00a70a0:  ba 00 40 01  add  %g1, %g1, %i5
a00a70a4:  c2 12 c0 1d  lduh  [ %o3 + %i5 ], %g1
a00a70a8:  82 00 40 19  add  %g1, %i1, %g1
a00a70ac:  83 28 60 02  sll  %g1, 2, %g1
a00a70b0:  82 10 40 0d  or  %g1, %o5, %g1
a00a70b4:  b8 07 20 01  inc  %i4
a00a70b8:  c2 00 40 00  ld  [ %g1 ], %g1
a00a70bc:  b0 0f 20 ff  and  %i4, 0xff, %i0
a00a70c0:  80 a3 e0 01  cmp  %o7, 1
a00a70c4:  02 80 00 03  be  0xa00a70d0
a00a70c8:  b6 10 40 0c  or  %g1, %o4, %i3
a00a70cc:  b6 08 40 1a  and  %g1, %i2, %i3
a00a70d0:  c2 12 c0 1d  lduh  [ %o3 + %i5 ], %g1
a00a70d4:  82 00 40 19  add  %g1, %i1, %g1
a00a70d8:  83 28 60 02  sll  %g1, 2, %g1
a00a70dc:  82 10 40 0d  or  %g1, %o5, %g1
a00a70e0:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00a70e4:  fa 20 40 00  st  %i5, [ %g1 ]
a00a70e8:  80 a6 20 01  cmp  %i0, 1
a00a70ec:  08 bf ff ed  bleu  0xa00a70a0
a00a70f0:  82 0f 20 ff  and  %i4, 0xff, %g1
a00a70f4:  30 80 00 1b  b,a   0xa00a7160
a00a70f8:  bb 2e 60 10  sll  %i1, 0x10, %i5
a00a70fc:  b8 13 e1 90  or  %o7, 0x190, %i4
a00a7100:  82 06 00 18  add  %i0, %i0, %g1
a00a7104:  bb 37 60 10  srl  %i5, 0x10, %i5
a00a7108:  c2 17 00 01  lduh  [ %i4 + %g1 ], %g1
a00a710c:  82 00 40 1d  add  %g1, %i5, %g1
a00a7110:  83 28 60 02  sll  %g1, 2, %g1
a00a7114:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a7118:  82 10 40 1d  or  %g1, %i5, %g1
a00a711c:  f2 00 40 00  ld  [ %g1 ], %i1
a00a7120:  82 0e e0 ff  and  %i3, 0xff, %g1
a00a7124:  80 a0 60 01  cmp  %g1, 1
a00a7128:  02 80 00 04  be  0xa00a7138
a00a712c:  b6 16 40 1a  or  %i1, %i2, %i3
a00a7130:  b6 2e 40 1a  andn  %i1, %i2, %i3
a00a7134:  b8 13 e1 90  or  %o7, 0x190, %i4
a00a7138:  82 06 00 18  add  %i0, %i0, %g1
a00a713c:  bb 2b 60 10  sll  %o5, 0x10, %i5
a00a7140:  bb 37 60 10  srl  %i5, 0x10, %i5
a00a7144:  c2 17 00 01  lduh  [ %i4 + %g1 ], %g1
a00a7148:  82 00 40 1d  add  %g1, %i5, %g1
a00a714c:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a7150:  83 28 60 02  sll  %g1, 2, %g1
a00a7154:  82 10 40 1d  or  %g1, %i5, %g1
a00a7158:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00a715c:  fa 20 40 00  st  %i5, [ %g1 ]
a00a7160:  81 c7 e0 08  ret
a00a7164:  81 e8 00 00  restore
