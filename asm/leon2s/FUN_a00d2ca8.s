# leon2s FUN_a00d2ca8 0xa00d2ca8-0xa00d2d1c (116 bytes)  [FUN_a00d2d14 = unreachable ret/restore tail, merged]
a00d2ca8:  9d e3 bf 98  save  %sp, -104, %sp
a00d2cac:  31 2a 01 e3  sethi  %hi(0xa8078c00), %i0
a00d2cb0:  c2 0e 20 25  ldub  [ %i0 + 0x25 ], %g1	! 0xa8078c25
a00d2cb4:  92 10 20 01  mov  1, %o1
a00d2cb8:  80 a0 60 00  cmp  %g1, 0
a00d2cbc:  12 80 00 15  bne  0xa00d2d10
a00d2cc0:  90 10 20 00  clr  %o0
a00d2cc4:  7f ff fd 53  call  0xa00d2210
a00d2cc8:  01 00 00 00  nop
a00d2ccc:  92 10 20 01  mov  1, %o1	! 0x1
a00d2cd0:  7f ff fd 6e  call  0xa00d2288
a00d2cd4:  90 10 20 00  clr  %o0
a00d2cd8:  92 10 20 01  mov  1, %o1
a00d2cdc:  7f ff fd b8  call  0xa00d23bc
a00d2ce0:  90 10 20 00  clr  %o0
a00d2ce4:  92 10 20 01  mov  1, %o1
a00d2ce8:  7f ff fd 86  call  0xa00d2300
a00d2cec:  90 10 20 00  clr  %o0
a00d2cf0:  90 10 20 00  clr  %o0
a00d2cf4:  7f ff fd d0  call  0xa00d2434
a00d2cf8:  92 10 20 00  clr  %o1
a00d2cfc:  82 10 20 01  mov  1, %g1
a00d2d00:  c2 2e 20 25  stb  %g1, [ %i0 + 0x25 ]
a00d2d04:  31 27 c7 18  sethi  %hi(0x9f1c6000), %i0
a00d2d08:  40 3a c1 ef  call  0xa0f834c4
a00d2d0c:  91 ee 23 f0  restore  %i0, 0x3f0, %o0
a00d2d10:  01 00 00 00  nop
a00d2d14:  81 c7 e0 08  ret
a00d2d18:  81 e8 00 00  restore
