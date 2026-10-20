# leon2m FUN_a014d474 0xa014d474-0xa014d504 (144 bytes)
a014d474:  9d e3 bf 98  save  %sp, -104, %sp
a014d478:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014d47c:  80 a6 20 01  cmp  %i0, 1
a014d480:  02 80 00 0b  be  0xa014d4ac
a014d484:  90 10 20 01  mov  1, %o0
a014d488:  80 a6 20 01  cmp  %i0, 1
a014d48c:  04 80 00 19  ble  0xa014d4f0
a014d490:  80 a6 20 02  cmp  %i0, 2
a014d494:  02 80 00 06  be  0xa014d4ac
a014d498:  90 10 20 02  mov  2, %o0
a014d49c:  80 a6 20 03  cmp  %i0, 3
a014d4a0:  02 80 00 03  be  0xa014d4ac
a014d4a4:  90 10 20 03  mov  3, %o0
a014d4a8:  90 10 3f ff  mov  -1, %o0
a014d4ac:  90 0a 20 ff  and  %o0, 0xff, %o0
a014d4b0:  80 a2 20 03  cmp  %o0, 3
a014d4b4:  38 80 00 07  bgu,a   0xa014d4d0
a014d4b8:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a014d4bc:  7f ff be 3b  call  0xa013cda8
a014d4c0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a014d4c4:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014d4c8:  7f fe ef eb  call  0xa0109474
a014d4cc:  81 e8 00 00  restore
a014d4d0:  7f fe 47 28  call  0xa00df170
a014d4d4:  90 12 21 d8  or  %o0, 0x1d8, %o0
a014d4d8:  7f ff be 34  call  0xa013cda8
a014d4dc:  90 10 20 00  clr  %o0
a014d4e0:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014d4e4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a014d4e8:  7f fe ef e3  call  0xa0109474
a014d4ec:  81 e8 00 00  restore
a014d4f0:  80 a6 20 00  cmp  %i0, 0
a014d4f4:  02 bf ff ee  be  0xa014d4ac
a014d4f8:  90 10 20 00  clr  %o0
a014d4fc:  10 bf ff ec  b  0xa014d4ac
a014d500:  90 10 3f ff  mov  -1, %o0
