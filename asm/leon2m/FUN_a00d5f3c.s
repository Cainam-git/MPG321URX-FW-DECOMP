# leon2m FUN_a00d5f3c 0xa00d5f3c-0xa00d5f9c (96 bytes)
a00d5f3c:  9d e3 bf 98  save  %sp, -104, %sp
a00d5f40:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d5f44:  98 10 62 90  or  %g1, 0x290, %o4	! 0xa802d290
a00d5f48:  da 0b 20 4a  ldub  [ %o4 + 0x4a ], %o5
a00d5f4c:  80 a3 60 00  cmp  %o5, 0
a00d5f50:  02 80 00 10  be  0xa00d5f90
a00d5f54:  01 00 00 00  nop
a00d5f58:  d0 03 20 b0  ld  [ %o4 + 0xb0 ], %o0
a00d5f5c:  80 a2 20 00  cmp  %o0, 0
a00d5f60:  02 80 00 0c  be  0xa00d5f90
a00d5f64:  90 10 20 01  mov  1, %o0
a00d5f68:  d4 0b 20 1f  ldub  [ %o4 + 0x1f ], %o2
a00d5f6c:  92 10 20 00  clr  %o1
a00d5f70:  80 a2 a0 00  cmp  %o2, 0
a00d5f74:  12 80 00 07  bne  0xa00d5f90
a00d5f78:  c0 2b 20 4a  clrb  [ %o4 + 0x4a ]
a00d5f7c:  40 01 dd 3e  call  0xa014d474
a00d5f80:  01 00 00 00  nop
a00d5f84:  90 10 20 01  mov  1, %o0	! 0x1
a00d5f88:  40 01 df 84  call  0xa014dd98
a00d5f8c:  92 10 20 00  clr  %o1
a00d5f90:  01 00 00 00  nop
a00d5f94:  81 c7 e0 08  ret
a00d5f98:  81 e8 00 00  restore
