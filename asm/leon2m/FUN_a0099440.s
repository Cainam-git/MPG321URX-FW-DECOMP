# leon2m FUN_a0099440 0xa0099440-0xa00994b8 (120 bytes)
a0099440:  9d e3 bf 98  save  %sp, -104, %sp
a0099444:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0099448:  96 12 22 90  or  %o0, 0x290, %o3	! 0xa802d290
a009944c:  da 02 e1 74  ld  [ %o3 + 0x174 ], %o5
a0099450:  03 00 00 20  sethi  %hi(0x8000), %g1
a0099454:  98 10 00 01  mov  %g1, %o4
a0099458:  94 2b 40 01  andn  %o5, %g1, %o2
a009945c:  80 8b 40 0c  btst  %o5, %o4
a0099460:  02 80 00 04  be  0xa0099470
a0099464:  82 13 40 01  or  %o5, %g1, %g1
a0099468:  10 80 00 03  b  0xa0099474
a009946c:  d4 22 e1 74  st  %o2, [ %o3 + 0x174 ]
a0099470:  c2 22 e1 74  st  %g1, [ %o3 + 0x174 ]
a0099474:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0099478:  d8 03 63 ec  ld  [ %o5 + 0x3ec ], %o4	! 0xa802afec
a009947c:  9e 03 3f f2  add  %o4, -14, %o7
a0099480:  90 0b e0 ff  and  %o7, 0xff, %o0
a0099484:  40 00 43 19  call  0xa00aa0e8
a0099488:  92 10 20 01  mov  1, %o1
a009948c:  92 10 20 01  mov  1, %o1
a0099490:  40 00 46 09  call  0xa00aacb4
a0099494:  90 10 20 01  mov  1, %o0
a0099498:  40 01 08 7e  call  0xa00db690
a009949c:  01 00 00 00  nop
a00994a0:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00994a4:  d6 0a 60 8e  ldub  [ %o1 + 0x8e ], %o3	! 0xa802b08e
a00994a8:  94 12 e0 02  or  %o3, 2, %o2
a00994ac:  d4 2a 60 8e  stb  %o2, [ %o1 + 0x8e ]
a00994b0:  81 c7 e0 08  ret
a00994b4:  81 e8 00 00  restore
