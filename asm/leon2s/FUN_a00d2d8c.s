# leon2s FUN_a00d2d8c 0xa00d2d8c-0xa00d2e00 (116 bytes)  [FUN_a00d2df8 = unreachable ret/restore tail, merged]
a00d2d8c:  9d e3 bf 98  save  %sp, -104, %sp
a00d2d90:  31 2a 01 e3  sethi  %hi(0xa8078c00), %i0
a00d2d94:  c2 0e 20 26  ldub  [ %i0 + 0x26 ], %g1	! 0xa8078c26
a00d2d98:  92 10 20 01  mov  1, %o1
a00d2d9c:  80 a0 60 00  cmp  %g1, 0
a00d2da0:  12 80 00 15  bne  0xa00d2df4
a00d2da4:  90 10 20 00  clr  %o0
a00d2da8:  7f ff fd 1a  call  0xa00d2210
a00d2dac:  01 00 00 00  nop
a00d2db0:  92 10 20 01  mov  1, %o1	! 0x1
a00d2db4:  7f ff fd 35  call  0xa00d2288
a00d2db8:  90 10 20 00  clr  %o0
a00d2dbc:  92 10 20 01  mov  1, %o1
a00d2dc0:  7f ff fd 7f  call  0xa00d23bc
a00d2dc4:  90 10 20 00  clr  %o0
a00d2dc8:  92 10 20 01  mov  1, %o1
a00d2dcc:  7f ff fd 4d  call  0xa00d2300
a00d2dd0:  90 10 20 00  clr  %o0
a00d2dd4:  90 10 20 00  clr  %o0
a00d2dd8:  7f ff fd 97  call  0xa00d2434
a00d2ddc:  92 10 20 01  mov  1, %o1
a00d2de0:  82 10 20 01  mov  1, %g1
a00d2de4:  c2 2e 20 26  stb  %g1, [ %i0 + 0x26 ]
a00d2de8:  31 27 c7 19  sethi  %hi(0x9f1c6400), %i0
a00d2dec:  40 3a c1 b6  call  0xa0f834c4
a00d2df0:  91 ee 20 20  restore  %i0, 0x20, %o0
a00d2df4:  01 00 00 00  nop
a00d2df8:  81 c7 e0 08  ret
a00d2dfc:  81 e8 00 00  restore
