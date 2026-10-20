# leon2m FUN_a0092f2c 0xa0092f2c-0xa0092fd4 (168 bytes)
a0092f2c:  9d e3 bf 98  save  %sp, -104, %sp
a0092f30:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0092f34:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1	! 0xa802afec
a0092f38:  90 00 7f cc  add  %g1, -52, %o0
a0092f3c:  40 00 57 eb  call  0xa00a8ee8
a0092f40:  90 0a 20 ff  and  %o0, 0xff, %o0
a0092f44:  40 00 74 3c  call  0xa00b0034
a0092f48:  90 10 20 08  mov  8, %o0
a0092f4c:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1
a0092f50:  80 a0 60 3b  cmp  %g1, 0x3b
a0092f54:  02 80 00 0a  be  0xa0092f7c
a0092f58:  90 10 20 01  mov  1, %o0
a0092f5c:  80 a0 60 35  cmp  %g1, 0x35
a0092f60:  02 80 00 13  be  0xa0092fac
a0092f64:  92 10 20 02  mov  2, %o1
a0092f68:  94 10 20 0a  mov  0xa, %o2
a0092f6c:  d4 26 63 ec  st  %o2, [ %i1 + 0x3ec ]
a0092f70:  b0 10 20 08  mov  8, %i0
a0092f74:  40 00 84 74  call  0xa00b4144
a0092f78:  93 e8 20 01  restore  %g0, 1, %o1
a0092f7c:  9a 10 3f ff  mov  -1, %o5
a0092f80:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a0092f84:  40 00 61 4e  call  0xa00ab4bc
a0092f88:  da 2a 60 19  stb  %o5, [ %o1 + 0x19 ]	! 0xa802d419
a0092f8c:  90 10 20 02  mov  2, %o0
a0092f90:  40 00 59 36  call  0xa00a9468
a0092f94:  92 10 20 05  mov  5, %o1
a0092f98:  90 10 20 00  clr  %o0
a0092f9c:  40 00 59 33  call  0xa00a9468
a0092fa0:  92 10 20 00  clr  %o1
a0092fa4:  90 10 20 01  mov  1, %o0
a0092fa8:  92 10 20 02  mov  2, %o1
a0092fac:  40 00 59 2f  call  0xa00a9468
a0092fb0:  b0 10 20 08  mov  8, %i0
a0092fb4:  90 10 20 00  clr  %o0
a0092fb8:  40 00 81 47  call  0xa00b34d4
a0092fbc:  92 10 20 01  mov  1, %o1
a0092fc0:  94 10 20 0a  mov  0xa, %o2
a0092fc4:  d4 26 63 ec  st  %o2, [ %i1 + 0x3ec ]
a0092fc8:  40 00 84 5f  call  0xa00b4144
a0092fcc:  93 e8 20 01  restore  %g0, 1, %o1
a0092fd0:  01 00 00 00  nop
