# leon2m FUN_a0096c80 0xa0096c80-0xa0096ce4 (100 bytes)
a0096c80:  9d e3 bf 98  save  %sp, -104, %sp
a0096c84:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a0096c88:  a0 13 e2 90  or  %o7, 0x290, %l0	! 0xa802d290
a0096c8c:  da 04 20 ac  ld  [ %l0 + 0xac ], %o5
a0096c90:  99 33 60 12  srl  %o5, 0x12, %o4
a0096c94:  92 0b 20 03  and  %o4, 3, %o1
a0096c98:  17 2a 00 97  sethi  %hi(0xa8025c00), %o3
a0096c9c:  d2 2a e0 56  stb  %o1, [ %o3 + 0x56 ]	! 0xa8025c56
a0096ca0:  90 10 20 01  mov  1, %o0
a0096ca4:  40 00 45 26  call  0xa00a813c
a0096ca8:  94 10 20 00  clr  %o2
a0096cac:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0096cb0:  d4 04 63 ec  ld  [ %l1 + 0x3ec ], %o2	! 0xa802afec
a0096cb4:  92 02 bf e8  add  %o2, -24, %o1
a0096cb8:  90 0a 60 ff  and  %o1, 0xff, %o0
a0096cbc:  40 00 48 d4  call  0xa00a900c
a0096cc0:  92 10 20 02  mov  2, %o1
a0096cc4:  d0 04 20 ac  ld  [ %l0 + 0xac ], %o0
a0096cc8:  b1 32 20 12  srl  %o0, 0x12, %i0
a0096ccc:  b0 0e 20 03  and  %i0, 3, %i0
a0096cd0:  82 06 20 77  add  %i0, 0x77, %g1
a0096cd4:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a0096cd8:  40 00 4a 5e  call  0xa00a9650
a0096cdc:  93 e8 20 01  restore  %g0, 1, %o1
a0096ce0:  01 00 00 00  nop
