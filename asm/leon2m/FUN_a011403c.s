# leon2m FUN_a011403c 0xa011403c-0xa01141fc (448 bytes)
a011403c:  9d e3 bf 98  save  %sp, -104, %sp
a0114040:  b4 0e a0 ff  and  %i2, 0xff, %i2
a0114044:  9a 10 00 18  mov  %i0, %o5
a0114048:  9e 10 00 19  mov  %i1, %o7
a011404c:  80 a6 a0 00  cmp  %i2, 0
a0114050:  08 80 00 69  bleu  0xa01141f4
a0114054:  96 10 20 00  clr  %o3
a0114058:  19 33 c0 47  sethi  %hi(0xcf011c00), %o4
a011405c:  a4 13 23 94  or  %o4, 0x394, %l2	! 0xcf011f94
a0114060:  a0 0e e0 ff  and  %i3, 0xff, %l0
a0114064:  92 10 00 1a  mov  %i2, %o1
a0114068:  90 10 20 80  mov  0x80, %o0
a011406c:  94 13 23 90  or  %o4, 0x390, %o2
a0114070:  a6 10 00 12  mov  %l2, %l3
a0114074:  a2 13 23 a4  or  %o4, 0x3a4, %l1
a0114078:  82 13 23 a0  or  %o4, 0x3a0, %g1
a011407c:  de 20 40 00  st  %o7, [ %g1 ]
a0114080:  bb 33 e0 08  srl  %o7, 8, %i5
a0114084:  fa 24 40 00  st  %i5, [ %l1 ]
a0114088:  b8 13 23 a8  or  %o4, 0x3a8, %i4
a011408c:  b5 33 e0 10  srl  %o7, 0x10, %i2
a0114090:  f4 27 00 00  st  %i2, [ %i4 ]
a0114094:  b6 13 23 ac  or  %o4, 0x3ac, %i3
a0114098:  b3 33 e0 18  srl  %o7, 0x18, %i1
a011409c:  f2 26 c0 00  st  %i1, [ %i3 ]
a01140a0:  b0 13 23 84  or  %o4, 0x384, %i0
a01140a4:  d0 26 00 00  st  %o0, [ %i0 ]
a01140a8:  82 13 23 8c  or  %o4, 0x38c, %g1
a01140ac:  d0 20 40 00  st  %o0, [ %g1 ]
a01140b0:  fa 02 80 00  ld  [ %o2 ], %i5
a01140b4:  80 a7 60 80  cmp  %i5, 0x80
a01140b8:  02 80 00 0b  be  0xa01140e4
a01140bc:  ba 10 3f ff  mov  -1, %i5
a01140c0:  ba 07 7f ff  add  %i5, -1, %i5
a01140c4:  b1 2f 60 10  sll  %i5, 0x10, %i0
a01140c8:  80 a6 20 00  cmp  %i0, 0
a01140cc:  02 80 00 07  be  0xa01140e8
a01140d0:  80 a4 20 01  cmp  %l0, 1
a01140d4:  f6 02 80 00  ld  [ %o2 ], %i3
a01140d8:  80 a6 e0 80  cmp  %i3, 0x80
a01140dc:  12 bf ff fa  bne  0xa01140c4
a01140e0:  ba 07 7f ff  add  %i5, -1, %i5
a01140e4:  80 a4 20 01  cmp  %l0, 1
a01140e8:  02 80 00 23  be  0xa0114174
a01140ec:  83 2a e0 10  sll  %o3, 0x10, %g1
a01140f0:  bb 30 60 10  srl  %g1, 0x10, %i5
a01140f4:  b7 2f 60 05  sll  %i5, 5, %i3
a01140f8:  b3 2f 60 15  sll  %i5, 0x15, %i1
a01140fc:  b5 36 60 10  srl  %i1, 0x10, %i2
a0114100:  b0 06 e0 20  add  %i3, 0x20, %i0
a0114104:  80 a6 80 18  cmp  %i2, %i0
a0114108:  16 80 00 13  bge  0xa0114154
a011410c:  b4 10 00 1b  mov  %i3, %i2
a0114110:  b2 10 00 12  mov  %l2, %i1
a0114114:  b7 2e a0 10  sll  %i2, 0x10, %i3
a0114118:  b7 36 e0 10  srl  %i3, 0x10, %i3
a011411c:  c2 06 40 00  ld  [ %i1 ], %g1
a0114120:  b8 06 c0 0d  add  %i3, %o5, %i4
a0114124:  c2 2f 20 03  stb  %g1, [ %i4 + 3 ]
a0114128:  fa 06 40 00  ld  [ %i1 ], %i5
a011412c:  fa 2f 20 02  stb  %i5, [ %i4 + 2 ]
a0114130:  c2 06 40 00  ld  [ %i1 ], %g1
a0114134:  b4 06 a0 04  add  %i2, 4, %i2
a0114138:  c2 2f 20 01  stb  %g1, [ %i4 + 1 ]
a011413c:  bb 2e a0 10  sll  %i2, 0x10, %i5
a0114140:  b9 37 60 10  srl  %i5, 0x10, %i4
a0114144:  c2 06 40 00  ld  [ %i1 ], %g1
a0114148:  80 a7 00 18  cmp  %i4, %i0
a011414c:  06 bf ff f2  bl  0xa0114114
a0114150:  c2 2e c0 0d  stb  %g1, [ %i3 + %o5 ]
a0114154:  b0 02 e0 01  add  %o3, 1, %i0
a0114158:  b3 2e 20 10  sll  %i0, 0x10, %i1
a011415c:  b5 36 60 10  srl  %i1, 0x10, %i2
a0114160:  80 a2 40 1a  cmp  %o1, %i2
a0114164:  9e 03 e0 01  inc  %o7
a0114168:  18 bf ff c4  bgu  0xa0114078
a011416c:  96 10 00 18  mov  %i0, %o3
a0114170:  30 80 00 21  b,a   0xa01141f4
a0114174:  bb 30 60 10  srl  %g1, 0x10, %i5
a0114178:  b3 2f 60 15  sll  %i5, 0x15, %i1
a011417c:  b9 2f 60 05  sll  %i5, 5, %i4
a0114180:  b5 36 60 10  srl  %i1, 0x10, %i2
a0114184:  b2 07 20 20  add  %i4, 0x20, %i1
a0114188:  80 a6 80 19  cmp  %i2, %i1
a011418c:  16 bf ff f2  bge  0xa0114154
a0114190:  b6 10 00 1c  mov  %i4, %i3
a0114194:  b4 10 00 13  mov  %l3, %i2
a0114198:  b1 2e e0 10  sll  %i3, 0x10, %i0
a011419c:  f8 06 80 00  ld  [ %i2 ], %i4
a01141a0:  83 36 20 10  srl  %i0, 0x10, %g1
a01141a4:  f8 28 40 0d  stb  %i4, [ %g1 + %o5 ]
a01141a8:  fa 06 80 00  ld  [ %i2 ], %i5
a01141ac:  82 00 40 0d  add  %g1, %o5, %g1
a01141b0:  fa 28 60 01  stb  %i5, [ %g1 + 1 ]
a01141b4:  f0 06 80 00  ld  [ %i2 ], %i0
a01141b8:  b6 06 e0 04  add  %i3, 4, %i3
a01141bc:  f0 28 60 02  stb  %i0, [ %g1 + 2 ]
a01141c0:  b9 2e e0 10  sll  %i3, 0x10, %i4
a01141c4:  b1 37 20 10  srl  %i4, 0x10, %i0
a01141c8:  fa 06 80 00  ld  [ %i2 ], %i5
a01141cc:  80 a6 00 19  cmp  %i0, %i1
a01141d0:  06 bf ff f2  bl  0xa0114198
a01141d4:  fa 28 60 03  stb  %i5, [ %g1 + 3 ]
a01141d8:  b0 02 e0 01  add  %o3, 1, %i0
a01141dc:  b3 2e 20 10  sll  %i0, 0x10, %i1
a01141e0:  b5 36 60 10  srl  %i1, 0x10, %i2
a01141e4:  80 a2 40 1a  cmp  %o1, %i2
a01141e8:  9e 03 e0 01  inc  %o7
a01141ec:  18 bf ff a3  bgu  0xa0114078
a01141f0:  96 10 00 18  mov  %i0, %o3
a01141f4:  81 c7 e0 08  ret
a01141f8:  81 e8 00 00  restore
