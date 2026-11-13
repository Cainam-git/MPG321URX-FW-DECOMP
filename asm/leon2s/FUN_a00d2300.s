# leon2s FUN_a00d2300 0xa00d2300-0xa00d2378 (120 bytes)
a00d2300:  9d e3 bf 90  save  %sp, -112, %sp
a00d2304:  21 34 00 4f  sethi  %hi(0xd0013c00), %l0
a00d2308:  90 14 23 50  or  %l0, 0x350, %o0	! 0xd0013f50
a00d230c:  80 8e 20 ff  btst  0xff, %i0
a00d2310:  c0 27 bf f4  clr  [ %fp + -12 ]
a00d2314:  12 80 00 0c  bne  0xa00d2344
a00d2318:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00d231c:  40 3a 7c 83  call  0xa0f71528
a00d2320:  01 00 00 00  nop
a00d2324:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d2328:  90 07 bf f4  add  %fp, -12, %o0
a00d232c:  96 10 00 19  mov  %i1, %o3
a00d2330:  92 10 20 1f  mov  0x1f, %o1
a00d2334:  40 3a 7c 61  call  0xa0f714b8
a00d2338:  94 10 20 1f  mov  0x1f, %o2
a00d233c:  10 80 00 0b  b  0xa00d2368
a00d2340:  90 14 23 50  or  %l0, 0x350, %o0
a00d2344:  40 3a 7c 79  call  0xa0f71528
a00d2348:  90 14 23 50  or  %l0, 0x350, %o0
a00d234c:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d2350:  90 07 bf f4  add  %fp, -12, %o0
a00d2354:  96 10 00 19  mov  %i1, %o3
a00d2358:  92 10 20 1e  mov  0x1e, %o1
a00d235c:  40 3a 7c 57  call  0xa0f714b8
a00d2360:  94 10 20 1e  mov  0x1e, %o2
a00d2364:  90 14 23 50  or  %l0, 0x350, %o0
a00d2368:  40 3a 7c 73  call  0xa0f71534
a00d236c:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d2370:  81 c7 e0 08  ret
a00d2374:  91 e8 20 01  restore  %g0, 1, %o0
