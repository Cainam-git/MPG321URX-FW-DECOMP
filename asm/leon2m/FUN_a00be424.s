# leon2m FUN_a00be424 0xa00be424-0xa00be470 (76 bytes)
a00be424:  9d e3 bf 98  save  %sp, -104, %sp
a00be428:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00be42c:  d4 02 e0 6c  ld  [ %o3 + 0x6c ], %o2	! 0xa802d46c
a00be430:  91 32 a0 1f  srl  %o2, 0x1f, %o0
a00be434:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be438:  82 12 60 78  or  %o1, 0x78, %g1	! 0xa802d078
a00be43c:  9a 02 20 30  add  %o0, 0x30, %o5
a00be440:  98 10 20 30  mov  0x30, %o4
a00be444:  da 28 60 09  stb  %o5, [ %g1 + 9 ]
a00be448:  d8 28 60 08  stb  %o4, [ %g1 + 8 ]
a00be44c:  d8 28 60 07  stb  %o4, [ %g1 + 7 ]
a00be450:  7f ff f1 fb  call  0xa00bac3c
a00be454:  90 10 20 71  mov  0x71, %o0
a00be458:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be45c:  7f ff f1 3d  call  0xa00ba950
a00be460:  90 10 00 18  mov  %i0, %o0
a00be464:  7f ff f1 e0  call  0xa00babe4
a00be468:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be46c:  01 00 00 00  nop
