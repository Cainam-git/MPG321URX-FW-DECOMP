# leon2m FUN_a00ae288 0xa00ae288-0xa00ae39c (276 bytes)
a00ae288:  9d e3 bf 90  save  %sp, -112, %sp
a00ae28c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ae290:  92 14 62 90  or  %l1, 0x290, %o1	! 0xa802d290
a00ae294:  d0 0a 61 a3  ldub  [ %o1 + 0x1a3 ], %o0
a00ae298:  82 02 00 08  add  %o0, %o0, %g1
a00ae29c:  a0 00 60 04  add  %g1, 4, %l0
a00ae2a0:  90 10 20 00  clr  %o0
a00ae2a4:  92 10 20 00  clr  %o1
a00ae2a8:  94 10 20 00  clr  %o2
a00ae2ac:  40 00 17 09  call  0xa00b3ed0
a00ae2b0:  96 10 20 00  clr  %o3
a00ae2b4:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00ae2b8:  90 10 20 00  clr  %o0
a00ae2bc:  92 10 20 00  clr  %o1
a00ae2c0:  94 10 27 92  mov  0x792, %o2
a00ae2c4:  96 10 20 03  mov  3, %o3
a00ae2c8:  98 10 20 0a  mov  0xa, %o4
a00ae2cc:  80 a4 20 0a  cmp  %l0, 0xa
a00ae2d0:  02 80 00 0a  be  0xa00ae2f8
a00ae2d4:  9a 10 20 02  mov  2, %o5
a00ae2d8:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae2dc:  90 10 20 00  clr  %o0
a00ae2e0:  92 10 20 00  clr  %o1
a00ae2e4:  94 10 27 92  mov  0x792, %o2
a00ae2e8:  96 10 20 03  mov  3, %o3
a00ae2ec:  98 10 00 10  mov  %l0, %o4
a00ae2f0:  10 80 00 0d  b  0xa00ae324
a00ae2f4:  9a 10 20 03  mov  3, %o5
a00ae2f8:  40 00 13 fb  call  0xa00b32e4
a00ae2fc:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae300:  96 10 20 11  mov  0x11, %o3
a00ae304:  d6 23 a0 5c  st  %o3, [ %sp + 0x5c ]
a00ae308:  15 00 00 0c  sethi  %hi(0x3000), %o2
a00ae30c:  94 12 a0 92  or  %o2, 0x92, %o2	! 0x3092
a00ae310:  90 10 20 01  mov  1, %o0
a00ae314:  92 10 20 00  clr  %o1
a00ae318:  96 10 20 03  mov  3, %o3
a00ae31c:  98 10 20 0c  mov  0xc, %o4
a00ae320:  9a 10 20 01  mov  1, %o5
a00ae324:  40 00 13 f0  call  0xa00b32e4
a00ae328:  01 00 00 00  nop
a00ae32c:  98 10 00 10  mov  %l0, %o4
a00ae330:  90 10 20 00  clr  %o0
a00ae334:  92 10 20 00  clr  %o1
a00ae338:  94 10 27 92  mov  0x792, %o2
a00ae33c:  96 10 20 12  mov  0x12, %o3
a00ae340:  9a 10 20 03  mov  3, %o5
a00ae344:  40 00 13 e8  call  0xa00b32e4
a00ae348:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae34c:  a0 14 62 90  or  %l1, 0x290, %l0
a00ae350:  d8 0c 21 a3  ldub  [ %l0 + 0x1a3 ], %o4
a00ae354:  1b 15 55 55  sethi  %hi(0x55555400), %o5
a00ae358:  90 03 20 02  add  %o4, 2, %o0
a00ae35c:  96 13 61 56  or  %o5, 0x156, %o3
a00ae360:  80 5a 00 0b  smul  %o0, %o3, %g0
a00ae364:  95 40 00 00  rd  %y, %o2
a00ae368:  92 02 80 0a  add  %o2, %o2, %o1
a00ae36c:  82 02 40 0a  add  %o1, %o2, %g1
a00ae370:  a2 22 00 01  sub  %o0, %g1, %l1
a00ae374:  e2 2c 21 a3  stb  %l1, [ %l0 + 0x1a3 ]
a00ae378:  90 0c 60 ff  and  %l1, 0xff, %o0
a00ae37c:  7f ff fd 3c  call  0xa00ad86c
a00ae380:  92 10 20 01  mov  1, %o1
a00ae384:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00ae388:  de 0b 60 8e  ldub  [ %o5 + 0x8e ], %o7	! 0xa802b08e
a00ae38c:  98 13 e0 02  or  %o7, 2, %o4
a00ae390:  d8 2b 60 8e  stb  %o4, [ %o5 + 0x8e ]
a00ae394:  81 c7 e0 08  ret
a00ae398:  81 e8 00 00  restore
