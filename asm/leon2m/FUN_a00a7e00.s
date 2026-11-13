# leon2m FUN_a00a7e00 0xa00a7e00-0xa00a813c (828 bytes)
a00a7e00:  9d e3 bf 90  save  %sp, -112, %sp
a00a7e04:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a7e08:  82 04 00 10  add  %l0, %l0, %g1
a00a7e0c:  80 a4 20 06  cmp  %l0, 6
a00a7e10:  18 80 00 03  bgu  0xa00a7e1c
a00a7e14:  b8 00 7f f7  add  %g1, -9, %i4
a00a7e18:  b8 00 60 05  add  %g1, 5, %i4
a00a7e1c:  17 00 00 18  sethi  %hi(0x6000), %o3
a00a7e20:  b6 12 e2 9a  or  %o3, 0x29a, %i3	! 0x629a
a00a7e24:  90 10 20 01  mov  1, %o0
a00a7e28:  92 10 20 00  clr  %o1
a00a7e2c:  40 02 7b 85  call  0xa0146c40
a00a7e30:  94 10 20 00  clr  %o2
a00a7e34:  90 10 20 02  mov  2, %o0
a00a7e38:  92 10 20 00  clr  %o1
a00a7e3c:  40 02 7b 81  call  0xa0146c40
a00a7e40:  94 10 20 00  clr  %o2
a00a7e44:  67 ff 99 18  call  0x4008e2a4
a00a7e48:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00a7e4c:  90 10 20 01  mov  1, %o0
a00a7e50:  92 10 00 1d  mov  %i5, %o1
a00a7e54:  94 10 20 01  mov  1, %o2
a00a7e58:  96 10 27 92  mov  0x792, %o3
a00a7e5c:  40 02 7b 09  call  0xa0146a80
a00a7e60:  98 10 20 00  clr  %o4
a00a7e64:  94 06 3f fa  add  %i0, -6, %o2
a00a7e68:  92 0a a0 ff  and  %o2, 0xff, %o1
a00a7e6c:  80 a2 60 02  cmp  %o1, 2
a00a7e70:  90 60 20 00  subx  %g0, 0, %o0
a00a7e74:  80 a0 00 10  cmp  %g0, %l0
a00a7e78:  9a 0a 20 01  and  %o0, 1, %o5
a00a7e7c:  82 60 3f ff  subx  %g0, -1, %g1
a00a7e80:  80 93 40 01  orcc  %o5, %g1, %g0
a00a7e84:  12 80 00 6f  bne  0xa00a8040
a00a7e88:  82 1c 20 08  xor  %l0, 8, %g1
a00a7e8c:  9a 1c 20 01  xor  %l0, 1, %o5
a00a7e90:  80 a0 00 0d  cmp  %g0, %o5
a00a7e94:  b6 40 20 00  addx  %g0, 0, %i3
a00a7e98:  80 a0 00 01  cmp  %g0, %g1
a00a7e9c:  b4 40 20 00  addx  %g0, 0, %i2
a00a7ea0:  80 8e c0 1a  btst  %i3, %i2
a00a7ea4:  12 80 00 46  bne  0xa00a7fbc
a00a7ea8:  80 a4 20 08  cmp  %l0, 8
a00a7eac:  02 80 00 99  be  0xa00a8110
a00a7eb0:  82 10 20 76  mov  0x76, %g1
a00a7eb4:  80 a4 20 01  cmp  %l0, 1
a00a7eb8:  02 80 00 96  be  0xa00a8110
a00a7ebc:  82 10 20 4f  mov  0x4f, %g1
a00a7ec0:  98 10 00 1d  mov  %i5, %o4
a00a7ec4:  90 10 20 01  mov  1, %o0
a00a7ec8:  92 10 20 00  clr  %o1
a00a7ecc:  94 10 27 92  mov  0x792, %o2
a00a7ed0:  96 10 20 01  mov  1, %o3
a00a7ed4:  9a 10 20 01  mov  1, %o5
a00a7ed8:  40 00 2d 03  call  0xa00b32e4
a00a7edc:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a7ee0:  98 10 00 1d  mov  %i5, %o4
a00a7ee4:  90 10 20 01  mov  1, %o0
a00a7ee8:  92 10 20 00  clr  %o1
a00a7eec:  94 10 27 92  mov  0x792, %o2
a00a7ef0:  96 10 20 05  mov  5, %o3
a00a7ef4:  9a 10 20 0d  mov  0xd, %o5
a00a7ef8:  40 00 2c fb  call  0xa00b32e4
a00a7efc:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a7f00:  92 07 20 02  add  %i4, 2, %o1
a00a7f04:  ba 0a 60 ff  and  %o1, 0xff, %i5
a00a7f08:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a7f0c:  90 10 20 01  mov  1, %o0
a00a7f10:  92 10 20 00  clr  %o1
a00a7f14:  94 10 27 92  mov  0x792, %o2
a00a7f18:  96 10 20 01  mov  1, %o3
a00a7f1c:  98 10 00 1d  mov  %i5, %o4
a00a7f20:  40 00 2c f1  call  0xa00b32e4
a00a7f24:  9a 10 20 11  mov  0x11, %o5
a00a7f28:  80 a4 20 05  cmp  %l0, 5
a00a7f2c:  02 80 00 3a  be  0xa00a8014
a00a7f30:  96 10 20 64  mov  0x64, %o3
a00a7f34:  3b 00 00 19  sethi  %hi(0x6400), %i5
a00a7f38:  b6 17 61 9a  or  %i5, 0x19a, %i3	! 0x659a
a00a7f3c:  b4 0f 20 ff  and  %i4, 0xff, %i2
a00a7f40:  b0 07 20 01  add  %i4, 1, %i0
a00a7f44:  98 0e 20 ff  and  %i0, 0xff, %o4
a00a7f48:  9a 10 20 01  mov  1, %o5
a00a7f4c:  90 10 20 01  mov  1, %o0
a00a7f50:  92 10 20 00  clr  %o1
a00a7f54:  94 10 27 92  mov  0x792, %o2
a00a7f58:  96 10 20 01  mov  1, %o3
a00a7f5c:  40 00 2c e2  call  0xa00b32e4
a00a7f60:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a7f64:  98 06 a0 01  add  %i2, 1, %o4
a00a7f68:  a1 2b 20 10  sll  %o4, 0x10, %l0
a00a7f6c:  b9 2e e0 10  sll  %i3, 0x10, %i4
a00a7f70:  b5 34 20 10  srl  %l0, 0x10, %i2
a00a7f74:  97 37 20 10  srl  %i4, 0x10, %o3
a00a7f78:  90 10 20 02  mov  2, %o0
a00a7f7c:  92 10 00 1a  mov  %i2, %o1
a00a7f80:  94 10 20 03  mov  3, %o2
a00a7f84:  40 02 7a bf  call  0xa0146a80
a00a7f88:  98 10 20 00  clr  %o4
a00a7f8c:  90 10 20 05  mov  5, %o0
a00a7f90:  92 10 00 1a  mov  %i2, %o1
a00a7f94:  94 10 20 0d  mov  0xd, %o2
a00a7f98:  96 10 27 92  mov  0x792, %o3
a00a7f9c:  40 02 7a b9  call  0xa0146a80
a00a7fa0:  98 10 20 00  clr  %o4
a00a7fa4:  b0 10 20 00  clr  %i0
a00a7fa8:  b2 10 20 11  mov  0x11, %i1
a00a7fac:  b6 10 20 01  mov  1, %i3
a00a7fb0:  b8 10 20 00  clr  %i4
a00a7fb4:  40 02 7a db  call  0xa0146b20
a00a7fb8:  9b e8 20 00  restore  %g0, 0, %o5
a00a7fbc:  98 10 00 1d  mov  %i5, %o4
a00a7fc0:  90 10 20 01  mov  1, %o0
a00a7fc4:  92 10 20 00  clr  %o1
a00a7fc8:  94 10 27 92  mov  0x792, %o2
a00a7fcc:  96 10 20 01  mov  1, %o3
a00a7fd0:  9a 10 20 11  mov  0x11, %o5
a00a7fd4:  40 00 2c c4  call  0xa00b32e4
a00a7fd8:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a7fdc:  92 07 20 02  add  %i4, 2, %o1
a00a7fe0:  ba 0a 60 ff  and  %o1, 0xff, %i5
a00a7fe4:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a7fe8:  90 10 20 01  mov  1, %o0
a00a7fec:  92 10 20 00  clr  %o1
a00a7ff0:  94 10 27 92  mov  0x792, %o2
a00a7ff4:  96 10 20 01  mov  1, %o3
a00a7ff8:  98 10 00 1d  mov  %i5, %o4
a00a7ffc:  40 00 2c ba  call  0xa00b32e4
a00a8000:  9a 10 20 11  mov  0x11, %o5
a00a8004:  80 a4 20 05  cmp  %l0, 5
a00a8008:  32 bf ff cc  bne,a   0xa00a7f38
a00a800c:  3b 00 00 19  sethi  %hi(0x6400), %i5
a00a8010:  96 10 20 64  mov  0x64, %o3
a00a8014:  d6 23 a0 5c  st  %o3, [ %sp + 0x5c ]
a00a8018:  15 00 00 18  sethi  %hi(0x6000), %o2
a00a801c:  94 12 a2 9a  or  %o2, 0x29a, %o2	! 0x629a
a00a8020:  98 10 00 1d  mov  %i5, %o4
a00a8024:  90 10 20 01  mov  1, %o0
a00a8028:  92 10 20 01  mov  1, %o1
a00a802c:  96 10 20 02  mov  2, %o3
a00a8030:  40 00 2c ad  call  0xa00b32e4
a00a8034:  9a 10 20 03  mov  3, %o5
a00a8038:  10 bf ff c0  b  0xa00a7f38
a00a803c:  3b 00 00 19  sethi  %hi(0x6400), %i5
a00a8040:  31 00 00 18  sethi  %hi(0x6000), %i0
a00a8044:  92 10 00 1d  mov  %i5, %o1
a00a8048:  96 16 22 9a  or  %i0, 0x29a, %o3
a00a804c:  90 10 20 02  mov  2, %o0
a00a8050:  94 10 20 03  mov  3, %o2
a00a8054:  40 02 7a 8b  call  0xa0146a80
a00a8058:  98 10 20 00  clr  %o4
a00a805c:  98 10 00 1d  mov  %i5, %o4
a00a8060:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a8064:  90 10 20 01  mov  1, %o0
a00a8068:  92 10 20 00  clr  %o1
a00a806c:  94 10 27 92  mov  0x792, %o2
a00a8070:  96 10 20 01  mov  1, %o3
a00a8074:  40 00 2c 9c  call  0xa00b32e4
a00a8078:  9a 10 20 01  mov  1, %o5
a00a807c:  98 10 00 1d  mov  %i5, %o4
a00a8080:  9a 10 20 0d  mov  0xd, %o5
a00a8084:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a8088:  90 10 20 01  mov  1, %o0
a00a808c:  92 10 20 00  clr  %o1
a00a8090:  94 10 27 92  mov  0x792, %o2
a00a8094:  96 10 20 05  mov  5, %o3
a00a8098:  40 00 2c 93  call  0xa00b32e4
a00a809c:  b4 0f 20 ff  and  %i4, 0xff, %i2
a00a80a0:  b2 06 a0 02  add  %i2, 2, %i1
a00a80a4:  9f 2e 60 10  sll  %i1, 0x10, %o7
a00a80a8:  93 33 e0 10  srl  %o7, 0x10, %o1
a00a80ac:  96 16 22 9a  or  %i0, 0x29a, %o3
a00a80b0:  90 10 20 02  mov  2, %o0
a00a80b4:  94 10 20 03  mov  3, %o2
a00a80b8:  40 02 7a 72  call  0xa0146a80
a00a80bc:  98 10 20 00  clr  %o4
a00a80c0:  98 07 20 02  add  %i4, 2, %o4
a00a80c4:  a0 0b 20 ff  and  %o4, 0xff, %l0
a00a80c8:  98 10 00 10  mov  %l0, %o4
a00a80cc:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a80d0:  90 10 20 01  mov  1, %o0
a00a80d4:  92 10 20 00  clr  %o1
a00a80d8:  94 10 27 92  mov  0x792, %o2
a00a80dc:  96 10 20 01  mov  1, %o3
a00a80e0:  40 00 2c 81  call  0xa00b32e4
a00a80e4:  9a 10 20 01  mov  1, %o5
a00a80e8:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a80ec:  98 10 00 10  mov  %l0, %o4
a00a80f0:  90 10 20 01  mov  1, %o0
a00a80f4:  92 10 20 00  clr  %o1
a00a80f8:  94 10 27 92  mov  0x792, %o2
a00a80fc:  96 10 20 05  mov  5, %o3
a00a8100:  40 00 2c 79  call  0xa00b32e4
a00a8104:  9a 10 20 0d  mov  0xd, %o5
a00a8108:  10 bf ff 8f  b  0xa00a7f44
a00a810c:  b0 07 20 01  add  %i4, 1, %i0
a00a8110:  11 00 00 18  sethi  %hi(0x6000), %o0
a00a8114:  94 12 22 9a  or  %o0, 0x29a, %o2	! 0x629a
a00a8118:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a00a811c:  90 10 20 01  mov  1, %o0
a00a8120:  92 10 20 01  mov  1, %o1
a00a8124:  96 10 20 02  mov  2, %o3
a00a8128:  98 10 00 1d  mov  %i5, %o4
a00a812c:  40 00 2c 6e  call  0xa00b32e4
a00a8130:  9a 10 20 03  mov  3, %o5
a00a8134:  10 bf ff 64  b  0xa00a7ec4
a00a8138:  98 10 00 1d  mov  %i5, %o4
