# leon2m FUN_a0098280 0xa0098280-0xa00982f0 (112 bytes)
a0098280:  9d e3 bf 98  save  %sp, -104, %sp
a0098284:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a0098288:  a0 13 e2 90  or  %o7, 0x290, %l0	! 0xa802d290
a009828c:  9a 10 20 05  mov  5, %o5
a0098290:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a0098294:  da 2b 20 8f  stb  %o5, [ %o4 + 0x8f ]	! 0xa802b08f
a0098298:  40 00 77 e1  call  0xa00b621c
a009829c:  c0 2c 21 a3  clrb  [ %l0 + 0x1a3 ]
a00982a0:  d4 0c 20 1e  ldub  [ %l0 + 0x1e ], %o2
a00982a4:  17 2a 00 97  sethi  %hi(0xa8025c00), %o3
a00982a8:  d4 2a e0 55  stb  %o2, [ %o3 + 0x55 ]	! 0xa8025c55
a00982ac:  40 02 b0 d4  call  0xa01445fc
a00982b0:  90 0a a0 ff  and  %o2, 0xff, %o0
a00982b4:  92 0a 20 ff  and  %o0, 0xff, %o1
a00982b8:  90 02 60 d4  add  %o1, 0xd4, %o0
a00982bc:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a00982c0:  d0 20 63 ec  st  %o0, [ %g1 + 0x3ec ]	! 0xa802afec
a00982c4:  40 02 b0 ce  call  0xa01445fc
a00982c8:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a00982cc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00982d0:  40 00 44 e0  call  0xa00a9650
a00982d4:  92 10 20 00  clr  %o1
a00982d8:  40 02 b0 c9  call  0xa01445fc
a00982dc:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a00982e0:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00982e4:  40 00 44 db  call  0xa00a9650
a00982e8:  93 e8 20 01  restore  %g0, 1, %o1
a00982ec:  01 00 00 00  nop
