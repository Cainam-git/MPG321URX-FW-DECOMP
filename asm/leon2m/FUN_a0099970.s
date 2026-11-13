# leon2m FUN_a0099970 0xa0099970-0xa00999ec (124 bytes)
a0099970:  9d e3 bf 98  save  %sp, -104, %sp
a0099974:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0099978:  f2 04 63 ec  ld  [ %l1 + 0x3ec ], %i1	! 0xa802afec
a009997c:  b0 06 7f bc  add  %i1, -68, %i0
a0099980:  40 00 3e 8f  call  0xa00a93bc
a0099984:  90 0e 20 ff  and  %i0, 0xff, %o0
a0099988:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a009998c:  a0 13 e2 90  or  %o7, 0x290, %l0	! 0xa802d290
a0099990:  da 0c 20 4a  ldub  [ %l0 + 0x4a ], %o5
a0099994:  98 03 60 02  add  %o5, 2, %o4
a0099998:  90 0b 20 ff  and  %o4, 0xff, %o0
a009999c:  40 00 3f 2d  call  0xa00a9650
a00999a0:  92 10 20 00  clr  %o1
a00999a4:  d6 0c 20 4a  ldub  [ %l0 + 0x4a ], %o3
a00999a8:  94 02 e0 02  add  %o3, 2, %o2
a00999ac:  92 0a a0 ff  and  %o2, 0xff, %o1
a00999b0:  90 10 20 01  mov  1, %o0
a00999b4:  40 00 39 e2  call  0xa00a813c
a00999b8:  94 10 20 00  clr  %o2
a00999bc:  d0 0c 20 4a  ldub  [ %l0 + 0x4a ], %o0
a00999c0:  92 02 20 02  add  %o0, 2, %o1
a00999c4:  92 0a 60 ff  and  %o1, 0xff, %o1
a00999c8:  90 10 20 01  mov  1, %o0
a00999cc:  40 00 39 dc  call  0xa00a813c
a00999d0:  94 10 20 01  mov  1, %o2
a00999d4:  82 10 20 0d  mov  0xd, %g1
a00999d8:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a00999dc:  b0 10 20 02  mov  2, %i0
a00999e0:  40 00 3d 8b  call  0xa00a900c
a00999e4:  93 e8 20 01  restore  %g0, 1, %o1
a00999e8:  01 00 00 00  nop
