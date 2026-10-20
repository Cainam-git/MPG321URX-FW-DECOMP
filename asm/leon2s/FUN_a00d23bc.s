# leon2s FUN_a00d23bc 0xa00d23bc-0xa00d2434 (120 bytes)
a00d23bc:  9d e3 bf 90  save  %sp, -112, %sp
a00d23c0:  21 34 00 4f  sethi  %hi(0xd0013c00), %l0
a00d23c4:  90 14 23 60  or  %l0, 0x360, %o0	! 0xd0013f60
a00d23c8:  80 8e 20 ff  btst  0xff, %i0
a00d23cc:  c0 27 bf f4  clr  [ %fp + -12 ]
a00d23d0:  12 80 00 0c  bne  0xa00d2400
a00d23d4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00d23d8:  40 3a 7c 54  call  0xa0f71528
a00d23dc:  01 00 00 00  nop
a00d23e0:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d23e4:  90 07 bf f4  add  %fp, -12, %o0
a00d23e8:  96 10 00 19  mov  %i1, %o3
a00d23ec:  92 10 20 1f  mov  0x1f, %o1
a00d23f0:  40 3a 7c 32  call  0xa0f714b8
a00d23f4:  94 10 20 1f  mov  0x1f, %o2
a00d23f8:  10 80 00 0b  b  0xa00d2424
a00d23fc:  90 14 23 60  or  %l0, 0x360, %o0
a00d2400:  40 3a 7c 4a  call  0xa0f71528
a00d2404:  90 14 23 70  or  %l0, 0x370, %o0
a00d2408:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d240c:  90 07 bf f4  add  %fp, -12, %o0
a00d2410:  96 10 00 19  mov  %i1, %o3
a00d2414:  92 10 20 1f  mov  0x1f, %o1
a00d2418:  40 3a 7c 28  call  0xa0f714b8
a00d241c:  94 10 20 1f  mov  0x1f, %o2
a00d2420:  90 14 23 70  or  %l0, 0x370, %o0
a00d2424:  40 3a 7c 44  call  0xa0f71534
a00d2428:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d242c:  81 c7 e0 08  ret
a00d2430:  91 e8 20 01  restore  %g0, 1, %o0
