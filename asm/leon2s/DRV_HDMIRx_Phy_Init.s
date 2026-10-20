# leon2s DRV_HDMIRx_Phy_Init 0xa0074bf8-0xa0074c48 (80 bytes)
a0074bf8:  9d e3 bf 98  save  %sp, -104, %sp
a0074bfc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0074c00:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0074c04:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a0074c08:  b0 10 20 00  clr  %i0
a0074c0c:  80 88 60 01  btst  1, %g1
a0074c10:  90 12 22 20  or  %o0, 0x220, %o0
a0074c14:  02 80 00 04  be  0xa0074c24
a0074c18:  92 10 23 e7  mov  0x3e7, %o1
a0074c1c:  7f ff f9 0a  call  0xa0073044
a0074c20:  01 00 00 00  nop
a0074c24:  7f ff fc 08  call  0xa0073c44
a0074c28:  01 00 00 00  nop
a0074c2c:  7f ff fa 35  call  0xa0073500
a0074c30:  01 00 00 00  nop
a0074c34:  7f ff fa 51  call  0xa0073578
a0074c38:  90 10 20 00  clr  %o0	! 0x0
a0074c3c:  7f ff fa 41  call  0xa0073540
a0074c40:  81 e8 00 00  restore
a0074c44:  01 00 00 00  nop
