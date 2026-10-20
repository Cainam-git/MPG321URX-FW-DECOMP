# leon2s FUN_a0090e6c 0xa0090e6c-0xa0090f0c (160 bytes)  [FUN_a0090f04 = unreachable ret/restore tail, merged]
a0090e6c:  9d e3 bf 98  save  %sp, -104, %sp
a0090e70:  82 0e 60 ff  and  %i1, 0xff, %g1
a0090e74:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0090e78:  92 10 21 26  mov  0x126, %o1
a0090e7c:  94 10 20 01  mov  1, %o2
a0090e80:  96 10 20 01  mov  1, %o3
a0090e84:  b2 10 21 26  mov  0x126, %i1
a0090e88:  b4 10 20 04  mov  4, %i2
a0090e8c:  b6 10 20 01  mov  1, %i3
a0090e90:  80 a0 60 01  cmp  %g1, 1
a0090e94:  02 80 00 17  be  0xa0090ef0
a0090e98:  90 10 00 10  mov  %l0, %o0
a0090e9c:  80 a0 60 01  cmp  %g1, 1
a0090ea0:  14 80 00 08  bg  0xa0090ec0
a0090ea4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0090ea8:  b0 10 00 10  mov  %l0, %i0
a0090eac:  96 10 20 00  clr  %o3
a0090eb0:  80 a0 60 00  cmp  %g1, 0
a0090eb4:  02 80 00 0c  be  0xa0090ee4
a0090eb8:  b6 10 20 00  clr  %i3
a0090ebc:  30 80 00 11  b,a   0xa0090f00
a0090ec0:  90 10 00 18  mov  %i0, %o0
a0090ec4:  92 10 21 26  mov  0x126, %o1
a0090ec8:  94 10 20 01  mov  1, %o2
a0090ecc:  96 10 20 01  mov  1, %o3
a0090ed0:  b2 10 21 26  mov  0x126, %i1
a0090ed4:  b4 10 20 04  mov  4, %i2
a0090ed8:  80 a0 60 02  cmp  %g1, 2
a0090edc:  12 80 00 09  bne  0xa0090f00
a0090ee0:  b6 10 20 00  clr  %i3
a0090ee4:  40 00 56 35  call  0xa00a67b8
a0090ee8:  01 00 00 00  nop
a0090eec:  30 80 00 03  b,a   0xa0090ef8
a0090ef0:  40 00 56 32  call  0xa00a67b8
a0090ef4:  b0 10 00 10  mov  %l0, %i0
a0090ef8:  40 00 56 30  call  0xa00a67b8
a0090efc:  81 e8 00 00  restore
a0090f00:  01 00 00 00  nop
a0090f04:  81 c7 e0 08  ret
a0090f08:  81 e8 00 00  restore
