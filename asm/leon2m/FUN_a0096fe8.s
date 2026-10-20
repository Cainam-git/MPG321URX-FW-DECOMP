# leon2m FUN_a0096fe8 0xa0096fe8-0xa0097090 (168 bytes)
a0096fe8:  9d e3 bf 98  save  %sp, -104, %sp
a0096fec:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0096ff0:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a0096ff4:  40 02 b5 82  call  0xa01445fc
a0096ff8:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a0096ffc:  82 0a 20 ff  and  %o0, 0xff, %g1
a0097000:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0097004:  90 10 20 02  mov  2, %o0
a0097008:  b0 10 20 00  clr  %i0
a009700c:  80 a0 60 02  cmp  %g1, 2
a0097010:  02 80 00 07  be  0xa009702c
a0097014:  b2 10 20 01  mov  1, %i1
a0097018:  40 02 b5 61  call  0xa014459c
a009701c:  01 00 00 00  nop
a0097020:  d0 2c 20 1e  stb  %o0, [ %l0 + 0x1e ]
a0097024:  40 00 85 f8  call  0xa00b8804
a0097028:  81 e8 00 00  restore
a009702c:  da 04 63 ec  ld  [ %l1 + 0x3ec ], %o5
a0097030:  98 03 7f e2  add  %o5, -30, %o4
a0097034:  40 00 47 ad  call  0xa00a8ee8
a0097038:  90 0b 20 ff  and  %o4, 0xff, %o0
a009703c:  d6 04 63 ec  ld  [ %l1 + 0x3ec ], %o3
a0097040:  94 02 ff e2  add  %o3, -30, %o2
a0097044:  90 0a a0 ff  and  %o2, 0xff, %o0
a0097048:  40 00 4b f5  call  0xa00aa01c
a009704c:  92 10 20 00  clr  %o1
a0097050:  40 02 b5 6b  call  0xa01445fc
a0097054:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a0097058:  90 0a 20 ff  and  %o0, 0xff, %o0
a009705c:  40 00 47 ec  call  0xa00a900c
a0097060:  92 10 20 00  clr  %o1
a0097064:  92 10 20 06  mov  6, %o1
a0097068:  d2 24 63 ec  st  %o1, [ %l1 + 0x3ec ]
a009706c:  90 10 20 04  mov  4, %o0
a0097070:  40 00 74 35  call  0xa00b4144
a0097074:  92 10 20 01  mov  1, %o1
a0097078:  90 10 20 01  mov  1, %o0
a009707c:  40 00 48 fb  call  0xa00a9468
a0097080:  92 10 20 02  mov  2, %o1
a0097084:  40 00 71 14  call  0xa00b34d4
a0097088:  81 e8 00 00  restore
a009708c:  01 00 00 00  nop
