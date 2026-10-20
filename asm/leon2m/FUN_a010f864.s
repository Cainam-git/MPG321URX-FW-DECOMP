# leon2m FUN_a010f864 0xa010f864-0xa010f8fc (152 bytes)
a010f864:  9d e3 bf 98  save  %sp, -104, %sp
a010f868:  33 3f fb ff  sethi  %hi(0xffeffc00), %i1
a010f86c:  37 3f f7 ff  sethi  %hi(0xffdffc00), %i3
a010f870:  9a 16 63 ff  or  %i1, 0x3ff, %o5
a010f874:  b2 16 e3 ff  or  %i3, 0x3ff, %i1
a010f878:  1f 34 00 c8  sethi  %hi(0xd0032000), %o7
a010f87c:  37 34 00 e8  sethi  %hi(0xd003a000), %i3
a010f880:  b0 0e 20 ff  and  %i0, 0xff, %i0
a010f884:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010f888:  b4 10 00 0f  mov  %o7, %i2
a010f88c:  b8 10 00 1b  mov  %i3, %i4
a010f890:  80 a6 20 01  cmp  %i0, 1
a010f894:  02 80 00 15  be  0xa010f8e8
a010f898:  ba 10 63 04  or  %g1, 0x304, %i5
a010f89c:  c2 0f 60 3e  ldub  [ %i5 + 0x3e ], %g1
a010f8a0:  82 08 7f fe  and  %g1, -2, %g1
a010f8a4:  80 a6 20 00  cmp  %i0, 0
a010f8a8:  12 80 00 09  bne  0xa010f8cc
a010f8ac:  c2 2f 60 3e  stb  %g1, [ %i5 + 0x3e ]
a010f8b0:  f8 03 c0 00  ld  [ %o7 ], %i4
a010f8b4:  b4 0f 00 0d  and  %i4, %o5, %i2
a010f8b8:  f4 23 c0 00  st  %i2, [ %o7 ]
a010f8bc:  f0 06 c0 00  ld  [ %i3 ], %i0
a010f8c0:  ba 0e 00 0d  and  %i0, %o5, %i5
a010f8c4:  fa 26 c0 00  st  %i5, [ %i3 ]
a010f8c8:  30 80 00 0b  b,a   0xa010f8f4
a010f8cc:  f0 06 80 00  ld  [ %i2 ], %i0
a010f8d0:  ba 0e 00 19  and  %i0, %i1, %i5
a010f8d4:  fa 26 80 00  st  %i5, [ %i2 ]
a010f8d8:  c2 07 00 00  ld  [ %i4 ], %g1
a010f8dc:  b6 08 40 19  and  %g1, %i1, %i3
a010f8e0:  f6 27 00 00  st  %i3, [ %i4 ]
a010f8e4:  30 80 00 04  b,a   0xa010f8f4
a010f8e8:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a010f8ec:  10 bf ff ec  b  0xa010f89c
a010f8f0:  ba 10 60 04  or  %g1, 4, %i5	! 0xa802d804
a010f8f4:  81 c7 e0 08  ret
a010f8f8:  81 e8 00 00  restore
