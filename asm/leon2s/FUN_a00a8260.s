# leon2s FUN_a00a8260 0xa00a8260-0xa00a82e4 (132 bytes)
a00a8260:  9d e3 bf 98  save  %sp, -104, %sp
a00a8264:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a8268:  9a 10 61 40  or  %g1, 0x140, %o5	! 0xa00b4d40
a00a826c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a8270:  83 2e 60 10  sll  %i1, 0x10, %g1
a00a8274:  b8 06 00 18  add  %i0, %i0, %i4
a00a8278:  80 a6 20 01  cmp  %i0, 1
a00a827c:  b3 2e 60 10  sll  %i1, 0x10, %i1
a00a8280:  98 10 00 0d  mov  %o5, %o4
a00a8284:  9e 10 00 1c  mov  %i4, %o7
a00a8288:  bb 30 60 10  srl  %g1, 0x10, %i5
a00a828c:  b6 0e e0 ff  and  %i3, 0xff, %i3
a00a8290:  18 80 00 13  bgu  0xa00a82dc
a00a8294:  b1 36 60 10  srl  %i1, 0x10, %i0
a00a8298:  c2 13 40 1c  lduh  [ %o5 + %i4 ], %g1
a00a829c:  82 00 40 1d  add  %g1, %i5, %g1
a00a82a0:  83 28 60 02  sll  %g1, 2, %g1
a00a82a4:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a82a8:  82 10 40 1d  or  %g1, %i5, %g1
a00a82ac:  c2 00 40 00  ld  [ %g1 ], %g1
a00a82b0:  80 a6 e0 01  cmp  %i3, 1
a00a82b4:  02 80 00 03  be  0xa00a82c0
a00a82b8:  b8 10 40 1a  or  %g1, %i2, %i4
a00a82bc:  b8 28 40 1a  andn  %g1, %i2, %i4
a00a82c0:  c2 13 00 0f  lduh  [ %o4 + %o7 ], %g1
a00a82c4:  82 00 40 18  add  %g1, %i0, %g1
a00a82c8:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a82cc:  83 28 60 02  sll  %g1, 2, %g1
a00a82d0:  82 10 40 1d  or  %g1, %i5, %g1
a00a82d4:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00a82d8:  fa 20 40 00  st  %i5, [ %g1 ]
a00a82dc:  81 c7 e0 08  ret
a00a82e0:  81 e8 00 00  restore
