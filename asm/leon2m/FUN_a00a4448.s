# leon2m FUN_a00a4448 0xa00a4448-0xa00a44a0 (88 bytes)
a00a4448:  9d e3 bf 98  save  %sp, -104, %sp
a00a444c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00a4450:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00a4454:  da 0b 20 0f  ldub  [ %o4 + 0xf ], %o5
a00a4458:  9a 03 60 01  inc  %o5
a00a445c:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a4460:  80 a0 60 05  cmp  %g1, 5
a00a4464:  08 80 00 05  bleu  0xa00a4478
a00a4468:  90 10 20 01  mov  1, %o0
a00a446c:  92 10 20 05  mov  5, %o1
a00a4470:  10 80 00 06  b  0xa00a4488
a00a4474:  d2 2b 20 0f  stb  %o1, [ %o4 + 0xf ]
a00a4478:  40 00 4c 2e  call  0xa00b7530
a00a447c:  da 2b 20 0f  stb  %o5, [ %o4 + 0xf ]
a00a4480:  40 00 c0 c0  call  0xa00d4780
a00a4484:  01 00 00 00  nop
a00a4488:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00a448c:  d8 0a a0 8e  ldub  [ %o2 + 0x8e ], %o4	! 0xa802b08e
a00a4490:  96 13 20 02  or  %o4, 2, %o3
a00a4494:  d6 2a a0 8e  stb  %o3, [ %o2 + 0x8e ]
a00a4498:  81 c7 e0 08  ret
a00a449c:  81 e8 00 00  restore
