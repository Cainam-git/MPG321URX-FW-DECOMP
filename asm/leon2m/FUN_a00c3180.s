# leon2m FUN_a00c3180 0xa00c3180-0xa00c3380 (512 bytes)
a00c3180:  9d e3 bf 98  save  %sp, -104, %sp
a00c3184:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c3188:  80 a4 20 02  cmp  %l0, 2
a00c318c:  02 80 00 55  be  0xa00c32e0
a00c3190:  80 a4 20 03  cmp  %l0, 3
a00c3194:  02 80 00 5c  be  0xa00c3304
a00c3198:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c319c:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c31a0:  94 08 60 ff  and  %g1, 0xff, %o2
a00c31a4:  96 02 bf d0  add  %o2, -48, %o3
a00c31a8:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00c31ac:  80 a3 60 04  cmp  %o5, 4
a00c31b0:  18 80 00 72  bgu  0xa00c3378
a00c31b4:  b0 10 20 ff  mov  0xff, %i0
a00c31b8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c31bc:  31 2a 00 b3  sethi  %hi(0xa802cc00), %i0
a00c31c0:  d6 2b e3 ce  stb  %o3, [ %o7 + 0x3ce ]
a00c31c4:  d8 16 23 f8  lduh  [ %i0 + 0x3f8 ], %o4
a00c31c8:  17 00 00 18  sethi  %hi(0x6000), %o3
a00c31cc:  80 8a c0 0c  btst  %o3, %o4
a00c31d0:  02 80 00 47  be  0xa00c32ec
a00c31d4:  01 00 00 00  nop
a00c31d8:  80 a4 20 02  cmp  %l0, 2
a00c31dc:  02 80 00 24  be  0xa00c326c
a00c31e0:  80 a4 20 03  cmp  %l0, 3
a00c31e4:  02 80 00 4b  be  0xa00c3310
a00c31e8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c31ec:  94 12 e0 78  or  %o3, 0x78, %o2	! 0xa802d078
a00c31f0:  9e 10 20 30  mov  0x30, %o7
a00c31f4:  90 10 20 35  mov  0x35, %o0
a00c31f8:  b0 10 20 36  mov  0x36, %i0
a00c31fc:  98 10 20 2b  mov  0x2b, %o4
a00c3200:  9a 10 20 0d  mov  0xd, %o5
a00c3204:  d0 2a e0 78  stb  %o0, [ %o3 + 0x78 ]
a00c3208:  f0 2a a0 01  stb  %i0, [ %o2 + 1 ]
a00c320c:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00c3210:  d8 2a a0 04  stb  %o4, [ %o2 + 4 ]
a00c3214:  da 2a a0 05  stb  %o5, [ %o2 + 5 ]
a00c3218:  80 a4 20 02  cmp  %l0, 2
a00c321c:  02 80 00 21  be  0xa00c32a0
a00c3220:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00c3224:  80 a4 20 03  cmp  %l0, 3
a00c3228:  02 80 00 47  be  0xa00c3344
a00c322c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c3230:  b0 13 20 d0  or  %o4, 0xd0, %i0	! 0xa802d0d0
a00c3234:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c3238:  c0 2a e0 9c  clrb  [ %o3 + 0x9c ]	! 0xa802b09c
a00c323c:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00c3240:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00c3244:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00c3248:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00c324c:  80 a4 20 02  cmp  %l0, 2
a00c3250:  02 80 00 1d  be  0xa00c32c4
a00c3254:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00c3258:  80 a4 20 03  cmp  %l0, 3
a00c325c:  12 80 00 1d  bne  0xa00c32d0
a00c3260:  90 10 00 10  mov  %l0, %o0
a00c3264:  10 80 00 42  b  0xa00c336c
a00c3268:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c326c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c3270:  a0 12 a1 28  or  %o2, 0x128, %l0	! 0xa802d128
a00c3274:  90 10 20 30  mov  0x30, %o0
a00c3278:  98 10 20 35  mov  0x35, %o4
a00c327c:  9a 10 20 0d  mov  0xd, %o5
a00c3280:  92 10 20 36  mov  0x36, %o1
a00c3284:  82 10 20 2b  mov  0x2b, %g1
a00c3288:  d8 2a a1 28  stb  %o4, [ %o2 + 0x128 ]
a00c328c:  da 2c 20 05  stb  %o5, [ %l0 + 5 ]
a00c3290:  d2 2c 20 01  stb  %o1, [ %l0 + 1 ]
a00c3294:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00c3298:  c2 2c 20 04  stb  %g1, [ %l0 + 4 ]
a00c329c:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00c32a0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c32a4:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c32a8:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00c32ac:  c0 2a 60 9a  clrb  [ %o1 + 0x9a ]	! 0xa802b09a
a00c32b0:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c32b4:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c32b8:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c32bc:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c32c0:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c32c4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c32c8:  94 12 21 28  or  %o0, 0x128, %o2	! 0xa802d128
a00c32cc:  90 10 20 02  mov  2, %o0
a00c32d0:  40 02 15 46  call  0xa01487e8
a00c32d4:  92 10 20 06  mov  6, %o1
a00c32d8:  10 80 00 28  b  0xa00c3378
a00c32dc:  b0 10 20 00  clr  %i0
a00c32e0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c32e4:  10 bf ff af  b  0xa00c31a0
a00c32e8:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c32ec:  7f ff 37 3b  call  0xa0090fd8
a00c32f0:  01 00 00 00  nop
a00c32f4:  7f ff 37 2e  call  0xa0090fac
a00c32f8:  01 00 00 00  nop
a00c32fc:  10 bf ff b8  b  0xa00c31dc
a00c3300:  80 a4 20 02  cmp  %l0, 2
a00c3304:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c3308:  10 bf ff a6  b  0xa00c31a0
a00c330c:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c3310:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c3314:  9e 12 61 08  or  %o1, 0x108, %o7	! 0xa802d108
a00c3318:  b0 10 20 30  mov  0x30, %i0
a00c331c:  82 10 20 35  mov  0x35, %g1
a00c3320:  90 10 20 0d  mov  0xd, %o0
a00c3324:  a0 10 20 36  mov  0x36, %l0
a00c3328:  96 10 20 2b  mov  0x2b, %o3
a00c332c:  c2 2a 61 08  stb  %g1, [ %o1 + 0x108 ]
a00c3330:  d0 2b e0 05  stb  %o0, [ %o7 + 5 ]
a00c3334:  e0 2b e0 01  stb  %l0, [ %o7 + 1 ]
a00c3338:  f0 2b e0 03  stb  %i0, [ %o7 + 3 ]
a00c333c:  d6 2b e0 04  stb  %o3, [ %o7 + 4 ]
a00c3340:  f0 2b e0 02  stb  %i0, [ %o7 + 2 ]
a00c3344:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c3348:  9e 13 60 98  or  %o5, 0x98, %o7	! 0xa802d098
a00c334c:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c3350:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c3354:  c0 2b 60 98  clrb  [ %o5 + 0x98 ]
a00c3358:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00c335c:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00c3360:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00c3364:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00c3368:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c336c:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c3370:  10 bf ff d8  b  0xa00c32d0
a00c3374:  90 10 20 03  mov  3, %o0
a00c3378:  81 c7 e0 08  ret
a00c337c:  81 e8 00 00  restore
