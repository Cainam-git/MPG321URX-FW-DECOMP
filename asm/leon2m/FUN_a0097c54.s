# leon2m FUN_a0097c54 0xa0097c54-0xa0097cb4 (96 bytes)
a0097c54:  9d e3 bf 98  save  %sp, -104, %sp
a0097c58:  b0 10 20 05  mov  5, %i0
a0097c5c:  33 2a 00 ac  sethi  %hi(0xa802b000), %i1
a0097c60:  40 00 4d b8  call  0xa00ab340
a0097c64:  f0 2e 60 8f  stb  %i0, [ %i1 + 0x8f ]	! 0xa802b08f
a0097c68:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a0097c6c:  a0 13 e2 90  or  %o7, 0x290, %l0	! 0xa802d290
a0097c70:  d4 04 20 30  ld  [ %l0 + 0x30 ], %o2
a0097c74:  91 32 a0 04  srl  %o2, 4, %o0
a0097c78:  98 0a 20 0f  and  %o0, 0xf, %o4
a0097c7c:  90 0b 20 ff  and  %o4, 0xff, %o0
a0097c80:  96 02 20 d8  add  %o0, 0xd8, %o3
a0097c84:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a0097c88:  d6 22 63 ec  st  %o3, [ %o1 + 0x3ec ]	! 0xa802afec
a0097c8c:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a0097c90:  d8 2b 60 55  stb  %o4, [ %o5 + 0x55 ]	! 0xa8025c55
a0097c94:  40 00 46 6f  call  0xa00a9650
a0097c98:  92 10 20 00  clr  %o1
a0097c9c:  c2 04 20 30  ld  [ %l0 + 0x30 ], %g1
a0097ca0:  b1 30 60 04  srl  %g1, 4, %i0
a0097ca4:  b0 0e 20 0f  and  %i0, 0xf, %i0
a0097ca8:  40 00 46 6a  call  0xa00a9650
a0097cac:  93 e8 20 01  restore  %g0, 1, %o1
a0097cb0:  01 00 00 00  nop
