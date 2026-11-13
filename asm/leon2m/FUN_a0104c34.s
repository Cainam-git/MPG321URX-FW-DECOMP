# leon2m FUN_a0104c34 0xa0104c34-0xa0104cb0 (124 bytes)
a0104c34:  9d e3 bf 98  save  %sp, -104, %sp
a0104c38:  90 0e 20 ff  and  %i0, 0xff, %o0
a0104c3c:  80 a2 20 08  cmp  %o0, 8
a0104c40:  02 80 00 09  be  0xa0104c64
a0104c44:  b0 10 20 00  clr  %i0
a0104c48:  7f ff b5 83  call  0xa00f2254
a0104c4c:  92 10 20 54  mov  0x54, %o1
a0104c50:  80 8a 20 03  btst  3, %o0
a0104c54:  12 80 00 15  bne  0xa0104ca8
a0104c58:  b0 10 20 01  mov  1, %i0
a0104c5c:  10 80 00 13  b  0xa0104ca8
a0104c60:  b0 10 20 00  clr  %i0
a0104c64:  b0 06 20 01  inc  %i0
a0104c68:  90 10 20 08  mov  8, %o0
a0104c6c:  7f ff b5 7a  call  0xa00f2254
a0104c70:  92 10 20 54  mov  0x54, %o1
a0104c74:  80 8a 20 03  btst  3, %o0
a0104c78:  12 80 00 0b  bne  0xa0104ca4
a0104c7c:  82 0e 20 ff  and  %i0, 0xff, %g1
a0104c80:  80 a0 60 03  cmp  %g1, 3
a0104c84:  18 bf ff f6  bgu  0xa0104c5c
a0104c88:  90 10 20 08  mov  8, %o0
a0104c8c:  7f ff b5 72  call  0xa00f2254
a0104c90:  92 10 20 54  mov  0x54, %o1
a0104c94:  b0 06 20 01  inc  %i0
a0104c98:  80 8a 20 03  btst  3, %o0
a0104c9c:  02 bf ff f9  be  0xa0104c80
a0104ca0:  82 0e 20 ff  and  %i0, 0xff, %g1
a0104ca4:  b0 10 20 01  mov  1, %i0
a0104ca8:  81 c7 e0 08  ret
a0104cac:  81 e8 00 00  restore
