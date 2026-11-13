# leon2s FUN_a00d2c38 0xa00d2c38-0xa00d2ca8 (112 bytes)  [FUN_a00d2ca0 = unreachable ret/restore tail, merged]
a00d2c38:  9d e3 bf 98  save  %sp, -104, %sp
a00d2c3c:  31 2a 01 e3  sethi  %hi(0xa8078c00), %i0
a00d2c40:  c2 0e 20 25  ldub  [ %i0 + 0x25 ], %g1	! 0xa8078c25
a00d2c44:  92 10 20 00  clr  %o1
a00d2c48:  80 a0 60 01  cmp  %g1, 1
a00d2c4c:  12 80 00 14  bne  0xa00d2c9c
a00d2c50:  90 10 20 00  clr  %o0
a00d2c54:  7f ff fd 6f  call  0xa00d2210
a00d2c58:  01 00 00 00  nop
a00d2c5c:  92 10 20 00  clr  %o1	! 0x0
a00d2c60:  7f ff fd 8a  call  0xa00d2288
a00d2c64:  90 10 20 00  clr  %o0
a00d2c68:  92 10 20 00  clr  %o1
a00d2c6c:  7f ff fd d4  call  0xa00d23bc
a00d2c70:  90 10 20 00  clr  %o0
a00d2c74:  92 10 20 00  clr  %o1
a00d2c78:  7f ff fd a2  call  0xa00d2300
a00d2c7c:  90 10 20 00  clr  %o0
a00d2c80:  90 10 20 00  clr  %o0
a00d2c84:  7f ff fd ec  call  0xa00d2434
a00d2c88:  92 10 20 00  clr  %o1
a00d2c8c:  c0 2e 20 25  clrb  [ %i0 + 0x25 ]
a00d2c90:  31 27 c7 18  sethi  %hi(0x9f1c6000), %i0
a00d2c94:  40 3a c2 0c  call  0xa0f834c4
a00d2c98:  91 ee 23 d8  restore  %i0, 0x3d8, %o0
a00d2c9c:  01 00 00 00  nop
a00d2ca0:  81 c7 e0 08  ret
a00d2ca4:  81 e8 00 00  restore
