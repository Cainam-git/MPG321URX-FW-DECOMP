# leon2m FUN_a01519d8 0xa01519d8-0xa0151aa4 (204 bytes)
a01519d8:  9d e3 bf 98  save  %sp, -104, %sp
a01519dc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01519e0:  80 a6 20 08  cmp  %i0, 8
a01519e4:  02 80 00 15  be  0xa0151a38
a01519e8:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a01519ec:  04 80 00 08  ble  0xa0151a0c
a01519f0:  80 a6 20 04  cmp  %i0, 4
a01519f4:  80 a6 20 10  cmp  %i0, 0x10
a01519f8:  02 80 00 19  be  0xa0151a5c
a01519fc:  80 a6 20 20  cmp  %i0, 0x20
a0151a00:  12 80 00 27  bne  0xa0151a9c
a0151a04:  90 10 20 01  mov  1, %o0
a0151a08:  30 80 00 1e  b,a   0xa0151a80
a0151a0c:  12 80 00 24  bne  0xa0151a9c
a0151a10:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0151a14:  a0 10 61 16  or  %g1, 0x116, %l0	! 0xa802e116
a0151a18:  7f ff 4d c3  call  0xa0125124
a0151a1c:  d0 0c 20 10  ldub  [ %l0 + 0x10 ], %o0
a0151a20:  90 0a 20 ff  and  %o0, 0xff, %o0
a0151a24:  7f ff 6c d1  call  0xa012cd68
a0151a28:  92 10 20 01  mov  1, %o1
a0151a2c:  f0 0c 20 10  ldub  [ %l0 + 0x10 ], %i0
a0151a30:  7f ff 4c f2  call  0xa0124df8
a0151a34:  81 e8 00 00  restore
a0151a38:  b2 12 21 16  or  %o0, 0x116, %i1
a0151a3c:  7f ff 4d ba  call  0xa0125124
a0151a40:  d0 0e 60 22  ldub  [ %i1 + 0x22 ], %o0
a0151a44:  90 0a 20 ff  and  %o0, 0xff, %o0
a0151a48:  7f ff 6c c8  call  0xa012cd68
a0151a4c:  92 10 20 01  mov  1, %o1
a0151a50:  f0 0e 60 22  ldub  [ %i1 + 0x22 ], %i0
a0151a54:  7f ff 4c e9  call  0xa0124df8
a0151a58:  81 e8 00 00  restore
a0151a5c:  90 10 20 00  clr  %o0
a0151a60:  7f fe d8 51  call  0xa0107ba4
a0151a64:  92 10 20 01  mov  1, %o1
a0151a68:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a0151a6c:  7f ff 4c e3  call  0xa0124df8
a0151a70:  d0 0a 61 4a  ldub  [ %o1 + 0x14a ], %o0	! 0xa802e14a
a0151a74:  b0 10 20 00  clr  %i0
a0151a78:  7f fe d7 ea  call  0xa0107a20
a0151a7c:  93 e8 20 01  restore  %g0, 1, %o1
a0151a80:  7f fe d8 49  call  0xa0107ba4
a0151a84:  92 10 20 01  mov  1, %o1
a0151a88:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a0151a8c:  7f ff 4c db  call  0xa0124df8
a0151a90:  d0 0a a1 5c  ldub  [ %o2 + 0x15c ], %o0	! 0xa802e15c
a0151a94:  10 bf ff f9  b  0xa0151a78
a0151a98:  b0 10 20 01  mov  1, %i0
a0151a9c:  81 c7 e0 08  ret
a0151aa0:  81 e8 00 00  restore
