# leon2m FUN_a01255a0 0xa01255a0-0xa01255dc (60 bytes)
a01255a0:  19 2a 00 b6  sethi  %hi(0xa802d800), %o4
a01255a4:  9a 0a 20 ff  and  %o0, 0xff, %o5
a01255a8:  82 13 20 80  or  %o4, 0x80, %g1
a01255ac:  d8 08 40 0d  ldub  [ %g1 + %o5 ], %o4
a01255b0:  11 00 06 90  sethi  %hi(0x1a4000), %o0
a01255b4:  82 12 22 a8  or  %o0, 0x2a8, %g1	! 0x1a42a8
a01255b8:  9a 5b 20 16  smul  %o4, 0x16, %o5
a01255bc:  9a 03 40 01  add  %o5, %g1, %o5
a01255c0:  80 a3 20 ff  cmp  %o4, 0xff
a01255c4:  02 80 00 03  be  0xa01255d0
a01255c8:  90 10 3f ff  mov  -1, %o0
a01255cc:  d0 13 60 04  lduh  [ %o5 + 4 ], %o0
a01255d0:  91 2a 20 10  sll  %o0, 0x10, %o0
a01255d4:  81 c3 e0 08  retl
a01255d8:  91 32 20 10  srl  %o0, 0x10, %o0
