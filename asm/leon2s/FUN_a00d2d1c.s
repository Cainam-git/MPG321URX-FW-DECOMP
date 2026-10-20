# leon2s FUN_a00d2d1c 0xa00d2d1c-0xa00d2d8c (112 bytes)  [FUN_a00d2d84 = unreachable ret/restore tail, merged]
a00d2d1c:  9d e3 bf 98  save  %sp, -104, %sp
a00d2d20:  31 2a 01 e3  sethi  %hi(0xa8078c00), %i0
a00d2d24:  c2 0e 20 26  ldub  [ %i0 + 0x26 ], %g1	! 0xa8078c26
a00d2d28:  92 10 20 00  clr  %o1
a00d2d2c:  80 a0 60 01  cmp  %g1, 1
a00d2d30:  12 80 00 14  bne  0xa00d2d80
a00d2d34:  90 10 20 00  clr  %o0
a00d2d38:  7f ff fd 36  call  0xa00d2210
a00d2d3c:  01 00 00 00  nop
a00d2d40:  92 10 20 00  clr  %o1	! 0x0
a00d2d44:  7f ff fd 51  call  0xa00d2288
a00d2d48:  90 10 20 00  clr  %o0
a00d2d4c:  92 10 20 00  clr  %o1
a00d2d50:  7f ff fd 9b  call  0xa00d23bc
a00d2d54:  90 10 20 00  clr  %o0
a00d2d58:  92 10 20 00  clr  %o1
a00d2d5c:  7f ff fd 69  call  0xa00d2300
a00d2d60:  90 10 20 00  clr  %o0
a00d2d64:  90 10 20 00  clr  %o0
a00d2d68:  7f ff fd b3  call  0xa00d2434
a00d2d6c:  92 10 20 00  clr  %o1
a00d2d70:  c0 2e 20 26  clrb  [ %i0 + 0x26 ]
a00d2d74:  31 27 c7 19  sethi  %hi(0x9f1c6400), %i0
a00d2d78:  40 3a c1 d3  call  0xa0f834c4
a00d2d7c:  91 ee 20 08  restore  %i0, 8, %o0
a00d2d80:  01 00 00 00  nop
a00d2d84:  81 c7 e0 08  ret
a00d2d88:  81 e8 00 00  restore
