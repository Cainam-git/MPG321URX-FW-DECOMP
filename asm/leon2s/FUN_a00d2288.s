# leon2s FUN_a00d2288 0xa00d2288-0xa00d2300 (120 bytes)
a00d2288:  9d e3 bf 90  save  %sp, -112, %sp
a00d228c:  21 34 00 4f  sethi  %hi(0xd0013c00), %l0
a00d2290:  90 14 23 e0  or  %l0, 0x3e0, %o0	! 0xd0013fe0
a00d2294:  80 8e 20 ff  btst  0xff, %i0
a00d2298:  c0 27 bf f4  clr  [ %fp + -12 ]
a00d229c:  12 80 00 0c  bne  0xa00d22cc
a00d22a0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00d22a4:  40 3a 7c a1  call  0xa0f71528
a00d22a8:  01 00 00 00  nop
a00d22ac:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d22b0:  90 07 bf f4  add  %fp, -12, %o0
a00d22b4:  96 10 00 19  mov  %i1, %o3
a00d22b8:  92 10 20 1f  mov  0x1f, %o1
a00d22bc:  40 3a 7c 7f  call  0xa0f714b8
a00d22c0:  94 10 20 1f  mov  0x1f, %o2
a00d22c4:  10 80 00 0b  b  0xa00d22f0
a00d22c8:  90 14 23 e0  or  %l0, 0x3e0, %o0
a00d22cc:  40 3a 7c 97  call  0xa0f71528
a00d22d0:  90 14 23 e0  or  %l0, 0x3e0, %o0
a00d22d4:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d22d8:  90 07 bf f4  add  %fp, -12, %o0
a00d22dc:  96 10 00 19  mov  %i1, %o3
a00d22e0:  92 10 20 1e  mov  0x1e, %o1
a00d22e4:  40 3a 7c 75  call  0xa0f714b8
a00d22e8:  94 10 20 1e  mov  0x1e, %o2
a00d22ec:  90 14 23 e0  or  %l0, 0x3e0, %o0
a00d22f0:  40 3a 7c 91  call  0xa0f71534
a00d22f4:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d22f8:  81 c7 e0 08  ret
a00d22fc:  91 e8 20 01  restore  %g0, 1, %o0
