# leon2m FUN_a0096420 0xa0096420-0xa009645c (60 bytes)
a0096420:  9d e3 bf 98  save  %sp, -104, %sp
a0096424:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0096428:  d2 04 23 ec  ld  [ %l0 + 0x3ec ], %o1	! 0xa802afec
a009642c:  90 02 7f e8  add  %o1, -24, %o0
a0096430:  90 0a 20 ff  and  %o0, 0xff, %o0
a0096434:  40 00 4a f6  call  0xa00a900c
a0096438:  92 10 20 02  mov  2, %o1
a009643c:  82 10 20 6b  mov  0x6b, %g1
a0096440:  c2 24 23 ec  st  %g1, [ %l0 + 0x3ec ]
a0096444:  40 00 83 51  call  0xa00b7188
a0096448:  90 10 20 01  mov  1, %o0
a009644c:  b0 10 20 00  clr  %i0
a0096450:  40 00 4c 80  call  0xa00a9650
a0096454:  93 e8 20 01  restore  %g0, 1, %o1
a0096458:  01 00 00 00  nop
