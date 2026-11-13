# leon2m FUN_a00961d4 0xa00961d4-0xa0096230 (92 bytes)
a00961d4:  9d e3 bf 98  save  %sp, -104, %sp
a00961d8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00961dc:  a0 13 22 90  or  %o4, 0x290, %l0	! 0xa802d290
a00961e0:  d6 14 20 34  lduh  [ %l0 + 0x34 ], %o3
a00961e4:  92 0a e0 0f  and  %o3, 0xf, %o1
a00961e8:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a00961ec:  d2 2a a0 56  stb  %o1, [ %o2 + 0x56 ]	! 0xa8025c56
a00961f0:  90 10 20 01  mov  1, %o0
a00961f4:  40 00 47 d2  call  0xa00a813c
a00961f8:  94 10 20 00  clr  %o2
a00961fc:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0096200:  d2 04 63 ec  ld  [ %l1 + 0x3ec ], %o1	! 0xa802afec
a0096204:  90 02 7f eb  add  %o1, -21, %o0
a0096208:  90 0a 20 ff  and  %o0, 0xff, %o0
a009620c:  40 00 4b 80  call  0xa00a900c
a0096210:  92 10 20 02  mov  2, %o1
a0096214:  f0 14 20 34  lduh  [ %l0 + 0x34 ], %i0
a0096218:  b0 0e 20 0f  and  %i0, 0xf, %i0
a009621c:  82 06 20 64  add  %i0, 0x64, %g1
a0096220:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a0096224:  40 00 4d 0b  call  0xa00a9650
a0096228:  93 e8 20 01  restore  %g0, 1, %o1
a009622c:  01 00 00 00  nop
