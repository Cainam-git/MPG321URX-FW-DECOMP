# leon2s FUN_a00a71fc 0xa00a71fc-0xa00a72c0 (196 bytes)
a00a71fc:  9d e3 bf 98  save  %sp, -104, %sp
a00a7200:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a7204:  80 a6 20 04  cmp  %i0, 4
a00a7208:  12 80 00 1b  bne  0xa00a7274
a00a720c:  80 a6 20 03  cmp  %i0, 3
a00a7210:  bb 2e 60 10  sll  %i1, 0x10, %i5
a00a7214:  b6 0e 80 1b  and  %i2, %i3, %i3
a00a7218:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a721c:  9a 10 61 88  or  %g1, 0x188, %o5	! 0xa00b4d88
a00a7220:  b3 37 60 10  srl  %i5, 0x10, %i1
a00a7224:  b0 10 20 00  clr  %i0
a00a7228:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a00a722c:  b4 38 00 1a  xnor  %g0, %i2, %i2
a00a7230:  82 0e 20 ff  and  %i0, 0xff, %g1
a00a7234:  82 00 40 01  add  %g1, %g1, %g1
a00a7238:  fa 13 40 01  lduh  [ %o5 + %g1 ], %i5
a00a723c:  ba 07 40 19  add  %i5, %i1, %i5
a00a7240:  bb 2f 60 02  sll  %i5, 2, %i5
a00a7244:  ba 17 40 0f  or  %i5, %o7, %i5
a00a7248:  c2 07 40 00  ld  [ %i5 ], %g1
a00a724c:  82 08 40 1a  and  %g1, %i2, %g1
a00a7250:  82 10 40 1b  or  %g1, %i3, %g1
a00a7254:  b0 06 20 01  inc  %i0
a00a7258:  82 08 60 ff  and  %g1, 0xff, %g1
a00a725c:  b8 0e 20 ff  and  %i0, 0xff, %i4
a00a7260:  c2 27 40 00  st  %g1, [ %i5 ]
a00a7264:  80 a7 20 03  cmp  %i4, 3
a00a7268:  08 bf ff f3  bleu  0xa00a7234
a00a726c:  82 0e 20 ff  and  %i0, 0xff, %g1
a00a7270:  30 80 00 12  b,a   0xa00a72b8
a00a7274:  18 80 00 11  bgu  0xa00a72b8
a00a7278:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a727c:  82 10 61 88  or  %g1, 0x188, %g1	! 0xa00b4d88
a00a7280:  ba 06 00 18  add  %i0, %i0, %i5
a00a7284:  b9 2e 60 10  sll  %i1, 0x10, %i4
a00a7288:  fa 10 40 1d  lduh  [ %g1 + %i5 ], %i5
a00a728c:  b9 37 20 10  srl  %i4, 0x10, %i4
a00a7290:  ba 07 40 1c  add  %i5, %i4, %i5
a00a7294:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00a7298:  bb 2f 60 02  sll  %i5, 2, %i5
a00a729c:  ba 17 40 01  or  %i5, %g1, %i5
a00a72a0:  c2 07 40 00  ld  [ %i5 ], %g1
a00a72a4:  b8 0e 80 1b  and  %i2, %i3, %i4
a00a72a8:  82 28 40 1a  andn  %g1, %i2, %g1
a00a72ac:  82 10 40 1c  or  %g1, %i4, %g1
a00a72b0:  82 08 60 ff  and  %g1, 0xff, %g1
a00a72b4:  c2 27 40 00  st  %g1, [ %i5 ]
a00a72b8:  81 c7 e0 08  ret
a00a72bc:  81 e8 00 00  restore
