# leon2m FUN_a00d934c 0xa00d934c-0xa00d93c8 (124 bytes)
a00d934c:  9d e3 bf 98  save  %sp, -104, %sp
a00d9350:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00d9354:  a0 12 a2 90  or  %o2, 0x290, %l0	! 0xa802d290
a00d9358:  d0 04 20 ac  ld  [ %l0 + 0xac ], %o0
a00d935c:  13 00 00 80  sethi  %hi(0x20000), %o1
a00d9360:  d8 0c 20 1e  ldub  [ %l0 + 0x1e ], %o4
a00d9364:  c2 0c 20 20  ldub  [ %l0 + 0x20 ], %g1
a00d9368:  9a 12 00 09  or  %o0, %o1, %o5
a00d936c:  80 a3 00 01  cmp  %o4, %g1
a00d9370:  da 24 20 ac  st  %o5, [ %l0 + 0xac ]
a00d9374:  c2 2c 20 1e  stb  %g1, [ %l0 + 0x1e ]
a00d9378:  02 80 00 12  be  0xa00d93c0
a00d937c:  d8 2c 20 20  stb  %o4, [ %l0 + 0x20 ]
a00d9380:  7f ff ff ae  call  0xa00d9238
a00d9384:  01 00 00 00  nop
a00d9388:  de 04 20 a8  ld  [ %l0 + 0xa8 ], %o7
a00d938c:  17 00 00 10  sethi  %hi(0x4000), %o3
a00d9390:  80 8b c0 0b  btst  %o7, %o3
a00d9394:  12 80 00 07  bne  0xa00d93b0
a00d9398:  90 10 20 01  mov  1, %o0
a00d939c:  d2 0c 20 20  ldub  [ %l0 + 0x20 ], %o1
a00d93a0:  40 01 c1 76  call  0xa0149978
a00d93a4:  90 10 20 01  mov  1, %o0
a00d93a8:  7f ff f2 4c  call  0xa00d5cd8
a00d93ac:  81 e8 00 00  restore
a00d93b0:  40 01 b9 8f  call  0xa01479ec
a00d93b4:  01 00 00 00  nop
a00d93b8:  10 bf ff fa  b  0xa00d93a0
a00d93bc:  d2 0c 20 20  ldub  [ %l0 + 0x20 ], %o1
a00d93c0:  81 c7 e0 08  ret
a00d93c4:  81 e8 00 00  restore
