# leon2m FUN_a013b4a4 0xa013b4a4-0xa013b4cc (40 bytes)
a013b4a4:  1b 2a 00 a9  sethi  %hi(0xa802a400), %o5
a013b4a8:  82 13 60 6c  or  %o5, 0x6c, %g1	! 0xa802a46c
a013b4ac:  d0 33 60 6c  sth  %o0, [ %o5 + 0x6c ]
a013b4b0:  1b 2a 00 a9  sethi  %hi(0xa802a400), %o5
a013b4b4:  d4 30 60 04  sth  %o2, [ %g1 + 4 ]
a013b4b8:  d2 30 60 02  sth  %o1, [ %g1 + 2 ]
a013b4bc:  d0 0b 60 60  ldub  [ %o5 + 0x60 ], %o0
a013b4c0:  82 13 c0 00  mov  %o7, %g1
a013b4c4:  7f ff fe 4f  call  0xa013ae00
a013b4c8:  9e 10 40 00  mov  %g1, %o7
