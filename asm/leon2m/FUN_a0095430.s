# leon2m FUN_a0095430 0xa0095430-0xa00954a0 (112 bytes)
a0095430:  9d e3 bf 98  save  %sp, -104, %sp
a0095434:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a0095438:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a009543c:  a0 12 62 90  or  %o1, 0x290, %l0	! 0xa802d290
a0095440:  d6 0c 60 55  ldub  [ %l1 + 0x55 ], %o3
a0095444:  da 0c 20 31  ldub  [ %l0 + 0x31 ], %o5
a0095448:  90 0a e0 ff  and  %o3, 0xff, %o0
a009544c:  98 10 20 0f  mov  0xf, %o4
a0095450:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a0095454:  80 a3 40 08  cmp  %o5, %o0
a0095458:  02 80 00 04  be  0xa0095468
a009545c:  d8 28 60 8f  stb  %o4, [ %g1 + 0x8f ]
a0095460:  40 01 09 b0  call  0xa00d7b20
a0095464:  d6 2c 20 31  stb  %o3, [ %l0 + 0x31 ]
a0095468:  40 00 4e 08  call  0xa00a8c88
a009546c:  01 00 00 00  nop
a0095470:  40 00 4c 9e  call  0xa00a86e8
a0095474:  01 00 00 00  nop
a0095478:  9e 10 20 7b  mov  0x7b, %o7	! 0x7b
a009547c:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a0095480:  de 22 e3 ec  st  %o7, [ %o3 + 0x3ec ]	! 0xa802afec
a0095484:  90 10 20 01  mov  1, %o0
a0095488:  40 00 50 72  call  0xa00a9650
a009548c:  92 10 20 01  mov  1, %o1
a0095490:  d4 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %o2
a0095494:  d4 2c 60 55  stb  %o2, [ %l1 + 0x55 ]
a0095498:  81 c7 e0 08  ret
a009549c:  81 e8 00 00  restore
