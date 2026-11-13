# leon2m FUN_a011b3e8 0xa011b3e8-0xa011b428 (64 bytes)
a011b3e8:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011b3ec:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011b3f0:  80 8a 20 ff  btst  0xff, %o0
a011b3f4:  02 80 00 05  be  0xa011b408
a011b3f8:  82 10 63 8c  or  %g1, 0x38c, %g1
a011b3fc:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a011b400:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011b404:  82 12 23 a0  or  %o0, 0x3a0, %g1
a011b408:  da 20 40 00  st  %o5, [ %g1 ]
a011b40c:  82 10 20 9f  mov  0x9f, %g1
a011b410:  01 00 00 00  nop
a011b414:  82 80 7f ff  addcc  %g1, -1, %g1
a011b418:  1c bf ff fe  bpos  0xa011b410
a011b41c:  01 00 00 00  nop
a011b420:  81 c3 e0 08  retl
a011b424:  01 00 00 00  nop
