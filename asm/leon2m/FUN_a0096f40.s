# leon2m FUN_a0096f40 0xa0096f40-0xa0096fe8 (168 bytes)
a0096f40:  9d e3 bf 98  save  %sp, -104, %sp
a0096f44:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0096f48:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a0096f4c:  40 02 b5 ac  call  0xa01445fc
a0096f50:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a0096f54:  82 0a 20 ff  and  %o0, 0xff, %g1
a0096f58:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0096f5c:  90 10 20 01  mov  1, %o0
a0096f60:  b0 10 20 00  clr  %i0
a0096f64:  80 a0 60 01  cmp  %g1, 1
a0096f68:  02 80 00 07  be  0xa0096f84
a0096f6c:  b2 10 20 01  mov  1, %i1
a0096f70:  40 02 b5 8b  call  0xa014459c
a0096f74:  01 00 00 00  nop
a0096f78:  d0 2c 20 1e  stb  %o0, [ %l0 + 0x1e ]
a0096f7c:  40 00 86 22  call  0xa00b8804
a0096f80:  81 e8 00 00  restore
a0096f84:  da 04 63 ec  ld  [ %l1 + 0x3ec ], %o5
a0096f88:  98 03 7f e2  add  %o5, -30, %o4
a0096f8c:  40 00 47 d7  call  0xa00a8ee8
a0096f90:  90 0b 20 ff  and  %o4, 0xff, %o0
a0096f94:  d6 04 63 ec  ld  [ %l1 + 0x3ec ], %o3
a0096f98:  94 02 ff e2  add  %o3, -30, %o2
a0096f9c:  90 0a a0 ff  and  %o2, 0xff, %o0
a0096fa0:  40 00 4c 1f  call  0xa00aa01c
a0096fa4:  92 10 20 00  clr  %o1
a0096fa8:  40 02 b5 95  call  0xa01445fc
a0096fac:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a0096fb0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0096fb4:  40 00 48 16  call  0xa00a900c
a0096fb8:  92 10 20 00  clr  %o1
a0096fbc:  92 10 20 06  mov  6, %o1
a0096fc0:  d2 24 63 ec  st  %o1, [ %l1 + 0x3ec ]
a0096fc4:  90 10 20 04  mov  4, %o0
a0096fc8:  40 00 74 5f  call  0xa00b4144
a0096fcc:  92 10 20 01  mov  1, %o1
a0096fd0:  90 10 20 01  mov  1, %o0
a0096fd4:  40 00 49 25  call  0xa00a9468
a0096fd8:  92 10 20 02  mov  2, %o1
a0096fdc:  40 00 71 3e  call  0xa00b34d4
a0096fe0:  81 e8 00 00  restore
a0096fe4:  01 00 00 00  nop
