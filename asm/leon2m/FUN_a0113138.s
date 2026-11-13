# leon2m FUN_a0113138 0xa0113138-0xa01131d4 (156 bytes)  [FUN_a01131cc = unreachable ret/restore tail, merged]
a0113138:  9d e3 bf 98  save  %sp, -104, %sp
a011313c:  25 33 c0 46  sethi  %hi(0xcf011800), %l2
a0113140:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0113144:  a2 10 20 00  clr  %l1
a0113148:  a0 10 20 00  clr  %l0
a011314c:  a8 10 20 01  mov  1, %l4
a0113150:  10 80 00 06  b  0xa0113168
a0113154:  a6 14 a2 00  or  %l2, 0x200, %l3
a0113158:  a0 0c 60 ff  and  %l1, 0xff, %l0
a011315c:  80 a4 20 04  cmp  %l0, 4
a0113160:  18 80 00 16  bgu  0xa01131b8
a0113164:  80 8e 20 20  btst  0x20, %i0
a0113168:  83 3e 00 10  sra  %i0, %l0, %g1
a011316c:  90 10 00 10  mov  %l0, %o0
a0113170:  92 10 20 00  clr  %o1
a0113174:  80 88 60 01  btst  1, %g1
a0113178:  02 bf ff f8  be  0xa0113158
a011317c:  a2 04 60 01  inc  %l1
a0113180:  67 fd ec 91  call  0x4008e3c4
a0113184:  01 00 00 00  nop
a0113188:  d4 04 80 00  ld  [ %l2 ], %o2
a011318c:  93 2d 00 10  sll  %l4, %l0, %o1
a0113190:  9a 12 80 09  or  %o2, %o1, %o5
a0113194:  da 24 80 00  st  %o5, [ %l2 ]
a0113198:  d0 04 c0 00  ld  [ %l3 ], %o0
a011319c:  98 12 00 09  or  %o0, %o1, %o4
a01131a0:  a0 0c 60 ff  and  %l1, 0xff, %l0
a01131a4:  d8 24 c0 00  st  %o4, [ %l3 ]
a01131a8:  80 a4 20 04  cmp  %l0, 4
a01131ac:  08 bf ff f0  bleu  0xa011316c
a01131b0:  83 3e 00 10  sra  %i0, %l0, %g1
a01131b4:  80 8e 20 20  btst  0x20, %i0
a01131b8:  02 80 00 04  be  0xa01131c8
a01131bc:  01 00 00 00  nop
a01131c0:  40 00 15 05  call  0xa01185d4
a01131c4:  81 e8 00 00  restore
a01131c8:  01 00 00 00  nop
a01131cc:  81 c7 e0 08  ret
a01131d0:  81 e8 00 00  restore
