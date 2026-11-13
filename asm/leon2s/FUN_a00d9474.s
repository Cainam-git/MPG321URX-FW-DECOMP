# leon2s FUN_a00d9474 0xa00d9474-0xa00d9524 (176 bytes)
a00d9474:  9d e3 bf 80  save  %sp, -128, %sp
a00d9478:  d8 07 bf e0  ld  [ %fp + -32 ], %o4
a00d947c:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00d9480:  98 13 00 01  or  %o4, %g1, %o4
a00d9484:  b0 0e 20 7f  and  %i0, 0x7f, %i0
a00d9488:  1b 1f c0 00  sethi  %hi(0x7f000000), %o5
a00d948c:  9a 2b 00 0d  andn  %o4, %o5, %o5
a00d9490:  b1 2e 20 18  sll  %i0, 0x18, %i0
a00d9494:  21 2a 01 e2  sethi  %hi(0xa8078800), %l0
a00d9498:  9a 13 40 18  or  %o5, %i0, %o5
a00d949c:  d8 0c 20 32  ldub  [ %l0 + 0x32 ], %o4
a00d94a0:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00d94a4:  b0 10 60 a4  or  %g1, 0xa4, %i0	! 0xa80760a4
a00d94a8:  99 2b 20 02  sll  %o4, 2, %o4
a00d94ac:  da 27 bf e0  st  %o5, [ %fp + -32 ]
a00d94b0:  d4 06 00 0c  ld  [ %i0 + %o4 ], %o2
a00d94b4:  96 10 20 00  clr  %o3
a00d94b8:  92 07 bf f8  add  %fp, -8, %o1
a00d94bc:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00d94c0:  83 2b 60 02  sll  %o5, 2, %g1
a00d94c4:  82 00 40 0a  add  %g1, %o2, %g1
a00d94c8:  d8 00 6d 00  ld  [ %g1 + 0xd00 ], %o4
a00d94cc:  96 02 e0 01  inc  %o3
a00d94d0:  9a 02 40 0d  add  %o1, %o5, %o5
a00d94d4:  82 0a e0 ff  and  %o3, 0xff, %g1
a00d94d8:  80 a0 60 0f  cmp  %g1, 0xf
a00d94dc:  08 bf ff f8  bleu  0xa00d94bc
a00d94e0:  d8 2b 7f e9  stb  %o4, [ %o5 + -23 ]
a00d94e4:  f2 2f bf f1  stb  %i1, [ %fp + -15 ]
a00d94e8:  f4 2f bf f2  stb  %i2, [ %fp + -14 ]
a00d94ec:  90 07 bf e0  add  %fp, -32, %o0
a00d94f0:  92 10 20 02  mov  2, %o1
a00d94f4:  94 10 20 01  mov  1, %o2
a00d94f8:  96 10 20 0f  mov  0xf, %o3
a00d94fc:  7f ff f9 08  call  0xa00d791c
a00d9500:  98 10 20 13  mov  0x13, %o4
a00d9504:  c2 0c 20 32  ldub  [ %l0 + 0x32 ], %g1
a00d9508:  83 28 60 02  sll  %g1, 2, %g1
a00d950c:  da 06 00 01  ld  [ %i0 + %g1 ], %o5
a00d9510:  c2 03 40 00  ld  [ %o5 ], %g1
a00d9514:  82 10 60 20  or  %g1, 0x20, %g1
a00d9518:  c2 23 40 00  st  %g1, [ %o5 ]
a00d951c:  81 c7 e0 08  ret
a00d9520:  81 e8 00 00  restore
