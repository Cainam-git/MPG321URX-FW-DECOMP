# leon2m FUN_a014505c 0xa014505c-0xa014512c (208 bytes)
a014505c:  9d e3 bf 98  save  %sp, -104, %sp
a0145060:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0145064:  80 a6 20 01  cmp  %i0, 1
a0145068:  a0 10 20 00  clr  %l0
a014506c:  02 80 00 0b  be  0xa0145098
a0145070:  98 10 20 01  mov  1, %o4
a0145074:  80 a6 20 01  cmp  %i0, 1
a0145078:  04 80 00 25  ble  0xa014510c
a014507c:  80 a6 20 02  cmp  %i0, 2
a0145080:  02 80 00 06  be  0xa0145098
a0145084:  98 10 20 02  mov  2, %o4
a0145088:  80 a6 20 03  cmp  %i0, 3
a014508c:  02 80 00 03  be  0xa0145098
a0145090:  98 10 20 03  mov  3, %o4
a0145094:  98 10 3f ff  mov  -1, %o4
a0145098:  82 0b 20 ff  and  %o4, 0xff, %g1
a014509c:  80 a0 60 03  cmp  %g1, 3
a01450a0:  38 80 00 17  bgu,a   0xa01450fc
a01450a4:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a01450a8:  9b 28 60 04  sll  %g1, 4, %o5
a01450ac:  92 23 40 01  sub  %o5, %g1, %o1
a01450b0:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a01450b4:  90 10 63 30  or  %g1, 0x330, %o0	! 0xa802df30
a01450b8:  b1 2a 60 03  sll  %o1, 3, %i0
a01450bc:  de 02 00 18  ld  [ %o0 + %i0 ], %o7
a01450c0:  99 33 e0 0c  srl  %o7, 0xc, %o4
a01450c4:  96 0b 20 0f  and  %o4, 0xf, %o3
a01450c8:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a01450cc:  92 5a e0 2a  smul  %o3, 0x2a, %o1
a01450d0:  9a 12 a2 24  or  %o2, 0x224, %o5
a01450d4:  82 02 40 0d  add  %o1, %o5, %g1
a01450d8:  7f ff f4 24  call  0xa0142168
a01450dc:  d0 08 60 0a  ldub  [ %g1 + 0xa ], %o0
a01450e0:  7f ff f4 8b  call  0xa014230c
a01450e4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01450e8:  80 8a 20 ff  btst  0xff, %o0
a01450ec:  32 80 00 0d  bne,a   0xa0145120
a01450f0:  a0 10 20 01  mov  1, %l0
a01450f4:  10 80 00 0c  b  0xa0145124
a01450f8:  b0 0c 20 01  and  %l0, 1, %i0
a01450fc:  7f fe 68 1d  call  0xa00df170
a0145100:  90 12 21 d8  or  %o0, 0x1d8, %o0
a0145104:  10 bf ff e9  b  0xa01450a8
a0145108:  82 10 20 00  clr  %g1
a014510c:  80 a6 20 00  cmp  %i0, 0
a0145110:  02 bf ff e2  be  0xa0145098
a0145114:  98 10 20 00  clr  %o4
a0145118:  10 bf ff e0  b  0xa0145098
a014511c:  98 10 3f ff  mov  -1, %o4
a0145120:  b0 0c 20 01  and  %l0, 1, %i0
a0145124:  81 c7 e0 08  ret
a0145128:  81 e8 00 00  restore
