# leon2m FUN_a0096e9c 0xa0096e9c-0xa0096f40 (164 bytes)
a0096e9c:  9d e3 bf 98  save  %sp, -104, %sp
a0096ea0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0096ea4:  a0 10 62 90  or  %g1, 0x290, %l0	! 0xa802d290
a0096ea8:  40 02 b5 d5  call  0xa01445fc
a0096eac:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a0096eb0:  80 8a 20 ff  btst  0xff, %o0
a0096eb4:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0096eb8:  b0 10 20 00  clr  %i0
a0096ebc:  b2 10 20 01  mov  1, %i1
a0096ec0:  12 80 00 1a  bne  0xa0096f28
a0096ec4:  90 10 20 00  clr  %o0
a0096ec8:  d8 04 63 ec  ld  [ %l1 + 0x3ec ], %o4
a0096ecc:  96 03 3f e2  add  %o4, -30, %o3
a0096ed0:  40 00 48 06  call  0xa00a8ee8
a0096ed4:  90 0a e0 ff  and  %o3, 0xff, %o0
a0096ed8:  d4 04 63 ec  ld  [ %l1 + 0x3ec ], %o2
a0096edc:  92 02 bf e2  add  %o2, -30, %o1
a0096ee0:  90 0a 60 ff  and  %o1, 0xff, %o0
a0096ee4:  40 00 4c 4e  call  0xa00aa01c
a0096ee8:  92 10 20 00  clr  %o1
a0096eec:  40 02 b5 c4  call  0xa01445fc
a0096ef0:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a0096ef4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0096ef8:  40 00 48 45  call  0xa00a900c
a0096efc:  92 10 20 00  clr  %o1
a0096f00:  90 10 20 06  mov  6, %o0
a0096f04:  d0 24 63 ec  st  %o0, [ %l1 + 0x3ec ]
a0096f08:  90 10 20 04  mov  4, %o0
a0096f0c:  40 00 74 8e  call  0xa00b4144
a0096f10:  92 10 20 01  mov  1, %o1
a0096f14:  90 10 20 01  mov  1, %o0
a0096f18:  40 00 49 54  call  0xa00a9468
a0096f1c:  92 10 20 02  mov  2, %o1
a0096f20:  40 00 71 6d  call  0xa00b34d4
a0096f24:  81 e8 00 00  restore
a0096f28:  40 02 b5 9d  call  0xa014459c
a0096f2c:  01 00 00 00  nop
a0096f30:  d0 2c 20 1e  stb  %o0, [ %l0 + 0x1e ]
a0096f34:  40 00 86 34  call  0xa00b8804
a0096f38:  81 e8 00 00  restore
a0096f3c:  01 00 00 00  nop
