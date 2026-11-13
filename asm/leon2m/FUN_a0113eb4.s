# leon2m FUN_a0113eb4 0xa0113eb4-0xa011403c (392 bytes)
a0113eb4:  9d e3 bf 98  save  %sp, -104, %sp
a0113eb8:  b4 0e a0 ff  and  %i2, 0xff, %i2
a0113ebc:  98 10 00 18  mov  %i0, %o4
a0113ec0:  9a 10 00 19  mov  %i1, %o5
a0113ec4:  80 a6 a0 00  cmp  %i2, 0
a0113ec8:  08 80 00 5b  bleu  0xa0114034
a0113ecc:  96 10 20 00  clr  %o3
a0113ed0:  15 33 c0 47  sethi  %hi(0xcf011c00), %o2
a0113ed4:  a6 12 a3 88  or  %o2, 0x388, %l3	! 0xcf011f88
a0113ed8:  90 0e e0 ff  and  %i3, 0xff, %o0
a0113edc:  92 10 00 1a  mov  %i2, %o1
a0113ee0:  a4 12 a3 84  or  %o2, 0x384, %l2
a0113ee4:  a8 10 00 13  mov  %l3, %l4
a0113ee8:  a0 12 a3 a4  or  %o2, 0x3a4, %l0
a0113eec:  a2 12 a3 a8  or  %o2, 0x3a8, %l1
a0113ef0:  b4 12 a3 a0  or  %o2, 0x3a0, %i2
a0113ef4:  da 26 80 00  st  %o5, [ %i2 ]
a0113ef8:  b3 33 60 08  srl  %o5, 8, %i1
a0113efc:  f2 24 00 00  st  %i1, [ %l0 ]
a0113f00:  b1 33 60 10  srl  %o5, 0x10, %i0
a0113f04:  f0 24 40 00  st  %i0, [ %l1 ]
a0113f08:  b8 12 a3 ac  or  %o2, 0x3ac, %i4
a0113f0c:  83 33 60 18  srl  %o5, 0x18, %g1
a0113f10:  c2 27 00 00  st  %g1, [ %i4 ]
a0113f14:  ba 10 20 80  mov  0x80, %i5
a0113f18:  fa 24 80 00  st  %i5, [ %l2 ]
a0113f1c:  80 a2 20 01  cmp  %o0, 1
a0113f20:  02 80 00 24  be  0xa0113fb0
a0113f24:  b1 2a e0 10  sll  %o3, 0x10, %i0
a0113f28:  bb 36 20 10  srl  %i0, 0x10, %i5
a0113f2c:  b5 2f 60 05  sll  %i5, 5, %i2
a0113f30:  b7 2f 60 15  sll  %i5, 0x15, %i3
a0113f34:  b3 36 e0 10  srl  %i3, 0x10, %i1
a0113f38:  9e 06 a0 20  add  %i2, 0x20, %o7
a0113f3c:  80 a6 40 0f  cmp  %i1, %o7
a0113f40:  16 80 00 14  bge  0xa0113f90
a0113f44:  b2 10 00 1a  mov  %i2, %i1
a0113f48:  b0 10 00 13  mov  %l3, %i0
a0113f4c:  b5 2e 60 10  sll  %i1, 0x10, %i2
a0113f50:  b5 36 a0 10  srl  %i2, 0x10, %i2
a0113f54:  b8 06 80 0c  add  %i2, %o4, %i4
a0113f58:  c2 0f 20 03  ldub  [ %i4 + 3 ], %g1
a0113f5c:  c2 26 00 00  st  %g1, [ %i0 ]
a0113f60:  f6 0f 20 02  ldub  [ %i4 + 2 ], %i3
a0113f64:  f6 26 00 00  st  %i3, [ %i0 ]
a0113f68:  fa 0f 20 01  ldub  [ %i4 + 1 ], %i5
a0113f6c:  b2 06 60 04  add  %i1, 4, %i1
a0113f70:  fa 26 00 00  st  %i5, [ %i0 ]
a0113f74:  83 2e 60 10  sll  %i1, 0x10, %g1
a0113f78:  f6 0e 80 0c  ldub  [ %i2 + %o4 ], %i3
a0113f7c:  b9 30 60 10  srl  %g1, 0x10, %i4
a0113f80:  f6 26 00 00  st  %i3, [ %i0 ]
a0113f84:  80 a7 00 0f  cmp  %i4, %o7
a0113f88:  06 bf ff f2  bl  0xa0113f50
a0113f8c:  b5 2e 60 10  sll  %i1, 0x10, %i2
a0113f90:  b2 02 e0 01  add  %o3, 1, %i1
a0113f94:  bb 2e 60 10  sll  %i1, 0x10, %i5
a0113f98:  b1 37 60 10  srl  %i5, 0x10, %i0
a0113f9c:  80 a2 40 18  cmp  %o1, %i0
a0113fa0:  9a 03 60 01  inc  %o5
a0113fa4:  18 bf ff d3  bgu  0xa0113ef0
a0113fa8:  96 10 00 19  mov  %i1, %o3
a0113fac:  30 80 00 22  b,a   0xa0114034
a0113fb0:  83 36 20 10  srl  %i0, 0x10, %g1
a0113fb4:  b9 28 60 05  sll  %g1, 5, %i4
a0113fb8:  bb 28 60 15  sll  %g1, 0x15, %i5
a0113fbc:  b7 37 60 10  srl  %i5, 0x10, %i3
a0113fc0:  b2 07 20 20  add  %i4, 0x20, %i1
a0113fc4:  80 a6 c0 19  cmp  %i3, %i1
a0113fc8:  16 bf ff f2  bge  0xa0113f90
a0113fcc:  b6 10 00 1c  mov  %i4, %i3
a0113fd0:  b4 10 00 14  mov  %l4, %i2
a0113fd4:  83 2e e0 10  sll  %i3, 0x10, %g1
a0113fd8:  b1 30 60 10  srl  %g1, 0x10, %i0
a0113fdc:  f8 0e 00 0c  ldub  [ %i0 + %o4 ], %i4
a0113fe0:  f8 26 80 00  st  %i4, [ %i2 ]
a0113fe4:  82 06 00 0c  add  %i0, %o4, %g1
a0113fe8:  fa 08 60 01  ldub  [ %g1 + 1 ], %i5
a0113fec:  fa 26 80 00  st  %i5, [ %i2 ]
a0113ff0:  f8 08 60 02  ldub  [ %g1 + 2 ], %i4
a0113ff4:  b6 06 e0 04  add  %i3, 4, %i3
a0113ff8:  f8 26 80 00  st  %i4, [ %i2 ]
a0113ffc:  b1 2e e0 10  sll  %i3, 0x10, %i0
a0114000:  fa 08 60 03  ldub  [ %g1 + 3 ], %i5
a0114004:  b9 36 20 10  srl  %i0, 0x10, %i4
a0114008:  fa 26 80 00  st  %i5, [ %i2 ]
a011400c:  80 a7 00 19  cmp  %i4, %i1
a0114010:  26 bf ff f2  bl,a   0xa0113fd8
a0114014:  83 2e e0 10  sll  %i3, 0x10, %g1
a0114018:  b2 02 e0 01  add  %o3, 1, %i1
a011401c:  bb 2e 60 10  sll  %i1, 0x10, %i5
a0114020:  b1 37 60 10  srl  %i5, 0x10, %i0
a0114024:  80 a2 40 18  cmp  %o1, %i0
a0114028:  9a 03 60 01  inc  %o5
a011402c:  18 bf ff b1  bgu  0xa0113ef0
a0114030:  96 10 00 19  mov  %i1, %o3
a0114034:  81 c7 e0 08  ret
a0114038:  81 e8 00 00  restore
