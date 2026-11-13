# leon2s FUN_a00ac41c 0xa00ac41c-0xa00ac4ec (208 bytes)  [FUN_a00ac4e4 = unreachable ret/restore tail, merged]
a00ac41c:  9d e3 bf 98  save  %sp, -104, %sp
a00ac420:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ac424:  37 2a 01 e4  sethi  %hi(0xa8079000), %i3
a00ac428:  e0 0e e3 1c  ldub  [ %i3 + 0x31c ], %l0	! 0xa807931c
a00ac42c:  92 10 24 60  mov  0x460, %o1
a00ac430:  7f ff e9 e2  call  0xa00a6bb8
a00ac434:  90 10 00 18  mov  %i0, %o0
a00ac438:  90 0a 20 01  and  %o0, 1, %o0
a00ac43c:  80 a4 00 08  cmp  %l0, %o0
a00ac440:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00ac444:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00ac448:  90 12 20 c8  or  %o0, 0xc8, %o0
a00ac44c:  02 80 00 04  be  0xa00ac45c
a00ac450:  92 10 00 18  mov  %i0, %o1
a00ac454:  7f ff 1a fc  call  0xa0073044
a00ac458:  01 00 00 00  nop
a00ac45c:  92 10 24 60  mov  0x460, %o1	! 0x460
a00ac460:  7f ff e9 d6  call  0xa00a6bb8
a00ac464:  90 10 00 18  mov  %i0, %o0
a00ac468:  82 0a 20 01  and  %o0, 1, %g1
a00ac46c:  92 10 20 30  mov  0x30, %o1
a00ac470:  94 10 20 80  mov  0x80, %o2
a00ac474:  96 10 20 01  mov  1, %o3
a00ac478:  80 a6 40 01  cmp  %i1, %g1
a00ac47c:  12 80 00 05  bne  0xa00ac490
a00ac480:  90 10 00 18  mov  %i0, %o0
a00ac484:  80 8e a0 ff  btst  0xff, %i2
a00ac488:  02 80 00 16  be  0xa00ac4e0
a00ac48c:  01 00 00 00  nop
a00ac490:  7f ff ea 02  call  0xa00a6c98
a00ac494:  01 00 00 00  nop
a00ac498:  90 10 00 18  mov  %i0, %o0
a00ac49c:  92 10 24 60  mov  0x460, %o1
a00ac4a0:  94 10 20 01  mov  1, %o2
a00ac4a4:  80 a6 60 01  cmp  %i1, 1
a00ac4a8:  12 80 00 04  bne  0xa00ac4b8
a00ac4ac:  96 10 20 01  mov  1, %o3
a00ac4b0:  10 80 00 07  b  0xa00ac4cc
a00ac4b4:  f2 2e e3 1c  stb  %i1, [ %i3 + 0x31c ]
a00ac4b8:  c0 2e e3 1c  clrb  [ %i3 + 0x31c ]
a00ac4bc:  90 10 00 18  mov  %i0, %o0
a00ac4c0:  92 10 24 60  mov  0x460, %o1
a00ac4c4:  94 10 20 01  mov  1, %o2
a00ac4c8:  96 10 20 00  clr  %o3
a00ac4cc:  7f ff e9 f3  call  0xa00a6c98
a00ac4d0:  b2 10 20 30  mov  0x30, %i1
a00ac4d4:  b4 10 20 80  mov  0x80, %i2
a00ac4d8:  7f ff e9 f0  call  0xa00a6c98
a00ac4dc:  97 e8 20 00  restore  %g0, 0, %o3
a00ac4e0:  01 00 00 00  nop
a00ac4e4:  81 c7 e0 08  ret
a00ac4e8:  81 e8 00 00  restore
