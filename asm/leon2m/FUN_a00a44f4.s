# leon2m FUN_a00a44f4 0xa00a44f4-0xa00a454c (88 bytes)
a00a44f4:  9d e3 bf 98  save  %sp, -104, %sp
a00a44f8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00a44fc:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00a4500:  da 0b 20 0c  ldub  [ %o4 + 0xc ], %o5
a00a4504:  9a 03 60 05  add  %o5, 5, %o5
a00a4508:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a450c:  80 a0 60 1e  cmp  %g1, 0x1e
a00a4510:  08 80 00 05  bleu  0xa00a4524
a00a4514:  90 10 20 01  mov  1, %o0
a00a4518:  92 10 20 1e  mov  0x1e, %o1
a00a451c:  10 80 00 06  b  0xa00a4534
a00a4520:  d2 2b 20 0c  stb  %o1, [ %o4 + 0xc ]
a00a4524:  40 00 4c 54  call  0xa00b7674
a00a4528:  da 2b 20 0c  stb  %o5, [ %o4 + 0xc ]
a00a452c:  40 00 c0 a1  call  0xa00d47b0
a00a4530:  01 00 00 00  nop
a00a4534:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00a4538:  d8 0a a0 8e  ldub  [ %o2 + 0x8e ], %o4	! 0xa802b08e
a00a453c:  96 13 20 02  or  %o4, 2, %o3
a00a4540:  d6 2a a0 8e  stb  %o3, [ %o2 + 0x8e ]
a00a4544:  81 c7 e0 08  ret
a00a4548:  81 e8 00 00  restore
