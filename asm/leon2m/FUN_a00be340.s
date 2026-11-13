# leon2m FUN_a00be340 0xa00be340-0xa00be38c (76 bytes)
a00be340:  9d e3 bf 98  save  %sp, -104, %sp
a00be344:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00be348:  d4 02 e0 84  ld  [ %o3 + 0x84 ], %o2	! 0xa802d484
a00be34c:  91 32 a0 1f  srl  %o2, 0x1f, %o0
a00be350:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be354:  82 12 60 78  or  %o1, 0x78, %g1	! 0xa802d078
a00be358:  9a 02 20 30  add  %o0, 0x30, %o5
a00be35c:  98 10 20 30  mov  0x30, %o4
a00be360:  da 28 60 09  stb  %o5, [ %g1 + 9 ]
a00be364:  d8 28 60 08  stb  %o4, [ %g1 + 8 ]
a00be368:  d8 28 60 07  stb  %o4, [ %g1 + 7 ]
a00be36c:  7f ff f2 34  call  0xa00bac3c
a00be370:  90 10 20 6e  mov  0x6e, %o0
a00be374:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be378:  7f ff f1 76  call  0xa00ba950
a00be37c:  90 10 00 18  mov  %i0, %o0
a00be380:  7f ff f2 19  call  0xa00babe4
a00be384:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be388:  01 00 00 00  nop
