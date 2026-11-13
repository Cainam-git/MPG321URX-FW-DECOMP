# leon2m FUN_a009584c 0xa009584c-0xa00958c4 (120 bytes)
a009584c:  9d e3 bf 98  save  %sp, -104, %sp
a0095850:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0095854:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0095858:  da 04 23 ec  ld  [ %l0 + 0x3ec ], %o5
a009585c:  98 10 62 90  or  %g1, 0x290, %o4
a0095860:  80 a3 60 42  cmp  %o5, 0x42
a0095864:  12 80 00 07  bne  0xa0095880
a0095868:  90 10 20 03  mov  3, %o0
a009586c:  94 10 24 02  mov  0x402, %o2
a0095870:  92 10 27 50  mov  0x750, %o1
a0095874:  d4 33 21 ae  sth  %o2, [ %o4 + 0x1ae ]
a0095878:  40 00 4e d1  call  0xa00a93bc
a009587c:  d2 33 21 ac  sth  %o1, [ %o4 + 0x1ac ]
a0095880:  90 10 20 01  mov  1, %o0
a0095884:  40 00 4e f9  call  0xa00a9468
a0095888:  92 10 20 02  mov  2, %o1
a009588c:  90 10 20 00  clr  %o0
a0095890:  40 00 77 11  call  0xa00b34d4
a0095894:  92 10 20 01  mov  1, %o1
a0095898:  9e 10 20 0c  mov  0xc, %o7
a009589c:  90 10 20 01  mov  1, %o0
a00958a0:  de 24 23 ec  st  %o7, [ %l0 + 0x3ec ]
a00958a4:  40 00 4d da  call  0xa00a900c
a00958a8:  92 10 20 01  mov  1, %o1
a00958ac:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00958b0:  d8 0a 20 8e  ldub  [ %o0 + 0x8e ], %o4	! 0xa802b08e
a00958b4:  96 13 20 02  or  %o4, 2, %o3
a00958b8:  d6 2a 20 8e  stb  %o3, [ %o0 + 0x8e ]
a00958bc:  81 c7 e0 08  ret
a00958c0:  81 e8 00 00  restore
