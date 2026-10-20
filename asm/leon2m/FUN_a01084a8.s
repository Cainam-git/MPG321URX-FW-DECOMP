# leon2m FUN_a01084a8 0xa01084a8-0xa0108544 (156 bytes)
a01084a8:  9d e3 bf 98  save  %sp, -104, %sp
a01084ac:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01084b0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a01084b4:  11 00 06 6a  sethi  %hi(0x19a800), %o0
a01084b8:  92 10 00 18  mov  %i0, %o1
a01084bc:  94 10 00 19  mov  %i1, %o2
a01084c0:  7f ff 5b 2c  call  0xa00df170
a01084c4:  90 12 23 e8  or  %o0, 0x3e8, %o0
a01084c8:  9a 10 20 01  mov  1, %o5
a01084cc:  15 33 c0 46  sethi  %hi(0xcf011800), %o2
a01084d0:  97 2b 40 18  sll  %o5, %i0, %o3
a01084d4:  9a 12 a3 f8  or  %o2, 0x3f8, %o5
a01084d8:  92 10 00 0a  mov  %o2, %o1
a01084dc:  98 38 00 0b  xnor  %g0, %o3, %o4
a01084e0:  9e 12 a2 00  or  %o2, 0x200, %o7
a01084e4:  80 a6 60 00  cmp  %i1, 0
a01084e8:  02 80 00 0c  be  0xa0108518
a01084ec:  b0 10 00 0d  mov  %o5, %i0
a01084f0:  da 02 80 00  ld  [ %o2 ], %o5
a01084f4:  82 13 40 0b  or  %o5, %o3, %g1
a01084f8:  c2 22 80 00  st  %g1, [ %o2 ]
a01084fc:  f2 03 c0 00  ld  [ %o7 ], %i1
a0108500:  98 16 40 0b  or  %i1, %o3, %o4
a0108504:  d8 23 c0 00  st  %o4, [ %o7 ]
a0108508:  d4 06 00 00  ld  [ %i0 ], %o2
a010850c:  92 12 80 0b  or  %o2, %o3, %o1
a0108510:  d2 26 00 00  st  %o1, [ %i0 ]
a0108514:  30 80 00 0a  b,a   0xa010853c
a0108518:  c2 03 40 00  ld  [ %o5 ], %g1
a010851c:  b2 08 40 0c  and  %g1, %o4, %i1
a0108520:  f2 23 40 00  st  %i1, [ %o5 ]
a0108524:  d4 03 c0 00  ld  [ %o7 ], %o2
a0108528:  b0 0a 80 0c  and  %o2, %o4, %i0
a010852c:  f0 23 c0 00  st  %i0, [ %o7 ]
a0108530:  de 02 40 00  ld  [ %o1 ], %o7
a0108534:  96 0b c0 0c  and  %o7, %o4, %o3
a0108538:  d6 22 40 00  st  %o3, [ %o1 ]
a010853c:  81 c7 e0 08  ret
a0108540:  81 e8 00 00  restore
