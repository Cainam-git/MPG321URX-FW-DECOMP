# leon2m FUN_a009a078 0xa009a078-0xa009a0d4 (92 bytes)
a009a078:  9d e3 bf 98  save  %sp, -104, %sp
a009a07c:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a009a080:  d4 04 23 ec  ld  [ %l0 + 0x3ec ], %o2	! 0xa802afec
a009a084:  92 02 a0 3d  add  %o2, 0x3d, %o1
a009a088:  40 00 3c cd  call  0xa00a93bc
a009a08c:  90 0a 60 ff  and  %o1, 0xff, %o0
a009a090:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a009a094:  d2 0a 20 7e  ldub  [ %o0 + 0x7e ], %o1	! 0xa802d47e
a009a098:  94 10 20 01  mov  1, %o2
a009a09c:  40 00 38 28  call  0xa00a813c
a009a0a0:  90 10 20 01  mov  1, %o0
a009a0a4:  82 10 20 36  mov  0x36, %g1
a009a0a8:  c2 24 23 ec  st  %g1, [ %l0 + 0x3ec ]
a009a0ac:  90 10 20 02  mov  2, %o0
a009a0b0:  40 00 3b d7  call  0xa00a900c
a009a0b4:  92 10 20 01  mov  1, %o1
a009a0b8:  90 10 20 01  mov  1, %o0
a009a0bc:  40 00 3c eb  call  0xa00a9468
a009a0c0:  92 10 20 02  mov  2, %o1
a009a0c4:  b0 10 20 00  clr  %i0
a009a0c8:  40 00 65 03  call  0xa00b34d4
a009a0cc:  93 e8 20 01  restore  %g0, 1, %o1
a009a0d0:  01 00 00 00  nop
