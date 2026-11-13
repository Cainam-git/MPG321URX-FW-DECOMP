# leon2s FUN_a00c8444 0xa00c8444-0xa00c850c (200 bytes)
a00c8444:  9d e3 bf 98  save  %sp, -104, %sp
a00c8448:  b6 0e 20 ff  and  %i0, 0xff, %i3
a00c844c:  82 06 c0 1b  add  %i3, %i3, %g1
a00c8450:  82 00 40 1b  add  %g1, %i3, %g1
a00c8454:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00c8458:  83 28 60 03  sll  %g1, 3, %g1
a00c845c:  9a 13 63 b0  or  %o5, 0x3b0, %o5
a00c8460:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00c8464:  83 30 60 1c  srl  %g1, 0x1c, %g1
a00c8468:  92 10 20 00  clr  %o1
a00c846c:  94 10 20 0f  mov  0xf, %o2
a00c8470:  90 10 00 1b  mov  %i3, %o0
a00c8474:  b0 10 00 1b  mov  %i3, %i0
a00c8478:  b2 10 20 00  clr  %i1
a00c847c:  80 88 60 01  btst  1, %g1
a00c8480:  02 80 00 11  be  0xa00c84c4
a00c8484:  b4 10 20 cc  mov  0xcc, %i2
a00c8488:  40 3b be d4  call  0xa0fb7fd8
a00c848c:  01 00 00 00  nop
a00c8490:  96 12 20 10  or  %o0, 0x10, %o3
a00c8494:  90 10 00 1b  mov  %i3, %o0
a00c8498:  96 0a e0 ff  and  %o3, 0xff, %o3
a00c849c:  92 10 20 00  clr  %o1
a00c84a0:  40 3b be ed  call  0xa0fb8054
a00c84a4:  94 10 20 0f  mov  0xf, %o2
a00c84a8:  90 10 00 1b  mov  %i3, %o0
a00c84ac:  92 10 20 00  clr  %o1
a00c84b0:  40 3b be ca  call  0xa0fb7fd8
a00c84b4:  94 10 20 cc  mov  0xcc, %o2
a00c84b8:  90 12 20 08  or  %o0, 8, %o0
a00c84bc:  10 80 00 11  b  0xa00c8500
a00c84c0:  b6 0a 20 ff  and  %o0, 0xff, %i3
a00c84c4:  40 3b be c5  call  0xa0fb7fd8
a00c84c8:  90 10 00 1b  mov  %i3, %o0
a00c84cc:  96 0a 20 ef  and  %o0, 0xef, %o3
a00c84d0:  90 10 00 1b  mov  %i3, %o0
a00c84d4:  92 10 20 00  clr  %o1
a00c84d8:  40 3b be df  call  0xa0fb8054
a00c84dc:  94 10 20 0f  mov  0xf, %o2
a00c84e0:  90 10 00 1b  mov  %i3, %o0
a00c84e4:  92 10 20 00  clr  %o1
a00c84e8:  40 3b be bc  call  0xa0fb7fd8
a00c84ec:  94 10 20 cc  mov  0xcc, %o2
a00c84f0:  b0 10 00 1b  mov  %i3, %i0
a00c84f4:  b6 0a 20 f7  and  %o0, 0xf7, %i3
a00c84f8:  b2 10 20 00  clr  %i1
a00c84fc:  b4 10 20 cc  mov  0xcc, %i2
a00c8500:  40 3b be d5  call  0xa0fb8054
a00c8504:  81 e8 00 00  restore
a00c8508:  01 00 00 00  nop
