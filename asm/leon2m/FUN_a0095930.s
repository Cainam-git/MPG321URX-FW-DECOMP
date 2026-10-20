# leon2m FUN_a0095930 0xa0095930-0xa0095984 (84 bytes)
a0095930:  9d e3 bf 98  save  %sp, -104, %sp
a0095934:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a0095938:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a009593c:  d4 04 23 ec  ld  [ %l0 + 0x3ec ], %o2	! 0xa802afec
a0095940:  da 0a e0 20  ldub  [ %o3 + 0x20 ], %o5
a0095944:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a0095948:  90 02 bf f5  add  %o2, -11, %o0
a009594c:  da 2a 60 56  stb  %o5, [ %o1 + 0x56 ]
a0095950:  90 0a 20 ff  and  %o0, 0xff, %o0
a0095954:  40 00 4d ae  call  0xa00a900c
a0095958:  92 10 20 02  mov  2, %o1
a009595c:  82 10 20 3f  mov  0x3f, %g1
a0095960:  c2 24 23 ec  st  %g1, [ %l0 + 0x3ec ]
a0095964:  90 10 20 01  mov  1, %o0
a0095968:  92 10 20 00  clr  %o1
a009596c:  40 00 49 f4  call  0xa00a813c
a0095970:  94 10 20 00  clr  %o2
a0095974:  b0 10 20 00  clr  %i0
a0095978:  40 00 4f 36  call  0xa00a9650
a009597c:  93 e8 20 01  restore  %g0, 1, %o1
a0095980:  01 00 00 00  nop
