# leon2m FUN_a00dd904 0xa00dd904-0xa00dda4c (328 bytes)
a00dd904:  1b 33 c0 f3  sethi  %hi(0xcf03cc00), %o5
a00dd908:  94 13 63 00  or  %o5, 0x300, %o2	! 0xcf03cf00
a00dd90c:  c0 22 80 00  clr  [ %o2 ]
a00dd910:  96 13 63 04  or  %o5, 0x304, %o3
a00dd914:  94 10 20 1b  mov  0x1b, %o2
a00dd918:  98 13 63 08  or  %o5, 0x308, %o4
a00dd91c:  d4 22 c0 00  st  %o2, [ %o3 ]
a00dd920:  82 10 20 80  mov  0x80, %g1
a00dd924:  c2 23 00 00  st  %g1, [ %o4 ]
a00dd928:  9a 13 63 0c  or  %o5, 0x30c, %o5
a00dd92c:  98 0a 20 ff  and  %o0, 0xff, %o4
a00dd930:  82 10 20 01  mov  1, %g1
a00dd934:  c2 23 40 00  st  %g1, [ %o5 ]
a00dd938:  80 8b 20 01  btst  1, %o4
a00dd93c:  02 80 00 08  be  0xa00dd95c
a00dd940:  80 8b 20 02  btst  2, %o4
a00dd944:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a00dd948:  9a 13 60 2c  or  %o5, 0x2c, %o5	! 0xcf03c02c
a00dd94c:  c2 03 40 00  ld  [ %o5 ], %g1
a00dd950:  82 10 60 01  or  %g1, 1, %g1
a00dd954:  c2 23 40 00  st  %g1, [ %o5 ]
a00dd958:  80 8b 20 02  btst  2, %o4
a00dd95c:  02 80 00 08  be  0xa00dd97c
a00dd960:  80 8b 20 04  btst  4, %o4
a00dd964:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a00dd968:  9a 13 60 2c  or  %o5, 0x2c, %o5	! 0xcf03c02c
a00dd96c:  c2 03 40 00  ld  [ %o5 ], %g1
a00dd970:  82 10 60 02  or  %g1, 2, %g1
a00dd974:  c2 23 40 00  st  %g1, [ %o5 ]
a00dd978:  80 8b 20 04  btst  4, %o4
a00dd97c:  02 80 00 08  be  0xa00dd99c
a00dd980:  80 8b 20 08  btst  8, %o4
a00dd984:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a00dd988:  9a 13 60 2c  or  %o5, 0x2c, %o5	! 0xcf03c02c
a00dd98c:  c2 03 40 00  ld  [ %o5 ], %g1
a00dd990:  82 10 60 04  or  %g1, 4, %g1
a00dd994:  c2 23 40 00  st  %g1, [ %o5 ]
a00dd998:  80 8b 20 08  btst  8, %o4
a00dd99c:  02 80 00 08  be  0xa00dd9bc
a00dd9a0:  80 8b 20 10  btst  0x10, %o4
a00dd9a4:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a00dd9a8:  9a 13 60 2c  or  %o5, 0x2c, %o5	! 0xcf03c02c
a00dd9ac:  c2 03 40 00  ld  [ %o5 ], %g1
a00dd9b0:  82 10 60 08  or  %g1, 8, %g1
a00dd9b4:  c2 23 40 00  st  %g1, [ %o5 ]
a00dd9b8:  80 8b 20 10  btst  0x10, %o4
a00dd9bc:  02 80 00 08  be  0xa00dd9dc
a00dd9c0:  80 8b 20 20  btst  0x20, %o4
a00dd9c4:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a00dd9c8:  9a 13 62 00  or  %o5, 0x200, %o5	! 0xcf03c200
a00dd9cc:  c2 03 40 00  ld  [ %o5 ], %g1
a00dd9d0:  82 10 60 01  or  %g1, 1, %g1
a00dd9d4:  c2 23 40 00  st  %g1, [ %o5 ]
a00dd9d8:  80 8b 20 20  btst  0x20, %o4
a00dd9dc:  02 80 00 08  be  0xa00dd9fc
a00dd9e0:  80 8b 20 40  btst  0x40, %o4
a00dd9e4:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a00dd9e8:  9a 13 62 00  or  %o5, 0x200, %o5	! 0xcf03c200
a00dd9ec:  c2 03 40 00  ld  [ %o5 ], %g1
a00dd9f0:  82 10 60 02  or  %g1, 2, %g1
a00dd9f4:  c2 23 40 00  st  %g1, [ %o5 ]
a00dd9f8:  80 8b 20 40  btst  0x40, %o4
a00dd9fc:  02 80 00 08  be  0xa00dda1c
a00dda00:  80 8a 20 80  btst  0x80, %o0
a00dda04:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a00dda08:  98 13 62 00  or  %o5, 0x200, %o4	! 0xcf03c200
a00dda0c:  c2 03 00 00  ld  [ %o4 ], %g1
a00dda10:  82 10 60 04  or  %g1, 4, %g1
a00dda14:  c2 23 00 00  st  %g1, [ %o4 ]
a00dda18:  80 8a 20 80  btst  0x80, %o0
a00dda1c:  02 80 00 08  be  0xa00dda3c
a00dda20:  90 10 20 19  mov  0x19, %o0
a00dda24:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a00dda28:  90 13 62 00  or  %o5, 0x200, %o0	! 0xcf03c200
a00dda2c:  c2 02 00 00  ld  [ %o0 ], %g1
a00dda30:  98 10 60 08  or  %g1, 8, %o4
a00dda34:  d8 22 00 00  st  %o4, [ %o0 ]
a00dda38:  90 10 20 19  mov  0x19, %o0
a00dda3c:  d0 22 c0 00  st  %o0, [ %o3 ]
a00dda40:  d4 22 c0 00  st  %o2, [ %o3 ]
a00dda44:  81 c3 e0 08  retl
a00dda48:  01 00 00 00  nop
