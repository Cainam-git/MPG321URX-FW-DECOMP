# leon2s FUN_a0062f3c 0xa0062f3c-0xa0062fc8 (140 bytes)
a0062f3c:  9d e3 bf 98  save  %sp, -104, %sp
a0062f40:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0062f44:  80 a6 20 01  cmp  %i0, 1
a0062f48:  12 80 00 06  bne  0xa0062f60
a0062f4c:  b0 10 20 00  clr  %i0
a0062f50:  40 01 3a 77  call  0xa00b192c
a0062f54:  01 00 00 00  nop
a0062f58:  10 80 00 06  b  0xa0062f70
a0062f5c:  1b 33 c0 f2  sethi  %hi(0xcf03c800), %o5
a0062f60:  9a 10 20 55  mov  0x55, %o5
a0062f64:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a0062f68:  da 20 40 00  st  %o5, [ %g1 ]
a0062f6c:  1b 33 c0 f2  sethi  %hi(0xcf03c800), %o5
a0062f70:  98 13 60 04  or  %o5, 4, %o4	! 0xcf03c804
a0062f74:  c2 03 00 00  ld  [ %o4 ], %g1
a0062f78:  80 a0 60 dd  cmp  %g1, 0xdd
a0062f7c:  22 80 00 11  be,a   0xa0062fc0
a0062f80:  b0 10 20 01  mov  1, %i0
a0062f84:  01 00 00 00  nop
a0062f88:  01 00 00 00  nop
a0062f8c:  01 00 00 00  nop
a0062f90:  01 00 00 00  nop
a0062f94:  01 00 00 00  nop
a0062f98:  01 00 00 00  nop
a0062f9c:  01 00 00 00  nop
a0062fa0:  01 00 00 00  nop
a0062fa4:  03 00 02 71  sethi  %hi(0x9c400), %g1
a0062fa8:  b0 06 20 01  inc  %i0
a0062fac:  80 a6 00 01  cmp  %i0, %g1
a0062fb0:  08 bf ff f1  bleu  0xa0062f74
a0062fb4:  82 10 20 88  mov  0x88, %g1
a0062fb8:  c2 23 40 00  st  %g1, [ %o5 ]
a0062fbc:  b0 10 20 00  clr  %i0
a0062fc0:  81 c7 e0 08  ret
a0062fc4:  81 e8 00 00  restore
