# leon2m FUN_a00962ac 0xa00962ac-0xa0096338 (140 bytes)
a00962ac:  9d e3 bf 98  save  %sp, -104, %sp
a00962b0:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a00962b4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00962b8:  d2 08 60 56  ldub  [ %g1 + 0x56 ], %o1
a00962bc:  a0 14 22 90  or  %l0, 0x290, %l0
a00962c0:  b0 0a 60 0f  and  %o1, 0xf, %i0
a00962c4:  e2 04 20 34  ld  [ %l0 + 0x34 ], %l1
a00962c8:  33 00 03 c0  sethi  %hi(0xf0000), %i1
a00962cc:  9e 2c 40 19  andn  %l1, %i1, %o7
a00962d0:  9b 2e 20 10  sll  %i0, 0x10, %o5
a00962d4:  98 13 c0 0d  or  %o7, %o5, %o4
a00962d8:  40 00 fd 88  call  0xa00d58f8
a00962dc:  d8 24 20 34  st  %o4, [ %l0 + 0x34 ]
a00962e0:  40 00 fd 7e  call  0xa00d58d8
a00962e4:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00962e8:  40 00 f9 ac  call  0xa00d4998
a00962ec:  b0 10 20 02  mov  2, %i0
a00962f0:  d6 04 63 ec  ld  [ %l1 + 0x3ec ], %o3
a00962f4:  94 02 ff 9c  add  %o3, -100, %o2
a00962f8:  40 00 4c 31  call  0xa00a93bc
a00962fc:  90 0a a0 ff  and  %o2, 0xff, %o0
a0096300:  d0 14 20 34  lduh  [ %l0 + 0x34 ], %o0
a0096304:  90 0a 20 0f  and  %o0, 0xf, %o0
a0096308:  40 00 4c d2  call  0xa00a9650
a009630c:  92 10 20 00  clr  %o1
a0096310:  d2 14 20 34  lduh  [ %l0 + 0x34 ], %o1
a0096314:  92 0a 60 0f  and  %o1, 0xf, %o1
a0096318:  90 10 20 01  mov  1, %o0
a009631c:  40 00 47 88  call  0xa00a813c
a0096320:  94 10 20 01  mov  1, %o2
a0096324:  82 10 20 17  mov  0x17, %g1
a0096328:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a009632c:  40 00 4b 38  call  0xa00a900c
a0096330:  93 e8 20 01  restore  %g0, 1, %o1
a0096334:  01 00 00 00  nop
