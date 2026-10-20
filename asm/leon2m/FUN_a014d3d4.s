# leon2m FUN_a014d3d4 0xa014d3d4-0xa014d474 (160 bytes)
a014d3d4:  9d e3 bf 98  save  %sp, -104, %sp
a014d3d8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014d3dc:  80 a6 20 01  cmp  %i0, 1
a014d3e0:  02 80 00 0b  be  0xa014d40c
a014d3e4:  82 10 20 01  mov  1, %g1
a014d3e8:  80 a6 20 01  cmp  %i0, 1
a014d3ec:  04 80 00 11  ble  0xa014d430
a014d3f0:  80 a6 20 02  cmp  %i0, 2
a014d3f4:  02 80 00 06  be  0xa014d40c
a014d3f8:  82 10 20 02  mov  2, %g1
a014d3fc:  80 a6 20 03  cmp  %i0, 3
a014d400:  02 80 00 03  be  0xa014d40c
a014d404:  82 10 20 03  mov  3, %g1
a014d408:  82 10 3f ff  mov  -1, %g1
a014d40c:  9a 08 60 ff  and  %g1, 0xff, %o5
a014d410:  80 a3 60 03  cmp  %o5, 3
a014d414:  08 80 00 0d  bleu  0xa014d448
a014d418:  9f 2b 60 04  sll  %o5, 4, %o7
a014d41c:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a014d420:  7f fe 47 54  call  0xa00df170
a014d424:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a014d428:  10 80 00 07  b  0xa014d444
a014d42c:  9a 10 20 00  clr  %o5
a014d430:  80 a6 20 00  cmp  %i0, 0
a014d434:  02 bf ff f6  be  0xa014d40c
a014d438:  82 10 20 00  clr  %g1
a014d43c:  10 bf ff f4  b  0xa014d40c
a014d440:  82 10 3f ff  mov  -1, %g1
a014d444:  9f 2b 60 04  sll  %o5, 4, %o7
a014d448:  98 23 c0 0d  sub  %o7, %o5, %o4
a014d44c:  17 2a 00 b7  sethi  %hi(0xa802dc00), %o3
a014d450:  95 2b 20 03  sll  %o4, 3, %o2
a014d454:  9a 12 e3 30  or  %o3, 0x330, %o5
a014d458:  d2 03 40 0a  ld  [ %o5 + %o2 ], %o1
a014d45c:  83 32 60 0c  srl  %o1, 0xc, %g1
a014d460:  7f ff cb 06  call  0xa0140078
a014d464:  90 08 60 0f  and  %g1, 0xf, %o0
a014d468:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014d46c:  81 c7 e0 08  ret
a014d470:  81 e8 00 00  restore
