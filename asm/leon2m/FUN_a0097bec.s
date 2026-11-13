# leon2m FUN_a0097bec 0xa0097bec-0xa0097c54 (104 bytes)
a0097bec:  9d e3 bf 98  save  %sp, -104, %sp
a0097bf0:  82 10 20 05  mov  5, %g1
a0097bf4:  33 2a 00 ac  sethi  %hi(0xa802b000), %i1
a0097bf8:  c2 2e 60 8f  stb  %g1, [ %i1 + 0x8f ]	! 0xa802b08f
a0097bfc:  40 00 4d ab  call  0xa00ab2a8
a0097c00:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a0097c04:  a0 16 22 90  or  %i0, 0x290, %l0	! 0xa802d290
a0097c08:  d6 0c 20 31  ldub  [ %l0 + 0x31 ], %o3
a0097c0c:  9e 0a e0 ff  and  %o3, 0xff, %o7
a0097c10:  94 10 20 cf  mov  0xcf, %o2
a0097c14:  b2 10 20 02  mov  2, %i1
a0097c18:  92 22 80 0f  sub  %o2, %o7, %o1
a0097c1c:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0097c20:  90 26 40 0b  sub  %i1, %o3, %o0
a0097c24:  d2 23 63 ec  st  %o1, [ %o5 + 0x3ec ]
a0097c28:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a0097c2c:  d6 2b 20 55  stb  %o3, [ %o4 + 0x55 ]	! 0xa8025c55
a0097c30:  90 0a 20 ff  and  %o0, 0xff, %o0
a0097c34:  40 00 46 87  call  0xa00a9650
a0097c38:  92 10 20 00  clr  %o1
a0097c3c:  c2 0c 20 31  ldub  [ %l0 + 0x31 ], %g1
a0097c40:  b0 26 40 01  sub  %i1, %g1, %i0
a0097c44:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0097c48:  40 00 46 82  call  0xa00a9650
a0097c4c:  93 e8 20 01  restore  %g0, 1, %o1
a0097c50:  01 00 00 00  nop
