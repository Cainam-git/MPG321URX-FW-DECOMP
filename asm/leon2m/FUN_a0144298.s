# leon2m FUN_a0144298 0xa0144298-0xa0144350 (184 bytes)
a0144298:  9d e3 bf 98  save  %sp, -104, %sp
a014429c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01442a0:  80 a6 20 01  cmp  %i0, 1
a01442a4:  02 80 00 0b  be  0xa01442d0
a01442a8:  98 10 20 01  mov  1, %o4
a01442ac:  80 a6 20 01  cmp  %i0, 1
a01442b0:  04 80 00 11  ble  0xa01442f4
a01442b4:  80 a6 20 02  cmp  %i0, 2
a01442b8:  02 80 00 06  be  0xa01442d0
a01442bc:  98 10 20 02  mov  2, %o4
a01442c0:  80 a6 20 03  cmp  %i0, 3
a01442c4:  02 80 00 03  be  0xa01442d0
a01442c8:  98 10 20 03  mov  3, %o4
a01442cc:  98 10 3f ff  mov  -1, %o4
a01442d0:  82 0b 20 ff  and  %o4, 0xff, %g1
a01442d4:  80 a0 60 03  cmp  %g1, 3
a01442d8:  08 80 00 0d  bleu  0xa014430c
a01442dc:  9b 28 60 04  sll  %g1, 4, %o5
a01442e0:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a01442e4:  7f fe 6b a3  call  0xa00df170
a01442e8:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a01442ec:  10 80 00 07  b  0xa0144308
a01442f0:  82 10 20 00  clr  %g1
a01442f4:  80 a6 20 00  cmp  %i0, 0
a01442f8:  02 bf ff f6  be  0xa01442d0
a01442fc:  98 10 20 00  clr  %o4
a0144300:  10 bf ff f4  b  0xa01442d0
a0144304:  98 10 3f ff  mov  -1, %o4
a0144308:  9b 28 60 04  sll  %g1, 4, %o5
a014430c:  94 23 40 01  sub  %o5, %g1, %o2
a0144310:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a0144314:  99 2a a0 03  sll  %o2, 3, %o4
a0144318:  92 10 63 30  or  %g1, 0x330, %o1
a014431c:  d0 02 40 0c  ld  [ %o1 + %o4 ], %o0
a0144320:  b1 32 20 0c  srl  %o0, 0xc, %i0
a0144324:  9e 0e 20 0f  and  %i0, 0xf, %o7
a0144328:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a014432c:  94 5b e0 2a  smul  %o7, 0x2a, %o2
a0144330:  9a 12 e2 24  or  %o3, 0x224, %o5
a0144334:  82 02 80 0d  add  %o2, %o5, %g1
a0144338:  d2 08 60 09  ldub  [ %g1 + 9 ], %o1
a014433c:  98 1a 60 05  xor  %o1, 5, %o4
a0144340:  80 a0 00 0c  cmp  %g0, %o4
a0144344:  b0 60 3f ff  subx  %g0, -1, %i0
a0144348:  81 c7 e0 08  ret
a014434c:  81 e8 00 00  restore
