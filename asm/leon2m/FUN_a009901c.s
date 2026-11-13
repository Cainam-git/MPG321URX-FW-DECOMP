# leon2m FUN_a009901c 0xa009901c-0xa009906c (80 bytes)
a009901c:  9d e3 bf 98  save  %sp, -104, %sp
a0099020:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0099024:  d2 04 63 ec  ld  [ %l1 + 0x3ec ], %o1	! 0xa802afec
a0099028:  90 02 60 4f  add  %o1, 0x4f, %o0
a009902c:  40 00 40 e4  call  0xa00a93bc
a0099030:  90 0a 20 ff  and  %o0, 0xff, %o0
a0099034:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0099038:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0	! 0xa8025c56
a009903c:  40 00 41 85  call  0xa00a9650
a0099040:  92 10 20 00  clr  %o1
a0099044:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a0099048:  90 10 20 01  mov  1, %o0
a009904c:  40 00 3c 3c  call  0xa00a813c
a0099050:  94 10 20 01  mov  1, %o2
a0099054:  82 10 20 2d  mov  0x2d, %g1
a0099058:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a009905c:  b0 10 20 03  mov  3, %i0
a0099060:  40 00 3f eb  call  0xa00a900c
a0099064:  93 e8 20 01  restore  %g0, 1, %o1
a0099068:  01 00 00 00  nop
