# leon2m FUN_a009530c 0xa009530c-0xa00953d4 (200 bytes)
a009530c:  9d e3 bf 98  save  %sp, -104, %sp
a0095310:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a0095314:  96 14 62 90  or  %l1, 0x290, %o3	! 0xa802d290
a0095318:  9a 10 20 10  mov  0x10, %o5
a009531c:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a0095320:  d8 0a e1 a3  ldub  [ %o3 + 0x1a3 ], %o4
a0095324:  da 28 60 8f  stb  %o5, [ %g1 + 0x8f ]
a0095328:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a009532c:  80 a3 20 00  cmp  %o4, 0
a0095330:  da 0a e0 20  ldub  [ %o3 + 0x20 ], %o5
a0095334:  02 80 00 09  be  0xa0095358
a0095338:  27 2a 00 97  sethi  %hi(0xa8025c00), %l3
a009533c:  d0 0c e0 55  ldub  [ %l3 + 0x55 ], %o0	! 0xa8025c55
a0095340:  80 a3 40 08  cmp  %o5, %o0
a0095344:  d0 2a e0 20  stb  %o0, [ %o3 + 0x20 ]
a0095348:  02 80 00 04  be  0xa0095358
a009534c:  90 10 20 01  mov  1, %o0
a0095350:  40 01 01 7a  call  0xa00d5938
a0095354:  01 00 00 00  nop
a0095358:  40 00 4e 4c  call  0xa00a8c88
a009535c:  01 00 00 00  nop
a0095360:  40 00 51 d7  call  0xa00a9abc
a0095364:  01 00 00 00  nop
a0095368:  94 14 62 90  or  %l1, 0x290, %o2
a009536c:  d2 0a a1 a3  ldub  [ %o2 + 0x1a3 ], %o1
a0095370:  80 a2 60 00  cmp  %o1, 0
a0095374:  02 80 00 04  be  0xa0095384
a0095378:  82 10 20 82  mov  0x82, %g1
a009537c:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a0095380:  82 10 20 83  mov  0x83, %g1
a0095384:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0095388:  c2 24 a3 ec  st  %g1, [ %l2 + 0x3ec ]
a009538c:  d0 0c 20 54  ldub  [ %l0 + 0x54 ], %o0
a0095390:  40 00 50 b0  call  0xa00a9650
a0095394:  92 10 20 02  mov  2, %o1
a0095398:  d2 0c 20 54  ldub  [ %l0 + 0x54 ], %o1
a009539c:  90 10 20 01  mov  1, %o0
a00953a0:  40 00 4b 67  call  0xa00a813c
a00953a4:  94 10 20 01  mov  1, %o2
a00953a8:  d8 04 a3 ec  ld  [ %l2 + 0x3ec ], %o4
a00953ac:  a0 03 3f 81  add  %o4, -127, %l0
a00953b0:  90 0c 20 ff  and  %l0, 0xff, %o0
a00953b4:  40 00 50 a7  call  0xa00a9650
a00953b8:  92 10 20 01  mov  1, %o1
a00953bc:  96 14 62 90  or  %l1, 0x290, %o3
a00953c0:  de 0a e1 a4  ldub  [ %o3 + 0x1a4 ], %o7
a00953c4:  de 2c e0 55  stb  %o7, [ %l3 + 0x55 ]
a00953c8:  c0 2a e1 a3  clrb  [ %o3 + 0x1a3 ]
a00953cc:  81 c7 e0 08  ret
a00953d0:  81 e8 00 00  restore
