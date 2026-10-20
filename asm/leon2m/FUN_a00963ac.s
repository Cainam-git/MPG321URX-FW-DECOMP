# leon2m FUN_a00963ac 0xa00963ac-0xa00963e8 (60 bytes)
a00963ac:  9d e3 bf 98  save  %sp, -104, %sp
a00963b0:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00963b4:  d2 04 23 ec  ld  [ %l0 + 0x3ec ], %o1	! 0xa802afec
a00963b8:  90 02 7f e8  add  %o1, -24, %o0
a00963bc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00963c0:  40 00 4b 13  call  0xa00a900c
a00963c4:  92 10 20 02  mov  2, %o1
a00963c8:  82 10 20 6a  mov  0x6a, %g1
a00963cc:  c2 24 23 ec  st  %g1, [ %l0 + 0x3ec ]
a00963d0:  40 00 82 d4  call  0xa00b6f20
a00963d4:  90 10 20 01  mov  1, %o0
a00963d8:  b0 10 20 00  clr  %i0
a00963dc:  40 00 4c 9d  call  0xa00a9650
a00963e0:  93 e8 20 01  restore  %g0, 1, %o1
a00963e4:  01 00 00 00  nop
