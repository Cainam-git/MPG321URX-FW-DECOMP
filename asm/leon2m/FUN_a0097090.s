# leon2m FUN_a0097090 0xa0097090-0xa0097138 (168 bytes)
a0097090:  9d e3 bf 98  save  %sp, -104, %sp
a0097094:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0097098:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a009709c:  40 02 b5 58  call  0xa01445fc
a00970a0:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a00970a4:  82 0a 20 ff  and  %o0, 0xff, %g1
a00970a8:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00970ac:  90 10 20 03  mov  3, %o0
a00970b0:  b0 10 20 00  clr  %i0
a00970b4:  80 a0 60 03  cmp  %g1, 3
a00970b8:  02 80 00 07  be  0xa00970d4
a00970bc:  b2 10 20 01  mov  1, %i1
a00970c0:  40 02 b5 37  call  0xa014459c
a00970c4:  01 00 00 00  nop
a00970c8:  d0 2c 20 1e  stb  %o0, [ %l0 + 0x1e ]
a00970cc:  40 00 85 ce  call  0xa00b8804
a00970d0:  81 e8 00 00  restore
a00970d4:  da 04 63 ec  ld  [ %l1 + 0x3ec ], %o5
a00970d8:  98 03 7f e2  add  %o5, -30, %o4
a00970dc:  40 00 47 83  call  0xa00a8ee8
a00970e0:  90 0b 20 ff  and  %o4, 0xff, %o0
a00970e4:  d6 04 63 ec  ld  [ %l1 + 0x3ec ], %o3
a00970e8:  94 02 ff e2  add  %o3, -30, %o2
a00970ec:  90 0a a0 ff  and  %o2, 0xff, %o0
a00970f0:  40 00 4b cb  call  0xa00aa01c
a00970f4:  92 10 20 00  clr  %o1
a00970f8:  40 02 b5 41  call  0xa01445fc
a00970fc:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a0097100:  90 0a 20 ff  and  %o0, 0xff, %o0
a0097104:  40 00 47 c2  call  0xa00a900c
a0097108:  92 10 20 00  clr  %o1
a009710c:  92 10 20 06  mov  6, %o1
a0097110:  d2 24 63 ec  st  %o1, [ %l1 + 0x3ec ]
a0097114:  90 10 20 04  mov  4, %o0
a0097118:  40 00 74 0b  call  0xa00b4144
a009711c:  92 10 20 01  mov  1, %o1
a0097120:  90 10 20 01  mov  1, %o0
a0097124:  40 00 48 d1  call  0xa00a9468
a0097128:  92 10 20 02  mov  2, %o1
a009712c:  40 00 70 ea  call  0xa00b34d4
a0097130:  81 e8 00 00  restore
a0097134:  01 00 00 00  nop
