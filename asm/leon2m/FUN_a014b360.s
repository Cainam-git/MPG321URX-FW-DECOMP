# leon2m FUN_a014b360 0xa014b360-0xa014b3fc (156 bytes)
a014b360:  9d e3 bf 98  save  %sp, -104, %sp
a014b364:  7f ff 67 8d  call  0xa0125198
a014b368:  90 0e 20 ff  and  %i0, 0xff, %o0
a014b36c:  7f ff db ab  call  0xa0142218
a014b370:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b374:  7f ff db 94  call  0xa01421c4
a014b378:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b37c:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b380:  80 a2 20 61  cmp  %o0, 0x61
a014b384:  02 80 00 1a  be  0xa014b3ec
a014b388:  9a 10 20 00  clr  %o5
a014b38c:  80 a2 20 61  cmp  %o0, 0x61
a014b390:  04 80 00 08  ble  0xa014b3b0
a014b394:  98 0b 60 03  and  %o5, 3, %o4
a014b398:  80 a2 20 71  cmp  %o0, 0x71
a014b39c:  02 80 00 16  be  0xa014b3f4
a014b3a0:  80 a2 20 81  cmp  %o0, 0x81
a014b3a4:  22 80 00 02  be,a   0xa014b3ac
a014b3a8:  9a 10 20 03  mov  3, %o5
a014b3ac:  98 0b 60 03  and  %o5, 3, %o4
a014b3b0:  97 2b 20 03  sll  %o4, 3, %o3
a014b3b4:  94 02 c0 0c  add  %o3, %o4, %o2
a014b3b8:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a014b3bc:  90 02 80 0a  add  %o2, %o2, %o0
a014b3c0:  9a 12 61 16  or  %o1, 0x116, %o5
a014b3c4:  82 02 00 0d  add  %o0, %o5, %g1
a014b3c8:  7f ff 67 57  call  0xa0125124
a014b3cc:  d0 08 60 10  ldub  [ %g1 + 0x10 ], %o0
a014b3d0:  b3 2e 60 10  sll  %i1, 0x10, %i1
a014b3d4:  b7 2e e0 10  sll  %i3, 0x10, %i3
a014b3d8:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014b3dc:  b3 36 60 10  srl  %i1, 0x10, %i1
a014b3e0:  b7 36 e0 10  srl  %i3, 0x10, %i3
a014b3e4:  7f ff 85 0a  call  0xa012c80c
a014b3e8:  99 e8 20 01  restore  %g0, 1, %o4
a014b3ec:  10 bf ff f0  b  0xa014b3ac
a014b3f0:  9a 10 20 01  mov  1, %o5
a014b3f4:  10 bf ff ee  b  0xa014b3ac
a014b3f8:  9a 10 20 02  mov  2, %o5
