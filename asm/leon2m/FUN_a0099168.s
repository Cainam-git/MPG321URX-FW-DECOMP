# leon2m FUN_a0099168 0xa0099168-0xa00991ec (132 bytes)
a0099168:  9d e3 bf 98  save  %sp, -104, %sp
a009916c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a0099170:  a0 14 22 90  or  %l0, 0x290, %l0	! 0xa802d290
a0099174:  d4 04 20 a8  ld  [ %l0 + 0xa8 ], %o2
a0099178:  91 32 a0 0f  srl  %o2, 0xf, %o0
a009917c:  40 00 40 90  call  0xa00a93bc
a0099180:  90 0a 20 01  and  %o0, 1, %o0
a0099184:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a0099188:  da 0a 60 56  ldub  [ %o1 + 0x56 ], %o5	! 0xa8025c56
a009918c:  b0 0b 60 01  and  %o5, 1, %i0
a0099190:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a0099194:  33 00 00 20  sethi  %hi(0x8000), %i1
a0099198:  9e 28 40 19  andn  %g1, %i1, %o7
a009919c:  99 2e 20 0f  sll  %i0, 0xf, %o4
a00991a0:  94 13 c0 0c  or  %o7, %o4, %o2
a00991a4:  97 32 a0 0f  srl  %o2, 0xf, %o3
a00991a8:  90 0a e0 01  and  %o3, 1, %o0
a00991ac:  d4 24 20 a8  st  %o2, [ %l0 + 0xa8 ]
a00991b0:  40 00 41 28  call  0xa00a9650
a00991b4:  92 10 20 00  clr  %o1
a00991b8:  d0 04 20 a8  ld  [ %l0 + 0xa8 ], %o0
a00991bc:  93 32 20 0f  srl  %o0, 0xf, %o1
a00991c0:  92 0a 60 01  and  %o1, 1, %o1
a00991c4:  90 10 20 01  mov  1, %o0
a00991c8:  40 00 3b dd  call  0xa00a813c
a00991cc:  94 10 20 01  mov  1, %o2
a00991d0:  9a 10 20 2e  mov  0x2e, %o5
a00991d4:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a00991d8:  da 20 63 ec  st  %o5, [ %g1 + 0x3ec ]	! 0xa802afec
a00991dc:  b0 10 20 04  mov  4, %i0
a00991e0:  40 00 3f 8b  call  0xa00a900c
a00991e4:  93 e8 20 01  restore  %g0, 1, %o1
a00991e8:  01 00 00 00  nop
