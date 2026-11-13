# leon2m FUN_a00f7894 0xa00f7894-0xa00f793c (168 bytes)
a00f7894:  c2 0a 20 02  ldub  [ %o0 + 2 ], %g1
a00f7898:  94 10 00 08  mov  %o0, %o2
a00f789c:  80 a0 60 08  cmp  %g1, 8
a00f78a0:  02 80 00 25  be  0xa00f7934
a00f78a4:  90 10 20 00  clr  %o0
a00f78a8:  80 a0 60 08  cmp  %g1, 8
a00f78ac:  14 80 00 1e  bg  0xa00f7924
a00f78b0:  80 a0 60 10  cmp  %g1, 0x10
a00f78b4:  17 33 c0 3b  sethi  %hi(0xcf00ec00), %o3
a00f78b8:  98 12 e2 80  or  %o3, 0x280, %o4	! 0xcf00ee80
a00f78bc:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f78c0:  c2 03 00 00  ld  [ %o4 ], %g1
a00f78c4:  d2 0b 63 b4  ldub  [ %o5 + 0x3b4 ], %o1
a00f78c8:  9a 02 40 09  add  %o1, %o1, %o5
a00f78cc:  82 08 60 f9  and  %g1, 0xf9, %g1
a00f78d0:  82 10 40 0d  or  %g1, %o5, %g1
a00f78d4:  c2 23 00 00  st  %g1, [ %o4 ]
a00f78d8:  96 12 e2 c0  or  %o3, 0x2c0, %o3
a00f78dc:  d8 0a 80 00  ldub  [ %o2 ], %o4
a00f78e0:  c2 02 c0 00  ld  [ %o3 ], %g1
a00f78e4:  9b 2b 20 07  sll  %o4, 7, %o5
a00f78e8:  82 08 60 3a  and  %g1, 0x3a, %g1
a00f78ec:  d8 0a a0 01  ldub  [ %o2 + 1 ], %o4
a00f78f0:  82 10 40 0d  or  %g1, %o5, %g1
a00f78f4:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00f78f8:  99 2b 20 06  sll  %o4, 6, %o4
a00f78fc:  90 10 40 0c  or  %g1, %o4, %o0
a00f7900:  9b 2b 60 02  sll  %o5, 2, %o5
a00f7904:  82 12 00 0d  or  %o0, %o5, %g1
a00f7908:  c2 22 c0 00  st  %g1, [ %o3 ]
a00f790c:  11 00 06 68  sethi  %hi(0x19a000), %o0
a00f7910:  90 12 23 c0  or  %o0, 0x3c0, %o0	! 0x19a3c0
a00f7914:  d4 0a a0 02  ldub  [ %o2 + 2 ], %o2
a00f7918:  82 13 c0 00  mov  %o7, %g1
a00f791c:  7f ff 9e 15  call  0xa00df170
a00f7920:  9e 10 40 00  mov  %g1, %o7
a00f7924:  22 bf ff e4  be,a   0xa00f78b4
a00f7928:  90 10 20 02  mov  2, %o0
a00f792c:  10 bf ff e3  b  0xa00f78b8
a00f7930:  17 33 c0 3b  sethi  %hi(0xcf00ec00), %o3
a00f7934:  10 bf ff e0  b  0xa00f78b4
a00f7938:  90 10 20 01  mov  1, %o0
