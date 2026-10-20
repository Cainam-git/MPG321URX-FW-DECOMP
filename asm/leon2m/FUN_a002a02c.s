# leon2m FUN_a002a02c 0xa002a02c-0xa002a144 (280 bytes)
a002a02c:  9d e3 bf 98  save  %sp, -104, %sp
a002a030:  17 27 c0 00  sethi  %hi(0x9f000000), %o3
a002a034:  90 12 e0 90  or  %o3, 0x90, %o0	! 0x9f000090
a002a038:  92 10 20 00  clr  %o1
a002a03c:  40 00 08 8b  call  0xa002c268
a002a040:  94 10 20 80  mov  0x80, %o2
a002a044:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a002a048:  92 10 20 80  mov  0x80, %o1
a002a04c:  94 10 20 80  mov  0x80, %o2
a002a050:  40 00 08 86  call  0xa002c268
a002a054:  90 14 60 28  or  %l1, 0x28, %o0
a002a058:  40 00 08 7e  call  0xa002c250
a002a05c:  90 14 60 88  or  %l1, 0x88, %o0
a002a060:  a4 10 00 08  mov  %o0, %l2
a002a064:  40 00 08 7b  call  0xa002c250
a002a068:  90 14 60 50  or  %l1, 0x50, %o0
a002a06c:  a0 2c 80 08  andn  %l2, %o0, %l0
a002a070:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a002a074:  92 12 a3 ff  or  %o2, 0x3ff, %o1	! 0xffff
a002a078:  91 32 20 10  srl  %o0, 0x10, %o0
a002a07c:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a002a080:  a4 0a 00 09  and  %o0, %o1, %l2
a002a084:  a0 0c 00 09  and  %l0, %o1, %l0
a002a088:  b0 10 61 70  or  %g1, 0x170, %i0
a002a08c:  b2 10 20 00  clr  %i1
a002a090:  98 10 20 01  mov  1, %o4
a002a094:  b5 2b 00 19  sll  %o4, %i1, %i2
a002a098:  80 8e 80 10  btst  %i2, %l0
a002a09c:  22 80 00 0f  be,a   0xa002a0d8
a002a0a0:  b2 06 60 01  inc  %i1
a002a0a4:  c2 06 21 c0  ld  [ %i0 + 0x1c0 ], %g1
a002a0a8:  80 a0 60 00  cmp  %g1, 0
a002a0ac:  22 80 00 0b  be,a   0xa002a0d8
a002a0b0:  b2 06 60 01  inc  %i1
a002a0b4:  92 10 00 1a  mov  %i2, %o1
a002a0b8:  80 8e 80 12  btst  %i2, %l2
a002a0bc:  02 80 00 1b  be  0xa002a128
a002a0c0:  90 14 60 88  or  %l1, 0x88, %o0
a002a0c4:  9f c0 40 00  call  %g1
a002a0c8:  b2 06 60 01  inc  %i1
a002a0cc:  92 10 00 1a  mov  %i2, %o1
a002a0d0:  40 00 08 63  call  0xa002c25c
a002a0d4:  90 14 60 88  or  %l1, 0x88, %o0
a002a0d8:  b0 06 20 04  add  %i0, 4, %i0
a002a0dc:  80 a6 60 01  cmp  %i1, 1
a002a0e0:  08 bf ff ed  bleu  0xa002a094
a002a0e4:  98 10 20 01  mov  1, %o4
a002a0e8:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a002a0ec:  90 14 60 34  or  %l1, 0x34, %o0	! 0x9f020034
a002a0f0:  40 00 08 5b  call  0xa002c25c
a002a0f4:  92 10 20 80  mov  0x80, %o1
a002a0f8:  31 27 c0 00  sethi  %hi(0x9f000000), %i0
a002a0fc:  90 16 20 9c  or  %i0, 0x9c, %o0	! 0x9f00009c
a002a100:  40 00 08 57  call  0xa002c25c
a002a104:  92 10 20 80  mov  0x80, %o1
a002a108:  90 14 60 28  or  %l1, 0x28, %o0
a002a10c:  92 10 20 00  clr  %o1
a002a110:  40 00 08 56  call  0xa002c268
a002a114:  94 10 20 80  mov  0x80, %o2
a002a118:  b0 16 20 90  or  %i0, 0x90, %i0
a002a11c:  b2 10 20 80  mov  0x80, %i1
a002a120:  40 00 08 52  call  0xa002c268
a002a124:  95 e8 20 80  restore  %g0, 0x80, %o2
a002a128:  40 00 08 4d  call  0xa002c25c
a002a12c:  b2 06 60 01  inc  %i1
a002a130:  da 06 21 c0  ld  [ %i0 + 0x1c0 ], %o5
a002a134:  9f c3 40 00  call  %o5
a002a138:  b0 06 20 04  add  %i0, 4, %i0
a002a13c:  10 bf ff e9  b  0xa002a0e0
a002a140:  80 a6 60 01  cmp  %i1, 1
