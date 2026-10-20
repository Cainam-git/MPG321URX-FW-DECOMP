# leon2m FUN_a00d1e3c 0xa00d1e3c-0xa00d1ed8 (156 bytes)
a00d1e3c:  9d e3 bf 98  save  %sp, -104, %sp
a00d1e40:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00d1e44:  80 a0 60 02  cmp  %g1, 2
a00d1e48:  02 80 00 0e  be  0xa00d1e80
a00d1e4c:  98 10 20 00  clr  %o4
a00d1e50:  04 80 00 09  ble  0xa00d1e74
a00d1e54:  80 a0 60 01  cmp  %g1, 1
a00d1e58:  80 a0 60 03  cmp  %g1, 3
a00d1e5c:  02 80 00 1b  be  0xa00d1ec8
a00d1e60:  80 a0 60 04  cmp  %g1, 4
a00d1e64:  02 80 00 07  be  0xa00d1e80
a00d1e68:  98 10 20 03  mov  3, %o4
a00d1e6c:  10 80 00 19  b  0xa00d1ed0
a00d1e70:  b0 10 20 e3  mov  0xe3, %i0
a00d1e74:  12 80 00 17  bne  0xa00d1ed0
a00d1e78:  b0 10 20 e3  mov  0xe3, %i0
a00d1e7c:  98 10 20 02  mov  2, %o4
a00d1e80:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d1e84:  b0 12 22 90  or  %o0, 0x290, %i0	! 0xa802d290
a00d1e88:  da 0e 20 11  ldub  [ %i0 + 0x11 ], %o5
a00d1e8c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00d1e90:  80 a3 40 01  cmp  %o5, %g1
a00d1e94:  22 80 00 0f  be,a   0xa00d1ed0
a00d1e98:  b0 10 20 e0  mov  0xe0, %i0
a00d1e9c:  40 00 1e 32  call  0xa00d9764
a00d1ea0:  d8 2e 20 11  stb  %o4, [ %i0 + 0x11 ]
a00d1ea4:  7f fe e0 1b  call  0xa0089f10
a00d1ea8:  01 00 00 00  nop
a00d1eac:  92 10 00 18  mov  %i0, %o1
a00d1eb0:  90 10 20 30  mov  0x30, %o0
a00d1eb4:  94 10 20 00  clr  %o2
a00d1eb8:  40 01 e4 06  call  0xa014aed0
a00d1ebc:  96 10 21 fc  mov  0x1fc, %o3
a00d1ec0:  10 80 00 04  b  0xa00d1ed0
a00d1ec4:  b0 10 20 e0  mov  0xe0, %i0
a00d1ec8:  10 bf ff ee  b  0xa00d1e80
a00d1ecc:  98 10 20 01  mov  1, %o4
a00d1ed0:  81 c7 e0 08  ret
a00d1ed4:  81 e8 00 00  restore
