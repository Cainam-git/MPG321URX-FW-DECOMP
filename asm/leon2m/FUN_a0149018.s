# leon2m FUN_a0149018 0xa0149018-0xa0149118 (84 bytes)
a0149018:  9d e3 bf 98  save  %sp, -104, %sp
a014901c:  90 10 20 10  mov  0x10, %o0
a0149020:  40 00 22 a1  call  0xa0151aa4
a0149024:  92 10 20 01  mov  1, %o1
a0149028:  90 10 20 20  mov  0x20, %o0
a014902c:  40 00 22 9e  call  0xa0151aa4
a0149030:  92 10 20 01  mov  1, %o1
a0149034:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a0149038:  d8 03 61 a0  ld  [ %o5 + 0x1a0 ], %o4	! 0xa802e1a0
a014903c:  92 0e 20 01  and  %i0, 1, %o1
a0149040:  15 00 80 00  sethi  %hi(0x2000000), %o2
a0149044:  b1 2a 60 19  sll  %o1, 0x19, %i0
a0149048:  90 2b 00 0a  andn  %o4, %o2, %o0
a014904c:  82 12 00 18  or  %o0, %i0, %g1
a0149050:  c2 23 61 a0  st  %g1, [ %o5 + 0x1a0 ]
a0149054:  b0 13 61 a0  or  %o5, 0x1a0, %i0
a0149058:  40 00 2a 46  call  0xa0153970
a014905c:  93 e8 20 00  restore  %g0, 0, %o1
a0149060:  01 00 00 00  nop
a0149064:  92 0a 60 ff  and  %o1, 0xff, %o1
a0149068:  80 a2 60 04  cmp  %o1, 4
a014906c:  38 80 00 0a  bgu,a   0xa0149094
a0149070:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149074:  83 2a 60 02  sll  %o1, 2, %g1
a0149078:  13 00 03 8d  sethi  %hi(0xe3400), %o1
a014907c:  9a 12 60 a0  or  %o1, 0xa0, %o5	! 0xe34a0
a0149080:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a0149084:  81 c3 00 00  jmp  %o4
a0149088:  01 00 00 00  nop
a014908c:  92 10 20 03  mov  3, %o1	! 0x3
a0149090:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149094:  80 a2 20 00  cmp  %o0, 0
a0149098:  02 80 00 08  be  0xa01490b8
a014909c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a01490a0:  80 a2 20 01  cmp  %o0, 1
a01490a4:  22 80 00 10  be,a   0xa01490e4
a01490a8:  90 13 23 d0  or  %o4, 0x3d0, %o0
a01490ac:  82 13 c0 00  mov  %o7, %g1
a01490b0:  7f ff e4 da  call  0xa0142418
a01490b4:  9e 10 40 00  mov  %g1, %o7
a01490b8:  98 13 23 d0  or  %o4, 0x3d0, %o4
a01490bc:  d6 03 20 04  ld  [ %o4 + 4 ], %o3
a01490c0:  9a 0a 60 0f  and  %o1, 0xf, %o5
a01490c4:  03 03 c0 00  sethi  %hi(0xf000000), %g1
a01490c8:  82 2a c0 01  andn  %o3, %g1, %g1
a01490cc:  9b 2b 60 18  sll  %o5, 0x18, %o5
a01490d0:  96 10 40 0d  or  %g1, %o5, %o3
a01490d4:  d6 23 20 04  st  %o3, [ %o4 + 4 ]
a01490d8:  82 13 c0 00  mov  %o7, %g1
a01490dc:  7f ff e4 cf  call  0xa0142418
a01490e0:  9e 10 40 00  mov  %g1, %o7
a01490e4:  d6 02 20 04  ld  [ %o0 + 4 ], %o3
a01490e8:  9a 0a 60 0f  and  %o1, 0xf, %o5
a01490ec:  03 00 3c 00  sethi  %hi(0xf00000), %g1
a01490f0:  82 2a c0 01  andn  %o3, %g1, %g1
a01490f4:  9b 2b 60 14  sll  %o5, 0x14, %o5
a01490f8:  82 10 40 0d  or  %g1, %o5, %g1
a01490fc:  c2 22 20 04  st  %g1, [ %o0 + 4 ]
a0149100:  90 10 20 01  mov  1, %o0
a0149104:  82 13 c0 00  mov  %o7, %g1
a0149108:  7f ff e4 c4  call  0xa0142418
a014910c:  9e 10 40 00  mov  %g1, %o7
a0149110:  10 bf ff e0  b  0xa0149090
a0149114:  92 10 20 00  clr  %o1
