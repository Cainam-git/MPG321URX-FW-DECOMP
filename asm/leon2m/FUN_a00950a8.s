# leon2m FUN_a00950a8 0xa00950a8-0xa0095134 (140 bytes)
a00950a8:  9d e3 bf 98  save  %sp, -104, %sp
a00950ac:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a00950b0:  d2 04 a3 ec  ld  [ %l2 + 0x3ec ], %o1	! 0xa802afec
a00950b4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00950b8:  a2 12 a2 90  or  %o2, 0x290, %l1	! 0xa802d290
a00950bc:  90 02 60 30  add  %o1, 0x30, %o0
a00950c0:  e0 0c 60 20  ldub  [ %l1 + 0x20 ], %l0
a00950c4:  40 02 bd 36  call  0xa014459c
a00950c8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00950cc:  82 0a 20 ff  and  %o0, 0xff, %g1
a00950d0:  d0 2c 60 20  stb  %o0, [ %l1 + 0x20 ]
a00950d4:  80 a0 40 10  cmp  %g1, %l0
a00950d8:  02 80 00 04  be  0xa00950e8
a00950dc:  90 10 20 01  mov  1, %o0
a00950e0:  40 01 02 16  call  0xa00d5938
a00950e4:  01 00 00 00  nop
a00950e8:  90 10 20 0f  mov  0xf, %o0	! 0xf
a00950ec:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00950f0:  40 00 4e e6  call  0xa00a8c88
a00950f4:  d0 28 60 8f  stb  %o0, [ %g1 + 0x8f ]	! 0xa802b08f
a00950f8:  40 00 4d 7c  call  0xa00a86e8
a00950fc:  a0 10 20 7a  mov  0x7a, %l0
a0095100:  e0 24 a3 ec  st  %l0, [ %l2 + 0x3ec ]
a0095104:  90 10 20 00  clr  %o0
a0095108:  40 00 51 52  call  0xa00a9650
a009510c:  92 10 20 01  mov  1, %o1
a0095110:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a0095114:  e4 0a e0 8e  ldub  [ %o3 + 0x8e ], %l2	! 0xa802b08e
a0095118:  d8 0c 61 a4  ldub  [ %l1 + 0x1a4 ], %o4
a009511c:  9a 14 a0 02  or  %l2, 2, %o5
a0095120:  1f 2a 00 97  sethi  %hi(0xa8025c00), %o7
a0095124:  d8 2b e0 55  stb  %o4, [ %o7 + 0x55 ]	! 0xa8025c55
a0095128:  da 2a e0 8e  stb  %o5, [ %o3 + 0x8e ]
a009512c:  81 c7 e0 08  ret
a0095130:  81 e8 00 00  restore
