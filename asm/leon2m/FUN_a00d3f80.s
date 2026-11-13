# leon2m FUN_a00d3f80 0xa00d3f80-0xa00d4084 (260 bytes)
a00d3f80:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d3f84:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d3f88:  da 00 60 a8  ld  [ %g1 + 0xa8 ], %o5
a00d3f8c:  80 8b 68 00  btst  0x800, %o5
a00d3f90:  22 80 00 07  be,a   0xa00d3fac
a00d3f94:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3f98:  d8 08 61 81  ldub  [ %g1 + 0x181 ], %o4
a00d3f9c:  80 a3 20 07  cmp  %o4, 7
a00d3fa0:  02 80 00 1c  be  0xa00d4010
a00d3fa4:  82 0a 20 ff  and  %o0, 0xff, %g1
a00d3fa8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3fac:  80 a2 20 45  cmp  %o0, 0x45
a00d3fb0:  18 80 00 0b  bgu  0xa00d3fdc
a00d3fb4:  82 5a 22 f1  smul  %o0, 0x2f1, %g1
a00d3fb8:  82 00 60 23  add  %g1, 0x23, %g1
a00d3fbc:  11 3a 83 a8  sethi  %hi(0xea0ea000), %o0
a00d3fc0:  99 30 60 01  srl  %g1, 1, %o4
a00d3fc4:  9a 12 20 eb  or  %o0, 0xeb, %o5
a00d3fc8:  80 53 00 0d  umul  %o4, %o5, %g0
a00d3fcc:  91 40 00 00  rd  %y, %o0
a00d3fd0:  9b 32 20 05  srl  %o0, 5, %o5
a00d3fd4:  10 80 00 1c  b  0xa00d4044
a00d3fd8:  82 03 60 7e  add  %o5, 0x7e, %g1
a00d3fdc:  83 2a 20 03  sll  %o0, 3, %g1
a00d3fe0:  98 00 40 08  add  %g1, %o0, %o4
a00d3fe4:  11 3f ff f6  sethi  %hi(0xffffd800), %o0
a00d3fe8:  83 2b 20 04  sll  %o4, 4, %g1
a00d3fec:  9a 12 20 af  or  %o0, 0xaf, %o5
a00d3ff0:  90 00 40 0d  add  %g1, %o5, %o0
a00d3ff4:  19 22 22 22  sethi  %hi(0x88888800), %o4
a00d3ff8:  9a 13 20 89  or  %o4, 0x89, %o5	! 0x88888889
a00d3ffc:  80 52 00 0d  umul  %o0, %o5, %g0
a00d4000:  83 40 00 00  rd  %y, %g1
a00d4004:  91 30 60 04  srl  %g1, 4, %o0
a00d4008:  10 80 00 0f  b  0xa00d4044
a00d400c:  82 02 23 6f  add  %o0, 0x36f, %g1
a00d4010:  80 a0 60 45  cmp  %g1, 0x45
a00d4014:  28 bf ff e9  bleu,a   0xa00d3fb8
a00d4018:  82 58 60 92  smul  %g1, 0x92, %g1
a00d401c:  19 3f ff cc  sethi  %hi(0xffff3000), %o4
a00d4020:  9a 13 22 b5  or  %o4, 0x2b5, %o5	! 0xffff32b5
a00d4024:  11 22 22 22  sethi  %hi(0x88888800), %o0
a00d4028:  82 58 62 ef  smul  %g1, 0x2ef, %g1
a00d402c:  82 00 40 0d  add  %g1, %o5, %g1
a00d4030:  98 12 20 89  or  %o0, 0x89, %o4
a00d4034:  80 50 40 0c  umul  %g1, %o4, %g0
a00d4038:  9b 40 00 00  rd  %y, %o5
a00d403c:  91 33 60 04  srl  %o5, 4, %o0
a00d4040:  82 02 21 10  add  %o0, 0x110, %g1
a00d4044:  99 28 60 10  sll  %g1, 0x10, %o4
a00d4048:  83 33 20 10  srl  %o4, 0x10, %g1
a00d404c:  98 58 60 64  smul  %g1, 0x64, %o4
a00d4050:  11 3f ff f3  sethi  %hi(0xffffcc00), %o0
a00d4054:  9a 12 22 c8  or  %o0, 0x2c8, %o5	! 0xffffcec8
a00d4058:  03 24 87 d9  sethi  %hi(0x921f6400), %g1
a00d405c:  98 03 00 0d  add  %o4, %o5, %o4
a00d4060:  90 10 60 bf  or  %g1, 0xbf, %o0
a00d4064:  80 5b 00 08  smul  %o4, %o0, %g0
a00d4068:  9b 40 00 00  rd  %y, %o5
a00d406c:  82 03 40 0c  add  %o5, %o4, %g1
a00d4070:  91 38 60 09  sra  %g1, 9, %o0
a00d4074:  99 3b 20 1f  sra  %o4, 0x1f, %o4
a00d4078:  9a 22 00 0c  sub  %o0, %o4, %o5
a00d407c:  81 c3 e0 08  retl
a00d4080:  90 0b 60 ff  and  %o5, 0xff, %o0
