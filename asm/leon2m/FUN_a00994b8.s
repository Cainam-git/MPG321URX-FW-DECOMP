# leon2m FUN_a00994b8 0xa00994b8-0xa0099524 (108 bytes)
a00994b8:  9d e3 bf 98  save  %sp, -104, %sp
a00994bc:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00994c0:  a0 13 62 90  or  %o5, 0x290, %l0	! 0xa802d290
a00994c4:  d8 0c 21 7c  ldub  [ %l0 + 0x17c ], %o4
a00994c8:  1f 2a 00 97  sethi  %hi(0xa8025c00), %o7
a00994cc:  92 0b 20 ff  and  %o4, 0xff, %o1
a00994d0:  d8 2b e0 56  stb  %o4, [ %o7 + 0x56 ]
a00994d4:  94 10 20 00  clr  %o2
a00994d8:  40 00 3b 19  call  0xa00a813c
a00994dc:  90 10 20 01  mov  1, %o0
a00994e0:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00994e4:  d6 04 63 ec  ld  [ %l1 + 0x3ec ], %o3	! 0xa802afec
a00994e8:  94 02 ff f5  add  %o3, -11, %o2
a00994ec:  90 0a a0 ff  and  %o2, 0xff, %o0
a00994f0:  40 00 3e c7  call  0xa00a900c
a00994f4:  92 10 20 02  mov  2, %o1
a00994f8:  d0 0c 21 7c  ldub  [ %l0 + 0x17c ], %o0
a00994fc:  92 02 20 3c  add  %o0, 0x3c, %o1
a0099500:  d2 24 63 ec  st  %o1, [ %l1 + 0x3ec ]
a0099504:  40 00 40 53  call  0xa00a9650
a0099508:  92 10 20 01  mov  1, %o1
a009950c:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0099510:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a0099514:  82 12 20 02  or  %o0, 2, %g1
a0099518:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a009951c:  81 c7 e0 08  ret
a0099520:  81 e8 00 00  restore
