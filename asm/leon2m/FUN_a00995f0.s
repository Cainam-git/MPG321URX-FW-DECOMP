# leon2m FUN_a00995f0 0xa00995f0-0xa0099658 (104 bytes)
a00995f0:  9d e3 bf 98  save  %sp, -104, %sp
a00995f4:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a00995f8:  a0 16 62 90  or  %i1, 0x290, %l0	! 0xa802d290
a00995fc:  de 0c 20 4a  ldub  [ %l0 + 0x4a ], %o7
a0099600:  98 03 e0 02  add  %o7, 2, %o4
a0099604:  92 0b 20 ff  and  %o4, 0xff, %o1
a0099608:  90 10 20 01  mov  1, %o0
a009960c:  40 00 3a cc  call  0xa00a813c
a0099610:  94 10 20 00  clr  %o2
a0099614:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0099618:  d6 04 63 ec  ld  [ %l1 + 0x3ec ], %o3	! 0xa802afec
a009961c:  92 02 ff f5  add  %o3, -11, %o1
a0099620:  90 0a 60 ff  and  %o1, 0xff, %o0
a0099624:  da 0c 20 4a  ldub  [ %l0 + 0x4a ], %o5
a0099628:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a009962c:  da 2a a0 56  stb  %o5, [ %o2 + 0x56 ]	! 0xa8025c56
a0099630:  40 00 3e 77  call  0xa00a900c
a0099634:  92 10 20 02  mov  2, %o1
a0099638:  d0 0c 20 4a  ldub  [ %l0 + 0x4a ], %o0
a009963c:  b0 02 20 02  add  %o0, 2, %i0
a0099640:  82 02 20 46  add  %o0, 0x46, %g1
a0099644:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a0099648:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009964c:  40 00 40 01  call  0xa00a9650
a0099650:  93 e8 20 01  restore  %g0, 1, %o1
a0099654:  01 00 00 00  nop
