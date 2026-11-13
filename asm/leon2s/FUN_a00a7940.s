# leon2s FUN_a00a7940 0xa00a7940-0xa00a79c4 (132 bytes)
a00a7940:  9d e3 bf 98  save  %sp, -104, %sp
a00a7944:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7948:  9a 10 61 7a  or  %g1, 0x17a, %o5	! 0xa00b4d7a
a00a794c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a7950:  83 2e 60 10  sll  %i1, 0x10, %g1
a00a7954:  b8 06 00 18  add  %i0, %i0, %i4
a00a7958:  80 a6 20 04  cmp  %i0, 4
a00a795c:  b3 2e 60 10  sll  %i1, 0x10, %i1
a00a7960:  98 10 00 0d  mov  %o5, %o4
a00a7964:  9e 10 00 1c  mov  %i4, %o7
a00a7968:  bb 30 60 10  srl  %g1, 0x10, %i5
a00a796c:  b6 0e e0 ff  and  %i3, 0xff, %i3
a00a7970:  18 80 00 13  bgu  0xa00a79bc
a00a7974:  b1 36 60 10  srl  %i1, 0x10, %i0
a00a7978:  c2 13 40 1c  lduh  [ %o5 + %i4 ], %g1
a00a797c:  82 00 40 1d  add  %g1, %i5, %g1
a00a7980:  83 28 60 02  sll  %g1, 2, %g1
a00a7984:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a7988:  82 10 40 1d  or  %g1, %i5, %g1
a00a798c:  c2 00 40 00  ld  [ %g1 ], %g1
a00a7990:  80 a6 e0 01  cmp  %i3, 1
a00a7994:  02 80 00 03  be  0xa00a79a0
a00a7998:  b8 10 40 1a  or  %g1, %i2, %i4
a00a799c:  b8 28 40 1a  andn  %g1, %i2, %i4
a00a79a0:  c2 13 00 0f  lduh  [ %o4 + %o7 ], %g1
a00a79a4:  82 00 40 18  add  %g1, %i0, %g1
a00a79a8:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a79ac:  83 28 60 02  sll  %g1, 2, %g1
a00a79b0:  82 10 40 1d  or  %g1, %i5, %g1
a00a79b4:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00a79b8:  fa 20 40 00  st  %i5, [ %g1 ]
a00a79bc:  81 c7 e0 08  ret
a00a79c0:  81 e8 00 00  restore
