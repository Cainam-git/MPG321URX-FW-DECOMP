# leon2s FUN_a00d2e00 0xa00d2e00-0xa00d2e9c (156 bytes)
a00d2e00:  9d e3 bf 98  save  %sp, -104, %sp
a00d2e04:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d2e08:  c2 08 60 37  ldub  [ %g1 + 0x37 ], %g1	! 0xa8078c37
a00d2e0c:  90 10 20 00  clr  %o0
a00d2e10:  80 a0 60 00  cmp  %g1, 0
a00d2e14:  02 80 00 06  be  0xa00d2e2c
a00d2e18:  b0 10 20 00  clr  %i0
a00d2e1c:  80 a0 60 01  cmp  %g1, 1
a00d2e20:  12 80 00 07  bne  0xa00d2e3c
a00d2e24:  80 a0 60 02  cmp  %g1, 2
a00d2e28:  90 10 20 01  mov  1, %o0
a00d2e2c:  40 3b 38 38  call  0xa0fa0f0c
a00d2e30:  01 00 00 00  nop
a00d2e34:  10 80 00 17  b  0xa00d2e90
a00d2e38:  b0 10 00 08  mov  %o0, %i0
a00d2e3c:  02 80 00 06  be  0xa00d2e54
a00d2e40:  90 10 20 00  clr  %o0
a00d2e44:  80 a0 60 03  cmp  %g1, 3
a00d2e48:  12 80 00 07  bne  0xa00d2e64
a00d2e4c:  80 a0 60 04  cmp  %g1, 4
a00d2e50:  90 10 20 01  mov  1, %o0
a00d2e54:  40 3b 7e 0e  call  0xa0fb268c
a00d2e58:  01 00 00 00  nop
a00d2e5c:  10 80 00 0d  b  0xa00d2e90
a00d2e60:  b0 10 00 08  mov  %o0, %i0
a00d2e64:  02 80 00 06  be  0xa00d2e7c
a00d2e68:  90 10 20 00  clr  %o0
a00d2e6c:  80 a0 60 05  cmp  %g1, 5
a00d2e70:  32 80 00 09  bne,a   0xa00d2e94
a00d2e74:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d2e78:  90 10 20 01  mov  1, %o0
a00d2e7c:  40 3b 90 3f  call  0xa0fb6f78
a00d2e80:  92 10 20 05  mov  5, %o1
a00d2e84:  80 8a 20 08  btst  8, %o0
a00d2e88:  32 80 00 02  bne,a   0xa00d2e90
a00d2e8c:  b0 10 20 01  mov  1, %i0
a00d2e90:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d2e94:  81 c7 e0 08  ret
a00d2e98:  81 e8 00 00  restore
