# leon2m FUN_a00e7dc8 0xa00e7dc8-0xa00e7eb0 (232 bytes)
a00e7dc8:  9d e3 bf 98  save  %sp, -104, %sp
a00e7dcc:  80 a6 60 03  cmp  %i1, 3
a00e7dd0:  18 80 00 25  bgu  0xa00e7e64
a00e7dd4:  90 10 00 18  mov  %i0, %o0
a00e7dd8:  80 a6 a0 07  cmp  %i2, 7
a00e7ddc:  18 80 00 2c  bgu  0xa00e7e8c
a00e7de0:  80 a6 60 03  cmp  %i1, 3
a00e7de4:  02 80 00 17  be  0xa00e7e40
a00e7de8:  80 a6 a0 03  cmp  %i2, 3
a00e7dec:  04 80 00 0f  ble  0xa00e7e28
a00e7df0:  94 06 40 19  add  %i1, %i1, %o2
a00e7df4:  82 06 40 19  add  %i1, %i1, %g1
a00e7df8:  b0 00 40 19  add  %g1, %i1, %i0
a00e7dfc:  b2 06 bf fc  add  %i2, -4, %i1
a00e7e00:  b4 10 20 01  mov  1, %i2
a00e7e04:  95 2e 80 19  sll  %i2, %i1, %o2
a00e7e08:  92 06 21 b7  add  %i0, 0x1b7, %o1
a00e7e0c:  80 a6 e0 01  cmp  %i3, 1
a00e7e10:  02 80 00 03  be  0xa00e7e1c
a00e7e14:  96 10 00 0a  mov  %o2, %o3
a00e7e18:  96 10 20 00  clr  %o3
a00e7e1c:  7f ff e1 ef  call  0xa00e05d8
a00e7e20:  b0 10 20 00  clr  %i0
a00e7e24:  30 80 00 21  b,a   0xa00e7ea8
a00e7e28:  96 02 80 19  add  %o2, %i1, %o3
a00e7e2c:  98 06 a0 04  add  %i2, 4, %o4
a00e7e30:  9e 10 20 01  mov  1, %o7
a00e7e34:  95 2b c0 0c  sll  %o7, %o4, %o2
a00e7e38:  10 bf ff f5  b  0xa00e7e0c
a00e7e3c:  92 02 e1 b6  add  %o3, 0x1b6, %o1
a00e7e40:  80 a6 a0 06  cmp  %i2, 6
a00e7e44:  92 10 21 bd  mov  0x1bd, %o1
a00e7e48:  14 bf ff f1  bg  0xa00e7e0c
a00e7e4c:  94 10 20 40  mov  0x40, %o2
a00e7e50:  92 10 20 01  mov  1, %o1
a00e7e54:  9a 06 a0 01  add  %i2, 1, %o5
a00e7e58:  95 2a 40 0d  sll  %o1, %o5, %o2
a00e7e5c:  10 bf ff ec  b  0xa00e7e0c
a00e7e60:  92 10 21 bf  mov  0x1bf, %o1
a00e7e64:  7f ff de 6a  call  0xa00df80c
a00e7e68:  01 00 00 00  nop
a00e7e6c:  7f ff e3 55  call  0xa00e0bc0
a00e7e70:  01 00 00 00  nop
a00e7e74:  11 00 06 66  sethi  %hi(0x199800), %o0
a00e7e78:  90 12 22 a8  or  %o0, 0x2a8, %o0	! 0x199aa8
a00e7e7c:  7f ff dc bd  call  0xa00df170
a00e7e80:  92 10 00 19  mov  %i1, %o1
a00e7e84:  10 80 00 09  b  0xa00e7ea8
a00e7e88:  b0 10 3f ff  mov  -1, %i0
a00e7e8c:  7f ff de 60  call  0xa00df80c
a00e7e90:  01 00 00 00  nop
a00e7e94:  7f ff e3 4b  call  0xa00e0bc0
a00e7e98:  01 00 00 00  nop
a00e7e9c:  03 00 06 66  sethi  %hi(0x199800), %g1
a00e7ea0:  10 bf ff f7  b  0xa00e7e7c
a00e7ea4:  90 10 62 d0  or  %g1, 0x2d0, %o0	! 0x199ad0
a00e7ea8:  81 c7 e0 08  ret
a00e7eac:  81 e8 00 00  restore
