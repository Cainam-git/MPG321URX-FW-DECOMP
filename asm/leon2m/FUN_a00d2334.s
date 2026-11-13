# leon2m FUN_a00d2334 0xa00d2334-0xa00d2384 (80 bytes)
a00d2334:  9d e3 bf 98  save  %sp, -104, %sp
a00d2338:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d233c:  94 10 20 00  clr  %o2
a00d2340:  96 10 20 00  clr  %o3
a00d2344:  90 12 62 74  or  %o1, 0x274, %o0
a00d2348:  82 02 c0 18  add  %o3, %i0, %g1
a00d234c:  98 02 c0 08  add  %o3, %o0, %o4
a00d2350:  94 02 a0 01  inc  %o2
a00d2354:  da 08 60 06  ldub  [ %g1 + 6 ], %o5
a00d2358:  96 0a a0 ff  and  %o2, 0xff, %o3
a00d235c:  80 a2 e0 0c  cmp  %o3, 0xc
a00d2360:  08 bf ff fa  bleu  0xa00d2348
a00d2364:  da 2b 20 03  stb  %o5, [ %o4 + 3 ]
a00d2368:  92 12 62 74  or  %o1, 0x274, %o1
a00d236c:  90 10 20 30  mov  0x30, %o0
a00d2370:  94 10 22 e0  mov  0x2e0, %o2
a00d2374:  40 01 e2 d7  call  0xa014aed0
a00d2378:  96 10 20 1c  mov  0x1c, %o3
a00d237c:  81 c7 e0 08  ret
a00d2380:  91 e8 20 e0  restore  %g0, 0xe0, %o0
