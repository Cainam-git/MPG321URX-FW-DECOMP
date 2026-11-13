# leon2s FUN_a00d31f8 0xa00d31f8-0xa00d3364 (364 bytes)
a00d31f8:  9d e3 bf 90  save  %sp, -112, %sp
a00d31fc:  23 2a 01 e3  sethi  %hi(0xa8078c00), %l1
a00d3200:  c2 0c 60 30  ldub  [ %l1 + 0x30 ], %g1	! 0xa8078c30
a00d3204:  80 88 60 08  btst  8, %g1
a00d3208:  02 80 00 55  be  0xa00d335c
a00d320c:  80 88 60 04  btst  4, %g1
a00d3210:  12 80 00 0d  bne  0xa00d3244
a00d3214:  03 2a 01 de  sethi  %hi(0xa8077800), %g1
a00d3218:  94 10 62 08  or  %g1, 0x208, %o2	! 0xa8077a08
a00d321c:  03 2a 01 e0  sethi  %hi(0xa8078000), %g1
a00d3220:  96 10 63 de  or  %g1, 0x3de, %o3	! 0xa80783de
a00d3224:  98 10 20 00  clr  %o4
a00d3228:  9a 03 00 0c  add  %o4, %o4, %o5
a00d322c:  98 03 20 01  inc  %o4
a00d3230:  c2 12 c0 0d  lduh  [ %o3 + %o5 ], %g1
a00d3234:  80 a3 21 00  cmp  %o4, 0x100
a00d3238:  08 bf ff fc  bleu  0xa00d3228
a00d323c:  c2 32 80 0d  sth  %g1, [ %o2 + %o5 ]
a00d3240:  30 80 00 0b  b,a   0xa00d326c
a00d3244:  94 10 62 08  or  %g1, 0x208, %o2
a00d3248:  03 27 c6 c2  sethi  %hi(0x9f1b0800), %g1
a00d324c:  96 10 60 00  mov  %g1, %o3	! 0x9f1b0800
a00d3250:  98 10 20 00  clr  %o4
a00d3254:  9a 03 00 0c  add  %o4, %o4, %o5
a00d3258:  98 03 20 01  inc  %o4
a00d325c:  c2 12 c0 0d  lduh  [ %o3 + %o5 ], %g1
a00d3260:  80 a3 21 00  cmp  %o4, 0x100
a00d3264:  08 bf ff fc  bleu  0xa00d3254
a00d3268:  c2 32 80 0d  sth  %g1, [ %o2 + %o5 ]
a00d326c:  7f ff fc 43  call  0xa00d2378
a00d3270:  90 10 21 00  mov  0x100, %o0
a00d3274:  98 10 20 00  clr  %o4
a00d3278:  92 10 20 00  clr  %o1
a00d327c:  94 10 20 00  clr  %o2
a00d3280:  96 10 20 00  clr  %o3
a00d3284:  7f ff ff a4  call  0xa00d3114
a00d3288:  90 10 20 00  clr  %o0
a00d328c:  21 34 00 4f  sethi  %hi(0xd0013c00), %l0
a00d3290:  40 3a 78 a6  call  0xa0f71528
a00d3294:  90 14 23 6c  or  %l0, 0x36c, %o0	! 0xd0013f6c
a00d3298:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d329c:  94 10 20 1e  mov  0x1e, %o2
a00d32a0:  96 10 20 00  clr  %o3
a00d32a4:  90 07 bf f4  add  %fp, -12, %o0
a00d32a8:  40 3a 78 84  call  0xa0f714b8
a00d32ac:  92 10 20 1f  mov  0x1f, %o1
a00d32b0:  90 14 23 6c  or  %l0, 0x36c, %o0
a00d32b4:  40 3a 78 a0  call  0xa0f71534
a00d32b8:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d32bc:  94 10 20 1e  mov  0x1e, %o2
a00d32c0:  96 10 20 03  mov  3, %o3
a00d32c4:  90 07 bf f4  add  %fp, -12, %o0
a00d32c8:  40 3a 78 7c  call  0xa0f714b8
a00d32cc:  92 10 20 1f  mov  0x1f, %o1
a00d32d0:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d32d4:  40 3a 78 98  call  0xa0f71534
a00d32d8:  90 14 23 6c  or  %l0, 0x36c, %o0
a00d32dc:  40 3a 78 93  call  0xa0f71528
a00d32e0:  90 14 23 dc  or  %l0, 0x3dc, %o0
a00d32e4:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d32e8:  94 10 20 18  mov  0x18, %o2
a00d32ec:  96 10 20 01  mov  1, %o3
a00d32f0:  90 07 bf f4  add  %fp, -12, %o0
a00d32f4:  40 3a 78 71  call  0xa0f714b8
a00d32f8:  92 10 20 19  mov  0x19, %o1
a00d32fc:  90 14 23 dc  or  %l0, 0x3dc, %o0
a00d3300:  40 3a 78 8d  call  0xa0f71534
a00d3304:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d3308:  94 10 20 1e  mov  0x1e, %o2
a00d330c:  96 10 20 00  clr  %o3
a00d3310:  90 07 bf f4  add  %fp, -12, %o0
a00d3314:  40 3a 78 69  call  0xa0f714b8
a00d3318:  92 10 20 1f  mov  0x1f, %o1
a00d331c:  90 14 23 dc  or  %l0, 0x3dc, %o0
a00d3320:  40 3a 78 85  call  0xa0f71534
a00d3324:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d3328:  94 10 20 1e  mov  0x1e, %o2
a00d332c:  96 10 20 03  mov  3, %o3
a00d3330:  90 07 bf f4  add  %fp, -12, %o0
a00d3334:  40 3a 78 61  call  0xa0f714b8
a00d3338:  92 10 20 1f  mov  0x1f, %o1
a00d333c:  90 14 23 dc  or  %l0, 0x3dc, %o0
a00d3340:  40 3a 78 7d  call  0xa0f71534
a00d3344:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d3348:  7f ff fe 58  call  0xa00d2ca8
a00d334c:  01 00 00 00  nop
a00d3350:  c2 0c 60 30  ldub  [ %l1 + 0x30 ], %g1
a00d3354:  82 08 7f f7  and  %g1, -9, %g1
a00d3358:  c2 2c 60 30  stb  %g1, [ %l1 + 0x30 ]
a00d335c:  81 c7 e0 08  ret
a00d3360:  81 e8 00 00  restore
