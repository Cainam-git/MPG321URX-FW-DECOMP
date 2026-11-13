# leon2m FUN_a0098374 0xa0098374-0xa0098434 (192 bytes)
a0098374:  9d e3 bf 98  save  %sp, -104, %sp
a0098378:  40 01 04 14  call  0xa00d93c8
a009837c:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0098380:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0098384:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a0098388:  a0 12 22 90  or  %o0, 0x290, %l0
a009838c:  da 0b 60 54  ldub  [ %o5 + 0x54 ], %o5
a0098390:  d8 0c 20 2f  ldub  [ %l0 + 0x2f ], %o4
a0098394:  82 0b 60 ff  and  %o5, 0xff, %g1
a0098398:  80 a3 00 01  cmp  %o4, %g1
a009839c:  22 80 00 05  be,a   0xa00983b0
a00983a0:  da 04 63 ec  ld  [ %l1 + 0x3ec ], %o5
a00983a4:  40 01 07 ac  call  0xa00da254
a00983a8:  da 2c 20 2f  stb  %o5, [ %l0 + 0x2f ]
a00983ac:  da 04 63 ec  ld  [ %l1 + 0x3ec ], %o5
a00983b0:  98 03 7f 81  add  %o5, -127, %o4
a00983b4:  40 00 44 02  call  0xa00a93bc
a00983b8:  90 0b 20 ff  and  %o4, 0xff, %o0
a00983bc:  94 10 20 01  mov  1, %o2
a00983c0:  d2 0c 20 2f  ldub  [ %l0 + 0x2f ], %o1
a00983c4:  40 00 3f 5e  call  0xa00a813c
a00983c8:  90 10 20 01  mov  1, %o0
a00983cc:  d0 0c 20 2f  ldub  [ %l0 + 0x2f ], %o0
a00983d0:  40 00 44 a0  call  0xa00a9650
a00983d4:  92 10 20 00  clr  %o1
a00983d8:  90 10 20 01  mov  1, %o0
a00983dc:  40 00 44 23  call  0xa00a9468
a00983e0:  92 10 20 02  mov  2, %o1
a00983e4:  82 10 20 25  mov  0x25, %g1
a00983e8:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a00983ec:  90 10 20 02  mov  2, %o0
a00983f0:  40 00 43 07  call  0xa00a900c
a00983f4:  92 10 20 01  mov  1, %o1
a00983f8:  90 10 20 01  mov  1, %o0
a00983fc:  40 00 44 1b  call  0xa00a9468
a0098400:  92 10 20 02  mov  2, %o1
a0098404:  92 10 20 01  mov  1, %o1
a0098408:  40 00 6c 33  call  0xa00b34d4
a009840c:  90 10 20 00  clr  %o0
a0098410:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a0098414:  e0 0a e0 8e  ldub  [ %o3 + 0x8e ], %l0	! 0xa802b08e
a0098418:  92 14 20 02  or  %l0, 2, %o1
a009841c:  9e 10 20 05  mov  5, %o7
a0098420:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a0098424:  de 2a a0 8f  stb  %o7, [ %o2 + 0x8f ]	! 0xa802b08f
a0098428:  d2 2a e0 8e  stb  %o1, [ %o3 + 0x8e ]
a009842c:  81 c7 e0 08  ret
a0098430:  81 e8 00 00  restore
