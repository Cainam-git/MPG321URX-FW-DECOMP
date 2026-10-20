# leon2m FUN_a00a1eec 0xa00a1eec-0xa00a20d0 (484 bytes)
a00a1eec:  9d e3 bf 98  save  %sp, -104, %sp
a00a1ef0:  31 2a 00 97  sethi  %hi(0xa8025c00), %i0
a00a1ef4:  1f 2a 00 ab  sethi  %hi(0xa802ac00), %o7
a00a1ef8:  f2 0e 20 55  ldub  [ %i0 + 0x55 ], %i1
a00a1efc:  fa 03 e3 ec  ld  [ %o7 + 0x3ec ], %i5
a00a1f00:  82 06 7f ff  add  %i1, -1, %g1
a00a1f04:  ba 07 7f 40  add  %i5, -192, %i5
a00a1f08:  c2 2e 20 55  stb  %g1, [ %i0 + 0x55 ]
a00a1f0c:  80 a7 60 39  cmp  %i5, 0x39
a00a1f10:  18 80 00 08  bgu  0xa00a1f30
a00a1f14:  b6 10 20 00  clr  %i3
a00a1f18:  b5 2f 60 02  sll  %i5, 2, %i2
a00a1f1c:  3b 00 00 c2  sethi  %hi(0x30800), %i5
a00a1f20:  82 17 60 d8  or  %i5, 0xd8, %g1	! 0x308d8
a00a1f24:  f8 00 40 1a  ld  [ %g1 + %i2 ], %i4
a00a1f28:  81 c7 00 00  jmp  %i4
a00a1f2c:  01 00 00 00  nop
a00a1f30:  ba 10 20 00  clr  %i5	! 0x0
a00a1f34:  f6 0e 20 55  ldub  [ %i0 + 0x55 ], %i3
a00a1f38:  80 a6 c0 1d  cmp  %i3, %i5
a00a1f3c:  1a 80 00 10  bcc  0xa00a1f7c
a00a1f40:  ba 16 20 55  or  %i0, 0x55, %i5
a00a1f44:  f2 03 e3 ec  ld  [ %o7 + 0x3ec ], %i1
a00a1f48:  82 06 7f 40  add  %i1, -192, %g1
a00a1f4c:  b4 10 00 1d  mov  %i5, %i2
a00a1f50:  80 a0 60 39  cmp  %g1, 0x39
a00a1f54:  18 80 00 08  bgu  0xa00a1f74
a00a1f58:  b6 10 20 00  clr  %i3
a00a1f5c:  33 00 00 c1  sethi  %hi(0x30400), %i1
a00a1f60:  83 28 60 02  sll  %g1, 2, %g1
a00a1f64:  ba 16 63 f0  or  %i1, 0x3f0, %i5
a00a1f68:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a00a1f6c:  81 c7 00 00  jmp  %i4
a00a1f70:  01 00 00 00  nop
a00a1f74:  82 10 20 00  clr  %g1	! 0x0
a00a1f78:  c2 2e 80 00  stb  %g1, [ %i2 ]
a00a1f7c:  f4 03 e3 ec  ld  [ %o7 + 0x3ec ], %i2
a00a1f80:  82 06 bf 40  add  %i2, -192, %g1
a00a1f84:  80 a0 60 39  cmp  %g1, 0x39
a00a1f88:  f4 0e 20 55  ldub  [ %i0 + 0x55 ], %i2
a00a1f8c:  18 80 00 08  bgu  0xa00a1fac
a00a1f90:  b6 10 20 00  clr  %i3
a00a1f94:  33 00 00 c1  sethi  %hi(0x30400), %i1
a00a1f98:  83 28 60 02  sll  %g1, 2, %g1
a00a1f9c:  ba 16 63 08  or  %i1, 0x308, %i5
a00a1fa0:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a00a1fa4:  81 c7 00 00  jmp  %i4
a00a1fa8:  01 00 00 00  nop
a00a1fac:  b8 10 20 00  clr  %i4	! 0x0
a00a1fb0:  ba 26 80 1c  sub  %i2, %i4, %i5
a00a1fb4:  82 07 40 1d  add  %i5, %i5, %g1
a00a1fb8:  b4 00 40 1d  add  %g1, %i5, %i2
a00a1fbc:  b7 2e a0 05  sll  %i2, 5, %i3
a00a1fc0:  f8 03 e3 ec  ld  [ %o7 + 0x3ec ], %i4
a00a1fc4:  ba 07 3f 40  add  %i4, -192, %i5
a00a1fc8:  9a 06 80 1b  add  %i2, %i3, %o5
a00a1fcc:  80 a7 60 39  cmp  %i5, 0x39
a00a1fd0:  18 80 00 08  bgu  0xa00a1ff0
a00a1fd4:  b6 10 20 00  clr  %i3
a00a1fd8:  03 00 00 c1  sethi  %hi(0x30400), %g1
a00a1fdc:  b5 2f 60 02  sll  %i5, 2, %i2
a00a1fe0:  b8 10 62 20  or  %g1, 0x220, %i4
a00a1fe4:  f2 07 00 1a  ld  [ %i4 + %i2 ], %i1
a00a1fe8:  81 c6 40 00  jmp  %i1
a00a1fec:  01 00 00 00  nop
a00a1ff0:  b2 10 20 00  clr  %i1	! 0x0
a00a1ff4:  f6 03 e3 ec  ld  [ %o7 + 0x3ec ], %i3
a00a1ff8:  82 06 ff 40  add  %i3, -192, %g1
a00a1ffc:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00a2000:  80 a0 60 39  cmp  %g1, 0x39
a00a2004:  18 80 00 08  bgu  0xa00a2024
a00a2008:  b6 10 20 00  clr  %i3
a00a200c:  33 00 00 c1  sethi  %hi(0x30400), %i1
a00a2010:  b9 28 60 02  sll  %g1, 2, %i4
a00a2014:  ba 16 61 38  or  %i1, 0x138, %i5
a00a2018:  f2 07 40 1c  ld  [ %i5 + %i4 ], %i1
a00a201c:  81 c6 40 00  jmp  %i1
a00a2020:  01 00 00 00  nop
a00a2024:  b2 10 20 00  clr  %i1	! 0x0
a00a2028:  b8 26 80 19  sub  %i2, %i1, %i4
a00a202c:  83 3b 60 1f  sra  %o5, 0x1f, %g1
a00a2030:  81 80 60 00  mov  %g1, %y
a00a2034:  01 00 00 00  nop
a00a2038:  01 00 00 00  nop
a00a203c:  01 00 00 00  nop
a00a2040:  b6 7b 40 1c  sdiv  %o5, %i4, %i3
a00a2044:  b4 06 e0 01  add  %i3, 1, %i2
a00a2048:  b2 0e a0 ff  and  %i2, 0xff, %i1
a00a204c:  f4 0e 20 55  ldub  [ %i0 + 0x55 ], %i2
a00a2050:  40 00 57 86  call  0xa00b7e68
a00a2054:  91 e8 20 01  restore  %g0, 1, %o0
a00a2058:  b6 10 20 01  mov  1, %i3
a00a205c:  b2 0e e0 ff  and  %i3, 0xff, %i1
a00a2060:  b8 26 80 19  sub  %i2, %i1, %i4
a00a2064:  83 3b 60 1f  sra  %o5, 0x1f, %g1
a00a2068:  81 80 60 00  mov  %g1, %y
a00a206c:  01 00 00 00  nop
a00a2070:  01 00 00 00  nop
a00a2074:  01 00 00 00  nop
a00a2078:  b6 7b 40 1c  sdiv  %o5, %i4, %i3
a00a207c:  b4 06 e0 01  add  %i3, 1, %i2
a00a2080:  b2 0e a0 ff  and  %i2, 0xff, %i1
a00a2084:  f4 0e 20 55  ldub  [ %i0 + 0x55 ], %i2
a00a2088:  40 00 57 78  call  0xa00b7e68
a00a208c:  91 e8 20 01  restore  %g0, 1, %o0
a00a2090:  b6 10 20 01  mov  1, %i3
a00a2094:  10 bf ff c7  b  0xa00a1fb0
a00a2098:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00a209c:  b6 10 20 01  mov  1, %i3
a00a20a0:  10 bf ff a5  b  0xa00a1f34
a00a20a4:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00a20a8:  b6 10 20 03  mov  3, %i3
a00a20ac:  10 bf ff d2  b  0xa00a1ff4
a00a20b0:  b2 0e e0 ff  and  %i3, 0xff, %i1
a00a20b4:  b6 10 20 01  mov  1, %i3
a00a20b8:  82 0e e0 ff  and  %i3, 0xff, %g1
a00a20bc:  10 bf ff b0  b  0xa00a1f7c
a00a20c0:  c2 2e 80 00  stb  %g1, [ %i2 ]
a00a20c4:  b6 10 20 02  mov  2, %i3
a00a20c8:  10 bf ff cb  b  0xa00a1ff4
a00a20cc:  b2 0e e0 ff  and  %i3, 0xff, %i1
