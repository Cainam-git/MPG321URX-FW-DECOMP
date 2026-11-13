# leon2m FUN_a0144144 0xa0144144-0xa0144200 (188 bytes)
a0144144:  9d e3 bf 98  save  %sp, -104, %sp
a0144148:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014414c:  80 a6 20 01  cmp  %i0, 1
a0144150:  02 80 00 0b  be  0xa014417c
a0144154:  98 10 20 01  mov  1, %o4
a0144158:  80 a6 20 01  cmp  %i0, 1
a014415c:  04 80 00 11  ble  0xa01441a0
a0144160:  80 a6 20 02  cmp  %i0, 2
a0144164:  02 80 00 06  be  0xa014417c
a0144168:  98 10 20 02  mov  2, %o4
a014416c:  80 a6 20 03  cmp  %i0, 3
a0144170:  02 80 00 03  be  0xa014417c
a0144174:  98 10 20 03  mov  3, %o4
a0144178:  98 10 3f ff  mov  -1, %o4
a014417c:  82 0b 20 ff  and  %o4, 0xff, %g1
a0144180:  80 a0 60 03  cmp  %g1, 3
a0144184:  08 80 00 0d  bleu  0xa01441b8
a0144188:  9b 28 60 04  sll  %g1, 4, %o5
a014418c:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0144190:  7f fe 6b f8  call  0xa00df170
a0144194:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a0144198:  10 80 00 07  b  0xa01441b4
a014419c:  82 10 20 00  clr  %g1
a01441a0:  80 a6 20 00  cmp  %i0, 0
a01441a4:  02 bf ff f6  be  0xa014417c
a01441a8:  98 10 20 00  clr  %o4
a01441ac:  10 bf ff f4  b  0xa014417c
a01441b0:  98 10 3f ff  mov  -1, %o4
a01441b4:  9b 28 60 04  sll  %g1, 4, %o5
a01441b8:  92 23 40 01  sub  %o5, %g1, %o1
a01441bc:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a01441c0:  b1 2a 60 03  sll  %o1, 3, %i0
a01441c4:  90 10 63 30  or  %g1, 0x330, %o0
a01441c8:  de 02 00 18  ld  [ %o0 + %i0 ], %o7
a01441cc:  99 33 e0 0c  srl  %o7, 0xc, %o4
a01441d0:  96 0b 20 0f  and  %o4, 0xf, %o3
a01441d4:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a01441d8:  92 5a e0 2a  smul  %o3, 0x2a, %o1
a01441dc:  9a 12 a2 24  or  %o2, 0x224, %o5
a01441e0:  82 02 40 0d  add  %o1, %o5, %g1
a01441e4:  7f ff f7 e1  call  0xa0142168
a01441e8:  d0 08 60 0a  ldub  [ %g1 + 0xa ], %o0
a01441ec:  7f ff 96 2e  call  0xa0129aa4
a01441f0:  90 0a 20 ff  and  %o0, 0xff, %o0
a01441f4:  b0 0a 20 ff  and  %o0, 0xff, %i0
a01441f8:  81 c7 e0 08  ret
a01441fc:  81 e8 00 00  restore
