# leon2s FUN_a00d36a4 0xa00d36a4-0xa00d36e4 (64 bytes)
a00d36a4:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d36a8:  c2 08 60 38  ldub  [ %g1 + 0x38 ], %g1	! 0xa8078c38
a00d36ac:  80 a0 60 01  cmp  %g1, 1
a00d36b0:  08 80 00 0a  bleu  0xa00d36d8
a00d36b4:  19 2a 01 e3  sethi  %hi(0xa8078c00), %o4
a00d36b8:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d36bc:  da 08 60 37  ldub  [ %g1 + 0x37 ], %o5	! 0xa8078c37
a00d36c0:  82 10 20 01  mov  1, %g1
a00d36c4:  83 28 40 0d  sll  %g1, %o5, %g1
a00d36c8:  da 0b 20 35  ldub  [ %o4 + 0x35 ], %o5
a00d36cc:  82 10 40 0d  or  %g1, %o5, %g1
a00d36d0:  10 80 00 03  b  0xa00d36dc
a00d36d4:  c2 2b 20 35  stb  %g1, [ %o4 + 0x35 ]
a00d36d8:  c0 2b 20 35  clrb  [ %o4 + 0x35 ]
a00d36dc:  81 c3 e0 08  retl
a00d36e0:  01 00 00 00  nop
