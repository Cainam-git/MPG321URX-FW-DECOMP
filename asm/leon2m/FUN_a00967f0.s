# leon2m FUN_a00967f0 0xa00967f0-0xa0096858 (104 bytes)
a00967f0:  9d e3 bf 98  save  %sp, -104, %sp
a00967f4:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00967f8:  a0 13 e2 90  or  %o7, 0x290, %l0	! 0xa802d290
a00967fc:  d6 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %o3
a0096800:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a0096804:  92 0a e0 ff  and  %o3, 0xff, %o1
a0096808:  d6 2b 20 56  stb  %o3, [ %o4 + 0x56 ]
a009680c:  94 10 20 00  clr  %o2
a0096810:  40 00 46 4b  call  0xa00a813c
a0096814:  90 10 20 01  mov  1, %o0
a0096818:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009681c:  d4 04 63 ec  ld  [ %l1 + 0x3ec ], %o2	! 0xa802afec
a0096820:  90 02 bf e8  add  %o2, -24, %o0
a0096824:  90 0a 20 ff  and  %o0, 0xff, %o0
a0096828:  40 00 49 f9  call  0xa00a900c
a009682c:  92 10 20 02  mov  2, %o1
a0096830:  d0 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %o0
a0096834:  92 02 20 70  add  %o0, 0x70, %o1
a0096838:  d2 24 63 ec  st  %o1, [ %l1 + 0x3ec ]
a009683c:  40 00 4b 85  call  0xa00a9650
a0096840:  92 10 20 01  mov  1, %o1
a0096844:  9a 10 20 0e  mov  0xe, %o5
a0096848:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a009684c:  da 28 60 8f  stb  %o5, [ %g1 + 0x8f ]	! 0xa802b08f
a0096850:  81 c7 e0 08  ret
a0096854:  81 e8 00 00  restore
