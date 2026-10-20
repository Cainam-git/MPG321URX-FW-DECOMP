# leon2m FUN_a00ae39c 0xa00ae39c-0xa00ae4f0 (340 bytes)
a00ae39c:  9d e3 bf 90  save  %sp, -112, %sp
a00ae3a0:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ae3a4:  94 14 62 90  or  %l1, 0x290, %o2	! 0xa802d290
a00ae3a8:  d2 0a a1 a0  ldub  [ %o2 + 0x1a0 ], %o1
a00ae3ac:  90 0a 60 03  and  %o1, 3, %o0
a00ae3b0:  82 02 00 08  add  %o0, %o0, %g1
a00ae3b4:  a0 00 60 04  add  %g1, 4, %l0
a00ae3b8:  90 10 20 00  clr  %o0
a00ae3bc:  92 10 20 00  clr  %o1
a00ae3c0:  94 10 20 00  clr  %o2
a00ae3c4:  40 00 16 c3  call  0xa00b3ed0
a00ae3c8:  96 10 20 00  clr  %o3
a00ae3cc:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00ae3d0:  90 10 20 00  clr  %o0
a00ae3d4:  92 10 20 00  clr  %o1
a00ae3d8:  94 10 27 92  mov  0x792, %o2
a00ae3dc:  96 10 20 03  mov  3, %o3
a00ae3e0:  98 10 20 0a  mov  0xa, %o4
a00ae3e4:  80 a4 20 0a  cmp  %l0, 0xa
a00ae3e8:  02 80 00 2c  be  0xa00ae498
a00ae3ec:  9a 10 20 02  mov  2, %o5
a00ae3f0:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae3f4:  90 10 20 00  clr  %o0
a00ae3f8:  92 10 20 00  clr  %o1
a00ae3fc:  94 10 27 92  mov  0x792, %o2
a00ae400:  96 10 20 03  mov  3, %o3
a00ae404:  98 10 00 10  mov  %l0, %o4
a00ae408:  9a 10 20 03  mov  3, %o5
a00ae40c:  40 00 13 b6  call  0xa00b32e4
a00ae410:  01 00 00 00  nop
a00ae414:  98 10 00 10  mov  %l0, %o4
a00ae418:  90 10 20 00  clr  %o0
a00ae41c:  92 10 20 00  clr  %o1
a00ae420:  94 10 27 92  mov  0x792, %o2
a00ae424:  96 10 20 12  mov  0x12, %o3
a00ae428:  9a 10 20 03  mov  3, %o5
a00ae42c:  40 00 13 ae  call  0xa00b32e4
a00ae430:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae434:  a0 14 62 90  or  %l1, 0x290, %l0
a00ae438:  d8 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o4
a00ae43c:  1b 19 99 99  sethi  %hi(0x66666400), %o5
a00ae440:  82 13 62 67  or  %o5, 0x267, %g1	! 0x66666667
a00ae444:  92 03 20 01  add  %o4, 1, %o1
a00ae448:  80 5a 40 01  smul  %o1, %g1, %g0
a00ae44c:  a3 40 00 00  rd  %y, %l1
a00ae450:  9f 3c 60 01  sra  %l1, 1, %o7
a00ae454:  97 2b e0 02  sll  %o7, 2, %o3
a00ae458:  94 02 c0 0f  add  %o3, %o7, %o2
a00ae45c:  a2 22 40 0a  sub  %o1, %o2, %l1
a00ae460:  9e 0c 60 ff  and  %l1, 0xff, %o7
a00ae464:  90 1b e0 04  xor  %o7, 4, %o0
a00ae468:  80 a0 00 08  cmp  %g0, %o0
a00ae46c:  9a 60 3f ff  subx  %g0, -1, %o5
a00ae470:  80 a0 00 0f  cmp  %g0, %o7
a00ae474:  82 60 3f ff  subx  %g0, -1, %g1
a00ae478:  80 93 40 01  orcc  %o5, %g1, %g0
a00ae47c:  e2 2c 21 a0  stb  %l1, [ %l0 + 0x1a0 ]
a00ae480:  02 80 00 12  be  0xa00ae4c8
a00ae484:  91 33 e0 02  srl  %o7, 2, %o0
a00ae488:  40 00 29 4f  call  0xa00b89c4
a00ae48c:  01 00 00 00  nop
a00ae490:  10 80 00 0f  b  0xa00ae4cc
a00ae494:  d4 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o2
a00ae498:  40 00 13 93  call  0xa00b32e4
a00ae49c:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae4a0:  98 10 20 11  mov  0x11, %o4
a00ae4a4:  17 00 00 0c  sethi  %hi(0x3000), %o3
a00ae4a8:  d8 23 a0 5c  st  %o4, [ %sp + 0x5c ]
a00ae4ac:  94 12 e0 92  or  %o3, 0x92, %o2
a00ae4b0:  90 10 20 01  mov  1, %o0
a00ae4b4:  92 10 20 00  clr  %o1
a00ae4b8:  96 10 20 03  mov  3, %o3
a00ae4bc:  98 10 20 0c  mov  0xc, %o4
a00ae4c0:  10 bf ff d3  b  0xa00ae40c
a00ae4c4:  9a 10 20 01  mov  1, %o5
a00ae4c8:  d4 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o2
a00ae4cc:  90 0a a0 03  and  %o2, 3, %o0
a00ae4d0:  7f ff fc e7  call  0xa00ad86c
a00ae4d4:  92 10 20 01  mov  1, %o1
a00ae4d8:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00ae4dc:  d2 0c 20 8e  ldub  [ %l0 + 0x8e ], %o1	! 0xa802b08e
a00ae4e0:  90 12 60 02  or  %o1, 2, %o0
a00ae4e4:  d0 2c 20 8e  stb  %o0, [ %l0 + 0x8e ]
a00ae4e8:  81 c7 e0 08  ret
a00ae4ec:  81 e8 00 00  restore
