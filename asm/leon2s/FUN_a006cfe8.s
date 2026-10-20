# leon2s FUN_a006cfe8 0xa006cfe8-0xa006d050 (104 bytes)  [FUN_a006d048 = unreachable ret/restore tail, merged]
a006cfe8:  9d e3 bf 98  save  %sp, -104, %sp
a006cfec:  33 2a 01 e1  sethi  %hi(0xa8078400), %i1
a006cff0:  11 28 01 96  sethi  %hi(0xa0065800), %o0
a006cff4:  c2 0e 63 f4  ldub  [ %i1 + 0x3f4 ], %g1
a006cff8:  21 2a 01 e1  sethi  %hi(0xa8078400), %l0
a006cffc:  80 a0 60 01  cmp  %g1, 1
a006d000:  12 80 00 11  bne  0xa006d044
a006d004:  90 12 23 c8  or  %o0, 0x3c8, %o0
a006d008:  40 00 18 0f  call  0xa0073044
a006d00c:  d2 0c 23 e0  ldub  [ %l0 + 0x3e0 ], %o1
a006d010:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a006d014:  9a 10 63 e4  or  %g1, 0x3e4, %o5	! 0xa80787e4
a006d018:  d0 00 63 e4  ld  [ %g1 + 0x3e4 ], %o0
a006d01c:  d6 03 60 0c  ld  [ %o5 + 0xc ], %o3
a006d020:  d2 03 60 04  ld  [ %o5 + 4 ], %o1
a006d024:  7f ff ff 00  call  0xa006cc24
a006d028:  d4 03 60 08  ld  [ %o5 + 8 ], %o2
a006d02c:  40 00 0b ac  call  0xa006fedc
a006d030:  c0 2e 63 f4  clrb  [ %i1 + 0x3f4 ]
a006d034:  31 28 01 96  sethi  %hi(0xa0065800), %i0
a006d038:  f2 0c 23 e0  ldub  [ %l0 + 0x3e0 ], %i1
a006d03c:  40 00 18 02  call  0xa0073044
a006d040:  91 ee 23 e0  restore  %i0, 0x3e0, %o0
a006d044:  01 00 00 00  nop
a006d048:  81 c7 e0 08  ret
a006d04c:  81 e8 00 00  restore
