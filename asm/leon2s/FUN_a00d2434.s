# leon2s FUN_a00d2434 0xa00d2434-0xa00d24ac (120 bytes)
a00d2434:  9d e3 bf 90  save  %sp, -112, %sp
a00d2438:  21 34 00 4f  sethi  %hi(0xd0013c00), %l0
a00d243c:  90 14 23 10  or  %l0, 0x310, %o0	! 0xd0013f10
a00d2440:  80 8e 20 ff  btst  0xff, %i0
a00d2444:  c0 27 bf f4  clr  [ %fp + -12 ]
a00d2448:  12 80 00 0c  bne  0xa00d2478
a00d244c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00d2450:  40 3a 7c 36  call  0xa0f71528
a00d2454:  01 00 00 00  nop
a00d2458:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d245c:  90 07 bf f4  add  %fp, -12, %o0
a00d2460:  96 10 00 19  mov  %i1, %o3
a00d2464:  92 10 20 00  clr  %o1
a00d2468:  40 3a 7c 14  call  0xa0f714b8
a00d246c:  94 10 20 00  clr  %o2
a00d2470:  10 80 00 0b  b  0xa00d249c
a00d2474:  90 14 23 10  or  %l0, 0x310, %o0
a00d2478:  40 3a 7c 2c  call  0xa0f71528
a00d247c:  90 14 23 10  or  %l0, 0x310, %o0
a00d2480:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d2484:  90 07 bf f4  add  %fp, -12, %o0
a00d2488:  96 10 00 19  mov  %i1, %o3
a00d248c:  92 10 20 01  mov  1, %o1
a00d2490:  40 3a 7c 0a  call  0xa0f714b8
a00d2494:  94 10 20 01  mov  1, %o2
a00d2498:  90 14 23 10  or  %l0, 0x310, %o0
a00d249c:  40 3a 7c 26  call  0xa0f71534
a00d24a0:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d24a4:  81 c7 e0 08  ret
a00d24a8:  91 e8 20 01  restore  %g0, 1, %o0
