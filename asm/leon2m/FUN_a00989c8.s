# leon2m FUN_a00989c8 0xa00989c8-0xa0098a74 (172 bytes)
a00989c8:  9d e3 bf 98  save  %sp, -104, %sp
a00989cc:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a00989d0:  a2 16 62 90  or  %i1, 0x290, %l1	! 0xa802d290
a00989d4:  21 09 24 92  sethi  %hi(0x24924800), %l0
a00989d8:  d4 0c 60 08  ldub  [ %l1 + 8 ], %o2
a00989dc:  b2 14 21 25  or  %l0, 0x125, %i1
a00989e0:  80 52 80 19  umul  %o2, %i1, %g0
a00989e4:  b1 40 00 00  rd  %y, %i0
a00989e8:  a4 22 80 18  sub  %o2, %i0, %l2
a00989ec:  9b 34 a0 01  srl  %l2, 1, %o5
a00989f0:  9e 06 00 0d  add  %i0, %o5, %o7
a00989f4:  83 33 e0 02  srl  %o7, 2, %g1
a00989f8:  99 28 60 03  sll  %g1, 3, %o4
a00989fc:  96 23 00 01  sub  %o4, %g1, %o3
a0098a00:  11 2a 00 97  sethi  %hi(0xa8025c00), %o0
a0098a04:  a4 22 80 0b  sub  %o2, %o3, %l2
a0098a08:  d4 2a 20 56  stb  %o2, [ %o0 + 0x56 ]
a0098a0c:  92 0c a0 ff  and  %l2, 0xff, %o1
a0098a10:  94 10 20 00  clr  %o2
a0098a14:  40 00 3d ca  call  0xa00a813c
a0098a18:  90 10 20 01  mov  1, %o0
a0098a1c:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a0098a20:  da 04 a3 ec  ld  [ %l2 + 0x3ec ], %o5	! 0xa802afec
a0098a24:  b0 03 7f d6  add  %o5, -42, %i0
a0098a28:  90 0e 20 ff  and  %i0, 0xff, %o0
a0098a2c:  40 00 41 78  call  0xa00a900c
a0098a30:  92 10 20 02  mov  2, %o1
a0098a34:  d0 0c 60 08  ldub  [ %l1 + 8 ], %o0
a0098a38:  80 52 00 19  umul  %o0, %i1, %g0
a0098a3c:  97 40 00 00  rd  %y, %o3
a0098a40:  9e 22 00 0b  sub  %o0, %o3, %o7
a0098a44:  99 33 e0 01  srl  %o7, 1, %o4
a0098a48:  94 02 c0 0c  add  %o3, %o4, %o2
a0098a4c:  a1 32 a0 02  srl  %o2, 2, %l0
a0098a50:  93 2c 20 03  sll  %l0, 3, %o1
a0098a54:  82 22 40 10  sub  %o1, %l0, %g1
a0098a58:  b0 22 00 01  sub  %o0, %g1, %i0
a0098a5c:  9a 02 20 92  add  %o0, 0x92, %o5
a0098a60:  da 24 a3 ec  st  %o5, [ %l2 + 0x3ec ]
a0098a64:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0098a68:  40 00 42 fa  call  0xa00a9650
a0098a6c:  93 e8 20 01  restore  %g0, 1, %o1
a0098a70:  01 00 00 00  nop
