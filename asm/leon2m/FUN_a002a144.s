# leon2m FUN_a002a144 0xa002a144-0xa002a25c (280 bytes)
a002a144:  9d e3 bf 98  save  %sp, -104, %sp
a002a148:  17 27 c0 00  sethi  %hi(0x9f000000), %o3
a002a14c:  90 12 e0 90  or  %o3, 0x90, %o0	! 0x9f000090
a002a150:  92 10 20 00  clr  %o1
a002a154:  40 00 08 45  call  0xa002c268
a002a158:  94 10 21 00  mov  0x100, %o2
a002a15c:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a002a160:  92 10 21 00  mov  0x100, %o1
a002a164:  94 10 21 00  mov  0x100, %o2
a002a168:  40 00 08 40  call  0xa002c268
a002a16c:  90 14 60 28  or  %l1, 0x28, %o0
a002a170:  40 00 08 38  call  0xa002c250
a002a174:  90 14 60 8c  or  %l1, 0x8c, %o0
a002a178:  a4 10 00 08  mov  %o0, %l2
a002a17c:  40 00 08 35  call  0xa002c250
a002a180:  90 14 60 54  or  %l1, 0x54, %o0
a002a184:  a0 2c 80 08  andn  %l2, %o0, %l0
a002a188:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a002a18c:  92 12 a3 ff  or  %o2, 0x3ff, %o1	! 0xffff
a002a190:  91 32 20 10  srl  %o0, 0x10, %o0
a002a194:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a002a198:  a4 0a 00 09  and  %o0, %o1, %l2
a002a19c:  a0 0c 00 09  and  %l0, %o1, %l0
a002a1a0:  b0 10 61 70  or  %g1, 0x170, %i0
a002a1a4:  b2 10 20 00  clr  %i1
a002a1a8:  98 10 20 01  mov  1, %o4
a002a1ac:  b5 2b 00 19  sll  %o4, %i1, %i2
a002a1b0:  80 8e 80 10  btst  %i2, %l0
a002a1b4:  22 80 00 0f  be,a   0xa002a1f0
a002a1b8:  b2 06 60 01  inc  %i1
a002a1bc:  c2 06 22 00  ld  [ %i0 + 0x200 ], %g1
a002a1c0:  80 a0 60 00  cmp  %g1, 0
a002a1c4:  22 80 00 0b  be,a   0xa002a1f0
a002a1c8:  b2 06 60 01  inc  %i1
a002a1cc:  92 10 00 1a  mov  %i2, %o1
a002a1d0:  80 8e 80 12  btst  %i2, %l2
a002a1d4:  02 80 00 1b  be  0xa002a240
a002a1d8:  90 14 60 8c  or  %l1, 0x8c, %o0
a002a1dc:  9f c0 40 00  call  %g1
a002a1e0:  b2 06 60 01  inc  %i1
a002a1e4:  92 10 00 1a  mov  %i2, %o1
a002a1e8:  40 00 08 1d  call  0xa002c25c
a002a1ec:  90 14 60 8c  or  %l1, 0x8c, %o0
a002a1f0:  b0 06 20 04  add  %i0, 4, %i0
a002a1f4:  80 a6 60 01  cmp  %i1, 1
a002a1f8:  08 bf ff ed  bleu  0xa002a1ac
a002a1fc:  98 10 20 01  mov  1, %o4
a002a200:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a002a204:  90 14 60 34  or  %l1, 0x34, %o0	! 0x9f020034
a002a208:  40 00 08 15  call  0xa002c25c
a002a20c:  92 10 21 00  mov  0x100, %o1
a002a210:  31 27 c0 00  sethi  %hi(0x9f000000), %i0
a002a214:  90 16 20 9c  or  %i0, 0x9c, %o0	! 0x9f00009c
a002a218:  40 00 08 11  call  0xa002c25c
a002a21c:  92 10 21 00  mov  0x100, %o1
a002a220:  90 14 60 28  or  %l1, 0x28, %o0
a002a224:  92 10 20 00  clr  %o1
a002a228:  40 00 08 10  call  0xa002c268
a002a22c:  94 10 21 00  mov  0x100, %o2
a002a230:  b0 16 20 90  or  %i0, 0x90, %i0
a002a234:  b2 10 21 00  mov  0x100, %i1
a002a238:  40 00 08 0c  call  0xa002c268
a002a23c:  95 e8 21 00  restore  %g0, 0x100, %o2
a002a240:  40 00 08 07  call  0xa002c25c
a002a244:  b2 06 60 01  inc  %i1
a002a248:  da 06 22 00  ld  [ %i0 + 0x200 ], %o5
a002a24c:  9f c3 40 00  call  %o5
a002a250:  b0 06 20 04  add  %i0, 4, %i0
a002a254:  10 bf ff e9  b  0xa002a1f8
a002a258:  80 a6 60 01  cmp  %i1, 1
