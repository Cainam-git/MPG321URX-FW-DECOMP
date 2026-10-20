# leon2s TMDS_PowerOn 0xa0074c78-0xa0074cf8 (128 bytes)
a0074c78:  9d e3 bf 98  save  %sp, -104, %sp
a0074c7c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0074c80:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a0074c84:  92 10 00 18  mov  %i0, %o1
a0074c88:  7f ff f8 ef  call  0xa0073044
a0074c8c:  90 12 22 48  or  %o0, 0x248, %o0
a0074c90:  90 10 00 18  mov  %i0, %o0
a0074c94:  7f ff fa e2  call  0xa007381c
a0074c98:  92 10 20 01  mov  1, %o1
a0074c9c:  17 00 00 07  sethi  %hi(0x1c00), %o3
a0074ca0:  96 12 e0 04  or  %o3, 4, %o3	! 0x1c04
a0074ca4:  90 10 20 01  mov  1, %o0
a0074ca8:  92 10 20 07  mov  7, %o1
a0074cac:  40 00 c9 de  call  0xa00a7424
a0074cb0:  94 10 00 18  mov  %i0, %o2
a0074cb4:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a0074cb8:  96 12 e0 04  or  %o3, 4, %o3	! 0x2c04
a0074cbc:  90 10 20 01  mov  1, %o0
a0074cc0:  92 10 20 07  mov  7, %o1
a0074cc4:  40 00 c9 d8  call  0xa00a7424
a0074cc8:  94 10 00 18  mov  %i0, %o2
a0074ccc:  90 10 00 18  mov  %i0, %o0
a0074cd0:  13 00 00 04  sethi  %hi(0x1000), %o1
a0074cd4:  94 10 3f 00  mov  -256, %o2
a0074cd8:  40 00 c9 ec  call  0xa00a7488
a0074cdc:  96 10 20 f9  mov  0xf9, %o3
a0074ce0:  90 10 00 18  mov  %i0, %o0
a0074ce4:  7f ff fb d0  call  0xa0073c24
a0074ce8:  92 10 20 01  mov  1, %o1
a0074cec:  7f ff f9 fb  call  0xa00734d8
a0074cf0:  81 e8 00 00  restore
a0074cf4:  01 00 00 00  nop
