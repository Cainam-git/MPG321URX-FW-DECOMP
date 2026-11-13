# leon2s FUN_a006d46c 0xa006d46c-0xa006d4e0 (116 bytes)
a006d46c:  9d e3 bf 98  save  %sp, -104, %sp
a006d470:  33 2a 01 ea  sethi  %hi(0xa807a800), %i1
a006d474:  b0 0e 20 ff  and  %i0, 0xff, %i0
a006d478:  ba 10 20 00  clr  %i5
a006d47c:  98 10 20 02  mov  2, %o4
a006d480:  9a 16 60 24  or  %i1, 0x24, %o5
a006d484:  9e 10 20 01  mov  1, %o7
a006d488:  b8 0f 60 ff  and  %i5, 0xff, %i4
a006d48c:  83 3e 00 1c  sra  %i0, %i4, %g1
a006d490:  80 88 60 01  btst  1, %g1
a006d494:  b6 07 60 01  add  %i5, 1, %i3
a006d498:  83 2f 20 02  sll  %i4, 2, %g1
a006d49c:  ba 00 40 1c  add  %g1, %i4, %i5
a006d4a0:  b4 16 60 24  or  %i1, 0x24, %i2
a006d4a4:  02 80 00 08  be  0xa006d4c4
a006d4a8:  bb 2f 60 02  sll  %i5, 2, %i5
a006d4ac:  c2 0e 80 1d  ldub  [ %i2 + %i5 ], %g1
a006d4b0:  80 a0 60 01  cmp  %g1, 1
a006d4b4:  22 80 00 05  be,a   0xa006d4c8
a006d4b8:  d8 2e 80 1d  stb  %o4, [ %i2 + %i5 ]
a006d4bc:  10 80 00 04  b  0xa006d4cc
a006d4c0:  82 0e e0 ff  and  %i3, 0xff, %g1
a006d4c4:  de 2b 40 1d  stb  %o7, [ %o5 + %i5 ]
a006d4c8:  82 0e e0 ff  and  %i3, 0xff, %g1
a006d4cc:  80 a0 60 08  cmp  %g1, 8
a006d4d0:  08 bf ff ee  bleu  0xa006d488
a006d4d4:  ba 10 00 1b  mov  %i3, %i5
a006d4d8:  81 c7 e0 08  ret
a006d4dc:  81 e8 00 00  restore
