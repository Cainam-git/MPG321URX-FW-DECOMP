# leon2m FUN_a00d24e0 0xa00d24e0-0xa00d253c (92 bytes)
a00d24e0:  9d e3 bf 98  save  %sp, -104, %sp
a00d24e4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00d24e8:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00d24ec:  80 a0 60 00  cmp  %g1, 0
a00d24f0:  12 80 00 08  bne  0xa00d2510
a00d24f4:  9a 14 22 90  or  %l0, 0x290, %o5
a00d24f8:  d2 03 60 a8  ld  [ %o5 + 0xa8 ], %o1
a00d24fc:  90 0a 7f bf  and  %o1, -65, %o0
a00d2500:  40 01 4d 72  call  0xa0125ac8
a00d2504:  d0 23 60 a8  st  %o0, [ %o5 + 0xa8 ]
a00d2508:  10 80 00 07  b  0xa00d2524
a00d250c:  92 14 22 90  or  %l0, 0x290, %o1
a00d2510:  d6 03 60 a8  ld  [ %o5 + 0xa8 ], %o3
a00d2514:  94 12 e0 40  or  %o3, 0x40, %o2
a00d2518:  40 01 4d 65  call  0xa0125aac
a00d251c:  d4 23 60 a8  st  %o2, [ %o5 + 0xa8 ]
a00d2520:  92 14 22 90  or  %l0, 0x290, %o1
a00d2524:  90 10 20 30  mov  0x30, %o0
a00d2528:  94 10 20 00  clr  %o2
a00d252c:  40 01 e2 69  call  0xa014aed0
a00d2530:  96 10 21 fc  mov  0x1fc, %o3
a00d2534:  81 c7 e0 08  ret
a00d2538:  91 e8 20 e0  restore  %g0, 0xe0, %o0
