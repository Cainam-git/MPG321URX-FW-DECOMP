# leon2m FUN_a013844c 0xa013844c-0xa01384ac (96 bytes)
a013844c:  9d e3 bf 88  save  %sp, -120, %sp
a0138450:  f0 2f bf e8  stb  %i0, [ %fp + -24 ]
a0138454:  94 10 20 00  clr  %o2
a0138458:  82 10 20 00  clr  %g1
a013845c:  92 07 bf f8  add  %fp, -8, %o1
a0138460:  82 00 40 01  add  %g1, %g1, %g1
a0138464:  98 00 40 09  add  %g1, %o1, %o4
a0138468:  da 0e 40 01  ldub  [ %i1 + %g1 ], %o5
a013846c:  90 00 40 19  add  %g1, %i1, %o0
a0138470:  94 02 a0 01  inc  %o2
a0138474:  d6 0a 20 01  ldub  [ %o0 + 1 ], %o3
a0138478:  82 0a a0 ff  and  %o2, 0xff, %g1
a013847c:  d6 2b 3f f5  stb  %o3, [ %o4 + -11 ]
a0138480:  80 a0 60 03  cmp  %g1, 3
a0138484:  08 bf ff f7  bleu  0xa0138460
a0138488:  da 2b 3f f4  stb  %o5, [ %o4 + -12 ]
a013848c:  90 10 20 59  mov  0x59, %o0
a0138490:  92 10 20 0c  mov  0xc, %o1
a0138494:  94 07 bf e8  add  %fp, -24, %o2
a0138498:  7f ff fb 11  call  0xa01370dc
a013849c:  96 10 20 00  clr  %o3
a01384a0:  01 00 00 00  nop
a01384a4:  81 c7 e0 08  ret
a01384a8:  81 e8 00 00  restore
