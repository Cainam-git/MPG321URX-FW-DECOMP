# leon2m FUN_a0096494 0xa0096494-0xa00964fc (104 bytes)
a0096494:  9d e3 bf 98  save  %sp, -104, %sp
a0096498:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a009649c:  a0 13 e2 90  or  %o7, 0x290, %l0	! 0xa802d290
a00964a0:  d6 0c 20 11  ldub  [ %l0 + 0x11 ], %o3
a00964a4:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a00964a8:  92 0a e0 ff  and  %o3, 0xff, %o1
a00964ac:  d6 2b 20 56  stb  %o3, [ %o4 + 0x56 ]
a00964b0:  94 10 20 00  clr  %o2
a00964b4:  40 00 47 22  call  0xa00a813c
a00964b8:  90 10 20 01  mov  1, %o0
a00964bc:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00964c0:  d4 04 63 ec  ld  [ %l1 + 0x3ec ], %o2	! 0xa802afec
a00964c4:  90 02 bf e8  add  %o2, -24, %o0
a00964c8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00964cc:  40 00 4a d0  call  0xa00a900c
a00964d0:  92 10 20 02  mov  2, %o1
a00964d4:  d0 0c 20 11  ldub  [ %l0 + 0x11 ], %o0
a00964d8:  92 02 20 6c  add  %o0, 0x6c, %o1
a00964dc:  d2 24 63 ec  st  %o1, [ %l1 + 0x3ec ]
a00964e0:  40 00 4c 5c  call  0xa00a9650
a00964e4:  92 10 20 01  mov  1, %o1
a00964e8:  9a 10 20 0d  mov  0xd, %o5
a00964ec:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00964f0:  da 28 60 8f  stb  %o5, [ %g1 + 0x8f ]	! 0xa802b08f
a00964f4:  81 c7 e0 08  ret
a00964f8:  81 e8 00 00  restore
