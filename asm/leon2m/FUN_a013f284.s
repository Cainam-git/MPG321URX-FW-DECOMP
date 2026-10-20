# leon2m FUN_a013f284 0xa013f284-0xa013f370 (236 bytes)
a013f284:  9d e3 bf 98  save  %sp, -104, %sp
a013f288:  7f ff f6 b1  call  0xa013cd4c
a013f28c:  90 0e 20 ff  and  %i0, 0xff, %o0
a013f290:  9a 0e 60 ff  and  %i1, 0xff, %o5
a013f294:  93 2b 60 03  sll  %o5, 3, %o1
a013f298:  98 02 40 0d  add  %o1, %o5, %o4
a013f29c:  15 00 06 96  sethi  %hi(0x1a5800), %o2
a013f2a0:  92 12 a2 16  or  %o2, 0x216, %o1	! 0x1a5a16
a013f2a4:  95 2b 20 02  sll  %o4, 2, %o2
a013f2a8:  98 02 80 09  add  %o2, %o1, %o4
a013f2ac:  d6 13 20 0e  lduh  [ %o4 + 0xe ], %o3
a013f2b0:  d6 32 20 12  sth  %o3, [ %o0 + 0x12 ]
a013f2b4:  f0 13 20 10  lduh  [ %o4 + 0x10 ], %i0
a013f2b8:  f0 32 20 14  sth  %i0, [ %o0 + 0x14 ]
a013f2bc:  d6 13 20 12  lduh  [ %o4 + 0x12 ], %o3
a013f2c0:  d6 32 20 16  sth  %o3, [ %o0 + 0x16 ]
a013f2c4:  e0 13 20 14  lduh  [ %o4 + 0x14 ], %l0
a013f2c8:  e0 32 20 18  sth  %l0, [ %o0 + 0x18 ]
a013f2cc:  f0 13 20 0a  lduh  [ %o4 + 0xa ], %i0
a013f2d0:  f0 32 20 0e  sth  %i0, [ %o0 + 0xe ]
a013f2d4:  e0 13 20 1a  lduh  [ %o4 + 0x1a ], %l0
a013f2d8:  e0 32 20 1e  sth  %l0, [ %o0 + 0x1e ]
a013f2dc:  c2 13 20 1c  lduh  [ %o4 + 0x1c ], %g1
a013f2e0:  c2 32 20 20  sth  %g1, [ %o0 + 0x20 ]
a013f2e4:  f2 13 20 16  lduh  [ %o4 + 0x16 ], %i1
a013f2e8:  f2 32 20 1a  sth  %i1, [ %o0 + 0x1a ]
a013f2ec:  de 13 20 18  lduh  [ %o4 + 0x18 ], %o7
a013f2f0:  de 32 20 1c  sth  %o7, [ %o0 + 0x1c ]
a013f2f4:  de 13 20 0a  lduh  [ %o4 + 0xa ], %o7
a013f2f8:  de 32 20 28  sth  %o7, [ %o0 + 0x28 ]
a013f2fc:  f2 13 20 16  lduh  [ %o4 + 0x16 ], %i1
a013f300:  f2 32 20 2a  sth  %i1, [ %o0 + 0x2a ]
a013f304:  da 13 20 18  lduh  [ %o4 + 0x18 ], %o5
a013f308:  82 10 20 20  mov  0x20, %g1
a013f30c:  c2 2a 20 26  stb  %g1, [ %o0 + 0x26 ]
a013f310:  da 32 20 2c  sth  %o5, [ %o0 + 0x2c ]
a013f314:  c0 2a 20 3a  clrb  [ %o0 + 0x3a ]
a013f318:  da 13 20 22  lduh  [ %o4 + 0x22 ], %o5
a013f31c:  da 32 20 3c  sth  %o5, [ %o0 + 0x3c ]
a013f320:  da 0a 40 0a  ldub  [ %o1 + %o2 ], %o5
a013f324:  82 0b 60 ff  and  %o5, 0xff, %g1
a013f328:  80 a3 60 00  cmp  %o5, 0
a013f32c:  02 80 00 0f  be  0xa013f368
a013f330:  96 5a c0 01  smul  %o3, %g1, %o3
a013f334:  d6 32 20 16  sth  %o3, [ %o0 + 0x16 ]
a013f338:  c2 0a 40 0a  ldub  [ %o1 + %o2 ], %g1
a013f33c:  9a 5e 00 01  smul  %i0, %g1, %o5
a013f340:  da 32 20 0e  sth  %o5, [ %o0 + 0xe ]
a013f344:  d8 0a 40 0a  ldub  [ %o1 + %o2 ], %o4
a013f348:  96 5c 00 0c  smul  %l0, %o4, %o3
a013f34c:  d6 32 20 1e  sth  %o3, [ %o0 + 0x1e ]
a013f350:  f0 0a 40 0a  ldub  [ %o1 + %o2 ], %i0
a013f354:  a0 5b c0 18  smul  %o7, %i0, %l0
a013f358:  e0 32 20 28  sth  %l0, [ %o0 + 0x28 ]
a013f35c:  c2 0a 40 0a  ldub  [ %o1 + %o2 ], %g1
a013f360:  9e 5e 40 01  smul  %i1, %g1, %o7
a013f364:  de 32 20 2a  sth  %o7, [ %o0 + 0x2a ]
a013f368:  81 c7 e0 08  ret
a013f36c:  81 e8 00 00  restore
