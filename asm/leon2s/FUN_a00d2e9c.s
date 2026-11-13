# leon2s FUN_a00d2e9c 0xa00d2e9c-0xa00d2f00 (100 bytes)
a00d2e9c:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d2ea0:  c2 08 60 37  ldub  [ %g1 + 0x37 ], %g1	! 0xa8078c37
a00d2ea4:  80 a0 60 00  cmp  %g1, 0
a00d2ea8:  02 80 00 13  be  0xa00d2ef4
a00d2eac:  80 a0 60 01  cmp  %g1, 1
a00d2eb0:  02 80 00 11  be  0xa00d2ef4
a00d2eb4:  80 a0 60 02  cmp  %g1, 2
a00d2eb8:  02 80 00 0f  be  0xa00d2ef4
a00d2ebc:  80 a0 60 03  cmp  %g1, 3
a00d2ec0:  02 80 00 0d  be  0xa00d2ef4
a00d2ec4:  90 10 20 00  clr  %o0
a00d2ec8:  92 10 20 05  mov  5, %o1
a00d2ecc:  80 a0 60 04  cmp  %g1, 4
a00d2ed0:  02 80 00 06  be  0xa00d2ee8
a00d2ed4:  94 10 20 08  mov  8, %o2
a00d2ed8:  90 10 20 01  mov  1, %o0
a00d2edc:  80 a0 60 05  cmp  %g1, 5
a00d2ee0:  12 80 00 05  bne  0xa00d2ef4
a00d2ee4:  01 00 00 00  nop
a00d2ee8:  82 13 c0 00  mov  %o7, %g1
a00d2eec:  40 3b 90 35  call  0xa0fb6fc0
a00d2ef0:  9e 10 40 00  mov  %g1, %o7
a00d2ef4:  01 00 00 00  nop
a00d2ef8:  81 c3 e0 08  retl
a00d2efc:  01 00 00 00  nop
