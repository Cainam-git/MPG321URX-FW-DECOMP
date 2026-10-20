# leon2m FUN_a009906c 0xa009906c-0xa00990e4 (120 bytes)
a009906c:  9d e3 bf 98  save  %sp, -104, %sp
a0099070:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a0099074:  a0 14 62 90  or  %l1, 0x290, %l0	! 0xa802d290
a0099078:  d0 04 20 a8  ld  [ %l0 + 0xa8 ], %o0
a009907c:  83 32 20 0f  srl  %o0, 0xf, %g1
a0099080:  92 08 60 01  and  %g1, 1, %o1
a0099084:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a0099088:  d2 2b 60 56  stb  %o1, [ %o5 + 0x56 ]	! 0xa8025c56
a009908c:  94 10 20 00  clr  %o2
a0099090:  40 00 3c 2b  call  0xa00a813c
a0099094:  90 10 20 01  mov  1, %o0
a0099098:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009909c:  de 04 63 ec  ld  [ %l1 + 0x3ec ], %o7	! 0xa802afec
a00990a0:  98 03 ff d6  add  %o7, -42, %o4
a00990a4:  90 0b 20 ff  and  %o4, 0xff, %o0
a00990a8:  40 00 3f d9  call  0xa00a900c
a00990ac:  92 10 20 02  mov  2, %o1
a00990b0:  d6 04 20 a8  ld  [ %l0 + 0xa8 ], %o3
a00990b4:  95 32 e0 0f  srl  %o3, 0xf, %o2
a00990b8:  90 0a a0 01  and  %o2, 1, %o0
a00990bc:  92 02 20 b4  add  %o0, 0xb4, %o1
a00990c0:  d2 24 63 ec  st  %o1, [ %l1 + 0x3ec ]
a00990c4:  40 00 41 63  call  0xa00a9650
a00990c8:  92 10 20 01  mov  1, %o1
a00990cc:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00990d0:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a00990d4:  82 12 20 02  or  %o0, 2, %g1
a00990d8:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a00990dc:  81 c7 e0 08  ret
a00990e0:  81 e8 00 00  restore
