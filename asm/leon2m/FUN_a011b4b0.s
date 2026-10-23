# leon2m FUN_a011b4b0 0xa011b4b0-0xa011b4f0 (64 bytes)
a011b4b0:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011b4b4:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011b4b8:  80 8a 20 ff  btst  0xff, %o0
a011b4bc:  02 80 00 05  be  0xa011b4d0
a011b4c0:  82 10 63 80  or  %g1, 0x380, %g1
a011b4c4:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a011b4c8:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011b4cc:  82 12 23 94  or  %o0, 0x394, %g1
a011b4d0:  da 20 40 00  st  %o5, [ %g1 ]
a011b4d4:  82 10 20 9f  mov  0x9f, %g1
a011b4d8:  01 00 00 00  nop
a011b4dc:  82 80 7f ff  addcc  %g1, -1, %g1
a011b4e0:  1c bf ff fe  bpos  0xa011b4d8
a011b4e4:  01 00 00 00  nop
a011b4e8:  81 c3 e0 08  retl
a011b4ec:  01 00 00 00  nop
