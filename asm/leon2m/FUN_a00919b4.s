# leon2m FUN_a00919b4 0xa00919b4-0xa0091a68 (180 bytes)
a00919b4:  9d e3 bf 98  save  %sp, -104, %sp
a00919b8:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a00919bc:  d6 06 63 ec  ld  [ %i1 + 0x3ec ], %o3	! 0xa802afec
a00919c0:  94 02 ff f2  add  %o3, -14, %o2
a00919c4:  40 00 5d 49  call  0xa00a8ee8
a00919c8:  90 0a a0 ff  and  %o2, 0xff, %o0
a00919cc:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a00919d0:  90 02 7f f2  add  %o1, -14, %o0
a00919d4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00919d8:  40 00 61 c4  call  0xa00aa0e8
a00919dc:  92 10 20 00  clr  %o1
a00919e0:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1
a00919e4:  90 10 20 0e  mov  0xe, %o0
a00919e8:  80 a0 60 14  cmp  %g1, 0x14
a00919ec:  08 80 00 0f  bleu  0xa0091a28
a00919f0:  92 10 20 00  clr  %o1
a00919f4:  40 00 79 90  call  0xa00b0034
a00919f8:  90 10 20 01  mov  1, %o0
a00919fc:  98 10 20 03  mov  3, %o4
a0091a00:  d8 26 63 ec  st  %o4, [ %i1 + 0x3ec ]
a0091a04:  90 10 20 01  mov  1, %o0
a0091a08:  40 00 89 cf  call  0xa00b4144
a0091a0c:  92 10 20 01  mov  1, %o1
a0091a10:  90 10 20 01  mov  1, %o0
a0091a14:  40 00 5e 95  call  0xa00a9468
a0091a18:  92 10 20 02  mov  2, %o1
a0091a1c:  b0 10 20 00  clr  %i0
a0091a20:  40 00 86 ad  call  0xa00b34d4
a0091a24:  93 e8 20 01  restore  %g0, 1, %o1
a0091a28:  40 00 76 89  call  0xa00af44c
a0091a2c:  b0 10 20 00  clr  %i0
a0091a30:  90 10 20 00  clr  %o0
a0091a34:  40 00 5d 76  call  0xa00a900c
a0091a38:  92 10 20 00  clr  %o1
a0091a3c:  98 10 20 03  mov  3, %o4
a0091a40:  d8 26 63 ec  st  %o4, [ %i1 + 0x3ec ]
a0091a44:  90 10 20 01  mov  1, %o0
a0091a48:  40 00 89 bf  call  0xa00b4144
a0091a4c:  92 10 20 01  mov  1, %o1
a0091a50:  90 10 20 01  mov  1, %o0
a0091a54:  40 00 5e 85  call  0xa00a9468
a0091a58:  92 10 20 02  mov  2, %o1
a0091a5c:  40 00 86 9e  call  0xa00b34d4
a0091a60:  93 e8 20 01  restore  %g0, 1, %o1
a0091a64:  01 00 00 00  nop
