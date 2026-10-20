# leon2m FUN_a01469e0 0xa01469e0-0xa0146a2c (76 bytes)
a01469e0:  9d e3 bf 98  save  %sp, -104, %sp
a01469e4:  82 0e 20 ff  and  %i0, 0xff, %g1
a01469e8:  b0 10 00 19  mov  %i1, %i0
a01469ec:  80 a0 60 07  cmp  %g1, 7
a01469f0:  18 80 00 0c  bgu  0xa0146a20
a01469f4:  b2 0e a0 ff  and  %i2, 0xff, %i1
a01469f8:  11 00 03 8c  sethi  %hi(0xe3000), %o0
a01469fc:  83 28 60 02  sll  %g1, 2, %g1
a0146a00:  9a 12 23 40  or  %o0, 0x340, %o5
a0146a04:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a0146a08:  81 c3 00 00  jmp  %o4
a0146a0c:  01 00 00 00  nop
a0146a10:  b2 0e a0 ff  and  %i2, 0xff, %i1
a0146a14:  90 10 20 07  mov  7, %o0
a0146a18:  67 fd 1f 33  call  0x4008e6e4
a0146a1c:  92 10 00 19  mov  %i1, %o1
a0146a20:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0146a24:  7f ff 4f 89  call  0xa011a848
a0146a28:  81 e8 00 00  restore
