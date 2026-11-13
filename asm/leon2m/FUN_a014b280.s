# leon2m FUN_a014b280 0xa014b280-0xa014b360 (224 bytes)
a014b280:  9d e3 bf 98  save  %sp, -104, %sp
a014b284:  7f ff 67 c5  call  0xa0125198
a014b288:  90 0e 20 ff  and  %i0, 0xff, %o0
a014b28c:  7f ff db e3  call  0xa0142218
a014b290:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b294:  7f ff db cc  call  0xa01421c4
a014b298:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b29c:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b2a0:  80 a2 20 61  cmp  %o0, 0x61
a014b2a4:  02 80 00 2b  be  0xa014b350
a014b2a8:  82 10 20 00  clr  %g1
a014b2ac:  80 a2 20 61  cmp  %o0, 0x61
a014b2b0:  14 80 00 18  bg  0xa014b310
a014b2b4:  80 a2 20 71  cmp  %o0, 0x71
a014b2b8:  98 08 60 03  and  %g1, 3, %o4
a014b2bc:  97 2b 20 03  sll  %o4, 3, %o3
a014b2c0:  94 02 c0 0c  add  %o3, %o4, %o2
a014b2c4:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a014b2c8:  90 02 80 0a  add  %o2, %o2, %o0
a014b2cc:  82 12 61 16  or  %o1, 0x116, %g1
a014b2d0:  9a 02 00 01  add  %o0, %g1, %o5
a014b2d4:  7f ff 67 94  call  0xa0125124
a014b2d8:  d0 0b 60 10  ldub  [ %o5 + 0x10 ], %o0
a014b2dc:  80 8f 20 ff  btst  0xff, %i4
a014b2e0:  12 80 00 12  bne  0xa014b328
a014b2e4:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a014b2e8:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a014b2ec:  b8 13 61 a0  or  %o5, 0x1a0, %i4	! 0xa802e1a0
a014b2f0:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014b2f4:  9e 06 00 1c  add  %i0, %i4, %o7
a014b2f8:  f2 2b e0 1b  stb  %i1, [ %o7 + 0x1b ]
a014b2fc:  b7 2e e0 10  sll  %i3, 0x10, %i3
a014b300:  b7 36 e0 10  srl  %i3, 0x10, %i3
a014b304:  b2 10 20 00  clr  %i1
a014b308:  7f ff 85 41  call  0xa012c80c
a014b30c:  99 e8 20 00  restore  %g0, 0, %o4
a014b310:  02 80 00 12  be  0xa014b358
a014b314:  80 a2 20 81  cmp  %o0, 0x81
a014b318:  22 bf ff e8  be,a   0xa014b2b8
a014b31c:  82 10 20 03  mov  3, %g1
a014b320:  10 bf ff e7  b  0xa014b2bc
a014b324:  98 08 60 03  and  %g1, 3, %o4
a014b328:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014b32c:  82 12 61 a0  or  %o1, 0x1a0, %g1
a014b330:  b2 06 00 01  add  %i0, %g1, %i1
a014b334:  90 10 3f ff  mov  -1, %o0
a014b338:  d0 2e 60 1b  stb  %o0, [ %i1 + 0x1b ]
a014b33c:  b7 2e e0 10  sll  %i3, 0x10, %i3
a014b340:  b7 36 e0 10  srl  %i3, 0x10, %i3
a014b344:  b2 10 20 00  clr  %i1
a014b348:  7f ff 85 31  call  0xa012c80c
a014b34c:  99 e8 20 00  restore  %g0, 0, %o4
a014b350:  10 bf ff da  b  0xa014b2b8
a014b354:  82 10 20 01  mov  1, %g1
a014b358:  10 bf ff d8  b  0xa014b2b8
a014b35c:  82 10 20 02  mov  2, %g1
