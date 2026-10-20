# leon2m FUN_a0146298 0xa0146298-0xa01462d0 (52 bytes)
a0146298:  90 0a 20 ff  and  %o0, 0xff, %o0
a014629c:  80 a2 20 04  cmp  %o0, 4
a01462a0:  18 80 00 08  bgu  0xa01462c0
a01462a4:  83 2a 20 02  sll  %o0, 2, %g1
a01462a8:  11 00 03 8c  sethi  %hi(0xe3000), %o0
a01462ac:  9a 12 22 c8  or  %o0, 0x2c8, %o5	! 0xe32c8
a01462b0:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a01462b4:  81 c3 00 00  jmp  %o4
a01462b8:  01 00 00 00  nop
a01462bc:  90 10 20 03  mov  3, %o0	! 0x3
a01462c0:  92 0a 60 ff  and  %o1, 0xff, %o1
a01462c4:  82 13 c0 00  mov  %o7, %g1
a01462c8:  7f ff 4c f4  call  0xa0119698
a01462cc:  9e 10 40 00  mov  %g1, %o7
