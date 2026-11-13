# leon2s FUN_a008642c 0xa008642c-0xa00864d4 (168 bytes)
a008642c:  9d e3 bf 90  save  %sp, -112, %sp
a0086430:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0086434:  80 a6 60 00  cmp  %i1, 0
a0086438:  02 80 00 0c  be  0xa0086468
a008643c:  82 10 20 21  mov  0x21, %g1
a0086440:  80 a6 60 01  cmp  %i1, 1
a0086444:  02 80 00 09  be  0xa0086468
a0086448:  82 10 20 22  mov  0x22, %g1
a008644c:  80 a6 60 02  cmp  %i1, 2
a0086450:  02 80 00 06  be  0xa0086468
a0086454:  82 10 20 23  mov  0x23, %g1
a0086458:  80 a6 60 03  cmp  %i1, 3
a008645c:  32 80 00 04  bne,a   0xa008646c
a0086460:  c0 2f bf f0  clrb  [ %fp + -16 ]
a0086464:  82 10 20 07  mov  7, %g1
a0086468:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a008646c:  82 0e e0 ff  and  %i3, 0xff, %g1
a0086470:  80 a0 60 02  cmp  %g1, 2
a0086474:  38 80 00 02  bgu,a   0xa008647c
a0086478:  b6 16 e0 04  or  %i3, 4, %i3
a008647c:  82 0f 20 ff  and  %i4, 0xff, %g1
a0086480:  80 a0 60 02  cmp  %g1, 2
a0086484:  38 80 00 02  bgu,a   0xa008648c
a0086488:  b8 17 20 04  or  %i4, 4, %i4
a008648c:  82 0f 20 ff  and  %i4, 0xff, %g1
a0086490:  83 28 60 03  sll  %g1, 3, %g1
a0086494:  82 10 40 1b  or  %g1, %i3, %g1
a0086498:  90 0e 20 ff  and  %i0, 0xff, %o0
a008649c:  c2 2f bf f4  stb  %g1, [ %fp + -12 ]
a00864a0:  c2 2f bf f1  stb  %g1, [ %fp + -15 ]
a00864a4:  c2 2f bf f2  stb  %g1, [ %fp + -14 ]
a00864a8:  c2 2f bf f3  stb  %g1, [ %fp + -13 ]
a00864ac:  96 0e a0 0f  and  %i2, 0xf, %o3
a00864b0:  92 10 20 80  mov  0x80, %o1
a00864b4:  94 10 21 02  mov  0x102, %o2
a00864b8:  7f ff ff c7  call  0xa00863d4
a00864bc:  98 07 bf f0  add  %fp, -16, %o4
a00864c0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00864c4:  80 a0 00 08  cmp  %g0, %o0
a00864c8:  b0 40 20 00  addx  %g0, 0, %i0
a00864cc:  81 c7 e0 08  ret
a00864d0:  81 e8 00 00  restore
