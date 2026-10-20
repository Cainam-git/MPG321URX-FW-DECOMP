# leon2m FUN_a0094f58 0xa0094f58-0xa0094fc4 (108 bytes)
a0094f58:  9d e3 bf 98  save  %sp, -104, %sp
a0094f5c:  31 2a 00 97  sethi  %hi(0xa8025c00), %i0
a0094f60:  d8 0e 20 55  ldub  [ %i0 + 0x55 ], %o4	! 0xa8025c55
a0094f64:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a0094f68:  d8 2b e3 cf  stb  %o4, [ %o7 + 0x3cf ]	! 0xa802d3cf
a0094f6c:  40 00 4f 47  call  0xa00a8c88
a0094f70:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0094f74:  40 00 5d 05  call  0xa00ac388
a0094f78:  90 10 20 01  mov  1, %o0
a0094f7c:  d6 0c 20 56  ldub  [ %l0 + 0x56 ], %o3
a0094f80:  94 02 e0 01  add  %o3, 1, %o2
a0094f84:  92 0a a0 ff  and  %o2, 0xff, %o1
a0094f88:  90 10 20 01  mov  1, %o0
a0094f8c:  40 00 4c 6c  call  0xa00a813c
a0094f90:  94 10 20 01  mov  1, %o2
a0094f94:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a0094f98:  90 02 60 01  add  %o1, 1, %o0
a0094f9c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0094fa0:  40 00 51 ac  call  0xa00a9650
a0094fa4:  92 10 20 00  clr  %o1
a0094fa8:  9a 10 20 56  mov  0x56, %o5
a0094fac:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a0094fb0:  da 20 63 ec  st  %o5, [ %g1 + 0x3ec ]	! 0xa802afec
a0094fb4:  b0 10 20 00  clr  %i0
a0094fb8:  40 00 51 a6  call  0xa00a9650
a0094fbc:  93 e8 20 01  restore  %g0, 1, %o1
a0094fc0:  01 00 00 00  nop
