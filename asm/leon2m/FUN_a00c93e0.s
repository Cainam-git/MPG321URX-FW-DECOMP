# leon2m FUN_a00c93e0 0xa00c93e0-0xa00c9470 (144 bytes)
a00c93e0:  9d e3 bf 98  save  %sp, -104, %sp
a00c93e4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c93e8:  80 a6 20 02  cmp  %i0, 2
a00c93ec:  02 80 00 19  be  0xa00c9450
a00c93f0:  80 a6 20 03  cmp  %i0, 3
a00c93f4:  02 80 00 1a  be  0xa00c945c
a00c93f8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c93fc:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c9400:  94 08 60 ff  and  %g1, 0xff, %o2
a00c9404:  80 a2 a0 31  cmp  %o2, 0x31
a00c9408:  12 80 00 18  bne  0xa00c9468
a00c940c:  82 10 20 ff  mov  0xff, %g1
a00c9410:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c9414:  da 0a e2 af  ldub  [ %o3 + 0x2af ], %o5	! 0xa802d2af
a00c9418:  80 a3 60 00  cmp  %o5, 0
a00c941c:  02 80 00 13  be  0xa00c9468
a00c9420:  01 00 00 00  nop
a00c9424:  40 00 3f ca  call  0xa00d934c
a00c9428:  01 00 00 00  nop
a00c942c:  7f ff c5 90  call  0xa00baa6c
a00c9430:  90 10 00 18  mov  %i0, %o0
a00c9434:  7f ff c5 47  call  0xa00ba950
a00c9438:  90 10 00 18  mov  %i0, %o0
a00c943c:  90 10 00 18  mov  %i0, %o0
a00c9440:  7f ff c5 d0  call  0xa00bab80
a00c9444:  92 10 20 06  mov  6, %o1
a00c9448:  10 80 00 08  b  0xa00c9468
a00c944c:  82 10 20 00  clr  %g1
a00c9450:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c9454:  10 bf ff eb  b  0xa00c9400
a00c9458:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c945c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c9460:  10 bf ff e8  b  0xa00c9400
a00c9464:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c9468:  81 c7 e0 08  ret
a00c946c:  91 e8 00 01  restore  %g0, %g1, %o0
