# leon2m FUN_a0099c0c 0xa0099c0c-0xa0099c64 (88 bytes)
a0099c0c:  9d e3 bf 98  save  %sp, -104, %sp
a0099c10:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a0099c14:  a0 12 e2 90  or  %o3, 0x290, %l0	! 0xa802d290
a0099c18:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0099c1c:  d4 04 63 ec  ld  [ %l1 + 0x3ec ], %o2	! 0xa802afec
a0099c20:  da 0c 21 dd  ldub  [ %l0 + 0x1dd ], %o5
a0099c24:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a0099c28:  90 02 bf cc  add  %o2, -52, %o0
a0099c2c:  da 2a 60 55  stb  %o5, [ %o1 + 0x55 ]
a0099c30:  90 0a 20 ff  and  %o0, 0xff, %o0
a0099c34:  40 00 3c f6  call  0xa00a900c
a0099c38:  92 10 20 02  mov  2, %o1
a0099c3c:  d0 0c 21 dd  ldub  [ %l0 + 0x1dd ], %o0
a0099c40:  82 02 20 f1  add  %o0, 0xf1, %g1
a0099c44:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a0099c48:  40 00 3e 82  call  0xa00a9650
a0099c4c:  92 10 20 01  mov  1, %o1
a0099c50:  f2 0c 21 dd  ldub  [ %l0 + 0x1dd ], %i1
a0099c54:  b0 10 20 01  mov  1, %i0
a0099c58:  40 00 39 39  call  0xa00a813c
a0099c5c:  95 e8 20 00  restore  %g0, 0, %o2
a0099c60:  01 00 00 00  nop
