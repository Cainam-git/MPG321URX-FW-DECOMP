# leon2s DRV_HDMI_PHY_Clr_EQ_Err 0xa0074e38-0xa0074ef4 (188 bytes)
a0074e38:  9d e3 bf 98  save  %sp, -104, %sp
a0074e3c:  92 06 20 41  add  %i0, 0x41, %o1
a0074e40:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0074e44:  21 00 00 07  sethi  %hi(0x1c00), %l0
a0074e48:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1
a0074e4c:  93 2a 60 18  sll  %o1, 0x18, %o1
a0074e50:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a0074e54:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a0074e58:  b2 14 22 a0  or  %l0, 0x2a0, %i1
a0074e5c:  b4 10 3f 00  mov  -256, %i2
a0074e60:  b6 10 20 87  mov  0x87, %i3
a0074e64:  80 88 60 02  btst  2, %g1
a0074e68:  93 3a 60 18  sra  %o1, 0x18, %o1
a0074e6c:  94 12 a0 58  or  %o2, 0x58, %o2
a0074e70:  90 12 22 78  or  %o0, 0x278, %o0
a0074e74:  02 80 00 04  be  0xa0074e84
a0074e78:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0074e7c:  7f ff f8 72  call  0xa0073044
a0074e80:  01 00 00 00  nop
a0074e84:  90 10 20 01  mov  1, %o0	! 0x1
a0074e88:  92 10 20 1d  mov  0x1d, %o1
a0074e8c:  94 10 00 18  mov  %i0, %o2
a0074e90:  40 00 c9 65  call  0xa00a7424
a0074e94:  96 14 22 94  or  %l0, 0x294, %o3
a0074e98:  90 10 20 01  mov  1, %o0
a0074e9c:  92 10 20 05  mov  5, %o1
a0074ea0:  94 10 00 18  mov  %i0, %o2
a0074ea4:  40 00 c9 60  call  0xa00a7424
a0074ea8:  96 14 22 98  or  %l0, 0x298, %o3
a0074eac:  90 10 20 01  mov  1, %o0
a0074eb0:  92 10 20 0d  mov  0xd, %o1
a0074eb4:  94 10 00 18  mov  %i0, %o2
a0074eb8:  40 00 c9 5b  call  0xa00a7424
a0074ebc:  96 14 22 98  or  %l0, 0x298, %o3
a0074ec0:  90 10 00 18  mov  %i0, %o0
a0074ec4:  92 14 22 a0  or  %l0, 0x2a0, %o1
a0074ec8:  94 10 3f 00  mov  -256, %o2
a0074ecc:  40 00 c9 6f  call  0xa00a7488
a0074ed0:  96 10 20 87  mov  0x87, %o3
a0074ed4:  90 10 00 18  mov  %i0, %o0
a0074ed8:  92 14 22 a0  or  %l0, 0x2a0, %o1
a0074edc:  94 10 3f 00  mov  -256, %o2
a0074ee0:  40 00 c9 6a  call  0xa00a7488
a0074ee4:  96 10 20 c7  mov  0xc7, %o3
a0074ee8:  40 00 c9 68  call  0xa00a7488
a0074eec:  81 e8 00 00  restore
a0074ef0:  01 00 00 00  nop
