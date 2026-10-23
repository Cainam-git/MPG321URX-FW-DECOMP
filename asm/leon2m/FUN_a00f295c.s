# leon2m FUN_a00f295c 0xa00f295c-0xa00f29d4 (120 bytes)
a00f295c:  94 0a 20 ff  and  %o0, 0xff, %o2
a00f2960:  80 a2 a0 08  cmp  %o2, 8
a00f2964:  98 40 20 00  addx  %g0, 0, %o4
a00f2968:  82 20 00 0c  neg  %o4, %g1
a00f296c:  96 0a 80 01  and  %o2, %g1, %o3
a00f2970:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f2974:  98 13 62 ec  or  %o5, 0x2ec, %o4	! 0x19a2ec
a00f2978:  90 02 c0 0b  add  %o3, %o3, %o0
a00f297c:  d6 13 00 08  lduh  [ %o4 + %o0 ], %o3
a00f2980:  94 0a 60 ff  and  %o1, 0xff, %o2
a00f2984:  96 02 c0 0a  add  %o3, %o2, %o3
a00f2988:  92 02 e0 02  add  %o3, 2, %o1
a00f298c:  83 2a 60 02  sll  %o1, 2, %g1
a00f2990:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a00f2994:  9a 02 e0 01  add  %o3, 1, %o5
a00f2998:  98 10 40 09  or  %g1, %o1, %o4
a00f299c:  91 2b 60 02  sll  %o5, 2, %o0
a00f29a0:  da 03 00 00  ld  [ %o4 ], %o5
a00f29a4:  94 12 00 09  or  %o0, %o1, %o2
a00f29a8:  d0 02 80 00  ld  [ %o2 ], %o0
a00f29ac:  83 2a e0 02  sll  %o3, 2, %g1
a00f29b0:  96 10 40 09  or  %g1, %o1, %o3
a00f29b4:  95 2b 60 08  sll  %o5, 8, %o2
a00f29b8:  98 0a 20 ff  and  %o0, 0xff, %o4
a00f29bc:  92 12 80 0c  or  %o2, %o4, %o1
a00f29c0:  c2 02 c0 00  ld  [ %o3 ], %g1
a00f29c4:  9b 2a 60 08  sll  %o1, 8, %o5
a00f29c8:  90 08 60 ff  and  %g1, 0xff, %o0
a00f29cc:  81 c3 e0 08  retl
a00f29d0:  90 13 40 08  or  %o5, %o0, %o0
