# leon2s FUN_a00dbf24 0xa00dbf24-0xa00dc034 (272 bytes)
a00dbf24:  15 2a 01 e2  sethi  %hi(0xa8078800), %o2
a00dbf28:  d8 0a a0 32  ldub  [ %o2 + 0x32 ], %o4	! 0xa8078832
a00dbf2c:  80 a3 20 00  cmp  %o4, 0
a00dbf30:  12 80 00 3f  bne  0xa00dc02c
a00dbf34:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dbf38:  82 10 60 28  or  %g1, 0x28, %g1	! 0xa8078828
a00dbf3c:  da 08 40 0c  ldub  [ %g1 + %o4 ], %o5
a00dbf40:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dbf44:  82 10 60 30  or  %g1, 0x30, %g1	! 0xa8078830
a00dbf48:  c2 08 40 0c  ldub  [ %g1 + %o4 ], %g1
a00dbf4c:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00dbf50:  98 20 40 0d  sub  %g1, %o5, %o4
a00dbf54:  80 a3 40 01  cmp  %o5, %g1
a00dbf58:  18 80 00 04  bgu  0xa00dbf68
a00dbf5c:  c0 2a e0 3e  clrb  [ %o3 + 0x3e ]
a00dbf60:  10 80 00 04  b  0xa00dbf70
a00dbf64:  d8 2a e0 3e  stb  %o4, [ %o3 + 0x3e ]
a00dbf68:  82 03 20 10  add  %o4, 0x10, %g1
a00dbf6c:  c2 2a e0 3e  stb  %g1, [ %o3 + 0x3e ]
a00dbf70:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dbf74:  d8 0a a0 32  ldub  [ %o2 + 0x32 ], %o4
a00dbf78:  82 10 60 00  mov  %g1, %g1
a00dbf7c:  da 08 40 0c  ldub  [ %g1 + %o4 ], %o5
a00dbf80:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dbf84:  82 10 60 08  or  %g1, 8, %g1	! 0xa8078808
a00dbf88:  c2 08 40 0c  ldub  [ %g1 + %o4 ], %g1
a00dbf8c:  80 a3 40 01  cmp  %o5, %g1
a00dbf90:  18 80 00 05  bgu  0xa00dbfa4
a00dbf94:  98 20 40 0d  sub  %g1, %o5, %o4
a00dbf98:  c2 0a e0 3e  ldub  [ %o3 + 0x3e ], %g1
a00dbf9c:  10 80 00 05  b  0xa00dbfb0
a00dbfa0:  82 03 00 01  add  %o4, %g1, %g1
a00dbfa4:  c2 0a e0 3e  ldub  [ %o3 + 0x3e ], %g1
a00dbfa8:  82 03 00 01  add  %o4, %g1, %g1
a00dbfac:  82 00 60 10  add  %g1, 0x10, %g1
a00dbfb0:  c2 2a e0 3e  stb  %g1, [ %o3 + 0x3e ]
a00dbfb4:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00dbfb8:  da 08 63 ff  ldub  [ %g1 + 0x3ff ], %o5	! 0xa80787ff
a00dbfbc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00dbfc0:  c2 08 63 fe  ldub  [ %g1 + 0x3fe ], %g1	! 0xa80787fe
a00dbfc4:  98 23 40 01  sub  %o5, %g1, %o4
a00dbfc8:  80 a0 40 0d  cmp  %g1, %o5
a00dbfcc:  18 80 00 05  bgu  0xa00dbfe0
a00dbfd0:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00dbfd4:  c2 0b 60 3e  ldub  [ %o5 + 0x3e ], %g1	! 0xa807883e
a00dbfd8:  10 80 00 05  b  0xa00dbfec
a00dbfdc:  82 03 00 01  add  %o4, %g1, %g1
a00dbfe0:  c2 0b 60 3e  ldub  [ %o5 + 0x3e ], %g1
a00dbfe4:  82 03 00 01  add  %o4, %g1, %g1
a00dbfe8:  82 00 60 10  add  %g1, 0x10, %g1
a00dbfec:  c2 2b 60 3e  stb  %g1, [ %o5 + 0x3e ]
a00dbff0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00dbff4:  da 08 63 fd  ldub  [ %g1 + 0x3fd ], %o5	! 0xa80787fd
a00dbff8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00dbffc:  c2 08 63 fc  ldub  [ %g1 + 0x3fc ], %g1	! 0xa80787fc
a00dc000:  98 23 40 01  sub  %o5, %g1, %o4
a00dc004:  80 a0 40 0d  cmp  %g1, %o5
a00dc008:  18 80 00 05  bgu  0xa00dc01c
a00dc00c:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00dc010:  c2 0b 60 3e  ldub  [ %o5 + 0x3e ], %g1	! 0xa807883e
a00dc014:  10 80 00 05  b  0xa00dc028
a00dc018:  82 03 00 01  add  %o4, %g1, %g1
a00dc01c:  c2 0b 60 3e  ldub  [ %o5 + 0x3e ], %g1
a00dc020:  82 03 00 01  add  %o4, %g1, %g1
a00dc024:  82 00 60 10  add  %g1, 0x10, %g1
a00dc028:  c2 2b 60 3e  stb  %g1, [ %o5 + 0x3e ]
a00dc02c:  81 c3 e0 08  retl
a00dc030:  01 00 00 00  nop
