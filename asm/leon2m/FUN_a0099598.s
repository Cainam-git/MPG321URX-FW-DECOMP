# leon2m FUN_a0099598 0xa0099598-0xa00995f0 (88 bytes)
a0099598:  9d e3 bf 98  save  %sp, -104, %sp
a009959c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00995a0:  a0 12 a2 90  or  %o2, 0x290, %l0	! 0xa802d290
a00995a4:  40 00 3f 86  call  0xa00a93bc
a00995a8:  d0 0c 21 7c  ldub  [ %l0 + 0x17c ], %o0
a00995ac:  11 2a 00 97  sethi  %hi(0xa8025c00), %o0
a00995b0:  d2 0a 20 56  ldub  [ %o0 + 0x56 ], %o1	! 0xa8025c56
a00995b4:  90 0a 60 ff  and  %o1, 0xff, %o0
a00995b8:  d2 2c 21 7c  stb  %o1, [ %l0 + 0x17c ]
a00995bc:  40 00 40 25  call  0xa00a9650
a00995c0:  92 10 20 00  clr  %o1
a00995c4:  d2 0c 21 7c  ldub  [ %l0 + 0x17c ], %o1
a00995c8:  90 10 20 01  mov  1, %o0
a00995cc:  40 00 3a dc  call  0xa00a813c
a00995d0:  94 10 20 01  mov  1, %o2
a00995d4:  9a 10 20 0b  mov  0xb, %o5
a00995d8:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a00995dc:  da 20 63 ec  st  %o5, [ %g1 + 0x3ec ]	! 0xa802afec
a00995e0:  b0 10 20 00  clr  %i0
a00995e4:  40 00 3e 8a  call  0xa00a900c
a00995e8:  93 e8 20 01  restore  %g0, 1, %o1
a00995ec:  01 00 00 00  nop
