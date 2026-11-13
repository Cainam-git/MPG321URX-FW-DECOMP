# leon2s FUN_a00a4ec4 0xa00a4ec4-0xa00a5050 (396 bytes)
a00a4ec4:  80 8a 20 ff  btst  0xff, %o0
a00a4ec8:  02 80 00 2e  be  0xa00a4f80
a00a4ecc:  83 2a 60 10  sll  %o1, 0x10, %g1
a00a4ed0:  1b 33 c0 49  sethi  %hi(0xcf012400), %o5
a00a4ed4:  98 13 60 b4  or  %o5, 0xb4, %o4	! 0xcf0124b4
a00a4ed8:  c2 03 00 00  ld  [ %o4 ], %g1
a00a4edc:  82 10 60 40  or  %g1, 0x40, %g1
a00a4ee0:  c2 23 00 00  st  %g1, [ %o4 ]
a00a4ee4:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a00a4ee8:  98 10 60 40  or  %g1, 0x40, %o4	! 0xcf03c840
a00a4eec:  9a 13 63 c0  or  %o5, 0x3c0, %o5
a00a4ef0:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00a4ef4:  c0 23 40 00  clr  [ %o5 ]
a00a4ef8:  90 10 63 ff  or  %g1, 0x3ff, %o0
a00a4efc:  94 10 3f ff  mov  -1, %o2
a00a4f00:  92 10 20 02  mov  2, %o1
a00a4f04:  82 02 bf ff  add  %o2, -1, %g1
a00a4f08:  9b 28 60 10  sll  %g1, 0x10, %o5
a00a4f0c:  97 33 60 10  srl  %o5, 0x10, %o3
a00a4f10:  da 03 00 00  ld  [ %o4 ], %o5
a00a4f14:  80 a3 60 01  cmp  %o5, 1
a00a4f18:  02 80 00 03  be  0xa00a4f24
a00a4f1c:  94 10 00 01  mov  %g1, %o2
a00a4f20:  d2 23 00 00  st  %o1, [ %o4 ]
a00a4f24:  c2 03 00 00  ld  [ %o4 ], %g1
a00a4f28:  80 a0 60 02  cmp  %g1, 2
a00a4f2c:  02 80 00 04  be  0xa00a4f3c
a00a4f30:  80 a2 c0 08  cmp  %o3, %o0
a00a4f34:  12 bf ff f5  bne  0xa00a4f08
a00a4f38:  82 02 bf ff  add  %o2, -1, %g1
a00a4f3c:  82 10 20 02  mov  2, %g1
a00a4f40:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a00a4f44:  c2 23 00 00  st  %g1, [ %o4 ]
a00a4f48:  9a 13 63 7c  or  %o5, 0x37c, %o5
a00a4f4c:  c2 03 40 00  ld  [ %o5 ], %g1
a00a4f50:  82 10 60 80  or  %g1, 0x80, %g1
a00a4f54:  c2 23 40 00  st  %g1, [ %o5 ]
a00a4f58:  1b 33 c0 49  sethi  %hi(0xcf012400), %o5
a00a4f5c:  c0 23 00 00  clr  [ %o4 ]
a00a4f60:  82 13 63 c4  or  %o5, 0x3c4, %g1
a00a4f64:  c0 20 40 00  clr  [ %g1 ]
a00a4f68:  82 13 63 c8  or  %o5, 0x3c8, %g1
a00a4f6c:  c0 20 40 00  clr  [ %g1 ]
a00a4f70:  9a 13 63 cc  or  %o5, 0x3cc, %o5
a00a4f74:  82 10 20 19  mov  0x19, %g1
a00a4f78:  c2 23 40 00  st  %g1, [ %o5 ]
a00a4f7c:  30 80 00 33  b,a   0xa00a5048
a00a4f80:  97 30 60 10  srl  %g1, 0x10, %o3
a00a4f84:  03 00 00 92  sethi  %hi(0x24800), %g1
a00a4f88:  80 a2 e1 90  cmp  %o3, 0x190
a00a4f8c:  18 80 00 14  bgu  0xa00a4fdc
a00a4f90:  92 10 61 f0  or  %g1, 0x1f0, %o1
a00a4f94:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00a4f98:  c2 00 60 08  ld  [ %g1 + 8 ], %g1	! 0xa807dc08
a00a4f9c:  c2 00 60 58  ld  [ %g1 + 0x58 ], %g1
a00a4fa0:  83 30 60 18  srl  %g1, 0x18, %g1
a00a4fa4:  80 88 60 01  btst  1, %g1
a00a4fa8:  12 80 00 0d  bne  0xa00a4fdc
a00a4fac:  92 5a e0 fa  smul  %o3, 0xfa, %o1
a00a4fb0:  1b 00 01 45  sethi  %hi(0x51400), %o5
a00a4fb4:  9a 13 61 c2  or  %o5, 0x1c2, %o5	! 0x515c2
a00a4fb8:  03 04 18 93  sethi  %hi(0x10624c00), %g1
a00a4fbc:  9a 5a c0 0d  smul  %o3, %o5, %o5
a00a4fc0:  82 10 61 d3  or  %g1, 0x1d3, %g1
a00a4fc4:  80 5b 40 01  smul  %o5, %g1, %g0
a00a4fc8:  83 40 00 00  rd  %y, %g1
a00a4fcc:  83 38 60 06  sra  %g1, 6, %g1
a00a4fd0:  9b 3b 60 1f  sra  %o5, 0x1f, %o5
a00a4fd4:  92 20 40 0d  sub  %g1, %o5, %o1
a00a4fd8:  92 02 7f 9c  add  %o1, -100, %o1
a00a4fdc:  03 2a aa aa  sethi  %hi(0xaaaaa800), %g1
a00a4fe0:  9a 5a 6a d0  smul  %o1, 0xad0, %o5
a00a4fe4:  82 10 62 ab  or  %g1, 0x2ab, %g1
a00a4fe8:  80 53 40 01  umul  %o5, %g1, %g0
a00a4fec:  9b 40 00 00  rd  %y, %o5
a00a4ff0:  03 04 18 93  sethi  %hi(0x10624c00), %g1
a00a4ff4:  99 2a 60 02  sll  %o1, 2, %o4
a00a4ff8:  82 10 61 d3  or  %g1, 0x1d3, %g1
a00a4ffc:  9b 33 60 01  srl  %o5, 1, %o5
a00a5000:  80 53 40 01  umul  %o5, %g1, %g0
a00a5004:  9b 40 00 00  rd  %y, %o5
a00a5008:  98 03 00 09  add  %o4, %o1, %o4
a00a500c:  98 03 00 0c  add  %o4, %o4, %o4
a00a5010:  9b 33 60 06  srl  %o5, 6, %o5
a00a5014:  92 03 00 0d  add  %o4, %o5, %o1
a00a5018:  17 33 c0 49  sethi  %hi(0xcf012400), %o3
a00a501c:  98 12 e3 c4  or  %o3, 0x3c4, %o4	! 0xcf0127c4
a00a5020:  82 0a 60 ff  and  %o1, 0xff, %g1
a00a5024:  c2 23 00 00  st  %g1, [ %o4 ]
a00a5028:  9b 32 60 08  srl  %o1, 8, %o5
a00a502c:  82 12 e3 c8  or  %o3, 0x3c8, %g1
a00a5030:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00a5034:  99 32 60 10  srl  %o1, 0x10, %o4
a00a5038:  da 20 40 00  st  %o5, [ %g1 ]
a00a503c:  96 12 e3 cc  or  %o3, 0x3cc, %o3
a00a5040:  98 0b 20 ff  and  %o4, 0xff, %o4
a00a5044:  d8 22 c0 00  st  %o4, [ %o3 ]
a00a5048:  81 c3 e0 08  retl
a00a504c:  01 00 00 00  nop
