# leon2m FUN_a00a454c 0xa00a454c-0xa00a45a8 (92 bytes)
a00a454c:  9d e3 bf 98  save  %sp, -104, %sp
a00a4550:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00a4554:  98 12 62 90  or  %o1, 0x290, %o4	! 0xa802d290
a00a4558:  da 0b 20 0c  ldub  [ %o4 + 0xc ], %o5
a00a455c:  90 03 7f f6  add  %o5, -10, %o0
a00a4560:  82 0a 20 ff  and  %o0, 0xff, %g1
a00a4564:  90 10 20 01  mov  1, %o0
a00a4568:  80 a0 60 19  cmp  %g1, 0x19
a00a456c:  08 80 00 05  bleu  0xa00a4580
a00a4570:  9a 03 7f fb  add  %o5, -5, %o5
a00a4574:  94 10 20 05  mov  5, %o2
a00a4578:  10 80 00 06  b  0xa00a4590
a00a457c:  d4 2b 20 0c  stb  %o2, [ %o4 + 0xc ]
a00a4580:  40 00 4c 3d  call  0xa00b7674
a00a4584:  da 2b 20 0c  stb  %o5, [ %o4 + 0xc ]
a00a4588:  40 00 c0 8a  call  0xa00d47b0
a00a458c:  01 00 00 00  nop
a00a4590:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00a4594:  de 0a e0 8e  ldub  [ %o3 + 0x8e ], %o7	! 0xa802b08e
a00a4598:  98 13 e0 02  or  %o7, 2, %o4
a00a459c:  d8 2a e0 8e  stb  %o4, [ %o3 + 0x8e ]
a00a45a0:  81 c7 e0 08  ret
a00a45a4:  81 e8 00 00  restore
