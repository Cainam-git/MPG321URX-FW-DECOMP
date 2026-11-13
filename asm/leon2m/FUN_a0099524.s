# leon2m FUN_a0099524 0xa0099524-0xa0099598 (116 bytes)
a0099524:  9d e3 bf 98  save  %sp, -104, %sp
a0099528:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a009952c:  40 00 3f a4  call  0xa00a93bc
a0099530:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0	! 0xa8025c56
a0099534:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a0099538:  94 10 20 00  clr  %o2
a009953c:  40 00 3b 00  call  0xa00a813c
a0099540:  90 10 20 01  mov  1, %o0
a0099544:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a0099548:  a0 12 e2 90  or  %o3, 0x290, %l0	! 0xa802d290
a009954c:  d0 0c 21 7c  ldub  [ %l0 + 0x17c ], %o0
a0099550:  40 00 40 40  call  0xa00a9650
a0099554:  92 10 20 00  clr  %o1
a0099558:  d2 0c 21 7c  ldub  [ %l0 + 0x17c ], %o1
a009955c:  90 10 20 01  mov  1, %o0
a0099560:  40 00 3a f7  call  0xa00a813c
a0099564:  94 10 20 01  mov  1, %o2
a0099568:  94 10 20 0b  mov  0xb, %o2
a009956c:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a0099570:  d4 22 63 ec  st  %o2, [ %o1 + 0x3ec ]	! 0xa802afec
a0099574:  90 10 20 00  clr  %o0
a0099578:  40 00 3e a5  call  0xa00a900c
a009957c:  92 10 20 01  mov  1, %o1
a0099580:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0099584:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a0099588:  82 12 20 02  or  %o0, 2, %g1
a009958c:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a0099590:  81 c7 e0 08  ret
a0099594:  81 e8 00 00  restore
